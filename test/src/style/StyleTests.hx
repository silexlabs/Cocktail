/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package style;

/**
 * Units tests for Styles
 * @author Yannick DOMINGUEZ
 * 
 * 
 */

import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.textElement.TextElement;
import haxe.Log;
import cocktail.domElement.ContainerDOMElement;
import cocktail.geom.GeomData;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.unit.UnitData;
import cocktailCore.style.StyleData;
import cocktail.resource.ResourceLoaderManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.nativeElement.NativeElementManager;
import cocktail.viewport.Viewport;


class StyleTests 
{
	
	private static var rootDOMElement:DOMElement;
	
	private var _mainContainer:ContainerDOMElement;
	
	private var _background:GraphicDOMElement;
	
	private var _siteBackground:GraphicDOMElement;
	
	private var _navigation:GraphicDOMElement;
	
	private var _header:GraphicDOMElement;
	
	private var _siteRightBackground:GraphicDOMElement;
	
	private var _footer:GraphicDOMElement;
	
	private var _siteLeftFloatBackground:GraphicDOMElement;
	
	private var _siteLeftAfterFloatBackground:GraphicDOMElement;
	private var _siteLeftAfterFloatBackground2:GraphicDOMElement;
	private var _siteLeftAfterFloatBackground3:GraphicDOMElement;
	
	private var _insetGraphicElement:GraphicDOMElement;
	
	public static function main()
	{
		//rootDOMElement = new ContainerDOMElement(NativeElementManager.getRoot());
		new StyleTests();
	}
	
	public function new() 
	{
		#if js
		js.Lib.window.onresize = refresh;
		
		#elseif flash9
		flash.Lib.current.stage.addEventListener(flash.events.Event.RESIZE, refresh);
		
		#end
		testLayout2();
		
		
	}
	
