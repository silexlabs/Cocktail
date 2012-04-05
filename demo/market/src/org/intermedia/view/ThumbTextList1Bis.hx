/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

//import cocktail.mouse.MouseData;
import org.intermedia.model.ApplicationModel;
//import cocktail.node.HtmlDom;

/**
 * This class defines a thumb & text cell
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1Bis extends ThumbTextList1
{
	private var _homePageData:Array<Dynamic>;
	
	//public function new(?cellPerLine:Int = 1, homePageData:Array<Dynamic>)
	public function new(?cellPerLine:Int = 1)
	{
		//trace(homePageData);
		//_homePageData = homePageData;
		super(cellPerLine);
	}

	
	//override private function buildView():Void
	public function buildHomePage(homePageData:Array<Dynamic>):Void
	//override private function updateView():Void
	{
		//trace(_homePageData);
		// add home page data at the top of the list
		var homePage:HomePage = new HomePage(homePageData);
		homePage.onListItemSelected = onListItemSelectedCallback;
		node.appendChild(homePage.node);
	}
	

}