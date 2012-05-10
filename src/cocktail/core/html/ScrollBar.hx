package cocktail.core.html;
import cocktail.core.event.MouseEvent;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ScrollBar extends HTMLElement
{

	private var _isVertical:Bool;
	
	public function new(isVertical:Bool) 
	{
		
		_isVertical = isVertical;
		super("");
		
		
		_style.position = "absolute";
		
		if (_isVertical)
		{
			_style.backgroundColor = "red";
			_style.height = "100%";
			_style.width = "30px";
			_style.right = "0";
			_style.top = "0";
		}
		else
		{
			_style.backgroundColor = "blue";
			_style.width = "100%";
			_style.height = "30px";
			_style.bottom = "0";
		}
		
		_style.display = "block";
		
		onmousedown = onTrackMouseDown;
	}
	
	private function onTrackMouseDown(event:MouseEvent):Void
	{
		trace(event);
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
	
}