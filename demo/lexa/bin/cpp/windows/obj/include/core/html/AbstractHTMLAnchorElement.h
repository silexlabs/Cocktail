#ifndef INCLUDED_core_html_AbstractHTMLAnchorElement
#define INCLUDED_core_html_AbstractHTMLAnchorElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/HTMLElement.h>
HX_DECLARE_CLASS2(core,dom,AnchorTarget)
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,event,MouseEvent)
HX_DECLARE_CLASS2(core,event,UIEvent)
HX_DECLARE_CLASS2(core,html,AbstractHTMLAnchorElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace html{


class AbstractHTMLAnchorElement_obj : public ::port::flash_player::HTMLElement_obj{
	public:
		typedef ::port::flash_player::HTMLElement_obj super;
		typedef AbstractHTMLAnchorElement_obj OBJ_;
		AbstractHTMLAnchorElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractHTMLAnchorElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractHTMLAnchorElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractHTMLAnchorElement"); }

		::String _href; /* REM */ 
		::String href; /* REM */ 
		::core::dom::AnchorTarget _target; /* REM */ 
		::core::dom::AnchorTarget target; /* REM */ 
		virtual Void initNativeElement( );
		Dynamic initNativeElement_dyn();

		virtual Dynamic set_onMouseDown( Dynamic value);
		Dynamic set_onMouseDown_dyn();

		virtual Dynamic set_onMouseOver( Dynamic value);
		Dynamic set_onMouseOver_dyn();

		virtual Dynamic set_onMouseOut( Dynamic value);
		Dynamic set_onMouseOut_dyn();

		virtual Void onMouseDownCallback( ::core::event::MouseEvent mouseEvent);
		Dynamic onMouseDownCallback_dyn();

		virtual Void onMouseOverCallback( ::core::event::MouseEvent mouseEvent);
		Dynamic onMouseOverCallback_dyn();

		virtual Void onMouseOutCallback( ::core::event::MouseEvent mouseEvent);
		Dynamic onMouseOutCallback_dyn();

		virtual Void openDocument( );
		Dynamic openDocument_dyn();

		virtual Void displayPointerCursor( );
		Dynamic displayPointerCursor_dyn();

		virtual Void hidePointerCursor( );
		Dynamic hidePointerCursor_dyn();

		virtual ::String getTargetAsString( ::core::dom::AnchorTarget value);
		Dynamic getTargetAsString_dyn();

		virtual ::String set_href( ::String value);
		Dynamic set_href_dyn();

		virtual ::String get_href( );
		Dynamic get_href_dyn();

		virtual ::core::dom::AnchorTarget set_target( ::core::dom::AnchorTarget value);
		Dynamic set_target_dyn();

		virtual ::core::dom::AnchorTarget get_target( );
		Dynamic get_target_dyn();

		static ::String HTML_ANCHOR_TAG_NAME; /* REM */ 
};

} // end namespace core
} // end namespace html

#endif /* INCLUDED_core_html_AbstractHTMLAnchorElement */ 
