/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.lexa.demo;

import js.Lib;
import js.Dom;

class Lexa 
{
	public static function main()
	{	
		var lx = new Lexa();
		lx.prezCocktail();
	}
	
	public function new()
	{
		
	}
	
	function prezCocktail()
	{
		//HTML DOM & JavaScript
		var title = Lib.document.createElement("h1");
		title.appendChild(Lib.document.createTextNode("Hello Cocktail"));
		Lib.document.body.appendChild(title);
		
		//HTML & semantics
		var paragraph = Lib.document.createElement("p");
		paragraph.appendChild(Lib.document.createTextNode("Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe."));
		Lib.document.body.appendChild(paragraph);
	
		//CSS text
		title.style.wordSpacing = "10px";
		title.style.color = "orange";
		title.style.fontFamily = "arial";
					
		//HTML4
		var img:Image = cast(Lib.document.createElement("img"));
		img.src = "cocktail.jpg";
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
		Lib.document.body.style.backgroundImage = "url(bg.png)";
	}
}