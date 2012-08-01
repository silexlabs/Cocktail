package cocktail.core.css;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.style.CoreStyle;
import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class StyleManager 
{
	private var _styleSheets:Array<CSSStyleSheet>;
	
	private var _selectorManager:SelectorManager;
	
	public function new() 
	{
		_styleSheets = new Array<CSSStyleSheet>();
		_selectorManager = new SelectorManager();
	}
	
	public function addStyleSheet(styleSheet:CSSStyleSheet):Void
	{
		_styleSheets.push(styleSheet);
	}
	
	public function removeStyleSheet(styleSheet:CSSStyleSheet):Void
	{
		_styleSheets.remove(styleSheet);
	}
	
	public function getStyleDeclaration(node:HTMLElement):CSSStyleDeclaration
	{
		var styleDeclaration:CSSStyleDeclaration = new CSSStyleDeclaration();
		
		applyDefaultStylesValues(styleDeclaration);
		
		if (node.parentNode != null)
		{
			applyInheritableStyles(node.parentNode, styleDeclaration);
		}
		
		applyStyleSheets(node, styleDeclaration, _styleSheets);
		
		return styleDeclaration;
	}
	
	private function applyStyleSheets(node:HTMLElement, nodeStyleDeclaration:CSSStyleDeclaration, styleSheets:Array<CSSStyleSheet>):Void
	{
		var matchingStyleDeclarations:Array<CSSStyleDeclaration> = new Array<CSSStyleDeclaration>();
		
		for (i in 0...styleSheets.length)
		{
			var styleSheet:CSSStyleSheet = styleSheets[i];
			
			for (j in 0...styleSheet.cssRules.length)
			{
				var cssRule:CSSRule = styleSheet.cssRules[j];
				
				switch (cssRule.type)
				{
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
		
		for (i in 0...matchingStyleDeclarations.length)
		{
			var styleDeclaration:CSSStyleDeclaration = matchingStyleDeclarations[i];
			
			var cssRule:CSSRule = styleDeclaration.parentRule;
			
			var selector:SelectorData = null;
			
			switch(cssRule.type)
			{
				case CSSRule.STYLE_RULE:
					var styleRule:CSSStyleRule = cast(cssRule);
					selector = styleRule.selector;
			}
			
			for (j in 0...styleDeclaration.length)
			{
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
		
		if (matchingProperties.length == 1)
		{
			var matchingProperty:PropertyData = matchingProperties[0];
			nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
			return;
		}
		
		var matchingProperty:PropertyData = matchingProperties[matchingProperties.length - 1];
		nodeStyleDeclaration.setProperty(property, matchingProperty.value, matchingProperty.important);
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
				case PropertyOriginValue.USER_AGENT:
					userAgentDeclarations.push(matchingProperty);
					
				case PropertyOriginValue.AUTHOR:
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
			var propertySpecificity:Int = _selectorManager.getSelectorSpecifity(property.selector);
			
			if (propertySpecificity > currentSpecificity)
			{
				matchingProperties = new Array<PropertyData>();
			}
			
			matchingProperties.push(property);
		
		}
		
		return matchingProperties;
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
	
	
	private function applyDefaultStylesValues(styleDeclaration:CSSStyleDeclaration):Void
	{
		styleDeclaration.setProperty("width", "auto");
		styleDeclaration.setProperty("height", "auto");
	}
	
	private function applyInheritableStyles(node:HTMLElement, styleDeclaration:CSSStyleDeclaration):Void
	{
		
	}
	
}