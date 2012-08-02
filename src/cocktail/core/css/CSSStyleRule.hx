package cocktail.core.css;

using StringTools;

import cocktail.core.css.CSSData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

extern private class S {
	public static inline var IGNORE_SPACES 	= 0;
	public static inline var BEGIN_SELECTOR	= 1;
	public static inline var SELECTOR = 2;
	public static inline var END_SELECTOR	= 3;
	public static inline var BEGIN_STYLE = 4;
	public static inline var STYLE = 5;
	public static inline var END_STYLE = 6;
}

extern private class S2 {
	public static inline var IGNORE_SPACES 	= 0;
	public static inline var BEGIN_SELECTOR	= 1;
	public static inline var SELECTOR = 2;
	public static inline var END_SELECTOR	= 3;
	public static inline var BEGIN_STYLE = 4;
	public static inline var STYLE = 5;
	public static inline var END_STYLE = 6;
}
 
class CSSStyleRule extends CSSRule
{

	public var selectorText:String;
	
	public var selector:SelectorData;
	
	public var style(default, null):CSSStyleDeclaration;
	
	public function new() 
	{
		super();
		style = new CSSStyleDeclaration(this);
		selector = {
			combinators:[],
			pseudoElement:PseudoElementSelectorValue.NONE
		}
	}
	
	override private function get_type():Int
	{
		return CSSRule.STYLE_RULE;
	}
	
	
	public function parse(css:String):Void
	{
		var state = S.IGNORE_SPACES;
		var next = S.BEGIN_SELECTOR;
		var start = 0;
		var position = 0;
		var c = css.fastCodeAt(position);
		
		while (!c.isEOF())
		{
			switch (state)
			{
				case S.IGNORE_SPACES:
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
					
				case S.BEGIN_SELECTOR:
					state = S.SELECTOR;
					next = S.END_SELECTOR;
					start = position;
					continue;
					
				case S.SELECTOR:	
					if (!isValidChar(c))
					{
						switch(c)
						{
							case '{'.code:
								state = next;
								continue;
						}
					}
					
				case S.END_SELECTOR:	
					var selector = css.substr(start, position - start);
					trace(selector);
					state = S.IGNORE_SPACES;
					next = S.BEGIN_STYLE;
					
				case S.BEGIN_STYLE:
					state = S.STYLE;
					next = S.END_STYLE;
					start = position;
					continue;
					
				case S.STYLE:
					if (!isValidChar(c))
					{
						switch(c)
						{
							case '}'.code:
								state = next;
								continue;
						}
					}
				
				case S.END_STYLE:
					var style = css.substr(start, position - start);
					trace(style);
					state = S.IGNORE_SPACES;
					next = S.IGNORE_SPACES;
					
			}
			c = css.fastCodeAt(++position);
		}
	}
	
	static inline function isValidChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code) || c == ':'.code || c == '.'.code || c == '_'.code || c == '-'.code;
	}
	
	private function parseSelector(selector:String):Void
	{
		var state = S2.IGNORE_SPACES;
		var next = S2.BEGIN_SIMPLE_SELECTOR;
		var start = 0;
		var position = 0;
		var c = selector.fastCodeAt(position);
		
		var simpleSelectorSequenceStartValue:SimpleSelectorSequenceStartValue = null;
		var simpleSelectorSequenceItemValues:Array<SimpleSelectorSequenceItemValue> = [];
		var selectorComponent:SelectorComponentValue = null;
		
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
					switch(c)
					{
						case isAsciiChar(c):
							state = SIMPLE_SELECTOR;
							next = END_TYPE_SELECTOR;
							start = position;
						
						case '.'.code:
							state = SIMPLE_SELECTOR;
							next = END_CLASS_SELECTOR;
							start = position;
							
						case '#'.code:
							state = SIMPLE_SELECTOR;
							next = END_ID_SELECTOR;
							start = position;
							
						case '*'.code:
							state = BEGIN_UNIVERSAL_SELECTOR;
							next = END_UNIVERSAL_SELECTOR;
							start = position;
							
						case ':'.code:
							state = BEGIN_PSEUDO_SELECTOR;
							next = END_PSEUDO_SELECTOR;
							start = position;
							
						case '['.code:
							state = BEGIN_ATTRIBUTE_SELECTOR;
							next = END_ATTRIBUTE_SELECTOR;
							
						default:
							state = INVALID_SELECTOR;
					}
					
				case END_SIMPLE_SELECTOR:
					switch(c)
					{
						case ' '.code, '>'.code:
								state = BEGIN_COMBINATOR;
								continue;
								
						case ':'.code, '#'.code, '.'.code, '['.code:
							state = BEGIN_SIMPLE_SELECTOR;
							
						default:
							state = INVALID_SELECTOR;
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
						}
					}
					
				
				case END_TYPE_SELECTOR:
					var type = selector.substr(start, position - start);
					simpleSelectorSequenceStartValue = SimpleSelectorSequenceStartValue.TYPE(type);
					state = END_SIMPLE_SELECTOR;
					
				case END_CLASS_SELECTOR:
					var className = selector.substr(start, position - start);
					simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.CLASS(className);
					state = END_SIMPLE_SELECTOR;
					
				case END_ID_SELECTOR:
					var id = selector.substr(start, position - start);
					simpleSelectorSequenceItemValues.push(SimpleSelectorSequenceItemValue.ID(id);
					state = END_SIMPLE_SELECTOR;	
					
				case BEGIN_COMBINATOR:
					if (simpleSelectorSequenceStartValue != null)
					{
						if (simpleSelectorSequenceItemValues.length > 0)
						{
							var simpleSelectorSequence = {
								startValue:simpleSelectorSequenceStartValue,
								simpleSelectors:simpleSelectorSequenceItemValues
							}
							
							firstSelectorComponent = SelectorComponentValue.SIMPLE_SELECTOR_SEQUENCE(simpleSelectorSequence);
						}
						else
						{
							firstSelectorComponent = SelectorComponentValue.SIMPLE_SELECTOR(SimpleSelectorValue.SEQUENCE_START(simpleSelectorSequenceStartValue));
						}
					}
					else
					{
						if (simpleSelectorSequenceItemValues.length == 1)
						{
							firstSelectorComponent = SelectorComponentValue.SIMPLE_SELECTOR(SimpleSelectorValue.SEQUENCE_ITEM(simpleSelectorSequenceItemValues[0]));
						}
					}
					
					state = IGNORE_SPACE;
					next = COMBINATOR;
					
				case COMBINATOR:
					switch(c)
					{
						case isAsciiChar(c):
							state = DESCENDANT_COMBINATOR;
							
						case '>'.code:
							state = CHILD_COMBINATOR;
					}
					
			}
			c = css.fastCodeAt(++position);
		}
	}
	
	static inline function isAsciiChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code);
	}
	
	
}