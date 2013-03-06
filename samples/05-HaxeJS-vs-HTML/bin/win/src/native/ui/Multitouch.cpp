#include <hxcpp.h>

#ifndef INCLUDED_native_Lib
#include <native/Lib.h>
#endif
#ifndef INCLUDED_native_Loader
#include <native/Loader.h>
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
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_ui_Multitouch
#include <native/ui/Multitouch.h>
#endif
#ifndef INCLUDED_native_ui_MultitouchInputMode
#include <native/ui/MultitouchInputMode.h>
#endif
namespace native{
namespace ui{

Void Multitouch_obj::__construct()
{
	return null();
}

Multitouch_obj::~Multitouch_obj() { }

Dynamic Multitouch_obj::__CreateEmpty() { return  new Multitouch_obj; }
hx::ObjectPtr< Multitouch_obj > Multitouch_obj::__new()
{  hx::ObjectPtr< Multitouch_obj > result = new Multitouch_obj();
	result->__construct();
	return result;}

Dynamic Multitouch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Multitouch_obj > result = new Multitouch_obj();
	result->__construct();
	return result;}

void Multitouch_obj::__init__() {
HX_STACK_PUSH("Multitouch::__init__","native/ui/Multitouch.hx",20);
{
	HX_STACK_LINE(22)
	::native::ui::Multitouch_obj::maxTouchPoints = (int)2;
	HX_STACK_LINE(23)
	::native::ui::Multitouch_obj::supportedGestures = Array_obj< ::String >::__new();
	HX_STACK_LINE(24)
	::native::ui::Multitouch_obj::supportsGestureEvents = false;
}
}

::native::ui::MultitouchInputMode Multitouch_obj::inputMode;

int Multitouch_obj::maxTouchPoints;

Array< ::String > Multitouch_obj::supportedGestures;

bool Multitouch_obj::supportsGestureEvents;

bool Multitouch_obj::supportsTouchEvents;

::native::ui::MultitouchInputMode Multitouch_obj::get_inputMode( ){
	HX_STACK_PUSH("Multitouch::get_inputMode","native/ui/Multitouch.hx",36);
	HX_STACK_LINE(36)
	if ((::native::ui::Multitouch_obj::nme_stage_get_multitouch_active(::native::Lib_obj::get_current()->get_stage()->nmeHandle))){
		HX_STACK_LINE(40)
		return ::native::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn();
	}
	else{
		HX_STACK_LINE(42)
		return ::native::ui::MultitouchInputMode_obj::NONE_dyn();
	}
	HX_STACK_LINE(36)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Multitouch_obj,get_inputMode,return )

::native::ui::MultitouchInputMode Multitouch_obj::set_inputMode( ::native::ui::MultitouchInputMode inMode){
	HX_STACK_PUSH("Multitouch::set_inputMode","native/ui/Multitouch.hx",47);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(49)
	if (((inMode == ::native::ui::MultitouchInputMode_obj::GESTURE_dyn()))){
		HX_STACK_LINE(50)
		return ::native::ui::Multitouch_obj::get_inputMode();
	}
	HX_STACK_LINE(53)
	::native::ui::Multitouch_obj::nme_stage_set_multitouch_active(::native::Lib_obj::get_current()->get_stage()->nmeHandle,(inMode == ::native::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn()));
	HX_STACK_LINE(54)
	return inMode;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Multitouch_obj,set_inputMode,return )

bool Multitouch_obj::get_supportsTouchEvents( ){
	HX_STACK_PUSH("Multitouch::get_supportsTouchEvents","native/ui/Multitouch.hx",59);
	HX_STACK_LINE(59)
	return ::native::ui::Multitouch_obj::nme_stage_get_multitouch_supported(::native::Lib_obj::get_current()->get_stage()->nmeHandle);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Multitouch_obj,get_supportsTouchEvents,return )

Dynamic Multitouch_obj::nme_stage_get_multitouch_supported;

Dynamic Multitouch_obj::nme_stage_get_multitouch_active;

Dynamic Multitouch_obj::nme_stage_set_multitouch_active;


Multitouch_obj::Multitouch_obj()
{
}

void Multitouch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Multitouch);
	HX_MARK_END_CLASS();
}

