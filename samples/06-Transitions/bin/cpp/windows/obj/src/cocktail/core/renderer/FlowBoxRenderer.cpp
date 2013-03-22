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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
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

Void FlowBoxRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("FlowBoxRenderer::new","cocktail/core/renderer/FlowBoxRenderer.hx",62);
{
	HX_STACK_LINE(63)
	super::__construct(node);
	HX_STACK_LINE(64)
	this->_absolutelyPositionedChildren = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_STACK_LINE(65)
	this->_childStaticOrigin = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
}
;
	return null();
}

FlowBoxRenderer_obj::~FlowBoxRenderer_obj() { }

Dynamic FlowBoxRenderer_obj::__CreateEmpty() { return  new FlowBoxRenderer_obj; }
hx::ObjectPtr< FlowBoxRenderer_obj > FlowBoxRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< FlowBoxRenderer_obj > result = new FlowBoxRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic FlowBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlowBoxRenderer_obj > result = new FlowBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::geom::PointVO FlowBoxRenderer_obj::getPositionAfterInlineBox( ::cocktail::core::linebox::InlineBox inlineBox,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::PointVO staticOrigin){
	HX_STACK_PUSH("FlowBoxRenderer::getPositionAfterInlineBox","cocktail/core/renderer/FlowBoxRenderer.hx",434);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inlineBox,"inlineBox");
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(staticOrigin,"staticOrigin");
	HX_STACK_LINE(440)
	if (((inlineBox->lineBox == null()))){
		HX_STACK_LINE(442)
		staticOrigin->x = elementRenderer->coreStyle->usedValues->marginLeft;
		HX_STACK_LINE(443)
		staticOrigin->y = elementRenderer->coreStyle->usedValues->marginTop;
	}
	else{
		HX_STACK_LINE(447)
		staticOrigin->x = ((((inlineBox->bounds->x + inlineBox->lineBox->bounds->x) + inlineBox->bounds->width) + inlineBox->marginLeft) + inlineBox->marginRight);
		HX_STACK_LINE(448)
		hx::AddEq(staticOrigin->x,elementRenderer->coreStyle->usedValues->marginLeft);
		HX_STACK_LINE(450)
		staticOrigin->y = (inlineBox->bounds->y + inlineBox->lineBox->bounds->y);
		HX_STACK_LINE(451)
		hx::AddEq(staticOrigin->y,elementRenderer->coreStyle->usedValues->marginTop);
	}
	HX_STACK_LINE(454)
	return staticOrigin;
}


HX_DEFINE_DYNAMIC_FUNC3(FlowBoxRenderer_obj,getPositionAfterInlineBox,return )

