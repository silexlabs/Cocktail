#ifndef INCLUDED_cocktail_core_css_StyleSheet
#define INCLUDED_cocktail_core_css_StyleSheet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,MediaList)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace css{


class StyleSheet_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StyleSheet_obj OBJ_;
		StyleSheet_obj();
		Void __construct(::String stylesheet,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet);

	public:
		static hx::ObjectPtr< StyleSheet_obj > __new(::String stylesheet,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StyleSheet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StyleSheet"); }

		bool disabled; /* REM */ 
		::cocktail::core::css::MediaList media; /* REM */ 
		::String title; /* REM */ 
		::cocktail::core::css::StyleSheet parentStyleSheet; /* REM */ 
		::cocktail::core::html::HTMLElement ownerNode; /* REM */ 
		::String href; /* REM */ 
		::String type; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_StyleSheet */ 
