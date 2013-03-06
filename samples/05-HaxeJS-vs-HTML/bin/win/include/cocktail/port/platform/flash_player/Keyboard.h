#ifndef INCLUDED_cocktail_port_platform_flash_player_Keyboard
#define INCLUDED_cocktail_port_platform_flash_player_Keyboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/KeyboardListenerBase.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,port,base,KeyboardListenerBase)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Keyboard)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class Keyboard_obj : public ::cocktail::port::base::KeyboardListenerBase_obj{
	public:
		typedef ::cocktail::port::base::KeyboardListenerBase_obj super;
		typedef Keyboard_obj OBJ_;
		Keyboard_obj();
		Void __construct(::cocktail::port::platform::flash_player::Platform platform);

	public:
		static hx::ObjectPtr< Keyboard_obj > __new(::cocktail::port::platform::flash_player::Platform platform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Keyboard_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Keyboard"); }

		virtual ::cocktail::core::event::KeyboardEvent getKeyData( Dynamic event);

		virtual Void removeNativeListeners( );

		virtual Void setNativeListeners( );

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_Keyboard */ 
