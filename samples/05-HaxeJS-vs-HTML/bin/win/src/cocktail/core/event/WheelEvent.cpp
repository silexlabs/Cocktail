#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_WheelEvent
#include <cocktail/core/event/WheelEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void WheelEvent_obj::__construct()
{
HX_STACK_PUSH("WheelEvent::new","cocktail/core/event/WheelEvent.hx",70);
{
	HX_STACK_LINE(70)
	super::__construct();
}
;
	return null();
}

WheelEvent_obj::~WheelEvent_obj() { }

Dynamic WheelEvent_obj::__CreateEmpty() { return  new WheelEvent_obj; }
hx::ObjectPtr< WheelEvent_obj > WheelEvent_obj::__new()
{  hx::ObjectPtr< WheelEvent_obj > result = new WheelEvent_obj();
	result->__construct();
	return result;}

Dynamic WheelEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WheelEvent_obj > result = new WheelEvent_obj();
	result->__construct();
	return result;}

Void WheelEvent_obj::initWheelEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,int screenXArg,int screenYArg,int clientXArg,int clientYArg,int buttonArg,::cocktail::core::event::EventTarget relatedTargetArg,::String modifiersListArg,Float deltaXArg,Float deltaYArg,Float deltaZArg,int deltaModeArg){
{
		HX_STACK_PUSH("WheelEvent::initWheelEvent","cocktail/core/event/WheelEvent.hx",104);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(viewArg,"viewArg");
		HX_STACK_ARG(detailArg,"detailArg");
		HX_STACK_ARG(screenXArg,"screenXArg");
		HX_STACK_ARG(screenYArg,"screenYArg");
		HX_STACK_ARG(clientXArg,"clientXArg");
		HX_STACK_ARG(clientYArg,"clientYArg");
		HX_STACK_ARG(buttonArg,"buttonArg");
		HX_STACK_ARG(relatedTargetArg,"relatedTargetArg");
		HX_STACK_ARG(modifiersListArg,"modifiersListArg");
		HX_STACK_ARG(deltaXArg,"deltaXArg");
		HX_STACK_ARG(deltaYArg,"deltaYArg");
		HX_STACK_ARG(deltaZArg,"deltaZArg");
		HX_STACK_ARG(deltaModeArg,"deltaModeArg");
		HX_STACK_LINE(106)
		if (((this->dispatched == true))){
			HX_STACK_LINE(107)
			return null();
		}
		HX_STACK_LINE(111)
		this->initMouseEvent(eventTypeArg,canBubbleArg,cancelableArg,viewArg,detailArg,screenXArg,screenYArg,clientXArg,clientYArg,false,false,false,false,buttonArg,relatedTargetArg);
		HX_STACK_LINE(114)
		this->deltaY = deltaYArg;
		HX_STACK_LINE(115)
		this->deltaX = deltaXArg;
		HX_STACK_LINE(116)
		this->deltaMode = deltaModeArg;
		HX_STACK_LINE(117)
		this->deltaZ = deltaZArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC16(WheelEvent_obj,initWheelEvent,(void))

int WheelEvent_obj::DOM_DELTA_PIXEL;

int WheelEvent_obj::DOM_DELTA_LINE;

int WheelEvent_obj::DOM_DELTA_PAGE;


WheelEvent_obj::WheelEvent_obj()
{
}

void WheelEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WheelEvent);
	HX_MARK_MEMBER_NAME(deltaMode,"deltaMode");
	HX_MARK_MEMBER_NAME(deltaZ,"deltaZ");
	HX_MARK_MEMBER_NAME(deltaY,"deltaY");
	HX_MARK_MEMBER_NAME(deltaX,"deltaX");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void WheelEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(deltaMode,"deltaMode");
	HX_VISIT_MEMBER_NAME(deltaZ,"deltaZ");
	HX_VISIT_MEMBER_NAME(deltaY,"deltaY");
	HX_VISIT_MEMBER_NAME(deltaX,"deltaX");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic WheelEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"deltaZ") ) { return deltaZ; }
		if (HX_FIELD_EQ(inName,"deltaY") ) { return deltaY; }
		if (HX_FIELD_EQ(inName,"deltaX") ) { return deltaX; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"deltaMode") ) { return deltaMode; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"DOM_DELTA_LINE") ) { return DOM_DELTA_LINE; }
		if (HX_FIELD_EQ(inName,"DOM_DELTA_PAGE") ) { return DOM_DELTA_PAGE; }
		if (HX_FIELD_EQ(inName,"initWheelEvent") ) { return initWheelEvent_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"DOM_DELTA_PIXEL") ) { return DOM_DELTA_PIXEL; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WheelEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"deltaZ") ) { deltaZ=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"deltaY") ) { deltaY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"deltaX") ) { deltaX=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"deltaMode") ) { deltaMode=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"DOM_DELTA_LINE") ) { DOM_DELTA_LINE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOM_DELTA_PAGE") ) { DOM_DELTA_PAGE=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"DOM_DELTA_PIXEL") ) { DOM_DELTA_PIXEL=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WheelEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("deltaMode"));
	outFields->push(HX_CSTRING("deltaZ"));
	outFields->push(HX_CSTRING("deltaY"));
	outFields->push(HX_CSTRING("deltaX"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DOM_DELTA_PIXEL"),
	HX_CSTRING("DOM_DELTA_LINE"),
	HX_CSTRING("DOM_DELTA_PAGE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initWheelEvent"),
	HX_CSTRING("deltaMode"),
	HX_CSTRING("deltaZ"),
	HX_CSTRING("deltaY"),
	HX_CSTRING("deltaX"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WheelEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(WheelEvent_obj::DOM_DELTA_PIXEL,"DOM_DELTA_PIXEL");
	HX_MARK_MEMBER_NAME(WheelEvent_obj::DOM_DELTA_LINE,"DOM_DELTA_LINE");
	HX_MARK_MEMBER_NAME(WheelEvent_obj::DOM_DELTA_PAGE,"DOM_DELTA_PAGE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WheelEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(WheelEvent_obj::DOM_DELTA_PIXEL,"DOM_DELTA_PIXEL");
	HX_VISIT_MEMBER_NAME(WheelEvent_obj::DOM_DELTA_LINE,"DOM_DELTA_LINE");
	HX_VISIT_MEMBER_NAME(WheelEvent_obj::DOM_DELTA_PAGE,"DOM_DELTA_PAGE");
};

Class WheelEvent_obj::__mClass;

void WheelEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.WheelEvent"), hx::TCanCast< WheelEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void WheelEvent_obj::__boot()
{
	DOM_DELTA_PIXEL= (int)0;
	DOM_DELTA_LINE= (int)1;
	DOM_DELTA_PAGE= (int)2;
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
