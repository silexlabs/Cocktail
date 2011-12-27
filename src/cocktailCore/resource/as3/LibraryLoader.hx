/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.as3;

import cocktail.nativeElement.NativeElement;
import cocktailCore.resource.abstract.AbstractLibraryLoader;

/**
 * This is the implementation of the library loader for the Flash AVM2 runtime. A library in Flash AS3 is a .swf
 * file containing ActionScript3 classes. It is loaded like a visual element (DisplayObject) but it is not added to
 * the Flash DOM
 * @author Yannick DOMINGUEZ
 */
class LibraryLoader extends AbstractLibraryLoader
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
}