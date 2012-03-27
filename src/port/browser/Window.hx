package port.browser;

import core.event.Event;
import core.window.AbstractWindow;
import js.Lib;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Window extends AbstractWindow
{

	public function new() 
	{
		super();
	}
	
	override private function set_onResize(value:Event->Void):Event->Void
	{
		if (value == null)
		{
			Lib.window.onresize = null;
		}
		else
		{
			Lib.window.onresize = onNativeResize;
		}
		
		return _onResize = value;
	}
	
	override private function get_innerHeight():Int
	{
		return Lib.window.innerHeight;
	}
	
	override private function get_innerWidth():Int
	{
		return Lib.window.innerWidth;
	}
	
	private function onNativeResize(event:Dynamic):Void
	{
		if (_onResize != null)
		{
			_onResize(new Event(Event.RESIZE, this));
		}
	}
	
}