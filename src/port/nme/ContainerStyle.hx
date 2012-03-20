/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.nme;

import core.dom.HTMLElement;
import core.style.AbstractContainerStyle;
import core.style.AbstractStyle;
import core.style.StyleData;
import core.style.renderer.TextRenderer;
import core.Text.abstract.AbstractTextElement;
import core.Text.TextElementData;
import core.unit.UnitManager;
import core.unit.UnitData;
import flash.text.TextFieldAutoSize;

import haxe.Log;

import flash.text.TextFormat;

/**
 * This is the Flash AS3 implementation of the ContainerStyle.
 * 
 * This class implement the Flash specific text fragment creation
 * using the flash text engine introduced in flash player 10.
 * 
 * It's purpose is to create as many TextRenderer as necessary
 * to render every TextElement of the styled ContainerDOMElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	

	override private function doCreateTextRenderer(text:String, textToken:TextTokenValue):TextRenderer
	{
		text = AbstractTextElement.applyTextTransform(text, _computedStyle.textTransform);
		
		var textField:flash.text.TextField = new flash.text.TextField();
		textField.text = text;
		textField.selectable = false;
		textField.autoSize = TextFieldAutoSize.LEFT;
		textField.setTextFormat(getTextFormat());
		
		var textRenderer:TextRenderer = new TextRenderer(_domElement, textField, textToken);

		//wrap the flash text line in a TextRenderer
		return textFragment;

	}	
	
	private function getTextFormat():TextFormat
	{
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = getNativeFontFamily(_computedStyle.fontFamily);
		
		textFormat.letterSpacing = _computedStyle.letterSpacing;
		textFormat.size = _computedStyle.fontSize;
		
		textFormat.bold = _computedStyle.fontWeight == FontWeight.bold;
		textFormat.italic = _computedStyle.fontStyle == FontStyle.italic;
		
		textFormat.letterSpacing = _computedStyle.letterSpacing;
		
		textFormat.color = _computedStyle.color.color;
		return textFormat;
	}

}