#ifndef INCLUDED_cocktail_port_platform_flash_player_TouchListener
#define INCLUDED_cocktail_port_platform_flash_player_TouchListener

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/TouchListenerBase.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,TouchEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS3(cocktail,port,base,TouchListenerBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,TouchListener)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class TouchListener_obj : public ::cocktail::port::base::TouchListenerBase_obj{
	public:
		typedef ::cocktail::port::base::TouchListenerBase_obj super;
		typedef TouchListener_obj OBJ_;
		TouchListener_obj();
		Void __construct(::cocktail::port::platform::flash_player::Platform platform);

	public:
		static hx::ObjectPtr< TouchListener_obj > __new(::cocktail::port::platform::flash_player::Platform platform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchListener_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchListener"); }

		virtual ::cocktail::core::event::TouchEvent getTouchEvent( Dynamic event);

		virtual Void removeNativeListeners( );

		virtual Void setNativeListeners( );

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_TouchListener */ 
