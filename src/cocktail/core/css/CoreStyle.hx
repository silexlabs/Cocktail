/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
import cocktail.core.event.TransitionEvent;
import cocktail.core.font.FontData;
import cocktail.core.font.FontManager;
import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.InvalidatingElementRenderer;
import cocktail.core.css.CSSConstants;
import cocktail.core.animation.Animator;
import cocktail.core.animation.Transition;
import cocktail.core.animation.TransitionManager;
import cocktail.core.unit.UnitManager;
import cocktail.core.renderer.RendererData;

/**
 * This class has 3 main purposes :
 *
 * It is in charge of the cascade, that is
 * for each supported style it selects the right
 * value for its HTMLElement based on the priority
 * of the style declaration.For instance, a style
 * declared inline on an HTMLElement has a higher
 * priority than a style declared in a style sheet.
 * 
 * For a given style, once its specified value has been
 * determined through cascading, derive a computed 
 * value from it which is the value used for inheritance
 * 
 * This class is also in charge of starting
 * transition/animation when the computed value
 * of an animatable property changes
 * 
 * @author Yannick DOMINGUEZ
 */

class CoreStyle
{	
	/**
	 * display styles
	 */
	public var display(get_display, null):CSSPropertyValue;
	public var position(get_position, null):CSSPropertyValue;
	public var cssFloat(get_cssFloat, null):CSSPropertyValue;
	public var clear(get_clear, null):CSSPropertyValue;
	public var zIndex(get_zIndex, null):CSSPropertyValue;
	
	/**
	 * box model styles
	 */
	public var marginLeft(get_marginLeft, null):CSSPropertyValue;
	public var marginRight(get_marginRight, null):CSSPropertyValue;
	public var marginTop(get_marginTop, null):CSSPropertyValue;
	public var marginBottom(get_marginTop, null):CSSPropertyValue;
	
	public var paddingLeft(get_paddingLeft, null):CSSPropertyValue;
	public var paddingRight(get_paddingRight, null):CSSPropertyValue;
	public var paddingTop(get_paddingTop, null):CSSPropertyValue;
	public var paddingBottom(get_paddingBottom, null):CSSPropertyValue;

	public var width(get_width, null):CSSPropertyValue;
	public var height(get_height, null):CSSPropertyValue;
	
	public var minHeight(get_minHeight, null):CSSPropertyValue;
	public var maxHeight(get_maxHeight, null):CSSPropertyValue;
	public var minWidth(get_minWidth, null):CSSPropertyValue;
	public var maxWidth(get_maxWidth, null):CSSPropertyValue;

	public var top(get_top, null):CSSPropertyValue;
	public var left(get_left, null):CSSPropertyValue;
	public var bottom(get_bottom, null):CSSPropertyValue;
	public var right(get_right, null):CSSPropertyValue;
	
	/**
	 * background styles
	 */
	public var backgroundColor(get_backgroundColor, null):CSSPropertyValue;
	public var backgroundImage(get_backgroundImage, null):CSSPropertyValue;
	public var backgroundRepeat(get_backgroundRepeat, null):CSSPropertyValue;
	public var backgroundOrigin(get_backgroundOrigin, null):CSSPropertyValue;
	public var backgroundSize(get_backgroundSize, null):CSSPropertyValue;
	public var backgroundPosition(get_backgroundPosition, null):CSSPropertyValue;
	public var backgroundClip(get_backgroundClip, null):CSSPropertyValue;
	
	/**
	 * font styles
	 */
	public var fontSize(get_fontSize, null):CSSPropertyValue;
	public var fontWeight(get_fontWeight, null):CSSPropertyValue;
	public var fontStyle(get_fontStyle, null):CSSPropertyValue;
	public var fontFamily(get_fontFamily, null):CSSPropertyValue;
	public var fontVariant(get_fontVariant,null):CSSPropertyValue;
	public var color(get_color, null):CSSPropertyValue;
	
	/**
	 * text styles
	 */
	public var lineHeight(get_lineHeight, null):CSSPropertyValue;
	public var textTransform(get_textTransform, null):CSSPropertyValue;
	public var letterSpacing(get_letterSpacing, null):CSSPropertyValue;
	public var wordSpacing(get_wordSpacing, null):CSSPropertyValue;
	public var whiteSpace(get_whiteSpace, null):CSSPropertyValue;
	public var textAlign(get_textAlign, null):CSSPropertyValue;
	public var textIndent(get_textIndent, null):CSSPropertyValue;
	public var verticalAlign(get_verticalAlign, null):CSSPropertyValue;
	
