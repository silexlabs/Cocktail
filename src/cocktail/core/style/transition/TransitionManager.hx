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
import haxe.Timer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TransitionManager 
{
	
	private var _transitions:Hash<Array<Transition>>;
	
	private static var _instance:TransitionManager;
	
	private var _currentTransitionsNumber:Int;
	
	private var _transitionTimer:Timer;
	
	private static inline var TRANSITION_UPDATE_SPEED:Int = 50;
	
	private var _lastTick:Float;
	
	
	/**
	 * class constructor
	 */
	private function new() 
	{
		_transitions = new Hash();
		_currentTransitionsNumber = 0;
		_lastTick = 0;
	}
	
	public static function getInstance():TransitionManager
	{
		if (_instance == null)
		{
			_instance = new TransitionManager();
		}
		
		return _instance;
	}
	
	public function isTransitioning(propertyName:String, style:ComputedStyle):Bool
	{
		if (_transitions.exists(propertyName))
		{
			var propertyTransitions:Array<Transition> = _transitions.get(propertyName);
			for (i in 0...propertyTransitions.length)
			{
				if (propertyTransitions[i].target == style)
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	public function getTransition(propertyName:String, style:ComputedStyle):Transition
	{
		if (_transitions.exists(propertyName))
		{
			var propertyTransitions:Array<Transition> = _transitions.get(propertyName);
			for (i in 0...propertyTransitions.length)
			{
				if (propertyTransitions[i].target == style)
				{
					return propertyTransitions[i];
				}
			}
		}
		
		return null;
	}
	
	public function startTransition(target:ComputedStyle, propertyName:String, startValue:Float, endValue:Float, transitionDuration:Float, 
	transitionDelay:Float, transitionTimingFunction:TransitionTimingFunctionValue, onComplete:Transition->Void, onUpdate:Transition->Void):Transition
	{
		if (_currentTransitionsNumber == 0)
		{
			startTransitionTimer();
		}
		_currentTransitionsNumber++;
		
		var transition:Transition = new Transition(target, transitionDuration, transitionDelay, transitionTimingFunction,
		startValue, endValue, onComplete, onUpdate);
		
		if (_transitions.exists(propertyName) == false)
		{
			_transitions.set(propertyName, []);
		}
		
		var propertyTransitions:Array<Transition> = _transitions.get(propertyName);
		propertyTransitions.push(transition);
		 
		return transition;
	}
	
	public function stopTransition(propertyName:String, computedStyle:ComputedStyle):Void
	{
		var propertyTransitions:Array<Transition> = _transitions.get(propertyName);
		for (i in 0...propertyTransitions.length)
		{
			if (propertyTransitions[i].target == computedStyle)
			{
				propertyTransitions.remove(propertyTransitions[i]);
				_currentTransitionsNumber--;
				break;
			}
		}
	}
	
	
	private function startTransitionTimer():Void
	{
		#if (flash9 || nme)
		_lastTick = Date.now().getTime();
		Timer.delay(onTransitionTick, TRANSITION_UPDATE_SPEED);
		#end
	}
	
	private function onTransitionTick():Void
	{
		var tick:Float = Date.now().getTime();
		var interval:Float = tick - _lastTick;
		
		_lastTick = tick;
		
		for (propertyTransitions in _transitions)
		{
			for (i in 0...propertyTransitions.length)
			{
				var transition:Transition = propertyTransitions[i];
				transition.updateTime(interval);
				
				if (transition.complete == true)
				{
					transition.onComplete(transition);
					_currentTransitionsNumber--;
					
					propertyTransitions.remove(transition);
				}
				else
				{
					transition.onUpdate(transition);
				}
			}
		}
		
		if (_currentTransitionsNumber > 0)
		{
			#if (flash9 || nme)
			Timer.delay(onTransitionTick, TRANSITION_UPDATE_SPEED);
			#end
		}
	}
	
	
}