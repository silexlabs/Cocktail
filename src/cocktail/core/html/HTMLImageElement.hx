/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.dom.Attr;
import cocktail.core.dom.Node;
import cocktail.core.event.UIEvent;
import cocktail.core.NativeElement;
import cocktail.core.event.Event;
import cocktail.core.renderer.ImageRenderer;
import cocktail.core.resource.ImageLoader;
import haxe.Log;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.renderer.RendererData;


/**
 * The IMG element embeds an image in the current document at
 * the location of the element's definition. The IMG element 
 * has no content; it is usually replaced inline by the image
 * designated by the src attribute, the exception being for 
 * left or right-aligned images that are "floated" out of line.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLImageElement extends EmbeddedElement
{

	//////////////////////
	// IDL ATTRIBUTES
	/////////////////////
	
	/**
	 * set/get the URL of the loaded picture.
	 * 
	 * store it and retrieve it from the attributes map,
	 * and start the loading of the picture when set
	 */
	public var src(get_src, set_src):String;
	
	//////////////////////
	// ATTRIBUTES
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
		super(HTMLConstants.HTML_IMAGE_TAG_NAME);
	}
	
	/**
	 * the embedded assed is held by the image loader
	 */
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _imageLoader.nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ATTRIBUTE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_SRC_ATTRIBUTE_NAME)
		{
			src = value;
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate an image specific renderer
	 */
	override private function createElementRenderer():Void
	{
		elementRenderer = new ImageRenderer(this);
		elementRenderer.coreStyle = coreStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as <img> element are serialised
	 * as self-closing tags
	 */
	override public function isVoidElement():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 */
	private function set_src(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME, value);
		_imageLoader.load([value], onLoadComplete, onLoadError);
		return value;
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
		
		invalidate(InvalidationReason.other);
		
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(UIEvent.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
	}
	
	/**
	 * Called when there was an error during loading.
	 * Call the error callback if provided
	 * 
	 * @param	message the error message
	 */
	private function onLoadError(message:String):Void
	{
		var errorEvent:UIEvent = new UIEvent();
		errorEvent.initUIEvent(UIEvent.ERROR, false, false, null, 0.0);
		dispatchEvent(errorEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_src():String
	{
		return getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME);
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