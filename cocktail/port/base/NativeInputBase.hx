/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.core.geom.GeomData;
import cocktail.core.graphics.GraphicsContext;

/**
 * a base class exposing method
 * native input of the underlying
 * platform, such as text inputs
 * or checkboxes
 * 
 * @author 
 */
class NativeInputBase
{
	/**
	 * get/set the text of the input
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * get/set the maxLength of the input, used only
	 * for text based inputs
	 */
	public var maxLength(default, set_maxLength):Int;
	
	/**
	 * get/set wether the user can interact with the
	 * input
	 */
	public var disabled(default, set_disabled):Bool;
	
	/**
	 * get/set read-only, similar to disabled but
	 * only for text based controls
	 */
	public var readonly(default, set_readonly):Bool;
	
	/**
	 * get/set the position of the input relative to
	 * the viewport
	 */
	public var viewport(get_viewport, set_viewport):RectangleVO;
	
	/**
	 * get/set the cliprect of the input which is the rectangle,
	 * relative to the viewport where the input can be displayed 
	 * without being masked
	 */
	public var clipRect(get_clipRect, set_clipRect):RectangleVO;
	
	/**
	 * Callback, called when the native input is
	 * "activated" (clicked, touched...)
	 */
	public var onActivate:Void->Void;
	
	/**
	 * Callback, called when text is input
	 * by the user, only applies to text based
	 * input
	 */
	public var onInput:Void->Void;
	
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Allow the native input to attach itself
	 * to the native rendering tree. How the text input
	 * is attached varies based on the platform
	 */
	public function attach(graphicContext:GraphicsContext):Void
	{
		//abstract
	}
	
	/**
	 * Allow the native input to detach itself 
	 * from the native rendering tree
	 */
	public function detach(graphicContext:GraphicsContext):Void
	{
		//abstract
	}
	
	/**
	 * When the HTMLInputElement creating this input
	 * gains focus, allow the native input to gain 
	 * native focus
	 */
	public function focus():Void
	{
		//abstract
	}
	
	/**
	 * Called when the native input
	 * is no longer displayed
	 */
	public function dispose():Void
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
	
	private function get_clipRect():RectangleVO
	{
		return clipRect;
	}
	
	private function set_clipRect(value:RectangleVO):RectangleVO
	{
		return clipRect = value;
	}
	
	private function get_value():String 
	{
		return value;
	}
	
	private function set_value(textValue:String):String 
	{
		return value = textValue;
	}
	
	private function set_maxLength(value:Int):Int 
	{
		return maxLength = value;
	}
	
	private function set_disabled(value:Bool):Bool 
	{
		return disabled = value;
	}
	
	private function set_readonly(value:Bool):Bool 
	{
		return readonly = value;
	}
}