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
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeTextElement;
import cocktail.core.geom.GeomData;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.text.engine.TextLine;

/**
 * This is the flash port of the class wrapping a native text element.
 * The native text element is a TextLine object, as it uses the 
 * flash text engine introduced on flash player 10
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeText extends NativeTextBase
{
	/**
	 * The native text element casted as a TextLine
	 */
	private var _textLine:TextLine;
	
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
		_textLine = cast(nativeTextElement);
	}
	
	/**
	 * clean-up method
	 */
	override public function dispose():Void
	{
		_textLine = null;
		_nativeBitmap.dispose();
		_nativeBitmap = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the TextLine bitmap data as a
	 * native flash BitmapData
	 */
	override public function getBitmap(bounds:RectangleVO):NativeBitmapData
	{
		_nativeBitmap = new BitmapData(Math.round(bounds.width), Math.round(bounds.height), true, 0x00000000);
		_matrix.identity();
		_matrix.translate(bounds.x, bounds.y);
		_nativeBitmap.draw(_nativeTextElement, _matrix);
		
		return _nativeBitmap;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the TextLine width
	 */
	override private function get_width():Float
	{
		return _textLine.textWidth;
	}
	
	
	
}