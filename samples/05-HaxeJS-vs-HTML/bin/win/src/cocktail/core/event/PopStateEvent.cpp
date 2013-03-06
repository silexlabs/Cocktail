#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_PopStateEvent
#include <cocktail/core/event/PopStateEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void PopStateEvent_obj::__construct()
{
HX_STACK_PUSH("PopStateEvent::new","cocktail/core/event/PopStateEvent.hx",26);
{
	HX_STACK_LINE(26)
	super::__construct();
}
;
	return null();
}

PopStateEvent_obj::~PopStateEvent_obj() { }

Dynamic PopStateEvent_obj::__CreateEmpty() { return  new PopStateEvent_obj; }
hx::ObjectPtr< PopStateEvent_obj > PopStateEvent_obj::__new()
{  hx::ObjectPtr< PopStateEvent_obj > result = new PopStateEvent_obj();
	result->__construct();
	return result;}

Dynamic PopStateEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PopStateEvent_obj > result = new PopStateEvent_obj();
	result->__construct();
	return result;}

Void PopStateEvent_obj::initPopStateEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,Dynamic state){
{
		HX_STACK_PUSH("PopStateEvent::initPopStateEvent","cocktail/core/event/PopStateEvent.hx",35);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(viewArg,"viewArg");
		HX_STACK_ARG(detailArg,"detailArg");
		HX_STACK_ARG(state,"state");
		HX_STACK_LINE(37)
		if (((this->dispatched == true))){
			HX_STACK_LINE(38)
			return null();
		}
		HX_STACK_LINE(42)
		this->initUIEvent(eventTypeArg,canBubbleArg,cancelableArg,viewArg,detailArg);
		HX_STACK_LINE(43)
		this->state = state;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(PopStateEvent_obj,initPopStateEvent,(void))


PopStateEvent_obj::PopStateEvent_obj()
{
}

void PopStateEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PopStateEvent);
	HX_MARK_MEMBER_NAME(state,"state");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PopStateEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(state,"state");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic PopStateEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initPopStateEvent") ) { return initPopStateEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PopStateEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PopStateEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("state"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initPopStateEvent"),
	HX_CSTRING("state"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PopStateEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PopStateEvent_obj::__mClass,"__mClass");
};

Class PopStateEvent_obj::__mClass;

void PopStateEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.PopStateEvent"), hx::TCanCast< PopStateEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PopStateEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
