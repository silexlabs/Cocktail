#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_Event
#include <core/event/Event.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_event_KeyboardEvent
#include <core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_core_event_UIEvent
#include <core/event/UIEvent.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_keyboard_AbstractKeyboard
#include <core/keyboard/AbstractKeyboard.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_KeyboardEvent
#include <nme/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Keyboard
#include <port/flash_player/Keyboard.h>
#endif
namespace port{
namespace flash_player{

Void Keyboard_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",31)
	super::__construct(htmlElement);
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",34)
	this->_keyDownEvent = ::nme::events::KeyboardEvent_obj::KEY_DOWN;
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",35)
	this->_keyUpEvent = ::nme::events::KeyboardEvent_obj::KEY_UP;
}
;
	return null();
}

Keyboard_obj::~Keyboard_obj() { }

Dynamic Keyboard_obj::__CreateEmpty() { return  new Keyboard_obj; }
hx::ObjectPtr< Keyboard_obj > Keyboard_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< Keyboard_obj > result = new Keyboard_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic Keyboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Keyboard_obj > result = new Keyboard_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Keyboard_obj::updateListeners( ::String keyboardEvent,Dynamic nativeCallback,Dynamic htmlElementCallback){
{
		HX_SOURCE_PUSH("Keyboard_obj::updateListeners")
		HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",49)
		this->_htmlElement->get_nativeElement()->__Field(HX_CSTRING("removeEventListener"))(keyboardEvent,nativeCallback);
		HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",51)
		if (((htmlElementCallback != null()))){
			HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",52)
			this->_htmlElement->get_nativeElement()->__Field(HX_CSTRING("addEventListener"))(keyboardEvent,nativeCallback);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Keyboard_obj,updateListeners,(void))

::core::event::KeyboardEvent Keyboard_obj::getKeyData( Dynamic event){
	HX_SOURCE_PUSH("Keyboard_obj::getKeyData")
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",65)
	::nme::events::KeyboardEvent typedEvent = event;
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",67)
	::String eventType;
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",69)
	::String _switch_1 = (typedEvent->nmeGetType());
	if (  ( _switch_1==::nme::events::KeyboardEvent_obj::KEY_DOWN)){
		HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",71)
		eventType = HX_CSTRING("keydown");
	}
	else if (  ( _switch_1==::nme::events::KeyboardEvent_obj::KEY_UP)){
		HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",74)
		eventType = HX_CSTRING("keyup");
	}
	else  {
		HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",77)
		eventType = typedEvent->nmeGetType();
	}
;
;
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",81)
	::core::event::KeyboardEvent keyboardEvent = ::core::event::KeyboardEvent_obj::__new(eventType,this->_htmlElement,0.0,typedEvent->charCode,typedEvent->keyCode,typedEvent->ctrlKey,typedEvent->shiftKey,typedEvent->altKey);
	HX_SOURCE_POS("../../src/port/flash_player/Keyboard.hx",85)
	return keyboardEvent;
}


HX_DEFINE_DYNAMIC_FUNC1(Keyboard_obj,getKeyData,return )


Keyboard_obj::Keyboard_obj()
{
}

void Keyboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Keyboard);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Keyboard_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"getKeyData") ) { return getKeyData_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateListeners") ) { return updateListeners_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Keyboard_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Keyboard_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateListeners"),
	HX_CSTRING("getKeyData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Keyboard_obj::__mClass;

void Keyboard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("port.flash_player.Keyboard"), hx::TCanCast< Keyboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Keyboard_obj::__boot()
{
}

} // end namespace port
} // end namespace flash_player
