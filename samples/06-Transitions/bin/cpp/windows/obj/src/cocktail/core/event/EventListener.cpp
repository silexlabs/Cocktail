#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventListener
#include <cocktail/core/event/EventListener.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void EventListener_obj::__construct(::String eventType,Dynamic listener,bool useCapture)
{
HX_STACK_PUSH("EventListener::new","cocktail/core/event/EventListener.hx",42);
{
	HX_STACK_LINE(43)
	this->listener = listener;
	HX_STACK_LINE(44)
	this->useCapture = useCapture;
	HX_STACK_LINE(45)
	this->eventType = eventType;
}
;
	return null();
}

EventListener_obj::~EventListener_obj() { }

Dynamic EventListener_obj::__CreateEmpty() { return  new EventListener_obj; }
hx::ObjectPtr< EventListener_obj > EventListener_obj::__new(::String eventType,Dynamic listener,bool useCapture)
{  hx::ObjectPtr< EventListener_obj > result = new EventListener_obj();
	result->__construct(eventType,listener,useCapture);
	return result;}

Dynamic EventListener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventListener_obj > result = new EventListener_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void EventListener_obj::handleEvent( ::cocktail::core::event::Event evt){
{
		HX_STACK_PUSH("EventListener::handleEvent","cocktail/core/event/EventListener.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(evt,"evt");
		HX_STACK_LINE(60)
		this->listener(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EventListener_obj,handleEvent,(void))


EventListener_obj::EventListener_obj()
{
}

void EventListener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventListener);
	HX_MARK_MEMBER_NAME(eventType,"eventType");
	HX_MARK_MEMBER_NAME(listener,"listener");
	HX_MARK_MEMBER_NAME(useCapture,"useCapture");
	HX_MARK_END_CLASS();
}

void EventListener_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(eventType,"eventType");
	HX_VISIT_MEMBER_NAME(listener,"listener");
	HX_VISIT_MEMBER_NAME(useCapture,"useCapture");
}

Dynamic EventListener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { return listener; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"eventType") ) { return eventType; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useCapture") ) { return useCapture; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"handleEvent") ) { return handleEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventListener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"eventType") ) { eventType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"useCapture") ) { useCapture=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventListener_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("eventType"));
	outFields->push(HX_CSTRING("useCapture"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("handleEvent"),
	HX_CSTRING("eventType"),
	HX_CSTRING("listener"),
	HX_CSTRING("useCapture"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventListener_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventListener_obj::__mClass,"__mClass");
};

Class EventListener_obj::__mClass;

void EventListener_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.EventListener"), hx::TCanCast< EventListener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EventListener_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
