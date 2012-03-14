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
	private var _xOffset:Int;
	private var _xOffsetStart:Int;
	
	private var _initialPosition:Int;
	
	// view port
	private var _viewport:Viewport;
	private var _viewportWidth:Int;
	
	public function new()
	{
		super();
		
		// init attributes
		_xOffset = 0;
		_xOffsetStart = 0;
		_initialPosition = 0;
		_viewport = new Viewport();
		_viewportWidth = _viewport.width;
		_viewport.onResize = onResizeCallback;
		
		// set style
		SwippableListViewStyle.setListStyle(this);
		// set onMouseDown callback
		onMouseDown = onMouseDownCallback2;
		
		// set _listView array
		_listViews = new Array<ViewBase>();
		
		// create all needed lists and add them to the _listView array
		list0 = new ListViewText();
		list0.x = -_viewportWidth;
		_listViews.push(list0);
		
		//var list1:ListViewBase = new ThumbTextList1Bis(3);Filters component
		list1 = new ThumbTextList1Bis(2);
		_listViews.push(list1);
		
		list2 = new ThumbTextList1(2);
		_listViews.push(list2);
		list2.x = _viewportWidth;

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
	 * sets _xOffsetStart & _initialPosition, and sets onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	private function onMouseDownCallback2(mouseEvent:MouseEventData):Void
	{
		// set _xOffset to current mouse position
		_xOffsetStart = Std.int(mouseEvent.mousePosition.localX);
		
		// set initial position to x coordinate of the swippable view 
		_initialPosition = this.x;
		
		// set onMouseMove & onMouseUp callbacks
		onMouseMove = onMouseMoveCallback2;
		onMouseUp = onMouseUpCallback2;
		
	}

	/**
	 * A way to override onMouseMoveCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * computes offset & moves the swippable view according to the offset
	 * 
	 * @param	mouseEventData
	 */
	private function onMouseMoveCallback2(mouseEvent:MouseEventData):Void
	{

		// compute offset
		_xOffset = Std.int(mouseEvent.mousePosition.localX) - _xOffsetStart;

		// move the swippable view according to the offset
		this.x = _initialPosition + _xOffset;
		
		// unset listItemSelected callback on current list to avoid opening detail view while swipping
		_currentListView.onListItemSelected = null;
		_currentListView.onListScrolled = null;

	}
	
	/**
	 * A way to override onMouseUpCallback - not the best way, but Cocktail bug posted as no "nice" way to do it
	 * unset onMouseMove & onMouseUp callbacks
	 * 
	 * @param	mouseEventData
	 */
	private function onMouseUpCallback2(mouseEvent:MouseEventData):Void
	{
		// compute offset
		_xOffset = Std.int(mouseEvent.mousePosition.localX) - _xOffsetStart;
		
		// go to list which user has scrolled to
		
		// if the mouse movement is from left to right
		// and if _xOffset is bigger than half the width of the viewport,
		// display next list and set _currentlist to the next list
		if (_xOffset < -_viewportWidth/2)
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
		else if (_xOffset > _viewportWidth/2)
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
		
		// js wokaround to scroll up
		#if js
		js.Lib.window.scrollTo(0, 0);
		//js.Lib.window.scrollTo(0,null);
		#end
		
		// unset onMouseMove & onMouseUp callbacks
		onMouseMove = null;
		onMouseUp = null;
	}
	
	/**
	 * swipe animation when touch is released
	 */
	private function releaseTween():Void
	{
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
    function tweenMove( e : Float )
    {
        this.x = Std.int(e);
    }

    function tweenEnd(e : Float )
	{
		
	}

}
