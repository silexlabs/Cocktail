/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.js;


import cocktailCore.resource.abstract.AbstractLibraryLoader;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import js.Dom.HtmlDom;
import js.Lib;

/**
 * This is the implementation of the library loader for the JavaScript runtime. A library in JavaScript
 * is a .js file. This class is in charge of adding a script tag to the HTML DOM with the url of the .js
 * to load
 * 
 * @author Yannick DOMINGUEZ
 */
class LibraryLoader extends AbstractLibraryLoader
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
	 * Set the script attributes on the script tag wrapped in the NativeElement and
	 * attach it to the HTML header
	 * 
	 * @param	url the url of the JS script to load
	 */
	override private function doLoad(url:String):Void
	{
		// Set it's 'type' attribute	
		_nativeElement.setAttribute("type", "text/javascript");

		// Set it's 'language' attribute
		_nativeElement.setAttribute("language", "JavaScript");

		// Now add this new element to the head tag
		Lib.document.getElementsByTagName("head")[0].appendChild(_nativeElement);
		
		//start the script loading
		super.doLoad(url);
	}
	

	
}