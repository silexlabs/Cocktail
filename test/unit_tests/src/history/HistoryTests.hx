/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package history;
import cocktail.core.history.History;

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
		var runner = new Runner();
		runner.addCase(new HistoryTests());
		Report.create(runner);
		runner.run();
	}

	public var history:History;
	
	public function new() 
	{
		// init history
		history = new History();
		var stateObj = { 
			title : "page 1", 
			url : "page1.html" 
		};
		history.pushState(stateObj, "page 1", "page1.html");
		var stateObj = { 
			title : "page 2", 
			url : "page2.html" 
		};
		history.pushState(stateObj, "page 2", "page1.html");
		var stateObj = { 
			title : "page 3", 
			url : "page3.html" 
		};
		history.pushState(stateObj, "page 3", "page1.html");
	}
	
	/**
	 * test history methods
	 */
	public function testHistoryMethods():Void
	{
		// Check the length of the history stack
		Assert.equals(3, history.length);

		// Check the current state
		Assert.equals("page 1", history.state.title);

		// Send the user agent forward
		history.forward(); 

		// Check the current state
		Assert.equals("page 2", history.state.title);

		// Send the user agent back
		history.back();

		// Check the current state
		Assert.equals("page 1", history.state.title);

		// Send the user agent back (negative) or forward (positive)
		// by a given number of items
		history.go(2);

		// Check the current state
		Assert.equals("page 3", history.state.title);

		// Send the user agent back (negative) or forward (positive)
		// by a given number of items
		history.go(-2);

		// Check the current state
		Assert.equals("page 1", history.state.title);

	}
	/**
	 * test history events
	 */
	public function testHistoryEvents():Void
	{
	}
}