::cocktail::core::geom::PointVO FlowBoxRenderer_obj::getStaticPosition( ::cocktail::core::renderer::ElementRenderer elementRenderer){
	HX_STACK_PUSH("FlowBoxRenderer::getStaticPosition","cocktail/core/renderer/FlowBoxRenderer.hx",348);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_LINE(352)
	::cocktail::core::renderer::ElementRenderer staticContainingBlock = elementRenderer->parentNode;		HX_STACK_VAR(staticContainingBlock,"staticContainingBlock");
	HX_STACK_LINE(353)
	while(((staticContainingBlock != null()))){
		HX_STACK_LINE(355)
		if (((staticContainingBlock->isBlockContainer == true))){
			HX_STACK_LINE(356)
			break;
		}
		HX_STACK_LINE(360)
		staticContainingBlock = staticContainingBlock->parentNode;
	}
	HX_STACK_LINE(369)
	if (((staticContainingBlock->childrenInline() == false))){
		HX_STACK_LINE(372)
		::cocktail::core::renderer::ElementRenderer previousNormalFlowSibling = elementRenderer->get_previousNormalFlowSibling();		HX_STACK_VAR(previousNormalFlowSibling,"previousNormalFlowSibling");
		HX_STACK_LINE(375)
		if (((previousNormalFlowSibling == null()))){
			HX_STACK_LINE(378)
			this->_childStaticOrigin->x = elementRenderer->coreStyle->usedValues->marginLeft;
			HX_STACK_LINE(379)
			this->_childStaticOrigin->y = elementRenderer->coreStyle->usedValues->marginTop;
		}
		else{
			HX_STACK_LINE(384)
			this->_childStaticOrigin->x = elementRenderer->coreStyle->usedValues->marginLeft;
			HX_STACK_LINE(387)
			this->_childStaticOrigin->y = ((previousNormalFlowSibling->bounds->y + previousNormalFlowSibling->bounds->height) + previousNormalFlowSibling->coreStyle->usedValues->marginBottom);
			HX_STACK_LINE(389)
			hx::AddEq(this->_childStaticOrigin->y,elementRenderer->coreStyle->usedValues->marginTop);
		}
	}
	else{
		HX_STACK_LINE(396)
		::cocktail::core::renderer::ElementRenderer previousNormalFlowSibling = elementRenderer->get_previousNormalFlowSibling();		HX_STACK_VAR(previousNormalFlowSibling,"previousNormalFlowSibling");
		HX_STACK_LINE(399)
		if (((previousNormalFlowSibling == null()))){
			HX_STACK_LINE(402)
			::cocktail::core::renderer::ElementRenderer parent = elementRenderer->parentNode;		HX_STACK_VAR(parent,"parent");
			HX_STACK_LINE(405)
			if (((parent->isBlockContainer == true))){
				HX_STACK_LINE(408)
				this->_childStaticOrigin->x = elementRenderer->coreStyle->usedValues->marginLeft;
				HX_STACK_LINE(409)
				this->_childStaticOrigin->y = elementRenderer->coreStyle->usedValues->marginTop;
			}
			else{
				HX_STACK_LINE(414)
				::cocktail::core::linebox::InlineBox lastInlineBox = parent->inlineBoxes->__get((parent->inlineBoxes->length - (int)1));		HX_STACK_VAR(lastInlineBox,"lastInlineBox");
				HX_STACK_LINE(415)
				this->_childStaticOrigin = this->getPositionAfterInlineBox(lastInlineBox,elementRenderer,this->_childStaticOrigin);
			}
		}
		else{
			HX_STACK_LINE(421)
			::cocktail::core::linebox::InlineBox lastInlineBox = previousNormalFlowSibling->inlineBoxes->__get((previousNormalFlowSibling->inlineBoxes->length - (int)1));		HX_STACK_VAR(lastInlineBox,"lastInlineBox");
			HX_STACK_LINE(422)
			this->_childStaticOrigin = this->getPositionAfterInlineBox(lastInlineBox,elementRenderer,this->_childStaticOrigin);
		}
	}
	HX_STACK_LINE(426)
	return this->_childStaticOrigin;
}


HX_DEFINE_DYNAMIC_FUNC1(FlowBoxRenderer_obj,getStaticPosition,return )

