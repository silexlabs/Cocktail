package src;
import haxe.Firebug;
import haxe.Http;

/**
 * load and display an html file with cocktail.
 * The url of the html file is provided by flash vars
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
		var testUrl = "";
		var baseUrl = "";
		
		#if flash
		//get html file url
		testUrl = flash.Lib.current.loaderInfo.parameters.testUrl;
		baseUrl = flash.Lib.current.loaderInfo.url;
		
		//get root location of swf
		baseUrl = baseUrl.substr(0, baseUrl.lastIndexOf("/") + 1);
		#end
		
		//use a php proxy to prevent cross-domain issue
		var http:Http = new Http(baseUrl+"proxy.php?url="+testUrl);
		http.onData = function(e) {
			trace(e);
			//js.Lib.document.innerHTML = e;
		}
		
		http.request(false);
	}
	
}