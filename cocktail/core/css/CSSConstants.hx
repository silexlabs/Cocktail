/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

/**
 * List constants for CSS style names, unit, keywords...
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSConstants 
{

	/**
	 * Holds the total number of supported CSS styles
	 */
	public static inline var SUPPORTED_STYLES_NUMBER:Int = 87;
	
	//style names
	
	public static inline var DISPLAY:Int = 0;
	
	public static inline var POSITION:Int = 1;
	
	public static inline var FLOAT:Int = 2;
	
	public static inline var CLEAR:Int = 3;
	
	public static inline var Z_INDEX:Int = 4;
	
	public static inline var MARGIN:Int = 5;
	
	public static inline var MARGIN_LEFT:Int = 6;
	
	public static inline var MARGIN_RIGHT:Int = 7;
	
	public static inline var MARGIN_TOP:Int = 8;
	
	public static inline var MARGIN_BOTTOM:Int = 9;
	
	public static inline var PADDING:Int = 10;
	
	public static inline var PADDING_LEFT:Int = 11;
	
	public static inline var PADDING_RIGHT:Int = 12;
	
	public static inline var PADDING_TOP:Int = 13;
	
	public static inline var PADDING_BOTTOM:Int = 14;
	
	public static inline var WIDTH:Int = 15;
	
	public static inline var HEIGHT:Int = 16;
	
	public static inline var MIN_HEIGHT:Int = 17;
	
	public static inline var MAX_HEIGHT:Int = 18;
	
	public static inline var MIN_WIDTH:Int = 19;
	
	public static inline var MAX_WIDTH:Int = 20;
	
	public static inline var TOP:Int = 21;
	
	public static inline var LEFT:Int = 22;
	
	public static inline var RIGHT:Int = 23;
	
	public static inline var BOTTOM:Int = 24;
	
	public static inline var BACKGROUND_COLOR:Int = 25;
	
	public static inline var BACKGROUND_IMAGE:Int = 26;
	
	public static inline var BACKGROUND_REPEAT:Int = 27;
	
	public static inline var BACKGROUND_ORIGIN:Int = 28;
	
	public static inline var BACKGROUND_SIZE:Int = 29;
	
	public static inline var BACKGROUND_POSITION:Int = 30;
	
	public static inline var BACKGROUND_CLIP:Int = 31;
	
	public static inline var BACKGROUND_ATTACHMENT:Int = 32;
	
	public static inline var BACKGROUND:Int = 33;
	
	public static inline var FONT_SIZE:Int = 34;
	
	public static inline var FONT_WEIGHT:Int = 35;
	
	public static inline var FONT_STYLE:Int = 36;
	
	public static inline var FONT_FAMILY:Int = 37;
	
	public static inline var FONT_VARIANT:Int = 38;
	
	public static inline var FONT:Int = 39;
	
	public static inline var COLOR:Int = 40;
	
	public static inline var LINE_HEIGHT:Int = 41;
	
	public static inline var TEXT_TRANSFORM:Int = 42;
	
	public static inline var LETTER_SPACING:Int = 43;
	
	public static inline var WORD_SPACING:Int = 44;
	
	public static inline var WHITE_SPACE:Int = 45;
	
	public static inline var TEXT_ALIGN:Int = 46;
	
	public static inline var TEXT_INDENT:Int = 47;
	
	public static inline var VERTICAL_ALIGN:Int = 48;
	
	public static inline var VISIBILITY:Int = 49;
	
	public static inline var CSS_OVERFLOW:Int = 50;
	
	public static inline var OVERFLOW_X:Int = 51;
	
	public static inline var OVERFLOW_Y:Int = 52;
	
	public static inline var OPACITY:Int = 53;
	
	public static inline var CURSOR:Int = 54;
	
	public static inline var TRANSITION_DURATION:Int = 55;

	public static inline var TRANSITION_DELAY:Int = 56;

	public static inline var TRANSITION_PROPERTY:Int = 57;

	public static inline var TRANSITION_TIMING_FUNCTION:Int = 58;
	
	public static inline var TRANSITION:Int = 59;

	public static inline var TRANSFORM_ORIGIN:Int = 60;

	public static inline var TRANSFORM:Int = 61;
	
	public static inline var BORDER_TOP_WIDTH:Int = 62;
	
	public static inline var BORDER_RIGHT_WIDTH:Int = 63;
	
	public static inline var BORDER_BOTTOM_WIDTH:Int = 64;
	
	public static inline var BORDER_LEFT_WIDTH:Int = 65;
	
	public static inline var BORDER_WIDTH:Int = 66;
	
	public static inline var BORDER_TOP_COLOR:Int = 67;
	
	public static inline var BORDER_RIGHT_COLOR:Int = 68;
	
	public static inline var BORDER_BOTTOM_COLOR:Int = 69;
	
	public static inline var BORDER_LEFT_COLOR:Int = 70;
	
	public static inline var BORDER_COLOR:Int = 71;
	
	public static inline var BORDER_TOP_STYLE:Int = 72;
	
	public static inline var BORDER_RIGHT_STYLE:Int = 73;
	
	public static inline var BORDER_BOTTOM_STYLE:Int = 74;
	
	public static inline var BORDER_LEFT_STYLE:Int = 75;
	
	public static inline var BORDER_STYLE:Int = 76;
	
	public static inline var BORDER_TOP:Int = 77;
	
	public static inline var BORDER_RIGHT:Int = 78;
	
	public static inline var BORDER_BOTTOM:Int = 79;
	
	public static inline var BORDER_LEFT:Int = 80;
	
	public static inline var BORDER:Int = 81;
	
	public static inline var OUTLINE_WIDTH:Int = 82;
	
	public static inline var OUTLINE_STYLE:Int = 83;
	
	public static inline var OUTLINE_COLOR:Int =  84;
	
	public static inline var OUTLINE:Int = 85;
	
	public static inline var TEXT_DECORATION:Int = 86;
	
	//CSS Ident
	
	public static inline var IMPORTANT:String = "important";
	
	public static inline var AUTO:String = "auto";
	
	public static inline var LEFT_IDENT:String = "left";
	
	public static inline var TOP_IDENT:String = "top";
	
	public static inline var RIGHT_IDENT:String = "right";
	
	public static inline var BOTTOM_IDENT:String = "bottom";
	
	//CSS IDL name (used when scripting)
	
	public static inline var HEIGHT_IDL_NAME:String = "height";
	
	public static inline var WIDTH_IDL_NAME:String = "width";
	
	public static inline var MAX_WIDTH_IDL_NAME:String = "maxWidth";
	
	public static inline var MIN_WIDTH_IDL_NAME:String = "minWidth";
	
	public static inline var MAX_HEIGHT_IDL_NAME:String = "maxHeight";
	
	//CSS metadata
	
	public static inline var CSS_MIME_TYPE:String = "text/css";
	
	public static inline var STYLESHEET_REL:String = "stylesheet";

	//CSS Property names
	
	public static inline var DISPLAY_NAME:String = "display";

	public static inline var POSITION_NAME:String = "position";

	public static inline var FLOAT_NAME:String = "float";

	public static inline var CLEAR_NAME:String = "clear";

	public static inline var Z_INDEX_NAME:String = "z-index";

	public static inline var MARGIN_NAME:String = "margin";

	public static inline var MARGIN_LEFT_NAME:String = "margin-left";

	public static inline var MARGIN_RIGHT_NAME:String = "margin-right";

	public static inline var MARGIN_TOP_NAME:String = "margin-top";

	public static inline var MARGIN_BOTTOM_NAME:String = "margin-bottom";

	public static inline var PADDING_NAME:String = "padding";

	public static inline var PADDING_LEFT_NAME:String = "padding-left";

	public static inline var PADDING_RIGHT_NAME:String = "padding-right";

	public static inline var PADDING_TOP_NAME:String = "padding-top";

	public static inline var PADDING_BOTTOM_NAME:String = "padding-bottom";

	public static inline var WIDTH_NAME:String = "width";

	public static inline var HEIGHT_NAME:String = "height";

	public static inline var MIN_HEIGHT_NAME:String = "min-height";

	public static inline var MAX_HEIGHT_NAME:String = "max-height";

	public static inline var MIN_WIDTH_NAME:String = "min-width";

	public static inline var MAX_WIDTH_NAME:String = "max-width";

	public static inline var TOP_NAME:String = "top";

	public static inline var LEFT_NAME:String = "left";

	public static inline var RIGHT_NAME:String = "right";

	public static inline var BOTTOM_NAME:String = "bottom";

	public static inline var BACKGROUND_COLOR_NAME:String = "background-color";

	public static inline var BACKGROUND_IMAGE_NAME:String = "background-image";

	public static inline var BACKGROUND_REPEAT_NAME:String = "background-repeat";

	public static inline var BACKGROUND_ORIGIN_NAME:String = "background-origin";

	public static inline var BACKGROUND_SIZE_NAME:String = "background-size";

	public static inline var BACKGROUND_POSITION_NAME:String = "background-position";

	public static inline var BACKGROUND_CLIP_NAME:String = "background-clip";

	public static inline var BACKGROUND_ATTACHMENT_NAME:String = "background-attachment";

	public static inline var BACKGROUND_NAME:String = "background";

	public static inline var FONT_SIZE_NAME:String = "font-size";

	public static inline var FONT_WEIGHT_NAME:String = "font-weight";

	public static inline var FONT_STYLE_NAME:String = "font-style";

	public static inline var FONT_FAMILY_NAME:String = "font-family";

	public static inline var FONT_VARIANT_NAME:String = "font-variant";

	public static inline var FONT_NAME:String = "font";

	public static inline var COLOR_NAME:String = "color";

	public static inline var LINE_HEIGHT_NAME:String = "line-height";

	public static inline var TEXT_TRANSFORM_NAME:String = "text-transform";

	public static inline var LETTER_SPACING_NAME:String = "letter-spacing";

	public static inline var WORD_SPACING_NAME:String = "word-spacing";

	public static inline var WHITE_SPACE_NAME:String = "white-space";

	public static inline var TEXT_ALIGN_NAME:String = "text-align";

	public static inline var TEXT_INDENT_NAME:String = "text-indent";

	public static inline var VERTICAL_ALIGN_NAME:String = "vertical-align";

	public static inline var VISIBILITY_NAME:String = "visibility";

	public static inline var CSS_OVERFLOW_NAME:String = "overflow";

	public static inline var OVERFLOW_X_NAME:String = "overflow-x";

	public static inline var OVERFLOW_Y_NAME:String = "overflow-y";

	public static inline var OPACITY_NAME:String = "opacity";

	public static inline var CURSOR_NAME:String = "cursor";

	public static inline var TRANSITION_DURATION_NAME:String = "transition-duration";

	public static inline var TRANSITION_DELAY_NAME:String = "transition-delay";

	public static inline var TRANSITION_PROPERTY_NAME:String = "transition-property";

	public static inline var TRANSITION_TIMING_FUNCTION_NAME:String = "transition-timing-function";

	public static inline var TRANSITION_NAME:String = "transition";

	public static inline var TRANSFORM_ORIGIN_NAME:String = "transform-origin";

	public static inline var TRANSFORM_NAME:String = "transform";
	
	public static inline var BORDER_TOP_WIDTH_NAME:String = "border-top-width";
	
	public static inline var BORDER_RIGHT_WIDTH_NAME:String = "border-right-width";
	
	public static inline var BORDER_BOTTOM_WIDTH_NAME:String = "border-bottom-width";
	
	public static inline var BORDER_LEFT_WIDTH_NAME:String = "border-left-width";
	
	public static inline var BORDER_WIDTH_NAME:String = "border-width";
	
	public static inline var BORDER_TOP_COLOR_NAME:String = "border-top-color";
	
	public static inline var BORDER_RIGHT_COLOR_NAME:String = "border-right-color";
	
	public static inline var BORDER_BOTTOM_COLOR_NAME:String = "border-bottom-color";
	
	public static inline var BORDER_LEFT_COLOR_NAME:String = "border-left-color";
	
	public static inline var BORDER_COLOR_NAME:String = "border-color";
	
	public static inline var BORDER_TOP_STYLE_NAME:String = "border-top-style";
	
	public static inline var BORDER_RIGHT_STYLE_NAME:String = "border-right-style";
	
	public static inline var BORDER_BOTTOM_STYLE_NAME:String = "border-bottom-style";
	
	public static inline var BORDER_LEFT_STYLE_NAME:String = "border-left-style";
	
	public static inline var BORDER_STYLE_NAME:String = "border-style";
	
	public static inline var BORDER_TOP_NAME:String = "border-top";
	
	public static inline var BORDER_RIGHT_NAME:String = "border-right";
	
	public static inline var BORDER_BOTTOM_NAME:String = "border-bottom";
	
	public static inline var BORDER_LEFT_NAME:String = "border-left";
	
	public static inline var BORDER_NAME:String = "border";
	
	public static inline var OUTLINE_WIDTH_NAME:String = "outline-width";
	
	public static inline var OUTLINE_STYLE_NAME:String = "outline-style";
	
	public static inline var OUTLINE_COLOR_NAME:String = "outline-color";
	
	public static inline var OUTLINE_NAME:String = "outline";
	
	public static inline var TEXT_DECORATION_NAME:String = "text-decoration";
	
	public function new() 
	{
		
	}
	
	/**
	 * Return the index of a CSS property from its name
	 */
	public static function getPropertyIndexFromName(name:String):Int
	{
		switch (name)
		{
			case DISPLAY_NAME:
				return DISPLAY;
				
			case POSITION_NAME:
				return POSITION;
				
			case FLOAT_NAME:
				return FLOAT;
				
			case CLEAR_NAME:
				return CLEAR;
				
			case Z_INDEX_NAME:
				return Z_INDEX;
				
			case MARGIN_NAME:
				return MARGIN;
				
			case MARGIN_LEFT_NAME:
				return MARGIN_LEFT;
				
			case MARGIN_TOP_NAME:
				return MARGIN_TOP;
				
			case MARGIN_RIGHT_NAME:
				return MARGIN_RIGHT;
				
			case MARGIN_BOTTOM_NAME:
				return MARGIN_BOTTOM;
				
			case PADDING_NAME:
				return PADDING;
				
			case PADDING_LEFT_NAME:
				return PADDING_LEFT;
				
			case PADDING_RIGHT_NAME:
				return PADDING_RIGHT;
				
			case PADDING_TOP_NAME:
				return PADDING_TOP;
				
			case PADDING_BOTTOM_NAME:
				return PADDING_BOTTOM;
				
			case WIDTH_NAME:
				return WIDTH;
				
			case HEIGHT_NAME:
				return HEIGHT;
				
			case MIN_HEIGHT_NAME:
				return MIN_HEIGHT;
				
			case MAX_HEIGHT_NAME:
				return MAX_HEIGHT;
				
			case MIN_WIDTH_NAME:
				return MIN_WIDTH;
				
			case MAX_WIDTH_NAME:
				return MAX_WIDTH;
				
			case TOP_NAME:
				return TOP;
				
			case RIGHT_NAME:
				return RIGHT;
				
			case BOTTOM_NAME:
				return BOTTOM;
				
			case LEFT_NAME:
				return LEFT;
				
			case BACKGROUND_COLOR_NAME:
				return BACKGROUND_COLOR;
			
			case BACKGROUND_IMAGE_NAME:
				return BACKGROUND_IMAGE;
				
			case BACKGROUND_REPEAT_NAME:
				return BACKGROUND_REPEAT;
				
			case BACKGROUND_ORIGIN_NAME:
				return BACKGROUND_ORIGIN;
				
			case BACKGROUND_SIZE_NAME:
				return BACKGROUND_SIZE;
				
			case BACKGROUND_POSITION_NAME:
				return BACKGROUND_POSITION;
				
			case BACKGROUND_CLIP_NAME:
				return BACKGROUND_CLIP;
				
			case BACKGROUND_ATTACHMENT_NAME:
				return BACKGROUND_ATTACHMENT;
				
			case BACKGROUND_NAME:
				return BACKGROUND;
				
			case FONT_SIZE_NAME:
				return FONT_SIZE;
				
			case FONT_WEIGHT_NAME:
				return FONT_WEIGHT;
				
			case FONT_STYLE_NAME:
				return FONT_STYLE;
				
			case FONT_FAMILY_NAME:
				return FONT_FAMILY;
				
			case FONT_VARIANT_NAME:
				return FONT_VARIANT;
				
			case FONT_NAME:
				return FONT;
			
			case COLOR_NAME:
				return COLOR;
				
			case LINE_HEIGHT_NAME:
				return LINE_HEIGHT;
				
			case TEXT_TRANSFORM_NAME:
				return TEXT_TRANSFORM;
				
			case LETTER_SPACING_NAME:
				return LETTER_SPACING;
				
			case WORD_SPACING_NAME:
				return WORD_SPACING;
				
			case WHITE_SPACE_NAME:
				return WHITE_SPACE;
				
			case TEXT_ALIGN_NAME:
				return TEXT_ALIGN;
				
			case TEXT_INDENT_NAME:
				return TEXT_INDENT;
				
			case VERTICAL_ALIGN_NAME:
				return VERTICAL_ALIGN;
				
			case VISIBILITY_NAME:
				return VISIBILITY;
				
			case CSS_OVERFLOW_NAME:
				return CSS_OVERFLOW;
				
			case OVERFLOW_X_NAME:
				return OVERFLOW_X;
				
			case OVERFLOW_Y_NAME:
				return OVERFLOW_Y;
				
			case OPACITY_NAME:
				return OPACITY;
				
			case CURSOR_NAME:
				return CURSOR;
				
			case TRANSITION_DURATION_NAME:
				return TRANSITION_DURATION;
				
			case TRANSITION_DELAY_NAME:
				return TRANSITION_DELAY;
				
			case TRANSITION_PROPERTY_NAME:
				return TRANSITION_PROPERTY;
				
			case TRANSITION_TIMING_FUNCTION_NAME:
				return TRANSITION_TIMING_FUNCTION;
				
			case TRANSITION_NAME:
				return TRANSITION;
				
			case TRANSFORM_ORIGIN_NAME:
				return TRANSFORM_ORIGIN;
				
			case TRANSFORM_NAME:
				return TRANSFORM;
				
			case BORDER_TOP_WIDTH_NAME:
				return BORDER_TOP_WIDTH;
	
			case BORDER_RIGHT_WIDTH_NAME:
				return BORDER_RIGHT_WIDTH;

			case BORDER_BOTTOM_WIDTH_NAME:
				return BORDER_BOTTOM_WIDTH;

			case BORDER_LEFT_WIDTH_NAME:
				return BORDER_LEFT_WIDTH;

			case BORDER_WIDTH_NAME:
				return BORDER_WIDTH;

			case BORDER_TOP_COLOR_NAME:
				return BORDER_TOP_COLOR;

			case BORDER_RIGHT_COLOR_NAME:
				return BORDER_RIGHT_COLOR;

			case BORDER_BOTTOM_COLOR_NAME:
				return BORDER_BOTTOM_COLOR;

			case BORDER_LEFT_COLOR_NAME:
				return BORDER_LEFT_COLOR;

			case BORDER_COLOR_NAME:
				return BORDER_COLOR;

			case BORDER_TOP_STYLE_NAME:
				return BORDER_TOP_STYLE;

			case BORDER_RIGHT_STYLE_NAME:
				return BORDER_RIGHT_STYLE;

			case BORDER_BOTTOM_STYLE_NAME:
				return BORDER_BOTTOM_STYLE;

			case BORDER_LEFT_STYLE_NAME:
				return BORDER_LEFT_STYLE;

			case BORDER_STYLE_NAME:
				return BORDER_STYLE;

			case BORDER_TOP_NAME:
				return BORDER_TOP;

			case BORDER_RIGHT_NAME:
				return BORDER_RIGHT;

			case BORDER_BOTTOM_NAME:
				return BORDER_BOTTOM;

			case BORDER_LEFT_NAME:
				return BORDER_LEFT;

			case BORDER_NAME:
				return BORDER;
				
			case OUTLINE_WIDTH_NAME:
				return OUTLINE_WIDTH;
				
			case OUTLINE_STYLE_NAME:
				return OUTLINE_STYLE;
				
			case OUTLINE_COLOR_NAME:
				return OUTLINE_COLOR;
			
			case OUTLINE_NAME:
				return OUTLINE;
				
			case TEXT_DECORATION_NAME:
				return TEXT_DECORATION;
				
			default:
				return -1;
		}
	}
	
	/**
	 * Return the name of a css property from its index
	 */
	public static function getPropertyNameFromIndex(index:Int):String
	{
		switch (index)
		{
			case DISPLAY:
				return DISPLAY_NAME;
				
			case POSITION:
				return POSITION_NAME;
				
			case FLOAT:
				return FLOAT_NAME;
				
			case CLEAR:
				return CLEAR_NAME;
				
			case Z_INDEX:
				return Z_INDEX_NAME;
				
			case MARGIN:
				return MARGIN_NAME;
				
			case MARGIN_LEFT:
				return MARGIN_LEFT_NAME;
				
			case MARGIN_TOP:
				return MARGIN_TOP_NAME;
				
			case MARGIN_RIGHT:
				return MARGIN_RIGHT_NAME;
				
			case MARGIN_BOTTOM:
				return MARGIN_BOTTOM_NAME;
				
			case PADDING:
				return PADDING_NAME;
				
			case PADDING_LEFT:
				return PADDING_LEFT_NAME;
				
			case PADDING_RIGHT:
				return PADDING_RIGHT_NAME;
				
			case PADDING_TOP:
				return PADDING_TOP_NAME;
				
			case PADDING_BOTTOM:
				return PADDING_BOTTOM_NAME;
				
			case WIDTH:
				return WIDTH_NAME;
				
			case HEIGHT:
				return HEIGHT_NAME;
				
			case MIN_HEIGHT:
				return MIN_HEIGHT_NAME;
				
			case MAX_HEIGHT:
				return MAX_HEIGHT_NAME;
				
			case MIN_WIDTH:
				return MIN_WIDTH_NAME;
				
			case MAX_WIDTH:
				return MAX_WIDTH_NAME;
				
			case TOP:
				return TOP_NAME;
				
			case RIGHT:
				return RIGHT_NAME;
				
			case BOTTOM:
				return BOTTOM_NAME;
				
			case LEFT:
				return LEFT_NAME;
				
			case BACKGROUND_COLOR:
				return BACKGROUND_COLOR_NAME;
			
			case BACKGROUND_IMAGE:
				return BACKGROUND_IMAGE_NAME;
				
			case BACKGROUND_REPEAT:
				return BACKGROUND_REPEAT_NAME;
				
			case BACKGROUND_ORIGIN:
				return BACKGROUND_ORIGIN_NAME;
				
			case BACKGROUND_SIZE:
				return BACKGROUND_SIZE_NAME;
				
			case BACKGROUND_POSITION:
				return BACKGROUND_POSITION_NAME;
				
			case BACKGROUND_CLIP:
				return BACKGROUND_CLIP_NAME;
				
			case BACKGROUND_ATTACHMENT:
				return BACKGROUND_ATTACHMENT_NAME;
				
			case BACKGROUND:
				return BACKGROUND_NAME;
				
			case FONT_SIZE:
				return FONT_SIZE_NAME;
				
			case FONT_WEIGHT:
				return FONT_WEIGHT_NAME;
				
			case FONT_STYLE:
				return FONT_STYLE_NAME;
				
			case FONT_FAMILY:
				return FONT_FAMILY_NAME;
				
			case FONT_VARIANT:
				return FONT_VARIANT_NAME;
				
			case FONT:
				return FONT_NAME;
			
			case COLOR:
				return COLOR_NAME;
				
			case LINE_HEIGHT:
				return LINE_HEIGHT_NAME;
				
			case TEXT_TRANSFORM:
				return TEXT_TRANSFORM_NAME;
				
			case LETTER_SPACING:
				return LETTER_SPACING_NAME;
				
			case WORD_SPACING:
				return WORD_SPACING_NAME;
				
			case WHITE_SPACE:
				return WHITE_SPACE_NAME;
				
			case TEXT_ALIGN:
				return TEXT_ALIGN_NAME;
				
			case TEXT_INDENT:
				return TEXT_INDENT_NAME;
				
			case VERTICAL_ALIGN:
				return VERTICAL_ALIGN_NAME;
				
			case VISIBILITY:
				return VISIBILITY_NAME;
				
			case CSS_OVERFLOW:
				return CSS_OVERFLOW_NAME;
				
			case OVERFLOW_X:
				return OVERFLOW_X_NAME;
				
			case OVERFLOW_Y:
				return OVERFLOW_Y_NAME;
				
			case OPACITY:
				return OPACITY_NAME;
				
			case CURSOR:
				return CURSOR_NAME;
				
			case TRANSITION_DURATION:
				return TRANSITION_DURATION_NAME;
				
			case TRANSITION_DELAY:
				return TRANSITION_DELAY_NAME;
				
			case TRANSITION_PROPERTY:
				return TRANSITION_PROPERTY_NAME;
				
			case TRANSITION_TIMING_FUNCTION:
				return TRANSITION_TIMING_FUNCTION_NAME;
				
			case TRANSITION:
				return TRANSITION_NAME;
				
			case TRANSFORM_ORIGIN:
				return TRANSFORM_ORIGIN_NAME;
				
			case TRANSFORM:
				return TRANSFORM_NAME;
				
			case BORDER_TOP_WIDTH:
				return BORDER_TOP_WIDTH_NAME;
	
			case BORDER_RIGHT_WIDTH:
				return BORDER_RIGHT_WIDTH_NAME;

			case BORDER_BOTTOM_WIDTH:
				return BORDER_BOTTOM_WIDTH_NAME;

			case BORDER_LEFT_WIDTH:
				return BORDER_LEFT_WIDTH_NAME;

			case BORDER_WIDTH:
				return BORDER_WIDTH_NAME;

			case BORDER_TOP_COLOR:
				return BORDER_TOP_COLOR_NAME;

			case BORDER_RIGHT_COLOR:
				return BORDER_RIGHT_COLOR_NAME;

			case BORDER_BOTTOM_COLOR:
				return BORDER_BOTTOM_COLOR_NAME;

			case BORDER_LEFT_COLOR:
				return BORDER_LEFT_COLOR_NAME;

			case BORDER_COLOR:
				return BORDER_COLOR_NAME;

			case BORDER_TOP_STYLE:
				return BORDER_TOP_STYLE_NAME;

			case BORDER_RIGHT_STYLE:
				return BORDER_RIGHT_STYLE_NAME;

			case BORDER_BOTTOM_STYLE:
				return BORDER_BOTTOM_STYLE_NAME;

			case BORDER_LEFT_STYLE:
				return BORDER_LEFT_STYLE_NAME;

			case BORDER_STYLE:
				return BORDER_STYLE_NAME;

			case BORDER_TOP:
				return BORDER_TOP_NAME;

			case BORDER_RIGHT:
				return BORDER_RIGHT_NAME;

			case BORDER_BOTTOM:
				return BORDER_BOTTOM_NAME;

			case BORDER_LEFT:
				return BORDER_LEFT_NAME;

			case BORDER:
				return BORDER_NAME;	
				
			case OUTLINE_WIDTH:
				return OUTLINE_WIDTH_NAME;
				
			case OUTLINE_STYLE:
				return OUTLINE_STYLE_NAME;
				
			case OUTLINE_COLOR:
				return OUTLINE_COLOR_NAME;
				
			case OUTLINE:
				return OUTLINE_NAME;
				
			case TEXT_DECORATION:
				return TEXT_DECORATION_NAME;
				
			default:
				throw "unknown property";
		}
	}
	
}