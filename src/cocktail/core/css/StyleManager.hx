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
import cocktail.core.css.CoreStyle;
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
	 * which applies to it.
	 * 
	 * The pseudo class matched by the node are also provided.
	 * For instance, if the node is hovered by the mouse, it will
	 * match the hover pseudo class
	 */
	public function getStyleDeclaration(node:HTMLElement, matchedPseudoClasses:MatchedPseudoClassesVO):CSSStyleDeclaration
	{
		var styleDeclaration:CSSStyleDeclaration = new CSSStyleDeclaration();
		applyStyleSheets(node, styleDeclaration, _styleSheets, matchedPseudoClasses);
		
		return styleDeclaration;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply the styles declaration applying to the node to 
	 * the node's CSSStyleDeclaration object.
	 */
	private function applyStyleSheets(node:HTMLElement, nodeStyleDeclaration:CSSStyleDeclaration, styleSheets:Array<CSSStyleSheet>, matchedPseudoClasses:MatchedPseudoClassesVO):Void
	{
		//contain all the style declarations whose selector matches the node
		var matchingStyleDeclarations:Array<StyleDeclarationVO> = getMatchingStyleDeclarations(node, styleSheets, matchedPseudoClasses);
		
		//when properties are applied to the nodeStyleDeclaration, this array
		//store the name of the property so that they are are not applied multiple
		//times
		var matchedProperties:Array<String> = new Array<String>();
		
		//loop in all the style declarations applying to the node
		for (i in 0...matchingStyleDeclarations.length)
		{
			var cssStyleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i].style;
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
	private function getMatchingStyleDeclarations(node:HTMLElement, styleSheets:Array<CSSStyleSheet>, matchedPseudoClasses:MatchedPseudoClassesVO):Array<StyleDeclarationVO>
	{
		var matchingStyleDeclarations:Array<StyleDeclarationVO> = new Array<StyleDeclarationVO>();
		
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
					//for style rules, if one of the selector of the rule
					//matches the node, return the style declaration
					//of the rule
					case CSSRule.STYLE_RULE:
						var styleRule:CSSStyleRule = cast(cssRule);
						var selectors:Array<SelectorVO> = styleRule.selectors;
						
						var selectorsLength:Int = selectors.length;
						for (k in 0...selectorsLength)
						{
							if (_selectorManager.matchSelector(node, selectors[k], matchedPseudoClasses) == true)
							{
								//if the selector is matched, store the coresponding style declaration
								//along with the matching selector
								var matchingStyleDeclaration:StyleDeclarationVO = new StyleDeclarationVO(styleRule.style, selectors[k]);
								matchingStyleDeclarations.push(matchingStyleDeclaration);
								
								//break to prevent from adding a style declaration
								//multiplt time if more than one selector
								//matches
								break;
							}
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
	private function applyMatchingProperty(property:String, matchingStyleDeclarations:Array<StyleDeclarationVO>, nodeStyleDeclaration:CSSStyleDeclaration):Void
	{
		//will hold the properties with the same specified property name
		//which are defined in the matching style declarations
		var matchingProperties:Array<PropertyVO> = new Array<PropertyVO>();
		
		//loop in all the style declarations applying to the node
		var matchingStyleDeclarationsLength:Int = matchingStyleDeclarations.length;
		for (i in 0...matchingStyleDeclarationsLength)
		{
			var styleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i].style;
			var selector:SelectorVO = matchingStyleDeclarations[i].selector;

			//if a property with a matching name is found,
			//it is stored
			var typedProperty:TypedPropertyVO = styleDeclaration.getTypedProperty(property);
			if (typedProperty != null)
			{
				var matchingProperty:PropertyVO = new PropertyVO(selector, typedProperty.typedValue, styleDeclaration.parentRule.parentStyleSheet.origin, typedProperty.important);
				matchingProperties.push(matchingProperty);
			}
		}
		
		//if there is only one matching property, it is immediately set
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyVO = matchingProperties[0];
			nodeStyleDeclaration.setTypedProperty(property, matchingProperty.typedValue, matchingProperty.important);
			return;
		}
		
		//else property are sorted by style sheet origin. Only properties with highest priority
		//origin found are returned
		matchingProperties = getSortedMatchingPropertiesByPriority(matchingProperties);
		
		
		//if after sorting by origin, only one property remains, then it is the higher priority
		//one and is applied
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyVO = matchingProperties[0];
			nodeStyleDeclaration.setTypedProperty(property, matchingProperty.typedValue, matchingProperty.important);
			return;
		}
		
		//same as above but property are sorted by the specificity of their selector
		matchingProperties = getSortedMatchingPropertiesBySpecificity(matchingProperties);
		
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyVO = matchingProperties[0];
			nodeStyleDeclaration.setTypedProperty(property, matchingProperty.typedValue, matchingProperty.important);
			return;
		}
		
		//lastly if there still is more than one priority, then the one which was defined
		//the later in the CSS style sheet is considered the one with the higher priority
		var matchingProperty:PropertyVO = matchingProperties[matchingProperties.length - 1];
		nodeStyleDeclaration.setTypedProperty(property, matchingProperty.typedValue, matchingProperty.important);
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
	private function getSortedMatchingPropertiesByPriority(matchingProperties:Array<PropertyVO>):Array<PropertyVO>
	{
		var userAgentDeclarations:Array<PropertyVO> = new Array<PropertyVO>();
		var authorNormalDeclarations:Array<PropertyVO> = new Array<PropertyVO>();
		var authorImportantDeclarations:Array<PropertyVO> = new Array<PropertyVO>();
		
		//push all the mathing ptiorities into the array corresponding to their priority
		for (i in 0...matchingProperties.length)
		{
			var matchingProperty:PropertyVO = matchingProperties[i];
			switch(matchingProperty.origin)
			{
				case PropertyOriginValue.USER_AGENT:
					userAgentDeclarations.push(matchingProperty);
					
				case PropertyOriginValue.AUTHOR:
					if (matchingProperty.important == true)
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
	private function getSortedMatchingPropertiesBySpecificity(matchingProperties:Array<PropertyVO>):Array<PropertyVO>
	{
		var mostSpecificMatchingProperties:Array<PropertyVO> = new Array<PropertyVO>();
		
		//will store the higher specificity found, so that only properties with the 
		//higher specificity found are returned
		var currentHigherSpecificity:Int = 0;
		
		//loop in all properties
		for (i in 0...matchingProperties.length)
		{
			var property:PropertyVO = matchingProperties[i];
			
			//get the property specifity, defined as an integer
			var propertySpecificity:Int = _selectorManager.getSelectorSpecifity(property.selector);
		
			//if this property as the highesrt specificity so far, it
			//becomes the new highest specificity
			if (propertySpecificity > currentHigherSpecificity)
			{
				currentHigherSpecificity = propertySpecificity;
				//reset the array to prevent returning properties with lower
				//specificity
				mostSpecificMatchingProperties = new Array<PropertyVO>();
			}
			
			//add the property if it has the same specificity as the current one
			if (propertySpecificity == currentHigherSpecificity)
			{
				mostSpecificMatchingProperties.push(property);
			}
		}
		
		return mostSpecificMatchingProperties;
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