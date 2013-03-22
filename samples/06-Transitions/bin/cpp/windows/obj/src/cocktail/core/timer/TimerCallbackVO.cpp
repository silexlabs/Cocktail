#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_timer_TimerCallbackVO
#include <cocktail/core/timer/TimerCallbackVO.h>
#endif
namespace cocktail{
namespace core{
namespace timer{

Void TimerCallbackVO_obj::__construct()
{
HX_STACK_PUSH("TimerCallbackVO::new","cocktail/core/timer/TimerData.hx",33);
{
	HX_STACK_LINE(34)
	this->callbackTime = (int)0;
	HX_STACK_LINE(35)
	this->called = false;
}
;
	return null();
}

TimerCallbackVO_obj::~TimerCallbackVO_obj() { }

Dynamic TimerCallbackVO_obj::__CreateEmpty() { return  new TimerCallbackVO_obj; }
hx::ObjectPtr< TimerCallbackVO_obj > TimerCallbackVO_obj::__new()
{  hx::ObjectPtr< TimerCallbackVO_obj > result = new TimerCallbackVO_obj();
	result->__construct();
	return result;}

Dynamic TimerCallbackVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimerCallbackVO_obj > result = new TimerCallbackVO_obj();
	result->__construct();
	return result;}


TimerCallbackVO_obj::TimerCallbackVO_obj()
{
}

void TimerCallbackVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TimerCallbackVO);
	HX_MARK_MEMBER_NAME(called,"called");
	HX_MARK_MEMBER_NAME(callbackTime,"callbackTime");
	HX_MARK_MEMBER_NAME(timerCallback,"timerCallback");
	HX_MARK_END_CLASS();
}

void TimerCallbackVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(called,"called");
	HX_VISIT_MEMBER_NAME(callbackTime,"callbackTime");
	HX_VISIT_MEMBER_NAME(timerCallback,"timerCallback");
}

Dynamic TimerCallbackVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"called") ) { return called; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callbackTime") ) { return callbackTime; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"timerCallback") ) { return timerCallback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TimerCallbackVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"called") ) { called=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callbackTime") ) { callbackTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"timerCallback") ) { timerCallback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TimerCallbackVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("called"));
	outFields->push(HX_CSTRING("callbackTime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("called"),
	HX_CSTRING("callbackTime"),
	HX_CSTRING("timerCallback"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TimerCallbackVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TimerCallbackVO_obj::__mClass,"__mClass");
};

Class TimerCallbackVO_obj::__mClass;

void TimerCallbackVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.timer.TimerCallbackVO"), hx::TCanCast< TimerCallbackVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TimerCallbackVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace timer
