package org.intermedia.view;

<<<<<<< HEAD
import js.Lib;
import org.intermedia.view.Constants;
import feffects.Tween;
import feffects.easing.Quart;
import feffects.easing.Quint;

/**
 * This class handles the default behaviour when scrolling on a device with touch events or mouse events
=======
import haxe.Firebug;
import haxe.Timer;
import js.Lib;
import org.intermedia.view.Constants;
import feffects.Tween;
import feffects.easing.Linear;
import feffects.easing.Quint;
import feffects.easing.Quart;
import feffects.easing.Quad;
import feffects.easing.Cubic;

/**
 * This class handles the default behaviour when scrolling on a device with touch events
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
 * 
 * @author Raphael Harmel
 */

class Scroll2D
{

	static inline var DIRECTION_PIXEL_MINIMUM:Int = 5;
<<<<<<< HEAD
	static inline var VERTICAL_TWEEN_DELTA:Int = 100;
=======
	static inline var TIME_DELTA:Int = 20;
	static inline var VERTICAL_RELEASE_DECELERATION:Float = 0.01;
	static inline var VERTICAL_VELOCITY_MESURES:Int = 5;
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	
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
	
	// horizontal move callback, sending new scroll position & offset
	public var onHorizontalScroll:Int->Void;
	
	// vertical move callback
	public var onVerticalScroll:Int->Void;
	
	// horizontal Up Callback
	public var onHorizontalUp:Dynamic->Int->Void;
	
	// horizontal tween
	public var onHorizontalTween:Int->Void;
	
	// horizontal tween end
	public var onHorizontalTweenEnd:Int->Void;
	
	// horizontal tween
	private var _horizontalTween:Tween;
	
	// vertical tween end
	private var _verticalTween:Tween;
	
<<<<<<< HEAD
=======
	// time marker
	private var _time:Float;
	
	private var _decelerationTimer:Timer;
	
	// values needed to compute velocity
	private var _verticalVelocityArray:Array<Float>;
	private var _verticalVelocity:Float;
	private var _previousY:Int;
	private var _yDelta:Int;
		
	private var _verticalReleaseDeceleration:Float;

>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	public function new(scrollType:ScrollType) 
	{
		// init attributes
		_scrollType = scrollType;
<<<<<<< HEAD
		_initialPosition = { x:0, y:0 };
		_offset = { x:0, y:0 };
		_scrollPosition = { x:0, y:0 };
		initialScrollPosition = { x:0, y:0 };
		_direction = Direction.notYetSet;
=======
		initialScrollPosition = { x:0, y:0 };
		init();
	}
	
