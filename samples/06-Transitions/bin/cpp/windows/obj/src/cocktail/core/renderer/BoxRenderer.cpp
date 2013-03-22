#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
#endif
#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#include <cocktail/core/background/BackgroundManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_LayoutManager
#include <cocktail/core/layout/LayoutManager.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_EmbeddedInlineBox
#include <cocktail/core/linebox/EmbeddedInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
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
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void BoxRenderer_obj::__construct(::cocktail::core::html::HTMLElement domNode)
{
HX_STACK_PUSH("BoxRenderer::new","cocktail/core/renderer/BoxRenderer.hx",90);
{
	HX_STACK_LINE(91)
	super::__construct(domNode);
	HX_STACK_LINE(92)
	this->_containerBlockData = ::cocktail::core::layout::ContainingBlockVO_obj::__new(0.0,false,0.0,false);
	HX_STACK_LINE(93)
	this->_windowData = ::cocktail::core::layout::ContainingBlockVO_obj::__new(0.0,false,0.0,false);
	HX_STACK_LINE(94)
	this->_backgroundAndBorderBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
}
;
	return null();
}

BoxRenderer_obj::~BoxRenderer_obj() { }

Dynamic BoxRenderer_obj::__CreateEmpty() { return  new BoxRenderer_obj; }
hx::ObjectPtr< BoxRenderer_obj > BoxRenderer_obj::__new(::cocktail::core::html::HTMLElement domNode)
{  hx::ObjectPtr< BoxRenderer_obj > result = new BoxRenderer_obj();
	result->__construct(domNode);
	return result;}

Dynamic BoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxRenderer_obj > result = new BoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::layout::ContainingBlockVO BoxRenderer_obj::getWindowData( ){
	HX_STACK_PUSH("BoxRenderer::getWindowData","cocktail/core/renderer/BoxRenderer.hx",995);
	HX_STACK_THIS(this);
	HX_STACK_LINE(996)
	::cocktail::core::window::Window window = ::cocktail::Lib_obj::get_window();		HX_STACK_VAR(window,"window");
	HX_STACK_LINE(997)
	Float width = window->get_innerWidth();		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(998)
	Float height = window->get_innerHeight();		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(1000)
	this->_windowData->width = window->get_innerWidth();
	HX_STACK_LINE(1001)
	this->_windowData->height = window->get_innerHeight();
	HX_STACK_LINE(1002)
	this->_windowData->isHeightAuto = false;
	HX_STACK_LINE(1003)
	this->_windowData->isWidthAuto = false;
	HX_STACK_LINE(1005)
	return this->_windowData;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,getWindowData,return )

::cocktail::core::layout::ContainingBlockVO BoxRenderer_obj::getContainerBlockData( ){
	HX_STACK_PUSH("BoxRenderer::getContainerBlockData","cocktail/core/renderer/BoxRenderer.hx",981);
	HX_STACK_THIS(this);
	HX_STACK_LINE(982)
	this->_containerBlockData->width = this->coreStyle->usedValues->width;
	HX_STACK_LINE(983)
	this->_containerBlockData->isWidthAuto = this->coreStyle->hasAutoWidth;
	HX_STACK_LINE(984)
	this->_containerBlockData->height = this->coreStyle->usedValues->height;
	HX_STACK_LINE(985)
	this->_containerBlockData->isHeightAuto = this->coreStyle->hasAutoHeight;
	HX_STACK_LINE(986)
	return this->_containerBlockData;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,getContainerBlockData,return )

::cocktail::core::geom::RectangleVO BoxRenderer_obj::getOutlineBounds( ::cocktail::core::geom::PointVO scrollOffset){
	HX_STACK_PUSH("BoxRenderer::getOutlineBounds","cocktail/core/renderer/BoxRenderer.hx",966);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scrollOffset,"scrollOffset");
	HX_STACK_LINE(967)
	::cocktail::core::geom::RectangleVO outlineBounds = this->getBackgroundAndBordersBounds(scrollOffset);		HX_STACK_VAR(outlineBounds,"outlineBounds");
	HX_STACK_LINE(968)
	hx::SubEq(outlineBounds->x,this->coreStyle->usedValues->outlineWidth);
	HX_STACK_LINE(969)
	hx::SubEq(outlineBounds->y,this->coreStyle->usedValues->outlineWidth);
	HX_STACK_LINE(970)
	hx::AddEq(outlineBounds->width,(this->coreStyle->usedValues->outlineWidth * (int)2));
	HX_STACK_LINE(971)
	hx::AddEq(outlineBounds->height,(this->coreStyle->usedValues->outlineWidth * (int)2));
	HX_STACK_LINE(973)
	return outlineBounds;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxRenderer_obj,getOutlineBounds,return )

::cocktail::core::geom::RectangleVO BoxRenderer_obj::getBackgroundAndBordersBounds( ::cocktail::core::geom::PointVO scrollOffset){
	HX_STACK_PUSH("BoxRenderer::getBackgroundAndBordersBounds","cocktail/core/renderer/BoxRenderer.hx",950);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scrollOffset,"scrollOffset");
	HX_STACK_LINE(951)
	this->_backgroundAndBorderBounds->x = (this->globalBounds->x - scrollOffset->x);
	HX_STACK_LINE(952)
	this->_backgroundAndBorderBounds->y = (this->globalBounds->y - scrollOffset->y);
	HX_STACK_LINE(953)
	this->_backgroundAndBorderBounds->width = this->globalBounds->width;
	HX_STACK_LINE(954)
	this->_backgroundAndBorderBounds->height = this->globalBounds->height;
	HX_STACK_LINE(956)
	return this->_backgroundAndBorderBounds;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxRenderer_obj,getBackgroundAndBordersBounds,return )

bool BoxRenderer_obj::isTransparent( ){
	HX_STACK_PUSH("BoxRenderer::isTransparent","cocktail/core/renderer/BoxRenderer.hx",934);
	HX_STACK_THIS(this);
	HX_STACK_LINE(934)
	return this->coreStyle->isTransparent;
}


