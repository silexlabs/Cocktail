#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_html_HTMLParamElement
#include <cocktail/core/html/HTMLParamElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLParamElement_obj::__construct()
{
HX_STACK_PUSH("HTMLParamElement::new","cocktail/core/html/HTMLParamElement.hx",36);
{
	HX_STACK_LINE(36)
	super::__construct(HX_CSTRING("PARAM"));
}
;
	return null();
}

HTMLParamElement_obj::~HTMLParamElement_obj() { }

Dynamic HTMLParamElement_obj::__CreateEmpty() { return  new HTMLParamElement_obj; }
hx::ObjectPtr< HTMLParamElement_obj > HTMLParamElement_obj::__new()
{  hx::ObjectPtr< HTMLParamElement_obj > result = new HTMLParamElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLParamElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLParamElement_obj > result = new HTMLParamElement_obj();
	result->__construct();
	return result;}

::String HTMLParamElement_obj::set_value( ::String value){
	HX_STACK_PUSH("HTMLParamElement::set_value","cocktail/core/html/HTMLParamElement.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(87)
	this->setAttribute(HX_CSTRING("value"),value);
	HX_STACK_LINE(88)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLParamElement_obj,set_value,return )

::String HTMLParamElement_obj::get_value( ){
	HX_STACK_PUSH("HTMLParamElement::get_value","cocktail/core/html/HTMLParamElement.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_LINE(81)
	return this->getAttributeAsDOMString(HX_CSTRING("value"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLParamElement_obj,get_value,return )

::String HTMLParamElement_obj::set_name( ::String value){
	HX_STACK_PUSH("HTMLParamElement::set_name","cocktail/core/html/HTMLParamElement.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(76)
	this->setAttribute(HX_CSTRING("name"),value);
	HX_STACK_LINE(77)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLParamElement_obj,set_name,return )

::String HTMLParamElement_obj::get_name( ){
	HX_STACK_PUSH("HTMLParamElement::get_name","cocktail/core/html/HTMLParamElement.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_LINE(70)
	return this->getAttributeAsDOMString(HX_CSTRING("name"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLParamElement_obj,get_name,return )

bool HTMLParamElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLParamElement::isVoidElement","cocktail/core/html/HTMLParamElement.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_LINE(61)
	return true;
}


Void HTMLParamElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLParamElement::createElementRenderer","cocktail/core/html/HTMLParamElement.hx",48);
		HX_STACK_THIS(this);
	}
return null();
}



HTMLParamElement_obj::HTMLParamElement_obj()
{
}

void HTMLParamElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLParamElement);
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(name,"name");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLParamElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(name,"name");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLParamElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return inCallProp ? get_name() : name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLParamElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp) return set_name(inValue);name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLParamElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("set_name"),
	HX_CSTRING("get_name"),
	HX_CSTRING("isVoidElement"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("value"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLParamElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLParamElement_obj::__mClass,"__mClass");
};

Class HTMLParamElement_obj::__mClass;

void HTMLParamElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLParamElement"), hx::TCanCast< HTMLParamElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLParamElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
