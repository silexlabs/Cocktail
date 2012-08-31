/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package ;

import js.Lib;
import js.Dom;

/**
 * This is a simple Cocktail example of an Html page with styles and interactivity.
 */
class Main 
{
	public static function main()
	{	
		#if nme
			nme.Lib.create(function() { new Main(); }, 1024, 768, 60, 0xffffff, (1 * nme.Lib.HARDWARE) | nme.Lib.RESIZABLE);
		#else
		    new Main();
		#end
		
	}
	
	public function new()
	{
		// use Haxe JS Api to build the DOM
		buildDomHaxeJS();
		// or use Html content to build the DOM
		//hs.buildDomHtml();
		
		// add interactivity
		addInteractivity();
		
	}
	
	/**
	 * Builds the DOM using Haxe JS Api
	 */
	function buildDomHaxeJS()
	{

		//HTML DOM & JavaScript
		var title = Lib.document.createElement("h1");
		title.appendChild(Lib.document.createTextNode("Hello Cocktail"));
		Lib.document.body.appendChild(title);
		
		//HTML & semantics
		var paragraph = Lib.document.createElement("p");
		paragraph.appendChild(Lib.document.createTextNode("Cocktail is a HTML rendering engine. It focuses on UIs and bridges the gap between all the targets supported by haXe."));
		Lib.document.body.appendChild(paragraph);
	
		//CSS text
		title.style.wordSpacing = "10px";
		title.style.color = "orange";
		title.style.fontFamily = "arial";
					
		//HTML4
		var img:Image = cast(Lib.document.createElement("img"));
		img.id = "pic";
		img.src = "assets/cocktail.png";
		paragraph.appendChild(img);
		
		//CSS layouts
		var site = Lib.document.createElement("div");
		site.appendChild(title);
		site.appendChild(paragraph);
		
		site.style.width = "50%";
		site.style.marginLeft = site.style.marginRight = "auto";
		
		Lib.document.body.appendChild(site);
		
		//CSS backgrounds
		site.style.backgroundColor = "rgba(255,255,255,0.5)";
		
	}
		
	/**
	 * Builds the DOM using Html content directly
	 */
	function buildDomHtml()
	{
		//HxTML
		Lib.document.body.innerHTML = '<div style="width: 50%; margin-right: auto; margin-left: auto; background-color: rgba(255, 255, 255, 0.5);"><h1 style="word-spacing: 10px; color: orange; font-family: arial;">Hello Cocktail</h1><p>Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe.<img id="pic" src="assets/cocktail.png" /></p></div>';

	}
	
	/**
	 * Add interactivity
	 */
	function addInteractivity()
	{
		var pic:HtmlDom = cast(Lib.document.getElementById("pic"));
		pic.onclick = function(e) {
			Lib.document.body.style.backgroundImage = "url(assets/bg.png)";
		}
		
	}
}