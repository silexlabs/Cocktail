/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.animation;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.event.TransitionEvent;

import cocktail.core.animation.AnimationData;
import cocktail.core.css.CSSData;
import cocktail.core.renderer.RendererData;

/**
 * 
 * This class is responsible for starting 
 * the transition of an ElementRenderer when
 * needed. When the value of a style
 * which can be transitioned is changed, 
 * it is stored in an array for pending
 * animation and will actually start on next layout
 * 
 * TODO 3 : name of class is confusing
 * 
 * @author Yannick DOMINGUEZ
 */
class Animator 
{
	/**
	 * An array holding the data necessary to start all pending
	 * animations on next layout
	 */
	private var _pendingAnimations:Array<PendingAnimationData>;
	
	/**
	 * Called when a transition has just been completed
	 */
	public var onTransitionCompleteCallback:Transition->Void;
	
	/**
	 * Called on update event of the animation
	 */
	public var onTransitionUpdateCallback:Transition->Void;

	public function new() 
	{
		_pendingAnimations = new Array<PendingAnimationData>();
	}
	
	/////////////////////////////////
	// PUBLIC TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * Tries to start each of the stored pending animations
	 * 
	 * @return wether at least one animation did start
	 */
	public function startPendingAnimations(style:CoreStyle):Bool
	{
		var atLeastOneAnimationStarted:Bool = false;
		
		for (i in 0..._pendingAnimations.length)
		{
			var animationStarted:Bool = startTransitionIfNeeded(_pendingAnimations[i], style);
			if (animationStarted == true)
			{
				atLeastOneAnimationStarted = true;
			}
		}
		
		//clear the pending animation to prevent from being started
		//for each layout
		_pendingAnimations = new Array<PendingAnimationData>();
		
		return atLeastOneAnimationStarted;
	}
	
	/**
	 * Register a pending animation that will tries to start on next layout.
	 * A pending animation is registered when the specified value of an
	 * animatable property is changed
	 * 
	 * @param	propertyName the name of the property to animate
	 * @param	invalidationReason the invalidation reason caused by the property change
	 * @param	startValue the current computed value of the animatable property, used as
	 * starting value if the animation actually starts
	 */
	public function registerPendingAnimation(propertyName:String, invalidationReason:InvalidationReason, startValue:Float):Void
	{
		_pendingAnimations.push( {
			propertyName:propertyName,
			invalidationReason:invalidationReason,
			startValue:startValue
		});
	}
	
