/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.as3;

import cocktail.domElement.DOMElement;
import cocktail.geom.Matrix;
import cocktail.geom.GeomData;
import cocktailCore.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import haxe.Log;

#if (flash9)
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;
#end

/**
 * This is the Flash AS3 implementation of the Style object.
 * 
 * It constructs the font metrics object using Flash text engine
 * font metrics. It uses the style object font size and font family
 * value to determine the font metrics
 * 
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private static inline var SERIF_GENERIC_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "_typewriter";
	
	/**
	 * The flash text block used to create the 
	 * flash text line that will be wrapped in
	 * TextFragmentDOMElement
	 */
#if (flash9)
	private var _textBlock:TextBlock;
#end
	
	
	public function new(domElement:DOMElement) 
	{
#if (flash9)
	   _textBlock = new TextBlock();
#end
		
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN NATIVE SETTERS
	// apply the properties to the native flash DisplayObject
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setNativeX(domElement:DOMElement, x:Int):Void
	{
		super.setNativeX(domElement, x);
		domElement.nativeElement.x = x;
	}
	
	override public function setNativeY(domElement:DOMElement, y:Int):Void
	{
		super.setNativeY(domElement, y);
		domElement.nativeElement.y = y;
	}
	
	override public function setNativeWidth(width:Int):Void
	{
		super.setNativeWidth(width);
		domElement.nativeElement.width = width;
	}
	
	override public function setNativeHeight(height:Int):Void
	{
		super.setNativeHeight(height);
		domElement.nativeElement.height = height;
	}
	
	override public function setNativeOpacity(opacity:Float):Void
	{
		super.setNativeOpacity(opacity);
		domElement.nativeElement.alpha = opacity;
	}
	
	override public function setNativeVisibility(visible:Bool):Void
	{
		super.setNativeVisibility(visible);
		domElement.nativeElement.visible = visible;
	}
	

#if (flash9)
	/**
	 * when the matrix is set, update also
	 * the values of the native flash matrix of the
	 * native DisplayObject
	 * @param	matrix
	 */
	override public function setNativeMatrix(matrix:Matrix):Void
	{
		//concenate the new matrix with the base matrix of the DOMElement
		var concatenatedMatrix:Matrix = getConcatenatedMatrix(matrix);
		
		//get the data of the abstract matrix
		var matrixData:MatrixData = concatenatedMatrix.data;
		
		//create a native flash matrix with the abstract matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
	
		//apply the native flash matrix to the native flash DisplayObject
		_domElement.nativeElement.transform.matrix = nativeTransformMatrix;
		
		super.setNativeMatrix(concatenatedMatrix);
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Returns a font metrics data object created using font metrics
	 * provided by the flash text engine. The font metrics are 
	 * processed using the styles of the DOMElement. The
	 * font metrics are provided for a given font at a given size
	 */
	override private function getFontMetricsData():FontMetricsData
	{
		//create the font metrics object only if null,
		//else it is already cached
		if (_fontMetrics == null)
		{
			//the flash object used to access flash font metrics
			var elementFormat:ElementFormat = new ElementFormat();
			
			//set font name
			var fontDescription:FontDescription = new FontDescription();
			fontDescription.fontName = getNativeFontFamily(this._fontFamily);
			elementFormat.fontDescription = fontDescription;
			
			//set font size used for the font metrics 
			elementFormat.fontSize = this._computedStyle.fontSize;
			
			//get the ascent (height above the baseline) and descent (height
			//below the baseline) from the flash font metrics
			var ascent:Float = Math.abs(elementFormat.getFontMetrics().emBox.top);
			var descent:Float = Math.abs(elementFormat.getFontMetrics().emBox.bottom);
			
			//get the x height (the height of a lower-case "x")
			var xHeight:Int = getXHeight(elementFormat.clone());
		
			var spaceWidth:Int = getSpaceWidth(elementFormat.clone());
			
			_fontMetrics = {
				fontSize:_computedStyle.fontSize,
				ascent:Math.round(ascent),
				descent:Math.round(descent),
				xHeight:xHeight,
				spaceWidth:spaceWidth,
				superscriptOffset:Math.round(elementFormat.getFontMetrics().superscriptOffset),
				subscriptOffset:Math.round(elementFormat.getFontMetrics().subscriptOffset),
				underlineOffset:Math.round(elementFormat.getFontMetrics().underlineOffset)
			};
		}
		
		return _fontMetrics;
	}
#end	
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * Concatenate the new matrix with the "base" matrix of the DOMElement
	 * where only translations (the x and y of the DOMElement) and scales
	 * (the width and height of the DOMElement) are applied.
	 * It is neccessary in flash to do so to prevent losing the x, y, width
	 * and height applied during layout
	 */
	private function getConcatenatedMatrix(matrix:Matrix):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		currentMatrix.concatenate(matrix);
		currentMatrix.translate(this._nativeX, this._nativeY);
		return currentMatrix;
	}
	
#if (flash9)
	/**
	 * Return a flash FontWeight object from
	 * the font weight style of the DOMElement
	 */
	private function getNativeFontWeight(fontWeight:FontWeightStyleValue):FontWeight
	{
		var nativeFontWeight:FontWeight;
		
		switch (fontWeight)
		{
			case bold:
				nativeFontWeight = FontWeight.BOLD;
				
			case normal:
				nativeFontWeight = FontWeight.NORMAL;
		}
		
		return nativeFontWeight;
	}
	
	/**
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names.
	 * @param	value an array which may contain any combination of generic
	 * font family name and font family name
	 * @return a comma separated list of font, generally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	private function getNativeFontFamily(value:Array<FontFamilyStyleValue>):String
	{
		var fontFamily:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String;
			
			switch (value[i])
			{
				case FontFamilyStyleValue.familyName(name):
					fontName = name;
				
				case FontFamilyStyleValue.genericFamily(genericName):
					switch (genericName)
					{
						case GenericFontFamilyValue.serif:
							fontName = SERIF_GENERIC_FONT_NAME;
						
						case GenericFontFamilyValue.sansSerif:
							fontName = SANS_SERIF_GENERIC_FONT_NAME;
							
						case GenericFontFamilyValue.monospace:
							fontName = MONOSPACE_GENERIC_FONT_NAME;
					}
			}
			
			fontFamily += fontName;
			
			if (i < value.length - 1)
			{
				fontFamily += ",";
			}
		}
		
		return fontFamily;
	}
	
	/**
	 * return the x height of the font which is equal to 
	 * the height of a lower-case 'x'.
	 */
	private function getXHeight(elementFormat:ElementFormat):Int
	{
		_textBlock.content = new TextElement("x", elementFormat);
		var textLine:TextLine = _textBlock.createTextLine(null, 10000);
		var descent:Float = textLine.descent;
		var top:Float = Math.abs(textLine.getAtomBounds(0).top);
		return Math.round(top - descent);
	}
	
	/**
	 * Return the width of a space character for the given font
	 * at the given size
	 */
	private function getSpaceWidth(elementFormat:ElementFormat):Int
	{
		_textBlock.content = new TextElement(" ", elementFormat);
		
		return Math.round(_textBlock.createTextLine(null, 10000, 0.0, true).getAtomBounds(0).width);
	}
#end
}