/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource;

import cocktail.resource.abstract.AbstractResourceLoader;
import haxe.Log;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.js.AnimationDOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.resource.ResourceData;

#if flash9
import cocktail.resource.as3.StringLoader;
import cocktail.resource.as3.ImageLoader;
import cocktail.resource.as3.TextLoader;
import cocktail.resource.as3.ContainerLoader;
import cocktail.resource.as3.AnimationLoader;
import cocktail.resource.as3.LibraryLoader;

#elseif js
import cocktail.resource.js.StringLoader;
import cocktail.resource.js.ImageLoader;
import cocktail.resource.js.TextLoader;
import cocktail.resource.js.ContainerLoader;
import cocktail.resource.js.AnimationLoader;
import cocktail.resource.js.LibraryLoader;

#elseif php
import cocktail.resource.php.StringLoader;
import cocktail.resource.php.ImageLoader;
import cocktail.resource.php.TextLoader;
import cocktail.resource.php.ContainerLoader;
import cocktail.resource.php.AnimationLoader;
import cocktail.resource.php.LibraryLoader;

#elseif doc
class StringLoader extends AbstractResourceLoader {}
class ImageLoader extends AbstractResourceLoader {}
class TextLoader extends AbstractResourceLoader {}
class ContainerLoader extends AbstractResourceLoader {}
class AnimationLoader extends AbstractResourceLoader {}
class LibraryLoader extends AbstractResourceLoader {}

#end	

/**
 * Manages the queue of files to load, and exposes method to load resources of diferrent types. 
 * @author Yannick DOMINGUEZ
 */
class ResourceLoaderManager 
{	
	/**
	 * Queue of files to load, stored in the order where they must be loaded
	 */
	private static var _resourceDataArray:Array<ResourceData>;
	
	/**
	 * Wheter a file is currently loading
	 */
	private static var _isLoading:Bool = false;
	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public methods, starting the files loading
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	domElement, if provided, the loaded resource (in this case a picture) will be set on this
	 * DOMElement, else a new ImageDOMElement will be created
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadImage(url:String, successCallback:ImageDOMElement->Void, errorCallback:String->Void , imageDOMElement:ImageDOMElement = null, allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			domElement:cast(imageDOMElement),
			allowCache:allowCache,
			loadingType:image
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	domElement, if provided, the loaded resource (in this case a formatted text) will be set on this
	 * DOMElement, else a new TextDOMElement will be created
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadText(url:String, successCallback:TextDOMElement->Void, errorCallback:String->Void , textDOMElement:TextDOMElement = null, allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			domElement:cast(textDOMElement),
			allowCache:allowCache,
			loadingType:text
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	domElement, if provided, the loaded resource (in this case an animation) will be set on this
	 * DOMElement, else a new AnimationDOMElement will be created
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadAnimation(url:String, successCallback:AnimationDOMElement->Void, errorCallback:String->Void , animationDOMElement:AnimationDOMElement = null, allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			allowCache:allowCache,
			domElement:cast(animationDOMElement),
			loadingType:animation
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadContainer(url:String, successCallback:ContainerDOMElement->Void, errorCallback:String->Void , containerDOMElement:ContainerDOMElement = null, allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			allowCache:allowCache,
			domElement:cast(containerDOMElement),
			loadingType:container
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadString(url:String, successCallback:String->Void, errorCallback:String->Void , allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			allowCache:allowCache,
			domElement:null,
			loadingType:data
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	/**
	 * Create a ResourceData object and add to the list of files to load by calling addResourceData
	 * @param	url the url of the file to load
	 * @param	successCallback the callback which must be called once the file is successfully done loading
	 * @param	errorCallback the callback which must be called if there was an error during loading
	 * @param	allowCache wheter to allow the browser to cache the loaded file
	 */
	public static function loadLibrary(url:String, successCallback:Dynamic->Void, errorCallback:String->Void , allowCache:Bool = true):Void
	{
		var resourceDataToAdd:ResourceData = {
			url:url,
			onLoadComplete:successCallback,
			onLoadError:errorCallback,
			allowCache:allowCache,
			domElement:null,
			loadingType:library
		};
		
		addResourceData(resourceDataToAdd);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, managing the loading queue
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * stores the ResourceData in resourceDataArray. Call loadNextResource if isLoading is false. 
	 * @param resourceData the new resourceData to add
	 */
	private static function addResourceData(resourceData:ResourceData):Void
	{
		//instantiate the array if first use
		if (_resourceDataArray == null)
		{
			_resourceDataArray = new Array<ResourceData>();
		}
		
		_resourceDataArray.push(resourceData);
		
		if (_isLoading == false)
		{
			loadNextResource();
		}
	}
	
	/**
	 *  Set isLoading to true or false depending on the content of filesArray.
	 *	Retrieve the next ResourceData object.
	 *	Create the corresponding AbstractResourceLoader
	 *	Actually start loading the resource.
	 */
	private static function loadNextResource():Void
	{
		//if there are no more elements to load in the resourceData array,
		//do nothing
		if (_resourceDataArray.length == 0)
		{
			_isLoading = false;
		}
		//else load the next file in the array
		else
		{
			_isLoading = true;
			
			var resourceDataToLoad:ResourceData = _resourceDataArray[0];
			
			var resourceLoader:AbstractResourceLoader;
			switch (resourceDataToLoad.loadingType)
			{
				case data:
				resourceLoader = new StringLoader();
				
				case image: 
				resourceLoader = new ImageLoader();
				
				case text:
				resourceLoader = new TextLoader();
				
				case animation:
				resourceLoader = new AnimationLoader();
				
				case container:
				resourceLoader = new ContainerLoader();
				
				case library:
				resourceLoader = new LibraryLoader();
			}
			
			resourceLoader.load(resourceDataToLoad.url, onLoadComplete, onLoadError, resourceDataToLoad.domElement, resourceDataToLoad.allowCache);
		}
	}
	
	/**
	 * Remove the 1st ResourceData from resourceDataArray and call the success callback.
	 * Then call loadNextResource.
	 * @param	data the loaded file data
	 */
	private static function onLoadComplete(data:Dynamic):Void
	{
		var loadedResourceData:ResourceData = _resourceDataArray.shift();
		
		loadedResourceData.onLoadComplete(data); 
		
		loadNextResource();
	}
	
	/**
	 * Remove the 1st ResourceData from resourceDataArray and call the error callback.
	 * Then call loadNextResource.
	 * @param	data the loading error data
	 */
	private static function onLoadError(data:Dynamic):Void
	{
		var errorResourceData:ResourceData = _resourceDataArray.shift();
		
		errorResourceData.onLoadError(data);
		
		loadNextResource();
	}
	
}