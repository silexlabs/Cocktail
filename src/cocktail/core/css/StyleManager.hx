/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.style.CoreStyle;
import cocktail.core.css.CSSData;

/**
 * This class holds a reference to each style sheet
 * declared in the document and can, for a given node,
 * return all of the styles applying to it
 * 
 * @author Yannick DOMINGUEZ
 */
class StyleManager 
{
	/**
	 * Holds all the style sheets of the document
	 */
	private var _styleSheets:Array<CSSStyleSheet>;
	
	/**
	 * a reference to a selector manager, which can
	 * determine wether a node matches a selector
	 */
	private var _selectorManager:SelectorManager;
	
	/**
	 * class constructor. Init class attribute
	 */
	public function new() 
	{
		_styleSheets = new Array<CSSStyleSheet>();
		_selectorManager = new SelectorManager();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Add a style sheet to the style
	 * sheets of the document
	 */
	public function addStyleSheet(styleSheet:CSSStyleSheet):Void
	{
		_styleSheets.push(styleSheet);
	}
	
	/**
	 * Remove a style sheet from the document's style sheet
	 */
	public function removeStyleSheet(styleSheet:CSSStyleSheet):Void
	{
		_styleSheets.remove(styleSheet);
	}
	
	/**
	 * For a given node, return an object containing
	 * all the style declarations from the style sheets
	 * which applies to it
	 */
	public function getStyleDeclaration(node:HTMLElement):CSSStyleDeclaration
	{
		var styleDeclaration:CSSStyleDeclaration = new CSSStyleDeclaration();
		
		applyStyleSheets(node, styleDeclaration, _styleSheets);
		
		return styleDeclaration;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply the styles declaration applying to the node to 
	 * the node's CSSStyleDeclaration object.
	 */
	private function applyStyleSheets(node:HTMLElement, nodeStyleDeclaration:CSSStyleDeclaration, styleSheets:Array<CSSStyleSheet>):Void
	{
		//contain all the style declarations whose selector matches the node
		var matchingStyleDeclarations:Array<CSSStyleDeclaration> = getMatchingStyleDeclarations(node, styleSheets);
		
		//when properties are applied to the nodeStyleDeclaration, this array
		//store the name of the property so that they are are not applied multiple
		//times
		var matchedProperties:Array<String> = new Array<String>();
		
		//loop in all the style declarations applying to the node
		for (i in 0...matchingStyleDeclarations.length)
		{
			var cssStyleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i];
			for (j in 0...cssStyleDeclaration.length)
			{
				var property:String = cssStyleDeclaration.item(j);
				//check if the property was already previously applied
				if (alreadyMatched(property, matchedProperties) == false)
				{
					applyMatchingProperty(property, matchingStyleDeclarations, nodeStyleDeclaration);
					matchedProperties.push(property);
				}
			}
		}
	}
	
	/**
	 * Return an array containing all the style declarations
	 * contained in the document's style sheets which apply to
	 * the node
	 */
	private function getMatchingStyleDeclarations(node:HTMLElement, styleSheets:Array<CSSStyleSheet>):Array<CSSStyleDeclaration>
	{
		var matchingStyleDeclarations:Array<CSSStyleDeclaration> = new Array<CSSStyleDeclaration>();
		
		//loop in all style sheets
		var styleSheetsLength:Int = styleSheets.length;
		for (i in 0...styleSheetsLength)
		{
			var styleSheet:CSSStyleSheet = styleSheets[i];
			
			//loop in all the rules of the style sheet
			var cssRules:CSSRuleList = styleSheet.cssRules;
			var cssRulesLength:Int = cssRules.length;
			for (j in 0...cssRulesLength)
			{
				var cssRule:CSSRule = cssRules[j];
				
				switch (cssRule.type)
				{
					//for style rules, if the selector of the rule
					//matches the node, return the style declaration
					//of the rule
					case CSSRule.STYLE_RULE:
						var styleRule:CSSStyleRule = cast(cssRule);
						if (_selectorManager.matchSelector(node, styleRule.selector) == true)
						{
							matchingStyleDeclarations.push(styleRule.style);
						}
						
					case CSSRule.MEDIA_RULE:
						//TODO : check if media rule applies before storing
						//style declaration
				}
			}
		}
		
		return matchingStyleDeclarations;
	}
	
	/**
	 * For a given property, if the property is defined in 
	 * multiple styles declaration, this method finds the
	 * one with the higher priority and applies it to
	 * the returned node's style declaration
	 */
	private function applyMatchingProperty(property:String, matchingStyleDeclarations:Array<CSSStyleDeclaration>, nodeStyleDeclaration:CSSStyleDeclaration):Void
	{
		//will hold the properties with the same specified property name
		//which are defined in the matching style declarations
		var matchingProperties:Array<PropertyData> = new Array<PropertyData>();
		
		//loop in all the style declarations applying to the node
		var matchingStyleDeclarationsLnegth:Int = matchingStyleDeclarations.length;
		for (i in 0...matchingStyleDeclarationsLnegth)
		{
			var styleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i];
			
			var cssRule:CSSRule = styleDeclaration.parentRule;
			
			var selector:SelectorData = null;
			
			//TODO 2 : the selector should be known by that point, add another structure ?
			//or store an array of CSSRule instead ? > Actually only CSSStyleRule are needed
			//for this section
			
			//retrieve the selector of the style declaration
			switch(cssRule.type)
			{
				case CSSRule.STYLE_RULE:
					var styleRule:CSSStyleRule = cast(cssRule);
					selector = styleRule.selector;
			}
			
			//loop in all the style declarations
			for (j in 0...styleDeclaration.length)
			{
				//if a property with a matching name is found,
				//it is stored
				if (styleDeclaration.item(j) == property)
				{
					var matchingProperty:PropertyData = {
						value:styleDeclaration.getPropertyValue(property),
						important:styleDeclaration.getPropertyPriority(property),
						//TODO : origin should be retrieved via stylesheet
						origin:PropertyOriginValue.AUTHOR,
						selector:selector
					}
					
					matchingProperties.push(matchingProperty);
				}
			}
		}
		
		//if there is only one matching property, it is immediately set
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyData = matchingProperties[0];
			nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
			return;
		}
		
