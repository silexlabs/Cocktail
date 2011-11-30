/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style;
import cocktail.domElement.DOMElement;
import cocktail.unit.UnitData;

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Represents the width, height of a DOMElement's
	 * parent content, and it's global position, relative
	 * to the root DOMElement.
	 * Specify for each dimension if it is 'auto', 
	 * meaning it depends on its content
	 */
	typedef ContainingDOMElementData = {
		var width:Int;
		var isWidthAuto:Bool;
		var height:Int;
		var isHeightAuto:Bool;
		var globalX:Int;
		var globalY:Int;
	}
	
	/**
	 * Stores all the computed styles
	 * of a DOMElement as they are 
	 * used multiple times when applying
	 * styles
	 */
	typedef ComputedStyleData = {
		
		/**
		 * content dimensions
		 */
		var width:Int;
		var height:Int;
		
		/**
		 * content dimensions constraints
		 */
		var minWidth:Int;
		var maxWidth:Int;
		var maxHeight:Int;
		var minHeight:Int;
		
		/**
		 * margins
		 */
		var marginLeft:Int;
		var marginRight:Int;
		var marginTop:Int;
		var marginBottom:Int;
		
		/**
		 * paddings
		 */
		var paddingLeft:Int;
		var paddingRight:Int;
		var paddingTop:Int;
		var paddingBottom:Int;
		
		/**
		 * position offset
		 */
		var left:Int;
		var right:Int;
		var top:Int;
		var bottom:Int;
		
		/**
		 * display
		 */
		var display:DisplayStyleValue;
		var float:FloatStyleValue;
		var clear:ClearStyleValue;
		var position:PositionStyleValue;
		var lineHeight:Float;
		
		/**
		 * font
		 */
		var fontSize:Float;
		var fontWeight:FontWeightStyleValue;
		var fontStyle:FontStyleStyleValue;
		var fontFamily:Array<FontFamilyStyleValue>;
		var fontVariant:FontVariantStyleValue;
		
		/**
		 * text
		 */
		var textTransform:TextTransformStyleValue;
		var letterSpacing:Int;
		var verticalAlign:Float;
		var wordSpacing:Int;
		var textIndent:Int;
		var whiteSpace:WhiteSpaceStyleValue;
		var textAlign:TextAlignStyleValue;
		var color:Int;
		
	}
	
	/**
	 * Contains the data necessary to place
	 * a DOMElement in flow
	 */
	typedef FlowData = {
		/**
		 * the x position where the next in flow DOMElement
		 * should be
		 */
		var x:Int;
		
		/**
		 * the y position where the next in flow DOMElement
		 * should be
		 */
		var y:Int;
		
		/**
		 * The x offset applied to each starting line
		 * (matches the containing DOMElement left padding)
		 */
		var xOffset:Int;
		
		/**
		 * The y offset applied to the formatting context
		 * (matches the containing DOMElement top padding)
		 */
		var yOffset:Int;
		
		/**
		 * The accumulated height of all the in flow DOMElements
		 * (includes paddings and margins)
		 */
		var totalHeight:Int;
	}
	
	/**
	 * Represents the left and right
	 * floats registered for a 
	 * container DOMElement
	 */
	typedef FloatsData = {
		var left:Array<FloatData>;
		var right:Array<FloatData>;
	}
	
	/**
	 * Represents the coordinates and
	 * dimensions of the float in its
	 * parent coordinate space
	 */
	typedef FloatData = {
		var x:Int;
		var y:Int;
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Given a font family and a font size
	 * provided by the DOMElement's styles, 
	 * this structures return metrics info
	 * on the font
	 */
	typedef FontMetricsData = {
		
		/**
		 * The font size of 
		 * the DOMElement, in pixels
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
		var ascent:Int;
		
		/**
		 * A characteristic height
		 * of the font below the 
		 * baseline defined by
		 * the font creator. This is a metric
		 * for the font has a whole, 
		 * not specific to any glyphs
		 */
		var descent:Int;
		
		/**
		 * This is a standard metrics used 
		 * to define a font size. Represents
		 * the height of a lowercase "x" glyph
		 * at the given font size
		 */ 
		var xHeight:Int;
		
		/**
		 * A suggested offset to apply
		 * from the baseline for subscript
		 * glyphs
		 */
		var subscriptOffset:Int;
		
		/**
		 * A suggested offset to apply
		 * from the baseline for superscript
		 * glyphs
		 */
		var superscriptOffset:Int;
		
		/**
		 * A suggested offset to apply from
		 * the baseline when drawing underlines
		 */
		var underlineOffset:Int;
	}
	
	/**
	 * Defines a DOMElement added to a LineBox
	 * and its type
	 */
	typedef LineBoxElementData = {
		var domElement:DOMElement;
		var domElementType:InlineBoxValue;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lists all the different consituant
	 * of a plain text, including 
	 * controls characters
	 */
	enum TextFragmentValue {
		
		/**
		 * a word, surrounded by
		 * spaces
		 */
		word(value:String);
		
		/**
		 * represents one
		 * space which can be 
		 * between 2 words or among
		 * a space sequence
		 */
		space;
		
		/**
		 * a tabulation
		 */
		tab;
		
		/**
		 * a line feed (starts
		 * a new line)
		 */
		lineFeed;
	}
	
	/**
	 * Lists the different kind of
	 * boxes that can be added in an
	 * inline formatting context.
	 * 
	 * Spaces and tabs are separated
	 * from other domElement as they
	 * can influence a linebox layout
	 * once it is complete
	 */
	enum InlineBoxValue {
		domElement;
		space;
		tab;
	}
	
	
		// FONT STYLES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Controls the em box size
	 * of a font.
	 */
	enum FontSizeStyleValue {
		
		/**
		 * absolute font size
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage of the containing block
		 * font size
		 */
		percentage(value:Int);
		
		/**
		 * use a keyword indexed to a specified dimension.
		 * For instance in a desktop browser, an absolute
		 * size of medium maps to 16 pixels.
		 */
		absoluteSize(value:FontSizeAbsoluteSizeValue);
		
		/**
		 * Define if the font should be larger or smaller
		 * than its parent's font. The closest absolute
		 * size is determined using the parent computed
		 * font size and this absolute size is used as
		 * the font size
		 */
		relativeSize(value:FontSizeRelativeSizeValue);
		
		
	}
	
	/**
	 * Controls the weight of the
	 * font
	 */
	enum FontWeightStyleValue {
		normal;
		bold;
	}
	
	/**
	 * Controls wether the font
	 * is displayed in italic
	 */
	enum FontStyleStyleValue {
		normal;
		italic;
	}
	
	/**
	 * Lists the type of font which can
	 * be affected to a text 
	 */
	enum FontFamilyStyleValue {
		
		/**
		 * A custom font family name
		 */
		familyName(name:String);
		
		/**
		 * A generic family name, most
		 * likely used as a fallback
		 * if a more specific font 
		 * wasn't available
		 */
		genericFamily(genericName:GenericFontFamilyValue);
	}
	
	/**
	 * Lists the available generic 
	 * font families
	 */
	enum GenericFontFamilyValue {
		serif;
		sansSerif;
		monospace;
	}
	
	/**
	 * Controls wether text is
	 * displayed as small caps, where
	 * lowercase charachters look like
	 * smaller uppercase characters
	 */
	enum FontVariantStyleValue {
		normal;
		smallCaps;
	}
	
		// TEXT STYLES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Controls how white space inside
	 * a DOMElement is handled
	 */
	enum WhiteSpaceStyleValue {
		
		/**
		 * This value directs user agents to collapse sequences
		 * of white space, and break lines as necessary to fill line boxes.
		 */
		normal;
		
		/**
		 * This value prevents user agents from collapsing
		 * sequences of white space. Lines are only broken at
		 * preserved newline characters.
		 */
		pre;
		
		/**
		 * This value collapses white space as for 'normal',
		 * but suppresses line breaks within text.
		 */
		nowrap;
		
		/**
		 * This value prevents user agents from collapsing sequences
		 * of white space. Lines are broken at preserved newline
		 * characters, and as necessary to fill line boxes.
		 */
		preWrap;
		
		/**
		 * This value directs user agents to collapse sequences of white space.
		 * Lines are broken at preserved newline characters,
		 * and as necessary to fill line boxes.
		 */
		preLine;
	}
	
	/**
	 * Controls the amount of space
	 * between 2 letter in a text.
	 */
	enum LetterSpacingStyleValue {
		/**
		 * Use the default spacing of
		 * the chosen font
		 */
		normal;
		
		/**
		 * A length to add to the 
		 * default spacing of the font,
		 * might be negative.
		 */
		length(value:LengthValue);
	}
	
	/**
	 * Controls the amount of space between
	 * two words in a text
	 */
	enum WordSpacingStyleValue {
		
		/**
		 * Use the default inter-word
		 * spacing of the chosen font
		 */
		normal;
		
		/**
		 * A length to add to each space
		 * character, might be negative
		 */
		length(value:LengthValue);
	}
	
	/**
	 * Controls the indentation of the
	 * first line of text in a block of text
	 * with respect to the containing block
	 */
	enum TextIndentStyleValue {
		
		/**
		 * An absolute value for the text indentation
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage of the containing block
		 * width
		 */
		percentage(value:Int);
	}
	
	/**
	 * Controls how inline DOMElement inside
	 * a block container is aligned
	 */
	enum TextAlignStyleValue {
		left;
		right;
		center;
		justify;
	}
	
	/**
	 * Controls wether all charachters
	 * in a text are transformed to
	 * uppercase, lowercase or capitalised
	 * (only first letter of each word is
	 * set to uppercase)
	 */
	enum TextTransformStyleValue {
		capitalize;
		uppercase;
		lowercase;
		none;
	}
	
	/**
	 * On a container DOMElement with inline level
	 * children, this style controls the minimum height
	 * of each line 
	 * 
	 * On a non-embedded inline DOMElement, it controls
	 * the height of the DOMElement, used to calculate
	 * its line height
	 */
	enum LineHeightStyleValue {
		
		/**
		 * Use a "reasonnable" line height value which
		 * is equal to the font size.
		 */
		normal;
		
		/**
		 * With this value, the computed value of the line height 
		 * is equal to this number multiplied by the font size
		 */
		number(value:Float);
		
		/**
		 * absolute line height value
		 */
		length(value:LengthValue);
		
		/**
		 * With this value, the computed value of the line height 
		 * is equal to this percentage multiplied by the font size
		 */
		percentage(value:Int);
		
		
	}
	
	/**
	 * Controls the vertical alignement of an 
	 * inline DOMElement in its containing
	 * DOMElement
	 */
	enum VerticalAlignStyleValue {
		
		/**
		 * Align the baseline of the box with the baseline
		 * of the parent box. If the box does not have a
		 * baseline, align the bottom margin edge with 
		 * the parent's baseline.
		 */
		baseline;
		
		/**
		 * Lower the baseline of the box to the proper 
		 * position for subscripts of the parent's box
		 */
		sub;
		
		/**
		 * Raise the baseline of the box to the proper 
		 * position for superscripts of the parent's box.
		 * 
		 * n.b: appended 'Style' to 'super' because 'super'
		 * is a reserved HaXe word
		 */
		superStyle;
		
		/**
		 * Align the top of the aligned subtree with 
		 * the top of the line box.
		 */
		top;
		
		/**
		 * Align the top of the box with the top of the
		 * parent's content area
		 */
		textTop;
		
		/**
		 * Align the vertical midpoint of the box with the baseline
		 * of the parent box plus half the x-height of the parent.
		 */
		middle;
		
		/**
		 * Align the bottom of the aligned subtree with the 
		 * bottom of the line box.
		 */
		bottom;
		
		/**
		 * Align the bottom of the box with the bottom of the 
		 * parent's content area
		 */
		textBottom;
		
		/**
		 * a positive value raise the box, a
		 * negative lowers it, by taking the
		 * parent baseline as reference for
		 * 0%
		 */
		percent(value:Int);
		
		/**
		 * a positive value raise the box, a
		 * negative lowers it, by taking the
		 * parent baseline as reference for
		 * 0
		 */
		length(value:LengthValue);
		
	}
	
		// BOX STYLES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dimensions values for margin thickness
	 */
	enum MarginStyleValue {
		
		/**
		 * absolute thickness
		 */
		length(value:LengthValue);
		
		/**
		 * thickness relatvie to the
		 * parent DOMElement's widthor height
		 */
		percent(value:Int);
		
		/**
		 * Margin takes the remaining space
		 * in the parent DOMElement width or height
		 */
		auto;
	}
	
	/**
	 * Dimensions value for padding thickness
	 */
	enum PaddingStyleValue {
		
		/**
		 * absolute thickness
		 */
		length(value:LengthValue);
		
		/**
		 * thickness relative to the
		 * parent DOMElement width or height
		 */
		percent(value:Int);
	}
	
	/**
	 * The dimension of the content of 
	 * a DOMElement (without margins 
	 * and paddings)
	 */
	enum DimensionStyleValue {
		
		/**
		 * absolute value
		 */
		length(value:LengthValue);
		
		/**
		 * relative the parent DOMElement
		 * dimensions
		 */
		percent(value:Int);
		
		/**
		 * takes the remaining space in
		 * the parent element width or 
		 * height
		 */
		auto;
	}
	
		// DISPLAY STYLES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Display of a DOMElement in a 
	 * DOMElements flow
	 */
	enum DisplayStyleValue {
		
		/**
		 * add a line break before 
		 * and after the DOMElement. Act
		 * as a box with margins, paddings
		 * and dimensions
		 */
		block;
		
		/**
		 * Displays as block but is placed
		 * on the current line in the flow
		 */
		inlineBlock;
		
		/**
		 * Displayed on the current line. 
		 * Can only have horizontal margins
		 * and paddings
		 * 
		 * n.b : appended 'Style' to 'inline'
		 * because inline is a reserved HaXe 
		 * word
		 */
		inlineStyle;
		
		/**
		 * The DOMElement isn't displays
		 * and doesn't influence the flow
		 */
		none;
	}
	
	/**
	 * A floated DOMElement is pushed to the
	 * left-most or the right-most of its container
	 */
	enum FloatStyleValue {
		left;
		right;
		none;
	}
	
	/**
	 * A DOMElement with clearance cancels a preceding
	 * float. It is placed below any preceding left
	 * or right float that it clears
	 */
	enum ClearStyleValue {
		none;
		left;
		right;
		both;
	}
	
	/**
	 * Determine how a DOMElement is positioned relative
	 * to its ancestors
	 */
	enum PositionStyleValue {
		
		/**
		 * Appear after its parent in the flow, on a
		 * new line or the current one based on its
		 * display
		 * 
		 * n.b: appended 'Style' to 'static' because
		 * 'static' is a reserved HaXe word
		 */
		staticStyle;
		
		/**
		 * same as static but an offset can be applied
		 * with the top, left, right and bottom styles
		 * once the DOMElement is placed in the flow
		 */
		relative;
		
		/**
		 * The DOMElement is outside of the flow, it 
		 * is placed using its left, right, bottom and
		 * top offsets, its origin being its first ancestor
		 * with a position different from static
		 */
		absolute;
		
		/**
		 * The DOMElement is outside the flow, it
		 * is placed using its left, right, bottom
		 * and top offsets, its origin being the first
		 * DOMElement (the one at the top of the 
		 * hierarchy)
		 */
		fixed;
	}
	
	/**
	 * The offset applied to a DOMElement
	 * once positioned
	 */
	enum PositionOffsetStyleValue {
		
		/**
		 * absolute offset
		 */
		length(value:LengthValue);
		
		/**
		 * relative to the parent
		 * DOMElement width or heigt
		 */
		percent(value:Int);
		
		/**
		 * no offset
		 */
		auto;
	}
	
	
	/**
	 * The constraint applied to the content
	 * of a DOMElement contrained its max/min
	 * width or height
	 */
	enum ConstrainedDimensionStyleValue {
		
		/**
		 * absolute value
		 */
		length(value:LengthValue);
		
		/**
		 * relative to the parent DOMElement
		 * dimensions 
		 */
		percent(value:Int);
		
		/**
		 * No constraint is enforced
		 */
		none;
	}