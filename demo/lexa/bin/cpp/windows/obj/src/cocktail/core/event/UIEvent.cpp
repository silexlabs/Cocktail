#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void UIEvent_obj::__construct(::String type,::cocktail::port::flash_player::HTMLElement target,double detail)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/event/UIEvent.hx",28)
	this->_detail = detail;
	HX_SOURCE_POS("../../src/cocktail/core/event/UIEvent.hx",29)
	super::__construct(type,target);
}
;
	return null();
}

UIEvent_obj::~UIEvent_obj() { }

Dynamic UIEvent_obj::__CreateEmpty() { return  new UIEvent_obj; }
hx::ObjectPtr< UIEvent_obj > UIEvent_obj::__new(::String type,::cocktail::port::flash_player::HTMLElement target,double detail)
{  hx::ObjectPtr< UIEvent_obj > result = new UIEvent_obj();
	result->__construct(type,target,detail);
	return result;}

Dynamic UIEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UIEvent_obj > result = new UIEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

double UIEvent_obj::get_detail( ){
	HX_SOURCE_PUSH("UIEvent_obj::get_detail")
	HX_SOURCE_POS("../../src/cocktail/core/event/UIEvent.hx",37)
	return this->_detail;
}


HX_DEFINE_DYNAMIC_FUNC0(UIEvent_obj,get_detail,return )

double UIEvent_obj::set_detail( double value){
	HX_SOURCE_PUSH("UIEvent_obj::set_detail")
	HX_SOURCE_POS("../../src/cocktail/core/event/UIEvent.hx",42)
	return this->_detail = value;
}


HX_DEFINE_DYNAMIC_FUNC1(UIEvent_obj,set_detail,return )


UIEvent_obj::UIEvent_obj()
{
}

void UIEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UIEvent);
	HX_MARK_MEMBER_NAME(_detail,"_detail");
	HX_MARK_MEMBER_NAME(detail,"detail");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic UIEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detail") ) { return get_detail(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_detail") ) { return _detail; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_detail") ) { return get_detail_dyn(); }
		if (HX_FIELD_EQ(inName,"set_detail") ) { return set_detail_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic UIEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detail") ) { return set_detail(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_detail") ) { _detail=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void UIEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_detail"));
	outFields->push(HX_CSTRING("detail"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_detail"),
	HX_CSTRING("detail"),
	HX_CSTRING("get_detail"),
	HX_CSTRING("set_detail"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class UIEvent_obj::__mClass;

void UIEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.UIEvent"), hx::TCanCast< UIEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void UIEvent_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
