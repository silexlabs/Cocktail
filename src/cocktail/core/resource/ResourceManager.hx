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
import cocktail.core.http.HTTPData;

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
	private static var _resources:Hash<AbstractResource> = new Hash<AbstractResource>();
	
	/**
	 * Store requested binary resources, where the 
	 * key is the url of the binary
	 */
	private static var _binaryResources:Hash<NativeHttp> = new Hash<NativeHttp>();
	
	/**
	 * class constructor. Private as this class
	 * is meant to be used through its static methods
	 */
	private function new() 
	{
		
	}
	
	/**
	 * Return the resource at the given url. If it is the first
	 * time this resource is requested, create a new Resource
	 * object which will starts its loading itself
	 */
	public static function getImageResource(url:String):AbstractResource
	{
		//get the resource or null if not existant yet
		var resource:AbstractResource = _resources.get(url);
		
		//if the resource with the given url is not
		//yet stored, create it
		if (resource == null)
		{
			resource = new ImageResource(url);
			_resources.set(url, resource);
		}
		
		//return the resource with the right URL
		return resource;
	}
	
	/**
	 * Return a binary resource, start loading it if
	 * first request.
	 */
	public static function getBinaryResource(url:String):NativeHttp
	{
		var resource:NativeHttp = _binaryResources.get(url);
		
		if (resource == null)
		{
			resource = new NativeHttp();
			resource.load(url, HTTPConstants.GET, null, null, DataFormatValue.BINARY);
			_binaryResources.set(url, resource);
		}
		
		return resource;
	}
}