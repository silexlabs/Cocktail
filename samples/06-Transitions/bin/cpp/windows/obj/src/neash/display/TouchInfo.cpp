#include <hxcpp.h>

#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_TouchInfo
#include <neash/display/TouchInfo.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
namespace neash{
namespace display{

Void TouchInfo_obj::__construct()
{
HX_STACK_PUSH("TouchInfo::new","neash/display/Stage.hx",926);
{
	HX_STACK_LINE(926)
	this->touchOverObjects = Array_obj< ::neash::display::InteractiveObject >::__new();
}
;
	return null();
}

TouchInfo_obj::~TouchInfo_obj() { }

Dynamic TouchInfo_obj::__CreateEmpty() { return  new TouchInfo_obj; }
hx::ObjectPtr< TouchInfo_obj > TouchInfo_obj::__new()
{  hx::ObjectPtr< TouchInfo_obj > result = new TouchInfo_obj();
	result->__construct();
	return result;}

Dynamic TouchInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchInfo_obj > result = new TouchInfo_obj();
	result->__construct();
	return result;}


TouchInfo_obj::TouchInfo_obj()
{
}

void TouchInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchInfo);
	HX_MARK_MEMBER_NAME(touchOverObjects,"touchOverObjects");
	HX_MARK_END_CLASS();
}

void TouchInfo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(touchOverObjects,"touchOverObjects");
}

Dynamic TouchInfo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"touchOverObjects") ) { return touchOverObjects; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"touchOverObjects") ) { touchOverObjects=inValue.Cast< Array< ::neash::display::InteractiveObject > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("touchOverObjects"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("touchOverObjects"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchInfo_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchInfo_obj::__mClass,"__mClass");
};

Class TouchInfo_obj::__mClass;

void TouchInfo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.TouchInfo"), hx::TCanCast< TouchInfo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TouchInfo_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
