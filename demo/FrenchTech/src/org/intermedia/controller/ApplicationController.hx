/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia.controller;

import haxe.Firebug;
import org.intermedia.model.ApplicationModel;


/**
 * ...
 * @author Raphael Harmel
 */

class ApplicationController 
{

	// Ref to the model
	private var _applicationModel:ApplicationModel;
	
	/**
	 * Store a ref to the application model
	 * @param	applicationModel
	 */
	public function new(applicationModel:ApplicationModel)
	{
		_applicationModel = applicationModel;
	}

	/**
	 * Prompt the model to open the swippableViewContainer when the application is in Detail view
	 * not needed as can be handled directly in the viewmanager
	 */
	/*public function goBackToListView():Void
	{
		
	}*/

	/**
	 * Prompt the model to load more cell data
	 * @param	feed
	 */
	public function loadCellData(feed:String):Void
	{
		_applicationModel.loadCellData(feed);
	}

	/**
	 * Prompt the model to load the detail data matching the provided cell data and to notify the view to open the detail view
	 * @param	cellData
	 */
	public function openDetailView(cellData:CellData):Void
	{
		_applicationModel.loadDetailData(cellData);
	}
	
}