/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.php;

import haxe.Http;
import haxe.Log;
import php.Web;
import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import cocktail.resource.ResourceData;

/**
 * This is the Image loader implementation for the PHP runtime. It is used to 
 * load pictures that will be attached to the DOM. It loads the picture by creating
 * an <img> tag and setting it's source to the url of the file to load.
 * It instantiate and returns an Image DOMElement.
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class ImageLoader extends AbstractResourceLoader
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
	 * To load a picture, an image element needs to be created, and
	 * its source has to be set the image's url
	 * @param	url the url of the picture
	 */
	override private function doLoad(relativeUrl:String):Void
	{
		// get server port
		var port:Int = untyped __var__('_SERVER', 'SERVER_PORT');
		
		// converts relative url to absolute url
		var absoluteUrl:String = 'http://' + Web.getHostName() + ':' + port + Web.getURI() + relativeUrl;
		
		// construction of the Xml element containing the image link
		
		//create a DOMElement and the image container
		var domElement:DOMElement = new ImageDOMElement(Xml.createElement('img'));
		
		// set its source to start the loading of the picture
		domElement.getReferenceToNativeDOM().set("src", relativeUrl);
		
		// in PHP, the image content is not loaded and only the <img src="..."> string is built
		// so parent's method is not called
		//super.doLoad(absoluteUrl);
		
		// onLoadComplete method is called directly
		onLoadComplete(domElement);
	}
}