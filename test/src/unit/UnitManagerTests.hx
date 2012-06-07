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
    public function testConstrainedDimentions() 
	{
		// "px" tests 
		Assert.same(ConstrainedDimension.length(Length.px(100)), UnitManager.constrainedDimensionEnum("100px"));		
		Assert.same(ConstrainedDimension.length(Length.px(100)), UnitManager.constrainedDimensionEnum("100 px"));
		Assert.same(ConstrainedDimension.length(Length.px(100)), UnitManager.constrainedDimensionEnum("100px "));
		Assert.same(ConstrainedDimension.length(Length.px(100)), UnitManager.constrainedDimensionEnum("100 px "));

		// "%" tests
		Assert.same(ConstrainedDimension.percent(100), UnitManager.constrainedDimensionEnum("100%"));		
		Assert.same(ConstrainedDimension.percent((100)), UnitManager.constrainedDimensionEnum("100 %"));
		Assert.same(ConstrainedDimension.percent((100)), UnitManager.constrainedDimensionEnum("100% "));
		Assert.same(ConstrainedDimension.percent((100)), UnitManager.constrainedDimensionEnum("100 % "));

		// "none"
		Assert.same(ConstrainedDimension.none, UnitManager.constrainedDimensionEnum("none"));
	}
   public function testDisplay() 
   {
		Assert.same(Display.cssInline, UnitManager.displayEnum("inline"));
		Assert.same(Display.block, UnitManager.displayEnum("block"));
		Assert.same(Display.inlineBlock, UnitManager.displayEnum("inline-block"));
		Assert.same(Display.none, UnitManager.displayEnum("none"));
		Assert.same(null, UnitManager.displayEnum(""));
		Assert.same(null, UnitManager.displayEnum("abcd"));
   }
   public function testOverflow() 
   {
		Assert.same(Overflow.visible, UnitManager.overflowEnum("visible"));
		Assert.same(Overflow.scroll, UnitManager.overflowEnum("scroll"));
		Assert.same(Overflow.cssAuto, UnitManager.overflowEnum("auto"));
		Assert.same(Overflow.hidden, UnitManager.overflowEnum("hidden"));
		Assert.same(null, UnitManager.overflowEnum(""));
		Assert.same(null, UnitManager.overflowEnum("abcd"));
   }
   public function testVerticalAlign() 
   {
 		Assert.same(VerticalAlign.baseline, UnitManager.verticalAlignEnum("baseline"));
 		Assert.same(VerticalAlign.bottom, UnitManager.verticalAlignEnum("bottom"));
 		Assert.same(VerticalAlign.cssSuper, UnitManager.verticalAlignEnum("super"));
 		Assert.same(VerticalAlign.middle, UnitManager.verticalAlignEnum("middle"));
 		Assert.same(VerticalAlign.top, UnitManager.verticalAlignEnum("top"));
 		Assert.same(VerticalAlign.textBottom, UnitManager.verticalAlignEnum("textBottom"));
 		Assert.same(VerticalAlign.textTop, UnitManager.verticalAlignEnum("textTop"));
 		Assert.same(VerticalAlign.sub, UnitManager.verticalAlignEnum("sub"));
 		Assert.same(VerticalAlign.percent(10), UnitManager.verticalAlignEnum("10%"));
 		Assert.same(VerticalAlign.length(Length.px(10)), UnitManager.verticalAlignEnum("10px"));
   }
   public function testClear() 
   {
 		Assert.same(Clear.both, UnitManager.clearEnum("both"));
 		Assert.same(Clear.left, UnitManager.clearEnum("left"));
 		Assert.same(Clear.right, UnitManager.clearEnum("right"));
 		Assert.same(Clear.none, UnitManager.clearEnum("none"));
   }
   public function testPosition() 
   { 
 		Assert.same(Position.cssStatic, UnitManager.positionEnum("static"));
 		Assert.same(Position.absolute, UnitManager.positionEnum("absolute"));
 		Assert.same(Position.relative, UnitManager.positionEnum("relative"));
 		Assert.same(Position.fixed, UnitManager.positionEnum("fixed"));
   }
   public function testWhiteSoace() 
   {
 		Assert.same(WhiteSpace.normal, UnitManager.whiteSpaceEnum("normal"));
 		Assert.same(WhiteSpace.nowrap, UnitManager.whiteSpaceEnum("nowrap"));
 		Assert.same(WhiteSpace.pre, UnitManager.whiteSpaceEnum("pre"));
 		Assert.same(WhiteSpace.preLine, UnitManager.whiteSpaceEnum("preLine"));
 		Assert.same(WhiteSpace.preWrap, UnitManager.whiteSpaceEnum("preWrap"));
   }
   public function testTextAlign() 
   { 
 		Assert.same(TextAlign.left, UnitManager.textAlignEnum("left"));
 		Assert.same(TextAlign.right, UnitManager.textAlignEnum("right"));
 		Assert.same(TextAlign.center, UnitManager.textAlignEnum("center"));
 		Assert.same(TextAlign.justify, UnitManager.textAlignEnum("justify"));
   }
   public function testFontWeight() 
   {
 		Assert.same(FontWeight.bold , UnitManager.fontWeightEnum("bold"));
 		Assert.same(FontWeight.bolder , UnitManager.fontWeightEnum("bolder"));
 		Assert.same(FontWeight.normal , UnitManager.fontWeightEnum("normal"));
 		Assert.same(FontWeight.lighter , UnitManager.fontWeightEnum("lighter"));
 		Assert.same(FontWeight.css100 , UnitManager.fontWeightEnum("100"));
   }
   public function testFontStyle() 
   {
 		Assert.same(FontStyle.italic, UnitManager.fontStyleEnum("italic"));
 		Assert.same(FontStyle.normal, UnitManager.fontStyleEnum("normal"));
   }
   public function testFontVariant() 
   {
 		Assert.same(FontVariant.normal, UnitManager.fontVariantEnum("normal"));
 		Assert.same(FontVariant.smallCaps, UnitManager.fontVariantEnum("small-caps"));
   }
   public function testTextTransform() 
   {
 		Assert.same(TextTransform.capitalize, UnitManager.textTransformEnum("capitalize"));
 		Assert.same(TextTransform.lowercase, UnitManager.textTransformEnum("lowercase"));
 		Assert.same(TextTransform.uppercase, UnitManager.textTransformEnum("uppercase"));
 		Assert.same(TextTransform.none, UnitManager.textTransformEnum("none"));
   }
   public function testVisibility() 
   {
 		Assert.same(Visibility.hidden, UnitManager.visibilityEnum("hidden"));
 		Assert.same(Visibility.visible, UnitManager.visibilityEnum("visible"));
   }
   public function testCursor() 
   {
 		Assert.same(Cursor.cssAuto, UnitManager.cursorEnum("auto"));
 		Assert.same(Cursor.crosshair, UnitManager.cursorEnum("crosshair"));
 		Assert.same(Cursor.pointer, UnitManager.cursorEnum("pointer"));
 		Assert.same(Cursor.cssDefault, UnitManager.cursorEnum("default"));
   }
 
