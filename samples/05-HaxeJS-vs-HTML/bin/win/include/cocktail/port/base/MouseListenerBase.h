#ifndef INCLUDED_cocktail_port_base_MouseListenerBase
#define INCLUDED_cocktail_port_base_MouseListenerBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,event,WheelEvent)
HX_DECLARE_CLASS3(cocktail,port,base,MouseListenerBase)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
namespace cocktail{
namespace port{
namespace base{


class MouseListenerBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MouseListenerBase_obj OBJ_;
		MouseListenerBase_obj();
		Void __construct(::cocktail::port::platform::flash_player::Platform platform);

	public:
		static hx::ObjectPtr< MouseListenerBase_obj > __new(::cocktail::port::platform::flash_player::Platform platform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseListenerBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MouseListenerBase"); }

		virtual ::cocktail::core::event::Event getEvent( Dynamic event);
		Dynamic getEvent_dyn();

		virtual ::cocktail::core::event::WheelEvent getWheelEvent( Dynamic event);
		Dynamic getWheelEvent_dyn();

		virtual ::cocktail::core::event::MouseEvent getMouseEvent( Dynamic event);
		Dynamic getMouseEvent_dyn();

		virtual Void removeNativeListeners( );
		Dynamic removeNativeListeners_dyn();

		virtual Void setNativeListeners( );
		Dynamic setNativeListeners_dyn();

		virtual Void onNativeMouseLeave( Dynamic event);
		Dynamic onNativeMouseLeave_dyn();

		virtual Void onNativeMouseWheel( Dynamic event);
		Dynamic onNativeMouseWheel_dyn();

		virtual Void onNativeMouseMove( Dynamic event);
		Dynamic onNativeMouseMove_dyn();

		virtual Void onNativeMouseUp( Dynamic event);
		Dynamic onNativeMouseUp_dyn();

		virtual Void onNativeMouseDown( Dynamic event);
		Dynamic onNativeMouseDown_dyn();

		virtual Void setMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor);
		Dynamic setMouseCursor_dyn();

		::cocktail::port::platform::flash_player::Platform _platform; /* REM */ 
		Dynamic onMouseLeave; /* REM */ 
		Dynamic &onMouseLeave_dyn() { return onMouseLeave;}
		Dynamic onMouseWheel; /* REM */ 
		Dynamic &onMouseWheel_dyn() { return onMouseWheel;}
		Dynamic onMouseMove; /* REM */ 
		Dynamic &onMouseMove_dyn() { return onMouseMove;}
		Dynamic onMouseUp; /* REM */ 
		Dynamic &onMouseUp_dyn() { return onMouseUp;}
		Dynamic onMouseDown; /* REM */ 
		Dynamic &onMouseDown_dyn() { return onMouseDown;}
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_MouseListenerBase */ 
