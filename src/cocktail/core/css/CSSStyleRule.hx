package cocktail.core.css;

using StringTools;

import cocktail.core.css.CSSData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */
 
class CSSStyleRule extends CSSRule
{

	public var selectorText:String;
	
	public var selector:SelectorData;
	
	public var style(default, null):CSSStyleDeclaration;
	
	public function new(parentStyleSheet:CSSStyleSheet = null, parentRule:CSSRule = null) 
	{
		super(parentStyleSheet, parentRule);
		style = new CSSStyleDeclaration(this);
		selector = {
			components:[],
			pseudoElement:PseudoElementSelectorValue.NONE
		}
	}
	
	override private function get_type():Int
	{
		return CSSRule.STYLE_RULE;
	}
	
	public function parse(css:String):Void
	{
		var state:StyleRuleParserState = IGNORE_SPACES;
		var next:StyleRuleParserState = BEGIN_SELECTOR;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = css.fastCodeAt(position);
		
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
					
				case BEGIN_SELECTOR:
					state = SELECTOR;
					next = END_SELECTOR;
					start = position;
					continue;
					
				case SELECTOR:	
					if (!isSelectorChar(c))
					{
						switch(c)
						{
							case '{'.code:
								state = END_SELECTOR;
								next = BEGIN_STYLES;
								continue;
								
							case ','.code:
								state = END_SELECTOR;
								next = BEGIN_SELECTOR;
								continue;
						}
					}
					
				case END_SELECTOR:	
					var selector = css.substr(start, position - start);
					trace(selector);
					state = next;
					
				case BEGIN_STYLES:
					state = STYLES;
					next = END_STYLES;
					start = position;
					continue;
					
				case STYLES:
					if (!isStyleChar(c))
					{
						switch(c)
						{
							case '}'.code:
								state = next;
								continue;
						}
					}
				
				case END_STYLES:
					var style = css.substr(start, position - start);
					trace(style);
					state = IGNORE_SPACES;
					next = IGNORE_SPACES;
			}
			c = css.fastCodeAt(++position);
		}
	}
	
	static inline function isSelectorChar(c:Int):Bool {
		return isAsciiChar(c) || c == ':'.code || c == '.'.code || c == '*'.code;
	}
	
	static inline function isStyleChar(c:Int):Bool {
		return isAsciiChar(c) || c == ":".code || c == "(".code || c == ")".code;
	}
	
	public function parseSelector(selector:String):Void
	{
		var state:SelectorParserState = IGNORE_SPACES;
		var next:SelectorParserState = BEGIN_SIMPLE_SELECTOR;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = selector.fastCodeAt(position);
		
		var simpleSelectorSequenceStartValue:SimpleSelectorSequenceStartValue = null;
		var simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue> = [];
		var components:Array<SelectorComponentValue> = [];
		
		var pseudoClass:String = null;
		
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
								
							default:
								state = INVALID_SELECTOR;
								continue;
						}
					}
					
					
				case BEGIN_PSEUDO_SELECTOR:
					if (isAsciiChar(c))
					{
						position = parsePseudoClass(selector, position, simpleSelectorSequenceItemValues);
						trace(position);
						state = END_SIMPLE_SELECTOR;
					}
					else
					{
						//switch(c)
						//{
							//case ':'.code:
								//state = PSEUDO_ELEMENT_SELECTOR;
								//start = position;
								//
							//default:
								//state = INVALID_SELECTOR;
						//}
					}
					
				case PSEUDO_ELEMENT_SELECTOR:	
					
				case END_SIMPLE_SELECTOR:
					trace(String.fromCharCode(c));
					switch(c)
					{
						case ' '.code, '>'.code:
							state = BEGIN_COMBINATOR;
							trace("biiii");
							continue;
								
						case ':'.code, '#'.code, '.'.code, '['.code:
							state = BEGIN_SIMPLE_SELECTOR;
							continue;
							
						default:
							trace("INVALID_SELECTOR");
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
					var type = selector.substr(start, position - start);
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
								
							case ':'.code, '#'.code, '.'.code, '['.code, '*'.code:
							state = BEGIN_SIMPLE_SELECTOR;
							components.push(SelectorComponentValue.COMBINATOR(CombinatorValue.DESCENDANT));
							continue;
						}
					}
					
				case INVALID_SELECTOR:
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
		
		trace(components);
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
	
	static inline function isAsciiChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code);
	}
	
	static inline function isPseudoClassChar(c) {
		return isAsciiChar(c) || c == '-'.code;
	}
	
	static inline function isPseudoClassArgChar(c) {
		return isAsciiChar(c) || c == '-'.code;
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
				trace(String.fromCharCode(c));
				break;
			}
			c = selector.fastCodeAt(++position);
		}
		
		var pseudoClass:String = selector.substr(start, position - start);
		
		switch(pseudoClass)
		{
			case 'first-child':
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.PSEUDO_CLASS(PseudoClassSelectorValue.FIRST_CHILD));
				
			case 'last-child':
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.PSEUDO_CLASS(PseudoClassSelectorValue.LAST_CHILD));
		
			case 'empty':
				simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.PSEUDO_CLASS(PseudoClassSelectorValue.EMPTY));
		}
		
		return --position;
		
	}
	
	
	
}