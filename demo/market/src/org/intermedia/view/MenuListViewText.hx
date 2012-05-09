/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import feffects.Tween;
import haxe.Firebug;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.Scroll2D;
import feffects.easing.Quint;

/**
 * Text list view
 * 
 * @author Raphael Harmel
 */

class MenuListViewText extends ListViewBase
{
	// bold font offset
	static inline var BOLD_FONT_OFFSET:Int = 5;
	
	// menu index
	private var _index:Int;
	public var index(getIndex,setIndex):Int;
	//public var index:Int;
	
	// menu item 0 width
	private var _menuItem0Width:Int;
	
	// menu item 1 width
	private var _menuItem1Width:Int;
	
	// menu item 2 width
	private var _menuItem2Width:Int;
	
	// menu item 0 left position
	private var _menuItem0LeftPos:Int;
	
	// menu item 1 left position
	private var _menuItem1LeftPos:Int;
	
	// menu item 2 left position
	private var _menuItem2LeftPos:Int;
	
	// menu item left position target
	private var _menuItem0LeftTarget:Int;
	private var _menuItem1LeftTarget:Int;
	private var _menuItem2LeftTarget:Int;

	
	public function new() 
	{
		_index = 0;
		
		//init left target values
		_menuItem0LeftTarget = 0;
		_menuItem1LeftTarget = 0;
		_menuItem2LeftTarget = 0;

		super();
		
		displayListBottomLoader = false;
	}
	
	/**
	 * initialize the default style
	 */
	override function initStyle():Void
	{
		// init style model
		_style = {
			list:MenuListViewStyle.setMenuStyle
		}
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		//_index = 0;
		for (field in Reflect.fields(_data))
		{
			// build cell
			var cell:CellBase = createCell();
			
			// set cell data
			cell.data = Reflect.field(_data, field);
			
			// set mouseUp callback
			cell.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);

			// add cell to list
			node.appendChild(cell.node);
			
		}
		
		// if loader is attached to to list container, detach it
		if (_listBottomLoader.parentNode != null)
		{
			node.removeChild(_listBottomLoader);
		}
		// add loader at the bottom of the screen if there is still data to load
		if(displayListBottomLoader == true)
		{
			node.appendChild(_listBottomLoader);
		}
		
		// reset width attributes
		computeMenuItemsWidth();
		
