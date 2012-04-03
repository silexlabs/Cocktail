package cocktail.core.style.adapter;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Style 
{
	/**
	 * display styles
	 */
	public var display(get_display, set_display):String;
	public var position(get_position, set_position):String;
	public var cssFloat(get_CSSFloat, set_CSSFloat):String;
	public var clear(get_clear, set_clear):String;
	
	/**
	 * box model styles
	 */
	public var marginLeft(get_marginLeft, set_marginLeft):String;
	public var marginRight(get_marginRight, set_marginRight):String;
	public var marginTop(get_marginTop, set_marginTop):String;
	public var marginBottom(get_marginBottom, set_marginBottom):String;
	
	public var paddingLeft(get_paddingLeft, set_paddingLeft):String;
	public var paddingRight(get_paddingRight, set_paddingRight):String;
	public var paddingTop(get_paddingTop, set_paddingTop):String;
	public var paddingBottom(get_paddingBottom, set_paddingBottom):String;

	public var width(get_width, set_width):String;
	public var height(get_height, set_height):String;
	
	public var minHeight(get_minHeight, set_minHeight):String;
	public var maxHeight(get_maxHeight, set_maxHeight):String;
	public var minWidth(get_minWidth, set_minWidth):String;
	public var maxWidth(get_maxWidth, set_maxWidth):String;

	public var top(get_top, set_top):String;
	public var left(get_left, set_left):String;
	public var bottom(get_bottom, set_bottom):String;
	public var right(get_right, set_right):String;
	
	/**
	 * background styles
	 */
	public var backgroundColor(get_backgroundColor, set_backgroundColor):String;
	public var backgroundImage(get_backgroundImage, set_backgroundImage):String;
	public var backgroundRepeat(get_backgroundRepeat, set_backgroundRepeat):String;
	public var backgroundOrigin(get_backgroundOrigin, set_backgroundOrigin):String;
	public var backgroundSize(get_backgroundSize, set_backgroundSize):String;
	public var backgroundPosition(get_backgroundPosition, set_backgroundPosition):String;
	public var backgroundClip(get_backgroundClip, set_backgroundClip):String;
	
	/**
	 * font styles
	 */
	public var fontSize(get_fontSize, set_fontSize):String;
	public var fontWeight(get_fontWeight, set_fontWeight):String;
	public var fontStyle(get_fontStyle, set_fontStyle):String;
	public var fontFamily(get_fontFamily, set_fontFamily ):String;
	public var fontVariant(get_fontVariant, set_fontVariant):String;
	public var color(get_color, set_color):String;
	
	/**
	 * text styles
	 */
	public var lineHeight(get_lineHeight, set_lineHeight):String;
	public var textTransform(get_textTransform, set_textTransform):String;
	public var letterSpacing(get_letterSpacing, set_letterSpacing):String;
	public var wordSpacing(get_wordSpacing, set_wordSpacing):String;
	public var whiteSpace(get_whiteSpace, set_whiteSpace):String;
	public var textAlign(get_textAlign, set_textAlign):String;
	public var textIndent(get_textIndent, set_textIndent):String;
	public var verticalAlign(get_verticalAlign, set_verticalAlign):String;
	
	/**
	 * visual effect styles
	 */
	public var opacity(get_opacity, set_opacity):String;
	public var visibility(get_visibility, set_visibility):String;
	public var overflowX(get_overflowX,  set_overflowX):String;
	public var overflowY(get_overflowY,  set_overflowY):String;
	
	/**
	 * user interface styles
	 */
	public var cursor(get_cursor, set_cursor):String;
	
	
	private var _coreStyle:CoreStyle;
	
	public function new(coreStyle:CoreStyle) 
	{
		_coreStyle = coreStyle;
	}

	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function get_opacity():String
	{
		return "";
	}
	
	private function set_opacity(value:String):String
	{
		return value;
	}
	
	private function get_visibility():String
	{
		return "";
	}
	
	private function set_visibility(value:String):String
	{
		return value;
	}
	
	private function get_marginLeft():String 
	{
		return "";
	}
	
	private function set_marginLeft(value:String):String 
	{
		return value;
	}
	
	private function get_marginRight():String 
	{
		return "";
	}
	
	private function set_marginRight(value:String):String 
	{
		return value;
	}
	
	private function get_marginTop():String 
	{
		return "";
	}
	
	private function set_marginTop(value:String):String 
	{
		return value;
	}
	
	private function get_marginBottom():String 
	{
		return "";
	}
	
	private function set_marginBottom(value:String):String 
	{
		return value;
	}
	
	private function get_paddingLeft():String 
	{
		return "";
	}
	
	private function set_paddingLeft(value:String):String 
	{
		return value;
	}
	
	private function get_paddingRight():String 
	{
		return "";
	}
	
	private function set_paddingRight(value:String):String
	{
		return value;
	}
	
	private function get_paddingTop():String 
	{
		return "";
	}
	
	private function set_paddingTop(value:String):String 
	{
		return value;
	}
	
	private function get_paddingBottom():String 
	{
		return "";
	}
	
	private function set_paddingBottom(value:String):String 
	{
		return value;
	}
	
	private function get_display():String 
	{
		return "";
	}
	
	private function set_display(value:String):String 
	{
		return value;
	}
	
	private function get_position():String 
	{
		return "";
	}
	
	private function set_position(value:String):String 
	{
		return value;
	}
	
	private function get_width():String 
	{
		return "";
	}
	
	private function set_width(value:String):String 
	{
		return value;
	}
	
	private function get_height():String 
	{
		return "";
	}
	
	private function set_height(value:String):String 
	{
		return value;
	}
	
	private function get_minHeight():String 
	{
		return "";
	}
	
	private function set_minHeight(value:String):String 
	{
		return value;
	}
	
	private function get_maxHeight():String 
	{
		return "";
	}

	private function set_maxHeight(value:String):String 
	{
		return value;
	}
	
	private function get_minWidth():String 
	{
		return "";
	}
		
	private function set_minWidth(value:String):String 
	{
		return value;
	}
	
	private function get_maxWidth():String 
	{
		return "";
	}
	
	private function set_maxWidth(value:String):String 
	{
		return value;
	}
	
	private function get_top():String 
	{
		return "";
	}
	
	private function set_top(value:String):String 
	{
		return value;
	}
	
	private function get_left():String 
	{
		return "";
	}
		
	private function set_left(value:String):String 
	{
		return value;
	}
	
	private function get_bottom():String 
	{
		return "";
	}
	
	private function set_bottom(value:String):String 
	{
		return value;
	}
	
	private function get_right():String 
	{
		return "";
	}
	
	private function set_right(value:String):String 
	{
		return value;
	}
	
	private function get_CSSFloat():String 
	{
		return "";
	}
	
	private function set_CSSFloat(value:String):String 
	{
		return value;
	}
	
	private function get_clear():String 
	{
		return "";
	}
	
	private function set_clear(value:String):String 
	{
		return value;
	}
	
	private function get_fontSize():String
	{
		return "";
	}
	
	private function set_fontSize(value:String):String
	{
		return value;
	}
	
	private function get_fontWeight():String
	{
		return "";
	}
	
	private function set_fontWeight(value:String):String
	{
		return value;
	}
	
	private function get_fontStyle():String
	{
		return "";
	}
	
	private function set_fontStyle(value:String):String
	{
		return value;
	}
	
	private function get_fontFamily():String
	{
		return "";
	}
	
	private function set_fontFamily(value:String):String
	{
		return value;
	}

	private function get_fontVariant():String
	{
		return "";
	}
	
	private function set_fontVariant(value:String):String
	{
		return value;
	}
	
	private function get_textTransform():String
	{
		return "";
	}
	
	private function set_textTransform(value:String):String
	{
		return value;
	}
	
	private function get_letterSpacing():String
	{
		return "";
	}
	
	private function set_letterSpacing(value:String):String
	{
		return value;
	}
	
	private function get_color():String
	{
		return "";
	}
	
	private function set_color(value:String):String
	{
		return value;
	}
	
	private function get_wordSpacing():String
	{
		return "";
	}
	
	private function set_wordSpacing(value:String):String
	{
		return value;
	}
	
	private function get_lineHeight():String
	{
		return "";
	}
	
	private function set_lineHeight(value:String):String
	{
		return value;
	}
	
	private function get_verticalAlign():String
	{
		return "";
	}
	
	private function set_verticalAlign(value:String):String
	{
		return value;
	}
	
	private function get_textIndent():String
	{
		return "";
	}
	
	private function set_textIndent(value:String):String
	{
		return value;
	}
	
	private function get_whiteSpace():String
	{
		return "";
	}
	
	private function set_whiteSpace(value:String):String
	{
		return value;
	}
	
	private function get_textAlign():String
	{
		return "";
	}
	
	private function set_textAlign(value:String):String
	{
		return value;
	}
	
	private function set_backgroundColor(value:String):String
	{
		return value;
	}
	
	private function get_backgroundColor():String
	{
		return "";
	}
	
	private function set_backgroundImage(value:String):String
	{
		return value;
	}
	
	private function get_backgroundImage():String
	{
		return "";
	}
	
	private function set_backgroundRepeat(value:String):String
	{
		return value;
	}
	
	private function get_backgroundRepeat():String
	{
		return "";
	}
	
	private function set_backgroundSize(value:String):String
	{
		return value;
	}
	
	private function get_backgroundSize():String
	{
		return "";
	}
	
	private function set_backgroundClip(value:String):String
	{
		return value;
	}
	
	private function get_backgroundClip():String
	{
		return "";
	}
	
	private function set_backgroundPosition(value:String):String
	{
		return value;
	}
	
	private function get_backgroundPosition():String
	{
		return "";
	}
	
	private function set_backgroundOrigin(value:String):String
	{
		return value;
	}
	
	private function get_backgroundOrigin():String
	{
		return "";
	}
	
	private function get_overflowX():String
	{
		return "";
	}
	
	private function set_overflowX(value:String):String
	{
		return value;
	}
	
	private function get_overflowY():String
	{
		return "";
	}
	
	private function set_overflowY(value:String):String
	{
		return value;
	}
	
	private function set_cursor(value:String):String
	{
		return value;
	}
	
	private function get_cursor():String
	{
		return "";
	}
	
}