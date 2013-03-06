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
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void EmbeddedBoxRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("EmbeddedBoxRenderer::new","cocktail/core/renderer/EmbeddedBoxRenderer.hx",33);
{
	HX_STACK_LINE(34)
	super::__construct(node);
	HX_STACK_LINE(35)
	this->isReplaced = true;
}
;
	return null();
}

EmbeddedBoxRenderer_obj::~EmbeddedBoxRenderer_obj() { }

Dynamic EmbeddedBoxRenderer_obj::__CreateEmpty() { return  new EmbeddedBoxRenderer_obj; }
hx::ObjectPtr< EmbeddedBoxRenderer_obj > EmbeddedBoxRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< EmbeddedBoxRenderer_obj > result = new EmbeddedBoxRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic EmbeddedBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedBoxRenderer_obj > result = new EmbeddedBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void EmbeddedBoxRenderer_obj::renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("EmbeddedBoxRenderer::renderEmbeddedAsset","cocktail/core/renderer/EmbeddedBoxRenderer.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EmbeddedBoxRenderer_obj,renderEmbeddedAsset,(void))

Void EmbeddedBoxRenderer_obj::renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("EmbeddedBoxRenderer::renderSelf","cocktail/core/renderer/EmbeddedBoxRenderer.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(48)
		this->super::renderSelf(graphicContext,clipRect,scrollOffset);
		HX_STACK_LINE(49)
		this->renderEmbeddedAsset(graphicContext,clipRect,scrollOffset);
	}
return null();
}



EmbeddedBoxRenderer_obj::EmbeddedBoxRenderer_obj()
{
}

void EmbeddedBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedBoxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EmbeddedBoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedBoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"renderSelf") ) { return renderSelf_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderEmbeddedAsset") ) { return renderEmbeddedAsset_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EmbeddedBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderEmbeddedAsset"),
	HX_CSTRING("renderSelf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmbeddedBoxRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedBoxRenderer_obj::__mClass,"__mClass");
};

Class EmbeddedBoxRenderer_obj::__mClass;

void EmbeddedBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.EmbeddedBoxRenderer"), hx::TCanCast< EmbeddedBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
