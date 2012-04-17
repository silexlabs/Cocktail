#ifndef INCLUDED_cocktail_core_keyboard_AbstractKeyboard
#define INCLUDED_cocktail_core_keyboard_AbstractKeyboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,KeyboardEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,keyboard,AbstractKeyboard)
namespace cocktail{
namespace core{
namespace keyboard{


class AbstractKeyboard_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractKeyboard_obj OBJ_;
		AbstractKeyboard_obj();
		Void __construct(::cocktail::core::html::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractKeyboard_obj > __new(::cocktail::core::html::HTMLElement htmlElement);
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
		::cocktail::core::html::HTMLElement _htmlElement; /* REM */ 
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

		virtual ::cocktail::core::event::KeyboardEvent getKeyData( Dynamic event);
		Dynamic getKeyData_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace keyboard

#endif /* INCLUDED_cocktail_core_keyboard_AbstractKeyboard */ 
