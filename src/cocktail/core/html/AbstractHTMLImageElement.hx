/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.NativeElement;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.nativeElement.NativeElementData;
import cocktail.core.event.Event;
import cocktail.core.ImageLoader;
import cocktail.core.EmbeddedCoreStyle;
import haxe.Log;
import cocktail.core.html.EmbeddedElement;


/**
 * The IMG element embeds an image in the current document at
 * the location of the element's definition. The IMG element 
 * has no content; it is usually replaced inline by the image
 * designated by the src attribute, the exception being for 
 * left or right-aligned images that are "floated" out of line.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractHTMLImageElement extends EmbeddedElement
{
	/**
	 * the html tag name of an image
	 */
	private static inline var HTML_IMAGE_TAG_NAME:String = "img";
	
	//////////////////////
	// CALLBACKS
	/////////////////////
	
	/**
	 * The callback called once a picture has been successfully
	 * loaded
	 */
	public var onLoad:Event->Void;
	
	/**
	 * The callback called when there was an error during loading
	 */
	public var onError:Event->Void;

	//////////////////////
	// PRIVATE ATTRIBUTES
	/////////////////////
	
	/**
	 * The instrinsic width of the loaded picture or
	 * return 0 if not available
	 */
	public var naturalWidth(get_naturalWidth, never):Int;
	
	/**
	 * The instrinsic height of the loaded picture  or
	 * return 0 if not available
	 */
	public var naturalHeight(get_naturalHeight, never):Int;
	
	/**
	 * set/get the URL of the loaded picture.
	 * 
	 * TODO : get/set from attributes map ? + override setAttribute
	 * to call src setter ? or use Reflection ?
	 * should not be _src attribute anymore
	 * Or, add an _srcAttr class attribute and attach it 
	 * to the attributes, then get/set src, set its value. Or 
	 * _src is of type Attr ?
	 */
	private var _src:String;
	public var src(get_src, set_src):String;
	
	/**
	 * Reponsible for loading pictures into a NativeElement. 
	 * Its NativeElement is used by this HTMLImageElement as an
	 * embedded asset
	 */
	private var _imageLoader:ImageLoader;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		_imageLoader = new ImageLoader();
		super(HTML_IMAGE_TAG_NAME);
	}
	
	/**
	 * the embedded assed is held by the image loader
	 */
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _imageLoader.nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 */
	private function set_src(value:String):String
	{
		_src = value;
		_imageLoader.load([value], onLoadComplete, onLoadError);
		return _src;
	}
	
	/**
	 * Called when the picture was successfuly loaded.
	 * Invalidate the Style and call the
	 * onLoad callback if provided.
	 * 
	 * Store the instrinsic dimensions of the loaded asset
	 * 
	 * @param	image the loaded picture stored as a nativeElement
	 */
	private function onLoadComplete(image:NativeElement):Void
	{
		this._intrinsicHeight = _imageLoader.intrinsicHeight;
		this._intrinsicWidth = _imageLoader.intrinsicWidth;
		this._intrinsicRatio = _intrinsicHeight / _intrinsicWidth;
		
		this._coreStyle.invalidate();
		
		//if provided, call the onload callback
		if (onLoad != null)
		{
			var loadEvent:Event = new Event(Event.LOAD, this);
			onLoad(loadEvent);
		}
	}
	
	/**
	 * Called when there was an error during loading.
	 * Call the error callback if provided
	 * 
	 * @param	message the error message
	 */
	private function onLoadError(message:String):Void
	{
		if (onError != null)
		{
			onError(new Event(Event.ERROR, this));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_src():String
	{
		return _src;
	}
	
	private function get_naturalHeight():Int
	{
		if (_intrinsicHeight == null)
		{
			return 0;
		}
		return _intrinsicHeight;
	}
	
	private function get_naturalWidth():Int
	{
		if (_intrinsicWidth == null)
		{
			return 0;
		}
		return _intrinsicWidth;
	}
	
}