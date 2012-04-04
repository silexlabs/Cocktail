/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package html;

import cocktail.Dom;
import cocktail.Lib;

import utest.Assert;
import utest.Runner;
import utest.ui.Report;

class HTMLTests 
{
	
	public static function main()
	{	
		var runner = new Runner();
		runner.addCase(new HTMLTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	function testHTMLElement()
	{
		var htmlEl = new HTMLElement("div");
		Lib.document.body.appendChild(htmlEl);
		
		htmlEl.style.width = "50px";
		
		Assert.equals(htmlEl.clientWidth, 50);
		Assert.equals(htmlEl.offsetWidth, 50);
		
		htmlEl.style.paddingLeft = "50px";
		
		Assert.equals(htmlEl.clientWidth, 100);
		Assert.equals(htmlEl.offsetWidth, 100);
		
		htmlEl.style.paddingRight = "50px";
		
		Assert.equals(htmlEl.offsetWidth, 150);
		Assert.equals(htmlEl.clientWidth, 150);
		
		htmlEl.style.height = "50px";
		
		Assert.equals(htmlEl.clientHeight, 50);
		Assert.equals(htmlEl.offsetHeight, 50);
		
		htmlEl.style.paddingTop = "50px";
		
		Assert.equals(htmlEl.clientHeight, 100);
		Assert.equals(htmlEl.offsetHeight, 100);
		
		htmlEl.style.paddingBottom = "50px";
		
		Assert.equals(htmlEl.clientHeight, 150);
		Assert.equals(htmlEl.offsetHeight, 150);
		
		Assert.equals(htmlEl.offsetParent, Lib.document.body);
		
		Assert.equals(htmlEl.clientTop, 0);
		Assert.equals(htmlEl.clientLeft,0);
		Assert.equals(htmlEl.offsetTop, 8);
		Assert.equals(htmlEl.offsetLeft, 8);
		
		htmlEl.id = "myId";
		
		Assert.equals(htmlEl.id, "myId");
		
	}
	
	function testHTMLImageElement()
	{
		var img = new Image();
	}
}