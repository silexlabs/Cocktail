#ifndef INCLUDED_cocktail_core_css_CSSConstants
#define INCLUDED_cocktail_core_css_CSSConstants

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSConstants)
namespace cocktail{
namespace core{
namespace css{


class CSSConstants_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSConstants_obj OBJ_;
		CSSConstants_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CSSConstants_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSConstants_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSConstants"); }

		static int SUPPORTED_STYLES_NUMBER; /* REM */ 
		static int DISPLAY; /* REM */ 
		static int POSITION; /* REM */ 
		static int FLOAT; /* REM */ 
		static int CLEAR; /* REM */ 
		static int Z_INDEX; /* REM */ 
		static int MARGIN; /* REM */ 
		static int MARGIN_LEFT; /* REM */ 
		static int MARGIN_RIGHT; /* REM */ 
		static int MARGIN_TOP; /* REM */ 
		static int MARGIN_BOTTOM; /* REM */ 
		static int PADDING; /* REM */ 
		static int PADDING_LEFT; /* REM */ 
		static int PADDING_RIGHT; /* REM */ 
		static int PADDING_TOP; /* REM */ 
		static int PADDING_BOTTOM; /* REM */ 
		static int WIDTH; /* REM */ 
		static int HEIGHT; /* REM */ 
		static int MIN_HEIGHT; /* REM */ 
		static int MAX_HEIGHT; /* REM */ 
		static int MIN_WIDTH; /* REM */ 
		static int MAX_WIDTH; /* REM */ 
		static int TOP; /* REM */ 
		static int LEFT; /* REM */ 
		static int RIGHT; /* REM */ 
		static int BOTTOM; /* REM */ 
		static int BACKGROUND_COLOR; /* REM */ 
		static int BACKGROUND_IMAGE; /* REM */ 
		static int BACKGROUND_REPEAT; /* REM */ 
		static int BACKGROUND_ORIGIN; /* REM */ 
		static int BACKGROUND_SIZE; /* REM */ 
		static int BACKGROUND_POSITION; /* REM */ 
		static int BACKGROUND_CLIP; /* REM */ 
		static int BACKGROUND_ATTACHMENT; /* REM */ 
		static int BACKGROUND; /* REM */ 
		static int FONT_SIZE; /* REM */ 
		static int FONT_WEIGHT; /* REM */ 
		static int FONT_STYLE; /* REM */ 
		static int FONT_FAMILY; /* REM */ 
		static int FONT_VARIANT; /* REM */ 
		static int FONT; /* REM */ 
		static int COLOR; /* REM */ 
		static int LINE_HEIGHT; /* REM */ 
		static int TEXT_TRANSFORM; /* REM */ 
		static int LETTER_SPACING; /* REM */ 
		static int WORD_SPACING; /* REM */ 
		static int WHITE_SPACE; /* REM */ 
		static int TEXT_ALIGN; /* REM */ 
		static int TEXT_INDENT; /* REM */ 
		static int VERTICAL_ALIGN; /* REM */ 
		static int VISIBILITY; /* REM */ 
		static int CSS_OVERFLOW; /* REM */ 
		static int OVERFLOW_X; /* REM */ 
		static int OVERFLOW_Y; /* REM */ 
		static int OPACITY; /* REM */ 
		static int CURSOR; /* REM */ 
		static int TRANSITION_DURATION; /* REM */ 
		static int TRANSITION_DELAY; /* REM */ 
		static int TRANSITION_PROPERTY; /* REM */ 
		static int TRANSITION_TIMING_FUNCTION; /* REM */ 
		static int TRANSITION; /* REM */ 
		static int TRANSFORM_ORIGIN; /* REM */ 
		static int TRANSFORM; /* REM */ 
		static int BORDER_TOP_WIDTH; /* REM */ 
		static int BORDER_RIGHT_WIDTH; /* REM */ 
		static int BORDER_BOTTOM_WIDTH; /* REM */ 
		static int BORDER_LEFT_WIDTH; /* REM */ 
		static int BORDER_WIDTH; /* REM */ 
		static int BORDER_TOP_COLOR; /* REM */ 
		static int BORDER_RIGHT_COLOR; /* REM */ 
		static int BORDER_BOTTOM_COLOR; /* REM */ 
		static int BORDER_LEFT_COLOR; /* REM */ 
		static int BORDER_COLOR; /* REM */ 
		static int BORDER_TOP_STYLE; /* REM */ 
		static int BORDER_RIGHT_STYLE; /* REM */ 
		static int BORDER_BOTTOM_STYLE; /* REM */ 
		static int BORDER_LEFT_STYLE; /* REM */ 
		static int BORDER_STYLE; /* REM */ 
		static int BORDER_TOP; /* REM */ 
		static int BORDER_RIGHT; /* REM */ 
		static int BORDER_BOTTOM; /* REM */ 
		static int BORDER_LEFT; /* REM */ 
		static int BORDER; /* REM */ 
		static int OUTLINE_WIDTH; /* REM */ 
		static int OUTLINE_STYLE; /* REM */ 
		static int OUTLINE_COLOR; /* REM */ 
		static int OUTLINE; /* REM */ 
		static int TEXT_DECORATION; /* REM */ 
		static ::String IMPORTANT; /* REM */ 
		static ::String AUTO; /* REM */ 
		static ::String LEFT_IDENT; /* REM */ 
		static ::String TOP_IDENT; /* REM */ 
		static ::String RIGHT_IDENT; /* REM */ 
		static ::String BOTTOM_IDENT; /* REM */ 
		static ::String HEIGHT_IDL_NAME; /* REM */ 
		static ::String WIDTH_IDL_NAME; /* REM */ 
		static ::String MAX_WIDTH_IDL_NAME; /* REM */ 
		static ::String MIN_WIDTH_IDL_NAME; /* REM */ 
		static ::String MAX_HEIGHT_IDL_NAME; /* REM */ 
		static ::String CSS_MIME_TYPE; /* REM */ 
		static ::String STYLESHEET_REL; /* REM */ 
		static ::String DISPLAY_NAME; /* REM */ 
		static ::String POSITION_NAME; /* REM */ 
		static ::String FLOAT_NAME; /* REM */ 
		static ::String CLEAR_NAME; /* REM */ 
		static ::String Z_INDEX_NAME; /* REM */ 
		static ::String MARGIN_NAME; /* REM */ 
		static ::String MARGIN_LEFT_NAME; /* REM */ 
		static ::String MARGIN_RIGHT_NAME; /* REM */ 
		static ::String MARGIN_TOP_NAME; /* REM */ 
		static ::String MARGIN_BOTTOM_NAME; /* REM */ 
		static ::String PADDING_NAME; /* REM */ 
		static ::String PADDING_LEFT_NAME; /* REM */ 
		static ::String PADDING_RIGHT_NAME; /* REM */ 
		static ::String PADDING_TOP_NAME; /* REM */ 
		static ::String PADDING_BOTTOM_NAME; /* REM */ 
		static ::String WIDTH_NAME; /* REM */ 
		static ::String HEIGHT_NAME; /* REM */ 
		static ::String MIN_HEIGHT_NAME; /* REM */ 
		static ::String MAX_HEIGHT_NAME; /* REM */ 
		static ::String MIN_WIDTH_NAME; /* REM */ 
		static ::String MAX_WIDTH_NAME; /* REM */ 
		static ::String TOP_NAME; /* REM */ 
		static ::String LEFT_NAME; /* REM */ 
		static ::String RIGHT_NAME; /* REM */ 
		static ::String BOTTOM_NAME; /* REM */ 
		static ::String BACKGROUND_COLOR_NAME; /* REM */ 
		static ::String BACKGROUND_IMAGE_NAME; /* REM */ 
		static ::String BACKGROUND_REPEAT_NAME; /* REM */ 
		static ::String BACKGROUND_ORIGIN_NAME; /* REM */ 
		static ::String BACKGROUND_SIZE_NAME; /* REM */ 
		static ::String BACKGROUND_POSITION_NAME; /* REM */ 
		static ::String BACKGROUND_CLIP_NAME; /* REM */ 
		static ::String BACKGROUND_ATTACHMENT_NAME; /* REM */ 
		static ::String BACKGROUND_NAME; /* REM */ 
		static ::String FONT_SIZE_NAME; /* REM */ 
		static ::String FONT_WEIGHT_NAME; /* REM */ 
		static ::String FONT_STYLE_NAME; /* REM */ 
		static ::String FONT_FAMILY_NAME; /* REM */ 
		static ::String FONT_VARIANT_NAME; /* REM */ 
		static ::String FONT_NAME; /* REM */ 
		static ::String COLOR_NAME; /* REM */ 
		static ::String LINE_HEIGHT_NAME; /* REM */ 
		static ::String TEXT_TRANSFORM_NAME; /* REM */ 
		static ::String LETTER_SPACING_NAME; /* REM */ 
		static ::String WORD_SPACING_NAME; /* REM */ 
		static ::String WHITE_SPACE_NAME; /* REM */ 
		static ::String TEXT_ALIGN_NAME; /* REM */ 
		static ::String TEXT_INDENT_NAME; /* REM */ 
		static ::String VERTICAL_ALIGN_NAME; /* REM */ 
		static ::String VISIBILITY_NAME; /* REM */ 
		static ::String CSS_OVERFLOW_NAME; /* REM */ 
		static ::String OVERFLOW_X_NAME; /* REM */ 
		static ::String OVERFLOW_Y_NAME; /* REM */ 
		static ::String OPACITY_NAME; /* REM */ 
		static ::String CURSOR_NAME; /* REM */ 
		static ::String TRANSITION_DURATION_NAME; /* REM */ 
		static ::String TRANSITION_DELAY_NAME; /* REM */ 
		static ::String TRANSITION_PROPERTY_NAME; /* REM */ 
		static ::String TRANSITION_TIMING_FUNCTION_NAME; /* REM */ 
		static ::String TRANSITION_NAME; /* REM */ 
		static ::String TRANSFORM_ORIGIN_NAME; /* REM */ 
		static ::String TRANSFORM_NAME; /* REM */ 
		static ::String BORDER_TOP_WIDTH_NAME; /* REM */ 
		static ::String BORDER_RIGHT_WIDTH_NAME; /* REM */ 
		static ::String BORDER_BOTTOM_WIDTH_NAME; /* REM */ 
		static ::String BORDER_LEFT_WIDTH_NAME; /* REM */ 
		static ::String BORDER_WIDTH_NAME; /* REM */ 
		static ::String BORDER_TOP_COLOR_NAME; /* REM */ 
		static ::String BORDER_RIGHT_COLOR_NAME; /* REM */ 
		static ::String BORDER_BOTTOM_COLOR_NAME; /* REM */ 
		static ::String BORDER_LEFT_COLOR_NAME; /* REM */ 
		static ::String BORDER_COLOR_NAME; /* REM */ 
		static ::String BORDER_TOP_STYLE_NAME; /* REM */ 
		static ::String BORDER_RIGHT_STYLE_NAME; /* REM */ 
		static ::String BORDER_BOTTOM_STYLE_NAME; /* REM */ 
		static ::String BORDER_LEFT_STYLE_NAME; /* REM */ 
		static ::String BORDER_STYLE_NAME; /* REM */ 
		static ::String BORDER_TOP_NAME; /* REM */ 
		static ::String BORDER_RIGHT_NAME; /* REM */ 
		static ::String BORDER_BOTTOM_NAME; /* REM */ 
		static ::String BORDER_LEFT_NAME; /* REM */ 
		static ::String BORDER_NAME; /* REM */ 
		static ::String OUTLINE_WIDTH_NAME; /* REM */ 
		static ::String OUTLINE_STYLE_NAME; /* REM */ 
		static ::String OUTLINE_COLOR_NAME; /* REM */ 
		static ::String OUTLINE_NAME; /* REM */ 
		static ::String TEXT_DECORATION_NAME; /* REM */ 
		static int getPropertyIndexFromName( ::String name);
		static Dynamic getPropertyIndexFromName_dyn();

		static ::String getPropertyNameFromIndex( int index);
		static Dynamic getPropertyNameFromIndex_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSConstants */ 
