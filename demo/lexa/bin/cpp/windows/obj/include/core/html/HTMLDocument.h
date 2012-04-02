#ifndef INCLUDED_core_html_HTMLDocument
#define INCLUDED_core_html_HTMLDocument

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/dom/Document.h>
HX_DECLARE_CLASS2(core,dom,Document)
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,HTMLDocument)
HX_DECLARE_CLASS2(core,window,AbstractWindow)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Window)
namespace core{
namespace html{


class HTMLDocument_obj : public ::core::dom::Document_obj{
	public:
		typedef ::core::dom::Document_obj super;
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

		::port::flash_player::HTMLElement _body; /* REM */ 
		::port::flash_player::HTMLElement body; /* REM */ 
		::port::flash_player::Window _window; /* REM */ 
		virtual ::core::dom::Element createElement( ::String tagName);
		Dynamic createElement_dyn();

		virtual Void onWindowResize( ::core::event::Event event);
		Dynamic onWindowResize_dyn();

		virtual ::port::flash_player::HTMLElement get_body( );
		Dynamic get_body_dyn();

		static ::String HTML_IMAGE_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_CANVAS_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_INPUT_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_ANCHOR_ELEMENT_TAG_NAME; /* REM */ 
};

} // end namespace core
} // end namespace html

#endif /* INCLUDED_core_html_HTMLDocument */ 
