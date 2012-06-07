/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.geom.GeomData;
import cocktail.core.geom.Matrix;
import cocktail.core.style.transition.Transition;
import cocktail.core.style.transition.TransitionManager;
import cocktail.core.unit.UnitData;
import cocktail.core.style.StyleData;

/**
 * This class holds the computed values of a style
 * object which are the value which can actually
 * be used during layout. 
 * 
 * For instance a width
 * value specified as 'auto' will be computed
 * into an absolute pixel during layout
 * 
 * @author Yannick DOMINGUEZ
 */
class ComputedStyle 
{

	/////////////////////////////////
	// STYLES attributes
	////////////////////////////////
	
	/**
	 * display styles
	 */
	private var _display:Display;
	public var display(getDisplay, setDisplay):Display;
	
	private var _position:Position;
	public var position(getPosition, setPosition):Position;
	
	private var _cssFloat:CSSFloat;
	public var cssFloat(getCSSFloat, setCSSFloat):CSSFloat;
	
	private var _clear:Clear;
	public var clear(getClear, setClear):Clear;
	
	private var _zIndex:ZIndex;
	public var zIndex(getZIndex, setZIndex):ZIndex;
	
	private var _transformOrigin:PointData;
	public var transformOrigin(getTransformOrigin, setTransformOrigin):PointData;
	
	private var _transform:Matrix;
	public var transform(getTransform, setTransform):Matrix;
	
	/**
	 * box model styles
	 */
	private var _marginLeft:Int;
	public var marginLeft(getMarginLeft, setMarginLeft):Int;
	private var _marginRight:Int;
	public var marginRight(getMarginRight, setMarginRight):Int;
	private var _marginTop:Int;
	public var marginTop(getMarginTop, setMarginTop):Int;
	private var _marginBottom:Int;
	public var marginBottom(getMarginBottom, setMarginBottom):Int;
	
	private var _paddingLeft:Int;
	public var paddingLeft(getPaddingLeft, setPaddingLeft):Int;
	private var _paddingRight:Int;
	public var paddingRight(getPaddingRight, setPaddingRight):Int;
	private var _paddingTop:Int;
	public var paddingTop(getPaddingTop, setPaddingTop):Int;
	private var _paddingBottom:Int;
	public var paddingBottom(getPaddingBottom, setPaddingBottom):Int;

	private var _width:Int;
	public var width(getWidth, setWidth):Int;
	private var _height:Int;
	public var height(getHeight, setHeight):Int;
	
	private var _minHeight:Int;
	public var minHeight(getMinHeight, setMinHeight):Int;
	private var _maxHeight:Int;
	public var maxHeight(getMaxHeight, setMaxHeight):Int;
	private var _minWidth:Int;
	public var minWidth(getMinWidth, setMinWidth):Int;
	private var _maxWidth:Int;
	public var maxWidth(getMaxWidth, setMaxWidth):Int;

	private var _top:Int;
	public var top(getTop, setTop):Int;
	private var _left:Int;
	public var left(getLeft, setLeft):Int;
	private var _bottom:Int;
	public var bottom(getBottom, setBottom):Int;
	private var _right:Int;
	public var right(getRight, setRight):Int;
	
	/**
	 * background styles
	 */
	private var _backgroundColor:ColorData;
	public var backgroundColor(getBackgroundColor, setBackgroundColor):ColorData;
	
	private var _backgroundImage:Array<BackgroundImage>;
	public var backgroundImage(getBackgroundImage, setBackgroundImage):Array<BackgroundImage>;
	
	private var _backgroundRepeat:Array<BackgroundRepeat>;
	public var backgroundRepeat(getBackgroundRepeat, setBackgroundRepeat):Array<BackgroundRepeat>;
	
	private var _backgroundOrigin:Array<BackgroundOrigin>;
	public var backgroundOrigin(getBackgroundOrigin, setBackgroundOrigin):Array<BackgroundOrigin>;
	
	private var _backgroundSize:Array<BackgroundSize>;
	public var backgroundSize(getBackgroundSize, setBackgroundSize):Array<BackgroundSize>;
	
	private var _backgroundPosition:Array<BackgroundPosition>;
	public var backgroundPosition(getBackgroundPosition, setBackgroundPosition):Array<BackgroundPosition>;
	
