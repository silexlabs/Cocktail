/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.RendererData;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.formatter.FormattingContext;
import haxe.Log;
import cocktail.core.geom.GeomData;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;

/**
 * Renders a run of text by creating as many text line box
 * as necessary for each word/space. Also in charge of separating
 * the source text into an array of word, space, tab...
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends ElementRenderer
{
	/**
	 * An array where each item contains a text token,
	 * representing the kind of text contained (a word,
	 * a space, a tab...). For each, a Text Line Box
	 * is created
	 */
	private var _textTokens:Array<TextToken>;
	
	/**
	 * The unedited source text
	 */
	private var _text:Text;
	
	/**
	 * Class constructor.
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_text = cast(node);
		_lineBoxes = null;
	}
	
	override public function layout(firstPositionedAncestorData:FirstPositionedAncestorData):Void
	{	
		//if (lineBoxes == null)
		//{
			createTextLines();
		//}
	}
	
	//TODO 1 IMPORTANT : setting lineBoxes to null causes runtime error in inline formatting context,
	//need to find a better way to refresh text
	override private function invalidateText():Void
	{
		//_lineBoxes = null;
		//invalidateLayout();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually convert a text into an array
	 * of text token.
	 */
	private static function doGetTextTokens(text:String):Array<TextToken>
	{
		var textTokens:Array<TextToken> = new Array<TextToken>();

		var textToken:String = null;
		
		var i:Int = 0;
		
		//Loop in all the text charachters
		while (i < text.length)
		{
			if (text.charAt(i) == "\\")
			{
				if (i <text.length - 1)
				{
					//if a line feed is found
					if (text.charAt(i + 1) == "n")
					{
						if (textToken != null)
						{
							//push the current word into the returned array
							textTokens.push(word(textToken));
							textToken = null;
						}
						//then push a line feed
						textTokens.push(lineFeed);
						i++;
					}
					//if a tab is found
					else if (text.charAt(i + 1) == "t")
					{
						if (textToken != null)
						{
							//push the word into the returned array
							textTokens.push(word(textToken));
							textToken = null;
						}
						//then push a tab
						textTokens.push(TextToken.tab);
						i++;
					}
				}
			}
			
			//If the character is a space
			if (StringTools.isSpace(text, i) == true)
			{
				
				//If a word was being formed by concatenating
				//characters
				if (textToken != null)
				{
					//push the word into the returned array
					textTokens.push(word(textToken));
					textToken = null;
				}
				
				//push the space in the returned array
				textTokens.push(TextToken.space);
			}
			//else the charachter belongs to a word
			//and is added to the word which is being
			//concatenated
			else
			{
				if (textToken == null)
				{
					textToken = "";
				}
				textToken += text.charAt(i);
			}
			
			i++;
		}
		
		//push the remaining word if text doesn't end with a space
		//or control character
		if (textToken != null)
		{
			textTokens.push(word(textToken));
		}

		return textTokens;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Separate the source text in an array of text token
	 * and create a text line box for each one
	 * 
	 * TODO 2 : shouldn't have to recreate text token unless
	 * node value changes
	 */
	private function createTextLines():Void
	{
		_textTokens = doGetTextTokens(_text.nodeValue);
		lineBoxes = [];
		
		var length:Int = _textTokens.length;
		for (i in 0...length)
		{
			//create and store the line boxes
			lineBoxes.push(createTextLineBoxFromTextToken(_textTokens[i]));
		}
	}
	
	/**
	 * Create and return a Text line box from a text token
	 */
	private function createTextLineBoxFromTextToken(textToken:TextToken):TextLineBox
	{
		//the text of the created text line box
		var text:String;
		
		switch(textToken)
		{
			case word(value):
				text = value;
		
			case space:
				text = " ";
				
			//TODO 5 : implement tab and line feed	
			case tab:
				text = "";
				
			case lineFeed:
				text = "";
		}
		
		var textLineBox:TextLineBox = new TextLineBox(this, text);
		
		return textLineBox;
	}

	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	////////////////////////////////

	override public function isFloat():Bool
	{
		return false;
	}
	
	override public function isPositioned():Bool
	{
		return false;
	}
	
	override public function isText():Bool
	{
		return true;
	}
	
	override public function isInlineLevel():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	////////////////////////////////
	
	/**
	 * Overriden as the bounds of a TextRenderer is formed
	 * by the bounds of its formatted text line boxes
	 * 
	 * TODO 4 : messy to return a new bounds
	 */
	override private function get_bounds():RectangleData
	{
		if (_lineBoxes == null)
		{
			return {
				x:0.0,
				y:0.0,
				width:0.0,
				height:0.0
			}
		}
		var textLineBoxesBounds:Array<RectangleData> = new Array<RectangleData>();
		var length:Int = _lineBoxes.length;
		for (i in 0...length)
		{
			textLineBoxesBounds.push(_lineBoxes[i].bounds);
		}
		return getChildrenBounds(textLineBoxesBounds);
	}
	
	override private function getLineBoxes():Array<LineBox>
	{
		if (_lineBoxes == null)
		{
			return [];
		}
		return _lineBoxes;
	}
	
	
}