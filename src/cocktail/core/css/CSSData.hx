package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

typedef CSSRuleList = Array<CSSRule>;

typedef PropertyData = {
	var value:String;
	var important:Bool;
	var origin:MatchingPropertyOrigin;
	var selectors:Array<SelectorValue>;
}

enum PropertyOriginValue {
	AUTHOR;
	USER_AGENT;
}

enum SelectorValue {
	UNIVERSAL;
	TYPE(value:String);
	ATTRIBUTE(value:AttributeSelectorValue);
	PSEUDO_CLASS(value:PseudoClassSelectorValue);
	PSEUDO_ELEMENT(value:PseudoElementSelectorValue);
	LINK_PSEUDO_CLASS(value:LinkPseudoClassValue);
	USER_ACTION_PSEUDO_CLASS(value:UserActionPseudoClassValue);
	CLASS(value:String);
	ID(value:String);
	DESCENDANT_COMBINATOR(parent:String, child:String);
	CHILD_COMBINATOR(parent:String, child:String);
	ADJACENT_SIBLING_COMBINATOR(sibling:String, child:String);
	GENERAL_SIBLING_COMBINATOR(sibling:String, child:String);
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
	FIRST_LINE;
	FIRST_LETTER;
}
