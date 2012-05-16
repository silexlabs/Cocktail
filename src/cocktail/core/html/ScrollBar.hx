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
	
	private var _upArrow:HTMLElement;
	
	private var _downArrow:HTMLElement;
	
	public function new(isVertical:Bool) 
	{
		
		_isVertical = isVertical;
		
		super("");
		
		_scrollThumb = new HTMLElement("");
		_upArrow = new HTMLElement("");
		_downArrow = new HTMLElement("");
	
	
		
		initScrollBar();
		
		if (_isVertical)
		{
			initVerticalScrollBar();
		}
		else
		{
			initHorizontalScrollBar();
		}
		
		//_scrollThumb.onmousedown = onThumbMouseDown;
		
		appendChild(_scrollThumb);
		appendChild(_upArrow);
		appendChild(_downArrow);
		
		onmousedown = onTrackMouseDown;
		
		_downArrow.onmousedown = onDownArrowMouseDown;
		_upArrow.onmousedown = onUpArrowMouseDown;
		
	}
	
	private function initScrollBar():Void
	{
		_style.backgroundColor = "red";
		_style.display = "block";
		_style.position = "absolute";
		
		_scrollThumb.style.backgroundColor = "green";
		_scrollThumb.style.position = "absolute";
		_scrollThumb.style.display = "block";
		_scrollThumb.style.width = "15px";
		_scrollThumb.style.height = "15px";
		
		_upArrow.style.backgroundColor = "orange";
		_upArrow.style.position = "absolute";
		_upArrow.style.display = "block";
		_upArrow.style.width = "15px";
		_upArrow.style.height = "15px";
		
		_downArrow.style.backgroundColor = "orange";
		_downArrow.style.position = "absolute";
		_downArrow.style.display = "block";
		_downArrow.style.width = "15px";
		_downArrow.style.height = "15px";
		
	}
	
	private function initVerticalScrollBar():Void
	{
		_style.height = "100%";
		_style.width = "15px";
		_style.right = "0";
		_style.top = "0";
		
		_downArrow.style.bottom = "0";
	}
	
	private function initHorizontalScrollBar():Void
	{
		_style.width = "100%";
		_style.height = "15px";
		_style.bottom = "0";
		_style.left = "0";
		
		_downArrow.style.right = "0";
	}
	
	private function onDownArrowMouseDown(event:MouseEvent):Void
	{
		scroll += 50;
	}
	
	private function onUpArrowMouseDown(event:MouseEvent):Void
	{
		scroll -= 50;
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
			scroll = event.clientY;
		}
		else
		{
			scroll = event.clientX;
		}
	}
	 
	private function onTrackMouseDown(event:MouseEvent):Void
	{
		if (_isVertical == true)
		{
			scroll = event.clientY;
		}
		else
		{
			scroll = event.clientX;
		}
	}
	
	private function updateScroll():Void
	{
		if (_scroll > _maxScroll)
		{
			_scroll = maxScroll;
		}
		else if (_scroll < 0)
		{
			_scroll = 0;
		}
		
		var progress:Float = scroll / maxScroll;
		
		if (_isVertical == true)
		{
			var thumbY:Int = Math.round(progress * (_coreStyle.computedStyle.height -
			_upArrow.coreStyle.computedStyle.height - _downArrow.coreStyle.computedStyle.height - _scrollThumb.coreStyle.computedStyle.height)
			+  _upArrow.coreStyle.computedStyle.height);
			_scrollThumb.style.top = thumbY + "px";
		}
		else
		{
			_scrollThumb.style.left = scroll + "px";
		}
		
		dispatchScrollEvent();
	}
	
	private function dispatchScrollEvent():Void
	{
		if (_onScroll != null)
		{
			var scrollEvent:UIEvent = new UIEvent();
			scrollEvent.initUIEvent(UIEvent.SCROLL, false, false, 0.0);
			_onScroll(scrollEvent);
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
		_maxScroll = value;
		//updateScroll();
		return value;
	}

	private function get_scroll():Float
	{
		return _scroll ;
	}
	
	private function set_scroll(value:Float):Float 
	{
		_scroll = value;
		updateScroll();
		return value;
	}
}