/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css.parsers;

using StringTools;
import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSParsersData;

/**
 * This class is a parser whose role
 * is to parse a selector string, which may contain
 * one or many selector and parse them into typed
 * selector data
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSSelectorParser 
{

	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PARSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Parse the selector string into typed selector
	 * object and store them in the typed selector
	 * attribute if the selector is valid
	 * 
	 * Return wether the selector is valid
	 */
	public function parseSelector(selector:String, typedSelectors:Array<SelectorVO>):Bool
	{
		var state:SelectorParserState = IGNORE_SPACES;
		var next:SelectorParserState = BEGIN_SIMPLE_SELECTOR;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = selector.fastCodeAt(position);
		
		var simpleSelectorSequenceStartValue:SimpleSelectorSequenceStartValue = null;
		var simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue> = [];
		var components:Array<SelectorComponentValue> = [];
		
		var selectorData:SelectorVO = new SelectorVO(components, PseudoElementSelectorValue.NONE,
		false, null, false, null, false, null, false, false, false);
		
		while (!StringTools.isEof(c))
		{
			switch (state)
			{
				case IGNORE_SPACES:
					switch(c)
					{
						case
							'\n'.code,
							'\r'.code,
							'\t'.code,
							' '.code:
						default:
							state = next;
							continue;
					}
					
				case BEGIN_SIMPLE_SELECTOR:
					if (isSelectorChar(c))
					{
						state = SIMPLE_SELECTOR;
						next = END_TYPE_SELECTOR;
						start = position;
					}
					else
					{
						switch(c)
						{
							
							case '.'.code:
								state = SIMPLE_SELECTOR;
								next = END_CLASS_SELECTOR;
								start = position + 1;
								
							case '#'.code:
								state = SIMPLE_SELECTOR;
								next = END_ID_SELECTOR;
								start = position + 1;
								
							case '*'.code:
								state = SIMPLE_SELECTOR;
								next = END_UNIVERSAL_SELECTOR;
								start = position;
								
							case ':'.code:
								state = BEGIN_PSEUDO_SELECTOR;
								start = position;
								
							case '['.code:
								state = BEGIN_ATTRIBUTE_SELECTOR;
								start = position;
								
							default:
								state = INVALID_SELECTOR;
								continue;
						}
					}
					
					
				case BEGIN_ATTRIBUTE_SELECTOR:
					position = parseAttributeSelector(selector, position, simpleSelectorSequenceItemValues);
					state = END_SIMPLE_SELECTOR;
					next = IGNORE_SPACES;
					
				case BEGIN_PSEUDO_SELECTOR:
					if (isSelectorChar(c))
					{
						position = parsePseudoClass(selector, position, simpleSelectorSequenceItemValues);
						state = END_SIMPLE_SELECTOR;
						next = IGNORE_SPACES;
					}
					else
					{
						switch(c)
						{
							case ':'.code:
								state = PSEUDO_ELEMENT_SELECTOR;
								
							default:
								state = INVALID_SELECTOR;
								continue;
						}
					}
					
				case PSEUDO_ELEMENT_SELECTOR:	
					position = parsePseudoElement(selector, position, selectorData);
					state = IGNORE_SPACES;
					next = INVALID_SELECTOR;
					
				case END_SIMPLE_SELECTOR:
					switch(c)
					{
						case ' '.code, '\n'.code, '\r'.code, '>'.code:
							state = BEGIN_COMBINATOR;
							continue;
								
						case ':'.code, '#'.code, '.'.code, '['.code:
							state = BEGIN_SIMPLE_SELECTOR;
							continue;
							
						default:
							state = INVALID_SELECTOR;
							continue;
					}
					
				case SIMPLE_SELECTOR:	
					if (!isSelectorChar(c))
					{
						switch(c)
						{
							case ' '.code, '\n'.code, '\r'.code, '>'.code, ':'.code, '#'.code, '.'.code, '['.code:
								state = next;
								continue;
								
							default:
								state = INVALID_SELECTOR;
								continue;
						}
					}
					
				case END_TYPE_SELECTOR:
					var type:String = selector.substr(start, position - start);
					simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.TYPE(type.toUpperCase());
					state = END_SIMPLE_SELECTOR;
					continue;
					
				case END_CLASS_SELECTOR:
					var className:String = selector.substr(start, position - start);
					simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.CSS_CLASS(className));
					state = END_SIMPLE_SELECTOR;
					continue;
					
				case END_ID_SELECTOR:
					var id:String = selector.substr(start, position - start);
					simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ID(id));
					state = END_SIMPLE_SELECTOR;	
					continue;
					
				case END_UNIVERSAL_SELECTOR:
					simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.UNIVERSAL;
					state = END_SIMPLE_SELECTOR;
					continue;
					
				case BEGIN_COMBINATOR:
					
					flushSelectors(simpleSelectorSequenceStartValue, simpleSelectorSequenceItemValues, components);
					
					simpleSelectorSequenceStartValue = null;
					simpleSelectorSequenceItemValues = [];
					
					state = IGNORE_SPACES;
					next = COMBINATOR;
					continue;
					
				case COMBINATOR:
					
					if (isSelectorChar(c))
					{
						state = BEGIN_SIMPLE_SELECTOR;
						components.push(SelectorComponentValue.COMBINATOR(CombinatorValue.DESCENDANT));
						continue;
					}
					else
					{
						switch(c)
						{
							case '>'.code:
								state = IGNORE_SPACES;
								next = BEGIN_SIMPLE_SELECTOR;
								components.push(SelectorComponentValue.COMBINATOR(CombinatorValue.CHILD));
								
							case '+'.code:
								state = IGNORE_SPACES;
								next = BEGIN_SIMPLE_SELECTOR;
								components.push(SelectorComponentValue.COMBINATOR(CombinatorValue.ADJACENT_SIBLING));
								
							case '~'.code:
								state = IGNORE_SPACES;
								next = BEGIN_SIMPLE_SELECTOR;
								components.push(SelectorComponentValue.COMBINATOR(CombinatorValue.GENERAL_SIBLING));
								
							case ':'.code, '#'.code, '.'.code, '['.code, '*'.code:
							state = BEGIN_SIMPLE_SELECTOR;
							components.push(SelectorComponentValue.COMBINATOR(CombinatorValue.DESCENDANT));
							continue;
						}
					}
					
				case INVALID_SELECTOR:
					return false;
			}
			c = selector.fastCodeAt(++position);
		}
		
		//TODO 2 : dusplaicate code, when reading ident, should
		//read until end of file
		switch(next)
		{
			case END_TYPE_SELECTOR:
				var type = selector.substr(start, position - start);
				//type stored internally as uppercase to match html tag name
				simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.TYPE(type.toUpperCase());
				
			case END_UNIVERSAL_SELECTOR:	
				simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.UNIVERSAL;
				
			case END_CLASS_SELECTOR:
				var className:String = selector.substr(start, position - start);
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.CSS_CLASS(className));
				state = END_SIMPLE_SELECTOR;
				
			case END_ID_SELECTOR:
				var id = selector.substr(start, position - start);
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ID(id));
				
			default:	
		}
		
		flushSelectors(simpleSelectorSequenceStartValue, simpleSelectorSequenceItemValues, components);
		
		//if at this point, there are no components in
		//this selector, it is invalid
		if (selectorData.components.length == 0)
		{
			return false;
		}
		
		//simple selectors and combinators are parsed from left to 
		//right but are matched from right to left to match
		//combinators logic, so the array is reversed
		selectorData.components.reverse();
		
		//if the selector begins with a class return it, else return null
		var firstClass:String = getFirstClass(selectorData.components);
		
		//check wether the selector only contains a single class
		var isSimpleClassSelector:Bool = false;
		if (firstClass != null)
		{
			isSimpleClassSelector = getIsSimpleClassSelector(selectorData.components);
		}
		
		//same as above for Id
		var firstId:String = getFirstId(selectorData.components);
		
		var isSimpleIdSelector:Bool = false;
		if (firstId != null)
		{
			isSimpleIdSelector = getIsSimpleIdSelector(selectorData.components);
		}
		
		//same as above for type
		var firstType:String = getFirstType(selectorData.components);
		
		var isSimpleTypeSelector:Bool = false;
		if (firstType != null)
		{
			isSimpleTypeSelector = getIsSimpleTypeSelector(selectorData.components);
		}
		
		var typedSelector:SelectorVO = new SelectorVO(selectorData.components, selectorData.pseudoElement,
		firstClass != null, firstClass,
		firstId != null, firstId,
		firstType != null, firstType
		, isSimpleClassSelector, isSimpleIdSelector, isSimpleTypeSelector);
		
		typedSelectors.push(typedSelector);
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PARSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function flushSelectors(simpleSelectorSequenceStartValue:SimpleSelectorSequenceStartValue, simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue>, components:Array<SelectorComponentValue>):Void
	{
		if (simpleSelectorSequenceStartValue == null && simpleSelectorSequenceItemValues.length == 0)
		{
			return;
		}
		
		if (simpleSelectorSequenceStartValue == null)
		{
			simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.UNIVERSAL;
		}

		var simpleSelectorSequence:SimpleSelectorSequenceVO = new SimpleSelectorSequenceVO(simpleSelectorSequenceStartValue, simpleSelectorSequenceItemValues);
		components.push(SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(simpleSelectorSequence));
		
	}
	
	//TODO : parse pseudo class with arguments
	private function parsePseudoClass(selector:String, position:Int, simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue>):Int
	{
		var c:Int = selector.fastCodeAt(position);
		var start:Int = position;
		
		while (true)
		{
			if (!isPseudoClassChar(c))
			{
				break;
			}
			c = selector.fastCodeAt(++position);
		}
		
		var pseudoClass:String = selector.substr(start, position - start);
		
		var typedPseudoClass:PseudoClassSelectorValue = PseudoClassSelectorValue.UNKNOWN;
		
		switch(pseudoClass)
		{
			case 'first-child':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.FIRST_CHILD);
				
			case 'last-child':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.LAST_CHILD);
		
			case 'empty':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.EMPTY);
				
			case 'root':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.ROOT);
				
			case 'first-of-type':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.FIRST_OF_TYPE);	
				
			case 'last-of-type':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.LAST_OF_TYPE);	
				
			case 'only-of-type':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.ONLY_OF_TYPE);	
				
			case 'only-child':
				typedPseudoClass = PseudoClassSelectorValue.STRUCTURAL(StructuralPseudoClassSelectorValue.ONLY_CHILD);
				
			case 'link':
				typedPseudoClass = PseudoClassSelectorValue.LINK(LinkPseudoClassValue.LINK);	
				
			case 'visited':
				typedPseudoClass = PseudoClassSelectorValue.LINK(LinkPseudoClassValue.VISITED);
				
			case 'active':
				typedPseudoClass = PseudoClassSelectorValue.USER_ACTION(UserActionPseudoClassValue.ACTIVE);
				
			case 'hover':
				typedPseudoClass = PseudoClassSelectorValue.USER_ACTION(UserActionPseudoClassValue.HOVER);
				
			case 'focus':
				typedPseudoClass = PseudoClassSelectorValue.USER_ACTION(UserActionPseudoClassValue.FOCUS);
				
			case 'target':
				typedPseudoClass = PseudoClassSelectorValue.TARGET;

			case 'fullscreen':
				typedPseudoClass = PseudoClassSelectorValue.FULLSCREEN;
				
			case 'nth-child':
				//TODO
				
			case 'nth-last-child':
				//TODO
				
			case 'nth-of-type':
				//TODO
				
			case 'nth-last-of-type':
				//TODO
				
			case 'not':
				//TODO
				
			case 'lang':
				//TODO
				
			case 'enabled':
				typedPseudoClass = PseudoClassSelectorValue.UI_ELEMENT_STATES(UIElementStatesValue.ENABLED);
				
			case 'disabled':
				typedPseudoClass = PseudoClassSelectorValue.UI_ELEMENT_STATES(UIElementStatesValue.DISABLED);
				
			case 'checked':
				typedPseudoClass = PseudoClassSelectorValue.UI_ELEMENT_STATES(UIElementStatesValue.CHECKED);
				
		}
		
		simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.PSEUDO_CLASS(typedPseudoClass));
		
		return --position;
	}
	
	private function parsePseudoElement(selector:String, position:Int, selectorData:SelectorVO):Int
	{
		var c:Int = selector.fastCodeAt(position);
		var start:Int = position;
		
		while (true)
		{
			if (!isPseudoClassChar(c))
			{
				break;
			}
			c = selector.fastCodeAt(++position);
		}
		
		var pseudoElement:String = selector.substr(start, position - start);
		var typedPseudoElement:PseudoElementSelectorValue = null;
		
		switch (pseudoElement)
		{
			case 'first-line':
				typedPseudoElement = PseudoElementSelectorValue.FIRST_LINE;
				
			case 'first-letter':
				typedPseudoElement = PseudoElementSelectorValue.FIRST_LETTER;
				
			case 'before':
				typedPseudoElement = PseudoElementSelectorValue.BEFORE;
				
			case 'after':
				typedPseudoElement = PseudoElementSelectorValue.AFTER;

			default:
				typedPseudoElement = PseudoElementSelectorValue.NONE;
				
		}
		
		selectorData.pseudoElement = typedPseudoElement;
		
		return --position;
	}
	
	private function parseAttributeSelector(selector:String, position:Int, simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue>):Int
	{
		var c:Int = selector.fastCodeAt(position);
		var start:Int = position;
		
		var attribute:String = null;
		var operator:String = null;
		var value:String = null;
		
		var state:AttributeSelectorParserState = IGNORE_SPACES;
		var next:AttributeSelectorParserState = ATTRIBUTE;
		
		while (true)
		{
			switch(state)
			{
				case IGNORE_SPACES:
					switch(c)
					{
						case
							'\n'.code,
							'\r'.code,
							'\t'.code,
							' '.code:
						default:
							state = next;
							continue;
					}
				
				case ATTRIBUTE:
					if (!isSelectorChar(c))
					{
						attribute = selector.substr(start, position - start);
						
						if (c == ']'.code)
						{
							state = END_SELECTOR;
							continue;
						}
						else
						{
							state = IGNORE_SPACES;
							next = BEGIN_OPERATOR;
							continue;
						}
					}
				
				case BEGIN_OPERATOR:
					start = position;
					state = OPERATOR;
					
				case OPERATOR:
					if (!isOperatorChar(c))
					{
						operator = selector.substr(start, position - start);
						state = IGNORE_SPACES;
						next = END_OPERATOR;
						continue;
					}
					
				case END_OPERATOR:
					switch(c)
						{
							case '"'.code, "'".code:
								position++;
								start = position;
								state = STRING_VALUE;
								
							case ']'.code:
								state = END_SELECTOR;
								continue;
								
							default:
								
								if (isSelectorChar(c) == true)
								{
									start = position;
									state = IDENTIFIER_VALUE;
								}
								else
								{
									state = INVALID_SELECTOR;
								}
						}
					
				case STRING_VALUE:
					if (!isSelectorChar(c))
					{
						switch (c)
						{
							case '"'.code, "'".code:
								value = selector.substr(start, position - start);
								state = END_SELECTOR;
								
							case ']'.code:
								state = INVALID_SELECTOR;
								
							default:
								state = INVALID_SELECTOR;
						}
					}
					
				case IDENTIFIER_VALUE:
					if (!isSelectorChar(c))
					{
						switch (c)
						{
							case ']'.code:
								value = selector.substr(start, position - start);
								state = END_SELECTOR;
								continue;
								
							default:
								state = INVALID_SELECTOR;
						}
					}
					
				case INVALID_SELECTOR:
					break;
					
				case END_SELECTOR:	
					break;
				
			}
			c = selector.fastCodeAt(++position);
		}
		
		if (attribute != null)
		{
			if (operator != null)
			{
				switch(operator)
				{
					case '=':
						simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE_VALUE(attribute, value)));
						
					case '^=':
						simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE_VALUE_BEGINS(attribute, value)));
				
					case '~=':
						simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE_LIST(attribute, value)));
						
					case '$=':
						simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE_VALUE_ENDS(attribute, value)));
						
					case '*=':
						simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE_VALUE_CONTAINS(attribute, value)));
					
					case '|=':
						simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(attribute, value)));
				}
			}
			else
			{
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ATTRIBUTE(AttributeSelectorValue.ATTRIBUTE(attribute)));
			}
		}
		
		return position;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * if the selector begins with a class selector, return it,
	 * else return null
	 */
	private function getFirstClass(components:Array<SelectorComponentValue>):String
	{
		switch(components[0])
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				//check that don't start with type selector
				if (value.startValue == UNIVERSAL)
				{
					//check that has at least 1 simple selector
					if (value.simpleSelectors.length != 0)
					{
						//check that the first simple selector is a class selector
						switch(value.simpleSelectors[0])
						{
							case CSS_CLASS(value):
								return value;
								
							default:	
						}
					}
				}
				
			//won't happen, selector always begins with selector sequence	
			case COMBINATOR(value):
		}
		return null;
	}
	
	/**
	 * Returns wether this selector contains only one clss selector
	 */
	private function getIsSimpleClassSelector(components:Array<SelectorComponentValue>):Bool
	{
		// > 1 means that it has combinators
		if (components.length > 1)
		{
			return false;
		}
		
		switch(components[0])
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				//must start with universal selector
				if (value.startValue == UNIVERSAL)
				{
					//check that has only 1 simple selector
					if (value.simpleSelectors.length == 1)
					{
						//check that that this simple selector is a class selector
						switch(value.simpleSelectors[0])
						{
							case CSS_CLASS(value):
								return true;
								
							default:	
						}
					}
				}
				
			case COMBINATOR(value):
		}
		return false;
	}
	
	/**
	 * Same as above for id selector
	 */
	private function getIsSimpleIdSelector(components:Array<SelectorComponentValue>):Bool
	{
		if (components.length > 1)
		{
			return false;
		}
		
		switch(components[0])
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				
				if (value.startValue == UNIVERSAL)
				{
					if (value.simpleSelectors.length == 1)
					{
						switch(value.simpleSelectors[0])
						{
							case ID(value):
								return true;
								
							default:	
						}
					}
				}
				
			case COMBINATOR(value):
		}
		return false;
	}
	
	/**
	 * Same as above for type selector
	 */
	private function getIsSimpleTypeSelector(components:Array<SelectorComponentValue>):Bool
	{
		if (components.length > 1)
		{
			return false;
		}
		
		switch(components[0])
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				switch(value.startValue)
				{
					case TYPE(typeValue):
						if (value.simpleSelectors.length == 0)
						{
							return true;
						}
						
					default:	
						
				}
				
			case COMBINATOR(value):
		}
		return false;
	}
	
	/**
	 * if the selector begins with an Id selector, return it,
	 * else return null
	 */
	private function getFirstId(components:Array<SelectorComponentValue>):String
	{
		switch(components[0])
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				//check that don't start with type selector
				if (value.startValue == UNIVERSAL)
				{
					//check that has at least 1 simple selector
					if (value.simpleSelectors.length != 0)
					{
						//check that the first simple selector is an Id selector
						switch(value.simpleSelectors[0])
						{
							case ID(value):
								return value;
								
							default:	
						}
					}
				}
				
			//won't happen, selector always begins with selector sequence	
			case COMBINATOR(value):
		}
		return null;
	}
	
	/**
	 * if the selector begins with a type selector, return it,
	 * else return null
	 */
	private function getFirstType(components:Array<SelectorComponentValue>):String
	{
		switch(components[0])
		{
			case SIMPLE_SELECTOR_SEQUENCE(value):
				switch(value.startValue)
				{
					case TYPE(value):
						return value;
						
					default:	
				}
				
			//won't happen, selector always begins with selector sequence	
			case COMBINATOR(value):
		}
		return null;
	}
	
	
	
	static inline function isOperatorChar(c:Int):Bool
	{
		return c == '='.code || c == '~'.code || c == '^'.code || c == '$'.code || c == '*'.code || c == '|'.code;
	}
	
	static inline function isAsciiChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code);
	}
	
	static inline function isSelectorChar(c) {
		return isAsciiChar(c) || c == '-'.code || c == '_'.code;
	}
	
	static inline function isPseudoClassChar(c) {
		return isAsciiChar(c) || c == '-'.code;
	}
	
}
