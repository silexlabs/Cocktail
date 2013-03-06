/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package;

import cocktail.core.focus.FocusManager;
import cocktail.Dom;
import cocktail.Lib;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class FocusTests 
{
	
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new FocusTests());
		Report.create(runner);
		runner.run();
		new FocusTests();
	}
	
	public function new() 
	{
	
	}
	
	public function testFocus()
	{
		var link:Anchor = cast(Lib.document.createElement("a"));
		link.href = "fakeUrl.html";
		
		Lib.document.body.appendChild(link);
		
		var fm = new FocusManager();
	
		var nextFocusedElement = fm.getNextFocusedElement(false, Lib.document.body, Lib.document.body);
		Assert.equals(nextFocusedElement, link);
		
		nextFocusedElement = fm.getNextFocusedElement(false, Lib.document.body, link);
		Assert.equals(nextFocusedElement, link);
		
		var div = Lib.document.createElement("div");
		div.tabIndex = 50;
		
		Lib.document.body.appendChild(div);
		
		nextFocusedElement = fm.getNextFocusedElement(false, Lib.document.body, link);
		Assert.equals(nextFocusedElement, div);
		
		nextFocusedElement = fm.getNextFocusedElement(false, Lib.document.body, div);
		Assert.equals(nextFocusedElement, link);
		
		nextFocusedElement = fm.getNextFocusedElement(true, Lib.document.body, link);
		Assert.equals(nextFocusedElement, div);
		
	}
}
