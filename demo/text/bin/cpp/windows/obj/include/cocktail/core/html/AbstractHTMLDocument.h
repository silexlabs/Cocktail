#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#define INCLUDED_cocktail_core_html_AbstractHTMLDocument

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Document.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,focus,FocusManager)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLBodyElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,keyboard,AbstractKeyboard)
HX_DECLARE_CLASS3(cocktail,core,window,AbstractWindow)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Keyboard)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Window)
namespace cocktail{
namespace core{
namespace html{


class AbstractHTMLDocument_obj : public ::cocktail::core::dom::Document_obj{
	public:
		typedef ::cocktail::core::dom::Document_obj super;
		typedef AbstractHTMLDocument_obj OBJ_;
		AbstractHTMLDocument_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractHTMLDocument_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractHTMLDocument_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractHTMLDocument"); }

		::cocktail::core::html::HTMLBodyElement _body; /* REM */ 
		::cocktail::core::html::HTMLBodyElement body; /* REM */ 
		::cocktail::port::flash_player::Window _window; /* REM */ 
		Dynamic _nativeElements; /* REM */ 
		::cocktail::core::html::HTMLElement _activeElement; /* REM */ 
		::cocktail::core::html::HTMLElement activeElement; /* REM */ 
		::cocktail::core::focus::FocusManager _focusManager; /* REM */ 
		::cocktail::port::flash_player::Keyboard _keyboard; /* REM */ 
		virtual Void initKeyboardListeners( );
		Dynamic initKeyboardListeners_dyn();

		virtual ::cocktail::core::html::HTMLElement createElement( ::String tagName);
		Dynamic createElement_dyn();

		virtual Void invalidate( Dynamic immediate);
		Dynamic invalidate_dyn();

		virtual Void onKeyDown( ::cocktail::core::event::KeyboardEvent keyboardEvent);
		Dynamic onKeyDown_dyn();

		virtual Void onKeyUp( ::cocktail::core::event::KeyboardEvent keyEventData);
		Dynamic onKeyUp_dyn();

		virtual Void layoutAndRender( );
		Dynamic layoutAndRender_dyn();

		virtual Void layout( );
		Dynamic layout_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual Void attachNativeElement( Dynamic nativeElement);
		Dynamic attachNativeElement_dyn();

		virtual Void detachNativeElement( Dynamic nativeElement);
		Dynamic detachNativeElement_dyn();

		virtual Void attachNativeElements( Dynamic nativeElements);
		Dynamic attachNativeElements_dyn();

		virtual Void detachNativeElements( Dynamic nativeElements);
		Dynamic detachNativeElements_dyn();

		virtual Void scheduleLayoutAndRender( );
		Dynamic scheduleLayoutAndRender_dyn();

		virtual Void onWindowResize( ::cocktail::core::event::Event event);
		Dynamic onWindowResize_dyn();

		virtual ::cocktail::core::html::HTMLBodyElement get_body( );
		Dynamic get_body_dyn();

		virtual ::cocktail::core::html::HTMLElement set_activeElement( ::cocktail::core::html::HTMLElement value);
		Dynamic set_activeElement_dyn();

		virtual ::cocktail::core::html::HTMLElement get_activeElement( );
		Dynamic get_activeElement_dyn();

		static ::String HTML_IMAGE_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_CANVAS_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_INPUT_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_ANCHOR_ELEMENT_TAG_NAME; /* REM */ 
		static ::String HTML_HTML_TAG_NAME; /* REM */ 
		static ::String HTML_BODY_TAG_NAME; /* REM */ 
		static int TAB_KEY_CODE; /* REM */ 
		static int ENTER_KEY_CODE; /* REM */ 
		static int SPACE_KEY_CODE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_AbstractHTMLDocument */ 
