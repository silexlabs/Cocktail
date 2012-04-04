#ifndef INCLUDED_cocktail_core_html_AbstractHTMLHtmlElement
#define INCLUDED_cocktail_core_html_AbstractHTMLHtmlElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/flash_player/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLHtmlElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class AbstractHTMLHtmlElement_obj : public ::cocktail::port::flash_player::HTMLElement_obj{
	public:
		typedef ::cocktail::port::flash_player::HTMLElement_obj super;
		typedef AbstractHTMLHtmlElement_obj OBJ_;
		AbstractHTMLHtmlElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractHTMLHtmlElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractHTMLHtmlElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractHTMLHtmlElement"); }

		static ::String HTML_HTML_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_AbstractHTMLHtmlElement */ 
