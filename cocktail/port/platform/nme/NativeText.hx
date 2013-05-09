/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.nme;

import cocktail.port.base.NativeTextBase;
import cocktail.port.Bindings;
import cocktail.core.geom.GeomData;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.text.TextField;

/**
 * This is the nme port of the class wrapping a native text element.
 * The native text element is a TextField object
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeText extends NativeTextBase
{
	/**
	 * The native text element casted as a TextField
	 */
	private var _textField:TextField;
	
	/**
	 * class constructor
	 */
	public function new(nativeTextElement:NativeTextElement) 
	{
		super(nativeTextElement);
		_textField = cast(nativeTextElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the TextField bitmap data as a
	 * native flash BitmapData
	 */
	override public function getBitmap(bounds:RectangleVO):NativeBitmapData
	{
		var bitmap:BitmapData = new BitmapData(Math.round(bounds.width), Math.round(bounds.height), true, 0x00000000);
		bitmap.draw(_nativeTextElement);
		return bitmap;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the TextField width
	 */
	override private function get_width():Float
	{
		return _textField.width;
	}
	
	
	
}