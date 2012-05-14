package cocktail.core.html;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ScrollBar extends HTMLElement
{

	private var _isVertical:Bool;
	
	private var _maxScroll:Float;
	public var maxScroll(get_maxScroll, set_maxScroll):Float;
	
	private var _scroll:Float;
	public var scroll(get_scroll, set_scroll):Float;
	
	public function new(isVertical:Bool) 
	{
		
		_isVertical = isVertical;
		super("");
		
		
		_style.position = "absolute";
		
		if (_isVertical)
		{
			_style.backgroundColor = "red";
			_style.height = "100%";
			_style.width = "15px";
			_style.right = "0";
			_style.top = "0";
		}
		else
		{
			_style.backgroundColor = "blue";
			_style.width = "100%";
			_style.height = "15px";
			_style.bottom = "0";
		}
		
		_style.display = "block";
		
		onmousedown = onTrackMouseDown;
	}
	
	private function onTrackMouseDown(event:MouseEvent):Void
	{
		if (_isVertical == true)
		{
			_scroll = event.clientY;
		}
		else
		{
			_scroll = event.clientX;
		}
		
		if (_onScroll != null)
		{
			_onScroll(new UIEvent("poj,",this, 0));
		}
	}
	
	
	override private function isParentRendered():Bool
	{
		return true;
	}

	override private function attachToParentElementRenderer():Void
	{
	
	}

	override private function detachFromParentElementRenderer():Void
	{
		
	}
	
	private function get_maxScroll():Float 
	{
		return _maxScroll;
	}
	
	private function set_maxScroll(value:Float):Float 
	{
		return _maxScroll = value;
	}

	private function get_scroll():Float
	{
		return (_scroll / _maxScroll) * 100;
	}
	
	private function set_scroll(value:Float):Float 
	{
		return _scroll = value;
	}
}