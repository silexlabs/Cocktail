package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.ListViewBase;
import org.intermedia.model.Feeds;
import org.intermedia.view.Scroll2D;
import haxe.Firebug;
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
	static inline var HOMEPAGE_ITEM_PER_LIST:Int = 3;
	
	// number of lists taken in account for the homepage items
	static inline var LIST_QTY:Int = 2;
	static inline var HOMEPAGE_ITEMS:Int = HOMEPAGE_ITEM_PER_LIST * LIST_QTY;
	
	// the container of the swippable lists
	private var _listsContainer:HtmlDom;
	
	// a ref to each of the list views which can be swiped
	private var _listViews:Array<ListViewBase>;
	
	private var list0:ListViewText;
	private var list1:ThumbTextList1Bis;
	private var list2:ThumbTextList1;
	private var _list1Data:Array<CellData>;
	
	// The ListView currently displayed
	private var _currentListView:ListViewBase;
	
	// current list view index
	private var _index:Int;
	public var index(getIndex,setIndex):Int;
	
	// X offset used to scroll list left and right
	private var _offset:Coordinate;
	private var _offsetStart:Coordinate;
	private var _initialPosition:Coordinate;
	
	// main movement direction
	private var _direction:Direction;
	
	// home page data
	private var _homePageData:Array<Dynamic>;
	
	private var _homePageDataSet:Bool;
	
	// touch & mouse handler
	private var _moveHandler:Scroll2D;
	
	// on horizontal move callback, used to send scroll offset to menu
	public var onHorizontalMove:Float->Void;
	
	// horizontal tween end
	public var onHorizontalTweenEnd:Void->Void;
	
	// horizontal tween end
	public var onHorizontalUp:Int->Void;
	
	public function new()
	{
		super();
		// display loading
		displayLoading = true;
		
		// init attributes
		_offset = { x:0, y:0 };
		_offsetStart = { x:0, y:0 };
		_initialPosition = { x:0, y:0 };
		_direction = Direction.notYetSet;
		
		_homePageData = new Array<Dynamic>();
		_homePageDataSet = false;
		
		_listsContainer = Lib.document.createElement("div");
		SwippableListViewStyle.setListsContainerStyle(_listsContainer);
		node.appendChild(_listsContainer);
		
		// set style
		SwippableListViewStyle.setSwippableListStyle(node);

		// set onMouseDown callback
		//onMouseDown = onDownCallback;
		//onMouseDown = function(mouseEvent:MouseEventData) { onDownCallback(mouseEvent.mousePosition.localX, mouseEvent.mousePosition.localY); };
		
		// set _listView array
		_listViews = new Array<ListViewBase>();
		
		// create all needed lists and add them to the _listView array
		list0 = new ListViewText();
		list0.id = Feeds.FEED_1.url;
		_listViews.push(list0);
		
		list1 = new ThumbTextList1Bis(2);
		list1.id = Feeds.FEED_2.url;
		_listViews.push(list1);
		
		list2 = new ThumbTextList1(2);
		list2.id = Feeds.FEED_3.url;
		_listViews.push(list2);
		
		// position the lists to their correct left offset
		positionLists();
		
		// add all lists to the view
		for (listView in _listViews)
		{
			listView.onDataRequest = onDataRequestCallback;
			listView.onListItemSelected = onListItemSelectedCallback;
			_listsContainer.appendChild(listView.node);

		}
		
		// set index
		_index = 1;
		// set current list to list1
		_currentListView = cast _listViews[_index];
		
		// set listItemSelected callback on current list
		_currentListView.onListItemSelected = onListItemSelectedCallback;
		
		// initialise move handler
		_moveHandler = new Scroll2D(ScrollType.both);
		_moveHandler.onVerticalScroll = onVerticalMove;
		_moveHandler.onHorizontalScroll = onHorizontalMoveCallback;
		_moveHandler.onHorizontalUp = onHorizontalUpCallback;
		_moveHandler.onHorizontalTween = onHorizontalTweenCallback;
		
		// js touch events handling
		addTouchEvents();

	}
	
	/**
	 * set lists left offset value (used for resizing)
	 */
	private function positionLists():Void
	{
		// position lists to their correct left position
		list1.node.style.left = Std.string(1 * Lib.window.innerWidth) + "px";
		list2.node.style.left = Std.string(2 * Lib.window.innerWidth) + "px";
	}
	
	/**
	 * data setter which sets each list data
	 * 
	 * @param	v
	 * @return
	 */
	override private function setData(v:Dynamic):Dynamic
	{
		_data = v;
		
		// set the data on the correct list, depending on the list id
		for (list in _listViews)
		{
			if (v.id == list.id && v.id != list1.id)
			{
				// if _homePageData is not fully filled, continue to fill it
				if (_homePageData.length < HOMEPAGE_ITEMS)
				{
					for (i in 0...HOMEPAGE_ITEM_PER_LIST)
					{
						_homePageData.push(data.cells[i]);
					}
				}
				
				// fill list with its corresponding data
				list.data = v.cells;
				
				break;
			}
			
			// if data id is main list one: list1, store this data into a temporary attribute so it can be pushed to the list once the homepage is loaded
			if (v.id == list1.id)
			{
				_list1Data = cast v.cells;
			}
			
		}
		
		// if home page data is not set yet and _homePageData elements quantity is equal to HOMEPAGE_ITEMS,
		// build home page, attach lists to swippable view, scroll to list1 and remove loading screen
		if (!_homePageDataSet && _homePageData.length == HOMEPAGE_ITEMS)
		{
			// build home page with its data
			list1.buildHomePage(_homePageData);
			// set _homePageDataSet flag to true
			_homePageDataSet = true;
			
			scrollToCurrentList();
			
			displayLoading = false;

		}
		
		// if homepage is set, add or update list1 data
		if (_homePageDataSet)
		{
			list1.data = _list1Data;
		}

		return _data;	
	}
	
	/**
	 * index getter
	 * 
	 * @param	v
	 * @return
	 */
	private function getIndex():Int
	{
		return _index;
	}
	
	/**
	 * index setter: animate the swippable view from the current position to the list corresponding to the new index
	 * 
	 * @param	v
	 * @return
	 */
	private function setIndex(v:Int):Int
	{
		// unset current list item selected callback
		_currentListView.onListItemSelected = null;
		// set _index
		_index = v;
		// update current list to new index
		_currentListView = cast _listViews[v];
		// set current list item selected callback
		_currentListView.onListItemSelected = onListItemSelectedCallback;
		
		// launch horizontal tween
		_moveHandler.horizontalReleaseTween(node.scrollLeft, _currentListView.node.offsetLeft);

		return v;
	}
	
	/**
	 * scroll the swippable view to the current list
	 */
	public function scrollToCurrentList():Void
	{
		node.scrollLeft = Std.parseInt(_currentListView.node.style.left.substr(0,-2));
	}
	
	/**
	 * on rezize callback
	 */
	public function onResizeCallback(event:Event):Void
	{
		// reset lists position
		positionLists();
		
		// scroll to current list
		scrollToCurrentList();
		
		// reapply lists styles (mainly for image cropping
		for (list in _listViews)
		{
			list.refreshStyles();
		}
	}
	
	/**
	 * move swippable view on the horizontal axis
	 * 
	 * @param	XScroll	new scroll position
	 * @param	XOffset	scroll offset ( = initial touch position - end touch position )
	 */
    private function onHorizontalMoveCallback( XScroll:Int, XOffset:Int )
    {
		// compute horizontal ratio
		var horizontalRatio:Float = computeHorizontalRatio(XOffset);
		
		node.scrollLeft = XScroll;
		
		// call onHorizontalMove callback
		if (onHorizontalMove != null && horizontalRatio != 0)
		{
			onHorizontalMove(horizontalRatio);
		}
		
    }
	
	/**
	 * Horizontal tween callback
	 * 
	 * @param	XScroll	new scroll position
	 */
    private function onHorizontalTweenCallback(XScroll:Int):Void
	{
		node.scrollLeft = XScroll;
	}
	
	/**
	 * move current list view on the vertical axis
	 * 
	 * @param	e
	 */
    private function onVerticalMove( y : Int )
    {
		_currentListView.node.scrollTop = y;
    }
	
	/**
	 * horizontal up handler
	 * 
	 * @param	event
	 */
	private function onHorizontalUpCallback(event:Dynamic,XOffset:Int):Void
	{
		event.preventDefault();
		
		// if movement was negative and more that half of the size of the screen
		//if (XOffset < -Lib.window.innerHeight / 2)
		if (XOffset < -Lib.window.innerHeight * Constants.SWIP_HORIZONTAL_WIDTH_RATIO)
		{
			// if the current list is not the last one, increment index using setter
			if (index < _listViews.length - 1)
				index++;
		}
		// if movement was positive and less that half of the size of the screen
		//else if (XOffset > Lib.window.innerHeight / 2)
		else if (XOffset > Lib.window.innerHeight * Constants.SWIP_HORIZONTAL_WIDTH_RATIO)
		{
			// if the current list is not the first one, decrement index using setter
			if (index > 0)
				index--;
		}
		// else come back on the current list
		else
		{
			index = index;
		}
		
		// js workaround to scroll up
		/*#if js
		js.Lib.window.scrollTo(0, 0);
		//js.Lib.window.scrollTo(0,null);
		#end*/
		
		// compute horizontal ratio
		var horizontalRatio:Float = computeHorizontalRatio(XOffset);
		
		// if onHorizontalUp callback is defined, call it
		if (onHorizontalUp != null)
		{
			onHorizontalUp(_index);
		}
	}

		
	/**
	 * remove list scroll callback behaviour
	 * @param	event
	 */
	override private function onScrollCallback(event:Event):Void
	{
	}

	/**
	 * Adds touch events
	 */
	public function addTouchEvents():Void
	{
		#if js
		untyped
		{
		node.addEventListener("touchstart",touchStart, false);
		node.addEventListener("touchmove", touchMove, false);
		node.addEventListener("touchend", touchEnd, false);
		node.addEventListener("touchcancel", _moveHandler.touchHandler, false);
		}
		#end
	}
	
	/**
	 * Touch start event handler
	 * 
	 * @param	event
	 */
	private function touchStart(event:Dynamic):Void
	{
		_moveHandler.initialScrollPosition = { x:node.scrollLeft, y:_currentListView.node.scrollTop };
		_moveHandler.touchHandler(event);
	}

	/**
	 * Touch move event handler
	 * 
	 * @param	event
	 */
	private function touchMove(event:Dynamic):Void
	{
		// unset currentListlist's ItemSelected callback 
		_currentListView.onListItemSelected = null;
		_moveHandler.touchHandler(event);
	}

	/**
	 * Touch end event handler
	 * 
	 * @param	event
	 */
	private function touchEnd(event:Dynamic):Void
	{
		// set currentListlist's ItemSelected callback
		_currentListView.onListItemSelected = onListItemSelectedCallback;
		_moveHandler.touchHandler(event);
	}

	/**
	 * Computes Horizontal ratio
	 * 
	 * @param	XOffset
	 * @return
	 */
	private function computeHorizontalRatio(XOffset:Int):Float
	{
		var ratio:Float = 0;
		if (Lib.window.innerHeight != 0)
			ratio = XOffset / Lib.window.innerHeight;
		return ratio;

	}
}
