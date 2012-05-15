package org.intermedia.view;

/**
 * Base class for cell. Each cell type has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

import js.Dom;
import org.intermedia.view.StyleModel;

class CellBase extends ViewBase
{
	
	// number of cells per line
	private var _cellPerLine:Int;
	
	// style
	private var _style:CellStyleModel;
	
	public function new(?cellPerLine:Int = 1, ?style:CellStyleModel) 
	{
		super();
		
		_style = cast _style;
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
			cell:CellStyle.setCellStyle,
			thumbnailMask:null,
			thumbnail:null,
			textBlock:null,
			title:null,
			author:null
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
