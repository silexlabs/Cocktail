/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.resource;

import cocktail.core.html.HTMLDocument;
import cocktail.core.http.HTTPConstants;
import cocktail.port.base.ResourceBase;
import cocktail.port.Bindings;
import cocktail.core.http.HTTPData;

/**
 * This is used to retrieve loaded asset
 * and start the loading of asset if they are not yet loaded.
 * 
 * This allows caching of assets which is useful for assets
 * frequently redrawn such as backgrounds
 * 
 * @author Yannick DOMINGUEZ
 */
class ResourceManager 
{
	/**
	 * Stores each requested asset in a map where the
	 * key is the url of the asset
	 */
	private var _resources:Map<String, ResourceBase>;
	
	/**
	 * Store requested binary resources, where the 
	 * key is the url of the binary
	 */
	private var _binaryResources:Map<String, NativeHttp>;
	
	/**
	 * a reference to the document owning this
	 * instance
	 */
	private var _document:HTMLDocument;
	
	/**
	 * class constructor
	 */
	public function new(document:HTMLDocument) 
	{
		_document = document;
		_resources = new Map<String, ResourceBase>();
		_binaryResources = new Map<String, NativeHttp>();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_document = null;
		_resources = null;
		_binaryResources = null;
	}
	
	/**
	 * Return the resource at the given url. If it is the first
	 * time this resource is requested, create a new Resource
	 * object which will starts its loading itself
	 */
	public function getImageResource(url:String):ResourceBase
	{
		//get the resource or null if not existant yet
		var resource:ResourceBase = _resources.get(url);
		
		//if the resource with the given url is not
		//yet stored, create it
		if (resource == null)
		{
			resource = new ImageResource(cleanRelativePathes(url));
			_resources.set(url, resource);
		}
		
		//return the resource with the right URL
		return resource;
	}
	
	/**
	 * Remove a cashed image resource
	 */
	public function removeImageResource(url:String):Void
	{
		_resources.remove(url);
	}
	
	/**
	 * Return a binary resource, start loading it if
	 * first request.
	 */
	public function getBinaryResource(url:String):NativeHttp
	{
		var resource:NativeHttp = _binaryResources.get(url);
		
		if (resource == null)
		{
			resource = new NativeHttp(_document.timer);
			resource.load(cleanRelativePathes(url), HTTPConstants.GET, null, null, DataFormatValue.BINARY);
			_binaryResources.set(url, resource);
		}
		
		return resource;
	}
	
	/**
	 * Remove a cashed binary resource
	 */
	public function removeBinaryResource(url:String):Void
	{
		_binaryResources.remove(url);
	}

	/**
	 * Pre-process relative resource pathes
	 */
	private function cleanRelativePathes(url:String):String {

		var splittedUrl : Array<String> = url.split('/');

		var rebuildUrl : Array<String> = [];

		while(splittedUrl.length > 0) {

			var d : String = splittedUrl.shift();

			if (d == "..") {

				rebuildUrl.pop();
			
			} else if (d != ".") {

				rebuildUrl.push(d);
			}
		}
		return rebuildUrl.join("/");
	}
}