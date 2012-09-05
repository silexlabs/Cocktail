/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
import cocktail.core.css.parsers.CSSStyleParser;
import cocktail.core.css.parsers.CSSStyleSerializer;
import cocktail.core.css.CSSConstants;
using StringTools;

/**
 * This objects holds declarations of style properties in key/value
 * pair, where key is a valid CSS property name and value
 * a valid CSS property value, stored as a typed object.
 * 
 * Once CSS property name and value are parsed, this class
 * check that they are both valid before storing them
 * 
 * @author Yannick DOMINGUEZ
 */

class CSSStyleDeclaration 
{

	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLES ATTRIBUTES
	// exposes getter/setter for each supported CSS styles
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * display styles
	 */
	public var display(get_display, set_display):String;
	public var position(get_position, set_position):String;
	public var cssFloat(get_CSSFloat, set_CSSFloat):String;
	public var clear(get_clear, set_clear):String;
	public var zIndex(get_zIndex, set_zIndex):String;
	
	/**
	 * box model styles
	 */
	public var margin(get_margin, set_margin):String;
	public var marginLeft(get_marginLeft, set_marginLeft):String;
	public var marginRight(get_marginRight, set_marginRight):String;
	public var marginTop(get_marginTop, set_marginTop):String;
	public var marginBottom(get_marginBottom, set_marginBottom):String;
	
	public var padding(get_padding, set_padding):String;
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
	
	public var overflow(get_overflow, set_overflow):String;
	public var overflowX(get_overflowX,  set_overflowX):String;
	public var overflowY(get_overflowY,  set_overflowY):String;
	
	/**
	 * transition styles
	 */
	public var transitionProperty(get_transitionProperty, set_transitionProperty):String;
	public var transitionDuration(get_transitionDuration, set_transitionDuration):String;
	public var transitionTimingFunction(get_transitionTimingFunction, set_transitionTimingFunction):String;
	public var transitionDelay(get_transitionDelay, set_transitionDelay):String;
	
	/**
	* transformation styles
	*/
	public var transform(get_transform, set_transform):String; 	
	public var transformOrigin(get_transformOrigin, set_transformOrigin):String; 
	
	/**
	 * user interface styles
	 */
	public var cursor(get_cursor, set_cursor):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// ATTRIBUTES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * on getting, serialize all the style declaration as
	 * a CSS string, on setting parse the CSS string into
	 * typed CSS object, reset all the previously stored
	 * CSS objects
	 */
	public var cssText(get_cssText, set_cssText):String;
	
	/**
	 * The number of style declaration on this
	 * object
	 */
	public var length(get_length, null):Int;
	
	/**
	 * A reference to the rule owning this style
	 * declaration or null if there are none
	 */
	public var parentRule(default, null):CSSRule;
	
	/**
	 * Holds all the style declarations of this 
	 * object, as typed objects
	 */
	private var _properties:Array<TypedPropertyVO>;
	
	/**
	 * a reference to a CSS parser instance
	 */
	private var _cssStyleParser:CSSStyleParser;
	
	/**
	 * Optionnal callback, called when the value
	 * of a style changes
	 */
	private var _onStyleChange:String->Void;
	
