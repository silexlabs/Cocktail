/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.transition;

import cocktail.core.css.CoreStyle;
import cocktail.css.CSSConstants;
import cocktail.event.TransitionEvent;

import cocktail.core.transition.TransitionData;
import cocktail.core.parser.ParserData;
import cocktail.css.CSSStyleData;
import cocktail.core.css.CSSCascadeData;

/**
 * 
 * This class is responsible for starting 
 * transitions of styles of an ElementRenderer when
 * needed. When the value of a style
 * which can be transitioned is changed, 
 * it is stored in an array for pending
 * transitions and will actually start on next 
 * document update
 * 
 * @author Yannick DOMINGUEZ
 */
class Transitioner 
{
	/**
	 * An array holding the data necessary to start all pending
	 * transitions on next update
	 */
	private var _pendingTransitions:Array<PendingTransitionVO>;
	
	/**
	 * Called when a transition has just been completed
	 */
	public var onTransitionCompleteCallback:Transition->Void;
	
	/**
	 * Called on update event of the animation
	 */
	public var onTransitionUpdateCallback:Transition->Void;

	/**
	 * a reference to the instance managing the document's transition
	 */
	private var _transitionManager:TransitionManager;
	
	/**
	 * class constructor
	 */
	public function new(transitionManager:TransitionManager) 
	{
		_transitionManager = transitionManager;
	}
	
	/////////////////////////////////
	// PUBLIC TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * Tries to start each of the stored pending transitions
	 * 
	 * @return wether at least one transition did start
	 */
	public function startPendingTransitions(style:CoreStyle):Bool
	{
		//do nothing if there are no pending transitions
		if (_pendingTransitions == null)
		{
			return false;
		}
		
		var atLeastOneTransitionStarted:Bool = false;
		
		var length:Int = _pendingTransitions.length;
		for (i in 0...length)
		{
			var transitionStarted:Bool = startTransitionIfNeeded(_pendingTransitions[i], style);
			if (transitionStarted == true)
			{
				atLeastOneTransitionStarted = true;
			}
		}
		
		//clear the pending transitions to prevent from being started
		//for each layout
		_pendingTransitions = [];
		
		return atLeastOneTransitionStarted;
	}
	
	/**
	 * Register a pending transition that will try to be started on next document update.
	 * A pending transition is registered when the specified value of a
	 * transitionable property is changed
	 * 
	 * @param	propertyIndex the index of the property to transition
	 * @param	startValue the current computed value of the transitionable property, used as
	 * starting value if the transition actually starts
	 */
	public function registerPendingTransition(propertyIndex:Int, startValue:Float):Void
	{
		var pendingTransition:PendingTransitionVO = new PendingTransitionVO();
		pendingTransition.propertyIndex = propertyIndex;
		pendingTransition.startValue = startValue;
		if (_pendingTransitions == null)
		{
			_pendingTransitions = new Array<PendingTransitionVO>();
		}
		_pendingTransitions.push(pendingTransition);
	}
	
	/**
	 * Revert a current transition which means that its start value
	 * becomes its end value
	 * @param	currentTransition the transition that might be reverted
	 * @param	currentValue the new value that was the set for the transitioned property
	 * @param	style
	 * @return	wether the transition was reverted
	 */
	public function revertTransitionIfNeeded(currentTransition:Transition, currentValue:Float, style:CoreStyle):Bool
	{
		//the new value for the style must match the beginning value
		//of the transition for the transition to be transitioned
		if (currentTransition.startValue != currentValue)
		{
			return false;
		}
		
		//check wether transition-duration, transition-delay and transition-timing-function
		//are the same as when the transition started. Any changes prevent a revert
		var indexInTransitionProperty:Int = getIndexOfPropertyInTransitionProperty(currentTransition.propertyIndex, style.transitionProperty);
		if (indexInTransitionProperty == -1)
		{
			return false;
		}
		
		var transitionDelays:Array<Float> = getAsFloatArray(style.transitionDelay);
		var transitionDelay:Float = transitionDelays[getRepeatedIndex(indexInTransitionProperty, transitionDelays.length)];
		if (currentTransition.transitionDelay != transitionDelay)
		{
			return false;
		}
		
		var transitionDurations:Array<Float> = getAsFloatArray(style.transitionDuration);
		var transitionDuration:Float = transitionDurations[getRepeatedIndex(indexInTransitionProperty, transitionDurations.length)];
		if (currentTransition.transitionDuration != transitionDuration)
		{
			return false;
		}
		
		var transitionTimingFunctionAsArray:Array<CSSPropertyValue> = getTransitionTimingFunctionsAsArray(style.transitionTimingFunction);
		var transitionTimingFunction:CSSPropertyValue = transitionTimingFunctionAsArray[getRepeatedIndex(indexInTransitionProperty, transitionTimingFunctionAsArray.length)];
		if (currentTransition.transitionTimingFunction != transitionTimingFunction)
		{
			return false;
		}
		
		//do revert the transition
		currentTransition.revert();
		return true;
	}
	
