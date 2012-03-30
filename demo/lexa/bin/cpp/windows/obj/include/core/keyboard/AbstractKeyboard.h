#ifndef INCLUDED_core_keyboard_AbstractKeyboard
#define INCLUDED_core_keyboard_AbstractKeyboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,event,KeyboardEvent)
HX_DECLARE_CLASS2(core,event,UIEvent)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,keyboard,AbstractKeyboard)
HX_DECLARE_CLASS2(core,keyboard,KeyboardKeyValue)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace keyboard{


class AbstractKeyboard_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractKeyboard_obj OBJ_;
		AbstractKeyboard_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractKeyboard_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractKeyboard_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractKeyboard"); }

		Dynamic _onKeyDown; /* REM */ 
	Dynamic &_onKeyDown_dyn() { return _onKeyDown;}
		Dynamic onKeyDown; /* REM */ 
	Dynamic &onKeyDown_dyn() { return onKeyDown;}
		Dynamic _onKeyUp; /* REM */ 
	Dynamic &_onKeyUp_dyn() { return _onKeyUp;}
		Dynamic onKeyUp; /* REM */ 
	Dynamic &onKeyUp_dyn() { return onKeyUp;}
		::port::flash_player::HTMLElement _htmlElement; /* REM */ 
		::String _keyDownEvent; /* REM */ 
		::String _keyUpEvent; /* REM */ 
		virtual Void onNativeKeyDown( Dynamic event);
		Dynamic onNativeKeyDown_dyn();

		virtual Void onNativeKeyUp( Dynamic event);
		Dynamic onNativeKeyUp_dyn();

		virtual Dynamic setOnKeyDown( Dynamic value);
		Dynamic setOnKeyDown_dyn();

		virtual Dynamic getOnKeyDown( );
		Dynamic getOnKeyDown_dyn();

		virtual Dynamic setOnKeyUp( Dynamic value);
		Dynamic setOnKeyUp_dyn();

		virtual Dynamic getOnKeyUp( );
		Dynamic getOnKeyUp_dyn();

		virtual Void updateListeners( ::String keyboardEvent,Dynamic nativeCallback,Dynamic htmlElementCallback);
		Dynamic updateListeners_dyn();

		virtual ::core::event::KeyboardEvent getKeyData( Dynamic event);
		Dynamic getKeyData_dyn();

		virtual ::core::keyboard::KeyboardKeyValue getKeyValue( int keyCode);
		Dynamic getKeyValue_dyn();

		static int TAB; /* REM */ 
		static int ENTER; /* REM */ 
		static int SPACE; /* REM */ 
};

} // end namespace core
} // end namespace keyboard

#endif /* INCLUDED_core_keyboard_AbstractKeyboard */ 
