/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package dom.test.bim;
import cocktail.Lib;
import cocktail.Cocktail;



class DOMTests 
{
	
	public static function main()
	{	
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
		//img.src = "testPicture.jpg";
		//img.style.display = block;
		
		img.style.marginTop = Margin.length(px(30));
		//img.style.marginLeft = Margin.length(px(15));
		img.style.paddingBottom = Padding.length(px(50));
		//container.appendChild(img);
	
		
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
}