#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLAnchorElement
#include <cocktail/core/html/HTMLAnchorElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLAnchorElement_obj::__construct()
{
HX_STACK_PUSH("HTMLAnchorElement::new","cocktail/core/html/HTMLAnchorElement.hx",46);
{
	HX_STACK_LINE(46)
	super::__construct(HX_CSTRING("A"));
}
;
	return null();
}

HTMLAnchorElement_obj::~HTMLAnchorElement_obj() { }

Dynamic HTMLAnchorElement_obj::__CreateEmpty() { return  new HTMLAnchorElement_obj; }
hx::ObjectPtr< HTMLAnchorElement_obj > HTMLAnchorElement_obj::__new()
{  hx::ObjectPtr< HTMLAnchorElement_obj > result = new HTMLAnchorElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLAnchorElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLAnchorElement_obj > result = new HTMLAnchorElement_obj();
	result->__construct();
	return result;}

::String HTMLAnchorElement_obj::get_target( ){
	HX_STACK_PUSH("HTMLAnchorElement::get_target","cocktail/core/html/HTMLAnchorElement.hx",154);
	HX_STACK_THIS(this);
	HX_STACK_LINE(155)
	::String target = this->super::getAttribute(HX_CSTRING("target"));		HX_STACK_VAR(target,"target");
	HX_STACK_LINE(157)
	if (((target == null()))){
		HX_STACK_LINE(158)
		return HX_CSTRING("_self");
	}
	HX_STACK_LINE(162)
	return target;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLAnchorElement_obj,get_target,return )

::String HTMLAnchorElement_obj::set_target( ::String value){
	HX_STACK_PUSH("HTMLAnchorElement::set_target","cocktail/core/html/HTMLAnchorElement.hx",148);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(149)
	this->setAttribute(HX_CSTRING("target"),value);
	HX_STACK_LINE(150)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLAnchorElement_obj,set_target,return )

::String HTMLAnchorElement_obj::get_href( ){
	HX_STACK_PUSH("HTMLAnchorElement::get_href","cocktail/core/html/HTMLAnchorElement.hx",143);
	HX_STACK_THIS(this);
	HX_STACK_LINE(143)
	return this->getAttribute(HX_CSTRING("href"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLAnchorElement_obj,get_href,return )

::String HTMLAnchorElement_obj::set_href( ::String value){
	HX_STACK_PUSH("HTMLAnchorElement::set_href","cocktail/core/html/HTMLAnchorElement.hx",137);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(138)
	this->setAttribute(HX_CSTRING("href"),value);
	HX_STACK_LINE(139)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLAnchorElement_obj,set_href,return )

Void HTMLAnchorElement_obj::openDocument( ){
{
		HX_STACK_PUSH("HTMLAnchorElement::openDocument","cocktail/core/html/HTMLAnchorElement.hx",125);
		HX_STACK_THIS(this);
		HX_STACK_LINE(125)
		if (((this->get_href() != null()))){
			HX_STACK_LINE(127)
			::cocktail::Lib_obj::get_window()->open(this->get_href(),this->get_target());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLAnchorElement_obj,openDocument,(void))

bool HTMLAnchorElement_obj::isDefaultFocusable( ){
	HX_STACK_PUSH("HTMLAnchorElement::isDefaultFocusable","cocktail/core/html/HTMLAnchorElement.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(105)
	if (((this->get_href() != null()))){
		HX_STACK_LINE(107)
		return true;
	}
	else{
		HX_STACK_LINE(111)
		return false;
	}
	HX_STACK_LINE(105)
	return false;
}


::String HTMLAnchorElement_obj::getAttribute( ::String name){
	HX_STACK_PUSH("HTMLAnchorElement::getAttribute","cocktail/core/html/HTMLAnchorElement.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(85)
	if (((name == HX_CSTRING("target")))){
		HX_STACK_LINE(87)
		return this->get_target();
	}
	else{
		HX_STACK_LINE(91)
		return this->super::getAttribute(name);
	}
	HX_STACK_LINE(85)
	return null();
}


Void HTMLAnchorElement_obj::runPostClickActivationStep( ::cocktail::core::event::MouseEvent event){
{
		HX_STACK_PUSH("HTMLAnchorElement::runPostClickActivationStep","cocktail/core/html/HTMLAnchorElement.hx",67);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(68)
		if (((event->defaultPrevented == true))){
			HX_STACK_LINE(69)
			return null();
		}
		HX_STACK_LINE(72)
		this->openDocument();
	}
return null();
}


bool HTMLAnchorElement_obj::hasActivationBehaviour( ){
	HX_STACK_PUSH("HTMLAnchorElement::hasActivationBehaviour","cocktail/core/html/HTMLAnchorElement.hx",59);
	HX_STACK_THIS(this);
	HX_STACK_LINE(59)
	return true;
}



HTMLAnchorElement_obj::HTMLAnchorElement_obj()
{
}

void HTMLAnchorElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLAnchorElement);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(href,"href");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLAnchorElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(href,"href");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLAnchorElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"href") ) { return inCallProp ? get_href() : href; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return inCallProp ? get_target() : target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_href") ) { return get_href_dyn(); }
		if (HX_FIELD_EQ(inName,"set_href") ) { return set_href_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_target") ) { return get_target_dyn(); }
		if (HX_FIELD_EQ(inName,"set_target") ) { return set_target_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"openDocument") ) { return openDocument_dyn(); }
		if (HX_FIELD_EQ(inName,"getAttribute") ) { return getAttribute_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { return isDefaultFocusable_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"hasActivationBehaviour") ) { return hasActivationBehaviour_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"runPostClickActivationStep") ) { return runPostClickActivationStep_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLAnchorElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"href") ) { if (inCallProp) return set_href(inValue);href=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { if (inCallProp) return set_target(inValue);target=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLAnchorElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("href"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_target"),
	HX_CSTRING("set_target"),
	HX_CSTRING("get_href"),
	HX_CSTRING("set_href"),
	HX_CSTRING("openDocument"),
	HX_CSTRING("isDefaultFocusable"),
	HX_CSTRING("getAttribute"),
	HX_CSTRING("runPostClickActivationStep"),
	HX_CSTRING("hasActivationBehaviour"),
	HX_CSTRING("target"),
	HX_CSTRING("href"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLAnchorElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLAnchorElement_obj::__mClass,"__mClass");
};

Class HTMLAnchorElement_obj::__mClass;

void HTMLAnchorElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLAnchorElement"), hx::TCanCast< HTMLAnchorElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLAnchorElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
