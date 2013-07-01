/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
	public var cssFloat(get_cssFloat, set_cssFloat):String;
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
	public var background(get_background, set_background):String;
	public var backgroundColor(get_backgroundColor, set_backgroundColor):String;
	public var backgroundImage(get_backgroundImage, set_backgroundImage):String;
	public var backgroundRepeat(get_backgroundRepeat, set_backgroundRepeat):String;
	public var backgroundOrigin(get_backgroundOrigin, set_backgroundOrigin):String;
	public var backgroundSize(get_backgroundSize, set_backgroundSize):String;
	public var backgroundPosition(get_backgroundPosition, set_backgroundPosition):String;
	public var backgroundClip(get_backgroundClip, set_backgroundClip):String;
	public var backgroundAttachment(get_backgroundAttachment, set_backgroundAttachment):String;
	
	/**
	 * border styles
	 */
	public var borderTopWidth(get_borderTopWidth, set_borderTopWidth):String;
	public var borderRightWidth(get_borderRightWidth, set_borderRightWidth):String;
	public var borderBottomWidth(get_borderBottomWidth, set_borderBottomWidth):String;
	public var borderLeftWidth(get_borderLeftWidth, set_borderLeftWidth):String;
	public var borderWidth(get_borderWidth, set_borderWidth):String;
	
	public var borderTopColor(get_borderTopColor, set_borderTopColor):String;
	public var borderRightColor(get_borderRightColor, set_borderRightColor):String;
	public var borderBottomColor(get_borderBottomColor, set_borderBottomColor):String;
	public var borderLeftColor(get_borderLeftColor, set_borderLeftColor):String;
	public var borderColor(get_borderColor, set_borderColor):String;
	
	public var borderTopStyle(get_borderTopStyle, set_borderTopStyle):String;
	public var borderRightStyle(get_borderRightStyle, set_borderRightStyle):String;
	public var borderBottomStyle(get_borderBottomStyle, set_borderBottomStyle):String;
	public var borderLeftStyle(get_borderLeftStyle, set_borderLeftStyle):String;
	public var borderStyle(get_borderStyle, set_borderStyle):String;
	
	public var borderTop(get_borderTop, set_borderTop):String;
	public var borderRight(get_borderRight, set_borderRight):String;
	public var borderBottom(get_borderBottom, set_borderBottom):String;
	public var borderLeft(get_borderLeft, set_borderLeft):String;
	public var border(get_border, set_border):String;
	
	/**
	 * font styles
	 */
	public var font(get_font, set_font):String;
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
	public var textDecoration(get_textDecoration, set_textDecoration):String;
	
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
	
	public var outline(get_outline, set_outline):String;
	public var outlineWidth(get_outlineWidth, set_outlineWidth):String;
	public var outlineColor(get_outlineColor, set_outlineColor):String;
	public var outlineStyle(get_outlineStyle, set_outlineStyle):String;
	
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
	public var length(default, null):Int;
	
	/**
	 * A reference to the rule owning this style
	 * declaration or null if there are none
	 */
	public var parentRule(default, null):CSSRule;
	
	/**
	 * Holds all the style declarations of this
	 * object, ordered by index, where each index
	 * is a CSS property. This allows for fast
	 * retrival of typed property
	 */
	private var _indexedProperties:Array<TypedPropertyVO>;
	
	/**
	 * Holds an item for each supported CSS style. For
	 * each item, hold the CSS index of the inserted style
	 * or -1 if no style was added at this index yet
	 * 
	 * For instance if the first style inserted in this stylesheet
	 * has the 30 CSS index, the value of the index 0 of this
	 * array will be 30.
	 */
	private var _propertiesPositions:Array<Int>;
	
	/**
	 * Optionnal callback, called when the value
	 * of a style changes
	 */
	private var _onStyleChange:Int->Void;
	
	/**
	 * Class constructor
	 */
	public function new(parentRule:CSSRule = null, onStyleChange:Int->Void = null) 
	{
		_onStyleChange = onStyleChange;
		this.parentRule = parentRule;
		
		length = 0;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_indexedProperties = null;
		_propertiesPositions = null;
		_onStyleChange = null;
		if (parentRule != null)
		{
			parentRule.dispose();
			parentRule = null;
		}
	}
	
	/**
	 * clean-up method to reuse
	 * style declaration
	 */
	public function reset():Void
	{
		_onStyleChange = null;
		parentRule = null;
		length = 0;
		
		resetIndexedProperties();
		resetPropertiesPositions();
	}
	
	/**
	 * for the indexed property array, init as many item as there are
	 * supported CSS style, each index will hold a CSS style value,
	 * always for the same style
	 */
	private function resetIndexedProperties():Void
	{
		if (_indexedProperties == null)
		{
			_indexedProperties = new Array<TypedPropertyVO>();
		}
		
		for (i in 0...CSSConstants.SUPPORTED_STYLES_NUMBER)
		{
			_indexedProperties[i] = null;
		}
	}
	
	/**
	 * 	for the position array, init as many item as there are
	 *	supported CSS styles, each index represents a CSS style and
	 *	holds the position of where the item was inserted
	 */
	private function resetPropertiesPositions():Void
	{
		if (_propertiesPositions == null)
		{
			_propertiesPositions = new Array<Int>();
		}
		
		for (i in 0...CSSConstants.SUPPORTED_STYLES_NUMBER)
		{
			_propertiesPositions[i] = -1;
		}
	}
	
	/**
	 * When a property is removed from this style sheet, decrement
	 * all the index of the properties that were added after it
	 * @param	removedPropertyIndex the CSS index of the property
	 * that was just removed
	 */
	private function decrementPropertiesPositions(removedPropertyIndex:Int):Void
	{
		//when the index of the property that was removed 
		//is found, decrement all the following properties index
		var foundProperty:Bool = false;
		for (i in 0...length)
		{
			if (foundProperty == true)
			{
				_propertiesPositions[i] = _propertiesPositions[i - 1];
			}
			if (_propertiesPositions[i] == removedPropertyIndex)
			{
				foundProperty = true;
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the index of the style
	 * at the given index
	 */
	public function item(index:Int):Int
	{
		//TODO 3 : should throw execption ?
		if (index > length - 1)
		{
			//out of bound item
			return -1;
		}
		return _propertiesPositions[index];
	}
	
	/**
	 * Return the value of the property with the given
	 * index, serialized as a CSS string, or null if
	 * thr property is not defined on this style declaration
	 */
	public function getPropertyValue(propertyIndex:Int):String
	{
		var typedProperty:TypedPropertyVO = getTypedProperty(propertyIndex);
		if (typedProperty != null)
		{
			return CSSStyleSerializer.serialize(typedProperty.typedValue);
		}
		return null;
	}
	
	/**
	 * Set the value of the property with the given index. 
	 * Do nothing if the name or the value are not valid.
	 * If the name is valid and the value is null, remove
	 * the property
	 */
	public function setProperty(index:Int, value:String, priority:String = null):Void
	{
		//initialised on first use
		if (_indexedProperties == null)
		{
			resetIndexedProperties();
			resetPropertiesPositions();
		}
		
		if (value == null)
		{
			removeProperty(index);
		}
		else
		{
			//parse the proeprty, the return property is null
			//if the style is invalid
			var typedProperty:TypedPropertyVO = CSSStyleParser.parseStyleValue(CSSConstants.getPropertyNameFromIndex(index), value, 0, null);
			
			if (typedProperty != null)
			{
				applyProperty(typedProperty.index, typedProperty.typedValue, typedProperty.important);
			}
		}
	}
	
	/**
	 * Remove the property with the given index from
	 * the style declarations, and return its index if it
	 * exists, else return -1
	 */
	public function removeProperty(index:Int):Int
	{
		var typedProperty:TypedPropertyVO = getTypedProperty(index);
		if (typedProperty != null)
		{
			//reorder the position array and decrement number of css style
			//in stylesheet
			decrementPropertiesPositions(index);
			_propertiesPositions[length] = -1;
			length--;
			
			_indexedProperties[index] =  null;
			
			//call the style update callback if provided
			if (_onStyleChange != null)
			{
				_onStyleChange(index);
			}
			
			return index;
		}
		
		return -1;
	}
	
	/**
	 * Return the priority (important or not) of the property
	 * with the given index.
	 * Return the empty string if the property is not important, 
	 * else return null
	 */
	public function getPropertyPriority(propertyIndex:Int):String
	{
		var typedProperty:TypedPropertyVO = getTypedProperty(propertyIndex);
		if (typedProperty != null)
		{
			if (typedProperty.important == true)
			{
				return CSSConstants.IMPORTANT;
			}
			else
			{
				return "";
			}
		}
		
		return null;
	}
	
	/**
	 * Return the property with the given index as a typed property
	 * object or null if it is not defined on this style declaration
	 */
	public inline function getTypedProperty(propertyIndex:Int):TypedPropertyVO
	{
		//initialised on first use
		if (_indexedProperties == null)
		{
			resetIndexedProperties();
			resetPropertiesPositions();
		}
		
		return _indexedProperties[propertyIndex];
	}
	
	/**
	 * Store the given typed property, update the current one
	 * if it was already existing
	 */
	public function setTypedProperty(propertyIndex:Int, typedValue:CSSPropertyValue, important:Bool):Void
	{
		//initialised on first use
		if (_indexedProperties == null)
		{
			resetIndexedProperties();
			resetPropertiesPositions();
		}
		
		//check if the property already exists
		var currentProperty:TypedPropertyVO = getTypedProperty(propertyIndex);
		
		//here the property doesn't exist yet, create it and store it
		if (currentProperty == null)
		{
			var newProperty:TypedPropertyVO = new TypedPropertyVO();
			newProperty.important = important;
			newProperty.typedValue = typedValue;
			newProperty.index = propertyIndex;
			
			//store the order where this css style was added by 
			//storing its index at the current length
			_propertiesPositions[length] = propertyIndex;
			length++;
			
			_indexedProperties[propertyIndex] = newProperty;
			
			if (_onStyleChange != null)
			{
				_onStyleChange(propertyIndex);
			}
		}
		//here the property exists, update it only if necessary
		else if (currentProperty.typedValue != typedValue || currentProperty.important != important)
		{
			currentProperty.typedValue = typedValue;
			currentProperty.important = important;
			if (_onStyleChange != null)
			{
				_onStyleChange(propertyIndex);
			}
		}
	}
	
	/**
	 * Same as above but faster, only called when
	 * it is known that this is the first time this property
	 * is set on this style declaration
	 */
	public function setTypedPropertyInitial(propertyIndex:Int, typedValue:CSSPropertyValue, important:Bool):Void
	{
		var newProperty:TypedPropertyVO = new TypedPropertyVO();
		newProperty.important = important;
		newProperty.typedValue = typedValue;
		newProperty.index = propertyIndex;
		
		//initialised on first use
		if (_indexedProperties == null)
		{
			resetIndexedProperties();
			resetPropertiesPositions();
		}

		_propertiesPositions[length] = propertyIndex;
		length++;
		
		_indexedProperties[propertyIndex] = newProperty;
		
		if (_onStyleChange != null)
		{
			_onStyleChange(propertyIndex);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STYLE VALIDITY METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply the property using the provided property index, 
	 * value and priority if the property is valid
	 */
	private function applyProperty(propertyIndex:Int, styleValue:CSSPropertyValue, important:Bool):Void
	{
		//shorthand property like 'margin' are a special case
		if (isShorthand(propertyIndex) == true)
		{
			//check that the shorthand value is valid and apply it
			//to each individual property if it is
			if (isValidShorthand(propertyIndex, styleValue) == true)
			{
				setShorthand(propertyIndex, styleValue, important);
			}
		}
		//check if a property is valid before setting it
		else if (isValidProperty(propertyIndex, styleValue) == true)
		{
			setTypedProperty(propertyIndex, styleValue, important);
		}
	}
	
	/**
	 * Main validity method. For each supported style, return wether the 
	 * provided value is valid or not. It also return false if the property
	 * index is not a valid CSS property index
	 */
	private function isValidProperty(propertyIndex:Int, styleValue:CSSPropertyValue):Bool
	{
		switch(propertyIndex)
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
						
					case TRANSFORM_FUNCTION(value):
						return true;
						
					case CSS_LIST(value):
						for (i in 0...value.length)
						{
							switch(value[i])
							{
								case TRANSFORM_FUNCTION(value):
									
								default:
									return false;
							}
						}
						
						return true;
						
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
				
			case CSSConstants.TRANSFORM_ORIGIN:
				switch(styleValue)
				{
					case GROUP(value):
						
						if (value.length != 2)
						{
							return false;
						}
						
						var horizontalValueIsValid:Bool = isValidTransformOrigin(value[0], true, false);
						
						if (horizontalValueIsValid == false)
						{
							return false;
						}
						
						return isValidTransformOrigin(value[1], false, true);
					
					
					case INHERIT, INITIAL:
						return true;
						
					default:
						return isValidTransformOrigin(styleValue, true, true);
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
					
			case CSSConstants.FONT_FAMILY:
				switch(styleValue)
				{
					case CSS_LIST(values):
						
						var length:Int = values.length;
						for (i in 0...length)
						{
							switch(values[i])
							{
								case IDENTIFIER(value):
									
								case STRING(value):
									
								default:
									return false;
							}
						}
						
						return true;
						
					case IDENTIFIER(value):
						return true;
						
					case STRING(value):
						return true;
						
					case INHERIT, INITIAL:
						return true;	
						
					default:
				}
				
			case CSSConstants.FLOAT, CSSConstants.CLEAR:
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
						
					case INTEGER(value):
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
				
			case CSSConstants.BACKGROUND_ATTACHMENT:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case SCROLL, FIXED:
								return true;
								
							default:	
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
						
					case CSS_LIST(value):
						for (i in 0...value.length)
						{
							if (isValidProperty(CSSConstants.BACKGROUND_REPEAT, value[i]) == false)
							{
								return false;
							}
						}
						return true;
						
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
						
					case CSS_LIST(value):
						for (i in 0...value.length)
						{
							if (isValidProperty(CSSConstants.BACKGROUND_SIZE, value[i]) == false)
							{
								return false;
							}
						}
						return true;	
						
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
						
					case CSS_LIST(value):
						for (i in 0...value.length)
						{
							if (isValidProperty(propertyIndex, value[i]) == false)
							{
								return false;
							}
						}
						return true;	
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			case CSSConstants.TRANSITION_PROPERTY:
				switch(styleValue)
				{
					case CSS_LIST(value):
						var length:Int = value.length;
						for (i in 0...length)
						{
							var isValid:Bool = isValidTransitionProperty(value[i]);
							if (isValid == false)
							{
								return false;
							}
						}
						return true;
						
					default:
						return isValidTransitionProperty(styleValue);
				}
					
			case CSSConstants.TRANSITION_DURATION, CSSConstants.TRANSITION_DELAY:
				switch(styleValue)
				{
					case CSS_LIST(value):
						var length:Int = value.length;
						for (i in 0...length)
						{
							var isValid:Bool = isValidTransitionDelayOrDuration(value[i]);
							if (isValid == false)
							{
								return false;
							}
						}
						return true;
						
					default:	
						return isValidTransitionDelayOrDuration(styleValue);
				}
				
			case CSSConstants.TRANSITION_TIMING_FUNCTION:
				switch(styleValue)
				{
					case CSS_LIST(value):
						var length:Int = value.length;
						for (i in 0...length)
						{
							var isValid:Bool = isValidTransitionTimingFunction(value[i]);
							if (isValid == false)
							{
								return false;
							}
						}
						
					default:	
						return isValidTransitionTimingFunction(styleValue);
				}
				
			case CSSConstants.BORDER_TOP_WIDTH, CSSConstants.BORDER_RIGHT_WIDTH,
			CSSConstants.BORDER_BOTTOM_WIDTH, CSSConstants.BORDER_LEFT_WIDTH,
			CSSConstants.OUTLINE_WIDTH:
				switch(styleValue)
				{
					case INHERIT, INITIAL:
						return true;
						
					default:	
						return isValidBorderWidthValue(styleValue);
				}
				
			case CSSConstants.BORDER_TOP_COLOR, CSSConstants.BORDER_RIGHT_COLOR,
			CSSConstants.BORDER_BOTTOM_COLOR, CSSConstants.BORDER_LEFT_COLOR:	
				switch(styleValue)
				{
					case INHERIT, INITIAL:
						return true;
						
					default:	
						return isValidBorderColorValue(styleValue);
				}
				
			case CSSConstants.BORDER_TOP_STYLE, CSSConstants.BORDER_RIGHT_STYLE,
			CSSConstants.BORDER_BOTTOM_STYLE, CSSConstants.BORDER_LEFT_STYLE:
				switch(styleValue)
				{
					case INHERIT, INITIAL:
						return true;
						
					default:	
						return isValidBorderStyleValue(styleValue);
				}
				
			case CSSConstants.OUTLINE_STYLE:
				switch(styleValue)
				{
					case INHERIT, INITIAL:
						return true;
						
					default:	
						return isValidOutlineStyleValue(styleValue);
				}
				
			case CSSConstants.OUTLINE_COLOR:
				switch(styleValue)
				{
					case INHERIT, INITIAL:
						return true;
						
					default:
						return isValidOutlineColorValue(styleValue);
				}
				
				
			case CSSConstants.TEXT_DECORATION:
				switch(styleValue)
				{
					case KEYWORD(value):
						switch(value)
						{
							case NONE, UNDERLINE, OVERLINE, LINE_THROUGH, BLINK:
								return true;
							
							default:	
						}
						
					case GROUP(value):
						if (value.length != 2 && value.length != 3 && value.length != 4)
						{
							return false;
						}
						
						var foundUnderline:Bool = false;
						var foundOverline:Bool = false;
						var foundLineThrough:Bool = false;
						var foundBlink:Bool = false;
						
						for (i in 0...value.length)
						{
							switch(value[i])
							{
								case KEYWORD(value):
									switch(value)
									{
										case UNDERLINE:
											if (foundUnderline == true)
											{
												//means that underline keyword was
												//used twice
												return false;
											}
											foundUnderline = true;
											
										case OVERLINE:
											if (foundOverline == true)
											{
												return false;
											}
											foundOverline = true; 	
											
										case LINE_THROUGH:
											if (foundLineThrough == true)
											{
												return false;
											}
											foundLineThrough = true; 
											
										case BLINK:
											if (foundBlink == true)
											{
												return false;
											}
											foundBlink = true; 	
											
										default:
											false;
									}
									
								default:
									false;
							}
						}
						
						return true;
					
					case INHERIT, INITIAL:
						return true;
						
					default:	
				}
		}
		
		return false;
	}
	
	/**
	 * Return wether a property has a valid value for 
	 * for the transition-timing-function property, excluding
	 * group and list value
	 */
	private function isValidTransitionTimingFunction(property:CSSPropertyValue):Bool
	{
		switch(property)
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
		
		return false;
	}
	
	/**
	 * Return wether a property has a valid value for 
	 * for the transition-property property, excluding
	 * group and list value
	 */
	private function isValidTransitionProperty(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case KEYWORD(value):
				switch(value)
				{
					//add special case for left, right, top and bottom which 
					//might both be style names and css keyword
					case NONE, ALL, LEFT, RIGHT, TOP, BOTTOM:
						return true;
						
					default:	
				}
				
			case IDENTIFIER(value):	
				return true;
				
			case INHERIT, INITIAL:
				return true;	
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether a property has a valid value for 
	 * for the transition-duration or transition-delay properties, excluding
	 * group and list value
	 */
	private function isValidTransitionDelayOrDuration(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case INTEGER(value):
				if (value == 0)
				{
					return true;
				}
			
			case TIME(value):
				return true;
				
			case INHERIT, INITIAL:
				return true;			
				
			default:
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
					case LEFT, CENTER, RIGHT, BOTTOM, TOP:
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
	 */
	private function isShorthand(propertyIndex:Int):Bool
	{
		switch(propertyIndex)
		{
			case CSSConstants.MARGIN, CSSConstants.PADDING, CSSConstants.CSS_OVERFLOW,
			CSSConstants.TRANSITION, CSSConstants.BACKGROUND, CSSConstants.FONT,
			CSSConstants.BORDER_TOP, CSSConstants.BORDER_LEFT, CSSConstants.BORDER_RIGHT,
			CSSConstants.BORDER_BOTTOM, CSSConstants.BORDER_WIDTH, CSSConstants.BORDER_COLOR,
			CSSConstants.BORDER_STYLE, CSSConstants.BORDER, CSSConstants.OUTLINE:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * Apply the individual values repesented by a shorthand, once it has
	 * been checked that the value of the shorthand is valid
	 */
	private function setShorthand(propertyIndex:Int, styleValue:CSSPropertyValue, important:Bool):Void
	{
		switch(propertyIndex)
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
				
			case CSSConstants.BACKGROUND:
				switch(styleValue)
				{
					case URL(value):
						setTypedProperty(CSSConstants.BACKGROUND_IMAGE, styleValue, important);
						
					case COLOR(value):
						setTypedProperty(CSSConstants.BACKGROUND_COLOR, styleValue, important);
						
					case KEYWORD(value):
						if (isValidBackgroundRepeat(styleValue) == true)
						{
							setTypedProperty(CSSConstants.BACKGROUND_REPEAT, styleValue, important);
						}
						else if (isValidBackgroundPosition(styleValue) == true)
						{
							setTypedProperty(CSSConstants.BACKGROUND_POSITION, styleValue, important);
						}
						else if (isValidBackgroundAttachment(styleValue) == true)
						{
							setTypedProperty(CSSConstants.BACKGROUND_ATTACHMENT, styleValue, important);
						}
						else
						{
							switch(value)
							{
								case NONE:
									var initialStyleDeclaration:InitialStyleDeclaration = InitialStyleDeclaration.getInstance();
									setTypedProperty(CSSConstants.BACKGROUND_ATTACHMENT, initialStyleDeclaration.getTypedProperty(CSSConstants.BACKGROUND_ATTACHMENT).typedValue, important);
									setTypedProperty(CSSConstants.BACKGROUND_POSITION, initialStyleDeclaration.getTypedProperty(CSSConstants.BACKGROUND_POSITION).typedValue, important);
									setTypedProperty(CSSConstants.BACKGROUND_COLOR, initialStyleDeclaration.getTypedProperty(CSSConstants.BACKGROUND_COLOR).typedValue, important);
									setTypedProperty(CSSConstants.BACKGROUND_REPEAT, initialStyleDeclaration.getTypedProperty(CSSConstants.BACKGROUND_REPEAT).typedValue, important);
									setTypedProperty(CSSConstants.BACKGROUND_IMAGE, initialStyleDeclaration.getTypedProperty(CSSConstants.BACKGROUND_IMAGE).typedValue, important);
									
								default:	
							}
						}
						
					case GROUP(value):
						var length:Int = value.length;
						
						//background position can have 2 components, store the first so
						//that if another is found, group them
						var firstBackgroundPosition:CSSPropertyValue = null;
						
						for (i in 0...length)
						{
							switch(value[i])
							{
								case COLOR(color):
									setTypedProperty(CSSConstants.BACKGROUND_COLOR, value[i], important);
									
								case URL(url):
									setTypedProperty(CSSConstants.BACKGROUND_IMAGE, value[i], important);
									
								default:
									if (isValidBackgroundRepeat(value[i]) == true)
									{
										setTypedProperty(CSSConstants.BACKGROUND_REPEAT, value[i], important);
									}
									else if (isValidBackgroundAttachment(value[i]) == true)
									{
										setTypedProperty(CSSConstants.BACKGROUND_ATTACHMENT, value[i], important);
									}
									else if (isValidBackgroundPosition(value[i]) == true)
									{
										if (firstBackgroundPosition == null)
										{
											setTypedProperty(CSSConstants.BACKGROUND_POSITION, value[i], important);
											firstBackgroundPosition = value[i];
										}
										//when a second value is found which is a background
										//position, group it with the first
										else
										{
											setTypedProperty(CSSConstants.BACKGROUND_POSITION, CSSPropertyValue.GROUP([firstBackgroundPosition, value[i]]), important);
										}
									}
							}
						}
						
					default:	
				}
				
			case CSSConstants.FONT:
				switch(styleValue)
				{
					case GROUP(values):
						//set all font styles except font family
						setFontShorthandGoup(values, important);
						//in this case, font-family has only one font name which is the last value
						setTypedProperty(CSSConstants.FONT_FAMILY, values[values.length - 1], important);
						
					case CSS_LIST(values):
						switch(values[0])
						{
							case GROUP(groupValues):
								//set all font styles except font family
								setFontShorthandGoup(groupValues, important);
								
								//in list case, the font names are the last item of the group
								//which is the first font name and all the subsequent list
								//values are the other font names
								var fontNames:Array<CSSPropertyValue> = [];
								fontNames.push(groupValues[groupValues.length - 1]);
								
								var length:Int = values.length;
								var i:Int = 1;
								while (i < length)
								{
									fontNames.push(values[i]);
									i++;
								}
								
								//set the list of font name
								setTypedProperty(CSSConstants.FONT_FAMILY, CSS_LIST(fontNames), important);
								
							default:
						}
						
					default:	
				}
				
			//TODO 2 : should force initial value when not specified ?	
			case CSSConstants.TRANSITION:
				
				//all values of transition styles will be pushed in those array before being affected to style
				//if not empty
				var transitionPropertyValues:Array<CSSPropertyValue> = new Array<CSSPropertyValue>();
				var transitionDurationValues:Array<CSSPropertyValue> = new Array<CSSPropertyValue>();
				var transitionDelayValues:Array<CSSPropertyValue> = new Array<CSSPropertyValue>();
				var transitionTimingFunctionValues:Array<CSSPropertyValue> = new Array<CSSPropertyValue>();
				
				switch(styleValue)
				{
					case CSS_LIST(value):
						for (i in 0...value.length)
						{
							switch(value[i])
							{
								case GROUP(value):
									setTransitionGroupShorthand(value, transitionPropertyValues, transitionDurationValues
									, transitionDelayValues, transitionTimingFunctionValues);
								
								default:
									setTransitionShorthand(value[i], false, transitionPropertyValues, transitionDurationValues
									, transitionDelayValues, transitionTimingFunctionValues);
							}
						}
					
					case GROUP(value):
						setTransitionGroupShorthand(value, transitionPropertyValues, transitionDurationValues
						, transitionDelayValues, transitionTimingFunctionValues);
						
					default:	
						setTransitionShorthand(styleValue, false, transitionPropertyValues, transitionDurationValues
						, transitionDelayValues, transitionTimingFunctionValues);
				}
				
				if (transitionPropertyValues.length > 0)
				{
					if (transitionPropertyValues.length == 1)
					{
						setTypedProperty(CSSConstants.TRANSITION_PROPERTY, transitionPropertyValues[0], important);
					}
					else
					{
						setTypedProperty(CSSConstants.TRANSITION_PROPERTY, CSS_LIST(transitionPropertyValues), important);
					}
				}
				
				if (transitionDelayValues.length > 0)
				{
					if (transitionDelayValues.length == 1)
					{
						setTypedProperty(CSSConstants.TRANSITION_DELAY, transitionDelayValues[0], important);
					}
					else
					{
						setTypedProperty(CSSConstants.TRANSITION_DELAY, CSS_LIST(transitionDelayValues), important);
					}
				}
				
				if (transitionDurationValues.length > 0)
				{
					if (transitionDurationValues.length == 1)
					{
						setTypedProperty(CSSConstants.TRANSITION_DURATION, transitionDurationValues[0], important);
					}
					else
					{
						setTypedProperty(CSSConstants.TRANSITION_DURATION, CSS_LIST(transitionDurationValues), important);
					}
				}
				
				if (transitionTimingFunctionValues.length > 0)
				{
					if (transitionTimingFunctionValues.length == 1)
					{
						setTypedProperty(CSSConstants.TRANSITION_TIMING_FUNCTION, transitionTimingFunctionValues[0], important);
					}
					else
					{
						setTypedProperty(CSSConstants.TRANSITION_TIMING_FUNCTION, CSS_LIST(transitionTimingFunctionValues), important);
					}
				}
				
			case CSSConstants.BORDER_WIDTH:
				switch(styleValue)
				{
					case KEYWORD(value):
						setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, styleValue, important);
					
					case LENGTH(value):
						setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, styleValue, important);
						
					case INTEGER(value):
						setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, styleValue, important);
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, value[0], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, value[1], important);
								
							case 3:
								setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, value[3], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, value[1], important);
								
							case 4:
								setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, value[2], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, value[3], important);
								
							default:	
						}
						
					case INHERIT, INITIAL:
						setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, styleValue, important);
						
					default:	
				}
				
			case CSSConstants.BORDER_COLOR:
				switch(styleValue)
				{
					case COLOR(value):
						setTypedProperty(CSSConstants.BORDER_TOP_COLOR, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_COLOR, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_COLOR, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_COLOR, styleValue, important);
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								setTypedProperty(CSSConstants.BORDER_TOP_COLOR, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_COLOR, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_COLOR, value[0], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_COLOR, value[1], important);
								
							case 3:
								setTypedProperty(CSSConstants.BORDER_TOP_COLOR, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_COLOR, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_COLOR, value[3], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_COLOR, value[1], important);
								
							case 4:
								setTypedProperty(CSSConstants.BORDER_TOP_COLOR, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_COLOR, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_COLOR, value[2], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_COLOR, value[3], important);
								
							default:	
						}
						
					case INHERIT, INITIAL:
						setTypedProperty(CSSConstants.BORDER_TOP_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_WIDTH, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_WIDTH, styleValue, important);
						
					default:	
				}	
				
			case CSSConstants.BORDER_STYLE:
				switch(styleValue)
				{
					case KEYWORD(value):
						setTypedProperty(CSSConstants.BORDER_TOP_STYLE, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_STYLE, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_STYLE, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_STYLE, styleValue, important);
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								setTypedProperty(CSSConstants.BORDER_TOP_STYLE, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_STYLE, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_STYLE, value[0], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_STYLE, value[1], important);
								
							case 3:
								setTypedProperty(CSSConstants.BORDER_TOP_STYLE, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_STYLE, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_STYLE, value[3], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_STYLE, value[1], important);
								
							case 4:
								setTypedProperty(CSSConstants.BORDER_TOP_STYLE, value[0], important);
								setTypedProperty(CSSConstants.BORDER_RIGHT_STYLE, value[1], important);
								setTypedProperty(CSSConstants.BORDER_BOTTOM_STYLE, value[2], important);
								setTypedProperty(CSSConstants.BORDER_LEFT_STYLE, value[3], important);
								
							default:	
						}
						
					case INHERIT, INITIAL:
						setTypedProperty(CSSConstants.BORDER_TOP_STYLE, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_RIGHT_STYLE, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_BOTTOM_STYLE, styleValue, important);
						setTypedProperty(CSSConstants.BORDER_LEFT_STYLE, styleValue, important);
						
					default:	
				}		
				
			case CSSConstants.BORDER_TOP, CSSConstants.BORDER_BOTTOM,
			CSSConstants.BORDER_LEFT, CSSConstants.BORDER_RIGHT,
			CSSConstants.BORDER:
				switch(styleValue)
				{
					case GROUP(value):
						var borderColor:CSSPropertyValue = null;
						var borderWidth:CSSPropertyValue = null;
						var borderStyle:CSSPropertyValue = null;
						for (i in 0...value.length)
						{
							if (isValidBorderColorValue(value[i]) == true)
							{
								borderColor = value[i];
							}
							else if (isValidBorderWidthValue(value[i]) == true)
							{
								borderWidth = value[i];
							}
							else if (isValidBorderStyleValue(value[i]) == true)
							{
								borderStyle = value[i];
							}
						}
						setTypedBordersProperties(propertyIndex, borderWidth, borderColor, borderStyle, important);
						
					default:	
						setBorderShorthand(propertyIndex, styleValue, important);
				}
				
			case CSSConstants.OUTLINE:
				switch(styleValue)
				{
					case GROUP(value):
						var outlineColor:CSSPropertyValue = null;
						var outlineWidth:CSSPropertyValue = null;
						var outlineStyle:CSSPropertyValue = null;
						for (i in 0...value.length)
						{
							if (isValidOutlineColorValue(value[i]) == true)
							{
								outlineColor = value[i];
							}
							else if (isValidBorderWidthValue(value[i]) == true)
							{
								outlineWidth = value[i];
							}
							else if (isValidOutlineStyleValue(value[i]) == true)
							{
								outlineStyle = value[i];
							}
						}
						setTypedOutlineProperties(outlineWidth, outlineColor, outlineStyle, important);
						
					default:
						if (isValidOutlineColorValue(styleValue) == true)
						{
							setTypedOutlineProperties(null, styleValue, null, important);
						}
						else if (isValidOutlineStyleValue(styleValue) == true)
						{
							setTypedOutlineProperties(null, null, styleValue, important);
						}
						else if (isValidBorderWidthValue(styleValue) == true)
						{
							setTypedOutlineProperties(styleValue, null, null, important);
						}
				}
				
			default:	
						
		}
	}
	
	/**
	 * Set the value for a border shorthand style, excluding 
	 * groups values
	 */
	private function setBorderShorthand(propertyIndex:Int, styleValue:CSSPropertyValue, important:Bool):Void
	{
		switch(styleValue)
		{
			case KEYWORD(value):
				if (isValidBorderWidthValue(styleValue) == true)
				{
					setTypedBordersProperties(propertyIndex, styleValue, null, null, important);
				}
				else if (isValidBorderStyleValue(styleValue) == true)
				{
					setTypedBordersProperties(propertyIndex, null, null, styleValue, important);
				}
				
			case INTEGER(value):
				setTypedBordersProperties(propertyIndex, styleValue, null, null, important);
				
			case LENGTH(value):	
				setTypedBordersProperties(propertyIndex, styleValue, null, null, important);
				
			case COLOR(value):
				setTypedBordersProperties(propertyIndex, null, styleValue, null, important);
				
			case INHERIT, INITIAL:
				setTypedBordersProperties(propertyIndex, styleValue, styleValue, styleValue, important);
				
			default:	
		}
	}
	
	/**
	 * Used for background shorthands "border-top", "border-left", "border-right", "border-bottom"
	 * and "border", set all the properties on the matching border style 
	 */
	private function setTypedBordersProperties(propertyIndex:Int, borderWidth:CSSPropertyValue, borderColor:CSSPropertyValue, borderStyle:CSSPropertyValue, important:Bool):Void
	{
		switch(propertyIndex)
		{
			case CSSConstants.BORDER_TOP:
				setTypedBorderProperties(CSSConstants.BORDER_TOP_WIDTH, borderWidth, CSSConstants.BORDER_TOP_COLOR, borderColor, CSSConstants.BORDER_TOP_STYLE, borderStyle, important);
				
			case CSSConstants.BORDER_RIGHT:
				setTypedBorderProperties(CSSConstants.BORDER_RIGHT_WIDTH, borderWidth, CSSConstants.BORDER_RIGHT_COLOR, borderColor, CSSConstants.BORDER_RIGHT_STYLE, borderStyle, important);
				
			case CSSConstants.BORDER_BOTTOM:
				setTypedBorderProperties(CSSConstants.BORDER_BOTTOM_WIDTH, borderWidth, CSSConstants.BORDER_BOTTOM_COLOR, borderColor, CSSConstants.BORDER_BOTTOM_STYLE, borderStyle, important);
			
			case CSSConstants.BORDER_LEFT:
				setTypedBorderProperties(CSSConstants.BORDER_LEFT_WIDTH, borderWidth, CSSConstants.BORDER_LEFT_COLOR, borderColor, CSSConstants.BORDER_LEFT_STYLE, borderStyle, important);
				
			case CSSConstants.BORDER:
				setTypedBorderProperties(CSSConstants.BORDER_TOP_WIDTH, borderWidth, CSSConstants.BORDER_TOP_COLOR, borderColor, CSSConstants.BORDER_TOP_STYLE, borderStyle, important);
				setTypedBorderProperties(CSSConstants.BORDER_RIGHT_WIDTH, borderWidth, CSSConstants.BORDER_RIGHT_COLOR, borderColor, CSSConstants.BORDER_RIGHT_STYLE, borderStyle, important);
				setTypedBorderProperties(CSSConstants.BORDER_BOTTOM_WIDTH, borderWidth, CSSConstants.BORDER_BOTTOM_COLOR, borderColor, CSSConstants.BORDER_BOTTOM_STYLE, borderStyle, important);
				setTypedBorderProperties(CSSConstants.BORDER_LEFT_WIDTH, borderWidth, CSSConstants.BORDER_LEFT_COLOR, borderColor, CSSConstants.BORDER_LEFT_STYLE, borderStyle, important);
			
			default:	
		}
	}
	
	/**
	 * For a givent border, set its width, color and style, using initial
	 * css value if no other value are provided
	 */
	private function setTypedBorderProperties(borderWidthPropertyIndex:Int, borderWidth:CSSPropertyValue, borderColorPropertyIndex:Int, borderColor:CSSPropertyValue, borderStylePropertyIndex:Int, borderStyle:CSSPropertyValue, important:Bool):Void
	{
		if (borderWidth == null)
		{
			borderWidth = InitialStyleDeclaration.getInstance().getTypedProperty(CSSConstants.BORDER_TOP_WIDTH).typedValue;
		}
		
		setTypedProperty(borderWidthPropertyIndex, borderWidth, important);
		
		if (borderColor == null)
		{
			borderColor = InitialStyleDeclaration.getInstance().getTypedProperty(CSSConstants.BORDER_TOP_COLOR).typedValue;
		}
		setTypedProperty(borderColorPropertyIndex, borderColor, important);
		
		if (borderStyle == null)
		{
			borderStyle = InitialStyleDeclaration.getInstance().getTypedProperty(CSSConstants.BORDER_TOP_STYLE).typedValue;
		}
		
		setTypedProperty(borderStylePropertyIndex, borderStyle, important);
		
	}
	
	/**
	 * set all outline properties at once, using initial css value if no
	 * other values are provided
	 */
	private function setTypedOutlineProperties(outlineWidth:CSSPropertyValue, outlineColor:CSSPropertyValue, outlineStyle:CSSPropertyValue, important:Bool):Void
	{
		if (outlineWidth == null)
		{
			outlineWidth = InitialStyleDeclaration.getInstance().getTypedProperty(CSSConstants.OUTLINE_WIDTH).typedValue;
		}
		
		setTypedProperty(CSSConstants.OUTLINE_WIDTH, outlineWidth, important);
		
		if (outlineColor == null)
		{
			outlineColor = InitialStyleDeclaration.getInstance().getTypedProperty(CSSConstants.OUTLINE_COLOR).typedValue;
		}
		setTypedProperty(CSSConstants.OUTLINE_COLOR, outlineColor, important);
		
		if (outlineStyle == null)
		{
			outlineStyle = InitialStyleDeclaration.getInstance().getTypedProperty(CSSConstants.OUTLINE_STYLE).typedValue;
		}
		
		setTypedProperty(CSSConstants.OUTLINE_STYLE, outlineStyle, important);
	}
	
	/**
	 * Set the values for each component of a transition
	 * shorthand group
	 */
	private function setTransitionGroupShorthand(styleValues:Array<CSSPropertyValue>, transitionProperty:Array<CSSPropertyValue>,
	transitionDuration:Array<CSSPropertyValue>, transitionDelay:Array<CSSPropertyValue>, transitionTimingFunction:Array<CSSPropertyValue>):Void
	{
		//a flag checking wether a transition 
		//duration already exists in the group, if it does
		//next time value will be transition delay
		var hasTransitionDuration:Bool = false;
		
		for (i in 0...styleValues.length)
		{
			setTransitionShorthand(styleValues[i], hasTransitionDuration, transitionProperty, transitionDuration
			, transitionDelay, transitionTimingFunction);
			
			if (isValidTransitionDelayOrDuration(styleValues[i]) == true)
			{
				hasTransitionDuration = true;
			}
		}
	}
	
	/**
	 * Set a value of a transition shorthand, excluding group and lists to
	 * the right transition style
	 */
	private function setTransitionShorthand(styleValue:CSSPropertyValue, useDelayForTime:Bool, transitionProperty:Array<CSSPropertyValue>,
	transitionDuration:Array<CSSPropertyValue>, transitionDelay:Array<CSSPropertyValue>, transitionTimingFunction:Array<CSSPropertyValue>):Void
	{
		switch(styleValue)
		{
			case IDENTIFIER(value):
				transitionProperty.push(styleValue);
				
			case TIME(value):
				if (useDelayForTime == false)
				{
					transitionDuration.push(styleValue);
				}
				else
				{
					transitionDelay.push(styleValue);
				}
				
			case KEYWORD(value):
				if (isValidTransitionProperty(styleValue) == true)
				{
					transitionProperty.push(styleValue);
				}
				else if (isValidTransitionTimingFunction(styleValue) == true)
				{
					transitionTimingFunction.push(styleValue);
				}
				
			default:	
				transitionTimingFunction.push(styleValue);
		}
	}
	
	/**
	 * Return wether the value of a given CSS shorthand property
	 * is valid
	 */
	private function isValidShorthand(propertyIndex:Int, styleValue:CSSPropertyValue):Bool
	{
		switch(propertyIndex)
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
			
			//TODO : for now only support background shorthand for CSS 2.1
			//when using a CSS 3 background style, need to use individual property
			//for now
			case CSSConstants.BACKGROUND:
				return isValidBackgroundShorthand(styleValue);
				
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
			
			case CSSConstants.FONT:
				return isValidFontShorthand(styleValue);
				
			case CSSConstants.TRANSITION:
				switch(styleValue)
				{
					case CSS_LIST(value):
						var length:Int = value.length;
						for (i in 0...length)
						{
							if (isValidTransitionShorthand(value[i]) == false)
							{
								return false;
							}
						}
						
						return true;
						
					default:
						return isValidTransitionShorthand(styleValue);
				}
				
			case CSSConstants.BORDER_WIDTH:
				switch(styleValue)
				{
					case KEYWORD(value):
						return isValidBorderWidthValue(styleValue);
					
					case LENGTH(value):
						return isValidBorderWidthValue(styleValue);
						
					case INTEGER(value):
						return isValidBorderWidthValue(styleValue);
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								if (isValidBorderWidthValue(value[0]) == true &&
								isValidBorderWidthValue(value[1]) == true)
								{
									return true;
								}
								
							case 3:
								if (isValidBorderWidthValue(value[0]) == true &&
								isValidBorderWidthValue(value[1]) == true && isValidBorderWidthValue(value[2]))
								{
									return true;
								}	
								
							case 4:
								if (isValidBorderWidthValue(value[0]) == true &&
								isValidBorderWidthValue(value[1]) == true && isValidBorderWidthValue(value[2])
								&& isValidBorderWidthValue(value[3]))
								{
									return true;
								}	
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			case CSSConstants.BORDER_COLOR:
				switch(styleValue)
				{
					case COLOR(value):
						return isValidBorderColorValue(styleValue);
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								if (isValidBorderColorValue(value[0]) == true &&
								isValidBorderColorValue(value[1]) == true)
								{
									return true;
								}
								
							case 3:
								if (isValidBorderColorValue(value[0]) == true &&
								isValidBorderColorValue(value[1]) == true && isValidBorderColorValue(value[2]))
								{
									return true;
								}	
								
							case 4:
								if (isValidBorderColorValue(value[0]) == true &&
								isValidBorderColorValue(value[1]) == true && isValidBorderColorValue(value[2])
								&& isValidBorderColorValue(value[3]))
								{
									return true;
								}	
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}	
				
			case CSSConstants.BORDER_STYLE:
				switch(styleValue)
				{
					case KEYWORD(value):
						return isValidBorderStyleValue(styleValue);
						
					case GROUP(value):
						switch(value.length)
						{
							case 2:
								if (isValidBorderStyleValue(value[0]) == true &&
								isValidBorderStyleValue(value[1]) == true)
								{
									return true;
								}
								
							case 3:
								if (isValidBorderStyleValue(value[0]) == true &&
								isValidBorderStyleValue(value[1]) == true && isValidBorderStyleValue(value[2]))
								{
									return true;
								}	
								
							case 4:
								if (isValidBorderStyleValue(value[0]) == true &&
								isValidBorderStyleValue(value[1]) == true && isValidBorderStyleValue(value[2])
								&& isValidBorderStyleValue(value[3]))
								{
									return true;
								}	
								
							default:	
						}
						
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			case CSSConstants.BORDER_TOP, CSSConstants.BORDER_RIGHT,
			CSSConstants.BORDER_BOTTOM, CSSConstants.BORDER_LEFT,
			CSSConstants.BORDER:	
				switch(styleValue)
				{
					case KEYWORD(value):
						if (isValidBorderWidthValue(styleValue) == true || isValidBorderStyleValue(styleValue) == true)
						{
							return true;
						}
						
					case COLOR(value):
						return true;
						
					case INTEGER(value):
						if (value == 0)
						{
							return true;
						}
						
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case GROUP(value):
						if (value.length != 2 && value.length != 3)
						{
							return false;
						}
						
						var foundBorderWidth:Bool = false;
						var foundBorderStyle:Bool = false;
						var foundBorderColor:Bool = false;
						
						for (i in 0...value.length)
						{
							if (isValidBorderWidthValue(value[i]) == true)
							{
								if (foundBorderWidth == true)
								{
									//means duplicate border width value provided
									return false;
								}
								foundBorderWidth = true;
							}
							else if (isValidBorderColorValue(value[i]) == true)
							{
								if (foundBorderColor == true)
								{
									return false;
								}
								foundBorderColor = true;
							}
							else if (isValidBorderStyleValue(value[i]) == true)
							{
								if (foundBorderStyle == true)
								{
									return false;
								}
								foundBorderStyle = true;
							}
							else
							{
								return false;
							}
						}
						
						return true;
					
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			case CSSConstants.OUTLINE:
				switch(styleValue)
				{
					case KEYWORD(value):
						if (isValidBorderWidthValue(styleValue) == true || isValidOutlineStyleValue(styleValue) == true || isValidOutlineColorValue(styleValue) == true)
						{
							return true;
						}
						
					case COLOR(value):
						return true;
						
					case INTEGER(value):
						if (value == 0)
						{
							return true;
						}
						
					case LENGTH(value):
						if (isPositiveLength(value) == true)
						{
							return true;
						}
						
					case GROUP(value):
						if (value.length != 2 && value.length != 3)
						{
							return false;
						}
						
						var foundOutlineWidth:Bool = false;
						var foundOutlineStyle:Bool = false;
						var foundOutlineColor:Bool = false;
						
						for (i in 0...value.length)
						{
							if (isValidBorderWidthValue(value[i]) == true)
							{
								if (foundOutlineWidth == true)
								{
									//means duplicate outline width value provided
									return false;
								}
								foundOutlineWidth = true;
							}
							else if (isValidOutlineColorValue(value[i]) == true)
							{
								if (foundOutlineColor == true)
								{
									return false;
								}
								foundOutlineColor = true;
							}
							else if (isValidOutlineStyleValue(value[i]) == true)
							{
								if (foundOutlineStyle == true)
								{
									return false;
								}
								foundOutlineStyle = true;
							}
							else
							{
								return false;
							}
						}
						
						return true;
					
					case INHERIT, INITIAL:
						return true;	
						
					default:	
				}
				
			default:	
						
		}
		
		return false;
	}
	
	/**
	 * Return wether a background shorthand value
	 * is valid, excluding list value
	 */
	private function isValidBackgroundShorthand(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case URL(value):
				return true;
				
			case COLOR(value):
				return true;
				
			case KEYWORD(value):
				switch (value)
				{
					//list all valid keywords for background-repeat, background-attachment
					//and background-position as well as 'none' to reset all background properties
					case REPEAT, REPEAT_X, REPEAT_Y, NO_REPEAT, FIXED, SCROLL,
					LEFT, CENTER, RIGHT, TOP, BOTTOM, NONE:
						return true;
						
					default:	
				}
				
			case GROUP(value):	
				
				var length:Int = value.length;
				
				//one flag for each property, as property
				//order must be respected for background shorthand
				//property can be ommited however
				var foundBackgroundColor:Bool = false;
				var foundBackgroundImage:Bool = false;
				var foundBackgroundRepeat:Bool = false;
				var foundBackgroundAttachment:Bool = false;
				
				//background position can have 2 components
				var foundFirstBackgroundPosition:Bool = false;
				var foundSecondBackgroundPosition:Bool = false;
				
				for (i in 0...length)
				{
					switch(value[i])
					{
						case COLOR(value):
							//if a color was already found, then style is
							//invalid
							if (foundBackgroundColor == true)
							{
								return false;
							}
							foundBackgroundColor = true;
							
						case URL(value):
							if (foundBackgroundImage == true)
							{
								return false;
							}
							foundBackgroundImage = true;
							//set also as true, as now that a url was found
							//no color can be defined after
							foundBackgroundColor = true;
							
						default:
							if (isValidBackgroundRepeat(value[i]) == true)
							{
								if (foundBackgroundRepeat == true)
								{
									return false;
								}
								
								foundBackgroundRepeat = true;
								foundBackgroundImage = true;
								foundBackgroundColor = true;
							}
							else if (isValidBackgroundAttachment(value[i]) == true)
							{
								if (foundBackgroundAttachment == true)
								{
									return false;
								}
								
								foundBackgroundAttachment = true;
								foundBackgroundColor = true;
								foundBackgroundRepeat = true;
								foundBackgroundImage = true; 
							}
							else if (isValidBackgroundPosition(value[i]) == true)
							{
								if (foundSecondBackgroundPosition == true)
								{
									return false;
								}
								
								if (foundFirstBackgroundPosition == true)
								{
									foundSecondBackgroundPosition = true;
								}
								else
								{
									foundFirstBackgroundPosition = true;
								}
								
								foundBackgroundAttachment = true;
								foundBackgroundColor = true;
								foundBackgroundRepeat = true;
								foundBackgroundImage = true; 
							}
					}
				}
				return true;
				
			case INHERIT, INITIAL:
				return true;
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Wether the style is a valid background repeat value,
	 * excluding inherit and initial
	 */
	private function isValidBackgroundRepeat(styleValue:CSSPropertyValue):Bool
	{
		switch (styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case REPEAT, REPEAT_X, REPEAT_Y, NO_REPEAT:
						return true;
						
					default:
				}	
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Wether the style is a valid background attachment value,
	 * excluding inherit and initial
	 */
	private function isValidBackgroundAttachment(styleValue:CSSPropertyValue):Bool
	{
		switch (styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case FIXED, SCROLL:
						return true;
						
					default:
				}	
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether a transition shorthand value
	 * is valid, excluding list value
	 */
	private function isValidTransitionShorthand(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case TIME(value):
				return isValidTransitionDelayOrDuration(styleValue);
				
			case IDENTIFIER(value):
				return true;
			
			case KEYWORD(keyword):
				var isValid:Bool = isValidTransitionProperty(styleValue);
				if (isValid == true)
				{
					return true;
				}
				return isValidTransitionTimingFunction(styleValue);	
				
			case GROUP(value):
				return isValidTransitionGroup(value);
				
			case INHERIT, INITIAL:
				return true;
				
			default:
				return isValidTransitionTimingFunction(styleValue);
		}
	}
	
	/**
	 * Apply all the values of the font shorthand when font shorthand
	 * is a group or list of values, excluding the font family values
	 */
	private function setFontShorthandGoup(styleValues:Array<CSSPropertyValue>, important:Bool):Void
	{
		var foundFontStyle:Bool = false;
		var foundFontVariant:Bool = false;
		var foundFontWeight:Bool = false;
		
		var length:Int = styleValues.length;
		for (i in 0...length)
		{
			switch(styleValues[i])
			{
				case KEYWORD(value):
					switch(value)
					{
						case ITALIC, OBLIQUE:
							setTypedProperty(CSSConstants.FONT_STYLE, styleValues[i], important);
							foundFontStyle = true;
							
						case SMALL_CAPS:
							setTypedProperty(CSSConstants.FONT_VARIANT, styleValues[i], important);
							foundFontVariant = true;
							
						case BOLD, BOLDER, LIGHTER:
							setTypedProperty(CSSConstants.FONT_WEIGHT, styleValues[i], important);
							foundFontWeight = true;
							
						case XX_SMALL, X_SMALL, SMALL, MEDIUM,
						LARGE, X_LARGE, XX_LARGE, LARGER, SMALLER:
							setTypedProperty(CSSConstants.FONT_SIZE, styleValues[i], important);
							
						case NORMAL:
							if (foundFontStyle == true)
							{
								if (foundFontVariant == true)
								{
									setTypedProperty(CSSConstants.FONT_WEIGHT, styleValues[i], important);
								}
								else
								{
									setTypedProperty(CSSConstants.FONT_VARIANT, styleValues[i], important);
								}
							}
							else
							{
								setTypedProperty(CSSConstants.FONT_STYLE, styleValues[i], important);
							}
							
						default:
					}
					
				case INTEGER(value):
					switch(value)
					{
						case 100, 200, 300, 400, 500,
						600, 700, 800, 900:
							setTypedProperty(CSSConstants.FONT_WEIGHT, styleValues[i], important);
							foundFontWeight = true;
					
							
						default:
					}
					
				case LENGTH(value):
					setTypedProperty(CSSConstants.FONT_SIZE, styleValues[i], important);
					
				case PERCENTAGE(value):
					setTypedProperty(CSSConstants.FONT_SIZE, styleValues[i], important);
				
				case FONT_SIZE_LINE_HEIGHT_GROUP(fontSize, lineHeight):
					setTypedProperty(CSSConstants.FONT_SIZE, fontSize, important);
					setTypedProperty(CSSConstants.LINE_HEIGHT, lineHeight, important);
					
				default:
					
			}
		}
	}
	
	/**
	 * Wether the stylevalue is a
	 * valid value for the font shorthand
	 */
	private function isValidFontShorthand(styleValue:CSSPropertyValue):Bool
	{
		switch (styleValue)
		{
			case GROUP(values):
				return isValidFontGroup(values);
				
			//when parsed, if font family has more than one item
			//(like 'arial, times...'), it results in a list where
			//the first item is a group of all the font styles including
			//the first font name for font family, and all the other list
			//items are subsequent font names for font-family
			case CSS_LIST(values):
				switch(values[0])
				{
					case GROUP(groupValues):
						var isValidFontGroup:Bool = isValidFontGroup(groupValues);
						if (isValidFontGroup == true)
						{
							var length:Int = values.length;
							var i:Int = 1;
							while (i < length)
							{
								switch(values[i])
								{
									case STRING(value):
										
									case IDENTIFIER(value):
										
									default:
										return false;
								}
								
								i++;
							}
						}
						else
						{
							return false;
						}
						
					default:
						return false;
				}
				
				
			case INHERIT, INITIAL:
				return true;
				
			default:
				return false;
		}
		
		return false;
	}
	
	/**
	 * Return wether a group of styles are valid
	 * for the font shorthand, excluding inherit and initial
	 * values
	 */
	private function isValidFontGroup(styleValues:Array<CSSPropertyValue>):Bool
	{
		//flag for all font style which can be found,
		//set to true when found or if a style which
		//should always be declared after it is found.
		//if a style is found twice, the shorthand
		//is invalid
		var foundFontStyle:Bool = false;
		var foundFontVariant:Bool = false;
		var foundFontWeight:Bool = false;
		var foundFontSize:Bool = false;
		var foundFontNotation:Bool = false;
		var foundFontFamily:Bool = false;
		
		var length:Int = styleValues.length;
		for (i in 0...length)
		{
			switch(styleValues[i])
			{
				case KEYWORD(value):
					switch(value)
					{
						case ITALIC, OBLIQUE:
							if (foundFontStyle == true)
							{
								return false;
							}
							
							foundFontStyle = true;
							
						case SMALL_CAPS:
							if (foundFontVariant == true)
							{
								return false;
							}
							
							foundFontVariant = true;
							
						case BOLD, BOLDER, LIGHTER:
							if (foundFontWeight == true)
							{
								return false;
							}
							
							foundFontWeight = true;
							
						case XX_SMALL, X_SMALL, SMALL, MEDIUM,
						LARGE, X_LARGE, XX_LARGE, LARGER, SMALLER:
							if (foundFontSize == true)
							{
								return false;
							}
							
							foundFontSize = true;
							foundFontStyle = true;
							foundFontVariant = true;
							
						case NORMAL:
							if (foundFontStyle == true)
							{
								if (foundFontVariant == true)
								{
									if (foundFontWeight == true)
									{
										return false;
									}
									else
									{
										foundFontWeight = true;
									}
								}
								else
								{
									foundFontVariant = true;
								}
							}
							else
							{
								foundFontStyle = true;
							}
							
						default:
							return false;
					}
					
				case INTEGER(value):
					switch(value)
					{
						case 100, 200, 300, 400, 500,
						600, 700, 800, 900:
							if (foundFontWeight == true)
							{
								return false;
							}
							
							foundFontWeight = true;
					
							
						default:
							return false;
					}
					
					
				case STRING(value):
					
					//a font size should always be
					//declared before a font family
					if (foundFontSize == false)
					{
						return false;
					}
					
					foundFontFamily = true;
					foundFontNotation = true;
					foundFontSize = true;
					foundFontStyle = true;
					foundFontVariant = true;
					foundFontWeight = true;
				
				case IDENTIFIER(value):
					
					//a font size should always be
					//declared before a font family
					if (foundFontSize == false)
					{
						return false;
					}
					
					foundFontFamily = true;
					foundFontNotation = true;
					foundFontSize = true;
					foundFontStyle = true;
					foundFontVariant = true;
					foundFontWeight = true;
				
				case LENGTH(value):
					if (foundFontSize == true)
					{
						return false;
					}
					
					foundFontNotation = true;
					foundFontSize = true;
					foundFontStyle = true;
					foundFontVariant = true;
					foundFontWeight = true;
					
				case PERCENTAGE(value):
					if (foundFontSize == true)
					{
						return false;
					}
					
					foundFontNotation = true;
					foundFontSize = true;
					foundFontStyle = true;
					foundFontVariant = true;
					foundFontWeight = true;
				
				case FONT_SIZE_LINE_HEIGHT_GROUP(fontSize, lineHeight):
					if (foundFontNotation == true)
					{
						return false;
					}
					
					foundFontNotation = true;
					foundFontSize = true;
					foundFontStyle = true;
					foundFontVariant = true;
					foundFontWeight = true;
					
				default:
					return false;
					
			}
		}
		
		//font family and font size are both required
		if (foundFontFamily == false || foundFontSize == false)
		{
			return false;
		}
		
		return true;
	}
	
	/**
	 * Return wether a group value for the 
	 * transition shorthand is valid
	 */
	private function isValidTransitionGroup(styleValues:Array<CSSPropertyValue>):Bool
	{
		//those flag keep track of which property was
		//already found in the group, ther can't be duplicates
		var hasTransitionProperty:Bool = false;
		var hasTransitionTimingFunction:Bool = false;
		var hasTransitionDelay:Bool = false;
		var hasTransitionDuration:Bool = false;
		
		//there can only be from 2 to 4 value for a shorthand group
		if (styleValues.length == 2 || styleValues.length == 3 ||
		styleValues.length == 4)
		{
			//check first value validity
			if (isValidTransitionProperty(styleValues[0]))
			{
				hasTransitionProperty = true;
			}
			else if (isValidTransitionDelayOrDuration(styleValues[0]))
			{
				hasTransitionDuration = true;
			}
			else if (isValidTransitionTimingFunction(styleValues[0]))
			{
				hasTransitionTimingFunction = true;
			}
			//here the value is not valid for a transition shorthand
			else
			{
				return false;
			}
			
			//check second value validity
			if (isValidTransitionProperty(styleValues[1]))
			{
				if (hasTransitionProperty == true)
				{
					return false;
				}
			}
			else if (isValidTransitionDelayOrDuration(styleValues[1]))
			{
				//if 2 values in the shorthand are time values,
				//the first one is used for duration and the second one
				//for delay
				if (hasTransitionDuration == true)
				{
					hasTransitionDelay = true;
				}
				else
				{
					hasTransitionDuration = true;
				}
			}
			else if (isValidTransitionTimingFunction(styleValues[1]))
			{
				if (hasTransitionTimingFunction == true)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			
			//if there are only 2 values in the shorthand
			//the shorthand is valid
			if (styleValues.length == 2)
			{
				return true;
			}
			
			//check third value validity
			if (isValidTransitionProperty(styleValues[2]))
			{
				if (hasTransitionProperty == true)
				{
					return false;
				}
			}
			else if (isValidTransitionDelayOrDuration(styleValues[2]))
			{
				if (hasTransitionDuration == true)
				{
					//return false if there was already 2 time values
					if (hasTransitionDelay == true)
					{
						return false;
					}
					else
					{
						hasTransitionDelay = true;
					}
				}
				else
				{
					hasTransitionDuration = true;
				}
			}
			else if (isValidTransitionTimingFunction(styleValues[2]))
			{
				if (hasTransitionTimingFunction == true)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			
			//if there was 3 values, the shorthand
			//is valid
			if (styleValues.length == 3)
			{
				return true;
			}
			
			//check fourth value
			if (isValidTransitionProperty(styleValues[3]))
			{
				if (hasTransitionProperty == true)
				{
					return false;
				}
			}
			else if (isValidTransitionDelayOrDuration(styleValues[3]))
			{
				if (hasTransitionDuration == true)
				{
					//return false if there was already 2 time values
					if (hasTransitionDelay == true)
					{
						return false;
					}
					else
					{
						hasTransitionDelay = true;
					}
				}
				else
				{
					hasTransitionDuration = true;
				}
			}
			else if (isValidTransitionTimingFunction(styleValues[3]))
			{
				if (hasTransitionTimingFunction == true)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			
			return true;
		}
		
		return false;
	}
	
	/**
	 * Return wether a CSS value is valid for a border width style
	 */
	private function isValidBorderWidthValue(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case THIN, MEDIUM, THICK:
						return true;
						
					default:	
				}
				
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
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether a CSS value is valid for a border color style
	 */
	private function isValidBorderColorValue(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case COLOR(value):
				return true;
				
			default:	
		}
		
		return false;		
	}
	
	/**
	 * Return wether a CSS value is valid for a border style style
	 */
	private function isValidBorderStyleValue(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case NONE, HIDDEN, DOTTED, DASHED, SOLID, DOUBLE,
					GROOVE, RIDGE, INSET, OUTSET:
						return true;
						
					default:	
				}
				
			default:	
		}
		
		return false;		
	}
	
	/**
	 * Return wether a CSS value is valid for a outline color style
	 */
	private function isValidOutlineColorValue(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case INVERT:
						return true;
					
					default:
						return isValidBorderColorValue(styleValue);
				}
				
			default:
				return isValidBorderColorValue(styleValue);
		}
	}
	
	/**
	 * Return wether a CSS value is valid for a outline style style
	 */
	private function isValidOutlineStyleValue(styleValue:CSSPropertyValue):Bool
	{
		switch(styleValue)
		{
			case KEYWORD(value):
				switch(value)
				{
					case HIDDEN:
						return false;
						
					default:	
						return isValidBorderStyleValue(styleValue);
				}
				
			default:	
				return isValidBorderStyleValue(styleValue);
		}	
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
	 * Return wether a value is valid for a transform origin style, excluding group value
	 * @param	styleValue
	 */
	private function isValidTransformOrigin(styleValue:CSSPropertyValue, areHorizontalKeywordValueAllowed:Bool, areVerticalKeywordAllowed:Bool):Bool
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
					case CENTER:
						return true;
						
					case LEFT, RIGHT:
						if (areHorizontalKeywordValueAllowed == true)
						{
							return true;
						}
						
					case TOP, BOTTOM:
						if (areVerticalKeywordAllowed ==  true)
						{
							return true;
						}
						
					default:	
				}
				
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
				
			case CH(value):
				return value >= 0; 
				
			case REM(value):
				return value >= 0; 	
				
			case VH(value):
				return value >= 0; 		
				
			case VW(value):
				return value >= 0; 	
				
			case VMIN(value):
				return value >= 0; 	
				
			case VMAX(value):
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
		
		for (i in 0...length)
		{
			var property:TypedPropertyVO = _indexedProperties[_propertiesPositions[i]];
			
			serializedStyleDeclaration += CSSConstants.getPropertyNameFromIndex(property.index) + ":" + CSSStyleSerializer.serialize(property.typedValue);
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
		resetIndexedProperties();
		resetPropertiesPositions();
		length = 0;
		
		//retrieve url of stylsheet owning this style declaration
		var baseUrl:String = null;
		if (parentRule != null)
		{
			if (parentRule.parentStyleSheet != null)
			{
				baseUrl = parentRule.parentStyleSheet.href;
			}
		}
		
		var typedProperties:Array<TypedPropertyVO> = CSSStyleParser.parseStyle(value, baseUrl);
		var length:Int = typedProperties.length;
		for (i in 0...length)
		{
			var typedProperty:TypedPropertyVO = typedProperties[i];
			applyProperty(typedProperty.index, typedProperty.typedValue, typedProperty.important);
		}
		
		return value;
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
	
	private function get_cssFloat():String 
	{
		return getPropertyValue(CSSConstants.FLOAT);
	}
	
	private function set_cssFloat(value:String):String 
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
	
	private function set_font(value:String):String
	{
		setProperty(CSSConstants.FONT, value);
		return value;
	}
	
	private function get_font():String
	{
		return getPropertyValue(CSSConstants.FONT);
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
	
	private function set_background(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND, value);
		return value;
	}
	
	private function get_background():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND);
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
	
	private function set_backgroundAttachment(value:String):String
	{
		setProperty(CSSConstants.BACKGROUND_ATTACHMENT, value);
		return value;
	}
	
	private function get_backgroundAttachment():String
	{
		return getPropertyValue(CSSConstants.BACKGROUND_ATTACHMENT);
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
	
	private function get_borderTopWidth():String
	{
		return getPropertyValue(CSSConstants.BORDER_TOP_WIDTH);
	}
	
	private function set_borderTopWidth(value:String):String
	{
		setProperty(CSSConstants.BORDER_TOP_WIDTH, value);
		return value;
	}
	
	private function get_borderRightWidth():String
	{
		return getPropertyValue(CSSConstants.BORDER_RIGHT_WIDTH);
	}
	
	private function set_borderRightWidth(value:String):String
	{
		setProperty(CSSConstants.BORDER_RIGHT_WIDTH, value);
		return value;
	}
	
	private function get_borderBottomWidth():String
	{
		return getPropertyValue(CSSConstants.BORDER_BOTTOM_WIDTH);
	}
	
	private function set_borderBottomWidth(value:String):String
	{
		setProperty(CSSConstants.BORDER_BOTTOM_WIDTH, value);
		return value;
	}
	
	private function get_borderLeftWidth():String
	{
		return getPropertyValue(CSSConstants.BORDER_LEFT_WIDTH);
	}
	
	private function set_borderLeftWidth(value:String):String
	{
		setProperty(CSSConstants.BORDER_LEFT_WIDTH, value);
		return value;
	}
	
	private function get_borderWidth():String
	{
		return getPropertyValue(CSSConstants.BORDER_WIDTH);
	}
	
	private function set_borderWidth(value:String):String
	{
		setProperty(CSSConstants.BORDER_WIDTH, value);
		return value;
	}
	
	private function get_borderTopColor():String
	{
		return getPropertyValue(CSSConstants.BORDER_TOP_COLOR);
	}
	
	private function set_borderTopColor(value:String):String
	{
		setProperty(CSSConstants.BORDER_TOP_COLOR, value);
		return value;
	}
	
	private function get_borderRightColor():String
	{
		return getPropertyValue(CSSConstants.BORDER_RIGHT_COLOR);
	}
	
	private function set_borderRightColor(value:String):String
	{
		setProperty(CSSConstants.BORDER_RIGHT_COLOR, value);
		return value;
	}
	
	private function get_borderBottomColor():String
	{
		return getPropertyValue(CSSConstants.BORDER_BOTTOM_COLOR);
	}
	
	private function set_borderBottomColor(value:String):String
	{
		setProperty(CSSConstants.BORDER_BOTTOM_COLOR, value);
		return value;
	}
		
	private function get_borderLeftColor():String
	{
		return getPropertyValue(CSSConstants.BORDER_LEFT_COLOR);
	}
	
	private function set_borderLeftColor(value:String):String
	{
		setProperty(CSSConstants.BORDER_LEFT_COLOR, value);
		return value;
	}
	
	private function get_borderColor():String
	{
		return getPropertyValue(CSSConstants.BORDER_COLOR);
	}
	
	private function set_borderColor(value:String):String
	{
		setProperty(CSSConstants.BORDER_COLOR, value);
		return value;
	}
	
	private function get_borderTopStyle():String
	{
		return getPropertyValue(CSSConstants.BORDER_TOP_STYLE);
	}
	
	private function set_borderTopStyle(value:String):String
	{
		setProperty(CSSConstants.BORDER_TOP_STYLE, value);
		return value;
	}
	
	private function get_borderRightStyle():String
	{
		return getPropertyValue(CSSConstants.BORDER_RIGHT_STYLE);
	}
	
	private function set_borderRightStyle(value:String):String
	{
		setProperty(CSSConstants.BORDER_RIGHT_STYLE, value);
		return value;
	}
	
	private function get_borderBottomStyle():String
	{
		return getPropertyValue(CSSConstants.BORDER_BOTTOM_STYLE);
	}
	
	private function set_borderBottomStyle(value:String):String
	{
		setProperty(CSSConstants.BORDER_BOTTOM_STYLE, value);
		return value;
	}
		
	private function get_borderLeftStyle():String
	{
		return getPropertyValue(CSSConstants.BORDER_LEFT_STYLE);
	}
	
	private function set_borderLeftStyle(value:String):String
	{
		setProperty(CSSConstants.BORDER_LEFT_STYLE, value);
		return value;
	}
	
	private function get_borderStyle():String
	{
		return getPropertyValue(CSSConstants.BORDER_STYLE);
	}
	
	private function set_borderStyle(value:String):String
	{
		setProperty(CSSConstants.BORDER_STYLE, value);
		return value;
	}
	
	private function get_borderTop():String
	{
		return getPropertyValue(CSSConstants.BORDER_TOP);
	}
	
	private function set_borderTop(value:String):String
	{
		setProperty(CSSConstants.BORDER_TOP, value);
		return value;
	}
	
	private function get_borderRight():String
	{
		return getPropertyValue(CSSConstants.BORDER_RIGHT);
	}
	
	private function set_borderRight(value:String):String
	{
		setProperty(CSSConstants.BORDER_RIGHT, value);
		return value;
	}
	
	private function get_borderBottom():String
	{
		return getPropertyValue(CSSConstants.BORDER_BOTTOM);
	}
	
	private function set_borderBottom(value:String):String
	{
		setProperty(CSSConstants.BORDER_BOTTOM, value);
		return value;
	}
		
	private function get_borderLeft():String
	{
		return getPropertyValue(CSSConstants.BORDER_LEFT);
	}
	
	private function set_borderLeft(value:String):String
	{
		setProperty(CSSConstants.BORDER_LEFT, value);
		return value;
	}
	
	private function get_border():String
	{
		return getPropertyValue(CSSConstants.BORDER);
	}
	
	private function set_border(value:String):String
	{
		setProperty(CSSConstants.BORDER, value);
		return value;
	}
	
	private function get_outline():String
	{
		return getPropertyValue(CSSConstants.OUTLINE);
	}
	
	private function set_outline(value:String):String
	{
		setProperty(CSSConstants.OUTLINE, value);
		return value;
	}
		
	private function get_outlineWidth():String
	{
		return getPropertyValue(CSSConstants.OUTLINE_WIDTH);
	}
	
	private function set_outlineWidth(value:String):String
	{
		setProperty(CSSConstants.OUTLINE_WIDTH, value);
		return value;
	}

	private function get_outlineColor():String
	{
		return getPropertyValue(CSSConstants.OUTLINE_COLOR);
	}
	
	private function set_outlineColor(value:String):String
	{
		setProperty(CSSConstants.OUTLINE_COLOR, value);
		return value;
	}
	
	private function get_outlineStyle():String
	{
		return getPropertyValue(CSSConstants.OUTLINE_STYLE);
	}
	
	private function set_outlineStyle(value:String):String
	{
		setProperty(CSSConstants.OUTLINE_STYLE, value);
		return value;
	}
	
	private function get_textDecoration():String
	{
		return getPropertyValue(CSSConstants.TEXT_DECORATION);
	}
	
	private function set_textDecoration(value:String):String
	{
		setProperty(CSSConstants.TEXT_DECORATION, value);
		return value;
	}
	
}