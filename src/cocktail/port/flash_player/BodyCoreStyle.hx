/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.NativeElement;
import cocktail.core.HTMLElement;
import cocktail.core.style.AbstractBodyCoreStyle;
import flash.Lib;
import haxe.Log;

/**
 * This is the Flash AS3 implementation of the BodyStyle
 * 
 * @author Yannick DOMINGUEZ
 */
class BodyCoreStyle extends AbstractBodyCoreStyle
{
	/**
	 * class constructor
	 * @param	htmlElement
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	// The body attach/detach its children from the flash Stage
	//////////////////////////////////////////////////////////////////////////////////////////
	

	override private function attachNativeElement(nativeElement:NativeElement):Void
	{
		Lib.current.addChild(nativeElement);
	}
	
	override private function detachNativeElement(nativeElement:NativeElement):Void
	{
		//TODO : this check is only neccessary as long
		//as nativeElement are added to stage for hit test.
		//To be removed once hit test is implemented on layerRenderer
		if (Lib.current.contains(nativeElement))
		{
			Lib.current.removeChild(nativeElement);
		}
	}
	
}