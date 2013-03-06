#ifndef INCLUDED_cocktail_port_base_TouchListenerBase
#define INCLUDED_cocktail_port_base_TouchListenerBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,TouchEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS3(cocktail,port,base,TouchListenerBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
namespace cocktail{
namespace port{
namespace base{


class TouchListenerBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TouchListenerBase_obj OBJ_;
		TouchListenerBase_obj();
		Void __construct(::cocktail::port::platform::flash_player::Platform platform);

	public:
		static hx::ObjectPtr< TouchListenerBase_obj > __new(::cocktail::port::platform::flash_player::Platform platform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchListenerBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchListenerBase"); }

		virtual ::cocktail::core::event::TouchEvent getTouchEvent( Dynamic event);
		Dynamic getTouchEvent_dyn();

		virtual Void removeNativeListeners( );
		Dynamic removeNativeListeners_dyn();

		virtual Void setNativeListeners( );
		Dynamic setNativeListeners_dyn();

		virtual Void onNativeTouchMove( Dynamic event);
		Dynamic onNativeTouchMove_dyn();

		virtual Void onNativeTouchEnd( Dynamic event);
		Dynamic onNativeTouchEnd_dyn();

		virtual Void onNativeTouchStart( Dynamic event);
		Dynamic onNativeTouchStart_dyn();

		::cocktail::port::platform::flash_player::Platform _platform; /* REM */ 
		Dynamic onTouchMove; /* REM */ 
		Dynamic &onTouchMove_dyn() { return onTouchMove;}
		Dynamic onTouchEnd; /* REM */ 
		Dynamic &onTouchEnd_dyn() { return onTouchEnd;}
		Dynamic onTouchStart; /* REM */ 
		Dynamic &onTouchStart_dyn() { return onTouchStart;}
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_TouchListenerBase */ 
