/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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