package org.intermedia.view;


import org.intermedia.view.StyleModel;

/**
 * Base class for list cell. Each ListView has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

class CellBase extends ViewBase
{
	
	// cell style
	private var _cellStyle:Dynamic;
	
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel) 
	{
		super();
		
		// init style
		if (cellStyle != null) _cellStyle = cellStyle;
		else initCellStyle();
		
		// apply cell style
		_cellStyle.cell(node,cellPerLine);
	}
	
	/**
	 * initialize the default cell style
	 */
	private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
			cell:CellStyle.setCellStyle,
			thumbnail:null,
			textBlock:null,
			title:null,
			author:null,
			line:null
		}
	}

	
}