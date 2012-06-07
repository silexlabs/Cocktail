#include <hxcpp.h>

#ifndef INCLUDED_nme_events_EventPhase
#include <nme/events/EventPhase.h>
#endif
namespace nme{
namespace events{

Void EventPhase_obj::__construct()
{
	return null();
}

EventPhase_obj::~EventPhase_obj() { }

Dynamic EventPhase_obj::__CreateEmpty() { return  new EventPhase_obj; }
hx::ObjectPtr< EventPhase_obj > EventPhase_obj::__new()
{  hx::ObjectPtr< EventPhase_obj > result = new EventPhase_obj();
	result->__construct();
	return result;}

Dynamic EventPhase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventPhase_obj > result = new EventPhase_obj();
	result->__construct();
	return result;}

int EventPhase_obj::CAPTURING_PHASE;

int EventPhase_obj::AT_TARGET;

int EventPhase_obj::BUBBLING_PHASE;


EventPhase_obj::EventPhase_obj()
{
}

void EventPhase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventPhase);
	HX_MARK_END_CLASS();
}

Dynamic EventPhase_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"AT_TARGET") ) { return AT_TARGET; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BUBBLING_PHASE") ) { return BUBBLING_PHASE; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CAPTURING_PHASE") ) { return CAPTURING_PHASE; }
	}
	return super::__Field(inName);
}

Dynamic EventPhase_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"AT_TARGET") ) { AT_TARGET=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BUBBLING_PHASE") ) { BUBBLING_PHASE=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CAPTURING_PHASE") ) { CAPTURING_PHASE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EventPhase_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CAPTURING_PHASE"),
	HX_CSTRING("AT_TARGET"),
	HX_CSTRING("BUBBLING_PHASE"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventPhase_obj::CAPTURING_PHASE,"CAPTURING_PHASE");
	HX_MARK_MEMBER_NAME(EventPhase_obj::AT_TARGET,"AT_TARGET");
	HX_MARK_MEMBER_NAME(EventPhase_obj::BUBBLING_PHASE,"BUBBLING_PHASE");
};

Class EventPhase_obj::__mClass;

void EventPhase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.EventPhase"), hx::TCanCast< EventPhase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EventPhase_obj::__boot()
{
	hx::Static(CAPTURING_PHASE) = (int)0;
	hx::Static(AT_TARGET) = (int)1;
	hx::Static(BUBBLING_PHASE) = (int)2;
}

} // end namespace nme
} // end namespace events
