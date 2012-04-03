/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer.boxComputers;

import cocktail.core.style.AbstractStyle;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitManager;
import haxe.Log;

/**
 * This is the box computer for inline embedded HTMLElement,
 * such as for instance an ImageHTMLElement inserted in a
 * text
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedInlineBoxStylesComputer extends EmbeddedBlockBoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for inline embedded HTMLElement, auto margins compute to 0
	 */
	override private function getComputedAutoMargin(marginStyleValue:Margin, opositeMargin:Margin, containingHTMLElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool):Int
	{
		return 0;
	}
	
}