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
 * is to parse a style sheet into 
 * an array of CSS rules
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSRulesParser 
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PARSING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Separate each CSS rule in a style sheet
	 * and return them as an array of string
	 * 
	 * @param	css the whole css style sheet to parse
	 * @return	an array where each item is a string representing
	 * a CSS rule
	 */
	public function parseRules(css:String):Array<String>
	{
		var state:StyleSheetRulesParserState = IGNORE_SPACES;
		var next:StyleSheetRulesParserState = BEGIN;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = css.fastCodeAt(position);
		
		var ruleStarted:Bool = false;
		var rules:Array<String> = new Array<String>();
		
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
					
				case BEGIN:
					switch(c)
					{
						case '/'.code:
							state = BEGIN_COMMENT;
							
						default:
							start = position;
							state = BEGIN_RULE;
							continue;
					}	
					
				case BEGIN_RULE:
					start = position;
					state = RULE;
					ruleStarted = true;
					continue;
					
				case RULE:
					switch(c)
					{
						case '}'.code:
						state = END_RULE;
					}
					
				case END_RULE:
					var rule:String = css.substr(start, position - start);
					rules.push(rule);
					state = IGNORE_SPACES;
					next = BEGIN;
					ruleStarted = false;
					continue;
					
				case BEGIN_COMMENT:
					//invalid comment, return all valid rules
					//so far, the rest of the stylesheet is ignored
					if (c != '*'.code)
					{
						return rules;
					}
					else
					{
						state = COMMENT;
					}
					
				case COMMENT:
					if (c == '*'.code)
					{
						state = END_COMMENT;
					}
				
				case END_COMMENT:
					if (c == '/'.code)
					{
						state = IGNORE_SPACES;
						next = BEGIN;
					}
					//was not actual comment end, just isolated '*'
					else
					{
						state = COMMENT;
					}
			}
			
			c = css.fastCodeAt(++position);
		}
		
		if (ruleStarted == true)
		{
			var rule:String = css.substr(start, position - start);
			rules.push(rule);
		}
		
		return rules;
	}
	
	/**
	 * Parse the string representing a CSS Rule into
	 * a CSS Rule object
	 * 
	 * @param	rule the CSS rule string
	 * @param	parentSyleSheet a ref to the style sheet owning the CSS rule
	 * @return	a typed CSS Rule object
	 */
	public function parseRule(rule:String, parentSyleSheet:CSSStyleSheet):CSSRule
	{
		var state:StyleSheetRuleParserState = IGNORE_SPACES;
		var next:StyleSheetRuleParserState = BEGIN_RULE;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = rule.fastCodeAt(position);
		
		var cssRule:CSSRule = null;
		
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
					
				case BEGIN_RULE:
					
					switch(c)
					{
						case '@'.code:
							state = BEGIN_AT_RULE;
							start = position;
							
						default:
							state = RULE;
							next = END_STYLE_RULE;
							start = position;
							continue;
					}
					
				case BEGIN_AT_RULE:
					if (!isValidChar(c))
					{
						var atRule = rule.substr(start, position - start);
						
						switch (atRule)
						{
							case '@media':
								state = RULE;
								next = END_MEDIA_RULE;
								continue;
								
							default:
								state = IGNORE_SPACES;
								next = BEGIN_RULE;
								
						}
					}
				case RULE:
					switch(c)
					{
						case '}'.code:
							state = next;
							continue;
					}
					
					
				case END_MEDIA_RULE:
					var rule = rule.substr(start, position - start + 1);
					
					var cssMediaRule:CSSMediaRule = new CSSMediaRule(parentSyleSheet);
					cssMediaRule.cssText = rule;
					
					return cssMediaRule;
						
				case END_STYLE_RULE:
					var rule = rule.substr(start, position - start + 1);
					
					var cssStyleRule:CSSStyleRule = new CSSStyleRule(parentSyleSheet);
					cssStyleRule.cssText = rule;
					
					return cssStyleRule;
					
			}
			c = rule.fastCodeAt(++position);
		}
		
		return cssRule;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	static inline function isValidChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code) || c == ':'.code || c == '.'.code || c == '_'.code || c == '-'.code;
	}
}