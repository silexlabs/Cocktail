#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_WheelEvent
#include <cocktail/core/event/WheelEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_port_base_MouseListenerBase
#include <cocktail/port/base/MouseListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Mouse
#include <cocktail/port/platform/flash_player/Mouse.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void Mouse_obj::__construct(::cocktail::port::platform::flash_player::Platform platform)
{
HX_STACK_PUSH("Mouse::new","cocktail/port/platform/flash_player/Mouse.hx",37);
{
	HX_STACK_LINE(37)
	super::__construct(platform);
}
;
	return null();
}

Mouse_obj::~Mouse_obj() { }

Dynamic Mouse_obj::__CreateEmpty() { return  new Mouse_obj; }
hx::ObjectPtr< Mouse_obj > Mouse_obj::__new(::cocktail::port::platform::flash_player::Platform platform)
{  hx::ObjectPtr< Mouse_obj > result = new Mouse_obj();
	result->__construct(platform);
	return result;}

Dynamic Mouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mouse_obj > result = new Mouse_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::event::Event Mouse_obj::getEvent( Dynamic event){
	HX_STACK_PUSH("Mouse::getEvent","cocktail/port/platform/flash_player/Mouse.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(230)
	::native::events::Event typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(232)
	::cocktail::core::event::Event event1 = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(event1,"event1");
	HX_STACK_LINE(233)
	event1->initEvent(HX_CSTRING("mouseleave"),true,false);
	HX_STACK_LINE(235)
	return event1;
}


::cocktail::core::event::WheelEvent Mouse_obj::getWheelEvent( Dynamic event){
	HX_STACK_PUSH("Mouse::getWheelEvent","cocktail/port/platform/flash_player/Mouse.hx",207);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(209)
	::native::events::MouseEvent typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(211)
	::cocktail::core::event::WheelEvent wheelEvent = ::cocktail::core::event::WheelEvent_obj::__new();		HX_STACK_VAR(wheelEvent,"wheelEvent");
	HX_STACK_LINE(212)
	::native::geom::Point offset = ::nme::Lib_obj::get_current()->localToGlobal(::native::geom::Point_obj::__new(null(),null()));		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(214)
	wheelEvent->initWheelEvent(HX_CSTRING("wheel"),true,true,null(),0.0,::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),(int)0,null(),HX_CSTRING(""),(int)0,typedEvent->delta,(int)0,(int)0);
	HX_STACK_LINE(218)
	return wheelEvent;
}


::cocktail::core::event::MouseEvent Mouse_obj::getMouseEvent( Dynamic event){
	HX_STACK_PUSH("Mouse::getMouseEvent","cocktail/port/platform/flash_player/Mouse.hx",168);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(170)
	::native::events::MouseEvent typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(172)
	::String eventType;		HX_STACK_VAR(eventType,"eventType");
	HX_STACK_LINE(174)
	::String _switch_1 = (typedEvent->get_type());
	if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_DOWN)){
		HX_STACK_LINE(176)
		eventType = HX_CSTRING("mousedown");
	}
	else if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_UP)){
		HX_STACK_LINE(179)
		eventType = HX_CSTRING("mouseup");
	}
	else if (  ( _switch_1==::native::events::MouseEvent_obj::MOUSE_MOVE)){
		HX_STACK_LINE(182)
		eventType = HX_CSTRING("mousemove");
	}
	else  {
		HX_STACK_LINE(185)
		eventType = typedEvent->get_type();
	}
;
;
	HX_STACK_LINE(190)
	::cocktail::core::event::MouseEvent mouseEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(mouseEvent,"mouseEvent");
	HX_STACK_LINE(191)
	::native::geom::Point offset = ::nme::Lib_obj::get_current()->localToGlobal(::native::geom::Point_obj::__new(null(),null()));		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(194)
	mouseEvent->initMouseEvent(eventType,true,true,null(),0.0,::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),typedEvent->ctrlKey,typedEvent->altKey,typedEvent->shiftKey,false,(int)0,null());
	HX_STACK_LINE(197)
	return mouseEvent;
}


Void Mouse_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("Mouse::removeNativeListeners","cocktail/port/platform/flash_player/Mouse.hx",152);
		HX_STACK_THIS(this);
		HX_STACK_LINE(153)
		this->_platform->hitTestingSprite->removeEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->onNativeMouseDown_dyn(),null());
		HX_STACK_LINE(154)
		this->_platform->hitTestingSprite->removeEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onNativeMouseUp_dyn(),null());
		HX_STACK_LINE(155)
		this->_platform->hitTestingSprite->removeEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->onNativeMouseMove_dyn(),null());
		HX_STACK_LINE(156)
		this->_platform->hitTestingSprite->removeEventListener(::native::events::MouseEvent_obj::MOUSE_WHEEL,this->onNativeMouseWheel_dyn(),null());
		HX_STACK_LINE(158)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::Event_obj::MOUSE_LEAVE,this->onNativeMouseLeave_dyn(),null());
	}
return null();
}


Void Mouse_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("Mouse::setNativeListeners","cocktail/port/platform/flash_player/Mouse.hx",139);
		HX_STACK_THIS(this);
		HX_STACK_LINE(140)
		this->_platform->hitTestingSprite->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->onNativeMouseDown_dyn(),null(),null(),null());
		HX_STACK_LINE(141)
		this->_platform->hitTestingSprite->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->onNativeMouseUp_dyn(),null(),null(),null());
		HX_STACK_LINE(142)
		this->_platform->hitTestingSprite->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->onNativeMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(143)
		this->_platform->hitTestingSprite->addEventListener(::native::events::MouseEvent_obj::MOUSE_WHEEL,this->onNativeMouseWheel_dyn(),null(),null(),null());
		HX_STACK_LINE(145)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::MOUSE_LEAVE,this->onNativeMouseLeave_dyn(),null(),null(),null());
	}
return null();
}


Void Mouse_obj::setBitmapCursor( ::native::display::BitmapData nativeBitmapData,::cocktail::core::geom::PointVO hotSpot){
{
		HX_STACK_PUSH("Mouse::setBitmapCursor","cocktail/port/platform/flash_player/Mouse.hx",95);
		HX_STACK_THIS(this);
		HX_STACK_ARG(nativeBitmapData,"nativeBitmapData");
		HX_STACK_ARG(hotSpot,"hotSpot");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Mouse_obj,setBitmapCursor,(void))

Void Mouse_obj::setMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor){
{
		HX_STACK_PUSH("Mouse::setMouseCursor","cocktail/port/platform/flash_player/Mouse.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cursor,"cursor");
	}
return null();
}



Mouse_obj::Mouse_obj()
{
}

void Mouse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mouse);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Mouse_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Mouse_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"getEvent") ) { return getEvent_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getWheelEvent") ) { return getWheelEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"getMouseEvent") ) { return getMouseEvent_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setMouseCursor") ) { return setMouseCursor_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setBitmapCursor") ) { return setBitmapCursor_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mouse_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Mouse_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getEvent"),
	HX_CSTRING("getWheelEvent"),
	HX_CSTRING("getMouseEvent"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	HX_CSTRING("setBitmapCursor"),
	HX_CSTRING("setMouseCursor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mouse_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mouse_obj::__mClass,"__mClass");
};

Class Mouse_obj::__mClass;

void Mouse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.Mouse"), hx::TCanCast< Mouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Mouse_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
