/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

<<<<<<< HEAD
//import cocktail.mouse.MouseData;
import haxe.Firebug;
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
	//private var _homePageData:Array<Dynamic>;
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
		/*for (i in 0...homePage.node.childNodes.length)
		{
			// copy homepage children node to this.node. cloneNode Does not seem to work correctly here
			//node.appendChild(homePage.node.childNodes[i].cloneNode(true));
			// instead, children nodes are moves
			node.appendChild(homePage.node.childNodes[0]);
			
		}*/
		for (i in 0...homePage.cells.length)
		{
			// copy homepage children node to this.node. cloneNode Does not seem to work correctly here
=======

		for (i in 0...homePage.cells.length)
		{
			// copy homepage children node to this.node
			// following cloneNode method does not seem to work correctly here
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
			//node.appendChild(homePage.node.childNodes[i].cloneNode(true));
			// instead, children nodes are moves
			_cells.push(homePage.cells[i]);
			node.appendChild(_cells[i].node);
		}

<<<<<<< HEAD
=======
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
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	}
	
}