		// set index to its initial value 
		//_index = 1;
		index = 1;
		refreshStyles();
	}	

	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	override private function createCell():CellBase
	{
		var cell:MenuCellText = new MenuCellText();
		return cell;
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
		// set previous menu item's font to normal, and current one to bold
		_cells[_index].node.style.fontWeight = "normal";
		_cells[v].node.style.fontWeight = "bold";

		_index = v;
		
		return v;
	}
	
	/**
	 * Menu item 0 tween move callback
	 * 
	 * @param	e
	 */
	public function menuItem0Move(e:Float):Void
	{
		_cells[0].node.style.left = Std.int(e) + "px";
	}
	
	/**
	 * Menu item 0 tween move callback
	 * 
	 * @param	e
	 */
	public function menuItem1Move(e:Float):Void
	{
		_cells[1].node.style.left = Std.int(e) + "px";
	}
	
	
	/**
	 * Menu item 0 tween move callback
	 * 
	 * @param	e
	 */
	public function menuItem2Move(e:Float):Void
	{
		_cells[2].node.style.left = Std.int(e) + "px";
	}
	
	/**
	 * Compute menu items width. It needs to be done at the beginning,
	 * as if an item is not visible in the viewport, its width is 0
	 */
	public function computeMenuItemsWidth():Void
	{
		_menuItem0Width = _cells[0].node.clientWidth;
		_menuItem1Width = _cells[1].node.clientWidth;
		_menuItem2Width = _cells[2].node.clientWidth;
	}
	
	/**
	 * Compute menu items left position. Used when swippableView is scrolled and when items needs to be moved accordingly
	 */
	public function computeMenuItemsLeftPos():Void
	{
		_menuItem0LeftPos = _cells[0].node.offsetLeft;
		_menuItem1LeftPos = _cells[1].node.offsetLeft;
		_menuItem2LeftPos = _cells[2].node.offsetLeft;
	}
	
	/**
	 * Compute menu items left target
	 * 
	 * @param	targetIndex	the menu item which "should" be the new target. we don not know yet as scroll is not complete
	 */
	private function computeMenuItemsLeftTarget(targetIndex:Int):Void
	{
		// depending on the index value, set each menu item left end position
		switch(targetIndex)
		{
			// google+ menu style
			//case 0:
				//_menuItem0LeftTarget = Std.int((Lib.window.innerWidth - _menuItem0Width) / 2);
				//_menuItem1LeftTarget = Lib.window.innerWidth - _menuItem1Width;
				//_menuItem2LeftTarget = Lib.window.innerWidth;
			//case 1:
				//_menuItem0LeftTarget = 0;
				//_menuItem1LeftTarget = Std.int((Lib.window.innerWidth - _menuItem1Width) / 2);
				//_menuItem2LeftTarget = Lib.window.innerWidth - _menuItem2Width;
			//case 2:
				//_menuItem0LeftTarget = -_menuItem0Width;
				//_menuItem1LeftTarget = 0;
				//_menuItem2LeftTarget = Std.int((Lib.window.innerWidth - _menuItem2Width) / 2);
			// android market style
			case 0:
				_menuItem0LeftTarget = Std.int((Lib.window.innerWidth - _menuItem0Width) / 2 - BOLD_FONT_OFFSET/2);
				_menuItem1LeftTarget = Std.int(Lib.window.innerWidth - Constants.MENU_LATERAL_OFFSET);
				_menuItem2LeftTarget = Std.int(3 * Lib.window.innerWidth / 2);
			case 1:
				_menuItem0LeftTarget = Std.int(-(_menuItem0Width - Constants.MENU_LATERAL_OFFSET));
				_menuItem1LeftTarget = Std.int((Lib.window.innerWidth - _menuItem1Width - BOLD_FONT_OFFSET) / 2);
				_menuItem2LeftTarget = Std.int(Lib.window.innerWidth - Constants.MENU_LATERAL_OFFSET);
			case 2:
				_menuItem0LeftTarget = Std.int( -Lib.window.innerWidth / 2);
				_menuItem1LeftTarget = Std.int(-(_menuItem1Width - Constants.MENU_LATERAL_OFFSET));
				_menuItem2LeftTarget = Std.int((Lib.window.innerWidth - _menuItem2Width) / 2 - BOLD_FONT_OFFSET/2);
			// keep the same values
			default:
		}
		
	}
	
	/**
	 * move horizontally menu items
	 * 
	 * @param	Xoffset
	 */
	public function moveHorizontally(ratio:Float):Void
	{
		// depending on ratio sign, increment or decrement _index
		// check is done so that index is always between 0 an 2
		if (ratio > 0)
		{
			computeMenuItemsLeftTarget(Std.int(Math.max(_index-1, 0)));
		}
		else if (ratio < 0)
		{
			computeMenuItemsLeftTarget(Std.int(Math.min(_index+1, 2)));
		}
		
		// move menu items depending on the ratio
		menuItem0Move(_menuItem0LeftPos + (Math.abs(_menuItem0LeftTarget - _menuItem0LeftPos) * ratio));
		menuItem1Move(_menuItem1LeftPos + (Math.abs(_menuItem1LeftTarget - _menuItem1LeftPos) * ratio));
		menuItem2Move(_menuItem2LeftPos + (Math.abs(_menuItem2LeftTarget - _menuItem2LeftPos) * ratio));
	}
	
	/**
	 * swippable view horizontal tween end callback
	 * 
	 * @param	newIndex	the new index value
	 */
    public function horizontalTweenEnd(newIndex:Int):Void
	{
		index = newIndex;
		//computeMenuItemsLeftPos();
		// styles are refreshed here to resolve bugs where menu items are not correctly positioned when a data loading is occuring
		refreshStyles();
	}
	
	/**
	 * refresh styles
	 */
	override public function refreshStyles():Void
	{
		// reset lists position
		computeMenuItemsLeftTarget(_index);
		menuItem0Move(_menuItem0LeftTarget);
		menuItem1Move(_menuItem1LeftTarget);
		menuItem2Move(_menuItem2LeftTarget);
		// reset left positions
		computeMenuItemsLeftPos();
	}	

}