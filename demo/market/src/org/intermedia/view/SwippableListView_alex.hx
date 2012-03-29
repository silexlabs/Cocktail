package org.intermedia.view;

import cocktail.viewport.Viewport;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.ListViewBase;
import cocktail.mouse.MouseData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktail.domElement.DOMElementData;

import feffects.Tween;
import feffects.easing.Quart;
import feffects.easing.Quint;

/**
 * A container for multiple list views which can be selected by swipping them.
 * 
 * @author Raphael Harmel
 */

class SwippableListView extends ListViewBase 
{

	static inline var DIRECTION_PIXEL_MINIMUM:Int = 5;
	
	// a ref to each of the list views which can be swiped
	private var _listViews:Array<ViewBase>;
	
	private var list0:ListViewText;
	private var list1:ThumbTextList1Bis;
	private var list2:ThumbTextList1;
	
	// The ListView currently displayed
	private var _currentListView:ListViewBase;
	
	// current list view index
	private var _index:Int;
	
	// X offset used to scroll list left and right
	private var _offset:Coordinate;
	private var _offsetStart:Coordinate;
	private var _initialPosition:Coordinate;
	
	// main movement direction
	private var _direction:Direction;
	
	// X offset used to scroll list left and right
	/*private var _xOffset:Int;
	private var _xOffsetStart:Int;
	private var _xInitial:Int;
	
	// Y offset used to scroll list left and right
	private var _yOffset:Int;
	private var _yOffsetStart:Int;
	private var _yInitialPosition:Int;*/
	
	// view port
	private var _viewport:Viewport;
	private var _viewportWidth:Int;
	
	public function new()
	{
		super();
		
		// init attributes
		_offset = { x:0, y:0 };
		_offsetStart = { x:0, y:0 };
		_initialPosition = { x:0, y:0 };
		_direction = Direction.notYetSet;
		//_xOffset = 0;
		//_xOffsetStart = 0;
		//_xInitial = 0;
		//_yOffset = 0;
		//_yOffsetStart = 0;
		//_yInitial = 0;
		_viewport = new Viewport();
		_viewportWidth = _viewport.width;
		//_viewport.onResize = onResizeCallback;
		
		// set style
		SwippableListViewStyle.setListStyle(this);
		// set onMouseDown callback
		//onMouseDown = onDownCallback2;
		//onMouseDown = function(mouseEvent:MouseEventData) { onDownCallback2(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };
		
		// set _listView array
		_listViews = new Array<ViewBase>();
		
		// create all needed lists and add them to the _listView array
		list0 = new ListViewText();
		//list0.x = -_viewportWidth;
		_listViews.push(list0);
		
		//var list1:ListViewBase = new ThumbTextList1Bis(3);Filters component
		list1 = new ThumbTextList1Bis(2);
		_listViews.push(list1);
		list1.x = _viewportWidth;
		
		list2 = new ThumbTextList1(2);
		_listViews.push(list2);
		//list2.x = _viewportWidth;
		list2.x = 2 * _viewportWidth;
		
//		this.alpha = 0;
		// add all lists to the view
		for (listView in _listViews)
		{
			this.addChild(listView);
		}
		
		// set index
		_index = 1;
		// set current list to list2
		_currentListView = cast _listViews[_index];
		// set listItemSelected callback on current list
		_currentListView.onListItemSelected = onListItemSelectedCallback;
		_currentListView.onListScrolled = onScrolledCallback;
		
		// js touch events handling
		#if js
		initTouchEvents();
		#end
	}
	
	/**
	 * data setter
	 * @param	v
	 * @return
	 */
	override private function setData(v:Dynamic):Dynamic
	{
		_data = v;
		
		// set displayEndListLoader to the lists and
		// update _currentListView data with updated data
		
		list0.displayListBottomLoader = displayListBottomLoader;
		list0.data = _data;
		
		list1.displayListBottomLoader = displayListBottomLoader;
		list1.data = _data;

		list2.displayListBottomLoader = displayListBottomLoader;
		list2.data = _data;
		
		return _data;	
	}
	