	/**
	 * visual effect styles
	 */
	public var opacity(get_opacity, null):CSSPropertyValue;
	public var visibility(get_visibility, null):CSSPropertyValue;
	public var overflowX(get_overflowX, null):CSSPropertyValue;
	public var overflowY(get_overflowY, null):CSSPropertyValue;
	public var transformOrigin(get_transformOrigin, null):CSSPropertyValue;
	public var transform(get_transform, null):CSSPropertyValue;
	
	/**
	 * user interface styles
	 */
	public var cursor(get_cursor, null):CSSPropertyValue;
	
	/**
	 * transition styles
	 */
	public var transitionProperty(get_transitionProperty, null):CSSPropertyValue;
	public var transitionDuration(get_transitionDuration, null):CSSPropertyValue;
	public var transitionDelay(get_transitionDelay, null):CSSPropertyValue;
	public var transitionTimingFunction(get_transitionTimingFunction, null):CSSPropertyValue;
	
	/**
	 * Contains the specified values for the HTMLElement which for
	 * each style can come from a style sheet, an inline
	 * style declaration or inherited through the parent
	 */
	public var specifiedValues:CSSStyleDeclaration;
	
	/**
	 * Contains the computed values for the HTMLElement.
	 * There is a computed value for each specified style.
	 * This is the value used for inheritance. Each style
	 * computes diffferently. For instance if for a given
	 * the specified value is a Length (for instance '10px')
	 * , the computed value will be an absolute length in pixel
	 * (for instance 10)
	 * 
	 * Specified values can always be converted to 
	 * computed values during cascade
	 */
	public var computedValues:CSSStyleDeclaration;
	
	/**
	 * This structures holds values of style actually
	 * used during layout. Not all styles used values
	 * can be determined during cascade. For instance
	 * a 'width' defined as '100%' must wait layout
	 * to determine its used value. This structure
	 * will hold the actual used value of 'width'
	 * during layout
	 */
	public var usedValues:UsedValuesData;
	
	/**
	 * An instance of the class
	 * managing this HTMLElement transitions
	 */
	private var _animator:Animator;
	
	/**
	 * A reference to the TransitionManager singleton
	 */
	private var _transitionManager:TransitionManager;
	
	/**
	 * Returns font metrics for the current style values.
	 * Font metrics depends on the computed values of
	 * the 'font-size' and 'font-family' properties
	 * 
	 */
	public var fontMetrics(get_fontMetricsData, null):FontMetricsData;
	
	/**
	 * An instance of fontmanager used to get the font metrics
	 */
	private var _fontManager:FontManager;
	
	/**
	 * The owning HTMLElement
	 */
	public var htmlElement:HTMLElement;
	
