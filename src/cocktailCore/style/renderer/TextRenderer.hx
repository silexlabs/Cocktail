/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.renderer;

import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktailCore.textElement.TextElementData;
import haxe.Log;

/**
 * Renders a text
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends ElementRenderer
{

	/**
	 * The text token (word, space, tab...)
	 * used to generate the TextRenderer
	 */
	private var _textToken:TextTokenValue;
	
	/**
	 * Class constructor. Set the width and height bounds
	 * to those of the generated text
	 * 
	 * @param domElement the generated text
	 */
	public function new(domElement:DOMElement, textToken:TextTokenValue) 
	{
		_textToken = textToken;
		
		super(domElement);
		
		_bounds.width = domElement.offsetWidth;
		_bounds.height = domElement.offsetHeight;
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Renders the text using runtime specific API and return
	 * the text NativeElement
	 */
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		#if flash9
		_domElement.nativeElement.x = _bounds.x;
		_domElement.nativeElement.y = _bounds.y;
		#elseif nme
		_domElement.nativeElement.x = _bounds.x;
		_domElement.nativeElement.y = _bounds.y - (_domElement.style.fontMetrics.ascent + _domElement.style.fontMetrics.descent);
		#end
		
		ret.push(_domElement.nativeElement);
		
		return ret;
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
	
	override public function isSpace():Bool
	{
		var isSpace:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.space:
				isSpace = true;
				
			default:
				isSpace = false;
		}
		
		return isSpace;
	}
	
	override public function isLineFeed():Bool
	{
		var isLineFeed:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.lineFeed:
				isLineFeed = true;
				
			default:
				isLineFeed = false;
		}
		
		return isLineFeed;
	}
	
	override public function isTab():Bool
	{
		var isTab:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.tab:
				isTab = true;
				
			default:
				isTab = false;
		}
		
		return isTab;
	}
	
	
	
}