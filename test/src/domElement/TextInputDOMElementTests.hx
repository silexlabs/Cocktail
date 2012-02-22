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
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.LinkDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktail.domElement.TextInputDOMElement;
import haxe.Log;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import utest.ui.common.HeaderDisplayMode;


class TextInputDOMElementTests 
{
	
	public static function main()
	{	
		/**var runner = new Runner();
		runner.addCase(new TextInputDOMElementTests());
		Report.create(runner);
		runner.run();*/
		new TextInputDOMElementTests();
	}
	
	public function new() 
	{
		testTextInput();
	}
	
	private function testTextInput()
	{
		var body = new BodyDOMElement();
		
		var textInput = new TextInputDOMElement();
		
		body.addChild(textInput);
		
		textInput.value = "bim";
		
		textInput.maxLength = 5;
		//textInput.disabled = true;
		
		textInput.onChange = function() {
			Log.trace(textInput.value);
		}
		
		textInput.width = 500;
		textInput.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.keyword(ColorKeywordValue.red));
	}
	
}