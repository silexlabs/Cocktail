/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.api;
import haxe.Http;

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
		
		var cocktailView = new CocktailView();
		cocktailView.loadURL(url);
		
		#if (flash || nme)
		flash.Lib.current.addChild(cocktailView.root);
		#end
		
		cocktail.Lib.init(cocktailView.document);
			
		#elseif js
		
		var http:Http = new Http(url);
		http.onData = function(e) js.Lib.document.documentElement.innerHTML = e;
		http.onError = function(e) throw "could not load : " + url;
		http.request(false);
		
		#end
	}
}