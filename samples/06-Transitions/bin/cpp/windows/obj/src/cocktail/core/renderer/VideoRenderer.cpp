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
#ifndef INCLUDED_cocktail_core_geom_GeomUtils
#include <cocktail/core/geom/GeomUtils.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
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
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ImageRenderer
#include <cocktail/core/renderer/ImageRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_VideoRenderer
#include <cocktail/core/renderer/VideoRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void VideoRenderer_obj::__construct(::cocktail::core::html::HTMLElement domNode)
{
HX_STACK_PUSH("VideoRenderer::new","cocktail/core/renderer/VideoRenderer.hx",53);
{
	HX_STACK_LINE(54)
	super::__construct(domNode);
	HX_STACK_LINE(55)
	this->_posterBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(56)
	this->_videoBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
}
;
	return null();
}

VideoRenderer_obj::~VideoRenderer_obj() { }

Dynamic VideoRenderer_obj::__CreateEmpty() { return  new VideoRenderer_obj; }
hx::ObjectPtr< VideoRenderer_obj > VideoRenderer_obj::__new(::cocktail::core::html::HTMLElement domNode)
{  hx::ObjectPtr< VideoRenderer_obj > result = new VideoRenderer_obj();
	result->__construct(domNode);
	return result;}

Dynamic VideoRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VideoRenderer_obj > result = new VideoRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void VideoRenderer_obj::renderPosterFrame( ::cocktail::core::html::HTMLVideoElement htmlVideoElement,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("VideoRenderer::renderPosterFrame","cocktail/core/renderer/VideoRenderer.hx",141);
		HX_STACK_THIS(this);
		HX_STACK_ARG(htmlVideoElement,"htmlVideoElement");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(142)
		::cocktail::core::resource::AbstractResource resource = ::cocktail::core::resource::ResourceManager_obj::getImageResource(this->domNode->getAttribute(HX_CSTRING("poster")));		HX_STACK_VAR(resource,"resource");
		HX_STACK_LINE(145)
		if (((bool((resource->loaded == false)) || bool((resource->loadedWithError == true))))){
			HX_STACK_LINE(146)
			return null();
		}
		HX_STACK_LINE(151)
		::cocktail::core::geom::GeomUtils_obj::getCenteredBounds(this->coreStyle->usedValues->width,this->coreStyle->usedValues->height,resource->intrinsicWidth,resource->intrinsicHeight,this->_posterBounds);
		HX_STACK_LINE(154)
		Float x = ((((this->globalBounds->x + this->coreStyle->usedValues->paddingLeft) + this->coreStyle->usedValues->borderLeftWidth) + this->_posterBounds->x) - scrollOffset->x);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(155)
		Float y = ((((this->globalBounds->y + this->coreStyle->usedValues->paddingTop) + this->coreStyle->usedValues->borderTopWidth) + this->_posterBounds->y) - scrollOffset->y);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(156)
		Float width = this->_posterBounds->width;		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(157)
		Float height = this->_posterBounds->height;		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(159)
		::cocktail::core::geom::RectangleVO paintBounds = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(paintBounds,"paintBounds");
		HX_STACK_LINE(160)
		paintBounds->x = x;
		HX_STACK_LINE(161)
		paintBounds->y = y;
		HX_STACK_LINE(162)
		paintBounds->width = width;
		HX_STACK_LINE(163)
		paintBounds->height = height;
		HX_STACK_LINE(165)
		this->paintResource(graphicContext,resource->nativeResource,paintBounds,resource->intrinsicWidth,resource->intrinsicHeight,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(VideoRenderer_obj,renderPosterFrame,(void))

Void VideoRenderer_obj::renderVideo( ::cocktail::core::html::HTMLVideoElement htmlVideoElement,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("VideoRenderer::renderVideo","cocktail/core/renderer/VideoRenderer.hx",116);
		HX_STACK_THIS(this);
		HX_STACK_ARG(htmlVideoElement,"htmlVideoElement");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(118)
		::cocktail::core::geom::GeomUtils_obj::getCenteredBounds(this->coreStyle->usedValues->width,this->coreStyle->usedValues->height,htmlVideoElement->get_videoWidth(),htmlVideoElement->get_videoHeight(),this->_videoBounds);
		HX_STACK_LINE(121)
		::cocktail::port::base::NativeMedia nativeVideo = htmlVideoElement->nativeMedia;		HX_STACK_VAR(nativeVideo,"nativeVideo");
		HX_STACK_LINE(125)
		::cocktail::core::geom::RectangleVO videoViewport = nativeVideo->get_viewport();		HX_STACK_VAR(videoViewport,"videoViewport");
		HX_STACK_LINE(126)
		videoViewport->x = ((((this->globalBounds->x + this->coreStyle->usedValues->paddingLeft) + this->coreStyle->usedValues->borderLeftWidth) + this->_videoBounds->x) - scrollOffset->x);
		HX_STACK_LINE(127)
		videoViewport->y = ((((this->globalBounds->y + this->coreStyle->usedValues->paddingTop) + this->coreStyle->usedValues->borderTopWidth) + this->_videoBounds->y) - scrollOffset->y);
		HX_STACK_LINE(128)
		videoViewport->width = this->_videoBounds->width;
		HX_STACK_LINE(129)
		videoViewport->height = this->_videoBounds->height;
		HX_STACK_LINE(131)
		nativeVideo->set_alpha(this->layerRenderer->alpha);
		HX_STACK_LINE(132)
		nativeVideo->set_matrix(this->layerRenderer->matrix);
		HX_STACK_LINE(133)
		nativeVideo->set_viewport(videoViewport);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(VideoRenderer_obj,renderVideo,(void))

Void VideoRenderer_obj::renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("VideoRenderer::renderEmbeddedAsset","cocktail/core/renderer/VideoRenderer.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(90)
		::cocktail::core::html::HTMLVideoElement htmlVideoElement = this->domNode;		HX_STACK_VAR(htmlVideoElement,"htmlVideoElement");
		HX_STACK_LINE(93)
		if (((htmlVideoElement->shouldRenderPosterFrame() == true))){
			HX_STACK_LINE(94)
			this->renderPosterFrame(htmlVideoElement,graphicContext,clipRect,scrollOffset);
		}
		else{
			HX_STACK_LINE(98)
			this->renderVideo(htmlVideoElement,graphicContext,scrollOffset);
		}
	}
return null();
}


Void VideoRenderer_obj::doCreateLayer( ){
{
		HX_STACK_PUSH("VideoRenderer::doCreateLayer","cocktail/core/renderer/VideoRenderer.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_LINE(77)
		this->layerRenderer = ::cocktail::core::layer::VideoLayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


bool VideoRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("VideoRenderer::createOwnLayer","cocktail/core/renderer/VideoRenderer.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_LINE(68)
	return true;
}



VideoRenderer_obj::VideoRenderer_obj()
{
}

void VideoRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VideoRenderer);
	HX_MARK_MEMBER_NAME(_videoBounds,"_videoBounds");
	HX_MARK_MEMBER_NAME(_posterBounds,"_posterBounds");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void VideoRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_videoBounds,"_videoBounds");
	HX_VISIT_MEMBER_NAME(_posterBounds,"_posterBounds");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic VideoRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"renderVideo") ) { return renderVideo_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_videoBounds") ) { return _videoBounds; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"doCreateLayer") ) { return doCreateLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"_posterBounds") ) { return _posterBounds; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"renderPosterFrame") ) { return renderPosterFrame_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderEmbeddedAsset") ) { return renderEmbeddedAsset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VideoRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_videoBounds") ) { _videoBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_posterBounds") ) { _posterBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VideoRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_videoBounds"));
	outFields->push(HX_CSTRING("_posterBounds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderPosterFrame"),
	HX_CSTRING("renderVideo"),
	HX_CSTRING("renderEmbeddedAsset"),
	HX_CSTRING("doCreateLayer"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("_videoBounds"),
	HX_CSTRING("_posterBounds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VideoRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VideoRenderer_obj::__mClass,"__mClass");
};

Class VideoRenderer_obj::__mClass;

void VideoRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.VideoRenderer"), hx::TCanCast< VideoRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VideoRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
