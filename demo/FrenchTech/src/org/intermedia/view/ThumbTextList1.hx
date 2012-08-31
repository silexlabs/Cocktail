/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

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