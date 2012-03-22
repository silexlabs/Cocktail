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
	static inline var VERTICAL_TWEEN_DELTA:Int = 150;
	
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
	private var _viewportHeight:Int;
	
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
		_viewportHeight = _viewport.height;
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
		
		//this.alpha = 0;
		// add all lists to the view
		for (listView in _listViews)
		{
			this.addChild(listView);
		}
		
		// set index
		_index = 1;
		// set current list to list2
		_currentListView = cast _listViews[_index];
		// scroll body to _currentListView position
		//this.parent.nativeElement.scrollLeft = _currentListView.x;
		//this.parent.nativeElement.scrollLeft = 0;
		
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
	/*private function onResizeCallback():Void
	{
		//trace("onResizeCallback");
		
		// compute new width
		_viewportWidth = _viewport.width;
		
		// update lists width
		list0.x = -_viewportWidth;
		list2.x = _viewportWidth;
		
		// update swippable view position
		this.x = -_currentListView.x;
	}*/
	
	/**
	 * A way to override onMouseDownCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * sets _xOffsetStart & _xInitial, and sets onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	//private function onDownCallback2(mouseEvent:MouseEventData):Void
	/*private function onDownCallback2(x:Float,y:Float):Void
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
	/*private function onMoveCallback2(x:Float,y:Float,event:Dynamic):Void
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
		

	//}
	
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

		
		//return;
		
		if (_direction == Direction.horizontal)
		{
			// compute offset
			//_xOffset = Std.int(mouseEvent.mousePosition.localX) - _xOffsetStart;
			//_offset.x = Std.int(x) - _offsetStart.x;
			//_offset.y = Std.int(y) - _offsetStart.y;
			//_offset.x = Std.int(x);
			//_offset.y = Std.int(y);
			
			//trace("onUpCallback2");
			//trace( x + ", " + y + ", " + _xOffsetStart + ", " + _xOffset + ", " + _viewportWidth);
			//trace( x + ", " + y);
			
			// go to list which user has scrolled to
			
			var w = _viewportWidth / 2;
			if (x < w)
			{
				//this.parent.nativeElement.scrollLeft = 0;
				_index = 0;
			}
			else if (x < 3 * w)
			{
				//this.parent.nativeElement.scrollLeft = _viewportWidth;
				_index = 1;
			}
			else 
			{
				//this.parent.nativeElement.scrollLeft = 2 * _viewportWidth;
				_index = 2;
			}
			//trace(_index);
			_currentListView = cast _listViews[_index];
		
			// if the mouse movement is from left to right
			// and if _xOffset is bigger than half the width of the viewport,
			// display next list and set _currentlist to the next list
			/*if (_offset.x < -_viewportWidth/2)
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
			}*/
			
			// set listItemSelected callback on current list
			_currentListView.onListItemSelected = onListItemSelectedCallback;
			_currentListView.onListScrolled = onScrolledCallback;

			// tween the swippable view in the correct position
			horizontalReleaseTween();
		
			// js workaround to scroll up
			/*#if js
			js.Lib.window.scrollTo(0, 0);
			//js.Lib.window.scrollTo(0,null);
			#end*/
		}
		else
		{
			verticalReleaseTween();
		}
			
		// unset onMouseMove & onMouseUp callbacks
		//onMouseMove = null;
		//onMouseUp = null;
		
		// reset direction
		//_direction = Direction.notYetSet;


		// done as a workaround for this bug: https://github.com/silexlabs/Cocktail/issues/139
		//_viewport.onResize = onResizeCallback;

	}
	
	/**
	 * swipe animation when touch is released
	 */
	private function horizontalReleaseTween():Void
	{
		//trace("releaseTween");
		//trace("releaseTween: " + "x:" + x + ", y:" + y + ", _offsetStart.x:" + _offsetStart.x + ", _offset.x:" + _offset.x + ", _viewportWidth:" + _viewportWidth + ", this.x:" + this.x + ", -_currentListView.x:" + -_currentListView.x);
		//trace( x + ", " + y + ", " + _offsetStart.x + ", " + _offset.x + ", " + _viewportWidth + ", " + this.x + ", " + -_currentListView.x);

		// create the tween
        //var tween = new Tween( this.nativeElement.scrollLeft, -_currentListView.x, 600, Quint.easeOut );
        var tween = new Tween( this.parent.nativeElement.scrollLeft, _currentListView.x, 600, Quint.easeOut );
		tween.setTweenHandlers( horizontalTweenMove, tweenEnd );
        // launch the tween
        tween.start();
	}
	
	/**
	 * move view on the x axis
	 * 
	 * @param	e
	 */
    private function horizontalTweenMove( e : Float )
    {
		//this.nativeElement.scrollLeft = Std.int(e);
		this.parent.nativeElement.scrollLeft = Std.int(e);
    }

	/**
	 * swipe animation when touch is released
	 */
	private function verticalReleaseTween():Void
	{
		//trace("releaseTween");
		//trace("releaseTween: " + "x:" + x + ", y:" + y + ", _offsetStart.x:" + _offsetStart.x + ", _offset.x:" + _offset.x + ", _viewportWidth:" + _viewportWidth + ", this.x:" + this.x + ", -_currentListView.x:" + -_currentListView.x);
		//trace( x + ", " + y + ", " + _offsetStart.x + ", " + _offset.x + ", " + _viewportWidth + ", " + this.x + ", " + -_currentListView.x);
		
		//trace(_currentListView.nativeElement.scrollTop);
		var verticalTweenEnd:Int = 0;
		// if scrolling direction is down
		if (_offset.y > 0 )
			verticalTweenEnd = _currentListView.nativeElement.scrollTop - VERTICAL_TWEEN_DELTA;
		else
			verticalTweenEnd = _currentListView.nativeElement.scrollTop + VERTICAL_TWEEN_DELTA;
		// create the tween
        //var tween = new Tween( this.nativeElement.scrollLeft, -_currentListView.x, 600, Quint.easeOut );
        var tween = new Tween( _currentListView.nativeElement.scrollTop, verticalTweenEnd, 600, Quint.easeOut );
		tween.setTweenHandlers( verticalTweenMove, tweenEnd );
        // launch the tween
        tween.start();
	}
	
	/**
	 * move view on the x axis
	 * 
	 * @param	e
	 */
    private function verticalTweenMove( e : Float )
    {
		//this.nativeElement.scrollLeft = Std.int(e);
		//_currentListView.nativeElement.scrollTop = _viewportHeight - Std.int(e);
		_currentListView.nativeElement.scrollTop = Std.int(e);
		//_currentListView.nativeElement.scrollTop = _currentListView.nativeElement.scrollHeight - Std.int(e);
    }

    private function tweenEnd(e : Float )
	{
		
	}
	
