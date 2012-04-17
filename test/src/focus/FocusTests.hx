/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package focus;

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
