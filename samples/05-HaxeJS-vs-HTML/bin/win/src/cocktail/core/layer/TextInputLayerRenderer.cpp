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
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_TextInputLayerRenderer
#include <cocktail/core/layer/TextInputLayerRenderer.h>
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
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#endif
namespace cocktail{
namespace core{
namespace layer{

Void TextInputLayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("TextInputLayerRenderer::new","cocktail/core/layer/TextInputLayerRenderer.hx",29);
{
	HX_STACK_LINE(29)
	super::__construct(rootElementRenderer);
}
;
	return null();
}

TextInputLayerRenderer_obj::~TextInputLayerRenderer_obj() { }

Dynamic TextInputLayerRenderer_obj::__CreateEmpty() { return  new TextInputLayerRenderer_obj; }
hx::ObjectPtr< TextInputLayerRenderer_obj > TextInputLayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< TextInputLayerRenderer_obj > result = new TextInputLayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic TextInputLayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextInputLayerRenderer_obj > result = new TextInputLayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void TextInputLayerRenderer_obj::detachGraphicsContext( ){
{
		HX_STACK_PUSH("TextInputLayerRenderer::detachGraphicsContext","cocktail/core/layer/TextInputLayerRenderer.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_LINE(55)
		if (((this->graphicsContext != null()))){
			HX_STACK_LINE(57)
			::cocktail::core::html::HTMLInputElement htmlInputElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlInputElement,"htmlInputElement");
			HX_STACK_LINE(58)
			if (((htmlInputElement->elementRenderer != null()))){
				HX_STACK_LINE(60)
				::cocktail::core::renderer::TextInputRenderer textInputRenderer = htmlInputElement->elementRenderer;		HX_STACK_VAR(textInputRenderer,"textInputRenderer");
				HX_STACK_LINE(61)
				textInputRenderer->nativeTextInput->detach(this->graphicsContext);
			}
		}
		HX_STACK_LINE(65)
		this->super::detachGraphicsContext();
	}
return null();
}


Void TextInputLayerRenderer_obj::attachGraphicsContext( ){
{
		HX_STACK_PUSH("TextInputLayerRenderer::attachGraphicsContext","cocktail/core/layer/TextInputLayerRenderer.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_LINE(39)
		this->super::attachGraphicsContext();
		HX_STACK_LINE(41)
		if (((this->graphicsContext != null()))){
			HX_STACK_LINE(43)
			::cocktail::core::html::HTMLInputElement htmlInputElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlInputElement,"htmlInputElement");
			HX_STACK_LINE(44)
			if (((htmlInputElement->elementRenderer != null()))){
				HX_STACK_LINE(46)
				::cocktail::core::renderer::TextInputRenderer textInputRenderer = htmlInputElement->elementRenderer;		HX_STACK_VAR(textInputRenderer,"textInputRenderer");
				HX_STACK_LINE(47)
				textInputRenderer->nativeTextInput->attach(this->graphicsContext);
			}
		}
	}
return null();
}



TextInputLayerRenderer_obj::TextInputLayerRenderer_obj()
{
}

void TextInputLayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextInputLayerRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextInputLayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TextInputLayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"detachGraphicsContext") ) { return detachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"attachGraphicsContext") ) { return attachGraphicsContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextInputLayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TextInputLayerRenderer_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(TextInputLayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextInputLayerRenderer_obj::__mClass,"__mClass");
};

Class TextInputLayerRenderer_obj::__mClass;

void TextInputLayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.TextInputLayerRenderer"), hx::TCanCast< TextInputLayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextInputLayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
