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
import cocktail.core.css.parsers.CSSRulesParser;
import cocktail.core.html.HTMLElement;
 
/**
 * The CSSStyleSheet interface represents
 * a CSS style sheet rule.
 */
class CSSStyleSheet extends StyleSheet
{
	/**
	 * A ref to The CSS rule in the style sheet parent
	 * that caused the inclusion of the style 
	 * sheet or null if there is no such CSS rule.
	 */
	public var ownerRule(default, null):CSSRule;
	
	/**
	 * The cssRules attribute return a CSSRuleList object 
	 * representing the style sheet CSS rules.
	 */
	public var cssRules(default, null):CSSRuleList;
	
	/**
	 * An instance of the parser parsing style sheet
	 * into CSS rules
	 */
	private var _cssRulesParser:CSSRulesParser;
	
	/**
	 * Return the origin of the stylesheet (user agent
	 * or author)
	 */
	public var origin(default, null):PropertyOriginValue;
	
	/**
	 * class constructor
	 */
	public function new(stylesheet:String, origin:PropertyOriginValue, ownerNode:HTMLElement = null, href:String = null, parentStyleSheet:StyleSheet = null, ownerRule:CSSRule = null) 
	{
		super(stylesheet, ownerNode, href, parentStyleSheet);
		cssRules = new CSSRuleList();
		this.ownerRule = ownerRule;
		this.origin = origin;
		_cssRulesParser = new CSSRulesParser();
		
		var rules:Array<String> = _cssRulesParser.parseRules(stylesheet);
		
		for (i in 0...rules.length)
		{
			insertRule(rules[i], cssRules.length);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Insert a CSS rule at the given index in the cssRules 
	 * list. If parsig he rule fails, it is not inserted
	 */
	public function insertRule(rule:String, index:Int):Int
	{
		var cssRule:CSSRule = _cssRulesParser.parseRule(rule, this);
		cssRules.insert(index, cssRule);
		return index;
	}
	
	/**
	 * Remove the rule at the given index from
	 * the cssRule array
	 */
	public function deleteRule(index:Int):Void
	{
		cssRules.remove(cssRules[index]);
	}
	
}