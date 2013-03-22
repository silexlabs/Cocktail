#ifndef INCLUDED_cocktail_port_platform_nme_FontManagerImpl
#define INCLUDED_cocktail_port_platform_nme_FontManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/font/AbstractFontManagerImpl.h>
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,FontManagerImpl)
HX_DECLARE_CLASS2(neash,text,TextFormat)
namespace cocktail{
namespace port{
namespace platform{
namespace nme{


class FontManagerImpl_obj : public ::cocktail::core::font::AbstractFontManagerImpl_obj{
	public:
		typedef ::cocktail::core::font::AbstractFontManagerImpl_obj super;
		typedef FontManagerImpl_obj OBJ_;
		FontManagerImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FontManagerImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontManagerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FontManagerImpl"); }

		virtual ::neash::text::TextFormat getTextFormat( ::cocktail::core::css::CoreStyle style,::String fontFamily);
		Dynamic getTextFormat_dyn();

		virtual ::String getNativeFontFamily( Array< ::String > value);

		virtual Dynamic createNativeTextElement( ::String text,::cocktail::core::css::CoreStyle style,::String fontFamily);

		virtual ::cocktail::core::font::FontMetricsVO getFontMetrics( ::String fontFamily,Float fontSize);

		static ::String SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_GENERIC_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_FLASH_FONT_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_cocktail_port_platform_nme_FontManagerImpl */ 