	/**
	 * Class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		this.htmlElement = htmlElement;
		
		computedValues = new CSSStyleDeclaration();
		specifiedValues = new CSSStyleDeclaration();
		
		_fontManager = FontManager.getInstance();
		
		_animator = new Animator();
		_animator.onTransitionCompleteCallback = onTransitionComplete;
		_animator.onTransitionUpdateCallback = onTransitionUpdate;
		
		_transitionManager = TransitionManager.getInstance();
		
		initUsedValues();
	}
	
	/**
	 * The used values are given a default
	 * value
	 */
	private function initUsedValues():Void
	{
		usedValues = {
			minHeight : 0.0,
			maxHeight : 0.0,
			minWidth : 0.0,
			maxWidth : 0.0,
			width : 0.0,
			height : 0.0,
			marginLeft : 0.0,
			marginRight : 0.0,
			marginTop : 0.0,
			marginBottom : 0.0,
			paddingLeft : 0.0,
			paddingRight : 0.0,
			paddingTop : 0.0,
			paddingBottom : 0.0,
			left: 0.0,
			right: 0.0,
			top: 0.0,
			bottom : 0.0,
			textIndent:0,
			lineHeight:0.0,
			letterSpacing:0.0,
			color:{color:0, alpha:1.0},
			transformOrigin: { x:0.0, y:0.0 },
			transform:new Matrix(),
			backgroundColor:{color:0, alpha:1.0}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The main cascading function. For each supported CSS style,
	 * get the right specified style for the CoreStyle's HTMLElement.
	 * The specified style for each property can come for multiple 
	 * source, this method manages the priority among those sources
	 * 
	 * @param	initialStyleDeclaration contains the initial value for each of the supported CSS styles.
	 * Used last if a value for a given style is not provided from other sources
	 * @param	styleSheetDeclaration	contains all the style values applying to the HTMLElement which
	 * comes from the CSS style sheet defined in the document or linked
	 * @param	inlineStyleDeclaration contains all the styles defined inline on the HTMLElement, using
	 * its "style" HTML attribute
	 * @param	parentStyleDeclaration contains the definition of all of the computed styles from the direct
	 * parent of the HTMLElement, used for inherithance
	 * @param	parentFontSize parent node's computed font size
	 * @param	parentXHeight parent node's computed x height
	 * @return an array containing the names of all the properties whose specified values changed during cascading
	 */
	public function cascade(properties:Hash<Void>, initialStyleDeclaration:InitialStyleDeclaration, styleSheetDeclaration:CSSStyleDeclaration, inlineStyleDeclaration:CSSStyleDeclaration, parentStyleDeclaration:CSSStyleDeclaration, parentFontSize:Float, parentXHeight:Float, programmaticChange:Bool):Hash<Void>
	{
		//TODO 2 : should do the same for "color" which influence style with a currentColor value
		if (properties.exists(CSSConstants.FONT_SIZE) == true || properties.exists(CSSConstants.FONT_FAMILY) == true)
		{
			//when all the properties are cascaded, font size
			//and font family must be cascaded first, as their
			//computed values is used to computed some length.
			//For instance if 'width' is defined as '2em', for
			//the computed absolute length be correct, font-size
			//and font-family must have been previously computed
			//so that the right font metrics is used for the computation
			cascadeProperty(CSSConstants.FONT_SIZE, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentFontSize, parentXHeight, 0, 0, programmaticChange);
			cascadeProperty(CSSConstants.FONT_FAMILY, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentFontSize, parentXHeight, 0, 0, programmaticChange);
			
			properties.remove(CSSConstants.FONT_SIZE);
			properties.remove(CSSConstants.FONT_FAMILY);
			
			var lengthCSSProperties:Array<String> = initialStyleDeclaration.lengthCSSProperties;
			
			//if font-size or font-family changed, all the properties which may depends
			//on font metrics (because they are for instance Length with 'em' unit) need to be cascaded
			var length:Int = lengthCSSProperties.length;
			for (i in 0...length)
			{
				properties.set(lengthCSSProperties[i], null);
			}
		}
				
		//will return the name of all the properties whose
		//specified values changed during cascading 
		var changedProperties:Hash<Void> = new Hash<Void>();

		//get the font metrics of this CoreStyle, used for
		//Length computation
		var fontMetrics:FontMetricsData = this.fontMetrics;
		var fontSize:Float = fontMetrics.fontSize;
		var xHeight:Float = fontMetrics.xHeight;
		
		for (propertyName in properties.keys())
		{
			//cascade the property, returns a flag of wether the cascade changed
			//the specified value of the property. Useful to know if children
			//also need to cascade this property
			var didChangeSpecifiedValue:Bool = cascadeProperty(propertyName, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange);
		
			if (didChangeSpecifiedValue == true)
			{
				changedProperties.set(propertyName, null);
			}
		}
		
		//apply special computing relationship between
		//disply, float and position property
		applyPositionFloatAndDisplayRelationship();
		
		return changedProperties;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually cascade a property
	 */
	private function cascadeProperty(propertyName:String, initialStyleDeclaration:CSSStyleDeclaration, styleSheetDeclaration:CSSStyleDeclaration, inlineStyleDeclaration:CSSStyleDeclaration, parentStyleDeclaration:CSSStyleDeclaration, parentFontSize:Float, parentXHeight:Float, fontSize:Float, xHeight:Float, programmaticChange:Bool):Bool
	{
		//first check if this property is defined inline which always has the
		//highest priority
		if (inlineStyleDeclaration.hasProperty(propertyName) == true)
		{
			return setProperty(propertyName, inlineStyleDeclaration, parentStyleDeclaration, initialStyleDeclaration, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange);
		}
		//else check if a value for this style for this HTMLElement was defined in the document's style sheet
		else if (styleSheetDeclaration.hasProperty(propertyName) == true)
		{
			return setProperty(propertyName, styleSheetDeclaration, parentStyleDeclaration, initialStyleDeclaration, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange);
		}
		//else if the property is inherithed (for instance 'font-family'),
		//use the value from the parent
		else if (isInherited(propertyName) == true)
		{
			return setProperty(propertyName, parentStyleDeclaration, parentStyleDeclaration, initialStyleDeclaration, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange);
		}
		//else at last use the initial value of the property
		else
		{
			return setProperty(propertyName, initialStyleDeclaration, parentStyleDeclaration, initialStyleDeclaration, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange);
		}
	}
	
	/**
	 * cascade a property by updating its specified value
	 * and computing its value if necessary
	 */
	private function setProperty(propertyName:String, styleDeclaration:CSSStyleDeclaration, parentStyleDeclaration:CSSStyleDeclaration, initialStyleDeclaration:CSSStyleDeclaration, parentFontSize:Float, parentXHeight:Float, fontSize:Float, xHeight:Float, programmaticChange:Bool):Bool
	{
		var propertyData:TypedPropertyData = styleDeclaration.getTypedProperty(propertyName);
		var property:CSSPropertyValue = propertyData.typedValue;
		
		var specifiedProperty:TypedPropertyData = specifiedValues.getTypedProperty(propertyName);
		
		var isNotInitial:Bool = specifiedProperty != null;
		
		if (specifiedProperty != null)
		{
			if (Type.enumEq(property, specifiedProperty.typedValue) == true)
			{
				return false;
			}
		}
		
		specifiedValues.setTypedProperty(propertyName, property, propertyData.important);
		
		var computedProperty:CSSPropertyValue = null;
		
		switch(property)
		{
			case INHERIT:
				computedProperty = parentStyleDeclaration.getTypedProperty(propertyName).typedValue;
				
			case INITIAL:
				computedProperty = initialStyleDeclaration.getTypedProperty(propertyName).typedValue;
				
			default:
				switch(propertyName)
				{
					default:	
						computedProperty = getComputedProperty(propertyName, property, parentFontSize, parentXHeight, fontSize, xHeight);
				}
		}
		
		//TODO 1 : try to start transition here, if value was herited, no transition must start. Same
		//if it was specified declaratively
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(propertyName);
		
		if (programmaticChange == true)
		{
			if (computedValues.getTypedProperty(propertyName) != null)
			{
				if (isAnimatable(propertyName))
				{
					_animator.registerPendingAnimation(propertyName, invalidationReason, Reflect.getProperty(usedValues, getIDLName(propertyName)));
				}
			}
		}
		
		computedValues.setTypedProperty(propertyName, computedProperty, propertyData.important);
		
		htmlElement.invalidate(invalidationReason);
		
		return true;
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STYLES COMPUTING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a given specified property value, 
	 * return its computed value, which is
	 * the value which will be used for 
	 * inheritance.
	 * 
	 * For instance, when a value is defined
	 * as a Length (like '10px'), it will
	 * always be computed into an absolute
	 * length ('10px' becomes '10')
	 * 
	 * If a property is not present in this method
	 * or one of its value does'nt appear, it means
	 * that the computed value is the same as the
	 * specified value and so it doesn't need any
	 * further treatement
	 */
	private function getComputedProperty(propertyName:String, property:CSSPropertyValue, parentFontSize:Float, parentXHeight:Float, fontSize:Float, xHeight:Float):CSSPropertyValue
	{
		switch(propertyName)
		{
			case CSSConstants.MIN_WIDTH, CSSConstants.MIN_HEIGHT, CSSConstants.MAX_HEIGHT, CSSConstants.MAX_WIDTH,
			CSSConstants.LEFT, CSSConstants.RIGHT, CSSConstants.TOP, CSSConstants.BOTTOM,
			CSSConstants.PADDING_LEFT, CSSConstants.PADDING_RIGHT, CSSConstants.PADDING_TOP, CSSConstants.PADDING_BOTTOM,
			CSSConstants.MARGIN_TOP, CSSConstants.MARGIN_LEFT, CSSConstants.MARGIN_BOTTOM, CSSConstants.MARGIN_RIGHT,
			CSSConstants.WIDTH, CSSConstants.HEIGHT:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
						
					case INTEGER(value):
						return ABSOLUTE_LENGTH(value);
						
					default:	
				}
				
			case CSSConstants.OPACITY:
				switch(property)
				{
					case NUMBER(value):
						if (value > 1)
						{
							return NUMBER(1);
						}
						if (value < 0)
						{
							return NUMBER(0);
						}
						
					case INTEGER(value):
						if (value < 0)
						{
							return NUMBER(0);
						}
						if (value > 1)
						{
							return NUMBER(1);
						}
						return NUMBER(value);
						
					default:	
				}
				
			case CSSConstants.FONT_SIZE:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, parentFontSize, parentXHeight));
						
					case PERCENTAGE(value):	
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromPercent(value, parentFontSize));
						
					case KEYWORD(value):
						switch(value)
						{
							case XX_SMALL, X_SMALL, SMALL, MEDIUM, LARGE, X_LARGE, XX_LARGE:
								return ABSOLUTE_LENGTH(UnitManager.getFontSizeFromAbsoluteSizeValue(value));
								
							case LARGER, SMALLER:
								return ABSOLUTE_LENGTH(UnitManager.getFontSizeFromRelativeSizeValue(value, parentFontSize));
								
							default:	
						}
						
					default:	
				}	
				
			case CSSConstants.TRANSFORM:
				switch(property)
				{
					//TODO : manage transform function to turn values
					//into absolutes length
					case KEYWORD(value):
						//computedValues.transform = property;
						
					default:	
				}
				
			case CSSConstants.FONT_WEIGHT:
				switch(property)
				{
					//TODO : manage bolder and lighter with parent font-weight
					case KEYWORD(value):
						
						
					default:	
				}
				
			case CSSConstants.VERTICAL_ALIGN:
				switch(property)
				{
					case INTEGER(value):
						return ABSOLUTE_LENGTH(0);
						
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
						
					default:	
				}	
				
			case CSSConstants.CURSOR:
				switch(property)
				{
					//TODO 1: should compute into absolute url
					case URL(value):
						
						
					default:	
				}	
				
			case CSSConstants.LINE_HEIGHT:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
						
					case PERCENTAGE(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromPercent(value, fontSize));
						
					default:	
				}
				
