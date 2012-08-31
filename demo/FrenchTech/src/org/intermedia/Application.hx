/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia;

//import core.HTMLImageElement;
//import cocktail.textElement.TextElement; => dom.Text
//import cocktail.node.BodyDOMElement;
//import cocktail.node.HtmlDom;
//import cocktail.textElement.TextElement;
// Style
//import cocktail.style.StyleData; => cocktail.core.style.StyleData
//import cocktail.unit.UnitData; => 

//import cocktail.Cocktail;

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
		// only for nme compilation tests
		/*var body:BodyDOMElement = new BodyDOMElement();
		body.style.width = "100%";
		body.style.height = "100%";
		
		var textContainer:HtmlDom = Lib.document.createElement("div");
		body.appendChild(textContainer);
		textContainer.style.position = "absolute";
		textContainer.style.left = Std.string(200));
		textContainer.style.top = Std.string(80));
		textContainer.style.width = "100%";
		textContainer.style.height = "100%";
		//HeaderStyle.setHeaderTextStyle(textContainer);
		var textElement:HtmlDom = Lib.document.createTextNode("ola !");
		textContainer.appendChild(textElement);
		
		var image:HtmlDom = Lib.document.createElement("div");
		body.appendChild(image);
		image.style.position = "absolute";
		image.style.left = Std.string(100));
		image.style.top = Std.string(100));
		image.style.width = Std.string(320));
		image.style.height = Std.string(180));
		image.src("assets/200-156_purple.png");*/
		
		
		// instantiate model
		var applicationModel:ApplicationModel = new ApplicationModel();
		//applicationModel.srcCellData(5);
		
		// instantiate controller
		var applicationController:ApplicationController = new ApplicationController(applicationModel);
		
		// instanciate view
		var view:ViewManager = new ViewManager(applicationModel, applicationController);
	}
	
}