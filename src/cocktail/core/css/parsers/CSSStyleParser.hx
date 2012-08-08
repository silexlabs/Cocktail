package cocktail.core.css.parsers;

import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSParsersData;
using StringTools;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSStyleParser 
{

	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PARSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : should return array of a property type instead of requiring callback
	public function parseStyle(styles:String, applyProperty:String->Array<CSSPropertyValue>->Bool->Void):Void
	{
		var state:StyleDeclarationParserState = IGNORE_SPACES;
		var next:StyleDeclarationParserState = BEGIN_STYLE_NAME;
		
		var position:Int = 0;
		
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
					position = parseStyleValue(styleName, styles, position, applyProperty);
					state = IGNORE_SPACES;
					next = BEGIN_STYLE_NAME;
					
				case INVALID_STYLE:	
			}
			c = styles.fastCodeAt(++position);
		}
	}
	
	private function parseStyleValue(propertyName:String, styles:String, position:Int, applyProperty:String->Array<CSSPropertyValue>->Bool->Void):Int
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
					position = parseIdentOrFunctionnalNotation(styles, position, styleValues);
					state = SPACE_OR_END;
					
				case NUMBER_OR_INTEGER:
					position = parseIntegerOrNumber(styles, position, styleValues);
					state = SPACE_OR_END;
					
				case INVALID_STYLE_VALUE:
					trace("invalid");
	
			}
			c = styles.fastCodeAt(++position);
		}
		
		applyProperty(propertyName, styleValues, important);
		
		return position;
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
			position = parseDimension(numberOrInteger, styles, position, styleValues);
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
	
	private function parseDimension(numberOrInteger:Float, styles:String, position:Int, styleValues:Array<CSSPropertyValue>):Int
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
				
			case 'Hz':
				styleValues.push(CSSPropertyValue.FREQUENCY(CSSFrequencyValue.HERTZ(numberOrInteger)));
				
			case 'kHz':
				styleValues.push(CSSPropertyValue.FREQUENCY(CSSFrequencyValue.KILO_HERTZ(numberOrInteger)));
				
			case 'dpi':
				styleValues.push(CSSPropertyValue.RESOLUTION(CSSResolutionValue.DPI(numberOrInteger)));
				
			case 'dpcm':
				styleValues.push(CSSPropertyValue.RESOLUTION(CSSResolutionValue.DPCM(numberOrInteger)));	
				
			case 'dppx':
				styleValues.push(CSSPropertyValue.RESOLUTION(CSSResolutionValue.DPPX(numberOrInteger)));		
				
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
				position = parseFunctionnalNotation(ident, styles, position, styleValues);
				
			default:	
				parseIdent(ident, styleValues);
		}
		
		return --position;
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
		}
		
		styleValues.push(cssPropertyValue);
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
	
}