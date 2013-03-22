#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_FocusEvent
#include <cocktail/core/event/FocusEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void FocusEvent_obj::__construct()
{
HX_STACK_PUSH("FocusEvent::new","cocktail/core/event/FocusEvent.hx",30);
{
	HX_STACK_LINE(30)
	super::__construct();
}
;
	return null();
}

FocusEvent_obj::~FocusEvent_obj() { }

Dynamic FocusEvent_obj::__CreateEmpty() { return  new FocusEvent_obj; }
hx::ObjectPtr< FocusEvent_obj > FocusEvent_obj::__new()
{  hx::ObjectPtr< FocusEvent_obj > result = new FocusEvent_obj();
	result->__construct();
	return result;}

Dynamic FocusEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FocusEvent_obj > result = new FocusEvent_obj();
	result->__construct();
	return result;}

Void FocusEvent_obj::initFocusEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,::cocktail::core::event::EventTarget relatedTargetArg){
{
		HX_STACK_PUSH("FocusEvent::initFocusEvent","cocktail/core/event/FocusEvent.hx",50);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(viewArg,"viewArg");
		HX_STACK_ARG(detailArg,"detailArg");
		HX_STACK_ARG(relatedTargetArg,"relatedTargetArg");
		HX_STACK_LINE(52)
		if (((this->dispatched == true))){
			HX_STACK_LINE(53)
			return null();
		}
		HX_STACK_LINE(57)
		this->initUIEvent(eventTypeArg,canBubbleArg,cancelableArg,viewArg,detailArg);
		HX_STACK_LINE(58)
		this->relatedTarget = relatedTargetArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(FocusEvent_obj,initFocusEvent,(void))


FocusEvent_obj::FocusEvent_obj()
{
}

void FocusEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FocusEvent);
	HX_MARK_MEMBER_NAME(relatedTarget,"relatedTarget");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FocusEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(relatedTarget,"relatedTarget");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FocusEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"relatedTarget") ) { return relatedTarget; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initFocusEvent") ) { return initFocusEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FocusEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"relatedTarget") ) { relatedTarget=inValue.Cast< ::cocktail::core::event::EventTarget >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FocusEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("relatedTarget"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initFocusEvent"),
	HX_CSTRING("relatedTarget"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FocusEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FocusEvent_obj::__mClass,"__mClass");
};

Class FocusEvent_obj::__mClass;

void FocusEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.FocusEvent"), hx::TCanCast< FocusEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FocusEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
