package cocktail.core.html;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;
import cocktail.Lib;

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
	
	private var _scrollThumb:HTMLElement;
	
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
		
		
		_scrollThumb = new HTMLElement("");
		appendChild(_scrollThumb);
		
		_scrollThumb.onmousedown = onThumbMouseDown;
		
		_scrollThumb.style.backgroundColor = "green";
		_scrollThumb.style.width = "15px";
		_scrollThumb.style.height = "15px";
		_scrollThumb.style.position = "absolute";
		_scrollThumb.style.display = "block";
		
		//onmousedown = onTrackMouseDown;
	}
	
	//TODO : should add event listener to body instead of callback
	//which erase all other callbacks
	private function onThumbMouseDown(event:MouseEvent):Void
	{
		cocktail.Lib.document.body.onmousemove = onThumbMove;
		cocktail.Lib.document.body.onmouseup = onThumbMouseUp;
	}
	
	private function onThumbMouseUp(event:MouseEvent):Void
	{
		cocktail.Lib.document.body.onmousemove = null;
		cocktail.Lib.document.body.onmouseup = null;
	}
	
	private function onThumbMove(event:MouseEvent):Void
	{
		if (_isVertical == true)
		{
		//	_scrollThumb.style.top = event.clientY + "px";
		}
		else
		{
		//	_scrollThumb.style.left = event.clientX + "px";
		}
		
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
	 
	private function onTrackMouseDown(event:MouseEvent):Void
	{
		if (_isVertical == true)
		{
		//	_scrollThumb.style.top = event.clientY + "px";
		}
		else
		{
		//	_scrollThumb.style.left = event.clientX + "px";
		}
		
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
		return _scroll ;
	}
	
	private function set_scroll(value:Float):Float 
	{
		return _scroll = value;
	}
}