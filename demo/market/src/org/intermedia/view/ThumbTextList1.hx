/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import cocktail.mouse.MouseData;
import org.intermedia.model.ApplicationModel;

/**
 * This class defines a thumb & text cell
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1 extends ListViewBase
{

	public function new()
	{
		super();
		ListViewStyle.setListStyle(this);
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		for (index in Reflect.fields(_data))
		{
			// build cell
			var cell:CellThumbText1 = new CellThumbText1();
			
			// set cell data
			cell.data = Reflect.field(_data, index);
			
			// set mouseUp callback
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellSelected(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);

			// add cell to list
			this.addChild(cell);
		}
	}
	
	private function onCellSelected(cellData:CellData):Void
	{
		if (onListItemSelected != null)
		{
			onListItemSelected(cellData);
		}
	}
	
}