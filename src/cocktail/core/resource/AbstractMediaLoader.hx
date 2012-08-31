/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.resource;

import cocktail.port.NativeElement;

/**
 * This is the base class for loading class
 * loading media assets such as pictures
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractMediaLoader extends ResourceLoader
{
	/**
	 * A reference to the native element actually loading
	 * the asset. For instance, for an image in Flash, a Loader, in JS,
	 * an img tag. When multiple loads occurs, this NativeElement is
	 * reused instead of a new one being created.
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, never):NativeElement;
	
	/**
	 * The intrinsic width of the loaded asset.
	 */
	private var _intrinsicWidth:Int;
	public var intrinsicWidth(getIntrinsicWidth, never):Int;
	
	/**
	 * The intrinsic height of the loaded asset.
	 */
	private var _intrinsicHeight:Int;
	public var intrinsicHeight(getIntrinsicHeight, never):Int;
	
	/**
	 * The intrinsic ratio of the loaded asset.
	 */
	private var _intrinsicRatio:Float;
	public var intrinsicRatio(getIntrinsicRatio, never):Float;
	
	/**
	 * class constructor. Store provided NativeElement
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getNativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	private function getIntrinsicWidth():Int
	{
		return _intrinsicWidth;
	}
	
	private function getIntrinsicHeight():Int
	{
		return _intrinsicHeight;
	}
	
	private function getIntrinsicRatio():Float
	{
		return _intrinsicRatio;
	}
	
}