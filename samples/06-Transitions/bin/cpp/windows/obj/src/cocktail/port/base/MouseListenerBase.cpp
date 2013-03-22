#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
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
#ifndef INCLUDED_cocktail_port_base_MouseListenerBase
#include <cocktail/port/base/MouseListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void MouseListenerBase_obj::__construct(::cocktail::port::platform::flash_player::Platform platform)
{
HX_STACK_PUSH("MouseListenerBase::new","cocktail/port/base/MouseListenerBase.hx",77);
{
	HX_STACK_LINE(78)
	this->_platform = platform;
	HX_STACK_LINE(81)
	if (((::cocktail::core::config::Config_obj::getInstance()->enableMouseEvent == true))){
		HX_STACK_LINE(82)
		this->setNativeListeners();
	}
}
;
	return null();
}

MouseListenerBase_obj::~MouseListenerBase_obj() { }

Dynamic MouseListenerBase_obj::__CreateEmpty() { return  new MouseListenerBase_obj; }
hx::ObjectPtr< MouseListenerBase_obj > MouseListenerBase_obj::__new(::cocktail::port::platform::flash_player::Platform platform)
{  hx::ObjectPtr< MouseListenerBase_obj > result = new MouseListenerBase_obj();
	result->__construct(platform);
	return result;}

Dynamic MouseListenerBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseListenerBase_obj > result = new MouseListenerBase_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::event::Event MouseListenerBase_obj::getEvent( Dynamic event){
	HX_STACK_PUSH("MouseListenerBase::getEvent","cocktail/port/base/MouseListenerBase.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(213)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,getEvent,return )

::cocktail::core::event::WheelEvent MouseListenerBase_obj::getWheelEvent( Dynamic event){
	HX_STACK_PUSH("MouseListenerBase::getWheelEvent","cocktail/port/base/MouseListenerBase.hx",202);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(202)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,getWheelEvent,return )

::cocktail::core::event::MouseEvent MouseListenerBase_obj::getMouseEvent( Dynamic event){
	HX_STACK_PUSH("MouseListenerBase::getMouseEvent","cocktail/port/base/MouseListenerBase.hx",191);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(191)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,getMouseEvent,return )

Void MouseListenerBase_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("MouseListenerBase::removeNativeListeners","cocktail/port/base/MouseListenerBase.hx",180);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MouseListenerBase_obj,removeNativeListeners,(void))

Void MouseListenerBase_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("MouseListenerBase::setNativeListeners","cocktail/port/base/MouseListenerBase.hx",172);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MouseListenerBase_obj,setNativeListeners,(void))

