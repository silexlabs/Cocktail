package cocktail.core.css;

import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

 //TODO 1 : should replace style adapter, must add all getter/setter on it
class CSSStyleDeclaration 
{

	public var cssText:String;
	
	public var length(get_length, null):Int;
	
	public var parentRule(default, null):CSSRule;
	
	private var _properties:Array<PropertyDeclarationData>;
	
	public function new(parentRule:CSSRule = null) 
	{
		_properties = new Array<PropertyDeclarationData>();
		this.parentRule = parentRule;
	}
	
	public function item(index:Int):String
	{
		return _properties[index].name;
	}
	
	public function getPropertyValue(property:String):String
	{
		for (i in 0..._properties.length)
		{
			var propertyDeclaration:PropertyDeclarationData = _properties[i];
			if (propertyDeclaration.name == property)
			{
				return propertyDeclaration.value;
			}
		}
		return null;
	}
	
	public function getPropertyPriority(property:String):String
	{
		for (i in 0..._properties.length)
		{
			var propertyDeclaration:PropertyDeclarationData = _properties[i];
			if (propertyDeclaration.name == property)
			{
				return propertyDeclaration.priority;
			}
		}
		
		return null;
	}
	
	public function setProperty(property:String, value:String, priority:String = null):Void
	{
		var newProperties:Array<PropertyDeclarationData> = new Array<PropertyDeclarationData>();
		
		var newProperty:PropertyDeclarationData = {
			name:property,
			value:value,
			priority:priority
		}
		
		var foundMatchingProperty:Bool = false;
		
		for (i in 0..._properties.length)
		{
			var propertyDeclaration:PropertyDeclarationData = _properties[i];
			if (propertyDeclaration.name != property)
			{
				newProperties.push(propertyDeclaration);
			}
			else
			{
				newProperties.push(newProperty);
				foundMatchingProperty = true;
			}
		}
		
		if (foundMatchingProperty == false)
		{
			newProperties.push(newProperty);
		}
		
		_properties = newProperties;
	}
	
	public function removeProperty(property:String):String
	{
		for (i in 0..._properties.length)
		{
			var propertyDeclaration:PropertyDeclarationData = _properties[i];
			
			if (propertyDeclaration.name == property)
			{
				var name:String = propertyDeclaration.name;
				_properties.remove(propertyDeclaration);
				return name;
			}
		}
		
		return null;
	}
	
	private function get_length():Int
	{
		return _properties.length;
	}
	
	private function parseStyle(name:String, value:String):Void
	{
		switch(name)
		{
			case "font-weight":
				
		}
	}
}