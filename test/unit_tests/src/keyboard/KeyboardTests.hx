/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package keyboard;

/**
 * Units tests for keyboard events
 * @author Yannick DOMINGUEZ
 */
import cocktail.core.HTMLElement;
import cocktail.core.Keyboard;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;


class KeyboardTests 
{
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new KeyboardTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	public function testKeyboard()
	{
		var html = new HTMLElement("div");
		var k = new Keyboard(html);
		
		//key down
		
		var down = false;
		
		k.onKeyDown = function(e) {
			down = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.KeyboardEvent(flash.events.KeyboardEvent.KEY_DOWN));
		#elseif js
		var e = untyped js.Lib.document.createEvent("KeyboardEvent");
		e.initEvent("keydown", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(down);
		
		//key up
		
		var up = false;
		
		k.onKeyUp = function(e) {
			up = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.KeyboardEvent(flash.events.KeyboardEvent.KEY_UP));
		#elseif js
		var e = untyped js.Lib.document.createEvent("KeyboardEvent");
		e.initEvent("keyup", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(up);
		
		
	}

	
}