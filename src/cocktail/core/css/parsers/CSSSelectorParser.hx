package cocktail.core.css.parsers;

using StringTools;
import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSParsersData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSSelectorParser 
{

	public function new() 
	{
		
	}

	/**
	 * Parse the selector string into typed selector
	 * object and store them in the typed selector
	 * attribute if the selector is valid
	 */
	public function parseSelector(selector:String, targetSelector:SelectorData):Void
	{
		var state:SelectorParserState = IGNORE_SPACES;
		var next:SelectorParserState = BEGIN_SIMPLE_SELECTOR;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = selector.fastCodeAt(position);
		
		var simpleSelectorSequenceStartValue:SimpleSelectorSequenceStartValue = null;
		var simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue> = [];
		var components:Array<SelectorComponentValue> = [];
		
		var selectorData:SelectorData = {
			components:components,
			pseudoElement:PseudoElementSelectorValue.NONE
		}
		
		while (!c.isEOF())
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
					if (isAsciiChar(c))
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
								start = position;
								
							case '#'.code:
								state = SIMPLE_SELECTOR;
								next = END_ID_SELECTOR;
								start = position;
								
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
					if (isAsciiChar(c))
					{
						position = parsePseudoClass(selector, position, simpleSelectorSequenceItemValues);
						state = END_SIMPLE_SELECTOR;
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
						case ' '.code, '>'.code:
							state = BEGIN_COMBINATOR;
							continue;
								
						case ':'.code, '#'.code, '.'.code, '['.code:
							state = BEGIN_SIMPLE_SELECTOR;
							continue;
							
						default:
							trace(String.fromCharCode(c));
							state = INVALID_SELECTOR;
							continue;
					}
					
				case SIMPLE_SELECTOR:	
					if (!isAsciiChar(c))
					{
						switch(c)
						{
							case ' '.code, '>'.code, ':'.code, '#'.code, '.'.code, '['.code:
								state = next;
								continue;
								
							default:	
								state = INVALID_SELECTOR;
								continue;
						}
					}
					
				case END_TYPE_SELECTOR:
					var type:String = selector.substr(start, position - start);
					trace(type);
					simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.TYPE(type);
					state = END_SIMPLE_SELECTOR;
					continue;
					
				case END_CLASS_SELECTOR:
					var className:String = selector.substr(start, position - start);
					simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.CLASS(className));
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
					
					if (isAsciiChar(c))
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
					trace("invalid");
					return;
			}
			c = selector.fastCodeAt(++position);
		}
		
		switch(next)
		{
			case END_TYPE_SELECTOR:
				var type = selector.substr(start, position - start);
				simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.TYPE(type);
				
			case END_UNIVERSAL_SELECTOR:	
				simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.UNIVERSAL;
				
			case END_CLASS_SELECTOR:
				var className = selector.substr(start, position - start);
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.CLASS(className));
				state = END_SIMPLE_SELECTOR;
				
			case END_ID_SELECTOR:
				var id = selector.substr(start, position - start);
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ID(id));
				
			default:	
		}
		
		flushSelectors(simpleSelectorSequenceStartValue, simpleSelectorSequenceItemValues, components);
		
		targetSelector.components = selectorData.components;
		targetSelector.pseudoElement = selectorData.pseudoElement;
	}
	
	private function flushSelectors(simpleSelectorSequenceStartValue:SimpleSelectorSequenceStartValue, simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue>, components:Array<SelectorComponentValue>):Void
	{
		if (simpleSelectorSequenceStartValue == null)
		{
			simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.UNIVERSAL;
		}

		var simpleSelectorSequence:SimpleSelectorSequenceData = {
			startValue:simpleSelectorSequenceStartValue,
			simpleSelectors:simpleSelectorSequenceItemValues
		}
		
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
		
		var typedPseudoClass:PseudoClassSelectorValue = null;
		
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
	
	private function parsePseudoElement(selector:String, position:Int, selectorData:SelectorData):Int
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
		
		var state:AttributeSelectorParserState = ATTRIBUTE;
		
		while (true)
		{
			switch(state)
			{
				case ATTRIBUTE:
					if (!isAsciiChar(c))
					{
						attribute = selector.substr(start, position - start);
						state = OPERATOR;
						start = position;
						continue;
					}
				
				case OPERATOR:
					if (!isOperatorChar(c))
					{
						switch (c)
						{
							case '"'.code:
								operator = selector.substr(start, position - start);
								start = position;
								state = BEGIN_VALUE;
								
							case ']'.code:
								state = END_SELECTOR;
								
							default:
								state = INVALID_SELECTOR;
						}
					}
					
					
				case BEGIN_VALUE:
					start = position;
					state = VALUE;
					
				case VALUE:
					if (!isAsciiChar(c))
					{
						switch (c)
						{
							case '"'.code:
								value = selector.substr(start, position - start);
								state = END_SELECTOR;
								
							case ']'.code:
								state = INVALID_SELECTOR;
								
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
	
	static inline function isOperatorChar(c:Int):Bool
	{
		return c == '='.code || c == '~'.code || c == '^'.code || c == '$'.code || c == '*'.code || c == '|'.code;
	}
	
	static inline function isAsciiChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code);
	}
	
	static inline function isPseudoClassChar(c) {
		return isAsciiChar(c) || c == '-'.code;
	}
	
}