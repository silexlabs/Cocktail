#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#include <cocktail/core/html/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#include <cocktail/core/renderer/TextInputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLInputElement_obj::__construct()
{
HX_STACK_PUSH("HTMLInputElement::new","cocktail/core/html/HTMLInputElement.hx",64);
{
	HX_STACK_LINE(64)
	super::__construct(HX_CSTRING("INPUT"));
}
;
	return null();
}

HTMLInputElement_obj::~HTMLInputElement_obj() { }

Dynamic HTMLInputElement_obj::__CreateEmpty() { return  new HTMLInputElement_obj; }
hx::ObjectPtr< HTMLInputElement_obj > HTMLInputElement_obj::__new()
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLInputElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

int HTMLInputElement_obj::get_maxLength( ){
	HX_STACK_PUSH("HTMLInputElement::get_maxLength","cocktail/core/html/HTMLInputElement.hx",186);
	HX_STACK_THIS(this);
	HX_STACK_LINE(187)
	::String maxLength = this->getAttribute(HX_CSTRING("maxlength"));		HX_STACK_VAR(maxLength,"maxLength");
	HX_STACK_LINE(189)
	if (((maxLength == null()))){
		HX_STACK_LINE(190)
		return (int)-1;
	}
	else{
		HX_STACK_LINE(194)
		return ::Std_obj::parseInt(maxLength);
	}
	HX_STACK_LINE(189)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_maxLength,return )

int HTMLInputElement_obj::set_maxLength( int value){
	HX_STACK_PUSH("HTMLInputElement::set_maxLength","cocktail/core/html/HTMLInputElement.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(174)
	this->setAttribute(HX_CSTRING("maxlength"),::Std_obj::string(value));
	HX_STACK_LINE(176)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(178)
		::cocktail::core::renderer::TextInputRenderer textInputElementRenderer = this->elementRenderer;		HX_STACK_VAR(textInputElementRenderer,"textInputElementRenderer");
		HX_STACK_LINE(179)
		textInputElementRenderer->set_maxLength(value);
	}
	HX_STACK_LINE(182)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_maxLength,return )

::String HTMLInputElement_obj::get_value( ){
	HX_STACK_PUSH("HTMLInputElement::get_value","cocktail/core/html/HTMLInputElement.hx",158);
	HX_STACK_THIS(this);
	HX_STACK_LINE(159)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(161)
		::cocktail::core::renderer::TextInputRenderer textInputElementRenderer = this->elementRenderer;		HX_STACK_VAR(textInputElementRenderer,"textInputElementRenderer");
		HX_STACK_LINE(162)
		return textInputElementRenderer->get_value();
	}
	HX_STACK_LINE(165)
	return this->getAttribute(HX_CSTRING("value"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_value,return )

::String HTMLInputElement_obj::set_value( ::String value){
	HX_STACK_PUSH("HTMLInputElement::set_value","cocktail/core/html/HTMLInputElement.hx",145);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(146)
	this->setAttribute(HX_CSTRING("value"),value);
	HX_STACK_LINE(148)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(150)
		::cocktail::core::renderer::TextInputRenderer textInputElementRenderer = this->elementRenderer;		HX_STACK_VAR(textInputElementRenderer,"textInputElementRenderer");
		HX_STACK_LINE(151)
		textInputElementRenderer->set_value(value);
	}
	HX_STACK_LINE(154)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_value,return )

Dynamic HTMLInputElement_obj::get_intrinsicHeight( ){
	HX_STACK_PUSH("HTMLInputElement::get_intrinsicHeight","cocktail/core/html/HTMLInputElement.hx",132);
	HX_STACK_THIS(this);
	HX_STACK_LINE(132)
	return (int)30;
}


