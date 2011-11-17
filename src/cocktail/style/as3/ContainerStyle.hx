/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.as3;

import cocktail.domElement.DOMElement;
import cocktail.domElement.TextNode;
import cocktail.style.abstract.AbstractContainerStyle;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import flash.text.engine.CFFHinting;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import haxe.Log;



/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	/////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	////////////////////////////////
	
	override private function getFontMetrics():FontMetrics
	{
		var elementFormat:ElementFormat = new ElementFormat();
		
		var fontDescription:FontDescription = new FontDescription(getFontFamilyValue(this._fontFamily));


		var fontWeightValue:FontWeight;
		
		switch (_computedStyle.fontWeight)
		{
			case bold:
				fontWeightValue = FontWeight.BOLD;
				
			case normal:
				fontWeightValue = FontWeight.NORMAL;
		}
		
		fontDescription.fontWeight = fontWeightValue;
		
		elementFormat.fontDescription = fontDescription;
	
		
		elementFormat.fontSize = this._computedStyle.fontSize;
		
		/**var ascent:Int = Math.round(Math.abs(elementFormat.getFontMetrics().emBox.top));
		var descent:Int = Math.round(Math.abs(elementFormat.getFontMetrics().emBox.bottom));
		
		var leading:Int = Math.round(_computedStyle.lineHeight - (ascent + descent));
		
		var leadedAscent:Int = Math.round(ascent + leading/2);
		var leadedDescent:Int = Math.round(descent + leading / 2);
		*/
		var ascent:Float = Math.abs(elementFormat.getFontMetrics().emBox.top);
		var descent:Float = Math.abs(elementFormat.getFontMetrics().emBox.bottom);
		
		//Log.trace(ascent);
		var leading:Float = _computedStyle.lineHeight - (ascent + descent);
		//Log.trace(leading);
		//Log.trace(_computedStyle.lineHeight);
		//Log.trace(ascent);
		//Log.trace(descent);
		var leadedAscent:Float = ascent + leading/2;
		var leadedDescent:Float = descent + leading/2;
		//Log.trace(leadedAscent);
		
	//	Log.trace(_computedStyle.lineHeight);
		//Log.trace(leadedAscent);
		
		return {
			ascent:Math.round(leadedAscent),
			descent:Math.round(leadedDescent),
			xHeight:0,
			superscriptOffset:0,
			subscriptOffset:0,
			underlineOffset:Math.round(elementFormat.getFontMetrics().underlineOffset)
		};
	}
	
	/**
	 * !WARNING duplicated code
	 */
	private function getFontFamilyValue(value:Array<FontFamilyStyleValue>):String
	{
		var fontFamilyValue:String = "";
		
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
							fontName = "_serif";
						
						case GenericFontFamilyValue.sansSerif:
							fontName = "_sans";
							
						case GenericFontFamilyValue.monospace:
							fontName = "_typewriter";
					}
			}
			
			if (fontName.indexOf(" ") != -1)
			{
				fontName = "'" + fontName + "'";
			}
			
			fontFamilyValue += fontName;
			
			if (i < value.length - 1)
			{
				fontFamilyValue += ",";
			}
		}
		
		return fontFamilyValue;
	}
}