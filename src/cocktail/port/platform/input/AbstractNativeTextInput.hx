/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.input;

import cocktail.core.geom.GeomData;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;

/**
 * A base class, exposing method to manipulate
 * a native text input of the underlying platform
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractNativeTextInput 
{
	/**
	 * get/set the text of the text input
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * get/set the position of the text input relative to
	 * the Window
	 */
	public var viewport(get_viewport, set_viewport):RectangleVO;
	
	//get/set style attributes
	
	public var italic(get_italic, set_italic):Bool;
	
	public var bold(get_italic, set_italic):Bool;
	
	public var color(get_color, set_color):Int;
	
	public var fontFamily(get_fontFamily, set_fontFamily):String;
	
	public var letterSpacing(get_letterSpacing, set_letterSpacing):Float;
	
	public var fontSize(get_fontSize, set_fontSize):Float;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Allow the native text input to attach itself
	 * to the rendering tree. How the text input
	 * is attach varies based on the platform
	 */
	public function attach(graphicContext:GraphicsContext):Void
	{
		//abstract
	}
	
	/**
	 * When the HTMLInputElement creating this text input
	 * gains focus, allow the native text input to gain 
	 * native focus
	 */
	public function focus():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_viewport():RectangleVO
	{
		return viewport;
	}
	
	private function set_viewport(value:RectangleVO):RectangleVO
	{
		return viewport = value;
	}
	
	private function set_italic(value:Bool):Bool
	{
		return italic = value;
	}
	
	private function get_italic():Bool
	{
		return italic;
	}
	
	private function get_bold():Bool
	{
		return bold;
	}
	
	private function set_bold(value:Bool):Bool
	{
		return bold = value;
	}
	
	private function set_color(value:Int):Int
	{
		return color = value;
	}
	
	private function get_color():Int
	{
		return color;
	}
	
	private function set_fontFamily(value:String):String
	{
		return fontFamily = value;
	}
	
	private function get_fontFamily():String
	{
		return fontFamily;
	}
	
	private function set_fontSize(value:Float):Float
	{
		return fontSize = value;
	}
	
	private function get_fontSize():Float
	{
		return fontSize;
	}
	
	private function get_value():String 
	{
		return value;
	}
	
	private function set_value(textValue:String):String 
	{
		return value = textValue;
	}
	
	private function set_letterSpacing(value:Float):Float
	{
		return letterSpacing = value;
	}
	
	private function get_letterSpacing():Float
	{
		return letterSpacing;
	}
	
}