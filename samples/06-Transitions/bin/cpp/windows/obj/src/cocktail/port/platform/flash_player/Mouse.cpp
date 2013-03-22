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
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
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
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
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
	HX_STACK_PUSH("Mouse::getEvent","cocktail/port/platform/flash_player/Mouse.hx",250);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(252)
	::neash::events::Event typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(254)
	::cocktail::core::event::Event event1 = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(event1,"event1");
	HX_STACK_LINE(255)
	event1->initEvent(HX_CSTRING("mouseleave"),true,false);
	HX_STACK_LINE(257)
	return event1;
}


::cocktail::core::event::WheelEvent Mouse_obj::getWheelEvent( Dynamic event){
	HX_STACK_PUSH("Mouse::getWheelEvent","cocktail/port/platform/flash_player/Mouse.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(231)
	::neash::events::MouseEvent typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(233)
	::cocktail::core::event::WheelEvent wheelEvent = ::cocktail::core::event::WheelEvent_obj::__new();		HX_STACK_VAR(wheelEvent,"wheelEvent");
	HX_STACK_LINE(234)
	::neash::geom::Point offset = ::nme::Lib_obj::nmeGetCurrent()->localToGlobal(::neash::geom::Point_obj::__new(null(),null()));		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(236)
	wheelEvent->initWheelEvent(HX_CSTRING("wheel"),true,true,null(),0.0,::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),(int)0,null(),HX_CSTRING(""),(int)0,typedEvent->delta,(int)0,(int)0);
	HX_STACK_LINE(240)
	return wheelEvent;
}


::cocktail::core::event::MouseEvent Mouse_obj::getMouseEvent( Dynamic event){
	HX_STACK_PUSH("Mouse::getMouseEvent","cocktail/port/platform/flash_player/Mouse.hx",191);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(193)
	::neash::events::MouseEvent typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(195)
	::String eventType;		HX_STACK_VAR(eventType,"eventType");
	HX_STACK_LINE(197)
	::String _switch_1 = (typedEvent->nmeGetType());
	if (  ( _switch_1==::neash::events::MouseEvent_obj::MOUSE_DOWN)){
		HX_STACK_LINE(199)
		eventType = HX_CSTRING("mousedown");
	}
	else if (  ( _switch_1==::neash::events::MouseEvent_obj::MOUSE_UP)){
		HX_STACK_LINE(202)
		eventType = HX_CSTRING("mouseup");
	}
	else if (  ( _switch_1==::neash::events::MouseEvent_obj::MOUSE_MOVE)){
		HX_STACK_LINE(205)
		eventType = HX_CSTRING("mousemove");
	}
	else  {
		HX_STACK_LINE(208)
		eventType = typedEvent->nmeGetType();
	}
;
;
	HX_STACK_LINE(212)
	::cocktail::core::event::MouseEvent mouseEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(mouseEvent,"mouseEvent");
	HX_STACK_LINE(213)
	::neash::geom::Point offset = ::nme::Lib_obj::nmeGetCurrent()->localToGlobal(::neash::geom::Point_obj::__new(null(),null()));		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(216)
	mouseEvent->initMouseEvent(eventType,true,true,null(),0.0,::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),::Math_obj::round((typedEvent->stageX - offset->x)),::Math_obj::round((typedEvent->stageY - offset->y)),typedEvent->ctrlKey,typedEvent->altKey,typedEvent->shiftKey,false,(int)0,null());
	HX_STACK_LINE(219)
	return mouseEvent;
}


Void Mouse_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("Mouse::removeNativeListeners","cocktail/port/platform/flash_player/Mouse.hx",164);
		HX_STACK_THIS(this);
		HX_STACK_LINE(174)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->onNativeMouseDown_dyn(),null());
		HX_STACK_LINE(175)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->onNativeMouseUp_dyn(),null());
		HX_STACK_LINE(176)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->onNativeMouseMove_dyn(),null());
		HX_STACK_LINE(177)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->onNativeMouseWheel_dyn(),null());
		HX_STACK_LINE(180)
		this->_platform->hitTestingSprite->removeEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->onNativeMouseLeave_dyn(),null());
		HX_STACK_LINE(181)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::neash::events::Event_obj::MOUSE_LEAVE,this->onNativeMouseLeave_dyn(),null());
	}
return null();
}


Void Mouse_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("Mouse::setNativeListeners","cocktail/port/platform/flash_player/Mouse.hx",139);
		HX_STACK_THIS(this);
		HX_STACK_LINE(149)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_DOWN,this->onNativeMouseDown_dyn(),null(),null(),null());
		HX_STACK_LINE(150)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_UP,this->onNativeMouseUp_dyn(),null(),null(),null());
		HX_STACK_LINE(151)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_MOVE,this->onNativeMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(152)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::MouseEvent_obj::MOUSE_WHEEL,this->onNativeMouseWheel_dyn(),null(),null(),null());
		HX_STACK_LINE(156)
		this->_platform->hitTestingSprite->addEventListener(::neash::events::MouseEvent_obj::MOUSE_OUT,this->onNativeMouseLeave_dyn(),null(),null(),null());
		HX_STACK_LINE(157)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::Event_obj::MOUSE_LEAVE,this->onNativeMouseLeave_dyn(),null(),null(),null());
	}
return null();
}


Void Mouse_obj::setBitmapCursor( ::neash::display::BitmapData nativeBitmapData,::cocktail::core::geom::PointVO hotSpot){
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
