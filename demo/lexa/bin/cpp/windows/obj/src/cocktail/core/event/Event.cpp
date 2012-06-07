#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void Event_obj::__construct(::String type,::cocktail::core::event::IEventTarget target)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/event/Event.hx",66)
	this->_type = type;
	HX_SOURCE_POS("../../src/cocktail/core/event/Event.hx",67)
	this->_target = target;
}
;
	return null();
}

Event_obj::~Event_obj() { }

Dynamic Event_obj::__CreateEmpty() { return  new Event_obj; }
hx::ObjectPtr< Event_obj > Event_obj::__new(::String type,::cocktail::core::event::IEventTarget target)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(type,target);
	return result;}

Dynamic Event_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Event_obj::preventDefault( ){
{
		HX_SOURCE_PUSH("Event_obj::preventDefault")
		HX_SOURCE_POS("../../src/cocktail/core/event/Event.hx",90)
		this->_defaultPrevented = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,preventDefault,(void))

bool Event_obj::get_defaultPrevented( ){
	HX_SOURCE_PUSH("Event_obj::get_defaultPrevented")
	HX_SOURCE_POS("../../src/cocktail/core/event/Event.hx",99)
	return this->_defaultPrevented;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,get_defaultPrevented,return )

::String Event_obj::get_type( ){
	HX_SOURCE_PUSH("Event_obj::get_type")
	HX_SOURCE_POS("../../src/cocktail/core/event/Event.hx",104)
	return this->_type;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,get_type,return )

::cocktail::core::event::IEventTarget Event_obj::get_target( ){
	HX_SOURCE_PUSH("Event_obj::get_target")
	HX_SOURCE_POS("../../src/cocktail/core/event/Event.hx",109)
	return this->_target;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,get_target,return )

::String Event_obj::SCROLL;

::String Event_obj::LOAD;

::String Event_obj::FOCUS;

::String Event_obj::BLUR;

::String Event_obj::ERROR;

::String Event_obj::READY_STATE_CHANGE;

::String Event_obj::RESIZE;


Event_obj::Event_obj()
{
}

void Event_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Event);
	HX_MARK_MEMBER_NAME(_type,"_type");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(_target,"_target");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(_defaultPrevented,"_defaultPrevented");
	HX_MARK_MEMBER_NAME(defaultPrevented,"defaultPrevented");
	HX_MARK_END_CLASS();
}

Dynamic Event_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"LOAD") ) { return LOAD; }
		if (HX_FIELD_EQ(inName,"BLUR") ) { return BLUR; }
		if (HX_FIELD_EQ(inName,"type") ) { return get_type(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"FOCUS") ) { return FOCUS; }
		if (HX_FIELD_EQ(inName,"ERROR") ) { return ERROR; }
		if (HX_FIELD_EQ(inName,"_type") ) { return _type; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SCROLL") ) { return SCROLL; }
		if (HX_FIELD_EQ(inName,"RESIZE") ) { return RESIZE; }
		if (HX_FIELD_EQ(inName,"target") ) { return get_target(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_target") ) { return _target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_target") ) { return get_target_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"preventDefault") ) { return preventDefault_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"defaultPrevented") ) { return get_defaultPrevented(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_defaultPrevented") ) { return _defaultPrevented; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"READY_STATE_CHANGE") ) { return READY_STATE_CHANGE; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_defaultPrevented") ) { return get_defaultPrevented_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Event_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"LOAD") ) { LOAD=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLUR") ) { BLUR=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"FOCUS") ) { FOCUS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ERROR") ) { ERROR=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_type") ) { _type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SCROLL") ) { SCROLL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RESIZE") ) { RESIZE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::cocktail::core::event::IEventTarget >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_target") ) { _target=inValue.Cast< ::cocktail::core::event::IEventTarget >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"defaultPrevented") ) { defaultPrevented=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_defaultPrevented") ) { _defaultPrevented=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"READY_STATE_CHANGE") ) { READY_STATE_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Event_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_type"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("_target"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("_defaultPrevented"));
	outFields->push(HX_CSTRING("defaultPrevented"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SCROLL"),
	HX_CSTRING("LOAD"),
	HX_CSTRING("FOCUS"),
	HX_CSTRING("BLUR"),
	HX_CSTRING("ERROR"),
	HX_CSTRING("READY_STATE_CHANGE"),
	HX_CSTRING("RESIZE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_type"),
	HX_CSTRING("type"),
	HX_CSTRING("_target"),
	HX_CSTRING("target"),
	HX_CSTRING("_defaultPrevented"),
	HX_CSTRING("defaultPrevented"),
	HX_CSTRING("preventDefault"),
	HX_CSTRING("get_defaultPrevented"),
	HX_CSTRING("get_type"),
	HX_CSTRING("get_target"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Event_obj::SCROLL,"SCROLL");
	HX_MARK_MEMBER_NAME(Event_obj::LOAD,"LOAD");
	HX_MARK_MEMBER_NAME(Event_obj::FOCUS,"FOCUS");
	HX_MARK_MEMBER_NAME(Event_obj::BLUR,"BLUR");
	HX_MARK_MEMBER_NAME(Event_obj::ERROR,"ERROR");
	HX_MARK_MEMBER_NAME(Event_obj::READY_STATE_CHANGE,"READY_STATE_CHANGE");
	HX_MARK_MEMBER_NAME(Event_obj::RESIZE,"RESIZE");
};

Class Event_obj::__mClass;

void Event_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.Event"), hx::TCanCast< Event_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Event_obj::__boot()
{
	hx::Static(SCROLL) = HX_CSTRING("scroll");
	hx::Static(LOAD) = HX_CSTRING("load");
	hx::Static(FOCUS) = HX_CSTRING("focus");
	hx::Static(BLUR) = HX_CSTRING("blur");
	hx::Static(ERROR) = HX_CSTRING("error");
	hx::Static(READY_STATE_CHANGE) = HX_CSTRING("readystatechange");
	hx::Static(RESIZE) = HX_CSTRING("resize");
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
