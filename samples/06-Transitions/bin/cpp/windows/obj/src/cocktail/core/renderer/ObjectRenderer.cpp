#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
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
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
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
#ifndef INCLUDED_cocktail_core_renderer_ObjectRenderer
#include <cocktail/core/renderer/ObjectRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_plugin_Plugin
#include <cocktail/plugin/Plugin.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void ObjectRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("ObjectRenderer::new","cocktail/core/renderer/ObjectRenderer.hx",39);
{
	HX_STACK_LINE(39)
	super::__construct(node);
}
;
	return null();
}

ObjectRenderer_obj::~ObjectRenderer_obj() { }

Dynamic ObjectRenderer_obj::__CreateEmpty() { return  new ObjectRenderer_obj; }
hx::ObjectPtr< ObjectRenderer_obj > ObjectRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< ObjectRenderer_obj > result = new ObjectRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic ObjectRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectRenderer_obj > result = new ObjectRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ObjectRenderer_obj::renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("ObjectRenderer::renderEmbeddedAsset","cocktail/core/renderer/ObjectRenderer.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(76)
		::cocktail::core::html::HTMLObjectElement htmlObjectElement = this->domNode;		HX_STACK_VAR(htmlObjectElement,"htmlObjectElement");
		HX_STACK_LINE(77)
		htmlObjectElement->plugin->updateViewport(((this->globalBounds->x + this->coreStyle->usedValues->paddingLeft) + this->coreStyle->usedValues->borderLeftWidth),((this->globalBounds->y + this->coreStyle->usedValues->paddingTop) + this->coreStyle->usedValues->borderTopWidth),this->globalBounds->width,this->globalBounds->height);
	}
return null();
}


Void ObjectRenderer_obj::doCreateLayer( ){
{
		HX_STACK_PUSH("ObjectRenderer::doCreateLayer","cocktail/core/renderer/ObjectRenderer.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_LINE(61)
		this->layerRenderer = ::cocktail::core::layer::PluginLayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


bool ObjectRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("ObjectRenderer::createOwnLayer","cocktail/core/renderer/ObjectRenderer.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_LINE(52)
	return true;
}



ObjectRenderer_obj::ObjectRenderer_obj()
{
}

void ObjectRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ObjectRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ObjectRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"doCreateLayer") ) { return doCreateLayer_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderEmbeddedAsset") ) { return renderEmbeddedAsset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ObjectRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderEmbeddedAsset"),
	HX_CSTRING("doCreateLayer"),
	HX_CSTRING("createOwnLayer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectRenderer_obj::__mClass,"__mClass");
};

Class ObjectRenderer_obj::__mClass;

void ObjectRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.ObjectRenderer"), hx::TCanCast< ObjectRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ObjectRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
