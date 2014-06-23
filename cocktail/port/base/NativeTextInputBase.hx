/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.geom.GeomData;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;

/**
 * A base class, exposing method to manipulate
 * a native text input of the underlying platform
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextInputBase extends NativeInputBase
{
	/**
	 * The intrinsic width and height of a text input used
	 * when no width or height attribute or CSS style defined, 
	 * values are abitrary, based on observation in browser
	 */
	private static inline var INPUT_TEXT_INTRINSIC_WIDTH:Int = 150;
	
	private static inline var INPUT_TEXT_INTRINSIC_HEIGHT:Int = 30;
	
	//getter/seter for style attributes
	
	@:isVar public var italic(get_italic, set_italic):Bool;
	
	@:isVar public var bold(get_bold, set_bold):Bool;
	
	@:isVar public var color(get_color, set_color):Int;
	
	@:isVar public var fontFamily(get_fontFamily, set_fontFamily):String;
	
	@:isVar public var letterSpacing(get_letterSpacing, set_letterSpacing):Float;
	
	@:isVar public var fontSize(get_fontSize, set_fontSize):Float;
	
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
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
	
	override private function get_intrinsicWidth():Int
	{
		return INPUT_TEXT_INTRINSIC_WIDTH;
	}
	
	override private function get_intrinsicHeight():Int
	{
		return INPUT_TEXT_INTRINSIC_HEIGHT;
	}
}
