/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSParsersData;
import cocktail.core.css.parsers.CSSSelectorParser;
import cocktail.core.css.parsers.SelectorSerializer;
using StringTools;

/**
 * The CSSStyleRule object represents a rule set.
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSStyleRule extends CSSRule
{
	/**
	 * get/set the selector text. When
	 * set, parse it. When get serialze the
	 * typed selector as a string
	 */
	public var selectorText(get_selectorText, set_selectorText):String;
	
	/**
	 * The selectors of this style rule, as
	 * typed objects
	 */
	public var selectors:Array<SelectorVO>;
	
	/**
	 * Stores all the style definition (the style name / 
	 * style value pairs) of this style rule
	 */
	public var style(default, null):CSSStyleDeclaration;
	
	/**
	 * an instance of the class used to parse the selector
	 * of this style rule
	 */
	private var _selectorParser:CSSSelectorParser;
	
	/**
	 * Class constructor
	 */
	public function new(parentStyleSheet:CSSStyleSheet = null, parentRule:CSSRule = null) 
	{
		super(parentStyleSheet, parentRule);
		style = new CSSStyleDeclaration(this);
		_selectorParser = new CSSSelectorParser();
		
		selectors = new Array<SelectorVO>();
		
		type = CSSRule.STYLE_RULE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PARSER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the cssText is set. Split the
	 * css rule style into a selector and
	 * a style declaration which would in turn
	 * be parsed into object in their
	 * own methods
	 */
	private function parse(css:String):Void
	{
		selectors = new Array<SelectorVO>();
		
		var state:StyleRuleParserState = IGNORE_SPACES;
		var next:StyleRuleParserState = BEGIN_SELECTOR;
		var start:Int = 0;
		var position:Int = 0;
		var c:Int = css.fastCodeAt(position);
		
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
					var selector:String = css.substr(start, position - start);
					var isValid:Bool = _selectorParser.parseSelector(selector, selectors);
					
					//if one selector is invalid, the whole rule and selectors are
					//invalid and won't be used during cascade
					if (isValid == false)
					{
						selectors = new Array<SelectorVO>();
						return;
					}
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
					var styleDeclaration:String = css.substr(start, position - start);
					style.cssText = styleDeclaration;
					state = IGNORE_SPACES;
					next = IGNORE_SPACES;
			}
			c = css.fastCodeAt(++position);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SERIALISER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Serialize the whole style rule : selectors and
	 * style declarations
	 */
	private function serializeStyleRule():String
	{
		var serializedStyleRule:String = serializeSelectors(selectors);
		
		serializedStyleRule += "{" +  style.cssText + "}";
		return serializedStyleRule;
	}
	
	/**
	 *	Serialize the selectors of this style rule as a string. Selectors
	 * are comma separated
	 */
	private function serializeSelectors(selectors:Array<SelectorVO>):String
	{
		var serializedSelectors:String = "";
		
		for (i in 0...selectors.length)
		{
			var selector:SelectorVO = selectors[i];
			serializedSelectors += SelectorSerializer.serialize(selector);
			
			if (i < selectors.length - 1)
			{
				serializedSelectors += ", ";
			}
		}
		
		return serializedSelectors;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	static inline function isSelectorChar(c:Int):Bool {
		return isAsciiChar(c) || c == ':'.code || c == '.'.code || c == '*'.code;
	}
	
	static inline function isStyleChar(c:Int):Bool {
		return isAsciiChar(c) || c == ":".code || c == "(".code || c == ")".code;
	}
	
	static inline function isAsciiChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_cssText(value:String):String
	{
		parse(value);
		return value;
	}
	
	override private function get_cssText():String
	{
		return serializeStyleRule();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_selectorText():String
	{
		return serializeSelectors(selectors);
	}
	
	//TODO 1 : should do nothing if selector parsing fails
	private function set_selectorText(value:String):String
	{
		this.selectors = new Array<SelectorVO>();
		_selectorParser.parseSelector(value, selectors);
		return value;
	}
}