/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
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
	
	public function new(parentRule:CSSRule = null) 
	{
		_properties = new Array<PropertyDeclarationData>();
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
	
	private function parseStyle(styles:String, position:Int):Void
	{
		var state:StyleDeclarationParserState = IGNORE_SPACES;
		var next:StyleDeclarationParserState = BEGIN_STYLE_NAME;
		
		var start:Int = position;
		var c:Int = styles.fastCodeAt(position);
		
		var styleName:String = null;
		
		while (!c.isEOF())
		{	
			switch (state)
			{
				case IGNORE_SPACES:
					switch(c)
					{
						case
							'\n'.code,
							'\r'.code,
							'\t'.code,
							' '.code:
						default:
							state = next;
							continue;
					}
				
				case BEGIN_STYLE_NAME:
					start = position;
					state = STYLE_NAME;
					continue;
					
				case STYLE_NAME:
					if (!isStyleNameChar(c))
					{
						switch(c)
						{
							case ':'.code:
								styleName = styles.substr(start, position - start);
								state = IGNORE_SPACES;
								next = STYLE_VALUE;
								continue;
								
							case ' '.code:
								styleName = styles.substr(start, position - start);
								state = IGNORE_SPACES;
								next = STYLE_SEPARATOR;
								continue;
								
							default:
								state = INVALID_STYLE;
								continue;
						}
					}
					
				case STYLE_SEPARATOR:
					
					if (c == ':'.code)
					{
						state = STYLE_VALUE;
					}
					else
					{
						state = INVALID_STYLE;
						continue;
					}
					
				case STYLE_VALUE:
					position = parseStyleValue(styleName, styles, position);
					state = IGNORE_SPACES;
					next = BEGIN_STYLE_NAME;
					
				case INVALID_STYLE:	
			}
			c = styles.fastCodeAt(++position);
		}
	}
	
	private function parseStyleValue(propertyName:String, styles:String, position:Int):Int
	{
		var c:Int = styles.fastCodeAt(position);
		
		var state:StyleValueParserState = IGNORE_SPACES;
		var next:StyleValueParserState = BEGIN_VALUE;
		var start:Int = position;
		
		var important:Bool = false;
		
		var previousStart:Int = 0;
		
		var styleValues:Array<CSSPropertyValue> = [];
		
		while (!c.isEOF())
		{
			switch(state)
			{
				case IGNORE_SPACES:
					switch(c)
					{
						case
							'\n'.code,
							'\r'.code,
							'\t'.code,
							' '.code:
						default:
							state = next;
							continue;
					}
				
					
				case SPACE_OR_END:
					switch(c)
					{
						case ' '.code:
							state = IGNORE_SPACES;
							next = BEGIN_VALUE;
							
						case ';'.code:
							state = END;
							continue;
							
						default:
							state = INVALID_STYLE_VALUE;
							continue;
					}
				
				case BEGIN_VALUE:
					
					switch(c)
					{
						case ';'.code:
							state = END;
							continue;
							
						case '-'.code:
							state = NUMBER_OR_INTEGER;
							start = position;
							continue;
							
						case '!'.code:
							state = IMPORTANT;
							start = position;
					}
					
					if (isIdentChar(c))
					{
						state = IDENT;
						start = position;
						continue;
					}
					
					if (isNumChar(c))
					{
						state = NUMBER_OR_INTEGER;
						continue;
					}
					
				case END:	
					if (c != ";".code)
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					else
					{
						break;
					}
					
				case IMPORTANT:
					position = parseImportant(styles, position);
					important = true;
					state = IGNORE_SPACES;
					next = END;
					
				case IDENT:
					position = parseIdent(styles, position, styleValues);
					state = SPACE_OR_END;
					
				case NUMBER_OR_INTEGER:
					position = parseIntegerOrNumber(styles, position, styleValues);
					state = SPACE_OR_END;
					
				case INVALID_STYLE_VALUE:
					trace("invalid");
	
			}
			c = styles.fastCodeAt(++position);
		}
		
		applyProperty(propertyName, styleValues);
		
		return position;
	}
	
	private function applyProperty(propertyName:String, styleValues:Array<CSSPropertyValue>):Void
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
						applyProperty('margin-left', [styleValues[0]]);
						applyProperty('margin-right', [styleValues[0]]);
						applyProperty('margin-top', [styleValues[0]]);
						applyProperty('margin-bottom', [styleValues[0]]);
						
					case 2:	
						applyProperty('margin-left', [styleValues[1]]);
						applyProperty('margin-right', [styleValues[1]]);
						applyProperty('margin-top', [styleValues[0]]);
						applyProperty('margin-bottom', [styleValues[0]]);
						
					case 3:	
						applyProperty('margin-left', [styleValues[1]]);
						applyProperty('margin-right', [styleValues[1]]);
						applyProperty('margin-top', [styleValues[0]]);
						applyProperty('margin-bottom', [styleValues[2]]);	
						
					case 4:	
						applyProperty('margin-left', [styleValues[3]]);
						applyProperty('margin-right', [styleValues[1]]);
						applyProperty('margin-top', [styleValues[0]]);
						applyProperty('margin-bottom', [styleValues[2]]);		
				}
		}
	}
	
	private function parseImportant(styles:String, position:Int):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		while (isIdentChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var ident:String = styles.substr(start, position - start);
		if (ident == "important")
		{
			return position;
		}
		return -1;
	}
	
	private function parseIntegerOrNumber(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		var isNumber:Bool = false;
		
		while (isNumChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		if (c == '.'.code)
		{
			c = styles.fastCodeAt(++position);
			isNumber = true;
			while (isNumChar(c))
			{
				c = styles.fastCodeAt(++position);
			}
		}
		
		if (isIdentChar(c))
		{
			var numberOrInteger:Float = Std.parseFloat(styles.substr(start, position - start));
			position = parseUnit(numberOrInteger, styles, position, styleValues);
		}
		
		switch (c)
		{
			case ' '.code, ';'.code:
				if (isNumber)
				{
					var number:Float = Std.parseFloat(styles.substr(start, position - start));
					styleValues.push(CSSPropertyValue.NUMBER(number));
				}
				else
				{
					var integer:Int = Std.parseInt(styles.substr(start, position - start));
					styleValues.push(CSSPropertyValue.INTEGER(integer));
				}
				
			case '%'.code:	
				var numberOrInteger:Float = Std.parseFloat(styles.substr(start, position - start));
				styleValues.push(CSSPropertyValue.PERCENTAGE(numberOrInteger));
				position++;
		}
		
		return --position;
	}
	
	private function parseUnit(numberOrInteger:Float, styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		while (isIdentChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var ident:String = styles.substr(start, position - start);
		
		switch(ident)
		{
			case "px":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.PX(numberOrInteger)));
				
			case "em":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.EM(numberOrInteger)));
				
			case "ex":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.EX(numberOrInteger)));	
				
			case "mm":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.MM(numberOrInteger)));		
				
			case "in":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.IN(numberOrInteger)));	
				
			case "cm":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.CM(numberOrInteger)));		
				
			case "pc":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.PC(numberOrInteger)));			
				
			case "pt":
				styleValues.push(CSSPropertyValue.LENGTH(CSSLengthValue.PT(numberOrInteger)));
				
			case "deg":
				styleValues.push(CSSPropertyValue.ANGLE(CSSAngleValue.DEG(numberOrInteger)));
				
			case "rad":
				styleValues.push(CSSPropertyValue.ANGLE(CSSAngleValue.RAD(numberOrInteger)));	
				
			case "grad":
				styleValues.push(CSSPropertyValue.ANGLE(CSSAngleValue.GRAD(numberOrInteger)));		
				
			case "turn":
				styleValues.push(CSSPropertyValue.ANGLE(CSSAngleValue.TURN(numberOrInteger)));	
				
			case "s":
				styleValues.push(CSSPropertyValue.TIME(CSSTimeValue.SECONDS(numberOrInteger)));	
				
			case "ms":
				styleValues.push(CSSPropertyValue.TIME(CSSTimeValue.MILLISECONDS(numberOrInteger)));		
				
		}
		
		return position;
	}
	
	private function parseIdent(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		while (isIdentChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var ident:String = styles.substr(start, position - start);
		switch(ident)
		{
			case 'url':
				position = parseURL(styles, position, styleValues);
				
			case 'rgb':
				position = parseRGB(styles, position, styleValues);
				
			default:
				styleValues.push(CSSPropertyValue.IDENTIFIER(ident));
		}
		
		return --position;
	}
	
	private function parseURL(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		return position;
	}
	
	private function parseRGB(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		return position;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	static inline function isStyleNameChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code) || c == '-'.code;
	}
	
	static inline function isIdentChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || c == '-'.code;
	}
	
	static inline function isNumChar(c) {
		return (c >= '0'.code && c <= '9'.code);
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
		parseStyle(value, 0);
		return value;
	}
	
}