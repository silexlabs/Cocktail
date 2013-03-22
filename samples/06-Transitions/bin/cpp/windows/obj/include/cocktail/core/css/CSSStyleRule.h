#ifndef INCLUDED_cocktail_core_css_CSSStyleRule
#define INCLUDED_cocktail_core_css_CSSStyleRule

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/css/CSSRule.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorVO)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,CSSSelectorParser)
namespace cocktail{
namespace core{
namespace css{


class CSSStyleRule_obj : public ::cocktail::core::css::CSSRule_obj{
	public:
		typedef ::cocktail::core::css::CSSRule_obj super;
		typedef CSSStyleRule_obj OBJ_;
		CSSStyleRule_obj();
		Void __construct(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule);

	public:
		static hx::ObjectPtr< CSSStyleRule_obj > __new(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSStyleRule_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSStyleRule"); }

		virtual ::String set_selectorText( ::String value);
		Dynamic set_selectorText_dyn();

		virtual ::String get_selectorText( );
		Dynamic get_selectorText_dyn();

		virtual ::String get_cssText( );

		virtual ::String set_cssText( ::String value);

		virtual ::String serializeSelectors( Array< ::cocktail::core::css::SelectorVO > selectors);
		Dynamic serializeSelectors_dyn();

		virtual ::String serializeStyleRule( );
		Dynamic serializeStyleRule_dyn();

		virtual Void parse( ::String css);
		Dynamic parse_dyn();

		::cocktail::core::css::parsers::CSSSelectorParser _selectorParser; /* REM */ 
		::cocktail::core::css::CSSStyleDeclaration style; /* REM */ 
		Array< ::cocktail::core::css::SelectorVO > selectors; /* REM */ 
		::String selectorText; /* REM */ 
		static bool isSelectorChar( int c);
		static Dynamic isSelectorChar_dyn();

		static bool isStyleChar( int c);
		static Dynamic isStyleChar_dyn();

		static bool isAsciiChar( int c);
		static Dynamic isAsciiChar_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSStyleRule */ 
