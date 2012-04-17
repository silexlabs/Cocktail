#ifndef INCLUDED_cocktail_core_html_AbstractHTMLAnchorElement
#define INCLUDED_cocktail_core_html_AbstractHTMLAnchorElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/flash_player/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLAnchorElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class AbstractHTMLAnchorElement_obj : public ::cocktail::port::flash_player::HTMLElement_obj{
	public:
		typedef ::cocktail::port::flash_player::HTMLElement_obj super;
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
		::String _target; /* REM */ 
		::String target; /* REM */ 
		virtual Void initNativeElement( );
		Dynamic initNativeElement_dyn();

		virtual Dynamic set_onMouseDown( Dynamic value);
		Dynamic set_onMouseDown_dyn();

		virtual Dynamic set_onMouseOver( Dynamic value);
		Dynamic set_onMouseOver_dyn();

		virtual Dynamic set_onMouseOut( Dynamic value);
		Dynamic set_onMouseOut_dyn();

		virtual Void onMouseDownCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseDownCallback_dyn();

		virtual Void onMouseOverCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseOverCallback_dyn();

		virtual Void onMouseOutCallback( ::cocktail::core::event::MouseEvent mouseEvent);
		Dynamic onMouseOutCallback_dyn();

		virtual Void openDocument( );
		Dynamic openDocument_dyn();

		virtual Void displayPointerCursor( );
		Dynamic displayPointerCursor_dyn();

		virtual Void hidePointerCursor( );
		Dynamic hidePointerCursor_dyn();

		virtual ::String set_href( ::String value);
		Dynamic set_href_dyn();

		virtual ::String get_href( );
		Dynamic get_href_dyn();

		virtual ::String set_target( ::String value);
		Dynamic set_target_dyn();

		virtual ::String get_target( );
		Dynamic get_target_dyn();

		static ::String TARGET_BLANK; /* REM */ 
		static ::String TARGET_SELF; /* REM */ 
		static ::String TARGET_PARENT; /* REM */ 
		static ::String TARGET_TOP; /* REM */ 
		static ::String HTML_ANCHOR_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_AbstractHTMLAnchorElement */ 
