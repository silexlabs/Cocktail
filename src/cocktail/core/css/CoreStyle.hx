package cocktail.core.css;

import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CoreStyle extends CSSStyleDeclaration
{
	
	/////////////////////////////////
	// STYLES attributes
	////////////////////////////////
	
	/**
	 * display styles
	 */
	public var display(default, null):CSSPropertyValue;
	public var position(default, null):CSSPropertyValue;
	public var cssFloat(default, null):CSSPropertyValue;
	public var clear(default, null):CSSPropertyValue;
	public var zIndex(default, null):CSSPropertyValue;
	
	/**
	 * box model styles
	 */
	public var marginLeft(default, null):CSSPropertyValue;
	public var marginRight(default, null):CSSPropertyValue;
	public var marginTop(default, null):CSSPropertyValue;
	public var marginBottom(default, null):CSSPropertyValue;
	
	public var paddingLeft(default, null):CSSPropertyValue;
	public var paddingRight(default, null):CSSPropertyValue;
	public var paddingTop(default, null):CSSPropertyValue;
	public var paddingBottom(default, null):CSSPropertyValue;

	public var width(default, null):CSSPropertyValue;
	public var height(default, null):CSSPropertyValue;
	
	public var minHeight(default, null):CSSPropertyValue;
	public var maxHeight(default, null):CSSPropertyValue;
	public var minWidth(default, null):CSSPropertyValue;
	public var maxWidth(default, null):CSSPropertyValue;

	public var top(default, null):CSSPropertyValue;
	public var left(default, null):CSSPropertyValue;
	public var bottom(default, null):CSSPropertyValue;
	public var right(default, null):CSSPropertyValue;
	
	public function new() 
	{
		
	}
	
	public function cascadeStyles(initialStyleDeclaration:CSSStyleDeclaration, styleSheetDeclaration:CSSStyleDeclaration, inlineStyleDeclaration:CSSStyleDeclaration, parentStyleDeclaration:CSSStyleDeclaration):Void
	{
		for (i in 0...initialStyleDeclaration.length)
		{
			var propertyName:String = initialStyleDeclaration.item(i);
			
			if (inlineStyleDeclaration.getPropertyValue(propertyName) != null)
			{
				setStyle(inlineStyleDeclaration.getPropertyValue(propertyName));
			}
			else if (styleSheetDeclaration.getPropertyValue(propertyName) != null)
			{
				setStyle(inlineStyleDeclaration.getPropertyValue(propertyName));
			}
			else if (isInheritable(propertyName) == true)
			{
				setStyle(parentStyleDeclaration.getProperty(propertyName));
			}
			else
			{
				setStyle(_initialStyleDeclaration.getPropertyValue(propertyName));
			}
		}
	}
}