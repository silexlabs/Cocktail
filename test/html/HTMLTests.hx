/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package ;

import cocktail.core.html.HTMLElement;
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
		var htmlEl = Lib.document.createElement("div");
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