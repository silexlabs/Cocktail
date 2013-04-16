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
		#if (flash || nme)
		
		//use a cocktail view
		var cocktailView = new CocktailView();
		//load the html document
		cocktailView.loadURL(url);
		
		//for flash and NME, attach to stage
		flash.Lib.current.addChild(cocktailView.root);
		
		//set static reference to the document and window,
		//so that they can be accessed with cocktail.Lib.document
		//and cocktail.Lib.window
		cocktail.Lib.init(cocktailView.document);
			
		//for js, load and set the document so that it matches the flash
		//and NME application
		#elseif js
		var http:haxe.Http = new haxe.Http(url);
		http.onData = function(e) js.Lib.document.documentElement.innerHTML = e;
		http.onError = function(e) throw "could not load : " + url;
		http.request(false);
		#end
	}
}