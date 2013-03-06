#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchEvent
#include <cocktail/core/event/TouchEvent.h>
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
namespace cocktail{
namespace port{
namespace base{

Void TouchListenerBase_obj::__construct(::cocktail::port::platform::flash_player::Platform platform)
{
HX_STACK_PUSH("TouchListenerBase::new","cocktail/port/base/TouchListenerBase.hx",58);
{
	HX_STACK_LINE(59)
	this->_platform = platform;
	HX_STACK_LINE(62)
	this->setNativeListeners();
}
;
	return null();
}

TouchListenerBase_obj::~TouchListenerBase_obj() { }

Dynamic TouchListenerBase_obj::__CreateEmpty() { return  new TouchListenerBase_obj; }
hx::ObjectPtr< TouchListenerBase_obj > TouchListenerBase_obj::__new(::cocktail::port::platform::flash_player::Platform platform)
{  hx::ObjectPtr< TouchListenerBase_obj > result = new TouchListenerBase_obj();
	result->__construct(platform);
	return result;}

Dynamic TouchListenerBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchListenerBase_obj > result = new TouchListenerBase_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::event::TouchEvent TouchListenerBase_obj::getTouchEvent( Dynamic event){
	HX_STACK_PUSH("TouchListenerBase::getTouchEvent","cocktail/port/base/TouchListenerBase.hx",132);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(132)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchListenerBase_obj,getTouchEvent,return )

Void TouchListenerBase_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("TouchListenerBase::removeNativeListeners","cocktail/port/base/TouchListenerBase.hx",123);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TouchListenerBase_obj,removeNativeListeners,(void))

Void TouchListenerBase_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("TouchListenerBase::setNativeListeners","cocktail/port/base/TouchListenerBase.hx",115);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TouchListenerBase_obj,setNativeListeners,(void))

Void TouchListenerBase_obj::onNativeTouchMove( Dynamic event){
{
		HX_STACK_PUSH("TouchListenerBase::onNativeTouchMove","cocktail/port/base/TouchListenerBase.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(100)
		if (((this->onTouchMove_dyn() != null()))){
			HX_STACK_LINE(102)
			this->onTouchMove(this->getTouchEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchListenerBase_obj,onNativeTouchMove,(void))

Void TouchListenerBase_obj::onNativeTouchEnd( Dynamic event){
{
		HX_STACK_PUSH("TouchListenerBase::onNativeTouchEnd","cocktail/port/base/TouchListenerBase.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(89)
		if (((this->onTouchEnd_dyn() != null()))){
			HX_STACK_LINE(91)
			this->onTouchEnd(this->getTouchEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchListenerBase_obj,onNativeTouchEnd,(void))

Void TouchListenerBase_obj::onNativeTouchStart( Dynamic event){
{
		HX_STACK_PUSH("TouchListenerBase::onNativeTouchStart","cocktail/port/base/TouchListenerBase.hx",78);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(78)
		if (((this->onTouchStart_dyn() != null()))){
			HX_STACK_LINE(80)
			this->onTouchStart(this->getTouchEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchListenerBase_obj,onNativeTouchStart,(void))


TouchListenerBase_obj::TouchListenerBase_obj()
{
}

void TouchListenerBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchListenerBase);
	HX_MARK_MEMBER_NAME(_platform,"_platform");
	HX_MARK_MEMBER_NAME(onTouchMove,"onTouchMove");
	HX_MARK_MEMBER_NAME(onTouchEnd,"onTouchEnd");
	HX_MARK_MEMBER_NAME(onTouchStart,"onTouchStart");
	HX_MARK_END_CLASS();
}

void TouchListenerBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_platform,"_platform");
	HX_VISIT_MEMBER_NAME(onTouchMove,"onTouchMove");
	HX_VISIT_MEMBER_NAME(onTouchEnd,"onTouchEnd");
	HX_VISIT_MEMBER_NAME(onTouchStart,"onTouchStart");
}

Dynamic TouchListenerBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_platform") ) { return _platform; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onTouchEnd") ) { return onTouchEnd; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onTouchMove") ) { return onTouchMove; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onTouchStart") ) { return onTouchStart; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getTouchEvent") ) { return getTouchEvent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onNativeTouchEnd") ) { return onNativeTouchEnd_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onNativeTouchMove") ) { return onNativeTouchMove_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeTouchStart") ) { return onNativeTouchStart_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchListenerBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_platform") ) { _platform=inValue.Cast< ::cocktail::port::platform::flash_player::Platform >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onTouchEnd") ) { onTouchEnd=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onTouchMove") ) { onTouchMove=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onTouchStart") ) { onTouchStart=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchListenerBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_platform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTouchEvent"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	HX_CSTRING("onNativeTouchMove"),
	HX_CSTRING("onNativeTouchEnd"),
	HX_CSTRING("onNativeTouchStart"),
	HX_CSTRING("_platform"),
	HX_CSTRING("onTouchMove"),
	HX_CSTRING("onTouchEnd"),
	HX_CSTRING("onTouchStart"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchListenerBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchListenerBase_obj::__mClass,"__mClass");
};

Class TouchListenerBase_obj::__mClass;

void TouchListenerBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.TouchListenerBase"), hx::TCanCast< TouchListenerBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TouchListenerBase_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
