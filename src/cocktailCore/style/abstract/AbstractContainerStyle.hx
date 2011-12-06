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
import cocktailCore.style.StyleData;
import cocktail.domElement.DOMElementData;
import cocktailCore.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import cocktailCore.textElement.TextElementData;
import haxe.Timer;

#if flash9
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
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElement:ContainingDOMElementData, rootDOMElement:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		flow(containingDOMElementData, rootDOMElement, lastPositionedDOMElement, null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null):Void
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
			//formatingContext = getFormatingContext();
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
		var childLastPositionedDOMElementDimensions:ContainingDOMElementData;
		
		//if the ContainerDOMElement is positioned, it becomes the last positioned DOMElement for the children it
		//lays out, and will be used as origin for absolutely positioned children
		if (this.isPositioned() == true)
		{
			childLastPositionedDOMElementDimensions = getContainerDOMElementData();
		}
		//
		else
		{
			childLastPositionedDOMElementDimensions = lastPositionedDOMElementDimensions;
		}
		
		//flow all children 
		for (i in 0...containerDOMElement.children.length)
		{
			//if the children is a DOMElement, call its flow method
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				//the flow method also lays out recursively all the children of the childrenDOMElement
				//if it is a ContainerDOMElement
				childrenDOMElement.style.flow(childrenContainingDOMElementData, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
			//else if it is a TextElement, call a method that will create as many TextFragmentDOMElement
			//as necessary to render the TextElement and insert them into the document
			else 
			{
				var childrenTextElement:TextElement = cast(containerDOMElement.children[i].child);
				insertTextElement(childrenTextElement, childrenFormattingContext, childrenContainingDOMElementData, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, containingDOMElementFontMetricsData);
			}
		}
		
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
		
		
		//if the 'height' style of this ContainerDOMElement is 
		//defined as 'auto', then it depends on its content height
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized
		if (this._height == DimensionStyleValue.auto)
		{
			this._computedStyle.height = childrenFormattingContext.flowData.totalHeight;
		}
		
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		if (this._width == DimensionStyleValue.auto)
		{
			this._computedStyle.width = shrinkToFitIfNeeded(containingDOMElementData.width, childrenFormattingContext.flowData.maxWidth);
		}
		
		if (formatingContext != null)
		{
			//insert the ContainerDOMElement into the document
			insertDOMElement(formatingContext, lastPositionedDOMElementDimensions, rootDOMElementDimensions);

			//retrieve the floats overflowing from the children of this ContainerDOMElement, 
			//that will also affect the position of its following siblings
			formatingContext.retrieveFloats(childrenFormattingContext);
		}
	
		
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
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function invalidate():Void
	{
		
		if (this._isInvalid == false)
		{
			this._isInvalid = true;
			
			if (this._domElement.parent != null)
			{
				this._domElement.parent.style.invalidate();	
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function invalidateText():Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		containerDOMElement.resetTextFragments();	
		super.invalidateText();
		
	}
	
	
	private function doLayout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		var layoutDelegate:ContainingDOMElementData->ContainingDOMElementData->ContainingDOMElementData->FontMetricsData->Void = layout;
		
		Timer.delay(function () { 
			layoutDelegate(containingDOMElementData, lastPositionedDOMElementData, viewportData, null);
		}, 1);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Insert a TextElement ( a string of text without formatting ) by creating as many TextFragmentDOMElement as needed from it
	 * and inserting them into the flow
	 * @param	textElement the string of text used as content for the created text lines
	 */
	private function insertTextElement(textElement:TextElement, formattingContext:FormattingContext, containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);

		//get the text to display from the TextElement
		var text:String = textElement.getNativeText();
		
		//apply the white space rule defined by the WhiteSpaceStyleValue to the text
		text = applyWhiteSpace(text, this._computedStyle.whiteSpace);
		
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
	 * @param	availableWidth the width of the container of this containerDOMElement
	 * @param	maxWidth the width of the widest line of children laid out
	 * by this ContainerDOMElement
	 */
	private function shrinkToFitIfNeeded(availableWidth:Int, minimumWidth:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		return boxComputer.shrinkToFit(this._computedStyle, availableWidth, minimumWidth);
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
	// PRIVATE TEXT HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply the whiteSpace style rule to a text
	 */
	private function applyWhiteSpace(text:String, whiteSpace:WhiteSpaceStyleValue):String
	{
		var ret:String = text;
		
		switch (whiteSpace)
		{
				case WhiteSpaceStyleValue.normal:
					ret = collapseSpaceSequences(text);
					
				case WhiteSpaceStyleValue.pre:
					ret = removeLineFeeds(text);
					
				case WhiteSpaceStyleValue.nowrap:
					ret = collapseSpaceSequences(text);
					ret = removeLineFeeds(text);
					ret = convertTabToSpace(text);
					
				case WhiteSpaceStyleValue.preWrap:
					
				case WhiteSpaceStyleValue.preLine:
					ret = collapseSpaceSequences(text);
		}
		
		return ret;
	}
	
	/**
	 * Transform a text letters into uppercase, lowercase
	 * or capitalise them (only the first letter of each word
	 * is transformed to uppercase), based on the textTransform
	 * style of this container DOMElement
	 * @param	text the text to transform
	 * @return the transformed text
	 */
	private function applyTextTransform(text:String):String
	{
		switch (_computedStyle.textTransform)
		{
			case uppercase:
				text = text.toUpperCase();
				
			case lowercase:
				text = text.toLowerCase();
				
			case capitalize:
				text = capitalizeText(text);
				
			case none:
		}
		
		return text;
	}
	
	/**
	 * Capitalise a text (turn each first letter
	 * of a word to uppercase)
	 * @param	text the text to capitaliee
	 * @return the capitalized
	 */
	private function capitalizeText(text:String):String
	{
		var capitalizedText:String = text.charAt(0);
		
		/**
		 * loop in all charachter looking for word breaks
		 * and capitalize each word's first letter
		 */
		for (i in 1...text.length)
		{	
			if (text.charAt(i - 1) == " ")
			{
				capitalizedText += text.charAt(i).toUpperCase();
			}
			else
			{
				capitalizedText += text.charAt(i);
			}
		}
		return capitalizedText;
	}
	
	/**
	 * Convert sequences of spaces in a text
	 * into a single space
	 */
	private function collapseSpaceSequences(text:String):String
	{
		var collapsedText:String = "";
		var isSpaceSequence:Bool = false;
		
		for (i in 0...text.length)
		{
			if (StringTools.isSpace(text, i))
			{
				if (isSpaceSequence == false)
				{
					collapsedText += text.charAt(i);
					isSpaceSequence = true;
				}
			}
			else
			{
				isSpaceSequence = false;
				collapsedText += text.charAt(i);
			}
		}
		
		return collapsedText;
	}
	
	/**
	 * Removes the new line control character
	 * from a text
	 */
	private function removeLineFeeds(text:String):String
	{
		return StringTools.replace(text, "\n", "");
	}
	
	/**
	 * Removes the tabulation control character
	 * from a text by converting them to space
	 * character
	 */
	private function convertTabToSpace(text:String):String
	{
		return StringTools.replace(text, "\t", " ");
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
	 * Return the dimensions and position data
	 * of the ContainerDOMElement
	 */
	private function getContainerDOMElementData():ContainingDOMElementData
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
			isWidthAuto:this._width == DimensionStyleValue.auto,
			height:height,
			isHeightAuto:this._height == DimensionStyleValue.auto,
			globalX:this._domElement.globalX,
			globalY:this._domElement.globalY
		};
	}
	
	/**
	 * Determine wether the children of this DOMElement
	 * are all block level or if they are all inline level
	 * elements
	 * @return true if all children are inline DOMElements
	 */
	private function childrenInline():Bool
	{
		var ret:Bool = true;
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		for (i in 0...containerDOMElement.children.length)
		{
			if (isDOMElement(containerDOMElement.children[i]))
			{
				//if one of the children is a block level DOMElement, then the container
				//is block level
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				
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
			}
		}
		
		return ret;
	}
	
	/**
	 * Determin wether a block container
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