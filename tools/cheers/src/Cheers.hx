package src;

import haxe.Timer;
import js.Lib;

/**
 * Webapp demoing Cocktail, allow
 * inputing html and css and test rendering
 * in browser and cocktail.
 * 
 * Input use codeMirror text editor : http://codemirror.net/
 * 
 * @author Yannick DOMINGUEZ
 */
class Cheers 
{
	/**
	 * entry point
	 */
	static function main()
	{
		new Cheers();
	}
	
	/**
	 * interval between updates in milliseconds
	 */
	static inline var UPDATE_DELAY:Int = 3000;
	
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
	var updateScheduled:Bool;
	
	public function new() 
	{
		updateScheduled = false;
		
		js.Lib.window.onload = function(e) {	
			init();
		}
	}
	
	/**
	 * init code editor and their content, listen
	 * for user input in them
	 */
	function init()
	{
		htmlCodeMirror = untyped __js__("CodeMirror(document.getElementById('html-editor'), {mode:'html'})");
		cssCodeMirror = untyped __js__("CodeMirror(document.getElementById('css-editor'), {mode:'css'})");
		
		htmlCodeMirror.setValue("<html><head></head><body>ssssssssssssss</body></html>");
		cssCodeMirror.setValue("bim");
		
		update();
		
		htmlCodeMirror.on("change", onInput);
		cssCodeMirror.on("change", onInput);
	}
	
	/**
	 * when user input html or css,
	 * shedule update of document content
	 */
	function onInput(e)
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
	 * get content of html and css 
	 * and update browser and cocktail
	 * rendering with it
	 */
	function update() 
	{
		var style:Dynamic = Lib.document.createElement("style");
		style.type = "text/css";
		style.innerHTML = cssCodeMirror.getValue();
		
		var iframe:Dynamic = Lib.document.getElementById("browser");
		iframe.src = "data:text/html;charset=utf-8," + htmlCodeMirror.getValue();
		iframe.contentDocument.head.appendChild(style);
		trace(iframe);
		var object:Dynamic = Lib.document.getElementById("cocktail");
		trace(object);
		//object.updateDocument(htmlCodeMirror.getValue(), cssCodeMirror.getValue());
		
	}
}