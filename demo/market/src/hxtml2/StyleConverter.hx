package hxtml2;

import hxtml2.CSSParser;
import js.Dom;

/*
import cocktailCore.style.Style;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
*/

typedef ValueWithUnit = {var value : Float; var unit : String;}

class StyleConverter
{
	/**
	 * class constructor
	 */
	public function new() 
	{
	}
	public static function valueToUnitArray(v:Value):Null<Array<Value>>
	{
		return switch (v)
		{
			case VGroup(array), VList(array):
				array;
			default:
				null;
		}
	}
	public static function valueToValueWithUnit(v:Value):Null<ValueWithUnit>
	{
		return switch (v)
		{
			case VUnit(value, unit):
				{value : value, unit : unit};
			default:
				null;
		}
	}
	public static function valueToString(v:Value):Null<String>
	{
		return switch (v)
		{
			case VIdent(value), VString(value), VHex(value), VUrl(value):
				value;
			default:
				null;
		}
	}
	public static function valueToFloat(v:Value):Null<Float>
	{
		return switch (v)
		{
			case VFloat(value):
				value;
			default:
				null;
		}
	}
	public static function valueToInt(v:Value):Null<Int>
	{
		return switch (v)
		{
			case VInt(value):
				value;
			default:
				null;
		}
	}
/*
	public static function valueToFontFamilyStyle(v:Value):Null<FontFamilyStyleValue>
	{
		var stringValue:Null<String> = valueToString(v);
		return switch (stringValue)
		{
			case "serif":
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.serif);

			case "sans-serif":
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif);

			case "monospace":
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.monospace);

			default:
				FontFamilyStyleValue.familyName(stringValue);
		}
	}
	public static function getMarginStyleValue(unit:String, value:Int):MarginStyleValue
	{
		return switch (unit)
		{
			case "%":
				MarginStyleValue.percent(value);
			default:
				MarginStyleValue.length(getLengthValue(unit, value));
		}
	}
	public static function getPaddingStyleValue(unit:String, value:Int):PaddingStyleValue
	{
		return switch (unit)
		{
			case "%":
				PaddingStyleValue.percent(value);
			default:
				PaddingStyleValue.length(getLengthValue(unit, value));
		}
	}
	public static function getDimensionStyleValue(unit:String, value:Int):DimensionStyleValue
	{
		return switch (unit)
		{
			case "%":
				DimensionStyleValue.percent(value);
			default:
				DimensionStyleValue.length(getLengthValue(unit, value));
		}
	}
	public static function getLengthValue(unit:String, value:Int):LengthValue
	{
		return switch (unit)
		{
			case "px":
				LengthValue.px(value);
			case "cm":
				LengthValue.cm(value);
			case "mm":
				LengthValue.mm(value);
			case "pt":
				LengthValue.pt(value);
			case "pc":
				LengthValue.pc(value);
			case "in":
				LengthValue._in(value);
			case "em":
				LengthValue.em(value);
			case "ex":
				LengthValue.ex(value);
			default:
				throw("unknown unit \""+unit+"\"");
		}
	}
	public static function getKeywordFromColor(value:String):ColorKeywordValue
	{
		return switch (value)
		{
			case "aqua":
				aqua;

			case "black":
				black;

			case "blue":
				blue;

			case "fuchsia":
				fuchsia;

			case "gray":
				gray;

			case "green":
				green;

			case "lime":
				lime;

			case "maroon":
				maroon;

			case "navy":
				navy;

			case "olive":
				olive;

			case "orange":
				orange;

			case "purple":
				purple;

			case "red":
				red;

			case "silver":
				silver;

			case "teal":
				teal;

			case "white":
				white;

			case "yellow":
				yellow;	
			default:
				throw "unknown color \""+value+"\"";
		}
	}
	public static function getCSSFontSize(value:Value):Null<FontSizeStyleValue>
	{
		trace ("getCSSFontSize "+value);

		// absolute and relative cases
		var valueString:Null<String> = valueToString(value);
		if( valueString != null ) 
		{
			return switch (valueString)
			{
				case "xx-small":
					absoluteSize(xxSmall);

				case "x-small":
					absoluteSize(xSmall);

				case "small":
					absoluteSize(small);

				case "medium":
					absoluteSize(medium);

				case "large":
					absoluteSize(large);

				case "x-large":
					absoluteSize(xLarge);

				case "xx-large":	
					absoluteSize(xxLarge);
				case "larger":
					relativeSize(larger);

				case "smaller":
					relativeSize(smaller);
			}
		}
		else
		{
			//  percent and length cases
			var valueWithUnit:Null<ValueWithUnit> = valueToValueWithUnit(value);
			if( valueWithUnit != null ) 
			{
				return switch (valueWithUnit.unit)
				{
					case "%":
						FontSizeStyleValue.percentage(Math.round(valueWithUnit.value));
					default:
						FontSizeStyleValue.length(getLengthValue(valueWithUnit.unit, Math.round(valueWithUnit.value)));
				}
			}
			return null;
		}
	}
*/
	public static function applyStyle(styleName : String, v : Value, s : Style ) : Bool 
	{
		trace("applyStyle "+styleName+", "+v+", "+s);
/*		trace(valueToUnitArray(v) + " - " + valueToValueWithUnit(v) + " - " + valueToString(v) + " - " + valueToFloat(v) + " - " + valueToInt(v));
		if(valueToUnitArray(v) == null && valueToValueWithUnit(v) == null && valueToString(v) == null && valueToFloat(v) == null && valueToInt(v) == null)
			trace ("NOT GOOD CONVERSION IMPOSSIBLE");
*/		

		switch( styleName ) 
		{
			case "margin":
				var values:Array<Value> = valueToUnitArray(v);
				if( values != null ) 
				{
					switch( values.length ) 
					{
						case 1:
							applyStyle( "margin-top", values[0], s);
							applyStyle( "margin-right", values[0], s);
							applyStyle( "margin-bottom", values[0], s);
							applyStyle( "margin-left", values[0], s);
							return true;
						case 2:
							applyStyle( "margin-top", values[0], s);
							applyStyle( "margin-right", values[1], s);
							applyStyle( "margin-bottom", values[0], s);
							applyStyle( "margin-left", values[1], s);
							return true;
						case 3:
							applyStyle( "margin-top", values[0], s);
							applyStyle( "margin-right", values[1], s);
							applyStyle( "margin-bottom", values[2], s);
							applyStyle( "margin-left", values[1], s);
							return true;
						case 4:
							applyStyle( "margin-top", values[0], s);
							applyStyle( "margin-right", values[1], s);
							applyStyle( "margin-bottom", values[2], s);
							applyStyle( "margin-left", values[3], s);
							return true;
					}
				}
			case "margin-left":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.marginLeft = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "margin-top":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.marginTop = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "margin-right":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.marginRight = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "margin-bottom":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.marginBottom = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "display":
				trace("display "+valueToString(v));
				s.display = valueToString(v);
				return true;
			case "padding":
				var values:Array<Value> = valueToUnitArray(v);
				if( values != null ) 
				{
					switch( values.length ) 
					{
						case 1:
							applyStyle( "padding-top", values[0], s);
							applyStyle( "padding-right", values[0], s);
							applyStyle( "padding-bottom", values[0], s);
							applyStyle( "padding-left", values[0], s);
							return true;
						case 2:
							applyStyle( "padding-top", values[0], s);
							applyStyle( "padding-right", values[1], s);
							applyStyle( "padding-bottom", values[0], s);
							applyStyle( "padding-left", values[1], s);
							return true;
						case 3:
							applyStyle( "padding-top", values[0], s);
							applyStyle( "padding-right", values[1], s);
							applyStyle( "padding-bottom", values[2], s);
							applyStyle( "padding-left", values[1], s);
							return true;
						case 4:
							applyStyle( "padding-top", values[0], s);
							applyStyle( "padding-right", values[1], s);
							applyStyle( "padding-bottom", values[2], s);
							applyStyle( "padding-left", values[3], s);
							return true;
					}
				}
			case "padding-left":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.paddingLeft = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "padding-right":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.paddingRight = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "padding-bottom":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.paddingBottom = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "padding-top":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.paddingTop = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "width":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.width = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "height":
				var valueWithUnit:ValueWithUnit = valueToValueWithUnit(v);
				if( valueWithUnit != null ) 
				{
					s.height = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					return true;
				}
			case "background-color":
				var c = getCol(v);
				if( c != null ) {
					s.backgroundColor = c;
					return true;
				}
				if( getIdent(v) == "transparent" ) {
					s.backgroundColor = "transparent";
					return true;
				}
			case "background-repeat":
				s.backgroundRepeat = getIdent(v);
/*					case "repeat-x": s.bgRepeatX = true; s.bgRepeatY = false; return true;
					case "repeat-y": s.bgRepeatX = false; s.bgRepeatY = true; return true;
					case "repeat": s.bgRepeatX = true; s.bgRepeatY = true; return true;
					case "no-repeat": s.bgRepeatX = false; s.bgRepeatY = false; return true;
*/
			case "background-image":
				switch( v ) {
				case VUrl(url):
					s.backgroundImage = url;
					return true;
				case VIdent(i):
					if( i == "none" ) {
						s.backgroundImage = "";
						return true;
					}
				default:
				}
			case "background-attachment":
				throw ("not implemented");
/*				switch( getIdent(v) ) {
				case "scroll": notImplemented(); return true;
				case "fixed": notImplemented(); return true;
				}
*/			case "background-position":
				throw ("not implemented");
/*				if( applyComposite(["-inner-bgpos-left","-inner-bgpos-top"], v, s) ) {
					if( s.bgPosY == null )
						s.bgPosY = Percent(0.5);
					if( s.bgPosX == null )
						s.bgPosX = Percent(0.5);
					return true;
				}
*/			case "-inner-bgpos-top":
				throw ("not implemented");
/*				var l = getUnit(v);
				if( l != null ) {
					s.bgPosY = l;
					return true;
				}
				switch( getIdent(v) ) {
				case "top": s.bgPosY = Percent(0); return true;
				case "center": s.bgPosY = Percent(.5); return true;
				case "bottom": s.bgPosY = Percent(1); return true;
				}
*/			case "-inner-bgpos-left":
				throw ("not implemented");
/*				var l = getUnit(v);
				if( l != null ) {
					s.bgPosX = l;
					return true;
				}
				switch( getIdent(v) ) {
				case "left": s.bgPosX = Percent(0); return true;
				case "center": s.bgPosX = Percent(.5); return true;
				case "right": s.bgPosX = Percent(1); return true;
				}
*/			case "background":
				return applyComposite(["background-color", "background-image", "background-repeat", "background-attachment", "background-position"], v, s);

			case "font-family":
				// retrieve a list of fonts or a single font
				var values:Array<Value> = valueToUnitArray(v);
				// single font case, make a single element array
				if( values == null ) 
					values = [v];
				// for all fonts in values, extract the font name and push it into fonts array
				var fonts:Array<String> = [];
				for (val in values)
					fonts.push(valueToString(val));
				// this is our font list
				s.fontFamily = fonts;
				return true;
			case "font-size":
				// absolute and relative cases
				var valueString:Null<String> = valueToString(v);
				if( valueString == null ) 
				{
					//  percent and length cases
					var valueWithUnit:Null<ValueWithUnit> = valueToValueWithUnit(v);
					if( valueWithUnit != null ) 
						valueString = Std.string(Math.round(valueWithUnit.value)) + valueWithUnit.unit;
					else
						valueString = "";
				}
				s.fontSize = valueString;
				return true;

			case "font-style":
				s.fontStyle = getIdent(v); 
				return true;
			case "font-variant":
				s.fontStyle = getIdent(v); 
				return true;
			case "font-weight":
				// can be "normal", "lighter", "bold", "bolder" or an int value
				s.fontStyle = getIdent(v); 
				return true;
			case "font":
				var vl = switch( v ) {
				case VGroup(l): l;
				default: [v];
				};
				var v = VGroup(vl);
				applyComposite(["font-style", "font-variant", "font-weight"], v, s);
				applyComposite(["font-size"], v, s);
				if( vl.length > 0 )
					switch( vl[0] ) {
					case VSlash: vl.shift();
					default:
					}
				applyComposite(["line-height"], v, s);
				applyComposite(["font-family"], v, s);
				if( vl.length == 0 )
					return true;
			case "color":
				var c = getCol(v);
				if( c != null ) {
					s.color = c;
					return true;
				}
/*			case "text-decoration":
				var idents = getGroup(v, getIdent);
				for( i in idents )
					switch( i ) {
					case "none": s.textDecoration = TDNone;
					case "underline": s.textDecoration = TDUnderline;
					case "overline", "line-through", "blink": notImplemented();
					default: return false;
					}
				return true;
			case "text-transform":
				switch( getIdent(v) ) {
				case "none": s.textTransform = TFNone; return true;
				case "capitalize": s.textTransform = TFCapitalize; return true;
				case "uppercase": s.textTransform = TFUppercase; return true;
				case "lowercase": s.textTransform = TFLowercase; return true;
				}
			case "line-height":
				var i = getUnit(v);
				if( i != null ) {
					s.lineHeight = i;
					return true;
				}
	*/
			default:
				throw "Not implemented '"+styleName+"' = "+Std.string(v);
		}
		return false;
	}
	public static function applyComposite( names : Array<String>, v : Value, s : Style ) {
		var vl = switch( v ) {
		case VGroup(l): l;
		default: [v];
		};
		while( vl.length > 0 ) {
			var found = false;
			for( n in names ) {
				var count = switch( n ) {
				case "background-position": 2;
				default: 1;
				}
				if( count > vl.length ) count = vl.length;
				while( count > 0 ) {
					var v = (count == 1) ? vl[0] : VGroup(vl.slice(0, count));
					if( applyStyle(n, v, s) ) {
						found = true;
						names.remove(n);
						for( i in 0...count )
							vl.shift();
						break;
					}
					count--;
				}
				if( found ) break;
			}
			if( !found )
				return false;
		}
		return true;
	}
/*	public static function getGroup<T>( v : Value, f : Value -> Null<T> ) : Null<Array<T>> {
		switch(v) {
		case VGroup(l):
			var a = [];
			for( v in l ) {
				var v = f(v);
				if( v == null ) return null;
				a.push(v);
			}
			return a;
		default:
			var v = f(v);
			return (v == null) ? null : [v];
		}
	}

	public static function getList<T>( v : Value, f : Value -> Null<T> ) : Null<Array<T>> {
		switch(v) {
		case VList(l):
			var a = [];
			for( v in l ) {
				var v = f(v);
				if( v == null ) return null;
				a.push(v);
			}
			return a;
		default:
			var v = f(v);
			return (v == null) ? null : [v];
		}
	}

	public static function getPix( v : Value ) : Null<Int> {
		return switch( v ) {
		case VUnit(f, u):
			switch( u ) {
			case "px": Std.int(f);
			case "pt": Std.int(f * 4 / 3);
			default: null;
			}
		case VInt(v):
			v;
		default:
			null;
		};
	}

	public static function getUnit( v : Value ) : Null<Unit> {
		return switch( v ) {
		case VUnit(f, u):
			switch( u ) {
			case "px": Pix(Std.int(f));
			case "pt": Pix(Std.int(f * 4 / 3));
			case "em": EM(f);
			case "%": Percent(f / 100);
			default: null;
			}
		case VInt(v):
			Pix(v);
		default:
			null;
		};
	}
*/
	public static function getIdent( v : Value ) : Null<String> {
		return switch( v ) {
		case VIdent(v): v;
		default: null;
		};
	}
	public static function getCol( v : Value ) : Null<Int> {
		return switch( v ) {
		case VHex(v):
			(v.length == 6) ? Std.parseInt("0x" + v) : ((v.length == 3) ? Std.parseInt("0x"+v.charAt(0)+v.charAt(0)+v.charAt(1)+v.charAt(1)+v.charAt(2)+v.charAt(2)) : null);
		case VIdent(i):
			switch( i ) {
			case "black":	0x000000;
			case "red": 	0xFF0000;
			case "lime":	0x00FF00;
			case "blue":	0x0000FF;
			case "white":	0xFFFFFF;
			case "aqua":	0x00FFFF;
			case "fuchsia":	0xFF00FF;
			case "yellow":	0xFFFF00;
			case "maroon":	0x800000;
			case "green":	0x008000;
			case "navy":	0x000080;
			case "olive":	0x808000;
			case "purple": 	0x800080;
			case "teal":	0x008080;
			case "silver":	0xC0C0C0;
			case "gray", "grey": 0x808080;
			default: null;
			}
		default:
			null;
		};
	}
/*
	public static function getFontName( v : Value ) {
		return switch( v ) {
		case VString(s): s;
		case VGroup(_):
			var g = getGroup(v, getIdent);
			if( g == null ) null else g.join(" ");
		case VIdent(i): i;
		default: null;
		};
	}
	*/
}