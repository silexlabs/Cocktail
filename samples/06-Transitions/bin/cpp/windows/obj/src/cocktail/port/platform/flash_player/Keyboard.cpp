#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_port_base_KeyboardListenerBase
#include <cocktail/port/base/KeyboardListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Keyboard
#include <cocktail/port/platform/flash_player/Keyboard.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void Keyboard_obj::__construct(::cocktail::port::platform::flash_player::Platform platform)
{
HX_STACK_PUSH("Keyboard::new","cocktail/port/platform/flash_player/Keyboard.hx",32);
{
	HX_STACK_LINE(32)
	super::__construct(platform);
}
;
	return null();
}

Keyboard_obj::~Keyboard_obj() { }

Dynamic Keyboard_obj::__CreateEmpty() { return  new Keyboard_obj; }
hx::ObjectPtr< Keyboard_obj > Keyboard_obj::__new(::cocktail::port::platform::flash_player::Platform platform)
{  hx::ObjectPtr< Keyboard_obj > result = new Keyboard_obj();
	result->__construct(platform);
	return result;}

Dynamic Keyboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Keyboard_obj > result = new Keyboard_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::event::KeyboardEvent Keyboard_obj::getKeyData( Dynamic event){
	HX_STACK_PUSH("Keyboard::getKeyData","cocktail/port/platform/flash_player/Keyboard.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(67)
	::neash::events::KeyboardEvent typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(69)
	::String eventType;		HX_STACK_VAR(eventType,"eventType");
	HX_STACK_LINE(71)
	::String _switch_1 = (typedEvent->nmeGetType());
	if (  ( _switch_1==::neash::events::KeyboardEvent_obj::KEY_DOWN)){
		HX_STACK_LINE(73)
		eventType = HX_CSTRING("keydown");
	}
	else if (  ( _switch_1==::neash::events::KeyboardEvent_obj::KEY_UP)){
		HX_STACK_LINE(76)
		eventType = HX_CSTRING("keyup");
	}
	else  {
		HX_STACK_LINE(79)
		eventType = typedEvent->nmeGetType();
	}
;
;
	HX_STACK_LINE(84)
	::cocktail::core::event::KeyboardEvent keyboardEvent = ::cocktail::core::event::KeyboardEvent_obj::__new();		HX_STACK_VAR(keyboardEvent,"keyboardEvent");
	HX_STACK_LINE(85)
	keyboardEvent->initKeyboardEvent(eventType,true,true,null(),::Std_obj::string(typedEvent->charCode),::Std_obj::string(typedEvent->keyCode),(int)0,HX_CSTRING(""),false,HX_CSTRING(""));
	HX_STACK_LINE(88)
	return keyboardEvent;
}


Void Keyboard_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("Keyboard::removeNativeListeners","cocktail/port/platform/flash_player/Keyboard.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_LINE(54)
		::nme::Lib_obj::nmeGetCurrent()->removeEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->onNativeKeyDown_dyn(),null());
		HX_STACK_LINE(55)
		::nme::Lib_obj::nmeGetCurrent()->removeEventListener(::neash::events::KeyboardEvent_obj::KEY_UP,this->onNativeKeyUp_dyn(),null());
	}
return null();
}


Void Keyboard_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("Keyboard::setNativeListeners","cocktail/port/platform/flash_player/Keyboard.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_LINE(45)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_DOWN,this->onNativeKeyDown_dyn(),null(),null(),null());
		HX_STACK_LINE(46)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::KeyboardEvent_obj::KEY_UP,this->onNativeKeyUp_dyn(),null(),null(),null());
	}
return null();
}



Keyboard_obj::Keyboard_obj()
{
}

void Keyboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Keyboard);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Keyboard_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Keyboard_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"getKeyData") ) { return getKeyData_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Keyboard_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Keyboard_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getKeyData"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Keyboard_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Keyboard_obj::__mClass,"__mClass");
};

Class Keyboard_obj::__mClass;

void Keyboard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.Keyboard"), hx::TCanCast< Keyboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Keyboard_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
