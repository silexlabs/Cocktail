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
	public var clear(get_Clear, set_Clear):String;
	
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
	
	private function getOpacity():String
	{
		return _opacity;
	}
	
	private function setOpacity(value:String):String
	{
		return value;
	}
	
	private function getVisibility():String
	{
		return _visibility;
	}
	
	private function setVisibility(value:String):String
	{
		return value;
	}
	
	private function getMarginLeft():String 
	{
		return _marginLeft;
	}
	
	private function setMarginLeft(value:String):String 
	{
		return value;
	}
	
	private function getMarginRight():String 
	{
		return _marginRight;
	}
	
	private function setMarginRight(value:String):String 
	{
		return value;
	}
	
	
	private function getMarginTop():String 
	{
		return _marginTop;
	}
	
	private function setMarginTop(value:String):String 
	{
		return value;
	}
	
	private function getMarginBottom():String 
	{
		return _marginBottom;
	}
	
	private function setMarginBottom(value:String):String 
	{
		return value;
	}
	
	private function getPaddingLeft():String 
	{
		return _paddingLeft;
	}
	
	private function setPaddingLeft(value:String):String 
	{
		return value;
	}
	
	private function getPaddingRight():String 
	{
		return _paddingRight;
	}
	
	private function setPaddingRight(value:String):String
	{
		return value;
	}
	
	private function getPaddingTop():String 
	{
		return _paddingTop;
	}
	
	private function setPaddingTop(value:String):String 
	{
		return value;
	}
	
	private function getPaddingBottom():String 
	{
		return _paddingBottom;
	}
	
	private function setPaddingBottom(value:String):String 
	{
		return value;
	}
	
	private function getDisplay():String 
	{
		return _display;
	}
	
	private function setDisplay(value:String):String 
	{
		return value;
	}
	
	private function getPosition():String 
	{
		return _position;
	}
	
	private function setPosition(value:String):String 
	{
		return value;
	}
	
	private function getWidth():String 
	{
		return _width;
	}
	
	private function setWidth(value:String):String 
	{
		return value;
	}
	
	private function getHeight():String 
	{
		return _height;
	}
	
	private function setHeight(value:String):String 
	{
		return value;
	}
	
	private function getMinHeight():String 
	{
		return _minHeight;
	}
	
	private function setMinHeight(value:String):String 
	{
		return value;
	}
	
	private function getMaxHeight():String 
	{
		return _maxHeight;
	}

	private function setMaxHeight(value:String):String 
	{
		return value;
	}
	
	private function getMinWidth():String 
	{
		return _minWidth;
	}
	
		
	private function setMinWidth(value:String):String 
	{
		return value;
	}
	
	private function getMaxWidth():String 
	{
		return _maxWidth;
	}
	
	private function setMaxWidth(value:String):String 
	{
		return value;
	}
	
	private function getTop():String 
	{
		return _top;
	}
	
	private function setTop(value:String):String 
	{
		return value;
	}
	
	private function getLeft():String 
	{
		return _left;
	}
		
	private function setLeft(value:String):String 
	{
		return value;
	}
	
	private function getBottom():String 
	{
		return _bottom;
	}
	
	private function setBottom(value:String):String 
	{
		return value;
	}
	
	private function getRight():String 
	{
		return _right;
	}
	
	private function setRight(value:String):String 
	{
		return value;
	}
	
	private function getCSSFloat():String 
	{
		return _cssFloat;
	}
	
	private function setCSSFloat(value:String):String 
	{
		return value;
	}
	
	
	private function getClear():String 
	{
		return _clear;
	}
	
	private function setClear(value:String):String 
	{
		return value;
	}
	
	private function getFontSize():String
	{
		return _fontSize;
	}
	
	private function setFontSize(value:String):String
	{
		return value;
	}
	
	private function getFontWeight():String
	{
		return _fontWeight;
	}
	
	private function setFontWeight(value:String):String
	{
		return value;
	}
	
	
	private function getFontStyle():String
	{
		return _fontStyle;
	}
	
	private function setFontStyle(value:String):String
	{
		return value;
	}
	
	
	private function getFontFamily():String
	{
		return _fontFamily;
	}
	
	private function setFontFamily(value:String):String
	{
		return value;
	}

	private function getFontVariant():String
	{
		return _fontVariant;
	}
	
	private function setFontVariant(value:String):String
	{
		return value;
	}
	
	private function getTextTransform():String
	{
		return _textTransform;
	}
	
	private function setTextTransform(value:String):String
	{
		return value;
	}
	
	private function getLetterSpacing():String
	{
		return _letterSpacing;
	}
	
	private function setLetterSpacing(value:String):String
	{
		return value;
	}
	
	private function getColor():String
	{
		return _color;
	}
	
	private function setColor(value:String):String
	{
		return value;
	}
	
	private function getWordSpacing():String
	{
		return _wordSpacing;
	}
	
	private function setWordSpacing(value:String):String
	{
		return value;
	}
	
	
	
	private function getLineHeight():String
	{
		return _lineHeight;
	}
	
	private function setLineHeight(value:String):String
	{
		return value;
	}
	
	private function getVerticalAlign():String
	{
		return _verticalAlign;
	}
	
	private function setVerticalAlign(value:String):String
	{
		return value;
	}
	
	private function getTextIndent():String
	{
		return _textIndent;
	}
	
	private function setTextIndent(value:String):String
	{
		return value;
	}
	
	private function getWhiteSpace():String
	{
		return _whiteSpace;
	}
	
	private function setWhiteSpace(value:String):String
	{
		return value;
	}
	
	private function getTextAlign():String
	{
		return _textAlign;
	}
	
	private function setTextAlign(value:String):String
	{
		return value;
	}
	
	private function setBackgroundColor(value:String):String
	{
		return value;
	}
	
	private function getBackgroundColor():String
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:String):String
	{
		return value;
	}
	
	private function getBackgroundImage():String
	{
		return _backgroundImage;
	}
	
	private function setBackgroundRepeat(value:String):String
	{
		return value;
	}
	
	private function getBackgroundRepeat():String
	{
		return _backgroundRepeat;
	}
	
	private function setBackgroundSize(value:String):String
	{
		return value;
	}
	
	private function getBackgroundSize():String
	{
		return _backgroundSize;
	}
	
	private function setBackgroundClip(value:String):String
	{
		return value;
	}
	
	private function getBackgroundClip():String
	{
		return _backgroundClip;
	}
	
	private function setBackgroundPosition(value:String):String
	{
		return value;
	}
	
	private function getBackgroundPosition():String
	{
		return _backgroundPosition;
	}
	
	private function setBackgroundOrigin(value:String):String
	{
		return value;
	}
	
	private function getBackgroundOrigin():String
	{
		return _backgroundOrigin;
	}
	
	private function getOverflowX():String
	{
		return _overflowX;
	}
	
	private function setOverflowX(value:String):String
	{
		return value;
	}
	
	private function getOverflowY():String
	{
		return _overflowY;
	}
	
	private function setOverflowY(value:String):String
	{
		return value;
	}
	
	private function setCursor(value:String):String
	{
		return value;
	}
	
	private function getCursor():String
	{
		return _cursor;
	}
	
}