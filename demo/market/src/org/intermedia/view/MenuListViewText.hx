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
	// menu index
	private var _index:Int;
	public var index(getIndex,setIndex):Int;
	//public var index:Int;
	
	// node used for the scrolling
	//private var _scrollNode:HtmlDom;
	
	// touch & mouse handler
	//private var _moveHandler:Scroll2D;
	
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
	
	public function new() 
	{
		_index = 0;
		
		super();
		MenuListViewStyle.setListStyle(node);

		// initialise move handler
		//_moveHandler = new Scroll2D(ScrollType.horizontal);
		//_moveHandler.onHorizontalScroll = onHorizontalMove;
		//_moveHandler.onHorizontalUp = onHorizontalUp;
		
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
		//trace("setIndex: " + v);
		
		_index = v;
		
		// depending on the index value, set each menu item left end position
		var menuItem0LeftEnd:Int = 0;
		var menuItem1LeftEnd:Int = 0;
		var menuItem2LeftEnd:Int = 0;
		switch(_index)
		{
			case 0:
				menuItem0LeftEnd = Std.int((Lib.window.innerWidth - _menuItem0Width) / 2);
				menuItem1LeftEnd = Lib.window.innerWidth - _menuItem1Width;
				menuItem2LeftEnd = Lib.window.innerWidth;
			case 1:
				menuItem0LeftEnd = 0;
				menuItem1LeftEnd = Std.int((Lib.window.innerWidth - _menuItem1Width) / 2);
				menuItem2LeftEnd = Lib.window.innerWidth - _menuItem2Width;
			case 2:
				menuItem0LeftEnd = -_menuItem0Width;
				menuItem1LeftEnd = 0;
				menuItem2LeftEnd = Std.int((Lib.window.innerWidth - _menuItem2Width) / 2);
			default:
		}

		//trace( _cells[0].node.offsetLeft + "," + _cells[1].node.offsetLeft + "," + _cells[2].node.offsetLeft);
		//trace("setIndex: " + v + " - " + _cells[0].node.offsetLeft + "," + menuItem0LeftEnd);
		
		// menu item 0 tween
		var tween0:Tween = new Tween( _cells[0].node.offsetLeft, menuItem0LeftEnd, 600, Quint.easeOut );
		tween0.setTweenHandlers( menuItem0Move, menuItemMoveEnd );
		// launch the tween
		//tween0.start();

		// menu item 1 tween
		var tween1:Tween = new Tween( _cells[1].node.offsetLeft, menuItem1LeftEnd, 600, Quint.easeOut );
		tween1.setTweenHandlers( menuItem1Move, menuItemMoveEnd );
		// launch the tween
		//tween1.start();

		// menu item 0 tween
		var tween2:Tween = new Tween( _cells[2].node.offsetLeft, menuItem2LeftEnd, 600, Quint.easeOut );
		tween2.setTweenHandlers( menuItem2Move, menuItemMoveEnd );
		// launch the tween
		//tween2.start();

		//trace(menuItem0LeftEnd + "," + _cells[0].node.offsetLeft + "," + menuItem1LeftEnd + "," + _cells[1].node.offsetLeft + "," + menuItem2LeftEnd + "," + _cells[2].node.offsetLeft);
		//trace( _cells[0].node.offsetLeft + "," + _cells[1].node.offsetLeft + "," + _cells[2].node.offsetLeft);
		//trace(menuItem0LeftEnd + "," + _cells[0].node.offsetLeft);

		//computeMenuItemsLeftPos();

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
	 * Menu item tween move end callback 
	 * 
	 * @param	e
	 */
	private function menuItemMoveEnd(e:Float):Void
	{
		//trace(e);
		//trace(_cells[0].node.style.left);
		//trace(_cells[0].node.offsetLeft);
		//computeMenuItemsLeftPos();
	}
	
	/**
	 * Compute menu items width. It needs to be done once, as if an item is not visible in the viewport, its width is 0
	 */
	public function computeMenuItemsWidth():Void
	{
		_menuItem0Width = _cells[0].node.clientWidth;
		_menuItem1Width = _cells[1].node.clientWidth;
		_menuItem2Width = _cells[2].node.clientWidth;
		//Firebug.trace(_menuItem0Width);
		//Firebug.trace(_menuItem1Width);
		//Firebug.trace(_menuItem2Width);
	}
	
	/**
	 * Compute menu items left position. Used when swippableView is scrolled and when items needs to be moved accordingly
	 */
	public function computeMenuItemsLeftPos():Void
	{
		_menuItem0LeftPos = _cells[0].node.offsetLeft;
		_menuItem1LeftPos = _cells[1].node.offsetLeft;
		_menuItem2LeftPos = _cells[2].node.offsetLeft;
		//Firebug.trace(_menuItem0LeftPos);
		//Firebug.trace(_menuItem1LeftPos);
		//Firebug.trace(_menuItem2LeftPos);
	}
	
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		_index = 0;
		for (field in Reflect.fields(_data))
		{
			// build cell
			var cell:CellBase = createCell();
			
			// set cell data
			cell.data = Reflect.field(_data, field);
			
			// set mouseUp callback
			//cell.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell.data); };
			cell.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);

			// add cell to list
			node.appendChild(cell.node);
			
			var style:HtmlDom->Void = setCellsStyle();
			style(cell.node);
			
			// re-apply cell styles, as we need to apply some styles which need to be computed by the layout
			//var style:HtmlDom->Void = setCellsStyle();
			//style(cell.node);
			
			// depending on the index value, set a specific id
			switch(_index)
			{
				case 0:
					cell.node.id = "menu_item0";
				case 1:
					cell.node.id = "menu_item1";
				case 2:
					cell.node.id = "menu_item2";
				default:
			}
			
			_index++;
			
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
		
		computeMenuItemsWidth();
		computeMenuItemsLeftPos();
	}	

	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	override private function createCell():CellBase
	{
		//var style:HtmlDom->Void = setCellsStyle();
		var cell:MenuCellText = new MenuCellText();
		return cell;
	}
	
	
	private function setCellsStyle():HtmlDom->Void
	{
		// set default cell style
		var style:HtmlDom->Void = MenuCellTextStyle.setCellStyle;
		// depending on the index value, apply corresponding style
		switch(_index)
		{
			case 0:
				style = MenuCellTextStyle.setLeftCellStyle;
			case 1:
				style = MenuCellTextStyle.setMiddleCellStyle;
			case 2:
				style = MenuCellTextStyle.setRightCellStyle;
			default:
		}
		return style;
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
	 * move swippable view on the horizontal axis
	 * 
	 * @param	e
	 */
    /*private function onHorizontalMove( x : Int )
    {
		node.scrollLeft = x;
		//node.style.left = x + "px";
    }*/

	
	/**
	 * move horizontally menu items
	 * 
	 * @param	Xoffset
	 */
	//public function moveHorizontally(XOffset:Int):Void
	public function moveHorizontally(ratio:Float):Void
	{
		//trace("moveHorizontally");
		//trace("ratio: " + Std.int(ratio*100));
		//trace(ratio);
		//menuItem0Move(_menuItem0LeftPos + ((Lib.window.innerWidth - _menuItem0Width) * XOffset / Lib.window.innerWidth));
		//menuItem1Move(_menuItem1LeftPos + ((Lib.window.innerWidth - _menuItem1Width) * XOffset / Lib.window.innerWidth));
		//menuItem2Move(_menuItem2LeftPos + ((Lib.window.innerWidth - _menuItem2Width) * XOffset / Lib.window.innerWidth));
		menuItem0Move(_menuItem0LeftPos + ((Lib.window.innerWidth - _menuItem0Width) * ratio / 2));
		menuItem1Move(_menuItem1LeftPos + ((Lib.window.innerWidth - _menuItem1Width) * ratio / 2));
		menuItem2Move(_menuItem2LeftPos + ((Lib.window.innerWidth - _menuItem2Width) * ratio / 2));
	}
	
	/**
	 * move horizontally menu items
	 * 
	 * @param	Xoffset
	 */
	//public function horizontalRelease(ratio:Float):Void
	public function horizontalRelease(listIndex:Int):Void
	{
		// reset position attributes
		//computeMenuItemsLeftPos();
		
		//trace(listIndex);
		//index = listIndex;
		
	}
	
	/**
	 * Horizontal tween
	 * 
	 * @param	e
	 */
    public function horizontalTweenEnd():Void
	{
		computeMenuItemsLeftPos();
	}
}