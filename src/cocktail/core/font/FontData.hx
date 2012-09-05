/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.font;

/**
 * Given a font family and a font size
 * provided by the htmlElement's styles, 
 * this structures return metrics info
 * on the font
 */
class FontMetricsVO {
	
	/**
	 * The font size of 
	 * the htmlElement, in pixels
	 */
	public var fontSize(default, null):Float;
	
	/**
	 * A characteristic height
	 * of the font above the 
	 * baseline defined by
	 * the font creator. This is a metric
	 * for the font has a whole, 
	 * not specific to any glyphs
	 */
	public var ascent(default, null):Float;
	
	/**
	 * A characteristic height
	 * of the font below the 
	 * baseline defined by
	 * the font creator. This is a metric
	 * for the font has a whole, 
	 * not specific to any glyphs
	 */
	public var descent(default, null):Float;
	
	/**
	 * This is a standard metrics used 
	 * to define a font size. Represents
	 * the height of a lowercase "x" glyph
	 * at the given font size
	 */ 
	public var xHeight(default, null):Float;
	
	/**
	 * A suggested offset to apply
	 * from the baseline for subscript
	 * glyphs
	 */
	public var subscriptOffset(default, null):Float;
	
	/**
	 * A suggested offset to apply
	 * from the baseline for superscript
	 * glyphs
	 */
	public var superscriptOffset(default, null):Float;
	
	/**
	 * A suggested offset to apply from
	 * the baseline when drawing underlines
	 */
	public var underlineOffset(default, null):Float;
	
	/**
	 * the width of a space character for
	 * a given font at a given size
	 */
	public var spaceWidth(default, null):Float;
	
	public function new(fontSize:Float, ascent:Float, descent:Float, xHeight:Float, subscriptOffset:Float, superscriptOffset:Float,
	underlineOffset:Float, spaceWidth:Float)
	{
		this.fontSize = fontSize;
		this.ascent = ascent;
		this.descent = descent;
		this.xHeight = xHeight;
		this.subscriptOffset = subscriptOffset;
		this.superscriptOffset = superscriptOffset;
		this.underlineOffset = underlineOffset;
		this.spaceWidth = spaceWidth;
	}
}