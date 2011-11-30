/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.abstract;

import cocktail.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.TextLineDOMElement;
import cocktail.domElement.TextNode;
import cocktail.style.formatter.BlockFormattingContext;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.formatter.InlineFormattingContext;
import cocktail.style.positioner.AbsolutePositioner;
import cocktail.style.positioner.BoxPositioner;
import cocktail.style.positioner.FixedPositioner;
import cocktail.style.positioner.RelativePositioner;
import cocktail.style.StyleData;
import cocktail.domElement.DOMElementData;

#if flash9
import cocktail.style.as3.Style;
#elseif js
import cocktail.style.js.Style;
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
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private var _serifFontName:String;
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private var _sansSerifFontName:String;
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font
	 */
	private var _monospaceFontName:String;
	
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
		
		containerDOMElement.resetTextLines();
		
		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0...containerDOMElement.children.length)
		{
			//only DOMElement styles are computed, not TextNode element's.
			//TextNode don't influence which type of formatting context will
			//be used as when rendered, they use the ContainerDOMElement's styles
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.computePositionStyle();
			}
		}
		
		//a new FormattingContext must be created for the children of the 
		//ContainerDOMElement as they will be laid out inside the ContainerDOMElement 
		//using its width and height
		var childrenFormattingContext:FormattingContext;
		
		//if the FormattingContext is null, this ContainerDOMElement
		//is the first to be laid out, it is not necessary the root
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
		//instead of its height
		var childrenContainingDOMElementData:ContainingDOMElementData = getChildrenContainingDOMElementData();
		
		//get the computed font metrics of the ContainerDOMElement. Those metrics
		//are based on the font and the font size used
		var childrenContainingDOMElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//pass a reference to the dimensions of the first positioned ancestor of the 
		//ContainerDOMElement
		var childLastPositionedDOMElementDimensions:ContainingDOMElementData = lastPositionedDOMElementDimensions;
		
		//if the ContainerDOMElement is positioned, it becomes the last positioned DOMElement for the children it
		//lays out, and will be used as origin for absolutely positioned children
		if (this.isPositioned() == true)
		{
			childLastPositionedDOMElementDimensions = getChildrenContainingDOMElementData();
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
			//else if it is a text node, call a method that will create as many TextLineDOMElement
			//as necessary to render the TextNode and insert them into the document
			else 
			{
				var childrenTextNode:TextNode = cast(containerDOMElement.children[i].child);
				insertTextNode(childrenTextNode, childrenFormattingContext, childrenContainingDOMElementData, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, containingDOMElementFontMetricsData);
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
		//defined as 'auto', then it depends on its content width
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized
		if (this._height == DimensionStyleValue.auto)
		{
			this._computedStyle.height = childrenFormattingContext.flowData.totalHeight;
		}
		
		//insert the ContainerDOMElement into the document
		insertDOMElement(formatingContext, lastPositionedDOMElementDimensions, rootDOMElementDimensions);

		//retrieve the floats overflowing from the children of this ContainerDOMElement, 
		//that will also affect the position of its following siblings
		formatingContext.retrieveFloats(childrenFormattingContext);
		
	}
	
	/**
	 * Overriden as ContainerDOMElement is only added to the flow if it is not inline.
	 * If it is inline, only its children are added in the flow.
	 */
	override private function insertInFlowDOMElement(formattingContext:FormattingContext):Void
	{
		if (isInline() == false)
		{
			super.insertInFlowDOMElement(formattingContext);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Insert a text node ( a string of text without formatting ) by creating as many text lines as needed from it
	 * and inserting them into the document
	 * @param	textNode the string of text used as content for the created text lines
	 */
	private function insertTextNode(textNode:TextNode, formattingContext:FormattingContext, containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);

		var textFragments:Array<TextFragmentValue> = getTextFragments(getNativeText(textNode));
		for (i in 0...textFragments.length)
		{
			switch(textFragments[i])
			{
				case word(value):
					var textLineDOMElement:TextLineDOMElement = createTextLine(value);
					if (textLineDOMElement.nativeElement != null)
					{
						formattingContext.insert(textLineDOMElement);
					}
					
				case space:
					var textLineDOMElement:TextLineDOMElement = createTextLine(" ");
					if (textLineDOMElement.nativeElement != null)
					{
						formattingContext.insertSpace(textLineDOMElement);
					}
					
				case tab:
					var textLineDOMElement:TextLineDOMElement = createTextLine(" ");
					formattingContext.insertTab(textLineDOMElement);
					
				case lineFeed:
					formattingContext.startNewLine(0);
			}
		}
				
	}
	
	/**
	 * Create and return a TextLineDOMElement of the specified width using the provided
	 * TextNode as model
	 * @param	width the desired width for the created text line. As many as possible glyphs will
	 * be added to the line until adding another glyph would make the text line too wide, so 
	 * the actual width of the line will probably be a bit inferior to the specified width. 
	 * It might also be inferior if there is not enough text to fill the specified width
	 * @param	textNode the string of unformatted text to use as the model to create the
	 * text line. If the createTextLine method is called multiple times in a row with the
	 * same TextNode, text lines will be created until all of the TextNode text has been rendered
	 * as text lines.
	 * @return either a TextLineDOMElement or null if the TextNode model has run out of text to 
	 * render
	 */
	private function createTextLine(text:String):TextLineDOMElement
	{
		var textLineDOMElement:TextLineDOMElement = doCreateTextLine(text);
		
		//stores the text lines to easily remove it on the next layout
		//and add it as a child of this ContainerDOMElement nativeElement
		//so that it can appear in the DOM
		
		if (textLineDOMElement.nativeElement != null)
		{
			var containerDOMElement:ContainerDOMElement = cast(this._domElement);
			containerDOMElement.addTextLine(textLineDOMElement);
		}
		
		return  textLineDOMElement;
	}
	
	private function doCreateTextLine(text:String):TextLineDOMElement
	{
		//implemented by each runtime :
		// create and style native element
		// wrap it in textlineDOMElement
		// add it as a text line children of the container DOM Element
		return null;
	}
	
	private function getTextFragments(text:String):Array<TextFragmentValue>
	{
		switch (_computedStyle.whiteSpace)
		{
			case WhiteSpaceStyleValue.normal:
				text = collapseSpaceSequences(text);
				
			case WhiteSpaceStyleValue.pre:
				text = removeLineFeeds(text);
				
			case WhiteSpaceStyleValue.nowrap:
				text = collapseSpaceSequences(text);
				text = removeLineFeeds(text);
				text = convertTabToSpace(text);
				
			case WhiteSpaceStyleValue.preWrap:
				
			case WhiteSpaceStyleValue.preLine:
				text = collapseSpaceSequences(text);
		}
		
		var textFragments:Array<TextFragmentValue> = new Array<TextFragmentValue>();
		
		var textFragment:String = "";
		
		var i:Int = 0;
		
		
		
		//Loop in all the text charachters
		while (i < text.length)
		{
			if (text.charAt(i) == "\\")
			{
				if (text.charAt(i + 1) != null)
				{
					if (text.charAt(i + 1) == "n")
					{
						if (textFragment != null)
						{
							//push the word into the returned array
							textFragments.push(word(textFragment));
							textFragment = null;
						}
						textFragments.push(lineFeed);
						i ++;
					}
					else if (text.charAt(i + 1) == "t")
					{
						if (textFragment != null)
						{
							//push the word into the returned array
							textFragments.push(word(textFragment));
							textFragment = null;
						}
						textFragments.push(tab);
						i ++;
					}
				}
			}
			
			//If the charachter is a space
			else if (StringTools.isSpace(text, i) == true)
			{
				
				//If a word was being formed by concatenating
				//characters
				if (textFragment != null)
				{
					//push the word into the returned array
					textFragments.push(word(textFragment));
					textFragment = null;
				}
				
				//push the space in the returned array
				textFragments.push(space);
			}
			//else the charachter belongs to a word
			//and is added to the word which is being
			//concatenated
			else
			{
				if (textFragment == null)
				{
					textFragment = "";
				}
				textFragment += text.charAt(i);
			}
			
			i++;
		}
		
		//push the remaining word if text doesn't end with a space
		if (textFragment != null)
		{
			textFragments.push(word(textFragment));
		}
		
		return textFragments;
	}
	
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
	
	private function removeLineFeeds(text:String):String
	{
		return StringTools.replace(text, "\n", "");
	}
	
	private function convertTabToSpace(text:String):String
	{
		return StringTools.replace(text, "\t", " ");
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
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names.
	 * @param	value an array which may contain any combination of generic
	 * font family name and font family name
	 * @return a comma separated list of font, genrally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	private function getFontFamilyValue(value:Array<FontFamilyStyleValue>):String
	{
		var fontFamilyValue:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String;
			
			switch (value[i])
			{
				case FontFamilyStyleValue.familyName(name):
					fontName = name;
				
				case FontFamilyStyleValue.genericFamily(genericName):
					switch (genericName)
					{
						case GenericFontFamilyValue.serif:
							fontName = this._serifFontName;
						
						case GenericFontFamilyValue.sansSerif:
							fontName = this._sansSerifFontName;
							
						case GenericFontFamilyValue.monospace:
							fontName = this._monospaceFontName;
					}
			}
			
			fontFamilyValue += fontName;
			
			if (i < value.length - 1)
			{
				fontFamilyValue += ",";
			}
		}
		
		return fontFamilyValue;
	}
	
	/**
	 * Return a String from a TextNode
	 * using runtime specific method
	 */
	private function getNativeText(textNode:TextNode):String
	{
		//abstract implemented by each runtime
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate the right formatting context for this ContainerDOMElement.
	 * 
	 * If the container DOMElement itself is an inline level DOMElement, all
	 * its children must be formatted as inline and thus an Inline formatting 
	 * context is returned
	 * 
	 * If the container DOMElement itself is a block level DOMElement, if all its
	 * children are inline level, an inline formatting context is instantiated, else
	 * if all its children are block level, a block level formatting context is
	 * instantiated. If its children mix inline and block level DOMElement, 
	 * block formatting context is the default
	 * 
	 * Lastly, if this container DOMElement is inline meaning it participates in
	 * an inline formatting context and the previous formatting context is already
	 * an inline formatting context, then this formatting context is used, none
	 * is instantiated. This case mainluy happens when block of text are formatted
	 * combining multiple elements (bold text, italic text...)
	 * 
	 * 
	 * @param	previousFormatingContext the formatting context of the parent of this
	 * Container DOMElement, used to retrieve floats position from it which might also
	 * apply to this container DOMElement
	 * 
	 * @return an inline or block formatting context
	 */
	private function getFormatingContext(previousFormatingContext:FormattingContext = null):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		var ret:FormattingContext;
		
		if (isInline() && Std.is(previousFormatingContext, InlineFormattingContext))
		{
			ret = previousFormatingContext;
		}
		
		else if (childrenInline() == true)
		{
			ret = new InlineFormattingContext(containerDOMElement, previousFormatingContext);	
		}
		else
		{
			ret = new BlockFormattingContext(containerDOMElement, previousFormatingContext);
		}
		
		return ret;
	}
	
	private function getChildrenContainingDOMElementData():ContainingDOMElementData
	{
		var height:Int;
		
		if (isInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		else if (isInline() == false && childrenInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
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
				
				if (childrenDOMElement.style.computedStyle.display == block && childrenDOMElement.style.isFloat() == false )
				{
					if (childrenDOMElement.style.isFloat() == false)
					{
						ret = false;
					}
					else if (childrenDOMElement.style.isEmbedded() == true)
					{
						ret = false;
					}
					
				}
			}
		}
		
		return ret;
	}
	
	/**
	 * Determine wether the given children is a 
	 * DOMElement or a TextNode
	 */
	private function isDOMElement(containerDOMElementChildData:ContainerDOMElementChildData):Bool
	{
		var ret:Bool = false;
		
		switch (containerDOMElementChildData.type)
		{
			case ContainerDOMElementChildValue.domElement:
				ret = true;
			
			case ContainerDOMElementChildValue.textNode:
				ret = false;
		}
		
		return ret;
	}
	
}