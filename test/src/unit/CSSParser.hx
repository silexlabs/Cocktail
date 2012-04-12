package ;

import cocktail.Lib;
import cocktail.Cocktail;

/**
 * structure used to store parsed string into value / unit pairs
 */
typedef VUnit = 
{
	value:String,
	unit:String
};
/**
 * structure used to store parsed string into a 4 channels color
 */
typedef VCol = 
{
	r:Int,
	g:Int,
	b:Int,
	a:Null<Float>
};

/**
 * this class handles the conversion between cocktail typed style objects and the Dynamic non-typed JS API styles
 * @example	CSSParser.boxStyleEnum(Padding, "100 px ") returns Padding.length(Length.px(100))
 */
class CSSParser {
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS FOR STRING TO ENUM CONVERSION (lexa)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * convert a string into a typed enum
	 * works with Cocktail enums Dimension, Margin, Padding 
	 * @example CSSParser.boxStyleEnum(Padding, "100 px ") returns Padding.length(Length.px(100))
	 */
	static public function boxStyleEnum<EnumName>(enumType:Enum<EnumName>, string:String):EnumName{
		if(string == "auto")
			return Type.createEnum(enumType, "cssAuto");
		
		// split unit and value
		var parsed:VUnit = string2VUnit(string);
		// convert into typed enum
		return switch (parsed.unit){
			case "%":
				Type.createEnum(enumType, "percent", [Std.parseInt(parsed.value)]);	
			default:
				Type.createEnum(enumType, "length", [string2Length(parsed)]);
		}
	}
	/**
	 * convert a string into a typed Color enum
	 * @example CSSParser.colorEnum("yellow") returns Color.yellow
	 */
	static public function colorEnum(string:String):Color{
		// clean up a bit
		string = trim(string);
		// case of hex values, e.g. #FFFFFF
		if (StringTools.startsWith(string, "#"))
			return hex(string.substr(1));
		// case of rgba values, e.g. rgba(255, 255, 255, 1)
		if (StringTools.startsWith(string, "rgba")){
			var vcol:VCol = string2RGBA(string);
			return rgba(vcol.r, vcol.g, vcol.b, vcol.a);
		}
		// case of rgb values, e.g. rgb(255, 255, 255)
		if (StringTools.startsWith(string, "rgb")){
			var vcol:VCol = string2RGB(string);
			return rgb(vcol.r, vcol.g, vcol.b);
		}
		// case of transparent and keywords
		return switch (string)
		{
			case "transparent": Color.transparent;
			case "aqua": Color.keyword(aqua);
			case "black": Color.keyword(black);
			case "blue": Color.keyword(blue);
			case "fuchsia": Color.keyword(fuchsia);
			case "gray": Color.keyword(gray);
			case "green": Color.keyword(green);
			case "lime": Color.keyword(lime);
			case "maroon": Color.keyword(maroon);
			case "navy": Color.keyword(navy);
			case "olive": Color.keyword(olive);
			case "orange": Color.keyword(orange);
			case "purple": Color.keyword(purple);
			case "red": Color.keyword(red);
			case "silver": Color.keyword(silver);
			case "teal": Color.keyword(teal);
			case "white": Color.keyword(white);
			case "yellow": Color.keyword(yellow);	
			default:
				throw "unknown color \""+string+"\"";
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS FOR STRING TO ENUM CONVERSION (lexa)
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * function used internally to convert an rgba value to a 4 digit object of type VCol
	 */
	static private function string2RGBA(string:String):VCol{
		// remove "rgba(" and ")"
		string = string.substr(5, string.length - 6);
		// split into [r, g, b, a]
		var rgba:Array<String> = string.split(",");
		// insert "0"s if some channels are missing
		while(rgba.length < 4)
			rgba.push("0");
		// return a typed object
		return {
			r:Std.parseInt(trim(rgba[0])),
			g:Std.parseInt(trim(rgba[1])),
			b:Std.parseInt(trim(rgba[2])),
			a:Std.parseFloat(trim(rgba[3]))
		};
	}
	/**
	 * function used internally to convert an rgb value to a 3 digit object of type VCol
	 */
	static private function string2RGB(string:String):VCol{
		// remove "rgb(" and ")"
		string = string.substr(4, string.length - 5);
		// split into [r, g, b, a]
		var rgba:Array<String> = string.split(",");
		// insert "0"s if some channels are missing
		while(rgba.length < 3)
			rgba.push("0");
		// return a typed object
		return {
			r:Std.parseInt(trim(rgba[0])),
			g:Std.parseInt(trim(rgba[1])),
			b:Std.parseInt(trim(rgba[2])),
			a:null
		};
	}
	/**
	 * function used internally to trim left and right a string   
	 */
	static private function trim(string:String):String{
		return StringTools.ltrim(StringTools.rtrim(string));
	} 
	/**
	 * function used internally to split a string to a value/unit strings pair   
	 */
	static private function string2VUnit(string:String):VUnit{
		var r : EReg = ~/([0-9]*)(.*)/;
		r.match(string);
//		trace("return "+r.matched(1)+"+"+r.matched(2));
		return {
			value: r.matched(1), 
			unit : trim(r.matched(2))
		};
	}
	/**
	 * function used internally to convert a value/unit strings pair to an enum  
	 */
	static private function string2Length(parsed):Length{
		return switch (parsed.unit)
		{
			case "in":
				Length._in(Std.parseInt(parsed.value));	
			case "cm":
				Length.cm(Std.parseInt(parsed.value));	
			case "em":
				Length.em(Std.parseInt(parsed.value));	
			case "ex":
				Length.ex(Std.parseInt(parsed.value));	
			case "mm":
				Length.mm(Std.parseInt(parsed.value));	
			case "pc":
				Length.pc(Std.parseInt(parsed.value));	
			case "pt":
				Length.pt(Std.parseInt(parsed.value));	
			case "px":
				Length.px(Std.parseInt(parsed.value));
			default:
				throw("Bad unit \"" + parsed.unit+"\"");
		}
	}
}
