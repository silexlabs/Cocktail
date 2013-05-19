package src;
import cocktail.api.Cocktail;
import cocktail.api.CocktailView;

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
		//init a cocktail document
		var cocktailView = new CocktailView();
		cocktailView.loadHTML("<html><head></head><body></body></html>");
		flash.Lib.current.addChild(cocktailView.root);
		cocktail.Lib.init(cocktailView.document);
		
		flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		
		new CocktailBrowser();
	}
	
	public function new() 
	{
		js.Lib.document.innerHTML = flash.Lib.current.loaderInfo.parameters.html;
	}
}