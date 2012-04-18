package org.intermedia.view;

import js.Lib;
import org.intermedia.view.Constants;
import feffects.Tween;
import feffects.easing.Quart;
import feffects.easing.Quint;

/**
 * This class handles the default behaviour when scrolling on a device with touch events or mouse events
 * 
 * @author Raphael Harmel
 */

class Move2D
{

	static inline var DIRECTION_PIXEL_MINIMUM:Int = 5;
	static inline var VERTICAL_TWEEN_DELTA:Int = 100;
	
	// touch offset
	private var _offset:Coordinate;
	
	// touch initial position
	private var _initialPosition:Coordinate;
	
	// initial scroll position
	public var initialScrollPosition:Coordinate;
	
	// current scroll position
	private var _scrollPosition:Coordinate;
	
	// scroll type
	private var _scrollType:ScrollType;
	
	// main movement direction
	private var _direction:Direction;
	
	// horizontal move callback
	public var onHorizontalScroll:Int->Void;
	
	// vertical move callback
	public var onVerticalScroll:Int->Void;
	
	// horizontal Up Callback
	public var onHorizontalUp:Dynamic->Int->Void;
	
	// horizontal tween end
	public var onHorizontalTweenEnd:Void->Void;
	
	// horizontal tween
	private var _horizontalTween:Tween;
	
	// vertical tween end
	private var _verticalTween:Tween;
	
	public function new(scrollType:ScrollType) 
	{
		// init attributes
		_scrollType = scrollType;
		_initialPosition = { x:0, y:0 };
		_offset = { x:0, y:0 };
		_scrollPosition = { x:0, y:0 };
		initialScrollPosition = { x:0, y:0 };
		_direction = Direction.notYetSet;
	}
	
	
	/**
	 * Touch event handler
	 * 
	 * @param	event
	 */
	public function touchHandler(event:Dynamic):Void
	{
		switch(event.type)
		{
			//case "touchstart": type = "mousedown";
			//case "touchmove":  type="mousemove";        
			//case "touchend":   type="mouseup";
			//default: return;
			case "touchstart":
				// initialise _moveHandler class initialScrollPosition
				//initialScrollPosition = { x:node.scrollLeft, y:_currentListView.node.scrollTop };
				// call onDownCallback
				onDownCallback(event);
			case "touchmove":
				// call onMoveCallback
				onMoveCallback(event);
			case "touchend":
				// call onUpCallback
				onUpCallback(event);
			default: return;
		}
	}

	/**
	 * A way to override onMouseDownCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * sets _xOffsetStart & _xInitial, and sets onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	public function onDownCallback(event:Dynamic):Void
	{
		// stop all tweens
		stopTweens();
		
		// done as a workaround for this bug: https://github.com/silexlabs/Cocktail/issues/139
		/*_viewport.onResize = null;
		
		// set onMouseMove & onMouseUp callbacks
		//onMouseMove = onMoveCallback;
		//onMouseUp = onUpCallback;
		//onMouseMove = function (mouseEvent:MouseEventData) { onMoveCallback(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };
		//onMouseUp = function (mouseEvent:MouseEventData) { onUpCallback(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };*/
		
		// initialise initial touch positions
		_initialPosition.x = event.touches[0].pageX;
		_initialPosition.y = event.touches[0].pageY;
		
