#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#define INCLUDED_cocktail_core_css_CSSStyleSheet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/css/StyleSheet.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,PropertyOriginValue)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,CSSRulesParser)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace css{


class CSSStyleSheet_obj : public ::cocktail::core::css::StyleSheet_obj{
	public:
		typedef ::cocktail::core::css::StyleSheet_obj super;
		typedef CSSStyleSheet_obj OBJ_;
		CSSStyleSheet_obj();
		Void __construct(::String stylesheet,::cocktail::core::css::PropertyOriginValue origin,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet,::cocktail::core::css::CSSRule ownerRule);

	public:
		static hx::ObjectPtr< CSSStyleSheet_obj > __new(::String stylesheet,::cocktail::core::css::PropertyOriginValue origin,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet,::cocktail::core::css::CSSRule ownerRule);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSStyleSheet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSStyleSheet"); }

		virtual Void deleteRule( int index);
		Dynamic deleteRule_dyn();

		virtual int insertRule( ::String rule,int index);
		Dynamic insertRule_dyn();

		::cocktail::core::css::PropertyOriginValue origin; /* REM */ 
		::cocktail::core::css::parsers::CSSRulesParser _cssRulesParser; /* REM */ 
		Array< ::cocktail::core::css::CSSRule > cssRules; /* REM */ 
		::cocktail::core::css::CSSRule ownerRule; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSStyleSheet */ 
