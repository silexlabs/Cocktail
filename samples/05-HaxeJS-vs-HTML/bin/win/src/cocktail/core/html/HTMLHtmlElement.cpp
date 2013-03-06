#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLHtmlElement
#include <cocktail/core/html/HTMLHtmlElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InitialBlockRenderer
#include <cocktail/core/renderer/InitialBlockRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLHtmlElement_obj::__construct()
{
HX_STACK_PUSH("HTMLHtmlElement::new","cocktail/core/html/HTMLHtmlElement.hx",29);
{
	HX_STACK_LINE(29)
	super::__construct(HX_CSTRING("HTML"));
}
;
	return null();
}

HTMLHtmlElement_obj::~HTMLHtmlElement_obj() { }

Dynamic HTMLHtmlElement_obj::__CreateEmpty() { return  new HTMLHtmlElement_obj; }
hx::ObjectPtr< HTMLHtmlElement_obj > HTMLHtmlElement_obj::__new()
{  hx::ObjectPtr< HTMLHtmlElement_obj > result = new HTMLHtmlElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLHtmlElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLHtmlElement_obj > result = new HTMLHtmlElement_obj();
	result->__construct();
	return result;}

int HTMLHtmlElement_obj::get_offsetLeft( ){
	HX_STACK_PUSH("HTMLHtmlElement::get_offsetLeft","cocktail/core/html/HTMLHtmlElement.hx",126);
	HX_STACK_THIS(this);
	HX_STACK_LINE(126)
	return (int)0;
}


int HTMLHtmlElement_obj::get_offsetTop( ){
	HX_STACK_PUSH("HTMLHtmlElement::get_offsetTop","cocktail/core/html/HTMLHtmlElement.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(118)
	return (int)0;
}


::cocktail::core::html::HTMLElement HTMLHtmlElement_obj::get_offsetParent( ){
	HX_STACK_PUSH("HTMLHtmlElement::get_offsetParent","cocktail/core/html/HTMLHtmlElement.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_LINE(110)
	return null();
}


Void HTMLHtmlElement_obj::detachFromParentElementRenderer( ){
{
		HX_STACK_PUSH("HTMLHtmlElement::detachFromParentElementRenderer","cocktail/core/html/HTMLHtmlElement.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_LINE(97)
		this->elementRenderer->removedFromRenderingTree();
	}
return null();
}


Void HTMLHtmlElement_obj::attachToParentElementRenderer( ){
{
		HX_STACK_PUSH("HTMLHtmlElement::attachToParentElementRenderer","cocktail/core/html/HTMLHtmlElement.hx",88);
		HX_STACK_THIS(this);
	}
return null();
}


Void HTMLHtmlElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLHtmlElement::createElementRenderer","cocktail/core/html/HTMLHtmlElement.hx",79);
		HX_STACK_THIS(this);
		HX_STACK_LINE(79)
		this->elementRenderer = ::cocktail::core::renderer::InitialBlockRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


bool HTMLHtmlElement_obj::isParentRendered( ){
	HX_STACK_PUSH("HTMLHtmlElement::isParentRendered","cocktail/core/html/HTMLHtmlElement.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_LINE(70)
	return true;
}


::String HTMLHtmlElement_obj::set_outerHTML( ::String value){
	HX_STACK_PUSH("HTMLHtmlElement::set_outerHTML","cocktail/core/html/HTMLHtmlElement.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(54)
	hx::Throw ((int)7);
	HX_STACK_LINE(55)
	return value;
}


::String HTMLHtmlElement_obj::set_innerHTML( ::String value){
	HX_STACK_PUSH("HTMLHtmlElement::set_innerHTML","cocktail/core/html/HTMLHtmlElement.hx",42);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(43)
	this->super::set_innerHTML(value);
	HX_STACK_LINE(44)
	::cocktail::core::html::HTMLDocument htmlDocument = this->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
	HX_STACK_LINE(45)
	htmlDocument->initBody(this->getElementsByTagName(HX_CSTRING("BODY"))->__get((int)0));
	HX_STACK_LINE(46)
	return value;
}



HTMLHtmlElement_obj::HTMLHtmlElement_obj()
{
}

void HTMLHtmlElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLHtmlElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLHtmlElement_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLHtmlElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"get_offsetTop") ) { return get_offsetTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_outerHTML") ) { return set_outerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"set_innerHTML") ) { return set_innerHTML_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_offsetLeft") ) { return get_offsetLeft_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_offsetParent") ) { return get_offsetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"isParentRendered") ) { return isParentRendered_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"attachToParentElementRenderer") ) { return attachToParentElementRenderer_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"detachFromParentElementRenderer") ) { return detachFromParentElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLHtmlElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLHtmlElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_offsetLeft"),
	HX_CSTRING("get_offsetTop"),
	HX_CSTRING("get_offsetParent"),
	HX_CSTRING("detachFromParentElementRenderer"),
	HX_CSTRING("attachToParentElementRenderer"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("isParentRendered"),
	HX_CSTRING("set_outerHTML"),
	HX_CSTRING("set_innerHTML"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLHtmlElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLHtmlElement_obj::__mClass,"__mClass");
};

Class HTMLHtmlElement_obj::__mClass;

void HTMLHtmlElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLHtmlElement"), hx::TCanCast< HTMLHtmlElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLHtmlElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
