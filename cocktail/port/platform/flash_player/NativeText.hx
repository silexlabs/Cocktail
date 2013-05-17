/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.port.base.NativeTextBase;
import cocktail.port.Bindings;
import cocktail.core.geom.GeomData;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.text.TextField;

/**
 * This is the flash port of the class wrapping a native text element.
 * The native text element is a TextLine object, as it uses the 
 * flash text engine introduced on flash player 10.
 * For nme, it uses a flash text field as the new flash text engine
 * is not implemented
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeText extends NativeTextBase
{
	/**
	 * The native text element cast as a TextField
	 */
	private var _textField:TextField;
	
	/**
	 * The native bitmap data extracted from
	 * the text
	 */
	private var _nativeBitmap:BitmapData;
	
	/**
	 * A reusable matrix used to trnaslate
	 * drawn text
	 */
	private static var _matrix:Matrix = new Matrix();
	
	/**
	 * class constructor
	 */
	public function new(nativeTextElement:NativeTextElement) 
	{
		super(nativeTextElement);
		_textField = cast(nativeTextElement);
	}
	
	/**
	 * clean-up method
	 */
	override public function dispose():Void
	{
		_textField = null;
		_nativeBitmap.dispose();
		_nativeBitmap = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the TextLine or TextField bitmap data as a
	 * native flash BitmapData
	 */
	override public function getBitmap(bounds:RectangleVO):NativeBitmapData
	{
		_nativeBitmap = new BitmapData(Math.round(bounds.width), Math.round(bounds.height), true, 0x00000000);
		_nativeBitmap.draw(_nativeTextElement);
		return _nativeBitmap;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the TextLine or TextField width
	 */
	override private function get_width():Float
	{
		return _textField.width;
	}
	
	
	
}