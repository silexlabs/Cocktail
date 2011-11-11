package cocktail.style;


	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Represents the width and height of a DOMElement's
	 * parent content, into which it can be placed
	 */
	typedef ContainingDOMElementDimensions = {
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Represents the dimensions of a DOMElement used
	 * as origin when positioning an absolutely
	 * positioned DOMElelement
	 */
	typedef AbsolutelyPositionedContainingDOMElementDimensions = {
		var globalX:Int;
		var globalY:Int;
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Stores all the computed styles
	 * of a DOMElement as they are 
	 * used multiple times when appliying
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
		var verticalAlign:Int;
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
		var wordSpacing:Int;
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
		 * The width of the content area of the containing
		 * DOMElement in which the flow occurs
		 */
		var containingBlockWidth:Int;
		
		/**
		 * The height of the content area of the containing
		 * DOMElement in which the flow occurs
		 */
		var containingBlockHeight:Int;
		
		/**
		 * The height of highest DOMElement in the current line
		 * (includes paddings and margins)
		 */
		var maxLineHeight:Int;
		
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
	typedef FontMetrics = {
		
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
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
		// FONT STYLES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lists the type of value which
	 * can define a text color
	 */
	enum ColorStyleValue {
		
		/**
		 * A numerical representation of a
		 * color (hex, RGB...)
		 */
		numeric(value:ColorValue);
		
		/**
		 * the color is chosen among a
		 * set of predefined colors
		 */ 
		keyword(value:ColorKeywordValue);
	}
	
	/**
	 * Lists the default available colors
	 */
	enum ColorKeywordValue {
		aqua;
		black;
		blue;
		fuchsia;
		gray;
		green;
		lime;
		maroon;
		navy;
		olive;
		orange;
		purple;
		red;
		silver;
		teal;
		white;
		yellow;
	}
	
	/**
	 * Controls the em box size
	 * of a font.
	 */
	enum FontSizeStyleValue {
		
		/**
		 * absolute font size
		 */
		length(value:LengthValue);
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
		 */
		_super;
		
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
		 * Doesn't have block's attributes
		 * such as margins, paddings...
		 */
		_inline;
		
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
		 */
		_static;
		
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
	
	
		// UNITS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lists the different types of 
	 * unit supported with an explicitly
	 * set length such as px, cm, em...
	 */
	enum LengthValue {
		
		/**
		 * pixel, 1px is equal to 0.75pt.
		 */
		px(value:Float);
		
		/**
		 * centimeters
		 */
		cm(value:Float);
		
		/**
		 * millimeters
		 */
		mm(value:Float);
		
		/**
		 * points, the points
		 * are equal to 1/72nd of 1in. 
		 */
		pt(value:Float);
		
		/**
		 * picas, 1pc is equal to 12pt.
		 */
		pc(value:Float);
		
		/**
		 * inches, 1in is equal to 2.54cm.
		 */
		_in(value:Float);
	}
	
	/**
	 * Lists the different color format supported.
	 * Each value describes one color
	 */
	enum ColorValue {
		
		/**
		 * each value (red, green and blue)
		 * must be an integer from 0 to 255
		 */
		RGB(red:Int, green:Int, blue:Int);
		
		/**
		 * The color value must be represented
		 * as 6 hexadecimal number string started
		 * with a "#" charachter.
		 * e.g : for red, #FF0000
		 */
		hex(value:String);
	}