		// set _direction
		if (_scrollType == ScrollType.horizontal)
			_direction = Direction.horizontal;
		else if (_scrollType == ScrollType.vertical)
			_direction = Direction.vertical;
		else
			_direction = Direction.notYetSet;
		
	}

	/**
	 * A way to override onMouseMoveCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * computes offset & moves the swippable view according to the offset
	 * 
	 * @param	mouseEventData
	 * @return	the coordinate where to scroll to
	 */
	public function onMoveCallback(event:Dynamic):Void
	{
		// compute x & y offset
		_offset.x = Std.int(event.touches[0].pageX - _initialPosition.x);
		_offset.y = Std.int(event.touches[0].pageY - _initialPosition.y);
		
		//_currentListView.onListItemSelected = null;
		
		//trace(_direction + " - " + _offset.x + "," + _offset.y );
		// done to avoid top rebound effect - to be done also on bottom rebound one
		//if (_currentListView.scrollTop <= 0 && _offset.y > 0)
		//{
			//event.preventDefault();
		//}
		
		//trace(_direction + " - " + _offset.x);
		
		// if direction is not set
		if (_direction == Direction.notYetSet)
		{
			// compute absolute values as movement _offset can be positive or negative
			var absX:Float = Math.abs(_offset.x);
			var absY:Float = Math.abs(_offset.y);
				
			// as first move event can be dispatched with both x and y values bigger than DIRECTION_PIXEL_MINIMUM,
			// take the biggest as a reference
			if ( Math.max(absX, absY) >= DIRECTION_PIXEL_MINIMUM )
			{
				if (absX > absY)
				{
					_direction = Direction.horizontal;
				}
				else
				{
					_direction = Direction.vertical;
				}
			}
		}
		
		// if direction is horizontal
		if (_direction == Direction.horizontal)
		{
			onHorizontalMoveCallback(event);
		}
		// if direction is vertical
		else if (_direction == Direction.vertical)
		{
			onVerticalMoveCallback(event);
		}
		
	}
	
	/**
	 * Horizontal move handler
	 * 
	 * @param	event
	 */
	private function onHorizontalMoveCallback(event:Dynamic):Void
	{
		// prevent default scroll behaviour
		event.preventDefault();
		// call horizontal scroll callback with correct x position
		_scrollPosition = {x: initialScrollPosition.x - _offset.x, y: initialScrollPosition.x }
		onHorizontalScrollCallback(_scrollPosition.x);
	}

	/**
	 * Vertical move handler
	 * 
	 * @param	event
	 */
	private function onVerticalMoveCallback(event:Dynamic):Void
	{
		// block left scroll position
		//node.scrollLeft = initialScrollPosition.x;
		// prevent default scroll behaviour
		event.preventDefault();
		
		// call vertical scroll callback with correct y position
		_scrollPosition = { x: initialScrollPosition.x, y: initialScrollPosition.y - _offset.y }
		onVerticalScrollCallback(_scrollPosition.y);
	}

		
	/**
	 * A way to override onMouseUpCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * unset onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 * @return	the coordinate where to scroll to
	 */
	public function onUpCallback(event:Dynamic):Void
	{
		if (_direction == Direction.horizontal)
		{
			onHorizontalUpCallback(event);
		}
		else if (_direction == Direction.vertical)
		{
			verticalReleaseTween();
		}
			
		// unset onMouseMove & onMouseUp callbacks
		//onMouseMove = null;
		//onMouseUp = null;
		
		// done as a workaround for this bug: https://github.com/silexlabs/Cocktail/issues/139
		//_viewport.onResize = onResizeCallback;
		
		// reset direction
		_direction = Direction.notYetSet;

	}
	
	/**
	 * horizontal up handler
	 * 
	 * @param	event
	 */
	private function onHorizontalUpCallback(event:Dynamic):Void
	{
		if (onHorizontalUp != null)
		{
			//event.preventDefault();
			onHorizontalUp(event,_offset.x);
		}
	}

		
	/**
	 * swipe animation when touch is released
	 */
	public function horizontalReleaseTween(xOrigin:Int,xTarget:Int):Void
	{
		// create the tween
		//haxe.Firebug.trace("index: " + _index + " - scrollLeft: " + node.scrollLeft + " - " + "_currentListView.x:" + _currentListView.x);
        _horizontalTween = new Tween( xOrigin, xTarget, 600, Quint.easeOut );
		_horizontalTween.setTweenHandlers( onHorizontalScrollCallback, horizontalTweenEnd );
        // launch the tween
        _horizontalTween.start();
	}
	
	/**
	 * move view on the x axis
	 * 
	 * @param	e
	 */
    private function onHorizontalScrollCallback( e : Float )
    {
		//node.scrollLeft = Std.int(e);
		//node.scrollLeft = Std.int(e);
		if (onHorizontalScroll != null)
		{
			onHorizontalScroll(Std.int(e));
		}
    }

	/**
	 * Vertical tween callback
	 * 
	 * @param	e
	 */
    private function horizontalTweenEnd(e : Float )
	{
		if (onHorizontalTweenEnd != null)
		{
			onHorizontalTweenEnd();
		}
	}
	
	/**
	 * swipe animation when touch is released
	 */
	private function verticalReleaseTween():Void
	{
		//trace("releaseTween");
		//trace("releaseTween: " + "x:" + x + ", y:" + y + ", initialScrollPosition.x:" + initialScrollPosition.x + ", _offset.x:" + _offset.x + ", _viewportWidth:" + _viewportWidth + ", this.x:" + this.x + ", -_currentListView.x:" + -_currentListView.x);
		
		var verticalTweenEnd:Int = 0;
		// if scrolling direction is down
		if (_offset.y > 0 )
			//verticalTweenEnd = _currentListView.node.scrollTop - VERTICAL_TWEEN_DELTA;
			verticalTweenEnd = _scrollPosition.y - VERTICAL_TWEEN_DELTA;
		else
			//verticalTweenEnd = _currentListView.node.scrollTop + VERTICAL_TWEEN_DELTA;
			verticalTweenEnd = _scrollPosition.y + VERTICAL_TWEEN_DELTA;
		// create the tween
        //var tween = new Tween( _currentListView.node.scrollTop, verticalTweenEnd, 600, Quint.easeOut );
        _verticalTween = new Tween( _scrollPosition.y, verticalTweenEnd, 600, Quint.easeOut );
		_verticalTween.setTweenHandlers( onVerticalScrollCallback, onVerticalTweenEnd );
        // launch the tween
        _verticalTween.start();
	}
	
	/**
	 * move view on the vertical axis
	 * 
	 * @param	e
	 */
    private function onVerticalScrollCallback( e : Float )
    {
		//_currentListView.node.scrollTop = Std.int(e);
		if (onVerticalScroll != null)
		{
			onVerticalScroll(Std.int(e));
		}
    }
	
	/**
	 * Vertical tween callback
	 * 
	 * @param	e
	 */
	private function onVerticalTweenEnd(e : Float ):Void
	{
		
	}
	
	/**
	 * Stop all initialised & running tweens
	 */
	private function stopTweens():Void
	{
		// only vertical tweenning is stopped otherwise horizontal scroll can stop between two lists
		/*if ( (_horizontalTween != null) && _horizontalTween.isPlaying)
			_horizontalTween.stop();*/
		if ( (_verticalTween != null) && _verticalTween.isPlaying)
			_verticalTween.stop();
	}
	
}

typedef Coordinate = {
	var x:Int;
	var y:Int;
}

enum Direction {
	horizontal;
	vertical;
	notYetSet;
}

enum ScrollType {
	horizontal;
	vertical;
	both;
}
