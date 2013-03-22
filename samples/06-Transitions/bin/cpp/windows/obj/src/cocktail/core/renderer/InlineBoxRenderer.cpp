#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#include <cocktail/core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
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
#ifndef INCLUDED_cocktail_core_graphics_BorderDrawer
#include <cocktail/core/graphics/BorderDrawer.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_LineBox
#include <cocktail/core/linebox/LineBox.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InlineBoxRenderer
#include <cocktail/core/renderer/InlineBoxRenderer.h>
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

Void InlineBoxRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("InlineBoxRenderer::new","cocktail/core/renderer/InlineBoxRenderer.hx",46);
{
	HX_STACK_LINE(47)
	super::__construct(node);
	HX_STACK_LINE(48)
	this->_renderRect = ::cocktail::core::geom::RectangleVO_obj::__new();
}
;
	return null();
}

InlineBoxRenderer_obj::~InlineBoxRenderer_obj() { }

Dynamic InlineBoxRenderer_obj::__CreateEmpty() { return  new InlineBoxRenderer_obj; }
hx::ObjectPtr< InlineBoxRenderer_obj > InlineBoxRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< InlineBoxRenderer_obj > result = new InlineBoxRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic InlineBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineBoxRenderer_obj > result = new InlineBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool InlineBoxRenderer_obj::canHaveClearance( ){
	HX_STACK_PUSH("InlineBoxRenderer::canHaveClearance","cocktail/core/renderer/InlineBoxRenderer.hx",134);
	HX_STACK_THIS(this);
	HX_STACK_LINE(134)
	return false;
}


Void InlineBoxRenderer_obj::renderChildren( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("InlineBoxRenderer::renderChildren","cocktail/core/renderer/InlineBoxRenderer.hx",115);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(116)
		this->super::renderChildren(graphicContext,clipRect,scrollOffset);
		HX_STACK_LINE(119)
		if (((this->createOwnLayer() == true))){
			HX_STACK_LINE(120)
			this->renderInlineChildren(hx::ObjectPtr<OBJ_>(this),this->layerRenderer,graphicContext,clipRect,scrollOffset);
		}
	}
return null();
}


Void InlineBoxRenderer_obj::updateInlineBoxes( ){
{
		HX_STACK_PUSH("InlineBoxRenderer::updateInlineBoxes","cocktail/core/renderer/InlineBoxRenderer.hx",95);
		HX_STACK_THIS(this);
		HX_STACK_LINE(96)
		this->inlineBoxes = Array_obj< ::cocktail::core::linebox::InlineBox >::__new();
		HX_STACK_LINE(97)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(98)
		while(((child != null()))){
			HX_STACK_LINE(100)
			child->updateInlineBoxes();
			HX_STACK_LINE(101)
			child = child->nextSibling;
		}
	}
return null();
}


Void InlineBoxRenderer_obj::render( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("InlineBoxRenderer::render","cocktail/core/renderer/InlineBoxRenderer.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(61)
		int inlineBoxesLength = this->inlineBoxes->length;		HX_STACK_VAR(inlineBoxesLength,"inlineBoxesLength");
		HX_STACK_LINE(62)
		{
			HX_STACK_LINE(62)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(62)
			while(((_g < inlineBoxesLength))){
				HX_STACK_LINE(62)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(64)
				::cocktail::core::linebox::InlineBox inlineBox = this->inlineBoxes->__get(i);		HX_STACK_VAR(inlineBox,"inlineBox");
				HX_STACK_LINE(66)
				this->_renderRect->width = inlineBox->bounds->width;
				HX_STACK_LINE(67)
				this->_renderRect->height = inlineBox->bounds->height;
				HX_STACK_LINE(68)
				this->_renderRect->x = (((inlineBox->bounds->x + inlineBox->lineBox->bounds->x) + this->globalBounds->x) - scrollOffset->x);
				HX_STACK_LINE(69)
				this->_renderRect->y = (((inlineBox->bounds->y + inlineBox->lineBox->bounds->y) + this->globalBounds->y) - scrollOffset->y);
				HX_STACK_LINE(72)
				if (((bool((this->coreStyle->hasBackgroundImage == true)) || bool((this->coreStyle->hasBackgroundColor == true))))){
					HX_STACK_LINE(73)
					::cocktail::core::background::BackgroundManager_obj::render(graphicsContext,this->_renderRect,this->coreStyle,hx::ObjectPtr<OBJ_>(this),clipRect);
				}
				HX_STACK_LINE(77)
				::cocktail::core::graphics::BorderDrawer_obj::draw(graphicsContext,this->_renderRect,this->coreStyle,clipRect);
			}
		}
		HX_STACK_LINE(82)
		if (((this->firstChild != null()))){
			HX_STACK_LINE(83)
			this->renderChildren(graphicsContext,clipRect,scrollOffset);
		}
	}
return null();
}



InlineBoxRenderer_obj::InlineBoxRenderer_obj()
{
}

void InlineBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineBoxRenderer);
	HX_MARK_MEMBER_NAME(_renderRect,"_renderRect");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InlineBoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_renderRect,"_renderRect");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InlineBoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_renderRect") ) { return _renderRect; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"renderChildren") ) { return renderChildren_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"canHaveClearance") ) { return canHaveClearance_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateInlineBoxes") ) { return updateInlineBoxes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InlineBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"_renderRect") ) { _renderRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InlineBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_renderRect"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("canHaveClearance"),
	HX_CSTRING("renderChildren"),
	HX_CSTRING("updateInlineBoxes"),
	HX_CSTRING("render"),
	HX_CSTRING("_renderRect"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InlineBoxRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InlineBoxRenderer_obj::__mClass,"__mClass");
};

Class InlineBoxRenderer_obj::__mClass;

void InlineBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InlineBoxRenderer"), hx::TCanCast< InlineBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InlineBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
