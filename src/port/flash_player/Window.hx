package port.flash_player;

import core.window.AbstractWindow;
import core.event.Event;
import flash.Lib;

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
			Lib.current.stage.removeEventListener(flash.events.Event.RESIZE, onNativeResize);
		}
		else
		{
			Lib.current.stage.addEventListener(flash.events.Event.RESIZE, onNativeResize);
		}
		
		return _onResize = value;
	}
	
	override private function get_innerHeight():Int
	{
		return Lib.current.stage.stageHeight;
	}
	
	override private function get_innerWidth():Int
	{
		return Lib.current.stage.stageWidth;
	}
	
	private function onNativeResize(event:Dynamic):Void
	{
		if (_onResize != null)
		{
			_onResize(new Event(Event.RESIZE, this));
		}
	}
	
}