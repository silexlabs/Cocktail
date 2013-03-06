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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_AnonymousBlockBoxRenderer
#include <cocktail/core/renderer/AnonymousBlockBoxRenderer.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void AnonymousBlockBoxRenderer_obj::__construct(::cocktail::core::dom::Document document)
{
HX_STACK_PUSH("AnonymousBlockBoxRenderer::new","cocktail/core/renderer/AnonymousBlockBoxRenderer.hx",37);
{
	HX_STACK_LINE(39)
	if (((::cocktail::core::renderer::AnonymousBlockBoxRenderer_obj::_node == null()))){
		HX_STACK_LINE(40)
		::cocktail::core::renderer::AnonymousBlockBoxRenderer_obj::_node = document->createElement(HX_CSTRING("DIV"));
	}
	HX_STACK_LINE(44)
	super::__construct(::cocktail::core::renderer::AnonymousBlockBoxRenderer_obj::_node);
}
;
	return null();
}

AnonymousBlockBoxRenderer_obj::~AnonymousBlockBoxRenderer_obj() { }

Dynamic AnonymousBlockBoxRenderer_obj::__CreateEmpty() { return  new AnonymousBlockBoxRenderer_obj; }
hx::ObjectPtr< AnonymousBlockBoxRenderer_obj > AnonymousBlockBoxRenderer_obj::__new(::cocktail::core::dom::Document document)
{  hx::ObjectPtr< AnonymousBlockBoxRenderer_obj > result = new AnonymousBlockBoxRenderer_obj();
	result->__construct(document);
	return result;}

Dynamic AnonymousBlockBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AnonymousBlockBoxRenderer_obj > result = new AnonymousBlockBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool AnonymousBlockBoxRenderer_obj::isInlineLevel( ){
	HX_STACK_PUSH("AnonymousBlockBoxRenderer::isInlineLevel","cocktail/core/renderer/AnonymousBlockBoxRenderer.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_LINE(86)
	return false;
}


bool AnonymousBlockBoxRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("AnonymousBlockBoxRenderer::createOwnLayer","cocktail/core/renderer/AnonymousBlockBoxRenderer.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_LINE(81)
	return false;
}


bool AnonymousBlockBoxRenderer_obj::isAnonymousBlockBox( ){
	HX_STACK_PUSH("AnonymousBlockBoxRenderer::isAnonymousBlockBox","cocktail/core/renderer/AnonymousBlockBoxRenderer.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_LINE(76)
	return true;
}


bool AnonymousBlockBoxRenderer_obj::isPositioned( ){
	HX_STACK_PUSH("AnonymousBlockBoxRenderer::isPositioned","cocktail/core/renderer/AnonymousBlockBoxRenderer.hx",71);
	HX_STACK_THIS(this);
	HX_STACK_LINE(71)
	return false;
}


Void AnonymousBlockBoxRenderer_obj::removeChild( Dynamic _tmp_oldChild){
{
		HX_STACK_PUSH("AnonymousBlockBoxRenderer::removeChild","cocktail/core/renderer/AnonymousBlockBoxRenderer.hx",56);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_oldChild,"_tmp_oldChild");
		HX_STACK_LINE(57)
		::cocktail::core::renderer::ElementRenderer oldChild = _tmp_oldChild;		HX_STACK_VAR(oldChild,"oldChild");
		HX_STACK_LINE(57)
		this->super::removeChild(oldChild);
		HX_STACK_LINE(59)
		if (((this->firstChild == null()))){
			HX_STACK_LINE(60)
			this->parentNode->__Field(HX_CSTRING("removeChild"),true)(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


::cocktail::core::html::HTMLElement AnonymousBlockBoxRenderer_obj::_node;


AnonymousBlockBoxRenderer_obj::AnonymousBlockBoxRenderer_obj()
{
}

void AnonymousBlockBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AnonymousBlockBoxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AnonymousBlockBoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic AnonymousBlockBoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_node") ) { return _node; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"isAnonymousBlockBox") ) { return isAnonymousBlockBox_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AnonymousBlockBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_node") ) { _node=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AnonymousBlockBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_node"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("isAnonymousBlockBox"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("removeChild"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnonymousBlockBoxRenderer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(AnonymousBlockBoxRenderer_obj::_node,"_node");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnonymousBlockBoxRenderer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AnonymousBlockBoxRenderer_obj::_node,"_node");
};

Class AnonymousBlockBoxRenderer_obj::__mClass;

void AnonymousBlockBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.AnonymousBlockBoxRenderer"), hx::TCanCast< AnonymousBlockBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AnonymousBlockBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