	/**
	 * on rezize callback
	 */
	private function onResizeCallback():Void
	{
		//trace("onResizeCallback");
		
		// compute new width
		_viewportWidth = _viewport.width;
		
		// update lists width
		list0.x = -_viewportWidth;
		list2.x = _viewportWidth;
		
		// update swippable view position
		this.x = -_currentListView.x;
	}
	
	/**
	 * A way to override onMouseDownCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * sets _xOffsetStart & _xInitial, and sets onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	//private function onDownCallback2(mouseEvent:MouseEventData):Void
	private function onDownCallback2(x:Float,y:Float):Void
	{
		// done as a workaround for this bug: https://github.com/silexlabs/Cocktail/issues/139
		_viewport.onResize = null;
		
		//trace("mousedown");
		// set _xOffset to current mouse position
		//_xOffsetStart = Std.int(mouseEvent.mousePosition.localX);
		//_xOffsetStart = Std.int(x);
		_offsetStart = { x:Std.int(x), y:Std.int(y) };
		
		//trace( x + ", " + y + ", " + _xOffsetStart + ", " + _xOffset + ", " + _viewportWidth);

		// set initial position to x & Y coordinate of the swippable view 
		//_xInitial = this.x;
		_initialPosition = { x:this.x, y:this.y };
		
		// set onMouseMove & onMouseUp callbacks
		//onMouseMove = onMoveCallback2;
		//onMouseUp = onUpCallback2;
		//onMouseMove = function (mouseEvent:MouseEventData) { onMoveCallback2(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };
		//onMouseUp = function (mouseEvent:MouseEventData) { onUpCallback2(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };
		
	}

	/**
	 * A way to override onMouseMoveCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * computes offset & moves the swippable view according to the offset
	 * 
	 * @param	mouseEventData
	 */
	//private function onMoveCallback2(mouseEvent:MouseEventData):Void
	//private function onMoveCallback2(x:Float,y:Float):Void
	private function onMoveCallback2(x:Float,y:Float,event:Dynamic):Void
	{

		//trace("onMoveCallback2");
		
		// unset listItemSelected callback on current list to avoid opening detail view while swipping
		_currentListView.onListItemSelected = null;
		_currentListView.onListScrolled = null;
		
		// compute offset
		//_xOffset = Std.int(mouseEvent.mousePosition.localX) - _xOffsetStart;
		//_xOffset = Std.int(x) - _xOffsetStart;
		_offset.x = Std.int(x) - _offsetStart.x;
		_offset.y = Std.int(y) - _offsetStart.y;
		
		// if direction is not set, set it to horizontal or vertical if movement is at least a few pixels
		if (_direction == Direction.notYetSet)
		{
			if (Math.abs(_offset.x) >= DIRECTION_PIXEL_MINIMUM)
				_direction = Direction.horizontal;
			if (Math.abs(_offset.y) >= DIRECTION_PIXEL_MINIMUM)
				_direction = Direction.vertical;
		}
		
		//trace( x + ", " + y + ", " + _xOffsetStart + ", " + _xOffset + ", " + _viewportWidth + ", " + this.x);

		// move the swippable view according to the direction and the offset
		if (_direction == Direction.horizontal)
		{
			//trace("horizontal");
			event.preventDefault();
			this.x = _initialPosition.x + _offset.x;
		}
		/*if (_direction == Direction.vertical)
		{
			//_currentListView.y = _initialPosition.y + _offset.y;
			// js workaround to scroll up
			#if js
			var scroll:Int = -(_initialPosition.y + _offset.y);
			//js.Lib.window.scrollTo(0, _initialPosition.y + _offset.y);
			js.Lib.window.scrollTo(0, scroll);
			#end
		}*/
		

	}
	
