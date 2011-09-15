/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource.php;

import haxe.Http;
import php.Web;
import cocktail.domElement.DOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.resource.abstract.AbstractResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Text loader implementation for the PHP runtime. It is 
 * used to load HTML text and display it by attaching it to the DOM. It behaves
 * like the StringLoader with the difference that the loaded String is HTML instead
 * of a serialised format and so it is displayed as is.
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class TextLoader extends AbstractResourceLoader
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement PHP specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts the file loading and converts the relative url to absolute url.
	 * The default implementation is to load an url and return the result as an Xml containing the string.
	 * It might be used to load, XML, JSON...
	 * @param	url the url to load
	 */
	override private function doLoad(relativeUrl:String):Void 
	{
		// get server port
		var port:Int = untyped __var__('_SERVER', 'SERVER_PORT');
		
		// converts relative url to absolute url
		var absoluteUrl:String = 'http://' + Web.getHostName() + ':' + port + Web.getURI() + relativeUrl;
		
		// call parent method so that text file content is retreived and onLoadComplete callbac is called
		super.doLoad(absoluteUrl);
	}

	/**
	 * When the HTML String has been loaded, create a Text DOMElement, and set its
	 * text to the loaded HTML.
	 * Xml is used for easier data structuring
	 * @param	data the loaded HTML
	 */
	override private function onLoadComplete(data:Dynamic):Void
	{
		// construction of the Xml element containing the div and the text 
		var domElement:TextDOMElement = new TextDOMElement(Xml.createElement('div'));
		domElement.setText(data);
		
		// calls initial callback
		_onLoadCompleteCallback(domElement);
	}
}