void Multitouch_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Multitouch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"inputMode") ) { return inCallProp ? get_inputMode() : inputMode; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_inputMode") ) { return get_inputMode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_inputMode") ) { return set_inputMode_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxTouchPoints") ) { return maxTouchPoints; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"supportedGestures") ) { return supportedGestures; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { return inCallProp ? get_supportsTouchEvents() : supportsTouchEvents; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"supportsGestureEvents") ) { return supportsGestureEvents; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"get_supportsTouchEvents") ) { return get_supportsTouchEvents_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_active") ) { return nme_stage_get_multitouch_active; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_multitouch_active") ) { return nme_stage_set_multitouch_active; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_supported") ) { return nme_stage_get_multitouch_supported; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Multitouch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"inputMode") ) { if (inCallProp) return set_inputMode(inValue);inputMode=inValue.Cast< ::native::ui::MultitouchInputMode >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxTouchPoints") ) { maxTouchPoints=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"supportedGestures") ) { supportedGestures=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { supportsTouchEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"supportsGestureEvents") ) { supportsGestureEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_active") ) { nme_stage_get_multitouch_active=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_multitouch_active") ) { nme_stage_set_multitouch_active=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_supported") ) { nme_stage_get_multitouch_supported=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Multitouch_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("inputMode"),
	HX_CSTRING("maxTouchPoints"),
	HX_CSTRING("supportedGestures"),
	HX_CSTRING("supportsGestureEvents"),
	HX_CSTRING("supportsTouchEvents"),
	HX_CSTRING("get_inputMode"),
	HX_CSTRING("set_inputMode"),
	HX_CSTRING("get_supportsTouchEvents"),
	HX_CSTRING("nme_stage_get_multitouch_supported"),
	HX_CSTRING("nme_stage_get_multitouch_active"),
	HX_CSTRING("nme_stage_set_multitouch_active"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Multitouch_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Multitouch_obj::inputMode,"inputMode");
	HX_MARK_MEMBER_NAME(Multitouch_obj::maxTouchPoints,"maxTouchPoints");
	HX_MARK_MEMBER_NAME(Multitouch_obj::supportedGestures,"supportedGestures");
	HX_MARK_MEMBER_NAME(Multitouch_obj::supportsGestureEvents,"supportsGestureEvents");
	HX_MARK_MEMBER_NAME(Multitouch_obj::supportsTouchEvents,"supportsTouchEvents");
	HX_MARK_MEMBER_NAME(Multitouch_obj::nme_stage_get_multitouch_supported,"nme_stage_get_multitouch_supported");
	HX_MARK_MEMBER_NAME(Multitouch_obj::nme_stage_get_multitouch_active,"nme_stage_get_multitouch_active");
	HX_MARK_MEMBER_NAME(Multitouch_obj::nme_stage_set_multitouch_active,"nme_stage_set_multitouch_active");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Multitouch_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::inputMode,"inputMode");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::maxTouchPoints,"maxTouchPoints");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::supportedGestures,"supportedGestures");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::supportsGestureEvents,"supportsGestureEvents");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::supportsTouchEvents,"supportsTouchEvents");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::nme_stage_get_multitouch_supported,"nme_stage_get_multitouch_supported");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::nme_stage_get_multitouch_active,"nme_stage_get_multitouch_active");
	HX_VISIT_MEMBER_NAME(Multitouch_obj::nme_stage_set_multitouch_active,"nme_stage_set_multitouch_active");
};

Class Multitouch_obj::__mClass;

void Multitouch_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.ui.Multitouch"), hx::TCanCast< Multitouch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Multitouch_obj::__boot()
{
	nme_stage_get_multitouch_supported= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_multitouch_supported"),(int)1);
	nme_stage_get_multitouch_active= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_multitouch_active"),(int)1);
	nme_stage_set_multitouch_active= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_multitouch_active"),(int)2);
}

} // end namespace native
} // end namespace ui
