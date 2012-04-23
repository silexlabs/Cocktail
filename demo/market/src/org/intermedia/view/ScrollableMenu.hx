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

	public function new() 
	{
		super();
		MenuListViewStyle.setMenuStyle(node);
		
		// init menu
		_menu = new MenuListViewText();
		_menu.displayListBottomLoader = false;
		node.appendChild(_menu.node);

		// set list item selelected callback
		_menu.onListItemSelected = onListItemSelectedCallback;	
	}
	
	/**
	 * Removes default updateView behaviour
	 */
	override private function updateView():Void
	{
		_menu.data = _data;
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
		_index = v;
		_menu.index = v;
		
		return v;
	}

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
	public function moveHorizontally(ratio:Float):Void
	{
		_menu.moveHorizontally(ratio);
	}
	

	/**
	 * move horizontally menu items
	 * 
	 * @param	Xoffset
	 */
	public function horizontalUp(listIndex:Int):Void
	{
		_menu.horizontalUp(listIndex);
	}
	
	/**
	 * Horizontal tween callback
	 * 
	 * @param	e
	 */
    /*public function horizontalTweenEnd():Void
	{
		_menu.horizontalTweenEnd();
	}*/
	
}