package cocktail.core.css;

import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

typedef CSSRuleList = Array<CSSRule>;

typedef TypedPropertyData = {
	var name:String;
	var value:String;
	var typedValue:Array<CSSPropertyValue>;
}

typedef PropertyData = {
	var value:String;
	var important:String;
	var origin:PropertyOriginValue;
	var selector:SelectorData;
}

typedef PropertyDeclarationData = {
	var name:String;
	var value:String;
	var priority:String;
}

enum PropertyOriginValue {
	AUTHOR;
	USER_AGENT;
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
	 */
	ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(name:String, value:String);
}

enum PseudoClassSelectorValue {
	STRUCTURAL(value:StructuralPseudoClassSelectorValue);
	LINK(value:LinkPseudoClassValue);
	TARGET;
	LANG(value:Array<String>);
	USER_ACTION(value:UserActionPseudoClassValue);
	UI_ELEMENT_STATES(value:UIElementStatesValue);
	NOT(value:SimpleSelectorSequenceData);
}

enum StructuralPseudoClassSelectorValue {
	ROOT;
	FIRST_CHILD;
	LAST_CHILD;
	FIRST_OF_TYPE;
	LAST_OF_TYPE;
	ONLY_CHILD;
	ONLY_OF_TYPE;
	EMPTY;
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

enum LinkPseudoClassValue {
	LINK;
	VISITED;
}

enum UserActionPseudoClassValue {
	ACTIVE;
	HOVER;
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

enum CSSPropertyValue {
	INTEGER(value:Int);
	NUMBER(value:Float);
	PERCENTAGE(value:Float);
	IDENTIFIER(value:String);
	KEYWORD(value:CSSKeywordValue);
	URL(value:String);
	STRING(value:String);
	LENGTH(value:CSSLengthValue);
	ANGLE(value:CSSAngleValue);
	TIME(value:CSSTimeValue);
	COLOR(value:CSSColorValue);
	FREQUENCY(value:CSSFrequencyValue);
	REPEAT_STYLE(value:CSSRepeatStyleValue);
	RESOLUTION(value:CSSResolutionValue);
	GROUP(value:Array<CSSPropertyValue>);
	LIST(value:Array<CSSPropertyValue>);
	INHERIT;
	INITIAL;
//	POSITION(value1:PositionValue, ?value2:PositionValue, ?value3:PositionValue, ?value4:PositionValue);
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
	BLOCK;
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

enum CSSRepeatStyleValue {
	REPEAT_X;
	REPEAT_Y;
	SINGLE(value:RepeatKeywordValue);
	DOUBLE(horizontalValue:RepeatKeywordValue, verticalValue:RepeatKeywordValue);
}

enum RepeatKeywordValue {
	REPEAT;
	SPACE;
	ROUND;
	NO_REPEAT;
}

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
}
