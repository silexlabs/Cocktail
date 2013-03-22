#ifndef INCLUDED_cocktail_core_css_CSSRule
#define INCLUDED_cocktail_core_css_CSSRule

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
namespace cocktail{
namespace core{
namespace css{


class CSSRule_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSRule_obj OBJ_;
		CSSRule_obj();
		Void __construct(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule);

	public:
		static hx::ObjectPtr< CSSRule_obj > __new(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSRule_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSRule"); }

		virtual ::String set_cssText( ::String value);
		Dynamic set_cssText_dyn();

		virtual ::String get_cssText( );
		Dynamic get_cssText_dyn();

		::cocktail::core::css::CSSStyleSheet parentStyleSheet; /* REM */ 
		::cocktail::core::css::CSSRule parentRule; /* REM */ 
		::String cssText; /* REM */ 
		int type; /* REM */ 
		static int STYLE_RULE; /* REM */ 
		static int IMPORT_RULE; /* REM */ 
		static int MEDIA_RULE; /* REM */ 
		static int FONT_FACE_RULE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSRule */ 
