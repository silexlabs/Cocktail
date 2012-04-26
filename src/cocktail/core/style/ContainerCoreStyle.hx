/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.dom.Text;
import cocktail.core.FontManager;
import cocktail.core.NativeElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.dom.Node;
import cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.formatter.InlineFormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.dom.DOMData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
import haxe.Timer;

import haxe.Log;

/**
 * This is the style implementation for HTMLElement which are also
 * containers.
 * 
 * This HTMLElement can have children, and when laid out,
 * also starts the layout on each of its children using
 * either a block or inline formatting
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerCoreStyle extends CoreStyle
{
	/**
	 * class constructor.
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * HTMLElement create either a BlockBoxRenderer or an InlineBoxRenderer
	 * depending on wheter they participate in a block or inline formatting context
	 * then attach it to their parent ElementRenderer
	 */
	override private function createElementRenderer(parentElementRenderer:FlowBoxRenderer):ElementRenderer
	{
		var elementRenderer:ElementRenderer;
		
		if (isInlineLevel() == true && establishesNewFormattingContext() == false)
		{
			elementRenderer = new InlineBoxRenderer(this);
		}
		else
		{
			elementRenderer = new BlockBoxRenderer(this);
		}
		
		elementRenderer.layerRenderer = getLayerRenderer(elementRenderer, parentElementRenderer);
		parentElementRenderer.appendChild(elementRenderer);
		
		return elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the HTMLElement
	 */
	override private function layoutChildren(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0..._htmlElement.childNodes.length)
		{
			//only HTMLElement styles are computed, not Text as they have no style.
			//When determining the formatting context to use, TextElement are always assumed
			//to be inline as text is always laid out on a line when rendered.
			//Text use its parent HTMLElement's styles for rendering
			if (_htmlElement.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var childHTMLElement:HTMLElement = cast(_htmlElement.childNodes[i]);
				childHTMLElement.coreStyle.computeDisplayStyles();
			}
		}
		
		//The children use either a new formatting context to
		//be laid out if the parent HTMLElement establishes
		//a new formatting context or participate in the current formatting
		//context
		var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
		
		//get the dimensions that will be used to lay out the children
		//of the HTMLElement (its width and height)
		var childrenContainingHTMLElementData:ContainingHTMLElementData = getContainerHTMLElementData();
		
		//get the computed font metrics of the parent HTMLElement. Those metrics
		//are based on the font itself and the font size used
		var childrenContainingHTMLElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children and to each of the children using it as first positioned ancestor
		var childLastPositionedHTMLElementData:LastPositionedHTMLElementData;
		
		//if the HTMLElement is positioned, it becomes the last positioned HTMLElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this HTMLElement is laid out, it will position all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this HTMLElement are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the HTMLElement as reference
		childLastPositionedHTMLElementData = getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		
		//flow all children and store their laid out position in the created child ElementRenderers, relative to the HTMLElement
		//which started the children formatting context
		childrenFormattingContext = doLayoutChildren(childrenContainingHTMLElementData, viewportData, childLastPositionedHTMLElementData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
		
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		//in some cases
		if (this._width == Dimension.cssAuto)
		{
			shrinkToFitIfNeeded(containingHTMLElementData, childrenFormattingContext.maxWidth, formattingContext, lastPositionedHTMLElementData, viewportData );
		}
		
		//if the 'height' style of this HTMLElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children. For some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._height == Dimension.cssAuto)
		{
			//format the children formatting context, so that the bounds
			//of the children of this HTMLElement can be found.
			//The height of this bound is applied as the new height
			//It only needs to be done for HTMLElement which doesn't
			//establish a new formatting context for its children, else
			//the formatting context would have been already formatted
			//at this point
			if (establishesNewFormattingContext() == false)
			{
				childrenFormattingContext.format();
			}
			
			this._computedStyle.height = applyContentHeightIfNeeded(containingHTMLElementData, viewportData, lastPositionedHTMLElementData.data, childrenFormattingContext.getChildrenHeight(cast(this._elementRenderer)));
		}
		
		//if this HTMLElement is positioned, it means that it is the first positioned ancestor
		//for its children and it is its responsability to position them.
		positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData, viewportData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually layout all the children of the HTMLElement
	 */
	private function doLayoutChildren(childrenContainingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, childLastPositionedHTMLElementData:LastPositionedHTMLElementData, childrenContainingHTMLElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):FormattingContext
	{
		var flowBoxRenderer:FlowBoxRenderer = cast(_elementRenderer);
		
		//first remove all the child that might have been added to the renderer
		//if any, as this method can be called multiple, it prevents multiple
		//text renderers to be generated for the same Text node
		//
		//TODO : should Text node have explicit reference to TextRenderer, like
		//HTMLElement have reference to ElementRenderer through CoreStyle ?
		for (i in 0...flowBoxRenderer.childNodes.length)
		{
			flowBoxRenderer.removeChild(flowBoxRenderer.childNodes[0]);
		}
		
		//layout all children 
		for (i in 0..._htmlElement.childNodes.length)
		{
			//if the children is an HTMLElement, call its layout method
			if (_htmlElement.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var childHTMLElement:HTMLElement = cast(_htmlElement.childNodes[i]);
				//the layout method also lays out recursively all the children of the children HTMLElement
				//if it is an HTMLElement
				childHTMLElement.coreStyle.layout(childrenContainingHTMLElementData, viewportData, childLastPositionedHTMLElementData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext, cast(_elementRenderer));
			}
			//else if it is a Text node, call a method that will create a TextRenderer
			//to render the text content of the text node, and attach the TextRenderer
			//to the rendering tree
			else 
			{
				var childrenText:Text = cast(_htmlElement.childNodes[i]);
				var insertedText:TextRenderer = getTextRenderer(childrenText);
				flowBoxRenderer.appendChild(insertedText);
			}
		}
		
		//prompt the children formatting context, to format all the children
		//ElementRenderer that were added to it. After this call, all the
		//ElementRenderer have the right bounds, in the space of their formatting
		// context
		//
		//This method is only called if a new formatting
		//context was established by this HTMLElement,
		//meaning that it also is responsible to format it
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format();
		}
		
		return childrenFormattingContext;
	}
	
	/**
	 * Do position absolutely positioned descendant if this HTMLElement is positioned
	 */
	private function positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		if (isPositioned() == true)
		{
			doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData, viewportData);
		}
	}
	
	/**
	 * When this HTMLElement is positioned, position each of its children using it
	 * as its origin. This method is called once all the dimensions of HTMLElement
	 * are known so that absolutely positioned children can be positioned using the bottom
	 * and right styles
	 * 
	 * TODO : update doc 
	 * 
	 * TODO : should position fixed element ? just for static position ?
	 */
	private function doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		//update the data of the HTMLElement now that its width and height are known
		childLastPositionedHTMLElementData.data = getPositionedHTMLElementData();
		
		//position each stored children
		for (i in 0...childLastPositionedHTMLElementData.elements.length)
		{
			var element:ElementRenderer = childLastPositionedHTMLElementData.elements[i];

			//position the child HTMLElement's ElementRenderer which set its x and y bounds in the space of this HTMLElement's
			//formatting context
			element.coreStyle.positionElement(childLastPositionedHTMLElementData.data, viewportData);
			
			//This container might establish a new formatting context, for instance if it is absolute,
			//in this case, the positioned children, whose bounds are defined relative to their nearest block
			//box container, use the container as origin.
			//Else, if this container does not establish a new formatting context, for instance if it is relative,
			//it's bounds which are relative to its own first ancestor block box are added to it's positioned children, so that
			//their bounds are also defined in this ancestor block box space.
			//It isn't applied if the positioned children use their static position as their bounds are already relative to their
			//first ancestor block box
			//
			//TODO : check if element is not passed by value
			if (establishesNewFormattingContext() == false)
			{
				//TODO : this bit should go into BoxPositioner
				var childStyle:CoreStyle = element.coreStyle;
				
				if (childStyle.computedStyle.position != fixed)
				{
					if (childStyle.top != PositionOffset.cssAuto || childStyle.bottom != PositionOffset.cssAuto)
					{
						element.positionedOrigin.y += _elementRenderer.bounds.y;
					}
					if (childStyle.left != PositionOffset.cssAuto || childStyle.right != PositionOffset.cssAuto)
					{
						element.positionedOrigin.x += _elementRenderer.bounds.x;
					}
				}
			}
			else
			{
				//TODO : this bit should go into BoxPositioner
				var childStyle:CoreStyle = element.coreStyle;
				
				if (childStyle.computedStyle.position != fixed)
				{
					if (childStyle.top == PositionOffset.cssAuto && childStyle.bottom == PositionOffset.cssAuto)
					{
						element.positionedOrigin.y += _computedStyle.marginTop;
					}
					if (childStyle.left == PositionOffset.cssAuto && childStyle.right == PositionOffset.cssAuto)
					{
						element.positionedOrigin.x +=  _computedStyle.marginLeft;
					}
				}
			}
		}
	}
	
	
	
	
	/**
	 * In certain cases, when the width of the HTMLElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * If the width of this HTMLElement is indeed shrinked, all
	 * its children are re-flowed
	 * 
	 * @param	containingHTMLElementData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this HTMLElement which will be the minimum width that should
	 * have this HTMLElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingHTMLElementData:ContainingHTMLElementData, minimumWidth:Int, formattingContext:FormattingContext, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		var shrinkedWidth:Int = boxComputer.shrinkToFit(this, containingHTMLElementData, minimumWidth);
		
		//if the computed width of the HTMLElement was shrinked, then
		//a new layout must happen
		if (this._computedStyle.width != shrinkedWidth)
		{
			//store the new computed width
			this._computedStyle.width = shrinkedWidth;
			
			//update the structures used for the layout and starts a new layout
			var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
			var childrenContainingHTMLElementData:ContainingHTMLElementData = getContainerHTMLElementData();
			var childLastPositionedHTMLElementData:LastPositionedHTMLElementData = getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
			doLayoutChildren(childrenContainingHTMLElementData, viewportData, childLastPositionedHTMLElementData, this.fontMetrics, childrenFormattingContext);
		}
	}
	
	/**
	 * In most cases, when the height of a HTMLElement
	 * is 'auto', its computed height become the total height
	 * of its in flow children, computed once all its
	 * children have been laid out 
	 * 
	 * @param	childrenHeight the total height of the children once laid out
	 */
	private function applyContentHeightIfNeeded(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:ContainingHTMLElementData, childrenHeight:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		//get the right containing dimensions. For example,
		//for a HTMLElement with a 'position' style of 'absolute',
		//it is the last positioned HTMLElement
		var containingBlockDimensions:ContainingHTMLElementData = getContainingHTMLElementData(containingHTMLElementData, viewportData, lastPositionedHTMLElementData );
		
		return boxComputer.applyContentHeight(this, containingBlockDimensions, childrenHeight);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE TEXT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Take a TextFragmentData and a text, and create
	 * a TextRenderer from it if it doesn't already
	 * exists. If it does, return it
	 * 
	 * TODO : should be instantiated by Text node ?
	 */
	private function getTextRenderer(text:Text):TextRenderer
	{	
		var textRenderer:TextRenderer = new TextRenderer(this, text);
		textRenderer.layerRenderer = _elementRenderer.layerRenderer;
		return textRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to use box computer specific to 
	 * container HTMLElement instead of the embedded one
	 */
	override private function getBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
				
		//get the box computer for float
		if (isFloat() == true)
		{
			boxComputer = new FloatBoxStylesComputer();
		}
		
		//get it for HTMLElement with 'position' value of 'absolute' or 'fixed'
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new PositionedBoxStylesComputer();
		}
		
		//else get the box computer based on the display style
		else
		{
			switch(this._computedStyle.display)
			{
				case block:
					boxComputer = new BlockBoxStylesComputer();
					
				case inlineBlock:
					boxComputer = new InlineBlockBoxStylesComputer();
				
				//not supposed to happen
				case none:
					boxComputer = null;
				
				case cssInline:
					boxComputer = new InLineBoxStylesComputer();
			}
		}
		
		return boxComputer;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the HTMLElement
	 * establishes a new formatting context for
	 * its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		var ret:Bool = false;
		
		//floats always establishes new context
		if (isFloat() == true)
		{
			ret = true;
		}
		//positioned element which are not relative always establishes new context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			ret = true;
		}
		//element with an inline-block display style
		//alwyas establishes a new context
		else
		{
			switch (this._computedStyle.display)
			{
				case inlineBlock:
				ret = true; 
				//a block HTMLElement may start a new inline
				//formatting context if all its children are inline,
				//else its children participate in the current block formatting
				//context
				case block:
					if (childrenInline() == true)
					{
						ret = true;
					}
					
				default:
			}
		}
		
		//in the other cases such as an inline level inline container
		//the current formatting context is used
		
		return ret;
	}
	
	/**
	 * Determine wether the children of this HTMLElement
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * TODO : throw exception when there is a float in the children
	 * 
	 * @return true if all children are inline level HTMLElements
	 */
	override public function childrenInline():Bool
	{
		
		//return false for a container with no children
		if (_htmlElement.childNodes.length == 0)
		{
			return false;
		}
		
		//establish if the first child is inline or block
		//all other child must be of the same type
		var ret:Bool = isChildInline(_htmlElement.childNodes[0]);
		
		//loop in all children and throw an exception
		//if one the children is not of the same type as the first
		for (i in 0..._htmlElement.childNodes.length)
		{
			if (isChildInline(_htmlElement.childNodes[i]) != ret)
			{
				//throw "children of a block container can only be either all block or all inline";
			}
		}
		
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the dimensions data
	 * of the HTMLElement
	 */
	public function getContainerHTMLElementData():ContainingHTMLElementData
	{
		return {
			width:this._computedStyle.width,
			isWidthAuto:this._width == Dimension.cssAuto,
			height:this._computedStyle.height,
			isHeightAuto:this._height == Dimension.cssAuto
		};
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the data of this htmlElement to be used when it is
	 * the first positioned ancestor for its children.
	 * Meant to be overriden
	 */
	private function getPositionedHTMLElementData():ContainingHTMLElementData
	{
		return getContainerHTMLElementData();
	}
	
	/**
	 * Return the right formatting context to layout this HTMLElement's
	 * children.
	 * 
	 * An HTMLElement can either establish a new formatting context
	 * or participate in the current formatting context. If it participates
	 * in the current formatting context, then the previous formatting
	 * is returned else a new block or inline formatting context is
	 * instantiated
	 * 
	 * @param	previousformattingContext the formatting context of the parent of this
	 * HTMLElement, might be returned if the HTMLElement participates
	 * in the same formatting context as its parent
	 * 
	 * @return an inline or block formatting context
	 */
	private function getFormattingContext(previousformattingContext:FormattingContext = null):FormattingContext
	{
		var formattingContext:FormattingContext;
		
		//here, a new formatting context is created
		if (establishesNewFormattingContext() == true || previousformattingContext == null)
		{
			var formattingContextRoot:BlockBoxRenderer = cast(this._elementRenderer);
			
			//instantiate the right formatting context
			//based on the children computed display styles
			if (childrenInline() == true)
			{
				formattingContext = new InlineFormattingContext(formattingContextRoot);	
			}
			else
			{
				formattingContext = new BlockFormattingContext(formattingContextRoot);
			}
		}
		else
		{
			formattingContext = previousformattingContext;
		}
		
		return formattingContext;
	}
	
	/**
	 * Determine wether a children is inline or not
	 */
	private function isChildInline(child:Node):Bool
	{
		var ret:Bool = true;
		
		//here the children is a HTMLElement
		if (child.nodeType == Node.ELEMENT_NODE)
		{
			var childHTMLElement:HTMLElement = cast(child);
			//here the child is of type block
			if (childHTMLElement.coreStyle.computedStyle.display == block)
			{
				//floated children are not taken into account 
				if (childHTMLElement.coreStyle.isFloat() == false)
				{
					ret = false;
				}
				//absolutely positioned children are not taken into account but relative positioned are
				else if (childHTMLElement.coreStyle.isPositioned() == false || childHTMLElement.coreStyle.isRelativePositioned() == true)
				{
					ret = false;
				}
			}
			//here the child is inline
			else
			{
				ret = true;
			}
		}
		//here the children is a Text node, which is
		//always inline as text is always displayed on a line
		else
		{
			ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the structure used to layout absolutely positioned
	 * children. If this HTMLElement is positioned, a new
	 * structure is created, else the current one is used
	 */
	private function getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData:LastPositionedHTMLElementData):LastPositionedHTMLElementData
	{
		var childLastPositionedHTMLElementData:LastPositionedHTMLElementData;
		
		if (isPositioned() == true)
		{
			childLastPositionedHTMLElementData = {
				data: getContainerHTMLElementData(),
				elements: new Array<ElementRenderer>()
			}
		}
		else
		{
			childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
		}
		
		return childLastPositionedHTMLElementData;
	}
}