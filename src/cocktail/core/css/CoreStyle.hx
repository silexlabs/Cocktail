package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CoreStyle extends CSSStyleDeclaration
{
	private var _initialStyleDeclaration:CSSStyleDeclaration;
	
	public function new() 
	{
		
	}
	
	public function cascadeStyles(styleSheetDeclaration:CSSStyleDeclaration, inlineStyleDeclaration:CSSStyleDeclaration, parentCoreStyle:CoreStyle):Void
	{
		for (i in 0..._initialStyleDeclaration.length)
		{
			var propertyName:String = _initialStyleDeclaration.item(i);
			
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
				setStyle(parentCoreStyle.getProperty(propertyName));
			}
			else
			{
				setStyle(_initialStyleDeclaration.getPropertyValue(propertyName));
			}
		}
	}
}