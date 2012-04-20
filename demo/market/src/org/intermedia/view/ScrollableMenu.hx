package org.intermedia.view;

import haxe.Firebug;
import org.intermedia.model.Feeds;
import org.intermedia.view.Scroll2D;
import org.intermedia.model.ApplicationModel;

/**
 * This class defines a scrollable menu
 * 
 * @author Raphael Harmel
 */

class ScrollableMenu extends ListViewBase
{
	
	// reference to the menu
	private var _menu:MenuListViewText;
	
	// menu index
	private var _index:Int;
	public var index(getIndex,setIndex):Int;

	// touch & mouse handler
	//private var _moveHandler:Scroll2D;
	
	public function new() 
	{
		super();
		MenuListViewStyle.setMenuStyle(node);
		
		// init menu
		_menu = new MenuListViewText();
		_menu.displayListBottomLoader = false;
		node.appendChild(_menu.node);
		//_menu.data = [Feeds.FEED_1, Feeds.FEED_2, Feeds.FEED_3];
		// set list item selelected callback
		_menu.onListItemSelected = onListItemSelectedCallback;
		
		// initialise move handler
		//_moveHandler = new Scroll2D(ScrollType.horizontal);
		//_moveHandler.onHorizontalScroll = onHorizontalMove;
		//_moveHandler.onHorizontalUp = onHorizontalUp;
		
	}
	
	/**
	 * Removes default updateView behaviour
	 */
	override private function updateView():Void
	{
		//super.updateView();
		_menu.data = _data;
		
		// computes menu items width, as cannot be done until dom structure is computed
		//_menu.computeMenuItemsWidth();
		//_menu.computeMenuItemsLeftPos();
		
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
		//Firebug.trace(v);
		_index = v;
		_menu.index = v;
		
		//_moveHandler.horizontalReleaseTween(node.scrollLeft, Std.parseInt(_currentListView.node.style.left));
		//_moveHandler.horizontalReleaseTween(node.scrollLeft, 100);
		
		return v;
	}

	/**
	 * move swippable view on the horizontal axis
	 * 
	 * @param	e
	 */
    /*private function onHorizontalMove( XScroll:Int, XOffset:Int )
    {
		//Firebug.trace(x);
		//node.scrollLeft = x;
		//_menu.node.scrollLeft = x;
		//node.style.left = x + "px";
    }*/

	/**
	 * onListItemSelected callback
	 * @param	cellData
	 */
	override public function onListItemSelectedCallback(cellData:CellData)
	{
		index = cellData.id;
		super.onListItemSelectedCallback(cellData);
	}
	
	/**
	 * move horizontally menu items
	 * 
	 * @param	Xoffset
	 */
	//public function horizontalMove(XOffset:Int):Void
	public function horizontalMove(ratio:Float):Void
	{
		Firebug.trace(ratio);
		//_menu.menuItem0Move(Xoffset);
		//_menu.menuItem1Move(Xoffset);
		//_menu.menuItem2Move(Xoffset);
		_menu.moveHorizontally(ratio);
	}
	

	/**
	 * move horizontally menu items
	 * 
	 * @param	Xoffset
	 */
	//public function horizontalRelease(ratio:Float):Void
	public function horizontalRelease(listIndex:Int):Void
	{
		_menu.horizontalRelease(listIndex);
	}
	

}