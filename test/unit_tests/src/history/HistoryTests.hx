/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package historyApi;
//import cocktail.core.history.History;
import js.Lib;
import js.Dom;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;

/**
 * Units tests for history API
 */

class HistoryTests 
{
	public static function main()
	{
		trace("...tests begin...");
		var runner = new Runner();
		runner.addCase(new HistoryTests());
		Report.create(runner);
		runner.run();
	}

	public var history:History;
	
	public function new() 
	{
		// init history
		// history = new History();
		this.history = Lib.window.history;
		trace("history = "+this.history);

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
	/**
	 * test history methods
	 */
	public function testHistoryMethods():Void
	{
		trace("testHistory");
		// Check the length of the history stack
		//Assert.equals(3, history.length);

		// Check the current state
		Assert.equals("page 3", history.state.title);

		_testHistoryBack();
	}
	public function _testHistoryBack():Void
	{
		trace("testHistoryBack");
		// Send the user agent forward
		history.back(); 

		var async = Assert.createAsync(function(){
			trace("test history async");
			Assert.equals("page 2", history.state.title);
			_testHistoryForward();
		}, 1000);
		haxe.Timer.delay(async, 500);

	}
	public function _testHistoryForward():Void
	{
		trace("testHistoryForward");
		// Send the user agent back
		history.forward();

		var async = Assert.createAsync(function(){
			trace("test history async");
			Assert.equals("page 3", history.state.title);
			_testHistoryGoNeg();
		}, 1000);
		haxe.Timer.delay(async, 500);

	}
	public function _testHistoryGoNeg():Void
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
	public function _testHistoryGoPositive():Void
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
	/*
	 * test history events
	 */
	public function testHistoryEvents():Void
	{
		Assert.isTrue(true);
	}
}