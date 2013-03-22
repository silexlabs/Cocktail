#ifndef INCLUDED_cocktail_core_css_parsers_CSSRulesParser
#define INCLUDED_cocktail_core_css_parsers_CSSRulesParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,CSSRulesParser)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class CSSRulesParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSRulesParser_obj OBJ_;
		CSSRulesParser_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CSSRulesParser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSRulesParser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSRulesParser"); }

		virtual ::cocktail::core::css::CSSRule parseRule( ::String rule,::cocktail::core::css::CSSStyleSheet parentSyleSheet);
		Dynamic parseRule_dyn();

		virtual Array< ::String > parseRules( ::String css);
		Dynamic parseRules_dyn();

		static bool isValidChar( int c);
		static Dynamic isValidChar_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_CSSRulesParser */ 
