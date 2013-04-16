/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import cocktail.api.Cocktail;
import cocktail.api.CocktailView;
import flash.display.Sprite;
import js.Lib;

class Main
{
	static function main()
	{
		new Main();
	}
	
	public function new()
	{
		initFlash();
		initCocktailView();
	}
	
	function initFlash()
	{
		var mc = new Sprite();
		mc.graphics.beginFill(0xDDDDDD, 1.0);
		mc.graphics.drawRect(0, 0, 200, 200);
		mc.graphics.endFill();
		
		var txt = new flash.text.TextField();
		txt.width = 200;
		txt.text = "This is a flash Sprite and TextField";
		
		mc.addChild(txt);
		
		flash.Lib.current.addChild(mc);
	}
	
	function initCocktailView()
	{
		var cv = new CocktailView();
		cv.viewport = { x:200, y:0, width:200, height:200 };
		cv.loadURL("index.html");
		flash.Lib.current.addChild(cv.root);
	}
}
