/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package mouse;

/**
 * Units tests for mouse events
 * @author Yannick DOMINGUEZ
 */

import cocktail.core.HTMLElement;
import cocktail.core.Mouse;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;
class MouseTests 
{
	
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new MouseTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	function testMouse()
	{
		
		var html = new HTMLElement("div");
		var m = new Mouse(html);
		
		//click
		
		var clicked = false;
		
		m.onClick = function(e) {
			clicked = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent("click"));
		#elseif js
		untyped html.nativeElement.click();
		#end
		
		Assert.isTrue(clicked);
		
		//mouse down 
		
		var mDown = false;
		
		m.onMouseDown = function(e) {
			mDown = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_DOWN));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mousedown", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(mDown);
		
		//mouse over 
		
		var mOver = false;
		
		m.onMouseOver = function(e) {
			mOver = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_OVER));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mouseover", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(mOver);
		
		//mouse up 
		
		var mUp = false;
		
		m.onMouseUp = function(e) {
			mUp = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_UP));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mouseup", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(mUp);
		
		//mouse out 
		
		var mOut = false;
		
		m.onMouseOut = function(e) {
			mOut = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_OUT));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mouseout", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(mOut);
		
		//mouse move 
		
		var mMove = false;
		
		m.onMouseMove = function(e) {
			mMove = true;
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_MOVE));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mousemove", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.isTrue(mMove);
		
		
	}
	
}