		//else property are sorted by style sheet origin. Only properties with highest priority
		//origin found are returned
		matchingProperties = getSortedMatchingPropertiesByPriority(matchingProperties);
		
		//if after sorting by origin, only one property remains, then it is the higher priority
		//one and is applied
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyData = matchingProperties[0];
			nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
			return;
		}
		
		//same as above but property are sorted by the specificity of their selector
		matchingProperties = getSortedMatchingPropertiesBySpecificity(matchingProperties);
		
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyData = matchingProperties[0];
			nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
			return;
		}
		
		//lastly if there still is more than one priority, then the one which was defined
		//the later in the CSS style sheet is considered the one with the higher priority
		var matchingProperty:PropertyData = matchingProperties[matchingProperties.length - 1];
		nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
	}
	
	/**
	 * Sort an array of property by origin of the style sheet.
	 * Style sheet can be declared by the user agent (this is the default style sheet applied)
	 * or by the document author.
	 * 
	 * In browsers, the user can also declare style sheets but it doesn't apply to Cocktail.
	 * 
	 * Style sheet defined by the author always have a higher priority than the one declared
	 * by the user agent (Cocktail).
	 * 
	 * If a priority is defined as "important" it has a higher priority
	 */
	private function getSortedMatchingPropertiesByPriority(matchingProperties:Array<PropertyData>):Array<PropertyData>
	{
		var userAgentDeclarations:Array<PropertyData> = new Array<PropertyData>();
		var authorNormalDeclarations:Array<PropertyData> = new Array<PropertyData>();
		var authorImportantDeclarations:Array<PropertyData> = new Array<PropertyData>();
		
		//push all the mathing ptiorities into the array corresponding to their priority
		for (i in 0...matchingProperties.length)
		{
			var matchingProperty:PropertyData = matchingProperties[i];
			switch(matchingProperty.origin)
			{
				case PropertyOriginValue.USER_AGENT:
					userAgentDeclarations.push(matchingProperty);
					
				case PropertyOriginValue.AUTHOR:
					//TODO 2 : add const
					if (matchingProperty.important == "important")
					{
						authorImportantDeclarations.push(matchingProperty);
					}
					else
					{
						authorNormalDeclarations.push(matchingProperty);
					}
			}
		}
		
		//first if at least one of the matching priorities is declared important
		//then the important properties are returned
		if (authorImportantDeclarations.length > 0)
		{
			return authorImportantDeclarations;
		}
		
		//here normal author defined properties are returned
		if (authorNormalDeclarations.length > 0)
		{
			return authorNormalDeclarations;
		}
		
		//else user agent defined properties are returned
		return userAgentDeclarations;
	}
	
	/**
	 * Sort an array of properties by the specificity of their
	 * selector. The specificity of the selector is defined by
	 * the SelectorManager. Only the properties with higher specificity
	 * found are returned
	 */
	private function getSortedMatchingPropertiesBySpecificity(matchingProperties:Array<PropertyData>):Array<PropertyData>
	{
		var matchingProperties:Array<PropertyData> = new Array<PropertyData>();
		
		//will store the higher specificity found, so that only properties with the 
		//higher specificity found are returned
		var currentHigherSpecificity:Int = 0;
		
		//loop in all properties
		for (i in 0...matchingProperties.length)
		{
			var property:PropertyData = matchingProperties[i];
			
			//get the property specifity, defined as an integer
			var propertySpecificity:Int = _selectorManager.getSelectorSpecifity(property.selector);
			
			//if this property as the highesrt specificity so far, it
			//becomes the new highest specificity
			if (propertySpecificity > currentHigherSpecificity)
			{
				currentHigherSpecificity = propertySpecificity;
				//reset the array to prevent returning properties with lower
				//specificity
				matchingProperties = new Array<PropertyData>();
			}
			
			//add the property if it has the same specificity as the current one
			if (propertySpecificity == currentHigherSpecificity)
			{
				matchingProperties.push(property);
			}
		}
		
		return matchingProperties;
	}
	
	/**
	 * Utils method determining if a property was already applied
	 * to the node's style declaration
	 */
	private function alreadyMatched(property:String, matchedProperties:Array<String>):Bool
	{
		for (i in 0...matchedProperties.length)
		{
			if (matchedProperties[i] == property)
			{
				return true;
			}
		}
		
		return false;
	}
}