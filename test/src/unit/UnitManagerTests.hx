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
import cocktail.core.unit.UnitManager;
import cocktail.core.unit.UnitData;
import cocktail.core.style.StyleData;
import cocktail.Dom;

/**
 * Units tests for UnitManager
 * @author a.hoyau [at] silexlabs.org
 */
class UnitManagerTests
{
	var container : HTMLElement;
	var text : Text;
		
	public static function main() 
	{
        var runner = new Runner();
        runner.addCase(new UnitManagerTests());
        Report.create(runner);
        runner.run();
    }
        
    public function new()
	{
        container = new HTMLElement("div");
		text = Lib.document.createTextNode("Hello Cocktail !");
		container.appendChild(text);
		Lib.document.body.appendChild(container);
	}
    public function testConversionToEnums() 
	{
/*
		Assert.equals("http://test.com", UnitManager.string2URLData('url("http://test.com")'));
		Assert.equals("http://test.com", UnitManager.string2URLData('url( "http://test.com" )'));
		Assert.equals("http://test.com", UnitManager.string2URLData('url(http://test.com)'));
		Assert.equals("http://test.com", UnitManager.string2URLData(' url(http://test.com)'));
		Assert.equals("http://test.com", UnitManager.string2URLData(' url( http://test.com ) '));
 /*
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("1px 2pt 3px 4%"));
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList(" 1px 2pt 3px 4%"));
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("1px   2pt  3px 4%"));
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("  1px 2pt 3px   4% "));
		
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("1px,2pt,3px,4%", ","));
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("1px, 2pt, 3px, 4%", ","));
		Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("1px,2pt ,   3px , 4%", ","));
/*
		var res = UnitManager.string2Array('"Times New Roman",Georgia,Serif');
		Assert.same(["Times New Roman","Georgia","Serif"], res);
*/		
		
		Assert.isTrue(true);
	}
    public function testBoxStyleEnum() 
	{
		// "px" tests 
		Assert.same(Margin.length(Length.px(100)), UnitManager.boxStyleEnum(Margin, "100px"));		
		Assert.same(Margin.length(Length.px(100)), UnitManager.boxStyleEnum(Margin, "100 px"));
		Assert.same(Margin.length(Length.px(100)), UnitManager.boxStyleEnum(Margin, "100px "));
		Assert.same(Margin.length(Length.px(100)), UnitManager.boxStyleEnum(Margin, "100 px "));

		// "%" tests
		Assert.same(Margin.percent(100), UnitManager.boxStyleEnum(Margin, "100%"));		
		Assert.same(Margin.percent((100)), UnitManager.boxStyleEnum(Margin, "100 %"));
		Assert.same(Margin.percent((100)), UnitManager.boxStyleEnum(Margin, "100% "));
		Assert.same(Margin.percent((100)), UnitManager.boxStyleEnum(Margin, "100 % "));

		// "auto"
		Assert.same(Margin.cssAuto, UnitManager.boxStyleEnum(Margin, "auto"));
	}
	public function testBackground() 
	{
		Assert.same([BackgroundImage.image(ImageValue.url("./abc.gif")), BackgroundImage.image(ImageValue.url("./def.jpg"))], UnitManager.backgroundImageEnum("url (./abc.gif),  url(./def.jpg)"));
		var res = UnitManager.backgroundImageEnum("url(./abc.gif), url(./def.jpg)");
		Assert.same(BackgroundImage.image(ImageValue.url("./abc.gif")), res[0]);
		Assert.same(BackgroundImage.image(ImageValue.url("./def.jpg")), res[1]);
		
		var res = UnitManager.backgroundImageEnum("url (./abc.gif),  url(./def.jpg)");
		Assert.same(BackgroundImage.image(ImageValue.url("./abc.gif")), res[0]);
		Assert.same(BackgroundImage.image(ImageValue.url("./def.jpg")), res[1]);
		
		var res = UnitManager.backgroundImageEnum('url("./abc.gif"),url  (./def.jpg)');
		Assert.same(BackgroundImage.image(ImageValue.url("./abc.gif")), res[0]);
		Assert.same(BackgroundImage.image(ImageValue.url("./def.jpg")), res[1]);
	}
   public function testFont() 
   {
		Assert.same(["Times New Roman","Georgia","Serif"], UnitManager.fontFamilyEnum('"Times New Roman",Georgia,Serif'));
		Assert.same(["Times New Roman","Georgia","Serif"], UnitManager.fontFamilyEnum('Times New Roman, "Georgia" , Serif'));
		Assert.same(["Times New Roman","Georgia","Serif"], UnitManager.fontFamilyEnum('"Times New Roman" ,Georgia , Serif'));
		Assert.same(["Times New Roman","Georgia","Serif"], UnitManager.fontFamilyEnum(' "Times New Roman" ,  Georgia,Serif'));
   }
   public function testColor() 
   {
		// keywords and transparent
		Assert.same(Color.keyword(ColorKeyword.yellow), UnitManager.colorEnum("yellow"));
		Assert.same(Color.transparent, UnitManager.colorEnum("transparent"));
		
		// rgba
		Assert.same(Color.rgba(10, 20, 30, .5), UnitManager.colorEnum("rgba(10,20,30,.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), UnitManager.colorEnum("rgba(10,20,30,0.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), UnitManager.colorEnum("rgba(10,20,30 ,.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), UnitManager.colorEnum("rgba(10,20, 30 ,.5)"));
		Assert.same(Color.rgba(10, 20, 30, .5), UnitManager.colorEnum("rgba( 10,20,30,.5) "));

		// rgb
		Assert.same(Color.rgb(10, 20, 30), UnitManager.colorEnum("rgb(10,20,30)"));
		Assert.same(Color.rgb(10, 20, 30), UnitManager.colorEnum("rgb(10,20 ,30)"));
		Assert.same(Color.rgb(10, 20, 30), UnitManager.colorEnum("rgb(10,20, 30)"));
		Assert.same(Color.rgb(10, 20, 30), UnitManager.colorEnum("rgb( 10,20,30) "));

		// hex
		Assert.same(Color.hex("6789AB"), UnitManager.colorEnum("#6789AB"));
		Assert.same(Color.hex("789AB"), UnitManager.colorEnum("#789AB"));
		Assert.same(Color.hex("89AB"), UnitManager.colorEnum("#89AB"));
		Assert.same(Color.hex("AB"), UnitManager.colorEnum("#AB"));
	}
    public function testSetterGetter() 
	{
		container.style.marginLeft = "100px";
		Assert.same(Margin.length(Length.px(100)), container.coreStyle.marginLeft);
		container.style.marginLeft = "100%";
		Assert.same(Margin.percent((100)), container.coreStyle.marginLeft);
		container.style.marginLeft = "auto";
		Assert.same(Margin.cssAuto, container.coreStyle.marginLeft);

		container.style.backgroundImage = ' url(./abc.gif), url("./def.jpg") ';
		Assert.same([BackgroundImage.image(ImageValue.url("./abc.gif")),BackgroundImage.image(ImageValue.url("./def.jpg"))], container.coreStyle.backgroundImage);
		
		container.style.fontFamily = '"Times New Roman",Georgia, Serif';
		Assert.same(["Times New Roman","Georgia","Serif"], container.coreStyle.fontFamily);
	}
}