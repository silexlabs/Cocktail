#ifndef INCLUDED_cocktail_core_html_HTMLHtmlElement
#define INCLUDED_cocktail_core_html_HTMLHtmlElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLHtmlElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLHtmlElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLHtmlElement_obj OBJ_;
		HTMLHtmlElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLHtmlElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLHtmlElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLHtmlElement"); }

		static ::String HTML_HTML_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLHtmlElement */ 
