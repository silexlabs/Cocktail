/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css.parsers;

import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSParsersData;
using StringTools;

/**
 * This class is a prser whose role is to parse
 * CSS property key/value pair into typed CSS
 * objects.
 * 
 * For instance, it should parse the following value :
	 * 'margin:15px;' into a CSSPropertyValue
 * 
 * @author Yannick DOMINGUEZ
 */

class CSSStyleParser 
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PARSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Parse the whole style declaration, which can contain any number
	 * of css name/value pair. This method parse property names and when
	 * a css separator ":" is found, parse the style value until an
	 * end separator ";" is found
	 */
	public function parseStyle(styles:String):Array<TypedPropertyData>
	{
		//start by ignoring all spaces
		var state:StyleDeclarationParserState = IGNORE_SPACES;
		var next:StyleDeclarationParserState = BEGIN;
		
		//will return all the parsed properties
		var typedProperties:Array<TypedPropertyData> = new Array<TypedPropertyData>();
		
		var position:Int = 0;
		
		var start:Int = position;
		var c:Int = styles.fastCodeAt(position);
		
		//will hold the current css property name
		var styleName:String = null;
			
		while (!c.isEOF())
		{	
			switch (state)
			{
				//ignore all spaces and line feed
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
				
				//start to parse the css property name 
				//at the current position
				case BEGIN:
					//store the start position of the name, will be
					//used when the whole name is parsed
					start = position;
					state = STYLE_NAME;
					continue;
					
				//read style name until a separator charachrter is found	
				case STYLE_NAME:
					if (!isIdentChar(c))
					{
						switch(c)
						{
							//signal that the style value starts
							case ':'.code:
								//style name is now parsed
								styleName = styles.substr(start, position - start);
								state = IGNORE_SPACES;
								next = STYLE_VALUE;
								continue;
							
							//spaces are allowed between a property name and the separator ":"
							case ' '.code:
								styleName = styles.substr(start, position - start);
								state = IGNORE_SPACES;
								next = STYLE_SEPARATOR;
								continue;
							
							//any other charachter between a style name and value makes
							//the style invalid
							default:
								state = INVALID_STYLE;
								continue;
						}
					}
				
				//parse the space between a property name
				//and the style separator ":". Any other charachter
				//make the style invalid
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
					
				//parse the style value, which return the position
				//where the style value ends. store the parsed
				case STYLE_VALUE:
					//typedProperties is passed by reference and filled by the parseStyleValue
					//method if the style value is not invalid
					position = parseStyleValue(styleName, styles, position, typedProperties);
					state = IGNORE_SPACES;
					next = BEGIN;
				
				//if a style is invalid, return no style
				//values
				//
				//TODO 3: eventually will make
				//more robust to error
				case INVALID_STYLE:	
					return [];
			}
			c = styles.fastCodeAt(++position);
		}
		
		//here the whole css string was parsed, all the valid parsed properties
		//are returned
		return typedProperties;
	}
	
	/**
	 * Parse the value of 1 style
	 * 
	 * @param	propertyName the name of the style to 
	 * @param	styles the whole parsed css string, might contain
	 * multiple css name/value properties
	 * @param	position the position where the style value begins
	 * in the parsed css string
	 * @param	typedProperties the typedProperties which will be filled if the style
	 * value is valid
	 * @return	return the position where the style value ended, delimited
	 * by ";"
	 */
	public function parseStyleValue(propertyName:String, styles:String, position:Int, typedProperties:Array<TypedPropertyData>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		
		//increment position if first char is separator
		if (c == ":".code)
		{
			position++;
			c = styles.fastCodeAt(position);
		}
		
		//start by ignoring any initial space, when a charachter
		//other than space is found, start parsing the first component
		//of the style value
		var state:StyleValueParserState = IGNORE_SPACES;
		var next:StyleValueParserState = BEGIN_VALUE;
		
		var start:Int = position;
		
		var important:Bool = false;
		
		var styleValues:Array<CSSPropertyValue> = [];
		var styleValuesLists:Array<Array<CSSPropertyValue>> = [];
		
		
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
				
				//in this state, either the end 
				//of the style value is expected or
				//another component of the style value
				case SPACE_OR_END:
					if (c.isEOF())
					{
						state = END;
						continue;
					}
					else
					{
						switch(c)
						{
							case ' '.code:
								state = IGNORE_SPACES;
								next = BEGIN_VALUE;
								
							case ','.code:
								styleValuesLists.push(styleValues);
								styleValues = [];
								state = IGNORE_SPACES;
								next = BEGIN_VALUE;
								
							case ';'.code:
								state = END;
								continue;
								
							default:
								state = INVALID_STYLE_VALUE;
								continue;
						}
					}
					
				
				//start parsing a value component
				//
				//TODO 1 : add String parsing
				case BEGIN_VALUE:
					
					//try first special value start charachters
					switch(c)
					{
						case ','.code:
							styleValuesLists.push(styleValues);
							styleValues = [];
							state = IGNORE_SPACES;
							next = BEGIN_VALUE;
							continue;
						
						case ';'.code:
							state = END;
							continue;
							
						case '-'.code:
							state = NUMBER_INTEGER_DIMENSION_PERCENTAGE;
							start = position;
							continue;
							
						case '.'.code:
							state = NUMBER_INTEGER_DIMENSION_PERCENTAGE;
							start = position;
							continue;
							
						case '#'.code:
							state = HEXA;
							start = position;
							continue;
							
						case '!'.code:
							state = IMPORTANT;
							start = position;
							continue;
					}
					
					//try a generic identifier
					if (isIdentChar(c))
					{
						state = IDENT;
						start = position;
						continue;
					}
					
					//at last try a number
					if (isNumChar(c))
					{
						state = NUMBER_INTEGER_DIMENSION_PERCENTAGE;
						continue;
					}
					
					//any other value makes the style invalid
					state = INVALID_STYLE_VALUE;
					continue;
					
				//when the end of the style is expected
				//any charachter other than ";" or the end
				//of the string is invalid
				case END:	
					if (c.isEOF())
					{
						break;
					}
					else if (c != ";".code)
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					else
					{
						break;
					}
				
				//parse the "!important" rule
				case IMPORTANT:
					//increment position as first character is "!"
					var endPosition:Int = parseImportant(styles, ++position);
					
					//when important is valid, the style value must
					//end after it, there can't be anymore style
					//components
					if (endPosition != -1)
					{
						position = endPosition;
						important = true;
						state = IGNORE_SPACES;
						next = END;
					}
					//if -1 is returned then the ident wasn't 
					//exactly "!important" which makes the style invalid
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
					
				//parse an hex number	
				case HEXA:
					//increment position as first charachter is '#'
					var endPosition:Int = parseHexaColor(styles, ++position, styleValues);
					
					//check that the hex value is valid
					if (endPosition != -1)
					{
						position = endPosition; 
						state = SPACE_OR_END;
					}
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
					
				case IDENT:
					position = parseIdentOrFunctionnalNotation(styles, position, styleValues);
					state = SPACE_OR_END;
					
				case NUMBER_INTEGER_DIMENSION_PERCENTAGE:
					
					//parse the value, return wether its a valid style component
					var endPosition:Int = parseIntegerNumberDimensionOrPercentage(styles, position, styleValues);
					
					if (endPosition != -1)
					{
						position = endPosition;
						state = SPACE_OR_END;
						continue;
					}
					//if -1 is returned then the value was invalid
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
				//when the style is invalid, return
				//the end position of the invalid style
				//so that if subsequent styles are valid,
				//they can be successfully parsed
				case INVALID_STYLE_VALUE:
					if (c == ";".code)
					{
						return ++position;
					}
	
			}
			c = styles.fastCodeAt(++position);
		}
		
		if (styleValuesLists.length == 0)
		{
			if (styleValues.length == 1)
			{
				typedProperties.push( {
				name:propertyName,
				typedValue:styleValues[0],
				important:important});
			}
			else
			{
				typedProperties.push( {
				name:propertyName,
				typedValue:GROUP(styleValues),
				important:important});
				
			}
		}
		else
		{
			var styleListProperty:Array<CSSPropertyValue> = [];
			
			if (styleValues.length > 0)
			{
				styleValuesLists.push(styleValues);
			}
	
			for (i in 0...styleValuesLists.length)
			{
				if (styleValuesLists[i].length == 1)
				{
					styleListProperty.push(styleValuesLists[i][0]);
				}
				else
				{
					styleListProperty.push(GROUP(styleValuesLists[i]));
				}
			}
			
			typedProperties.push( {
				name:propertyName,
				typedValue:CSS_LIST(styleListProperty),
				important:important});
			
		}
		
		
		
		return position;
	}
	
	

	/**
	 * Expect the "important" ident.
	 * Return the position where "important" end
	 * or -1 to signal that an unexpected ident was parsed
	 */
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
	
	
	/**
	 * Called when a number is expected (when starts with a 0-9 number or minus).
	 * The number might turn out to be a dimension if it is suffixed
	 * with a unit like, 'px' or a percentage if suffixed with '%'
	 */
	private function parseIntegerNumberDimensionOrPercentage(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		//increment is starts with minus
		if (c == '-'.code)
		{
			c = styles.fastCodeAt(++position);
		}
		
		//determine wether it is a floating number or integer.
		//number might start with "." instead of a 0-9 number
		var isNumber:Bool = c == '.'.code;
		
		while (isNumChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		//if the end of the css string is reached and the number
		//didn't start with ".", then it is an integer
		if (c.isEOF() && isNumber == false)
		{
			var integer:Int = Std.parseInt(styles.substr(start, position - start));
			styleValues.push(CSSPropertyValue.INTEGER(integer));
			return position;
		}
		
		//here the number is separated by ".",
		//it is a floating number
		if (c == '.'.code)
		{
			c = styles.fastCodeAt(++position);
			isNumber = true;
			
			while (isNumChar(c))
			{
				c = styles.fastCodeAt(++position);
			}
		}
		
		//store a number if end of css string
		if (c.isEOF())
		{
			var number:Float = Std.parseFloat(styles.substr(start, position - start));
			styleValues.push(CSSPropertyValue.NUMBER(number));
			return position;
		}
		
		//if the number is followed by a letter, then it is a dimension
		if (isIdentChar(c))
		{
			var numberOrInteger:Float = Std.parseFloat(styles.substr(start, position - start));
			position = parseDimension(numberOrInteger, styles, position, styleValues);
		}
		
		//else can be number, integer or percentage
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
			
			//number is a percentage	
			case '%'.code:	
				var numberOrInteger:Float = Std.parseFloat(styles.substr(start, position - start));
				styleValues.push(CSSPropertyValue.PERCENTAGE(numberOrInteger));
				position++;
		}
		
		return position;
	}
	
	/**
	 * parse a dimension by parsing the ident after the number
	 */
	private function parseDimension(numberOrInteger:Float, styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		while (isIdentChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var ident:String = styles.substr(start, position - start);
		
		//check that ident is valid dimension unit, and store it if it is
		switch(ident)
		{
			case "px":
				styleValues.push(LENGTH(PX(numberOrInteger)));
				
			case "em":
				styleValues.push(LENGTH(EM(numberOrInteger)));
				
			case "ex":
				styleValues.push(LENGTH(EX(numberOrInteger)));	
				
			case "mm":
				styleValues.push(LENGTH(MM(numberOrInteger)));		
				
			case "in":
				styleValues.push(LENGTH(IN(numberOrInteger)));	
				
			case "cm":
				styleValues.push(LENGTH(CM(numberOrInteger)));		
				
			case "pc":
				styleValues.push(LENGTH(PC(numberOrInteger)));			
				
			case "pt":
				styleValues.push(LENGTH(PT(numberOrInteger)));
				
			case "deg":
				styleValues.push(ANGLE(DEG(numberOrInteger)));
				
			case "rad":
				styleValues.push(ANGLE(RAD(numberOrInteger)));	
				
			case "grad":
				styleValues.push(ANGLE(GRAD(numberOrInteger)));		
				
			case "turn":
				styleValues.push(ANGLE(TURN(numberOrInteger)));	
				
			case "s":
				styleValues.push(TIME(SECONDS(numberOrInteger)));	
				
			case "ms":
				styleValues.push(TIME(MILLISECONDS(numberOrInteger)));		
				
			case 'Hz':
				styleValues.push(FREQUENCY(HERTZ(numberOrInteger)));
				
			case 'kHz':
				styleValues.push(FREQUENCY(KILO_HERTZ(numberOrInteger)));
				
			case 'dpi':
				styleValues.push(RESOLUTION(DPI(numberOrInteger)));
				
			case 'dpcm':
				styleValues.push(RESOLUTION(DPCM(numberOrInteger)));	
				
			case 'dppx':
				styleValues.push(RESOLUTION(DPPX(numberOrInteger)));	
				
			//if it's not a valid unit, signal that it is an invalid 
			//style value
			default:
				return -1;
				
		}
		
		return position;
	}
	
	private function parseIdentOrFunctionnalNotation(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		while (isIdentChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var ident:String = styles.substr(start, position - start);
		
		switch(c)
		{
			case '('.code:
				position = parseFunctionnalNotation(ident, styles, ++position, styleValues);
				
			default:	
				parseIdent(ident, styleValues);
		}
		
		return --position;
	}
	
	private function parseHexaColor(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start:Int = position;
		
		while (isHexaChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var hexa:String = styles.substr(start, position - start);
		
		if (hexa.length == 3 || hexa.length == 6)
		{
			styleValues.push(CSSPropertyValue.COLOR(CSSColorValue.HEX(hexa)));
			return --position;
		}
		
		return -1;
		
	}
	
	private function parseFunctionnalNotation(ident:String, styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		switch(ident)
		{
			case 'url':
				position = parseURL(styles, position, styleValues);
				
			case 'rgb':
				position = parseRGB(styles, position, styleValues);
		}
		
		return position;
	}
	
	
	
	private function parseURL(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		
		var c:Int = styles.fastCodeAt(position);
		
		switch(c)
		{
			case '"'.code, "'".code:
				++position;
				c = styles.fastCodeAt(position);
		}

		var start = position;
		
		while (c != ')'.code && c != '"'.code && c != "'".code)
		{
			if (c.isEOF())
			{
				return position;
			}
			c = styles.fastCodeAt(++position);
		}
		
		styleValues.push(CSSPropertyValue.URL(styles.substr(start, position - start)));
		
		return ++position;
	}
	
	private function parseRGB(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		return position;
	}
	
	
	/**
	 * Try to match an identifier to a CSS value
	 */
	private function parseIdent(ident:String, styleValues:Array<CSSPropertyValue>):Void
	{
		switch(ident)
		{
			case 'inherit':
				styleValues.push(CSSPropertyValue.INHERIT);
				
			case 'initial':
				styleValues.push(CSSPropertyValue.INITIAL);
				
			default:
				parseKeyword(ident, styleValues);
		}
	}
	
	/**
	 * Try to find a CSS keyword or color keyword from an identifier.
	 * If no match is found, a generic Identifier will be stored
	 */
	private function parseKeyword(ident:String, styleValues:Array<CSSPropertyValue>):Void
	{
		var cssPropertyValue:CSSPropertyValue = IDENTIFIER(ident);
		
		switch (ident)
		{
			case 'normal':
				cssPropertyValue = KEYWORD(NORMAL);
				
			case 'bold':
				cssPropertyValue = KEYWORD(BOLD);
				
			case 'bolder':
				cssPropertyValue = KEYWORD(BOLDER);
				
			case 'lighter':
				cssPropertyValue = KEYWORD(LIGHTER);
				
			case 'oblique':
				cssPropertyValue = KEYWORD(OBLIQUE);
				
			case 'italic':
				cssPropertyValue = KEYWORD(ITALIC);
				
			case 'small-caps':
				cssPropertyValue = KEYWORD(SMALL_CAPS);
				
			case 'pre':
				cssPropertyValue = KEYWORD(PRE);
				
			case 'no-wrap':
				cssPropertyValue = KEYWORD(NO_WRAP);	
				
			case 'pre-wrap':
				cssPropertyValue = KEYWORD(PRE_WRAP);
				
			case 'pre-line':
				cssPropertyValue = KEYWORD(PRE_LINE);
				
			case 'left':
				cssPropertyValue = KEYWORD(LEFT);	
				
			case 'right':
				cssPropertyValue = KEYWORD(RIGHT);
				
			case 'center':
				cssPropertyValue = KEYWORD(CENTER);	
				
			case 'justify':
				cssPropertyValue = KEYWORD(JUSTIFY);	
				
			case 'capitalize':
				cssPropertyValue = KEYWORD(CAPITALIZE);	
				
			case 'uppercase':
				cssPropertyValue = KEYWORD(UPPERCASE);
				
			case 'lowercase':
				cssPropertyValue = KEYWORD(LOWERCASE);
				
			case 'none':
				cssPropertyValue = KEYWORD(NONE);
				
			case 'baseline':
				cssPropertyValue = KEYWORD(BASELINE);
				
			case 'sub':
				cssPropertyValue = KEYWORD(SUB);
				
			case 'super':
				cssPropertyValue = KEYWORD(SUPER);
			
			case 'top':
				cssPropertyValue = KEYWORD(TOP);	
				
			case 'text-top':
				cssPropertyValue = KEYWORD(TEXT_TOP);
				
			case 'middle':
				cssPropertyValue = KEYWORD(MIDDLE);
				
			case 'bottom':
				cssPropertyValue = KEYWORD(BOTTOM);
				
			case 'text-bottom':
				cssPropertyValue = KEYWORD(TEXT_BOTTOM);
				
			case 'auto':
				cssPropertyValue = KEYWORD(AUTO);
				
			case 'block':
				cssPropertyValue = KEYWORD(BLOCK);
				
			case 'inline-block':
				cssPropertyValue = KEYWORD(INLINE_BLOCK);	
				
			case 'inline':
				cssPropertyValue = KEYWORD(INLINE);
				
			case 'both':
				cssPropertyValue = KEYWORD(BOTH);
				
			case 'static':
				cssPropertyValue = KEYWORD(STATIC);
				
			case 'relative':
				cssPropertyValue = KEYWORD(RELATIVE);
				
			case 'absolute':
				cssPropertyValue = KEYWORD(ABSOLUTE);
				
			case 'fixed':
				cssPropertyValue = KEYWORD(FIXED);
				
			case 'visible':
				cssPropertyValue = KEYWORD(VISIBLE);
				
			case 'hidden':
				cssPropertyValue = KEYWORD(HIDDEN);
				
			case 'scroll':
				cssPropertyValue = KEYWORD(SCROLL);
				
			case 'border-box':
				cssPropertyValue = KEYWORD(BORDER_BOX);
				
			case 'padding-box':
				cssPropertyValue = KEYWORD(PADDING_BOX);
				
			case 'content-box':
				cssPropertyValue = KEYWORD(CONTENT_BOX);	
				
			case 'contain':
				cssPropertyValue = KEYWORD(CONTAIN);
				
			case 'cover':
				cssPropertyValue = KEYWORD(COVER);
				
			case 'crosshair':
				cssPropertyValue = KEYWORD(CROSSHAIR);
				
			case 'default':
				cssPropertyValue = KEYWORD(DEFAULT);
				
			case 'pointer':
				cssPropertyValue = KEYWORD(POINTER);
				
			case 'text':
				cssPropertyValue = KEYWORD(TEXT);
				
			case 'all':
				cssPropertyValue = KEYWORD(ALL);
				
			case 'ease':
				cssPropertyValue = KEYWORD(EASE);
				
			case 'linear':
				cssPropertyValue = KEYWORD(LINEAR);
				
			case 'ease-in':
				cssPropertyValue = KEYWORD(EASE_IN);	
				
			case 'ease-out':
				cssPropertyValue = KEYWORD(EASE_OUT);
				
			case 'ease-in-out':
				cssPropertyValue = KEYWORD(EASE_IN_OUT);
				
			case 'step-start':
				cssPropertyValue = KEYWORD(STEP_START);		
				
			case 'step-end':
				cssPropertyValue = KEYWORD(STEP_END);	
				
			case 'start':
				cssPropertyValue = KEYWORD(START);
				
			case 'end':
				cssPropertyValue = KEYWORD(END);
				
			case 'x-small':
				cssPropertyValue = KEYWORD(X_SMALL);
				
			case 'xx-small':
				cssPropertyValue = KEYWORD(XX_SMALL);
				
			case 'x-large':
				cssPropertyValue = KEYWORD(X_LARGE);
				
			case 'xx-large':
				cssPropertyValue = KEYWORD(XX_LARGE);
				
			case 'medium':
				cssPropertyValue = KEYWORD(MEDIUM);
				
			case 'smaller':
				cssPropertyValue = KEYWORD(SMALLER);
				
			case 'larger':
				cssPropertyValue = KEYWORD(LARGER);
				
			case 'space':
				cssPropertyValue = KEYWORD(SPACE);
				
			case 'round':
				cssPropertyValue = KEYWORD(ROUND);
				
			case 'large':
				cssPropertyValue = KEYWORD(LARGE);
				
			case 'small':
				cssPropertyValue = KEYWORD(SMALL);
				
			case 'repeat-x':
				cssPropertyValue = KEYWORD(REPEAT_X);
				
			case 'repeat-y':
				cssPropertyValue = KEYWORD(REPEAT_Y);
				
			case 'no-repeat':
				cssPropertyValue = KEYWORD(NO_REPEAT);
				
			case 'repeat':
				cssPropertyValue = KEYWORD(REPEAT);
				
			case 'transparent':
				cssPropertyValue = COLOR(TRANSPARENT);
				
			case 'aqua':
				cssPropertyValue = COLOR(KEYWORD(AQUA));
				
			case 'blue':
				cssPropertyValue = COLOR(KEYWORD(BLUE));
				
			case 'black':
				cssPropertyValue = COLOR(KEYWORD(BLACK));	
				
			case 'silver':
				cssPropertyValue = COLOR(KEYWORD(SILVER));	
				
			case 'gray':
				cssPropertyValue = COLOR(KEYWORD(GRAY));	
				
			case 'white':
				cssPropertyValue = COLOR(KEYWORD(WHITE));	
				
			case 'maroon':
				cssPropertyValue = COLOR(KEYWORD(MAROON));	
				
			case 'red':
				cssPropertyValue = COLOR(KEYWORD(RED));		
				
			case 'purple':
				cssPropertyValue = COLOR(KEYWORD(PURPLE));	
				
			case 'fuchsia':
				cssPropertyValue = COLOR(KEYWORD(FUSHIA));		
				
			case 'green':
				cssPropertyValue = COLOR(KEYWORD(GREEN));	
				
			case 'lime':
				cssPropertyValue = COLOR(KEYWORD(LIME));
				
			case 'olive':
				cssPropertyValue = COLOR(KEYWORD(OLIVE));		
				
			case 'yellow':
				cssPropertyValue = COLOR(KEYWORD(YELLOW));	
				
			case 'navy':
				cssPropertyValue = COLOR(KEYWORD(NAVY));
				
			case 'orange':
				cssPropertyValue = COLOR(KEYWORD(ORANGE));
				
			case 'teal':
				cssPropertyValue = COLOR(KEYWORD(TEAL));
		}
		
		styleValues.push(cssPropertyValue);
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	static inline function isHexaChar(c) {
		return (c >= 'a'.code && c <= 'f'.code) || (c >= 'A'.code && c <= 'F'.code) || (c >= '0'.code && c <= '9'.code);
	}
	
	static inline function isIdentChar(c) {
		return (c >= 'a'.code && c <= 'z'.code) || (c >= 'A'.code && c <= 'Z'.code) || c == '-'.code;
	}
	
	static inline function isNumChar(c) {
		return (c >= '0'.code && c <= '9'.code);
	}
	
}