			case CSSConstants.TEXT_INDENT:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
	
					case INTEGER(value):
						return ABSOLUTE_LENGTH(value);
						
					default:	
				}
				
			case CSSConstants.LETTER_SPACING:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
						
					default:	
				}
				
			case CSSConstants.WORD_SPACING:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
						
					case KEYWORD(value):
						return ABSOLUTE_LENGTH(0);
						
					default:	
				}	
				
			case CSSConstants.COLOR:
				switch(property)
				{
					case COLOR(value):
						//TODO : currentColor should be parent color
						return COLOR(UnitManager.getComputedCSSColorFromCSSColor(value, value));
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_COLOR:
				switch(property)
				{
					case COLOR(value):
						return COLOR(UnitManager.getComputedCSSColorFromCSSColor(value, value));
						
					default:	
				}	
			
			//TODO : add support for list of item	
			case CSSConstants.BACKGROUND_IMAGE:
				switch(property)
				{
					case KEYWORD(value):
						//computedValues.backgroundImage = property;
						
					case URL(value):
						//computedValues.backgroundImage = property;
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_POSITION:
				switch(property)
				{
					case KEYWORD(value):
						return GROUP([KEYWORD(value), KEYWORD(CENTER)]);
					
					case LENGTH(value):
						return GROUP([ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight)), KEYWORD(CENTER)]);
						
					case PERCENTAGE(value):
						return GROUP([PERCENTAGE(value), KEYWORD(CENTER)]);
						
					case GROUP(value):
						var backgroundPositionX:CSSPropertyValue = null;
						var backgroundPostionY:CSSPropertyValue = null;
						switch(value[0])
						{
							case LENGTH(value):
								backgroundPositionX = ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundPositionX = value[0];
						}
						
						switch(value[1])
						{
							case LENGTH(value):
								backgroundPostionY = ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundPostionY = value[1];
						}
						
						return GROUP([backgroundPositionX, backgroundPostionY]);
					
					default:	
				}
				
			case CSSConstants.BACKGROUND_REPEAT:
				switch(property)
				{
					case KEYWORD(value):
						switch(value)
						{
							case REPEAT:
								return GROUP([KEYWORD(REPEAT), KEYWORD(REPEAT)]);
								
							case NO_REPEAT:
								return  GROUP([KEYWORD(NO_REPEAT), KEYWORD(NO_REPEAT)]);
								
							case ROUND:
								return GROUP([KEYWORD(ROUND), KEYWORD(ROUND)]);	
								
							case SPACE:
								return GROUP([KEYWORD(SPACE), KEYWORD(SPACE)]);		
								
							case REPEAT_X:
								return GROUP([KEYWORD(REPEAT), KEYWORD(NO_REPEAT)]);		
								
							case REPEAT_Y:
								return GROUP([KEYWORD(NO_REPEAT), KEYWORD(REPEAT)]);			
								
							default:					
						}
						
					//TODO	
					case GROUP(value):
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_SIZE:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
						
					//TODO	
					case GROUP(value):
						var backgroundSizeX:CSSPropertyValue = null;
						var backgroundSizeY:CSSPropertyValue = null;
						
						switch(value[0])
						{
							case LENGTH(value):
								backgroundSizeX = ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundSizeX = value[0];
						}
						
						switch(value[1])
						{
							case LENGTH(value):
								backgroundSizeY = ABSOLUTE_LENGTH(UnitManager.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundSizeY = value[1];
						}
						
						return GROUP([backgroundSizeX, backgroundSizeY]);
						
					default:	
				}	
		}
		
		return property;
	}
	
	/**
	 * Special computing relationship exists between position, 
	 * float and display. For instance if position is absolute,
	 * a dispaly value of 'inline' will compute to 'block' as
	 * absolutely positioned element should always be displayed
	 * as blocks
	 */
	private function applyPositionFloatAndDisplayRelationship():Void
	{
		switch(getKeyword(position))
		{
			case ABSOLUTE, FIXED:
				switch(getKeyword(display))
				{
					//if position is absolute, inline display
					//must become block
					case INLINE, INLINE_BLOCK:
						computedValues.setTypedProperty(CSSConstants.DISPLAY, KEYWORD(BLOCK), false);
					
					default:	
				}
				
				switch(getKeyword(cssFloat))
				{
					//if position is absolute, the element
					//can't be floated
					case LEFT, RIGHT:
						computedValues.setTypedProperty(CSSConstants.FLOAT, KEYWORD(NONE), false);
						
					default:	
				}
				
			default:	
				
				//check if the element is floated
				switch(getKeyword(cssFloat))
				{
					case LEFT, RIGHT:
						switch (getKeyword(display))
						{
							//if the element is floated, it must be a block
							case INLINE, INLINE_BLOCK:
							computedValues.setTypedProperty(CSSConstants.DISPLAY, KEYWORD(BLOCK), false);
							
							default:
						}
						
					default:	
				}
				
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Start pending animations on the animator
	 */
	public function startPendingAnimations():Bool
	{
		return _animator.startPendingAnimations(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a transition is complete, invalidate the HTMLElement,
	 * then dispatch a transition end event
	 */
	private function onTransitionComplete(transition:Transition):Void
	{
		htmlElement.invalidate(transition.invalidationReason);
		var transitionEvent:TransitionEvent = new TransitionEvent();
		transitionEvent.initTransitionEvent(TransitionEvent.TRANSITION_END, true, true, transition.propertyName, transition.transitionDuration, "");
		htmlElement.dispatchEvent(transitionEvent);
	}
	
	/**
	 * When a transition is updated, invalidate the HTMLElement
	 * to schedule a repaint and relayout of the rendering tree
	 */
	private function onTransitionUpdate(transition:Transition):Void
	{
		htmlElement.invalidate(transition.invalidationReason);
	}
	
	/**
	 * Utils method to return the value of a property which can be transitioned
	 * If the property is currently being transitioned, return the current value
	 * of the transition, else return the computed value of the property
	 * @param	propertyName the name of the property whose value is returned
	 * @param	propertyValue the computed value of the property, returned if
	 * the property is not transitioning
	 */
	private function getTransitionablePropertyValue(propertyName:String, propertyValue:CSSPropertyValue):CSSPropertyValue
	{
		//try to get a transition for the property
		var transition:Transition = _transitionManager.getTransition(propertyName, this);
		//if there actually is a transition in progress for this property,
		//return its current value
		if (transition != null)
		{
			return ABSOLUTE_LENGTH(transition.currentValue);
		}
		else
		{
			return propertyValue;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	 
	/**
	 * Return the IDL name of the property, i.e
	 * the name used for scripting. For instance,
	 * min-width will become camel-case minWidth
	 * 
	 * TODO 1 : complete
	 */
	private function getIDLName(propertyName:String):String
	{
		switch(propertyName)
		{
			default:
				return propertyName;
		}
	}
	
	/**
	 * Return wether a given CSS property can
	 * be animated/transitioned
	 * 
	 * TODO 1 : complete
	 */
	private function isAnimatable(propertyName:String):Bool
	{
		switch(propertyName)
		{
			case CSSConstants.WIDTH, CSSConstants.HEIGHT, CSSConstants.TOP, CSSConstants.BOTTOM:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * Return wether a given CSS property is inherithed,
	 * meaning the an HTMLElement inherits its property
	 * from its value from its parent node if the 
	 * property has no explicit value defined for it.
	 * 
	 * For instance 'font-family' is inherited, if it is
	 * set on the root HTML element, its values will be
	 * used by each node in the document unless another
	 * value is explicitely used
	 */
	private function isInherited(propertyName:String):Bool
	{
		switch(propertyName)
		{
			case CSSConstants.COLOR, CSSConstants.CURSOR, CSSConstants.FONT_FAMILY,
			CSSConstants.FONT_SIZE, CSSConstants.FONT_STYLE, CSSConstants.FONT_VARIANT,
			CSSConstants.FONT_WEIGHT, CSSConstants.LETTER_SPACING, CSSConstants.LINE_HEIGHT,
			CSSConstants.TEXT_ALIGN, CSSConstants.TEXT_INDENT, CSSConstants.TEXT_TRANSFORM,
			CSSConstants.VISIBILITY, CSSConstants.WHITE_SPACE, CSSConstants.WORD_SPACING:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * Return the keyword from a CSS property,
	 * or throw an exception if it doesn't wrap a
	 * keyword
	 */
	public function getKeyword(value:CSSPropertyValue):CSSKeywordValue
	{	
		switch(value)
		{
			case KEYWORD(value):
				return value;
				
			default:
				throw 'not a keyword value';
		}
	}
	
	/**
	 * Same as above for number
	 */
	public function getNumber(value:CSSPropertyValue):Float
	{
		switch(value)
		{
			case NUMBER(value):
				return value;
				
			default:
				throw'not a number value';
		}
	}
	
	/**
	 * Same as above for list
	 */
	public function getList(value:CSSPropertyValue):Array<CSSPropertyValue>
	{
		switch (value)
		{
			case CSS_LIST(value):
				return value;
				
			default:
				throw'not a list value';
		}
	}
	
	/**
	 * Same as above for absolute length
	 */
	public function getAbsoluteLength(value:CSSPropertyValue):Float
	{
		switch (value)
		{
			case ABSOLUTE_LENGTH(value):
				return value;
				
			default:
				throw'not an absolute length value';
		}
	}
	
	/**
	 * Same as above for color
	 */
	public function getColor(value:CSSPropertyValue):CSSColorValue
	{
		switch(value)
		{
			case COLOR(value):
				return value;
				
			default:
				throw'not a color value';
		}
	}
	
	/**
	 * Utils method returning wether a given
	 * style's value is the CSS 'auto'
	 * keyword
	 */
	public function isAuto(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case KEYWORD(value):
				switch(value)
				{
					case AUTO:
						return true;
						
					default:
						return false;
				}
				
			default:
				return false;
		}
	}
	
	/**
	 * Same as above for the 'none' CSS keyword
	 */
	public function isNone(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case KEYWORD(value):
				switch(value)
				{
					case NONE:
						return true;
						
					default:
						return false;
				}
				
			default:
				return false;
		}
	}
	
	/////////////////////////////////
	// GETTERS
	////////////////////////////////
	
	private function get_fontMetricsData():FontMetricsData
	{
		//TODO 1 : how to deal with font size for macro target ? Does it matter
		//to get layout info at compile/server time ? use em font ?
		#if macro
		return { fontSize:12.0, ascent:12.0, descent:12.0, xHeight:12.0, subscriptOffset:3.0, superscriptOffset:3.0, underlineOffset:3.0, spaceWidth:5.0 };
		#else
		return _fontManager.getFontMetrics(UnitManager.getCSSFontFamily(fontFamily), getAbsoluteLength(fontSize));
		#end
	}
	
	/////////////////////////////////
	// STYLE GETTERS
	// For each, return the
	// computed value of the style
	////////////////////////////////
	
	private function get_opacity():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.OPACITY, computedValues.getTypedProperty(CSSConstants.OPACITY).typedValue);
	}
	
	private function get_marginLeft():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_LEFT, computedValues.getTypedProperty(CSSConstants.MARGIN_LEFT).typedValue);
	}
	
	private function get_marginRight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_RIGHT, computedValues.getTypedProperty(CSSConstants.MARGIN_RIGHT).typedValue);
	}
	
	private function get_marginTop():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_TOP, computedValues.getTypedProperty(CSSConstants.MARGIN_TOP).typedValue);
	}
	
	private function get_marginBottom():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_BOTTOM, computedValues.getTypedProperty(CSSConstants.MARGIN_BOTTOM).typedValue);
	}
	
	private function get_paddingLeft():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_LEFT, computedValues.getTypedProperty(CSSConstants.PADDING_LEFT).typedValue);
	}
	
	private function get_paddingRight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_RIGHT, computedValues.getTypedProperty(CSSConstants.PADDING_RIGHT).typedValue);
	}
	
	private function get_paddingTop():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_TOP, computedValues.getTypedProperty(CSSConstants.PADDING_TOP).typedValue);
	}
	
	private function get_paddingBottom():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_BOTTOM, computedValues.getTypedProperty(CSSConstants.PADDING_BOTTOM).typedValue);
	}
	
	private function get_width():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.WIDTH, computedValues.getTypedProperty(CSSConstants.WIDTH).typedValue);
	}
	
	private function get_height():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.HEIGHT, computedValues.getTypedProperty(CSSConstants.HEIGHT).typedValue);
	}
	
	private function get_minHeight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MIN_HEIGHT, computedValues.getTypedProperty(CSSConstants.MIN_HEIGHT).typedValue);
	}
	
	private function get_maxHeight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MAX_HEIGHT, computedValues.getTypedProperty(CSSConstants.MAX_HEIGHT).typedValue);
	}
	
	private function get_minWidth():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MIN_WIDTH, computedValues.getTypedProperty(CSSConstants.MIN_WIDTH).typedValue);
	}
	
	private function get_maxWidth():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MAX_WIDTH, computedValues.getTypedProperty(CSSConstants.MAX_WIDTH).typedValue);
	}
	
	private function get_top():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.TOP, computedValues.getTypedProperty(CSSConstants.TOP).typedValue);
	}
	
	private function get_left():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.LEFT, computedValues.getTypedProperty(CSSConstants.LEFT).typedValue);
	}
	
	private function get_bottom():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.BOTTOM, computedValues.getTypedProperty(CSSConstants.BOTTOM).typedValue);
	}
	
	private function get_right():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.RIGHT, computedValues.getTypedProperty(CSSConstants.RIGHT).typedValue);
	}
	
	private function get_fontSize():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.FONT_SIZE, computedValues.getTypedProperty(CSSConstants.FONT_SIZE).typedValue);
	}
	
	private function get_display():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.DISPLAY).typedValue;
	}
	
	private function get_position():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.POSITION).typedValue;
	}
	
	private function get_cssFloat():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.FLOAT).typedValue;
	}
	
	private function get_clear():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.CLEAR).typedValue;
	}
	
	private function get_zIndex():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.Z_INDEX).typedValue;
	}
	
	private function get_backgroundColor():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_COLOR).typedValue;
	}
	
	private function get_backgroundImage():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_IMAGE).typedValue;
	}

	private function get_backgroundOrigin():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_ORIGIN).typedValue;
	}
	
	private function get_backgroundClip():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_CLIP).typedValue;
	}
	
	private function get_backgroundRepeat():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_REPEAT).typedValue;
	}
	
	private function get_backgroundSize():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_SIZE).typedValue;
	}
	
	private function get_backgroundPosition():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.BACKGROUND_POSITION).typedValue;
	}
	
	private function get_fontWeight():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.FONT_WEIGHT).typedValue;
	}
	
	private function get_fontStyle():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.FONT_STYLE).typedValue;
	}
	
	private function get_fontFamily():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.FONT_FAMILY).typedValue;
	}
	
	private function get_fontVariant():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.FONT_VARIANT).typedValue;
	}
	
	private function get_color():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.COLOR).typedValue;
	}
	
	private function get_lineHeight():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.LINE_HEIGHT, computedValues.getTypedProperty(CSSConstants.LINE_HEIGHT).typedValue);
	}
	
	private function get_textTransform():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TEXT_TRANSFORM).typedValue;
	}
	
	private function get_letterSpacing():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.LETTER_SPACING, computedValues.getTypedProperty(CSSConstants.LETTER_SPACING).typedValue);
	}
	
	private function get_wordSpacing():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.WORD_SPACING, computedValues.getTypedProperty(CSSConstants.WORD_SPACING).typedValue);
	}
	
	private function get_whiteSpace():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.WHITE_SPACE).typedValue;
	}
	
	private function get_textAlign():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TEXT_ALIGN).typedValue;
	}
	
	private function get_textIndent():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.TEXT_INDENT, computedValues.getTypedProperty(CSSConstants.TEXT_INDENT).typedValue);
	}
	
	private function get_verticalAlign():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.VERTICAL_ALIGN).typedValue;
	}
	
	private function get_visibility():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.VISIBILITY).typedValue;
	}
	
	private function get_overflowX():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.OVERFLOW_X).typedValue;
	}
	
	private function get_overflowY():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.OVERFLOW_Y).typedValue;
	}
	
	private function get_transformOrigin():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TRANSFORM_ORIGIN).typedValue;
	}
	
	private function get_transform():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TRANSFORM).typedValue;
	}
	
	private function get_cursor():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.CURSOR).typedValue;
	}
	
	private function get_transitionProperty():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TRANSITION_PROPERTY).typedValue;
	}
	
	private function get_transitionDuration():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TRANSITION_DURATION).typedValue;
	}
	
	private function get_transitionTimingFunction():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TRANSITION_TIMING_FUNCTION).typedValue;
	}
	
	private function get_transitionDelay():CSSPropertyValue
	{
		return computedValues.getTypedProperty(CSSConstants.TRANSITION_DELAY).typedValue;
	}
}