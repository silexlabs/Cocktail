/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.port.platform.input.AbstractNativeTextInput;
import flash.display.DisplayObjectContainer;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.text.TextFieldType;
import cocktail.core.geom.GeomData;

/**
 * This is the flash port of for the native text input,
 * allowing manipulation of a flash TextField
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextInput extends AbstractNativeTextInput
{

	//those const holds CSS standard font name and their equivalent
	//for flash, so that the name can be switched when setting the font
	//of the text field

	private static inline var SERIF_GENERIC_FONT_NAME:String = "serif";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "sans";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "typewriter";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";

	/**
	 * The wrapped native flash text field
	 */
	private var _textField:TextField;
	
	/**
	 * The text format for the text field, storing
	 * its style
	 */
	private var _textFormat:TextFormat;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		_textField = new TextField();
		
		//not supported in nme
		#if flash9
		_textField.tabEnabled = false;
		#end
		
		//make the text field editable
		_textField.type = TextFieldType.INPUT;
		
		_textFormat = new TextFormat();
		
		updateTextFormat();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The flash text field attach itself to the flash display list
	 * 
	 * TODO 1 : graphicsContext no longer a DisplayObjectContainer
	 */
	override public function attach(graphicContext:GraphicsContext):Void
	{
		var containerGraphicContext:DisplayObjectContainer = cast(graphicContext.nativeLayer);
		//TODO 3 : in NME, seems to make text field lose focus
		containerGraphicContext.addChild(_textField);
	}
	
	/**
	 * set the flash native foxus on the text field
	 */
	override public function focus():Void
	{	
		//TODO 2 : seems to do nothing in NME
		flash.Lib.current.stage.focus = _textField;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * TextFormat needs to be set on the text field
	 * each time one of its style changes
	 */
	private function updateTextFormat():Void
	{
		_textField.defaultTextFormat = _textFormat;
		_textField.setTextFormat(_textFormat);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	// set/get the attribute on the flash text field and text format
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_viewport():RectangleVO
	{
		return new RectangleVO(_textField.x, _textField.y, _textField.width, _textField.height);
	}
	
	override private function set_viewport(value:RectangleVO):RectangleVO
	{
		_textField.x = value.x;
		_textField.y = value.y;
		_textField.width = value.width;
		_textField.height = value.height;
		
		return value;
	}
	
	override private function set_fontSize(value:Float):Float
	{
		_textFormat.size = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_fontSize():Float
	{
		return _textFormat.size;
	}
	
	override private function set_italic(value:Bool):Bool
	{
		_textFormat.italic = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_italic():Bool
	{
		return _textFormat.italic;
	}
	
	override private function get_bold():Bool
	{
		return _textFormat.bold;
	}
	
	override private function set_bold(value:Bool):Bool
	{
		_textFormat.bold = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function set_color(value:Int):Int
	{
		_textFormat.color = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_color():Int
	{
		return _textFormat.color;
	}
	
	/**
	 * Replace CSS font name by flash font name if
	 * needed
	 */
	override private function set_fontFamily(value:String):String
	{
		switch (value)
		{
			case SERIF_GENERIC_FONT_NAME:
				value = SERIF_FLASH_FONT_NAME;
				
			case SANS_SERIF_GENERIC_FONT_NAME:
				value = SANS_SERIF_FLASH_FONT_NAME;
				
			case MONOSPACE_GENERIC_FONT_NAME:
				value = MONOSPACE_FLASH_FONT_NAME;
		}
		
		_textFormat.font = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_fontFamily():String
	{
		return _textFormat.font;
	}
	
	override private function get_value():String 
	{
		return _textField.text;
	}
	
	override private function set_value(textValue:String):String 
	{
		return _textField.text = textValue;
	}
	
	override private function set_letterSpacing(value:Float):Float
	{
		_textFormat.letterSpacing = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_letterSpacing():Float
	{
		return _textFormat.letterSpacing;
	}
	
}