/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style;
import cocktail.domElement.DOMElement;
import cocktail.unit.UnitData;
import cocktail.geom.GeomData;
import cocktail.geom.Matrix;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.formatter.FormattingContext;
import cocktailCore.style.renderer.ElementRenderer;
import cocktailCore.style.renderer.InlineBoxRenderer;
import cocktailCore.style.renderer.TextRenderer;
	
	
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
		autoValue;
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
		autoValue;
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
		autoValue;
	}
	
		// VISUAL EFFECTS STYLES
//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Specifies wether the content of a block container
	 * is clipped when its content overflows
	 * the block container boxes.
	 * 
	 * A different value can be provided for x and y.
	 */
	typedef OverflowStyleData = {
		var x:OverflowStyleValue;
		var y:OverflowStyleValue;
	}
	
	/**
	 * Lists the values that x and
	 * y overflow can use
	 */
	enum OverflowStyleValue {
		
		/**
		 * This value indicates that content is not clipped,
		 * i.e., it may be rendered outside the block box. 
		 */
		visible;
		
		/**
		 * This value indicates that the content is clipped and that
		 * no scrolling user interface should be provided to
		 * view the content outside the clipping region. 
		 */
		hidden;
		
		/**
		 * This value indicates that the content is clipped and that if the
		 * containing block displays a vertical or horizontal scrollbar.
		 * The scrollbar is displayed even if the content of
		 * the box is not clipped
		 */
		scroll;
		
		/**
		 * The scrollbar are displayed as needed, only if a containing
		 * block's content overflows
		 */
		autoValue;
	}

	/**
	 * Specifies wether the DOMElement is
	 * displayed. A hidden DOMElement
	 * still affects layout
	 */
	enum VisibilityStyleValue {
		
		/**
		 * The DOMElement is visible
		 */
		visible;
		
		/**
		 * The DOMElement is invisible 
		 * (fully transparent, nothing is drawn),
		 * but still affects layout.
		 * Furthermore, children of the DOMElement will
		 * be visible if they have 'visibility: visible'.
		 */
		hidden;
	}
	
	/**
	 * Specifies the transparency of a DOMElement
	 * where 1.0 is opaque and 0 is transparent
	 */
	enum OpacityStyleValue {
		number(value:Float);
	}
	
	/**
	 * Specifiy a list of transormation to apply
	 * to the DOMElement. The transformation
	 * are applied in order. The final 
	 * transformation is obtained by performing
	 * a matrix concatenation of each entry in the list
	 */
	enum TransformStyleValue {
		
		/**
		 * no transformations
		 */
		none;
		
		/**
		 * A list of transformations
		 * to apply in order
		 */
		transformFunctions(transformFunctions:Array<TransformFunctionValue>);
		
	}
	
	/**
	 * The list of allowed transform functions to
	 * apply to a DOMElement
	 */
	enum TransformFunctionValue {
		
		/**
		 * specify a 2D transformation in the form of
		 * a transformation matrix
		 */
		matrix(data:MatrixData);
		
		/**
		 * specify a 2D translation by the vector [tx, ty]
		 */
		translate(tx:TranslationValue, ty:TranslationValue);
		
		/**
		 * specifies a translation by the given amount in the
		 * X direction
		 */
		translateX(tx:TranslationValue);
		
		/**
		 * specifies a translation by the given amount in the
		 * Y direction
		 */
		translateY(ty:TranslationValue);
		
		/**
		 * Specifies a 2D scale operation by the
		 * [sx, sy] scaling vector
		 */
		scale(sx:Float, sy:Float);
		
		/**
		 * Specifies a 2D scale operation by the
		 * [sx, 1] scaling vector
		 */
		scaleX(sx:Float);
		
		/**
		 * Specifies a 2D scale operation by the
		 * [1, sy] scaling vector
		 */
		scaleY(sy:Float);
		
		/**
		 * specifies a 2D rotation by the angle specified in the
		 * parameter about the origin of the element,
		 * as defined by the TransformOriginStyleValue property
		 */
		rotate(angle:AngleValue);
		
		/**
		 * specifies a skew transformation
		 * along the X axis by the given angle.
		 */
		skewX(angle:AngleValue);
		
		/**
		 * specifies a skew transformation
		 * along the Y axis by the given angle.
		 */
		skewY(angle:AngleValue);
		
		/**
		 * specifies a skew transformation 
		 * along the X and Y axes.
		 */
		skew(angleX:AngleValue, angleY:AngleValue);
	}
	
	/**
	 * The list of value allowed to 
	 * specify the amount of a translation
	 */
	enum TranslationValue {
		
		/**
		 * a length value
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage relative to the DOMElement
		 * dimensions
		 */
		percent(value:Int);
	}
	
	/**
	 * Specifies the origin of transformation
	 * for a DOMElement along the x and y
	 * axis
	 */
	typedef TransformOriginStyleData = {
		
		/**
		 * x axis origin
		 */
		var x:TransformOriginXStyleValue;
		
		/**
		 * y axis origin
		 */
		var y:TransformOriginYStyleValue;
		
	}
	
	/**
	 * The list of available transformation
	 * origin values for x axis
	 */
	enum TransformOriginXStyleValue {
		
		/**
		 * a length value
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage relative
		 * to the DOMElement's width
		 */
		percent(value:Int);
		
		/**
		 * same as 0%
		 */
		left;
		
		/**
		 * same as 50%
		 */
		center;
		
		/**
		 * same as 100%
		 */
		right;
	}
	
	/**
	 * The list of available transformation
	 * origin values for y axis
	 */
	enum TransformOriginYStyleValue {
		
		/**
		 * a length value
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage relative
		 * to the DOMElement's height
		 */
		percent(value:Int);
		
		/**
		 * same as 0%
		 */
		top;
		
		/**
		 * same as 50%
		 */
		center;
		
		/**
		 * same as 100%
		 */
		bottom;
	}
	
		// BACKGROUND STYLES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Sets the background color of a DOMElement. 
	 * The color is drawn behind any background images. 
	 */
	enum BackgroundColorStyleValue {
		colorValue(value:ColorValue);
	}
	
	/**
	 * Set a background image of a DOMElement. A DOMElement can
	 * have any number of background image.
	 * Images are drawn with the first specified one on top 
	 * (closest to the user) and each subsequent image behind
	 * the previous one.
	 */
	enum BackgroundImageStyleValue {
		none;
		image(value:ImageValue);
	}
	
	/**
	 * Specifies how background images are tiled after
	 * they have been sized and positioned
	 */
	typedef BackgroundRepeatStyleData = {
		
		/**
		 * horizontal repeat
		 */
		var x:BackgroundRepeatStyleValue;
		
		/**
		 * vertical repeat
		 */
		var y:BackgroundRepeatStyleValue;
	}
	
	/**
	 * The different repeat value for each direction
	 */
	enum BackgroundRepeatStyleValue {
		
		/**
		 * The background image is repeated as often
		 * as needed to cover the background
		 */
		repeat;
		
		/**
		 * The background image is repeated as often
		 * as needed to cover the background without
		 * being clipped and the images are spaced
		 * out to cover all the background
		 */
		space;
		
		/**
		 * The background image is repeated as often
		 * as needed to cover the background without
		 * being clipped and then the images are scaled
		 * to fill the background
		 */
		round;
		
		/**
		 * The background image is placed once and
		 * not repeated
		 */
		noRepeat;
	}
	
	/**
	 * If background images have been specified,
	 * this property specifies their initial position
	 * , after resizing within the background
	 * positioning area
	 */
	typedef BackgroundPositionStyleData = {
		var x:BackgroundPositionXStyleValue;
		var y:BackgroundPositionYStyleValue;
	}
	
	/**
	 * The values for the horizontal background
	 * position
	 */
	enum BackgroundPositionXStyleValue {
		/**
		 * a length value
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage relative
		 * to the DOMElement's width
		 */
		percent(value:Int);
		
		/**
		 * same as 0%
		 */
		left;
		
		/**
		 * same as 50%
		 */
		center;
		
		/**
		 * same as 100%
		 */
		right;
	}
	
	/**
	 * The values for the vertical background
	 * position
	 */
	enum BackgroundPositionYStyleValue {
		
		/**
		 * a length value
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage relative
		 * to the DOMElement's height
		 */
		percent(value:Int);
		
		/**
		 * same as 0%
		 */
		top;
		
		/**
		 * same as 50%
		 */
		center;
		
		/**
		 * same as 100%
		 */
		bottom;
	}
	
	/**
	 * Determines the background painting
	 * area
	 */
	enum BackgroundClipStyleValue {
		
		/**
		 * The background is painted within (clipped to) the border box.
		 */
		borderBox;
		
		/**
		 * The background is painted within (clipped to) the padding box.
		 */
		paddingBox;
		
		/**
		 * The background is painted within (clipped to) the content box.
		 */
		contentBox;
	}
	
	/**
	 * Specifies the origin of the background positioning
	 * area
	 */
	enum BackgroundOriginStyleValue {
		
		/**
		 * The position is relative to the border box.
		 */
		borderBox;
		
		/**
		 * The position is relative to the padding box.
		 */
		paddingBox;
		
		/**
		 * The position is relative to the content box.
		 */
		contentBox;
	}
	
	/**
	 * Specifies the size of a background image
	 */
	enum BackgroundSizeStyleValue {
		
		/**
		 * Scale the image, while preserving its intrinsic aspect ratio 
		 * (if any), to the largest size such that both 
		 * its width and its height can fit inside the background positioning area.
		 */
		contain;
		
		/**
		 * Scale the image, while preserving its intrinsic aspect ratio (if any), 
		 * to the smallest size such that both its width and its height
		 * can completely cover the background positioning area.
		 */
		cover;
		
		/**
		 * determine the width 	and height of the background image
		 */
		dimensions(value:BackgroundSizeStyleData);
	}
	
	/**
	 * Contain the size data for one image background
	 */
	typedef BackgroundSizeStyleData = {
		var x:BackgroundSizeStyleDimensionValue;
		var y:BackgroundSizeStyleDimensionValue;
	}
	
	/**
	 * A vertical or horizontal size for 
	 * a background image
	 */
	enum BackgroundSizeStyleDimensionValue {
		/**
		 * a length value
		 */
		length(value:LengthValue);
		
		/**
		 * a percentage relative
		 * to the DOMElement's height or width
		 */
		percent(value:Int);
		
		/**
		 * use the intrinsic dimensions
		 * of the image
		 */
		autoValue;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Represents the width, height of a DOMElement's
	 * parent content.
	 * Specify for each dimension if it is 'autoValue', 
	 * meaning it depends on its content dimension
	 */
	typedef ContainingDOMElementData = {
		var width:Int;
		var isWidthAuto:Bool;
		var height:Int;
		var isHeightAuto:Bool;
	}
	
	/**
	 * Contains the data of the first 
	 * positioned ancestor (a DOMElement with
	 * a position style of relative, absolute,
	 * or fixed) dimensions and a reference to each of
	 * the style objects using those dimensions
	 * as origin to layout an absolutely
	 * positioned DOMElement.
	 */
	typedef LastPositionedDOMElementData = {
		var children:Array<PositionedDOMElementData>;
		var data:ContainingDOMElementData;
		
	}
	
	/**
	 * Holds a reference to the Style of a
	 * positioned DOMElement. The static position
	 * is the x,y point where the DOMElement
	 * would have been if its position style
	 * had been 'static'.
	 * 
	 * It is used if left and right or
	 * top and bottom styles are both
	 * set to 'autoValue'
	 */
	typedef PositionedDOMElementData =  {
		var style:AbstractStyle;
		var staticPosition:PointData;
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
		var floatValue:FloatStyleValue;
		var clear:ClearStyleValue;
		var position:PositionStyleValue;
		var lineHeight:Float;
		
		/**
		 * visual effects
		 */
		var opacity:Float;
		var visibility:Bool;
		var overflow:OverflowStyleData;
		var transformOrigin:PointData;
		var transform:Matrix;
		
		/**
		 * background
		 */
		var backgroundColor:ColorData;
		var backgroundImage:Array<BackgroundImageStyleValue>;
		var backgroundRepeat:Array<BackgroundRepeatStyleData>;
		var backgroundPosition:Array<BackgroundPositionStyleData>;
		var backgroundClip:Array<BackgroundClipStyleValue>;
		var backgroundOrigin:Array<BackgroundOriginStyleValue>;
		var backgroundSize:Array<BackgroundSizeStyleValue>;
		
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
		var color:ColorData;
		
	}

	/**
	 * Store the computed background style
	 * for one background image
	 */
	typedef ComputedBackgroundStyleData = {
		
		/**
		 * The size of the background image, it might
		 * be tiled based on the background repeat
		 * style
		 */
		var backgroundSize:DimensionData;
		
		/**
		 * a rectangle used as origin to position
		 * the background image and might also
		 * be used to clip it based on the
		 * background clip style
		 */
		var backgroundOrigin:RectangleData;
		
		/**
		 * The rectangle clipping the background
		 * image, might be the rectangle of the content,
		 * padding or border box of the DOMElement
		 */
		var backgroundClip:RectangleData;
		
		/**
		 * how to repeat the background image in the
		 * x and y directions
		 */
		var backgroundRepeat:BackgroundRepeatStyleData;
		
		/**
		 * the point of origin of the background image
		 * relative to the backgroundOrigin rectangle
		 */
		var backgroundPosition:PointData;
		
		/**
		 * the data of the background image (url or
		 * gradient data)
		 */
		var backgroundImage:BackgroundImageStyleValue;
	}
	
	/**
	 * Holds a reference to default styles values.
	 * Those styles default values are defined by 
	 * the User Agent in JS, for Flash and other
	 * runtime they will be hard-coded in this
	 * structure.
	 */
	typedef DefaultStylesData = {
		var fontFamily:Array<FontFamilyStyleValue>;
		var color:ColorValue;
	}
	
	/**
	 * Contains the data necessary to place
	 * a DOMElement in flow into the current
	 * formatting context
	 */
	typedef FormattingContextData = {
		/**
		 * the x position where the next in flow DOMElement
		 * should be placed in the formatting context
		 */
		var x:Int;
		
		/**
		 * the y position where the next in flow DOMElement
		 * should be placed in the formatting context
		 */
		var y:Int;
		
		/**
		 * Determine the largest width of a line that was formatted
		 * in the current formatting context
		 */
		var maxWidth:Int;
		
		/**
		 * The accumulated height of all the in flow DOMElements
		 * (includes paddings and margins) of the current
		 * formatting context
		 */
		var maxHeight:Int;
	}
	
	/**
	 * Represents the left and right
	 * floats registered for a 
	 * formatting context
	 */
	typedef FloatsData = {
		var left:Array<FloatData>;
		var right:Array<FloatData>;
	}
	
	/**
	 * Represents the coordinates and
	 * dimensions of the float in its
	 * formatting context coordinate space
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
		
		/**
		 * the width of a space character for
		 * a given font at a given size
		 */
		var spaceWidth:Int;
	}
	
	
	typedef InlineBoxData = {
		var element:InlineBoxRenderer;
		var children:Array<ElementRenderer>;
	}