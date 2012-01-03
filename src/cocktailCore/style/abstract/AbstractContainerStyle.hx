/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.viewport.Viewport;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.domElement.TextFragmentDOMElement;
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
import cocktailCore.textElement.abstract.AbstractTextElement;
import cocktailCore.textElement.TextElementData;
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
 * also start the layout on each of its children
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerStyle extends Style
{
	/**
	 * class constructor
	 * @param	domElement
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is overriden to start a recursive layout when called on a ContainerDOMElement. The ContainerDOMElement
	 * will be measured and placed as well as all its children
	 */
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		flow(containingDOMElementData, viewportData, lastPositionedDOMElementData, null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null):Void
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
			//TextElement don't influence which type of formatting context will
			//be used and when rendered, they use the ContainerDOMElement's styles
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.computeDisplayStyles();
			}
		}
		
		//The children use either a new Formatting context to
		//be laid out into if the ContainerDOMElement establishes
		//a new formatting context or use the current formatting
		//context
		var childrenFormattingContext:FormattingContext;
		
		//if the FormattingContext is null, this ContainerDOMElement
		//is the first to be laid out, it is not necessarily the root
		//DOMElement of the document as any DOMElement can trigger
		//a layout
		if (formatingContext == null)
		{
			formatingContext = getFormatingContext();
			childrenFormattingContext = getFormatingContext();
		}
		else
		{
			childrenFormattingContext = getFormatingContext(formatingContext);
		}
		
		//get the dimensions that will be used to lay out the children
		//of the DOMElement. If the ContainerDOMElement establishes an
		//inline formatting context, then its lineHeight will be used
		//instead of its height as containing height
		var childrenContainingDOMElementData:ContainingDOMElementData = getContainerDOMElementData();
		
		//get the computed font metrics of the ContainerDOMElement. Those metrics
		//are based on the font and the font size used
		var childrenContainingDOMElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children
		var childLastPositionedDOMElementData:LastPositionedDOMElementData;
		
		//if the ContainerDOMElement is positioned, it becomes the last positioned DOMElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned will be
		//stored and once this ContainerDOMElement is laid out, it will position all those children. the layout
		//of absolutely positioned children must happen once the dimensions of this ContainerDOMElement are known so
		//that children can be positioned using the 'bottom' and 'right' styles
		childLastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
		
		//flow all children 
		doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
		
		//destroy the current formatting context, prompting
		//to clean up all references it might have and also
		//lays out the last line of DOMElement for an
		//inline formatting context
		//This method is only called if a new formatting
		//context was established by this ContainerDOMElement,
		//meaning that the previous formatting context needs to
		//be destroyed.
		if (childrenFormattingContext != formatingContext)
		{
			childrenFormattingContext.destroy();
		}
		
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		if (this._width == DimensionStyleValue.autoValue)
		{
			
			var currentWidth:Int = this._computedStyle.width;
			this._computedStyle.width = shrinkToFitIfNeeded(containingDOMElementData, childrenFormattingContext.flowData.maxWidth);
			
			//if the computed width of the ContainerDOMElement was shrinked, then
			//a new layout must happen
			if (currentWidth != this._computedStyle.width)
			{
				//update the structure used for the layout and starts a new layout
				childrenFormattingContext = getFormatingContext(formatingContext);
				childrenContainingDOMElementData = getContainerDOMElementData();
				childLastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
				doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
		}
		
		//if the 'height' style of this ContainerDOMElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized. Fort some border case though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._height == DimensionStyleValue.autoValue)
		{
			this._computedStyle.height = applyContentHeightIfNeeded(containingDOMElementData, childrenFormattingContext.flowData.totalHeight);
		}

		//insert the ContainerDOMElement into the document
		insertDOMElement(formatingContext, lastPositionedDOMElementData, viewportData);

		//retrieve the floats overflowing from the children of this ContainerDOMElement, 
		//that will also affect the position of its following siblings
		formatingContext.retrieveFloats(childrenFormattingContext);
		
		//if the childLastPositionedDOMElementData is different from the lastPositionedDOMElementData
		//it means that this ContainerDOMElement is the first positioned ancestor for its children
		//and it is its responsability to position them
		var isFirstPositionedAncestor:Bool = childLastPositionedDOMElementData != lastPositionedDOMElementData;
		doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor, childLastPositionedDOMElementData, viewportData);
	}
	
	/**
	 * Overriden as ContainerDOMElement is only added to the flow if it is not inline.
	 * If it is inline, only its children are added in the flow.
	 */
	override private function insertInFlowDOMElement(formattingContext:FormattingContext):Void
	{
		if (isInline() == false || isInlineFlow() == false )
		{
			super.insertInFlowDOMElement(formattingContext);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually flow all the children of the ContainerDOMElement
	 */
	private function doFlowChildren(childrenContainingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, childLastPositionedDOMElementData:LastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//flow all children 
		for (i in 0...containerDOMElement.children.length)
		{
			//if the children is a DOMElement, call its flow method
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				//the flow method also lays out recursively all the children of the childrenDOMElement
				//if it is a ContainerDOMElement
				childrenDOMElement.style.flow(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
			//else if it is a TextElement, call a method that will create as many TextFragmentDOMElement
			//as necessary to render the TextElement and insert them into the document
			else 
			{
				var childrenTextElement:TextElement = cast(containerDOMElement.children[i].child);
				insertTextElement(childrenTextElement, childrenFormattingContext, childrenContainingDOMElementData);
			}
		}
	}
	
	/**
	 * When this ContainerDOMElement is positioned, position each of its children using it
	 * as its origin. This method is called once all the dimensions of ContainerDOMElement
	 * are known so that absolutely positioned children can be positioned using the bottom
	 * and right styles
	 */
	private function doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor:Bool, childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		if (isFirstPositionedAncestor == true)
		{
			//update the data of the ContainerDOMElement now that its width and height are known
			childLastPositionedDOMElementData.data = getContainerDOMElementData();
			//position each stored children
			for (i in 0...childLastPositionedDOMElementData.children.length)
			{
				var positionedDOMElementData:PositionedDOMElementData = childLastPositionedDOMElementData.children[i];
				positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data, viewportData, positionedDOMElementData.staticPosition );
			}
		}
	}
	
	/**
	 * Insert a TextElement ( a string of text without formatting ) by creating as many TextFragmentDOMElement as needed from it
	 * and inserting them into the flow
	 * @param	textElement the string of text used as content for the created text lines
	 */
	private function insertTextElement(textElement:TextElement, formattingContext:FormattingContext, containingDOMElementData:ContainingDOMElementData):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);

		//get the text to display from the TextElement
		var text:String = textElement.getNativeText();
		
		//apply the white space rule defined by the WhiteSpaceStyleValue to the text
		text = AbstractTextElement.applyWhiteSpace(text, this._computedStyle.whiteSpace);
		
		//split the text into an array of text token
		var textFragments:Array<TextFragmentData> = textElement.getTextFragments(text);
		
		//loop through the text tokens
		for (i in 0...textFragments.length)
		{
			switch(textFragments[i].textToken)
			{
				case word(value):
					//insert a word in the flow
					formattingContext.insert(getTextFragmentDOMElement(textFragments[i], value));
					
					
				case space:
					//insert a space in the flow
					formattingContext.insertSpace(getTextFragmentDOMElement(textFragments[i], " "));
					
					
				case tab:
					//insert a tab in the flow
					formattingContext.insertTab(getTextFragmentDOMElement(textFragments[i], " "));
					
					
				case lineFeed:
					//start a new line
					formattingContext.insertLineFeed();
			}
		}		
	}
	
	/**
	 * In certain cases, when the width of the ContainerDOMElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line form by its children or the width of its
	 * container if the children overflows
	 * 
	 * @param	containingDOMElementData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this ContainerDOMElement which will be the minimum width that should
	 * have this DOMElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		return boxComputer.shrinkToFit(this, containingDOMElementData, minimumWidth);
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
	// OVERRIDEN PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When invalidating text on a ContainerDOMElement, the created TextFragmentDOMElement
	 * must be deleted so that they can be redrawn on next layout
	 */
	override private function invalidateText():Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		containerDOMElement.resetTextFragments();	
		super.invalidateText();
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE TEXT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Take a TextFragmentData and a text, and create
	 * a TextFragmentDOMElement from it if it does'nt already
	 * exists. If it does, return it
	 */
	private function getTextFragmentDOMElement(textFragmentData:TextFragmentData, text:String):TextFragmentDOMElement
	{
		var textFragmentDOMElement:TextFragmentDOMElement;
		
		if (textFragmentData.textFragmentDOMElement == null)
		{
			textFragmentDOMElement = createTextFragment(text);
			textFragmentData.textFragmentDOMElement = textFragmentDOMElement;
		}
		else
		{
			textFragmentDOMElement = textFragmentData.textFragmentDOMElement;
		}
		
		return textFragmentDOMElement;
	}
	
	/**
	 * Create a TextFragmentDOMElement from a string of text and
	 * add it to the ContainerDOMElement
	 */
	private function createTextFragment(text:String):TextFragmentDOMElement
	{
		var textFragmentDOMElement:TextFragmentDOMElement = doCreateTextFragment(text);
	
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		containerDOMElement.addTextFragment(textFragmentDOMElement);
		
		return  textFragmentDOMElement;
	}
	
	/**
	 * Actually create the TextFragmentDOMElement using runtime
	 * specific API. Overriden by each runtime
	 */
	private function doCreateTextFragment(text:String):TextFragmentDOMElement
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the dimensions and position data
	 * of the ContainerDOMElement
	 */
	public function getContainerDOMElementData():ContainingDOMElementData
	{
		var height:Int;
		
		//if the ContainerDOMElement
		//is inline, then its line height will
		//be used to lay out its children in lines
		if (isInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//same if the ContainerDOMElement starts
		//an inline formatting context
		else if (isInline() == false && childrenInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//else it starts a block formatting context
		//and its height is used
		else
		{
			height = this._computedStyle.height;
		}
		
		return {
			width:this._computedStyle.width,
			isWidthAuto:this._width == DimensionStyleValue.autoValue,
			height:height,
			isHeightAuto:this._height == DimensionStyleValue.autoValue,
			globalX:this._domElement.globalX,
			globalY:this._domElement.globalY
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
	 * INLINE FLOW CONTAINER DOMELEMENT
	 * 
	 * If the container DOMElement itself is an inline flow DOMElement
	 * (it flows its children in an inline formatting context), the
	 * container DOMElement participates in the previous formatting context
	 * 
	 * BLOCK FLOW CONTAINER DOMELEMENT
	 * 
	 * If the container DOMElement itself is a block flow DOMElement, (it can
	 * layout its children either in an inline or block formatting context)
	 * ,it establishes a new formatting context for its children. If all its 
	 * children are inline level, an inline formatting context is instantiated,
	 * else if all its children are block level, a block level formatting context
	 * is instantiated. If its children mix inline and block level DOMElement,
	 * inline formatting context is the default.
	 * 
	 * 
	 * @param	previousFormatingContext the formatting context of the parent of this
	 * Container DOMElement, might be returned if the container DOMElement participates
	 * in the same formatting context as its parent
	 * 
	 * @return an inline or block formatting context
	 */
	private function getFormatingContext(previousFormatingContext:FormattingContext = null):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		var formattingContext:FormattingContext;
		
		//here, a new formatting context is created
		if (startsNewFormattingContext() == true)
		{
			//the formatting context that will be passed to the
			//new formatting context
			var usedFormatingContext:FormattingContext;
			
			//If the container DOMElement is absolutely positioned, then it belongs to a
			//different stacking context than the curent flow and is not influenced by the previously
			//declared float, so it doesn't use the previousFormattingContext
			if (isPositioned() == true && isRelativePositioned() == false)
			{
				usedFormatingContext = null;
			}
			else
			{
				usedFormatingContext = previousFormatingContext;
			}
			
			//instantiate the right formatting context
			//based on the children display
			if (childrenInline() == true)
			{
				formattingContext = new InlineFormattingContext(containerDOMElement, usedFormatingContext);	
			}
			else
			{
				formattingContext = new BlockFormattingContext(containerDOMElement, usedFormatingContext);
			}
		}
		else
		{
			formattingContext = previousFormatingContext;
		}
		
		
		return formattingContext;
	}
	
	/**
	 * Determine wether the children of this DOMElement
	 * are all block level or if they are all inline level
	 * elements
	 * @return true if all children are inline DOMElements
	 */
	private function childrenInline():Bool
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
		
		if (this.isPositioned() == true)
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
	 * Determine wether a block container
	 * starts a new formatting context for
	 * its children
	 */
	private function startsNewFormattingContext():Bool
	{
		var ret:Bool = false;
		
		//floats starts new context
		if (isFloat() == true)
		{
			ret = true;
		}
		//positioned element which are not relative start new context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			ret = true;
		}
		//element with a block/inline-block display style
		//start a new context
		else
		{
			switch (this._computedStyle.display)
			{
				case block, inlineBlock:
					ret = true; 
					
				default:
			}
		}
		
		//in the other cases such as an inline container
		//the current formatting context is used
		
		return ret;
	}
	
	/**
	 * Determine wheter the container DOMElement
	 * is an inline or block flow. For instance,
	 * an inline-block containerDOMElement is both
	 * inline (because it is placed on a line) and
	 * a block flow, because it can layout its
	 * children either into either a block or
	 * inline formatting context
	 */
	private function isInlineFlow():Bool
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