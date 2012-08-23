package cocktail.core.css;

import cocktail.core.geom.Matrix;
import cocktail.core.layout.LayoutData;
import cocktail.core.unit.UnitData;
import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

typedef CSSRuleList = Array<CSSRule>;

typedef TypedPropertyData = {
	var name:String;
	var typedValue:CSSPropertyValue;
	var important:Bool;
}

typedef PropertyData = {
	var important:Bool;
	var origin:PropertyOriginValue;
	var typedValue:CSSPropertyValue;
	var selector:SelectorData;
}

typedef StyleDeclarationData = {
	var style:CSSStyleDeclaration;
	var selector:SelectorData;
}

typedef MatchedPseudoClasses = {
	var hover:Bool;
	var focus:Bool;
	var active:Bool;
	var link:Bool;
	var enabled:Bool;
	var disabled:Bool;
	var checked:Bool;
}

enum PropertyOriginValue {
	AUTHOR;
	USER_AGENT;
}

typedef UsedValuesData = {
	var width:Float;
	var minHeight:Float;
	var	maxHeight:Float;
	var minWidth:Float;
	var maxWidth:Float;
	var	height:Float;
	var	marginLeft:Float;
	var	marginRight:Float;
	var	marginTop:Float;
	var	marginBottom:Float;
	var	paddingLeft:Float;
	var	paddingRight:Float;
	var	paddingTop:Float;
	var	paddingBottom:Float;
	var	left:Float;
	var	right:Float;
	var	top:Float;
	var	bottom:Float;
	var	textIndent:Float;
	var	color:ColorData;
	var lineHeight:Float;
	var letterSpacing:Float;
	var	transformOrigin:PointData;
	var	transform:Matrix;
	var	backgroundColor:ColorData;
}

//////////////////////////////////////////////////////////////////////////////////////////
// SELECTOR STRUCTURES
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * Holds the data used to determine a selector specificity (priority).
 * Selector specificity is used to determine which styles to use when
 * a particular style is defined in more than one CSS rule. The 
 * style with the more specific selector is used.
 * 
 * Specificity is defined by 3 categories whose value are
 * then concatenated into an integer value
 */
typedef SelectorSpecificityData = {
	
	/**
	 * Incremented for each ID simple selector
	 * in the selector
	 */
	var idSelectorsNumber:Int;
	
	/**
	 * Incremented for each class and pseudo class
	 * simple selector in the selector
	 */
	var classAttributesAndPseudoClassesNumber:Int;
	
	/**
	 * Incremented for each type and pseudo element
	 * simple selector in the selector
	 */
	var typeAndPseudoElementsNumber:Int;
}

/**
 * Contains all the data of one selector
 */
typedef SelectorData = {
	
	/**
	 * an array of any combination of selector
	 * components
	 */
	var components:Array<SelectorComponentValue>;
	
	/**
	 * a selector can only have one pseudo element,
	 * always specified at the end of the selector
	 */
	var pseudoElement:PseudoElementSelectorValue;
}

/**
 * Represent a simple selector sequence.
 * A sequence always begin with a type or 
 * universal selector and only has one of
 * those two in the whole sequence. Then it can
 * have any combination of the remaining simple
 * selectors
 */
typedef SimpleSelectorSequenceData = {
	
	/**
	 * Only one sequence start selector for a selector
	 * sequence
	 */
	var startValue:SimpleSelectorSequenceStartValue;
	
	/**
	 * any number of the remaining simple selectors
	 */
	var simpleSelectors:Array<SimpleSelectorSequenceItemValue>;
}

//////////////////////////////////////////////////////////////////////////////////////////
// SELECTOR ENUMS
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * A selector contains either simple selector
 * or combinator between 2 simple selector
 */
enum SelectorComponentValue {
	SIMPLE_SELECTOR_SEQUENCE(value:SimpleSelectorSequenceData);
	COMBINATOR(value:CombinatorValue);
} 

