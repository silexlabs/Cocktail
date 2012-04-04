#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#define INCLUDED_cocktail_core_html_HTMLDocument

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Document.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,window,AbstractWindow)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Window)
namespace cocktail{
namespace core{
namespace html{


class HTMLDocument_obj : public ::cocktail::core::dom::Document_obj{
	public:
		typedef ::cocktail::core::dom::Document_obj super;
		typedef HTMLDocument_obj OBJ_;
		HTMLDocument_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLDocument_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLDocument_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLDocument"); }

		::cocktail::port::flash_player::HTMLElement _body; /* REM */ 
		::cocktail::port::flash_player::HTMLElement body; /* REM */ 
		::cocktail::port::flash_player::Window _window; /* REM */ 
		virtual ::cocktail::port::flash_player::HTMLElement createElement( ::String tagName);
		Dynamic createElement_dyn();

		virtual Void onWindowResize( ::cocktail::core::event::Event event);
		Dynamic onWindowResize_dyn();

		virtual ::cocktail::port::flash_player::HTMLElement get_body( );
		Dynamic get_body_dyn();

		static ::String HTML_IMAGE_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_CANVAS_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_INPUT_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_ANCHOR_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_HTML_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLDocument */ 