	private var _backgroundClip:Array<BackgroundClip>;
	public var backgroundClip(getBackgroundClip, setBackgroundClip):Array<BackgroundClip>;
	
	/**
	 * font styles
	 */
	private var _fontSize:Float;
	public var fontSize(getFontSize, setFontSize):Float;
	
	private var _fontWeight:FontWeight;
	public var fontWeight(getFontWeight, setFontWeight):FontWeight;
	
	private var _fontStyle:FontStyle;
	public var fontStyle(getFontStyle, setFontStyle):FontStyle;
	
	private var _fontFamily:Array<String>;
	public var fontFamily(getFontFamily, setFontFamily ):Array<String>;
	
	private var _fontVariant:FontVariant;
	public var fontVariant(getFontVariant, setFontVariant):FontVariant;
	
	private var _color:ColorData;
	public var color(getColor, setColor):ColorData;
	
	/**
	 * text styles
	 */
	private var _lineHeight:Float;
	public var lineHeight(getLineHeight, setLineHeight):Float;
	
	private var _textTransform:TextTransform;
	public var textTransform(getTextTransform, setTextTransform):TextTransform;
	
	private var _letterSpacing:Int;
	public var letterSpacing(getLetterSpacing, setLetterSpacing):Int;
	
	private var _wordSpacing:Int;
	public var wordSpacing(getWordSpacing, setWordSpacing):Int;
	
	private var _whiteSpace:WhiteSpace;
	public var whiteSpace(getWhiteSpace, setWhiteSpace):WhiteSpace;
	
	private var _textAlign:TextAlign;
	public var textAlign(getTextAlign, setTextAlign):TextAlign;
	
	private var _textIndent:Int;
	public var textIndent(getTextIndent, setTextIndent):Int;
		
	private var _verticalAlign:Float;
	public var verticalAlign(getVerticalAlign, setVerticalAlign):Float;
	
	/**
	 * visual effect styles
	 */
	private var _opacity:Float;
	public var opacity(getOpacity, setOpacity):Float;
	
	private var _visibility:Bool;
	public var visibility(getVisibility, setVisibility):Bool;
	
	private var _overflowX:Overflow;
	public var overflowX(getOverflowX,  setOverflowX):Overflow;
	
	private var _overflowY:Overflow;
	public var overflowY(getOverflowY,  setOverflowY):Overflow;
	
	/**
	 * user interface styles
	 */
	private var _cursor:Cursor;
	public var cursor(getCursor, setCursor):Cursor;
	
	/**
	 * transition styles
	 */
	private var _transitionProperty:TransitionProperty;
	public var transitionProperty(getTransitionProperty, setTransitionProperty):TransitionProperty;
	
	private var _transitionDuration:Array<Float>;
	public var transitionDuration(getTransitionDuration, setTransitionDuration):Array<Float>;
	
	private var _transitionDelay:Array<Float>;
	public var transitionDelay(getTransitionDelay, setTransitionDelay):Array<Float>;
	
