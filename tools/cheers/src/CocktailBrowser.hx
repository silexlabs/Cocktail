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
	static var cv:CocktailView;
	
	static function main()
	{
		cv = new CocktailView();
		cv.loadHTML("<!doctype html><html><head></head><body></body></html>");

		flash.Lib.current.addChild(cv.root);
		new CocktailBrowser();
	}
	
	public function new() 
	{
		if (ExternalInterface.available)
		{
			ExternalInterface.addCallback("updateDocument", updateDocument);
		}
	}
	
	function updateDocument(html, css)
	{
		try {
			cv.document.documentElement.innerHTML = html;
			var style = cv.document.createElement("style");
			style.appendChild(cv.document.createTextNode(css));
			cv.document.body.appendChild(style);
			
		}
		//html could not be parsed
		catch(e:Dynamic)
		{
			
		}
		
	}
}