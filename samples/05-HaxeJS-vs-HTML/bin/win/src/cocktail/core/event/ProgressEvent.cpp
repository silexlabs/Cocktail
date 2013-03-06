#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_ProgressEvent
#include <cocktail/core/event/ProgressEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void ProgressEvent_obj::__construct()
{
HX_STACK_PUSH("ProgressEvent::new","cocktail/core/event/ProgressEvent.hx",43);
{
	HX_STACK_LINE(44)
	super::__construct();
	HX_STACK_LINE(46)
	this->lengthComputable = false;
	HX_STACK_LINE(47)
	this->loaded = (int)0;
	HX_STACK_LINE(48)
	this->total = (int)0;
}
;
	return null();
}

ProgressEvent_obj::~ProgressEvent_obj() { }

Dynamic ProgressEvent_obj::__CreateEmpty() { return  new ProgressEvent_obj; }
hx::ObjectPtr< ProgressEvent_obj > ProgressEvent_obj::__new()
{  hx::ObjectPtr< ProgressEvent_obj > result = new ProgressEvent_obj();
	result->__construct();
	return result;}

Dynamic ProgressEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ProgressEvent_obj > result = new ProgressEvent_obj();
	result->__construct();
	return result;}

Void ProgressEvent_obj::initProgressEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,bool lengthComputableArg,Float loadedArg,Float totalArg){
{
		HX_STACK_PUSH("ProgressEvent::initProgressEvent","cocktail/core/event/ProgressEvent.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(lengthComputableArg,"lengthComputableArg");
		HX_STACK_ARG(loadedArg,"loadedArg");
		HX_STACK_ARG(totalArg,"totalArg");
		HX_STACK_LINE(59)
		if (((this->dispatched == true))){
			HX_STACK_LINE(60)
			return null();
		}
		HX_STACK_LINE(64)
		this->initEvent(eventTypeArg,canBubbleArg,cancelableArg);
		HX_STACK_LINE(66)
		this->lengthComputable = lengthComputableArg;
		HX_STACK_LINE(67)
		this->loaded = loadedArg;
		HX_STACK_LINE(68)
		this->total = totalArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(ProgressEvent_obj,initProgressEvent,(void))


ProgressEvent_obj::ProgressEvent_obj()
{
}

void ProgressEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ProgressEvent);
	HX_MARK_MEMBER_NAME(total,"total");
	HX_MARK_MEMBER_NAME(loaded,"loaded");
	HX_MARK_MEMBER_NAME(lengthComputable,"lengthComputable");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ProgressEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(total,"total");
	HX_VISIT_MEMBER_NAME(loaded,"loaded");
	HX_VISIT_MEMBER_NAME(lengthComputable,"lengthComputable");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ProgressEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"total") ) { return total; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { return loaded; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lengthComputable") ) { return lengthComputable; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initProgressEvent") ) { return initProgressEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ProgressEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"total") ) { total=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { loaded=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lengthComputable") ) { lengthComputable=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ProgressEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("total"));
	outFields->push(HX_CSTRING("loaded"));
	outFields->push(HX_CSTRING("lengthComputable"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initProgressEvent"),
	HX_CSTRING("total"),
	HX_CSTRING("loaded"),
	HX_CSTRING("lengthComputable"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ProgressEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ProgressEvent_obj::__mClass,"__mClass");
};

Class ProgressEvent_obj::__mClass;

void ProgressEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.ProgressEvent"), hx::TCanCast< ProgressEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ProgressEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
