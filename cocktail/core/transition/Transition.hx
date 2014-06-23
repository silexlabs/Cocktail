/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.transition;

import cocktail.geom.CubicBezier;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.parser.ParserData;
import cocktail.css.CSSStyleData;

/**
 * Represents a property transition form a start
 * value to an end value over a given period of time.
 * 
 * The transition can return the current value 
 * of the property based on the current time and
 * the used easing function
 * 
 * @author Yannick DOMINGUEZ
 */
class Transition 
{
	/**
	 * The delay to apply to the transition
	 * before it actually starts
	 */
	public var transitionDelay(default, null):Float;
	
	/**
	 * The easing function that should be used for
	 * this property
	 */
	public var transitionTimingFunction(default, null):CSSPropertyValue;
	
	/**
	 * The value of the transitioned property when
	 * the transition started
	 */
	public var startValue(default, null):Float;
	
	/**
	 * The value that the transitioned property
	 * will have when the transition is complete
	 */
	public var endValue(default, null):Float;
	
	/**
	 * The elapsed time, in milliseconds, since the transition
	 * started
	 */
	private var _elapsedTime:Float;
	
	/**
	 * An instance of the class used to compute easing
	 */
	private var _cubicBezier:CubicBezier;
	
	/**
	 * The index of the transitioned property.
	 */
	public var propertyIndex(default, null):Int;
	
	/**
	 * Returns the current value of the transitioned property,
	 * based on the current time and the used easing function
	 */
	public var currentValue(get_currentValue, never):Float;
	
	/**
	 * Called on the target computed style once the transition is complete
	 */
	public var onComplete(default, null):Transition->Void;
	
	/**
	 * Callback called while the transition is in progress. The interval
	 * between two calls of this method is controlled by the
	 * TransitionManager
	 */
	public var onUpdate(default, null):Transition->Void;
	
	/**
	 * the duration of the transition, in seconds
	 */
	public var transitionDuration(default, null):Float;
	
	/**
	 * The target CoreStyle of the transition onto which
	 * update and complete method are called
	 */
	public var target(default, null):CoreStyle;
	
	/**
	 * Returns wether the transition is complete based on the
	 * elapsed time since it started
	 */
	public var complete(get_complete, never):Bool;
	
	/**
	 * class constructor. Set
	 * the transition attribute
	 */
	public function new(propertyIndex:Int, target:CoreStyle, transitionDuration:Float, transitionDelay:Float, transitionTimingFunction:CSSPropertyValue,
	startValue:Float, endValue:Float, onComplete:Transition->Void, onUpdate:Transition->Void) 
	{
		this.transitionDelay = transitionDelay;
		this.transitionDuration = transitionDuration;
		this.transitionTimingFunction = transitionTimingFunction;
		this.startValue = startValue;
		this.endValue = endValue;
		this.target = target;
		this.propertyIndex = propertyIndex;
		this.onComplete = onComplete;
		this.onUpdate = onUpdate;
		_elapsedTime = 0;
		_cubicBezier = new CubicBezier();
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Update the elapsed time of the 
	 * transition
	 */
	public function updateTime(delta:Float)
	{
		_elapsedTime += delta;
	}
	
	/**
	 * clean-up method called once a 
	 * transition is complete
	 */
	public function dispose():Void
	{
		onComplete = null;
		onUpdate = null;
		transitionTimingFunction = null;
	}
	
	/**
	 * Revert the transition, which set its
	 * stat value to be its end value.
	 * A transition can be reveted any
	 * number of tmes while it is in progress
	 */
	public function revert():Void
	{
		//"invert" elapsed time, including transition delay,
		//as delay isn't used when reverting
		_elapsedTime = transitionDuration + transitionDelay - _elapsedTime;
		
		//swap end and start values
		var oldEndValue:Float = endValue;
		endValue = startValue;
		startValue = oldEndValue;
	}
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	/**
	 * A transition is complete if the elaped
	 * time since its started is superior to 
	 * the transition duration + the delay
	 * of the transition
	 */
	private function get_complete():Bool
	{
		if (_elapsedTime >= (transitionDelay + transitionDuration))
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Return the current value of the transitioned
	 * property based on the elapsed time and the used easing
	 * function
	 */
	private function get_currentValue():Float
	{
		//offet between the elapsed time since the transition started 
		//and the delay to apply to the transition before actually
		//tweening value
		var transitionTime:Float = _elapsedTime - (transitionDelay);
		//if the offset is negative, it means that the transition delay time
		//is not yet complete, and so the start value must be returned
		if (transitionTime < 0)
		{
			return startValue;
		}
		
		var completePercent:Float = (transitionTime) / (transitionDuration);
		
		switch (transitionTimingFunction)
		{
			case KEYWORD(value):
				switch(value)
				{
					//cubic bezier functions
					case EASE:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((endValue - startValue) * _cubicBezier.bezierY(completePercent)) + startValue;
						
					case EASE_IN:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((endValue - startValue) * _cubicBezier.bezierY(completePercent)) + startValue;
						
					case EASE_OUT:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((endValue - startValue) * _cubicBezier.bezierY(completePercent)) + startValue;	
						
					case EASE_IN_OUT:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((endValue - startValue) * _cubicBezier.bezierY(completePercent)) + startValue;
						
					//step functions	
					case STEP_START:
						return ((endValue - startValue) * 1) + startValue;	
						
					case STEP_END:
						return ((endValue - startValue) * 0) + startValue;	
						
					//linear function
					case LINEAR:
						return ((endValue - startValue) * completePercent) + startValue;	
						
					default:
						throw 'Illegal keyword value for transition timing function style';
				}
				
			case CUBIC_BEZIER(x1, y1, x2, y2):
				_cubicBezier.init(x1, y1, x2, y2);
				return ((endValue - startValue) * _cubicBezier.bezierY(completePercent)) + startValue;	
			
			//TODO 1 : implement stepping function	
			case STEPS(intervalNumbers, intervalChange):
				return ((endValue - startValue) * completePercent) + startValue;	
				
			default:
				throw 'Illegal value for transition timing function style';
		}
	}
}
