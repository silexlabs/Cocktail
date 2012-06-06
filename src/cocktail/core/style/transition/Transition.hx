/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.transition;

import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;

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
	private var _propertyName:String;
	public var propertyName(get_propertyName, never):String;
	
	/**
	 * Returns the current value of the transitioned property,
	 * based on the current time and the used easing function
	 */
	public var currentValue(get_currentValue, never):Float;
	
	/**
	 * Called on the target computed style once the transition is complete
	 */
	private var _onComplete:Transition->Void;
	public var onComplete(get_onComplete, never):Transition->Void;
	
	/**
	 * Callback called while the transition is in progress. The interval
	 * between two calls of this method is controlled by the
	 * TransitionManager
	 */
	private var _onUpdate:Transition->Void;
	public var onUpdate(get_onUpdate, never):Transition->Void;
	
	/**
	 * the duration of the transition, in seconds
	 */
	private var _transitionDuration:Float;
	public var transitionDuration(get_transitionDuration, never):Float;
	
	/**
	 * The target ComputedStyle of the transition onto which
	 * update and complete method are called
	 */
	private var _target:ComputedStyle;
	public var target(get_target, never):ComputedStyle;
	
	/**
	 * Returns wether the transition is complete based on the
	 * elapsed time since it started
	 */
	public var complete(get_complete, never):Bool;
	
	/**
	 * class constructor. Set
	 * the transition attribute
	 */
	public function new(propertyName:String, target:ComputedStyle, transitionDuration:Float, transitionDelay:Float, transitionTimingFunction:TransitionTimingFunctionValue,
	startValue:Float, endValue:Float, onComplete:Transition->Void, onUpdate:Transition->Void) 
	{
		_transitionDelay = transitionDelay;
		_transitionDuration = transitionDuration;
		_transitionTimingFunction = transitionTimingFunction;
		_startValue = startValue;
		_endValue = endValue;
		_target = target;
		_propertyName = propertyName;
		_onComplete = onComplete;
		_onUpdate = onUpdate;
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
	 */
	public function dispose():Void
	{
		_onComplete = null;
		_onUpdate = null;
		_target = null;
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
		if (_elapsedTime >= (_transitionDelay + _transitionDuration) * 1000)
		{
			return true;
		}
		
		return false;
	}
	
	//TODO 1 : implement easing function
	private function get_currentValue():Float
	{
		var completePercent:Float = (_elapsedTime) / ((_transitionDelay + _transitionDuration) * 1000);
		return ((_endValue - _startValue) * completePercent) + _startValue;
	}
	
	private function get_transitionDuration():Float
	{
		return _transitionDuration;
	}
	
	private function get_target():ComputedStyle
	{
		return _target;
	}
	
	private function get_onComplete():Transition->Void
	{
		return _onComplete;
	}
	
	private function get_propertyName():String
	{
		return _propertyName;
	}
	
	private function get_onUpdate():Transition->Void
	{
		return _onUpdate;
	}
	
	
	
}