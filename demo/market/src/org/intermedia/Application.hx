package org.intermedia;

import org.intermedia.model.ApplicationModel;
import org.intermedia.controller.ApplicationController;
import org.intermedia.view.ViewManager;

/**
 * Entry point, instantiate the view, model and controller.
 * 
 * @author Raphael Harmel
 */

class Application 
{

	// application entry point
	public static function main()
	{
		new Application();
	}
	
	public function new() 
	{
		// instantiate model
		var applicationModel:ApplicationModel = new ApplicationModel();
		//applicationModel.loadCellData(5);
		
		// instantiate controller
		var applicationController:ApplicationController = new ApplicationController(applicationModel);
		
		// instanciate view
		var view:ViewManager = new ViewManager(applicationModel, applicationController);
	}
	
}