/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.core.geom.Matrix;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

typedef CSSRuleList = Array<CSSRule>;

class TypedPropertyVO {
	
	public var index:Int;
	public var typedValue:CSSPropertyValue;
	public var important:Bool;
	
	public function new()
	{
		
	}
}

class PropertyVO {
	
	public var important:Bool;
	public var origin:PropertyOriginValue;
	public var typedValue:CSSPropertyValue;
	public var selector:SelectorVO;
	
	public function new()
	{
		this.important = false;
	}
}

class StyleDeclarationVO {
	
	public var style:CSSStyleDeclaration;
	public var selector:SelectorVO;
	
	public function new()
	{
		
	}
}

/**
 * For a given element, when retrieving
 * its styles, stores which pseudo-classes
 * the element currently matches.
 * 
 * Also store some additional data about
 * the node, such as wether it has an ID,
 * used to optimise cascading
 */
class MatchedPseudoClassesVO {
	
	public var hover:Bool;
	public var focus:Bool;
	public var active:Bool;
	public var link:Bool;
	public var enabled:Bool;
	public var disabled:Bool;
	public var checked:Bool;
	public var fullscreen:Bool;
	
	public var hasId:Bool;
	public var nodeId:String;
	public var hasClasses:Bool;
	public var nodeClassList:Array<String>;
	public var nodeType:String;
	
	public function new(hover:Bool, focus:Bool, active:Bool, link:Bool, enabled:Bool,
	disabled:Bool, checked:Bool, fullscreen:Bool,
	hasId:Bool, hasClasses:Bool, nodeId:String, nodeClassList:Array<String>, nodeType:String) 
	{
		this.hover = hover;
		this.focus = focus;
		this.active = active;
		this.link = link;
		this.enabled = enabled;
		this.disabled = disabled;
		this.checked = checked;
        this.fullscreen = fullscreen;
		this.hasId = hasId;
		this.hasClasses = false;
		this.nodeId = nodeId;
		this.nodeClassList = nodeClassList;
		this.nodeType = nodeType;
	}
}

enum PropertyOriginValue {
	AUTHOR;
	USER_AGENT;
}

//////////////////////////////////////////////////////////////////////////////////////////
// USED VALUES
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * Represents the used values of an HTMLElement, that is
 * the value which will be used during layout. For instance,
 * during layout, width or height are represented by a
 * floating number
 */
class UsedValuesVO {
	public var width:Float;
	public var minHeight:Float;
	public var maxHeight:Float;
	public var minWidth:Float;
	public var maxWidth:Float;
	public var height:Float;
	public var marginLeft:Float;
	public var marginRight:Float;
	public var marginTop:Float;
	public var marginBottom:Float;
	public var paddingLeft:Float;
	public var paddingRight:Float;
	public var paddingTop:Float;
	public var paddingBottom:Float;
	public var left:Float;
	public var right:Float;
	public var top:Float;
	public var bottom:Float;
	public var textIndent:Float;
	public var color:ColorVO;
	public var lineHeight:Float;
	public var letterSpacing:Float;
	public var transformOrigin:PointVO;
	public var transform:Matrix;
	public var backgroundColor:ColorVO;
	public var borderLeftWidth:Float;
	public var borderRightWidth:Float;
	public var borderTopWidth:Float;
	public var borderBottomWidth:Float;
	public var borderTopColor:ColorVO;
	public var borderRightColor:ColorVO;
	public var borderBottomColor:ColorVO;
	public var borderLeftColor:ColorVO;
	public var outlineWidth:Float;
	public var outlineColor:ColorVO;
	
