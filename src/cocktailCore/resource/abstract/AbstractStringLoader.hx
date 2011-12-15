/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.abstract;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktailCore.resource.ResourceLoader;
import haxe.Http;
import haxe.Log;

/**
 * This class is in charge of loading a data String 
 * which can be serialised as XML, JSON....
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractStringLoader extends ResourceLoader
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null)
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Private method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Load an URL and return it as a String using the Http class
	 * 
	 * @param	url the url to load
	 */
	override private function doLoad(url:String):Void
	{
		//prepare and send an http request
		var fileRequest:Http = new Http(url);
		fileRequest.onData = this.onLoadComplete;
		fileRequest.onError = this.onLoadError;
		fileRequest.request(false);
	}
}