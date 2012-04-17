/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import haxe.Firebug;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

/**
 * Text list view
 * 
 * @author Raphael Harmel
 */

class MenuListViewText extends ListViewBase
{
	// menu index
	private var _index:Int;
	//public var index(getIndex,setIndex):Int;
	public var index:Int;
	
	public function new() 
	{
		_index = 0;
		super();
		MenuListViewStyle.setListStyle(node);
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
	/*private function setIndex(v:Int):Int
	{
		var leftMenuItem:HtmlDom = Lib.document.createElement("div");
		var centerMenuItem:HtmlDom = Lib.document.createElement("div");
		var rightMenuItem:HtmlDom = Lib.document.createElement("div");
		
		_index = v;
		// apply middle style to the cell corresponding to the new index
		MenuCellTextStyle.setRightCellStyle(_cells[v].node);
		// depending on the index value, set the left, middle and right menu item
		switch(_index)
		{
			case 0:
				leftMenuItem = _cells[2].node;
				centerMenuItem = _cells[0].node;
				rightMenuItem = _cells[1].node;
			case 1:
				leftMenuItem = _cells[0].node;
				centerMenuItem = _cells[1].node;
				rightMenuItem = _cells[2].node;
			case 2:
				leftMenuItem = _cells[1].node;
				centerMenuItem = _cells[2].node;
				rightMenuItem = _cells[0].node;
			default:
		}
		//remove all menu items
		for (cell in _cells)
		{
			node.removeChild(cell.node);
		}
		// attach all menu items in the correct order
		node.appendChild(leftMenuItem);
		node.appendChild(centerMenuItem);
		node.appendChild(rightMenuItem);
		// apply correct style to each cell
		MenuCellTextStyle.setLeftCellStyle(leftMenuItem);
		MenuCellTextStyle.setMiddleCellStyle(centerMenuItem);
		MenuCellTextStyle.setRightCellStyle(rightMenuItem);
		return v;
	}*/

	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	override private function createCell():CellBase
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
		_index++;
		var cell:MenuCellText = new MenuCellText(style);
		return cell;
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

}