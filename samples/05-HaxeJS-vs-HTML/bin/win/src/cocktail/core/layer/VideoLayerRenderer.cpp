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
#ifndef INCLUDED_cocktail_core_html_HTMLMediaElement
#include <cocktail/core/html/HTMLMediaElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLVideoElement
#include <cocktail/core/html/HTMLVideoElement.h>
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
#ifndef INCLUDED_cocktail_core_layer_VideoLayerRenderer
#include <cocktail/core/layer/VideoLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
namespace cocktail{
namespace core{
namespace layer{

Void VideoLayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("VideoLayerRenderer::new","cocktail/core/layer/VideoLayerRenderer.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct(rootElementRenderer);
}
;
	return null();
}

VideoLayerRenderer_obj::~VideoLayerRenderer_obj() { }

Dynamic VideoLayerRenderer_obj::__CreateEmpty() { return  new VideoLayerRenderer_obj; }
hx::ObjectPtr< VideoLayerRenderer_obj > VideoLayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< VideoLayerRenderer_obj > result = new VideoLayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic VideoLayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VideoLayerRenderer_obj > result = new VideoLayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void VideoLayerRenderer_obj::doClear( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("VideoLayerRenderer::doClear","cocktail/core/layer/VideoLayerRenderer.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


bool VideoLayerRenderer_obj::needsBitmap( ){
	HX_STACK_PUSH("VideoLayerRenderer::needsBitmap","cocktail/core/layer/VideoLayerRenderer.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_LINE(76)
	return false;
}


Void VideoLayerRenderer_obj::detachGraphicsContext( ){
{
		HX_STACK_PUSH("VideoLayerRenderer::detachGraphicsContext","cocktail/core/layer/VideoLayerRenderer.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_LINE(57)
		if (((this->graphicsContext != null()))){
			HX_STACK_LINE(59)
			::cocktail::core::html::HTMLVideoElement htmlVideoElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlVideoElement,"htmlVideoElement");
			HX_STACK_LINE(60)
			htmlVideoElement->nativeMedia->detach(this->graphicsContext);
		}
		HX_STACK_LINE(62)
		this->super::detachGraphicsContext();
	}
return null();
}


Void VideoLayerRenderer_obj::attachGraphicsContext( ){
{
		HX_STACK_PUSH("VideoLayerRenderer::attachGraphicsContext","cocktail/core/layer/VideoLayerRenderer.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		this->super::attachGraphicsContext();
		HX_STACK_LINE(43)
		::cocktail::core::html::HTMLVideoElement htmlVideoElement = this->rootElementRenderer->domNode;		HX_STACK_VAR(htmlVideoElement,"htmlVideoElement");
		HX_STACK_LINE(44)
		htmlVideoElement->nativeMedia->attach(this->graphicsContext);
	}
return null();
}



VideoLayerRenderer_obj::VideoLayerRenderer_obj()
{
}

void VideoLayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VideoLayerRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void VideoLayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic VideoLayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"doClear") ) { return doClear_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"needsBitmap") ) { return needsBitmap_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"detachGraphicsContext") ) { return detachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"attachGraphicsContext") ) { return attachGraphicsContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VideoLayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void VideoLayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doClear"),
	HX_CSTRING("needsBitmap"),
	HX_CSTRING("detachGraphicsContext"),
	HX_CSTRING("attachGraphicsContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VideoLayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VideoLayerRenderer_obj::__mClass,"__mClass");
};

Class VideoLayerRenderer_obj::__mClass;

void VideoLayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.VideoLayerRenderer"), hx::TCanCast< VideoLayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VideoLayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