	/**
	 * Class constructor
	 */
	public function new(parentRule:CSSRule = null, onStyleChange:String->Void = null) 
	{
		_properties = new Array<TypedPropertyVO>();
		_cssStyleParser = new CSSStyleParser();
		_onStyleChange = onStyleChange;
		this.parentRule = parentRule;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the style declaration
	 * at the given index
	 */
	public function item(index:Int):String
	{
		return _properties[index].name;
	}
	
	/**
	 * Return wether a value exits for the specified
	 * property
	 */
	public function hasProperty(property:String):Bool
	{
		var length:Int = _properties.length;
		for (i in 0...length)
		{
			if (_properties[i].name == property)
			{
				return true;
			}
		}
		
		return false;
	}
	
	/**
	 * Return the value of the property with the given
	 * name, serialized as a CSS string, or null if
	 * thr property is not defined on this style declaration
	 */
	public function getPropertyValue(property:String):String
	{
		var length:Int = _properties.length;
		for (i in 0...length)
		{
			var propertyDeclaration:TypedPropertyVO = _properties[i];
			if (propertyDeclaration.name == property)
			{
				return CSSStyleSerializer.serialize(propertyDeclaration.typedValue);
			}
		}
		return null;
	}
	
	/**
	 * Set the value of the property with the given name. 
	 * Do nothing if the name or the value are not valid.
	 * If the name is valid and the value is null, remove
	 * the property
	 * 
	 * TODO 1 : check that property name is valid and that
	 * "!important" is not in parsed value
	 */
	public function setProperty(name:String, value:String, priority:String = null)
	{
		if (value == null)
		{
			removeProperty(name);
		}
		else
		{
			//parse the proeprty, the return property is null
			//if the style is invalid
			var typedProperty:TypedPropertyVO = _cssStyleParser.parseStyleValue(name, value, 0);
			
			if (typedProperty != null)
			{
				applyProperty(typedProperty.name, typedProperty.typedValue, typedProperty.important);
			}
			
			
		}
	}
	
	/**
	 * Remove the property with the given name from
	 * the style declarations, and return its name if it
	 * exists, else return null
	 */
	public function removeProperty(property:String):String
	{
		var length:Int = _properties.length;
		for (i in 0...length)
		{
			var propertyDeclaration:TypedPropertyVO = _properties[i];
			
			if (propertyDeclaration.name == property)
			{
				var name:String = propertyDeclaration.name;
				_properties.remove(propertyDeclaration);
				
				//call the style update callback if provided
				if (_onStyleChange != null)
				{
					_onStyleChange(property);
				}
				
				return name;
			}
		}
		
		return null;
	}
	
	/**
	 * Return the priority (important or not) of the property
	 * with the given name.
	 * Return the empty string if the property is not important, 
	 * else return null
	 */
	public function getPropertyPriority(property:String):String
	{
		var length:Int = _properties.length;
		for (i in 0...length)
		{
			var propertyDeclaration:TypedPropertyVO = _properties[i];
			if (propertyDeclaration.name == property)
			{
				if (propertyDeclaration.important == true)
				{
					return CSSConstants.IMPORTANT;
				}
				else
				{
					return "";
				}
			}
		}
		
		return null;
	}
	
	/**
	 * Return the property with the given name as a typed property
	 * object or null if it is not defined on this style declaration
	 */
	public function getTypedProperty(property:String):TypedPropertyVO
	{
		var length:Int = _properties.length;
		for (i in 0...length)
		{
			var propertyDeclaration:TypedPropertyVO = _properties[i];
			if (propertyDeclaration.name == property)
			{
				return propertyDeclaration;
			}
		}
		return null;
	}
	
	/**
	 * Store the given typed property, replacing the current one
	 * if it was already existing
	 */
	public function setTypedProperty(property:String, typedValue:CSSPropertyValue, important:Bool):Void
	{
		//a new array which will hold all current styles and the new one
		var newProperties:Array<TypedPropertyVO> = new Array<TypedPropertyVO>();
		
		var newProperty:TypedPropertyVO = new TypedPropertyVO(property, typedValue, important);
		
		var foundMatchingProperty:Bool = false;
		var oldProperty:TypedPropertyVO = null;
		
		//look for a property with the same name
		//as the old property
		var length:Int = _properties.length;
		for (i in 0...length)
		{
			var propertyDeclaration:TypedPropertyVO = _properties[i];
			if (propertyDeclaration.name != property)
			{
				newProperties.push(propertyDeclaration);
			}
			//a match is found, only push the new property
			//and not the old one
			else
			{
				newProperties.push(newProperty);
				oldProperty = propertyDeclaration;
				foundMatchingProperty = true;
			}
		}
		
		//here no match was found for the old property, so it is
		//just added
		if (foundMatchingProperty == false)
		{
			newProperties.push(newProperty);
		}
		
		
		_properties = newProperties;
		
		//call the style change callback if provided
		if (_onStyleChange != null)
		{
			//always call if this is the first
			//time the property is defined on this object
			if (oldProperty == null)
			{
				_onStyleChange(property);
			}
			//else only call update for properties
			//which value actually changed
			//
			//TODO 2 : shouldn't need to call this method if value didn't
			//change
			else
			{
				if (Type.enumEq(oldProperty.typedValue, newProperty.typedValue) == false)
				{
					_onStyleChange(property);
				}
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STYLE VALIDITY METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply the property using the provided property name, 
	 * value and priority if the property is valid
	 */
	private function applyProperty(propertyName:String, styleValue:CSSPropertyValue, important:Bool):Void
	{
		//shorthand property like 'margin' are a special case
		if (isShorthand(propertyName) == true)
		{
			//check that the shorthand value is valid and apply it
			//to each individual property if it is
			if (isValidShorthand(propertyName, styleValue) == true)
			{
				setShorthand(propertyName, styleValue, important);
			}
		}
		//check if a property is valid before setting it
		else if (isValidProperty(propertyName, styleValue) == true)
		{
			setTypedProperty(propertyName, styleValue, important);
		}
	}
	
	/**
	 * Main validity method. For each supported style, return wether the 
	 * provided value is valid or not. It also return false if the property
	 * name is not a valid CSS property
	 */
	private function isValidProperty(propertyName:String, styleValue:CSSPropertyValue):Bool
	{
		switch(propertyName)
		{
			case CSSConstants.WIDTH, CSSConstants.HEIGHT:
				switch(styleValue)
				{
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case INTEGER(value):
						if (value == 0)
						{
							return true;
						}
						
					case PERCENTAGE(value):
						if (value >= 0)
						{
							return true;
						}
						
					case KEYWORD(value):
						if (value == AUTO)
						{
							return true;
						}
						
					case INHERIT, INITIAL:	
						return true;
						
					default:	
				}
				
				
			case CSSConstants.DISPLAY:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case INLINE, INLINE_BLOCK, NONE, BLOCK:
								return true;
								
							default:
						}
						
					case INHERIT, INITIAL:	
						return true;	
						
					default:	
				}
				
			case CSSConstants.VISIBILITY:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case VISIBLE, HIDDEN:
								return true;
								
							default:	
						}
					
					case INHERIT, INITIAL:	
						return true;	
						
					default:	
				}
				
				
			case CSSConstants.POSITION:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case STATIC, FIXED, ABSOLUTE, RELATIVE:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:	
						return true;	
						
					default:	
				}
				
				
			case CSSConstants.FONT_SIZE:
				switch(styleValue)
				{
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case PERCENTAGE(value):
						if (value >= 0)
						{
							return true;
						}
						
					case KEYWORD(value):	
						switch(value)
						{
							case XX_SMALL, X_SMALL, SMALL, MEDIUM, LARGE, X_LARGE, XX_LARGE, LARGER, SMALLER:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
						
				}
				
				
			case CSSConstants.MARGIN_TOP, CSSConstants.MARGIN_LEFT, CSSConstants.MARGIN_BOTTOM, CSSConstants.MARGIN_RIGHT:
				return isValidMarginProperty(styleValue);
				
			case CSSConstants.PADDING_TOP, CSSConstants.PADDING_BOTTOM, CSSConstants.PADDING_LEFT, CSSConstants.PADDING_RIGHT:
				return isValidPaddingProperty(styleValue);
				
			case CSSConstants.MAX_WIDTH, CSSConstants.MAX_HEIGHT:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NONE:
								return true;
								
							default:	
						}
						
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case PERCENTAGE(value):
						if (value >= 0)
						{
							return true;
						}
						
					case INHERIT, INITIAL:	
						return true;
						
					default:	
						
				}
				
				
			case CSSConstants.OPACITY:
				switch(styleValue)
				{
					case NUMBER(value):
						return true;
						
					case INTEGER(value):
						return true;
					
					case INHERIT, INITIAL:	
						return true;
						
					default:	
				}
				
