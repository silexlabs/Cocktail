#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchEvent
#include <cocktail/core/event/TouchEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchList
#include <cocktail/core/event/TouchList.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_TouchListenerBase
#include <cocktail/port/base/TouchListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_TouchListener
#include <cocktail/port/platform/flash_player/TouchListener.h>
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
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
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
#ifndef INCLUDED_neash_events_TouchEvent
#include <neash/events/TouchEvent.h>
#endif
#ifndef INCLUDED_neash_ui_Multitouch
#include <neash/ui/Multitouch.h>
#endif
#ifndef INCLUDED_neash_ui_MultitouchInputMode
#include <neash/ui/MultitouchInputMode.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void TouchListener_obj::__construct(::cocktail::port::platform::flash_player::Platform platform)
{
HX_STACK_PUSH("TouchListener::new","cocktail/port/platform/flash_player/TouchListener.hx",32);
{
	HX_STACK_LINE(33)
	super::__construct(platform);
	HX_STACK_LINE(37)
	::neash::ui::Multitouch_obj::nmeSetInputMode(::neash::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn());
}
;
	return null();
}

TouchListener_obj::~TouchListener_obj() { }

Dynamic TouchListener_obj::__CreateEmpty() { return  new TouchListener_obj; }
hx::ObjectPtr< TouchListener_obj > TouchListener_obj::__new(::cocktail::port::platform::flash_player::Platform platform)
{  hx::ObjectPtr< TouchListener_obj > result = new TouchListener_obj();
	result->__construct(platform);
	return result;}

Dynamic TouchListener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchListener_obj > result = new TouchListener_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::event::TouchEvent TouchListener_obj::getTouchEvent( Dynamic event){
	HX_STACK_PUSH("TouchListener::getTouchEvent","cocktail/port/platform/flash_player/TouchListener.hx",72);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(74)
	::neash::events::TouchEvent typedEvent = event;		HX_STACK_VAR(typedEvent,"typedEvent");
	HX_STACK_LINE(76)
	::String touchType;		HX_STACK_VAR(touchType,"touchType");
	HX_STACK_LINE(78)
	::String _switch_1 = (typedEvent->nmeGetType());
	if (  ( _switch_1==::neash::events::TouchEvent_obj::TOUCH_BEGIN)){
		HX_STACK_LINE(80)
		touchType = HX_CSTRING("touchstart");
	}
	else if (  ( _switch_1==::neash::events::TouchEvent_obj::TOUCH_END)){
		HX_STACK_LINE(83)
		touchType = HX_CSTRING("touchend");
	}
	else if (  ( _switch_1==::neash::events::TouchEvent_obj::TOUCH_MOVE)){
		HX_STACK_LINE(86)
		touchType = HX_CSTRING("touchmove");
	}
	else  {
		HX_STACK_LINE(89)
		touchType = typedEvent->nmeGetType();
	}
;
;
	struct _Function_1_1{
		inline static Dynamic Block( ::neash::events::TouchEvent &typedEvent){
			HX_STACK_PUSH("*::closure","cocktail/port/platform/flash_player/TouchListener.hx",93);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("identifier") , typedEvent->touchPointID,false);
				__result->Add(HX_CSTRING("target") , null(),false);
				__result->Add(HX_CSTRING("screenX") , ::Math_obj::round(typedEvent->stageX),false);
				__result->Add(HX_CSTRING("screenY") , ::Math_obj::round(typedEvent->stageY),false);
				__result->Add(HX_CSTRING("clientX") , ::Math_obj::round(typedEvent->stageX),false);
				__result->Add(HX_CSTRING("clientY") , ::Math_obj::round(typedEvent->stageY),false);
				__result->Add(HX_CSTRING("pageX") , (int)0,false);
				__result->Add(HX_CSTRING("pageY") , (int)0,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(93)
	Dynamic touch = _Function_1_1::Block(typedEvent);		HX_STACK_VAR(touch,"touch");
	HX_STACK_LINE(107)
	::cocktail::core::event::TouchEvent touchEvent = ::cocktail::core::event::TouchEvent_obj::__new();		HX_STACK_VAR(touchEvent,"touchEvent");
	HX_STACK_LINE(108)
	touchEvent->initTouchEvent(touchType,false,false,null(),0.0,::cocktail::core::event::TouchList_obj::__new(Dynamic( Array_obj<Dynamic>::__new().Add(touch))),null(),null(),false,false,false,false);
	HX_STACK_LINE(110)
	return touchEvent;
}


Void TouchListener_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("TouchListener::removeNativeListeners","cocktail/port/platform/flash_player/TouchListener.hx",59);
		HX_STACK_THIS(this);
		HX_STACK_LINE(60)
		this->_platform->hitTestingSprite->removeEventListener(::neash::events::TouchEvent_obj::TOUCH_BEGIN,this->onNativeTouchStart_dyn(),null());
		HX_STACK_LINE(61)
		this->_platform->hitTestingSprite->removeEventListener(::neash::events::TouchEvent_obj::TOUCH_MOVE,this->onNativeTouchMove_dyn(),null());
		HX_STACK_LINE(62)
		this->_platform->hitTestingSprite->removeEventListener(::neash::events::TouchEvent_obj::TOUCH_END,this->onNativeTouchEnd_dyn(),null());
	}
return null();
}


Void TouchListener_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("TouchListener::setNativeListeners","cocktail/port/platform/flash_player/TouchListener.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(50)
		this->_platform->hitTestingSprite->addEventListener(::neash::events::TouchEvent_obj::TOUCH_BEGIN,this->onNativeTouchStart_dyn(),null(),null(),null());
		HX_STACK_LINE(51)
		this->_platform->hitTestingSprite->addEventListener(::neash::events::TouchEvent_obj::TOUCH_MOVE,this->onNativeTouchMove_dyn(),null(),null(),null());
		HX_STACK_LINE(52)
		this->_platform->hitTestingSprite->addEventListener(::neash::events::TouchEvent_obj::TOUCH_END,this->onNativeTouchEnd_dyn(),null(),null(),null());
	}
return null();
}



TouchListener_obj::TouchListener_obj()
{
}

void TouchListener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchListener);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TouchListener_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TouchListener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"getTouchEvent") ) { return getTouchEvent_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchListener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchListener_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTouchEvent"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchListener_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchListener_obj::__mClass,"__mClass");
};

Class TouchListener_obj::__mClass;

void TouchListener_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.TouchListener"), hx::TCanCast< TouchListener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TouchListener_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
