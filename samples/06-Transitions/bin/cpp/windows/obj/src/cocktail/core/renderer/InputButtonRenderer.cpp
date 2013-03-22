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
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InputButtonRenderer
#include <cocktail/core/renderer/InputButtonRenderer.h>
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
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeButton
#include <cocktail/port/platform/flash_player/NativeButton.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void InputButtonRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("InputButtonRenderer::new","cocktail/core/renderer/InputButtonRenderer.hx",31);
{
	HX_STACK_LINE(31)
	super::__construct(node);
}
;
	return null();
}

InputButtonRenderer_obj::~InputButtonRenderer_obj() { }

Dynamic InputButtonRenderer_obj::__CreateEmpty() { return  new InputButtonRenderer_obj; }
hx::ObjectPtr< InputButtonRenderer_obj > InputButtonRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< InputButtonRenderer_obj > result = new InputButtonRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic InputButtonRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InputButtonRenderer_obj > result = new InputButtonRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InputButtonRenderer_obj::createNativeInput( ){
{
		HX_STACK_PUSH("InputButtonRenderer::createNativeInput","cocktail/core/renderer/InputButtonRenderer.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_LINE(39)
		this->nativeInput = ::cocktail::port::platform::flash_player::NativeButton_obj::__new(this->domNode);
	}
return null();
}



InputButtonRenderer_obj::InputButtonRenderer_obj()
{
}

void InputButtonRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InputButtonRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InputButtonRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InputButtonRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"createNativeInput") ) { return createNativeInput_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InputButtonRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InputButtonRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createNativeInput"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InputButtonRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InputButtonRenderer_obj::__mClass,"__mClass");
};

Class InputButtonRenderer_obj::__mClass;

void InputButtonRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InputButtonRenderer"), hx::TCanCast< InputButtonRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InputButtonRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
