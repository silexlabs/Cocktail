package src;

import haxe.Resource;
import haxe.Timer;
import js.Lib;

/**
 * Webapp demoing Cocktail, allow
 * inputing html and css and test rendering
 * in browser and cocktail in flash.
 * 
 * Input use codeMirror text editor : http://codemirror.net/
 * 
 * class is exposed to javascript, so that flash can call method
 * through external interface to signal it is ready
 * 
 * @author Yannick DOMINGUEZ
 */
@:expose("cheers")
class Cheers 
{
	/**
	 * ref to this for static method (a bit
	 * messy, I know)
	 */
	static var self:Cheers;
	
	/**
	 * entry point
	 */
	static function main()
	{
		self = new Cheers();
	}
	
	/**
	 * interval between updates in milliseconds
	 */
	static inline var UPDATE_DELAY:Int = 300;
	
	/**
	 * html editor
	 */
	var htmlCodeMirror:Dynamic;
	
	/**
	 * cs editor
	 */
	var cssCodeMirror:Dynamic;
	
	/**
	 * wether browser and cocktail 
	 * content is already set to be updated
	 */
	var updateScheduled:Bool = false;
	
	/**
	 * constructor
	 */ 
	public function new() 
	{
		
	}
	
	/**
	 * called by flash CocktailBrowser through 
	 * External interface when flash ready
	 */
	static function cocktailBrowserReady()
	{
		self.init();
	}
	
	/**
	 * init code editor and their content, listen
	 * for user input in them
	 */
	function init()
	{
		htmlCodeMirror = untyped __js__("CodeMirror(document.getElementById('html-editor'), {mode:'html'})");
		cssCodeMirror = untyped __js__("CodeMirror(document.getElementById('css-editor'), {mode:'css'})");
		
		htmlCodeMirror.setValue(Resource.getString("html"));
		cssCodeMirror.setValue(Resource.getString("css"));
	
		htmlCodeMirror.on("change", onInput);
		cssCodeMirror.on("change", onInput);
		
		scheduleUpdate();
	}
	
	/**
	 * schedhule an update of html and css
	 * content. Asynchronous to prevent
	 * too much update
	 */
	function scheduleUpdate()
	{
		if (updateScheduled)
			return;
			
		Timer.delay(function() { 
			updateScheduled = false;
			update(); 
			}, UPDATE_DELAY);
			
		updateScheduled = true;	
	}
	
	/**
	 * when user input html or css,
	 * shedule update of document content
	 */
	function onInput(e)
	{
		scheduleUpdate();
	}
	
	/**
	 * get content of html and css 
	 * and update browser and cocktail
	 * rendering with it
	 */
	function update() 
	{
		var object:Dynamic = Lib.document.getElementById("cocktail");	
		object.updateDocument(htmlCodeMirror.getValue(), cssCodeMirror.getValue(), Lib.window.location.href);
		
		//strangely, the easiest way I found to mix html and css content for iframe is
		//using cocktail content
		var iframe:Dynamic = Lib.document.getElementById("browser");
		iframe.src = "data:text/html;charset=utf-8," + object.getContent();
	}
}