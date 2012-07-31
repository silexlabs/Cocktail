package cocktail.core.css;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.CoreStyle;
import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class StyleManager 
{

	private var _defaultStyleSheet:CSSStyleSheet;
	
	private var _styleSheets:Array<CSSStyleSheet>;
	
	public function new() 
	{
		_styleSheets = new Array<CSSStyleSheet>();
	}
	
	public function addStyleSheet(styleSheet:CSSStyleSheet):Void
	{
		
	}
	
	public function removeStyleSheet(styleSheet:CSSStyleSheet):Void
	{
		
	}
	
	public function getCoreStyle(node:HTMLElement):CSSStyleDeclaration
	{
		var styleDeclaration:CSSStyleDeclaration = new CSSStyleDeclaration();
		
		applyDefaultStylesValues(styleDeclaration);
		
		applyDefaultStyleSheet(styleDeclaration, _defaultStyleSheet);
		
		if (node.parentNode != null)
		{
			applyInheritableStyles(node.parentNode, coreStyle);
		}
		
	}
	
	private function applyStyleSheets(node:HTMLElement, nodeStyleDeclaration:CSSStyleDeclaration, styleSheets:Array<CSSStyleSheet>):Void
	{
		var matchingStyleDeclarations:Array<CSSStyleDeclaration> = new Array<CSSStyleDeclaration>();
		
		for (i in 0...styleSheets.length)
		{
			var styleSheet:CSSStyleSheet = styleSheets[i];
			
			for (j in 0...styleSheet.cssRules.length)
			{
				var cssRule:CSSRule = defaultSyleSheet.cssRules[j];
				
				switch (cssRule.type)
				{
					case CSSRule.STYLE_RULE:
						var styleRule:CSSStyleRule = cast(cssRule);
						if (matchSelector(node, styleRule.selectorText) == true)
						{
							matchingStyleDeclarations.push(styleRule.style);
						}
						
					case CSSRule.MEDIA_RULE:
						//TODO : check if media rule applies before storing
						//style declaration
				}
			}
		}
		
		var matchedProperties:Array<String> = new Array<String>();
		
		for (i in 0...matchingStyleDeclarations.length)
		{
			var cssStyleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i];
			
			for (j in 0...cssStyleDeclaration.length)
			{
				var property:String = cssStyleDeclaration.item(j);
				if (alreadyMatched(property, matchedProperties) == false)
				{
					applyMatchingProperty(property, matchingStyleDeclarations, nodeStyleDeclaration);
					matchedProperties.push(property);
				}
			}
		}
	}
	
	private function applyMatchingProperty(property:String, matchingStyleDeclarations:Array<CSSStyleDeclaration>, nodeStyleDeclaration:CSSStyleDeclaration):Void
	{
		var matchingProperties:Array<PropertyData> = new Array<PropertyData>();
		
		for (i in 0....matchingStyleDeclarations.length)
		{
			var styleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i];
			
			for (j in 0...styleDeclaration.length)
			{
				if (styleDeclaration.item(j) == property)
				{
					var matchingPropertyData:PropertyData = {
						value:styleDeclaration.getPropertyValue(property),
						important:styleDeclaration.getPropertyPriority(property) == "important",
						origin:MatchingPropertyOrigin.AUTHOR;
					}
				}
			}
		}
		
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyData = matchingProperties[0];
			nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
			return;
		}
		
		matchingProperties = getSortedMatchingPropertiesByPriority(matchingProperties);
		
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyData = matchingProperties[0];
			nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
			return;
		}
		
		matchingProperties = getSortedMatchingPropertiesBySpecificity(matchingProperties);
	}
	
	private function getSortedMatchingPropertiesByPriority(matchingProperties:Array<PropertyData>):Array<PropertyData>
	{
		var userAgentDeclarations:Array<PropertyData> = new Array<PropertyData>();
		var authorNormalDeclarations:Array<PropertyData> = new Array<PropertyData>();
		var authorImportantDeclarations:Array<PropertyData> = new Array<PropertyData>();
		
		for (i in 0...matchingProperties.length)
		{
			var matchingProperty:PropertyData = matchingProperties[i];
			switch(matchingProperty.origin)
			{
				case MatchingPropertyOrigin.USER_AGENT:
					userAgentDeclarations.push(matchingProperty);
					
				case MatchingPropertyOrigin.AUTHOR:
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
		
		if (authorImportantDeclarations.length > 0)
		{
			return authorImportantDeclarations;
		}
		
		if (authorNormalDeclarations.length > 0)
		{
			return authorNormalDeclarations;
		}
		
		return userAgentDeclarations;
	}
	
	
	private function getSortedMatchingPropertiesBySpecificity(matchingProperties:Array<PropertyData>):Array<PropertyData>
	{
		var matchingProperties:Array<PropertyData> = new Array<PropertyData>();
		var currentSpecificity:Int = 0;
		
		for (i in 0...matchingProperties.length)
		{
			var property:PropertyData = matchingProperties[i];
			var propertySpecificity:Int = getPropertySpecifity(property.selectors);
			
			if (propertySpecificity > currentSpecificity)
			{
				matchingProperties = new Array<PropertyData>();
			}
			
			matchingProperties.push(property);
		
		}
	}
	
	private function getPropertySpecifity(selectors:Array<SelectorValue>):Int
	{
		var propertySpecificity:Int = 0;
		
		var idSelectorsNumber:Int = 0;
		var classAttributesAndPseudoClassesNumber:Int = 0;
		var typeAndPseudoElementsNumber:Int = 0;
		
		for (i in 0...selectors.length)
		{
			var selector:SelectorValue = selectors[i];
			
			switch (selector)
			{
				case UNIVERSAL:
					
				case TYPE(value):
					typeAndPseudoElementsNumber++;
					
				case ATTRIBUTE(value):
					classAttributesAndPseudoClassesNumber++;
					
				case PSEUDO_CLASS(value):
					classAttributesAndPseudoClassesNumber++;
					
				case PSEUDO_ELEMENT(value):
					typeAndPseudoElementsNumber++;
					
				case LINK_PSEUDO_CLASS(value):
					classAttributesAndPseudoClassesNumber++;
					
				case USER_ACTION_PSEUDO_CLASS(value):
					classAttributesAndPseudoClassesNumber++;
					
				case CLASS(value):
					classAttributesAndPseudoClassesNumber++;
					
				case ID(value):
					idSelectorsNumber++;
					
				case DESCENDANT_COMBINATOR(parent, child):
					
				case CHILD_COMBINATOR(parent, child):
					
				case ADJACENT_SIBLING_COMBINATOR(sibling, child):
					
				case GENERAL_SIBLING_COMBINATOR(sibling, child):
			}
		}
		
		var concatenated:String = Std.string(idSelectorsNumber) + Std.string(classAttributesAndPseudoClassesNumber) + Std.string(typeAndPseudoElementsNumber);
		propertySpecificity = Std.int(concatenated);
		
		return propertySpecificity;
	}
	
	
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
	
	private function matchSelector(node:HTMLElement, selector:String):Bool
	{
		return true;
	}
	
	private function applyDefaultStylesValues(styleDeclaration:CSSStyleDeclaration):Void
	{
		styleDeclaration.setProperty("width", "auto");
		styleDeclaration.setProperty("height", "auto");
	}
	
	private function applyInheritableStyles(node:HTMLElement, coreStyle:CoreStyle):Void
	{
		
	}
	
}