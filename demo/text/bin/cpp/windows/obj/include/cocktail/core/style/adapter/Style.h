#ifndef INCLUDED_cocktail_core_style_adapter_Style
#define INCLUDED_cocktail_core_style_adapter_Style

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS4(cocktail,core,style,adapter,Style)
namespace cocktail{
namespace core{
namespace style{
namespace adapter{


class Style_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Style_obj OBJ_;
		Style_obj();
		Void __construct(::cocktail::core::style::CoreStyle coreStyle);

	public:
		static hx::ObjectPtr< Style_obj > __new(::cocktail::core::style::CoreStyle coreStyle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Style_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Style"); }

		::String display; /* REM */ 
		::String position; /* REM */ 
		::String cssFloat; /* REM */ 
		::String clear; /* REM */ 
		::String marginLeft; /* REM */ 
		::String marginRight; /* REM */ 
		::String marginTop; /* REM */ 
		::String marginBottom; /* REM */ 
		::String paddingLeft; /* REM */ 
		::String paddingRight; /* REM */ 
		::String paddingTop; /* REM */ 
		::String paddingBottom; /* REM */ 
		::String width; /* REM */ 
		::String height; /* REM */ 
		::String minHeight; /* REM */ 
		::String maxHeight; /* REM */ 
		::String minWidth; /* REM */ 
		::String maxWidth; /* REM */ 
		::String top; /* REM */ 
		::String left; /* REM */ 
		::String bottom; /* REM */ 
		::String right; /* REM */ 
		::String backgroundColor; /* REM */ 
		::String backgroundImage; /* REM */ 
		::String backgroundRepeat; /* REM */ 
		::String backgroundOrigin; /* REM */ 
		::String backgroundSize; /* REM */ 
		::String backgroundPosition; /* REM */ 
		::String backgroundClip; /* REM */ 
		::String fontSize; /* REM */ 
		::String fontWeight; /* REM */ 
		::String fontStyle; /* REM */ 
		::String fontFamily; /* REM */ 
		::String fontVariant; /* REM */ 
		::String color; /* REM */ 
		::String lineHeight; /* REM */ 
		::String textTransform; /* REM */ 
		::String letterSpacing; /* REM */ 
		::String wordSpacing; /* REM */ 
		::String whiteSpace; /* REM */ 
		::String textAlign; /* REM */ 
		::String textIndent; /* REM */ 
		::String verticalAlign; /* REM */ 
		::String opacity; /* REM */ 
		::String visibility; /* REM */ 
		::String overflowX; /* REM */ 
		::String overflowY; /* REM */ 
		::String cursor; /* REM */ 
		::cocktail::core::style::CoreStyle _coreStyle; /* REM */ 
		virtual ::String get_opacity( );
		Dynamic get_opacity_dyn();

		virtual ::String set_opacity( ::String value);
		Dynamic set_opacity_dyn();

		virtual ::String get_visibility( );
		Dynamic get_visibility_dyn();

		virtual ::String set_visibility( ::String value);
		Dynamic set_visibility_dyn();

		virtual ::String get_marginLeft( );
		Dynamic get_marginLeft_dyn();

		virtual ::String set_marginLeft( ::String value);
		Dynamic set_marginLeft_dyn();

		virtual ::String get_marginRight( );
		Dynamic get_marginRight_dyn();

		virtual ::String set_marginRight( ::String value);
		Dynamic set_marginRight_dyn();

		virtual ::String get_marginTop( );
		Dynamic get_marginTop_dyn();

		virtual ::String set_marginTop( ::String value);
		Dynamic set_marginTop_dyn();

		virtual ::String get_marginBottom( );
		Dynamic get_marginBottom_dyn();

		virtual ::String set_marginBottom( ::String value);
		Dynamic set_marginBottom_dyn();

		virtual ::String get_paddingLeft( );
		Dynamic get_paddingLeft_dyn();

		virtual ::String set_paddingLeft( ::String value);
		Dynamic set_paddingLeft_dyn();

		virtual ::String get_paddingRight( );
		Dynamic get_paddingRight_dyn();

		virtual ::String set_paddingRight( ::String value);
		Dynamic set_paddingRight_dyn();

		virtual ::String get_paddingTop( );
		Dynamic get_paddingTop_dyn();

		virtual ::String set_paddingTop( ::String value);
		Dynamic set_paddingTop_dyn();

		virtual ::String get_paddingBottom( );
		Dynamic get_paddingBottom_dyn();

		virtual ::String set_paddingBottom( ::String value);
		Dynamic set_paddingBottom_dyn();

		virtual ::String get_display( );
		Dynamic get_display_dyn();

		virtual ::String set_display( ::String value);
		Dynamic set_display_dyn();

		virtual ::String get_position( );
		Dynamic get_position_dyn();

		virtual ::String set_position( ::String value);
		Dynamic set_position_dyn();

		virtual ::String get_width( );
		Dynamic get_width_dyn();

		virtual ::String set_width( ::String value);
		Dynamic set_width_dyn();

		virtual ::String get_height( );
		Dynamic get_height_dyn();

		virtual ::String set_height( ::String value);
		Dynamic set_height_dyn();

		virtual ::String get_minHeight( );
		Dynamic get_minHeight_dyn();

		virtual ::String set_minHeight( ::String value);
		Dynamic set_minHeight_dyn();

		virtual ::String get_maxHeight( );
		Dynamic get_maxHeight_dyn();

		virtual ::String set_maxHeight( ::String value);
		Dynamic set_maxHeight_dyn();

		virtual ::String get_minWidth( );
		Dynamic get_minWidth_dyn();

		virtual ::String set_minWidth( ::String value);
		Dynamic set_minWidth_dyn();

		virtual ::String get_maxWidth( );
		Dynamic get_maxWidth_dyn();

		virtual ::String set_maxWidth( ::String value);
		Dynamic set_maxWidth_dyn();

		virtual ::String get_top( );
		Dynamic get_top_dyn();

		virtual ::String set_top( ::String value);
		Dynamic set_top_dyn();

		virtual ::String get_left( );
		Dynamic get_left_dyn();

		virtual ::String set_left( ::String value);
		Dynamic set_left_dyn();

		virtual ::String get_bottom( );
		Dynamic get_bottom_dyn();

		virtual ::String set_bottom( ::String value);
		Dynamic set_bottom_dyn();

		virtual ::String get_right( );
		Dynamic get_right_dyn();

		virtual ::String set_right( ::String value);
		Dynamic set_right_dyn();

		virtual ::String get_CSSFloat( );
		Dynamic get_CSSFloat_dyn();

		virtual ::String set_CSSFloat( ::String value);
		Dynamic set_CSSFloat_dyn();

		virtual ::String get_clear( );
		Dynamic get_clear_dyn();

		virtual ::String set_clear( ::String value);
		Dynamic set_clear_dyn();

		virtual ::String get_fontSize( );
		Dynamic get_fontSize_dyn();

		virtual ::String set_fontSize( ::String value);
		Dynamic set_fontSize_dyn();

		virtual ::String get_fontWeight( );
		Dynamic get_fontWeight_dyn();

		virtual ::String set_fontWeight( ::String value);
		Dynamic set_fontWeight_dyn();

		virtual ::String get_fontStyle( );
		Dynamic get_fontStyle_dyn();

		virtual ::String set_fontStyle( ::String value);
		Dynamic set_fontStyle_dyn();

		virtual ::String get_fontFamily( );
		Dynamic get_fontFamily_dyn();

		virtual ::String set_fontFamily( ::String value);
		Dynamic set_fontFamily_dyn();

		virtual ::String get_fontVariant( );
		Dynamic get_fontVariant_dyn();

		virtual ::String set_fontVariant( ::String value);
		Dynamic set_fontVariant_dyn();

		virtual ::String get_textTransform( );
		Dynamic get_textTransform_dyn();

		virtual ::String set_textTransform( ::String value);
		Dynamic set_textTransform_dyn();

		virtual ::String get_letterSpacing( );
		Dynamic get_letterSpacing_dyn();

		virtual ::String set_letterSpacing( ::String value);
		Dynamic set_letterSpacing_dyn();

		virtual ::String get_color( );
		Dynamic get_color_dyn();

		virtual ::String set_color( ::String value);
		Dynamic set_color_dyn();

		virtual ::String get_wordSpacing( );
		Dynamic get_wordSpacing_dyn();

		virtual ::String set_wordSpacing( ::String value);
		Dynamic set_wordSpacing_dyn();

		virtual ::String get_lineHeight( );
		Dynamic get_lineHeight_dyn();

		virtual ::String set_lineHeight( ::String value);
		Dynamic set_lineHeight_dyn();

		virtual ::String get_verticalAlign( );
		Dynamic get_verticalAlign_dyn();

		virtual ::String set_verticalAlign( ::String value);
		Dynamic set_verticalAlign_dyn();

		virtual ::String get_textIndent( );
		Dynamic get_textIndent_dyn();

		virtual ::String set_textIndent( ::String value);
		Dynamic set_textIndent_dyn();

		virtual ::String get_whiteSpace( );
		Dynamic get_whiteSpace_dyn();

		virtual ::String set_whiteSpace( ::String value);
		Dynamic set_whiteSpace_dyn();

		virtual ::String get_textAlign( );
		Dynamic get_textAlign_dyn();

		virtual ::String set_textAlign( ::String value);
		Dynamic set_textAlign_dyn();

		virtual ::String set_backgroundColor( ::String value);
		Dynamic set_backgroundColor_dyn();

		virtual ::String get_backgroundColor( );
		Dynamic get_backgroundColor_dyn();

		virtual ::String set_backgroundImage( ::String value);
		Dynamic set_backgroundImage_dyn();

		virtual ::String get_backgroundImage( );
		Dynamic get_backgroundImage_dyn();

		virtual ::String set_backgroundRepeat( ::String value);
		Dynamic set_backgroundRepeat_dyn();

		virtual ::String get_backgroundRepeat( );
		Dynamic get_backgroundRepeat_dyn();

		virtual ::String set_backgroundSize( ::String value);
		Dynamic set_backgroundSize_dyn();

		virtual ::String get_backgroundSize( );
		Dynamic get_backgroundSize_dyn();

		virtual ::String set_backgroundClip( ::String value);
		Dynamic set_backgroundClip_dyn();

		virtual ::String get_backgroundClip( );
		Dynamic get_backgroundClip_dyn();

		virtual ::String set_backgroundPosition( ::String value);
		Dynamic set_backgroundPosition_dyn();

		virtual ::String get_backgroundPosition( );
		Dynamic get_backgroundPosition_dyn();

		virtual ::String set_backgroundOrigin( ::String value);
		Dynamic set_backgroundOrigin_dyn();

		virtual ::String get_backgroundOrigin( );
		Dynamic get_backgroundOrigin_dyn();

		virtual ::String get_overflowX( );
		Dynamic get_overflowX_dyn();

		virtual ::String set_overflowX( ::String value);
		Dynamic set_overflowX_dyn();

		virtual ::String get_overflowY( );
		Dynamic get_overflowY_dyn();

		virtual ::String set_overflowY( ::String value);
		Dynamic set_overflowY_dyn();

		virtual ::String set_cursor( ::String value);
		Dynamic set_cursor_dyn();

		virtual ::String get_cursor( );
		Dynamic get_cursor_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace adapter

#endif /* INCLUDED_cocktail_core_style_adapter_Style */ 
