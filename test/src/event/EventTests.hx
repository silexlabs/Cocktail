/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package event;

import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.EventListener;
import cocktail.core.event.EventTarget;
import cocktail.core.event.MouseEvent;
import cocktail.Lib;
import cocktail.Dom;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class EventTests 
{
	
	public static function main()
	{	
		var runner = new Runner();
		runner.addCase(new EventTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	function testEvent()
	{
		var evt:Event = untyped Lib.document.createEvent("Event");
		untyped evt.initEvent("scroll", false, false);
		
		Assert.equals(evt.type, "scroll");
		Assert.isFalse(untyped evt.bubbles);
		Assert.isFalse(untyped evt.cancelable);
	}
	
	function testMouseEvent()
	{

		var evt:MouseEvent = cast(Lib.document.createEvent("MouseEvent"));
		evt.initMouseEvent("click", true, true, null, 1.0, 2.0, 3.0, 4.0, 5.0, false, false, false, false, 0, null);
		
		Assert.equals(evt.type, "click");
		Assert.isTrue(evt.bubbles);
		Assert.isTrue(evt.cancelable);
		Assert.equals(evt.detail, 1.0);
		Assert.equals(evt.screenX, 2.0);
		Assert.equals(evt.screenY, 3.0);
		Assert.equals(evt.clientX, 4.0);
		Assert.equals(evt.clientY, 5.0);
		Assert.isFalse(evt.ctrlKey);
		Assert.isFalse(evt.shiftKey);
		Assert.isFalse(evt.altKey);	
	}
	
	function testEventListener()
	{
		var test = false;
		var eventListener = new EventListener("test", function(e) { test = true; }, true);
		
		Assert.isTrue(eventListener.useCapture);
		Assert.equals(eventListener.eventType, "test");
		
		eventListener.handleEvent(new Event() );
		
		Assert.isTrue(test);
	}
	
	function testEventTarget()
	{
		var test = 0;
		
		var et = new EventTarget();
		
		var func = function(e) { test++; };
		
		et.addEventListener("test",func );
		var evt = new Event();
		evt.initEvent("test", true, true);
		et.dispatchEvent(evt);
		
		Assert.equals(test, 1);
		
		et.removeEventListener("test", func);
		
		var evt = new Event();
		evt.initEvent("test", true, true);
		et.dispatchEvent(evt);
		
		Assert.equals(test, 1);
		
	}
	
	function testBubbling()
	{
		var node = new Node();
		
		var parentNode = new Node();
		
		parentNode.appendChild(node);
		
		var test = 0;
		
		parentNode.addEventListener("test", function(e) { test++; } );
		
		var evt = new Event();
		evt.initEvent("test", true, true);
		node.dispatchEvent(evt);
		
		Assert.equals(test, 1);
		
		var evt = new Event();
		evt.initEvent("test", false, true);
		node.dispatchEvent(evt);
		
		Assert.equals(test, 1);
	}
	
	function testCapture()
	{
		var node = new Node();
		
		var parentNode = new Node();
		
		parentNode.appendChild(node);
		
		var test = 0;
		
		parentNode.addEventListener("test", function(e) { test++; }, true );
		
		var evt = new Event();
		evt.initEvent("test", false, true);
		node.dispatchEvent(evt);
		
		Assert.equals(test, 1);
	}
	
	function testStopPropagation()
	{
		var node = new Node();
		
		var parentNode = new Node();
		
		parentNode.appendChild(node);
		
		var test = 0;
		
		node.addEventListener("test", function(e) { e.stopPropagation() ; } );
		parentNode.addEventListener("test", function(e) { test++; });
		
		var evt = new Event();
		evt.initEvent("test", true, true);
		node.dispatchEvent(evt);
		
		Assert.equals(test, 0);
	}
	
	function testStopImmediatePropagation()
	{
		var node = new Node();
	
		var test = 0;
		
		node.addEventListener("test", function(e) { e.stopImmediatePropagation() ;} );
		node.addEventListener("test", function(e) { test++; });
		
		var evt = new Event();
		evt.initEvent("test", true, true);
		node.dispatchEvent(evt);
		
		Assert.equals(test, 0);
	}
	
	function testPreventDefault()
	{
		var node = new Node();
	
		node.addEventListener("test", function(e) { e.preventDefault(); } );
		var evt = new Event();
		evt.initEvent("test", true, true);
		
		Assert.isTrue(node.dispatchEvent(evt));
	}
}