/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style.computer.boxComputers;
import core.style.AbstractStyle;
import core.style.StyleData;
import haxe.Log;

/**
 * This is the box computer for inlineBlock non-embedded
 * DOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBlockBoxStylesComputer extends BoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for inlineBlock non-embedded DOMElements, auto margin compute to 0
	 */
	override private function getComputedAutoMargin(marginStyleValue:Margin, opositeMargin:Margin, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool):Int
	{
		return 0;
	}
	
	/**
	 * if the width is set to 'auto', then this method is called once all the children
	 * of the inlineBlock are laid out
	 * 
	 * TODO : doesn't return the right value when inline-block establishing inline formatting context in inline formatting context
	 * with 'auto'
	 * , maybe should use the available width
	 */
	override public function shrinkToFit(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		//if the minimum width that must use the inlineBlock
		//is not superior to the width of the containing
		//DOMElement, use the minimum width
		if (minimumWidth < containingDOMElementData.width)
		{
			shrinkedWidth = minimumWidth;
		}
		else
		{
			shrinkedWidth = containingDOMElementData.width;
		}
		
		return shrinkedWidth;
	}
	
}