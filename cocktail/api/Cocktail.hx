/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.api;

/**
 * This class provides an easy, one step way of
 * creating a cocktail application.
 * 
 * Use it when you're creating a full cocktail application,
 * where cocktail is not meant to be embedded like a web view.
 * 
 * This class will create a cocktail application taking the full 
 * available space of the window or browser tab containing it.
 * 
 * It is compatible with flash/air and NME. 
 * 
 * @author Yannick DOMINGUEZ
 */
class Cocktail
{
	/**
	 * initialise a cocktail application with 
	 * the provided url
	 */
	public static function boot(url:String = "index.html")
	{
		//use a cocktail view
		var cocktailView = new CocktailView();
		//load the html document
		cocktailView.loadURL(url);
		
		#if (flash || nme)
		//for flash and NME, attach to stage
		flash.Lib.current.addChild(cocktailView.root);
		#end
		
		//set static reference to the document and window,
		//so that they can be accessed with cocktail.Browser.document
		//and cocktail.Browser.window
		cocktail.Browser.init(cocktailView.document);
	}
}