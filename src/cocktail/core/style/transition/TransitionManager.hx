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
import cocktail.core.renderer.RendererData;

/**
 * The transition manager is in charge of starting
 * and stopping the transition of properties.
 * 
 * When at least one transition is in progress, the
 * TransitionManager sets a timer to update the transition
 * while in progress
 * 
 * The TransitionManager is a singleton and is in charge of
 * all the transitions in the Document
 * 
 * The data flow of a transition is as follow : 
	 * - the value of a transitionable property is updated
	 * - a pending animation is registered storing all the data needed to start
	 * a transition
	 * - when the next scheduled layout starts, CoreStyle tries to start all registered
	 * pending animations
	 * - CoreStyle checks if the property should be transitioned
	 * - if it does, starts a new transition using the TransitionManager
	 * - the TransitionManager calls at regular interval the onUpdate callback
	 * of each transition, which triggers invalidation in CoreStyle, thus
	 * re-painting the document as needed
	 * - While a transition is in progress, the corresponding ComputedStyle only return its
	 * transitioned value
	 * - When the transition is complete, calls its complete callback, triggering invalidation
	 * in CoreStyle and the dispatch of a transition end event on the transitioned element
 * 
 * @author Yannick DOMINGUEZ
 */
class TransitionManager 
{
	/**
	 * The instance for the singleton pattern
	 */
	private static var _instance:TransitionManager;
	
	/**
	 * The time, in milliseconds between each update of the transition
	 * in progress
	 */
	private static inline var TRANSITION_UPDATE_SPEED:Int = 20;
	
	/**
	 * Store a ref to each transitions in progress, where
	 * the key is a CSS property name and the value is the
	 * array of transition in progress for this property
	 * name
	 */
	private var _transitions:Hash<Array<Transition>>;
	
	/**
	 * The current number of transition in progress. When it
	 * drops to 0, stop the update timer
	 */
	private var _currentTransitionsNumber:Int;
	
	/**
	 * The timestamp of the last tick of the update Timer.
	 * Stored to compensate the elapsed time when the time between
	 * two timer tick was longer than intended
	 */
	private var _lastTick:Float;
	
	/**
	 * class constructor. private for
	 * singleton
	 */
	private function new() 
	{
		_transitions = new Hash();
		_currentTransitionsNumber = 0;
		_lastTick = 0;
	}
	
	/**
	 * Singleton method
	 */
	public static function getInstance():TransitionManager
	{
		if (_instance == null)
		{
			_instance = new TransitionManager();
		}
		
		return _instance;
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////

	/**
	 * Return a transition currently in progress using the name of a property
	 * and a given target computed style.
	 * 
	 * Returns null if no transition matches
	 */
	public function getTransition(propertyName:String, style:ComputedStyle):Transition
	{
		//shortcut, return null if no transition
		//are currently in progress
		if (_currentTransitionsNumber == 0)
		{
			return null;
		}
		
		//check that a key in the hash matches the property name.
		//if it does not then no property with this name is transitioning
		if (_transitions.exists(propertyName))
		{
			var propertyTransitions:Array<Transition> = _transitions.get(propertyName);
			//look for a transition object with the right target
			var length:Int = propertyTransitions.length;
			for (i in 0...length)
			{
				if (propertyTransitions[i].target == style)
				{
					return propertyTransitions[i];
				}
			}
		}
		
		return null;
	}
	
	/**
	 * start a new transition by instantiating a new 
	 * Transition obejct
	 */
	public function startTransition(target:ComputedStyle, propertyName:String, startValue:Float, endValue:Float, transitionDuration:Float, 
	transitionDelay:Float, transitionTimingFunction:TransitionTimingFunctionValue, onComplete:Transition->Void, onUpdate:Transition->Void, invalidationReason:InvalidationReason):Void
	{
		//create a new transition
		var transition:Transition = new Transition(propertyName, target, transitionDuration, transitionDelay, transitionTimingFunction,
		startValue, endValue, onComplete, onUpdate, invalidationReason);

		//create a key in the hash for the property name
		//of the new transition if necessary
		if (_transitions.exists(propertyName) == false)
		{
			_transitions.set(propertyName, []);
		}
		
		//store the new transition
		var propertyTransitions:Array<Transition> = _transitions.get(propertyName);
		propertyTransitions.push(transition);
		
		//if the number of transition in progress was 0
		//before this one, then the update timer must be
		//started
		if (_currentTransitionsNumber == 0)
		{
			startTransitionTimer();
		}
		
		//increment the number of transition in progress
		_currentTransitionsNumber++;
	}
	
	/**
	 * Stop a transition upon completion or if it was
	 * canceled ansd dispose of it
	 */
	public function stopTransition(transition:Transition):Void
	{
		//remove the stored reference to the transition
		var propertyTransitions:Array<Transition> = _transitions.get(transition.propertyName);
		propertyTransitions.remove(transition);
		//clean-up
		transition.dispose();
		
		//decrement the number of transition in prgress
		//to be sure that the update timer stops if there
		//are no more transition in progress
		_currentTransitionsNumber--;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Start the update timer
	 */
	private function startTransitionTimer():Void
	{
		//store the current date timestamp, so that
		//on each timer tick, the actual elapsed
		//time can be calculated
		_lastTick = Date.now().getTime();
		
		#if macro
		#elseif (flash9 || nme)
		//set a delayed method call which will be repeated
		//as long as needed
		haxe.Timer.delay(onTransitionTick, TRANSITION_UPDATE_SPEED);
		#end
	}
	
	/**
	 * Called at regular interval while at least one
	 * transition is in progress to call the right
	 * callback for the transition
	 */
	private function onTransitionTick():Void
	{
		//get the current timestamp
		var tick:Float = Date.now().getTime();
		//store the actual elapsed time since the last
		//time this methd was called, in milliseconds
		var interval:Float = tick - _lastTick;
		
		//the last time is updated for the next call
		//of this method
		_lastTick = tick;
		
		//loop in all Transition in the hash
		for (propertyTransitions in _transitions)
		{
			//store each completed transition, which will be stopped after this loop
			//(stopped after loop to prevent from modifying the transition array while
			//looping in it)
			var completedTransitions:Array<Transition> = new Array<Transition>();
			
			var length:Int = propertyTransitions.length;
			for (i in 0...length)
			{
				var transition:Transition = propertyTransitions[i];
				
				//update the elapsed time of the transition with
				//the actual elapsed interval since this method
				//was last called
				transition.updateTime(interval);
				
				//call the right callback for the transition
				if (transition.complete == true)
				{
					//here the transition is complete
					transition.onComplete(transition);
					//if the transition is complete, store it to stop it
					//afterwards
					completedTransitions.push(transition);
				}
				else
				{
					//here the transition is not yet complete
					transition.onUpdate(transition);
				}
			}
			
			//remove completed transitions
			var completedTransitionsLength:Int = completedTransitions.length;
			for (i in 0...completedTransitionsLength)
			{
				stopTransition(completedTransitions[i]);
			}
		}
		
		//while the number of transition in progress doesn't
		//drop to 0, delay a call to this method
		if (_currentTransitionsNumber > 0)
		{
			#if macro
			#elseif (flash9 || nme)
			Timer.delay(onTransitionTick, TRANSITION_UPDATE_SPEED);
			#end
		}
	}
	
	
}