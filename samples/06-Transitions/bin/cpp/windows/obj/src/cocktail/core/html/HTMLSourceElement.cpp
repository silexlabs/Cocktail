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
#ifndef INCLUDED_cocktail_core_html_HTMLSourceElement
#include <cocktail/core/html/HTMLSourceElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLSourceElement_obj::__construct()
{
HX_STACK_PUSH("HTMLSourceElement::new","cocktail/core/html/HTMLSourceElement.hx",55);
{
	HX_STACK_LINE(55)
	super::__construct(HX_CSTRING("SOURCE"));
}
;
	return null();
}

HTMLSourceElement_obj::~HTMLSourceElement_obj() { }

Dynamic HTMLSourceElement_obj::__CreateEmpty() { return  new HTMLSourceElement_obj; }
hx::ObjectPtr< HTMLSourceElement_obj > HTMLSourceElement_obj::__new()
{  hx::ObjectPtr< HTMLSourceElement_obj > result = new HTMLSourceElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLSourceElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLSourceElement_obj > result = new HTMLSourceElement_obj();
	result->__construct();
	return result;}

::String HTMLSourceElement_obj::set_media( ::String value){
	HX_STACK_PUSH("HTMLSourceElement::set_media","cocktail/core/html/HTMLSourceElement.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(117)
	this->setAttribute(HX_CSTRING("media"),value);
	HX_STACK_LINE(118)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLSourceElement_obj,set_media,return )

::String HTMLSourceElement_obj::get_media( ){
	HX_STACK_PUSH("HTMLSourceElement::get_media","cocktail/core/html/HTMLSourceElement.hx",111);
	HX_STACK_THIS(this);
	HX_STACK_LINE(111)
	return this->getAttributeAsDOMString(HX_CSTRING("media"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLSourceElement_obj,get_media,return )

::String HTMLSourceElement_obj::set_type( ::String value){
	HX_STACK_PUSH("HTMLSourceElement::set_type","cocktail/core/html/HTMLSourceElement.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(106)
	this->setAttribute(HX_CSTRING("type"),value);
	HX_STACK_LINE(107)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLSourceElement_obj,set_type,return )

::String HTMLSourceElement_obj::get_type( ){
	HX_STACK_PUSH("HTMLSourceElement::get_type","cocktail/core/html/HTMLSourceElement.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_LINE(100)
	return this->getAttributeAsDOMString(HX_CSTRING("type"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLSourceElement_obj,get_type,return )

::String HTMLSourceElement_obj::set_src( ::String value){
	HX_STACK_PUSH("HTMLSourceElement::set_src","cocktail/core/html/HTMLSourceElement.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(95)
	this->setAttribute(HX_CSTRING("src"),value);
	HX_STACK_LINE(96)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLSourceElement_obj,set_src,return )

::String HTMLSourceElement_obj::get_src( ){
	HX_STACK_PUSH("HTMLSourceElement::get_src","cocktail/core/html/HTMLSourceElement.hx",89);
	HX_STACK_THIS(this);
	HX_STACK_LINE(89)
	return this->getAttributeAsDOMString(HX_CSTRING("src"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLSourceElement_obj,get_src,return )

bool HTMLSourceElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLSourceElement::isVoidElement","cocktail/core/html/HTMLSourceElement.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_LINE(80)
	return true;
}


Void HTMLSourceElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLSourceElement::createElementRenderer","cocktail/core/html/HTMLSourceElement.hx",67);
		HX_STACK_THIS(this);
	}
return null();
}



HTMLSourceElement_obj::HTMLSourceElement_obj()
{
}

void HTMLSourceElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLSourceElement);
	HX_MARK_MEMBER_NAME(media,"media");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(src,"src");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLSourceElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(media,"media");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(src,"src");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLSourceElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return inCallProp ? get_src() : src; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? get_type() : type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"media") ) { return inCallProp ? get_media() : media; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_src") ) { return set_src_dyn(); }
		if (HX_FIELD_EQ(inName,"get_src") ) { return get_src_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_media") ) { return set_media_dyn(); }
		if (HX_FIELD_EQ(inName,"get_media") ) { return get_media_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLSourceElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { if (inCallProp) return set_src(inValue);src=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return set_type(inValue);type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"media") ) { if (inCallProp) return set_media(inValue);media=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLSourceElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("media"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("src"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_media"),
	HX_CSTRING("get_media"),
	HX_CSTRING("set_type"),
	HX_CSTRING("get_type"),
	HX_CSTRING("set_src"),
	HX_CSTRING("get_src"),
	HX_CSTRING("isVoidElement"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("media"),
	HX_CSTRING("type"),
	HX_CSTRING("src"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLSourceElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLSourceElement_obj::__mClass,"__mClass");
};

Class HTMLSourceElement_obj::__mClass;

void HTMLSourceElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLSourceElement"), hx::TCanCast< HTMLSourceElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLSourceElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
