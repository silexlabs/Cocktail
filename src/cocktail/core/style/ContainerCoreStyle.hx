/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.FontManager;
import cocktail.core.NativeElement;
import cocktail.core.HTMLElement;
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
import cocktail.core.style.positioner.AbsolutePositioner;
import cocktail.core.style.positioner.BoxPositioner;
import cocktail.core.style.positioner.FixedPositioner;
import cocktail.core.style.positioner.RelativePositioner;
import cocktail.core.style.StyleData;
import cocktail.core.dom.DOMData;
import cocktail.core.dom.DOMData;
import cocktail.core.Text;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.geom.GeomData;
import cocktail.core.dom.DOMData;
import haxe.Timer;

import haxe.Log;

/**
 * This is the style implementation for ContainerHTMLElement.
 * 
 * ContainerHTMLElement can have children, and when laid out,
 * also start the layout on each of its children using
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
	 * ContainerHTMLElement create either a BlockBoxRenderer or an InlineBoxRenderer
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
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is overriden to start a recursive layout when called on a ContainerHTMLElement. The ContainerHTMLElement
	 * will be measured and placed as well as all of its children.
	 */
	override public function layout(containingHTMLElementData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{		
		flow(containingHTMLElementData, viewportData, lastPositionedHTMLElementData, null, null, null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerHTMLElement
	 */
	override private function flowChildren(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{

		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0..._htmlElement.childNodes.length)
		{
			//only HTMLElement styles are computed, not TextElement as they have no style.
			//When determining the formatting context to use, TextElement are always assumed
			//to be inline as text is always laid out on a line when rendered.
			//Text use its ContainerHTMLElement's styles for rendering
			if (_htmlElement.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var childHTMLElement:HTMLElement = cast(_htmlElement.childNodes[i]);
				childHTMLElement.coreStyle.computeDisplayStyles();
			}
		}
		
		//The children use either a new formatting context to
		//be laid out into if the ContainerHTMLElement establishes
		//a new formatting context or participate in the current formatting
		//context
		var childrenFormattingContext:FormattingContext = getformattingContext(formattingContext);
		
		//get the dimensions that will be used to lay out the children
		//of the HTMLElement. For instance, if the ContainerHTMLElement establishes an
		//inline formatting context, then its lineHeight will be used
		//instead of its height as containing height
		var childrenContainingHTMLElementData:ContainingHTMLElementData = getContainerHTMLElementData();
		
		//get the computed font metrics of the ContainerHTMLElement. Those metrics
		//are based on the font itself and the font size used
		var childrenContainingHTMLElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children and to each of the children using it as first positioned ancestor
		var childLastPositionedHTMLElementData:LastPositionedHTMLElementData;
		
		//if the ContainerHTMLElement is positioned, it becomes the last positioned HTMLElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this ContainerHTMLElement is laid out, it will position all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this ContainerHTMLElement are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the ContainerHTMLElement as reference
		childLastPositionedHTMLElementData = getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		
		//flow all children and store their laid out position in the created child ElementRenderers, relative to the ContainerHTMLElement
		//which started the children formatting context
		childrenFormattingContext = doFlowChildren(childrenContainingHTMLElementData, viewportData, childLastPositionedHTMLElementData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
	

		
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		if (this._width == Dimension.cssAuto)
		{
			shrinkToFitIfNeeded(containingHTMLElementData, childrenFormattingContext.maxWidth, formattingContext, lastPositionedHTMLElementData, viewportData );
		}
		
		//if the 'height' style of this ContainerHTMLElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children before the ContainerHTMLElement is actually
		//sized. For some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._height == Dimension.cssAuto)
		{
			//format the children formatting context, so that the bounds
			//of the children of this ContainerHTMLElement can be found.
			//The height of this bound is applied as the new height
			//It only needs to be done for ContainerHTMLElement which doesn't
			//establish a new formatting context for its children, else
			//the formatting context would have been already formatted
			//at this point
			if (establishesNewFormattingContext() == false)
			{
				childrenFormattingContext.format();
			}
			
			this._computedStyle.height = applyContentHeightIfNeeded(containingHTMLElementData,childrenFormattingContext.getChildrenHeight(cast(this._elementRenderer)));
		}
		
		//if this ContainerHTMLElement is positioned, it means that it is the first positioned ancestor
		//for its children and it is its responsability to position them.
		positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData, viewportData);
		
		//clean up the children formatting context for garbage collection
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.dispose();
		}

	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually flow all the children of the ContainerHTMLElement
	 * 
	 * TODO : re-add the code to insert offset before and after children ?
	 * 
	 */
	private function doFlowChildren(childrenContainingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, childLastPositionedHTMLElementData:LastPositionedHTMLElementData, childrenContainingHTMLElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):FormattingContext
	{
		var flowBoxRenderer:FlowBoxRenderer = cast(_elementRenderer);
		
		//flow all children 
		for (i in 0..._htmlElement.childNodes.length)
		{
			//if the children is a HTMLElement, call its flow method
			if (_htmlElement.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var childHTMLElement:HTMLElement = cast(_htmlElement.childNodes[i]);
				//the flow method also lays out recursively all the children of the childrenHTMLElement
				//if it is a ContainerHTMLElement
				childHTMLElement.coreStyle.flow(childrenContainingHTMLElementData, viewportData, childLastPositionedHTMLElementData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext, cast(_elementRenderer));
			}
			//else if it is a TextElement, call a method that will create as many TextFragmentHTMLElement
			//as necessary to render the TextElement and insert them into the document
			else 
			{
				var childrenText:Text = cast(_htmlElement.childNodes[i]);
				var insertedText:Array<TextRenderer> = insertTextElement(childrenText, childrenFormattingContext, childrenContainingHTMLElementData);
				
				//add the created TextRenderer to the ContainerHTMLElement
				//ElementRenderer
				for (j in 0...insertedText.length)
				{
					flowBoxRenderer.appendChild(insertedText[j]);
				}
			}
		}
		
		//prompt the children formatting context, to format all the children
		//ElementRenderer that were added to it. After this call, all the
		//ElementRenderer have the right bounds
		//
		//This method is only called if a new formatting
		//context was established by this ContainerHTMLElement,
		//meaning that it also is responsible to format it
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format();
		}
		
		return childrenFormattingContext;
	}
	
	/**
	 * Do position absolutely positioned descendant if this ContainerHTMLElement is positioned
	 */
	private function positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		if (isPositioned() == true)
		{
			doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData, viewportData);
		}
	}
	
	/**
	 * When this ContainerHTMLElement is positioned, position each of its children using it
	 * as its origin. This method is called once all the dimensions of ContainerHTMLElement
	 * are known so that absolutely positioned children can be positioned using the bottom
	 * and right styles
	 */
	private function doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		//update the data of the ContainerHTMLElement now that its width and height are known
		childLastPositionedHTMLElementData.data = getPositionedHTMLElementData();
		
		//position each stored children
		for (i in 0...childLastPositionedHTMLElementData.children.length)
		{
			var positionedHTMLElementData:PositionedHTMLElementData = childLastPositionedHTMLElementData.children[i];
			
			//position the HTMLElement's ElementRenderer which set its x and y bounds in the space of this ContainerHTMLElement's
			//formatting context
			positionedHTMLElementData.coreStyle.positionElement(childLastPositionedHTMLElementData.data, viewportData, positionedHTMLElementData.staticPosition );

			//absolutely positioned HTMLElement are positioned relative to the margin box
			//of their parent and not the content box, so an offset need to be applied
			//
			//TODO : re-implement but works for embedded elements but not container
			//boxElementData.bounds.x += _computedStyle.paddingLeft + _computedStyle.marginLeft;
			//boxElementData.bounds.y += _computedStyle.marginTop + _computedStyle.paddingTop;
		}
	}
	
	/**
	 * Insert a TextElement (a string of text without formatting) by creating as many TextFragmentHTMLElement as needed from it
	 * and inserting them into the flow
	 * @param	textElement the string of text used as content for the created text lines
	 */
	private function insertTextElement(textElement:Text, formattingContext:FormattingContext, containingHTMLElementData:ContainingHTMLElementData):Array<TextRenderer>
	{
		var rendereredText:Array<TextRenderer> = new Array<TextRenderer>();
		
		//get the text to display from the TextElement
		var text:String = textElement.nodeValue;
		
		//split the text into an array of text token
		var textFragments:Array<TextFragmentData> = textElement.getTextFragments(text);
		
		//loop through the text tokens
		for (i in 0...textFragments.length)
		{
			var textRenderer:TextRenderer = createTextRendererFromTextFragment(textFragments[i]);
			formattingContext.insertElement(textRenderer);
			rendereredText.push(textRenderer);
		}	
		
		return rendereredText;
	}
	
	/**
	 * Create and return a TextRenderer from a TextFragmentData
	 */
	private function createTextRendererFromTextFragment(textFragment:TextFragmentData):TextRenderer
	{
		//the text of the created TextRenderer
		var text:String;
		
		switch(textFragment.textToken)
		{
			case word(value):
				text = value;
		
			case space:
				text = " ";
				
			//TODO : implement tab and line feed	
			case tab:
				text = "";
				
			case lineFeed:
				text = "";
		}
		
		var textRenderer:TextRenderer = getTextRenderer(textFragment, text);
		
		return textRenderer;
	}
	
	/**
	 * In certain cases, when the width of the ContainerHTMLElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * If the width of this ContainerHTMLElement is indeed shrinked, all
	 * its children are re-flowed
	 * 
	 * @param	containingHTMLElementData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this ContainerHTMLElement which will be the minimum width that should
	 * have this HTMLElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingHTMLElementData:ContainingHTMLElementData, minimumWidth:Int, formattingContext:FormattingContext, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		var shrinkedWidth:Int = boxComputer.shrinkToFit(this, containingHTMLElementData, minimumWidth);
		
		//if the computed width of the ContainerHTMLElement was shrinked, then
		//a new layout must happen
		if (this._computedStyle.width != shrinkedWidth)
		{
			//store the new computed width
			this._computedStyle.width = shrinkedWidth;
			
			//update the structures used for the layout and starts a new layout
			var childrenFormattingContext:FormattingContext = getformattingContext(formattingContext);
			var childrenContainingHTMLElementData:ContainingHTMLElementData = getContainerHTMLElementData();
			var childLastPositionedHTMLElementData:LastPositionedHTMLElementData = getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
			childrenFormattingContext = doFlowChildren(childrenContainingHTMLElementData, viewportData, childLastPositionedHTMLElementData, this.fontMetrics, childrenFormattingContext);
		}
	}
	
	/**
	 * In most cases, when the height of a ContainerHTMLElement
	 * is 'auto', its computed height become the total height
	 * of its in flow children, computed once all its
	 * children have been laid out 
	 * 
	 * @param	containingHTMLElementData
	 * @param	childrenHeight the total height of the children once laid out
	 */
	private function applyContentHeightIfNeeded(containingHTMLElementData:ContainingHTMLElementData, childrenHeight:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		return boxComputer.applyContentHeight(this, containingHTMLElementData, childrenHeight);
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
	// PRIVATE TEXT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Take a TextFragmentData and a text, and create
	 * a TextRenderer from it if it doesn't already
	 * exists. If it does, return it
	 */
	private function getTextRenderer(textFragmentData:TextFragmentData, text:String):TextRenderer
	{
		var fontManager:FontManager = new FontManager();
		var nativeTextElement:NativeElement = fontManager.createNativeTextElement(text, _computedStyle);
		
		var textRenderer:TextRenderer = new TextRenderer(this, nativeTextElement, textFragmentData.textToken);
	
		textRenderer.layerRenderer = _elementRenderer.layerRenderer;
		textFragmentData.textRenderer = textRenderer;
			
		//TODO : reusing a textRenderer creates an infinite loop
		/**if (textFragmentData.textRenderer == null)
		{
			textRenderer = createTextRenderer(text, textFragmentData.textToken);
			textRenderer.layerRenderer = _elementRenderer.layerRenderer;
			textFragmentData.textRenderer = textRenderer;
		}
		else
		{
			textRenderer = textFragmentData.textRenderer;
		}*/
		
		return textRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the ContainerHTMLElement
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
	 * of the ContainerHTMLElement
	 */
	public function getContainerHTMLElementData():ContainingHTMLElementData
	{
		var height:Int;
		
		//if the ContainerHTMLElement
		//is inline level, then its line height will
		//be used to lay out its children in lines
		if (isInlineLevel() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//same if the ContainerHTMLElement establishes
		//an inline formatting context
		else if (establishesNewFormattingContext() == true && childrenInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//else it either establishes a block formatting context or participate
		//in one and its height is used
		else
		{
			height = this._computedStyle.height;
		}
		
		return {
			width:this._computedStyle.width,
			isWidthAuto:this._width == Dimension.cssAuto,
			height:height,
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
		var positionedHTMLElementData:ContainingHTMLElementData = getContainerHTMLElementData();
		
		//ensure that the actual height of the ContainerHTMLElement is used instead of its lineHeight
		positionedHTMLElementData.height = getComputedHeight();
		
		return positionedHTMLElementData;
	}
	
	/**
	 * Return the right formatting context to layout this ContainerHTMLElement
	 * children.
	 * 
	 * A ContainerHTMLElement can either establish a new formatting context
	 * or participate in the current formatting context. If it participates
	 * in the current formatting context, then the previous formatting
	 * is returned else a new block or inline formatting context is
	 * instantiated
	 * 
	 * @param	previousformattingContext the formatting context of the parent of this
	 * Container HTMLElement, might be returned if the container HTMLElement participates
	 * in the same formatting context as its parent
	 * 
	 * @return an inline or block formatting context
	 */
	private function getformattingContext(previousformattingContext:FormattingContext = null):FormattingContext
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
		//here the children is a textElement, which is
		//always inline as text is always displayed on a line
		else
		{
			ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the structure used to layout absolutely positioned
	 * children. If this ContainerHTMLElement is positioned, a new
	 * structure is created, else the current one is used
	 */
	private function getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData:LastPositionedHTMLElementData):LastPositionedHTMLElementData
	{
		var childLastPositionedHTMLElementData:LastPositionedHTMLElementData;
		
		if (isPositioned() == true)
		{
			childLastPositionedHTMLElementData = {
				data: getContainerHTMLElementData(),
				children: new Array<PositionedHTMLElementData>()
			}
		}
		else
		{
			childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
		}
		
		return childLastPositionedHTMLElementData;
	}

	/**
	 * Determine wheter the container HTMLElement
	 * is an inline or block container. For instance,
	 * an inline-block containerHTMLElement is both
	 * inline level (because it is placed on a line) and
	 * a block container, because it can layout its
	 * children either into either a block or
	 * inline formatting context. An inline container
	 * can only lay out its children into an
	 * inline formatting context
	 */
	private function isInlineContainer():Bool
	{
		var ret:Bool;
		
		switch(this._computedStyle.display)
		{ 
			case block, inlineBlock:
				ret = false;
				
			case cssInline:
				ret = true;
				
			default:
				ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the computed height of the ContainerHTMLElement.
	 * Use as a hook to be overriden by the BodyStyle
	 * to return the viewport height
	 */
	private function getComputedHeight():Int
	{
		return this._computedStyle.height;
	}
	
}