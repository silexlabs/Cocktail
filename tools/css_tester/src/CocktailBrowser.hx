package src;
import haxe.Firebug;
import haxe.Http;

/**
 * display an html string with cocktail.
 * The html string is provided by flash vars
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
		js.Lib.document.innerHTML = flash.Lib.current.loaderInfo.parameters.html;
	}
	
}