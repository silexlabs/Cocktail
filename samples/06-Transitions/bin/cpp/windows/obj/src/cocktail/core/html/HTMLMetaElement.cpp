#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLMetaElement
#include <cocktail/core/html/HTMLMetaElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLMetaElement_obj::__construct()
{
HX_STACK_PUSH("HTMLMetaElement::new","cocktail/core/html/HTMLMetaElement.hx",36);
{
	HX_STACK_LINE(36)
	super::__construct(HX_CSTRING("META"));
}
;
	return null();
}

HTMLMetaElement_obj::~HTMLMetaElement_obj() { }

Dynamic HTMLMetaElement_obj::__CreateEmpty() { return  new HTMLMetaElement_obj; }
hx::ObjectPtr< HTMLMetaElement_obj > HTMLMetaElement_obj::__new()
{  hx::ObjectPtr< HTMLMetaElement_obj > result = new HTMLMetaElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLMetaElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLMetaElement_obj > result = new HTMLMetaElement_obj();
	result->__construct();
	return result;}

::String HTMLMetaElement_obj::set_content( ::String value){
	HX_STACK_PUSH("HTMLMetaElement::set_content","cocktail/core/html/HTMLMetaElement.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(93)
	this->setAttribute(HX_CSTRING("content"),value);
	HX_STACK_LINE(94)
	this->updateConfig();
	HX_STACK_LINE(95)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMetaElement_obj,set_content,return )

::String HTMLMetaElement_obj::get_content( ){
	HX_STACK_PUSH("HTMLMetaElement::get_content","cocktail/core/html/HTMLMetaElement.hx",87);
	HX_STACK_THIS(this);
	HX_STACK_LINE(87)
	return this->getAttributeAsDOMString(HX_CSTRING("content"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMetaElement_obj,get_content,return )

::String HTMLMetaElement_obj::set_name( ::String value){
	HX_STACK_PUSH("HTMLMetaElement::set_name","cocktail/core/html/HTMLMetaElement.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(81)
	this->setAttribute(HX_CSTRING("name"),value);
	HX_STACK_LINE(82)
	this->updateConfig();
	HX_STACK_LINE(83)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLMetaElement_obj,set_name,return )

::String HTMLMetaElement_obj::get_name( ){
	HX_STACK_PUSH("HTMLMetaElement::get_name","cocktail/core/html/HTMLMetaElement.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_LINE(75)
	return this->getAttributeAsDOMString(HX_CSTRING("name"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMetaElement_obj,get_name,return )

Void HTMLMetaElement_obj::updateConfig( ){
{
		HX_STACK_PUSH("HTMLMetaElement::updateConfig","cocktail/core/html/HTMLMetaElement.hx",63);
		HX_STACK_THIS(this);
		HX_STACK_LINE(63)
		if (((bool((bool((this->isAttachedToDOM() == true)) && bool((this->get_name() != null())))) && bool((this->get_content() != null()))))){
			HX_STACK_LINE(65)
			::cocktail::core::config::Config_obj::getInstance()->updateConfig(this->get_name(),this->get_content());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLMetaElement_obj,updateConfig,(void))

Void HTMLMetaElement_obj::addedToDOM( ){
{
		HX_STACK_PUSH("HTMLMetaElement::addedToDOM","cocktail/core/html/HTMLMetaElement.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(50)
		this->super::addedToDOM();
		HX_STACK_LINE(51)
		this->updateConfig();
	}
return null();
}



HTMLMetaElement_obj::HTMLMetaElement_obj()
{
}

void HTMLMetaElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLMetaElement);
	HX_MARK_MEMBER_NAME(content,"content");
	HX_MARK_MEMBER_NAME(name,"name");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLMetaElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(content,"content");
	HX_VISIT_MEMBER_NAME(name,"name");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLMetaElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return inCallProp ? get_name() : name; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { return inCallProp ? get_content() : content; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addedToDOM") ) { return addedToDOM_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_content") ) { return set_content_dyn(); }
		if (HX_FIELD_EQ(inName,"get_content") ) { return get_content_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateConfig") ) { return updateConfig_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLMetaElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp) return set_name(inValue);name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { if (inCallProp) return set_content(inValue);content=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLMetaElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("content"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_content"),
	HX_CSTRING("get_content"),
	HX_CSTRING("set_name"),
	HX_CSTRING("get_name"),
	HX_CSTRING("updateConfig"),
	HX_CSTRING("addedToDOM"),
	HX_CSTRING("content"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLMetaElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLMetaElement_obj::__mClass,"__mClass");
};

Class HTMLMetaElement_obj::__mClass;

void HTMLMetaElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLMetaElement"), hx::TCanCast< HTMLMetaElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLMetaElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
