#ifndef INCLUDED_cocktail_core_css_CSSMediaRule
#define INCLUDED_cocktail_core_css_CSSMediaRule

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/css/CSSRule.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSMediaRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,MediaList)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
namespace cocktail{
namespace core{
namespace css{


class CSSMediaRule_obj : public ::cocktail::core::css::CSSRule_obj{
	public:
		typedef ::cocktail::core::css::CSSRule_obj super;
		typedef CSSMediaRule_obj OBJ_;
		CSSMediaRule_obj();
		Void __construct(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule);

	public:
		static hx::ObjectPtr< CSSMediaRule_obj > __new(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSMediaRule_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSMediaRule"); }

		virtual Void deleteRule( int index);
		Dynamic deleteRule_dyn();

		virtual int insertRule( ::String rule,int index);
		Dynamic insertRule_dyn();

		Array< ::cocktail::core::css::CSSRule > cssRules; /* REM */ 
		::cocktail::core::css::MediaList media; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSMediaRule */ 
