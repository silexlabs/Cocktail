/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package;
import js.Lib;
import js.Dom;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;

/**
 * Units tests for history API
 * I have named the package historyApi instead of history because it used to have side effects in firefox js
 * TODO:
 * - test History::resolveUrl - ie use a url in the state passed to pushState
 */

class HistoryTests 
{
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new HistoryTests());
		Report.create(runner);
		runner.run();
	}

	public var history:History;
	
	//////////////////////////////////////////////////////////////////////////
	public function new() 
	{
	}
	/**
	 * init history for a new test, called before all sery of tests
	 */
	public function initHistory() 
	{
		// init history
		history = Lib.window.history;
		if (history == null){
			throw("this browser does not support history api");
		}

		var stateObj = { 
			title : "page 1", 
			url : "?page1.html",
		};
		history.pushState(stateObj, "page 1", "?page1.html");
		var stateObj = { 
			title : "page 2", 
			url : "?page2.html",
		};
		history.pushState(stateObj, "page 2", "?page2.html");
		var stateObj = { 
			title : "page 3", 
			url : "?page3.html",
		};
		history.pushState(stateObj, "page 3", "?page3.html");
	}
	//////////////////////////////////////////////////////////////////////////
	/**
	 * test history methods
	 */
	public function testHistoryMethods():Void
	{
		trace("testHistory");
		// reset history
		initHistory();

		// Check the length of the history stack
		//Assert.equals(3, history.length);

		// Check the current state
		Assert.equals("page 3", history.state.title);

		_testHistoryBack();
	}
	private function _testHistoryBack():Void
	{
		trace("testHistoryBack");
		// Send the user agent back
		history.back(); 

		var async = Assert.createAsync(function(){
			trace("test history async");
			Assert.equals("page 2", history.state.title);
			_testHistoryForward();
		}, 1000);
		haxe.Timer.delay(async, 500);

	}
	private function _testHistoryForward():Void
	{
		trace("testHistoryForward");
		// Send the user agent forward
		history.forward();

		var async = Assert.createAsync(function(){
			trace("test history async");
			Assert.equals("page 3", history.state.title);
			_testHistoryGoNeg();
		}, 1000);
		haxe.Timer.delay(async, 500);

	}
	private function _testHistoryGoNeg():Void
	{
		trace("testHistoryGoNeg");
		// Send the user agent back (negative) or forward (positive)
		// by a given number of items
		history.go(-2);

		var async = Assert.createAsync(function(){
			trace("test history async");
			Assert.equals("page 1", history.state.title);
			_testHistoryGoPositive();
		}, 1000);
		haxe.Timer.delay(async, 500);

	}
	private function _testHistoryGoPositive():Void
	{
		trace("testHistoryGoPositive");
		// Send the user agent back (negative) or forward (positive)
		// by a given number of items
		history.go(2);

		var async = Assert.createAsync(function(){
			trace("test history async");
			Assert.equals("page 3", history.state.title);
		}, 1000);
		haxe.Timer.delay(async, 500);
	}
	//////////////////////////////////////////////////////////////////////////
	/*
	 * test history events
	 */
	public function testHistoryEvents():Void
	{
		trace("testHistoryEvents");
		// reset history
		initHistory();

		_testHistoryAddEventListener();
	}
	/**
	 * store a reference to the ongoing callback 
	 */
	private var async:Event->Void;
	private function _testHistoryAddEventListener():Void
	{
		trace("_testHistoryAddEventListener");
		// create callback
		async = Assert.createEvent(cast(_callbackHistoryAddEventListener), 1000);

		// attach listener
		Lib.window.addEventListener("popstate", async, true);

		// Send the user agent back
		history.back(); 
	}
	private function _callbackHistoryAddEventListener(e:Event){
		trace("test history async");
		// get the typed event object
		var event:PopStateEvent = cast(e);
		// check the state
		Assert.equals("page 2", event.state.title);
		// remove listener
		Lib.window.removeEventListener("popstate", async, true);
		async = null;
		// continue the test
		_testHistoryCallback();
	}
	private function _testHistoryCallback():Void
	{
		trace("_testHistoryCallback");

		// create callback
		var async = Assert.createEvent(_callbackHistoryCallback, 1000);

		// attach listener
		Lib.window.onpopstate = async;

		// Send the user agent forward
		history.forward();
	}
	private function _callbackHistoryCallback(e:Event){
		trace("test history async");
		// get the typed event object
		var event:PopStateEvent = cast(e);
		// check the state
		Assert.equals("page 3", event.state.title);
		// remove listener
		Lib.window.onpopstate= null;
		// continue the test
		// ??
	}
}