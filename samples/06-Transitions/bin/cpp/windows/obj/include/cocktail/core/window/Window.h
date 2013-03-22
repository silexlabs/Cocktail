#ifndef INCLUDED_cocktail_core_window_Window
#define INCLUDED_cocktail_core_window_Window

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/EventCallback.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,history,History)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,window,Window)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
namespace cocktail{
namespace core{
namespace window{


class Window_obj : public ::cocktail::core::event::EventCallback_obj{
	public:
		typedef ::cocktail::core::event::EventCallback_obj super;
		typedef Window_obj OBJ_;
		Window_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Window_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Window_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Window"); }

		virtual int get_innerWidth( );
		Dynamic get_innerWidth_dyn();

		virtual int get_innerHeight( );
		Dynamic get_innerHeight_dyn();

		virtual Void onPlatformOrientationChangeEvent( ::cocktail::core::event::Event e);
		Dynamic onPlatformOrientationChangeEvent_dyn();

		virtual Void onPlatformResizeEvent( ::cocktail::core::event::UIEvent e);
		Dynamic onPlatformResizeEvent_dyn();

		virtual Void onDocumentSetMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor);
		Dynamic onDocumentSetMouseCursor_dyn();

		virtual Void onDocumentExitFullscreen( );
		Dynamic onDocumentExitFullscreen_dyn();

		virtual Void onDocumentEnterFullscreen( );
		Dynamic onDocumentEnterFullscreen_dyn();

		virtual Void onPlatformFullScreenChange( ::cocktail::core::event::Event event);
		Dynamic onPlatformFullScreenChange_dyn();

		virtual Void open( ::String url,::String name);
		Dynamic open_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		::cocktail::core::css::CSSPropertyValue _currentMouseCursor; /* REM */ 
		::cocktail::core::history::History history; /* REM */ 
		::cocktail::port::platform::flash_player::Platform platform; /* REM */ 
		int innerWidth; /* REM */ 
		int innerHeight; /* REM */ 
		::cocktail::core::html::HTMLDocument document; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace window

#endif /* INCLUDED_cocktail_core_window_Window */ 
