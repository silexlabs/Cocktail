#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_CustomEvent
#include <cocktail/core/event/CustomEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void CustomEvent_obj::__construct()
{
HX_STACK_PUSH("CustomEvent::new","cocktail/core/event/CustomEvent.hx",33);
{
	HX_STACK_LINE(33)
	super::__construct();
}
;
	return null();
}

CustomEvent_obj::~CustomEvent_obj() { }

Dynamic CustomEvent_obj::__CreateEmpty() { return  new CustomEvent_obj; }
hx::ObjectPtr< CustomEvent_obj > CustomEvent_obj::__new()
{  hx::ObjectPtr< CustomEvent_obj > result = new CustomEvent_obj();
	result->__construct();
	return result;}

Dynamic CustomEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CustomEvent_obj > result = new CustomEvent_obj();
	result->__construct();
	return result;}

Void CustomEvent_obj::initCustomEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic detailArg){
{
		HX_STACK_PUSH("CustomEvent::initCustomEvent","cocktail/core/event/CustomEvent.hx",50);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(detailArg,"detailArg");
		HX_STACK_LINE(52)
		if (((this->dispatched == true))){
			HX_STACK_LINE(53)
			return null();
		}
		HX_STACK_LINE(57)
		this->initEvent(eventTypeArg,canBubbleArg,cancelableArg);
		HX_STACK_LINE(58)
		this->detail = detailArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(CustomEvent_obj,initCustomEvent,(void))


CustomEvent_obj::CustomEvent_obj()
{
}

void CustomEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CustomEvent);
	HX_MARK_MEMBER_NAME(detail,"detail");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CustomEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(detail,"detail");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CustomEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detail") ) { return detail; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"initCustomEvent") ) { return initCustomEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CustomEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detail") ) { detail=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CustomEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("detail"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initCustomEvent"),
	HX_CSTRING("detail"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CustomEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CustomEvent_obj::__mClass,"__mClass");
};

Class CustomEvent_obj::__mClass;

void CustomEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.CustomEvent"), hx::TCanCast< CustomEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CustomEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
