/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

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
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SELECTOR MATCHING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a given node and selector, return wether
	 * the node matches all of the components of the selector
	 * 
	 * TODO 1 : array should be traversed in reverse order ?
	 */
	public function matchSelector(node:HTMLElement, selector:SelectorData):Bool
	{
		var components:Array<SelectorComponentValue> = selector.components;
		
		//simple selectors and combinators are parsed from left to 
		//right but are matched from right to left to match
		//combinators logic
		components.reverse();
		
		//a flag set to true when the last item in the components array
		//was a combinator.
		//This flag is a shortcut to prevent matching again selector
		//sequence that were matched by the combinator
		var lastWasCombinator:Bool = false;
		
		//loop in all the components of the selector
		for (i in 0...components.length)
		{
			var component:SelectorComponentValue = components[i];
	
			//wether the current selector component match the node
			var matched:Bool = false;
			
			switch(component)
			{
				case SelectorComponentValue.COMBINATOR(value):
					matched = matchCombinator(node, value, cast(components[i + 1]));
					lastWasCombinator = true;
					
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
						matched = matchSimpleSelectorSequence(node, value);
					}
			}
			
			//if the component is not
			//matched, then the selector is not matched
			if (matched == false)
			{
				//back to initial order
				components.reverse();
				
				return false;
			}
		}
		
		//back to initial order
		components.reverse();
		
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
	private function matchCombinator(node:HTMLElement, combinator:CombinatorValue, nextSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		//if the node has no parent, it can't match
		//any combinator
		if (node.parentNode == null)
		{
			return false;
		}
		
		switch(combinator)
		{
			case CombinatorValue.ADJACENT_SIBLING:
				return matchAdjacentSiblingCombinator(node, nextSelectorSequence);
				
			case CombinatorValue.GENERAL_SIBLING:
				return matchGeneralSiblingCombinator(node, nextSelectorSequence);
				
			case CombinatorValue.CHILD:
				return matchChildCombinator(node, nextSelectorSequence);
				
			case CombinatorValue.DESCENDANT:
				return matchDescendantCombinator(node, nextSelectorSequence);
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
	private function  matchGeneralSiblingCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		var previousElementSibling:HTMLElement = node.previousElementSibling;
		
		while (previousElementSibling != null)
		{
			if (matchSimpleSelectorSequence(previousElementSibling, nextSelectorSequence) == true)
			{
				return true;
			}
			
			previousElementSibling = previousElementSibling.previousElementSibling;
		}
		
		return false;
	}
	
	/**
	 * Same as general sibling combinator, but 
	 * only matched if the first previous
	 * element sibling of the node matches
	 * the previous selector
	 */
	private function  matchAdjacentSiblingCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		var previousElementSibling:HTMLElement = node.previousElementSibling;
		
		if (previousElementSibling == null)
		{
			return false;
		}
		
		return matchSimpleSelectorSequence(previousElementSibling, nextSelectorSequence);
	}
	
	/**
	 * Return wether a descendant combinator is matched.
	 * It is matched when an ancestor of the node
	 * matches the next selector sequence
	 */
	private function matchDescendantCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		var parentNode:HTMLElement = node.parentNode;
		
		//check that at least one ancestor matches
		//the parent selector
		while (parentNode != null)
		{
			if (matchSimpleSelectorSequence(parentNode, nextSelectorSequence) == true)
			{
				return true;
			}
			
			parentNode = parentNode.parentNode;
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
	private function matchChildCombinator(node:HTMLElement, nextSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		return matchSimpleSelectorSequence(node.parentNode, nextSelectorSequence);
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
				return node.tagName == value.toUpperCase();
				
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
	private function matchSimpleSelectorSequenceItem(node:HTMLElement, simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue):Bool
	{
		switch(simpleSelectorSequenceItem)
		{
			case ATTRIBUTE(value):
				return matchAttributeSelector(node, value);
				
			//for this check the className of the node	
			case CLASS(value):
				//TODO 1 : add class list
				return node.className.indexOf(value) != -1;
				
			//for this check the id attribute of the node	
			case ID(value):
				return node.id == value;
				
			case PSEUDO_CLASS(value):
				return matchPseudoClassSelector(node, value);
		}		
	}
	
	/**
	 * Return wether all items in a simple selector
	 * sequence are matched
	 */
	private function matchSimpleSelectorSequence(node:HTMLElement, simpleSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		//check if sequence start matches
		if (matchSimpleSelectorSequenceStart(node, simpleSelectorSequence.startValue) == false)
		{
			return false;
		}
		
		//check all items
		for (i in 0...simpleSelectorSequence.simpleSelectors.length)
		{
			var simpleSelectorSequence:SimpleSelectorSequenceItemValue = simpleSelectorSequence.simpleSelectors[i];
			if (matchSimpleSelectorSequenceItem(node, simpleSelectorSequence) == false)
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
	 * return wether the valu of the "name" attribute is a hyphen
	 * separated lsit whose first item is "value"
	 */
	private function matchAttributeBeginsHyphenList(node:HTMLElement, name:String, value:String):Bool
	{
		var attributeValue:String = node.getAttribute(name);
		//early exit if the attribute doesn't exist on the node
		if (attributeValue == null)
		{
			return false;
		}
		
		var attributeValueAsList:Array<String> = attributeValue.split("-");
		return attributeValueAsList[0] == value;
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
	private function matchPseudoClassSelector(node:HTMLElement, pseudoClassSelector:PseudoClassSelectorValue):Bool
	{
		switch (pseudoClassSelector)
		{
			case PseudoClassSelectorValue.STRUCTURAL(value):
				return matchStructuralPseudoClassSelector(node, value);
				
			case PseudoClassSelectorValue.LINK(value):
				return matchLinkPseudoClassSelector(node, value);
				
			case PseudoClassSelectorValue.USER_ACTION(value):
				return matchUserActionPseudoClassSelector(node, value);	
				
			case PseudoClassSelectorValue.TARGET:
				return matchTargetPseudoClassSelector(node);
				
			case PseudoClassSelectorValue.NOT(value):
				return matchNegationPseudoClassSelector(node, value);
				
			case PseudoClassSelectorValue.LANG(value):
				return matchLangPseudoClassSelector(node, value);
		}
	}
	
	/**
	 * Return wether a negation pseudo-class selector
	 * matches the node
	 */
	private function matchNegationPseudoClassSelector(node:HTMLElement, negationSimpleSelectorSequence:SimpleSelectorSequenceData):Bool
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
				return node.previousSibling == null;
				
			case StructuralPseudoClassSelectorValue.LAST_CHILD:
				return node.nextSibling == null;
				
			case StructuralPseudoClassSelectorValue.ONLY_CHILD:
				return node.parentNode.childNodes.length == 1;
				
			case StructuralPseudoClassSelectorValue.ROOT:
				return node.tagName == HTMLConstants.HTML_HTML_TAG_NAME && node.parentNode == null;
				
			case StructuralPseudoClassSelectorValue.ONLY_OF_TYPE:
				return matchOnlyOfType(node);
				
			case StructuralPseudoClassSelectorValue.FIRST_OF_TYPE:
				return matchFirstOfType(node);
				
			case StructuralPseudoClassSelectorValue.LAST_OF_TYPE:
				return matchLastOfType(node);	
		}
		
		return true;
	}
	
	/**
	 * Return wether the node is the first 
	 * element among its element siblings of
	 * its type (tag name)
	 */
	private function matchFirstOfType(node:HTMLElement):Bool
	{
		var type:String = node.tagName;
		
		var previousElementSibling:HTMLElement = node.previousElementSibling;
		
		while (previousElementSibling != null)
		{
			if (previousElementSibling.tagName == type)
			{
				return false;
			}
			
			previousElementSibling = previousElementSibling.previousElementSibling;
		}
		
		return true;
	}
	
	/**
	 * Same as above but for last element
	 */
	private function matchLastOfType(node:HTMLElement):Bool
	{
		var type:String = node.tagName;
		
		var nextElementSibling:HTMLElement = node.nextElementSibling;
		
		while (nextElementSibling != null)
		{
			if (nextElementSibling.tagName == type)
			{
				return false;
			}
			
			nextElementSibling = nextElementSibling.nextElementSibling;
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
	private function matchLinkPseudoClassSelector(node:HTMLElement, linkPseudoClassSelector:LinkPseudoClassValue):Bool
	{
		return true;
	}
	
	/**
	 * Return wether a user pseudo-class selector
	 * matches the node
	 */
	private function matchUserActionPseudoClassSelector(node:HTMLElement, value:UserActionPseudoClassValue):Bool
	{
		return true;
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
	public function getSelectorSpecifity(selector:SelectorData):Int
	{
		//holds the specificity data, is passe by reference
		//to all methods which can increment the specificity
		//attribute
		var selectorSpecificity:SelectorSpecificityData = {
			idSelectorsNumber:0,
			classAttributesAndPseudoClassesNumber:0,
			typeAndPseudoElementsNumber:0
		}
		
		//a pseudo element increment the specificity
		switch (selector.pseudoElement)
		{
			case PseudoElementSelectorValue.FIRST_LETTER,
			PseudoElementSelectorValue.FIRST_LINE:
				selectorSpecificity.typeAndPseudoElementsNumber++;
			
			case PseudoElementSelectorValue.NONE:	
		}
		
		var components:Array<SelectorComponentValue> = selector.components;
		
		for (i in 0...components.length)
		{
			var component:SelectorComponentValue = components[i];
			
			switch(component)
			{
				case SelectorComponentValue.COMBINATOR(value):
					
				case SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(value):
					getSimpleSelectorSequenceSpecificity(value, selectorSpecificity);
			}
		}
		
		//specificity has 3 categories, whose int values are concatenated as a string then parsed as int
		//for instance, if idSelectorsNumber is equal to 1, classAttributesAndPseudoClassesNumber to 0
		//and typeAndPseudoElementsNumber to 2,
		//the specificity is 102
		var concatenatedSpecificity:String = Std.string(selectorSpecificity.idSelectorsNumber) + Std.string(selectorSpecificity.classAttributesAndPseudoClassesNumber) + Std.string(selectorSpecificity.typeAndPseudoElementsNumber);

		return Std.parseInt(concatenatedSpecificity);
	}
	
	/**
	 * Increment the specificity of simple selector sequence
	 */
	private function getSimpleSelectorSequenceSpecificity(simpleSelectorSequence:SimpleSelectorSequenceData, selectorSpecificity:SelectorSpecificityData):Void
	{
		getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequence.startValue, selectorSpecificity);
		
		for (i in 0...simpleSelectorSequence.simpleSelectors.length)
		{
			var simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue = simpleSelectorSequence.simpleSelectors[i];
			getSimpleSelectorSequenceItemSpecificity(simpleSelectorSequenceItem, selectorSpecificity);
		}
	}
	
	/**
	 * Increment specificity according to a simple selector start item
	 */
	private function getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequenceStart:SimpleSelectorSequenceStartValue, selectorSpecificity:SelectorSpecificityData):Void
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
	private function getSimpleSelectorSequenceItemSpecificity(simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue, selectorSpecificity:SelectorSpecificityData):Void
	{
		switch (simpleSelectorSequenceItem)
		{
			case ATTRIBUTE(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case PSEUDO_CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case ID(value):
				selectorSpecificity.idSelectorsNumber++;
		}
	}
}