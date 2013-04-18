/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import cocktail.api.CocktailView;
import flash.display.Sprite;
import flash.text.TextField;
import js.Lib;

/**
 * This sample show how to use cocktail as a
 * webview, and how to mix the flash and DOM api
 */
class Main extends Sprite
{
	static function main()
	{
		flash.Lib.current.addChild( new Main() );
	}
	
	/**
	 * cocktail's "web view"
	 */
	var cv:CocktailView;
	
	/**
	 * flash interface's root sprite
	 */
	var mc:Sprite;
	
	var resizeCallbacks : List<Void->Void>;
	public function new()
	{
		super();
		resizeCallbacks = new List();
		addEventListener( flash.events.Event.ADDED_TO_STAGE, onAdded );
	}

	function onAdded(_)
	{

		stage.align = flash.display.StageAlign.TOP_LEFT;
		stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;

		removeEventListener(flash.events.Event.ADDED_TO_STAGE, onAdded);
		stage.addEventListener(flash.events.Event.RESIZE, resize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}

	var inited : Bool;
	function resize(e) 
	{
		//reset();
		if (!inited) init();
		// else (resize or orientation change)
		for( cb in resizeCallbacks )
			cb();
	}

	function init()
	{
		inited = true;
		initFlash();
		initCocktailView();
	}
	
	function registerResizable( cb : Void->Void )
	{
		resizeCallbacks.add( cb );
		return cb;
	}

	/**
	 * build flash interface
	 */
	function initFlash()
	{
		mc = new Sprite();
		
		var txt = new flash.text.TextField();
		txt.width = 200;
		txt.text = "This is a flash Sprite and TextField";
		
		mc.addChild(txt);
		
		var button = new Sprite();
		button.graphics.beginFill(0xDDDDDD, 1.0);
		button.graphics.drawRect(0, 0, 200, 200);
		button.graphics.endFill();
		
		function updateButtonPosition()
		{
			button.x = (stage.stageWidth / 2 - button.width) / 2;
			button.y = stage.stageHeight / 2 - 100;
		}
		registerResizable( updateButtonPosition )();

		mc.addChild(button);
		
		var label = new TextField();
		label.text = "Click to show/hide cocktail view";
		label.width = 200;
		button.addChild(label);
		
		button.addEventListener(flash.events.MouseEvent.CLICK, onFlashClick);
		
		flash.Lib.current.addChild(mc);
	}
	
	/**
	 * toggle cocktail view visibility
	 */
	function onFlashClick(e)
	{
		cv.root.visible = !cv.root.visible;
	}
	
	/**
	 * build cocktail interface
	 */
	function initCocktailView()
	{
		//build a cocktail webview
		cv = new CocktailView();
		
		function updateViewportPosition()
		{
			//place the webview in the flash/NME app
			cv.viewport = { 
				x:Std.int(stage.stageWidth / 2),
				y:0,
				width:Std.int(stage.stageWidth / 2),
				height:stage.stageHeight
				};
		}
		registerResizable( updateViewportPosition )();
		
		//use an external html for the document
		cv.loadURL("index.html");
		
		//wait for document ready
		cv.window.onload = function(e) { 
			
			var document = cv.document;
			
			//access to DOM
			var button = document.getElementById("button");
			button.onclick = function(e) {
				//toggle flash interface visibility
				mc.visible = !mc.visible;
			}
			
			//attach cocktail root to native flash root
			flash.Lib.current.addChild(cv.root);
		};
	}
}