/**
 * Lists all the simple selectors besides the type and
 * universal selector, reserved for the start of a
 * simple selector sequence
 */
enum SimpleSelectorSequenceItemValue {
	ATTRIBUTE(value:AttributeSelectorValue);
	PSEUDO_CLASS(value:PseudoClassSelectorValue);
	CLASS(value:String);
	ID(value:String);
}

/**
 * Matches an element's type (tag name) or any element (universal, symbolised by "*").
 * A simple selector sequence always begin with
 * one of those 2 values. Universal may be implied.
 * For instance ".myclass" is the same as "*.myClass"
 */
enum SimpleSelectorSequenceStartValue {
	
	/**
	 * any element
	 */
	UNIVERSAL;
	
	/**
	 * an element of type value
	 */
	TYPE(value:String);
}

/**
 * Matches an element's attribute
 * presence and value
 */
enum AttributeSelectorValue {
	
	/**
	 * an element with a "value" attribute
	 */
	ATTRIBUTE(value:String);
	
	/**
	 * an element with a "name" attribute
	 * whose value is exactly "value"
	 */
	ATTRIBUTE_VALUE(name:String, value:String);
	
	/**
	 * an element whose "name" attribute
	 * value is a list of whitespace-separated values,
	 * one of which is exactly equal to "value"
	 * 
	 * TODO 2 : value should be stored as string array
	 */
	ATTRIBUTE_LIST(name:String, value:String);
	
	/**
	 * an element whose "name" attribute value begins
	 * exactly with the string "value"
	 */
	ATTRIBUTE_VALUE_BEGINS(name:String, value:String);
	
	/**
	 * an element whose "name" attribute
	 * value ends exactly with the string "value"
	 */
	ATTRIBUTE_VALUE_ENDS(name:String, value:String);
	
	/**
	 * an element whose "name" attribute value
	 * contains the substring "value"
	 */
	ATTRIBUTE_VALUE_CONTAINS(name:String, value:String);
	
	/**
	 * an element whose "name" attribute has a hyphen-separated
	 * list of values beginning (from the left) with "value"
	 * 
	 * TODO 2 : value should be store as string array
	 */
	ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(name:String, value:String);
}

/**
 * List the pseuso class selector types
 */
enum PseudoClassSelectorValue {
	STRUCTURAL(value:StructuralPseudoClassSelectorValue);
	LINK(value:LinkPseudoClassValue);
	TARGET;
	LANG(value:Array<String>);
	USER_ACTION(value:UserActionPseudoClassValue);
	UI_ELEMENT_STATES(value:UIElementStatesValue);
	
	//TODO 2 : should actually be SelectorData ?
	NOT(value:SimpleSelectorSequenceData);
}

/**
 * List the structural pseudo class, which
 * are based on the DOM structure
 */
enum StructuralPseudoClassSelectorValue {
	
	/**
	 * The :root pseudo-class represents an element 
	 * that is the root of the document. In HTML 4, this 
	 * is always the HTML element. 
	 */
	ROOT;
	
	/**
	 * The :first-child pseudo-class represents an element
	 * that is the first child of some other element. 
	 */
	FIRST_CHILD;
	
	/**
	 * The :last-child pseudo-class represents 
	 * an element that is the last child of
	 * some other element. 
	 */
	LAST_CHILD;
	
	/**
	 * The :first-of-type pseudo-class represents
	 * an element that is the first sibling of its
	 * type in the list of children of its parent element. 
	 */
	FIRST_OF_TYPE;
	
	/**
	 * he :last-of-type pseudo-class represents an element
	 * that is the last sibling of its type in the list
	 * of children of its parent element. 
	 */
	LAST_OF_TYPE;
	
	/**
	 * Represents an element that has a parent element and whose
	 * parent element has no other element children. 
	 * Same as :first-child:last-child
	 */
	ONLY_CHILD;
	