Float FlowBoxRenderer_obj::getBottomOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float containingHTMLElementHeight,bool isAbsolutelyPositioned){
	HX_STACK_PUSH("FlowBoxRenderer::getBottomOffset","cocktail/core/renderer/FlowBoxRenderer.hx",326);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(containingHTMLElementHeight,"containingHTMLElementHeight");
	HX_STACK_ARG(isAbsolutelyPositioned,"isAbsolutelyPositioned");
	HX_STACK_LINE(327)
	::cocktail::core::css::UsedValuesVO usedValues = elementRenderer->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(329)
	Float bottomOffset = (((((containingHTMLElementHeight - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->bottom) - usedValues->marginBottom);		HX_STACK_VAR(bottomOffset,"bottomOffset");
	HX_STACK_LINE(333)
	if (((isAbsolutelyPositioned == true))){
		HX_STACK_LINE(334)
		hx::AddEq(bottomOffset,(this->coreStyle->usedValues->paddingBottom + this->coreStyle->usedValues->borderBottomWidth));
	}
	HX_STACK_LINE(338)
	return bottomOffset;
}


HX_DEFINE_DYNAMIC_FUNC3(FlowBoxRenderer_obj,getBottomOffset,return )

Float FlowBoxRenderer_obj::getTopOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,bool isAbsolutelyPositioned){
	HX_STACK_PUSH("FlowBoxRenderer::getTopOffset","cocktail/core/renderer/FlowBoxRenderer.hx",308);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(isAbsolutelyPositioned,"isAbsolutelyPositioned");
	HX_STACK_LINE(309)
	::cocktail::core::css::UsedValuesVO usedValues = elementRenderer->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(311)
	Float topOffset = (usedValues->top + usedValues->marginTop);		HX_STACK_VAR(topOffset,"topOffset");
	HX_STACK_LINE(314)
	if (((isAbsolutelyPositioned == true))){
		HX_STACK_LINE(315)
		hx::SubEq(topOffset,(this->coreStyle->usedValues->paddingTop - this->coreStyle->usedValues->borderTopWidth));
	}
	HX_STACK_LINE(319)
	return topOffset;
}


HX_DEFINE_DYNAMIC_FUNC2(FlowBoxRenderer_obj,getTopOffset,return )

Float FlowBoxRenderer_obj::getRightOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float containingHTMLElementWidth,bool isAbsolutelyPositioned){
	HX_STACK_PUSH("FlowBoxRenderer::getRightOffset","cocktail/core/renderer/FlowBoxRenderer.hx",289);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(containingHTMLElementWidth,"containingHTMLElementWidth");
	HX_STACK_ARG(isAbsolutelyPositioned,"isAbsolutelyPositioned");
	HX_STACK_LINE(290)
	::cocktail::core::css::UsedValuesVO usedValues = elementRenderer->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(292)
	Float rightOffset = (((((((containingHTMLElementWidth - usedValues->width) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->right) - usedValues->marginRight);		HX_STACK_VAR(rightOffset,"rightOffset");
	HX_STACK_LINE(296)
	if (((isAbsolutelyPositioned == true))){
		HX_STACK_LINE(297)
		hx::AddEq(rightOffset,(this->coreStyle->usedValues->paddingRight + this->coreStyle->usedValues->borderRightWidth));
	}
	HX_STACK_LINE(301)
	return rightOffset;
}


HX_DEFINE_DYNAMIC_FUNC3(FlowBoxRenderer_obj,getRightOffset,return )

Float FlowBoxRenderer_obj::getLeftOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,bool isAbsolutelyPositioned){
	HX_STACK_PUSH("FlowBoxRenderer::getLeftOffset","cocktail/core/renderer/FlowBoxRenderer.hx",269);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(isAbsolutelyPositioned,"isAbsolutelyPositioned");
	HX_STACK_LINE(270)
	::cocktail::core::css::UsedValuesVO usedValues = elementRenderer->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(271)
	Float leftOffset = (usedValues->left + usedValues->marginLeft);		HX_STACK_VAR(leftOffset,"leftOffset");
	HX_STACK_LINE(277)
	if (((isAbsolutelyPositioned == true))){
		HX_STACK_LINE(278)
		hx::SubEq(leftOffset,(this->coreStyle->usedValues->paddingLeft - this->coreStyle->usedValues->borderLeftWidth));
	}
	HX_STACK_LINE(282)
	return leftOffset;
}


HX_DEFINE_DYNAMIC_FUNC2(FlowBoxRenderer_obj,getLeftOffset,return )

Void FlowBoxRenderer_obj::doLayoutPositionedChild( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::layout::ContainingBlockVO containingBlockData,bool isAbsolutelyPositioned){
{
		HX_STACK_PUSH("FlowBoxRenderer::doLayoutPositionedChild","cocktail/core/renderer/FlowBoxRenderer.hx",225);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_ARG(isAbsolutelyPositioned,"isAbsolutelyPositioned");
		HX_STACK_LINE(226)
		::cocktail::core::css::CoreStyle elementCoreStyle = elementRenderer->coreStyle;		HX_STACK_VAR(elementCoreStyle,"elementCoreStyle");
		HX_STACK_LINE(230)
		if (((elementCoreStyle->hasAutoLeft == false))){
			HX_STACK_LINE(231)
			elementRenderer->bounds->x = this->getLeftOffset(elementRenderer,isAbsolutelyPositioned);
		}
		else{
			HX_STACK_LINE(237)
			if (((elementCoreStyle->hasAutoRight == false))){
				HX_STACK_LINE(238)
				elementRenderer->bounds->x = this->getRightOffset(elementRenderer,containingBlockData->width,isAbsolutelyPositioned);
			}
			else{
				HX_STACK_LINE(246)
				elementRenderer->staticOrigin->x = this->getStaticPosition(elementRenderer)->x;
			}
		}
		HX_STACK_LINE(251)
		if (((elementCoreStyle->hasAutoTop == false))){
			HX_STACK_LINE(252)
			elementRenderer->bounds->y = this->getTopOffset(elementRenderer,isAbsolutelyPositioned);
		}
		else{
			HX_STACK_LINE(255)
			if (((elementCoreStyle->hasAutoBottom == false))){
				HX_STACK_LINE(256)
				elementRenderer->bounds->y = this->getBottomOffset(elementRenderer,containingBlockData->height,isAbsolutelyPositioned);
			}
			else{
				HX_STACK_LINE(260)
				elementRenderer->staticOrigin->y = this->getStaticPosition(elementRenderer)->y;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlowBoxRenderer_obj,doLayoutPositionedChild,(void))

Void FlowBoxRenderer_obj::layoutPositionedChild( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::layout::ContainingBlockVO firstPositionedAncestorData,::cocktail::core::layout::ContainingBlockVO viewportData){
{
		HX_STACK_PUSH("FlowBoxRenderer::layoutPositionedChild","cocktail/core/renderer/FlowBoxRenderer.hx",204);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(firstPositionedAncestorData,"firstPositionedAncestorData");
		HX_STACK_ARG(viewportData,"viewportData");
		HX_STACK_LINE(205)
		::cocktail::core::css::CoreStyle coreStyle = elementRenderer->coreStyle;		HX_STACK_VAR(coreStyle,"coreStyle");
		HX_STACK_LINE(207)
		if (((coreStyle->isFixedPositioned == true))){
			HX_STACK_LINE(208)
			this->doLayoutPositionedChild(elementRenderer,viewportData,false);
		}
		else{
			HX_STACK_LINE(213)
			this->doLayoutPositionedChild(elementRenderer,firstPositionedAncestorData,true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlowBoxRenderer_obj,layoutPositionedChild,(void))

Void FlowBoxRenderer_obj::layoutAbsolutelyPositionedChildren( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("FlowBoxRenderer::layoutAbsolutelyPositionedChildren","cocktail/core/renderer/FlowBoxRenderer.hx",181);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(182)
		::cocktail::core::layout::ContainingBlockVO containerBlockData = this->getContainerBlockData();		HX_STACK_VAR(containerBlockData,"containerBlockData");
		HX_STACK_LINE(183)
		::cocktail::core::layout::ContainingBlockVO windowData = this->getWindowData();		HX_STACK_VAR(windowData,"windowData");
		HX_STACK_LINE(186)
		int length = this->_absolutelyPositionedChildren->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(187)
		{
			HX_STACK_LINE(187)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(187)
			while(((_g < length))){
				HX_STACK_LINE(187)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(189)
				this->_absolutelyPositionedChildren->__get(i)->layout(true,layoutState);
				HX_STACK_LINE(192)
				this->layoutPositionedChild(this->_absolutelyPositionedChildren->__get(i),containerBlockData,windowData);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlowBoxRenderer_obj,layoutAbsolutelyPositionedChildren,(void))

Void FlowBoxRenderer_obj::layoutChildren( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("FlowBoxRenderer::layoutChildren","cocktail/core/renderer/FlowBoxRenderer.hx",173);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlowBoxRenderer_obj,layoutChildren,(void))

Void FlowBoxRenderer_obj::layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("FlowBoxRenderer::layout","cocktail/core/renderer/FlowBoxRenderer.hx",140);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(141)
		this->super::layout(forceLayout,layoutState);
		HX_STACK_LINE(144)
		if (((this->firstChild != null()))){
			HX_STACK_LINE(145)
			this->layoutChildren(layoutState);
		}
		HX_STACK_LINE(153)
		if (((this->isPositioned() == true))){
			HX_STACK_LINE(154)
			if (((this->_absolutelyPositionedChildren->length > (int)0))){
				HX_STACK_LINE(157)
				this->layoutAbsolutelyPositionedChildren(layoutState);
			}
		}
	}
return null();
}


Void FlowBoxRenderer_obj::removeAbsolutelyPositionedChild( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_STACK_PUSH("FlowBoxRenderer::removeAbsolutelyPositionedChild","cocktail/core/renderer/FlowBoxRenderer.hx",127);
		HX_STACK_THIS(this);
		HX_STACK_ARG(element,"element");
		HX_STACK_LINE(127)
		this->_absolutelyPositionedChildren->remove(element);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlowBoxRenderer_obj,removeAbsolutelyPositionedChild,(void))

Void FlowBoxRenderer_obj::addAbsolutelyPositionedChildren( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_STACK_PUSH("FlowBoxRenderer::addAbsolutelyPositionedChildren","cocktail/core/renderer/FlowBoxRenderer.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_ARG(element,"element");
		HX_STACK_LINE(118)
		this->_absolutelyPositionedChildren->push(element);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlowBoxRenderer_obj,addAbsolutelyPositionedChildren,(void))

Void FlowBoxRenderer_obj::renderInlineChildren( ::cocktail::core::renderer::ElementRenderer rootRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("FlowBoxRenderer::renderInlineChildren","cocktail/core/renderer/FlowBoxRenderer.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootRenderer,"rootRenderer");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(86)
		::cocktail::core::renderer::ElementRenderer child = rootRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(87)
		while(((child != null()))){
			HX_STACK_LINE(89)
			if (((child->layerRenderer == referenceLayer))){
				HX_STACK_LINE(90)
				if (((child->coreStyle->isFloat == false))){
					HX_STACK_LINE(93)
					child->render(graphicContext,clipRect,scrollOffset);
					HX_STACK_LINE(96)
					if (((bool((child->firstChild != null())) && bool((child->establishesNewBlockFormattingContext() == false))))){
						HX_STACK_LINE(97)
						this->renderInlineChildren(child,referenceLayer,graphicContext,clipRect,scrollOffset);
					}
				}
			}
			HX_STACK_LINE(104)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlowBoxRenderer_obj,renderInlineChildren,(void))


FlowBoxRenderer_obj::FlowBoxRenderer_obj()
{
}

void FlowBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlowBoxRenderer);
	HX_MARK_MEMBER_NAME(_childStaticOrigin,"_childStaticOrigin");
	HX_MARK_MEMBER_NAME(_absolutelyPositionedChildren,"_absolutelyPositionedChildren");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlowBoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_childStaticOrigin,"_childStaticOrigin");
	HX_VISIT_MEMBER_NAME(_absolutelyPositionedChildren,"_absolutelyPositionedChildren");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FlowBoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getTopOffset") ) { return getTopOffset_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getLeftOffset") ) { return getLeftOffset_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getRightOffset") ) { return getRightOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"layoutChildren") ) { return layoutChildren_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getBottomOffset") ) { return getBottomOffset_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getStaticPosition") ) { return getStaticPosition_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_childStaticOrigin") ) { return _childStaticOrigin; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"renderInlineChildren") ) { return renderInlineChildren_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"layoutPositionedChild") ) { return layoutPositionedChild_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"doLayoutPositionedChild") ) { return doLayoutPositionedChild_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getPositionAfterInlineBox") ) { return getPositionAfterInlineBox_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"_absolutelyPositionedChildren") ) { return _absolutelyPositionedChildren; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"removeAbsolutelyPositionedChild") ) { return removeAbsolutelyPositionedChild_dyn(); }
		if (HX_FIELD_EQ(inName,"addAbsolutelyPositionedChildren") ) { return addAbsolutelyPositionedChildren_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"layoutAbsolutelyPositionedChildren") ) { return layoutAbsolutelyPositionedChildren_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlowBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"_childStaticOrigin") ) { _childStaticOrigin=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"_absolutelyPositionedChildren") ) { _absolutelyPositionedChildren=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlowBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_childStaticOrigin"));
	outFields->push(HX_CSTRING("_absolutelyPositionedChildren"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getPositionAfterInlineBox"),
	HX_CSTRING("getStaticPosition"),
	HX_CSTRING("getBottomOffset"),
	HX_CSTRING("getTopOffset"),
	HX_CSTRING("getRightOffset"),
	HX_CSTRING("getLeftOffset"),
	HX_CSTRING("doLayoutPositionedChild"),
	HX_CSTRING("layoutPositionedChild"),
	HX_CSTRING("layoutAbsolutelyPositionedChildren"),
	HX_CSTRING("layoutChildren"),
	HX_CSTRING("layout"),
	HX_CSTRING("removeAbsolutelyPositionedChild"),
	HX_CSTRING("addAbsolutelyPositionedChildren"),
	HX_CSTRING("renderInlineChildren"),
	HX_CSTRING("_childStaticOrigin"),
	HX_CSTRING("_absolutelyPositionedChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlowBoxRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlowBoxRenderer_obj::__mClass,"__mClass");
};

Class FlowBoxRenderer_obj::__mClass;

void FlowBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.FlowBoxRenderer"), hx::TCanCast< FlowBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FlowBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
