#ifndef INCLUDED_port_flash_player_Keyboard
#define INCLUDED_port_flash_player_Keyboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/keyboard/AbstractKeyboard.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,event,KeyboardEvent)
HX_DECLARE_CLASS2(core,event,UIEvent)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,keyboard,AbstractKeyboard)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Keyboard)
namespace port{
namespace flash_player{


class Keyboard_obj : public ::core::keyboard::AbstractKeyboard_obj{
	public:
		typedef ::core::keyboard::AbstractKeyboard_obj super;
		typedef Keyboard_obj OBJ_;
		Keyboard_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< Keyboard_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Keyboard_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Keyboard"); }

		virtual Void updateListeners( ::String keyboardEvent,Dynamic nativeCallback,Dynamic htmlElementCallback);
		Dynamic updateListeners_dyn();

		virtual ::core::event::KeyboardEvent getKeyData( Dynamic event);
		Dynamic getKeyData_dyn();

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_Keyboard */ 
