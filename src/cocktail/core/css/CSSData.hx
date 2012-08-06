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
	var typedValue:PropertyValue;
}

enum PropertyValue {
	FONT_SIZE(value:FontSize);
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

//TODO 2 : add before and adter for generated content
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

enum StyleValue {
	INTEGER(value:Int);
	NUMBER(value:Float);
	PERCENTAGE(value:Float);
	IDENTIFIER(value:String);
	URL(value:String);
	STRING(value:String);
	LENGTH(value:Length);
	ANGLE(value:Angle);
	TIME(value:TimeValue);
	COLOR(VALUE:CSSColor);
	INHERIT;
}

//////////////////////////////////////////////////////////////////////////////////////////
// PARSERS STATES ENUMS
//////////////////////////////////////////////////////////////////////////////////////////

enum SelectorParserState {
	IGNORE_SPACES;
	BEGIN_SIMPLE_SELECTOR;
	END_SIMPLE_SELECTOR;
	SIMPLE_SELECTOR;
	END_TYPE_SELECTOR;
	END_CLASS_SELECTOR;
	END_ID_SELECTOR;
	BEGIN_COMBINATOR;
	COMBINATOR;
	BEGIN_PSEUDO_SELECTOR;
	END_UNIVERSAL_SELECTOR;
	PSEUDO_ELEMENT_SELECTOR;
	BEGIN_ATTRIBUTE_SELECTOR;
	INVALID_SELECTOR;
}

enum StyleDeclarationParserState {
	STYLE_NAME;
	STYLE_VALUE;
	IGNORE_SPACES;
	INVALID_STYLE;
	STYLE_SEPARATOR;
	BEGIN_STYLE_NAME;
}

enum StyleValueParserState {
	IGNORE_SPACES;
	BEGIN_VALUE;
	IDENT;
	NUMBER_OR_INTEGER;
	SPACE_OR_END;
	INVALID_STYLE_VALUE;
	IMPORTANT;
	END;
}

enum AttributeSelectorParserState {
	ATTRIBUTE;
	OPERATOR;
	BEGIN_VALUE;
	VALUE;
	END_SELECTOR;
	INVALID_SELECTOR;
}

enum StyleRuleParserState {
	IGNORE_SPACES;
	BEGIN_SELECTOR;
	END_SELECTOR;
	SELECTOR;
	BEGIN_STYLES;
	STYLES;
	END_STYLES;
}

enum StyleSheetRulesParserState {
	IGNORE_SPACES;
	BEGIN_RULE;
	RULE;
	END_RULE;
}

enum StyleSheetRuleParserState {
	IGNORE_SPACES;
	BEGIN_RULE;
	BEGIN_AT_RULE;
	END_MEDIA_RULE;
	RULE;
	END_STYLE_RULE;
}