	public function new() 
	{
		minHeight = 0.0;
		maxHeight = 0.0;
		minWidth = 0.0;
		maxWidth = 0.0;
		width = 0.0;
		height = 0.0;
		marginLeft = 0.0;
		marginRight = 0.0;
		marginTop = 0.0;
		marginBottom = 0.0;
		paddingLeft = 0.0;
		paddingRight = 0.0;
		paddingTop = 0.0;
		paddingBottom = 0.0;
		left = 0.0;
		right = 0.0;
		top = 0.0;
		bottom = 0.0;
		textIndent = 0;
		lineHeight = 0.0;
		letterSpacing = 0.0;
		color = new ColorVO(0, 1.0);
		transformOrigin = new PointVO(0.0, 0.0);
		transform = new Matrix();
		backgroundColor = new ColorVO(0, 0.0);
		borderLeftWidth = 0.0;
		borderRightWidth = 0.0;
		borderTopWidth = 0.0;
		borderBottomWidth = 0.0;
		borderLeftColor = new ColorVO(0, 1.0);
		borderRightColor = new ColorVO(0, 1.0);
		borderTopColor = new ColorVO(0, 1.0);
		borderBottomColor = new ColorVO(0, 1.0);
		outlineWidth = 0.0;
		outlineColor = new ColorVO(0, 1.0);

	}
}

/**
 * Represents a color with
 * its alpha (from 0 to 1)
 */
class ColorVO {
	public var color:Int;
	public var alpha:Float;
	
	public function new(color:Int, alpha:Float)
	{
		this.color = color;
		this.alpha = alpha;
	}
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
class SelectorSpecificityVO {
	
	/**
	 * Incremented for each ID simple selector
	 * in the selector
	 */
	public var idSelectorsNumber:Int;
	
	/**
	 * Incremented for each class and pseudo class
	 * simple selector in the selector
	 */
	public var classAttributesAndPseudoClassesNumber:Int;
	
	/**
	 * Incremented for each type and pseudo element
	 * simple selector in the selector
	 */
	public var typeAndPseudoElementsNumber:Int;
	
	public function new()
	{
		idSelectorsNumber = 0;
		classAttributesAndPseudoClassesNumber = 0;
		typeAndPseudoElementsNumber = 0;
	}
}

/**
 * Contains all the data of one selector
 */
class SelectorVO {
	
	/**
	 * an array of any combination of selector
	 * components
	 */
	public var components:Array<SelectorComponentValue>;
	
	/**
	 * a selector can only have one pseudo element,
	 * always specified at the end of the selector
	 */
	public var pseudoElement:PseudoElementSelectorValue;
	
	/**
	 * Store wether the first component (starting from the right)
	 * of this selector is a class selector. Used for optimisations
	 * during cascade
	 */
	public var beginsWithClass:Bool;
	
	/**
	 * If the selector begins with a class, it is stored
	 * here, else it is null
	 */
	public var firstClass:String;
	
	/**
	 * same as beginsWithClass for Id selector
	 */
	public var beginsWithId:Bool;
	
	/**
	 * same as firstClass for Id
	 */
	public var firstId:String;
	
	/**
	 * same as beginsWithClass for type selector
	 */
	public var beginsWithType:Bool;
	
	/**
	 * same as firstClass for type selector
	 */
	public var firstType:String;
	
	/**
	 * Wether this selector only contains a single
	 * class selector
	 */
	public var isSimpleClassSelector:Bool;
	
	/**
	 * same as above for id selector
	 */
	public var isSimpleIdSelector:Bool;
	
	/**
	 * same as above for type selector
	 */
	public var isSimpleTypeSelector:Bool;
	
	public function new(components:Array<SelectorComponentValue>, pseudoElement:PseudoElementSelectorValue,
	beginsWithClass:Bool, firstClass:String, beginsWithId:Bool, firstId:String, beginsWithType:Bool, firstType:String
	, isSimpleClassSelector:Bool, isSimpleIdSelector:Bool, isSimpleTypeSelector:Bool)
	{
		this.components = components;
		this.pseudoElement = pseudoElement;
		this.beginsWithClass = beginsWithClass;
		this.firstClass = firstClass;
		this.beginsWithId = beginsWithId;
		this.firstId = firstId;
		this.beginsWithType = beginsWithType;
		this.firstType = firstType;
		this.isSimpleClassSelector = isSimpleClassSelector;
		this.isSimpleIdSelector = isSimpleIdSelector;
		this.isSimpleTypeSelector = isSimpleTypeSelector;
	}
}

/**
 * Represent a simple selector sequence.
 * A sequence always begin with a type or 
 * universal selector and only has one of
 * those two in the whole sequence. Then it can
 * have any combination of the remaining simple
 * selectors
 */
class SimpleSelectorSequenceVO {
	
