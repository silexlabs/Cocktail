#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_AbstractMouse
#include <cocktail/core/mouse/AbstractMouse.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Mouse
#include <cocktail/port/flash_player/Mouse.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void Mouse_obj::__construct(::cocktail::core::html::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",32)
	super::__construct(htmlElement);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",35)
	this->_clickEvent = ::nme::events::MouseEvent_obj::CLICK;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",36)
	this->_mouseDownEvent = ::nme::events::MouseEvent_obj::MOUSE_DOWN;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",37)
	this->_mouseUpEvent = ::nme::events::MouseEvent_obj::MOUSE_UP;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",38)
	this->_mouseOverEvent = ::nme::events::MouseEvent_obj::MOUSE_OVER;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",39)
	this->_mouseOutEvent = ::nme::events::MouseEvent_obj::MOUSE_OUT;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",40)
	this->_mouseMoveEvent = ::nme::events::MouseEvent_obj::MOUSE_MOVE;
}
;
	return null();
}

Mouse_obj::~Mouse_obj() { }

Dynamic Mouse_obj::__CreateEmpty() { return  new Mouse_obj; }
hx::ObjectPtr< Mouse_obj > Mouse_obj::__new(::cocktail::core::html::HTMLElement htmlElement)
{  hx::ObjectPtr< Mouse_obj > result = new Mouse_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic Mouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mouse_obj > result = new Mouse_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Mouse_obj::updateListeners( ::String mouseEvent,Dynamic nativeCallback,Dynamic htmlElementCallback){
{
		HX_SOURCE_PUSH("Mouse_obj::updateListeners")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",55)
		this->_htmlElement->get_nativeElement()->__Field(HX_CSTRING("removeEventListener"))(mouseEvent,nativeCallback);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",57)
		if (((htmlElementCallback != null()))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",58)
			this->_htmlElement->get_nativeElement()->__Field(HX_CSTRING("addEventListener"))(mouseEvent,nativeCallback);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Mouse_obj,updateListeners,(void))

::cocktail::core::event::MouseEvent Mouse_obj::getMouseEvent( Dynamic event){
	HX_SOURCE_PUSH("Mouse_obj::getMouseEvent")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",71)
	::nme::events::MouseEvent typedEvent = event;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",73)
	::String eventType;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",75)
	::String _switch_1 = (typedEvent->nmeGetType());
	if (  ( _switch_1==::nme::events::MouseEvent_obj::CLICK)){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",77)
		eventType = HX_CSTRING("click");
	}
	else if (  ( _switch_1==::nme::events::MouseEvent_obj::MOUSE_DOWN)){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",80)
		eventType = HX_CSTRING("mousedown");
	}
	else if (  ( _switch_1==::nme::events::MouseEvent_obj::MOUSE_UP)){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",83)
		eventType = HX_CSTRING("mouseup");
	}
	else if (  ( _switch_1==::nme::events::MouseEvent_obj::MOUSE_OVER)){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",86)
		eventType = HX_CSTRING("mouseover");
	}
	else if (  ( _switch_1==::nme::events::MouseEvent_obj::MOUSE_OUT)){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",89)
		eventType = HX_CSTRING("mouseout");
	}
	else if (  ( _switch_1==::nme::events::MouseEvent_obj::MOUSE_MOVE)){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",92)
		eventType = HX_CSTRING("mousemove");
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",95)
		eventType = typedEvent->nmeGetType();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",99)
	::cocktail::core::event::MouseEvent mouseEvent = ::cocktail::core::event::MouseEvent_obj::__new(eventType,this->_htmlElement,0.0,typedEvent->stageX,typedEvent->stageY,typedEvent->localX,typedEvent->localY,typedEvent->ctrlKey,typedEvent->shiftKey,typedEvent->altKey);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Mouse.hx",102)
	return mouseEvent;
}


HX_DEFINE_DYNAMIC_FUNC1(Mouse_obj,getMouseEvent,return )


Mouse_obj::Mouse_obj()
{
}

void Mouse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mouse);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Mouse_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"getMouseEvent") ) { return getMouseEvent_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateListeners") ) { return updateListeners_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Mouse_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Mouse_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateListeners"),
	HX_CSTRING("getMouseEvent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Mouse_obj::__mClass;

void Mouse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.Mouse"), hx::TCanCast< Mouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Mouse_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
