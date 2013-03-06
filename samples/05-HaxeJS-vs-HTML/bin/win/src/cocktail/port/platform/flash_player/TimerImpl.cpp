#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_timer_AbstractTimerImpl
#include <cocktail/core/timer/AbstractTimerImpl.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_TimerImpl
#include <cocktail/port/platform/flash_player/TimerImpl.h>
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
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void TimerImpl_obj::__construct(Dynamic updateCallback)
{
HX_STACK_PUSH("TimerImpl::new","cocktail/port/platform/flash_player/TimerImpl.hx",25);
{
	HX_STACK_LINE(25)
	Dynamic updateCallback1 = Dynamic( Array_obj<Dynamic>::__new().Add(updateCallback));		HX_STACK_VAR(updateCallback1,"updateCallback1");
	HX_STACK_LINE(27)
	super::__construct(updateCallback1->__GetItem((int)0));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,updateCallback1)
	Void run(Dynamic e){
		HX_STACK_PUSH("*::_Function_1_1","cocktail/port/platform/flash_player/TimerImpl.hx",28);
		HX_STACK_ARG(e,"e");
		{
			HX_STACK_LINE(28)
			updateCallback1->__GetItem((int)0)().Cast< Void >();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(28)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::ENTER_FRAME, Dynamic(new _Function_1_1(updateCallback1)),null(),null(),null());
}
;
	return null();
}

TimerImpl_obj::~TimerImpl_obj() { }

Dynamic TimerImpl_obj::__CreateEmpty() { return  new TimerImpl_obj; }
hx::ObjectPtr< TimerImpl_obj > TimerImpl_obj::__new(Dynamic updateCallback)
{  hx::ObjectPtr< TimerImpl_obj > result = new TimerImpl_obj();
	result->__construct(updateCallback);
	return result;}

Dynamic TimerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimerImpl_obj > result = new TimerImpl_obj();
	result->__construct(inArgs[0]);
	return result;}


TimerImpl_obj::TimerImpl_obj()
{
}

void TimerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TimerImpl);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TimerImpl_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TimerImpl_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic TimerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TimerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TimerImpl_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TimerImpl_obj::__mClass,"__mClass");
};

Class TimerImpl_obj::__mClass;

void TimerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.TimerImpl"), hx::TCanCast< TimerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TimerImpl_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