	/**
	 * Only one sequence start selector for a selector
	 * sequence
	 */
	public var startValue:SimpleSelectorSequenceStartValue;
	
	/**
	 * any number of the remaining simple selectors
	 */
	public var simpleSelectors:Array<SimpleSelectorSequenceItemValue>;
	
	public function new(startValue:SimpleSelectorSequenceStartValue, simpleSelectors:Array<SimpleSelectorSequenceItemValue>)
	{
		this.startValue = startValue;
		this.simpleSelectors = simpleSelectors;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// SELECTOR ENUMS
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * A selector contains either simple selector
 * or combinator between 2 simple selector
 */
enum SelectorComponentValue {
	SIMPLE_SELECTOR_SEQUENCE(value:SimpleSelectorSequenceVO);
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
	CSS_CLASS(value:String);
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

/**
 * List the pseuso class selector types
 */
enum PseudoClassSelectorValue {
	UNKNOWN;
	STRUCTURAL(value:StructuralPseudoClassSelectorValue);
	LINK(value:LinkPseudoClassValue);
	TARGET;
    FULLSCREEN;
	LANG(value:Array<String>);
	USER_ACTION(value:UserActionPseudoClassValue);
	UI_ELEMENT_STATES(value:UIElementStatesValue);
	
	//TODO 2 : should actually be SelectorVO ?
	NOT(value:SimpleSelectorSequenceVO);
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
	 * represent a special notation for the font shorthand
	 * where the first value is the font size and the second
	 * the line height. It is noted like this : "12px/100%",
	 * this value means a font size of 12px and a line height
	 * of 100% of the font size
	 */
	FONT_SIZE_LINE_HEIGHT_GROUP(fontSize:CSSPropertyValue, lineHeight:CSSPropertyValue);
	
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
	ALICE_BLUE;
	ANTIQUE_WHITE;
	AQUA;
	AQUAMARINE;
	AZURE;
	BEIGE;
	BISQUE;
	BLACK;
	BLANCHE_DALMOND;
	BLUE;
	BLUE_VIOLET;
	BROWN;
	BURLY_WOOD;
	CADET_BLUE;
	CHARTREUSE;
	CHOCOLATE;
	CORAL;
	CORNFLOWER_BLUE;
	CORNSILK;
	CRIMSON;
	CYAN;
	DARK_BLUE;
	DARK_CYAN;
	DARK_GOLDEN_ROD;
	DARK_GRAY;
	DARK_GREEN;
	DARK_GREY;
	DARK_KHAKI;
	DARK_MAGENTA;
	DARK_OLIVE_GREEN;
	DARK_ORANGE;
	DARK_ORCHID;
	DARK_RED;
	DARK_SALMON;
	DARK_SEA_GREEN;
	DARK_SLATE_BLUE;
	DARK_SLATE_GRAY;
	DARK_SLATE_GREY;
	DARK_TURQUOISE;
	DARK_VIOLET;
	DEEP_PINK;
	DEEP_SKY_BLUE;
	DIM_GRAY;
	DIM_GREY;
	DODGER_BLUE;
	FIRE_BRICK;
	FLORAL_WHITE;
	FOREST_GREEN;
	FUCHSIA;
	GAINSBORO;
	GHOST_WHITE;
	GOLD;
	GOLDEN_ROD;
	GRAY;
	GREEN;
	GREEN_YELLOW;
	GREY;
	HONEY_DEW;
	HOT_PINK;
	INDIAN_RED;
	INDIGO;
	IVORY;
	KHAKI;
	LAVENDER;
	LAVENDER_BLUSH;
	LAWN_GREEN;
	LEMON_CHIFFON;
	LIGHT_BLUE;
	LIGHT_CORAL;
	LIGHT_CYAN;
	LIGHT_GOLDENROD_YELLOW;
	LIGHT_GRAY;
	LIGHT_GREEN;
	LIGHT_GREY;
	LIGHT_PINK;
	LIGHT_SALMON;
	LIGHT_SEA_GREEN;
	LIGHT_SKY_BLUE;
	LIGHT_SLATE_GRAY;
	LIGHT_SLATE_GREY;
	LIGHT_STEEL_BLUE;
	LIGHT_YELLOW;
	LIME;
	LIME_GREEN;
	LINEN;
	MAGENTA;
	MAROON;
	MEDIUM_AQUAMARINE;
	MEDIUM_BLUE;
	MEDIUM_ORCHID;
	MEDIUM_PURPLE;
	MEDIUM_SEA_GREEN;
	MEDIUM_SLATE_BLUE;
	MEDIUM_SPRING_GREEN;
	MEDIUM_TURQUOISE;
	MEDIUM_VIOLET_RED;
	MIDNIGHT_BLUE;
	MINT_CREAM;
	MISTY_ROSE;
	MOCCASIN;
	NAVAJO_WHITE;
	NAVY;
	OLD_LACE;
	OLIVE;
	OLIVE_DRAB;
	ORANGE;
	ORANGE_RED;
	ORCHID;
	PALE_GOLDEN_ROD;
	PALE_GREEN;
	PALE_TURQUOISE;
	PALE_VIOLET_RED;
	PAPAYA_WHIP;
	PEACH_PUFF;
	PERU;
	PINK;
	PLUM;
	POWDER_BLUE;
	PURPLE;
	RED;
	ROSY_BROWN;
	ROYAL_BLUE;
	SADDLE_BROWN;
	SALMON;
	SANDY_BROWN;
	SEA_GREEN;
	SEA_SHELL;
	SIENNA;
	SILVER;
	SKY_BLUE;
	SLATE_BLUE;
	SLATE_GRAY;
	SLATE_GREY;
	SNOW;
	SPRING_GREEN;
	STEEL_BLUE;
	TAN;
	TEAL;
	THISLE;
	TOMATO;
	TURQUOISE;
	VIOLET;
	WHEAT;
	WHITE;
	WHITE_SMOKE;
	YELLOW;
	YELLOW_GREEN;
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
	MATRIX(a:Float, b:Float, c:Float, d:Float, e:Float, f:Float);
	
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
	 * Equal to the computed value of ‘font-size’ on the root element.
	 * When specified on the ‘font-size’ property of the root element, 
	 * the ‘rem’ units refer to the property's initial value.
	 */
	REM(value:Float);
	
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
	
	/**
	 * Equal to the advance measure of the "0" 
	 * (ZERO, U+0030) glyph found in the font used to render it.
	 */
	CH(value:Float);
	
	/**
	 * Equal to 1% of the width of the initial containing block.
	 */
	VW(value:Float);
	
	/**
	 * Equal to 1% of the height of the initial containing block.
	 */
	VH(value:Float);
	
	/**
	 * Equal to the smaller of ‘vw’ or ‘vh’.
	 */
	VMIN(value:Float);
	
	/**
	 * Equal to the larger of ‘vw’ or ‘vh’.
	 */
	VMAX(value:Float);
}

/**
 * When computing a length into an aboslute
 * value, holds all the reference data necessary
 * to compute this length
 */
class RelativeLengthReferenceData {
	
	/**
	 * reference for an em length. Represents
	 * the font-size of the element or of the 
	 * parent
	 */
	public var em:Float;
	
	/**
	 * represents the font-size of the root (HTML)
	 * element
	 */
	public var rem:Float;
	
	/**
	 * the current width of the viewport, in pixels
	 */
	public var viewportWidth:Float;
	
	/**
	 * same for viewport height
	 */
	public var viewportHeight:Float;
	
	/**
	 * the measure of the "0" of the element's
	 * font
	 */
	public var ch:Float;
	
	/**
	 * the measure of the "x" of the element's
	 * font
	 */
	public var ex:Float;
	
	public function new() 
	{
		em = 0;
		rem = 0;
		viewportHeight = 0;
		viewportWidth = 0;
		ch = 0;
		ex = 0;
	}
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
	THIN;
	THICK;
	DOTTED;
	DASHED;
	SOLID;
	DOUBLE;
	GROOVE;
	RIDGE;
	INSET;
	OUTSET;
	INVERT;
	UNDERLINE;
	OVERLINE;
	LINE_THROUGH;
	BLINK;
}
