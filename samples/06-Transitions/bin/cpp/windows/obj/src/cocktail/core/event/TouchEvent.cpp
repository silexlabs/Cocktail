#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchEvent
#include <cocktail/core/event/TouchEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchList
#include <cocktail/core/event/TouchList.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void TouchEvent_obj::__construct()
{
HX_STACK_PUSH("TouchEvent::new","cocktail/core/event/TouchEvent.hx",63);
{
	HX_STACK_LINE(63)
	super::__construct();
}
;
	return null();
}

TouchEvent_obj::~TouchEvent_obj() { }

Dynamic TouchEvent_obj::__CreateEmpty() { return  new TouchEvent_obj; }
hx::ObjectPtr< TouchEvent_obj > TouchEvent_obj::__new()
{  hx::ObjectPtr< TouchEvent_obj > result = new TouchEvent_obj();
	result->__construct();
	return result;}

Dynamic TouchEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchEvent_obj > result = new TouchEvent_obj();
	result->__construct();
	return result;}

Void TouchEvent_obj::initTouchEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,::cocktail::core::event::TouchList touchesArg,::cocktail::core::event::TouchList targetTouchesArg,::cocktail::core::event::TouchList changedTouchesArg,bool altKeyArg,bool metaKeyArg,bool ctrlKeyArg,bool shiftKeyArg){
{
		HX_STACK_PUSH("TouchEvent::initTouchEvent","cocktail/core/event/TouchEvent.hx",78);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(viewArg,"viewArg");
		HX_STACK_ARG(detailArg,"detailArg");
		HX_STACK_ARG(touchesArg,"touchesArg");
		HX_STACK_ARG(targetTouchesArg,"targetTouchesArg");
		HX_STACK_ARG(changedTouchesArg,"changedTouchesArg");
		HX_STACK_ARG(altKeyArg,"altKeyArg");
		HX_STACK_ARG(metaKeyArg,"metaKeyArg");
		HX_STACK_ARG(ctrlKeyArg,"ctrlKeyArg");
		HX_STACK_ARG(shiftKeyArg,"shiftKeyArg");
		HX_STACK_LINE(80)
		if (((this->dispatched == true))){
			HX_STACK_LINE(81)
			return null();
		}
		HX_STACK_LINE(85)
		this->initUIEvent(eventTypeArg,canBubbleArg,cancelableArg,viewArg,detailArg);
		HX_STACK_LINE(86)
		this->touches = touchesArg;
		HX_STACK_LINE(87)
		targetTouchesArg = this->targetTouches;
		HX_STACK_LINE(88)
		this->changedTouches = changedTouchesArg;
		HX_STACK_LINE(89)
		this->altKey = altKeyArg;
		HX_STACK_LINE(90)
		this->metaKey = metaKeyArg;
		HX_STACK_LINE(91)
		this->ctrlKey = ctrlKeyArg;
		HX_STACK_LINE(92)
		this->shiftKey = shiftKeyArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC12(TouchEvent_obj,initTouchEvent,(void))


TouchEvent_obj::TouchEvent_obj()
{
}

void TouchEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchEvent);
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(metaKey,"metaKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	HX_MARK_MEMBER_NAME(changedTouches,"changedTouches");
	HX_MARK_MEMBER_NAME(targetTouches,"targetTouches");
	HX_MARK_MEMBER_NAME(touches,"touches");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TouchEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shiftKey,"shiftKey");
	HX_VISIT_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_VISIT_MEMBER_NAME(metaKey,"metaKey");
	HX_VISIT_MEMBER_NAME(altKey,"altKey");
	HX_VISIT_MEMBER_NAME(changedTouches,"changedTouches");
	HX_VISIT_MEMBER_NAME(targetTouches,"targetTouches");
	HX_VISIT_MEMBER_NAME(touches,"touches");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TouchEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"altKey") ) { return altKey; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ctrlKey; }
		if (HX_FIELD_EQ(inName,"metaKey") ) { return metaKey; }
		if (HX_FIELD_EQ(inName,"touches") ) { return touches; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"targetTouches") ) { return targetTouches; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initTouchEvent") ) { return initTouchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"changedTouches") ) { return changedTouches; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TouchEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"metaKey") ) { metaKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touches") ) { touches=inValue.Cast< ::cocktail::core::event::TouchList >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"targetTouches") ) { targetTouches=inValue.Cast< ::cocktail::core::event::TouchList >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"changedTouches") ) { changedTouches=inValue.Cast< ::cocktail::core::event::TouchList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TouchEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shiftKey"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("metaKey"));
	outFields->push(HX_CSTRING("altKey"));
	outFields->push(HX_CSTRING("changedTouches"));
	outFields->push(HX_CSTRING("targetTouches"));
	outFields->push(HX_CSTRING("touches"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initTouchEvent"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("metaKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("changedTouches"),
	HX_CSTRING("targetTouches"),
	HX_CSTRING("touches"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TouchEvent_obj::__mClass,"__mClass");
};

Class TouchEvent_obj::__mClass;

void TouchEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.TouchEvent"), hx::TCanCast< TouchEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TouchEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
