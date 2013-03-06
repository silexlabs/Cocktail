#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_AbstractTimerImpl
#include <cocktail/core/timer/AbstractTimerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_TimerCallbackVO
#include <cocktail/core/timer/TimerCallbackVO.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_TimerImpl
#include <cocktail/port/platform/flash_player/TimerImpl.h>
#endif
namespace cocktail{
namespace core{
namespace timer{

Void Timer_obj::__construct()
{
HX_STACK_PUSH("Timer::new","cocktail/core/timer/Timer.hx",45);
{
	HX_STACK_LINE(46)
	this->_pendingCallbacks = Array_obj< ::cocktail::core::timer::TimerCallbackVO >::__new();
	HX_STACK_LINE(47)
	this->_pendingCount = (int)0;
	HX_STACK_LINE(51)
	this->_timerImpl = ::cocktail::port::platform::flash_player::TimerImpl_obj::__new(this->onUpdate_dyn());
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new()
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct();
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct();
	return result;}

Void Timer_obj::onUpdate( ){
{
		HX_STACK_PUSH("Timer::onUpdate","cocktail/core/timer/Timer.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_LINE(106)
		if (((this->_pendingCount > (int)0))){
			HX_STACK_LINE(110)
			Float time = ::Date_obj::now()->getTime();		HX_STACK_VAR(time,"time");
			HX_STACK_LINE(112)
			int length = this->_pendingCallbacks->length;		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(113)
			{
				HX_STACK_LINE(113)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(113)
				while(((_g < length))){
					HX_STACK_LINE(113)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(115)
					::cocktail::core::timer::TimerCallbackVO pendingCallback = this->_pendingCallbacks->__get(i);		HX_STACK_VAR(pendingCallback,"pendingCallback");
					HX_STACK_LINE(119)
					if (((bool((pendingCallback->callbackTime < time)) && bool((pendingCallback->called == false))))){
						HX_STACK_LINE(123)
						pendingCallback->timerCallback(time);
						HX_STACK_LINE(127)
						pendingCallback->called = true;
						HX_STACK_LINE(131)
						(this->_pendingCount)--;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,onUpdate,(void))

Void Timer_obj::delay( Dynamic timerCallback,hx::Null< Float >  __o_delay){
Float delay = __o_delay.Default(0);
	HX_STACK_PUSH("Timer::delay","cocktail/core/timer/Timer.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_ARG(timerCallback,"timerCallback");
	HX_STACK_ARG(delay,"delay");
{
		HX_STACK_LINE(68)
		(this->_pendingCount)++;
		HX_STACK_LINE(72)
		Float callbackTime = (::Date_obj::now()->getTime() + delay);		HX_STACK_VAR(callbackTime,"callbackTime");
		HX_STACK_LINE(75)
		int length = this->_pendingCallbacks->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(76)
		{
			HX_STACK_LINE(76)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(76)
			while(((_g < length))){
				HX_STACK_LINE(76)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(78)
				::cocktail::core::timer::TimerCallbackVO pendingCallback = this->_pendingCallbacks->__get(i);		HX_STACK_VAR(pendingCallback,"pendingCallback");
				HX_STACK_LINE(80)
				if (((pendingCallback->called == true))){
					HX_STACK_LINE(82)
					pendingCallback->called = false;
					HX_STACK_LINE(83)
					pendingCallback->callbackTime = callbackTime;
					HX_STACK_LINE(84)
					pendingCallback->timerCallback = timerCallback;
					HX_STACK_LINE(85)
					return null();
				}
			}
		}
		HX_STACK_LINE(90)
		::cocktail::core::timer::TimerCallbackVO newTimerCallback = ::cocktail::core::timer::TimerCallbackVO_obj::__new();		HX_STACK_VAR(newTimerCallback,"newTimerCallback");
		HX_STACK_LINE(91)
		newTimerCallback->called = false;
		HX_STACK_LINE(92)
		newTimerCallback->callbackTime = callbackTime;
		HX_STACK_LINE(93)
		newTimerCallback->timerCallback = timerCallback;
		HX_STACK_LINE(94)
		this->_pendingCallbacks->push(newTimerCallback);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,delay,(void))


Timer_obj::Timer_obj()
{
}

void Timer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Timer);
	HX_MARK_MEMBER_NAME(_timerImpl,"_timerImpl");
	HX_MARK_MEMBER_NAME(_pendingCount,"_pendingCount");
	HX_MARK_MEMBER_NAME(_pendingCallbacks,"_pendingCallbacks");
	HX_MARK_END_CLASS();
}

void Timer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_timerImpl,"_timerImpl");
	HX_VISIT_MEMBER_NAME(_pendingCount,"_pendingCount");
	HX_VISIT_MEMBER_NAME(_pendingCallbacks,"_pendingCallbacks");
}

Dynamic Timer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { return delay_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_timerImpl") ) { return _timerImpl; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_pendingCount") ) { return _pendingCount; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_pendingCallbacks") ) { return _pendingCallbacks; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_timerImpl") ) { _timerImpl=inValue.Cast< ::cocktail::port::platform::flash_player::TimerImpl >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_pendingCount") ) { _pendingCount=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_pendingCallbacks") ) { _pendingCallbacks=inValue.Cast< Array< ::cocktail::core::timer::TimerCallbackVO > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_timerImpl"));
	outFields->push(HX_CSTRING("_pendingCount"));
	outFields->push(HX_CSTRING("_pendingCallbacks"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onUpdate"),
	HX_CSTRING("delay"),
	HX_CSTRING("_timerImpl"),
	HX_CSTRING("_pendingCount"),
	HX_CSTRING("_pendingCallbacks"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Timer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Timer_obj::__mClass,"__mClass");
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.timer.Timer"), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace timer
