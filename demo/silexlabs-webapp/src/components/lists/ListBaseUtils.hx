/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
		var richListModel:ListModel = 
		{
			content: new Array<CellModel>()
		};
		
		return richListModel;	
	}
	
}