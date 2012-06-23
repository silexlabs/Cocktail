/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.event.UIEvent;
import cocktail.core.NativeElement;
import cocktail.core.renderer.ImageRenderer;
import cocktail.core.resource.ImageLoader;
import cocktail.core.renderer.RendererData;

/**
 * The object element can represent an external resource,
 * which, depending on the type of the resource,
 * will either be treated as an image, as a nested browsing
 * context, or as an external resource to be processed by a plugin.
 * 
 * TODO 1 IMPORTANT : for now only support embedding of flash movies.
 * Eventually, when a ResourceManager is done, this class might be used
 * to display any type of embedded content
 * 
 * TODO 1 : this is pretty much the same code as HTMLImageElement for now, comments
 * have not been updated either
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLObjectElement extends EmbeddedElement
{

	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The data attribute specifies the address of the resource.
	 */
	public var data(get_data, set_data):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reponsible for loading pictures into a NativeElement. 
	 * Its NativeElement is used by this HTMLImageElement as an
	 * embedded asset
	 */
	private var _imageLoader:ImageLoader;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		_imageLoader = new ImageLoader();
		super(HTMLConstants.HTML_OBJECT_TAG_NAME);
	}
	
	/**
	 * the embedded assed is held by the image loader
	 */
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _imageLoader.nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_DATA_ATTRIBUTE_NAME)
		{
			data = value;
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
	// PRIVATE LOADING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	// IDL SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts a loading with the image loader
	 */
	private function set_data(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME, value);
		_imageLoader.load([value], onLoadComplete, onLoadError);
		return value;
	}
	
	private function get_data():String
	{
		return getAttribute(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME);
	}
	
}