	/**
	 * Represents an element that has a parent element and 
	 * whose parent element has no other element children
	 * with the same expanded element name
	 */
	ONLY_OF_TYPE;
	
	/**
	 * The :empty pseudo-class represents an element 
	 * that has no children at all. 
	 */
	EMPTY;
	
	//TODO 2 : doc + implementation
	NTH_CHILD(value:StructuralPseudoClassArgumentValue);
	NTH_LAST_CHILD(value:StructuralPseudoClassArgumentValue);
	NTH_OF_TYPE(value:StructuralPseudoClassArgumentValue);
	NTH_LAST_OF_TYPE(value:StructuralPseudoClassArgumentValue);
}

//TODO 2 : missing values
enum StructuralPseudoClassArgumentValue {
	ODD;
	EVEN;
}

/**
 * pseudo class applying to anchor
 */
enum LinkPseudoClassValue {
	
	/**
	 * The :link pseudo-class applies 
	 * to links that have not yet been visited. 
	 */
	LINK;
	
	/**
	 * The :visited pseudo-class applies once
	 * the link has been visited by the user. 
	 */
	VISITED;
}

/**
 * Pseudo classes caused by user actions
 */
enum UserActionPseudoClassValue {
	
	/**
	 * The :active pseudo-class applies while an element is being
	 * activated by the user. For example, between
	 * the times the user presses the mouse
	 * button and releases it.
	 */
	ACTIVE;
	
	/**
	 * The :hover pseudo-class applies while the user
	 * designates an element with a pointing device,
	 * but does not necessarily activate it.
	 */
	HOVER;
	
	/**
	 * The :focus pseudo-class applies while an element
	 * has the focus (accepts keyboard or mouse events,
	 * or other forms of input). 
	 */
	FOCUS;
}

enum UIElementStatesValue {
	ENABLED;
	DISABLED;
	CHECKED;
}

enum PseudoElementSelectorValue {
	NONE;
	FIRST_LINE;
	FIRST_LETTER;
	BEFORE;
	AFTER;
}

enum CombinatorValue {
	DESCENDANT;
	CHILD;
	ADJACENT_SIBLING;
	GENERAL_SIBLING;
}

//////////////////////////////////////////////////////////////////////////////////////////
// STYLE VALUES
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * Lists all the basic types for CSS property values
 */
enum CSSPropertyValue {
	
	/**
	 * represents a simple Int
	 */
	INTEGER(value:Int);
	
	/**
	 * Represent a floating number
	 */
	NUMBER(value:Float);
	
	/**
	 * percentage
	 */
	PERCENTAGE(value:Float);
	
	/**
	 * an arbitrary identifier who is
	 * not a defined CSS keyword
	 */
	IDENTIFIER(value:String);
	
	/**
	 * a pre-defined CSS keyword, for instance
	 * 'auto'
	 */
	KEYWORD(value:CSSKeywordValue);
	
	/**
	 * an url
	 */
	URL(value:String);
	
	/**
	 * Like an identifier but between quotes
	 */
	STRING(value:String);
	
	/**
	 * Represents a dimension expressed with
	 * a CSS Number followed by a unit. 
	 * For instance '10px'
	 */
	LENGTH(value:CSSLengthValue);
	
	/**
	 * A dimension, like a length but with
	 * angle unit such as 'deg'
	 */
	ANGLE(value:CSSAngleValue);
	
	/**
	 * A dimension, like a length but
	 * for time unit such as 's'
	 */
	TIME(value:CSSTimeValue);
	
	/**
	 * A dimension, like a length but
	 * for frequency unit such as 'hz'
	 */
	FREQUENCY(value:CSSFrequencyValue);
	
	/**
	 * A dimension, like a length but
	 * for resolution unit such as 'dpi'
	 */
	RESOLUTION(value:CSSResolutionValue);
	
	/**
	 * a CSS color value
	 */
	COLOR(value:CSSColorValue);
	
