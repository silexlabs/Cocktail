/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.renderer;
import core.nativeElement.NativeElement;
import core.geom.GeomData;
import core.Style;
import core.Window;

/**
 * This is the ElementRenderer generated by a BodyDOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialBlockRenderer extends BlockBoxRenderer
{
	/**
	 * class constructor. Set the viewport as the bounds
	 * of the ElementRenderer, as a BodyDOMElement
	 * always covers all of the viewport
	 */
	public function new(style:Style) 
	{
		super(style);
		
		var window:Window = new Window();
		var width:Float = window.innerWidth;
		var height:Float = window.innerHeight;
		
		_bounds.width = width;
		_bounds.height = height;
	}
	
	override public function isInitialContainer():Bool
	{
		return true;
	}
	
}