	/////////////////////////////////
	// PRIVATE TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * When the specified value of a style changes, starts
	 * a transition for the proeprty if needed using the
	 * TransitionManager
	 * 
	 * @param pendingTransition the data of the transition which might
	 * start
	 * @return wheter the transition did start
	 */
	private function startTransitionIfNeeded(pendingTransition:PendingTransitionVO, style:CoreStyle):Bool
	{	
		var usedValues:UsedValuesVO = style.usedValues;
		
		//will store the index of the property in the TransitionProperty
		//array, so that its duration, delay, and timing function can be found
		//at the same index
		var indexInTransitionProperty:Int = getIndexOfPropertyInTransitionProperty(pendingTransition.propertyIndex, style.transitionProperty);
		
		//if -1 means that this property
		//can't be transitioned
		if (indexInTransitionProperty == -1)
		{
			return false;
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
		
		var transitionDelay:Float = transitionDelays[getRepeatedIndex(indexInTransitionProperty, transitionDelays.length)];
		var transitionDuration:Float = transitionDurations[getRepeatedIndex(indexInTransitionProperty, transitionDurations.length)];
		combinedDuration = transitionDuration + transitionDelay;
		
		//if the combined duration is not superior to
		//0, then there is no transition
		if (combinedDuration <= 0)
		{
			return false;
		}
		
		var transitionTimingFunctionAsArray:Array<CSSPropertyValue> = getTransitionTimingFunctionsAsArray(style.transitionTimingFunction);
		
		//get the transition timing function
		var transitionTimingFunction:CSSPropertyValue = transitionTimingFunctionAsArray[getRepeatedIndex(indexInTransitionProperty,transitionTimingFunctionAsArray.length)];
		
		//check if a transition is already in progress for the same property
		var transition:Transition = _transitionManager.getTransition(pendingTransition.propertyIndex, style);
		
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
		
		//get the current value of the property to transition. Since the ElementRenderer was laid out
		//after the pending transition was registered, the current computed value of the property
		//is now the end value of the transition
		
		//TODO 1 : really messy to use reflection + for now transition only work for number properties
		var endValue:Float = getEndValue(style, pendingTransition.propertyIndex);
		
		//start a transition using the TransitionManager
		_transitionManager.startTransition(style, pendingTransition.propertyIndex, pendingTransition.startValue, endValue, 
		transitionDuration, transitionDelay, transitionTimingFunction, onTransitionComplete, onTransitionUpdate);
	
		//the transition did in fact start
		return true;
	}
	
	/**
	 * Return the index of the propertyIndex in the list of properties
	 * which can be transitioned
	 * @param 	propertyIndex the index of the searched properties
	 * @param	transitionProperty hold which property can be transitioned
	 * @return	the index of the property or -1 if the property is not in
	 * the list of transitioned properties
	 */
	private function getIndexOfPropertyInTransitionProperty(propertyIndex:Int, transitionProperty:CSSPropertyValue):Int
	{
		//check if the changed property is supposed to be transitioned
		switch (transitionProperty)
		{
			case KEYWORD(value):
				switch(value)
				{
					//if none, the method returns here as no property
					//of this style should be transitioned
					case NONE:
						return -1;
						
					//here all property can transition. The index
					//will stay at 0	
					case ALL:	
						return 0;
						
					default:
						throw 'Illegal keyword value for transition property';
				}
				
			case IDENTIFIER(value):
				//if only one property name is defined, it must
				//match the name of the pending animation property
				if (value != CSSConstants.getPropertyNameFromIndex(propertyIndex))
				{
					return -1;
				}		
				else
				{
					return 0;
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
							if (value == CSSConstants.getPropertyNameFromIndex(propertyIndex))
							{
								return i;
							}	
							
						default:
							throw 'Illegal value for transition property';
					}
				}
				
				//no match found
				return -1;
			
			default:
				throw'Illegal values for transition property style';
		}
	}
	
	/**
	 * Return the current used value for
	 * a given property, which can be used as
	 * end value
	 */
	private function getEndValue(style:CoreStyle, propertyIndex:Int):Float
	{
		switch(propertyIndex)
		{
			case CSSConstants.OPACITY:
				switch(style.opacity)
				{
					case NUMBER(value):
						return value;
					
					case ABSOLUTE_LENGTH(value):
						return value;
						
					default: 
						return 0;
				}
			
			default:
				
				return Reflect.field(style.usedValues, CSSConstants.getPropertyNameFromIndex(propertyIndex));
		}
	}
	
	/**
	 * Utils method returning all the transition timing functions in an array
	 */
	private function getTransitionTimingFunctionsAsArray(transitionTimingFunction:CSSPropertyValue):Array<CSSPropertyValue>
	{
		switch(transitionTimingFunction)
		{
			case KEYWORD(value):
				return [transitionTimingFunction];
				
			case CSS_LIST(value):
				return value;
				
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
			case CSS_LIST(value):
				for (i in 0...value.length)
				{
					floats.push(getTransitionDelayOrDurationAsFloat(value[i]));
				}
				
			default:
				floats.push(getTransitionDelayOrDurationAsFloat(value));
		}
		
		return floats;
	}
	
	/**
	 * Convert a transition delay or duration, excluding list
	 * value as a float, representing the value in milliseconds
	 */
	private function getTransitionDelayOrDurationAsFloat(value:CSSPropertyValue):Float
	{
		switch(value)
		{
			case INTEGER(value):
				return value;
			
			case TIME(value):
				switch(value)
				{
					case MILLISECONDS(value):
						return value;
						
					case SECONDS(value):
						return value * 1000;
				}
				
			default:
		}
		
		return 0.0;
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
		else if (length == 1)
		{
			return 0;
		}
		
		//TODO : probably wrong
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
