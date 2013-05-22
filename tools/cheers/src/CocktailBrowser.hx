package src;
import flash.external.ExternalInterface;
import cocktail.api.CocktailView;
import js.Lib;

/**
 * display html and css with cocktail.
 * html and css is provided via external interface
 * 
 * @author Yannick DOMINGUEZ
 */
class CocktailBrowser 
{
	/**
	 * cocktail view ref
	 */
	static var cv:CocktailView;
	
	static function main()
	{
		//init cocktail view with minimal html
		cv = new CocktailView();
		cv.loadHTML("<!doctype html><html><head></head><body></body></html>");

		flash.Lib.current.addChild(cv.root);
		new CocktailBrowser();
	}
	
	/**
	 * constructor, set external interface callbacks
	 */
	public function new() 
	{
		if (ExternalInterface.available)
		{
			ExternalInterface.addCallback("updateDocument", updateDocument);
			ExternalInterface.addCallback("getContent", getContent);
			
			//signals to the app that ready
			ExternalInterface.call("window.cheers.cocktailBrowserReady");
		}
		else {
			
		}
	}
	
	/**
	 * update the document's html with the html and
	 * css provided by the user
	 */
	function updateDocument(html, css, baseUrl)
	{
		//save html before change
		var currentHTML = getContent();
		
		try {
			cv.document.documentElement.innerHTML = html;
			var header = cv.document.getElementsByTagName("header")[0];
			var style = cv.document.createElement("style");
			style.appendChild(cv.document.createTextNode(css));
			cv.document.body.appendChild(style);
			
			//set base url for iframe so it can load local resource
			var base = cv.document.createElement("base");
			base.setAttribute("href", baseUrl);
			header.appendChild(base);
			
		}
		//html could not be parsed
		catch(e:Dynamic)
		{
			//restore previous html
			cv.document.documentElement.innerHTML = currentHTML;
		}
		
	}
	
	/**
	 * return the serialised content of the document
	 */
	function getContent()
	{
		try {
			return cv.document.documentElement.innerHTML;
		}
		catch (e:Dynamic)
		{
			return "";
		}
	}
}