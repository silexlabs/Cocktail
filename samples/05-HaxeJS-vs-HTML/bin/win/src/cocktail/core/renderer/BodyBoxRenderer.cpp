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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BodyBoxRenderer
#include <cocktail/core/renderer/BodyBoxRenderer.h>
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

Void BodyBoxRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("BodyBoxRenderer::new","cocktail/core/renderer/BodyBoxRenderer.hx",30);
{
	HX_STACK_LINE(30)
	super::__construct(node);
}
;
	return null();
}

BodyBoxRenderer_obj::~BodyBoxRenderer_obj() { }

Dynamic BodyBoxRenderer_obj::__CreateEmpty() { return  new BodyBoxRenderer_obj; }
hx::ObjectPtr< BodyBoxRenderer_obj > BodyBoxRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< BodyBoxRenderer_obj > result = new BodyBoxRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic BodyBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BodyBoxRenderer_obj > result = new BodyBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::geom::RectangleVO BodyBoxRenderer_obj::getBackgroundAndBordersBounds( ::cocktail::core::geom::PointVO scrollOffset){
	HX_STACK_PUSH("BodyBoxRenderer::getBackgroundAndBordersBounds","cocktail/core/renderer/BodyBoxRenderer.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scrollOffset,"scrollOffset");
	HX_STACK_LINE(108)
	::cocktail::core::layout::ContainingBlockVO windowData = this->getWindowData();		HX_STACK_VAR(windowData,"windowData");
	HX_STACK_LINE(110)
	Float width = windowData->width;		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(111)
	Float height = windowData->height;		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(112)
	this->bounds->width = width;
	HX_STACK_LINE(113)
	this->bounds->height = height;
	HX_STACK_LINE(114)
	this->bounds->x = 0.0;
	HX_STACK_LINE(115)
	this->bounds->y = 0.0;
	HX_STACK_LINE(117)
	return this->bounds;
}


::cocktail::core::layout::ContainingBlockVO BodyBoxRenderer_obj::getContainerBlockData( ){
	HX_STACK_PUSH("BodyBoxRenderer::getContainerBlockData","cocktail/core/renderer/BodyBoxRenderer.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_LINE(92)
	this->super::getContainerBlockData();
	HX_STACK_LINE(94)
	if (((bool((this->coreStyle->hasAutoHeight == true)) && bool(((bool((this->isPositioned() == false)) || bool((this->isRelativePositioned() == true)))))))){
		HX_STACK_LINE(95)
		this->_containerBlockData->isHeightAuto = false;
	}
	HX_STACK_LINE(99)
	return this->_containerBlockData;
}


bool BodyBoxRenderer_obj::collapseBottomMarginWithParentBottomMargin( ){
	HX_STACK_PUSH("BodyBoxRenderer::collapseBottomMarginWithParentBottomMargin","cocktail/core/renderer/BodyBoxRenderer.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_LINE(77)
	return false;
}


bool BodyBoxRenderer_obj::collapseTopMarginWithParentTopMargin( ){
	HX_STACK_PUSH("BodyBoxRenderer::collapseTopMarginWithParentTopMargin","cocktail/core/renderer/BodyBoxRenderer.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_LINE(69)
	return false;
}


Void BodyBoxRenderer_obj::layoutSelfIfNeeded( bool forceLayout){
{
		HX_STACK_PUSH("BodyBoxRenderer::layoutSelfIfNeeded","cocktail/core/renderer/BodyBoxRenderer.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_LINE(45)
		if (((bool((this->_needsLayout == false)) && bool((forceLayout == false))))){
			HX_STACK_LINE(46)
			return null();
		}
		HX_STACK_LINE(50)
		this->super::layoutSelfIfNeeded(forceLayout);
		HX_STACK_LINE(52)
		if (((bool((this->coreStyle->hasAutoHeight == true)) && bool(((bool((this->isPositioned() == false)) || bool((this->isRelativePositioned() == true)))))))){
			HX_STACK_LINE(54)
			::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
			HX_STACK_LINE(55)
			usedValues->height = ((((((this->containingBlock->getContainerBlockData()->height - usedValues->marginTop) - usedValues->marginBottom) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth);
		}
	}
return null();
}



BodyBoxRenderer_obj::BodyBoxRenderer_obj()
{
}

void BodyBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BodyBoxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BodyBoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BodyBoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"layoutSelfIfNeeded") ) { return layoutSelfIfNeeded_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getContainerBlockData") ) { return getContainerBlockData_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"getBackgroundAndBordersBounds") ) { return getBackgroundAndBordersBounds_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"collapseTopMarginWithParentTopMargin") ) { return collapseTopMarginWithParentTopMargin_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"collapseBottomMarginWithParentBottomMargin") ) { return collapseBottomMarginWithParentBottomMargin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BodyBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BodyBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getBackgroundAndBordersBounds"),
	HX_CSTRING("getContainerBlockData"),
	HX_CSTRING("collapseBottomMarginWithParentBottomMargin"),
	HX_CSTRING("collapseTopMarginWithParentTopMargin"),
	HX_CSTRING("layoutSelfIfNeeded"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BodyBoxRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BodyBoxRenderer_obj::__mClass,"__mClass");
};

Class BodyBoxRenderer_obj::__mClass;

void BodyBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.BodyBoxRenderer"), hx::TCanCast< BodyBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BodyBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
