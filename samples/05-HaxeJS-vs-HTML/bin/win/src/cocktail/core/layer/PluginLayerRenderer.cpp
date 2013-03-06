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
#ifndef INCLUDED_cocktail_core_html_HTMLObjectElement
#include <cocktail/core/html/HTMLObjectElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_CompositingLayerRenderer
#include <cocktail/core/layer/CompositingLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_PluginLayerRenderer
#include <cocktail/core/layer/PluginLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_plugin_Plugin
#include <cocktail/plugin/Plugin.h>
#endif
namespace cocktail{
namespace core{
namespace layer{

Void PluginLayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("PluginLayerRenderer::new","cocktail/core/layer/PluginLayerRenderer.hx",27);
{
	HX_STACK_LINE(27)
	super::__construct(rootElementRenderer);
}
;
	return null();
}

PluginLayerRenderer_obj::~PluginLayerRenderer_obj() { }

Dynamic PluginLayerRenderer_obj::__CreateEmpty() { return  new PluginLayerRenderer_obj; }
hx::ObjectPtr< PluginLayerRenderer_obj > PluginLayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< PluginLayerRenderer_obj > result = new PluginLayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic PluginLayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PluginLayerRenderer_obj > result = new PluginLayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PluginLayerRenderer_obj::doClear( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("PluginLayerRenderer::doClear","cocktail/core/layer/PluginLayerRenderer.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


bool PluginLayerRenderer_obj::needsBitmap( ){
	HX_STACK_PUSH("PluginLayerRenderer::needsBitmap","cocktail/core/layer/PluginLayerRenderer.hx",89);
	HX_STACK_THIS(this);
	HX_STACK_LINE(89)
	return false;
}


bool PluginLayerRenderer_obj::isCompositingLayer( ){
	HX_STACK_PUSH("PluginLayerRenderer::isCompositingLayer","cocktail/core/layer/PluginLayerRenderer.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_LINE(74)
	::cocktail::core::html::HTMLObjectElement htmlObjectElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlObjectElement,"htmlObjectElement");
	HX_STACK_LINE(75)
	return htmlObjectElement->plugin->isCompositedPlugin();
}


Void PluginLayerRenderer_obj::detachGraphicsContext( ){
{
		HX_STACK_PUSH("PluginLayerRenderer::detachGraphicsContext","cocktail/core/layer/PluginLayerRenderer.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_LINE(56)
		if (((this->graphicsContext != null()))){
			HX_STACK_LINE(58)
			::cocktail::core::html::HTMLObjectElement htmlObjectElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlObjectElement,"htmlObjectElement");
			HX_STACK_LINE(59)
			htmlObjectElement->plugin->detach(this->graphicsContext);
		}
		HX_STACK_LINE(61)
		this->super::detachGraphicsContext();
	}
return null();
}


Void PluginLayerRenderer_obj::attachGraphicsContext( ){
{
		HX_STACK_PUSH("PluginLayerRenderer::attachGraphicsContext","cocktail/core/layer/PluginLayerRenderer.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_LINE(41)
		this->super::attachGraphicsContext();
		HX_STACK_LINE(42)
		::cocktail::core::html::HTMLObjectElement htmlObjectElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlObjectElement,"htmlObjectElement");
		HX_STACK_LINE(43)
		htmlObjectElement->plugin->attach(this->graphicsContext);
	}
return null();
}



PluginLayerRenderer_obj::PluginLayerRenderer_obj()
{
}

void PluginLayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PluginLayerRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PluginLayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic PluginLayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"doClear") ) { return doClear_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"needsBitmap") ) { return needsBitmap_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isCompositingLayer") ) { return isCompositingLayer_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"detachGraphicsContext") ) { return detachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"attachGraphicsContext") ) { return attachGraphicsContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PluginLayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PluginLayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doClear"),
	HX_CSTRING("needsBitmap"),
	HX_CSTRING("isCompositingLayer"),
	HX_CSTRING("detachGraphicsContext"),
	HX_CSTRING("attachGraphicsContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PluginLayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PluginLayerRenderer_obj::__mClass,"__mClass");
};

Class PluginLayerRenderer_obj::__mClass;

void PluginLayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.PluginLayerRenderer"), hx::TCanCast< PluginLayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PluginLayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