	/////////////////////////////////
	// PRIVATE TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * When the specified value of a style changes, starts
	 * a transition for the proeprty if needed using the
	 * TransitionManager
	 * 
	 * @param pendingAnimation the data of the animation which might
	 * start
	 * @return wheter the animation did start
	 */
	private function startTransitionIfNeeded(pendingAnimation:PendingAnimationData, style:CoreStyle):Bool
	{	
		var usedValues:UsedValuesVO = style.usedValues;
		
		//will store the index of the property in the TransitionPorperty
		//array, so that its duration, delay, and timing function can be found
		//at the same index
		var propertyIndex:Int = 0;
		
		//check if the changed property is supposed to be transitioned
		switch (style.transitionProperty)
		{
			case KEYWORD(value):
				switch(value)
				{
					//if none, the method returns here as no property
					//of this style should be transitioned
					case NONE:
						return false;
						
					//here all property can transition. The index
					//will stay at 0	
					case ALL:	
						
					default:
						throw 'Illegal keyword value for transition property';
				}
				
			case IDENTIFIER(value):
				//if only one property name is defined, it must
				//match the name of the pending animation property
				if (value != pendingAnimation.propertyName)
				{
					return false;
				}		
			
			//here, check in the list of transitionable property
			//for a match
			case CSS_LIST(value):
				var foundFlag:Bool = false;
				
				for (i in 0...value.length)
				{
					switch(value[i])
					{
						case IDENTIFIER(value):
							//if there is a match, store the index
							//of the match
							if (value == pendingAnimation.propertyName)
							{
								propertyIndex = i;
								foundFlag = true;
								break;
							}	
							
						default:
							throw 'Illegal value for transition property';
					}
				}
				
				//if there is no match, the method stops
				//here
				if (foundFlag == false)
				{
					return false;
				}
			
			default:
				throw'Illegal values for transition property style';
		}

		//the combined duration is the combined duration
		//and delay of the transition, 
		var combinedDuration:Float = 0.0;
		
		//convert CSS values for transition delays and durations as an array of float,
		//where each float is a time in milliseconds
		var transitionDelays:Array<Float> = getAsFloatArray(style.transitionDelay);
		var transitionDurations:Array<Float> = getAsFloatArray(style.transitionDuration);
		
		//get  the delay and duration of the transition in their respective array
		//using the same index as the one in the transitionproperty array
		
		var transitionDelay:Float = transitionDelays[getRepeatedIndex(propertyIndex, transitionDelays.length)];
		var transitionDuration:Float = transitionDurations[getRepeatedIndex(propertyIndex, transitionDurations.length)];
		combinedDuration = transitionDuration + transitionDelay;
			
		//if the combined duration is not superior to
		//0, then there is no transition
		if (combinedDuration <= 0)
		{
			return false;
		}
		
		var transitionTimingFunctionAsArray:Array<CSSPropertyValue> = getTransitionTimingFunctionsAsArray(style.transitionTimingFunction);
		
		//get the transition timing function
		var transitionTimingFunction:CSSPropertyValue = transitionTimingFunctionAsArray[getRepeatedIndex(propertyIndex,transitionTimingFunctionAsArray.length)];
		
		var transitionManager:TransitionManager = TransitionManager.getInstance();
		
		//check if a transition is already in progress for the same property
		var transition:Transition = transitionManager.getTransition(pendingAnimation.propertyName, style);
		
		//if the transition is not null, then a transition for the property is already
		//in progress and no new transition must start
		if (transition != null)
		{
			//TODO 1 : in the spec, transition are not supposed to be interrupted
			//unless transitionProperty change or transition should reverse
			//transitionManager.stopTransition(transition);
			//TODO 1 : add the reverse transition case
			return false;
		}
		
		//get the current value of the property to animate. Since the ElementRenderer was laid out
		//after the pending animation was registered, the current computed value of the property
		//is now the end value of the transition
		
		//TODO 1 : really messy to use reflection + for now transition only work for number properties
		var endValue:Float = Reflect.getProperty(style.usedValues, pendingAnimation.propertyName);
		
		//start a transition using the TransitionManager
		transitionManager.startTransition(style, pendingAnimation.propertyName, pendingAnimation.startValue, endValue, 
		transitionDuration, transitionDelay, transitionTimingFunction, onTransitionComplete, onTransitionUpdate, pendingAnimation.invalidationReason);
	
		//the transition did in fact start
		return true;
	}
	
	/**
	 * Utils method returning all the transition timing functions in an array
	 * 
	 * TODO 1 : support for lists
	 */
	private function getTransitionTimingFunctionsAsArray(transitionTimingFunction:CSSPropertyValue):Array<CSSPropertyValue>
	{
		switch(transitionTimingFunction)
		{
			case KEYWORD(value):
				return [transitionTimingFunction];
				
			default:
				return null;
		}
	}
	
	/**
	 * Utils method to convert a CSS transition
	 * value from a CSS type to an array of float, 
	 * where each item is a time in milliseconds
	 */
	private function getAsFloatArray(value:CSSPropertyValue):Array<Float>
	{
		var floats:Array<Float> = new Array<Float>();
		
		switch(value)
		{
			case INTEGER(value):
				floats.push(value);
			
			case TIME(value):
				switch(value)
				{
					case MILLISECONDS(value):
						floats.push(value);
						
					case SECONDS(value):
						floats.push(value * 1000);
						
					default:	
				}
				
			default:
		}
		
		return floats;
	}
	
	/**
	 * Utils method, which return, given
	 * an index and the length of an array, the 
	 * actual index to use by looping in the length
	 * if the length is inferior to the index
	 * 
	 * @example if the length is 2 and the index is 3,
	 * the returned index will be 0, as by looping in the length,
	 * the index will be 0,1,0
	 */
	private function getRepeatedIndex(index:Int, length:Int):Int
	{
		if (index < length)
		{
			return index;
		}
		
		return length % index;
	}
	
	/**
	 * When a transition is complete, call the transition 
	 * complete callback
	 */
	private function onTransitionComplete(transition:Transition):Void
	{
		this.onTransitionCompleteCallback(transition);
		
	}
	
	/**
	 * When a transition is updated, call the update
	 * callback
	 */
	private function onTransitionUpdate(transition:Transition):Void
	{
		this.onTransitionUpdateCallback(transition);
	}
}