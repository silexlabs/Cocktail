package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

typedef CSSRuleList = Array<CSSRule>;

typedef PropertyData = {
	var value:String;
	var important:String;
	var origin:PropertyOriginValue;
	var selector:SelectorData;
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
	var combinators:Array<CombinatorValue>;
	var pseudoElement:PseudoElementSelectorValue;
}

enum SelectorComponentValue {
	SIMPLE_SELECTOR_SEQUENCE(value:SimpleSelectorSequenceData);
	SIMPLE_SELECTOR(value:SimpleSelectorValue);
} 

enum CombinatorValue {
	NONE(value:SelectorComponentValue);
	DESCENDANT(parent:SelectorComponentValue, child:SelectorComponentValue);
	CHILD(parent:SelectorComponentValue, child:SelectorComponentValue);
	ADJACENT_SIBLING(sibling:SelectorComponentValue, child:SelectorComponentValue);
	GENERAL_SIBLING(sibling:SelectorComponentValue, child:SelectorComponentValue);
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
