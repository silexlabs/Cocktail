#ifndef INCLUDED_core_html_HTMLBodyElement
#define INCLUDED_core_html_HTMLBodyElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/HTMLElement.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,HTMLBodyElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace html{


class HTMLBodyElement_obj : public ::port::flash_player::HTMLElement_obj{
	public:
		typedef ::port::flash_player::HTMLElement_obj super;
		typedef HTMLBodyElement_obj OBJ_;
		HTMLBodyElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLBodyElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLBodyElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLBodyElement"); }

		virtual Void initNativeElement( );
		Dynamic initNativeElement_dyn();

		virtual Void initStyle( );
		Dynamic initStyle_dyn();

		static ::String HTML_BODY_TAG_NAME; /* REM */ 
};

} // end namespace core
} // end namespace html

#endif /* INCLUDED_core_html_HTMLBodyElement */ 
