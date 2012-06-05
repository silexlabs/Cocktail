package cocktail.core.style.transition;

import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Transition 
{
	
	private var _transitionDuration:Float;
	
	private var _transitionDelay:Float;
	
	private var _transitionTimingFunction:TransitionTimingFunction;
	
	private var _startValue:Float;
	
	private var _endValue:Float;
	
	private var _startTime:Float;
	
	public var currentValue(get_currentValue, never):Float;
	
	private var _target:ComputedStyle;
	
	private var _onComplete:Transition->Void;
	public var onComplete(get_onComplete, never):Transition->Void;
	
	private var _onUpdate:Transition->Void;
	public var onUpdate(get_onUpdate, never):Transition->Void;
	
	public function new(target:ComputedStyle, transitionDuration:Float, transitionDelay:Float, transitionTimingFunction:TransitionTimingFunction,
	startValue:Float, endValue:Float, onComplete:Transition->Void, onUpdate:Transition->Void) 
	{
		_transitionDelay = transitionDelay;
		_transitionDuration = transitionDuration;
		_transitionTimingFunction = transitionTimingFunction;
		_startValue = startValue;
		_endValue = endValue;
		_target = target;
		
		_onComplete = onComplete;
		_onUpdate = onUpdate;
		
		_startTime = Date.now();
	}
	
	private function get_currentValue():Float
	{
		return 0;
	}
	
	private function get_target():ComputedStyle
	{
		return _target;
	}
	
	private function get_onComplete():Transition->Void
	{
		return _onComplete;
	}
	
	private function get_onUpdate():Transition->Void
	{
		return _onUpdate;
	}
	
}