	public function testLayout2()
	{
		_mainContainer = getContainer();
		_mainContainer.style.width = DimensionStyleValue.percent(80);
		_mainContainer.style.height = DimensionStyleValue.auto;
		_mainContainer.style.left = PositionOffsetStyleValue.length(px(20));
		_mainContainer.style.top = PositionOffsetStyleValue.length(px(50));
		//_mainContainer.style.right = PositionOffsetStyleValue.length(px(20));
		_mainContainer.style.bottom = PositionOffsetStyleValue.length(px(200));
		_mainContainer.style.marginLeft = MarginStyleValue.length(px(50));
		//_mainContainer.style.position = PositionStyleValue.relative;
		
		var bodyDOMElement:BodyDOMElement = new BodyDOMElement();
		bodyDOMElement.addChild(_mainContainer);
		
		getDefaultStyle(bodyDOMElement);
		
		
		
		var headerContainer:ContainerDOMElement = getContainer();
		headerContainer.style.width = DimensionStyleValue.auto;
		headerContainer.style.height = DimensionStyleValue.length(px(150));
		headerContainer.style.paddingTop = PaddingStyleValue.length(px(5));
		headerContainer.style.paddingBottom = PaddingStyleValue.length(px(5));
		headerContainer.style.paddingLeft = PaddingStyleValue.length(px(5));
		headerContainer.style.paddingRight = PaddingStyleValue.length(px(5));
		headerContainer.style.marginBottom = MarginStyleValue.length(px(30));
		headerContainer.style.marginRight = MarginStyleValue.length(px(50));
		
		_header = getGraph();
		_header.style.width = DimensionStyleValue.auto;
		_header.style.height = DimensionStyleValue.length(px(300));
		//_header.style.float = FloatStyleValue.right;
		//headerContainer.style.position = PositionStyleValue.absolute;
		//headerContainer.style.left = PositionOffsetStyleValue.length(px(200)); 
		//headerContainer.style.top = PositionOffsetStyleValue.length(px(200));
		
		headerContainer.addChild(_header);
		var textContainer:ContainerDOMElement = getContainer();
		textContainer.style.width = DimensionStyleValue.percent(50);
		
		
		
		
		textContainer.addText(new TextElement("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus facilisis tortor sodales lacus pretium scelerisque dapibus est rhoncus. Aenean feugiat nulla vel libero imperdiet et iaculis nisl tristique. Pellentesque congue varius consectetur. Sed vulputate tristique ante, at ullamcorper odio adipiscing vitae. Cras interdum blandit ultricies. Pellentesque id lacus orci. Sed volutpat mi vel odio viverra molestie. Fusce rutrum purus accumsan lectus venenatis mattis at vel eros. Sed ac scelerisque neque. Donec et mi mollis ligula imperdiet euismod. Nunc ac consectetur orci. Morbi a enim lacus. Pellentesque dolor massa, vestibulum vitae placerat pretium, gravida suscipit nulla. Pellentesque est ipsum, egestas ut ullamcorper bibendum, dapibus at erat. Morbi purus lectus, aliquam at molestie in, sagittis ac magna. "));
		//textContainer.addText(new TextElement("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus facilisis tortor sodales lacus pretium scelerisque dapibus est rhoncus. Aenean feugiat nulla vel libero imperdiet et iaculis nisl tristique. Pellentesque congue varius consectetur. Sed vulputate tristique ante, at ullamcorper odio adipiscing vitae. Cras interdum blandit ultricies. Pellentesque id lacus orci. Sed volutpat mi vel odio viverra molestie. Fusce rutrum purus accumsan lectus venenatis mattis at vel eros. Sed ac scelerisque neque. Donec et mi mollis ligula imperdiet euismod. Nunc ac consectetur orci. Morbi a enim lacus. Pellentesque dolor massa, vestibulum vitae placerat pretium, gravida suscipit nulla. Pellentesque est ipsum, egestas ut ullamcorper bibendum, dapibus at erat. Morbi purus lectus, aliquam at molestie in, sagittis ac magna. "));
		
		
		textContainer.style.fontSize = FontSizeStyleValue.length(px(12));
		textContainer.style.color = ColorValue.keyword(ColorKeywordValue.gray);
		
		textContainer.style.display = DisplayStyleValue.inlineStyle;
		_siteLeftFloatBackground = getGraph();
		_siteLeftFloatBackground.style.width = DimensionStyleValue.length(px(50));
		_siteLeftFloatBackground.style.height = DimensionStyleValue.length(px(400)); 
		
		var firstLetterContainer:ContainerDOMElement = getContainer();
		firstLetterContainer.addText(new TextElement("a, b, c, d "));
		firstLetterContainer.style.textTransform = TextTransformStyleValue.uppercase;
		firstLetterContainer.style.fontSize = FontSizeStyleValue.length(px(50));
		firstLetterContainer.style.display = DisplayStyleValue.inlineStyle;
		firstLetterContainer.style.float = FloatStyleValue.left;
		firstLetterContainer.style.width = DimensionStyleValue.length(px(400));
		firstLetterContainer.style.height = DimensionStyleValue.length(px(50));
		//firstLetterContainer.style.fontFamily = [FontFamilyStyleValue.familyName("Magneto Gras")];
		//firstLetterContainer.style.fontVariant = FontVariantStyleValue.smallCaps;
		
		var textBlock:ContainerDOMElement = getContainer();
		
		//textBlock.style.whiteSpace = WhiteSpaceStyleValue.pre;
	
		
		textBlock.style.textIndent = TextIndentStyleValue.length(px(150));
		//firstLetterContainer.style.clear = ClearStyleValue.right;
		textBlock.style.textAlign = TextAlignStyleValue.justify;
		
			
		var getDefaultStyleProxy:DOMElement->Void = getDefaultStyle;
		var refreshProxy:Dynamic->Void = refresh;
		
		 _footer = getGraph();
		_footer.style.width = DimensionStyleValue.percent(100);
		_footer.style.height = DimensionStyleValue.length(px(100));
		_footer.style.marginTop = MarginStyleValue.length(px(0));
		
		var mainCont:ContainerDOMElement = _mainContainer;
		var foot:GraphicDOMElement = _footer;
		
		//headerContainer.style.position = absolute;
		//headerContainer.style.left = PositionOffsetStyleValue.auto;
		//headerContainer.style.right = PositionOffsetStyleValue.length(px(10));
		//headerContainer.style.display = inlineBlock;
		
		textContainer.style.position = relative;
		//textContainer.style.whiteSpace = WhiteSpaceStyleValue.pre;
		//textContainer.style.top = PositionOffsetStyleValue.length(px(500));
		//textContainer.style.left = PositionOffsetStyleValue.length(px(150));
textBlock.addText(new TextElement("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus facilisis tortor sodales lacus pretium scelerisque dapibus est rhoncus. Aenean feugiat nulla vel libero imperdiet et iaculis nisl tristique. Pellentesque congue varius consectetur. Sed vulputate tristique ante, at ullamcorper odio adipiscing vitae. Cras interdum blandit ultricies. Pellentesque id lacus orci. Sed volutpat mi vel odio viverra molestie. Fusce rutrum purus accumsan lectus venenatis mattis at vel eros. Sed ac scelerisque neque. Donec et mi mollis ligula imperdiet euismod. Nunc ac consectetur orci. Morbi a enim lacus. Pellentesque dolor massa, vestibulum vitae placerat pretium, gravida suscipit nulla. Pellentesque est ipsum, egestas ut ullamcorper bibendum, dapibus at erat. Morbi purus lectus, aliquam at molestie in, sagittis ac magna. "));
		
			var image:ImageDOMElement = new ImageDOMElement();
			
			ResourceLoaderManager.loadImage("testPicture.jpg", function(picture) {
		//	mainCont.addChild(headerContainer);
		//	textBlock.addChild(firstLetterContainer);
			textBlock.addChild(textContainer);
		//	textContainer.style.position = relative;
			textBlock.addChild(headerContainer);
		textBlock.addChild(picture);
		
			headerContainer.style.display = inlineBlock;
			
			//textBlock.style.float = FloatStyleValue.left;
			//textContainer.style.position = PositionStyleValue.absolute;
			
			//textBlock.style.fontFamily = [FontFamilyStyleValue.familyName("Blackoak Std")];
			//mainCont.addChild(headerContainer);
			mainCont.addChild(textBlock);
			mainCont.addChild(foot);
			//foot.style.position = absolute;
			//mainCont.style.position = PositionStyleValue.relative;
			//mainCont.style.top = PositionOffsetStyleValue.length(px(500));
			//foot.style.position = absolute;
			
			getDefaultStyleProxy(picture);
			
			picture.onMouseDown = function(event) {
				//picture.style.width = DimensionStyleValue.length(px(500));
				
				textBlock.style.lineHeight = LineHeightStyleValue.length(px(50));
				textBlock.style.fontSize = FontSizeStyleValue.length(px(25));
			
			
			//refreshProxy(null);
			}
			picture.onMouseOver = function(event) {
				picture.style.marginRight = MarginStyleValue.length(px(100));
			}
			
			picture.onMouseOut = function(event) {
				picture.style.marginRight = MarginStyleValue.length(px(0));
			}
			
			picture.style.width = DimensionStyleValue.length(px(100));
			picture.style.height = DimensionStyleValue.length(px(100));
			picture.style.display = DisplayStyleValue.inlineStyle;
			//picture.style.verticalAlign = VerticalAlignStyleValue.top;
			
			picture.style.width = DimensionStyleValue.length(px(200));
			picture.style.height = DimensionStyleValue.length(px(200));
		//	picture.style.display = DisplayStyleValue.inlineBlock;
			//picture.style.marginLeft = MarginStyleValue.percent(10);
			//picture.style.marginTop = MarginStyleValue.length(px(20));
			//picture.style.marginBottom = MarginStyleValue.length(px(20));
			//picture.style.position = PositionStyleValue.absolute;
			
		
	
			//refreshProxy(null);
		
		}, function(event) { }, image );
		
	/**	_mainContainer.addChild(headerContainer);
		_mainContainer.addChild(_footer);
		_mainContainer.addChild(textBlock);
			textBlock.addChild(textContainer);
	textContainer.addChild(firstLetterContainer);*/
			
		var viewPort:Viewport = new Viewport();
		
		var browserWidth:Int = viewPort.width;
		var browserHeight:Int = viewPort.height;
		
		//_mainContainer.style.computedStyle.lineHeight = 70;
		//bodyDOMElement.style.layout( { width:browserWidth, height:browserHeight, isWidthAuto:false, isHeightAuto:false, globalX:0, globalY:0 }, {width:browserWidth, height:browserHeight, globalX:0, globalY:0, isWidthAuto:false, isHeightAuto:false}, {width:browserWidth, height:browserHeight, globalX:0, globalY:0, isWidthAuto:false, isHeightAuto:false}, bodyDOMElement.style.fontMetrics);
			paint(_footer, 0xBBBBBB);
				paint(_header, 0xCCCCCC);
	}
	
	
	private function paint(domElement:GraphicDOMElement, color:Int):Void
	{
		domElement.clear();
		domElement.beginFill(FillStyleValue.monochrome( { color:color, alpha:100 } ), LineStyleValue.none);
		domElement.drawRect(0, 0, domElement.width, domElement.height);
		domElement.endFill();
		domElement.alpha = 0.6;
		
	}
	
