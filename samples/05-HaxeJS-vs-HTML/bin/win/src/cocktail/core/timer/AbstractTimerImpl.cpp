#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_timer_AbstractTimerImpl
#include <cocktail/core/timer/AbstractTimerImpl.h>
#endif
namespace cocktail{
namespace core{
namespace timer{

Void AbstractTimerImpl_obj::__construct(Dynamic updateCallback)
{
HX_STACK_PUSH("AbstractTimerImpl::new","cocktail/core/timer/AbstractTimerImpl.hx",31);
{
}
;
	return null();
}

AbstractTimerImpl_obj::~AbstractTimerImpl_obj() { }

Dynamic AbstractTimerImpl_obj::__CreateEmpty() { return  new AbstractTimerImpl_obj; }
hx::ObjectPtr< AbstractTimerImpl_obj > AbstractTimerImpl_obj::__new(Dynamic updateCallback)
{  hx::ObjectPtr< AbstractTimerImpl_obj > result = new AbstractTimerImpl_obj();
	result->__construct(updateCallback);
	return result;}

Dynamic AbstractTimerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractTimerImpl_obj > result = new AbstractTimerImpl_obj();
	result->__construct(inArgs[0]);
	return result;}


AbstractTimerImpl_obj::AbstractTimerImpl_obj()
{
}

void AbstractTimerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractTimerImpl);
	HX_MARK_END_CLASS();
}

void AbstractTimerImpl_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic AbstractTimerImpl_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic AbstractTimerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void AbstractTimerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractTimerImpl_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AbstractTimerImpl_obj::__mClass,"__mClass");
};

Class AbstractTimerImpl_obj::__mClass;

void AbstractTimerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.timer.AbstractTimerImpl"), hx::TCanCast< AbstractTimerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AbstractTimerImpl_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace timer
