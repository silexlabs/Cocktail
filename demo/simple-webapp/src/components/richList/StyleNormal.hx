/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktailCore.style.StyleData;

// RichList
import components.richList.RichListModels;

//Iphone
import Utils;

/**
 * This class defines the styles used by the normal RichList,
 * i.e. a list with each cell containing a text and an image on the same line, and having each cell under the previous one
 * 
 * @author Raphael Harmel
 */

class StyleNormal
{

	/**
	 * initializes Style
	 * 
	 * @param	domElement
	 */
	public static function initStyle(domElement:DOMElement):Void
	{
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
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		initStyle(domElement);

		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		
		//domElement.style.top = PositionOffsetStyleValue.length(px(0));
		//domElement.style.left = PositionOffsetStyleValue.length(px(0));
		//domElement.style.right = PositionOffsetStyleValue.length(px(0));
		//domElement.style.bottom  = PositionOffsetStyleValue.length(px(0));
		//
		//domElement.style.minWidth = ConstrainedDimensionStyleValue.none;
		//domElement.style.maxWidth = ConstrainedDimensionStyleValue.none;
		//domElement.style.minHeight = ConstrainedDimensionStyleValue.none;
		//domElement.style.maxHeight = ConstrainedDimensionStyleValue.none;
		
		//domElement.style.display = block;
		//domElement.style.position = staticStyle;
		
		//domElement.style.width = DimensionStyleValue.auto;
		//domElement.style.height = DimensionStyleValue.auto;
		
		//domElement.style.float = FloatStyleValue.none;
		//domElement.style.clear = ClearStyleValue.none;
	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:ContainerDOMElement):Void
	{
		initStyle(domElement);
		getDefaultStyle(domElement);

		domElement.style.paddingLeft = PaddingStyleValue.length(px(8));
		domElement.style.paddingRight = PaddingStyleValue.length(px(8));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(8));
				
		//domElement.style.position = absolute;
		domElement.style.color = ColorValue.hex('#666666');
		//domElement.style.width = DimensionStyleValue.percent(100);


		// create line to separate cells
		//var line:GraphicDOMElement;
		//line = createLine(0xDDDDDD);
		
		//domElement.removeChild(line);
		//domElement.addChild(line);
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellImageStyle(domElement:DOMElement):Void
	{
		initStyle(domElement);
		getDefaultStyle(domElement);
		//domElement.style.position = absolute;

		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		domElement.style.float = FloatStyleValue.right;
		
		domElement.style.height = DimensionStyleValue.length(px(16));
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:DOMElement):Void
	{
		initStyle(domElement);
		//getDefaultStyle(domElement);
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Helvetica'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.fontVariant = FontVariantStyleValue.normal;
		domElement.style.textTransform = TextTransformStyleValue.none;
		domElement.style.letterSpacing = LetterSpacingStyleValue.normal;
		domElement.style.wordSpacing = WordSpacingStyleValue.normal;
		domElement.style.textIndent = TextIndentStyleValue.length(px(0));
		domElement.style.whiteSpace = WhiteSpaceStyleValue.normal;
		domElement.style.textAlign = TextAlignStyleValue.left;
		
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		
		domElement.style.color = ColorValue.hex('#666666');
		domElement.style.width = DimensionStyleValue.percent(100);
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:ContainerDOMElement):Void
	{
		initStyle(domElement);
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('#333333');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:ContainerDOMElement):Void
	{
		initStyle(domElement);
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('#666666');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:ContainerDOMElement):Void
	{
		initStyle(domElement);
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('#000000');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:ContainerDOMElement):Void
	{
		initStyle(domElement);
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('#333333');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	domElement
	 */
	public static function getCellLineStyle(domElement:DOMElement):Void
	{
		initStyle(domElement);

		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(1));
	}
	
	/**
	 * Creates a line.
	 * 
	 * @param	color
	 * @return
	 */
	/*private static function createLine(color:Int):GraphicDOMElement
	{
		initStyle(domElement);

		var line:GraphicDOMElement = Utils.getGraphic();
		getCellLineStyle(line);
		Utils.fillGraphic(line, color);
		
		return(line);
	}*/
	
	/**
	 * Adds a line. Used to split each cell.
	 * 
	 * @param	domElement
	 */
	/*private static function addLineAgain(domElement:ContainerDOMElement)
	{
		initStyle(domElement);

		// create line to separate cells
		var line:GraphicDOMElement;
		line = createLine(0xDDDDDD);
		
		domElement.removeChild(line);
		domElement.addChild(line);
	}*/
}
