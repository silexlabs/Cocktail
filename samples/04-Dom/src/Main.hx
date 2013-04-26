/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import js.Lib;
import js.Dom;

/**
 * an example of using the DOM api to build an html document
 */
class Main
{
	static function main()
	{
		#if !js
		//init cocktail with the content of the index.html file
		cocktail.api.Cocktail.boot();
		#end
		
		Lib.window.onload = function(e) new Main();
	}

	
	public function new()
	{
		buildDom();
		
		// add interactivity
		addInteractivity();
	}
	
	/**
	 * Builds the DOM 
	 */
	function buildDom()
	{
		var title = Lib.document.createElement("h1");
		title.appendChild(Lib.document.createTextNode("Hello Cocktail"));
		Lib.document.body.appendChild(title);
		
		var paragraph = Lib.document.createElement("p");
		paragraph.appendChild(Lib.document.createTextNode("Cocktail is a HTML rendering engine."));
		Lib.document.body.appendChild(paragraph);
	
		title.style.wordSpacing = "10px";
		title.style.color = "orange";
		title.style.fontFamily = "arial";
					
		var img:Image = cast(Lib.document.createElement("img"));
		img.id = "pic";
		img.src = "assets/cocktail.png";
		paragraph.appendChild(img);
		
		var site = Lib.document.createElement("div");
		site.appendChild(title);
		site.appendChild(paragraph);
		
		site.style.width = "50%";
		site.style.marginLeft = site.style.marginRight = "auto";
		
		Lib.document.body.appendChild(site);
		
		site.style.backgroundColor = "rgba(255,255,255,0.5)";
	}
	
	/**
	 * Add click listener on body
	 */
	function addInteractivity()
	{
		var pic:HtmlDom = cast(Lib.document.getElementById("pic"));
		pic.onclick = function(e) {
			Lib.document.body.style.backgroundImage = "url(assets/bg.png)";
		}
		
	}
}
