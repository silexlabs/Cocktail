/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	public var selectors:Array<SelectorData>;
	
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
		
		selectors = new Array<SelectorData>();
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
		selectors = new Array<SelectorData>();
		
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
					var selector:String = css.substr(start, position - start);
					_selectorParser.parseSelector(selector, selectors);
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
	private function serializeSelectors(selectors:Array<SelectorData>):String
	{
		var serializedSelectors:String = "";
		
		for (i in 0...selectors.length)
		{
			var selector:SelectorData = selectors[i];
			serializedSelectors += SelectorSerializer.serialize(selector);
			
			if (i < selectors.length)
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
	
	
	override private function get_type():Int
	{
		return CSSRule.STYLE_RULE;
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
		this.selectors = new Array<SelectorData>();
		_selectorParser.parseSelector(value, selectors);
		return value;
	}
}