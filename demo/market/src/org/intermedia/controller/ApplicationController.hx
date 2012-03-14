package org.intermedia.controller;

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
	 * @param	numberOfCellsToLoad
	 */
	public function loadCellData(numberOfCellsToLoad):Void
	{
		_applicationModel.loadCellData(numberOfCellsToLoad);
	}

	/**
	 * Prompt the model to load the detail data matching the provided cell data and to notify the view to open the detail view
	 * @param	cellData
	 */
	public function openDetailView(cellData):Void
	{
		//trace(cellData);
		_applicationModel.loadDetailData(cellData);
	}
	
}