bool BoxRenderer_obj::isVisible( ){
	HX_STACK_PUSH("BoxRenderer::isVisible","cocktail/core/renderer/BoxRenderer.hx",925);
	HX_STACK_THIS(this);
	HX_STACK_LINE(925)
	return this->coreStyle->isVisible;
}


bool BoxRenderer_obj::hasCSSTransform( ){
	HX_STACK_PUSH("BoxRenderer::hasCSSTransform","cocktail/core/renderer/BoxRenderer.hx",913);
	HX_STACK_THIS(this);
	HX_STACK_LINE(913)
	return this->coreStyle->hasCSSTransform;
}


bool BoxRenderer_obj::isTransformed( ){
	HX_STACK_PUSH("BoxRenderer::isTransformed","cocktail/core/renderer/BoxRenderer.hx",903);
	HX_STACK_THIS(this);
	HX_STACK_LINE(903)
	return this->coreStyle->isTransformed;
}


bool BoxRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("BoxRenderer::createOwnLayer","cocktail/core/renderer/BoxRenderer.hx",872);
	HX_STACK_THIS(this);
	HX_STACK_LINE(874)
	if (((this->coreStyle->isPositioned == true))){
		HX_STACK_LINE(875)
		return true;
	}
	else{
		HX_STACK_LINE(881)
		if (((this->coreStyle->isTransparent == true))){
			HX_STACK_LINE(882)
			return true;
		}
		else{
			HX_STACK_LINE(886)
			if (((this->coreStyle->isTransformed == true))){
				HX_STACK_LINE(887)
				return true;
			}
		}
	}
	HX_STACK_LINE(892)
	return false;
}


bool BoxRenderer_obj::isInlineLevel( ){
	HX_STACK_PUSH("BoxRenderer::isInlineLevel","cocktail/core/renderer/BoxRenderer.hx",863);
	HX_STACK_THIS(this);
	HX_STACK_LINE(863)
	return this->coreStyle->isInlineLevel;
}


bool BoxRenderer_obj::isRelativePositioned( ){
	HX_STACK_PUSH("BoxRenderer::isRelativePositioned","cocktail/core/renderer/BoxRenderer.hx",848);
	HX_STACK_THIS(this);
	HX_STACK_LINE(848)
	return this->coreStyle->isRelativePositioned;
}


bool BoxRenderer_obj::isAbsolutelyPositioned( ){
	HX_STACK_PUSH("BoxRenderer::isAbsolutelyPositioned","cocktail/core/renderer/BoxRenderer.hx",829);
	HX_STACK_THIS(this);
	HX_STACK_LINE(829)
	return this->coreStyle->isAbsolutelyPositioned;
}


bool BoxRenderer_obj::isPositioned( ){
	HX_STACK_PUSH("BoxRenderer::isPositioned","cocktail/core/renderer/BoxRenderer.hx",820);
	HX_STACK_THIS(this);
	HX_STACK_LINE(820)
	return this->coreStyle->isPositioned;
}


bool BoxRenderer_obj::canHaveClearance( ){
	HX_STACK_PUSH("BoxRenderer::canHaveClearance","cocktail/core/renderer/BoxRenderer.hx",796);
	HX_STACK_THIS(this);
	HX_STACK_LINE(796)
	return this->coreStyle->canHaveClearance;
}


bool BoxRenderer_obj::isFloat( ){
	HX_STACK_PUSH("BoxRenderer::isFloat","cocktail/core/renderer/BoxRenderer.hx",783);
	HX_STACK_THIS(this);
	HX_STACK_LINE(783)
	return this->coreStyle->isFloat;
}


bool BoxRenderer_obj::hasZeroHeightChildren( ){
	HX_STACK_PUSH("BoxRenderer::hasZeroHeightChildren","cocktail/core/renderer/BoxRenderer.hx",761);
	HX_STACK_THIS(this);
	HX_STACK_LINE(761)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,hasZeroHeightChildren,return )

bool BoxRenderer_obj::collapseTopMarginWithBottomMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseTopMarginWithBottomMargin","cocktail/core/renderer/BoxRenderer.hx",710);
	HX_STACK_THIS(this);
	HX_STACK_LINE(711)
	if (((this->get_firstNormalFlowChild() != null()))){
		HX_STACK_LINE(712)
		if (((this->hasZeroHeightChildren() == false))){
			HX_STACK_LINE(716)
			return false;
		}
	}
	HX_STACK_LINE(722)
	if (((bool((this->coreStyle->usedValues->paddingTop != (int)0)) || bool((this->coreStyle->usedValues->paddingBottom != (int)0))))){
		HX_STACK_LINE(723)
		return false;
	}
	HX_STACK_LINE(728)
	if (((bool((this->coreStyle->usedValues->borderTopWidth != (int)0)) || bool((this->coreStyle->usedValues->borderBottomWidth != (int)0))))){
		HX_STACK_LINE(729)
		return false;
	}
	HX_STACK_LINE(739)
	if (((this->bounds->height != (int)0))){
		HX_STACK_LINE(740)
		return false;
	}
	HX_STACK_LINE(745)
	if (((this->establishesNewBlockFormattingContext() == true))){
		HX_STACK_LINE(746)
		return false;
	}
	HX_STACK_LINE(750)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseTopMarginWithBottomMargin,return )

bool BoxRenderer_obj::collapseBottomMarginWithLastChildBottomMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseBottomMarginWithLastChildBottomMargin","cocktail/core/renderer/BoxRenderer.hx",701);
	HX_STACK_THIS(this);
	HX_STACK_LINE(701)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseBottomMarginWithLastChildBottomMargin,return )

bool BoxRenderer_obj::collapseTopMarginWithFirstChildTopMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseTopMarginWithFirstChildTopMargin","cocktail/core/renderer/BoxRenderer.hx",692);
	HX_STACK_THIS(this);
	HX_STACK_LINE(692)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseTopMarginWithFirstChildTopMargin,return )

