/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.dom.Attr;
import cocktail.core.dom.Node;
import cocktail.core.event.EventConstants;
import cocktail.core.event.EventTarget;
import cocktail.core.event.UIEvent;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.port.ImageResource;
import cocktail.port.NativeElement;
import cocktail.core.event.Event;
import cocktail.core.renderer.ImageRenderer;
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
	 * Callback called when resource sucessfully loaded
	 */
	private var _resourceLoadedCallback:Event->Void;
	
	/**
	 * Callback called when there is an error when loading
	 * a resource
	 */
	private var _resourceLoadError:Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_IMAGE_TAG_NAME);
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
		
		var resource:AbstractResource = ResourceManager.getImageResource(value);

		if (resource.loaded == false)
		{
			_resourceLoadedCallback = onResourceLoaded;
			_resourceLoadError = onResourceLoadError;
			resource.addEventListener(EventConstants.LOAD, _resourceLoadedCallback);
			resource.addEventListener(EventConstants.ERROR, _resourceLoadError);
		}
		else
		{
			if (resource.loadedWithError == true)
			{
				onLoadError();
			}
			else
			{
				onLoadComplete(resource);
			}
		}
		
		return value;
	}
	
	private function onResourceLoaded(e:Event):Void
	{
		removeListeners(e.target);
		onLoadComplete(cast(e.target));
	}
	
	private function onResourceLoadError(e:Event):Void
	{
		removeListeners(e.target);
		onLoadError();
	}
	
	private function removeListeners(resource:EventTarget):Void
	{
		resource.removeEventListener(EventConstants.LOAD, _resourceLoadedCallback);
		resource.removeEventListener(EventConstants.ERROR, _resourceLoadError);
	}
	
	private function onLoadComplete(resource:AbstractResource):Void
	{	
		intrinsicHeight = resource.intrinsicHeight;
		intrinsicWidth = resource.intrinsicWidth;
		intrinsicRatio = intrinsicHeight / intrinsicWidth;
		
		//if the picture has a defined width and height, only the rendering of the document
		//needs to be updated
		if (getAttributeNode(HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME) != null && getAttributeNode(HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME) != null)
		{
			if (elementRenderer != null)
			{
				_ownerHTMLDocument.invalidationManager.invalidateRendering(elementRenderer.hitTestingBounds);
			}
		}
		//else the size of the loaded
		//picture will probably affect layout too
		else
		{
			invalidate();
		}
		
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(EventConstants.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
	}
	
	private function onLoadError():Void
	{
		var errorEvent:UIEvent = new UIEvent();
		errorEvent.initUIEvent(EventConstants.ERROR, false, false, null, 0.0);
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
		if (intrinsicHeight == null)
		{
			return 0;
		}
		return Math.round(intrinsicHeight);
	}
	
	private function get_naturalWidth():Int
	{
		if (intrinsicWidth == null)
		{
			return 0;
		}
		return Math.round(intrinsicWidth);
	}
	
}