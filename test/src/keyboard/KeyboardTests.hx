/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
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