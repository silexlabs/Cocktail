/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.animation;

import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.geom.CubicBezier;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSConstants;
import cocktail.core.layout.LayoutData;
import cocktail.core.renderer.RendererData;
import cocktail.core.css.CSSData;

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
	private var _transitionTimingFunction:CSSPropertyValue;
	
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
	 * An instance of the class used to compute easing
	 */
	private var _cubicBezier:CubicBezier;
	
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
	 * The target CSSStyleDeclaration of the transition onto which
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
	public function new(propertyName:String, target:CoreStyle, transitionDuration:Float, transitionDelay:Float, transitionTimingFunction:CSSPropertyValue,
	startValue:Float, endValue:Float, onComplete:Transition->Void, onUpdate:Transition->Void) 
	{
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
		if (_elapsedTime >= (_transitionDelay + transitionDuration))
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
		var transitionTime:Float = _elapsedTime - (_transitionDelay);
		//if the offset is negative, it means that the transition delay time
		//is not yet complete, and so the start value must be returned
		if (transitionTime < 0)
		{
			return _startValue;
		}
		
		var completePercent:Float = (transitionTime) / (transitionDuration);
		
		switch (_transitionTimingFunction)
		{
			case KEYWORD(value):
				switch(value)
				{
					//cubic bezier functions
					case EASE:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((_endValue - _startValue) * _cubicBezier.bezierY(completePercent)) + _startValue;
						
					case EASE_IN:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((_endValue - _startValue) * _cubicBezier.bezierY(completePercent)) + _startValue;
						
					case EASE_OUT:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((_endValue - _startValue) * _cubicBezier.bezierY(completePercent)) + _startValue;	
						
					case EASE_IN_OUT:
						_cubicBezier.init(0.25, 0.1, 0.25, 1.0);
						return ((_endValue - _startValue) * _cubicBezier.bezierY(completePercent)) + _startValue;
						
					//step functions	
					case STEP_START:
						return ((_endValue - _startValue) * 1) + _startValue;	
						
					case STEP_END:
						return ((_endValue - _startValue) * 0) + _startValue;	
						
					//linear function
					case LINEAR:
						return ((_endValue - _startValue) * completePercent) + _startValue;	
						
					default:
						throw 'Illegal keyword value for transition timing function style';
				}
				
			case CUBIC_BEZIER(x1, y1, x2, y2):
				_cubicBezier.init(x1, y1, x2, y2);
				return ((_endValue - _startValue) * _cubicBezier.bezierY(completePercent)) + _startValue;	
			
			//TODO 1 : implement stepping function	
			case STEPS(intervalNumbers, intervalChange):
				return ((_endValue - _startValue) * completePercent) + _startValue;	
				
			default:
				throw 'Illegal value for transition timing function style';
		}
	}
}