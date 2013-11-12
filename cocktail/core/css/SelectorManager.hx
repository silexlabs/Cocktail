/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.css.CSSData;

/**
 * The selector manager has 2 purposes : 
 * - For a given node and selector, it returns wether the node
 * matches the selector
 * - For a given selector, it can return its specificity (its priority)
 *	 
 * @author Yannick DOMINGUEZ
 */
class SelectorManager 
{
	/**
	 * Used to count the current selector specifity.
	 * Implemented as class attribute to only 
	 * instantiate one
	 */
	private var _selectorSpecificityVO:SelectorSpecificityVO;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		_selectorSpecificityVO = new SelectorSpecificityVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SELECTOR MATCHING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a given node and selector, return wether
	 * the node matches all of the components of the selector
	 */
	public function matchSelector(node:HTMLElement, selector:SelectorVO, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		var components:Array<SelectorComponentValue> = selector.components;
		
		//a flag set to true when the last item in the components array
		//was a combinator.
		//This flag is a shortcut to prevent matching again selector
		//sequence that were matched by the combinator
		var lastWasCombinator:Bool = false;
		
		//loop in all the components of the selector
		var length:Int = components.length;
		for (i in 0...length)
		{
			var component:SelectorComponentValue = components[i];
	
			//wether the current selector component match the node
			var matched:Bool = false;
			
			switch(component)
			{
				case SelectorComponentValue.COMBINATOR(value):
					matched = matchCombinator(node, value, components[i + 1], matchedPseudoClasses);
					lastWasCombinator = true;
					
					//if the combinator is a child combinator, the relevant
					//node becomes the parent node as any subsequent would
					//apply to it instead of the current node
					if (value == CHILD)
					{
						node = castToHTMLElement(node.parentNode);
					}
					
				case SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(value):
					//if the previous item was a combinator, then 
					//this simple selector sequence was already
					//successfuly matched, else the method would have
					//returned
					if (lastWasCombinator == true) 
					{
						matched = true;
						lastWasCombinator = false;
					}
					else
					{
						matched = matchSimpleSelectorSequence(node, value, matchedPseudoClasses);
					}
			}
			
			//if the component is not
			//matched, then the selector is not matched
			if (matched == false)
			{
				return false;
			}
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SELECTOR MATCHING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
		// COMBINATORS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return wether a combinator is matched
	 */
	private function matchCombinator(node:HTMLElement, combinator:CombinatorValue, nextSelectorComponent:SelectorComponentValue, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		//if the node has no parent, it can't match
		//any combinator
		if (node.parentNode == null)
		{
			return false;
		}
		
		var nextSelectorSequence:SimpleSelectorSequenceVO = null;
		//the next component at this point is always a simple
		//selector sequence, there can't be 2 combinators in a row
		//in a selector, it makes the selector invalid
		switch(nextSelectorComponent)
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				nextSelectorSequence = value;
				
			case COMBINATOR(value):	
				return false;
		}
		
		switch(combinator)
		{
			case CombinatorValue.ADJACENT_SIBLING:
				return matchAdjacentSiblingCombinator(node, nextSelectorSequence, matchedPseudoClasses);
				
			case CombinatorValue.GENERAL_SIBLING:
				return matchGeneralSiblingCombinator(node, nextSelectorSequence, matchedPseudoClasses);
				
			case CombinatorValue.CHILD:
				return matchChildCombinator(node, nextSelectorSequence, matchedPseudoClasses);
				
			case CombinatorValue.DESCENDANT:
				return matchDescendantCombinator(node, nextSelectorSequence, matchedPseudoClasses);
		}
	}
	
	/**
	 * Return wether a general sibling combinator is
	 * matched.
	 * 
	 * It is matched if the node has a sibling matching
	 * the preious selector sequence which precedes in 
	 * the DOM tree
	 */
	private function matchGeneralSiblingCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceVO, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		var previousElementSibling:HTMLElement = cast(node.previousElementSibling);
		
		while (previousElementSibling != null)
		{
			if (matchSimpleSelectorSequence(previousElementSibling, nextSelectorSequence, matchedPseudoClasses) == true)
			{
				return true;
			}
			
			previousElementSibling = cast(previousElementSibling.previousElementSibling);
		}
		
		return false;
	}
	