bool BoxRenderer_obj::collapseBottomMarginWithNextSiblingTopMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseBottomMarginWithNextSiblingTopMargin","cocktail/core/renderer/BoxRenderer.hx",677);
	HX_STACK_THIS(this);
	HX_STACK_LINE(678)
	if (((this->get_nextNormalFlowSibling() == null()))){
		HX_STACK_LINE(679)
		return false;
	}
	HX_STACK_LINE(683)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseBottomMarginWithNextSiblingTopMargin,return )

bool BoxRenderer_obj::collapseTopMarginWithPreviousSiblingBottomMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseTopMarginWithPreviousSiblingBottomMargin","cocktail/core/renderer/BoxRenderer.hx",661);
	HX_STACK_THIS(this);
	HX_STACK_LINE(664)
	if (((this->get_previousNormalFlowSibling() == null()))){
		HX_STACK_LINE(665)
		return false;
	}
	HX_STACK_LINE(669)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseTopMarginWithPreviousSiblingBottomMargin,return )

bool BoxRenderer_obj::collapseBottomMarginWithParentBottomMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseBottomMarginWithParentBottomMargin","cocktail/core/renderer/BoxRenderer.hx",631);
	HX_STACK_THIS(this);
	HX_STACK_LINE(632)
	if (((this->parentNode == null()))){
		HX_STACK_LINE(633)
		return false;
	}
	HX_STACK_LINE(637)
	if (((this->get_nextNormalFlowSibling() != null()))){
		HX_STACK_LINE(638)
		return false;
	}
	HX_STACK_LINE(642)
	if (((this->parentNode->__Field(HX_CSTRING("establishesNewBlockFormattingContext"),true)() == true))){
		HX_STACK_LINE(643)
		return false;
	}
	HX_STACK_LINE(647)
	if (((this->parentNode->__Field(HX_CSTRING("coreStyle"),true)->__Field(HX_CSTRING("usedValues"),true)->__Field(HX_CSTRING("paddingBottom"),true) != (int)0))){
		HX_STACK_LINE(648)
		return false;
	}
	HX_STACK_LINE(652)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseBottomMarginWithParentBottomMargin,return )

bool BoxRenderer_obj::collapseTopMarginWithParentTopMargin( ){
	HX_STACK_PUSH("BoxRenderer::collapseTopMarginWithParentTopMargin","cocktail/core/renderer/BoxRenderer.hx",586);
	HX_STACK_THIS(this);
	HX_STACK_LINE(589)
	if (((this->parentNode == null()))){
		HX_STACK_LINE(590)
		return false;
	}
	HX_STACK_LINE(596)
	if (((this->get_previousNormalFlowSibling() != null()))){
		HX_STACK_LINE(597)
		return false;
	}
	HX_STACK_LINE(603)
	if (((this->parentNode->__Field(HX_CSTRING("establishesNewBlockFormattingContext"),true)() == true))){
		HX_STACK_LINE(604)
		return false;
	}
	HX_STACK_LINE(610)
	if (((this->parentNode->__Field(HX_CSTRING("coreStyle"),true)->__Field(HX_CSTRING("usedValues"),true)->__Field(HX_CSTRING("paddingTop"),true) != (int)0))){
		HX_STACK_LINE(611)
		return false;
	}
	HX_STACK_LINE(617)
	if (((this->parentNode->__Field(HX_CSTRING("coreStyle"),true)->__Field(HX_CSTRING("usedValues"),true)->__Field(HX_CSTRING("borderTopWidth"),true) != (int)0))){
		HX_STACK_LINE(618)
		return false;
	}
	HX_STACK_LINE(623)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,collapseTopMarginWithParentTopMargin,return )

Float BoxRenderer_obj::getCollapsedMargin( Array< Float > adjoiningMargins){
	HX_STACK_PUSH("BoxRenderer::getCollapsedMargin","cocktail/core/renderer/BoxRenderer.hx",553);
	HX_STACK_THIS(this);
	HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
	HX_STACK_LINE(555)
	Float maximumPositiveMargin = 0.0;		HX_STACK_VAR(maximumPositiveMargin,"maximumPositiveMargin");
	HX_STACK_LINE(556)
	Float maximumNegativeMargin = 0.0;		HX_STACK_VAR(maximumNegativeMargin,"maximumNegativeMargin");
	HX_STACK_LINE(560)
	int length = adjoiningMargins->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(561)
	{
		HX_STACK_LINE(561)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(561)
		while(((_g < length))){
			HX_STACK_LINE(561)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(563)
			Float adjoiningMargin = adjoiningMargins->__get(i);		HX_STACK_VAR(adjoiningMargin,"adjoiningMargin");
			HX_STACK_LINE(564)
			if (((adjoiningMargin > maximumPositiveMargin))){
				HX_STACK_LINE(565)
				maximumPositiveMargin = adjoiningMargin;
			}
			else{
				HX_STACK_LINE(568)
				if (((adjoiningMargin < maximumNegativeMargin))){
					HX_STACK_LINE(569)
					maximumNegativeMargin = adjoiningMargin;
				}
			}
		}
	}
	HX_STACK_LINE(576)
	return (maximumPositiveMargin - ::Math_obj::abs(maximumNegativeMargin));
}


HX_DEFINE_DYNAMIC_FUNC1(BoxRenderer_obj,getCollapsedMargin,return )

