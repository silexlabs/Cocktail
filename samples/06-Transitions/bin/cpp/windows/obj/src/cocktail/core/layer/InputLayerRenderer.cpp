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
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
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
#ifndef INCLUDED_cocktail_core_layer_CompositingLayerRenderer
#include <cocktail/core/layer/CompositingLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_InputLayerRenderer
#include <cocktail/core/layer/InputLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
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
namespace layer{

Void InputLayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("InputLayerRenderer::new","cocktail/core/layer/InputLayerRenderer.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct(rootElementRenderer);
}
;
	return null();
}

InputLayerRenderer_obj::~InputLayerRenderer_obj() { }

Dynamic InputLayerRenderer_obj::__CreateEmpty() { return  new InputLayerRenderer_obj; }
hx::ObjectPtr< InputLayerRenderer_obj > InputLayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< InputLayerRenderer_obj > result = new InputLayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic InputLayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InputLayerRenderer_obj > result = new InputLayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InputLayerRenderer_obj::detachGraphicsContext( ){
{
		HX_STACK_PUSH("InputLayerRenderer::detachGraphicsContext","cocktail/core/layer/InputLayerRenderer.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_LINE(54)
		if (((this->graphicsContext != null()))){
			HX_STACK_LINE(56)
			::cocktail::core::html::HTMLInputElement htmlInputElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlInputElement,"htmlInputElement");
			HX_STACK_LINE(57)
			if (((htmlInputElement->elementRenderer != null()))){
				HX_STACK_LINE(59)
				::cocktail::core::renderer::InputRenderer inputRenderer = htmlInputElement->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
				HX_STACK_LINE(60)
				inputRenderer->nativeInput->detach(this->graphicsContext);
			}
		}
		HX_STACK_LINE(64)
		this->super::detachGraphicsContext();
	}
return null();
}


Void InputLayerRenderer_obj::attachGraphicsContext( ){
{
		HX_STACK_PUSH("InputLayerRenderer::attachGraphicsContext","cocktail/core/layer/InputLayerRenderer.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_LINE(38)
		this->super::attachGraphicsContext();
		HX_STACK_LINE(40)
		if (((this->graphicsContext != null()))){
			HX_STACK_LINE(42)
			::cocktail::core::html::HTMLInputElement htmlInputElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlInputElement,"htmlInputElement");
			HX_STACK_LINE(43)
			if (((htmlInputElement->elementRenderer != null()))){
				HX_STACK_LINE(45)
				::cocktail::core::renderer::InputRenderer inputRenderer = htmlInputElement->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
				HX_STACK_LINE(46)
				inputRenderer->nativeInput->attach(this->graphicsContext);
			}
		}
	}
return null();
}



InputLayerRenderer_obj::InputLayerRenderer_obj()
{
}

void InputLayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InputLayerRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InputLayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InputLayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"detachGraphicsContext") ) { return detachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"attachGraphicsContext") ) { return attachGraphicsContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InputLayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InputLayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("detachGraphicsContext"),
	HX_CSTRING("attachGraphicsContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InputLayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InputLayerRenderer_obj::__mClass,"__mClass");
};

Class InputLayerRenderer_obj::__mClass;

void InputLayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.InputLayerRenderer"), hx::TCanCast< InputLayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InputLayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
