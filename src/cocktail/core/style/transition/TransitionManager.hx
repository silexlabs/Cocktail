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
 * ...
 * @author Yannick DOMINGUEZ
 */

class TransitionManager 
{
	
	private var _transitions:Hash<Array<Transition>>;
	
	private static var _instance:TransitionManager;
	
	/**
	 * class constructor
	 */
	private function new() 
	{
		_transitions = new Hash();
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
		
	}
	
	public function getTransition(propertyName:String, style:ComputedStyle):Transition
	{
		
	}
	
	public function startTransition(target:ComputedStyle, propertyName:String, startValue:Float, endValue:Float, transitionDuration:Float, 
	transitionDelay:Float, transitionTimingFunction:TransitionTimingFunction, onComplete:Transition->Void, onUpdate:Transition->Void):Transition
	{
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
	
	public function stopTransition(transition:Transition):Void
	{
		
	}
	
}