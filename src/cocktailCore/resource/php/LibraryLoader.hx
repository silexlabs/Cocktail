/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.php;


import php.Web;
import cocktailCore.resource.abstract.AbstractResourceLoader;

/**
 * This is the implementation of the library loader for the PHP runtime. A library in PHP
 * is a .php file. This class launches the "require_once(library.php)" command
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class LibraryLoader extends AbstractResourceLoader
{

	/**
	 * Class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement JS specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Add a new script tag to the HTML DOM and track the script loading end
	 * to call the onLoadComplete method
	 * @param	url the url of the JS script to load
	 */
	override private function doLoad(relativeUrl:String):Void
	{
		// loads the PHP library using the relativeUrl parameter
		untyped __call__('require_once', relativeUrl);
		
		// calls callback
		onLoadComplete(null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method for load complete
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the library is loaded, calls the success callback with no argument, as the loaded
	 * library is stored in memory but is not to be manipulated by the object that started the loading
	 * @param	data the loaded library data
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		_onLoadCompleteCallback(null);
	}
}