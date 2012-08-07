/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
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
	 * class constructor
	 */
	public function new(stylesheet:String, ownerNode:HTMLElement = null, href:String = null, parentStyleSheet:StyleSheet = null, ownerRule:CSSRule = null) 
	{
		super(stylesheet, ownerNode, href, parentStyleSheet);
		cssRules = new CSSRuleList();
		this.ownerRule = ownerRule;
		_cssRulesParser = new CSSRulesParser();
		
		var rules:Array<String> = _cssRulesParser.parseRules(stylesheet);
		
		for (i in 0...rules.length)
		{
			insertRule(rules[i], cssRules.length - 1);
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