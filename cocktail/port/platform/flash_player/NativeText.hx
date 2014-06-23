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
import cocktail.geom.GeomData;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.text.TextField;

/**
 * This is the flash port of the class wrapping a native text element.
 * The native text element is a TextField object
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
	 * return the TextField bitmap data as a
	 * native flash BitmapData
	 */
	override public function getBitmap(bounds:RectangleVO):NativeBitmapData
	{
		//this offset is the offset between the top most of the text and the top of the text
		//field. We want to remove it so that text gets drawn at y=0
		var textYOffset:Float = _textField.textHeight - _textField.height;
		
		_nativeBitmap = new BitmapData(Math.round(bounds.width), Math.round(bounds.height - textYOffset), true, 0x00000000);
		
		_matrix.identity();
		
		//there is a documented 2px gutter (horizontal and vertical) in the flash text field before the
		//first char :
		//http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/flash/text/TextLineMetrics.html
		_matrix.translate( -2, textYOffset + 2);
		
		_nativeBitmap.draw(_textField, _matrix);
		
		return _nativeBitmap;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the TextField width
	 */
	override private function get_width():Float
	{
		return _textField.textWidth;
	}
}