	/**
	 * A way to override onMouseUpCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * unset onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	//private function onUpCallback2(mouseEvent:MouseEventData):Void
	private function onUpCallback2(x:Int):Void
	{
		//trace("onUpCallback2: " + "x:" + x + ", y:" + y + ", _offsetStart.x:" + _offsetStart.x + ", _offset.x:" + _offset.x + ", _viewportWidth:" + _viewportWidth + ", this.x:" + this.x + ", -_currentListView.x:" + -_currentListView.x);

		var w = _viewportWidth / 2;
		if (x < w)
			this.parent.nativeElement.scrollLeft = 0;
		else if (x < 3 * w)
			this.parent.nativeElement.scrollLeft = _viewportWidth;
		else 
			this.parent.nativeElement.scrollLeft = 2 * _viewportWidth;
		
return;		
		if (_direction == Direction.horizontal)
		{
			// compute offset
			//_xOffset = Std.int(mouseEvent.mousePosition.localX) - _xOffsetStart;
			_offset.x = Std.int(x) - _offsetStart.x;
			_offset.y = Std.int(y) - _offsetStart.y;
			//_offset.x = Std.int(x);
			//_offset.y = Std.int(y);
			
			//trace("onUpCallback2");
			//trace( x + ", " + y + ", " + _xOffsetStart + ", " + _xOffset + ", " + _viewportWidth);
			//trace( x + ", " + y);
			
			// go to list which user has scrolled to
			
			// if the mouse movement is from left to right
			// and if _xOffset is bigger than half the width of the viewport,
			// display next list and set _currentlist to the next list
			if (_offset.x < -_viewportWidth/2)
			{
				// if the current list is not the last list
				if(_index < _listViews.length-1)
				{
					_index++;
					//_currentListView = _listViews[_index];
					_currentListView = cast _listViews[_index];
				}
			}
			// if the mouse movement is from right to left
			// and if _xOffset is lower than minus half the width of the viewport,
			// display previous list and set _currentlist to the previous list
			else if (_offset.x > _viewportWidth/2)
			{
				// if the current list is not the first list
				if(_index > 0)
				{
					_index--;
					_currentListView = cast _listViews[_index];
				}
			}
			
			// set listItemSelected callback on current list
			_currentListView.onListItemSelected = onListItemSelectedCallback;
			_currentListView.onListScrolled = onScrolledCallback;

			// tween the swippable view in the correct position
			releaseTween();
		
			// js workaround to scroll up
			/*#if js
			js.Lib.window.scrollTo(0, 0);
			//js.Lib.window.scrollTo(0,null);
			#end*/
		}
			
		// unset onMouseMove & onMouseUp callbacks
		onMouseMove = null;
		onMouseUp = null;
		
		// reset direction
		_direction = Direction.notYetSet;


		// done as a workaround for this bug: https://github.com/silexlabs/Cocktail/issues/139
		//_viewport.onResize = onResizeCallback;

	}
	
	/**
	 * swipe animation when touch is released
	 */
	private function releaseTween():Void
	{
		//trace("releaseTween");
		//trace("releaseTween: " + "x:" + x + ", y:" + y + ", _offsetStart.x:" + _offsetStart.x + ", _offset.x:" + _offset.x + ", _viewportWidth:" + _viewportWidth + ", this.x:" + this.x + ", -_currentListView.x:" + -_currentListView.x);
		//trace( x + ", " + y + ", " + _offsetStart.x + ", " + _offset.x + ", " + _viewportWidth + ", " + this.x + ", " + -_currentListView.x);

		// create the tween
        var tween = new Tween( this.x, -_currentListView.x, 600, Quint.easeOut );
		tween.setTweenHandlers( tweenMove, tweenEnd );
        // launch the tween
        tween.start();
	}
	
	/**
	 * move view on the x axis
	 * 
	 * @param	e
	 */
    private function tweenMove( e : Float )
    {
        //trace("tweenMove");
		this.x = Std.int(e);
    }

    private function tweenEnd(e : Float )
	{
		
	}
	
	/*private function initTouchEvents():Void
	{
		//js.Lib.document.addEventListener('touchmove', function(event) {
		//event.preventDefault();
		//var touch = event.touches[0];
		//console.log("Touch x:" + touch.pageX + ", y:" + touch.pageY);
		//}, false);
		
		untyped
		{
			//js.Lib.document.addEventListener(
			document.addEventListener(
				'touchstart',
				function(event) {
					event.preventDefault();
					var touch = event.touches[0];
					//trace("Touch x:" + touch.pageX + ", y:" + touch.pageY);
					__this__.onDownCallback2(event);
					},
				false
			);
			
			document.addEventListener(
				'touchmove',
				function(event) {
					event.preventDefault();
					var touch = event.touches[0];
					trace("Touch x:" + touch.pageX + ", y:" + touch.pageY);
					__this__.onMoveCallback2(event);
					},
				false
			);
			
			document.addEventListener(
				'touchend',
				function(event) {
					event.preventDefault();
					__this__.onUpCallback2(event);
					},
				false
			);
			
			
		}
	}*/
	
