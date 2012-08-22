/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css.parsers;

import cocktail.core.css.CSSData;

/**
 * This class serialize a CSS selector
 * inot a String
 * 
 * @author Yannick DOMINGUEZ
 */
class SelectorSerializer 
{

	/**
	 * Class cosntructor. Private as 
	 * this is a static class
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SERIALIZATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public static function serialize(selector:SelectorData):String
	{
		var serializedSelector:String = "";
		
		for (i in 0...selector.components.length)
		{
			var component:SelectorComponentValue = selector.components[i];
			
			switch(component)
			{
				case SIMPLE_SELECTOR_SEQUENCE(value):
					serializedSelector += serializeSimpleSelectorSequence(value);
					
				case COMBINATOR(value):
					serializedSelector += serializeCombinator(value);
			}
		}
		
		serializedSelector += serializePseudoElement(selector.pseudoElement);
		
		
		return serializedSelector;
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SERIALIZATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private static function serializePseudoElement(pseudoElement:PseudoElementSelectorValue):String
	{
		switch(pseudoElement)
		{
			case NONE:
				return "";
				
			case FIRST_LETTER:
				return "::first-letter";
				
			case FIRST_LINE:
				return "::first-line";
				
			case BEFORE:
				return "::before";
				
			case AFTER:
				return "::after";
		}
	}
	
	private static function serializeSimpleSelectorSequence(simpleSelectorSequence:SimpleSelectorSequenceData):String
	{
		var serializedSimpleSelectorSequence:String = "";
		
		serializedSimpleSelectorSequence += serializeStartValue(simpleSelectorSequence.startValue);
		
		for (i in 0...simpleSelectorSequence.simpleSelectors.length)
		{
			var simpleSelector:SimpleSelectorSequenceItemValue = simpleSelectorSequence.simpleSelectors[i];
			serializedSimpleSelectorSequence += serializeSimpleSelector(simpleSelector);
		}
		
		return serializedSimpleSelectorSequence;
	}
	
	private static function serializeCombinator(combinator:CombinatorValue):String
	{
		switch(combinator)
		{
			case DESCENDANT:
				return " ";
				
			case CHILD:
				return " > ";
				
			case ADJACENT_SIBLING:
				return " + ";
				
			case GENERAL_SIBLING:
				return " ~ ";
		}
	}
	
	private static function serializeStartValue(selectorStartValue:SimpleSelectorSequenceStartValue):String
	{
		switch(selectorStartValue)
		{
			case UNIVERSAL:
				return "*";
				
			case TYPE(value):
				return value;
		}
	}
	
	private static function serializeSimpleSelector(simpleSelector:SimpleSelectorSequenceItemValue):String
	{
		switch (simpleSelector)
		{
			case ID(value):
				return "#" + value;
				
			case CLASS(value):
				return "." + value;
				
			case ATTRIBUTE(value):
				return serializeAttributeSelector(value);
				
			case PSEUDO_CLASS(value):
				return serializePseudoClassSelector(value);
		}
	}
	
	private static function serializeAttributeSelector(attributeSelector:AttributeSelectorValue):String
	{
		switch(attributeSelector)
		{
			case ATTRIBUTE(value):
				return "[" + value + "]";
				
			case ATTRIBUTE_VALUE(name, value):
				return '[' + name + '="' + value + '"]';
				
			case ATTRIBUTE_LIST(name, value):
				return '[' + name + '~="' + value + '"]';	
				
			case ATTRIBUTE_VALUE_BEGINS(name, value):
				return '[' + name + '^="' + value + '"]';	
				
			case ATTRIBUTE_VALUE_ENDS(name, value):
				return '[' + name + '$="' + value + '"]';		
			
			case ATTRIBUTE_VALUE_CONTAINS(name, value):
				return '[' + name + '*="' + value + '"]';	
				
			case ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(name, value):
				return '[' + name + '|="' + value + '"]';		
		}
	}
	
	private static function serializePseudoClassSelector(pseudoClassSelector:PseudoClassSelectorValue):String
	{
		switch(pseudoClassSelector)
		{
			case STRUCTURAL(value):
				return serializeStructuralPseudoClassSelector(value);
				
			case LINK(value):
				return serializeLinkPseudoClassSelector(value);
				
			case TARGET:
				return ":target";
				
			case LANG(value):
				return serializeLangPseudoClassSelector(value);
				
			case USER_ACTION(value):
				return serializeUserActionPseudoClassSelector(value);
				
			case UI_ELEMENT_STATES(value):
				return serializeUIElementStatePseudoClass(value);
				
			case NOT(value):
				return ":not("+serializeSimpleSelectorSequence(value)+")";
		}
	}
	
	private static function serializeUIElementStatePseudoClass(uiElementStateSelector:UIElementStatesValue):String
	{
		switch (uiElementStateSelector)
		{
			case ENABLED:
				return ":enabled";
				
			case DISABLED:
				return ":disabled";
				
			case CHECKED:
				return ":checked";
		}
	}
	
	private static function serializeLangPseudoClassSelector(langs:Array<String>):String
	{
		var serializedLangSelector:String = ":lang(";
		
		for (i in 0...langs.length)
		{
			serializedLangSelector += langs[i];
			if (i < langs.length)
			{
				serializedLangSelector += "-";
			}
		}
		
		serializedLangSelector += ")";
		return serializedLangSelector;
	}
	
	private static function serializeLinkPseudoClassSelector(linkPseudoClassSelector:LinkPseudoClassValue):String
	{
		switch(linkPseudoClassSelector)
		{
			case VISITED:
				return ":visited";
				
			case LINK:
				return ":link";
		}
	}
	
	private static function serializeUserActionPseudoClassSelector(userActionPseudoClassSelector:UserActionPseudoClassValue):String
	{
		switch (userActionPseudoClassSelector)
		{
			case ACTIVE:
				return ":active";
				
			case HOVER:
				return ":hover";
				
			case FOCUS:
				return ":focus";
		}
	}
	
	private static function serializeStructuralPseudoClassSelector(structuralpseudoClassSelector:StructuralPseudoClassSelectorValue):String
	{
		switch(structuralpseudoClassSelector)
		{
			case ROOT:
				return ":root";
				
			case FIRST_CHILD:
				return ":first-child";
				
			case LAST_CHILD:
				return ":last-child";
				
			case FIRST_OF_TYPE:
				return ":first-of-type";
				
			case LAST_OF_TYPE:
				return ":last-of-type";
				
			case ONLY_CHILD:
				return ":only-child";
				
			case ONLY_OF_TYPE:
				return ":only-of-type";
				
			case EMPTY:
				return ":empty";
				
			//TODO 1 : values with arguments
			default:
				return "";
		}
	}
	
}