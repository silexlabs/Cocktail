/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSStyleParser;
import cocktail.core.unit.UnitData;
using StringTools;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

 //TODO 1 : should replace style adapter, must add all getter/setter on it
class CSSStyleDeclaration 
{

	public var cssText(get_cssText, set_cssText):String;
	
	public var length(get_length, null):Int;
	
	public var parentRule(default, null):CSSRule;
	
	private var _properties:Array<PropertyDeclarationData>;
	
	private var _cssStyleParser:CSSStyleParser;
	
	public function new(parentRule:CSSRule = null) 
	{
		_properties = new Array<PropertyDeclarationData>();
		_cssStyleParser = new CSSStyleParser();
		this.parentRule = parentRule;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PARSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function applyProperty(propertyName:String, styleValues:Array<CSSPropertyValue>, important:Bool):Void
	{
		switch(propertyName)
		{
			case 'width':
				if (styleValues.length == 1)
				{
					switch(styleValues[0])
					{
						case CSSPropertyValue.LENGTH(value):
							
						case CSSPropertyValue.INTEGER(value):
							if (value == 0)
							{
								trace(value);
							}
							
						default:	
					}
				}
				
			case 'display':
				if (styleValues.length == 1)
				{
					switch(styleValues[0])
					{
						case CSSPropertyValue.IDENTIFIER(value):
							trace(value);
							switch(value)
							{
								case 'inline':
									
								case 'block':
									
								case 'none':
									
								case 'inline-block':	
							}
							
						default:	
					}
				}
				
			case 'position':
				if (styleValues.length == 1)
				{
					switch(styleValues[0])
					{
						case CSSPropertyValue.IDENTIFIER(value):
							trace(value);
						
							switch(value)
							{
								case 'static':
									
								case 'relative':
									
								case 'absolute':
									
								case 'fixed':	
							}
							
						default:	
					}
				}
				
			case 'font-size':
				if (styleValues.length == 1)
				{
					switch(styleValues[0])
					{
						case CSSPropertyValue.LENGTH(value):
							
						case CSSPropertyValue.PERCENTAGE(value):
							
						case CSSPropertyValue.IDENTIFIER(value):	
							
						default:	
							
					}
				}
				
				
			case 'margin-left':
				if (styleValues.length == 1)
				{
					switch(styleValues[0])
					{
						case CSSPropertyValue.LENGTH(value):
							
						case CSSPropertyValue.PERCENTAGE(value):
							
						case CSSPropertyValue.IDENTIFIER(value):	
							
						default:	
					}
				}
				
			case 'margin':
				switch (styleValues.length)
				{
					case 1:
						applyProperty('margin-left', [styleValues[0]], important);
						applyProperty('margin-right', [styleValues[0]], important);
						applyProperty('margin-top', [styleValues[0]], important);
						applyProperty('margin-bottom', [styleValues[0]], important);
						
					case 2:	
						applyProperty('margin-left', [styleValues[1]], important);
						applyProperty('margin-right', [styleValues[1]], important);
						applyProperty('margin-top', [styleValues[0]], important);
						applyProperty('margin-bottom', [styleValues[0]], important);
						
					case 3:	
						applyProperty('margin-left', [styleValues[1]], important);
						applyProperty('margin-right', [styleValues[1]], important);
						applyProperty('margin-top', [styleValues[0]], important);
						applyProperty('margin-bottom', [styleValues[2]], important);	
						
					case 4:	
						applyProperty('margin-left', [styleValues[3]], important);
						applyProperty('margin-right', [styleValues[1]], important);
						applyProperty('margin-top', [styleValues[0]], important);
						applyProperty('margin-bottom', [styleValues[2]], important);		
				}
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
		_cssStyleParser.parseStyle(value, applyProperty);
		return value;
	}
	
}