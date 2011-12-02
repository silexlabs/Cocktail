/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.js;


import cocktailCore.resource.abstract.AbstractResourceLoader;
import js.Dom.HtmlDom;
import js.Lib;

/**
 * This is the implementation of the library loader for the JavaScript runtime. A library in JavaScript
 * is a .js file. This class is in charge of adding a script tag to the HTML DOM with the new script to add
 * @author Yannick DOMINGUEZ
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
	override private function doLoad(url:String):Void
	{
		//Create a 'script' element	
		var scrptE:HtmlDom = Lib.document.createElement("script");

		// Set it's 'type' attribute	
		scrptE.setAttribute("type", "text/javascript");

		// Set it's 'language' attribute
		scrptE.setAttribute("language", "JavaScript");

		// Set it's 'src' attribute
		scrptE.setAttribute("src", url);

		// Set it's onLoad callback
		untyped scrptE.onload = onLoadComplete;
		
		//Set it's error callback
		untyped scrptE.onerror = onLoadError;
		

		// Now add this new element to the head tag
		Lib.document.getElementsByTagName("head")[0].appendChild(scrptE);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method for load complete
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the file is done loading, calls the success callback with no argument, as the loaded
	 * library is stored in memory but is not to be manipulated by the object that started the load
	 * @param	data the loaded library data
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		_onLoadCompleteCallback(null);
	}
	
}