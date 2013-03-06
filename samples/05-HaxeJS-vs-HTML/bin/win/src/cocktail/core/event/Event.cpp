#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void Event_obj::__construct()
{
HX_STACK_PUSH("Event::new","cocktail/core/event/Event.hx",114);
{
}
;
	return null();
}

Event_obj::~Event_obj() { }

Dynamic Event_obj::__CreateEmpty() { return  new Event_obj; }
hx::ObjectPtr< Event_obj > Event_obj::__new()
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct();
	return result;}

Dynamic Event_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct();
	return result;}

Void Event_obj::stopImmediatePropagation( ){
{
		HX_STACK_PUSH("Event::stopImmediatePropagation","cocktail/core/event/Event.hx",183);
		HX_STACK_THIS(this);
		HX_STACK_LINE(183)
		this->immediatePropagationStopped = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,stopImmediatePropagation,(void))

Void Event_obj::stopPropagation( ){
{
		HX_STACK_PUSH("Event::stopPropagation","cocktail/core/event/Event.hx",173);
		HX_STACK_THIS(this);
		HX_STACK_LINE(173)
		this->propagationStopped = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,stopPropagation,(void))

Void Event_obj::preventDefault( ){
{
		HX_STACK_PUSH("Event::preventDefault","cocktail/core/event/Event.hx",161);
		HX_STACK_THIS(this);
		HX_STACK_LINE(161)
		this->defaultPrevented = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,preventDefault,(void))

Void Event_obj::initEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg){
{
		HX_STACK_PUSH("Event::initEvent","cocktail/core/event/Event.hx",138);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_LINE(140)
		if (((this->dispatched == true))){
			HX_STACK_LINE(141)
			return null();
		}
		HX_STACK_LINE(145)
		this->type = eventTypeArg;
		HX_STACK_LINE(146)
		this->bubbles = canBubbleArg;
		HX_STACK_LINE(147)
		this->cancelable = cancelableArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Event_obj,initEvent,(void))

int Event_obj::CAPTURING_PHASE;

int Event_obj::AT_TARGET;

int Event_obj::BUBBLING_PHASE;


Event_obj::Event_obj()
{
}

void Event_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Event);
	HX_MARK_MEMBER_NAME(dispatched,"dispatched");
	HX_MARK_MEMBER_NAME(immediatePropagationStopped,"immediatePropagationStopped");
	HX_MARK_MEMBER_NAME(propagationStopped,"propagationStopped");
	HX_MARK_MEMBER_NAME(defaultPrevented,"defaultPrevented");
	HX_MARK_MEMBER_NAME(cancelable,"cancelable");
	HX_MARK_MEMBER_NAME(bubbles,"bubbles");
	HX_MARK_MEMBER_NAME(currentTarget,"currentTarget");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(eventPhase,"eventPhase");
	HX_MARK_END_CLASS();
}

void Event_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(dispatched,"dispatched");
	HX_VISIT_MEMBER_NAME(immediatePropagationStopped,"immediatePropagationStopped");
	HX_VISIT_MEMBER_NAME(propagationStopped,"propagationStopped");
	HX_VISIT_MEMBER_NAME(defaultPrevented,"defaultPrevented");
	HX_VISIT_MEMBER_NAME(cancelable,"cancelable");
	HX_VISIT_MEMBER_NAME(bubbles,"bubbles");
	HX_VISIT_MEMBER_NAME(currentTarget,"currentTarget");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(eventPhase,"eventPhase");
}

Dynamic Event_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bubbles") ) { return bubbles; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AT_TARGET") ) { return AT_TARGET; }
		if (HX_FIELD_EQ(inName,"initEvent") ) { return initEvent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dispatched") ) { return dispatched; }
		if (HX_FIELD_EQ(inName,"cancelable") ) { return cancelable; }
		if (HX_FIELD_EQ(inName,"eventPhase") ) { return eventPhase; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentTarget") ) { return currentTarget; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BUBBLING_PHASE") ) { return BUBBLING_PHASE; }
		if (HX_FIELD_EQ(inName,"preventDefault") ) { return preventDefault_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CAPTURING_PHASE") ) { return CAPTURING_PHASE; }
		if (HX_FIELD_EQ(inName,"stopPropagation") ) { return stopPropagation_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"defaultPrevented") ) { return defaultPrevented; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"propagationStopped") ) { return propagationStopped; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"stopImmediatePropagation") ) { return stopImmediatePropagation_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"immediatePropagationStopped") ) { return immediatePropagationStopped; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Event_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::cocktail::core::event::EventTarget >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bubbles") ) { bubbles=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AT_TARGET") ) { AT_TARGET=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dispatched") ) { dispatched=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cancelable") ) { cancelable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"eventPhase") ) { eventPhase=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentTarget") ) { currentTarget=inValue.Cast< ::cocktail::core::event::EventTarget >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BUBBLING_PHASE") ) { BUBBLING_PHASE=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CAPTURING_PHASE") ) { CAPTURING_PHASE=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"defaultPrevented") ) { defaultPrevented=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"propagationStopped") ) { propagationStopped=inValue.Cast< bool >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"immediatePropagationStopped") ) { immediatePropagationStopped=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Event_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("dispatched"));
	outFields->push(HX_CSTRING("immediatePropagationStopped"));
	outFields->push(HX_CSTRING("propagationStopped"));
	outFields->push(HX_CSTRING("defaultPrevented"));
	outFields->push(HX_CSTRING("cancelable"));
	outFields->push(HX_CSTRING("bubbles"));
	outFields->push(HX_CSTRING("currentTarget"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("eventPhase"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CAPTURING_PHASE"),
	HX_CSTRING("AT_TARGET"),
	HX_CSTRING("BUBBLING_PHASE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stopImmediatePropagation"),
	HX_CSTRING("stopPropagation"),
	HX_CSTRING("preventDefault"),
	HX_CSTRING("initEvent"),
	HX_CSTRING("dispatched"),
	HX_CSTRING("immediatePropagationStopped"),
	HX_CSTRING("propagationStopped"),
	HX_CSTRING("defaultPrevented"),
	HX_CSTRING("cancelable"),
	HX_CSTRING("bubbles"),
	HX_CSTRING("currentTarget"),
	HX_CSTRING("target"),
	HX_CSTRING("type"),
	HX_CSTRING("eventPhase"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Event_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Event_obj::CAPTURING_PHASE,"CAPTURING_PHASE");
	HX_MARK_MEMBER_NAME(Event_obj::AT_TARGET,"AT_TARGET");
	HX_MARK_MEMBER_NAME(Event_obj::BUBBLING_PHASE,"BUBBLING_PHASE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Event_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Event_obj::CAPTURING_PHASE,"CAPTURING_PHASE");
	HX_VISIT_MEMBER_NAME(Event_obj::AT_TARGET,"AT_TARGET");
	HX_VISIT_MEMBER_NAME(Event_obj::BUBBLING_PHASE,"BUBBLING_PHASE");
};

Class Event_obj::__mClass;

void Event_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.Event"), hx::TCanCast< Event_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Event_obj::__boot()
{
	CAPTURING_PHASE= (int)1;
	AT_TARGET= (int)2;
	BUBBLING_PHASE= (int)3;
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
