/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer;

import cocktail.core.geom.Matrix;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.unit.UnitManager;
import cocktail.core.unit.UnitData;

/**
 * This is a static class in charge of
 * computing the transition styles
 * 
 * @author Yannick DOMINGUEZ
 */
class TransitionStylesComputer 
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
	 * Compute all the transition styles
	 * 
	 * @param	style contain the styles definition of the 
	 * target htmlElement
	 */
	public static function compute(style:CoreStyle):Void
	{
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyle = style.computedStyle;
		
		//transition-delay
		computedStyle.transitionDelay = getComputedTransitionDelay(style);
		
		//transition-duration
		computedStyle.transitionDuration = getComputedTransitionDuration(style);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'transition-duration' style
	 */
	private static function getComputedTransitionDuration(style:CoreStyle):Array<Float>
	{
		var transitionDurations:Array<Float> = new Array<Float>();
		
		for (i in 0...style.transitionDuration.length)
		{
			switch (style.transitionDuration[i])
			{
				case TimeValue.seconds(value):
					transitionDurations.push(value);
					
				case TimeValue.milliSeconds(value):
					//convert to seconds
					transitionDurations.push(value / 1000);
			}
		}
		
		return transitionDurations;
		
	}
	
	/**
	 * Compute the 'transition-delay' style
	 */
	private static function getComputedTransitionDelay(style:CoreStyle):Array<Float>
	{
		var transitionDelays:Array<Float> = new Array<Float>();

		for (i in 0...style.transitionDelay.length)
		{
			switch (style.transitionDelay[i])
			{
				case TimeValue.seconds(value):
					transitionDelays.push(value);
					
				case TimeValue.milliSeconds(value):
					//convert to seconds
					transitionDelays.push(value / 1000);
			}
		}
		
		return transitionDelays;
	}
}