/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.lexa.demo;


import core.HTMLAnchorElement;
import core.HTMLElement;
import core.Text;

import cocktail.Cocktail;
import cocktail.Lib;

class Lexa 
{
	public static function main()
	{	
		var site:HTMLElement = cast(Lib.document.createElement("div"));
		
		site.style.width = Dimension.percent(30);
		site.style.marginLeft = site.style.marginRight = Margin.cssAuto;
		
		var title:HTMLElement = cast(Lib.document.createElement("h1"));
		title.appendChild(Lib.document.createTextNode("Cocktail"));
		title.style.color = keyword(orange);
		title.style.fontSize = FontSize.length(px(48));
		title.style.textAlign = center;
		
		var subTitle:HTMLElement = cast(Lib.document.createElement("h2"));
		subTitle.appendChild(Lib.document.createTextNode("cross-platform haXe UIs"));
		subTitle.style.fontSize = FontSize.length(px(36));
		subTitle.style.textAlign = center;
		
		
		title.style.fontFamily = subTitle.style.fontFamily = [FontFamily.familyName("arial")];
		
		var logo:Image = new Image();
		logo.src = "cocktail.jpg";
		logo.style.backgroundColor = keyword(gray);
		
		var text:HTMLElement = cast(Lib.document.createElement("p"));
		text.appendChild(Lib.document.createTextNode("Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe."));
		text.style.backgroundColor = keyword(orange);
		text.style.color = hex("#FFFFFF");
		text.style.paddingLeft = text.style.paddingTop = text.style.paddingBottom = text.style.paddingRight = Padding.length(px(10));
		
		var logoContainer:HTMLAnchorElement = cast(Lib.document.createElement("a"));
		logoContainer.style.textAlign = center;
		logoContainer.appendChild(logo);
		logoContainer.style.display = block;
		logoContainer.href = "http://www.silexlabs.org/groups/labs/cocktail/";
		
		site.appendChild(title);
		site.appendChild(subTitle);
		site.appendChild(text);
		site.appendChild(logoContainer);
		
		Lib.document.body.appendChild(site);
	}
}