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
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_CheckboxRenderer
#include <cocktail/core/renderer/CheckboxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InputRenderer
#include <cocktail/core/renderer/InputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#include <cocktail/port/base/NativeInputBase.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void CheckboxRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("CheckboxRenderer::new","cocktail/core/renderer/CheckboxRenderer.hx",30);
{
	HX_STACK_LINE(30)
	super::__construct(node);
}
;
	return null();
}

CheckboxRenderer_obj::~CheckboxRenderer_obj() { }

Dynamic CheckboxRenderer_obj::__CreateEmpty() { return  new CheckboxRenderer_obj; }
hx::ObjectPtr< CheckboxRenderer_obj > CheckboxRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< CheckboxRenderer_obj > result = new CheckboxRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic CheckboxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CheckboxRenderer_obj > result = new CheckboxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void CheckboxRenderer_obj::createNativeInput( ){
{
		HX_STACK_PUSH("CheckboxRenderer::createNativeInput","cocktail/core/renderer/CheckboxRenderer.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_LINE(38)
		this->nativeInput = ::cocktail::port::base::NativeInputBase_obj::__new(this->domNode);
	}
return null();
}



CheckboxRenderer_obj::CheckboxRenderer_obj()
{
}

void CheckboxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CheckboxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CheckboxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CheckboxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"createNativeInput") ) { return createNativeInput_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CheckboxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CheckboxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createNativeInput"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CheckboxRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CheckboxRenderer_obj::__mClass,"__mClass");
};

Class CheckboxRenderer_obj::__mClass;

void CheckboxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.CheckboxRenderer"), hx::TCanCast< CheckboxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CheckboxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
