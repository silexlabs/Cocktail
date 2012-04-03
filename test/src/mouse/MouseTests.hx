/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package mouse;

/**
 * Units tests for mouse events
 * @author Yannick DOMINGUEZ
 */

import core.HTMLElement;
import core.Mouse;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import haxe.Log;
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
		
		var click = "not clicked";
		
		m.onClick = function(e) {
			click = "clicked";
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent("click"));
		#elseif js
		untyped html.nativeElement.click();
		#end
		
		Assert.equals(click, "clicked");
		
		//mouse down 
		
		var mDown = "not mouse down";
		
		m.onMouseDown = function(e) {
			mDown = "mouse down";
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_DOWN));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mousedown", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.equals(mDown, "mouse down");
		
		//mouse over 
		
		var mOver = "not mouse over";
		
		m.onMouseOver = function(e) {
			mOver = "mouse over";
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_OVER));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mouseover", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.equals(mOver, "mouse over");
		
		//mouse up 
		
		var mUp = "not mouse up";
		
		m.onMouseUp = function(e) {
			mUp = "mouse up";
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_UP));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mouseup", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.equals(mUp, "mouse up");
		
		//mouse out 
		
		var mOut = "not mouse out";
		
		m.onMouseOut = function(e) {
			mOut = "mouse out";
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_OUT));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mouseout", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.equals(mOut, "mouse out");
		
		//mouse move 
		
		var mMove = "not mouse move";
		
		m.onMouseMove = function(e) {
			mMove = "mouse move";
		}
		
		#if flash9
		html.nativeElement.dispatchEvent(new flash.events.MouseEvent(flash.events.MouseEvent.MOUSE_MOVE));
		#elseif js
		var e = untyped js.Lib.document.createEvent("MouseEvent");
		e.initEvent("mousemove", false, false);
		untyped html.nativeElement.dispatchEvent(e);
		#end
		
		Assert.equals(mMove, "mouse move");
		
		
	}
	
}