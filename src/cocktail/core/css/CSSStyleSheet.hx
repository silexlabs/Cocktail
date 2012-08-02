package cocktail.core.css;

using StringTools;

import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

 extern private class S {
	public static inline var IGNORE_SPACES 	= 0;
	public static inline var BEGIN_RULE	= 1;
	public static inline var END_RULE	= 2;
	public static inline var BEGIN_AT_RULE	= 3;
	public static inline var RULE = 5;
	public static inline var END_MEDIA_RULE = 6;
	public static inline var END_STYLE_RULE = 7;
}
 
class CSSStyleSheet extends StyleSheet
{

	public var ownerRule(default, null):CSSRule;
	
	public var cssRules(default, null):CSSRuleList;
	
	public function new() 
	{
		super();
		cssRules = new CSSRuleList();
	}
	
	public function insertRule(rule:String, index:Int):Int
	{
		return -1;
	}
	
	public function deleteRule(index:Int):Void
	{
		
	}
	
	public function parse(css:String):Void
	{
		var state = S.IGNORE_SPACES;
		var next = S.BEGIN_RULE;
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
					
				case S.BEGIN_RULE:
					switch(c)
					{
						case '@'.code:
							state = S.BEGIN_AT_RULE;
							next = S.END_RULE;
							start = position;
							
						default:
							state = S.RULE;
							next = S.END_STYLE_RULE;
							start = position;
					}
					
				case S.BEGIN_AT_RULE:
					if (!isValidChar(c))
					{
						var atRule = css.substr(start, position - start);
						
						switch (atRule)
						{
							case '@media':
								state = S.RULE;
								next = S.END_MEDIA_RULE;
								continue;
								
							default:
								state = S.IGNORE_SPACES;
								next = S.BEGIN_RULE;
						}
					}
				case S.RULE:
					switch(c)
					{
						case '}'.code:
							state = next;
					}
					
					
					
				case S.END_MEDIA_RULE:
					var rule = css.substr(start, position - start);
					trace(rule);
					state = S.IGNORE_SPACES;
					next = S.BEGIN_RULE;
						
				case S.END_STYLE_RULE:
					var rule = css.substr(start, position - start);
					trace(rule);
					state = S.IGNORE_SPACES;
					next = S.BEGIN_RULE;
					
			}
			c = css.fastCodeAt(++position);
		}
	}
	
	static inline function isValidChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code) || c == ':'.code || c == '.'.code || c == '_'.code || c == '-'.code;
	}
	
}