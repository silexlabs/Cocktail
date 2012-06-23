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
	public var display:Display;
	public var position:Position;
	public var cssFloat:CSSFloat;
	public var clear:Clear;
	public var zIndex:ZIndex;
	public var transformOrigin:PointData;
	public var transform:Matrix;
	
	/**
	 * box model styles
	 */
	public var marginLeft(getMarginLeft, set_marginLeft):Float;
	public var marginRight(getMarginRight, set_marginRight):Float;
	public var marginTop(getMarginTop, set_marginTop):Float;
	public var marginBottom(getMarginBottom, set_marginBottom):Float;
	
	
	public var paddingLeft(getPaddingLeft, set_paddingLeft):Float;
	public var paddingRight(getPaddingRight, set_paddingRight):Float;
	public var paddingTop(getPaddingTop, set_paddingTop):Float;
	public var paddingBottom(getPaddingBottom, set_paddingBottom):Float;

	public var width(getWidth, set_width):Float;
	public var height(getHeight, set_height):Float;
	
	//TODO 2 : when setting one of those values, should constrain
	//width/height
	public var minHeight(getMinHeight, set_minHeight):Float;
	public var maxHeight(getMaxHeight, set_maxHeight):Float;
	public var minWidth(getMinWidth, set_minWidth):Float;
	public var maxWidth(getMaxWidth, set_maxWidth):Float;

	public var top(getTop, set_top):Float;
	public var left(getLeft, set_left):Float;
	public var bottom(getBottom, set_bottom):Float;
	public var right(getRight, set_right):Float;
	
	/**
	 * background styles
	 */
	public var backgroundColor:ColorData;
	public var backgroundImage:Array<BackgroundImage>;
	public var backgroundRepeat:Array<BackgroundRepeat>;
	public var backgroundOrigin:Array<BackgroundOrigin>;
	public var backgroundSize:Array<BackgroundSize>;
	public var backgroundPosition:Array<BackgroundPosition>;
	public var backgroundClip:Array<BackgroundClip>;
	
	/**
	 * font styles
	 */
	public var fontSize(getFontSize, set_fontSize):Float;
	public var fontWeight:FontWeight;
	public var fontStyle:FontStyle;
	public var fontFamily:Array<String>;
	public var fontVariant:FontVariant;
	public var color:ColorData;
	
	/**
	 * text styles
	 */
	public var lineHeight(getLineHeight, set_lineHeight):Float;
	public var textTransform:TextTransform;
	public var letterSpacing(getLetterSpacing, set_letterSpacing):Float;
	public var wordSpacing(getWordSpacing, set_wordSpacing):Float;
	public var whiteSpace:WhiteSpace;
	public var textAlign:TextAlign;
	public var textIndent(getTextIndent, set_textIndent):Float;
	public var verticalAlign:Float;
	
	/**
	 * visual effect styles
	 */
	public var opacity(getOpacity, set_opacity):Float;
	public var visibility:Visibility;
	public var overflowX:Overflow;
	public var overflowY:Overflow;
	
	/**
	 * user interface styles
	 */
	public var cursor:Cursor;
	
	/**
	 * transition styles
	 */
	public var transitionProperty:TransitionProperty;
	public var transitionDuration:Array<Float>;
	public var transitionDelay:Array<Float>;
	public var transitionTimingFunction:TransitionTimingFunction;
	
	/**
	 * A reference to the style used to computed those coputedStyles
	 */
	private var _coreStyle:CoreStyle;
	
	/**
	 * class constructor
	 */
	public function new(coreStyle:CoreStyle) 
	{
		_coreStyle = coreStyle;
	}
	
	/**
	 * Set the default value on every styles
	 */
	public function init():Void
	{
		minHeight = 0.0;
		maxHeight = 0.0;
		minWidth = 0.0;
		maxWidth = 0.0;
		width = 0.0;
		height = 0.0;
		marginLeft = 0.0;
		marginRight = 0.0;
		marginTop = 0.0;
		marginBottom = 0.0;
		paddingLeft = 0.0;
		paddingRight = 0.0;
		paddingTop = 0.0;
		paddingBottom = 0.0;
		left= 0.0;
		right= 0.0;
		top= 0.0;
		bottom = 0.0;
		clear = Clear.none;
		cssFloat = CSSFloat.none;
		display = Display.cssInline;
		position= Position.cssStatic;
		verticalAlign = 0.0;
		fontSize=16.0;
		lineHeight=14.0;
		fontWeight=FontWeight.normal;
		fontStyle=FontStyle.normal;
		fontFamily=["serif"];
		fontVariant=FontVariant.normal;
		textTransform=TextTransform.none;
		letterSpacing=0;
		wordSpacing=0;
		textIndent=0;
		whiteSpace=WhiteSpace.normal;
		textAlign=TextAlign.left;
		color={color:0, alpha:1.0};
		visibility=Visibility.visible;
		zIndex=ZIndex.cssAuto;
		opacity=1.0;
		overflowX= Overflow.visible;
		overflowY= Overflow.visible;
		transformOrigin= { x:0.0, y:0.0 };
		transform=new Matrix();
		backgroundColor={color:0, alpha:1.0};
		backgroundSize=[];
		backgroundOrigin=[];
		backgroundImage=[];
		backgroundClip=[];
		backgroundPosition=[];
		backgroundRepeat=[];
		cursor = Cursor.cssDefault;
		transitionDelay = [];
		transitionDuration = [];
		transitionProperty = TransitionProperty.all;
		transitionTimingFunction = [];
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
	// PRIVATE DIMENSIONS CONSTRAINTS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Constrain computed width if it is above/below max/min width
	 */
	private function constrainWidth(style:CoreStyle, computedWidth:Float):Float
	{
		var computedStyle:ComputedStyle = style.computedStyle;
		
		//check that the computedWidth is not 
		//superior to max width. The max width
		//can be defined as "none" if there are 
		//no width limit on this HTMLElement
		if (style.maxWidth != ConstrainedDimension.none)
		{
			if (computedWidth > computedStyle.maxWidth)
			{
				computedWidth = computedStyle.maxWidth;
			}
		}
		
		//check that width is superior to min width
		if (computedWidth < computedStyle.minWidth)
		{
			computedWidth = computedStyle.minWidth;
		}
		
		return computedWidth;
	}
	
	/**
	 * Constrain computed height if it is above/below max/min height
	 */
	private function constrainHeight(style:CoreStyle, computedHeight:Float):Float
	{
		var computedStyle:ComputedStyle = style.computedStyle;
	
		//check that height is within authorised range
		if (style.maxHeight != ConstrainedDimension.none)
		{
			if (computedHeight > computedStyle.maxHeight)
			{
				computedHeight = computedStyle.maxHeight;
			}
		}
		
		//check that height is superior to min height
		if (computedHeight < computedStyle.minHeight)
		{
			computedHeight = computedStyle.minHeight;
		}
		
		return computedHeight;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTER
	//////////////////////////////////////////////////////////////////////////////////////////

	private function set_width(value:Float):Float 
	{
		width = constrainWidth(_coreStyle, value);
		return value;
	}
	
	private function set_height(value:Float):Float 
	{
		height = constrainHeight(_coreStyle, value);
		return value;
	}
	
	private function set_marginLeft(value:Float):Float
	{
		return marginLeft = value;
	}
	
	private function set_marginTop(value:Float):Float
	{
		return marginTop = value;
	}
	
	private function set_marginBottom(value:Float):Float
	{
		return marginBottom = value;
	}
	
	private function set_marginRight(value:Float):Float
	{
		return marginRight = value;
	}
	
	private function set_paddingTop(value:Float):Float
	{
		return paddingTop = value;
	}
	
	private function set_paddingBottom(value:Float):Float
	{
		return paddingBottom = value;
	}
	
	private function set_paddingLeft(value:Float):Float
	{
		return paddingLeft = value;
	}
	
	private function set_paddingRight(value:Float):Float
	{
		return paddingRight = value;
	}
	
	private function set_minHeight(value:Float):Float
	{
		return minHeight = value;
	}
	
	private function set_minWidth(value:Float):Float
	{
		return minWidth = value;
	}
	
	private function set_maxHeight(value:Float):Float
	{
		return maxHeight = value;
	}
	
	private function set_maxWidth(value:Float):Float
	{
		return maxWidth = value;
	}
	
	private function set_top(value:Float):Float
	{
		return top = value;
	}
	
	private function set_bottom(value:Float):Float
	{
		return bottom = value;
	}
	
	private function set_left(value:Float):Float
	{
		return left = value;
	}
	
	private function set_right(value:Float):Float
	{
		return right = value;
	}
	
	private function set_fontSize(value:Float):Float
	{
		return fontSize = value;
	}
	
	private function set_lineHeight(value:Float):Float
	{
		return lineHeight = value;
	}
	
	private function set_letterSpacing(value:Float):Float
	{
		return letterSpacing = value;
	}
	
	private function set_wordSpacing(value:Float):Float
	{
		return wordSpacing = value;
	}
	
	private function set_textIndent(value:Float):Float
	{
		return textIndent = value;
	}
	
	private function set_opacity(value:Float):Float
	{
		return opacity = value;
	}
	
	/////////////////////////////////
	// GETTERS
	////////////////////////////////
	
	private function getOpacity():Float
	{
		return getTransitionablePropertyValue(CSSConstants.OPACITY_STYLE_NAME, opacity);
	}
	
	private function getMarginLeft():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_LEFT_STYLE_NAME, marginLeft);
	}
	
	private function getMarginRight():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_RIGHT_STYLE_NAME, marginRight);
	}
	
	private function getMarginTop():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_TOP_STYLE_NAME, marginTop);
	}
	
	private function getMarginBottom():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_BOTTOM_STYLE_NAME, marginBottom);
	}
	
	private function getPaddingLeft():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_LEFT_STYLE_NAME, paddingLeft);
	}
	
	private function getPaddingRight():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_RIGHT_STYLE_NAME, paddingRight);
	}
	
	private function getPaddingTop():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_TOP_STYLE_NAME, paddingTop);
	}
	
	private function getPaddingBottom():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_BOTTOM_STYLE_NAME, paddingBottom);
	}
	
	private function getWidth():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.WIDTH_STYLE_NAME, width);
	}
	
	private function getHeight():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.HEIGHT_STYLE_NAME, height);
	}
	
	private function getMinHeight():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MIN_HEIGHT_STYLE_NAME, minHeight);
	}
	
	private function getMaxHeight():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MAX_HEIGHT_STYLE_NAME, maxHeight);
	}
	
	private function getMinWidth():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MIN_WIDTH_STYLE_NAME, minWidth);
	}
	
	private function getMaxWidth():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.MAX_WIDTH_STYLE_NAME, maxWidth);
	}
	
	private function getTop():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.TOP_STYLE_NAME, top);
	}
	
	private function getLeft():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.LEFT_STYLE_NAME, left);
	}
	
	private function getBottom():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.BOTTOM_STYLE_NAME, bottom);
	}
	
	private function getRight():Float 
	{
		return getTransitionablePropertyValue(CSSConstants.RIGHT_STYLE_NAME, right);
	}
	
	private function getFontSize():Float
	{
		return getTransitionablePropertyValue(CSSConstants.FONT_SIZE_STYLE_NAME, fontSize);
	}
	
	private function getLetterSpacing():Float
	{
		return getTransitionablePropertyValue(CSSConstants.LETTER_SPACING_STYLE_NAME, letterSpacing);
	}
	
	private function getWordSpacing():Float
	{
		return getTransitionablePropertyValue(CSSConstants.WORD_SPACING_STYLE_NAME, wordSpacing);
	}
	
	private function getLineHeight():Float
	{
		return getTransitionablePropertyValue(CSSConstants.LINE_HEIGHT_STYLE_NAME, lineHeight);
	}
	
	private function getTextIndent():Float
	{
		return getTransitionablePropertyValue(CSSConstants.TEXT_INDENT_STYLE_NAME, textIndent);
	}
}