	/**
	 * init attributes
	 */
	private function init():Void
	{
		// init attributes
		_initialPosition = { x:0, y:0 };
		_offset = { x:0, y:0 };
		_scrollPosition = { x:0, y:0 };
		_direction = Direction.notYetSet;
		_verticalVelocityArray = new Array<Float>();
		_yDelta = 0;
		_time = Timer.stamp() * 1000;

		// init attributes used for acceleration computation
		_verticalVelocity = 0;
		_previousY = 0;
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
			//case "touchstart": type = "mousedown";
			//case "touchmove":  type="mousemove";        
			//case "touchend":   type="mouseup";
			//default: return;
			case "touchstart":
				// initialise _moveHandler class initialScrollPosition
				//initialScrollPosition = { x:node.scrollLeft, y:_currentListView.node.scrollTop };
=======
			case "touchstart":
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
	 * A way to override onMouseDownCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * sets _xOffsetStart & _xInitial, and sets onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	public function onDownCallback(event:Dynamic):Void
	{
		// stop all tweens
		//stopTweens();

=======
	 * Down callback
	 * sets _xOffsetStart & _xInitial, and sets onMouseMove & onMouseUp callbacks
	 * 
	 * @param	event
	 */
	public function onDownCallback(event:Dynamic):Void
	{
		init();
		
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		// Stop all initialised & running tweens
		// only vertical tweenning is stopped otherwise horizontal scroll can stop between two lists
		if ( (_horizontalTween != null) && _horizontalTween.isPlaying)
		{
			_horizontalTween.pause();
		}
		if ( (_verticalTween != null) && _verticalTween.isPlaying)
		{
			_verticalTween.stop();
		}
		
<<<<<<< HEAD
		// set onMouseMove & onMouseUp callbacks
		//onMouseMove = onMoveCallback;
		//onMouseUp = onUpCallback;
		//onMouseMove = function (mouseEvent:MouseEventData) { onMoveCallback(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };
		//onMouseUp = function (mouseEvent:MouseEventData) { onUpCallback(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };*/
		
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
		
	}

	/**
	 * A way to override onMouseMoveCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * computes offset & moves the swippable view according to the offset
	 * 
	 * @param	mouseEventData
	 * @return	the coordinate where to scroll to
=======
	}

	/**
	 * Move callback
	 * computes offset & moves the swippable view according to the offset
	 * 
	 * @param	event
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	 */
	public function onMoveCallback(event:Dynamic):Void
	{
		// compute x & y offset
		_offset.x = Std.int(event.touches[0].pageX - _initialPosition.x);
		_offset.y = Std.int(event.touches[0].pageY - _initialPosition.y);
		
<<<<<<< HEAD
		//_currentListView.onListItemSelected = null;
		
		//trace(_direction + " - " + _offset.x + "," + _offset.y );
		// done to avoid top rebound effect - to be done also on bottom rebound one
		//if (_currentListView.scrollTop <= 0 && _offset.y > 0)
		//{
			//event.preventDefault();
		//}
		
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
			// if horizontal tween has been initialised, resume it. Done to avoid horizontal scroll stopping between 2 lists
			if ( (_horizontalTween != null) )
			{
				_horizontalTween.resume();
			}
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
		// call horizontal scroll callback with correct x position
		_scrollPosition = {x: initialScrollPosition.x - _offset.x, y: initialScrollPosition.y }
		//onHorizontalScrollCallback(_scrollPosition.x);
=======
		
		// call horizontal scroll callback with correct x position
		_scrollPosition = {x: initialScrollPosition.x - _offset.x, y: initialScrollPosition.y }
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		onHorizontalScrollCallback(_offset.x);
	}

	/**
	 * Vertical move handler
	 * 
	 * @param	event
	 */
	private function onVerticalMoveCallback(event:Dynamic):Void
	{
<<<<<<< HEAD
		// block left scroll position
		//node.scrollLeft = initialScrollPosition.x;
		
		// prevent default scroll behaviour
		event.preventDefault();
		
		// call vertical scroll callback with correct y position
		_scrollPosition = { x: initialScrollPosition.x, y: initialScrollPosition.y - _offset.y }
		//onVerticalScrollCallback(_scrollPosition.y);
=======
		var timeDelta:Float = (Timer.stamp() * 1000) - _time;
		_time = Timer.stamp() * 1000;
		
		computeVelocity(timeDelta);
		
		// compute new scroll position
		_scrollPosition = { x: initialScrollPosition.x, y: initialScrollPosition.y - _offset.y }
		
		// prevent default scroll behaviour but keep the top rebound effect on iOS as is
		// if not done, conflicts with native scroll
		if (_scrollPosition.y > 0)
		{
			event.preventDefault();
		}
		
		// call vertical scroll callback with correct y position
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		onVerticalScrollCallback(_offset.y);
	}

		
	/**
<<<<<<< HEAD
	 * A way to override onMouseUpCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * unset onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 * @return	the coordinate where to scroll to
	 */
	public function onUpCallback(event:Dynamic):Void
	{
		//event.preventDefault();
		if (_direction == Direction.horizontal)
		{
			//event.preventDefault();
=======
	 * Up callback
	 * unset onMouseMove & onMouseUp callbacks
	 * 
	 * @param	event
	 */
	public function onUpCallback(event:Dynamic):Void
	{
		if (_direction == Direction.horizontal)
		{
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
			onHorizontalUpCallback(event);
		}
		else if (_direction == Direction.vertical)
		{
<<<<<<< HEAD
			//event.preventDefault();
			verticalReleaseTween();
		}
			
		// unset onMouseMove & onMouseUp callbacks
		//onMouseMove = null;
		//onMouseUp = null;
		
=======
			verticalReleaseTween();
		}
			
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
			//event.preventDefault();
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
			onHorizontalUp(event,_offset.x);
		}
	}

		
	/**
	 * swipe animation when touch is released
	 * 
	 * @param	xOrigin
	 * @param	xTarget
	 */
	public function horizontalReleaseTween(xOrigin:Int,xTarget:Int):Void
	{
		// create the tween
<<<<<<< HEAD
        _horizontalTween = new Tween( -xOrigin, -xTarget, Constants.SWIP_HORIZONTAL_TWEEN_DELAY, Quint.easeOut );
		//_horizontalTween.setTweenHandlers( onHorizontalTweenCallback, horizontalTweenEnd );
		_horizontalTween.setTweenHandlers( onHorizontalScrollCallback, horizontalTweenEnd );
=======
        _horizontalTween = new Tween( xOrigin, xTarget, Constants.SWIP_HORIZONTAL_TWEEN_DELAY, Quad.easeOut );
		_horizontalTween.setTweenHandlers( onHorizontalScrollCallback, horizontalTweenEnd );
		
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
        // launch the tween
        _horizontalTween.start();
	}
	
	/**
	 * move view on the x axis
	 * 
	 * @param	e
	 */
    private function onHorizontalScrollCallback( xOffset : Float )
    {
		if (onHorizontalScroll != null)
		{
<<<<<<< HEAD
			//onHorizontalScroll(Std.int(e),_offset.x);
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
			onHorizontalScroll(Std.int(xOffset));
		}
    }

	/**
	 * move view on the x axis
	 * 
	 * @param	e
	 */
    private function onHorizontalTweenCallback( e : Float )
    {
		if (onHorizontalTween != null)
		{
			onHorizontalTween(Std.int(e));
		}
    }

	/**
	 * Horizontal tween callback
	 * 
	 * @param	e
	 */
    private function horizontalTweenEnd(e : Float )
	{
		if (onHorizontalTweenEnd != null)
		{
			onHorizontalTweenEnd(Std.int(e));
		}
	}
	
	/**
	 * swipe animation when touch is released
	 */
	private function verticalReleaseTween():Void
	{
<<<<<<< HEAD
		var verticalTweenEnd:Int = 0;
		// if scrolling direction is down
		if (_offset.y > 0 )
			//verticalTweenEnd = _scrollPosition.y - VERTICAL_TWEEN_DELTA;
			verticalTweenEnd = _offset.y + VERTICAL_TWEEN_DELTA;
		else
			//verticalTweenEnd = _scrollPosition.y + VERTICAL_TWEEN_DELTA;
			verticalTweenEnd = _offset.y - VERTICAL_TWEEN_DELTA;
		// create the tween
        _verticalTween = new Tween( _offset.y, verticalTweenEnd, 600, Quint.easeOut );
		_verticalTween.setTweenHandlers( onVerticalScrollCallback, onVerticalTweenEnd );
        // launch the tween
        _verticalTween.start();
=======
		_time = Timer.stamp() * 1000;
		
		// if scrolling direction is down
		if (_offset.y > 0 )
		{
			_verticalReleaseDeceleration = -VERTICAL_RELEASE_DECELERATION;
		}
		else
		{
			_verticalReleaseDeceleration = VERTICAL_RELEASE_DECELERATION;
		}
		
		// compute average velocity
		computeAverageVelocity();
		
		// scroll release automation
		_decelerationTimer = new Timer(10);
		_decelerationTimer.run = onVerticalReleaseCallback;
		
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	}
	
	/**
	 * move view on the vertical axis
	 * 
	 * @param	e
	 */
    private function onVerticalScrollCallback( e : Float )
    {
		if (onVerticalScroll != null)
		{
			onVerticalScroll(Std.int(e));
		}
    }
	
	/**
<<<<<<< HEAD
=======
	 * move view on the vertical axis
	 * taken from http://ariya.ofilabs.com/2011/10/flick-list-with-its-momentum-scrolling-and-deceleration.html
	 * 
	 * @param	e
	 */
    private function onVerticalReleaseCallback()
    {
		if (onVerticalScroll != null)
		{
			// compute elapsed time since release
			var timeDelta:Float = (Timer.stamp() * 1000) - _time;
			var releaseTime:Float = Math.abs(_verticalVelocity / VERTICAL_RELEASE_DECELERATION);
			var amplitude:Float = _verticalVelocity * releaseTime;

			// compute vertical release delta, based on _offset.y, velocity and deceleration
			var verticalReleaseDelta:Int = _offset.y + Std.int(amplitude * ( 1 - Math.exp( -timeDelta / releaseTime)));
			
			// call callback
			onVerticalScroll(verticalReleaseDelta);

			if (timeDelta > 6 * releaseTime)
			{
				// stop deceleration timer
				_decelerationTimer.stop();
			}
		}
    }
	
	/**
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	 * Vertical tween callback
	 * 
	 * @param	e
	 */
	private function onVerticalTweenEnd(e : Float ):Void
	{
		
	}
	
	/**
<<<<<<< HEAD
	 * Stop all initialised & running tweens
	 */
	/*private function stopTweens():Void
	{
		// only vertical tweenning is stopped otherwise horizontal scroll can stop between two lists
		if ( (_horizontalTween != null) && _horizontalTween.isPlaying)
		{
			_horizontalTween.pause();
		}
		if ( (_verticalTween != null) && _verticalTween.isPlaying)
		{
			_verticalTween.stop();
		}
	}*/

	
=======
	 * Computes instantaneous velocity
	 * 
	 * @return
	 */
	private function computeVelocity(time:Float):Void
	{
		// compute vertical velocity & stores previous offset
		_verticalVelocity = (_offset.y - _previousY)/time;
		_previousY = _offset.y;
		
		// store the newly computed velocity in the velocity array
		if(_verticalVelocityArray.length < VERTICAL_VELOCITY_MESURES)
		{
			// if the array is not already filed, fill it with initial velocity
			for (i in 0...VERTICAL_VELOCITY_MESURES)
			{
				_verticalVelocityArray.push(_verticalVelocity);
			}
		}
		else
		{
			// add latest velocity and remove oldest from _verticalVelocityArray
			_verticalVelocityArray.unshift(_verticalVelocity);
			_verticalVelocityArray.pop();
		}
	}
	
	/**
	 * compute AverageVelocity
	 */
	private function computeAverageVelocity():Void
	{
		_verticalVelocity = 0;
		var sum:Float = 0;
		
		// compute average velocity using degressive weights
		for (i in 0..._verticalVelocityArray.length)
		{
			sum += _verticalVelocityArray[i] * (VERTICAL_VELOCITY_MESURES - i);
		}
		_verticalVelocity = sum / (VERTICAL_VELOCITY_MESURES * (VERTICAL_VELOCITY_MESURES + 1) / 2);
	}
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
