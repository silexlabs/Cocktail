package cocktail.core.css;
import cocktail.core.html.HTMLElement;

import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class SelectorManager 
{

	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SELECTOR MATCHING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function matchSelector(node:HTMLElement, selector:SelectorData):Bool
	{
		var components:Array<SelectorComponentValue> = selector.components;
		
		var previousSelectorItem:SelectorItemValue = null;
		
		for (i in 0...components.length)
		{
			var component:SelectorComponentValue = components[i];
			
			var matched:Bool = false;
			
			switch(component)
			{
				case SelectorComponentValue.COMBINATOR(value):
					matched = matchCombinator(node, value, previousSelectorItem, cast(components[i+1]));
					
				case SelectorComponentValue.SELECTOR_ITEM(value):
					previousSelectorItem = value;
					matched = matchSelectorItem(node, value);
			}
			
			if (matched == false)
			{
				return false;
			}
		}
		
		return true;
	}
	
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
	
		
	private function matchDescendantCombinator(node:HTMLElement, parentSelectorItem:SelectorItemValue, childSelectorItem:SelectorItemValue):Bool
	{
		if (matchSelectorItem(node, childSelectorItem) == false)
		{
			return false;
		}
		
		if (node.parentNode == null)
		{
			return false;
		}
		
		var parent:HTMLElement = node.parentNode;
		
		var matched:Bool = false;
		
		while (parent != null)
		{
			if (matchSelectorItem(parent, parentSelectorItem) == true)
			{
				return true;
			}
			
			parent = parent.parentNode;
		}
		
		return false;
		
	}
	
	private function matchChildCombinator(node:HTMLElement, parentSelectorItem:SelectorItemValue, childSelectorItem:SelectorItemValue):Bool
	{
		if (matchSelectorItem(node, childSelectorItem) == false)
		{
			return false;
		}
		
		if (node.parentNode == null)
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
	
	private function matchSimpleSelectorSequenceItem(node:HTMLElement, simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue):Bool
	{
		switch(simpleSelectorSequenceItem)
		{
			case ATTRIBUTE(value):
				return matchAttributeSelector(node, value);
				
			case CLASS(value):
				//TODO 1 : add class list
				return node.className.indexOf(value) != -1;
				
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
	
	
	private function matchSimpleSelectorSequence(node:HTMLElement, simpleSelectorSequence:SimpleSelectorSequenceData):Bool
	{
		if (matchSimpleSelectorSequenceStart(node, simpleSelectorSequence.startValue) == false)
		{
			return false;
		}
		
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
	
	private function matchAttributeSelector(node:HTMLElement, attributeSelector:AttributeSelectorValue):Bool
	{
		return true;
	}
	
	private function matchPseudoClassSelector(node:HTMLElement, pseudoClassSelector:PseudoClassSelectorValue):Bool
	{
		return true;
	}
	
	private function matchLinkPseudoClassSelector(node:HTMLElement, linkPseudoClassSelector:LinkPseudoClassValue):Bool
	{
		return true;
	}
	
	private function matchUserActionPseudoClassSelector(node:HTMLElement, value:UserActionPseudoClassValue):Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SELECTOR SPECIFICITY METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function getSelectorSpecifity(selector:SelectorData):Int
	{
		var selectorSpecificity:SelectorSpecificityData = {
			idSelectorsNumber:0,
			classAttributesAndPseudoClassesNumber:0,
			typeAndPseudoElementsNumber:0
		}
		
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
		
		var concatenatedSpecificity:String = Std.string(selectorSpecificity.idSelectorsNumber) + Std.string(selectorSpecificity.classAttributesAndPseudoClassesNumber) + Std.string(selectorSpecificity.typeAndPseudoElementsNumber);

		return Std.parseInt(concatenatedSpecificity);
	}
	
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
	
	
	private function getSimpleSelectorSequenceSpecificity(simpleSelectorSequence:SimpleSelectorSequenceData, selectorSpecificity:SelectorSpecificityData):Void
	{
		getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequence.startValue, selectorSpecificity);
		
		for (i in 0...simpleSelectorSequence.simpleSelectors.length)
		{
			var simpleSelectorSequenceItem:SimpleSelectorSequenceItemValue = simpleSelectorSequence.simpleSelectors[i];
			getSimpleSelectorSequenceItemSpecificity(simpleSelectorSequenceItem, selectorSpecificity);
		}
	}
	
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
	
	private function getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequenceStart:SimpleSelectorSequenceStartValue, selectorSpecificity:SelectorSpecificityData):Void
	{
		switch(simpleSelectorSequenceStart)
		{
			case SimpleSelectorSequenceStartValue.TYPE(value):
				selectorSpecificity.typeAndPseudoElementsNumber++;
				
			case SimpleSelectorSequenceStartValue.UNIVERSAL:
				
		}
	}
	
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