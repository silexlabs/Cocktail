#ifndef INCLUDED_cocktail_core_linebox_TextInlineBox
#define INCLUDED_cocktail_core_linebox_TextInlineBox

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/linebox/InlineBox.h>
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,font,FontManager)
HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,linebox,TextInlineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextBase)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,NativeText)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
namespace cocktail{
namespace core{
namespace linebox{


class TextInlineBox_obj : public ::cocktail::core::linebox::InlineBox_obj{
	public:
		typedef ::cocktail::core::linebox::InlineBox_obj super;
		typedef TextInlineBox_obj OBJ_;
		TextInlineBox_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent,::String text,::cocktail::core::font::FontMetricsVO fontMetrics,::cocktail::core::font::FontManager fontManager,::String fontFamily);

	public:
		static hx::ObjectPtr< TextInlineBox_obj > __new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent,::String text,::cocktail::core::font::FontMetricsVO fontMetrics,::cocktail::core::font::FontManager fontManager,::String fontFamily);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextInlineBox_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextInlineBox"); }

		virtual Float getTextHeight( );
		Dynamic getTextHeight_dyn();

		virtual Float getTextWidth( );
		Dynamic getTextWidth_dyn();

		virtual ::neash::display::BitmapData get_nativeTextBitmap( );
		Dynamic get_nativeTextBitmap_dyn();

		virtual Void initTextBitmap( );
		Dynamic initTextBitmap_dyn();

		virtual Void initNativeTextElement( ::String text,::cocktail::core::font::FontManager fontManager,::cocktail::core::css::CoreStyle style,::String fontFamily);
		Dynamic initNativeTextElement_dyn();

		virtual Void dispose( );

		::String _text; /* REM */ 
		::neash::display::BitmapData nativeTextBitmap; /* REM */ 
		::cocktail::port::platform::nme::NativeText _nativeText; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _bitmapBounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace linebox

#endif /* INCLUDED_cocktail_core_linebox_TextInlineBox */ 
