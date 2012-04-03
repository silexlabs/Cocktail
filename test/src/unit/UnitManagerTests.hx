/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

import utest.Assert;
import utest.Runner;
import utest.ui.Report;
import cocktail.Lib;
import cocktail.Cocktail;

/**
 * Units tests for UnitManager
 * @author a.hoyau [at] silexlabs.org
 */
class UnitManagerTests
{
	var container : HTMLElement;
	var text : Text;
		
	public static function main() {
        var runner = new Runner();
        runner.addCase(new UnitManagerTests());
        Report.create(runner);
        runner.run();
    }
        
    public function new(){
        container = new HTMLElement("div");
		text = Lib.document.createTextNode("Hello Cocktail !");
		container.appendChild(text);
		Lib.document.body.appendChild(container);
	}
    public function testBoxStyleEnum() {
		// "px" tests 
		Assert.same(Margin.length(Length.px(100)), CSSParser.boxStyleEnum(Margin, "100px"));		
		Assert.same(Margin.length(Length.px(100)), CSSParser.boxStyleEnum(Margin, "100 px"));
		Assert.same(Margin.length(Length.px(100)), CSSParser.boxStyleEnum(Margin, "100px "));
		Assert.same(Margin.length(Length.px(100)), CSSParser.boxStyleEnum(Margin, "100 px "));

		// "%" tests
		Assert.same(Margin.percent(100), CSSParser.boxStyleEnum(Margin, "100%"));		
		Assert.same(Margin.percent((100)), CSSParser.boxStyleEnum(Margin, "100 %"));
		Assert.same(Margin.percent((100)), CSSParser.boxStyleEnum(Margin, "100% "));
		Assert.same(Margin.percent((100)), CSSParser.boxStyleEnum(Margin, "100 % "));

		// "auto"
		Assert.same(Margin.cssAuto, CSSParser.boxStyleEnum(Margin, "auto"));
	}
   public function testColor() {
		// keywords and transparent
		Assert.same(Color.keyword(ColorKeyword.yellow), CSSParser.colorEnum("yellow"));
		Assert.same(Color.transparent, CSSParser.colorEnum("transparent"));
		
		// rgba
		Assert.same(Color.rgba(10, 20, 30, .5), CSSParser.colorEnum("rgba(10,20,30,.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), CSSParser.colorEnum("rgba(10,20,30,0.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), CSSParser.colorEnum("rgba(10,20,30 ,.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), CSSParser.colorEnum("rgba(10,20, 30 ,.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), CSSParser.colorEnum("rgba( 10,20,30,.5) "));

		// rgb
		Assert.same(Color.rgb(10, 20, 30), CSSParser.colorEnum("rgb(10,20,30)"));
		Assert.same(Color.rgb(10, 20, 30), CSSParser.colorEnum("rgb(10,20 ,30)"));
		Assert.same(Color.rgb(10, 20, 30), CSSParser.colorEnum("rgb(10,20, 30)"));
		Assert.same(Color.rgb(10, 20, 30), CSSParser.colorEnum("rgb( 10,20,30) "));

		// hex
		Assert.same(Color.hex("6789AB"), CSSParser.colorEnum("#6789AB"));
		Assert.same(Color.hex("789AB"), CSSParser.colorEnum("#789AB"));
		Assert.same(Color.hex("89AB"), CSSParser.colorEnum("#89AB"));
		Assert.same(Color.hex("AB"), CSSParser.colorEnum("#AB"));
	}
    public function testSetterGetter() {
		// "px" tests 
		container.style.marginLeft = "100px";
		Assert.same(Margin.length(Length.px(100)), container.style.marginLeft);		
		return;

		// "%" tests
		container.style.marginLeft = "100%";
		Assert.same(Margin.percent((100)), container.style.marginLeft);

		// "auto"
		container.style.marginLeft = "auto";
		Assert.same(Margin.cssAuto, container.style.marginLeft);
	}
}