	/**
	 * an array of CSS properties, represented
	 * in the CSS string by space separated value.
	 * For instance '10px 5px', will create a group
	 * with 2 length items
	 */
	GROUP(value:Array<CSSPropertyValue>);
	
	/**
	 * Like a group but for comma separated CSS values.
	 * For instance '10px, 5px' will create a list
	 * with 2 length items
	 */
	CSS_LIST(value:Array<CSSPropertyValue>);
	
	/**
	 * represents the CSS wide keyword inherit
	 */
	INHERIT;
	
	/**
	 * represents the CSS wide keyword initial.
	 */
	INITIAL;
	
	/**
	 * Represents a number which is the result
	 * of the computation of a length
	 */
	ABSOLUTE_LENGTH(value:Float);
	
	/**
	 * Represents steps for an animation/transition
	 */
	STEPS(intervalNumbers:Int, intervalChange:CSSKeywordValue);
	
	/**
	 * Represent easing function for an animation/transition
	 */
	CUBIC_BEZIER(x1:Float, y1:Float, x2:Float, y2:Float);
	
	/**
	 * Represent a transformation function defining
	 * an affine transformation, used by the 'transform'
	 * style
	 */
	TRANSFORM_FUNCTION(value:CSSTransformFunctionValue);
}

/**
 * Lists the different color format supported.
 * Each value describes one color
 */
enum CSSColorValue {
	
	/**
	 * each value (red, green and blue)
	 * must be an integer from 0 to 255
	 */
	RGB(red:Int, green:Int, blue:Int);
	
	/**
	 * Same as above but individual colors are reprented
	 * as percentage of the max value (e.g, 100% is
	 * equal to 255)
	 */
	RGB_PERCENTAGE(red:Float, green:Float, blue:Float);
	
	/**
	 * same as rgb + alpha is a float from 
	 * 0 (transparent) to 1 (opaque)
	 */
	RGBA(red:Int, green:Int, blue:Int, alpha:Float);
	
	/**
	 * Same as RGB_PERCENTAGE for RGBA
	 */
	RGBA_PERCENTAGE(red:Float, green:Float, blue:Float, alpha:Float);
	
	/**
	 * The color value must be represented
	 * as 6 hexadecimal number string started
	 * with a "#" charachter.
	 * e.g : for red, #FF0000
	 */
	HEX(value:String);
	
	/**
	 * HSL colors are encoding as a triple (hue, saturation, lightness). Hue is represented 
	 * as an angle of the color circle (i.e. the rainbow represented in a circle). 
	 * This angle is so typically measured in degrees that the unit is implicit in CSS;
	 * syntactically, only a <number> is given
	 * 
	 * Saturation and lightness are represented as percentages. 100% is
	 * full saturation, and 0% is a shade of gray. 0% lightness is black,
	 * 100% lightness is white, and 50% lightness is “normal”.
	 */
	HSL(hue:Float, saturation:Float, lightness:Float);
	
	/**
	 * Same as HSL with an extra alpha value
	 */
	HSLA(hue:Float, saturation:Float, lightness:Float, alpha:Float);
	
	/**
	 * the color is chosen among a
	 * set of predefined colors
	 */ 
	KEYWORD(value:CSSColorKeyword);
	
	/**
	 * a fully transparent color, equivalent
	 * to rgba(0,0,0,0)
	 */
	TRANSPARENT;
	
	/**
	 * Correspond to the value of the "color"
	 * CSS property, its computed value
	 * is the computed value of "color".
	 * If this value is set on color itself,
	 * it is treated as "inherit"
	 */
	CURRENT_COLOR;
}


/**
 * Lists the default available colors
 */
enum CSSColorKeyword {
	AQUA;
	BLACK;
	BLUE;
	FUSHIA;
	GRAY;
	GREEN;
	LIME;
	MAROON;
	NAVY;
	OLIVE;
	ORANGE;
	PURPLE;
	RED;
	SILVER;
	TEAL;
	WHITE;
	YELLOW;
}

