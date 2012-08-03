package cocktail.core.css;

import cocktail.core.style.StyleData;

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

typedef SelectorSpecificityData = {
	var idSelectorsNumber:Int;
	var classAttributesAndPseudoClassesNumber:Int;
	var typeAndPseudoElementsNumber:Int;
}

enum PropertyOriginValue {
	AUTHOR;
	USER_AGENT;
}

typedef SelectorData = {
	var components:Array<SelectorComponentValue>;
	var pseudoElement:PseudoElementSelectorValue;
}

enum SelectorComponentValue {
	SELECTOR_ITEM(value:SelectorItemValue);
	COMBINATOR(value:CombinatorValue);
} 

enum SelectorItemValue {
	SIMPLE_SELECTOR_SEQUENCE(value:SimpleSelectorSequenceData);
	SIMPLE_SELECTOR(value:SimpleSelectorValue);
}

enum CombinatorValue {
	DESCENDANT;
	CHILD;
	ADJACENT_SIBLING;
	GENERAL_SIBLING;
}

typedef SimpleSelectorSequenceData = {
	var startValue:SimpleSelectorSequenceStartValue;
	var simpleSelectors:Array<SimpleSelectorSequenceItemValue>;
}

enum SimpleSelectorValue {
	SEQUENCE_START(value:SimpleSelectorSequenceStartValue);
	SEQUENCE_ITEM(value:SimpleSelectorSequenceItemValue);
}

enum SimpleSelectorSequenceItemValue {
	ATTRIBUTE(value:AttributeSelectorValue);
	PSEUDO_CLASS(value:PseudoClassSelectorValue);
	LINK_PSEUDO_CLASS(value:LinkPseudoClassValue);
	USER_ACTION_PSEUDO_CLASS(value:UserActionPseudoClassValue);
	CLASS(value:String);
	ID(value:String);
}

enum SimpleSelectorSequenceStartValue {
	UNIVERSAL;
	TYPE(value:String);
}

enum AttributeSelectorValue {
	ATTRIBUTE(value:String);
	ATTRIBUTE_VALUE(name:String, value:String);
	ATTRIBUTE_LIST(name:String, value:String);
}

enum PseudoClassSelectorValue {
	ROOT;
	NTH_CHILD(index:Int);
	NTH_LAST_CHILD(index:Int);
	FIRST_CHILD;
	LAST_CHILD;
	FIRST_OF_TYPE;
	LAST_OF_TYPE;
	ONLY_CHILD;
	ONLY_OF_TYPE;
	EMPTY;
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

enum PseudoElementSelectorValue {
	NONE;
	FIRST_LINE;
	FIRST_LETTER;
}

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
	END_UNIVERSAL_SELECTOR;
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
