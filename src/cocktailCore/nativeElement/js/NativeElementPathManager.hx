/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.nativeElement.js;

import js.Lib;
import cocktailCore.nativeElement.abstract.AbstractNativeElementPathManager;
import cocktail.nativeElement.NativeElement;

/**
 * This is the JavaScript implementation for the path manager. 
 * It returns the HTML document body
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeElementPathManager extends AbstractNativeElementPathManager
{
	/**
	 * class contructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Returns a reference to the Flash Stage
	 */
	override public function getRoot():NativeElement
	{
		return Lib.document.body;
	}
	
}