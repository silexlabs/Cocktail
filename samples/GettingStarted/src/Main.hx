/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import haxe.Http;
import js.Lib;
import js.Dom;

/**
 * Getting Started with cocktail
 * 
 * @author	Raphael Harmel
 * @date	2012-08-13
 */
class Main
{
	/**
	 * Constructor
	 */
	public function new()
	{

		// get the image node
		var image:Image = cast Lib.document.getElementById("icon");
		
		// create interactivity
		image.onmousedown = onMouseDown;
		image.onmouseup = onMouseUp;
	}
	
	/**
	 * Creates a centered div container and attach it to the body
	 * @return container
	 */
	public static function createContainer():HtmlDom
	{
		// create a container to gather all of our visual elements
		var container = Lib.document.createElement("div");
		
		// apply styles to the container
		container.style.st = container.style.marginRight = "auto";
		container.style.width = "150px";
		container.style.textAlign = "center";
		
		// create a reference to the body
		var body = Lib.document.body;
		
		//attach the container to the body
		body.appendChild(container);
		
		return container;
	}
	
	/**
	 * Mouse Down callback. Changes the image to be displayed.
	 * @param	event
	 */
	public static function onMouseDown(event:Event):Void
	{
		var image:Image = cast(event.target);
		image.src = "assets/icone_haxe_blanche_ombre.png";
	}
	
	/**
	 * Mouse Up callback. Resets the image to be displayed and loads the dynamic data.
	 * @param	event
	 */
	public static function onMouseUp(event:Event):Void
	{
		var image:Image = cast(event.target);
		image.src = "assets/icone_cocktail_blanche_ombre.png";
		
		try {
			// calls the http request
			var request:Http = new Http("assets/feed.txt");
			// sets the callbacks
			request.onData = onData;
			request.onError = onError;
			// closes the http request
			request.request(false);
		}
		catch (error:Dynamic) {
			onError(error);
		}
	}
	
	/**
	 * Http request success callback. Attach the external file content to the stage using a centered container.
	 * @param	string
	 */
	public static function onData(string:String):Void
	{
		// create a container and attch it to the body
		var container = createContainer();
		// create a text node to display the content of the file
		var text = Lib.document.createTextNode(string);
		// attach the text node to the container
		container.appendChild(text);
	}
	
	/**
	 * Http request error callback. Displays an error message.
	 * @param	string
	 */
	public static function onError(msg:Dynamic):Void
	{
		trace("there was an error while loading the external data");
	}
	
}