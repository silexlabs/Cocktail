#ifndef INCLUDED_cocktail_core_font_FontManager
#define INCLUDED_cocktail_core_font_FontManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,font,FontManager)
HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,FontManagerImpl)
namespace cocktail{
namespace core{
namespace font{


class FontManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FontManager"); }

		virtual ::String getNativeFontFamily( Array< ::String > fontFamily);
		Dynamic getNativeFontFamily_dyn();

		virtual Dynamic createNativeTextElement( ::String text,::cocktail::core::css::CoreStyle style,::String fontFamily);
		Dynamic createNativeTextElement_dyn();

		virtual ::cocktail::core::font::FontMetricsVO getFontMetrics( ::String fontFamily,Float fontSize);
		Dynamic getFontMetrics_dyn();

		::cocktail::port::platform::nme::FontManagerImpl _fontManagerImpl; /* REM */ 
		static ::cocktail::core::font::FontManager _instance; /* REM */ 
		static ::cocktail::core::font::FontManager getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace font

#endif /* INCLUDED_cocktail_core_font_FontManager */ 
