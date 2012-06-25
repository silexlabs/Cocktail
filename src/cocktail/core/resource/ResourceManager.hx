/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.resource;

import cocktail.port.Resource;

/**
 * This is a static class used to retrive loaded asset
 * and start the loading of asset if they are not yet loaded.
 * 
 * This allows caching of asset which becomes useful for assets
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
	private static var _resources:Hash<Resource>;
	
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
	public static function getResource(url:String):Resource
	{
		//init the hash if first request
		if (_resources == null)
		{
			_resources = new Hash<Resource>();
		}
		
		//if the resource with the given url is not
		//yet stored, create it
		if (_resources.exists(url) == false)
		{
			var resource:Resource = new Resource(url);
			_resources.set(url, resource);
		}
		
		//return the resource with the right URL
		return _resources.get(url);
	}
}