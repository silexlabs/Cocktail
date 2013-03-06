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
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl
#include <cocktail/core/graphics/AbstractGraphicsContextImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
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
#ifndef INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl
#include <cocktail/port/platform/flash_player/GraphicsContextImpl.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void ImageRenderer_obj::__construct(::cocktail::core::html::HTMLElement domNode)
{
HX_STACK_PUSH("ImageRenderer::new","cocktail/core/renderer/ImageRenderer.hx",48);
{
	HX_STACK_LINE(49)
	super::__construct(domNode);
	HX_STACK_LINE(51)
	this->_paintBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(52)
	this->_destinationPoint = ::cocktail::core::geom::PointVO_obj::__new(0.0,0.0);
}
;
	return null();
}

ImageRenderer_obj::~ImageRenderer_obj() { }

Dynamic ImageRenderer_obj::__CreateEmpty() { return  new ImageRenderer_obj; }
hx::ObjectPtr< ImageRenderer_obj > ImageRenderer_obj::__new(::cocktail::core::html::HTMLElement domNode)
{  hx::ObjectPtr< ImageRenderer_obj > result = new ImageRenderer_obj();
	result->__construct(domNode);
	return result;}

Dynamic ImageRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ImageRenderer_obj > result = new ImageRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ImageRenderer_obj::paintResource( ::cocktail::core::graphics::GraphicsContext graphicContext,::native::display::BitmapData nativeBitmapData,::cocktail::core::geom::RectangleVO bounds,Float intrinsicWidth,Float intrinsicHeight,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("ImageRenderer::paintResource","cocktail/core/renderer/ImageRenderer.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(nativeBitmapData,"nativeBitmapData");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_ARG(intrinsicWidth,"intrinsicWidth");
		HX_STACK_ARG(intrinsicHeight,"intrinsicHeight");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(101)
		if (((bool((intrinsicWidth != bounds->width)) || bool((intrinsicHeight != bounds->height))))){
			HX_STACK_LINE(107)
			::cocktail::core::geom::Matrix matrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
			HX_STACK_LINE(109)
			matrix->translate(bounds->x,bounds->y);
			HX_STACK_LINE(110)
			matrix->scale((Float(bounds->width) / Float(intrinsicWidth)),(Float(bounds->height) / Float(intrinsicHeight)));
			HX_STACK_LINE(112)
			graphicContext->graphics->drawImage(nativeBitmapData,matrix,bounds,clipRect);
		}
		else{
			HX_STACK_LINE(118)
			Float width = intrinsicWidth;		HX_STACK_VAR(width,"width");
			HX_STACK_LINE(119)
			Float height = intrinsicHeight;		HX_STACK_VAR(height,"height");
			HX_STACK_LINE(123)
			this->_destinationPoint->x = bounds->x;
			HX_STACK_LINE(124)
			this->_destinationPoint->y = bounds->y;
			HX_STACK_LINE(128)
			bounds->width = width;
			HX_STACK_LINE(129)
			bounds->height = height;
			HX_STACK_LINE(130)
			bounds->x = 0.0;
			HX_STACK_LINE(131)
			bounds->y = 0.0;
			HX_STACK_LINE(133)
			graphicContext->graphics->copyPixels(nativeBitmapData,bounds,this->_destinationPoint,clipRect);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(ImageRenderer_obj,paintResource,(void))

Void ImageRenderer_obj::renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("ImageRenderer::renderEmbeddedAsset","cocktail/core/renderer/ImageRenderer.hx",64);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(66)
		::String src = this->domNode->getAttribute(HX_CSTRING("src"));		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(69)
		if (((src == null()))){
			HX_STACK_LINE(70)
			return null();
		}
		HX_STACK_LINE(74)
		::cocktail::core::resource::AbstractResource resource = ::cocktail::core::resource::ResourceManager_obj::getImageResource(src);		HX_STACK_VAR(resource,"resource");
		HX_STACK_LINE(78)
		if (((bool((resource->loaded == false)) || bool((resource->loadedWithError == true))))){
			HX_STACK_LINE(79)
			return null();
		}
		HX_STACK_LINE(83)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(85)
		this->_paintBounds->x = (((this->globalBounds->x + usedValues->paddingLeft) + usedValues->borderLeftWidth) - scrollOffset->x);
		HX_STACK_LINE(86)
		this->_paintBounds->y = (((this->globalBounds->y + usedValues->paddingTop) + usedValues->borderTopWidth) - scrollOffset->y);
		HX_STACK_LINE(87)
		this->_paintBounds->width = usedValues->width;
		HX_STACK_LINE(88)
		this->_paintBounds->height = usedValues->height;
		HX_STACK_LINE(90)
		this->paintResource(graphicContext,resource->nativeResource,this->_paintBounds,resource->intrinsicWidth,resource->intrinsicHeight,clipRect);
	}
return null();
}



ImageRenderer_obj::ImageRenderer_obj()
{
}

void ImageRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ImageRenderer);
	HX_MARK_MEMBER_NAME(_destinationPoint,"_destinationPoint");
	HX_MARK_MEMBER_NAME(_paintBounds,"_paintBounds");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ImageRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_destinationPoint,"_destinationPoint");
	HX_VISIT_MEMBER_NAME(_paintBounds,"_paintBounds");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ImageRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_paintBounds") ) { return _paintBounds; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"paintResource") ) { return paintResource_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_destinationPoint") ) { return _destinationPoint; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderEmbeddedAsset") ) { return renderEmbeddedAsset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ImageRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_paintBounds") ) { _paintBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_destinationPoint") ) { _destinationPoint=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ImageRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_destinationPoint"));
	outFields->push(HX_CSTRING("_paintBounds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("paintResource"),
	HX_CSTRING("renderEmbeddedAsset"),
	HX_CSTRING("_destinationPoint"),
	HX_CSTRING("_paintBounds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ImageRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ImageRenderer_obj::__mClass,"__mClass");
};

Class ImageRenderer_obj::__mClass;

void ImageRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.ImageRenderer"), hx::TCanCast< ImageRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ImageRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
