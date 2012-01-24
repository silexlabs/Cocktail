/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package focus;

import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.LinkDOMElement;
import cocktail.textElement.TextElement;
import cocktailCore.focus.FocusManager;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import haxe.Log;


class FocusTests 
{
	
	public static function main()
	{
		/**var runner = new Runner();
		runner.addCase(new FocusTests());
		Report.create(runner);
		runner.run();*/
		new FocusTests();
	}
	
	public function new() 
	{
		testFocus();
	}
	
	public function testFocus()
	{
		var bodyDOMElement:BodyDOMElement = new BodyDOMElement();
		
		
		var link1 = getLink("link 1");
		var link2 = getLink("link 2");
		var link3 = getLink("link 3");
		
		var focusableContainer = getFocusableContainer();
		focusableContainer.tabIndex = 40;
		
		var link4 = getLink("link 4");
		var link5 = getLink("link 5");
		link1.tabIndex = 50;
		
		link3.tabIndex = 25;
		
		bodyDOMElement.addChild(link1);
		bodyDOMElement.addChild(link2);
		bodyDOMElement.addChild(focusableContainer);
		
		focusableContainer.addChild(link3);
		focusableContainer.addChild(link4);
		
		
	}
	
	private function getLink(text:String):LinkDOMElement
	{
		var linkDOMElement:LinkDOMElement = new LinkDOMElement();
		linkDOMElement.href = "#";
		linkDOMElement.addText(new TextElement(text));
		linkDOMElement.style.display = DisplayStyleValue.block;
		
		linkDOMElement.onFocusIn = function() {
			linkDOMElement.style.color = ColorValue.keyword(ColorKeywordValue.red);
		}
		linkDOMElement.onFocusOut = function() {
			linkDOMElement.style.color = ColorValue.keyword(ColorKeywordValue.black);
		}
		linkDOMElement.onMouseDown = function(e) {
			linkDOMElement.style.color = ColorValue.keyword(ColorKeywordValue.green);
		}
		
		return linkDOMElement;
	}
	
	private function getFocusableContainer():ContainerDOMElement
	{
		var containerDOMElement:ContainerDOMElement = new ContainerDOMElement();
		containerDOMElement.tabEnabled = true;
		
		containerDOMElement.style.display = DisplayStyleValue.block;
		
		containerDOMElement.onFocusIn = function() {
			containerDOMElement.style.opacity = OpacityStyleValue.number(0.5);
		}
		containerDOMElement.onFocusOut = function() {
			containerDOMElement.style.opacity = OpacityStyleValue.number(1.0);
		}
		
		return containerDOMElement;
		
	}
}
