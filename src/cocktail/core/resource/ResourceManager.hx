/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.resource;

import cocktail.core.http.HTTPConstants;
import cocktail.port.ImageResource;
import cocktail.port.NativeHttp;
import cocktail.port.platform.nativeHttp.NativeHTTPData;

/**
 * This is a static class used to retrive loaded asset
 * and start the loading of asset if they are not yet loaded.
 * 
 * This allows caching of assets which becomes useful for assets
 * frequently redrawn such as backgrounds
 * 
 * @author Yannick DOMINGUEZ
 */
class ResourceManager 
{
	/**
	 * Stores each requested asset in a hash where the
	 * key is the url of the asset
	 */
	private static var _resources:Hash<AbstractResource>;
	
	/**
	 * Store requested swf resources, where the 
	 * key is the url of the swf
	 */
	private static var _swfResources:Hash<NativeHttp>;
	
	/**
	 * class constructor. Private as this class
	 * is meant to be used through its static methods
	 */
	private function new() 
	{
		
	}
	
	/**
	 * Init resource hash on first use
	 */
	private static function init():Void
	{
		if (_resources == null)
		{
			_resources = new Hash<AbstractResource>();
		}
		
		if (_swfResources == null)
		{
			_swfResources = new Hash<NativeHttp>();
		}
	}
	
	/**
	 * Return the resource at the given url. If it is the first
	 * time this resource is requested, create a new Resource
	 * object which will starts its loading itself
	 */
	public static function getImageResource(url:String):AbstractResource
	{
		init();
		
		//if the resource with the given url is not
		//yet stored, create it
		if (_resources.exists(url) == false)
		{
			var resource:ImageResource = new ImageResource(url);
			_resources.set(url, resource);
		}
		
		//return the resource with the right URL
		return _resources.get(url);
	}
	
	/**
	 * Return an SWF resource, start loading it if
	 * first request.
	 * 
	 * TODO 2 : should SWF loading be in core ?
	 * Should be abstracted as binary loading ?
	 */
	public static function getSWFResource(url:String):NativeHttp
	{
		init();
		
		if (_swfResources.exists(url) == false)
		{
			var resource:NativeHttp = new NativeHttp();
			resource.load(url, HTTPConstants.GET, null, null, DataFormatValue.BINARY);
			_swfResources.set(url, resource);
		}
		
		return _swfResources.get(url);
	}
}