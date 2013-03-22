#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BodyBoxRenderer
#include <cocktail/core/renderer/BodyBoxRenderer.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLBodyElement_obj::__construct()
{
HX_STACK_PUSH("HTMLBodyElement::new","cocktail/core/html/HTMLBodyElement.hx",30);
{
	HX_STACK_LINE(30)
	super::__construct(HX_CSTRING("BODY"));
}
;
	return null();
}

HTMLBodyElement_obj::~HTMLBodyElement_obj() { }

Dynamic HTMLBodyElement_obj::__CreateEmpty() { return  new HTMLBodyElement_obj; }
hx::ObjectPtr< HTMLBodyElement_obj > HTMLBodyElement_obj::__new()
{  hx::ObjectPtr< HTMLBodyElement_obj > result = new HTMLBodyElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLBodyElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLBodyElement_obj > result = new HTMLBodyElement_obj();
	result->__construct();
	return result;}

int HTMLBodyElement_obj::get_offsetLeft( ){
	HX_STACK_PUSH("HTMLBodyElement::get_offsetLeft","cocktail/core/html/HTMLBodyElement.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_LINE(114)
	return (int)0;
}


int HTMLBodyElement_obj::get_offsetTop( ){
	HX_STACK_PUSH("HTMLBodyElement::get_offsetTop","cocktail/core/html/HTMLBodyElement.hx",106);
	HX_STACK_THIS(this);
	HX_STACK_LINE(106)
	return (int)0;
}


::cocktail::core::html::HTMLElement HTMLBodyElement_obj::get_offsetParent( ){
	HX_STACK_PUSH("HTMLBodyElement::get_offsetParent","cocktail/core/html/HTMLBodyElement.hx",98);
	HX_STACK_THIS(this);
	HX_STACK_LINE(98)
	return null();
}


Void HTMLBodyElement_obj::cascadeSelf( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange){
{
		HX_STACK_PUSH("HTMLBodyElement::cascadeSelf","cocktail/core/html/HTMLBodyElement.hx",58);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cascadeManager,"cascadeManager");
		HX_STACK_ARG(programmaticChange,"programmaticChange");
		HX_STACK_LINE(59)
		this->super::cascadeSelf(cascadeManager,programmaticChange);
		HX_STACK_LINE(61)
		::cocktail::core::css::CoreStyle parentCoreStyle = this->parentNode->__Field(HX_CSTRING("coreStyle"),true);		HX_STACK_VAR(parentCoreStyle,"parentCoreStyle");
		HX_STACK_LINE(65)
		if (((parentCoreStyle->computedValues->get_overflowX() != null()))){
			HX_STACK_LINE(66)
			{
				::cocktail::core::css::CSSKeywordValue _switch_1 = (parentCoreStyle->getKeyword(parentCoreStyle->getComputedOrInitialProperty((int)51)));
				switch((_switch_1)->GetIndex()){
					case 36: {
						HX_STACK_LINE(69)
						parentCoreStyle->computedValues->set_overflowX(this->coreStyle->computedValues->get_overflowX());
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(77)
		if (((parentCoreStyle->computedValues->get_overflowY() != null()))){
			HX_STACK_LINE(78)
			{
				::cocktail::core::css::CSSKeywordValue _switch_2 = (parentCoreStyle->getKeyword(parentCoreStyle->getComputedOrInitialProperty((int)52)));
				switch((_switch_2)->GetIndex()){
					case 36: {
						HX_STACK_LINE(81)
						parentCoreStyle->computedValues->set_overflowY(this->coreStyle->computedValues->get_overflowY());
					}
					;break;
					default: {
					}
				}
			}
		}
	}
return null();
}


Void HTMLBodyElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLBodyElement::createElementRenderer","cocktail/core/html/HTMLBodyElement.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		this->elementRenderer = ::cocktail::core::renderer::BodyBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}



HTMLBodyElement_obj::HTMLBodyElement_obj()
{
}

void HTMLBodyElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLBodyElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLBodyElement_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLBodyElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"cascadeSelf") ) { return cascadeSelf_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_offsetTop") ) { return get_offsetTop_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_offsetLeft") ) { return get_offsetLeft_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_offsetParent") ) { return get_offsetParent_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLBodyElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLBodyElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_offsetLeft"),
	HX_CSTRING("get_offsetTop"),
	HX_CSTRING("get_offsetParent"),
	HX_CSTRING("cascadeSelf"),
	HX_CSTRING("createElementRenderer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLBodyElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLBodyElement_obj::__mClass,"__mClass");
};

Class HTMLBodyElement_obj::__mClass;

void HTMLBodyElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLBodyElement"), hx::TCanCast< HTMLBodyElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLBodyElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
