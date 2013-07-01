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
class FontMetricsVO {
	
	/**
	 * The font size of 
	 * the htmlElement, in pixels
	 */
	public var fontSize:Float;
	
	/**
	 * A characteristic height
	 * of the font above the 
	 * baseline defined by
	 * the font creator. This is a metric
	 * for the font has a whole, 
	 * not specific to any glyphs
	 */
	public var ascent:Float;
	
	/**
	 * A characteristic height
	 * of the font below the 
	 * baseline defined by
	 * the font creator. This is a metric
	 * for the font has a whole, 
	 * not specific to any glyphs
	 */
	public var descent:Float;
	
	/**
	 * This is a standard metrics used 
	 * to define a font size. Represents
	 * the height of a lowercase "x" glyph
	 * at the given font size
	 */ 
	public var xHeight:Float;
	
	/**
	 * A suggested offset to apply
	 * from the baseline for subscript
	 * glyphs
	 */
	public var subscriptOffset:Float;
	
	/**
	 * A suggested offset to apply
	 * from the baseline for superscript
	 * glyphs
	 */
	public var superscriptOffset:Float;
	
	/**
	 * A suggested offset to apply from
	 * the baseline when drawing underlines
	 */
	public var underlineOffset:Float;
	
	/**
	 * the width of a space character for
	 * a given font at a given size
	 */
	public var spaceWidth:Float;
	
	/**
	 * Equal to the advance measure of the "0" (ZERO, U+0030) 
	 * glyph found in the font used to render it.
	 */
	public var zeroHeight:Float;
	
	public function new(fontSize:Float, ascent:Float, descent:Float, xHeight:Float, subscriptOffset:Float, superscriptOffset:Float,
	underlineOffset:Float, spaceWidth:Float, zeroHeight:Float)
	{
		this.fontSize = fontSize;
		this.ascent = ascent;
		this.descent = descent;
		this.xHeight = xHeight;
		this.subscriptOffset = subscriptOffset;
		this.superscriptOffset = superscriptOffset;
		this.underlineOffset = underlineOffset;
		this.spaceWidth = spaceWidth;
		this.zeroHeight = zeroHeight;
	}
}