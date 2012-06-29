/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.transition;

import cocktail.core.geom.CubicBezier;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.CSSConstants;
import cocktail.core.style.StyleData;
import cocktail.core.renderer.RendererData;

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
	private var _transitionDelay:Float;
	
	/**
	 * The easing function that should be used for
	 * this property
	 */
	private var _transitionTimingFunction:TransitionTimingFunctionValue;
	
	/**
	 * The value of the transitioned property when
	 * the transition started
	 */
	private var _startValue:Float;
	
	/**
	 * The value that the transitioned property
	 * will have when the transition is complete
	 */
	private var _endValue:Float;
	
	/**
	 * The elapsed time, in milliseconds, since the transition
	 * started
	 */
	private var _elapsedTime:Float;
	
	/**
	 * The name of the transitioned property. This is
	 * a CSS property name
	 */
	public var propertyName(default, null):String;
	
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
	 * The target ComputedStyle of the transition onto which
	 * update and complete method are called
	 */
	public var target(default, null):ComputedStyle;
	
	/**
	 * Returns wether the transition is complete based on the
	 * elapsed time since it started
	 */
	public var complete(get_complete, never):Bool;
	
	/**
	 * A reference to the invalidation which started this transition,
	 * most liekly a property value change. Will be used for invalidation
	 * on each update tick
	 */
	public var invalidationReason(default, null):InvalidationReason;
	
	/**
	 * class constructor. Set
	 * the transition attribute
	 */
	public function new(propertyName:String, target:ComputedStyle, transitionDuration:Float, transitionDelay:Float, transitionTimingFunction:TransitionTimingFunctionValue,
	startValue:Float, endValue:Float, onComplete:Transition->Void, onUpdate:Transition->Void, invalidationReason:InvalidationReason) 
	{
		this.invalidationReason = invalidationReason;
		_transitionDelay = transitionDelay;
		this.transitionDuration = transitionDuration;
		_transitionTimingFunction = transitionTimingFunction;
		_startValue = startValue;
		_endValue = endValue;
		this.target = target;
		this.propertyName = propertyName;
		this.onComplete = onComplete;
		this.onUpdate = onUpdate;
		_elapsedTime = 0;
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
	 * 
	 * TODO 2 : risks of destroying objets instead of
	 * de-referencing, like for ElementRenderer.dispose
	 */
	public function dispose():Void
	{
		onComplete = null;
		onUpdate = null;
		//_target = null;
		_transitionTimingFunction = null;
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
		if (_elapsedTime >= (_transitionDelay + transitionDuration) * 1000)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Return tthe current value of the transitioned
	 * property based on the elapsed time and the used easing
	 * function
	 * 
	 * TODO 1 : manage delay
	 */
	private function get_currentValue():Float
	{
		var completePercent:Float = (_elapsedTime) / ((_transitionDelay + transitionDuration) * 1000);
		
		switch (_transitionTimingFunction)
		{
			//cubic bezier functions
			case TransitionTimingFunctionValue.ease:
				var cubicBezier:CubicBezier = new CubicBezier(0.25, 0.1, 0.25, 1.0);
				return ((_endValue - _startValue) * cubicBezier.bezierY(completePercent)) + _startValue;
				
			case TransitionTimingFunctionValue.easeIn:
				var cubicBezier:CubicBezier = new CubicBezier(0.25, 0.1, 0.25, 1.0);
				return ((_endValue - _startValue) * cubicBezier.bezierY(completePercent)) + _startValue;
				
			case TransitionTimingFunctionValue.easeOut:
				var cubicBezier:CubicBezier = new CubicBezier(0.25, 0.1, 0.25, 1.0);
				return ((_endValue - _startValue) * cubicBezier.bezierY(completePercent)) + _startValue;	
				
			case TransitionTimingFunctionValue.easeInOut:
				var cubicBezier:CubicBezier = new CubicBezier(0.25, 0.1, 0.25, 1.0);
				return ((_endValue - _startValue) * cubicBezier.bezierY(completePercent)) + _startValue;		
				
			case TransitionTimingFunctionValue.cubicBezier(x1, y1, x2, y2):
				var cubicBezier:CubicBezier = new CubicBezier(x1, y1, x2, y2);
				return ((_endValue - _startValue) * cubicBezier.bezierY(completePercent)) + _startValue;	
				
			//step functions	
			case TransitionTimingFunctionValue.stepStart:
				return ((_endValue - _startValue) * 1) + _startValue;	
				
			case TransitionTimingFunctionValue.stepEnd:
				return ((_endValue - _startValue) * 0) + _startValue;		
				
			//TODO 1 : implement
			case TransitionTimingFunctionValue.steps(intervalNumbers, intervalChange):
				return ((_endValue - _startValue) * completePercent) + _startValue;			
			
			//linear function
			case TransitionTimingFunctionValue.linear:
				return ((_endValue - _startValue) * completePercent) + _startValue;
		}
	}
}