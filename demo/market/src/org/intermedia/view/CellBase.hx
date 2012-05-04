package org.intermedia.view;


import org.intermedia.view.StyleModel;

/**
 * Base class for list cell. Each ListView has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

class CellBase extends ViewBase
{
	
	// number of celles per line
	private var _cellPerLine:Int;
	
	public function new(?cellPerLine:Int = 1, ?style:CellStyleModel) 
	{
		super();
		
		_cellPerLine = cellPerLine;
		
		// init style
		if (style != null) _style = style;
		else initStyle();
		
		// apply cell style
		_style.cell(node,cellPerLine);
	}
	
	/**
	 * initialize the default style
	 */
	private function initStyle():Void
	{
		// init style model
		_style = {
			cell:CellStyle.setCellStyle
		}
	}
	
	/**
	 * Refresh cell styles, to be overriden in inheriting classes 
	 */
	public function refreshStyles():Void
	{
		_style.cell(node,_cellPerLine);
	}

	
}