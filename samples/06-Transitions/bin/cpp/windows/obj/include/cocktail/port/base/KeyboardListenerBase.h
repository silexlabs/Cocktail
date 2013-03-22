#ifndef INCLUDED_cocktail_port_base_KeyboardListenerBase
#define INCLUDED_cocktail_port_base_KeyboardListenerBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,port,base,KeyboardListenerBase)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
namespace cocktail{
namespace port{
namespace base{


class KeyboardListenerBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef KeyboardListenerBase_obj OBJ_;
		KeyboardListenerBase_obj();
		Void __construct(::cocktail::port::platform::flash_player::Platform platform);

	public:
		static hx::ObjectPtr< KeyboardListenerBase_obj > __new(::cocktail::port::platform::flash_player::Platform platform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyboardListenerBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("KeyboardListenerBase"); }

		virtual ::cocktail::core::event::KeyboardEvent getKeyData( Dynamic event);
		Dynamic getKeyData_dyn();

		virtual Void removeNativeListeners( );
		Dynamic removeNativeListeners_dyn();

		virtual Void setNativeListeners( );
		Dynamic setNativeListeners_dyn();

		virtual Void onNativeKeyUp( Dynamic event);
		Dynamic onNativeKeyUp_dyn();

		virtual Void onNativeKeyDown( Dynamic event);
		Dynamic onNativeKeyDown_dyn();

		::cocktail::port::platform::flash_player::Platform _platform; /* REM */ 
		Dynamic onKeyUp; /* REM */ 
		Dynamic &onKeyUp_dyn() { return onKeyUp;}
		Dynamic onKeyDown; /* REM */ 
		Dynamic &onKeyDown_dyn() { return onKeyDown;}
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_KeyboardListenerBase */ 
