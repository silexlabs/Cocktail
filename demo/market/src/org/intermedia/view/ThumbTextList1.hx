/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

//import cocktail.mouse.MouseData;
import org.intermedia.model.ApplicationModel;

/**
 * This class defines a thumb & text cell which can have a variable numbers of cells per line
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1 extends ListViewBase
{
	// defines cells per line
	private var _cellsPerLine:Int;
	
	public function new(?cellPerLine:Int = 1)
	{
		_cellsPerLine = cellPerLine;
		super();
		ListViewStyle.setListStyle(node, Constants.LIST_TOP);
	}
	
	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	override private function createCell():CellBase
	{
		var cell:CellThumbText1 = new CellThumbText1(_cellsPerLine);
		return cell;
	}
	
	
}