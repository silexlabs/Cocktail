#ifndef INCLUDED_cocktail_core_html_HTMLStyleElement
#define INCLUDED_cocktail_core_html_HTMLStyleElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLStyleElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLStyleElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLStyleElement_obj OBJ_;
		HTMLStyleElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLStyleElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLStyleElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLStyleElement"); }

		virtual bool set_disabled( bool value);
		Dynamic set_disabled_dyn();

		virtual bool get_disabled( );
		Dynamic get_disabled_dyn();

		virtual Void createElementRenderer( );

		virtual ::String concatenateChildTextNode( );
		Dynamic concatenateChildTextNode_dyn();

		virtual Void removeStyleSheet( );
		Dynamic removeStyleSheet_dyn();

		virtual Void updateStyleSheet( );
		Dynamic updateStyleSheet_dyn();

		virtual Void removedFromDOM( );

		virtual Void addedToDOM( );

		virtual Dynamic insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild);

		virtual Dynamic removeChild( Dynamic _tmp_oldChild);

		virtual Dynamic appendChild( Dynamic _tmp_newChild);

		::cocktail::core::css::CSSStyleSheet sheet; /* REM */ 
		bool disabled; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLStyleElement */ 
