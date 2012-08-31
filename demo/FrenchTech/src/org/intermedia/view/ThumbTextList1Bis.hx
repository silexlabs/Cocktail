/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

import js.Lib;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.StyleModel;

/**
 * This class defines a thumb & text cell having custom items in addition to its oawn cells
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1Bis extends ThumbTextList1
{
	private var _homePage:HomePage;
	
	public function new(?cellPerLine:Int = 1)
	{
		super(cellPerLine);
	}

	/**
	 * initialize the default style
	 */
	override function initStyle():Void
	{
		// init style model
		_style = {
			list:ThumbTextList1BisStyle.setListStyle
		}
	}
	
	public function buildHomePage(homePageData:Array<Dynamic>):Void
	{
		// add home page data at the top of the list
		var homePage:HomePage = new HomePage(homePageData);
		homePage.onListItemSelected = onListItemSelectedCallback;

		for (i in 0...homePage.cells.length)
		{
			// copy homepage children node to this.node
			// following cloneNode method does not seem to work correctly here
			//node.appendChild(homePage.node.childNodes[i].cloneNode(true));
			// instead, children nodes are moves
			_cells.push(homePage.cells[i]);
			node.appendChild(_cells[i].node);
		}

	}
	
	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	override private function createCell():CellBase
	{
		// init style model
		var cellStyle:CellStyleModel = {
			cell:CellThumbText1BisStyle.setCellStyle,
			thumbnailMask:CellThumbText1Style.setThumbnailMaskStyle,
			thumbnail:null,
			textBlock:CellThumbText1Style.setTextBlockStyle,
			title:CellThumbText1Style.setTitleStyle,
			author:null
		}
		
		var cell:CellThumbText1 = new CellThumbText1(_cellsPerLine, cellStyle);
		return cell;
	}
	
}