Void BoxRenderer_obj::getAdjoiningBottomMargins( Array< Float > adjoiningMargins){
{
		HX_STACK_PUSH("BoxRenderer::getAdjoiningBottomMargins","cocktail/core/renderer/BoxRenderer.hx",516);
		HX_STACK_THIS(this);
		HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
		HX_STACK_LINE(518)
		this->layoutSelfIfNeeded(false);
		HX_STACK_LINE(520)
		if (((this->collapseBottomMarginWithParentBottomMargin() == true))){
			HX_STACK_LINE(521)
			adjoiningMargins->push(this->coreStyle->usedValues->marginBottom);
		}
		else{
			HX_STACK_LINE(524)
			if (((this->collapseBottomMarginWithNextSiblingTopMargin() == true))){
				HX_STACK_LINE(525)
				adjoiningMargins->push(this->coreStyle->usedValues->marginBottom);
			}
		}
		HX_STACK_LINE(529)
		if (((this->collapseBottomMarginWithLastChildBottomMargin() == true))){
			HX_STACK_LINE(530)
			this->get_lastNormalFlowChild()->getAdjoiningBottomMargins(adjoiningMargins);
		}
		else{
			HX_STACK_LINE(533)
			if (((this->collapseTopMarginWithBottomMargin() == true))){
				HX_STACK_LINE(535)
				adjoiningMargins->push(this->coreStyle->usedValues->marginTop);
				HX_STACK_LINE(536)
				if (((this->previousSibling != null()))){
					HX_STACK_LINE(537)
					this->previousSibling->__Field(HX_CSTRING("getAdjoiningBottomMargins"),true)(adjoiningMargins);
				}
			}
		}
	}
return null();
}


Float BoxRenderer_obj::getCollapsedBottomMargin( ){
	HX_STACK_PUSH("BoxRenderer::getCollapsedBottomMargin","cocktail/core/renderer/BoxRenderer.hx",479);
	HX_STACK_THIS(this);
	HX_STACK_LINE(481)
	this->layoutSelfIfNeeded(false);
	HX_STACK_LINE(483)
	if (((this->collapseBottomMarginWithParentBottomMargin() == true))){
		HX_STACK_LINE(484)
		return (int)0;
	}
	else{
		HX_STACK_LINE(487)
		if (((this->collapseTopMarginWithBottomMargin() == true))){
			HX_STACK_LINE(488)
			return (int)0;
		}
	}
	HX_STACK_LINE(492)
	if (((this->collapseBottomMarginWithLastChildBottomMargin() == true))){
		HX_STACK_LINE(494)
		Array< Float > adjoiningMargins = Array_obj< Float >::__new();		HX_STACK_VAR(adjoiningMargins,"adjoiningMargins");
		HX_STACK_LINE(495)
		adjoiningMargins->push(this->coreStyle->usedValues->marginBottom);
		HX_STACK_LINE(496)
		this->get_lastNormalFlowChild()->getAdjoiningBottomMargins(adjoiningMargins);
		HX_STACK_LINE(498)
		return this->getCollapsedMargin(adjoiningMargins);
	}
	else{
		HX_STACK_LINE(500)
		if (((this->collapseBottomMarginWithNextSiblingTopMargin() == true))){
			HX_STACK_LINE(502)
			Array< Float > adjoiningMargins = Array_obj< Float >::__new();		HX_STACK_VAR(adjoiningMargins,"adjoiningMargins");
			HX_STACK_LINE(503)
			adjoiningMargins->push(this->coreStyle->usedValues->marginBottom);
			HX_STACK_LINE(504)
			this->get_nextNormalFlowSibling()->getAdjoiningTopMargins(adjoiningMargins);
			HX_STACK_LINE(506)
			return this->getCollapsedMargin(adjoiningMargins);
		}
	}
	HX_STACK_LINE(509)
	return this->coreStyle->usedValues->marginBottom;
}


Void BoxRenderer_obj::getAdjoiningTopMargins( Array< Float > adjoiningMargins){
{
		HX_STACK_PUSH("BoxRenderer::getAdjoiningTopMargins","cocktail/core/renderer/BoxRenderer.hx",441);
		HX_STACK_THIS(this);
		HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
		HX_STACK_LINE(443)
		this->layoutSelfIfNeeded(false);
		HX_STACK_LINE(446)
		if (((this->collapseTopMarginWithParentTopMargin() == true))){
			HX_STACK_LINE(447)
			adjoiningMargins->push(this->coreStyle->usedValues->marginTop);
		}
		else{
			HX_STACK_LINE(450)
			if (((this->collapseTopMarginWithPreviousSiblingBottomMargin() == true))){
				HX_STACK_LINE(451)
				adjoiningMargins->push(this->coreStyle->usedValues->marginTop);
			}
		}
		HX_STACK_LINE(458)
		if (((this->collapseTopMarginWithFirstChildTopMargin() == true))){
			HX_STACK_LINE(459)
			this->get_firstNormalFlowChild()->getAdjoiningTopMargins(adjoiningMargins);
		}
		else{
			HX_STACK_LINE(463)
			if (((this->collapseTopMarginWithBottomMargin() == true))){
				HX_STACK_LINE(465)
				adjoiningMargins->push(this->coreStyle->usedValues->marginBottom);
				HX_STACK_LINE(468)
				if (((this->get_nextNormalFlowSibling() != null()))){
					HX_STACK_LINE(469)
					this->get_nextNormalFlowSibling()->getAdjoiningTopMargins(adjoiningMargins);
				}
			}
		}
	}
return null();
}


