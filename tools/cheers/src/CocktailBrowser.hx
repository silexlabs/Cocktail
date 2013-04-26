package src;
import flash.external.ExternalInterface;
import js.Lib;

/**
 * display html and css with cocktail.
 * html and css is provided via external interface
 * 
 * @author Yannick DOMINGUEZ
 */
class CocktailBrowser 
{

	static function main()
	{
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
		Lib.document.documentElement.innerHTML = html;
	}
}