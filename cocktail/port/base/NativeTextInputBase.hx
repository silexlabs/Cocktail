/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.base;

import cocktail.core.geom.GeomData;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeElement;

/**
 * A base class, exposing method to manipulate
 * a native text input of the underlying platform
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextInputBase extends NativeInputBase
{
	//getter/seter for style attributes
	
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
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	
	private function set_letterSpacing(value:Float):Float
	{
		return letterSpacing = value;
	}
	
	private function get_letterSpacing():Float
	{
		return letterSpacing;
	}
}