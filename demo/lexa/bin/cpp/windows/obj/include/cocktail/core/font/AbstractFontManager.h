#ifndef INCLUDED_cocktail_core_font_AbstractFontManager
#define INCLUDED_cocktail_core_font_AbstractFontManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontLoader)
HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontManager)
HX_DECLARE_CLASS3(cocktail,core,style,TextTransform)
HX_DECLARE_CLASS3(cocktail,port,flash_player,FontLoader)
namespace cocktail{
namespace core{
namespace font{


class AbstractFontManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractFontManager_obj OBJ_;
		AbstractFontManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractFontManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractFontManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractFontManager"); }

		virtual Dynamic getEmbeddedFonts( );
		Dynamic getEmbeddedFonts_dyn();

		virtual Dynamic getSystemFonts( );
		Dynamic getSystemFonts_dyn();

		virtual bool hasFont( ::String fontName);
		Dynamic hasFont_dyn();

		virtual Dynamic getFontMetrics( ::String fontFamily,double fontSize);
		Dynamic getFontMetrics_dyn();

		virtual Dynamic createNativeTextElement( ::String text,Dynamic computedStyle);
		Dynamic createNativeTextElement_dyn();

		virtual ::String applyTextTransform( ::String text,::cocktail::core::style::TextTransform textTransform);
		Dynamic applyTextTransform_dyn();

		virtual ::String capitalizeText( ::String text);
		Dynamic capitalizeText_dyn();

		virtual Void loadFont( ::String url,::String name,Dynamic successCallback,Dynamic errorCallback);
		Dynamic loadFont_dyn();

		virtual Void _onFontLoadingSuccess( Dynamic fontData);
		Dynamic _onFontLoadingSuccess_dyn();

		virtual Void _onFontLoadingError( Dynamic fontData,::String errorStr);
		Dynamic _onFontLoadingError_dyn();

		virtual bool _removeFontLoader( Dynamic fontData);
		Dynamic _removeFontLoader_dyn();

		static Dynamic _loadedFonts; /* REM */ 
		static Array< ::cocktail::port::flash_player::FontLoader > _fontLoaderArray; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace font

#endif /* INCLUDED_cocktail_core_font_AbstractFontManager */ 
