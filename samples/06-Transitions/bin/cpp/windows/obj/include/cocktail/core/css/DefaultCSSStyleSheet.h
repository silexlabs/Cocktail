#ifndef INCLUDED_cocktail_core_css_DefaultCSSStyleSheet
#define INCLUDED_cocktail_core_css_DefaultCSSStyleSheet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/css/CSSStyleSheet.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,DefaultCSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
namespace cocktail{
namespace core{
namespace css{


class DefaultCSSStyleSheet_obj : public ::cocktail::core::css::CSSStyleSheet_obj{
	public:
		typedef ::cocktail::core::css::CSSStyleSheet_obj super;
		typedef DefaultCSSStyleSheet_obj OBJ_;
		DefaultCSSStyleSheet_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DefaultCSSStyleSheet_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DefaultCSSStyleSheet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DefaultCSSStyleSheet"); }

		virtual ::String getDefaultStyleSheet( );
		Dynamic getDefaultStyleSheet_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_DefaultCSSStyleSheet */ 
