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
namespace cocktail{
namespace core{
namespace event{

Void MouseEvent_obj::__construct()
{
HX_STACK_PUSH("MouseEvent::new","cocktail/core/event/MouseEvent.hx",106);
{
	HX_STACK_LINE(106)
	super::__construct();
}
;
	return null();
}

MouseEvent_obj::~MouseEvent_obj() { }

Dynamic MouseEvent_obj::__CreateEmpty() { return  new MouseEvent_obj; }
hx::ObjectPtr< MouseEvent_obj > MouseEvent_obj::__new()
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct();
	return result;}

Dynamic MouseEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct();
	return result;}

Void MouseEvent_obj::initMouseEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,Float detailArg,int screenXArg,int screenYArg,int clientXArg,int clientYArg,bool ctrlKeyArg,bool altKeyArg,bool shiftKeyArg,bool metaKeyArg,int buttonArg,::cocktail::core::event::EventTarget relatedTargeArg){
{
		HX_STACK_PUSH("MouseEvent::initMouseEvent","cocktail/core/event/MouseEvent.hx",137);
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
		HX_STACK_ARG(ctrlKeyArg,"ctrlKeyArg");
		HX_STACK_ARG(altKeyArg,"altKeyArg");
		HX_STACK_ARG(shiftKeyArg,"shiftKeyArg");
		HX_STACK_ARG(metaKeyArg,"metaKeyArg");
		HX_STACK_ARG(buttonArg,"buttonArg");
		HX_STACK_ARG(relatedTargeArg,"relatedTargeArg");
		HX_STACK_LINE(139)
		if (((this->dispatched == true))){
			HX_STACK_LINE(140)
			return null();
		}
		HX_STACK_LINE(144)
		this->initUIEvent(eventTypeArg,canBubbleArg,cancelableArg,viewArg,detailArg);
		HX_STACK_LINE(145)
		this->screenX = screenXArg;
		HX_STACK_LINE(146)
		this->screenY = screenYArg;
		HX_STACK_LINE(147)
		this->clientX = clientXArg;
		HX_STACK_LINE(148)
		this->clientY = clientYArg;
		HX_STACK_LINE(149)
		this->ctrlKey = ctrlKeyArg;
		HX_STACK_LINE(150)
		this->shiftKey = shiftKeyArg;
		HX_STACK_LINE(151)
		this->altKey = altKeyArg;
		HX_STACK_LINE(152)
		this->metaKey = metaKeyArg;
		HX_STACK_LINE(153)
		this->button = buttonArg;
		HX_STACK_LINE(154)
		this->relatedTarget = relatedTargeArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC15(MouseEvent_obj,initMouseEvent,(void))


MouseEvent_obj::MouseEvent_obj()
{
}

void MouseEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MouseEvent);
	HX_MARK_MEMBER_NAME(relatedTarget,"relatedTarget");
	HX_MARK_MEMBER_NAME(button,"button");
	HX_MARK_MEMBER_NAME(metaKey,"metaKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(clientY,"clientY");
	HX_MARK_MEMBER_NAME(clientX,"clientX");
	HX_MARK_MEMBER_NAME(screenY,"screenY");
	HX_MARK_MEMBER_NAME(screenX,"screenX");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MouseEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(relatedTarget,"relatedTarget");
	HX_VISIT_MEMBER_NAME(button,"button");
	HX_VISIT_MEMBER_NAME(metaKey,"metaKey");
	HX_VISIT_MEMBER_NAME(altKey,"altKey");
	HX_VISIT_MEMBER_NAME(shiftKey,"shiftKey");
	HX_VISIT_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_VISIT_MEMBER_NAME(clientY,"clientY");
	HX_VISIT_MEMBER_NAME(clientX,"clientX");
	HX_VISIT_MEMBER_NAME(screenY,"screenY");
	HX_VISIT_MEMBER_NAME(screenX,"screenX");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MouseEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"button") ) { return button; }
		if (HX_FIELD_EQ(inName,"altKey") ) { return altKey; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"metaKey") ) { return metaKey; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ctrlKey; }
		if (HX_FIELD_EQ(inName,"clientY") ) { return clientY; }
		if (HX_FIELD_EQ(inName,"clientX") ) { return clientX; }
		if (HX_FIELD_EQ(inName,"screenY") ) { return screenY; }
		if (HX_FIELD_EQ(inName,"screenX") ) { return screenX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"relatedTarget") ) { return relatedTarget; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initMouseEvent") ) { return initMouseEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MouseEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"button") ) { button=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"metaKey") ) { metaKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientY") ) { clientY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientX") ) { clientX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screenY") ) { screenY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screenX") ) { screenX=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"relatedTarget") ) { relatedTarget=inValue.Cast< ::cocktail::core::event::EventTarget >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MouseEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("relatedTarget"));
	outFields->push(HX_CSTRING("button"));
	outFields->push(HX_CSTRING("metaKey"));
	outFields->push(HX_CSTRING("altKey"));
	outFields->push(HX_CSTRING("shiftKey"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("clientY"));
	outFields->push(HX_CSTRING("clientX"));
	outFields->push(HX_CSTRING("screenY"));
	outFields->push(HX_CSTRING("screenX"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initMouseEvent"),
	HX_CSTRING("relatedTarget"),
	HX_CSTRING("button"),
	HX_CSTRING("metaKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("clientY"),
	HX_CSTRING("clientX"),
	HX_CSTRING("screenY"),
	HX_CSTRING("screenX"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MouseEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MouseEvent_obj::__mClass,"__mClass");
};

Class MouseEvent_obj::__mClass;

void MouseEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.MouseEvent"), hx::TCanCast< MouseEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MouseEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
