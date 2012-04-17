#ifndef INCLUDED_cocktail_port_flash_player_Keyboard
#define INCLUDED_cocktail_port_flash_player_Keyboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/keyboard/AbstractKeyboard.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,keyboard,AbstractKeyboard)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Keyboard)
namespace cocktail{
namespace port{
namespace flash_player{


class Keyboard_obj : public ::cocktail::core::keyboard::AbstractKeyboard_obj{
	public:
		typedef ::cocktail::core::keyboard::AbstractKeyboard_obj super;
		typedef Keyboard_obj OBJ_;
		Keyboard_obj();
		Void __construct(::cocktail::core::html::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< Keyboard_obj > __new(::cocktail::core::html::HTMLElement htmlElement);
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

		virtual ::cocktail::core::event::KeyboardEvent getKeyData( Dynamic event);
		Dynamic getKeyData_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_Keyboard */ 
