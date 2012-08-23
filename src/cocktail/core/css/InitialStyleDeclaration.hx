/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;
import cocktail.core.style.CSSConstants;

/**
 * This class holds all the initial values of
 * the supported CSS styles. It is used during 
 * cascading, to assign the initial value of a
 * property when it wasn't given an explicit
 * value for a given node
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialStyleDeclaration extends CSSStyleDeclaration
{
	/**
	 * An array containing the names of all of the supported
	 * CSS properties
	 */
	public var supportedCSSProperties(default, null):Hash<Void>;
	
	/**
	 * An array containing the names of all of the supported
	 * CSS properties which can be defined as a CSS Length
	 * or can have Length component
	 */
	public var lengthCSSProperties(default, null):Array<String>;
	
	
	/**
	 * Class constructor. Push all the initial values
	 */
	public function new() 
	{
		super();
		
		initSupportedCSSProperties();
		initLengthCSSProperties();
		initProperties();
	}
	
	private function initLengthCSSProperties():Void
	{
		lengthCSSProperties = [
		CSSConstants.WIDTH, CSSConstants.HEIGHT, CSSConstants.TOP, CSSConstants.LEFT,
		CSSConstants.BOTTOM, CSSConstants.RIGHT, CSSConstants.MIN_HEIGHT, CSSConstants.MAX_HEIGHT,
		CSSConstants.MIN_WIDTH, CSSConstants.MAX_WIDTH, CSSConstants.VERTICAL_ALIGN, CSSConstants.LINE_HEIGHT,
		CSSConstants.MARGIN_LEFT, CSSConstants.MARGIN_RIGHT, CSSConstants.MARGIN_TOP, CSSConstants.MARGIN_BOTTOM,
		CSSConstants.PADDING_LEFT, CSSConstants.PADDING_RIGHT, CSSConstants.PADDING_TOP, CSSConstants.PADDING_BOTTOM,
		CSSConstants.LEFT, CSSConstants.RIGHT, CSSConstants.TOP, CSSConstants.BOTTOM, CSSConstants.LETTER_SPACING,
		CSSConstants.WORD_SPACING, CSSConstants.TEXT_INDENT, CSSConstants.TRANSFORM, CSSConstants.TRANSFORM_ORIGIN,
		CSSConstants.BACKGROUND_POSITION, CSSConstants.BACKGROUND_SIZE
		];
	}
	
	private function initSupportedCSSProperties():Void
	{
		supportedCSSProperties = new Hash<Void>();
		
		supportedCSSProperties.set(CSSConstants.DISPLAY, null);
		supportedCSSProperties.set(CSSConstants.POSITION, null);
		supportedCSSProperties.set(CSSConstants.FLOAT, null);
		supportedCSSProperties.set(CSSConstants.CLEAR, null);
		supportedCSSProperties.set(CSSConstants.Z_INDEX, null);
		supportedCSSProperties.set(CSSConstants.OVERFLOW_X, null);
		supportedCSSProperties.set(CSSConstants.OVERFLOW_Y, null);
		supportedCSSProperties.set(CSSConstants.VISIBILITY, null);
		supportedCSSProperties.set(CSSConstants.OPACITY, null);
		supportedCSSProperties.set(CSSConstants.VERTICAL_ALIGN, null);
		supportedCSSProperties.set(CSSConstants.LINE_HEIGHT, null);
		
		supportedCSSProperties.set(CSSConstants.WIDTH, null);
		supportedCSSProperties.set(CSSConstants.HEIGHT, null);
		
		supportedCSSProperties.set(CSSConstants.MIN_WIDTH, null);
		supportedCSSProperties.set(CSSConstants.MIN_HEIGHT, null);
		supportedCSSProperties.set(CSSConstants.MAX_WIDTH, null);
		supportedCSSProperties.set(CSSConstants.MAX_HEIGHT, null);
		
		supportedCSSProperties.set(CSSConstants.MARGIN_LEFT, null);
		supportedCSSProperties.set(CSSConstants.MARGIN_TOP, null);
		supportedCSSProperties.set(CSSConstants.MARGIN_RIGHT, null);
		supportedCSSProperties.set(CSSConstants.MARGIN_BOTTOM, null);
		
		supportedCSSProperties.set(CSSConstants.PADDING_LEFT, null);
		supportedCSSProperties.set(CSSConstants.PADDING_TOP, null);
		supportedCSSProperties.set(CSSConstants.PADDING_RIGHT, null);
		supportedCSSProperties.set(CSSConstants.PADDING_BOTTOM, null);
		
		supportedCSSProperties.set(CSSConstants.LEFT, null);
		supportedCSSProperties.set(CSSConstants.RIGHT, null);
		supportedCSSProperties.set(CSSConstants.TOP, null);
		supportedCSSProperties.set(CSSConstants.BOTTOM, null);

		supportedCSSProperties.set(CSSConstants.FONT_FAMILY, null);
		supportedCSSProperties.set(CSSConstants.FONT_SIZE, null);
		supportedCSSProperties.set(CSSConstants.FONT_STYLE, null);
		supportedCSSProperties.set(CSSConstants.FONT_VARIANT, null);
		supportedCSSProperties.set(CSSConstants.FONT_WEIGHT, null);
		
		supportedCSSProperties.set(CSSConstants.LETTER_SPACING, null);
		supportedCSSProperties.set(CSSConstants.WORD_SPACING, null);
		supportedCSSProperties.set(CSSConstants.TEXT_INDENT, null);
		supportedCSSProperties.set(CSSConstants.TEXT_ALIGN, null);
		supportedCSSProperties.set(CSSConstants.WHITE_SPACE, null);
		supportedCSSProperties.set(CSSConstants.TEXT_TRANSFORM, null);
		supportedCSSProperties.set(CSSConstants.COLOR, null);
		
		supportedCSSProperties.set(CSSConstants.TRANSITION_PROPERTY, null);
		supportedCSSProperties.set(CSSConstants.TRANSITION_DURATION, null);
		supportedCSSProperties.set(CSSConstants.TRANSITION_DELAY, null);
		supportedCSSProperties.set(CSSConstants.TRANSITION_TIMING_FUNCTION, null);
		
		supportedCSSProperties.set(CSSConstants.TRANSFORM, null);
		supportedCSSProperties.set(CSSConstants.TRANSFORM_ORIGIN, null);
		
		supportedCSSProperties.set(CSSConstants.BACKGROUND_COLOR, null);
		supportedCSSProperties.set(CSSConstants.BACKGROUND_IMAGE, null);
		supportedCSSProperties.set(CSSConstants.BACKGROUND_POSITION, null);
		supportedCSSProperties.set(CSSConstants.BACKGROUND_SIZE, null);
		supportedCSSProperties.set(CSSConstants.BACKGROUND_REPEAT, null);
		supportedCSSProperties.set(CSSConstants.BACKGROUND_ORIGIN, null);
		supportedCSSProperties.set(CSSConstants.BACKGROUND_CLIP, null);
		
		supportedCSSProperties.set(CSSConstants.CURSOR, null);
	}
	
	private function initProperties():Void
	{
		pushProperty(CSSConstants.WIDTH, KEYWORD(AUTO));
		pushProperty(CSSConstants.HEIGHT, KEYWORD(AUTO));
		
		pushProperty(CSSConstants.DISPLAY, KEYWORD(INLINE));
		pushProperty(CSSConstants.POSITION, KEYWORD(STATIC));
		pushProperty(CSSConstants.FLOAT, KEYWORD(NONE));
		pushProperty(CSSConstants.CLEAR, KEYWORD(NONE));
		pushProperty(CSSConstants.Z_INDEX, KEYWORD(AUTO));
		pushProperty(CSSConstants.OVERFLOW_X, KEYWORD(VISIBLE));
		pushProperty(CSSConstants.OVERFLOW_Y, KEYWORD(VISIBLE));
		pushProperty(CSSConstants.VISIBILITY, KEYWORD(VISIBLE));
		pushProperty(CSSConstants.OPACITY, NUMBER(1.0));
		
		pushProperty(CSSConstants.VERTICAL_ALIGN, KEYWORD(BASELINE));
		pushProperty(CSSConstants.LINE_HEIGHT, KEYWORD(NORMAL));
		
		pushProperty(CSSConstants.MAX_WIDTH, KEYWORD(NONE));
		pushProperty(CSSConstants.MAX_HEIGHT, KEYWORD(NONE));
		pushProperty(CSSConstants.MIN_WIDTH, INTEGER(0));
		pushProperty(CSSConstants.MIN_HEIGHT, INTEGER(0));
		
		pushProperty(CSSConstants.MARGIN_LEFT, INTEGER(0));
		pushProperty(CSSConstants.MARGIN_TOP, INTEGER(0));
		pushProperty(CSSConstants.MARGIN_RIGHT, INTEGER(0));
		pushProperty(CSSConstants.MARGIN_BOTTOM, INTEGER(0));
		
		pushProperty(CSSConstants.PADDING_LEFT, INTEGER(0));
		pushProperty(CSSConstants.PADDING_TOP, INTEGER(0));
		pushProperty(CSSConstants.PADDING_RIGHT, INTEGER(0));
		pushProperty(CSSConstants.PADDING_BOTTOM, INTEGER(0));
		
		pushProperty(CSSConstants.LEFT, KEYWORD(AUTO));
		pushProperty(CSSConstants.RIGHT, KEYWORD(AUTO));
		pushProperty(CSSConstants.TOP, KEYWORD(AUTO));
		pushProperty(CSSConstants.BOTTOM, KEYWORD(AUTO));
		

		pushProperty(CSSConstants.FONT_STYLE, KEYWORD(NORMAL));
		pushProperty(CSSConstants.FONT_VARIANT, KEYWORD(NORMAL));
		pushProperty(CSSConstants.FONT_WEIGHT, KEYWORD(NORMAL));
		pushProperty(CSSConstants.FONT_SIZE, KEYWORD(MEDIUM));
		
		pushProperty(CSSConstants.LETTER_SPACING, KEYWORD(NORMAL));
		pushProperty(CSSConstants.WORD_SPACING, KEYWORD(NORMAL));
		pushProperty(CSSConstants.TEXT_INDENT, INTEGER(0));
		pushProperty(CSSConstants.TEXT_ALIGN, KEYWORD(LEFT));
		pushProperty(CSSConstants.WHITE_SPACE, KEYWORD(NORMAL));
		pushProperty(CSSConstants.TEXT_TRANSFORM, KEYWORD(NONE));
		
		pushProperty(CSSConstants.TRANSITION_PROPERTY, KEYWORD(ALL));
		pushProperty(CSSConstants.TRANSITION_DURATION, TIME(SECONDS(0)));
		pushProperty(CSSConstants.TRANSITION_DELAY, TIME(SECONDS(0)));
		pushProperty(CSSConstants.TRANSITION_TIMING_FUNCTION, KEYWORD(EASE));
		
		pushProperty(CSSConstants.TRANSFORM, KEYWORD(NONE));
		pushProperty(CSSConstants.TRANSFORM_ORIGIN, GROUP([PERCENTAGE(50), PERCENTAGE(50)]));
		
		pushProperty(CSSConstants.BACKGROUND_COLOR, COLOR(TRANSPARENT));
		pushProperty(CSSConstants.BACKGROUND_IMAGE, KEYWORD(NONE));
		pushProperty(CSSConstants.BACKGROUND_POSITION, GROUP([PERCENTAGE(0.0), PERCENTAGE(0.0)]));
		pushProperty(CSSConstants.BACKGROUND_SIZE, KEYWORD(AUTO));
		pushProperty(CSSConstants.BACKGROUND_REPEAT, KEYWORD(REPEAT));
		pushProperty(CSSConstants.BACKGROUND_CLIP, KEYWORD(BORDER_BOX));
		pushProperty(CSSConstants.BACKGROUND_ORIGIN, KEYWORD(PADDING_BOX));
		
		pushProperty(CSSConstants.CURSOR, KEYWORD(AUTO));
		
		//TODO 2 : this represents default value for whole document, should be in config file ?
		pushProperty(CSSConstants.FONT_FAMILY, CSS_LIST([STRING("serif")]));
		pushProperty(CSSConstants.COLOR, COLOR(CSSColorValue.KEYWORD(CSSColorKeyword.BLACK)));
	}
	
	/**
	 * Utils method to push properties
	 */
	private function pushProperty(name:String, typedValue:CSSPropertyValue):Void
	{
		_properties.push( { name:name, typedValue:typedValue, important:false });
	}
}