Float BoxRenderer_obj::getCollapsedTopMargin( ){
	HX_STACK_PUSH("BoxRenderer::getCollapsedTopMargin","cocktail/core/renderer/BoxRenderer.hx",389);
	HX_STACK_THIS(this);
	HX_STACK_LINE(391)
	this->layoutSelfIfNeeded(false);
	HX_STACK_LINE(396)
	if (((this->collapseTopMarginWithParentTopMargin() == true))){
		HX_STACK_LINE(397)
		return (int)0;
	}
	else{
		HX_STACK_LINE(401)
		if (((this->collapseTopMarginWithPreviousSiblingBottomMargin() == true))){
			HX_STACK_LINE(402)
			return (int)0;
		}
	}
	HX_STACK_LINE(409)
	if (((this->collapseTopMarginWithFirstChildTopMargin() == true))){
		HX_STACK_LINE(411)
		Array< Float > adjoiningMargins = Array_obj< Float >::__new();		HX_STACK_VAR(adjoiningMargins,"adjoiningMargins");
		HX_STACK_LINE(412)
		adjoiningMargins->push(this->coreStyle->usedValues->marginTop);
		HX_STACK_LINE(413)
		this->get_firstNormalFlowChild()->getAdjoiningTopMargins(adjoiningMargins);
		HX_STACK_LINE(415)
		return this->getCollapsedMargin(adjoiningMargins);
	}
	else{
		HX_STACK_LINE(418)
		if (((this->collapseTopMarginWithBottomMargin() == true))){
			HX_STACK_LINE(420)
			Array< Float > adjoiningMargins = Array_obj< Float >::__new();		HX_STACK_VAR(adjoiningMargins,"adjoiningMargins");
			HX_STACK_LINE(421)
			adjoiningMargins->push(this->coreStyle->usedValues->marginBottom);
			HX_STACK_LINE(423)
			if (((this->get_nextNormalFlowSibling() != null()))){
				HX_STACK_LINE(424)
				this->get_nextNormalFlowSibling()->getAdjoiningTopMargins(adjoiningMargins);
			}
			HX_STACK_LINE(428)
			return this->getCollapsedMargin(adjoiningMargins);
		}
	}
	HX_STACK_LINE(432)
	return this->coreStyle->usedValues->marginTop;
}


