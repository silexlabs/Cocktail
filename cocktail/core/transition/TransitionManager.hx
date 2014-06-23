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
import cocktail.core.html.HTMLDocument;
import cocktail.core.layout.LayoutData;
import cocktail.core.parser.ParserData;
import cocktail.core.transition.TransitionData;
import cocktail.css.CSSStyleData;

/**
 * The transition manager is in charge of starting
 * and stopping the transition of properties.
 * 
 * When at least one transition is in progress, the
 * TransitionManager set up delayed called to an
 * update method
 * 
 * The TransitionManager is in charge of
 * all the transitions in the Document, there is one instance
 * per document
 * 
 * The data flow of a transition is as follow : 
	 * - the value of a transitionable property is updated
	 * - a pending transition is registered storing all the data needed to start
	 * a transition
	 * - when the next scheduled document update starts, the transitioner tries to start all registered
	 * pending transitions
	 * - the transitioner checks if the property should be transitioned
	 * - if it does, starts a new transition using the TransitionManager
	 * - the TransitionManager schedule calls to its update callbacks while transitions
	 * are in progress, which triggers an invalidation mechanisms causing the document
	 * to be updated
	 * - While a transition is in progress, getting the computed value of the property return
	 * its current transitioning value
	 * - When the transition is complete, it calls its complete callback, triggering invalidation
	 * and the dispatch of a transition end event on the transitioned element
 * 
 * @author Yannick DOMINGUEZ
 */
class TransitionManager 
{
	/**
	 * Store a ref to each transitions in progress.
	 * Each index corresponds to one CSS style, referenced by
	 * its CSS property index,
	 * and the array at the index contains all
	 * the current transitions for this property index
	 */
	private var _transitions:Array<Array<Transition>>;
	
	/**
	 * The current number of transition in progress. When it
	 * drops to 0, stop the update timer
	 */
	private var _currentTransitionsNumber:Int;
	
	/**
	 * Wether at least one animation is in progress.
	 * Meant to provide fast access to this info 
	 * to exterior classes
	 */
	public var hasTransitionsInProgress:Bool;
	
	/**
	 * The timestamp of the last tick of the update Timer.
	 * Stored to compensate the elapsed time when the time between
	 * two timer tick was longer than intended
	 */
	private var _lastTick:Float;
	
	/**
	 * a reference to the document owning
	 * this instance
	 */
	private var _document:HTMLDocument;
	
	/**
	 * class constructor
	 */
	public function new(document:HTMLDocument) 
	{
		initTransitions();
		_document = document;
		_currentTransitionsNumber = 0;
		hasTransitionsInProgress = false;
		_lastTick = 0;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_transitions = null;
		_document = null;
	}
	
	/**
	 * Create the array holding transitions
	 */
	private function initTransitions():Void
	{
		_transitions = new Array<Array<Transition>>();
		//create one array of transition for each supported
		//CSS styles
		for (i in 0...CSSConstants.SUPPORTED_STYLES_NUMBER)
		{
			_transitions[i] = new Array<Transition>();
		}
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////

	/**
	 * Return a transition currently in progress using the index of a property
	 * and a given target computed style.
	 * 
	 * Returns null if no transition matches
	 */
	public function getTransition(propertyIndex:Int, style:CoreStyle):Transition
	{
		//get all the transitions in progress for the given property name
		var transitionsForProperty:Array<Transition> = getTransitionsForProperty(propertyIndex);
		if (transitionsForProperty.length == 0)
		{
			return null;
		}
		
		//look for a transition object with the right target
		var length:Int = transitionsForProperty.length;
		for (i in 0...length)
		{
			if (transitionsForProperty[i].target == style)
			{
				return transitionsForProperty[i];
			}
		}
		
		//no transition found
		return null;
	}
	
	/**
	 * start a new transition by instantiating a new 
	 * Transition obejct
	 */
	public function startTransition(target:CoreStyle, propertyIndex:Int, startValue:Float, endValue:Float, transitionDuration:Float, 
	transitionDelay:Float, transitionTimingFunction:CSSPropertyValue, onComplete:Transition->Void, onUpdate:Transition->Void):Void
	{
		//create a new transition
		var transition:Transition = new Transition(propertyIndex, target, transitionDuration, transitionDelay, transitionTimingFunction,
		startValue, endValue, onComplete, onUpdate);
		
		//get the array to store the transition the new transition
		var transitionsForProperty:Array<Transition> = getTransitionsForProperty(propertyIndex);
		
		transitionsForProperty.push(transition);
		
		//if the number of transition in progress was 0
		//before this one, then the update mechanism must be
		//started
		if (_currentTransitionsNumber == 0)
		{
			startTransitionUpdate();
			hasTransitionsInProgress = true;
		}
		
		//increment the number of transition in progress
		_currentTransitionsNumber++;
	}
	
	/**
	 * Stop a transition upon completion or if it was
	 * canceled and dispose of it
	 */
	public function stopTransition(transition:Transition):Void
	{
		//remove the stored reference to the transition
		var propertyTransitions:Array<Transition> = getTransitionsForProperty(transition.propertyIndex);
		propertyTransitions.remove(transition);
		//clean-up
		transition.dispose();
		
		//decrement the number of transition in progress
		//to be sure that the update stops if there
		//are no more transition in progress
		_currentTransitionsNumber--;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * return the array of transitions
	 * for a given CSS property index 
	 */
	private inline function getTransitionsForProperty(propertyIndex:Int):Array<Transition>
	{
		return _transitions[propertyIndex];
	}
	
	/**
	 * Start schduling updates
	 */
	private function startTransitionUpdate():Void
	{
		//store the current date timestamp, so that
		//on each tick, the actual elapsed
		//time can be calculated
		_lastTick = _document.timer.getTimer();
		
		//set a delayed method call which will be repeated
		//as long as needed
		_document.timer.delay(onTransitionTick);
	}
	
	/**
	 * Called at regular interval while at least one
	 * transition is in progress to call the right
	 * callback for the transition
	 */
	private function onTransitionTick(timeStamp:Float):Void
	{
		//store the actual elapsed time since the last
		//time this methd was called, in milliseconds
		var interval:Float = timeStamp - _lastTick;
		
		//the last time is updated for the next call
		//of this method
		_lastTick = timeStamp;
		
		var transitionsLength:Int = _transitions.length;
		//loop in all Transition 
		for (i in 0...transitionsLength)
		{
			//store each completed transition, which will be stopped after this loop
			//(stopped after loop to prevent from modifying the transition array while
			//looping in it)
			var completedTransitions:Array<Transition> = new Array<Transition>();
			
			var transitionsForProperty:Array<Transition> = _transitions[i];
			var length:Int = transitionsForProperty.length;
			for (j in 0...length)
			{
				var transition:Transition = transitionsForProperty[j];
				
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
			_document.timer.delay(onTransitionTick);
		}
		else
		{
			hasTransitionsInProgress = false;
		}
	}
	
	
}
