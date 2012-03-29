package org.intermedia;

import cocktail.domElement.ImageDOMElement;
import cocktail.textElement.TextElement;
import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.textElement.TextElement;
// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

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
		body.style.width = DimensionStyleValue.percent(100);
		body.style.height = DimensionStyleValue.percent(100);
		
		var textContainer:ContainerDOMElement = new ContainerDOMElement();
		body.addChild(textContainer);
		textContainer.style.position = PositionStyleValue.absolute;
		textContainer.style.left = PositionOffsetStyleValue.length(px(200));
		textContainer.style.top = PositionOffsetStyleValue.length(px(80));
		textContainer.style.width = DimensionStyleValue.percent(100);
		textContainer.style.height = DimensionStyleValue.percent(100);
		//HeaderStyle.setHeaderTextStyle(textContainer);
		var textElement:TextElement = new TextElement("ola !");
		textContainer.addText(textElement);
		
		var image:ImageDOMElement = new ImageDOMElement();
		body.addChild(image);
		image.style.position = PositionStyleValue.absolute;
		image.style.left = PositionOffsetStyleValue.length(px(100));
		image.style.top = PositionOffsetStyleValue.length(px(100));
		image.style.width = DimensionStyleValue.length(px(320));
		image.style.height = DimensionStyleValue.length(px(180));
		image.load("assets/200-156_purple.png");*/
		
		
		// instantiate model
		var applicationModel:ApplicationModel = new ApplicationModel();
		//applicationModel.loadCellData(5);
		
		// instantiate controller
		var applicationController:ApplicationController = new ApplicationController(applicationModel);
		
		// instanciate view
		var view:ViewManager = new ViewManager(applicationModel, applicationController);
	}
	
}