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
 * This class is in charge of loading a library of
 * classes
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractLibraryLoader extends ResourceLoader
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null)
	{
		//create a library NativeElement if none is provided
		if (nativeElement == null)
		{
			nativeElement = NativeElementManager.createNativeElement(library);
		}
		
		super(nativeElement);
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