/**
 * The list of allowed transform functions to
 * apply to a htmlElement
 */
enum CSSTransformFunctionValue {
	
	/**
	 * specify a 2D transformation in the form of
	 * a transformation matrix
	 */
	MATRIX(data:MatrixData);
	
	/**
	 * specify a 2D translation by the vector [tx, ty]
	 */
	TRANSLATE(tx:CSSTranslationValue, ty:CSSTranslationValue);
	
	/**
	 * specifies a translation by the given amount in the
	 * X direction
	 */
	TRANSLATE_X(tx:CSSTranslationValue);
	
	/**
	 * specifies a translation by the given amount in the
	 * Y direction
	 */
	TRANSLATE_Y(ty:CSSTranslationValue);
	
	/**
	 * Specifies a 2D scale operation by the
	 * [sx, sy] scaling vector
	 */
	SCALE(sx:Float, sy:Float);
	
	/**
	 * Specifies a 2D scale operation by the
	 * [sx, 1] scaling vector
	 */
	SCALE_X(sx:Float);
	
	/**
	 * Specifies a 2D scale operation by the
	 * [1, sy] scaling vector
	 */
	SCALE_Y(sy:Float);
	
	/**
	 * specifies a 2D rotation by the angle specified in the
	 * parameter about the origin of the element,
	 * as defined by the TransformOriginStyleValue property
	 */
	ROTATE(angle:CSSAngleValue);
	
	/**
	 * specifies a skew transformation
	 * along the X axis by the given angle.
	 */
	SKEW_X(angle:CSSAngleValue);
	
	/**
	 * specifies a skew transformation
	 * along the Y axis by the given angle.
	 */
	SKEW_Y(angle:CSSAngleValue);
	
	/**
	 * specifies a skew transformation 
	 * along the X and Y axes.
	 */
	SKEW(angleX:CSSAngleValue, angleY:CSSAngleValue);
}

/**
 * The list of value allowed to 
 * specify the amount of a translation
 * 
 * TODO : is this useful or could be replaced
 * with CSSPropertyValue ?
 */
enum CSSTranslationValue {
	
	ABSOLUTE_LENGTH(value:Float);
	
	/**
	 * a length value
	 */
	LENGTH(value:CSSLengthValue);
	
	/**
	 * a percentage relative to the htmlElement's
	 * dimensions
	 */
	PERCENTAGE(value:Float);
}


/**
 * Represent a frequency. 
 * For example, when representing sound pitches, 
 * 200Hz (or 200hz) is a bass sound, 
 * and 6kHz (or 6khz) is a treble sound.
 */
enum CSSFrequencyValue {
	
	/**
	 *  It represents the number of occurrences per second.
	 */
	HERTZ(value:Float);
	
	/**
	 * A kiloHertz is 1000 Hertz.
	 */
	KILO_HERTZ(value:Float);
}

/**
 * The resolution unit represents the size of a single "dot"
 * in a graphical representation by indicating 
 * how many of these dots fit in a CSS ‘in’, ‘cm’, or ‘px’.
 */
enum CSSResolutionValue {
	
	/**
	 * dots per inch
	 */
	DPI(value:Float);
	
	/**
	 * dots per centimeter
	 */
	DPCM(value:Float);
	
	/**
	 * dots per 'px' unit
	 */
	DPPX(value:Float);
}

/**
 * Lists the different available
 * units to specify an angle
 */
enum CSSAngleValue {
	
	/**
	 * Degress. There are
	 * 360 degrees in a full 
	 * circle
	 */
	DEG(value:Float);
	
	/**
	 * Gradians. There
	 * are 400 gradians in
	 * a full circle
	 */
	GRAD(value:Float);
	
	/**
	 * Radians. There are 2π
	 * radians in a full circle.
	 */
	RAD(value:Float);
	
	/**
	 * Turns. There is 1 
	 * turn in a full circle. 
	 */
	TURN(value:Float);
}

