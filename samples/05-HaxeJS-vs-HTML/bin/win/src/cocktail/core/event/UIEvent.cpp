#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void UIEvent_obj::__construct()
{
HX_STACK_PUSH("UIEvent::new","cocktail/core/event/UIEvent.hx",36);
{
	HX_STACK_LINE(36)
	super::__construct();
}
;
	return null();
}

UIEvent_obj::~UIEvent_obj() { }

Dynamic UIEvent_obj::__CreateEmpty() { return  new UIEvent_obj; }
hx::ObjectPtr< UIEvent_obj > UIEvent_obj::__new()
{  hx::ObjectPtr< UIEvent_obj > result = new UIEvent_obj();
	result->__construct();
	return result;}

Dynamic UIEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UIEvent_obj > result = new UIEvent_obj();
	result->__construct();
	return result;}

Void UIEvent_obj::initUIEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg){
{
		HX_STACK_PUSH("UIEvent::initUIEvent","cocktail/core/event/UIEvent.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(viewArg,"viewArg");
		HX_STACK_ARG(detailArg,"detailArg");
		HX_STACK_LINE(57)
		if (((this->dispatched == true))){
			HX_STACK_LINE(58)
			return null();
		}
		HX_STACK_LINE(62)
		this->initEvent(eventTypeArg,canBubbleArg,cancelableArg);
		HX_STACK_LINE(63)
		this->view = viewArg;
		HX_STACK_LINE(64)
		this->detail = detailArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(UIEvent_obj,initUIEvent,(void))


UIEvent_obj::UIEvent_obj()
{
}

void UIEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UIEvent);
	HX_MARK_MEMBER_NAME(detail,"detail");
	HX_MARK_MEMBER_NAME(view,"view");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void UIEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(detail,"detail");
	HX_VISIT_MEMBER_NAME(view,"view");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic UIEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detail") ) { return detail; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initUIEvent") ) { return initUIEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UIEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detail") ) { detail=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void UIEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("detail"));
	outFields->push(HX_CSTRING("view"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initUIEvent"),
	HX_CSTRING("detail"),
	HX_CSTRING("view"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UIEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UIEvent_obj::__mClass,"__mClass");
};

Class UIEvent_obj::__mClass;

void UIEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.UIEvent"), hx::TCanCast< UIEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void UIEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
