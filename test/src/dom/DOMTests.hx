/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package dom;


import core.HTMLElement;
import core.Text;
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
		testPresCocktail();
	}
	
	function testPresCocktail()
	{
		var container:HTMLElement = cast(Lib.document.createElement("div"));
		
		container.style.position = absolute;
		container.style.bottom = PositionOffset.length(px(0));
		container.style.left = PositionOffset.length(px(250));
		
		container.style.height = Dimension.length(em(25));
		
		//container.style.display = block;
		
		var img = new Image();
		img.src = "testPicture.jpg";
		//img.style.display = block;
		
		img.style.marginTop = Margin.length(px(30));
		//img.style.marginLeft = Margin.length(px(15));
		img.style.paddingBottom = Padding.length(px(50));
		container.appendChild(img);
	
		
		img.style.position = relative;
		img.style.bottom = PositionOffset.length(px(70));
		
		img.onClick = function(e) {
			container.appendChild(Lib.document.createTextNode("hello HaXe !"));
		}
		container.appendChild(Lib.document.createTextNode("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam suscipit nisl ac erat blandit eget dictum erat feugiat. Praesent vitae dolor vitae tellus luctus vulputate non eu neque. Sed vitae tortor dolor. Etiam tempus iaculis pretium. Sed ac est lorem, vel commodo diam. Vestibulum ultricies nisl in risus ultricies facilisis. Ut accumsan ullamcorper elementum. Maecenas tincidunt odio ut risus egestas convallis. Etiam ornare, orci ut viverra vehicula, purus nunc fermentum tellus, at gravida urna purus et tellus. Sed urna nulla, rhoncus a ultricies eget, facilisis vitae lorem. Duis eget nisl nunc. Nullam sit amet enim ac libero suscipit tempor id sed mauris. Pellentesque fermentum elementum nisl quis convallis. Donec vulputate aliquam congue. Vivamus sed arcu eu massa pharetra commodo in vitae purus. Sed nunc leo, consectetur ac fringilla in, mattis semper arcu."));
		
		container.style.wordSpacing = WordSpacing.length(px(5));
		
		//img.style.cssFloat = left;
		
		Lib.document.body.style.backgroundImage = [image(url("testPicture.jpg"))];
		
		container.style.width = Dimension.percent(50);
		container.style.backgroundColor = rgba(255, 0, 0, 0.9);
		container.style.marginRight = container.style.marginLeft = container.style.marginTop = container.style.marginBottom = Margin.cssAuto;
		container.style.paddingLeft = container.style.paddingRight = container.style.paddingTop = container.style.paddingBottom = Padding.length(px(20));
		
		var h1:HTMLElement = cast(Lib.document.createElement("h1"));
		h1.appendChild(Lib.document.createTextNode("title"));
		h1.style.textAlign = TextAlign.center;
		
		Lib.document.body.style.marginLeft = Lib.document.body.style.marginRight = Lib.document.body.style.marginTop = Lib.document.body.style.marginBottom = Margin.length(px(0));
		
		Lib.document.body.appendChild(h1);
		
		
		
		Lib.document.body.appendChild(container);
	}
	
	function testBlockBackground()
	{
		var container:HTMLElement = cast(Lib.document.createElement("div"));
		container.style.width = Dimension.length(px(600));
		container.style.marginLeft = container.style.marginRight = Margin.cssAuto;
		
		Lib.document.body.style.marginLeft = Lib.document.body.style.marginRight = Lib.document.body.style.marginTop = Lib.document.body.style.marginBottom = Margin.length(px(0));
	
		var h1:HTMLElement = cast(Lib.document.createElement("h1"));
		h1.appendChild(Lib.document.createTextNode("Titlej"));
		
		h1.style.paddingTop = Padding.length(px(60));
		
		var h2:HTMLElement = cast(Lib.document.createElement("h2"));
		
		h2.style.paddingTop = Padding.length(px(60));
		
		var h3 = Lib.document.createElement("h3");
		h3.appendChild(Lib.document.createTextNode("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam suscipit nisl ac erat blandit eget dictum erat feugiat. Praesent vitae dolor vitae tellus luctus vulputate non eu neque. Sed vitae tortor dolor. Etiam tempus iaculis pretium. Sed ac est lorem, vel commodo diam. Vestibulum ultricies nisl in risus ultricies facilisis. Ut accumsan ullamcorper elementum. Maecenas tincidunt odio ut risus egestas convallis. Etiam ornare, orci ut viverra vehicula, purus nunc fermentum tellus, at gravida urna purus et tellus. Sed urna nulla, rhoncus a ultricies eget, facilisis vitae lorem. Duis eget nisl nunc. Nullam sit amet enim ac libero suscipit tempor id sed mauris. Pellentesque fermentum elementum nisl quis convallis. Donec vulputate aliquam congue. Vivamus sed arcu eu massa pharetra commodo in vitae purus. Sed nunc leo, consectetur ac fringilla in, mattis semper arcu."));
		
		//container.style.height = Dimension.length(px(50));
		//container.style.marginTop = Margin.length(px(50));
		container.appendChild(h1);
		container.appendChild(h2);
		h2.appendChild(h3);
		
		container.style.backgroundColor = keyword(red);
		
		Lib.document.body.appendChild(container);
	}
	
	function testDOM2()
	{
		var div:HTMLElement = cast(Lib.document.createElement("div"));
		
		var div2 = new HTMLElement("div");
		div2.style.color = rgba(255, 0, 0, 0.5);
		div2.style.fontSize = FontSize.length(px(50));
		div2.appendChild(Lib.document.createTextNode("test text 2 test text 2test text 2 test text 2"));
		div2.style.display = block;
		
		div.appendChild(Lib.document.createTextNode("test text"));
		div.style.display = block;
		
		Lib.document.body.appendChild(div);
		Lib.document.body.appendChild(div2);
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