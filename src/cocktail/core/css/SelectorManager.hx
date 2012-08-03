/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

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
	 */
	public function matchSelector(node:HTMLElement, selector:SelectorData):Bool
	{
		var components:Array<SelectorComponentValue> = selector.components;
		
		//loop in all the components of the selector
		for (i in 0...components.length)
		{
			var component:SelectorComponentValue = components[i];
	
			//wether the current selector component match the node
			var matched:Bool = false;
			
			switch(component)
			{
				case SelectorComponentValue.COMBINATOR(value):
					matched = matchCombinator(node, value, cast(components[i-1]), cast(components[i+1]));
					
				case SelectorComponentValue.SELECTOR_ITEM(value):
					matched = matchSelectorItem(node, value);
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
	private function matchCombinator(node:HTMLElement, combinator:CombinatorValue, previousSelectorItem:SelectorItemValue, nextSelectorItem:SelectorItemValue):Bool
	{
		switch(combinator)
		{
			case CombinatorValue.ADJACENT_SIBLING:
				//TODO
				return false;
				
			case CombinatorValue.GENERAL_SIBLING:
				//TODO
				return false;
				
			case CombinatorValue.CHILD:
				return matchChildCombinator(node, previousSelectorItem, nextSelectorItem);
				
			case CombinatorValue.DESCENDANT:
				return matchDescendantCombinator(node, previousSelectorItem, nextSelectorItem);
		}
	}
	
	/**
	 * Return wether a descendant combinator is matched.
	 * It is matched when the node matches the 
	 * childSelectorItem and an acestor of the node
	 * matches the parentSelectorItem
	 */
	private function matchDescendantCombinator(node:HTMLElement, parentSelectorItem:SelectorItemValue, childSelectorItem:SelectorItemValue):Bool
	{
		//if the node has no parent, it can't match
		//this combinator
		if (node.parentNode == null)
		{
			return false;
		}
		
		//wether the node matches its selector
		if (matchSelectorItem(node, childSelectorItem) == false)
		{
			return false;
		}
		
		var parent:HTMLElement = node.parentNode;
		
		var matched:Bool = false;
		
		//check that at least one ancestor matches
		//the parent selector
		while (parent != null)
		{
			if (matchSelectorItem(parent, parentSelectorItem) == true)
			{
				return true;
			}
			
			parent = parent.parentNode;
		}
		
		//here no parent matched, so the
		//combinator is not matched
		return false;
		
	}
	
	/**
	 * Same as matchDescendantCombinator, but the 
	 * parentSelectorItem must be matched by the 
	 * direct parent of the node and not any ancestor
	 */
	private function matchChildCombinator(node:HTMLElement, parentSelectorItem:SelectorItemValue, childSelectorItem:SelectorItemValue):Bool
	{
		if (node.parentNode == null)
		{
			return false;
		}
		
		if (matchSelectorItem(node, childSelectorItem) == false)
		{
			return false;
		}
		
		return matchSelectorItem(node.parentNode, parentSelectorItem);
	}
	
	private function matchSelectorItem(node:HTMLElement, selectorItem:SelectorItemValue):Bool
	{
		switch (selectorItem)
		{
			case SelectorItemValue.SIMPLE_SELECTOR(value):
				return matchSimpleSelector(node, value);
				
			case SelectorItemValue.SIMPLE_SELECTOR_SEQUENCE(value):
				return matchSimpleSelectorSequence(node, value);
		}
	}
	
		// SIMPLE SEELCTORS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return wether a node matches a simple selector
	 * (like for instance a class selector or an ID selector)
	 */
	private function matchSimpleSelector(node:HTMLElement, simpleSelector:SimpleSelectorValue):Bool
	{
		switch (simpleSelector)
		{
			case SimpleSelectorValue.SEQUENCE_START(value):
				return matchSimpleSelectorSequenceStart(node, value);
				
			case SimpleSelectorValue.SEQUENCE_ITEM(value):
				return matchSimpleSelectorSequenceItem(node, value);
		}
	}
	
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
				
			case LINK_PSEUDO_CLASS(value):
				return matchLinkPseudoClassSelector(node, value);
				
			case USER_ACTION_PSEUDO_CLASS(value):
				return matchUserActionPseudoClassSelector(node, value);
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
		return true;
	}
	
	/**
	 * Return wether an pseudo-class selector
	 * matches the node
	 */
	private function matchPseudoClassSelector(node:HTMLElement, pseudoClassSelector:PseudoClassSelectorValue):Bool
	{
		return true;
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
					
				case SelectorComponentValue.SELECTOR_ITEM(value):
					getSelectorItemSpecifity(value, selectorSpecificity);
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
	 * Increment the specificity of simple selector item
	 */
	private function getSelectorItemSpecifity(selector:SelectorItemValue, selectorSpecificity:SelectorSpecificityData):Void
	{
		switch (selector)
		{
			case SelectorItemValue.SIMPLE_SELECTOR(value):
				getSimpleSelectorSpecificity(value, selectorSpecificity); 
				
			case SelectorItemValue.SIMPLE_SELECTOR_SEQUENCE(value):
				getSimpleSelectorSequenceSpecificity(value, selectorSpecificity);
		}
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
	 * Increment specificity according to a simple selector
	 */
	private function getSimpleSelectorSpecificity(simpleSelector:SimpleSelectorValue, selectorSpecificity:SelectorSpecificityData):Void
	{
		switch(simpleSelector)
		{
			case SimpleSelectorValue.SEQUENCE_START(value):
				getSimpleSelectorSequenceStartSpecificity(value, selectorSpecificity);
				
			case SimpleSelectorValue.SEQUENCE_ITEM(value):
				getSimpleSelectorSequenceItemSpecificity(value, selectorSpecificity);
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
				
			case LINK_PSEUDO_CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case USER_ACTION_PSEUDO_CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case CLASS(value):
				selectorSpecificity.classAttributesAndPseudoClassesNumber++;
				
			case ID(value):
				selectorSpecificity.idSelectorsNumber++;
		}
	}
}