// ****************************************************
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
		Lib.document.body.style.backgroundColor = "#ABCDEF";
		
		container.style.marginLeft = "100px";
		Assert.same(Margin.length(Length.px(100)), container.coreStyle.marginLeft);
		container.style.marginLeft = "100%";
		Assert.same(Margin.percent((100)), container.coreStyle.marginLeft);
		container.style.marginLeft = "auto";
		Assert.same(Margin.cssAuto, container.coreStyle.marginLeft);

		container.style.minWidth = "100%";
		Assert.same(ConstrainedDimension.percent(100), container.coreStyle.minWidth);
		container.style.minWidth = "none";
		Assert.same(ConstrainedDimension.none, container.coreStyle.minWidth);

		container.style.display = "inline-block";
		Assert.same(Display.inlineBlock, container.coreStyle.display);
		container.style.display = "";
		Assert.same(null, container.coreStyle.display);

		container.style.overflowX = "hidden";
		Assert.same(Overflow.hidden, container.coreStyle.overflowX);
		container.style.overflowX = "";
		Assert.same(null, container.coreStyle.overflowX);
		
		container.style.verticalAlign = "sub";
		Assert.same(VerticalAlign.sub, container.coreStyle.verticalAlign);
		container.style.verticalAlign = "10%";
		Assert.same(VerticalAlign.percent(10), container.coreStyle.verticalAlign);
		container.style.verticalAlign = "100px";
		Assert.same(VerticalAlign.length(Length.px(100)), container.coreStyle.verticalAlign);

		container.style.clear = "none";
		Assert.same(Clear.none, container.coreStyle.clear);

		container.style.position = "fixed";
		Assert.same(Position.fixed, container.coreStyle.position);

		container.style.whiteSpace = "preWrap";
		Assert.same(WhiteSpace.preWrap, container.coreStyle.whiteSpace);

		container.style.textAlign = "justify";
		Assert.same(TextAlign.justify, container.coreStyle.textAlign);

		container.style.fontWeight = "bold";
		Assert.same(FontWeight.bold , container.coreStyle.fontWeight);

		container.style.fontStyle= "normal";
		Assert.same(FontStyle.normal, container.coreStyle.fontStyle);

 		container.style.fontVariant= "small-caps";
		Assert.same(FontVariant.smallCaps, container.coreStyle.fontVariant);

 		container.style.textTransform= "none";
		Assert.same(TextTransform.none, container.coreStyle.textTransform);

 		container.style.visibility= "hidden";
		Assert.same(Visibility.hidden, container.coreStyle.visibility);
 		container.style.visibility= "visible";
		Assert.same(Visibility.visible, container.coreStyle.visibility);

 		container.style.cursor= "default";
		Assert.same(Cursor.cssDefault, container.coreStyle.cursor);
 		container.style.cursor= "crosshair";
		Assert.same(Cursor.crosshair, container.coreStyle.cursor);

		container.style.backgroundImage = ' url(./abc.gif), url("./def.jpg") ';
		Assert.same([BackgroundImage.image(ImageValue.url("./abc.gif")),BackgroundImage.image(ImageValue.url("./def.jpg"))], container.coreStyle.backgroundImage);
		
		container.style.fontFamily = '"Times New Roman",Georgia, Serif';
		Assert.same(["Times New Roman","Georgia","Serif"], container.coreStyle.fontFamily);
	}
}