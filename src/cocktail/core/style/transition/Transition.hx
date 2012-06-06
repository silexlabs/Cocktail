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
	
	private var _transitionTimingFunction:TransitionTimingFunctionValue;
	
	private var _startValue:Float;
	
	private var _endValue:Float;
	
	private var _currentTime:Float;
	
	public var currentValue(get_currentValue, never):Float;
	
	private var _target:ComputedStyle;
	public var target(get_target, never):ComputedStyle;
	
	private var _onComplete:Transition->Void;
	public var onComplete(get_onComplete, never):Transition->Void;
	
	private var _onUpdate:Transition->Void;
	public var onUpdate(get_onUpdate, never):Transition->Void;
	
	public var complete(get_complete, never):Bool;
	
	public function new(target:ComputedStyle, transitionDuration:Float, transitionDelay:Float, transitionTimingFunction:TransitionTimingFunctionValue,
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
		
		_currentTime = 0;
	}
	
	public function updateTime(delta:Float)
	{
		_currentTime += delta;
	}
	
	private function get_currentValue():Float
	{
		var completePercent:Float = (_currentTime) / ((_transitionDelay + _transitionDuration) * 1000);
		
		return _endValue * completePercent;
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
	
	private function get_complete():Bool
	{
		
		if (_currentTime >= (_transitionDelay + _transitionDuration) * 1000)
		{
			return true;
		}
		
		return false;
	}
	
}