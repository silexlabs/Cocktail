package src;

import haxe.Timer;
import js.Lib;

/**
 * Webapp demoing Cocktail, allow
 * inputing html and css and test rendering
 * in browser and cocktail in flash.
 * 
 * Input use codeMirror text editor : http://codemirror.net/
 * 
 * @author Yannick DOMINGUEZ
 */
@:expose("cheers")
class Cheers 
{
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
	static inline var UPDATE_DELAY:Int = 1000;
	
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
		
		htmlCodeMirror.setValue("<!doctype html><html><head></head><body>ssssssssssssss</body></html>");
		cssCodeMirror.setValue("body {margin:0;}");
	
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
		object.updateDocument(htmlCodeMirror.getValue(), cssCodeMirror.getValue());
		
		//strangely, the easiest way I found to mix html and css content for iframe is
		//using cocktail content
		var iframe:Dynamic = Lib.document.getElementById("browser");
		iframe.src = "data:text/html;charset=utf-8," + object.getContent();
	}
}