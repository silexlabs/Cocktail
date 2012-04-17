/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.html.AbstractHTMLDocument;
import cocktail.core.NativeElement;

/**
 * This is the flash player implementation of
 * the HTMLDocument
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLDocument extends AbstractHTMLDocument
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	// attach/detach the rendered native elements to/from the flash Stage
	//////////////////////////////////////////////////////////////////////////////////////////

	override private function attachNativeElement(nativeElement:NativeElement):Void
	{
		flash.Lib.current.addChild(nativeElement);
	}
	
	override private function detachNativeElement(nativeElement:NativeElement):Void
	{
		flash.Lib.current.removeChild(nativeElement);
	}
}