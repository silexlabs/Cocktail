#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void KeyboardListenerBase_obj::__construct(::cocktail::port::platform::flash_player::Platform platform)
{
HX_STACK_PUSH("KeyboardListenerBase::new","cocktail/port/base/KeyboardListenerBase.hx",55);
{
	HX_STACK_LINE(56)
	this->_platform = platform;
	HX_STACK_LINE(59)
	this->setNativeListeners();
}
;
	return null();
}

KeyboardListenerBase_obj::~KeyboardListenerBase_obj() { }

Dynamic KeyboardListenerBase_obj::__CreateEmpty() { return  new KeyboardListenerBase_obj; }
hx::ObjectPtr< KeyboardListenerBase_obj > KeyboardListenerBase_obj::__new(::cocktail::port::platform::flash_player::Platform platform)
{  hx::ObjectPtr< KeyboardListenerBase_obj > result = new KeyboardListenerBase_obj();
	result->__construct(platform);
	return result;}

Dynamic KeyboardListenerBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyboardListenerBase_obj > result = new KeyboardListenerBase_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::event::KeyboardEvent KeyboardListenerBase_obj::getKeyData( Dynamic event){
	HX_STACK_PUSH("KeyboardListenerBase::getKeyData","cocktail/port/base/KeyboardListenerBase.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(120)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(KeyboardListenerBase_obj,getKeyData,return )

Void KeyboardListenerBase_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("KeyboardListenerBase::removeNativeListeners","cocktail/port/base/KeyboardListenerBase.hx",109);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardListenerBase_obj,removeNativeListeners,(void))

Void KeyboardListenerBase_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("KeyboardListenerBase::setNativeListeners","cocktail/port/base/KeyboardListenerBase.hx",101);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardListenerBase_obj,setNativeListeners,(void))

Void KeyboardListenerBase_obj::onNativeKeyUp( Dynamic event){
{
		HX_STACK_PUSH("KeyboardListenerBase::onNativeKeyUp","cocktail/port/base/KeyboardListenerBase.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(86)
		if (((this->onKeyUp_dyn() != null()))){
			HX_STACK_LINE(88)
			this->onKeyUp(this->getKeyData(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(KeyboardListenerBase_obj,onNativeKeyUp,(void))

Void KeyboardListenerBase_obj::onNativeKeyDown( Dynamic event){
{
		HX_STACK_PUSH("KeyboardListenerBase::onNativeKeyDown","cocktail/port/base/KeyboardListenerBase.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(75)
		if (((this->onKeyDown_dyn() != null()))){
			HX_STACK_LINE(77)
			this->onKeyDown(this->getKeyData(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(KeyboardListenerBase_obj,onNativeKeyDown,(void))


KeyboardListenerBase_obj::KeyboardListenerBase_obj()
{
}

void KeyboardListenerBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(KeyboardListenerBase);
	HX_MARK_MEMBER_NAME(_platform,"_platform");
	HX_MARK_MEMBER_NAME(onKeyUp,"onKeyUp");
	HX_MARK_MEMBER_NAME(onKeyDown,"onKeyDown");
	HX_MARK_END_CLASS();
}

void KeyboardListenerBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_platform,"_platform");
	HX_VISIT_MEMBER_NAME(onKeyUp,"onKeyUp");
	HX_VISIT_MEMBER_NAME(onKeyDown,"onKeyDown");
}

Dynamic KeyboardListenerBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_platform") ) { return _platform; }
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getKeyData") ) { return getKeyData_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onNativeKeyUp") ) { return onNativeKeyUp_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onNativeKeyDown") ) { return onNativeKeyDown_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic KeyboardListenerBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { onKeyUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_platform") ) { _platform=inValue.Cast< ::cocktail::port::platform::flash_player::Platform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { onKeyDown=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void KeyboardListenerBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_platform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getKeyData"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	HX_CSTRING("onNativeKeyUp"),
	HX_CSTRING("onNativeKeyDown"),
	HX_CSTRING("_platform"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("onKeyDown"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyboardListenerBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(KeyboardListenerBase_obj::__mClass,"__mClass");
};

Class KeyboardListenerBase_obj::__mClass;

void KeyboardListenerBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.KeyboardListenerBase"), hx::TCanCast< KeyboardListenerBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void KeyboardListenerBase_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