/**
 * Lists the different types of 
 * unit supported with an explicitly
 * set length such as px, cm, em...
 * 
 * There are two kinds of length units :
 * - absolute (px, cm, mm, pt, pc, in).
 * absolute length are all computed to pixel
 * values.
 * 
 * - relative (em and ex). Relative length units 
 * specify a length relative to another length property.
 * 
 * TODO : missing values rem, vw, vh, vmin
 */
enum CSSLengthValue {
	
	/**
	 * pixel, 1px is equal to 0.75pt.
	 */
	PX(value:Float);
	
	/**
	 * centimeters
	 */
	CM(value:Float);
	
	/**
	 * millimeters
	 */
	MM(value:Float);
	
	/**
	 * points, the points
	 * are equal to 1/72nd of 1in. 
	 */
	PT(value:Float);
	
	/**
	 * picas, 1pc is equal to 12pt.
	 */
	PC(value:Float);
	
	/**
	 * inches, 1in is equal to 2.54cm.
	 */
	IN(value:Float);
	
	/**
	 * The 'em' unit is equal to the
	 * computed value of the 'font-size'
	 * property of the element on which it is used.
	 * The exception is when 'em'
	 * occurs in the value of the 'font-size' 
	 * property itself, in which case it
	 * refers to the font size of the parent
	 * element. It may be used for vertical or
	 * horizontal measurement.
	 */
	EM(value:Float);
	
	/**
	 * The 'ex' unit is defined by the element's first available font.
	 * The exception is when 'ex' occurs in
	 * the value of the 'font-size' property,
	 * in which case it refers to the 'ex' of the
	 * parent element.The 'x-height' 
	 * is so called because it is often equal to the height
	 * of the lowercase "x". However, an 'ex' is
	 * defined even for fonts that do not contain an "x".
	 */
	EX(value:Float);
}

/**
 * Lists of supported time dimensions
 */
enum CSSTimeValue {
	
	/**
	 * seconds
	 */
	SECONDS(value:Float);
	
	/**
	 * Milliseconds. There are 1000 milliseconds in a second.
	 */
	MILLISECONDS(value:Float);
}


/**
 * Lists all the pre defined CSS Keywords.
 * Some are used in multiple styles and their
 * effects varies based on the style on which
 * they are used
 */
enum CSSKeywordValue {
	NORMAL;
	BOLD;
	BOLDER;
	LIGHTER;
	ITALIC;
	OBLIQUE;
	SMALL_CAPS;
	PRE;
	NO_WRAP;
	PRE_WRAP;
	PRE_LINE;
	LEFT;
	RIGHT;
	CENTER;
	JUSTIFY;
	CAPITALIZE;
	UPPERCASE;
	LOWERCASE;
	NONE;
	BASELINE;
	SUB;
	SUPER;
	TOP;
	TEXT_TOP;
	MIDDLE;
	BOTTOM;
	TEXT_BOTTOM;
	AUTO;
	BLOCK;
	INLINE_BLOCK;
	INLINE;
	BOTH;
	STATIC;
	RELATIVE;
	ABSOLUTE;
	FIXED;
	VISIBLE;
	HIDDEN;
	SCROLL;
	BORDER_BOX;
	PADDING_BOX;
	CONTENT_BOX;
	CONTAIN;
	COVER;
	CROSSHAIR;
	DEFAULT;
	POINTER;
	TEXT;
	ALL;
	EASE;
	LINEAR;
	EASE_IN;
	EASE_OUT;
	EASE_IN_OUT;
	STEP_START;
	STEP_END;
	START;
	END;
	XX_SMALL;
	X_SMALL;
	SMALL;
	MEDIUM;
	LARGE;
	X_LARGE;
	XX_LARGE;
	LARGER;
	SMALLER;
	REPEAT;
	REPEAT_X;
	REPEAT_Y;
	SPACE;
	ROUND;
	NO_REPEAT;
}
