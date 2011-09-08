/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource.js;

import haxe.Http;
import haxe.Log;
import js.Lib;
import js.Dom.HtmlDom;
import cocktail.domObject.ContainerDOMObject;
import cocktail.domObject.DOMObject;
import cocktail.resource.ResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Container loader implementation for the JavaScript runtime. It is used to 
 * load complex object, such as a skin formed of multiple HTML tag. It is loaded from
 * an HTML file
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerLoader extends ResourceLoader
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement JS specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When the HTML has been loaded, set the loaded HTML as the
	 * native DOM of the Container DOMObject
	 * @param	data the loaded HTML
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		var domObject:ContainerDOMObject = new ContainerDOMObject(Lib.document.createElement("div"));
		domObject.nativeReference.innerHTML = data;
		_onLoadCompleteCallback(domObject);
	}
}