/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.resource;

import cocktail.core.MediaLoader;
import cocktail.core.NativeElement;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.nativeElement.NativeElementData;
import haxe.Http;
import haxe.Log;

/**
 * This class is in charge of loading a picture. When multiple
 * pictures are loaded with the same instance, the picture is 
 * replaced
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractImageLoader extends MediaLoader
{
	/**
	 * class constructor. Instantiate
	 * the right nativeElement to load a picture
	 */
	public function new()
	{
		var nativeElement:NativeElement = NativeElementManager.createNativeElement(image);
		super(nativeElement);
	}
}