Dynamic HTMLInputElement_obj::get_intrinsicWidth( ){
	HX_STACK_PUSH("HTMLInputElement::get_intrinsicWidth","cocktail/core/html/HTMLInputElement.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_LINE(127)
	return (int)150;
}


bool HTMLInputElement_obj::isDefaultFocusable( ){
	HX_STACK_PUSH("HTMLInputElement::isDefaultFocusable","cocktail/core/html/HTMLInputElement.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(118)
	return true;
}


Void HTMLInputElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLInputElement::createElementRenderer","cocktail/core/html/HTMLInputElement.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_LINE(90)
		this->elementRenderer = ::cocktail::core::renderer::TextInputRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(92)
		::cocktail::core::renderer::TextInputRenderer textInputElementRenderer = this->elementRenderer;		HX_STACK_VAR(textInputElementRenderer,"textInputElementRenderer");
		HX_STACK_LINE(95)
		int maxLength = this->get_maxLength();		HX_STACK_VAR(maxLength,"maxLength");
		HX_STACK_LINE(96)
		if (((maxLength != (int)-1))){
			HX_STACK_LINE(97)
			textInputElementRenderer->set_maxLength(maxLength);
		}
		HX_STACK_LINE(102)
		::String value = this->getAttribute(HX_CSTRING("value"));		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(103)
		if (((value != null()))){
			HX_STACK_LINE(104)
			textInputElementRenderer->set_value(value);
		}
	}
return null();
}


bool HTMLInputElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLInputElement::isVoidElement","cocktail/core/html/HTMLInputElement.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_LINE(77)
	return true;
}


int HTMLInputElement_obj::HTML_INPUT_TEXT_INTRINSIC_WIDTH;

Float HTMLInputElement_obj::HTML_INPUT_TEXT_INTRINSIC_HEIGHT;


HTMLInputElement_obj::HTMLInputElement_obj()
{
}

void HTMLInputElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLInputElement);
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(value,"value");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLInputElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(maxLength,"maxLength");
	HX_VISIT_MEMBER_NAME(value,"value");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLInputElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return inCallProp ? get_maxLength() : maxLength; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_maxLength") ) { return get_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { return isDefaultFocusable_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"HTML_INPUT_TEXT_INTRINSIC_WIDTH") ) { return HTML_INPUT_TEXT_INTRINSIC_WIDTH; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"HTML_INPUT_TEXT_INTRINSIC_HEIGHT") ) { return HTML_INPUT_TEXT_INTRINSIC_HEIGHT; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLInputElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxLength") ) { if (inCallProp) return set_maxLength(inValue);maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"HTML_INPUT_TEXT_INTRINSIC_WIDTH") ) { HTML_INPUT_TEXT_INTRINSIC_WIDTH=inValue.Cast< int >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"HTML_INPUT_TEXT_INTRINSIC_HEIGHT") ) { HTML_INPUT_TEXT_INTRINSIC_HEIGHT=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLInputElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("maxLength"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_INPUT_TEXT_INTRINSIC_WIDTH"),
	HX_CSTRING("HTML_INPUT_TEXT_INTRINSIC_HEIGHT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_maxLength"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("get_value"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_intrinsicHeight"),
	HX_CSTRING("get_intrinsicWidth"),
	HX_CSTRING("isDefaultFocusable"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("isVoidElement"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLInputElement_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTMLInputElement_obj::HTML_INPUT_TEXT_INTRINSIC_WIDTH,"HTML_INPUT_TEXT_INTRINSIC_WIDTH");
	HX_MARK_MEMBER_NAME(HTMLInputElement_obj::HTML_INPUT_TEXT_INTRINSIC_HEIGHT,"HTML_INPUT_TEXT_INTRINSIC_HEIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLInputElement_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTMLInputElement_obj::HTML_INPUT_TEXT_INTRINSIC_WIDTH,"HTML_INPUT_TEXT_INTRINSIC_WIDTH");
	HX_VISIT_MEMBER_NAME(HTMLInputElement_obj::HTML_INPUT_TEXT_INTRINSIC_HEIGHT,"HTML_INPUT_TEXT_INTRINSIC_HEIGHT");
};

Class HTMLInputElement_obj::__mClass;

void HTMLInputElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLInputElement"), hx::TCanCast< HTMLInputElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLInputElement_obj::__boot()
{
	HTML_INPUT_TEXT_INTRINSIC_WIDTH= (int)150;
	HTML_INPUT_TEXT_INTRINSIC_HEIGHT= (int)30;
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
