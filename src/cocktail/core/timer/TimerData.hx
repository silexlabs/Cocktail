package cocktail.core.timer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TimerCallbackVO 
{

	public var timerCallback(default, null):Void->Void;
	
	public var callbackTime:Float;
	
	public function new(timerCallback:Void->Void, callbackTime:Float) 
	{
		this.timerCallback = timerCallback;
		this.callbackTime = callbackTime;
	}
	
}