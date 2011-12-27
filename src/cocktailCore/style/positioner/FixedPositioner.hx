/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.positioner;
import cocktail.domElement.DOMElement;

/**
 * This is the box positioner class for
 * 'fixed' DOMElements. There are positioned
 * by using the viewport as origin
 * 
 * @author Yannick DOMINGUEZ
 */
class FixedPositioner extends BoxPositioner
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden because the global x applied to a fixed DOMElement
	 * is always 0 as its origin is the viewport
	 */
	override private function applyGlobalX(domElement:DOMElement, globalX:Int):Void
	{
		domElement.globalX = 0;
	}
	
	/**
	 * Overriden because the global y applied to a fixed DOMElement
	 * is always 0 as its origin is the viewport
	 */
	override private function applyGlobalY(domElement:DOMElement, globalY:Int):Void
	{
		domElement.globalY = 0;
	}
	
}