	private function refresh(event:Dynamic = null)
	{
		var viewPort:Viewport = new Viewport();
		
		var browserWidth:Int = viewPort.width;
		var browserHeight:Int = viewPort.height;
		
		//_mainContainer.style.computedStyle.lineHeight = 70;
		_mainContainer.style.layout( { width:browserWidth, height:browserHeight, isWidthAuto:false, isHeightAuto:false, globalX:0, globalY:0 }, {width:browserWidth, height:browserHeight, globalX:0, globalY:0, isWidthAuto:false, isHeightAuto:false}, {width:browserWidth, height:browserHeight, globalX:0, globalY:0, isWidthAuto:false, isHeightAuto:false}, _mainContainer.style.fontMetrics);
	
	//	paint(_background, 0x222222);
	//	paint(_siteBackground, 0xFFFFFF);
		paint(_header, 0xDDDDDD);
	//	paint(_navigation, 0xDDDDDD);
	//	paint(_siteRightBackground, 0xDDDDDD);
	
	//	paint(_siteLeftFloatBackground, 0xBBBBBB);
	//	paint(_siteLeftAfterFloatBackground, 0x00000);
	//	paint(_siteLeftAfterFloatBackground2, 0x00000);
	//	paint(_siteLeftAfterFloatBackground3, 0x222222);
	//	paint(_insetGraphicElement, 0xFF0000);
	}
	
