#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TransitionEvent
#include <cocktail/core/event/TransitionEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void TransitionEvent_obj::__construct()
{
HX_STACK_PUSH("TransitionEvent::new","cocktail/core/event/TransitionEvent.hx",49);
{
	HX_STACK_LINE(49)
	super::__construct();
}
;
	return null();
}

TransitionEvent_obj::~TransitionEvent_obj() { }

Dynamic TransitionEvent_obj::__CreateEmpty() { return  new TransitionEvent_obj; }
hx::ObjectPtr< TransitionEvent_obj > TransitionEvent_obj::__new()
{  hx::ObjectPtr< TransitionEvent_obj > result = new TransitionEvent_obj();
	result->__construct();
	return result;}

Dynamic TransitionEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransitionEvent_obj > result = new TransitionEvent_obj();
	result->__construct();
	return result;}

Void TransitionEvent_obj::initTransitionEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,::String propertyNameArg,Float elapsedTimeArg,::String pseudoElementArg){
{
		HX_STACK_PUSH("TransitionEvent::initTransitionEvent","cocktail/core/event/TransitionEvent.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(propertyNameArg,"propertyNameArg");
		HX_STACK_ARG(elapsedTimeArg,"elapsedTimeArg");
		HX_STACK_ARG(pseudoElementArg,"pseudoElementArg");
		HX_STACK_LINE(82)
		if (((this->dispatched == true))){
			HX_STACK_LINE(83)
			return null();
		}
		HX_STACK_LINE(87)
		this->initEvent(eventTypeArg,canBubbleArg,cancelableArg);
		HX_STACK_LINE(89)
		this->propertyName = propertyNameArg;
		HX_STACK_LINE(90)
		this->elapsedTime = elapsedTimeArg;
		HX_STACK_LINE(91)
		this->pseudoElement = pseudoElementArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(TransitionEvent_obj,initTransitionEvent,(void))


TransitionEvent_obj::TransitionEvent_obj()
{
}

void TransitionEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransitionEvent);
	HX_MARK_MEMBER_NAME(pseudoElement,"pseudoElement");
	HX_MARK_MEMBER_NAME(elapsedTime,"elapsedTime");
	HX_MARK_MEMBER_NAME(propertyName,"propertyName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TransitionEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pseudoElement,"pseudoElement");
	HX_VISIT_MEMBER_NAME(elapsedTime,"elapsedTime");
	HX_VISIT_MEMBER_NAME(propertyName,"propertyName");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TransitionEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"elapsedTime") ) { return elapsedTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"propertyName") ) { return propertyName; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pseudoElement") ) { return pseudoElement; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"initTransitionEvent") ) { return initTransitionEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TransitionEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"elapsedTime") ) { elapsedTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"propertyName") ) { propertyName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pseudoElement") ) { pseudoElement=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransitionEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pseudoElement"));
	outFields->push(HX_CSTRING("elapsedTime"));
	outFields->push(HX_CSTRING("propertyName"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initTransitionEvent"),
	HX_CSTRING("pseudoElement"),
	HX_CSTRING("elapsedTime"),
	HX_CSTRING("propertyName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TransitionEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TransitionEvent_obj::__mClass,"__mClass");
};

Class TransitionEvent_obj::__mClass;

void TransitionEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.TransitionEvent"), hx::TCanCast< TransitionEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TransitionEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
