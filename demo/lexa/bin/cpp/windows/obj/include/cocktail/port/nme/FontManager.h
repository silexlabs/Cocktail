#ifndef INCLUDED_cocktail_port_nme_FontManager
#define INCLUDED_cocktail_port_nme_FontManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/font/AbstractFontManager.h>
HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontManager)
HX_DECLARE_CLASS3(cocktail,port,nme,FontManager)
HX_DECLARE_CLASS2(nme,text,TextFormat)
namespace cocktail{
namespace port{
namespace nme{


class FontManager_obj : public ::cocktail::core::font::AbstractFontManager_obj{
	public:
		typedef ::cocktail::core::font::AbstractFontManager_obj super;
		typedef FontManager_obj OBJ_;
		FontManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FontManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FontManager"); }

		virtual Dynamic getFontMetrics( ::String fontFamily,double fontSize);
		Dynamic getFontMetrics_dyn();

		virtual Dynamic createNativeTextElement( ::String text,Dynamic computedStyle);
		Dynamic createNativeTextElement_dyn();

		virtual ::String getNativeFontFamily( Array< ::String > value);
		Dynamic getNativeFontFamily_dyn();

		virtual ::nme::text::TextFormat getTextFormat( Dynamic computedStyle);
		Dynamic getTextFormat_dyn();

		static ::String SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_GENERIC_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_FLASH_FONT_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace nme

#endif /* INCLUDED_cocktail_port_nme_FontManager */ 
