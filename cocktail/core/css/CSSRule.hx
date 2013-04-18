/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

/**
 * The CSSRule interface represents an abstract, base 
 * CSS style rule. Each distinct CSS style rule type is
 * represented by a distinct interface that inherits from this interface.
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSRule 
{
	/**
	 * When the value of the type attribute is STYLE_RULE, 
	 * then the object that implements this interface
	 * must implement the CSSStyleRule interface.
	 */
	public static inline var STYLE_RULE:Int = 1;
	
	/**
	 * When the value of the type attribute is IMPORT_RULE,
	 * then the object that implements this interface must
	 * implement the CSSImportRule interface.
	 */
	public static inline var IMPORT_RULE:Int = 3;
	
	/**
	 * When the value of the type attribute is MEDIA_RULE,
	 * then the object that implements this interface must 
	 * implement the CSSMediaRule interface.
	 */
	public static inline var MEDIA_RULE:Int = 4;
	
	/**
	 * When the value of the type attribute is FONT_FACE_RULE,
	 * then the object that implements this interface must
	 * implement the CSSFontFaceRule interface.
	 */
	public static inline var FONT_FACE_RULE:Int = 5;
	
	/**
	 * The type attribute must return one of the following values: 
	 * STYLE_RULE, IMPORT_RULE, MEDIA_RULE, FONT_FACE_RULE, PAGE_RULE, NAMESPACE_RULE,
	 * or a registered extension value.
	 */
	public var type(default, null):Int;
	
	/**
	 * get/set the rule content. On getting return
	 * a CSS serialisation of the rule, on setting
	 * parse the CSS rule into object
	 */
	public var cssText(get_cssText, set_cssText):String;
	
	/**
	 * The parentRule attribute must return the nearest
	 * enclosing rule of the current rule or null, if
	 * there is no enclosing rule.
	 */
	public var parentRule(default, null):CSSRule;
	
	/**
	 * The parentStyleSheet attribute must return the
	 * CSSStyleSheet object that contains the the current rule.
	 */
	public var parentStyleSheet(default, null):CSSStyleSheet;
	
	/**
	 * class constructor
	 */
	public function new(parentStyleSheet:CSSStyleSheet = null, parentRule:CSSRule = null) 
	{
		this.parentStyleSheet = parentStyleSheet;
		this.parentRule = parentRule;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		if (parentRule != null)
		{
			parentRule.dispose();
			parentRule = null;
		}
		
		if (parentStyleSheet != null)
		{
			parentStyleSheet.dispose();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_cssText():String
	{
		return cssText;
	}
	
	private function set_cssText(value:String):String
	{
		return cssText = value;
	}
}