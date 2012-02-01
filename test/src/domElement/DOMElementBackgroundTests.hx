/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package domElement;

import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.LinkDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import haxe.Log;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;

/**
 * Units tests for DOMElements
 * @author Yannick DOMINGUEZ & Raphael HARMEL
 * 
 * 2011-08-10 PHP part is not complete yet.
 * 
 */

class DOMElementBackgroundTests 
{
	
	public static function main()
	{	
		var runner = new Runner();
		runner.addCase(new DOMElementBackgroundTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	public function testDOMElementBackground()
	{
		
		Log.trace("bim");
		var bodyDOMElement:BodyDOMElement = new BodyDOMElement();
		
		var container1 = new ContainerDOMElement();
		container1.style.display = DisplayStyleValue.block;
		container1.width = 100;
		container1.height = 100;
		
		container1.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.keyword(ColorKeywordValue.red));
		
		bodyDOMElement.addChild(container1);
		
	}
}