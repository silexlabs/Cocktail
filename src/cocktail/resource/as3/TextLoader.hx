/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource.as3;

import flash.display.Sprite;
import cocktail.domObject.DOMObject;
import cocktail.domObject.TextDOMObject;
import cocktail.resource.ResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Text loader implementation for the Flash runtime. It is 
 * used to load HTML text and display it by attaching it to the DOM. It behaves
 * like the StringLoader with the difference that the loaded String is HTML instead
 * of a serialised format. The loaded HTML is attached to an Text DOMObject, used to
 * display and convert the html for Flash.
 * 
 * @author Yannick DOMINGUEZ
 */
class TextLoader extends ResourceLoader
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
	 * When the HTML String has been loaded, create a Text DOMObject, and set its
	 * text to the loaded HTML
	 * @param	data the loaded HTML
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		var domObject:TextDOMObject = new TextDOMObject(new Sprite());
		domObject.setText(data);
		
		_onLoadCompleteCallback(domObject);
	}
}