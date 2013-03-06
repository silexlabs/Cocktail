#ifndef INCLUDED_cocktail_port_base_PlatformBase
#define INCLUDED_cocktail_port_base_PlatformBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,stacking,StackingContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,port,base,KeyboardListenerBase)
HX_DECLARE_CLASS3(cocktail,port,base,MouseListenerBase)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS3(cocktail,port,base,TouchListenerBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Keyboard)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Mouse)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,TouchListener)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace cocktail{
namespace port{
namespace base{


class PlatformBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PlatformBase_obj OBJ_;
		PlatformBase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PlatformBase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PlatformBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlatformBase"); }

		virtual int get_innerWidth( );
		Dynamic get_innerWidth_dyn();

		virtual int get_innerHeight( );
		Dynamic get_innerHeight_dyn();

		virtual ::cocktail::core::event::Event getEvent( Dynamic event);
		Dynamic getEvent_dyn();

		virtual ::cocktail::core::event::UIEvent getUIEvent( Dynamic event);
		Dynamic getUIEvent_dyn();

		virtual Void removeNativeListeners( );
		Dynamic removeNativeListeners_dyn();

		virtual Void setNativeListeners( );
		Dynamic setNativeListeners_dyn();

		virtual Void onNativeOrientationChange( Dynamic event);
		Dynamic onNativeOrientationChange_dyn();

		virtual Void onNativeFullScreenChange( Dynamic event);
		Dynamic onNativeFullScreenChange_dyn();

		virtual Void onNativeResize( Dynamic event);
		Dynamic onNativeResize_dyn();

		virtual Void updateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext);
		Dynamic updateHitTestingBounds_dyn();

		virtual ::native::display::DisplayObjectContainer getInitialNativeLayer( );
		Dynamic getInitialNativeLayer_dyn();

		virtual bool fullscreen( );
		Dynamic fullscreen_dyn();

		virtual bool fullScreenEnabled( );
		Dynamic fullScreenEnabled_dyn();

		virtual Void exitFullscreen( );
		Dynamic exitFullscreen_dyn();

		virtual Void enterFullscreen( );
		Dynamic enterFullscreen_dyn();

		virtual Void open( ::String url,::String name);
		Dynamic open_dyn();

		int innerWidth; /* REM */ 
		int innerHeight; /* REM */ 
		Dynamic onFullScreenChange; /* REM */ 
		Dynamic &onFullScreenChange_dyn() { return onFullScreenChange;}
		Dynamic onOrientationChange; /* REM */ 
		Dynamic &onOrientationChange_dyn() { return onOrientationChange;}
		Dynamic onResize; /* REM */ 
		Dynamic &onResize_dyn() { return onResize;}
		::cocktail::port::platform::flash_player::TouchListener touchListener; /* REM */ 
		::cocktail::port::platform::flash_player::Mouse mouse; /* REM */ 
		::cocktail::port::platform::flash_player::Keyboard keyboard; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_PlatformBase */ 