// Touch event workaround	
#if js

	function touchHandler(event:Dynamic):Void
	{
		switch(event.type)
		{
			//case "touchstart": type = "mousedown";
			//case "touchmove":  type="mousemove";        
			//case "touchend":   type="mouseup";
			//default: return;
			case "touchstart":
				_initialPosition.x = event.pageX;
				_initialPosition.y = event.pageY;
				_offsetStart.x = this.parent.nativeElement.scrollLeft;
				_direction = Direction.notYetSet;
			case "touchmove":
				this.parent.nativeElement.scrollLeft -= Std.int(event.pageX - _initialPosition.x);

				_offset.x = Std.int(event.pageX - _initialPosition.x);
				_offset.y = Std.int(event.pageY - _initialPosition.y);
				
				//trace(_direction + " - " + _offset.x + "," + _offset.y );
				if (_currentListView.nativeElement.scrollTop == 0 && _offset.y > 0)
				{
					event.preventDefault();
				}
				
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
					event.preventDefault();
				}
				// if direction is vertical
				else if (_direction == Direction.vertical)
				{
					this.parent.nativeElement.scrollLeft = _offsetStart.x;
				}

			case "touchend":
				//trace(_direction);
				if (_direction == Direction.horizontal)
				{
					event.preventDefault();
				}
				onUpCallback2(this.parent.nativeElement.scrollLeft);
				_direction = Direction.notYetSet;
			default: return;
		}
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

