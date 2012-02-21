/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

// list
import components.lists.ListBaseModels;


/**
 * This contains the utils methods used by the RichLists
 * 
 * @author Raphael Harmel
 */

class ListBaseUtils extends Utils 
{
	/**
	 * Initializes a rich list model
	 * 
	 * @return
	 */
	public static function createListModel():ListModel
	{
		var list:ListModel = 
		{
			content: new Array<CellModel>()
		};
		
		return list;	
	}
	
}