Void BoxRenderer_obj::computeBoxModelStyles( ::cocktail::core::layout::ContainingBlockVO containingBlockDimensions){
{
		HX_STACK_PUSH("BoxRenderer::computeBoxModelStyles","cocktail/core/renderer/BoxRenderer.hx",362);
		HX_STACK_THIS(this);
		HX_STACK_ARG(containingBlockDimensions,"containingBlockDimensions");
		HX_STACK_LINE(363)
		::cocktail::core::html::HTMLDocument htmlDocument = this->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(364)
		::cocktail::core::layout::computer::boxComputers::BoxStylesComputer boxComputer = htmlDocument->layoutManager->getBoxStylesComputer(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(boxComputer,"boxComputer");
		HX_STACK_LINE(367)
		boxComputer->measure(this->coreStyle,containingBlockDimensions);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BoxRenderer_obj,computeBoxModelStyles,(void))

Float BoxRenderer_obj::getHeightOfFirstParentWithNotAutoHeight( ){
	HX_STACK_PUSH("BoxRenderer::getHeightOfFirstParentWithNotAutoHeight","cocktail/core/renderer/BoxRenderer.hx",342);
	HX_STACK_THIS(this);
	HX_STACK_LINE(343)
	::cocktail::core::renderer::FlowBoxRenderer parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(344)
	while(((parent != null()))){
		HX_STACK_LINE(346)
		if (((parent->getContainerBlockData()->isHeightAuto == false))){
			HX_STACK_LINE(347)
			return parent->coreStyle->usedValues->height;
		}
		HX_STACK_LINE(351)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(354)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,getHeightOfFirstParentWithNotAutoHeight,return )

Void BoxRenderer_obj::updateUsedTextIndent( Float containingBlockWidth){
{
		HX_STACK_PUSH("BoxRenderer::updateUsedTextIndent","cocktail/core/renderer/BoxRenderer.hx",322);
		HX_STACK_THIS(this);
		HX_STACK_ARG(containingBlockWidth,"containingBlockWidth");
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::renderer::BoxRenderer_obj *__this){
				HX_STACK_PUSH("*::closure","cocktail/core/renderer/BoxRenderer.hx",323);
				{
					HX_STACK_LINE(323)
					::cocktail::core::css::CoreStyle _this = __this->coreStyle;		HX_STACK_VAR(_this,"_this");
					struct _Function_2_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &_this){
							HX_STACK_PUSH("*::closure","cocktail/core/renderer/BoxRenderer.hx",323);
							{
								HX_STACK_LINE(323)
								::cocktail::core::animation::Transition transition = _this->_transitionManager->getTransition((int)47,_this);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(323)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)47)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(323)
					return (  (((_this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)47)) : ::cocktail::core::css::CSSPropertyValue((  (((_this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)47)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(_this)) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(322)
		{
			::cocktail::core::css::CSSPropertyValue _switch_1 = (_Function_1_1::Block(this));
			switch((_switch_1)->GetIndex()){
				case 18: {
					Float value = _switch_1->__Param(0);
{
						HX_STACK_LINE(325)
						this->coreStyle->usedValues->textIndent = value;
					}
				}
				;break;
				case 2: {
					Float value = _switch_1->__Param(0);
{
						HX_STACK_LINE(328)
						this->coreStyle->usedValues->textIndent = (containingBlockWidth * ((value * 0.01)));
					}
				}
				;break;
				default: {
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BoxRenderer_obj,updateUsedTextIndent,(void))

Void BoxRenderer_obj::layoutSelfIfNeeded( bool forceLayout){
{
		HX_STACK_PUSH("BoxRenderer::layoutSelfIfNeeded","cocktail/core/renderer/BoxRenderer.hx",236);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_LINE(238)
		if (((bool((this->_needsLayout == false)) && bool((forceLayout == false))))){
			HX_STACK_LINE(239)
			return null();
		}
		HX_STACK_LINE(247)
		::cocktail::core::layout::ContainingBlockVO containingBlockData = this->containingBlock->getContainerBlockData();		HX_STACK_VAR(containingBlockData,"containingBlockData");
		HX_STACK_LINE(257)
		if (((containingBlockData->isHeightAuto == true))){
			HX_STACK_LINE(258)
			if (((this->coreStyle->isAbsolutelyPositioned == false))){
				struct _Function_3_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::renderer::BoxRenderer_obj *__this){
						HX_STACK_PUSH("*::closure","cocktail/core/renderer/BoxRenderer.hx",261);
						{
							HX_STACK_LINE(261)
							::cocktail::core::css::CoreStyle _this = __this->coreStyle;		HX_STACK_VAR(_this,"_this");
							struct _Function_4_1{
								inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &_this){
									HX_STACK_PUSH("*::closure","cocktail/core/renderer/BoxRenderer.hx",261);
									{
										HX_STACK_LINE(261)
										::cocktail::core::animation::Transition transition = _this->_transitionManager->getTransition((int)16,_this);		HX_STACK_VAR(transition,"transition");
										HX_STACK_LINE(261)
										return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)16)) );
									}
									return null();
								}
							};
							HX_STACK_LINE(261)
							return (  (((_this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue((  (((_this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(_this)) )) );
						}
						return null();
					}
				};
				HX_STACK_LINE(260)
				{
					::cocktail::core::css::CSSPropertyValue _switch_2 = (_Function_3_1::Block(this));
					switch((_switch_2)->GetIndex()){
						case 2: {
							Float value = _switch_2->__Param(0);
{
								HX_STACK_LINE(263)
								containingBlockData->height = this->getHeightOfFirstParentWithNotAutoHeight();
							}
						}
						;break;
						default: {
						}
					}
				}
			}
		}
		HX_STACK_LINE(281)
		if (((this->coreStyle->isAbsolutelyPositioned == true))){
			HX_STACK_LINE(282)
			if (((this->containingBlock->isBlockContainer == true))){
				HX_STACK_LINE(287)
				::cocktail::core::css::UsedValuesVO containingBlockUsedValues = this->containingBlock->coreStyle->usedValues;		HX_STACK_VAR(containingBlockUsedValues,"containingBlockUsedValues");
				HX_STACK_LINE(288)
				hx::AddEq(containingBlockData->height,(containingBlockUsedValues->paddingTop + containingBlockUsedValues->paddingBottom));
				HX_STACK_LINE(289)
				hx::AddEq(containingBlockData->width,(containingBlockUsedValues->paddingLeft + containingBlockUsedValues->paddingRight));
			}
		}
		HX_STACK_LINE(295)
		if (((this->coreStyle->isBlock == true))){
			HX_STACK_LINE(296)
			if (((this->childrenInline() == true))){
				HX_STACK_LINE(298)
				this->updateUsedTextIndent(containingBlockData->width);
			}
		}
		HX_STACK_LINE(304)
		this->computeBoxModelStyles(containingBlockData);
		HX_STACK_LINE(309)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(310)
		this->bounds->width = ((((usedValues->width + usedValues->paddingLeft) + usedValues->paddingRight) + usedValues->borderLeftWidth) + usedValues->borderRightWidth);
		HX_STACK_LINE(311)
		this->bounds->height = ((((usedValues->height + usedValues->paddingTop) + usedValues->paddingBottom) + usedValues->borderTopWidth) + usedValues->borderBottomWidth);
		HX_STACK_LINE(314)
		this->_needsLayout = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BoxRenderer_obj,layoutSelfIfNeeded,(void))

Void BoxRenderer_obj::layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BoxRenderer::layout","cocktail/core/renderer/BoxRenderer.hx",223);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(223)
		this->layoutSelfIfNeeded(forceLayout);
	}
return null();
}


Void BoxRenderer_obj::renderChildren( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BoxRenderer::renderChildren","cocktail/core/renderer/BoxRenderer.hx",209);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BoxRenderer_obj,renderChildren,(void))

Void BoxRenderer_obj::renderOutline( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BoxRenderer::renderOutline","cocktail/core/renderer/BoxRenderer.hx",199);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(200)
		::cocktail::core::geom::RectangleVO outlineBounds = this->getOutlineBounds(scrollOffset);		HX_STACK_VAR(outlineBounds,"outlineBounds");
		HX_STACK_LINE(201)
		::cocktail::core::graphics::BorderDrawer_obj::drawOutline(graphicsContext,outlineBounds,this->coreStyle,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BoxRenderer_obj,renderOutline,(void))

Void BoxRenderer_obj::renderBorder( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BoxRenderer::renderBorder","cocktail/core/renderer/BoxRenderer.hx",190);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicsContext,"graphicsContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(191)
		::cocktail::core::geom::RectangleVO borderBounds = this->getBackgroundAndBordersBounds(scrollOffset);		HX_STACK_VAR(borderBounds,"borderBounds");
		HX_STACK_LINE(192)
		::cocktail::core::graphics::BorderDrawer_obj::draw(graphicsContext,borderBounds,this->coreStyle,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BoxRenderer_obj,renderBorder,(void))

Void BoxRenderer_obj::renderBackground( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BoxRenderer::renderBackground","cocktail/core/renderer/BoxRenderer.hx",181);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(182)
		::cocktail::core::geom::RectangleVO backgroundBounds = this->getBackgroundAndBordersBounds(scrollOffset);		HX_STACK_VAR(backgroundBounds,"backgroundBounds");
		HX_STACK_LINE(183)
		::cocktail::core::background::BackgroundManager_obj::render(graphicContext,backgroundBounds,this->coreStyle,hx::ObjectPtr<OBJ_>(this),clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BoxRenderer_obj,renderBackground,(void))

Void BoxRenderer_obj::renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BoxRenderer::renderSelf","cocktail/core/renderer/BoxRenderer.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(168)
		if (((bool((this->coreStyle->hasBackgroundImage == true)) || bool((this->coreStyle->hasBackgroundColor == true))))){
			HX_STACK_LINE(169)
			this->renderBackground(graphicContext,clipRect,scrollOffset);
		}
		HX_STACK_LINE(173)
		this->renderBorder(graphicContext,clipRect,scrollOffset);
		HX_STACK_LINE(174)
		this->renderOutline(graphicContext,clipRect,scrollOffset);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BoxRenderer_obj,renderSelf,(void))

Void BoxRenderer_obj::render( ::cocktail::core::graphics::GraphicsContext parentGraphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BoxRenderer::render","cocktail/core/renderer/BoxRenderer.hx",128);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentGraphicContext,"parentGraphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(132)
		if (((this->coreStyle->isVisible == true))){
			HX_STACK_LINE(136)
			::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds->x = this->hitTestingBounds->x;
			HX_STACK_LINE(137)
			::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds->y = this->hitTestingBounds->y;
			HX_STACK_LINE(138)
			::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds->width = this->hitTestingBounds->width;
			HX_STACK_LINE(139)
			::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds->height = this->hitTestingBounds->height;
			HX_STACK_LINE(141)
			{
				HX_STACK_LINE(141)
				::cocktail::core::geom::RectangleVO bounds1 = ::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds;		HX_STACK_VAR(bounds1,"bounds1");
				::cocktail::core::geom::RectangleVO resultBounds = ::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
				HX_STACK_LINE(141)
				if (((bool((bool((bool(((bounds1->x + bounds1->width) < clipRect->x)) || bool(((clipRect->x + clipRect->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < clipRect->y)))) || bool(((clipRect->y + clipRect->height) < bounds1->y))))){
					HX_STACK_LINE(141)
					resultBounds->x = (int)0;
					HX_STACK_LINE(141)
					resultBounds->y = (int)0;
					HX_STACK_LINE(141)
					resultBounds->height = (int)0;
					HX_STACK_LINE(141)
					resultBounds->width = (int)0;
				}
				else{
					HX_STACK_LINE(141)
					Float left = (int)0;		HX_STACK_VAR(left,"left");
					HX_STACK_LINE(141)
					Float right = (int)0;		HX_STACK_VAR(right,"right");
					HX_STACK_LINE(141)
					Float top = (int)0;		HX_STACK_VAR(top,"top");
					HX_STACK_LINE(141)
					Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
					HX_STACK_LINE(141)
					if (((bounds1->x < clipRect->x))){
						HX_STACK_LINE(141)
						left = clipRect->x;
					}
					else{
						HX_STACK_LINE(141)
						left = bounds1->x;
					}
					HX_STACK_LINE(141)
					if ((((bounds1->x + bounds1->width) < (clipRect->x + clipRect->width)))){
						HX_STACK_LINE(141)
						right = (bounds1->x + bounds1->width);
					}
					else{
						HX_STACK_LINE(141)
						right = (clipRect->x + clipRect->width);
					}
					HX_STACK_LINE(141)
					if (((bounds1->y < clipRect->y))){
						HX_STACK_LINE(141)
						top = clipRect->y;
					}
					else{
						HX_STACK_LINE(141)
						top = bounds1->y;
					}
					HX_STACK_LINE(141)
					if ((((bounds1->y + bounds1->height) < (clipRect->y + clipRect->height)))){
						HX_STACK_LINE(141)
						bottom = (bounds1->y + bounds1->height);
					}
					else{
						HX_STACK_LINE(141)
						bottom = (clipRect->y + clipRect->height);
					}
					HX_STACK_LINE(141)
					resultBounds->x = left;
					HX_STACK_LINE(141)
					resultBounds->y = top;
					HX_STACK_LINE(141)
					resultBounds->width = (right - left);
					HX_STACK_LINE(141)
					resultBounds->height = (bottom - top);
				}
			}
			HX_STACK_LINE(142)
			if (((bool((::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds->width != (int)0)) && bool((::cocktail::core::renderer::BoxRenderer_obj::_intersectBounds->height != (int)0))))){
				HX_STACK_LINE(143)
				this->renderSelf(parentGraphicContext,clipRect,scrollOffset);
			}
		}
		HX_STACK_LINE(150)
		if (((this->firstChild != null()))){
			HX_STACK_LINE(151)
			this->renderChildren(parentGraphicContext,clipRect,scrollOffset);
		}
	}
return null();
}


Void BoxRenderer_obj::updateInlineBoxes( ){
{
		HX_STACK_PUSH("BoxRenderer::updateInlineBoxes","cocktail/core/renderer/BoxRenderer.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_LINE(107)
		this->inlineBoxes = Array_obj< ::cocktail::core::linebox::InlineBox >::__new();
		HX_STACK_LINE(112)
		::cocktail::core::linebox::InlineBox inlineBox = ::cocktail::core::linebox::EmbeddedInlineBox_obj::__new(hx::ObjectPtr<OBJ_>(this),this->getLeadedAscent(),this->getLeadedDescent());		HX_STACK_VAR(inlineBox,"inlineBox");
		HX_STACK_LINE(113)
		this->inlineBoxes->push(inlineBox);
		HX_STACK_LINE(116)
		this->super::updateInlineBoxes();
	}
return null();
}


::cocktail::core::geom::RectangleVO BoxRenderer_obj::_intersectBounds;


BoxRenderer_obj::BoxRenderer_obj()
{
}

void BoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoxRenderer);
	HX_MARK_MEMBER_NAME(_backgroundAndBorderBounds,"_backgroundAndBorderBounds");
	HX_MARK_MEMBER_NAME(_windowData,"_windowData");
	HX_MARK_MEMBER_NAME(_containerBlockData,"_containerBlockData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_backgroundAndBorderBounds,"_backgroundAndBorderBounds");
	HX_VISIT_MEMBER_NAME(_windowData,"_windowData");
	HX_VISIT_MEMBER_NAME(_containerBlockData,"_containerBlockData");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isVisible") ) { return isVisible_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"renderSelf") ) { return renderSelf_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_windowData") ) { return _windowData; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"renderBorder") ) { return renderBorder_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getWindowData") ) { return getWindowData_dyn(); }
		if (HX_FIELD_EQ(inName,"isTransparent") ) { return isTransparent_dyn(); }
		if (HX_FIELD_EQ(inName,"isTransformed") ) { return isTransformed_dyn(); }
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"renderOutline") ) { return renderOutline_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"renderChildren") ) { return renderChildren_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasCSSTransform") ) { return hasCSSTransform_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_intersectBounds") ) { return _intersectBounds; }
		if (HX_FIELD_EQ(inName,"getOutlineBounds") ) { return getOutlineBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"canHaveClearance") ) { return canHaveClearance_dyn(); }
		if (HX_FIELD_EQ(inName,"renderBackground") ) { return renderBackground_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateInlineBoxes") ) { return updateInlineBoxes_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getCollapsedMargin") ) { return getCollapsedMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"layoutSelfIfNeeded") ) { return layoutSelfIfNeeded_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_containerBlockData") ) { return _containerBlockData; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"isRelativePositioned") ) { return isRelativePositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"updateUsedTextIndent") ) { return updateUsedTextIndent_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getContainerBlockData") ) { return getContainerBlockData_dyn(); }
		if (HX_FIELD_EQ(inName,"hasZeroHeightChildren") ) { return hasZeroHeightChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"getCollapsedTopMargin") ) { return getCollapsedTopMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"computeBoxModelStyles") ) { return computeBoxModelStyles_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"isAbsolutelyPositioned") ) { return isAbsolutelyPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"getAdjoiningTopMargins") ) { return getAdjoiningTopMargins_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getCollapsedBottomMargin") ) { return getCollapsedBottomMargin_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getAdjoiningBottomMargins") ) { return getAdjoiningBottomMargins_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_backgroundAndBorderBounds") ) { return _backgroundAndBorderBounds; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"getBackgroundAndBordersBounds") ) { return getBackgroundAndBordersBounds_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"collapseTopMarginWithBottomMargin") ) { return collapseTopMarginWithBottomMargin_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"collapseTopMarginWithParentTopMargin") ) { return collapseTopMarginWithParentTopMargin_dyn(); }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"getHeightOfFirstParentWithNotAutoHeight") ) { return getHeightOfFirstParentWithNotAutoHeight_dyn(); }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"collapseTopMarginWithFirstChildTopMargin") ) { return collapseTopMarginWithFirstChildTopMargin_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"collapseBottomMarginWithParentBottomMargin") ) { return collapseBottomMarginWithParentBottomMargin_dyn(); }
		break;
	case 44:
		if (HX_FIELD_EQ(inName,"collapseBottomMarginWithNextSiblingTopMargin") ) { return collapseBottomMarginWithNextSiblingTopMargin_dyn(); }
		break;
	case 45:
		if (HX_FIELD_EQ(inName,"collapseBottomMarginWithLastChildBottomMargin") ) { return collapseBottomMarginWithLastChildBottomMargin_dyn(); }
		break;
	case 48:
		if (HX_FIELD_EQ(inName,"collapseTopMarginWithPreviousSiblingBottomMargin") ) { return collapseTopMarginWithPreviousSiblingBottomMargin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"_windowData") ) { _windowData=inValue.Cast< ::cocktail::core::layout::ContainingBlockVO >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_intersectBounds") ) { _intersectBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_containerBlockData") ) { _containerBlockData=inValue.Cast< ::cocktail::core::layout::ContainingBlockVO >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_backgroundAndBorderBounds") ) { _backgroundAndBorderBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_backgroundAndBorderBounds"));
	outFields->push(HX_CSTRING("_windowData"));
	outFields->push(HX_CSTRING("_containerBlockData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_intersectBounds"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getWindowData"),
	HX_CSTRING("getContainerBlockData"),
	HX_CSTRING("getOutlineBounds"),
	HX_CSTRING("getBackgroundAndBordersBounds"),
	HX_CSTRING("isTransparent"),
	HX_CSTRING("isVisible"),
	HX_CSTRING("hasCSSTransform"),
	HX_CSTRING("isTransformed"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("isRelativePositioned"),
	HX_CSTRING("isAbsolutelyPositioned"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("canHaveClearance"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("hasZeroHeightChildren"),
	HX_CSTRING("collapseTopMarginWithBottomMargin"),
	HX_CSTRING("collapseBottomMarginWithLastChildBottomMargin"),
	HX_CSTRING("collapseTopMarginWithFirstChildTopMargin"),
	HX_CSTRING("collapseBottomMarginWithNextSiblingTopMargin"),
	HX_CSTRING("collapseTopMarginWithPreviousSiblingBottomMargin"),
	HX_CSTRING("collapseBottomMarginWithParentBottomMargin"),
	HX_CSTRING("collapseTopMarginWithParentTopMargin"),
	HX_CSTRING("getCollapsedMargin"),
	HX_CSTRING("getAdjoiningBottomMargins"),
	HX_CSTRING("getCollapsedBottomMargin"),
	HX_CSTRING("getAdjoiningTopMargins"),
	HX_CSTRING("getCollapsedTopMargin"),
	HX_CSTRING("computeBoxModelStyles"),
	HX_CSTRING("getHeightOfFirstParentWithNotAutoHeight"),
	HX_CSTRING("updateUsedTextIndent"),
	HX_CSTRING("layoutSelfIfNeeded"),
	HX_CSTRING("layout"),
	HX_CSTRING("renderChildren"),
	HX_CSTRING("renderOutline"),
	HX_CSTRING("renderBorder"),
	HX_CSTRING("renderBackground"),
	HX_CSTRING("renderSelf"),
	HX_CSTRING("render"),
	HX_CSTRING("updateInlineBoxes"),
	HX_CSTRING("_backgroundAndBorderBounds"),
	HX_CSTRING("_windowData"),
	HX_CSTRING("_containerBlockData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoxRenderer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BoxRenderer_obj::_intersectBounds,"_intersectBounds");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoxRenderer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BoxRenderer_obj::_intersectBounds,"_intersectBounds");
};

Class BoxRenderer_obj::__mClass;

void BoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.BoxRenderer"), hx::TCanCast< BoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BoxRenderer_obj::__boot()
{
	_intersectBounds= ::cocktail::core::geom::RectangleVO_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
