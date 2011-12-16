/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList
import components.richList.RichListModels;

// Iphone specific
import Utils;


/**
 * This contains the utils methods used by the RichLists
 * 
 * @author Raphael Harmel
 */

class RichListUtils extends Utils 
{
	/**
	 * Initializes a rich list model
	 * 
	 * @return
	 */
	public static function createRichListModel():RichListModel
	{
		var richListModel:RichListModel = 
		{
			content: new Array<CellModel>()
		};
		
		return richListModel;	
	}
	
}