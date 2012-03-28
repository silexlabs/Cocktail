/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package dom.test.nme;


import haxe.Log;
//
//import core.HTMLElement;
//import core.html.HTMLBodyElement;
//import core.html.HTMLImageElement;
//import core.HTMLAnchorElement;
//import core.html.HTMLCanvasElement;
//import core.html.HTMLDocument;
//import core.Text;
//import core.HTMLInputElement;
//import core.style.StyleData;
//import core.unit.UnitData;
//import core.resource.XMLHTTPRequest;

import cocktail.Cocktail;
import cocktail.Lib;

class DOMTests 
{
	
	public static function main()
	{	
		/**var runner = new Runner();
		runner.addCase(new DOMTests());
		Report.create(runner);
		runner.run();*/
		new DOMTests();
	}
	
	public function new() 
	{
		testDOM();
	}
	
	public function testDOM()
	{
		var document = Lib.document;
		var img:Image = new Image();
		img.src = "testPicture.jpg";
		//img.style.floatStyle = FloatStyle.left;
		
		var container:HTMLElement = cast(document.createElement("li"));
		container.appendChild(img);
		container.style.display = Display.block;
		
		container.onMouseDown = function(e) {
			Log.trace("bim");
		}
		
		var text = document.createTextNode("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam suscipit nisl ac erat blandit eget dictum erat feugiat. Praesent vitae dolor vitae tellus luctus vulputate non eu neque. Sed vitae tortor dolor. Etiam tempus iaculis pretium. Sed ac est lorem, vel commodo diam. Vestibulum ultricies nisl in risus ultricies facilisis. Ut accumsan ullamcorper elementum. Maecenas tincidunt odio ut risus egestas convallis. Etiam ornare, orci ut viverra vehicula, purus nunc fermentum tellus, at gravida urna purus et tellus. Sed urna nulla, rhoncus a ultricies eget, facilisis vitae lorem. Duis eget nisl nunc. Nullam sit amet enim ac libero suscipit tempor id sed mauris. Pellentesque fermentum elementum nisl quis convallis. Donec vulputate aliquam congue. Vivamus sed arcu eu massa pharetra commodo in vitae purus. Sed nunc leo, consectetur ac fringilla in, mattis semper arcu.");

		container.appendChild(text);
		
		container.style.width = Dimension.length(px(150));
		container.style.marginLeft = Margin.cssAuto;
		container.style.marginRight = Margin.cssAuto;
		
		document.body.style.backgroundImage = [BackgroundImage.image(ImageValue.url("testPicture.jpg"))];
		
		
		
		container.style.backgroundColor = BackgroundColor.keyword(ColorKeyword.fuchsia);
		
		document.body.appendChild(container);
		
	}
	
	public function testXMLHTTPRequest()
	{
		var xhr = new XMLHTTPRequest();
		
		xhr.onReadyStateChange = function(e) {
			if (xhr.readyState == 4 && xhr.status == 200)
			{
				Log.trace(xhr.responseText);
			}
		}
		
		xhr.open("GET", "test_load.txt");
		
		xhr.send();
	}
	
	public function testLib()
	{
		
		Log.trace(Lib.document);
	}
}