			case CSSConstants.MIN_WIDTH, CSSConstants.MIN_HEIGHT:
				switch(styleValue)
				{
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case PERCENTAGE(value):
						if (value >= 0)
						{
							return true;
						}
						
					case INHERIT, INITIAL:	
						return true;
						
					default:	
				}
				
			case CSSConstants.LEFT, CSSConstants.RIGHT, CSSConstants.TOP, CSSConstants.BOTTOM:
				switch(styleValue)
				{
					case LENGTH(value):
						return true;
						
					case PERCENTAGE(value):
						return true;
						
					case INTEGER(value):
						if (value == 0)
						{
							return true;
						}	
						
					case KEYWORD(value):
						if (value == AUTO)
						{
							return true;	
						}
						
					case INHERIT, INITIAL:	
						return true;
						
					default:	
				}
				
			case CSSConstants.FONT_STYLE:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case ITALIC, OBLIQUE, NORMAL:
								return true;
								
							default:
						}
					
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			
			//TOSO : don't check transform functions	
			case CSSConstants.TRANSFORM:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NONE:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
				
			case CSSConstants.OVERFLOW_X, CSSConstants.OVERFLOW_Y:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case VISIBLE, SCROLL, HIDDEN, AUTO:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:
				}
				
			//TODO 1 : need better check	
			case CSSConstants.FONT_FAMILY:
				switch(styleValue)
				{
					case CSS_LIST(values):
						return true;
						
					case IDENTIFIER(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;	
						
					default:
				}
				
			case CSSConstants.FLOAT:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case LEFT, RIGHT, BOTH, NONE:
								return true;
								
							default:
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
				
			case CSSConstants.WHITE_SPACE:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NORMAL, NO_WRAP, PRE_LINE, PRE, PRE_WRAP:
								return true;
								
							default:
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.TEXT_TRANSFORM:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NONE, UPPERCASE, LOWERCASE, CAPITALIZE:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.FONT_WEIGHT:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NORMAL, BOLD, BOLDER, LIGHTER:
								return true;
								
							default:	
						}
						
					case INTEGER(value):
						switch(value)
						{
							case 100, 200, 300, 400, 500, 600, 700, 800, 900:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
						
				}
				
			case CSSConstants.FONT_VARIANT:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NORMAL, SMALL_CAPS:
								return true;
								
							default:
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.TEXT_ALIGN:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case LEFT, RIGHT, CENTER, JUSTIFY:
								return true;
								
							default:
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
				
			case CSSConstants.VERTICAL_ALIGN:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case BASELINE, SUB, SUPER, TEXT_BOTTOM, TEXT_TOP, MIDDLE, TOP, BOTTOM:
								return true;
								
							default:	
						}
						
					case PERCENTAGE(value):
						return true;
						
					case LENGTH(value):	
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.CURSOR:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case AUTO, CROSSHAIR, DEFAULT, POINTER, TEXT:
								return true;
								
							default:	
						}
						
					case URL(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.Z_INDEX:
				switch(styleValue)
				{
					case KEYWORD(value):
						if (value == AUTO)
						{
							return true;
						}
						
					case INTEGER(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.LINE_HEIGHT:
				switch(styleValue)
				{
					case KEYWORD(value):
						if (value == NORMAL)
						{
							return true;
						}
						
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case NUMBER(value):
						if (value >= 0)
						{
							return true;
						}
						
					case PERCENTAGE(value):
						if (value >= 0)
						{
							return true;
						}
						
					case INHERIT, INITIAL:
						return true;
						
					default:		
				}
				
			case CSSConstants.TEXT_INDENT:
				switch(styleValue)
				{
					case INTEGER(value):
						if (value == 0)
						{
							return true;
						}
						
					case LENGTH(value):
						return true;
						
					case PERCENTAGE(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:			
				}
				
			case CSSConstants.LETTER_SPACING, CSSConstants.WORD_SPACING:
				switch(styleValue)
				{
					case KEYWORD(value):
						if (value == NORMAL)
						{
							return true;
						}
						
					case LENGTH(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.COLOR, CSSConstants.BACKGROUND_COLOR:
				switch(styleValue)
				{
					case COLOR(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_IMAGE:
				
				switch(styleValue)
				{
					case KEYWORD(value):
						if (value == CSSKeywordValue.NONE)
						{
							return true;
						}
						
					case URL(value):	
						return true;
						
					case CSS_LIST(value):	
						var isImageList:Bool = true;
						for (i in 0...value.length)
						{
							switch(value[i])
							{
								case URL(value):
								
								case KEYWORD(value):
									if (value != CSSKeywordValue.NONE)
									{
										isImageList = false;
									}
									
								default:
									isImageList = false;
							}
						}
						
						if (isImageList == true)
						{
							return true;
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_POSITION:
				switch(styleValue)
				{	
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								
								var isValidHorizontalPosition:Bool = isValidBackgroundPosition(value[0]);
								
								if (isValidHorizontalPosition == false)
								{
									return false;
								}
								
								return isValidBackgroundPosition(value[1]);
						}
						
					default:
						return isValidBackgroundPosition(styleValue);
						
				}
				
				
			case CSSConstants.BACKGROUND_REPEAT:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case REPEAT, REPEAT_X, REPEAT_Y, NO_REPEAT, ROUND, SPACE:
								return true;
								
							default:	
						}
						
					case GROUP(value):
						if (value.length == 2)
						{
							var isFirstValueValid:Bool = false;
							switch(value[0])
							{
								case KEYWORD(value):
									switch(value)
									{
										case REPEAT, SPACE, ROUND, NO_REPEAT:
											isFirstValueValid = true;
											
										default:	
									}
									
								default:	
							}
							
							var isSecondValueValid:Bool = false;
							switch(value[1])
							{
								case KEYWORD(value):
									switch(value)
									{
										case REPEAT, SPACE, ROUND, NO_REPEAT:
											isSecondValueValid = true;
											
										default:	
									}
									
								default:	
							}
							
							if (isFirstValueValid == true && isSecondValueValid == true)
							{
								return true;
							}
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_SIZE:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case COVER, CONTAIN, AUTO:
								return true;
								
							default:	
						}
						
					case GROUP(value):
						if (value.length == 2)
						{
							var isFirstValueValid:Bool = isValidBackgroundSize(value[0]);
							
							if (isFirstValueValid == false)
							{
								return false;
							}
							
							return isValidBackgroundSize(value[1]);
						}	
						
					default:
						return isValidBackgroundSize(styleValue);
				}
				
			case CSSConstants.BACKGROUND_CLIP, CSSConstants.BACKGROUND_ORIGIN:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case BORDER_BOX, PADDING_BOX, CONTENT_BOX:
								return true;
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			//TODO : manage list	
			case CSSConstants.TRANSITION_PROPERTY:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							//add special case for left and right which 
							//might be both style names and css keyword
							case NONE, ALL, LEFT, RIGHT:
								return true;
								
							default:	
						}
						
					case IDENTIFIER(value):	
						return true;
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			//TODO : manage list of Time	
			case CSSConstants.TRANSITION_DURATION:
				switch(styleValue)
				{
					case TIME(value):
						return true;
						
					default:	
				}
				
			//TODO : manage list	
			case CSSConstants.TRANSITION_TIMING_FUNCTION:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case EASE, EASE_IN, LINEAR, EASE_OUT, EASE_IN_OUT, STEP_START, STEP_END:
								return true;
								
							default:	
						}
						
					case STEPS(intervalNumbers, intervalChange):
						return true;
						
					case CUBIC_BEZIER(x1, y1, x2, y2):	
						return true;
						
					default:	
				}
				
			case CSSConstants.TRANSITION_DELAY:
				switch(styleValue)
				{
					case INTEGER(value):
						if (value == 0)
						{
							return true;
						}
					
					case TIME(value):
						return true;
						
					default:
				}
		}
		
		return false;
	}
	
	/**
	 * Return wether a property has a valid value for 
	 * for the background-position property, excluding
	 * group and list value
	 */
	private function isValidBackgroundPosition(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case LENGTH(value):
				return true;
				
			case INTEGER(value):
				return value == 0;
				
			case PERCENTAGE(value):
				return true;
				
			case KEYWORD(value):
				switch(value)
				{
					case LEFT, CENTER, RIGHT:
						return true;
						
					default:	
				}
				
			case INHERIT, INITIAL:
				return true;		
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Same as above for background-size property
	 */
	private function isValidBackgroundSize(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case KEYWORD(value):
				return value == AUTO;
				
			case LENGTH(value):
				if (isPositiveLength(value))
				{
					return true;
				}
				
			case INTEGER(value):
				return value == 0;
				
			case PERCENTAGE(value):
				return true;
				
			case INHERIT, INITIAL:
				return true;	
				
			default:	
		}
		
		return false;
	}

	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SHORTHANDS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return wether a property is a
	 * CSS shorthand, usgin its name
	 * 
	 * TODO 1 : complete shorthands
	 */
	private function isShorthand(propertyName:String):Bool
	{
		switch(propertyName)
		{
			case CSSConstants.MARGIN, CSSConstants.PADDING, CSSConstants.CSS_OVERFLOW:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * Apply the individual values repesented by a shorthand, once it has
	 * been checked that the value of the shorthand is valid
	 */
	private function setShorthand(propertyName:String, styleValue:CSSPropertyValue, important:Bool):Void
	{
		switch(propertyName)
		{
			case CSSConstants.MARGIN:
				switch(styleValue)
				{
					case LENGTH(value):
						setTypedProperty(CSSConstants.MARGIN_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_RIGHT, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_TOP, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_BOTTOM, styleValue, important);
						
					case PERCENTAGE(value):	
						setTypedProperty(CSSConstants.MARGIN_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_RIGHT,styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_TOP, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_BOTTOM, styleValue, important);
						
					case INTEGER(value):	
						setTypedProperty(CSSConstants.MARGIN_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_RIGHT,styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_TOP, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_BOTTOM, styleValue, important);
						
					case INHERIT, INITIAL:	
						setTypedProperty(CSSConstants.MARGIN_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_RIGHT,styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_TOP, styleValue, important);
						setTypedProperty(CSSConstants.MARGIN_BOTTOM, styleValue, important);
						
					case KEYWORD(value):
						if (value == AUTO)
						{
							setTypedProperty(CSSConstants.MARGIN_LEFT, styleValue, important);
							setTypedProperty(CSSConstants.MARGIN_RIGHT, styleValue, important);
							setTypedProperty(CSSConstants.MARGIN_TOP, styleValue, important);
							setTypedProperty(CSSConstants.MARGIN_BOTTOM, styleValue, important);
						}
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:	
								setTypedProperty(CSSConstants.MARGIN_LEFT, value[1], important);
								setTypedProperty(CSSConstants.MARGIN_RIGHT, value[1], important);
								setTypedProperty(CSSConstants.MARGIN_TOP, value[0], important);
								setTypedProperty(CSSConstants.MARGIN_BOTTOM, value[0], important);
								
							case 3:	
								setTypedProperty(CSSConstants.MARGIN_LEFT, value[1], important);
								setTypedProperty(CSSConstants.MARGIN_RIGHT, value[1], important);
								setTypedProperty(CSSConstants.MARGIN_TOP, value[0], important);
								setTypedProperty(CSSConstants.MARGIN_BOTTOM, value[2], important);
								
							case 4:	
								setTypedProperty(CSSConstants.MARGIN_LEFT, value[3], important);
								setTypedProperty(CSSConstants.MARGIN_RIGHT, value[1], important);
								setTypedProperty(CSSConstants.MARGIN_TOP, value[0], important);
								setTypedProperty(CSSConstants.MARGIN_BOTTOM, value[2], important);	
						}
						
					default:	
					
				}
				
			case CSSConstants.PADDING:
				switch (styleValue)
				{
					case LENGTH(value):
						setTypedProperty(CSSConstants.PADDING_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_RIGHT, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_TOP, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_BOTTOM, styleValue, important);
						
					case PERCENTAGE(value):
						setTypedProperty(CSSConstants.PADDING_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_RIGHT, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_TOP, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_BOTTOM, styleValue, important);	
						
					case INTEGER(value):	
						setTypedProperty(CSSConstants.PADDING_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_RIGHT,styleValue, important);
						setTypedProperty(CSSConstants.PADDING_TOP, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_BOTTOM, styleValue, important);	
						
					//TODO 2 : is inherit allowed for each value in shorthand ?	
					case INHERIT, INITIAL:	
						setTypedProperty(CSSConstants.PADDING_LEFT, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_RIGHT,styleValue, important);
						setTypedProperty(CSSConstants.PADDING_TOP, styleValue, important);
						setTypedProperty(CSSConstants.PADDING_BOTTOM, styleValue, important);
					
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								setTypedProperty(CSSConstants.PADDING_LEFT, value[1], important);
								setTypedProperty(CSSConstants.PADDING_RIGHT, value[1], important);
								setTypedProperty(CSSConstants.PADDING_TOP, value[0], important);
								setTypedProperty(CSSConstants.PADDING_BOTTOM, value[0], important);
								
							case 3:	
								setTypedProperty(CSSConstants.PADDING_LEFT, value[1], important);
								setTypedProperty(CSSConstants.PADDING_RIGHT, value[1], important);
								setTypedProperty(CSSConstants.PADDING_TOP, value[0], important);
								setTypedProperty(CSSConstants.PADDING_BOTTOM, value[2], important);
								
							case 4:	
								setTypedProperty(CSSConstants.PADDING_LEFT, value[3], important);
								setTypedProperty(CSSConstants.PADDING_RIGHT, value[1], important);
								setTypedProperty(CSSConstants.PADDING_TOP, value[0], important);
								setTypedProperty(CSSConstants.PADDING_BOTTOM, value[2], important);
						}
						
					default:
				}
				
			case CSSConstants.CSS_OVERFLOW:
				switch(styleValue)
				{
					case KEYWORD(value):
						setTypedProperty(CSSConstants.OVERFLOW_X, styleValue, important);
						setTypedProperty(CSSConstants.OVERFLOW_Y, styleValue, important);
						
					case GROUP(value):
						setTypedProperty(CSSConstants.OVERFLOW_X, value[0], important);
						setTypedProperty(CSSConstants.OVERFLOW_Y, value[1], important);
						
					default:	
				}
				
			default:	
						
		}
	}
	
	/**
	 * Return wether the value of a given CSS shorthand property
	 * is valid
	 */
	private function isValidShorthand(propertyName:String, styleValue:CSSPropertyValue):Bool
	{
		switch(propertyName)
		{
			case CSSConstants.MARGIN:
				switch(styleValue)
				{
					case LENGTH(value):
						return isValidMarginProperty(styleValue);
						
					case PERCENTAGE(value):	
						return isValidMarginProperty(styleValue);
						
					case INTEGER(value):
						return isValidMarginProperty(styleValue);
						
					case KEYWORD(value):
						return isValidMarginProperty(styleValue);
						
					case INHERIT, INITIAL:
						return true;
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:	
								var isValid:Bool = isValidMarginProperty(value[0]);
								if (isValid == false)
								{
									return false;
								}
								return isValidMarginProperty(value[1]);
								
							case 3:	
								var isValid:Bool = isValidMarginProperty(value[0]);
								if (isValid == false)
								{
									return false;
								}
								isValid = isValidMarginProperty(value[1]);
								if (isValid == false)
								{
									return false;
								}
								return isValidMarginProperty(value[2]);
								
							case 4:	
								var isValid:Bool = isValidMarginProperty(value[0]);
								if (isValid == false)
								{
									return false;
								}
								isValid = isValidMarginProperty(value[1]);
								if (isValid == false)
								{
									return false;
								}
								isValid = isValidMarginProperty(value[2]);
								if (isValid == false)
								{
									return false;
								}
								return isValidMarginProperty(value[3]);
						}
						
					default:	
				}
					
					
			case CSSConstants.PADDING:
				switch (styleValue)
				{
					case LENGTH(value):
						return isValidPaddingProperty(styleValue);
						
					case PERCENTAGE(value):
						return isValidPaddingProperty(styleValue);
						
					case INTEGER(value):
						return isValidPaddingProperty(styleValue);
						
					case INHERIT, INITIAL:
						return true;
					
					case GROUP(value):
						switch(value.length)
						{
							case 2:	
								var isValid:Bool = isValidPaddingProperty(value[0]);
								if (isValid == false)
								{
									return false;
								}
								return isValidPaddingProperty(value[1]);
								
							case 3:	
								var isValid:Bool = isValidPaddingProperty(value[0]);
								if (isValid == false)
								{
									return false;
								}
								isValid = isValidPaddingProperty(value[1]);
								if (isValid == false)
								{
									return false;
								}
								return isValidPaddingProperty(value[2]);
								
							case 4:	
								var isValid:Bool = isValidPaddingProperty(value[0]);
								if (isValid == false)
								{
									return false;
								}
								isValid = isValidPaddingProperty(value[1]);
								if (isValid == false)
								{
									return false;
								}
								isValid = isValidPaddingProperty(value[2]);
								if (isValid == false)
								{
									return false;
								}
								return isValidPaddingProperty(value[3]);
						}
						
					default:
				}	
				
			case CSSConstants.CSS_OVERFLOW:
				switch(styleValue)
				{
					case KEYWORD(value):
						return isValidOverflowValue(styleValue);
						
					case INHERIT, INITIAL:
						return true;	
						
					case GROUP(value):
						var isValid:Bool = isValidOverflowValue(value[0]);
						if (isValid == false)
						{
							return false;
						}
						return isValidOverflowValue(value[1]);
						
					default:	
						
				}
				
				
			default:	
						
		}
		
		return false;
	}
	
	/**
	 * Return wether a CSS value is valid for an overflow style
	 */
	private function isValidOverflowValue(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case VISIBLE, SCROLL, HIDDEN, AUTO:
						return true;
						
					default:	
				}
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether a CSS value is valid for a margin style
	 */
	private function isValidMarginProperty(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case LENGTH(value):
				return true;
				
			case INTEGER(value):
				if (value == 0)
				{
					return true;
				}
				
			case PERCENTAGE(value):
				return true;
				
			case KEYWORD(value):
				switch(value)
				{
					case AUTO:
						return true;
						
					default:	
				}
				
			case INHERIT:
				return true;
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether a CSS value is valid for a padding style
	 */
	private function isValidPaddingProperty(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue) 
		{
			case LENGTH(value):
				if (isPositiveLength(value) == true)
				{
					return true;
				}
				
			case INTEGER(value):
				if (value == 0)
				{
					return true;
				}
				
			case PERCENTAGE(value):
				if (value >= 0)
				{
					return true;
				}
				
			case INHERIT:
				return true;
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Helper method return wether a length value
	 * is positive. Some styles, such as width and height
	 * for instance require length to be positive to be valid
	 */
	private function isPositiveLength(length:CSSLengthValue):Bool
	{
		switch(length)
		{
			case PX(value):
				return value >= 0;
				
			case EM(value):
				return value >= 0;
				
			case IN(value):
				return value >= 0;
				
			case PC(value):
				return value >= 0;	
				
			case EX(value):
				return value >= 0;	
				
			case PT(value):
				return value >= 0;		
				
			case MM(value):
				return value >= 0;		
				
			case CM(value):
				return value >= 0;		
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SERIALIZATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Serialize all the style declarations of this 
	 * object into a CSS string
	 */
	private function serializeStyleDeclaration():String
	{
		var serializedStyleDeclaration:String = "";
		
		for (i in 0..._properties.length)
		{
			var property:TypedPropertyVO = _properties[i];
			
			serializedStyleDeclaration += property.name + ":" + CSSStyleSerializer.serialize(property.typedValue);
			if (property.important == true)
			{
				serializedStyleDeclaration += " !important";
			}
			serializedStyleDeclaration += ";";
		}
		
		return serializedStyleDeclaration;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_cssText():String
	{
		return serializeStyleDeclaration();
	}
	
	private function set_cssText(value:String):String
	{
		//reset properties
		_properties = new Array<TypedPropertyVO>();
		
		var typedProperties:Array<TypedPropertyVO> = _cssStyleParser.parseStyle(value);
		
		for (i in 0...typedProperties.length)
		{
			var typedProperty:TypedPropertyVO = typedProperties[i];
			applyProperty(typedProperty.name, typedProperty.typedValue, typedProperty.important);
		}
		
		return value;
	}
	
	private function get_length():Int
	{
		return _properties.length;
	}
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function get_opacity():String
	{
		return getPropertyValue(CSSConstants.OPACITY);
	}
	
	private function set_opacity(value:String):String
	{
		setProperty(CSSConstants.OPACITY, value);
		return value;
	}
	
	private function get_visibility():String
	{
		return getPropertyValue(CSSConstants.VISIBILITY);
	}
	
	private function set_visibility(value:String):String
	{
		setProperty(CSSConstants.VISIBILITY, value);
		return value;
	}
	
	//TODO 1 : should serialize defined margin properties ?
	private function get_margin():String
	{
		return getPropertyValue(CSSConstants.MARGIN);
	}
	
	private function set_margin(value:String):String
	{
		setProperty(CSSConstants.MARGIN, value);
		return value;
	}
	
	private function get_marginLeft():String 
	{
		return getPropertyValue(CSSConstants.MARGIN_LEFT);
	}
	
	private function set_marginLeft(value:String):String 
	{
		setProperty(CSSConstants.MARGIN_LEFT, value);
		return value;
	}
	
	private function get_marginRight():String 
	{
		return getPropertyValue(CSSConstants.MARGIN_RIGHT);
	}
	
	private function set_marginRight(value:String):String 
	{
		setProperty(CSSConstants.MARGIN_RIGHT, value);
		return value;
	}
	
	private function get_marginTop():String 
	{
		return getPropertyValue(CSSConstants.MARGIN_TOP);
	}
	
	private function set_marginTop(value:String):String 
	{
		setProperty(CSSConstants.MARGIN_TOP, value);
		return value;
	}
	
	private function get_marginBottom():String 
	{
		return getPropertyValue(CSSConstants.MARGIN_BOTTOM);
	}
	
	private function set_marginBottom(value:String):String 
	{
		setProperty(CSSConstants.MARGIN_BOTTOM, value);
		return value;
	}
	
	private function get_padding():String
	{
		return getPropertyValue(CSSConstants.PADDING);
	}
	
	private function set_padding(value:String):String
	{
		setProperty(CSSConstants.PADDING, value);
		return value;
	}
	
	private function get_paddingLeft():String 
	{
		return getPropertyValue(CSSConstants.PADDING_LEFT);
	}
	
	private function set_paddingLeft(value:String):String 
	{
		setProperty(CSSConstants.PADDING_LEFT, value);
		return value;
	}
	
	private function get_paddingRight():String 
	{
		return getPropertyValue(CSSConstants.PADDING_RIGHT);
	}
	
	private function set_paddingRight(value:String):String
	{
		setProperty(CSSConstants.PADDING_RIGHT, value);
		return value;
	}
	
	private function get_paddingTop():String 
	{
		return getPropertyValue(CSSConstants.PADDING_TOP);
	}
	
	private function set_paddingTop(value:String):String 
	{
		setProperty(CSSConstants.PADDING_TOP, value);
		return value;
	}
	
	private function get_paddingBottom():String 
	{
		return getPropertyValue(CSSConstants.PADDING_BOTTOM);
	}
	
	private function set_paddingBottom(value:String):String 
	{
		setProperty(CSSConstants.PADDING_BOTTOM, value);
		return value;
	}
	
	private function get_display():String 
	{
		return getPropertyValue(CSSConstants.DISPLAY);
	}
	
	private function set_display(value:String):String 
	{
		setProperty(CSSConstants.DISPLAY, value);
		return value;
	}
	
	private function get_position():String 
	{
		return getPropertyValue(CSSConstants.POSITION);
	}
	
	private function set_position(value:String):String 
	{
		setProperty(CSSConstants.POSITION, value);
		return value;
	}
	
	private function get_zIndex():String
	{
		return getPropertyValue(CSSConstants.Z_INDEX);
	}
	
	private function set_zIndex(value:String):String
	{
		setProperty(CSSConstants.Z_INDEX, value);
		return value;
	}
	
	private function get_width():String 
	{
		return getPropertyValue(CSSConstants.WIDTH);
	}
	
	private function set_width(value:String):String 
	{
		setProperty(CSSConstants.WIDTH, value);
		return value;
	}
	
	private function get_height():String 
	{
		return getPropertyValue(CSSConstants.HEIGHT);
	}
	
	private function set_height(value:String):String 
	{
		setProperty(CSSConstants.HEIGHT, value);
		return value;
	}
	
	private function get_minHeight():String 
	{
		return getPropertyValue(CSSConstants.MIN_HEIGHT);
	}
	
	private function set_minHeight(value:String):String 
	{
		setProperty(CSSConstants.MIN_HEIGHT, value);
		return value;
	}
	
	private function get_maxHeight():String 
	{
		return getPropertyValue(CSSConstants.MAX_HEIGHT);
	}

	private function set_maxHeight(value:String):String 
	{
		setProperty(CSSConstants.MAX_HEIGHT, value);
		return value;
	}
	
	private function get_minWidth():String 
	{
		return getPropertyValue(CSSConstants.MIN_WIDTH);
	}
		
	private function set_minWidth(value:String):String 
	{
		setProperty(CSSConstants.MIN_WIDTH, value);
		return value;
	}
	
	private function get_maxWidth():String 
	{
		return getPropertyValue(CSSConstants.MAX_WIDTH);
	}
	
	private function set_maxWidth(value:String):String 
	{
		setProperty(CSSConstants.MAX_WIDTH, value);
		return value;
	}
	
	private function get_top():String 
	{
		return getPropertyValue(CSSConstants.TOP);
	}
	
	private function set_top(value:String):String 
	{
		setProperty(CSSConstants.TOP, value);
		return value;
	}
	
	private function get_left():String 
	{
		return getPropertyValue(CSSConstants.LEFT);
	}
		
	private function set_left(value:String):String 
	{
		setProperty(CSSConstants.LEFT, value);
		return value;
	}
	
	private function get_bottom():String 
	{
		return getPropertyValue(CSSConstants.BOTTOM);
	}
	
	private function set_bottom(value:String):String 
	{
		setProperty(CSSConstants.BOTTOM, value);
		return value;
	}
	
	private function get_right():String 
	{
		return getPropertyValue(CSSConstants.RIGHT);
	}
	
	private function set_right(value:String):String 
	{
		setProperty(CSSConstants.RIGHT, value);
		return value;
	}
	
	private function get_CSSFloat():String 
	{
		return getPropertyValue(CSSConstants.FLOAT);
	}
	
	private function set_CSSFloat(value:String):String 
	{
		setProperty(CSSConstants.FLOAT, value);
		return value;
	}
	
	private function get_clear():String 
	{
		return getPropertyValue(CSSConstants.CLEAR);
	}
	
	private function set_clear(value:String):String 
	{
		setProperty(CSSConstants.CLEAR, value);
		return value;
	}
	
	private function get_fontSize():String
	{
		return getPropertyValue(CSSConstants.FONT_SIZE);
	}
	
	private function set_fontSize(value:String):String
	{
		setProperty(CSSConstants.FONT_SIZE, value);
		return value;
	}
	
	private function get_fontWeight():String
	{
		return getPropertyValue(CSSConstants.FONT_WEIGHT);
	}
	
	private function set_fontWeight(value:String):String
	{
		setProperty(CSSConstants.FONT_WEIGHT, value);
		return value;
	}
	
	private function get_fontStyle():String
	{
		return getPropertyValue(CSSConstants.FONT_STYLE);
	}
	
	private function set_fontStyle(value:String):String
	{
		setProperty(CSSConstants.FONT_STYLE, value);
		return value;
	}
	
	private function get_fontFamily():String
	{
		return getPropertyValue(CSSConstants.FONT_FAMILY);
	}
	
	private function set_fontFamily(value:String):String
	{
		setProperty(CSSConstants.FONT_FAMILY, value);
		return value;
	}
	

	private function get_fontVariant():String
	{
		return getPropertyValue(CSSConstants.FONT_VARIANT);
	}
	
	private function set_fontVariant(value:String):String
	{
		setProperty(CSSConstants.FONT_VARIANT, value);
		return value;
	}
	
	private function get_textTransform():String
	{
		return getPropertyValue(CSSConstants.TEXT_TRANSFORM);
	}
	
	private function set_textTransform(value:String):String
	{
		setProperty(CSSConstants.TEXT_TRANSFORM, value);
		return value;
	}
	
	private function get_letterSpacing():String
	{
		return getPropertyValue(CSSConstants.LETTER_SPACING);
	}
	
	private function set_letterSpacing(value:String):String
	{
		setProperty(CSSConstants.LETTER_SPACING, value);
		return value;
	}
	
	private function get_color():String
	{
		return getPropertyValue(CSSConstants.COLOR);
	}
	
	private function set_color(value:String):String
	{
		setProperty(CSSConstants.COLOR, value);
		return value;
	}
	
	private function get_wordSpacing():String
	{
		return getPropertyValue(CSSConstants.WORD_SPACING);
	}
	
	private function set_wordSpacing(value:String):String
	{
		setProperty(CSSConstants.WORD_SPACING, value);
		return value;
	}
	
	private function get_lineHeight():String
	{
		return getPropertyValue(CSSConstants.LINE_HEIGHT);
	}
	
	private function set_lineHeight(value:String):String
	{
		setProperty(CSSConstants.LINE_HEIGHT, value);
		return value;
	}
	
	private function get_verticalAlign():String
	{
		return getPropertyValue(CSSConstants.VERTICAL_ALIGN);
	}
	
	private function set_verticalAlign(value:String):String
	{
		setProperty(CSSConstants.VERTICAL_ALIGN, value);
		return value;
	}
	
	private function get_textIndent():String
	{
		return getPropertyValue(CSSConstants.TEXT_INDENT);
	}
	
	private function set_textIndent(value:String):String
	{
		setProperty(CSSConstants.TEXT_INDENT, value);
		return value;
	}
	
	private function get_whiteSpace():String
	{
		return getPropertyValue(CSSConstants.WHITE_SPACE);
	}
	
	private function set_whiteSpace(value:String):String
	{
		setProperty(CSSConstants.WHITE_SPACE, value);
		return value;
	}
	
	private function get_textAlign():String
	{
		return getPropertyValue(CSSConstants.TEXT_ALIGN);
	}
	
	private function set_textAlign(value:String):String
	{
		setProperty(CSSConstants.TEXT_ALIGN, value);
		return value;
	}
	
	private function set_backgroundColor(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_COLOR, value);
		return value;
	}
	
	private function get_backgroundColor():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_COLOR);
	}
	
	private function set_backgroundImage(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_IMAGE, value);
		return value;
	}
	
	private function get_backgroundImage():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_IMAGE);
	}
	
	private function set_backgroundRepeat(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_REPEAT, value);
		return value;
	}
	
	private function get_backgroundRepeat():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_REPEAT);
	}
	
	private function set_backgroundSize(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_SIZE, value);
		return value;
	}
	
	private function get_backgroundSize():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_SIZE);
	}
	
	private function set_backgroundClip(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_CLIP, value);
		return value;
	}
	
	private function get_backgroundClip():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_CLIP);
	}
	
	private function set_backgroundPosition(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_POSITION, value);
		return value;
	}
	
	private function get_backgroundPosition():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_POSITION);
	}
	
	private function set_backgroundOrigin(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_ORIGIN, value);
		return value;
	}
	
	private function get_backgroundOrigin():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_ORIGIN);
	}
	
	private function get_overflow():String
	{
		return getPropertyValue(CSSConstants.CSS_OVERFLOW);
	}
	
	private function set_overflow(value:String):String
	{
		setProperty(CSSConstants.CSS_OVERFLOW, value);
		return value;
	}
	
	private function get_overflowX():String
	{
		return getPropertyValue(CSSConstants.OVERFLOW_X);
	}
	
	private function set_overflowX(value:String):String
	{
		setProperty(CSSConstants.OVERFLOW_X, value);
		return value;
	}
	
	private function get_overflowY():String
	{
		return getPropertyValue(CSSConstants.OVERFLOW_Y);
	}
	
	private function set_overflowY(value:String):String
	{
		setProperty(CSSConstants.OVERFLOW_Y, value);
		return value;
	}
	
	private function set_cursor(value:String):String
	{
		setProperty(CSSConstants.CURSOR, value);
		return value;
	}
	
	private function get_cursor():String
	{
		return getPropertyValue(CSSConstants.CURSOR);
	}

	/* transitions */
	private function get_transitionProperty():String 
	{
		return getPropertyValue(CSSConstants.TRANSITION_PROPERTY);
	}
	
	private function set_transitionProperty(value:String):String 
	{
		setProperty(CSSConstants.TRANSITION_PROPERTY, value);
		return value;
	}

	private function get_transitionDuration():String 
	{
		return getPropertyValue(CSSConstants.TRANSITION_DURATION);
	}
	
	private function set_transitionDuration(value:String):String 
	{
		setProperty(CSSConstants.TRANSITION_DURATION, value);
		return value;
	}

	private function get_transitionDelay():String 
	{
		return getPropertyValue(CSSConstants.TRANSITION_DELAY);
	}
	
	private function set_transitionDelay(value:String):String 
	{
		setProperty(CSSConstants.TRANSITION_DELAY, value);
		return value;
	}	

	private function get_transitionTimingFunction():String 
	{
		return getPropertyValue(CSSConstants.TRANSITION_TIMING_FUNCTION);
	}
	
	private function set_transitionTimingFunction(value:String):String 
	{
		setProperty(CSSConstants.TRANSITION_TIMING_FUNCTION, value);
		return value;
	}

	private function get_transform():String
	{
		return getPropertyValue(CSSConstants.TRANSFORM);
	}

	private function set_transform(value:String):String
	{
		setProperty(CSSConstants.TRANSFORM, value);
		return value;		
	}

	private function get_transformOrigin():String
	{
		return getPropertyValue(CSSConstants.TRANSFORM_ORIGIN);
	}

	private function set_transformOrigin(value:String):String
	{
		setProperty(CSSConstants.TRANSFORM_ORIGIN, value);
		return value;		
	}
}