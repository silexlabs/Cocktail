/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.air;

import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.port.platform.input.AbstractNativeTextInput;
import flash.display.DisplayObjectContainer;
import flash.geom.Rectangle;
import flash.Lib;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.text.TextFieldType;
import cocktail.core.geom.GeomData;

/**
 * This is a air for mobile port of the native text, 
 * leveraging the StageText API introduced in Air 3,
 * which allows using native text field on mobile platform.
 * Fallback to flash TextField when used on desktop platform
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
	 * The wrapped StageText object
	 * 
	 * TODO 1 : create extern
	 */
	private var _stageText:Dynamic;
	
	/**
	 * class constructor.
	 * Init the StageText object
	 */
	public function new() 
	{
		super();
		_stageText = Type.createInstance(Type.resolveClass("flash.text.StageText"), []);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The StageText attach itself using the a reference to the Stage.
	 * It is not part of the display list and is always rendered on top
	 * of it
	 */
	override public function attach(graphicContext:GraphicsContext):Void
	{
		_stageText.stage = Lib.current.stage;
	}
	
	/**
	 * set the OS native focus on the StageText object
	 */
	override public function focus():Void
	{	
		_stageText.assignFocus();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	// set/get the attribute on the flash StageText
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_viewport():RectangleVO
	{
		return new RectangleVO(_stageText.viewport.x, _stageText.viewport.y, _stageText.viewport.width, _stageText.viewport.height);
	}
	
	override private function set_viewport(value:RectangleVO):RectangleVO
	{
		var viewPort:Rectangle = new Rectangle(value.x, value.y, value.width, value.height);
		_stageText.viewPort = viewPort;
		
		return value;
	}
	
	override private function set_fontSize(value:Float):Float
	{
		_stageText.fontSize = value;
		return value;
	}
	
	override private function get_fontSize():Float
	{
		return _stageText.fontSize;
	}
	
	override private function set_italic(value:Bool):Bool
	{
		if (value == true)
		{
			_stageText.fontPosture = FontPosture.ITALIC;
		}
		else
		{
			_stageText.fontPosture = FontPosture.NORMAL;
		}
		
		return value;
	}
	
	override private function get_italic():Bool
	{
		return _stageText.fontPosture == FontPosture.ITALIC;
	}
	
	override private function get_bold():Bool
	{
		return _stageText.fontWeight == FontWeight.BOLD;
	}
	
	override private function set_bold(value:Bool):Bool
	{
		if (value == true)
		{
			_stageText.fontWeight = FontWeight.BOLD;
		}
		else
		{
			_stageText.fontWeight = FontWeight.NORMAL;
		}
		
		return value;
	}
	
	override private function set_color(value:Int):Int
	{
		_stageText.color = value;
		return value;
	}
	
	override private function get_color():Int
	{
		return _stageText.color;
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
		
		_stageText.fontFamily = value;
		
		return value;
	}
	
	override private function get_fontFamily():String
	{
		return _stageText.fontFamily;
	}
	
	override private function get_value():String 
	{
		return _stageText.text;
	}
	
	override private function set_value(textValue:String):String 
	{
		return _stageText.text = textValue;
	}
	
}