	/**
	 * Same as general sibling combinator, but 
	 * only matched if the first previous
	 * element sibling of the node matches
	 * the previous selector
	 */
	private function  matchAdjacentSiblingCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceVO, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		var previousElementSibling:HTMLElement = cast(node.previousElementSibling);
		
		if (previousElementSibling == null)
		{
			return false;
		}
		
		return matchSimpleSelectorSequence(previousElementSibling, nextSelectorSequence, matchedPseudoClasses);
	}
	
	/**
	 * Return wether a descendant combinator is matched.
	 * It is matched when an ancestor of the node
	 * matches the next selector sequence
	 */
	private function matchDescendantCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceVO, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		var parentNode:HTMLElement = castToHTMLElement(node.parentNode);
		
		//check that at least one ancestor matches
		//the parent selector
		while (parentNode != null)
		{
			if (matchSimpleSelectorSequence(parentNode, nextSelectorSequence, matchedPseudoClasses) == true)
			{
				return true;
			}
			
			parentNode = castToHTMLElement(parentNode.parentNode);
		}
		
		//here no parent matched, so the
		//combinator is not matched
		return false;
	}
	
	/**
	 * Same as matchDescendantCombinator, but the 
	 * next selector sequence must be matched by the 
	 * direct parent of the node and not just any ancestor
	 */
	private function matchChildCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceVO, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		return matchSimpleSelectorSequence(cast(node.parentNode), nextSelectorSequence, matchedPseudoClasses);
	}
	
		// SIMPLE SELECTORS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return wether a node match a simple selector sequence starter.
	 * 
	 * A simple selector sequence is a list of simple selector, 
	 * for instance in : div.myclass , div is a simple selector, .myclass is too 
	 * and together they are a simple selector sequence
	 * 
	 * A simple selector sequence always start with either a type (like 'div') or a universal ('*')
	 * selector
	 */
	private function matchSimpleSelectorSequenceStart(node:HTMLElement, simpleSelectorSequenceStart:SimpleSelectorSequenceStartValue):Bool
	{
		switch(simpleSelectorSequenceStart)
		{
			case SimpleSelectorSequenceStartValue.TYPE(value):
				return node.tagName == value;
				
			case SimpleSelectorSequenceStartValue.UNIVERSAL:
				return true;
		}
	}
	
	/**
	 * Return weher a node match an item of a simple selector sequence.
	 * The possible items of a simple selector are all simple selectors
	 * (class, ID...) but type or universal which are always at the 
	 * begining of a simple selector sequence
	 */
	private function matchSimpleSelectorSequenceItem(node:HTMLElement, simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		switch(simpleSelectorSequenceItem)
		{
			//for this check the list of class of the node	
			case CSS_CLASS(value):
				var classList:Array<String> = node.classList;
				
				//here the node has no classes
				if (classList == null)
				{ 
					return false;
				}
				
				var length:Int = classList.length;
				for (i in 0...length)
				{
					if (value == classList[i])
					{
						return true;
					}
				}
				
				return false;
				
			//for this check the id attribute of the node	
			case ID(value):
				return node.id == value;	
				
			case PSEUDO_CLASS(value):
				return matchPseudoClassSelector(node, value, matchedPseudoClasses);	
			
			case ATTRIBUTE(value):
				return matchAttributeSelector(node, value);
		}		
	}
	
	/**
	 * Return wether all items in a simple selector
	 * sequence are matched
	 */
	private function matchSimpleSelectorSequence(node:HTMLElement, simpleSelectorSequence:SimpleSelectorSequenceVO, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		//check if sequence start matches
		if (matchSimpleSelectorSequenceStart(node, simpleSelectorSequence.startValue) == false)
		{
			return false;
		}
		
		//check all items
		var simpleSelectors:Array<SimpleSelectorSequenceItemValue> =  simpleSelectorSequence.simpleSelectors;
		var length:Int = simpleSelectors.length;
		for (i in 0...length)
		{
			var simpleSelectorSequence:SimpleSelectorSequenceItemValue = simpleSelectors[i];
			if (matchSimpleSelectorSequenceItem(node, simpleSelectorSequence, matchedPseudoClasses) == false)
			{
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * Return wether an attribute selector
	 * matches the node
	 */
	private function matchAttributeSelector(node:HTMLElement, attributeSelector:AttributeSelectorValue):Bool
	{
		switch(attributeSelector)
		{
			case AttributeSelectorValue.ATTRIBUTE(value):
				return node.getAttribute(value) != null;
				
			case AttributeSelectorValue.ATTRIBUTE_VALUE(name, value):
				return node.getAttribute(name) == value;
				
			case AttributeSelectorValue.ATTRIBUTE_LIST(name, value):
				return matchAttributeList(node, name, value);
				
			case AttributeSelectorValue.ATTRIBUTE_VALUE_BEGINS(name, value):
				return matchAttributeBeginValue(node, name, value);
				
			case AttributeSelectorValue.ATTRIBUTE_VALUE_CONTAINS(name, value):
				return matchAttributeContainsValue(node, name, value);
				
			case AttributeSelectorValue.ATTRIBUTE_VALUE_ENDS(name, value):
				return matchAttributeEndValue(node, name, value);
				
			case AttributeSelectorValue.ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(name, value):
				return matchAttributeBeginsHyphenList(node, name, value);
		}
		
		return true;
	}
	
	/**
	 * return wether the value of the "name" attribute is a hyphen
	 * separated list whose first item is "value"
	 */
	private function matchAttributeBeginsHyphenList(node:HTMLElement, name:String, value:String):Bool
	{
		var attributeValue:String = node.getAttribute(name);
		//early exit if the attribute doesn't exist on the node
		if (attributeValue == null)
		{
			return false;
		}
		
		//valid if value exactly matches the attribute
		if (attributeValue == value)
		{
			return true;
		}
		
		//else valid if begins with value + hyphen
		var hyphenValue:String = value + "-";
		return attributeValue.substr(0, hyphenValue.length) == hyphenValue;
	}
	
	/**
	 * Return wether the value of the "name" attribute ends with "value"
	 */
	private function matchAttributeEndValue(node:HTMLElement, name:String, value:String):Bool
	{
		var attributeValue:String = node.getAttribute(name);
		//early exit if the attribute doesn't exist on the node
		if (attributeValue == null)
		{
			return false;
		}
		
		return attributeValue.lastIndexOf(value) == attributeValue.length - value.length;
	}
	
	/**
	 * Return wether the value of the "name" attribute contains "value"
	 */
	private function matchAttributeContainsValue(node:HTMLElement, name:String, value:String):Bool
	{
		var attributeValue:String = node.getAttribute(name);
		//early exit if the attribute doesn't exist on the node
		if (attributeValue == null)
		{
			return false;
		}
		
		return attributeValue.indexOf(value) != -1;
	}
	
	/**
	 * Return wether the value of the "name" attribute
	 * on the node begins with "value"
	 */
	private function matchAttributeBeginValue(node:HTMLElement, name:String, value:String):Bool
	{
		var attributeValue:String = node.getAttribute(name);
		//early exit if the attribute doesn't exist on the node
		if (attributeValue == null)
		{
			return false;
		}
		
		return attributeValue.indexOf(value) == 0;
	}
	
	/**
	 * Return wether "value" is a part of the "name" attribute
	 * which is a white-space separated list of values
	 */
	private function matchAttributeList(node:HTMLElement, name:String, value:String):Bool
	{
		var attributeValue:String = node.getAttribute(name);
		//early exit if the attribute doesn't exist on the node
		if (attributeValue == null)
		{
			return false;
		}
		
		var attributeValueAsList:Array<String> = attributeValue.split(" ");
		for (i in 0...attributeValueAsList.length)
		{
			if (attributeValueAsList[i] == value)
			{
				return true;
			}
		}
		
		return false;
	}
	
	/**
	 * Return wether a pseudo class matches
	 * the node
	 */
	private function matchPseudoClassSelector(node:HTMLElement, pseudoClassSelector:PseudoClassSelectorValue, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		switch (pseudoClassSelector)
		{
			case PseudoClassSelectorValue.STRUCTURAL(value):
				return matchStructuralPseudoClassSelector(node, value);
				
			case PseudoClassSelectorValue.LINK(value):
				return matchLinkPseudoClassSelector(node, value, matchedPseudoClasses);
				
			case PseudoClassSelectorValue.USER_ACTION(value):
				return matchUserActionPseudoClassSelector(node, value, matchedPseudoClasses);	
				
			case PseudoClassSelectorValue.TARGET:
				return matchTargetPseudoClassSelector(node);
				
			case PseudoClassSelectorValue.NOT(value):
				return matchNegationPseudoClassSelector(node, value);
				
			case PseudoClassSelectorValue.LANG(value):
				return matchLangPseudoClassSelector(node, value);
				
			case PseudoClassSelectorValue.UI_ELEMENT_STATES(value):
				return matchUIElementStatesSelector(node, value, matchedPseudoClasses);

            case PseudoClassSelectorValue.FULLSCREEN:
                return matchedPseudoClasses.fullscreen;
			
			case PseudoClassSelectorValue.UNKNOWN :
				return false;
		}
	}
	
	/**
	 * Return wether a UI state selector
	 * matches the node
	 */
	private function matchUIElementStatesSelector(node:HTMLElement, uiElementState:UIElementStatesValue, matchedPseudoClasses:MatchedPseudoClassesVO):Bool
	{
		switch(uiElementState)
		{
			case UIElementStatesValue.CHECKED:
				return matchedPseudoClasses.checked;
				
			case UIElementStatesValue.DISABLED:
				return matchedPseudoClasses.disabled;
				
			case UIElementStatesValue.ENABLED:
				return matchedPseudoClasses.enabled;
		}
	}
	
	/**
	 * Return wether a negation pseudo-class selector
	 * matches the node
	 */
	private function matchNegationPseudoClassSelector(node:HTMLElement, negationSimpleSelectorSequence:SimpleSelectorSequenceVO):Bool
	{
		return false;
	}

	/**
	 * Return wether a lang pseudo-class selector
	 * matches the node
	 */
	private function matchLangPseudoClassSelector(node:HTMLElement, lang:Array<String>):Bool
	{
		return false;
	}
	
	/**
	 * Return wether a structural pseudo-class selector
	 * matches the node
	 */
	private function matchStructuralPseudoClassSelector(node:HTMLElement, structuralPseudoClassSelector:StructuralPseudoClassSelectorValue):Bool
	{
		switch(structuralPseudoClassSelector)
		{
			case StructuralPseudoClassSelectorValue.EMPTY:
				return node.hasChildNodes();
				
			case StructuralPseudoClassSelectorValue.FIRST_CHILD:
				
				//HTML root element is not considered a first child
				//
				//TODO : parent of root node should actually be a document
				if (node.parentNode == null)
				{
					return false;
				}
				
				return node.previousElementSibling == null;
				
			case StructuralPseudoClassSelectorValue.LAST_CHILD:
				
				//HTML root element not considered last child
				if (node.parentNode == null)
				{
					return false;
				}
				
				return node.nextElementSibling == null;
				
			case StructuralPseudoClassSelectorValue.ONLY_CHILD:
				
				//HTML root element is not considered only child
				if (node.parentNode == null)
				{
					return false;
				}
				
				return node.parentNode.childNodes.length == 1;
				
			case StructuralPseudoClassSelectorValue.ROOT:
				return node.tagName == HTMLConstants.HTML_HTML_TAG_NAME && node.parentNode == null;
				
			case StructuralPseudoClassSelectorValue.ONLY_OF_TYPE:
				return matchOnlyOfType(node);
				
			case StructuralPseudoClassSelectorValue.FIRST_OF_TYPE:
				return matchFirstOfType(node);
				
			case StructuralPseudoClassSelectorValue.LAST_OF_TYPE:
				return matchLastOfType(node);	
				
			case StructuralPseudoClassSelectorValue.NTH_CHILD(value):
				return matchNthChild(node, value);
				
			case StructuralPseudoClassSelectorValue.NTH_LAST_CHILD(value):
				return matchNthLastChild(node, value);
				
			case StructuralPseudoClassSelectorValue.NTH_LAST_OF_TYPE(value):
				return matchNthLastOfType(node, value);
				
			case StructuralPseudoClassSelectorValue.NTH_OF_TYPE(value):
				return matchNthOfType(node, value);
		}
	}
	
	private function matchNthChild(node:HTMLElement, value:StructuralPseudoClassArgumentValue):Bool
	{
		return false;
	}
	
	private function matchNthLastChild(node:HTMLElement, value:StructuralPseudoClassArgumentValue):Bool
	{
		return false;
	}
	
	private function matchNthLastOfType(node:HTMLElement, value:StructuralPseudoClassArgumentValue):Bool
	{
		return false;
	}
	
	private function matchNthOfType(node:HTMLElement, value:StructuralPseudoClassArgumentValue):Bool
	{
		return false;
	}
	
	/**
	 * Return wether the node is the first 
	 * element among its element siblings of
	 * its type (tag name)
	 */
	private function matchFirstOfType(node:HTMLElement):Bool
	{
		var type:String = node.tagName;
		
		var previousElementSibling:HTMLElement = cast(node.previousElementSibling);
		
		while (previousElementSibling != null)
		{
			if (previousElementSibling.tagName == type)
			{
				return false;
			}
			
			previousElementSibling = cast(previousElementSibling.previousElementSibling);
		}
		
		return true;
	}
	
	/**
	 * Same as above but for last element
	 */
	private function matchLastOfType(node:HTMLElement):Bool
	{
		var type:String = node.tagName;
		
		var nextElementSibling:HTMLElement = cast(node.nextElementSibling);
		
		while (nextElementSibling != null)
		{
			if (nextElementSibling.tagName == type)
			{
				return false;
			}
			
			nextElementSibling = cast(nextElementSibling.nextElementSibling);
		}
		
		return true;
	}
	
	/**
	 * Return wether this node is the only among
	 * its element sibling of its type (tag name)
	 */
	private function matchOnlyOfType(node:HTMLElement):Bool
	{
		//to be the only of its type is the same as
		//being the first and last of its type
		return matchLastOfType(node) == true && matchFirstOfType(node) == true;
	}
	
	/**
	 * Return wether a link pseudo-class selector
	 * matches the node
	 */
	private function matchLinkPseudoClassSelector(node:HTMLElement, linkPseudoClassSelector:LinkPseudoClassValue, matchedPseudoClass:MatchedPseudoClassesVO):Bool
	{
		switch(linkPseudoClassSelector)
		{
			case LinkPseudoClassValue.LINK:
				return matchedPseudoClass.link;
				
			case LinkPseudoClassValue.VISITED:
				return false;
		}
	}
	
	/**
	 * Return wether a user pseudo-class selector
	 * matches the node
	 */
	private function matchUserActionPseudoClassSelector(node:HTMLElement, userActionPseudoClassSelector:UserActionPseudoClassValue, matchedPseudoClass:MatchedPseudoClassesVO):Bool
	{
		switch(userActionPseudoClassSelector)
		{
			case UserActionPseudoClassValue.ACTIVE:
				return matchedPseudoClass.active;
				
			case UserActionPseudoClassValue.HOVER:
				return matchedPseudoClass.hover;
				
			case UserActionPseudoClassValue.FOCUS:
				return matchedPseudoClass.focus;
		}
	}
	
	/**
	 * Return wether the target pseudo-class 
	 * matches the node.
	 */
	private function matchTargetPseudoClassSelector(node:HTMLElement):Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SELECTOR SPECIFICITY METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the specifity of a selector, which is
	 * its priority next to other selector
	 */
	public function getSelectorSpecifity(selector:SelectorVO):Int
	{
		//holds the specificity data, is passed by reference
		//to all methods which can increment the specificity
		//attribute
		//reset before usage
		_selectorSpecificityVO.classAttributesAndPseudoClassesNumber = 0;
		_selectorSpecificityVO.idSelectorsNumber = 0;
		_selectorSpecificityVO.typeAndPseudoElementsNumber = 0;
		
		//a pseudo element increment the specificity
		switch (selector.pseudoElement)
		{
			case PseudoElementSelectorValue.FIRST_LETTER,
			PseudoElementSelectorValue.FIRST_LINE,
			PseudoElementSelectorValue.AFTER,
			PseudoElementSelectorValue.BEFORE:
				_selectorSpecificityVO.typeAndPseudoElementsNumber++;
			
			case PseudoElementSelectorValue.NONE:	
		}
		
		var components:Array<SelectorComponentValue> = selector.components;
		var length:Int = components.length;
		for (i in 0...length)
		{
			var component:SelectorComponentValue = components[i];
			
			switch(component)
			{
				case SelectorComponentValue.COMBINATOR(value):
					
				case SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(value):
					getSimpleSelectorSequenceSpecificity(value, _selectorSpecificityVO);
			}
		}
		
		//specificity has 3 categories, whose int values are concatenated
		//for instance, if idSelectorsNumber is equal to 1, classAttributesAndPseudoClassesNumber to 0
		//and typeAndPseudoElementsNumber to 2,
		//the specificity is 102
		return _selectorSpecificityVO.idSelectorsNumber * 100 + _selectorSpecificityVO.classAttributesAndPseudoClassesNumber * 10 + _selectorSpecificityVO.typeAndPseudoElementsNumber;
	}
	
	/**
	 * Increment the specificity of simple selector sequence
	 */
	private function getSimpleSelectorSequenceSpecificity(simpleSelectorSequence:SimpleSelectorSequenceVO, selectorSpecificity:SelectorSpecificityVO):Void
	{
		getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequence.startValue, selectorSpecificity);
		
		var simpleSelectors:Array<SimpleSelectorSequenceItemValue> = simpleSelectorSequence.simpleSelectors;
		var length:Int = simpleSelectors.length;
		for (i in 0...length)
		{
			var simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue = simpleSelectors[i];
			getSimpleSelectorSequenceItemSpecificity(simpleSelectorSequenceItem, selectorSpecificity);
		}
	}
	
	/**
	 * Increment specificity according to a simple selector start item
	 */
	private function getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequenceStart:SimpleSelectorSequenceStartValue, selectorSpecificity:SelectorSpecificityVO):Void
	{
		switch(simpleSelectorSequenceStart)
		{
			case SimpleSelectorSequenceStartValue.TYPE(value):
				selectorSpecificity.typeAndPseudoElementsNumber++;
				
			case SimpleSelectorSequenceStartValue.UNIVERSAL:
		}
	}
	
	/**
	 * Increment specificity according to a simple selector item
	 */
	private function getSimpleSelectorSequenceItemSpecificity(simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue, selectorSpecificity:SelectorSpecificityVO):Void
	{
		switch (simpleSelectorSequenceItem)
		{
			case ATTRIBUTE(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case PSEUDO_CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case CSS_CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case ID(value):
				selectorSpecificity.idSelectorsNumber++;
		}
	}

	inline private function castToHTMLElement( node : Node ) : Null<HTMLElement> {
		switch( node.nodeType ){
			case DOMConstants.ELEMENT_NODE :
				return cast( node , HTMLElement );
			default : 
				return null;
		}
		
	}
}
