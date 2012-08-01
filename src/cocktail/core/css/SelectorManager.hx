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
		for (i in 0...selector.combinators.length)
		{
			var combinator:CombinatorValue = selector.combinators[i];
			
			switch(combinator)
			{
				case CombinatorValue.NONE(value):
					matchSelectorComponent(node, value);
					
				case CombinatorValue.CHILD(parent, child):
					matchChildCombinator(node, parent, child);
					
				case CombinatorValue.DESCENDANT(parent, child):
					matchDescendantCombinator(node, parent, child);
					
				case CombinatorValue.GENERAL_SIBLING(sibling, child):
					//TODO
				case CombinatorValue.ADJACENT_SIBLING(sibling, CHILD):	
					//TODO
			}
		}
		
		return true;
	}
	
	private function matchDescendantCombinator(node:HTMLElement, parentSelectorComponent:SelectorComponentValue, childSelectorComponent:SelectorComponentValue):Bool
	{
		if (matchSelectorComponent(node, childSelectorComponent) == false)
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
			if (matchSelectorComponent(parent, parentSelectorComponent) == true)
			{
				return true;
			}
			
			parent = parent.parentNode;
		}
		
		return false;
		
	}
	
	private function matchChildCombinator(node:HTMLElement, parentSelectorComponent:SelectorComponentValue, childSelectorComponent:SelectorComponentValue):Bool
	{
		if (matchSelectorComponent(node, childSelectorComponent) == false)
		{
			return false;
		}
		
		if (node.parentNode == null)
		{
			return false;
		}
		
		return matchSelectorComponent(node.parentNode, parentSelectorComponent);
	}
	
	private function matchSelectorComponent(node:HTMLElement, selectorComponent:SelectorComponentValue):Bool
	{
		switch (selectorComponent)
		{
			case SelectorComponentValue.SIMPLE_SELECTOR(value):
				return matchSimpleSelector(node, value);
				
			case SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(value):
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
				return node.tagName == value;
				
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
		
		
		for (i in 0...selector.combinators.length)
		{
			var combinator:CombinatorValue = selector.combinators[i];
			
			switch(combinator)
			{
				case CombinatorValue.NONE(value):
					getSelectorComponentSpecificity(value, selectorSpecificity);
					
				case CombinatorValue.CHILD(parent, child):
					getSelectorComponentSpecificity(child, selectorSpecificity);
					
				case CombinatorValue.DESCENDANT(parent, child):
					getSelectorComponentSpecificity(child, selectorSpecificity);	
					
				case CombinatorValue.ADJACENT_SIBLING(sibling, child):
					getSelectorComponentSpecificity(child, selectorSpecificity);	
					
				case CombinatorValue.GENERAL_SIBLING(sibling, child):
					getSelectorComponentSpecificity(child, selectorSpecificity);		
			}
		}
		
		var concatenatedSpecificity:String = Std.string(selectorSpecificity.idSelectorsNumber) + Std.string(selectorSpecificity.classAttributesAndPseudoClassesNumber) + Std.string(selectorSpecificity.typeAndPseudoElementsNumber);

		return Std.parseInt(concatenatedSpecificity);
	}
	
	private function getSelectorComponentSpecificity(selectorComponent:SelectorComponentValue, selectorSpecificity:SelectorSpecificityData):Void
	{
		switch (selectorComponent)
		{
			case SelectorComponentValue.SIMPLE_SELECTOR(value):
				getSimpleSelectorSpecificity(value, selectorSpecificity); 
				
			case SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(value):
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