	private var _transitionTimingFunction:TransitionTimingFunction;
	public var transitionTimingFunction(getTransitionTimingFunction, setTransitionTimingFunction):TransitionTimingFunction;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	/**
	 * Set the default value on every styles
	 */
	public function init():Void
	{
		_width = 0;
		_height = 0;
		_minHeight = 0;
		_maxHeight = 0;
		_minWidth = 0;
		_maxWidth = 0;
		_marginLeft = 0;
		_marginRight = 0;
		_marginTop = 0;
		_marginBottom = 0;
		_paddingLeft = 0;
		_paddingRight = 0;
		_paddingTop = 0;
		_paddingBottom = 0;
		_left= 0;
		_right= 0;
		_top= 0;
		_bottom = 0;
		_clear = Clear.none;
		_cssFloat = CSSFloat.none;
		_display = Display.cssInline;
		_position= Position.cssStatic;
		_verticalAlign = 0.0;
		_fontSize=16.0;
		_lineHeight=14.0;
		_fontWeight=FontWeight.normal;
		_fontStyle=FontStyle.normal;
		_fontFamily=["serif"];
		_fontVariant=FontVariant.normal;
		_textTransform=TextTransform.none;
		_letterSpacing=0;
		_wordSpacing=0;
		_textIndent=0;
		_whiteSpace=WhiteSpace.normal;
		_textAlign=TextAlign.left;
		_color={color:0, alpha:1.0};
		_visibility=true;
		_zIndex=ZIndex.cssAuto;
		_opacity=1.0;
		_overflowX= Overflow.visible;
		_overflowY= Overflow.visible;
		_transformOrigin= { x:0.0, y:0.0 };
		_transform=new Matrix();
		_backgroundColor={color:0, alpha:1.0};
		_backgroundSize=[];
		_backgroundOrigin=[];
		_backgroundImage=[];
		_backgroundClip=[];
		_backgroundPosition=[];
		_backgroundRepeat=[];
		_cursor = Cursor.cssDefault;
		_transitionDelay = [];
		_transitionDuration = [];
		_transitionProperty = TransitionProperty.all;
		_transitionTimingFunction = [];
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method to return the value of a property which can be transitioned
	 * If the property is currently being transitioned, return the current value
	 * of the transition, else return the computed value of the property
	 * @param	propertyName the name of the property whose value is returned
	 * @param	propertyValue the computed value of the property, returned if
	 * the property is not transitioning
	 */
	private function getTransitionablePropertyValue(propertyName:String, propertyValue:Float):Float
	{
		//try to get a transition for the property
		var transition:Transition = TransitionManager.getInstance().getTransition(propertyName, this);
		//if there actually is a transition in progress for this property,
		//return its current value
		if (transition != null)
		{
			return transition.currentValue;
		}
		else
		{
			return propertyValue;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setWidth(value:Int):Int 
	{
		_width = value;
		return value;
	}
	
	private function setMarginLeft(value:Int):Int 
	{
		_marginLeft = value;
		return value;
	}
	
	private function setMarginRight(value:Int):Int 
	{
		_marginRight = value;
		return value;
	}
	
	private function setMarginTop(value:Int):Int 
	{
		_marginTop = value;
		return value;
	}
	
	private function setMarginBottom(value:Int):Int 
	{
		_marginBottom = value;
		return value;
	}
	
	private function setPaddingLeft(value:Int):Int 
	{
		_paddingLeft = value;
		return value;
	}
	
	private function setPaddingRight(value:Int):Int 
	{
		_paddingRight = value;
		return value;
	}
	
	private function setPaddingTop(value:Int):Int 
	{
		_paddingTop = value;
		return value;
	}
	
	private function setPaddingBottom(value:Int):Int 
	{
		_paddingBottom = value;
		return value;
	}
	
	private function setDisplay(value:Display):Display 
	{
		_display = value;
		return value;
	}
	
	private function setPosition(value:Position):Position 
	{
		_position = value;
		return value;
	}
	
	private function setHeight(value:Int):Int 
	{
		_height = value;
		return value;
	}
	
	private function setMinHeight(value:Int):Int 
	{
		_minHeight = value;
		return value;
	}
	
	private function setMaxHeight(value:Int):Int 
	{
		_maxHeight = value;
		return value;
	}
	
	private function setMinWidth(value:Int):Int 
	{
		_minWidth = value;
		return value;
	}
	
	private function setMaxWidth(value:Int):Int 
	{
		_maxWidth = value;
		return value;
	}
	
	private function setTop(value:Int):Int 
	{
		_top = value;
		return value;
	}
	
	private function setLeft(value:Int):Int 
	{
		_left = value;
		return value;
	}
	
	private function setBottom(value:Int):Int 
	{
		_bottom = value;
		return value;
	}
	
	private function setRight(value:Int):Int 
	{
		_right = value;
		return value;
	}
	
	private function setCSSFloat(value:CSSFloat):CSSFloat 
	{
		_cssFloat = value;
		return value;
	}
	
	private function setClear(value:Clear):Clear 
	{
		_clear = value;
		return value;
	}
	
	private function setZIndex(value:ZIndex):ZIndex 
	{
		_zIndex = value;
		return value;
	}
	
	private function setFontSize(value:Float):Float
	{
		_fontSize = value;
		return value;
	}
	
	private function setFontWeight(value:FontWeight):FontWeight
	{
		_fontWeight = value;
		return value;
	}
	
	private function setFontStyle(value:FontStyle):FontStyle
	{
		_fontStyle = value;
		return value;
	}
	
	private function setFontFamily(value:Array<String>):Array<String>
	{
		_fontFamily = value;
		return value;
	}
	
	private function setFontVariant(value:FontVariant):FontVariant
	{
		_fontVariant = value;
		return value;
	}
	
	private function setTextTransform(value:TextTransform):TextTransform
	{
		_textTransform = value;
		return value;
	}
	
	private function setLetterSpacing(value:Int):Int
	{
		_letterSpacing = value;
		return value;
	}
	
	private function setWordSpacing(value:Int):Int
	{
		_wordSpacing = value;
		return value;
	}
	
	private function setLineHeight(value:Float):Float
	{
		_lineHeight = value;
		return value;
	}
	
	private function setColor(value:ColorData):ColorData
	{
		_color = value;
		return value;
	}
	
	private function setVerticalAlign(value:Float):Float
	{
		_verticalAlign = value;
		return value;
	}
	
	private function setTextIndent(value:Int):Int
	{
		_textIndent = value;
		return value;
	}
	
	private function setWhiteSpace(value:WhiteSpace):WhiteSpace
	{
		_whiteSpace = value;
		return value;
	}
	
	private function setTextAlign(value:TextAlign):TextAlign
	{
		 _textAlign = value;
		return value;
	}
	
	private function setOpacity(value:Float):Float
	{
		_opacity = value;
		return _opacity;
	}
	
	private function setVisibility(value:Bool):Bool
	{
		_visibility = value;
		return _visibility;
	}
	
	private function setTransformOrigin(value:PointData):PointData
	{
		_transformOrigin = value;
		return value;
	}
	
	private function setTransform(value:Matrix):Matrix
	{
		_transform = value;
		return value;
	}
	
	private function setOverflowX(value:Overflow):Overflow
	{
		_overflowX = value;
		return value;
	}
	
	private function setOverflowY(value:Overflow):Overflow
	{
		_overflowY = value;
		return value;
	}
	
	private function setTransitionProperty(value:TransitionProperty):TransitionProperty
	{
		return _transitionProperty = value;
	}
	
	private function setTransitionDuration(value:Array<Float>):Array<Float>
	{
		return _transitionDuration = value;
	}
	
	private function setTransitionDelay(value:Array<Float>):Array<Float>
	{
		return _transitionDelay = value;
	}
	
	private function setTransitionTimingFunction(value:TransitionTimingFunction):TransitionTimingFunction
	{
		return _transitionTimingFunction = value;
	}
	
	/////////////////////////////////
	// GETTERS
	////////////////////////////////
	
	private function getOpacity():Float
	{
		return getTransitionablePropertyValue(CSSConstants.OPACITY_STYLE_NAME, _opacity);
	}
	
	private function getVisibility():Bool
	{
		return _visibility;
	}
	
	private function getMarginLeft():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MARGIN_LEFT_STYLE_NAME, _marginLeft));
	}
	
