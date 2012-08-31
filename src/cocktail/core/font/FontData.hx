/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.font;

/**
 * Given a font family and a font size
 * provided by the htmlElement's styles, 
 * this structures return metrics info
 * on the font
 */
typedef FontMetricsData = {
	
	/**
	 * The font size of 
	 * the htmlElement, in pixels
	 */
	var fontSize:Float;
	
	/**
	 * A characteristic height
	 * of the font above the 
	 * baseline defined by
	 * the font creator. This is a metric
	 * for the font has a whole, 
	 * not specific to any glyphs
	 */
	var ascent:Float;
	
	/**
	 * A characteristic height
	 * of the font below the 
	 * baseline defined by
	 * the font creator. This is a metric
	 * for the font has a whole, 
	 * not specific to any glyphs
	 */
	var descent:Float;
	
	/**
	 * This is a standard metrics used 
	 * to define a font size. Represents
	 * the height of a lowercase "x" glyph
	 * at the given font size
	 */ 
	var xHeight:Float;
	
	/**
	 * A suggested offset to apply
	 * from the baseline for subscript
	 * glyphs
	 */
	var subscriptOffset:Float;
	
	/**
	 * A suggested offset to apply
	 * from the baseline for superscript
	 * glyphs
	 */
	var superscriptOffset:Float;
	
	/**
	 * A suggested offset to apply from
	 * the baseline when drawing underlines
	 */
	var underlineOffset:Float;
	
	/**
	 * the width of a space character for
	 * a given font at a given size
	 */
	var spaceWidth:Float;
}