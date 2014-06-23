/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.port.Bindings;
import cocktail.geom.GeomData;

/**
 * Wraps a native platform specific text element
 * and give access to its properties
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextBase
{
	/**
	 * return the width of the text
	 */
	public var width(get_width, null):Float;
	
	/**
	 * The platform specific text element
	 */
	private var _nativeTextElement:NativeTextElement;
	
	/**
	 * class constructor
	 */
	public function new(nativeTextElement:NativeTextElement) 
	{
		_nativeTextElement = nativeTextElement;
	}
	
	/**
	 * clean-up method
	 */
	public function dispose():Void
	{
		_nativeTextElement = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the bitmap data of the text for the
	 * given bounds
	 */
	public function getBitmap(bounds:RectangleVO):NativeBitmapData
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_width():Float
	{
		return 0.0;
	}
	
	
	
}
