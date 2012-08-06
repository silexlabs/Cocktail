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
	
	private function parseStyle(styles:String, position:Int):Void
	{
		var state:StyleDeclarationParserState = IGNORE_SPACES;
		var next:StyleDeclarationParserState = STYLE_NAME;
		
		var start:Int = position;
		var c:Int = styles.fastCodeAt(position);
		
		var styleName:String = null;
		
		while (true)
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
				
				case STYLE_NAME:
					if (!isStyleNameChar(c))
					{
						switch(c)
						{
							case ':'.code:
								styleName = styles.substr(start, position - start);
								state = IGNORE_SPACES;
								state = STYLE_VALUE;
								
							case ' '.code:
								state = IGNORE_SPACES;
								next = STYLE_NAME;
								
							default:
								state = INVALID_STYLE;
								continue;
						}
						
					}
					
				case STYLE_VALUE:
					position = parseStyleValue(styles, position);
					
				case INVALID_STYLE:	
			}
		}
	}
	
	public function parseStyleValue(styles:String, position:Int):Int
	{
		var c:Int = styles.fastCodeAt(position);
		
		var state:StyleValueParserState = IGNORE_SPACES;
		var next:StyleValueParserState = BEGIN_VALUE;
		var start:Int = position;
		
		var previousStart:Int = 0;
		
		var styleValues:Array<StyleValue> = [];
		
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
				
				case BEGIN_VALUE:
					
					switch(c)
					{
						case ';'.code:
							break;
							
						case '-'.code:
							state = NUMBER_OR_INTEGER;
							start = position;
							continue;
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
					
				case IDENT:
					position = parseIdent(styles, position, styleValues);
					state = IGNORE_SPACES;
					next = BEGIN_VALUE;
					
				case NUMBER_OR_INTEGER:
					position = parseIntegerOrNumber(styles, position, styleValues);
					state = IGNORE_SPACES;
					next = BEGIN_VALUE;
	
			}
			c = styles.fastCodeAt(++position);
		}
		
		trace(styleValues);
		
		return position;
	}
	
	private function parseIntegerOrNumber(styles:String, position:Int, styleValues:Array<StyleValue>):Int
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
					styleValues.push(StyleValue.NUMBER(number));
				}
				else
				{
					var integer:Int = Std.parseInt(styles.substr(start, position - start));
					styleValues.push(StyleValue.INTEGER(integer));
				}
				
			case '%'.code:	
				var numberOrInteger:Float = Std.parseFloat(styles.substr(start, position - start));
				position = parsePercentage(numberOrInteger, styles, position, styleValues);
		}
		
		return position;
	}
	
	private function parseUnit(numberOrInteger:Float, styles:String, position:Int, styleValues:Array<StyleValue>):Int
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
				styleValues.push(StyleValue.LENGTH(Length.px(numberOrInteger)));
				
			case "em":
				styleValues.push(StyleValue.LENGTH(Length.em(numberOrInteger)));
				
			case "ex":
				styleValues.push(StyleValue.LENGTH(Length.ex(numberOrInteger)));	
				
			case "mm":
				styleValues.push(StyleValue.LENGTH(Length.mm(numberOrInteger)));		
				
			case "in":
				styleValues.push(StyleValue.LENGTH(Length.cssIn(numberOrInteger)));	
				
			case "cm":
				styleValues.push(StyleValue.LENGTH(Length.cm(numberOrInteger)));		
				
			case "pc":
				styleValues.push(StyleValue.LENGTH(Length.pc(numberOrInteger)));			
				
			case "pt":
				styleValues.push(StyleValue.LENGTH(Length.pt(numberOrInteger)));
				
			case "deg":
				styleValues.push(StyleValue.ANGLE(Angle.deg(numberOrInteger)));
				
			case "rad":
				styleValues.push(StyleValue.ANGLE(Angle.rad(numberOrInteger)));	
				
			case "grad":
				styleValues.push(StyleValue.ANGLE(Angle.grad(numberOrInteger)));		
				
			case "turn":
				styleValues.push(StyleValue.ANGLE(Angle.turn(numberOrInteger)));	
				
			case "s":
				styleValues.push(StyleValue.TIME(TimeValue.seconds(numberOrInteger)));	
				
			case "ms":
				styleValues.push(StyleValue.TIME(TimeValue.milliSeconds(numberOrInteger)));		
				
		}
		
		return position;
	}
	
	private function parsePercentage(numberOrInteger, styles, position, styleValues):Int
	{
		return position;
	}
	
	private function parseIdent(styles:String, position:Int, styleValues:Array<StyleValue>):Int
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
				styleValues.push(StyleValue.IDENTIFIER(ident));
		}
		
		return position;
	}
	
	private function parseURL(styles:String, position:Int, styleValues:Array<StyleValue>):Int
	{
		return position;
	}
	
	private function parseRGB(styles:String, position:Int, styleValues:Array<StyleValue>):Int
	{
		return position;
	}
	
	static inline function isStyleNameChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || (c >= '0'.code && c <= '9'.code) || c == '-'.code;
	}
	
	static inline function isIdentChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || c == '-'.code;
	}
	
	static inline function isNumChar(c) {
		return (c >= '0'.code && c <= '9'.code);
	}
}