Void MouseListenerBase_obj::onNativeMouseLeave( Dynamic event){
{
		HX_STACK_PUSH("MouseListenerBase::onNativeMouseLeave","cocktail/port/base/MouseListenerBase.hx",157);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(157)
		if (((this->onMouseLeave_dyn() != null()))){
			HX_STACK_LINE(159)
			this->onMouseLeave(this->getEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,onNativeMouseLeave,(void))

Void MouseListenerBase_obj::onNativeMouseWheel( Dynamic event){
{
		HX_STACK_PUSH("MouseListenerBase::onNativeMouseWheel","cocktail/port/base/MouseListenerBase.hx",146);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(146)
		if (((this->onMouseWheel_dyn() != null()))){
			HX_STACK_LINE(148)
			this->onMouseWheel(this->getWheelEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,onNativeMouseWheel,(void))

Void MouseListenerBase_obj::onNativeMouseMove( Dynamic event){
{
		HX_STACK_PUSH("MouseListenerBase::onNativeMouseMove","cocktail/port/base/MouseListenerBase.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(135)
		if (((this->onMouseMove_dyn() != null()))){
			HX_STACK_LINE(137)
			this->onMouseMove(this->getMouseEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,onNativeMouseMove,(void))

Void MouseListenerBase_obj::onNativeMouseUp( Dynamic event){
{
		HX_STACK_PUSH("MouseListenerBase::onNativeMouseUp","cocktail/port/base/MouseListenerBase.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(124)
		if (((this->onMouseUp_dyn() != null()))){
			HX_STACK_LINE(126)
			this->onMouseUp(this->getMouseEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,onNativeMouseUp,(void))

Void MouseListenerBase_obj::onNativeMouseDown( Dynamic event){
{
		HX_STACK_PUSH("MouseListenerBase::onNativeMouseDown","cocktail/port/base/MouseListenerBase.hx",113);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(113)
		if (((this->onMouseDown_dyn() != null()))){
			HX_STACK_LINE(115)
			this->onMouseDown(this->getMouseEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,onNativeMouseDown,(void))

Void MouseListenerBase_obj::setMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor){
{
		HX_STACK_PUSH("MouseListenerBase::setMouseCursor","cocktail/port/base/MouseListenerBase.hx",96);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cursor,"cursor");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MouseListenerBase_obj,setMouseCursor,(void))


MouseListenerBase_obj::MouseListenerBase_obj()
{
}

void MouseListenerBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MouseListenerBase);
	HX_MARK_MEMBER_NAME(_platform,"_platform");
	HX_MARK_MEMBER_NAME(onMouseLeave,"onMouseLeave");
	HX_MARK_MEMBER_NAME(onMouseWheel,"onMouseWheel");
	HX_MARK_MEMBER_NAME(onMouseMove,"onMouseMove");
	HX_MARK_MEMBER_NAME(onMouseUp,"onMouseUp");
	HX_MARK_MEMBER_NAME(onMouseDown,"onMouseDown");
	HX_MARK_END_CLASS();
}

void MouseListenerBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_platform,"_platform");
	HX_VISIT_MEMBER_NAME(onMouseLeave,"onMouseLeave");
	HX_VISIT_MEMBER_NAME(onMouseWheel,"onMouseWheel");
	HX_VISIT_MEMBER_NAME(onMouseMove,"onMouseMove");
	HX_VISIT_MEMBER_NAME(onMouseUp,"onMouseUp");
	HX_VISIT_MEMBER_NAME(onMouseDown,"onMouseDown");
}

Dynamic MouseListenerBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"getEvent") ) { return getEvent_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_platform") ) { return _platform; }
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { return onMouseMove; }
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onMouseLeave") ) { return onMouseLeave; }
		if (HX_FIELD_EQ(inName,"onMouseWheel") ) { return onMouseWheel; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getWheelEvent") ) { return getWheelEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"getMouseEvent") ) { return getMouseEvent_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setMouseCursor") ) { return setMouseCursor_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onNativeMouseUp") ) { return onNativeMouseUp_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onNativeMouseMove") ) { return onNativeMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeMouseDown") ) { return onNativeMouseDown_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeMouseLeave") ) { return onNativeMouseLeave_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeMouseWheel") ) { return onNativeMouseWheel_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MouseListenerBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_platform") ) { _platform=inValue.Cast< ::cocktail::port::platform::flash_player::Platform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { onMouseUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { onMouseMove=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { onMouseDown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onMouseLeave") ) { onMouseLeave=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onMouseWheel") ) { onMouseWheel=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MouseListenerBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_platform"));
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
	HX_CSTRING("onNativeMouseLeave"),
	HX_CSTRING("onNativeMouseWheel"),
	HX_CSTRING("onNativeMouseMove"),
	HX_CSTRING("onNativeMouseUp"),
	HX_CSTRING("onNativeMouseDown"),
	HX_CSTRING("setMouseCursor"),
	HX_CSTRING("_platform"),
	HX_CSTRING("onMouseLeave"),
	HX_CSTRING("onMouseWheel"),
	HX_CSTRING("onMouseMove"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("onMouseDown"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MouseListenerBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MouseListenerBase_obj::__mClass,"__mClass");
};

Class MouseListenerBase_obj::__mClass;

void MouseListenerBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.MouseListenerBase"), hx::TCanCast< MouseListenerBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MouseListenerBase_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
