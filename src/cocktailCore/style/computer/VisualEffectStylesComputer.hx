/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer;

import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.Style;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;

/**
 * This is a static class in charge of
 * computing the visual effect styles
 * 
 * @author Yannick DOMINGUEZ
 */
class VisualEffectStylesComputer 
{
	/**
	 * Class contructor. Private, as
	 * this class is meant to be accessed
	 * through its public static methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute all the visual effect styles
	 * 
	 * @param	style contain the styles definition of the 
	 * target DOMElement
	 */
	public static function compute(style:AbstractStyle):Void
	{
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//opacity
		computedStyle.opacity = getComputedOpacity(style);
		
		//visibility
		computedStyle.visibility = getComputedVisibility(style);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'opacity' style.
	 */
	private static function getComputedOpacity(style:AbstractStyle):Float
	{
		var opacity:Float;
		
		switch (style.opacity)
		{
			case OpacityStyleValue.number(value):
				opacity = value;
		}
		
		return opacity;
	}
	
	/**
	 * Compute the 'visibility' style
	 */
	private static function getComputedVisibility(style:AbstractStyle):Bool
	{
		var visibility:Bool;
		
		switch(style.visibility)
		{
			case visible:
				visibility = true;
				
			case hidden:
				visibility = false;
		}
		
		return visibility;
	}
}