/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.selector.SelectorMatcher;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.css.CoreStyle;
import cocktail.css.*;
import cocktail.css.CSSOMData;
import cocktail.css.CSSSelectorData;

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
	 * a reference to a selector matcher, which can
	 * determine wether a node matches a selector
	 */
	private var _selectorMatcher:SelectorMatcher;
	
	/**
	 * when properties are applied to a style declaration,
	 * stores the index of the properties so that they are are not
	 * applied multiple times
	 */
	private var _matchedProperties:Array<Int>;
	
	/**
	 * Holds all the style declaration applying to 
	 * the current node
	 */
	private var _matchingStyleDeclaration:Array<StyleDeclarationVO>;
	
	/**
	 * hold the properties with the same specified property name
	 * which are defined in the matching style declarations
	 */ 
	private var _matchingProperties:Array<PropertyVO>;
	
	/**
	 * When sorting properties by specificity,
	 * store the most specifics
	 */
	private var _mostSpecificMatchingProperties:Array<PropertyVO>;
	
	/**
	 * When sorting a property by origin, store
	 * user agent declarations
	 */
	private var _userAgentDeclarations:Array<PropertyVO>;
	
	/**
	 * When sorting a property by origin, store
	 * author normal declarations
	 */
	private var _authorNormalDeclarations:Array<PropertyVO>;
	
	/**
	 * When sorting a property by origin, store
	 * author "!important" declarations
	 */
	private var _authorImportantDeclarations:Array<PropertyVO>;
	
	/**
	 * class constructor. Init class attribute
	 */
	public function new(selectorMatcher:SelectorMatcher) 
	{
		_styleSheets = new Array<CSSStyleSheet>();
		
		_matchingStyleDeclaration = new Array<StyleDeclarationVO>();
		_mostSpecificMatchingProperties = new Array<PropertyVO>();
		_matchingProperties = new Array<PropertyVO>();
		_matchedProperties = new Array<Int>();
		_userAgentDeclarations = new Array<PropertyVO>();
		_authorNormalDeclarations = new Array<PropertyVO>();
		_authorImportantDeclarations = new Array<PropertyVO>();
		
		_selectorMatcher = selectorMatcher;
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
		var styleDeclaration:CSSStyleDeclaration = null;
		
		//reuse the style declaration if existing
		if (node.styleManagerCSSDeclaration != null)
		{
			styleDeclaration = node.styleManagerCSSDeclaration;
			styleDeclaration.reset();
		}
		else
		{
			styleDeclaration = new CSSStyleDeclaration();
		}
		
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

		//clear the array keeping track of which property
		//was already matched
		_matchedProperties = [];
		
		//loop in all the style declarations applying to the node
		var length:Int = matchingStyleDeclarations.length;
		for (i in 0...length)
		{
			var cssStyleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i].style;
			var styleLength:Int = cssStyleDeclaration.length;
			for (j in 0...styleLength)
			{
				var propertyIndex:Int = cssStyleDeclaration.item(j);
				//check if the property was already previously applied
				if (alreadyMatched(propertyIndex, _matchedProperties) == false)
				{
					applyMatchingProperty(propertyIndex, matchingStyleDeclarations, nodeStyleDeclaration);
					_matchedProperties.push(propertyIndex);
				}
			}
		}
	}
	
	/**
	 * Return wether a given property was
	 * already matched
	 */
	private function alreadyMatched(propertyIndex:Int, matchedProperties:Array<Int>):Bool
	{
		var length:Int = matchedProperties.length;
		for (i in 0...length)
		{
			if (matchedProperties[i] == propertyIndex)
			{
				return true;
			}
		}
		
		return false;
	}
	
	/**
	 * Return an array containing all the style declarations
	 * contained in the document's style sheets which apply to
	 * the node or null if there are none
	 */
	private function getMatchingStyleDeclarations(node:HTMLElement, styleSheets:Array<CSSStyleSheet>, matchedPseudoClasses:MatchedPseudoClassesVO):Array<StyleDeclarationVO>
	{
		_matchingStyleDeclaration = [];
		
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
							var selector:SelectorVO = selectors[k];
							var match:Bool = false;
							
							//to optimise speed the matchSelector method must be called
							//the least time possible
							
							//if the selector begins with a class, 
							//then only match if the node has at least one class,
							//and contains the first class of the selector
							if (selector.beginsWithClass == true)
							{
								if (matchedPseudoClasses.hasClasses == true)
								{
									var classListLength:Int = matchedPseudoClasses.nodeClassList.length;
									for (l in 0...classListLength)
									{
										if (matchedPseudoClasses.nodeClassList[l] == selector.firstClass)
										{
											//in this case, the selector only has a single
											//class selector, so it is a match
											if (selector.isSimpleClassSelector == true)
											{
												match = true;
												break;
											}
											//else need to perform a full match
											else
											{
												match = _selectorMatcher.matchSelector(cast(node), cast(selectors[k]), cast(matchedPseudoClasses)) == true;
												break;
											}
										}
									}
								}
							}
							//if the selector begins with an id selector, only match node if
							//it has an id
							else if (selector.beginsWithId == true)
							{
								if (matchedPseudoClasses.hasId == true)
								{
									if (matchedPseudoClasses.nodeId == selector.firstId)
									{
										//if the selector consists of only an Id, it is a match
										if (selector.isSimpleIdSelector == true)
										{
											match = true;
										}
										//else need to perform a full match
										else
										{
											match = _selectorMatcher.matchSelector(cast(node), cast(selectors[k]), cast(matchedPseudoClasses)) == true; }
									}
								}
							}
							//if the selector begins with a type, only match node wih the
							//same type
							else if (selector.beginsWithType == true)
							{
								if (matchedPseudoClasses.nodeType == selector.firstType)
								{
									//if the selector is only a type selector, then it matches
									if (selector.isSimpleTypeSelector == true)
									{
										match = true;
									}
									//else a full match is needed
									else
									{
										match = _selectorMatcher.matchSelector(cast(node), cast(selectors[k]), cast(matchedPseudoClasses)) == true;
									}
								}
							}
							//in other cases, full match
							else
							{
								match = _selectorMatcher.matchSelector(cast(node), cast(selectors[k]), cast(matchedPseudoClasses)) == true;
							}
							
							if (match == true)
							{
								//if the selector is matched, store the coresponding style declaration
								//along with the matching selector
								var matchingStyleDeclaration:StyleDeclarationVO = new StyleDeclarationVO();
								matchingStyleDeclaration.style = styleRule.style;
								matchingStyleDeclaration.selector = selectors[k];
								_matchingStyleDeclaration.push(matchingStyleDeclaration);
								
								//break to prevent from adding a style declaration
								//multiplt time if more than one selector
								//matches
								break;
							}
						}
						
					default:
				}
			}
		}
		
		return _matchingStyleDeclaration;
	}
	
	/**
	 * For a given property, if the property is defined in 
	 * multiple styles declaration, this method finds the
	 * one with the higher priority and applies it to
	 * the returned node's style declaration
	 */
	private function applyMatchingProperty(propertyIndex:Int, matchingStyleDeclarations:Array<StyleDeclarationVO>, nodeStyleDeclaration:CSSStyleDeclaration):Void
	{
		//will hold the properties with the same specified property name
		//which are defined in the matching style declarations
		_matchingProperties = [];
		
		//loop in all the style declarations applying to the node
		var matchingStyleDeclarationsLength:Int = matchingStyleDeclarations.length;
		for (i in 0...matchingStyleDeclarationsLength)
		{
			var styleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i].style;
			var selector:SelectorVO = matchingStyleDeclarations[i].selector;

			//if a property with a matching name is found,
			//it is stored
			var typedProperty:TypedPropertyVO = styleDeclaration.getTypedProperty(propertyIndex);
			if (typedProperty != null)
			{
				var matchingProperty:PropertyVO = new PropertyVO();
				matchingProperty.selector = selector;
				matchingProperty.typedValue = typedProperty.typedValue;
				matchingProperty.origin = styleDeclaration.parentRule.parentStyleSheet.origin;
				matchingProperty.important = typedProperty.important;
				_matchingProperties.push(matchingProperty);
			}
		}
		
		//if there is only one matching property, it is immediately set
		if (_matchingProperties.length == 1)
		{
			var matchingProperty:PropertyVO = _matchingProperties[0];
			nodeStyleDeclaration.setTypedProperty(propertyIndex, matchingProperty.typedValue, matchingProperty.important);
			return;
		}
		
		//else property are sorted by style sheet origin. Only properties with highest priority
		//origin found are returned
		var tempMatchingProperties:Array<PropertyVO> = getSortedMatchingPropertiesByPriority(_matchingProperties);
		
		//if after sorting by origin, only one property remains, then it is the higher priority
		//one and is applied
		if (tempMatchingProperties.length == 1)
		{
			var matchingProperty:PropertyVO = tempMatchingProperties[0];
			nodeStyleDeclaration.setTypedProperty(propertyIndex, matchingProperty.typedValue, matchingProperty.important);
			return;
		}
		
		//same as above but property are sorted by the specificity of their selector
		tempMatchingProperties = getSortedMatchingPropertiesBySpecificity(tempMatchingProperties);
		
		if (tempMatchingProperties.length == 1)
		{
			var matchingProperty:PropertyVO = tempMatchingProperties[0];
			nodeStyleDeclaration.setTypedProperty(propertyIndex, matchingProperty.typedValue, matchingProperty.important);
			return;
		}
		
		//lastly if there still is more than one priority, then the one which was defined
		//the later in the CSS style sheet is considered the one with the higher priority
		var matchingProperty:PropertyVO = tempMatchingProperties[tempMatchingProperties.length - 1];
		nodeStyleDeclaration.setTypedProperty(propertyIndex, matchingProperty.typedValue, matchingProperty.important);
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
		_userAgentDeclarations = [];
		_authorNormalDeclarations = [];
		_authorImportantDeclarations = [];
		
		//push all the mathing ptiorities into the array corresponding to their priority
		var length:Int = matchingProperties.length;
		for (i in 0...length)
		{
			var matchingProperty:PropertyVO = matchingProperties[i];
			switch(matchingProperty.origin)
			{
				case PropertyOriginValue.USER_AGENT:
					_userAgentDeclarations.push(matchingProperty);
					
				case PropertyOriginValue.AUTHOR:
					if (matchingProperty.important == true)
					{
						_authorImportantDeclarations.push(matchingProperty);
					}
					else
					{
						_authorNormalDeclarations.push(matchingProperty);
					}
			}
		}
		
		//first if at least one of the matching priorities is declared important
		//then the important properties are returned
		if (_authorImportantDeclarations.length > 0)
		{
			return _authorImportantDeclarations;
		}
		
		
		//here normal author defined properties are returned
		if (_authorNormalDeclarations.length > 0)
		{
			return _authorNormalDeclarations;
		}
		
		//else user agent defined properties are returned
		return _userAgentDeclarations;
	}
	
	/**
	 * Sort an array of properties by the specificity of their
	 * selector. The specificity of the selector is defined by
	 * the SelectorManager. Only the properties with higher specificity
	 * found are returned
	 */
	private function getSortedMatchingPropertiesBySpecificity(matchingProperties:Array<PropertyVO>):Array<PropertyVO>
	{
		_mostSpecificMatchingProperties = [];
		
		//will store the higher specificity found, so that only properties with the 
		//higher specificity found are returned
		var currentHigherSpecificity:Int = 0;
		
		//loop in all properties
		var length:Int = matchingProperties.length;
		for (i in 0...length)
		{
			var property:PropertyVO = matchingProperties[i];
			
			//get the property specifity, defined as an integer
			var propertySpecificity:Int = _selectorMatcher.getSelectorSpecifity(cast property.selector);
		
			//if this property as the highesrt specificity so far, it
			//becomes the new highest specificity
			if (propertySpecificity > currentHigherSpecificity)
			{
				currentHigherSpecificity = propertySpecificity;
				
				//reset the array to prevent returning properties with lower
				//specificity
				_mostSpecificMatchingProperties = [];
			}
			
			//add the property if it has the same specificity as the current one
			if (propertySpecificity == currentHigherSpecificity)
			{
				_mostSpecificMatchingProperties.push(property);
			}
		}
		
		return _mostSpecificMatchingProperties;
	}
}
