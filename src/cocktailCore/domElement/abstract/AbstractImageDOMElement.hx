/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.domElement.DOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElement;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import cocktailCore.resource.abstract.AbstractImageLoader;
import cocktailCore.resource.ImageLoader;
import cocktailCore.resource.ResourceLoader;
import haxe.Log;

/**
 * This DOMElement is in charge of displaying a picture of 
 * type .jpg, .png or .gif
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractImageDOMElement extends EmbeddedDOMElement
{
	//////////////////////
	// CALLBACKS
	/////////////////////
	
	/**
	 * The callback called once a picture has been successfully
	 * loaded
	 */
	public var onLoad:Void->Void;
	
	/**
	 * The callback called when there was an error during loading
	 */
	public var onError:String->Void;
	
	//////////////////////
	// PICTURE INFO
	/////////////////////
	
	/**
	 * The actual width (no scaling) of the currently loaded picture
	 * in pixels
	 */
	private var _naturalWidth:Int;
	public var naturalWidth(getNaturalWidth, never):Int;
	
	/**
	 * The actual height (no scaling) of the currently loaded picture
	 * in pixels
	 */
	private var _naturalHeight:Int;
	public var naturalHeight(getNaturalHeight, never):Int;
	
	/**
	 * The URL of the loaded picture.
	 * Read-only
	 */
	private var _src:String;
	public var src(getSrc, never):String;
	
	//////////////////////
	// PRIVATE ATTRIBUTES
	/////////////////////
	
	/**
	 * Reponsible for loading pictures into a NativeElement. 
	 * Its NativeElement is used by this ImageDOMElement
	 */
	private var _imageLoader:ImageLoader;

	/**
	 * Determine wether the bitmap should be smoothed
	 */
	private var _smooth:Bool;
	public var smooth(getSmooth, setSmooth):Bool;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor. Instantiate the image loader
	 * and set its NativeElement as this ImageDOMElement's
	 * NativeElement
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		_imageLoader = new ImageLoader();
		super(_imageLoader.nativeElement);
	}

	/**
	 * Init the smoothing of the picture
	 */
	override private function init():Void
	{	
		super.init();
		
		//smooth the picture by default
		this.smooth = true;
	}
	
	/**
	 * For an ImageDOMElement, the intrinsic width, height and ratio
	 * represents the scaled dimensions of the picture. They are
	 * equal to 0 until a picture is loaded
	 * 
	 * The natural width and height represent the unscaled
	 * dimensions of the picture
	 */
	override private function initInstrinsicDimensions():Void
	{
		this._intrinsicHeight = 0;
		this._intrinsicWidth = 0;
		this._intrinsicRatio = 0;
		this._naturalHeight = 0;
		this._naturalWidth = 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 * @param	url the url of the picture to load
	 * @param	allowCache wheter the picture is allowed to be cached by the browser
	 */
	public function load(url:String, allowCache:Bool = true):Void
	{
		_imageLoader.load(url, onLoadComplete, onLoadError, allowCache);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the picture was successfuly loaded.
	 * Invalidate the DOMElement and call the
	 * onLoad callback if provided
	 * @param	image the loaded picture stored as a nativeElement
	 */
	private function onLoadComplete(image:NativeElement):Void
	{
		this._style.invalidate();
		
		//refresh picture smoothing
		this.smooth = this.smooth;
		
		if (onLoad != null)
		{
			onLoad();
		}
	}
	
	/**
	 * Called when there was an error during loading.
	 * Call the error callback if provided
	 * @param	message the error message
	 */
	private function onLoadError(message:String):Void
	{
		if (onError != null)
		{
			onError(message);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getSrc():String
	{
		return this._src;
	}
	
	private function setSmooth(value:Bool):Bool
	{
		this._smooth = value;
		return value;
	}
	
	private function getSmooth():Bool
	{
		return this._smooth;
	}
	
	private function getNaturalWidth():Int
	{
		return _naturalWidth;
	}
	
	private function getNaturalHeight():Int
	{
		return _naturalHeight;
	}
	
}