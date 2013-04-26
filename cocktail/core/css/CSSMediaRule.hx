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

/**
 * The CSSMediaRule interface 
 * represents a "@media" rule.
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSMediaRule extends CSSRule
{
	/**
	 * returns a MediaList object for 
	 * the list of media queries specified with the "@media" rule.
	 */
	public var media(default, null):MediaList;
	
	/**
	 * return a CSSRuleList object for the list 
	 * of CSS rules specified with the "@media" rule.
	 */
	public var cssRules(default, null):CSSRuleList;
	
	/**
	 * class constructor
	 */
	public function new(parentStyleSheet:CSSStyleSheet = null, parentRule:CSSRule = null) 
	{
		super(parentStyleSheet, parentRule);
	}
	
	public function insertRule(rule:String, index:Int):Int
	{
		return -1;
	}
	
	public function deleteRule(index:Int):Void
	{
		
	}
	
}