// Touch event workaround	
#if js

	function touchHandler(event:Dynamic):Void
	{
		//untyped
		//{
			//event.preventDefault();

			/*var touches = event.changedTouches,
				first = touches[0],
				type = "";*/
				
			//trace(_direction + " - " + event.type);
			//if (_direction != Direction.vertical)
			//{
			//event.preventDefault();
			switch(event.type)
			{
				//case "touchstart": type = "mousedown";
				//case "touchmove":  type="mousemove";        
				//case "touchend":   type="mouseup";
				//default: return;
				case "touchstart":
					//if (!(_direction == Direction.vertical)) {event.preventDefault(); trace("event.preventDefault");}
					//event.preventDefault();
//					onDownCallback2(event.pageX, event.pageY);
					_initialPosition.x = event.pageX;
					_initialPosition.y = event.pageY;
					_offsetStart.x = this.parent.nativeElement.scrollLeft;
//		trace("XXXXXXXXXXXXX "+event.type + " - "+event.pageX+", "+event.pageY);
_direction = Direction.notYetSet;
				case "touchmove":
					this.parent.nativeElement.scrollLeft -= (0+ event.pageX - _initialPosition.x);
					//this.parent.nativeElement.scrollLeft = event.pageX;
					this.parent.nativeElement.scrollLeft += 10;
//					trace(event.pageX - _initialPosition.x);
					// if direction is horizontal, prevent default behaviour to be used
					//onMoveCallback2(event.pageX, event.pageY);
//					onMoveCallback2(event.pageX, event.pageY, event);
					//trace(_direction);
					_offset.x = 0 + event.pageX - _initialPosition.x;
					_offset.y = 0 + event.pageY - _initialPosition.y;

					if (_direction == Direction.notYetSet)
					{
						//trace(_offset.x);
						if (Math.abs(_offset.x) >= DIRECTION_PIXEL_MINIMUM)
							_direction = Direction.horizontal;
						if (Math.abs(_offset.y) >= DIRECTION_PIXEL_MINIMUM)
							_direction = Direction.vertical;
					}
					if (_direction == Direction.horizontal)
					{
						event.preventDefault(); 
						//trace("event.preventDefault");
					}
					else
					{
						event.preventDefault();
						this.parent.nativeElement.scrollLeft = _offsetStart.x;
					}

			case "touchend":
					//if (!(_direction == Direction.vertical)) {event.preventDefault(); trace("event.preventDefault");}
					onUpCallback2(this.parent.nativeElement.scrollLeft);
					if (_direction == Direction.horizontal)
					{
						event.preventDefault(); //trace("event.preventDefault");
					}
//		trace("XXXXXXXXXXXXX "+event.type + " - "+event.pageX+", "+event.pageY + " - "+ this.parent.nativeElement.scrollLeft+", "+this.parent.nativeElement.scrollTop);
_direction = Direction.notYetSet;
				default: return;
			}
			//}

			// initMouseEvent(type, canBubble, cancelable, view, clickCount, 
			// screenX, screenY, clientX, clientY, ctrlKey, 
			// altKey, shiftKey, metaKey, button, relatedTarget);
			
			//var simulatedEvent = document.createEvent("MouseEvent");
			//simulatedEvent.initMouseEvent(type, true, true, window, 1, 
				//first.screenX, first.screenY, 
				//first.clientX, first.clientY, false, 
				//false, false, false, 0, null);
//
			//first.target.dispatchEvent(simulatedEvent);
		//}

	}

	function initTouchEvents() 
	{
		untyped
		{
		document.addEventListener("touchstart", touchHandler, true);
		document.addEventListener("touchmove", touchHandler, true);
		document.addEventListener("touchend", touchHandler, true);
		document.addEventListener("touchcancel", touchHandler, true);
		}
		
	}

#end
	
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

