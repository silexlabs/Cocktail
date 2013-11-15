/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css.parsers;

import cocktail.core.css.CSSConstants;
import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSParsersData;
import cocktail.core.url.URL;
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
	 * when parsing a css style declaration 
	 * with multiple key/value css styles, hold
	 * the current parsing position
	 */
	private static var _position:Int = 0;
	
	/**
	 * When parsing, holds all the resulting
	 * typed properties objects
	 */
	private static var _typedProperties:Array<TypedPropertyVO>;
	
	/**
	 * class constructor
	 */
	private function new() 
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
	 * 
	 * @param styles the CSS style string
	 * @param baseURL base url of the css stylesheet, if any or null (styles might be provided
	 * by inline style tag)
	 */
	public static function parseStyle(styles:String, baseURL:String):Array<TypedPropertyVO>
	{
		//reset the position when parsing multiple styles
		_position = 0;
		
		//start by ignoring all spaces
		var state:StyleDeclarationParserState = IGNORE_SPACES;
		var next:StyleDeclarationParserState = BEGIN;
		
		//init and reset returned array
		if (_typedProperties == null)
		{
			_typedProperties = new Array<TypedPropertyVO>();
		}
		_typedProperties = [];
		
		//will return all the parsed properties
		var typedProperties:Array<TypedPropertyVO> = _typedProperties;
		
		var position:Int = 0;
		
		var start:Int = position;
		var c:Int = styles.fastCodeAt(position);
		
		//will hold the current css property name
		var styleName:String = null;
			
		while (!StringTools.isEof(c))
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
				
				//start to parse the css
				//at the current position,
				//expect either a css propery name
				//or the start of a comment
				case BEGIN:
					switch(c)
					{
						//begin comment, content is ignored until comment
						//end
						case '/'.code:
							state = BEGIN_COMMENT;
							
						default:	
							//store the start position of the name, will be
							//used when the whole name is parsed
							start = position;
							state = STYLE_NAME;
							continue;
					}
				
				//check validity of comment	
				case BEGIN_COMMENT:
					if (c != '*'.code)
					{
						state = INVALID_STYLE;
					}
					else
					{
						state = COMMENT;
					}
				
				//content ignored until end of comment	
				case COMMENT:
					if (c == '*'.code)
					{
						state = END_COMMENT;
					}
				
				//check validity of comment end	
				case END_COMMENT:
					if (c == '/'.code)
					{
						//re-start checking for stylname
						//or comment
						state = IGNORE_SPACES;
						next = BEGIN;
					}
					else
					{
						state = INVALID_STYLE;
					}
					
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
					//parse the property value,null is returned if the property is invalid
					var typedProperty:TypedPropertyVO = parseStyleValue(styleName, styles, position, baseURL);
					
					//global position was updated in the parseStyleValue
					//to correspond to the end of the style value, separated
					//by ";" or the end of string
					position = _position;
					
					if (typedProperty != null)
					{
						typedProperties.push(typedProperty);
					}
					
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
	 * @param	propertyName the name of the style to  parse
	 * @param	styles the whole parsed css string, might contain
	 * multiple css name/value properties
	 * @param	position the position where the style value begins
	 * in the parsed css string
	 * @param	baseURL the url of the CSS stylesheet where the style value originates,
	 * or null or if doesn't come from a CSS stylesheet. Used for style value pointing
	 * to a url to make the url relative to the document instead of the stylesheet
	 * @return the typed property resulting from the parsing or null
	 * if the style was invalid
	 */
	public static function parseStyleValue(propertyName:String, styles:String, position:Int, baseURL:String):TypedPropertyVO
	{
		var c:Int = styles.fastCodeAt(position);
		
		//increment position if first char is separator
		if (c == ":".code)
		{
			++position;
			c = styles.fastCodeAt(position);
		}
		
		//start by ignoring any initial space, when a charachter
		//other than space is found, start parsing the first component
		//of the style value
		var state:StyleValueParserState = IGNORE_SPACES;
		var next:StyleValueParserState = BEGIN_VALUE;
		
		var start:Int = position;
		
		//will return wether the style is declared important with "!important" token
		var important:Bool = false;
		
		//hold the value of the currently parsed group of style component
		//which are space separated
		var styleValues:Array<CSSPropertyValue> = [];
		
		//hold the value of each item of the list of style values which
		//are comma separated
		var styleValuesLists:Array<Array<CSSPropertyValue>> = [];
		
		//hold the value of each item of the font notation, for
		//font-size and line height, like '12px/120%'. Can contain
		//only 2 items else style is invalid
		var fontNotations:Array<CSSPropertyValue> = [];
		
		while (!StringTools.isEof(c))
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
				case COMPONENT_OR_END:
					
					if (StringTools.isEof(c))
					{
						state = END;
						continue;
					}
					//there can only be 2 items for font notation, if 2
					//slashes are found in a row, style is invalid
					else if (c == '/'.code && fontNotations.length > 0)
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					else
					{
						//if last value was first part of font notation
						//store font notation
						if (fontNotations.length == 1)
						{
							fontNotations.push(styleValues.pop());
							styleValues.push(FONT_SIZE_LINE_HEIGHT_GROUP(fontNotations[0], fontNotations[1]));
							fontNotations = [];
						}
								
						switch(c)
						{
							case ' '.code:
								state = IGNORE_SPACES;
								next = BEGIN_VALUE;
							
							//a comma signals a list of values, push
							//the current value in the list value array
							case ','.code:
								styleValuesLists.push(styleValues);
								styleValues = [];
								state = IGNORE_SPACES;
								next = BEGIN_VALUE;
							
							//a slash signals a font notation	
							case '/'.code:
								
								//the font notation can only happen for
								//a 'font' style shorthand, else the style
								//is invalid
								if (propertyName == CSSConstants.FONT_NAME)
								{
									//get the last style value which is the
									//first component of the font notation
									fontNotations.push(styleValues.pop());
									
									state = IGNORE_SPACES;
									next = BEGIN_VALUE;
								}
								else
								{
									state = INVALID_STYLE_VALUE;
									continue;
								}
								
								
							case ';'.code:
								state = END;
								continue;
								
							default:
								state = INVALID_STYLE_VALUE;
								continue;
						}
					}
				
				//start parsing a value component
				case BEGIN_VALUE:
					
					//try first special value start charachters
					switch(c)
					{
						//TODO 3 : duplicated code
						case ','.code:
							styleValuesLists.push(styleValues);
							styleValues = [];
							state = IGNORE_SPACES;
							next = BEGIN_VALUE;
							
							c = styles.fastCodeAt(++position);
							continue;
						
						case ';'.code:
							state = END;
							continue;
							
						case '-'.code, '+'.code, '.'.code:
							state = NUMBER_INTEGER_DIMENSION_PERCENTAGE;
							start = position;
							continue;
							
						case '#'.code:
							state = HEX;
							start = position;
							continue;
							
						case '!'.code:
							state = IMPORTANT;
							start = position;
							continue;
							
						case '"'.code, "'".code:
							state = STRING;
							start = position;
							continue;
					}
					
					//try a generic identifier
					if (isIdentChar(c))
					{
						state = IDENT_FUNCTION;
						start = position;
						continue;
					}
					
					//at last try a number
					if (isNumChar(c))
					{
						state = NUMBER_INTEGER_DIMENSION_PERCENTAGE;
						start = position;
						continue;
					}
					
					//any other value makes the style invalid
					state = INVALID_STYLE_VALUE;
					continue;
					
				//when the end of the style is expected
				//any charachter other than ";" or the end
				//of the string is invalid
				case END:	
					if (StringTools.isEof(c))
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
						c = styles.fastCodeAt(position);
						important = true;
						state = IGNORE_SPACES;
						next = END;
						continue;
					}
					//if -1 is returned then the ident wasn't 
					//exactly "!important" which makes the style invalid
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
					
				//parse an hex number	
				case HEX:
					//increment position as first charachter is '#'
					var endPosition:Int = parseHexaColor(styles, ++position, styleValues);
					
					//check that the hex value is valid
					if (endPosition != -1)
					{
						position = endPosition; 
						state = COMPONENT_OR_END;
					}
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
					
				case STRING:
					var endPosition:Int = parseString(styles, position, styleValues);
					
					if (endPosition != -1)
					{
						position = endPosition;
						c = styles.fastCodeAt(position);
						
						state = COMPONENT_OR_END;
						continue;
					}
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
				case IDENT_FUNCTION:
					var endPosition:Int = parseIdentOrFunctionnalNotation(styles, position, styleValues, baseURL);
					
					//if different from -1, style value is valid
					if (endPosition != -1)
					{
						position = endPosition;
						c = styles.fastCodeAt(position);
						
						state = COMPONENT_OR_END;
						continue;
					}
					else
					{
						state = INVALID_STYLE_VALUE;
						continue;
					}
					
				case NUMBER_INTEGER_DIMENSION_PERCENTAGE:
					
					//parse the value, return wether its a valid style component
					var endPosition:Int = parseIntegerNumberDimensionOrPercentage(styles, position, styleValues);
					
					if (endPosition != -1)
					{
						//update position of current char
						position = endPosition;
						c = styles.fastCodeAt(position);
					
						state = COMPONENT_OR_END;
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
						//increment the global position, so that
						//further style might be parsed
						_position = ++position;
						return null;
					}
	
			}
			c = styles.fastCodeAt(++position);
		}
		
		//increment global position, so that further
		//styles can be parsed
		_position = position;
		
		//flush font notation if needed
		if (fontNotations.length == 1)
		{
			fontNotations.push(styleValues.pop());
			styleValues.push(FONT_SIZE_LINE_HEIGHT_GROUP(fontNotations[0], fontNotations[1]));
			fontNotations = [];
		}
		
		//if there is no list of styles
		if (styleValuesLists.length == 0)
		{
			//and no group of styles either
			if (styleValues.length == 1)
			{
				var typedProperty:TypedPropertyVO = new TypedPropertyVO();
				typedProperty.important = important;
				typedProperty.index = CSSConstants.getPropertyIndexFromName(propertyName);
				typedProperty.typedValue = styleValues[0];
				return typedProperty;
			}
			//else group the style values
			else
			{
				var typedProperty:TypedPropertyVO = new TypedPropertyVO();
				typedProperty.important = important;
				typedProperty.index = CSSConstants.getPropertyIndexFromName(propertyName);
				typedProperty.typedValue = GROUP(styleValues);
				return typedProperty;
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
			
			var typedProperty:TypedPropertyVO = new TypedPropertyVO();
			typedProperty.important = important;
			typedProperty.index = CSSConstants.getPropertyIndexFromName(propertyName);
			typedProperty.typedValue = CSS_LIST(styleListProperty);
			
			return typedProperty;
		}
	}
	
	

	/**
	 * Expect the "important" ident.
	 * Return the position where "important" end
	 * or -1 to signal that an unexpected ident was parsed
	 */
	private static function parseImportant(styles:String, position:Int):Int
	{
		var c:Int = styles.fastCodeAt(position);
		
		//spaces are accepted between "!" and "important"
		while (c == " ".code)
		{
			c = styles.fastCodeAt(++position);
		}
		
		var start:Int = position;
		while (isIdentChar(c))
		{
			c = styles.fastCodeAt(++position);
		}
		
		var ident:String = styles.substr(start, position - start);
		
		if (ident == CSSConstants.IMPORTANT)
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
	private static function parseIntegerNumberDimensionOrPercentage(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start = position;
		
		//increment if starts with minus or plus sign
		if (c == '-'.code || c == "+".code)
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
		if (StringTools.isEof(c) && isNumber == false)
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
		if (StringTools.isEof(c))
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
		else
		{
			//else can be number, integer or percentage
			switch (c)
			{
				//number is a percentage	
				case '%'.code:	
					var numberOrInteger:Float = Std.parseFloat(styles.substr(start, position - start));
					styleValues.push(CSSPropertyValue.PERCENTAGE(numberOrInteger));
					++position;
					
				default:
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
			}
		}
		
		
		return position;
	}
	
	/**
	 * parse a dimension by parsing the ident after the number
	 */
	private static function parseDimension(numberOrInteger:Float, styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
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
				
			case "ch":
				styleValues.push(LENGTH(CH(numberOrInteger)));	
				
			case "rem":
				styleValues.push(LENGTH(REM(numberOrInteger)));		
				
			case "vh":
				styleValues.push(LENGTH(VH(numberOrInteger)));	
				
			case "vw":
				styleValues.push(LENGTH(VW(numberOrInteger)));			
				
			case "vmin":
				styleValues.push(LENGTH(VMIN(numberOrInteger)));			
				
			case "vmax":
				styleValues.push(LENGTH(VMAX(numberOrInteger)));			
				
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
	
	private static function parseString(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
	{
		var quote:Int = styles.fastCodeAt(position);
		
		var start:Int = ++position;
		var c:Int = styles.fastCodeAt(position);
		
		while (c != quote)
		{
			if (StringTools.isEof(c))
			{
				return -1;
			}
			c = styles.fastCodeAt(++position);
		}
		
		var stringValue:String = styles.substr(start, position - start);
		
		styleValues.push(STRING(stringValue));
		
		return ++position;
	}
	
	
	private static function parseIdentOrFunctionnalNotation(styles:String, position:Int, styleValues:Array<CSSPropertyValue>, baseURL:String):Int
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
				position = parseFunctionnalNotation(ident, styles, ++position, styleValues, baseURL);
				
			default:	
				parseIdent(ident, styleValues);
		}
		
		return position;
	}
	
	private static function parseHexaColor(styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
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
	
	/**
	 * parse css functional notation, like : url(myurl) or rgb(red,green,blue)
	 */
	private static function parseFunctionnalNotation(ident:String, styles:String, position:Int, styleValues:Array<CSSPropertyValue>, baseURL:String):Int
	{
		var c:Int = styles.fastCodeAt(position);
		var start:Int = position;
		
		while (c != ')'.code)
		{
			if (StringTools.isEof(c))
			{
				return -1;
			}
			c = styles.fastCodeAt(++position);
		}
		

		
		var cssFunction:String = styles.substr(start, position - start);
		
		//add quote to url if forgotten by author, url are
		//parsed as string instead of indent to allow any charachter
		if (ident == 'url')
		{
			if (cssFunction.charAt(0) != "'" && cssFunction.charAt(0) != '"')
			{
				cssFunction = "'" + cssFunction + "'";
			}
		}
		
		
		var functionValues:TypedPropertyVO = parseStyleValue("", cssFunction, 0, baseURL);
		
		var functionValue:CSSPropertyValue = getFunctionalNotation(ident, functionValues.typedValue, baseURL);
		
		if (functionValue == null)
		{
			return -1;
		}
		else
		{
			styleValues.push(functionValue);
			return ++position;
		}
		
	}
	
	/**
	 * parse a CSS functionnal notation (an ident preceding a parenthesis)
	 * @return null if invalid
	 */
	private static function getFunctionalNotation(name:String, value:CSSPropertyValue, baseURL:String):CSSPropertyValue
	{
		switch (name)
		{
			case 'rgb':
				return parseRGBOrRGBA(value, false);
			
			case 'rgba':
				return parseRGBOrRGBA(value, true);
				
			case 'url':
				switch(value)
				{

					case IDENTIFIER(value):
						return CSSPropertyValue.URL(getURLRelativeToDocument(value, baseURL));
					case STRING(value):	
						return CSSPropertyValue.URL(getURLRelativeToDocument(value, baseURL));
						
					default:	
						return null;
				}
			
			//CSS TRANSFORMS
			
			case 'matrix':
				switch(value)
				{
					case CSS_LIST(value):
						if (value.length == 6)
						{
							var matrixNumbers:Array<Float> = new Array<Float>();
							
							for (i in 0...value.length)
							{
								switch(value[i])
								{
									case NUMBER(value):
										matrixNumbers.push(value);
										
									case INTEGER(value):
										matrixNumbers.push(value);
										
									default:
										return null;
								}
							}
							
							return TRANSFORM_FUNCTION(MATRIX(matrixNumbers[0], matrixNumbers[1], matrixNumbers[2], matrixNumbers[3], matrixNumbers[4], matrixNumbers[5]));
						}
						
					default:	
				}
			
			case 'rotate':
				switch(value)
				{
					case ANGLE(value):
						return CSSPropertyValue.TRANSFORM_FUNCTION(CSSTransformFunctionValue.ROTATE(value));
						
					default:	
				}
				
			case 'scaleX':
				switch(value)
				{
					case NUMBER(value):
						return CSSPropertyValue.TRANSFORM_FUNCTION(CSSTransformFunctionValue.SCALE_X(value));
						
					case INTEGER(value):
						return CSSPropertyValue.TRANSFORM_FUNCTION(CSSTransformFunctionValue.SCALE_X(value));
						
					default:	
						
				}
			
			case 'scaleY':
				switch(value)
				{
					case NUMBER(value):
						return CSSPropertyValue.TRANSFORM_FUNCTION(CSSTransformFunctionValue.SCALE_Y(value));
						
					case INTEGER(value):
						return CSSPropertyValue.TRANSFORM_FUNCTION(CSSTransformFunctionValue.SCALE_Y(value));
						
					default:	
						
				}	
				
			case 'scale':
				switch(value)
				{
					case NUMBER(value):
						return TRANSFORM_FUNCTION(SCALE(value, value));
						
					case INTEGER(value):
						return TRANSFORM_FUNCTION(SCALE(value, value));
						
					case CSS_LIST(value):
						if (value.length == 2)
						{
							var scaleX:Float = 0.0;
							var scaleY:Float = 0.0;
							switch(value[0])
							{
								case NUMBER(value):
									scaleX = value;
									
								case INTEGER(value):
									scaleX = value;
								
								//invalid scale declarations	
								default:
									return null;
							}
							
							switch(value[1])
							{
								case NUMBER(value):
									scaleY = value;
									
								case INTEGER(value):
									scaleY = value;
								
								//invalid scale declarations	
								default:
									return null;
							}
							
							return TRANSFORM_FUNCTION(SCALE(scaleX, scaleY));
						}
						
					default:	
				}
				
			case 'skew':
				switch(value)
				{
					case ANGLE(value):
						return TRANSFORM_FUNCTION(SKEW(value, value));
					
					case CSS_LIST(value):
						if (value.length == 2)
						{
							var skewX:CSSAngleValue = null;
							var skewY:CSSAngleValue = null;
							
							switch(value[0])
							{
								case ANGLE(value):
									skewX = value;
									
								default:
									return null;
							}
							
							switch(value[1])
							{
								case ANGLE(value):
									skewY = value;
									
								default:
									return null;
							}
							
							return TRANSFORM_FUNCTION(SKEW(skewX, skewY));
						}
						
					default:	
				}
				
			case 'skewX':
				switch(value)
				{
					case ANGLE(value):
						return TRANSFORM_FUNCTION(CSSTransformFunctionValue.SKEW_X(value));
						
					default:	
						
				}		
				
			case 'skewY':
				switch(value)
				{
					case ANGLE(value):
						return TRANSFORM_FUNCTION(CSSTransformFunctionValue.SKEW_Y(value));
						
					default:	
						
				}			
				
			case 'translateX':
				switch(value)
				{
					case ABSOLUTE_LENGTH(value):
						return TRANSFORM_FUNCTION(TRANSLATE_X(CSSTranslationValue.ABSOLUTE_LENGTH(value)));
						
					case PERCENTAGE(value):
						return TRANSFORM_FUNCTION(TRANSLATE_X(CSSTranslationValue.PERCENTAGE(value)));
						
					case LENGTH(value):
						return TRANSFORM_FUNCTION(TRANSLATE_X(CSSTranslationValue.LENGTH(value)));	
						
					default:	
				}
				
			case 'translateY':
				switch(value)
				{
					case ABSOLUTE_LENGTH(value):
						return TRANSFORM_FUNCTION(TRANSLATE_Y(CSSTranslationValue.ABSOLUTE_LENGTH(value)));
						
					case PERCENTAGE(value):
						return TRANSFORM_FUNCTION(TRANSLATE_Y(CSSTranslationValue.PERCENTAGE(value)));
						
					case LENGTH(value):
						return TRANSFORM_FUNCTION(TRANSLATE_Y(CSSTranslationValue.LENGTH(value)));	
						
					default:	
				}	
				
			case 'translate':
				switch(value)
				{
					case ABSOLUTE_LENGTH(value):
						return TRANSFORM_FUNCTION(TRANSLATE(CSSTranslationValue.ABSOLUTE_LENGTH(value), CSSTranslationValue.ABSOLUTE_LENGTH(value)));
						
					case PERCENTAGE(value):
						return TRANSFORM_FUNCTION(TRANSLATE(CSSTranslationValue.PERCENTAGE(value), CSSTranslationValue.PERCENTAGE(value)));
						
					case LENGTH(value):
						return TRANSFORM_FUNCTION(TRANSLATE(CSSTranslationValue.LENGTH(value), CSSTranslationValue.LENGTH(value)));
						
					case CSS_LIST(value):
						
						var translateX:CSSTranslationValue = null;
						var translateY:CSSTranslationValue = null;
						
						if (value.length == 2)
						{
							switch(value[0])
							{
								case ABSOLUTE_LENGTH(value):
									translateX = CSSTranslationValue.ABSOLUTE_LENGTH(value);
									
								case PERCENTAGE(value):
									translateX = CSSTranslationValue.PERCENTAGE(value);
									
								case LENGTH(value):
									translateX = CSSTranslationValue.LENGTH(value);
									
								default:
									return null;
							}
							
							switch(value[1])
							{
								case ABSOLUTE_LENGTH(value):
									translateY = CSSTranslationValue.ABSOLUTE_LENGTH(value);
									
								case PERCENTAGE(value):
									translateY = CSSTranslationValue.PERCENTAGE(value);
									
								case LENGTH(value):
									translateY = CSSTranslationValue.LENGTH(value);
									
								default:
									return null;	
							}
							
							return TRANSFORM_FUNCTION(TRANSLATE(translateX, translateY));
						}
					
					default:	
				}		
				
				
				
			default:
		}
		
		return null;
	}
	
	private static function parseRGBOrRGBA(property:CSSPropertyValue, isRGBA:Bool):CSSPropertyValue
	{
		switch(property)
		{
			case CSS_LIST(value):
				
				if (isRGBA == true)
				{
					if (value.length != 4)
					{
						return null;
					}
				}
				else
				{
					if (value.length != 3)
					{
						return null;
					}
				}
				
				
				var isPercentRGB:Bool = false;
				var red:Int = 0;
				var green:Int = 0;
				var blue:Int = 0;
				
				var percentRed:Float = 0.0;
				var percentGreen:Float = 0.0;
				var percentBlue:Float = 0.0;
				
				switch(value[0])
				{
					case INTEGER(value):
						red = value;
						
					case PERCENTAGE(value):	
						percentRed = value;
						isPercentRGB = true;
						
					default:
						return null;
				}
				
				switch(value[1])
				{
					case INTEGER(value):
						green = value;
						if (isPercentRGB == true)
						{
							return null;
						}
						
					case PERCENTAGE(value):
						percentGreen = value;
						if (isPercentRGB == false)
						{
							return null;
						}
					default:
						return null;
						
				}
				
				switch(value[2])
				{
					case INTEGER(value):
						blue = value;
						if (isPercentRGB == true)
						{
							return null;
						}
						
					case PERCENTAGE(value):
						percentBlue = value;
						if (isPercentRGB == false)
						{
							return null;
						}
					default:
						return null;		
				}
				
				if (isRGBA == false)
				{
					if (isPercentRGB == true)
					{
						return COLOR(RGB_PERCENTAGE(percentRed, percentGreen, percentBlue));
					}
					else
					{
						return COLOR(RGB(red, green, blue));
					}
				}
				else
				{
					var alpha:Float = 0.0;
					
					switch(value[3])
					{
						case NUMBER(value):
							alpha = value;
							
						case INTEGER(value):
							alpha = value;
							
						default:
							return null;
					}
					
					if (isPercentRGB == true)
					{
						return COLOR(RGBA_PERCENTAGE(percentRed, percentGreen, percentBlue, alpha));
					}
					else
					{
						return COLOR(RGBA(red, green, blue, alpha));
					}
				}
				
			
			return null;
				
			default:
				return null;
		}
	}
	
	/**
	 * Try to match an identifier to a CSS value
	 */
	private static function parseIdent(ident:String, styleValues:Array<CSSPropertyValue>):Void
	{
		//always compare lowercase string in CSS
		ident = ident.toLowerCase();
		
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
	private static function parseKeyword(ident:String, styleValues:Array<CSSPropertyValue>):Void
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
				
			case 'nowrap':
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
				
			case 'thin':
				cssPropertyValue = KEYWORD(THIN);
				
			case 'thick':
				cssPropertyValue = KEYWORD(THICK);
				
			case 'dotted':
				cssPropertyValue = KEYWORD(DOTTED);
				
			case 'dashed':
				cssPropertyValue = KEYWORD(DASHED);
				
			case 'solid':
				cssPropertyValue = KEYWORD(SOLID);
				
			case 'double':
				cssPropertyValue = KEYWORD(DOUBLE);
				
			case 'groove':
				cssPropertyValue = KEYWORD(GROOVE);
				
			case 'ridge':
				cssPropertyValue = KEYWORD(RIDGE);
				
			case 'inset':
				cssPropertyValue = KEYWORD(INSET);
				
			case 'outset':
				cssPropertyValue = KEYWORD(OUTSET);
				
			case 'invert':
				cssPropertyValue = KEYWORD(INVERT);
				
			case 'underline':
				cssPropertyValue = KEYWORD(UNDERLINE);
				
			case 'overline':
				cssPropertyValue = KEYWORD(OVERLINE);
				
			case 'line-through':
				cssPropertyValue = KEYWORD(LINE_THROUGH);
				
			case 'blink':
				cssPropertyValue = KEYWORD(BLINK);
				
			case 'transparent':
				cssPropertyValue = COLOR(TRANSPARENT);
				
			case 'currentcolor':
				cssPropertyValue = COLOR(CURRENT_COLOR);
				
			default:	
				cssPropertyValue = parseColorKeyword(ident);
		}
		
		//if no match was found among CSS keywords, then
		//it is stored as an ident
		if (cssPropertyValue == null)
		{
			cssPropertyValue = IDENTIFIER(ident);
		}

		styleValues.push(cssPropertyValue);
	}
	
	/**
	 * Try to match the ident to a CSS color keyword
	 */
	private static function parseColorKeyword(ident:String):CSSPropertyValue
	{
		var cssPropertyValue:CSSPropertyValue = null;
		
		switch(ident)
		{
			case 'aliceblue':
				cssPropertyValue = COLOR(KEYWORD(ALICE_BLUE));
					
			case 'antiquewhite':
				cssPropertyValue = COLOR(KEYWORD(ANTIQUE_WHITE));	
				
			case 'aqua':
				cssPropertyValue = COLOR(KEYWORD(AQUA));
				
			case 'aquamarine':
				cssPropertyValue = COLOR(KEYWORD(AQUAMARINE));	
				
			case 'azure':
				cssPropertyValue = COLOR(KEYWORD(AZURE));	
				
			case 'beige':
				cssPropertyValue = COLOR(KEYWORD(BEIGE));	
				
			case 'bisque':
				cssPropertyValue = COLOR(KEYWORD(BISQUE));	
				
				
			case 'dimgray':
				cssPropertyValue = COLOR(KEYWORD(DIM_GRAY));
				
			case 'dimgrey':
				cssPropertyValue = COLOR(KEYWORD(DIM_GREY));	
				
			case 'blue':
				cssPropertyValue = COLOR(KEYWORD(BLUE));
				
			case 'black':
				cssPropertyValue = COLOR(KEYWORD(BLACK));	
				
			case 'blanchedalmond':
				cssPropertyValue = COLOR(KEYWORD(BLANCHE_DALMOND));	
					
			case 'blueviolet':
				cssPropertyValue = COLOR(KEYWORD(BLUE_VIOLET));
					
			case 'brown':
				cssPropertyValue = COLOR(KEYWORD(BROWN));	
				
			case 'burlywood':
				cssPropertyValue = COLOR(KEYWORD(ALICE_BLUE));	
				
			case 'cadetblue':
				cssPropertyValue = COLOR(KEYWORD(CADET_BLUE));	
				
			case 'chartreuse':
				cssPropertyValue = COLOR(KEYWORD(CHARTREUSE));	
				
			case 'chocolate':
				cssPropertyValue = COLOR(KEYWORD(CHOCOLATE));	
				
			case 'coral':
				cssPropertyValue = COLOR(KEYWORD(CORAL));	
					
			case 'cornflowerblue':
				cssPropertyValue = COLOR(KEYWORD(CORNFLOWER_BLUE));	
				
			case 'cornsilk':
				cssPropertyValue = COLOR(KEYWORD(CORNSILK));	
				
			case 'crimson':
				cssPropertyValue = COLOR(KEYWORD(CRIMSON));	
	
			case 'cyan':
				cssPropertyValue = COLOR(KEYWORD(CYAN));
						
			case 'darkblue':
				cssPropertyValue = COLOR(KEYWORD(DARK_BLUE));	
				
			case 'darkgoldenrod':
				cssPropertyValue = COLOR(KEYWORD(DARK_GOLDEN_ROD));	
						
			case 'darkgray':
				cssPropertyValue = COLOR(KEYWORD(DARK_GRAY));
					
			case 'darkgreen':
				cssPropertyValue = COLOR(KEYWORD(DARK_GREEN));	
				
			case 'darkgrey':
				cssPropertyValue = COLOR(KEYWORD(DARK_GREY));	
					
			case 'darkkhaki':
				cssPropertyValue = COLOR(KEYWORD(DARK_KHAKI));	
					
			case 'darkmagenta':
				cssPropertyValue = COLOR(KEYWORD(DARK_MAGENTA));	
					
			case 'darkolivegreen':
				cssPropertyValue = COLOR(KEYWORD(DARK_OLIVE_GREEN));	
				
			case 'darkorange':
				cssPropertyValue = COLOR(KEYWORD(DARK_ORANGE));	
				
			case 'darkorchid':
				cssPropertyValue = COLOR(KEYWORD(DARK_ORCHID));	
				
			case 'darkred':
				cssPropertyValue = COLOR(KEYWORD(DARK_RED));	
				
			case 'darksalmon':
				cssPropertyValue = COLOR(KEYWORD(DARK_SALMON));	
				
			case 'darkseagreen':
				cssPropertyValue = COLOR(KEYWORD(DARK_SEA_GREEN));	
				
			case 'darkslateblue':
				cssPropertyValue = COLOR(KEYWORD(DARK_SLATE_BLUE));	
				
			case 'darkslategray':
				cssPropertyValue = COLOR(KEYWORD(DARK_SLATE_GRAY));	
				
			case 'darkslategrey':
				cssPropertyValue = COLOR(KEYWORD(DARK_SLATE_GREY));	
				
			case 'darkturquoise':
				cssPropertyValue = COLOR(KEYWORD(DARK_TURQUOISE));	
						
			case 'darkviolet':
				cssPropertyValue = COLOR(KEYWORD(DARK_VIOLET));
						
			case 'deeppink':
				cssPropertyValue = COLOR(KEYWORD(DEEP_PINK));
						
			case 'deepskyblue':
				cssPropertyValue = COLOR(KEYWORD(DEEP_SKY_BLUE));
						
			case 'dodgerblue':
				cssPropertyValue = COLOR(KEYWORD(DODGER_BLUE));
						
			case 'firebrick':
				cssPropertyValue = COLOR(KEYWORD(FIRE_BRICK));
						
			case 'floralwhite':
				cssPropertyValue = COLOR(KEYWORD(FLORAL_WHITE));
						
			case 'forestgreen':
				cssPropertyValue = COLOR(KEYWORD(FOREST_GREEN));
						
			case 'gainsboro':
				cssPropertyValue = COLOR(KEYWORD(GAINSBORO));
						
			case 'ghostwhite':
				cssPropertyValue = COLOR(KEYWORD(GHOST_WHITE));
						
			case 'gold':
				cssPropertyValue = COLOR(KEYWORD(GOLD));
						
			case 'goldenrod':
				cssPropertyValue = COLOR(KEYWORD(GOLDEN_ROD));
						
			case 'greenyellow':
				cssPropertyValue = COLOR(KEYWORD(GREEN_YELLOW));
						
			case 'honeydew':
				cssPropertyValue = COLOR(KEYWORD(HONEY_DEW));
						
			case 'hotpink':
				cssPropertyValue = COLOR(KEYWORD(HOT_PINK));
						
			case 'indianred':
				cssPropertyValue = COLOR(KEYWORD(INDIAN_RED));
						
			case 'indigo':
				cssPropertyValue = COLOR(KEYWORD(INDIGO));
						
			case 'ivory':
				cssPropertyValue = COLOR(KEYWORD(IVORY));
						
			case 'khaki':
				cssPropertyValue = COLOR(KEYWORD(KHAKI));
						
			case 'lavender':
				cssPropertyValue = COLOR(KEYWORD(LAVENDER));
						
			case 'lavenderblush':
				cssPropertyValue = COLOR(KEYWORD(LAVENDER_BLUSH));
						
			case 'lawngreen':
				cssPropertyValue = COLOR(KEYWORD(LAWN_GREEN));
						
			case 'lemonchiffon':
				cssPropertyValue = COLOR(KEYWORD(LEMON_CHIFFON));
						
			case 'lightblue':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_BLUE));
						
			case 'lightcoral':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_CORAL));
						
			case 'lightcyan':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_CYAN));
						
			case 'lightgoldenrodyellow':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_GOLDENROD_YELLOW));
						
			case 'lightgray':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_GRAY));
						
			case 'lightgrey':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_GREY));
					
			case 'lightgreen':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_GREEN));
						
			case 'lightpink':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_PINK));
						
			case 'lightsalmon':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_SALMON));
						
			case 'lightseagreen':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_SEA_GREEN));
						
			case 'lightskyblue':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_SKY_BLUE));
						
			case 'lightslategray':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_SLATE_GRAY));
						
			case 'lightslategrey':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_SLATE_GREY));
						
			case 'lightsteelblue':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_STEEL_BLUE));
				
			default:
				cssPropertyValue = parseColorKeyword2(ident);
		}
		
		return cssPropertyValue;
	}
	
	/**
	 * The color keyword method is split in 2 because of
	 * weird bug when compiling cpp output caused by
	 * too many switch statements
	 */
	private static function parseColorKeyword2(ident:String):CSSPropertyValue
	{
		var cssPropertyValue:CSSPropertyValue = null;
		
		switch(ident)
		{
			case 'lightyellow':
				cssPropertyValue = COLOR(KEYWORD(LIGHT_YELLOW));
						
			case 'limegreen':
				cssPropertyValue = COLOR(KEYWORD(LIME_GREEN));
						
			case 'linen':
				cssPropertyValue = COLOR(KEYWORD(LINEN));
						
			case 'magenta':
				cssPropertyValue = COLOR(KEYWORD(MAGENTA));
						
			case 'marron':
				cssPropertyValue = COLOR(KEYWORD(MAROON));
						
			case 'mediumaquamarine':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_AQUAMARINE));
						
			case 'mediumblue':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_BLUE));
						
			case 'mediumorchid':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_ORCHID));
						
			case 'mediumpurple':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_PURPLE));
						
			case 'mediumseagreen':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_SEA_GREEN));
						
			case 'mediumslateblue':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_SLATE_BLUE));
						
			case 'mediumspringgreen':
				cssPropertyValue = COLOR(KEYWORD(MEDIUM_SPRING_GREEN));
						
			case 'mintcream':
				cssPropertyValue = COLOR(KEYWORD(MINT_CREAM));
						
			case 'mistyrose':
				cssPropertyValue = COLOR(KEYWORD(MISTY_ROSE));
						
			case 'moccasin':
				cssPropertyValue = COLOR(KEYWORD(MOCCASIN));
						
			case 'navajowhite':
				cssPropertyValue = COLOR(KEYWORD(NAVAJO_WHITE));
						
			case 'oldlace':
				cssPropertyValue = COLOR(KEYWORD(OLD_LACE));
						
			case 'olivedrab':
				cssPropertyValue = COLOR(KEYWORD(OLIVE_DRAB));
						
			case 'orangered':
				cssPropertyValue = COLOR(KEYWORD(ORANGE_RED));
						
			case 'orchid':
				cssPropertyValue = COLOR(KEYWORD(ORCHID));
						
			case 'palegoldenrod':
				cssPropertyValue = COLOR(KEYWORD(PALE_GOLDEN_ROD));
						
			case 'palegreen':
				cssPropertyValue = COLOR(KEYWORD(PALE_GREEN));
						
			case 'paleturquoise':
				cssPropertyValue = COLOR(KEYWORD(PALE_TURQUOISE));
						
			case 'palevioletred':
				cssPropertyValue = COLOR(KEYWORD(PALE_VIOLET_RED));
						
			case 'papayawhip':
				cssPropertyValue = COLOR(KEYWORD(PAPAYA_WHIP));
						
			case 'peachpuff':
				cssPropertyValue = COLOR(KEYWORD(PEACH_PUFF));
						
			case 'peru':
				cssPropertyValue = COLOR(KEYWORD(PERU));
						
			case 'pink':
				cssPropertyValue = COLOR(KEYWORD(PINK));
						
			case 'plum':
				cssPropertyValue = COLOR(KEYWORD(PLUM));
						
			case 'powderblue':
				cssPropertyValue = COLOR(KEYWORD(POWDER_BLUE));
						
			case 'rosybrown':
				cssPropertyValue = COLOR(KEYWORD(ROSY_BROWN));
						
			case 'royalblue':
				cssPropertyValue = COLOR(KEYWORD(ROYAL_BLUE));
						
			case 'saddlebrown':
				cssPropertyValue = COLOR(KEYWORD(SADDLE_BROWN));
						
			case 'salmon':
				cssPropertyValue = COLOR(KEYWORD(SALMON));
						
			case 'sandybrown':
				cssPropertyValue = COLOR(KEYWORD(SANDY_BROWN));
						
			case 'seagreen':
				cssPropertyValue = COLOR(KEYWORD(SEA_GREEN));
						
			case 'sienna':
				cssPropertyValue = COLOR(KEYWORD(SIENNA));
						
			case 'skyblue':
				cssPropertyValue = COLOR(KEYWORD(SKY_BLUE));
						
			case 'slateblue':
				cssPropertyValue = COLOR(KEYWORD(SLATE_BLUE));
						
			case 'slategray':
				cssPropertyValue = COLOR(KEYWORD(SLATE_GRAY));
						
			case 'slategrey':
				cssPropertyValue = COLOR(KEYWORD(SLATE_GREY));
						
			case 'snow':
				cssPropertyValue = COLOR(KEYWORD(SNOW));
						
			case 'springgreen':
				cssPropertyValue = COLOR(KEYWORD(SPRING_GREEN));
						
			case 'steelblue':
				cssPropertyValue = COLOR(KEYWORD(STEEL_BLUE));
						
			case 'tan':
				cssPropertyValue = COLOR(KEYWORD(TAN));
						
			case 'thisle':
				cssPropertyValue = COLOR(KEYWORD(THISLE));
						
			case 'tomato':
				cssPropertyValue = COLOR(KEYWORD(TOMATO));
						
			case 'turquoise':
				cssPropertyValue = COLOR(KEYWORD(TURQUOISE));
						
			case 'violet':
				cssPropertyValue = COLOR(KEYWORD(VIOLET));
						
			case 'wheat':
				cssPropertyValue = COLOR(KEYWORD(WHEAT));
						
			case 'whitesmoke':
				cssPropertyValue = COLOR(KEYWORD(WHITE_SMOKE));
						
			case 'yellowgreen':
				cssPropertyValue = COLOR(KEYWORD(YELLOW_GREEN));
				
			case 'silver':
				cssPropertyValue = COLOR(KEYWORD(SILVER));	
				
			case 'gray':
				cssPropertyValue = COLOR(KEYWORD(GRAY));	
				
			case 'grey':
				cssPropertyValue = COLOR(KEYWORD(GREY));		
				
			case 'white':
				cssPropertyValue = COLOR(KEYWORD(WHITE));	
				
			case 'maroon':
				cssPropertyValue = COLOR(KEYWORD(MAROON));	
				
			case 'red':
				cssPropertyValue = COLOR(KEYWORD(RED));		
				
			case 'purple':
				cssPropertyValue = COLOR(KEYWORD(PURPLE));	
				
			case 'fuchsia':
				cssPropertyValue = COLOR(KEYWORD(FUCHSIA));		
				
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
		
		return cssPropertyValue;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * for url style value, convert the url to a url relative to document
	 * if needed, as by default url declared in an external stylsheet are relative
	 * to this stylesheet
	 * @param	value the url to convert
	 * @param	baseURL the url of css style sheet owning the value, or null if the
	 * style is embedded
	 * @return	the url relative to the document
	 */
	static function getURLRelativeToDocument(value:String, baseURL:String):String
	{
		//no need to convert if style don't come from an external stylesheet
		if (baseURL == null)
		{
			return value;
		}
		
		var url:URL = cocktail.core.url.URL.fromString(value);
		
		//absolute url don't need to be converted
		if (cocktail.core.url.URL.isRelative(url) == false)
		{
			return value;
		}
		
		var typedBaseURL:URL = cocktail.core.url.URL.fromString(baseURL);

		//append url to base url
		return cocktail.core.url.URL.toString(cocktail.core.url.URL.appendURL(typedBaseURL, url));
	}
	
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