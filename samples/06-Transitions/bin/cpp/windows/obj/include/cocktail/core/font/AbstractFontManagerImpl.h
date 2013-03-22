#ifndef INCLUDED_cocktail_core_font_AbstractFontManagerImpl
#define INCLUDED_cocktail_core_font_AbstractFontManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
namespace cocktail{
namespace core{
namespace font{


class AbstractFontManagerImpl_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractFontManagerImpl_obj OBJ_;
		AbstractFontManagerImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractFontManagerImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractFontManagerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractFontManagerImpl"); }

		virtual ::cocktail::core::font::FontMetricsVO doGetFontMetrics( ::String fontFamily,Float fontSize);
		Dynamic doGetFontMetrics_dyn();

		virtual ::String getNativeFontFamily( Array< ::String > fontFamily);
		Dynamic getNativeFontFamily_dyn();

		virtual Dynamic createNativeTextElement( ::String text,::cocktail::core::css::CoreStyle style,::String fontFamily);
		Dynamic createNativeTextElement_dyn();

		virtual ::cocktail::core::font::FontMetricsVO getFontMetrics( ::String fontFamily,Float fontSize);
		Dynamic getFontMetrics_dyn();

		::Hash _computedFontMetrics; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace font

#endif /* INCLUDED_cocktail_core_font_AbstractFontManagerImpl */ 
