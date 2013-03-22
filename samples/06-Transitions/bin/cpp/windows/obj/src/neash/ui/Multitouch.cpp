#include <hxcpp.h>

#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
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
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_ui_Multitouch
#include <neash/ui/Multitouch.h>
#endif
#ifndef INCLUDED_neash_ui_MultitouchInputMode
#include <neash/ui/MultitouchInputMode.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace neash{
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
HX_STACK_PUSH("Multitouch::__init__","neash/ui/Multitouch.hx",19);
{
	HX_STACK_LINE(20)
	::neash::ui::Multitouch_obj::maxTouchPoints = (int)2;
	HX_STACK_LINE(21)
	::neash::ui::Multitouch_obj::supportedGestures = Array_obj< ::String >::__new();
	HX_STACK_LINE(22)
	::neash::ui::Multitouch_obj::supportsGestureEvents = false;
}
}

::neash::ui::MultitouchInputMode Multitouch_obj::inputMode;

int Multitouch_obj::maxTouchPoints;

Array< ::String > Multitouch_obj::supportedGestures;

bool Multitouch_obj::supportsGestureEvents;

bool Multitouch_obj::supportsTouchEvents;

::neash::ui::MultitouchInputMode Multitouch_obj::nmeGetInputMode( ){
	HX_STACK_PUSH("Multitouch::nmeGetInputMode","neash/ui/Multitouch.hx",32);
	HX_STACK_LINE(32)
	if ((::neash::ui::Multitouch_obj::nme_stage_get_multitouch_active(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeHandle))){
		HX_STACK_LINE(35)
		return ::neash::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn();
	}
	else{
		HX_STACK_LINE(37)
		return ::neash::ui::MultitouchInputMode_obj::NONE_dyn();
	}
	HX_STACK_LINE(32)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Multitouch_obj,nmeGetInputMode,return )

::neash::ui::MultitouchInputMode Multitouch_obj::nmeSetInputMode( ::neash::ui::MultitouchInputMode inMode){
	HX_STACK_PUSH("Multitouch::nmeSetInputMode","neash/ui/Multitouch.hx",42);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(43)
	if (((inMode == ::neash::ui::MultitouchInputMode_obj::GESTURE_dyn()))){
		HX_STACK_LINE(44)
		return ::neash::ui::Multitouch_obj::nmeGetInputMode();
	}
	HX_STACK_LINE(47)
	::neash::ui::Multitouch_obj::nme_stage_set_multitouch_active(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeHandle,(inMode == ::neash::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn()));
	HX_STACK_LINE(48)
	return inMode;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Multitouch_obj,nmeSetInputMode,return )

bool Multitouch_obj::nmeGetSupportsTouchEvents( ){
	HX_STACK_PUSH("Multitouch::nmeGetSupportsTouchEvents","neash/ui/Multitouch.hx",52);
	HX_STACK_LINE(52)
	return ::neash::ui::Multitouch_obj::nme_stage_get_multitouch_supported(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeHandle);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Multitouch_obj,nmeGetSupportsTouchEvents,return )

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
		if (HX_FIELD_EQ(inName,"inputMode") ) { return inCallProp ? nmeGetInputMode() : inputMode; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxTouchPoints") ) { return maxTouchPoints; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeGetInputMode") ) { return nmeGetInputMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetInputMode") ) { return nmeSetInputMode_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"supportedGestures") ) { return supportedGestures; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { return inCallProp ? nmeGetSupportsTouchEvents() : supportsTouchEvents; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"supportsGestureEvents") ) { return supportsGestureEvents; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nmeGetSupportsTouchEvents") ) { return nmeGetSupportsTouchEvents_dyn(); }
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
		if (HX_FIELD_EQ(inName,"inputMode") ) { if (inCallProp) return nmeSetInputMode(inValue);inputMode=inValue.Cast< ::neash::ui::MultitouchInputMode >(); return inValue; }
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
	HX_CSTRING("nmeGetInputMode"),
	HX_CSTRING("nmeSetInputMode"),
	HX_CSTRING("nmeGetSupportsTouchEvents"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.ui.Multitouch"), hx::TCanCast< Multitouch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Multitouch_obj::__boot()
{
	nme_stage_get_multitouch_supported= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_multitouch_supported"),(int)1);
	nme_stage_get_multitouch_active= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_multitouch_active"),(int)1);
	nme_stage_set_multitouch_active= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_multitouch_active"),(int)2);
}

} // end namespace neash
} // end namespace ui