	private function getMarginRight():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MARGIN_RIGHT_STYLE_NAME, _marginRight));
	}
	
	private function getMarginTop():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MARGIN_TOP_STYLE_NAME, _marginTop));
	}
	
	private function getMarginBottom():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MARGIN_BOTTOM_STYLE_NAME, _marginBottom));
	}
	
	private function getPaddingLeft():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.PADDING_LEFT_STYLE_NAME, _paddingLeft));
	}
	
	private function getPaddingRight():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.PADDING_RIGHT_STYLE_NAME, _paddingRight));
	}
	
	private function getPaddingTop():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.PADDING_TOP_STYLE_NAME, _paddingTop));
	}
	
	private function getPaddingBottom():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.PADDING_BOTTOM_STYLE_NAME, _paddingBottom));
	}
	
	private function getDisplay():Display 
	{
		return _display;
	}
	
	private function getPosition():Position 
	{
		return _position;
	}
	
	private function getWidth():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.WIDTH_STYLE_NAME, _width));
	}
	
	private function getHeight():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.HEIGHT_STYLE_NAME, _height));
	}
	
	private function getMinHeight():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MIN_HEIGHT_STYLE_NAME, _minHeight));
	}
	
	private function getMaxHeight():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MAX_HEIGHT_STYLE_NAME, _maxHeight));
	}
	
	private function getMinWidth():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MIN_WIDTH_STYLE_NAME, _minWidth));
	}
	
	private function getMaxWidth():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.MAX_WIDTH_STYLE_NAME, _maxWidth));
	}
	
	private function getTop():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.TOP_STYLE_NAME, _top));
	}
	
	private function getLeft():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.LEFT_STYLE_NAME, _left));
	}
	
	private function getBottom():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.BOTTOM_STYLE_NAME, _bottom));
	}
	
	private function getRight():Int 
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.RIGHT_STYLE_NAME, _right));
	}
	
	private function getCSSFloat():CSSFloat 
	{
		return _cssFloat;
	}
	
	private function getClear():Clear 
	{
		return _clear;
	}
	
	private function getZIndex():ZIndex 
	{
		return _zIndex;
	}
	
	private function getFontSize():Float
	{
		return getTransitionablePropertyValue(CSSConstants.FONT_SIZE_STYLE_NAME, _fontSize);
	}
	
	private function getFontWeight():FontWeight
	{
		return _fontWeight;
	}
	
	private function getFontStyle():FontStyle
	{
		return _fontStyle;
	}
	
	private function getFontFamily():Array<String>
	{
		return _fontFamily;
	}
	
	private function getFontVariant():FontVariant
	{
		return _fontVariant;
	}
	
	private function getTextTransform():TextTransform
	{
		return _textTransform;
	}
	
	private function getLetterSpacing():Int
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.LETTER_SPACING_STYLE_NAME, _letterSpacing));
	}
	
	private function getColor():ColorData
	{
		return _color;
	}
	
	private function getWordSpacing():Int
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.WORD_SPACING_STYLE_NAME, _wordSpacing));
	}
	
	private function getLineHeight():Float
	{
		return getTransitionablePropertyValue(CSSConstants.LINE_HEIGHT_STYLE_NAME, _lineHeight);
	}
	
	private function getVerticalAlign():Float
	{
		return _verticalAlign;
	}
	
	private function getTextIndent():Int
	{
		return Math.round(getTransitionablePropertyValue(CSSConstants.TEXT_INDENT_STYLE_NAME, _textIndent));
	}
	
	private function getWhiteSpace():WhiteSpace
	{
		return _whiteSpace;
	}
	
	private function getTextAlign():TextAlign
	{
		return _textAlign;
	}
	
	private function getTransform():Matrix
	{
		return _transform;
	}
	
	private function getTransformOrigin():PointData
	{
		return _transformOrigin;
	}
	
	private function setBackgroundColor(value:ColorData):ColorData
	{
		_backgroundColor = value;
		return value;
	}
	
	private function getBackgroundColor():ColorData
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		_backgroundImage = value;
		return value;
	}
	
	private function getBackgroundImage():Array<BackgroundImage>
	{
		return _backgroundImage;
	}
	
	private function setBackgroundRepeat(value:Array<BackgroundRepeat>):Array<BackgroundRepeat>
	{
		return _backgroundRepeat = value;
	}
	
	private function getBackgroundRepeat():Array<BackgroundRepeat>
	{
		return _backgroundRepeat;
	}
	
	private function setBackgroundSize(value:Array<BackgroundSize>):Array<BackgroundSize>
	{
		_backgroundSize = value;
		return value;
	}
	
	private function getBackgroundSize():Array<BackgroundSize>
	{
		return _backgroundSize;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		_backgroundClip = value;
		return value;
	}
	
	private function getBackgroundClip():Array<BackgroundClip>
	{
		return _backgroundClip;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		_backgroundPosition = value;
		return value;
	}
	
	private function getBackgroundPosition():Array<BackgroundPosition>
	{
		return _backgroundPosition;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		_backgroundOrigin = value;
		return value;
	}
	
	private function getBackgroundOrigin():Array<BackgroundOrigin>
	{
		return _backgroundOrigin;
	}
	
	private function getOverflowX():Overflow
	{
		return _overflowX;
	}
	
	private function getOverflowY():Overflow
	{
		return _overflowY;
	}
	
	private function setCursor(value:Cursor):Cursor
	{
		return _cursor = value;
	}
	
	private function getCursor():Cursor
	{
		return _cursor;
	}
	
	private function getTransitionProperty():TransitionProperty
	{
		return _transitionProperty;
	}
	
	private function getTransitionDuration():Array<Float>
	{
		return _transitionDuration;
	}
	
	private function getTransitionDelay():Array<Float>
	{
		return _transitionDelay;
	}
	
	private function getTransitionTimingFunction():TransitionTimingFunction
	{
		return _transitionTimingFunction;
	}
	
}