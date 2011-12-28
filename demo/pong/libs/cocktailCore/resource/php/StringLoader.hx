/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.php;

import haxe.Http;
import cocktailCore.resource.abstract.AbstractResourceLoader;
import php.FileSystem;
import php.Web;

/**
 * Implementation of StringLoader for the PHP runtime, used to load resources
 * such as ax XML or JSON files. It uses the default implementation, found in 
 * its parent class, the haxe.Http class acting as an abstraction layer
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class StringLoader extends AbstractResourceLoader
{
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method to implement PHP specific behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts the file loading and converts the relative url to absolute url.
	 * The default implementation is to load an url and return the result as a String.
	 * It might be used to load, XML, JSON...
	 * @param	url the url to load
	 */
	override private function doLoad(relativeUrl:String):Void 
	{
		// get server port
		var port:Int = untyped __var__('_SERVER', 'SERVER_PORT');
		
		// converts relative url to absolute url
		var absoluteUrl:String = 'http://' + Web.getHostName() + ':' + port + Web.getURI() + relativeUrl;
		
		// call parent method
		super.doLoad(absoluteUrl);
	}
}