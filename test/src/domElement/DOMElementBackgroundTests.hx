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
		/**var runner = new Runner();
		runner.addCase(new DOMElementBackgroundTests());
		Report.create(runner);
		runner.run();*/
		new DOMElementBackgroundTests();
	}
	
	public function new() 
	{
		testDOMElementBackground();
	}
	
	public function testDOMElementBackground()
	{
		
		var bodyDOMElement:BodyDOMElement = new BodyDOMElement();
		
		
		var container1 = new ContainerDOMElement();
		container1.style.display = DisplayStyleValue.block;
		//container1.width = 700;
		//container1.height = 300;
		container1.style.height = DimensionStyleValue.length(px(500));
		
		container1.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.rgba(255, 0, 0, 0.5));
		
		/**container1.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.gradient(GradientValue.linear( { angle:GradientAngleValue.angle(AngleValue.deg(55.0)),
		colorStops:[{color:ColorValue.rgba(0, 255, 0,0.7), stop:GradientStopValue.percent(0)}, {color:ColorValue.rgba(255, 0, 0,0.3), stop:GradientStopValue.percent(100)} ]} ))), 
		BackgroundImageStyleValue.image(ImageValue.url("firefox.png"))];*/
		
		container1.style.backgroundPosition = [
		{ x:BackgroundPositionXStyleValue.center, y:BackgroundPositionYStyleValue.center },
		{ x:BackgroundPositionXStyleValue.left, y:BackgroundPositionYStyleValue.center }
		];
		
		container1.style.backgroundOrigin = [
		BackgroundOriginStyleValue.paddingBox,
		BackgroundOriginStyleValue.contentBox
		];
		
		container1.style.backgroundRepeat = [
		{x:BackgroundRepeatStyleValue.repeat, y:BackgroundRepeatStyleValue.repeat},
		{x:BackgroundRepeatStyleValue.repeat, y:BackgroundRepeatStyleValue.repeat }
		
		];
		
		container1.style.backgroundClip = [
		BackgroundClipStyleValue.contentBox,
		BackgroundClipStyleValue.paddingBox
		];
		
		container1.style.backgroundSize = [
		BackgroundSizeStyleValue.dimensions( { x:BackgroundSizeStyleDimensionValue.auto, y:BackgroundSizeStyleDimensionValue.auto } ),
		BackgroundSizeStyleValue.dimensions( { x:BackgroundSizeStyleDimensionValue.auto, y:BackgroundSizeStyleDimensionValue.length(px(150)) } )
		];
		 
		container1.addText(new TextElement("text"));
		
		var container2:ContainerDOMElement = new ContainerDOMElement();
		container2.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.keyword(ColorKeywordValue.purple));
		container2.addText(new TextElement("bold linessssssssss"));
		container2.style.fontWeight = FontWeightStyleValue.bold;
		
		var container3:ContainerDOMElement = new ContainerDOMElement();
		container3.addText(new TextElement("In Beetween"));
		container3.style.fontSize = FontSizeStyleValue.length(px(50));
		container3.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.keyword(ColorKeywordValue.black));
		container3.style.color = ColorValue.keyword(ColorKeywordValue.white);
		container3.style.paddingLeft = PaddingStyleValue.length(px(100));
		
		container2.addChild(container3);
		
			container2.addText(new TextElement("bim bam boum"));
		
		container1.addChild(container2);
		
		container1.style.marginLeft = MarginStyleValue.length(px(20));
		container1.style.marginRight = MarginStyleValue.length(px(20));
		container1.style.marginTop = MarginStyleValue.length(px(20));
		container1.style.marginBottom = MarginStyleValue.length(px(20));
		container1.style.paddingLeft = PaddingStyleValue.length(px(30));
		container1.style.paddingTop = PaddingStyleValue.length(px(30));
		container1.style.paddingBottom = PaddingStyleValue.length(px(30));
		container1.style.paddingRight = PaddingStyleValue.length(px(30));
		
		
		
		var img:ImageDOMElement = new ImageDOMElement();
		img.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.keyword(ColorKeywordValue.green));
		
	//	img.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.imageList( { urls:["fakeUrl.jpg"], fallbackColor:ColorValue.rgba(0, 0, 0, 0.5) } ))];
		
		//img.style.marginLeft = MarginStyleValue.length(px(20));
		//img.style.marginTop = MarginStyleValue.length(px(20));
		//img.style.marginBottom = MarginStyleValue.length(px(2));
		//img.style.marginRight = MarginStyleValue.length(px(20));
		img.load("firefox.png");
		img.width = 100;
		img.height = 100;
		//img.style.paddingTop = PaddingStyleValue.length(px(50));
		//img.style.paddingLeft = PaddingStyleValue.length(px(50));
		//img.style.paddingRight = PaddingStyleValue.length(px(50));
		//img.style.paddingBottom = PaddingStyleValue.length(px(50));
		
	//	container1.addChild(img);
		
		container1.addText(new TextElement("biiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiim"));
		container1.style.position = PositionStyleValue.relative;
		container1.style.top = PositionOffsetStyleValue.length(px(250));
		//container1.style.left = PositionOffsetStyleValue.length(px(300));
		
		
		bodyDOMElement.style.display = DisplayStyleValue.block;
		//bodyDOMElement.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.hex("#00CC00"));
		//bodyDOMElement.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.url("firefox.png"))];
		
		
		bodyDOMElement.addChild(container1);
		
	}
}