	private function attach(domElement:DOMElement):Void
	{
		
	}
	
	private function getContainer():ContainerDOMElement
	{
		var ret:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(neutral));
		getDefaultStyle(ret);
		
		ret.x = 0;
		ret.y = 0;
		return ret;
	}
	

	
	private function getGraph():GraphicDOMElement
	{
		
		
		var ret:GraphicDOMElement = new GraphicDOMElement();
		
		getDefaultStyle(ret);
		
		return ret;
	}
	
	
	private function getDefaultStyle(domElement:DOMElement):Void
	{
			domElement.style.marginLeft = MarginStyleValue.length(px(0));
			domElement.style.marginRight = MarginStyleValue.length(px(0));
			domElement.style.marginTop = MarginStyleValue.length(px(0));
			domElement.style.marginBottom = MarginStyleValue.length(px(0));
			
			domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
			domElement.style.paddingRight = PaddingStyleValue.length(px(0));
			domElement.style.paddingTop = PaddingStyleValue.length(px(0));
			domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
			
			domElement.style.top = PositionOffsetStyleValue.auto;
			domElement.style.left = PositionOffsetStyleValue.auto;
			domElement.style.right = PositionOffsetStyleValue.auto;
			domElement.style.bottom  = PositionOffsetStyleValue.auto;
			
			domElement.style.minWidth = ConstrainedDimensionStyleValue.none;
			domElement.style.maxWidth = ConstrainedDimensionStyleValue.none;
			domElement.style.minHeight = ConstrainedDimensionStyleValue.none;
			domElement.style.maxHeight = ConstrainedDimensionStyleValue.none;
			

			
			domElement.style.fontSize = FontSizeStyleValue.length(px(12));
			domElement.style.lineHeight = LineHeightStyleValue.normal;
			domElement.style.fontWeight = FontWeightStyleValue.normal;
			domElement.style.fontStyle = FontStyleStyleValue.normal;
			domElement.style.fontFamily = [FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)];
			domElement.style.fontVariant = FontVariantStyleValue.normal;
			domElement.style.textTransform = TextTransformStyleValue.none;
			domElement.style.letterSpacing = LetterSpacingStyleValue.normal;
			domElement.style.wordSpacing = WordSpacingStyleValue.normal;
			domElement.style.textIndent = TextIndentStyleValue.length(px(0));
			domElement.style.whiteSpace = WhiteSpaceStyleValue.normal;
			domElement.style.textAlign = TextAlignStyleValue.left;
			
			domElement.style.verticalAlign = VerticalAlignStyleValue.baseline;
			
			domElement.style.color = ColorValue.keyword(ColorKeywordValue.black);
			
			domElement.style.display = block;
			
			domElement.style.position = staticStyle;
			
			domElement.style.width = DimensionStyleValue.auto;
			domElement.style.height = DimensionStyleValue.auto;
			
			domElement.style.float = FloatStyleValue.none;
			domElement.style.clear = ClearStyleValue.none;
			
			var computedStyle:ComputedStyleData = {
			width : 0,
			height : 0,
			minHeight : 0,
			maxHeight : 0,
			minWidth : 0,
			maxWidth : 0,
			marginLeft : 0,
			marginRight : 0,
			marginTop : 0,
			marginBottom : 0,
			paddingLeft : 0,
			paddingRight : 0,
			paddingTop : 0,
			paddingBottom : 0,
			left: 0,
			right: 0,
			top: 0,
			bottom : 0,
			clear : ClearStyleValue.none,
			float : FloatStyleValue.none,
			display : DisplayStyleValue.block,
			position: PositionStyleValue.staticStyle,
			verticalAlign : 0.0,
			fontSize:12.0,
			lineHeight:14.0,
			fontWeight:FontWeightStyleValue.normal,
			fontStyle:FontStyleStyleValue.normal,
			fontFamily:[FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.serif)],
			fontVariant:FontVariantStyleValue.normal,
			textTransform:TextTransformStyleValue.none,
			letterSpacing:0,
			wordSpacing:0,
			textIndent:0,
			whiteSpace:WhiteSpaceStyleValue.normal,
			textAlign:TextAlignStyleValue.left,
			color:0
			}
			
			domElement.style.computedStyle = computedStyle;
		
	}
	
}