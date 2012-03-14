/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.viewport.Viewport;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktailCore.style.formatter.BlockFormattingContext;
import cocktailCore.style.formatter.FormattingContext;
import cocktailCore.style.formatter.InlineFormattingContext;
import cocktailCore.style.positioner.AbsolutePositioner;
import cocktailCore.style.positioner.BoxPositioner;
import cocktailCore.style.positioner.FixedPositioner;
import cocktailCore.style.positioner.RelativePositioner;
import cocktail.style.StyleData;
import cocktail.domElement.DOMElementData;
import cocktailCore.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import cocktailCore.style.renderer.BlockBoxRenderer;
import cocktailCore.style.renderer.ElementRenderer;
import cocktailCore.style.renderer.FlowBoxRenderer;
import cocktailCore.style.renderer.InlineBoxRenderer;
import cocktailCore.style.renderer.LayerRenderer;
import cocktailCore.style.renderer.TextRenderer;
import cocktailCore.textElement.abstract.AbstractTextElement;
import cocktailCore.textElement.TextElementData;
import cocktail.geom.GeomData;
import haxe.Timer;

#if (flash9 || cpp || nme)
import cocktailCore.style.as3.Style;
#elseif js
import cocktailCore.style.js.Style;
#end

import haxe.Log;

/**
 * This is the style implementation for ContainerDOMElement.
 * 
 * ContainerDOMElement can have children, and when laid out,
 * also start the layout on each of its children using
 * either a block or inline formatting
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerStyle extends Style
{
	/**
	 * class constructor.
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * ContainerDOMElement create either a BlockBoxRenderer or an InlineBoxRenderer
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
		parentElementRenderer.addChild(elementRenderer);
		
		return elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is overriden to start a recursive layout when called on a ContainerDOMElement. The ContainerDOMElement
	 * will be measured and placed as well as all of its children.
	 */
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{		
		flow(containingDOMElementData, viewportData, lastPositionedDOMElementData, null, null, null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		//cast the ContainerDOMElement, as base DOMElement have no children attribute
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0...containerDOMElement.children.length)
		{
			//only DOMElement styles are computed, not TextElement as they have no style.
			//When determining the formatting context to use, TextElement are always assumed
			//to be inline as text is always laid out on a line when rendered.
			//Text use its ContainerDOMElement's styles for rendering
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.computeDisplayStyles();
			}
		}
		
		//The children use either a new formatting context to
		//be laid out into if the ContainerDOMElement establishes
		//a new formatting context or participate in the current formatting
		//context
		var childrenFormattingContext:FormattingContext = getformattingContext(formattingContext);
		
		//get the dimensions that will be used to lay out the children
		//of the DOMElement. For instance, if the ContainerDOMElement establishes an
		//inline formatting context, then its lineHeight will be used
		//instead of its height as containing height
		var childrenContainingDOMElementData:ContainingDOMElementData = getContainerDOMElementData();
		
		//get the computed font metrics of the ContainerDOMElement. Those metrics
		//are based on the font itself and the font size used
		var childrenContainingDOMElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children and to each of the children using it as first positioned ancestor
		var childLastPositionedDOMElementData:LastPositionedDOMElementData;
		
		//if the ContainerDOMElement is positioned, it becomes the last positioned DOMElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this ContainerDOMElement is laid out, it will position all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this ContainerDOMElement are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the ContainerDOMElement as reference
		childLastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
		
		//flow all children and store their laid out position in the created child ElementRenderers, relative to the ContainerDOMElement
		//which started the children formatting context
		childrenFormattingContext = doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
	
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		if (this._width == DimensionStyleValue.autoValue)
		{
			shrinkToFitIfNeeded(containingDOMElementData, childrenFormattingContext.formattingContextData.maxWidth, formattingContext, lastPositionedDOMElementData, viewportData );
		}
		
		//if the 'height' style of this ContainerDOMElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized. For some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._height == DimensionStyleValue.autoValue)
		{
			//format the children formatting context, so that the bounds
			//of the children of this ContainerDOMElement can be found.
			//The height of this bound is applied as the new height
			//It only needs to be done for ContainerDOMElement which doesn't
			//establish a new formatting context for its children, else
			//the formatting context would have been already formatted
			//at this point
			if (establishesNewFormattingContext() == false)
			{
				childrenFormattingContext.format();
			}
			
			this._computedStyle.height = applyContentHeightIfNeeded(containingDOMElementData,childrenFormattingContext.getChildrenHeight(cast(this._elementRenderer)));
		}
		
		//if this ContainerDOMElement is positioned, it means that it is the first positioned ancestor
		//for its children and it is its responsability to position them.
		positionAbsolutelyPositionedDOMElementsIfNeeded(childLastPositionedDOMElementData, viewportData);
		
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
	 * Actually flow all the children of the ContainerDOMElement
	 * 
	 * TODO : re-add the code to insert offset before and after children ?
	 * 
	 */
	private function doFlowChildren(childrenContainingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, childLastPositionedDOMElementData:LastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		var flowBoxRenderer:FlowBoxRenderer = cast(_elementRenderer);
		
		//flow all children 
		for (i in 0...containerDOMElement.children.length)
		{
			//if the children is a DOMElement, call its flow method
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				//the flow method also lays out recursively all the children of the childrenDOMElement
				//if it is a ContainerDOMElement
				childrenDOMElement.style.flow(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext, cast(_elementRenderer));
			}
			//else if it is a TextElement, call a method that will create as many TextFragmentDOMElement
			//as necessary to render the TextElement and insert them into the document
			else 
			{
				var childrenTextElement:TextElement = cast(containerDOMElement.children[i].child);
				var insertedText:Array<TextRenderer> = insertTextElement(childrenTextElement, childrenFormattingContext, childrenContainingDOMElementData);
				
				//add the created TextRenderer to the ContainerDOMElement
				//ElementRenderer
				for (j in 0...insertedText.length)
				{
					flowBoxRenderer.addChild(insertedText[j]);
				}
			}
		}
		
		//prompt the children formatting context, to format all the children
		//ElementRenderer that were added to it. After this call, all the
		//ElementRenderer have the right bounds
		//
		//This method is only called if a new formatting
		//context was established by this ContainerDOMElement,
		//meaning that it also is responsible to format it
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format(true);
		}
		
		return childrenFormattingContext;
	}
	
	/**
	 * Do position absolutely positioned descendant if this ContainerDOMElement is positioned
	 */
	private function positionAbsolutelyPositionedDOMElementsIfNeeded(childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		if (isPositioned() == true)
		{
			doPositionAbsolutelyPositionedDOMElements(childLastPositionedDOMElementData, viewportData);
		}
	}
	
	/**
	 * When this ContainerDOMElement is positioned, position each of its children using it
	 * as its origin. This method is called once all the dimensions of ContainerDOMElement
	 * are known so that absolutely positioned children can be positioned using the bottom
	 * and right styles
	 */
	private function doPositionAbsolutelyPositionedDOMElements(childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		//update the data of the ContainerDOMElement now that its width and height are known
		childLastPositionedDOMElementData.data = getContainerDOMElementData();
		
		//ensure that the actual height of the ContainerDOMElement is used instead of its lineHeight
		childLastPositionedDOMElementData.data.height = getComputedHeight();
		
		//position each stored children
		for (i in 0...childLastPositionedDOMElementData.children.length)
		{
			var positionedDOMElementData:PositionedDOMElementData = childLastPositionedDOMElementData.children[i];
			
			//position the DOMElement's ElementRenderer which set its x and y bounds in the space of this ContainerDOMElement's
			//formatting context
			positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data, viewportData, positionedDOMElementData.staticPosition );

			//absolutely positioned DOMElement are positioned relative to the margin box
			//of their parent and not the content box, so an offset need to be applied
			//
			//TODO : re-implement but works for embedded elements but not container
			//boxElementData.bounds.x += _computedStyle.paddingLeft + _computedStyle.marginLeft;
			//boxElementData.bounds.y += _computedStyle.marginTop + _computedStyle.paddingTop;
		}
	}
	
	/**
	 * Insert a TextElement (a string of text without formatting) by creating as many TextFragmentDOMElement as needed from it
	 * and inserting them into the flow
	 * @param	textElement the string of text used as content for the created text lines
	 */
	private function insertTextElement(textElement:TextElement, formattingContext:FormattingContext, containingDOMElementData:ContainingDOMElementData):Array<TextRenderer>
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);

		var rendereredText:Array<TextRenderer> = new Array<TextRenderer>();
		
		//get the text to display from the TextElement
		var text:String = textElement.text;
		
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
	 * In certain cases, when the width of the ContainerDOMElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * If the width of this ContainerDOMElement is indeed shrinked, all
	 * its children are re-flowed
	 * 
	 * @param	containingDOMElementData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this ContainerDOMElement which will be the minimum width that should
	 * have this DOMElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingDOMElementData:ContainingDOMElementData, minimumWidth:Int, formattingContext:FormattingContext, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		var shrinkedWidth:Int = boxComputer.shrinkToFit(this, containingDOMElementData, minimumWidth);
		
		//if the computed width of the ContainerDOMElement was shrinked, then
		//a new layout must happen
		if (this._computedStyle.width != shrinkedWidth)
		{
			//store the new computed width
			this._computedStyle.width = shrinkedWidth;
			
			//update the structures used for the layout and starts a new layout
			var childrenFormattingContext:FormattingContext = getformattingContext(formattingContext);
			var childrenContainingDOMElementData:ContainingDOMElementData = getContainerDOMElementData();
			var childLastPositionedDOMElementData:LastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
			childrenFormattingContext = doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, this.fontMetrics, childrenFormattingContext);
		}
	}
	
	/**
	 * In most cases, when the height of a ContainerDOMElement
	 * is 'auto', its computed height become the total height
	 * of its in flow children, computed once all its
	 * children have been laid out 
	 * 
	 * @param	containingDOMElementData
	 * @param	childrenHeight the total height of the children once laid out
	 */
	private function applyContentHeightIfNeeded(containingDOMElementData:ContainingDOMElementData, childrenHeight:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		return boxComputer.applyContentHeight(this, containingDOMElementData, childrenHeight);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to use box computer specific to 
	 * container DOMElement instead of the embedded one
	 */
	override private function getBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
				
		//get the box computer for float
		if (isFloat() == true)
		{
			boxComputer = new FloatBoxStylesComputer();
		}
		
		//get it for DOMElement with 'position' value of 'absolute' or 'fixed'
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
				
				case none:
					boxComputer = new NoneBoxStylesComputer();
				
				case inlineStyle:
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
		var textRenderer:TextRenderer;
		textRenderer = createTextRenderer(text, textFragmentData.textToken);
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
	
	/**
	 * Create a TextRenderer from a string of text and
	 * add it to the ContainerDOMElement
	 */
	private function createTextRenderer(text:String, textToken:TextTokenValue):TextRenderer
	{
		return  doCreateTextRenderer(text, textToken);
	}
	
	/**
	 * Actually create the TextFragmentDOMElement using runtime
	 * specific API. Overriden by each runtime
	 */
	private function doCreateTextRenderer(text:String, textToken:TextTokenValue):TextRenderer
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the ContainerDOMElement
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
				//a block DOMElement may start a new inline
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
	 * Determine wether the children of this DOMElement
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * TODO : throw exception when there is a float in the children
	 * 
	 * @return true if all children are inline level DOMElements
	 */
	override public function childrenInline():Bool
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//return false for a container with no children
		if (containerDOMElement.children.length == 0)
		{
			return false;
		}
		
		//establish if the first child is inline or block
		//all other child must be of the same type
		var ret:Bool = isChildInline(containerDOMElement.children[0]);
		
		//loop in all children and throw an exception
		//if one the children is not of the same type as the first
		for (i in 0...containerDOMElement.children.length)
		{
			if (isChildInline(containerDOMElement.children[i]) != ret)
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
	 * of the ContainerDOMElement
	 */
	public function getContainerDOMElementData():ContainingDOMElementData
	{
		var height:Int;
		
		//if the ContainerDOMElement
		//is inline level, then its line height will
		//be used to lay out its children in lines
		if (isInlineLevel() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//same if the ContainerDOMElement establishes
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
			isWidthAuto:this._width == DimensionStyleValue.autoValue,
			height:height,
			isHeightAuto:this._height == DimensionStyleValue.autoValue
		};
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the right formatting context to layout this ContainerDOMElement
	 * children.
	 * 
	 * A ContainerDOMElement can either establish a new formatting context
	 * or participate in the current formatting context. If it participates
	 * in the current formatting context, then the previous formatting
	 * is returned else a new block or inline formatting context is
	 * instantiated
	 * 
	 * @param	previousformattingContext the formatting context of the parent of this
	 * Container DOMElement, might be returned if the container DOMElement participates
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
	private function isChildInline(child:ContainerDOMElementChildData):Bool
	{
		var ret:Bool = true;
		
		//here the children is a DOMElement
		if (isDOMElement(child))
		{
			var childrenDOMElement:DOMElement = cast(child.child);
			//here the child is of type block
			if (childrenDOMElement.style.computedStyle.display == block)
			{
				//floated children are not taken into account 
				if (childrenDOMElement.style.isFloat() == false)
				{
					ret = false;
				}
				//absolutely positioned children are not taken into account but relative positioned are
				else if (childrenDOMElement.style.isPositioned() == false || childrenDOMElement.style.isRelativePositioned() == true)
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
	 * children. If this ContainerDOMElement is positioned, a new
	 * structure is created, else the current one is used
	 */
	private function getChildLastPositionedDOMElementData(lastPositionedDOMElementData:LastPositionedDOMElementData):LastPositionedDOMElementData
	{
		var childLastPositionedDOMElementData:LastPositionedDOMElementData;
		
		if (isPositioned() == true)
		{
			childLastPositionedDOMElementData = {
				data: getContainerDOMElementData(),
				children: new Array<PositionedDOMElementData>()
			}
		}
		else
		{
			childLastPositionedDOMElementData = lastPositionedDOMElementData;
		}
		
		return childLastPositionedDOMElementData;
	}

	/**
	 * Determine wheter the container DOMElement
	 * is an inline or block container. For instance,
	 * an inline-block containerDOMElement is both
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
				
			case inlineStyle:
				ret = true;
				
			default:
				ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the computed height of the ContainerDOMElement.
	 * Use as a hook to be overriden by the BodyStyle
	 * to return the viewport height
	 */
	private function getComputedHeight():Int
	{
		return this._computedStyle.height;
	}
	
	/**
	 * Determine wether the given children is a 
	 * DOMElement or a TextElement
	 */
	private function isDOMElement(containerDOMElementChildData:ContainerDOMElementChildData):Bool
	{
		var ret:Bool = false;
		
		switch (containerDOMElementChildData.type)
		{
			case ContainerDOMElementChildValue.domElement:
				ret = true;
			
			case ContainerDOMElementChildValue.textElement:
				ret = false;
		}
		
		return ret;
	}
	
}