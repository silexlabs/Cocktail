#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_InitialStyleDeclaration
#include <cocktail/core/css/InitialStyleDeclaration.h>
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
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
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
#ifndef INCLUDED_cocktail_core_layout_FloatVO
#include <cocktail/core/layout/FloatVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_FloatsVO
#include <cocktail/core/layout/FloatsVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_InlineFormattingVO
#include <cocktail/core/layout/InlineFormattingVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_floats_FloatsManager
#include <cocktail/core/layout/floats/FloatsManager.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_LineBox
#include <cocktail/core/linebox/LineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_AnonymousBlockBoxRenderer
#include <cocktail/core/renderer/AnonymousBlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
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

Void BlockBoxRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("BlockBoxRenderer::new","cocktail/core/renderer/BlockBoxRenderer.hx",127);
{
	HX_STACK_LINE(128)
	super::__construct(node);
	HX_STACK_LINE(130)
	this->_lineBoxPosition = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(131)
	this->_childPosition = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(132)
	this->lineBoxes = Array_obj< ::cocktail::core::linebox::LineBox >::__new();
	HX_STACK_LINE(133)
	this->floatsManager = ::cocktail::core::layout::floats::FloatsManager_obj::__new();
	HX_STACK_LINE(134)
	this->_floatFound = false;
	HX_STACK_LINE(135)
	this->_inlineBoxGlobalBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(136)
	this->_blockFormattingBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(137)
	this->_floatedElementsBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(138)
	this->_childBlockFormattingBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(139)
	this->_offsetFromBlockFormattingRoot = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(141)
	this->isBlockContainer = true;
}
;
	return null();
}

BlockBoxRenderer_obj::~BlockBoxRenderer_obj() { }

Dynamic BlockBoxRenderer_obj::__CreateEmpty() { return  new BlockBoxRenderer_obj; }
hx::ObjectPtr< BlockBoxRenderer_obj > BlockBoxRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< BlockBoxRenderer_obj > result = new BlockBoxRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic BlockBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlockBoxRenderer_obj > result = new BlockBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::renderer::BlockBoxRenderer BlockBoxRenderer_obj::getNearestBlockFormattingContextRoot( ){
	HX_STACK_PUSH("BlockBoxRenderer::getNearestBlockFormattingContextRoot","cocktail/core/renderer/BlockBoxRenderer.hx",1681);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1682)
	::cocktail::core::renderer::ElementRenderer parent = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1684)
	while(((parent != null()))){
		HX_STACK_LINE(1686)
		if (((parent->establishesNewBlockFormattingContext() == true))){
			HX_STACK_LINE(1687)
			return parent;
		}
		HX_STACK_LINE(1691)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1694)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,getNearestBlockFormattingContextRoot,return )

::cocktail::core::geom::PointVO BlockBoxRenderer_obj::getBlockBoxesOffset( ::cocktail::core::renderer::BlockBoxRenderer target,::cocktail::core::renderer::BlockBoxRenderer source){
	HX_STACK_PUSH("BlockBoxRenderer::getBlockBoxesOffset","cocktail/core/renderer/BlockBoxRenderer.hx",1655);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(source,"source");
	HX_STACK_LINE(1656)
	::cocktail::core::geom::PointVO offset = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(1658)
	::cocktail::core::renderer::ElementRenderer parent = target;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1659)
	while(((parent != null()))){
		HX_STACK_LINE(1661)
		if (((parent == source))){
			HX_STACK_LINE(1662)
			return offset;
		}
		HX_STACK_LINE(1666)
		hx::AddEq(offset->x,parent->bounds->x);
		HX_STACK_LINE(1667)
		hx::AddEq(offset->y,parent->bounds->y);
		HX_STACK_LINE(1669)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1673)
	return offset;
}


HX_DEFINE_DYNAMIC_FUNC2(BlockBoxRenderer_obj,getBlockBoxesOffset,return )

bool BlockBoxRenderer_obj::establishesNewBlockFormattingContextOnlyBecauseOfOverflow( ){
	HX_STACK_PUSH("BlockBoxRenderer::establishesNewBlockFormattingContextOnlyBecauseOfOverflow","cocktail/core/renderer/BlockBoxRenderer.hx",1637);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1637)
	if (((bool((bool((bool((this->coreStyle->isFloat == false)) && bool((this->coreStyle->isAbsolutelyPositioned == false)))) && bool((this->coreStyle->isInlineBlock == false)))) && bool((this->coreStyle->canAlwaysOverflow == false))))){
		HX_STACK_LINE(1641)
		return true;
	}
	else{
		HX_STACK_LINE(1645)
		return false;
	}
	HX_STACK_LINE(1637)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,establishesNewBlockFormattingContextOnlyBecauseOfOverflow,return )

::cocktail::core::geom::RectangleVO BlockBoxRenderer_obj::getBackgroundAndBordersBounds( ::cocktail::core::geom::PointVO scrollOffset){
	HX_STACK_PUSH("BlockBoxRenderer::getBackgroundAndBordersBounds","cocktail/core/renderer/BlockBoxRenderer.hx",1616);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scrollOffset,"scrollOffset");
	HX_STACK_LINE(1617)
	::cocktail::core::geom::RectangleVO backgroundAndBordersBounds = this->super::getBackgroundAndBordersBounds(scrollOffset);		HX_STACK_VAR(backgroundAndBordersBounds,"backgroundAndBordersBounds");
	HX_STACK_LINE(1619)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1621)
		hx::AddEq(backgroundAndBordersBounds->x,this->layerRenderer->scrollLeft);
		HX_STACK_LINE(1622)
		hx::AddEq(backgroundAndBordersBounds->y,this->layerRenderer->scrollTop);
	}
	HX_STACK_LINE(1625)
	return backgroundAndBordersBounds;
}


bool BlockBoxRenderer_obj::childrenInline( ){
	HX_STACK_PUSH("BlockBoxRenderer::childrenInline","cocktail/core/renderer/BlockBoxRenderer.hx",1583);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1584)
	::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(1585)
	while(((child != null()))){
		HX_STACK_LINE(1587)
		if (((child->isInlineLevel() == true))){
			HX_STACK_LINE(1588)
			if (((child->isFloat() == false))){
				HX_STACK_LINE(1592)
				if (((child->isAbsolutelyPositioned() == false))){
					HX_STACK_LINE(1594)
					return true;
				}
			}
		}
		HX_STACK_LINE(1600)
		child = child->nextSibling;
	}
	HX_STACK_LINE(1602)
	return false;
}


bool BlockBoxRenderer_obj::establishesNewBlockFormattingContext( ){
	HX_STACK_PUSH("BlockBoxRenderer::establishesNewBlockFormattingContext","cocktail/core/renderer/BlockBoxRenderer.hx",1547);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1549)
	if (((this->coreStyle->isFloat == true))){
		HX_STACK_LINE(1550)
		return true;
	}
	else{
		HX_STACK_LINE(1555)
		if (((this->coreStyle->canAlwaysOverflow == false))){
			HX_STACK_LINE(1556)
			return true;
		}
		else{
			HX_STACK_LINE(1560)
			if (((bool((this->coreStyle->isPositioned == true)) && bool((this->coreStyle->isRelativePositioned == false))))){
				HX_STACK_LINE(1561)
				return true;
			}
			else{
				HX_STACK_LINE(1564)
				if (((this->coreStyle->isInlineBlock == true))){
					HX_STACK_LINE(1565)
					return true;
				}
			}
		}
	}
	HX_STACK_LINE(1572)
	return false;
}


bool BlockBoxRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("BlockBoxRenderer::createOwnLayer","cocktail/core/renderer/BlockBoxRenderer.hx",1527);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1530)
	bool createOwnLayer = this->super::createOwnLayer();		HX_STACK_VAR(createOwnLayer,"createOwnLayer");
	HX_STACK_LINE(1532)
	if (((createOwnLayer == true))){
		HX_STACK_LINE(1533)
		return true;
	}
	HX_STACK_LINE(1537)
	return (this->coreStyle->canAlwaysOverflow != true);
}


bool BlockBoxRenderer_obj::hasZeroHeightChildren( ){
	HX_STACK_PUSH("BlockBoxRenderer::hasZeroHeightChildren","cocktail/core/renderer/BlockBoxRenderer.hx",1492);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1494)
	if (((this->childrenInline() == true))){
		HX_STACK_LINE(1498)
		int lineBoxesLength = this->lineBoxes->length;		HX_STACK_VAR(lineBoxesLength,"lineBoxesLength");
		HX_STACK_LINE(1499)
		{
			HX_STACK_LINE(1499)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1499)
			while(((_g < lineBoxesLength))){
				HX_STACK_LINE(1499)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1501)
				if (((this->lineBoxes->__get(i)->bounds->height > (int)0))){
					HX_STACK_LINE(1502)
					return false;
				}
			}
		}
	}
	else{
		HX_STACK_LINE(1509)
		return (this->bounds->height == (int)0);
	}
	HX_STACK_LINE(1515)
	return true;
}


bool BlockBoxRenderer_obj::collapseBottomMarginWithLastChildBottomMargin( ){
	HX_STACK_PUSH("BlockBoxRenderer::collapseBottomMarginWithLastChildBottomMargin","cocktail/core/renderer/BlockBoxRenderer.hx",1483);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1483)
	return false;
}


bool BlockBoxRenderer_obj::collapseTopMarginWithFirstChildTopMargin( ){
	HX_STACK_PUSH("BlockBoxRenderer::collapseTopMarginWithFirstChildTopMargin","cocktail/core/renderer/BlockBoxRenderer.hx",1441);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1443)
	if (((this->get_firstNormalFlowChild() == null()))){
		HX_STACK_LINE(1444)
		return false;
	}
	HX_STACK_LINE(1449)
	if (((this->get_firstNormalFlowChild()->isBlockContainer == false))){
		HX_STACK_LINE(1450)
		return false;
	}
	HX_STACK_LINE(1456)
	if (((this->establishesNewBlockFormattingContext() == true))){
		HX_STACK_LINE(1457)
		return false;
	}
	HX_STACK_LINE(1462)
	if (((bool((this->coreStyle->usedValues->paddingTop != (int)0)) || bool((this->get_firstNormalFlowChild()->coreStyle->usedValues->paddingTop != (int)0))))){
		HX_STACK_LINE(1463)
		return false;
	}
	HX_STACK_LINE(1468)
	if (((bool((this->coreStyle->usedValues->borderTopWidth != (int)0)) || bool((this->get_firstNormalFlowChild()->coreStyle->usedValues->borderTopWidth != (int)0))))){
		HX_STACK_LINE(1469)
		return false;
	}
	HX_STACK_LINE(1473)
	return true;
}


Void BlockBoxRenderer_obj::updateInlineChildrenBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer){
{
		HX_STACK_PUSH("BlockBoxRenderer::updateInlineChildrenBounds","cocktail/core/renderer/BlockBoxRenderer.hx",1375);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_LINE(1377)
		::cocktail::core::renderer::ElementRenderer child = elementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(1378)
		while(((child != null()))){
			HX_STACK_LINE(1381)
			if (((bool(((bool((child->isPositioned() == false)) || bool((child->isRelativePositioned() == true))))) && bool((child->isFloat() == false))))){
				HX_STACK_LINE(1386)
				if (((bool((child->firstChild != null())) && bool((child->establishesNewBlockFormattingContext() == false))))){
					HX_STACK_LINE(1387)
					this->updateInlineChildrenBounds(child);
				}
				HX_STACK_LINE(1392)
				child->bounds->width = (int)0;
				HX_STACK_LINE(1393)
				child->bounds->height = (int)0;
				HX_STACK_LINE(1394)
				child->bounds->x = (int)50000;
				HX_STACK_LINE(1395)
				child->bounds->y = (int)50000;
				HX_STACK_LINE(1400)
				int inlineBoxesLength = child->inlineBoxes->length;		HX_STACK_VAR(inlineBoxesLength,"inlineBoxesLength");
				HX_STACK_LINE(1404)
				if (((inlineBoxesLength == (int)0))){
					HX_STACK_LINE(1406)
					child->bounds->x = (int)0;
					HX_STACK_LINE(1407)
					child->bounds->y = (int)0;
				}
				HX_STACK_LINE(1410)
				{
					HX_STACK_LINE(1410)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(1410)
					while(((_g < inlineBoxesLength))){
						HX_STACK_LINE(1410)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(1412)
						::cocktail::core::linebox::InlineBox inlineBox = child->inlineBoxes->__get(i);		HX_STACK_VAR(inlineBox,"inlineBox");
						HX_STACK_LINE(1417)
						this->_inlineBoxGlobalBounds->width = inlineBox->bounds->width;
						HX_STACK_LINE(1418)
						this->_inlineBoxGlobalBounds->height = inlineBox->bounds->height;
						HX_STACK_LINE(1420)
						if (((inlineBox->lineBox != null()))){
							HX_STACK_LINE(1422)
							this->_inlineBoxGlobalBounds->x = (inlineBox->bounds->x + inlineBox->lineBox->bounds->x);
							HX_STACK_LINE(1423)
							this->_inlineBoxGlobalBounds->y = (inlineBox->bounds->y + inlineBox->lineBox->bounds->y);
						}
						HX_STACK_LINE(1427)
						{
							HX_STACK_LINE(1427)
							::cocktail::core::geom::RectangleVO addedBounds = this->_inlineBoxGlobalBounds;		HX_STACK_VAR(addedBounds,"addedBounds");
							::cocktail::core::geom::RectangleVO bounds = child->bounds;		HX_STACK_VAR(bounds,"bounds");
							bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
							bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
							HX_STACK_LINE(1427)
							if (((getHorizontalBounds == true))){
								HX_STACK_LINE(1427)
								if (((addedBounds->x < bounds->x))){
									HX_STACK_LINE(1427)
									bounds->x = addedBounds->x;
								}
								HX_STACK_LINE(1427)
								if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
									HX_STACK_LINE(1427)
									bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
								}
							}
							HX_STACK_LINE(1427)
							if (((getVerticalBounds == true))){
								HX_STACK_LINE(1427)
								if (((addedBounds->y < bounds->y))){
									HX_STACK_LINE(1427)
									bounds->y = addedBounds->y;
								}
								HX_STACK_LINE(1427)
								if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
									HX_STACK_LINE(1427)
									bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(1431)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,updateInlineChildrenBounds,(void))

::cocktail::core::linebox::InlineBox BlockBoxRenderer_obj::doLayoutInlineChildrenAndFloats( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::layout::InlineFormattingVO inlineFormattingData,::cocktail::core::layout::LayoutStateValue layoutState){
	HX_STACK_PUSH("BlockBoxRenderer::doLayoutInlineChildrenAndFloats","cocktail/core/renderer/BlockBoxRenderer.hx",1184);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_ARG(inlineFormattingData,"inlineFormattingData");
	HX_STACK_ARG(layoutState,"layoutState");
	HX_STACK_LINE(1186)
	::cocktail::core::renderer::ElementRenderer child = elementRenderer->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(1187)
	while(((child != null()))){
		HX_STACK_LINE(1190)
		if (((bool((child->isPositioned() == false)) || bool((child->isRelativePositioned() == true))))){
			HX_STACK_LINE(1191)
			if (((child->isFloat() == true))){
				HX_STACK_LINE(1196)
				child->layout(true,layoutState);
				HX_STACK_LINE(1201)
				if (((child->canHaveClearance() == true))){
					HX_STACK_LINE(1203)
					Float hypotheticalChildYPosition = (inlineFormattingData->lineBoxPosition->y + child->coreStyle->usedValues->marginTop);		HX_STACK_VAR(hypotheticalChildYPosition,"hypotheticalChildYPosition");
					HX_STACK_LINE(1205)
					if (((this->floatsManager->hasClearance(child,hypotheticalChildYPosition) == true))){
						HX_STACK_LINE(1207)
						this->registerClearElement(child);
						HX_STACK_LINE(1211)
						Float clearance = this->floatsManager->getClearance(child,hypotheticalChildYPosition);		HX_STACK_VAR(clearance,"clearance");
						HX_STACK_LINE(1212)
						::cocktail::core::geom::PointVO clearedFloatPosition = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);		HX_STACK_VAR(clearedFloatPosition,"clearedFloatPosition");
						HX_STACK_LINE(1213)
						clearedFloatPosition->y = (inlineFormattingData->lineBoxPosition->y + clearance);
						HX_STACK_LINE(1214)
						this->registerFloatedElement(child,clearedFloatPosition);
						HX_STACK_LINE(1215)
						this->_floatFound = true;
					}
				}
				else{
					HX_STACK_LINE(1223)
					Float floatMarginWidth = ((child->bounds->width + child->coreStyle->usedValues->marginLeft) + child->coreStyle->usedValues->marginRight);		HX_STACK_VAR(floatMarginWidth,"floatMarginWidth");
					HX_STACK_LINE(1224)
					if (((inlineFormattingData->lineBox->widthCanFit(floatMarginWidth) == false))){
						HX_STACK_LINE(1225)
						this->layoutLineBox(inlineFormattingData,layoutState);
					}
					HX_STACK_LINE(1231)
					this->registerFloatedElement(child,inlineFormattingData->lineBoxPosition);
					HX_STACK_LINE(1236)
					this->_floatFound = true;
				}
			}
			else{
				HX_STACK_LINE(1242)
				if (((child->isText == true))){
					HX_STACK_LINE(1246)
					int textLength = child->inlineBoxes->length;		HX_STACK_VAR(textLength,"textLength");
					HX_STACK_LINE(1247)
					{
						HX_STACK_LINE(1247)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(1247)
						while(((_g < textLength))){
							HX_STACK_LINE(1247)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(1249)
							bool lineIsFull = inlineFormattingData->lineBox->insert(child->inlineBoxes->__get(i),inlineFormattingData->inlineBox,false);		HX_STACK_VAR(lineIsFull,"lineIsFull");
							HX_STACK_LINE(1251)
							if (((lineIsFull == true))){
								HX_STACK_LINE(1255)
								this->layoutLineBox(inlineFormattingData,layoutState);
								HX_STACK_LINE(1261)
								inlineFormattingData->lineBox->insert(child->inlineBoxes->__get(i),inlineFormattingData->inlineBox,true);
							}
						}
					}
				}
				else{
					HX_STACK_LINE(1267)
					if (((bool((child->establishesNewBlockFormattingContext() == true)) || bool((child->isReplaced == true))))){
						HX_STACK_LINE(1271)
						child->layout(true,layoutState);
						HX_STACK_LINE(1275)
						::cocktail::core::linebox::InlineBox childInlineBox = child->inlineBoxes->__get((int)0);		HX_STACK_VAR(childInlineBox,"childInlineBox");
						HX_STACK_LINE(1278)
						childInlineBox->bounds->height = child->bounds->height;
						HX_STACK_LINE(1279)
						childInlineBox->bounds->width = child->bounds->width;
						HX_STACK_LINE(1280)
						childInlineBox->marginLeft = child->coreStyle->usedValues->marginLeft;
						HX_STACK_LINE(1281)
						childInlineBox->marginRight = child->coreStyle->usedValues->marginRight;
						HX_STACK_LINE(1284)
						bool lineIsFull = inlineFormattingData->lineBox->insert(childInlineBox,inlineFormattingData->inlineBox,false);		HX_STACK_VAR(lineIsFull,"lineIsFull");
						HX_STACK_LINE(1286)
						if (((lineIsFull == true))){
							HX_STACK_LINE(1288)
							this->layoutLineBox(inlineFormattingData,layoutState);
							HX_STACK_LINE(1289)
							inlineFormattingData->lineBox->insert(childInlineBox,inlineFormattingData->inlineBox,true);
						}
					}
					else{
						HX_STACK_LINE(1294)
						if (((child->firstChild != null()))){
							HX_STACK_LINE(1298)
							child->layout(true,::cocktail::core::layout::LayoutStateValue_obj::NORMAL_dyn());
							HX_STACK_LINE(1301)
							child->inlineBoxes = Array_obj< ::cocktail::core::linebox::InlineBox >::__new();
							HX_STACK_LINE(1304)
							::cocktail::core::linebox::InlineBox childInlineBox = ::cocktail::core::linebox::InlineBox_obj::__new(child,child->getLeadedAscent(),child->getLeadedDescent());		HX_STACK_VAR(childInlineBox,"childInlineBox");
							HX_STACK_LINE(1305)
							childInlineBox->lineBox = inlineFormattingData->lineBox;
							HX_STACK_LINE(1306)
							child->inlineBoxes->push(childInlineBox);
							HX_STACK_LINE(1308)
							::cocktail::core::css::UsedValuesVO childUsedValues = child->coreStyle->usedValues;		HX_STACK_VAR(childUsedValues,"childUsedValues");
							HX_STACK_LINE(1311)
							childInlineBox->marginLeft = childUsedValues->marginLeft;
							HX_STACK_LINE(1312)
							childInlineBox->paddingLeft = childUsedValues->paddingLeft;
							HX_STACK_LINE(1313)
							childInlineBox->borderLeft = childUsedValues->borderLeftWidth;
							HX_STACK_LINE(1316)
							inlineFormattingData->lineBox->addUnbreakableWidth(((childUsedValues->marginLeft + childUsedValues->paddingLeft) + childUsedValues->borderLeftWidth));
							HX_STACK_LINE(1320)
							inlineFormattingData->inlineBox->appendChild(childInlineBox);
							HX_STACK_LINE(1322)
							inlineFormattingData->inlineBox = childInlineBox;
							HX_STACK_LINE(1329)
							inlineFormattingData->openedElementRenderers->push(child);
							HX_STACK_LINE(1335)
							inlineFormattingData->inlineBox = this->doLayoutInlineChildrenAndFloats(child,inlineFormattingData,layoutState);
							HX_STACK_LINE(1340)
							if (((this->_floatFound == true))){
								HX_STACK_LINE(1341)
								return null();
							}
							HX_STACK_LINE(1348)
							inlineFormattingData->openedElementRenderers->pop();
							HX_STACK_LINE(1352)
							inlineFormattingData->inlineBox = inlineFormattingData->inlineBox->parentNode;
							HX_STACK_LINE(1356)
							::cocktail::core::linebox::InlineBox lastInLineBox = child->inlineBoxes->__get((child->inlineBoxes->length - (int)1));		HX_STACK_VAR(lastInLineBox,"lastInLineBox");
							HX_STACK_LINE(1357)
							lastInLineBox->marginRight = childUsedValues->marginRight;
							HX_STACK_LINE(1358)
							lastInLineBox->paddingRight = childUsedValues->paddingRight;
							HX_STACK_LINE(1359)
							inlineFormattingData->lineBox->addUnbreakableWidth((childUsedValues->marginRight + childUsedValues->paddingRight));
						}
					}
				}
			}
		}
		HX_STACK_LINE(1363)
		child = child->nextSibling;
	}
	HX_STACK_LINE(1366)
	return inlineFormattingData->inlineBox;
}


HX_DEFINE_DYNAMIC_FUNC3(BlockBoxRenderer_obj,doLayoutInlineChildrenAndFloats,return )

Void BlockBoxRenderer_obj::layoutLineBox( ::cocktail::core::layout::InlineFormattingVO inlineFormattingData,::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BlockBoxRenderer::layoutLineBox","cocktail/core/renderer/BlockBoxRenderer.hx",1119);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inlineFormattingData,"inlineFormattingData");
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(1120)
		::cocktail::core::linebox::LineBox lineBox = inlineFormattingData->lineBox;		HX_STACK_VAR(lineBox,"lineBox");
		HX_STACK_LINE(1121)
		::cocktail::core::geom::PointVO lineBoxPosition = inlineFormattingData->lineBoxPosition;		HX_STACK_VAR(lineBoxPosition,"lineBoxPosition");
		HX_STACK_LINE(1122)
		Array< ::cocktail::core::renderer::ElementRenderer > openedElementRenderers = inlineFormattingData->openedElementRenderers;		HX_STACK_VAR(openedElementRenderers,"openedElementRenderers");
		HX_STACK_LINE(1124)
		lineBox->layout(false,null());
		HX_STACK_LINE(1128)
		hx::AddEq(lineBoxPosition->y,lineBox->bounds->height);
		HX_STACK_LINE(1136)
		Float firstAvailableY = lineBoxPosition->y;		HX_STACK_VAR(firstAvailableY,"firstAvailableY");
		HX_STACK_LINE(1137)
		if (((this->floatsManager->hasFloats == true))){
			HX_STACK_LINE(1139)
			firstAvailableY = this->floatsManager->getFirstAvailableYPosition((lineBoxPosition->y + this->_offsetFromBlockFormattingRoot->y),this->coreStyle->usedValues->lineHeight,lineBox->unbreakableWidth,this->coreStyle->usedValues->width,this->_offsetFromBlockFormattingRoot->x);
			HX_STACK_LINE(1143)
			hx::SubEq(firstAvailableY,this->_offsetFromBlockFormattingRoot->y);
		}
		HX_STACK_LINE(1146)
		lineBoxPosition->y = firstAvailableY;
		HX_STACK_LINE(1148)
		::cocktail::core::linebox::LineBox newLineBox = this->createLineBox(lineBoxPosition,layoutState);		HX_STACK_VAR(newLineBox,"newLineBox");
		HX_STACK_LINE(1152)
		::cocktail::core::linebox::InlineBox currentInlineBox = newLineBox->rootInlineBox;		HX_STACK_VAR(currentInlineBox,"currentInlineBox");
		HX_STACK_LINE(1156)
		int length = openedElementRenderers->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(1157)
		{
			HX_STACK_LINE(1157)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1157)
			while(((_g < length))){
				HX_STACK_LINE(1157)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1163)
				::cocktail::core::linebox::InlineBox childInlineBox = ::cocktail::core::linebox::InlineBox_obj::__new(openedElementRenderers->__get(i),openedElementRenderers->__get(i)->getLeadedAscent(),openedElementRenderers->__get(i)->getLeadedDescent());		HX_STACK_VAR(childInlineBox,"childInlineBox");
				HX_STACK_LINE(1164)
				childInlineBox->lineBox = newLineBox;
				HX_STACK_LINE(1165)
				openedElementRenderers->__get(i)->inlineBoxes->push(childInlineBox);
				HX_STACK_LINE(1166)
				currentInlineBox->appendChild(childInlineBox);
				HX_STACK_LINE(1167)
				currentInlineBox = childInlineBox;
			}
		}
		HX_STACK_LINE(1170)
		inlineFormattingData->lineBox = newLineBox;
		HX_STACK_LINE(1171)
		inlineFormattingData->inlineBox = currentInlineBox;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BlockBoxRenderer_obj,layoutLineBox,(void))

::cocktail::core::linebox::LineBox BlockBoxRenderer_obj::createLineBox( ::cocktail::core::geom::PointVO lineBoxPosition,::cocktail::core::layout::LayoutStateValue layoutState){
	HX_STACK_PUSH("BlockBoxRenderer::createLineBox","cocktail/core/renderer/BlockBoxRenderer.hx",1073);
	HX_STACK_THIS(this);
	HX_STACK_ARG(lineBoxPosition,"lineBoxPosition");
	HX_STACK_ARG(layoutState,"layoutState");
	HX_STACK_LINE(1078)
	Float availableWidth = this->coreStyle->usedValues->width;		HX_STACK_VAR(availableWidth,"availableWidth");
	HX_STACK_LINE(1081)
	if (((this->floatsManager->hasFloats == true))){
		HX_STACK_LINE(1082)
		availableWidth = (this->floatsManager->getRightFloatOffset((lineBoxPosition->y + this->_offsetFromBlockFormattingRoot->y),this->coreStyle->usedValues->lineHeight,(int)0,this->_offsetFromBlockFormattingRoot->x,this->coreStyle->usedValues->width) - this->floatsManager->getLeftFloatOffset((lineBoxPosition->y + this->_offsetFromBlockFormattingRoot->y),this->coreStyle->usedValues->lineHeight,this->_offsetFromBlockFormattingRoot->x));
	}
	HX_STACK_LINE(1088)
	::cocktail::core::linebox::LineBox lineBox = ::cocktail::core::linebox::LineBox_obj::__new(hx::ObjectPtr<OBJ_>(this),availableWidth,(this->lineBoxes->length == (int)0),layoutState);		HX_STACK_VAR(lineBox,"lineBox");
	HX_STACK_LINE(1092)
	lineBox->bounds->y = lineBoxPosition->y;
	HX_STACK_LINE(1095)
	Float leftFloatOffset = (int)0;		HX_STACK_VAR(leftFloatOffset,"leftFloatOffset");
	HX_STACK_LINE(1097)
	if (((this->floatsManager->hasFloats == true))){
		HX_STACK_LINE(1099)
		leftFloatOffset = this->floatsManager->getLeftFloatOffset((lineBox->bounds->y + this->_offsetFromBlockFormattingRoot->y),this->coreStyle->usedValues->lineHeight,this->_offsetFromBlockFormattingRoot->x);
		HX_STACK_LINE(1103)
		hx::SubEq(leftFloatOffset,this->_offsetFromBlockFormattingRoot->x);
	}
	HX_STACK_LINE(1106)
	lineBox->bounds->x = leftFloatOffset;
	HX_STACK_LINE(1107)
	this->lineBoxes->push(lineBox);
	HX_STACK_LINE(1108)
	this->hasLineBoxes = true;
	HX_STACK_LINE(1110)
	return lineBox;
}


HX_DEFINE_DYNAMIC_FUNC2(BlockBoxRenderer_obj,createLineBox,return )

Void BlockBoxRenderer_obj::layoutInlineChildrenAndFloats( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BlockBoxRenderer::layoutInlineChildrenAndFloats","cocktail/core/renderer/BlockBoxRenderer.hx",1023);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(1025)
		this->lineBoxes = Array_obj< ::cocktail::core::linebox::LineBox >::__new();
		HX_STACK_LINE(1026)
		this->hasLineBoxes = false;
		HX_STACK_LINE(1031)
		this->_lineBoxPosition->x = (int)0;
		HX_STACK_LINE(1032)
		this->_lineBoxPosition->y = (int)0;
		HX_STACK_LINE(1034)
		::cocktail::core::linebox::LineBox firstLineBox = this->createLineBox(this->_lineBoxPosition,layoutState);		HX_STACK_VAR(firstLineBox,"firstLineBox");
		HX_STACK_LINE(1037)
		Array< ::cocktail::core::renderer::ElementRenderer > openedElementRendererStack = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();		HX_STACK_VAR(openedElementRendererStack,"openedElementRendererStack");
		HX_STACK_LINE(1040)
		::cocktail::core::layout::InlineFormattingVO inlineFormattingData = ::cocktail::core::layout::InlineFormattingVO_obj::__new();		HX_STACK_VAR(inlineFormattingData,"inlineFormattingData");
		HX_STACK_LINE(1041)
		inlineFormattingData->inlineBox = firstLineBox->rootInlineBox;
		HX_STACK_LINE(1042)
		inlineFormattingData->lineBox = firstLineBox;
		HX_STACK_LINE(1043)
		inlineFormattingData->openedElementRenderers = openedElementRendererStack;
		HX_STACK_LINE(1044)
		inlineFormattingData->lineBoxPosition = this->_lineBoxPosition;
		HX_STACK_LINE(1047)
		::cocktail::core::linebox::InlineBox lastInlineBox = this->doLayoutInlineChildrenAndFloats(hx::ObjectPtr<OBJ_>(this),inlineFormattingData,layoutState);		HX_STACK_VAR(lastInlineBox,"lastInlineBox");
		HX_STACK_LINE(1054)
		if (((this->_floatFound == true))){
			HX_STACK_LINE(1055)
			this->_floatFound = false;
		}
		HX_STACK_LINE(1061)
		inlineFormattingData->lineBox->layout(true,lastInlineBox);
		HX_STACK_LINE(1065)
		hx::AddEq(this->_lineBoxPosition->y,inlineFormattingData->lineBox->bounds->height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,layoutInlineChildrenAndFloats,(void))

Void BlockBoxRenderer_obj::registerFloatedElement( ::cocktail::core::renderer::ElementRenderer floatedElement,::cocktail::core::geom::PointVO childPosition){
{
		HX_STACK_PUSH("BlockBoxRenderer::registerFloatedElement","cocktail/core/renderer/BlockBoxRenderer.hx",997);
		HX_STACK_THIS(this);
		HX_STACK_ARG(floatedElement,"floatedElement");
		HX_STACK_ARG(childPosition,"childPosition");
		HX_STACK_LINE(998)
		::cocktail::core::renderer::BlockBoxRenderer blockFormattingContextRoot = this->getNearestBlockFormattingContextRoot();		HX_STACK_VAR(blockFormattingContextRoot,"blockFormattingContextRoot");
		HX_STACK_LINE(1001)
		Float contentWidth = ((((this->bounds->width - this->coreStyle->usedValues->paddingLeft) - this->coreStyle->usedValues->paddingRight) - this->coreStyle->usedValues->borderLeftWidth) - this->coreStyle->usedValues->borderRightWidth);		HX_STACK_VAR(contentWidth,"contentWidth");
		HX_STACK_LINE(1005)
		::cocktail::core::geom::RectangleVO floatBounds = blockFormattingContextRoot->floatsManager->registerFloat(floatedElement,(childPosition->y + this->_offsetFromBlockFormattingRoot->y),contentWidth,this->_offsetFromBlockFormattingRoot->x);		HX_STACK_VAR(floatBounds,"floatBounds");
		HX_STACK_LINE(1010)
		floatedElement->bounds->x = (floatBounds->x + floatedElement->coreStyle->usedValues->marginLeft);
		HX_STACK_LINE(1011)
		floatedElement->bounds->y = (floatBounds->y + floatedElement->coreStyle->usedValues->marginTop);
		HX_STACK_LINE(1014)
		hx::SubEq(floatedElement->bounds->x,this->_offsetFromBlockFormattingRoot->x);
		HX_STACK_LINE(1015)
		hx::SubEq(floatedElement->bounds->y,this->_offsetFromBlockFormattingRoot->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BlockBoxRenderer_obj,registerFloatedElement,(void))

Void BlockBoxRenderer_obj::registerClearElement( ::cocktail::core::renderer::ElementRenderer clearElement){
{
		HX_STACK_PUSH("BlockBoxRenderer::registerClearElement","cocktail/core/renderer/BlockBoxRenderer.hx",986);
		HX_STACK_THIS(this);
		HX_STACK_ARG(clearElement,"clearElement");
		HX_STACK_LINE(987)
		::cocktail::core::renderer::BlockBoxRenderer blockFormattingContextRoot = this->getNearestBlockFormattingContextRoot();		HX_STACK_VAR(blockFormattingContextRoot,"blockFormattingContextRoot");
		HX_STACK_LINE(988)
		blockFormattingContextRoot->floatsManager->registerClear(clearElement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,registerClearElement,(void))

Void BlockBoxRenderer_obj::layoutBlockChildrenAndFloats( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BlockBoxRenderer::layoutBlockChildrenAndFloats","cocktail/core/renderer/BlockBoxRenderer.hx",826);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(829)
		this->_childPosition->x = (int)0;
		HX_STACK_LINE(830)
		this->_childPosition->y = (int)0;
		HX_STACK_LINE(833)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(834)
		while(((child != null()))){
			HX_STACK_LINE(837)
			if (((bool((child->isPositioned() == false)) || bool((child->isRelativePositioned() == true))))){
				HX_STACK_LINE(841)
				bool childHasClearance = false;		HX_STACK_VAR(childHasClearance,"childHasClearance");
				HX_STACK_LINE(845)
				if (((child->canHaveClearance() == true))){
					HX_STACK_LINE(848)
					Float hypotheticalChildYPosition = (this->_childPosition->y + child->getCollapsedTopMargin());		HX_STACK_VAR(hypotheticalChildYPosition,"hypotheticalChildYPosition");
					HX_STACK_LINE(852)
					if (((this->floatsManager->hasClearance(child,(hypotheticalChildYPosition + this->_offsetFromBlockFormattingRoot->y)) == true))){
						HX_STACK_LINE(854)
						this->registerClearElement(child);
						HX_STACK_LINE(858)
						Float clearance = this->floatsManager->getClearance(child,(hypotheticalChildYPosition + this->_offsetFromBlockFormattingRoot->y));		HX_STACK_VAR(clearance,"clearance");
						HX_STACK_LINE(860)
						hx::AddEq(this->_childPosition->y,clearance);
						HX_STACK_LINE(861)
						childHasClearance = true;
					}
				}
				HX_STACK_LINE(866)
				child->layout(true,layoutState);
				HX_STACK_LINE(869)
				if (((child->isFloat() == false))){
					HX_STACK_LINE(872)
					if (((bool((child->establishesNewBlockFormattingContext() == false)) && bool((child->isBlockContainer == true))))){
						HX_STACK_LINE(875)
						if (((childHasClearance == false))){
							HX_STACK_LINE(876)
							hx::AddEq(this->_childPosition->y,child->getCollapsedTopMargin());
						}
						HX_STACK_LINE(886)
						child->bounds->x = child->coreStyle->usedValues->marginLeft;
						HX_STACK_LINE(887)
						child->bounds->y = this->_childPosition->y;
					}
					else{
						HX_STACK_LINE(896)
						Float childMarginWidth = ((child->bounds->width + child->coreStyle->usedValues->marginLeft) + child->coreStyle->usedValues->marginRight);		HX_STACK_VAR(childMarginWidth,"childMarginWidth");
						HX_STACK_LINE(897)
						Float childMarginHeight = ((child->bounds->height + child->getCollapsedTopMargin()) + child->getCollapsedBottomMargin());		HX_STACK_VAR(childMarginHeight,"childMarginHeight");
						HX_STACK_LINE(898)
						Float contentWidth = ((((this->bounds->width - this->coreStyle->usedValues->paddingLeft) - this->coreStyle->usedValues->paddingRight) - this->coreStyle->usedValues->borderLeftWidth) - this->coreStyle->usedValues->borderRightWidth);		HX_STACK_VAR(contentWidth,"contentWidth");
						HX_STACK_LINE(900)
						Float firstYPosition = this->_childPosition->y;		HX_STACK_VAR(firstYPosition,"firstYPosition");
						HX_STACK_LINE(901)
						if (((this->floatsManager->hasFloats == true))){
							HX_STACK_LINE(903)
							firstYPosition = this->floatsManager->getFirstAvailableYPosition((this->_childPosition->y + this->_offsetFromBlockFormattingRoot->y),childMarginHeight,childMarginWidth,contentWidth,this->_offsetFromBlockFormattingRoot->x);
							HX_STACK_LINE(908)
							this->_childPosition->y = (firstYPosition - this->_offsetFromBlockFormattingRoot->y);
						}
						HX_STACK_LINE(912)
						if (((childHasClearance == false))){
							HX_STACK_LINE(913)
							hx::AddEq(this->_childPosition->y,child->getCollapsedTopMargin());
						}
						HX_STACK_LINE(920)
						child->bounds->y = this->_childPosition->y;
						HX_STACK_LINE(922)
						Float leftFloatOffset = (int)0;		HX_STACK_VAR(leftFloatOffset,"leftFloatOffset");
						HX_STACK_LINE(923)
						if (((this->floatsManager->hasFloats == true))){
							HX_STACK_LINE(925)
							Float leftFloatOffset1 = this->floatsManager->getLeftFloatOffset((this->_childPosition->y + this->_offsetFromBlockFormattingRoot->y),childMarginHeight,this->_offsetFromBlockFormattingRoot->x);		HX_STACK_VAR(leftFloatOffset1,"leftFloatOffset1");
							HX_STACK_LINE(929)
							hx::SubEq(leftFloatOffset1,this->_offsetFromBlockFormattingRoot->x);
						}
						HX_STACK_LINE(934)
						if (((leftFloatOffset > child->coreStyle->usedValues->marginLeft))){
							HX_STACK_LINE(935)
							child->bounds->x = leftFloatOffset;
						}
						else{
							HX_STACK_LINE(939)
							child->bounds->x = child->coreStyle->usedValues->marginLeft;
						}
					}
					HX_STACK_LINE(945)
					hx::AddEq(this->_childPosition->y,child->bounds->height);
					HX_STACK_LINE(948)
					hx::AddEq(this->_childPosition->y,child->getCollapsedBottomMargin());
				}
				else{
					HX_STACK_LINE(953)
					::cocktail::core::geom::PointVO childPosition = this->_childPosition;		HX_STACK_VAR(childPosition,"childPosition");
					HX_STACK_LINE(958)
					::cocktail::core::renderer::ElementRenderer previousFlowSibling = child->get_previousNormalFlowSibling();		HX_STACK_VAR(previousFlowSibling,"previousFlowSibling");
					HX_STACK_LINE(959)
					if (((previousFlowSibling != null()))){
						HX_STACK_LINE(960)
						if (((previousFlowSibling->isAnonymousBlockBox() == true))){
							HX_STACK_LINE(962)
							if (((previousFlowSibling->childrenInline() == true))){
								HX_STACK_LINE(965)
								childPosition = ::cocktail::core::geom::PointVO_obj::__new(this->_childPosition->x,this->_childPosition->y);
								HX_STACK_LINE(966)
								::cocktail::core::renderer::AnonymousBlockBoxRenderer blockPreviousSibling = previousFlowSibling;		HX_STACK_VAR(blockPreviousSibling,"blockPreviousSibling");
								HX_STACK_LINE(967)
								::cocktail::core::linebox::LineBox lastLineBox = blockPreviousSibling->lineBoxes->__get((blockPreviousSibling->lineBoxes->length - (int)1));		HX_STACK_VAR(lastLineBox,"lastLineBox");
								HX_STACK_LINE(968)
								childPosition->y = (lastLineBox->bounds->y + blockPreviousSibling->bounds->y);
							}
						}
					}
					HX_STACK_LINE(973)
					this->registerFloatedElement(child,childPosition);
				}
			}
			HX_STACK_LINE(977)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,layoutBlockChildrenAndFloats,(void))

bool BlockBoxRenderer_obj::isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight( ){
	HX_STACK_PUSH("BlockBoxRenderer::isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight","cocktail/core/renderer/BlockBoxRenderer.hx",812);
	HX_STACK_THIS(this);
	HX_STACK_LINE(813)
	if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
		HX_STACK_LINE(814)
		return (bool((this->coreStyle->hasAutoLeft == false)) && bool((this->coreStyle->hasAutoRight == false)));
	}
	HX_STACK_LINE(818)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight,return )

bool BlockBoxRenderer_obj::isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom( ){
	HX_STACK_PUSH("BlockBoxRenderer::isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom","cocktail/core/renderer/BlockBoxRenderer.hx",797);
	HX_STACK_THIS(this);
	HX_STACK_LINE(798)
	if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
		HX_STACK_LINE(799)
		return (bool((this->coreStyle->hasAutoTop == false)) && bool((this->coreStyle->hasAutoBottom == false)));
	}
	HX_STACK_LINE(803)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom,return )

Void BlockBoxRenderer_obj::applyContentHeightIfNeeded( ){
{
		HX_STACK_PUSH("BlockBoxRenderer::applyContentHeightIfNeeded","cocktail/core/renderer/BlockBoxRenderer.hx",736);
		HX_STACK_THIS(this);
		HX_STACK_LINE(736)
		if (((bool((this->coreStyle->hasAutoHeight == true)) && bool((this->isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom() == false))))){
			HX_STACK_LINE(741)
			Float childrenHeight = (int)0;		HX_STACK_VAR(childrenHeight,"childrenHeight");
			HX_STACK_LINE(742)
			if (((this->childrenInline() == false))){
				HX_STACK_LINE(743)
				childrenHeight = this->_childPosition->y;
			}
			else{
				HX_STACK_LINE(747)
				childrenHeight = this->_lineBoxPosition->y;
			}
			HX_STACK_LINE(753)
			if (((this->establishesNewBlockFormattingContext() == true))){
				HX_STACK_LINE(756)
				this->getFloatedElementsBounds();
				HX_STACK_LINE(758)
				if ((((this->_floatedElementsBounds->y + this->_floatedElementsBounds->height) > childrenHeight))){
					HX_STACK_LINE(759)
					childrenHeight = (this->_floatedElementsBounds->y + this->_floatedElementsBounds->height);
				}
			}
			HX_STACK_LINE(765)
			if (((this->coreStyle->hasMaxHeight == true))){
				HX_STACK_LINE(766)
				if (((childrenHeight > this->coreStyle->usedValues->maxHeight))){
					HX_STACK_LINE(768)
					childrenHeight = this->coreStyle->usedValues->maxHeight;
				}
			}
			HX_STACK_LINE(773)
			if (((childrenHeight < this->coreStyle->usedValues->minHeight))){
				HX_STACK_LINE(774)
				childrenHeight = this->coreStyle->usedValues->minHeight;
			}
			HX_STACK_LINE(778)
			this->coreStyle->usedValues->height = childrenHeight;
			HX_STACK_LINE(780)
			this->bounds->height = ((((childrenHeight + this->coreStyle->usedValues->paddingTop) + this->coreStyle->usedValues->paddingBottom) + this->coreStyle->usedValues->borderTopWidth) + this->coreStyle->usedValues->borderBottomWidth);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,applyContentHeightIfNeeded,(void))

Void BlockBoxRenderer_obj::doGetFloatedElementsBounds( Array< ::cocktail::core::layout::FloatVO > floats,::cocktail::core::geom::RectangleVO floatedElementsBounds){
{
		HX_STACK_PUSH("BlockBoxRenderer::doGetFloatedElementsBounds","cocktail/core/renderer/BlockBoxRenderer.hx",724);
		HX_STACK_THIS(this);
		HX_STACK_ARG(floats,"floats");
		HX_STACK_ARG(floatedElementsBounds,"floatedElementsBounds");
		HX_STACK_LINE(725)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = floats->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(725)
		while(((_g1 < _g))){
			HX_STACK_LINE(725)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(727)
			{
				HX_STACK_LINE(727)
				::cocktail::core::geom::RectangleVO addedBounds = floats->__get(i)->bounds;		HX_STACK_VAR(addedBounds,"addedBounds");
				bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
				bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
				HX_STACK_LINE(727)
				if (((getHorizontalBounds == true))){
					HX_STACK_LINE(727)
					if (((addedBounds->x < floatedElementsBounds->x))){
						HX_STACK_LINE(727)
						floatedElementsBounds->x = addedBounds->x;
					}
					HX_STACK_LINE(727)
					if ((((addedBounds->x + addedBounds->width) > (floatedElementsBounds->x + floatedElementsBounds->width)))){
						HX_STACK_LINE(727)
						floatedElementsBounds->width = ((addedBounds->x + addedBounds->width) - floatedElementsBounds->x);
					}
				}
				HX_STACK_LINE(727)
				if (((getVerticalBounds == true))){
					HX_STACK_LINE(727)
					if (((addedBounds->y < floatedElementsBounds->y))){
						HX_STACK_LINE(727)
						floatedElementsBounds->y = addedBounds->y;
					}
					HX_STACK_LINE(727)
					if ((((addedBounds->y + addedBounds->height) > (floatedElementsBounds->y + floatedElementsBounds->height)))){
						HX_STACK_LINE(727)
						floatedElementsBounds->height = ((addedBounds->y + addedBounds->height) - floatedElementsBounds->y);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BlockBoxRenderer_obj,doGetFloatedElementsBounds,(void))

Void BlockBoxRenderer_obj::getFloatedElementsBounds( ){
{
		HX_STACK_PUSH("BlockBoxRenderer::getFloatedElementsBounds","cocktail/core/renderer/BlockBoxRenderer.hx",698);
		HX_STACK_THIS(this);
		HX_STACK_LINE(699)
		this->_floatedElementsBounds->x = (int)50000;
		HX_STACK_LINE(700)
		this->_floatedElementsBounds->y = (int)50000;
		HX_STACK_LINE(701)
		this->_floatedElementsBounds->width = (int)0;
		HX_STACK_LINE(702)
		this->_floatedElementsBounds->height = (int)0;
		HX_STACK_LINE(706)
		if (((bool((this->floatsManager->floats->left->length == (int)0)) && bool((this->floatsManager->floats->right->length == (int)0))))){
			HX_STACK_LINE(708)
			this->_floatedElementsBounds->x = (int)0;
			HX_STACK_LINE(709)
			this->_floatedElementsBounds->y = (int)0;
			HX_STACK_LINE(710)
			return null();
		}
		HX_STACK_LINE(715)
		this->doGetFloatedElementsBounds(this->floatsManager->floats->left,this->_floatedElementsBounds);
		HX_STACK_LINE(716)
		this->doGetFloatedElementsBounds(this->floatsManager->floats->right,this->_floatedElementsBounds);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,getFloatedElementsBounds,(void))

Void BlockBoxRenderer_obj::doGetBlockFormattingBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO blockFormattingBounds,Float xOffset,Float yOffset){
{
		HX_STACK_PUSH("BlockBoxRenderer::doGetBlockFormattingBounds","cocktail/core/renderer/BlockBoxRenderer.hx",667);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(blockFormattingBounds,"blockFormattingBounds");
		HX_STACK_ARG(xOffset,"xOffset");
		HX_STACK_ARG(yOffset,"yOffset");
		HX_STACK_LINE(668)
		::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(669)
		while(((child != null()))){
			HX_STACK_LINE(671)
			if (((child->isFloat() == false))){
				HX_STACK_LINE(672)
				if (((child->isAbsolutelyPositioned() == false))){
					HX_STACK_LINE(675)
					this->_childBlockFormattingBounds->x = ((child->bounds->x + xOffset) - child->coreStyle->usedValues->marginLeft);
					HX_STACK_LINE(676)
					this->_childBlockFormattingBounds->y = ((child->bounds->y + yOffset) - child->coreStyle->usedValues->marginTop);
					HX_STACK_LINE(677)
					this->_childBlockFormattingBounds->width = ((child->bounds->width + child->coreStyle->usedValues->marginRight) + child->coreStyle->usedValues->marginLeft);
					HX_STACK_LINE(678)
					this->_childBlockFormattingBounds->height = ((child->bounds->height + child->coreStyle->usedValues->marginBottom) + child->coreStyle->usedValues->marginTop);
					HX_STACK_LINE(680)
					{
						HX_STACK_LINE(680)
						::cocktail::core::geom::RectangleVO addedBounds = this->_childBlockFormattingBounds;		HX_STACK_VAR(addedBounds,"addedBounds");
						bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
						bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
						HX_STACK_LINE(680)
						if (((getHorizontalBounds == true))){
							HX_STACK_LINE(680)
							if (((addedBounds->x < blockFormattingBounds->x))){
								HX_STACK_LINE(680)
								blockFormattingBounds->x = addedBounds->x;
							}
							HX_STACK_LINE(680)
							if ((((addedBounds->x + addedBounds->width) > (blockFormattingBounds->x + blockFormattingBounds->width)))){
								HX_STACK_LINE(680)
								blockFormattingBounds->width = ((addedBounds->x + addedBounds->width) - blockFormattingBounds->x);
							}
						}
						HX_STACK_LINE(680)
						if (((getVerticalBounds == true))){
							HX_STACK_LINE(680)
							if (((addedBounds->y < blockFormattingBounds->y))){
								HX_STACK_LINE(680)
								blockFormattingBounds->y = addedBounds->y;
							}
							HX_STACK_LINE(680)
							if ((((addedBounds->y + addedBounds->height) > (blockFormattingBounds->y + blockFormattingBounds->height)))){
								HX_STACK_LINE(680)
								blockFormattingBounds->height = ((addedBounds->y + addedBounds->height) - blockFormattingBounds->y);
							}
						}
					}
					HX_STACK_LINE(682)
					if (((bool((child->establishesNewBlockFormattingContext() == false)) && bool((child->firstChild != null()))))){
						HX_STACK_LINE(683)
						this->doGetBlockFormattingBounds(child,blockFormattingBounds,(xOffset + child->bounds->x),(yOffset + child->bounds->y));
					}
				}
			}
			HX_STACK_LINE(689)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BlockBoxRenderer_obj,doGetBlockFormattingBounds,(void))

Void BlockBoxRenderer_obj::getBlockFormattingBounds( ){
{
		HX_STACK_PUSH("BlockBoxRenderer::getBlockFormattingBounds","cocktail/core/renderer/BlockBoxRenderer.hx",653);
		HX_STACK_THIS(this);
		HX_STACK_LINE(654)
		this->_blockFormattingBounds->x = (int)50000;
		HX_STACK_LINE(655)
		this->_blockFormattingBounds->y = (int)50000;
		HX_STACK_LINE(656)
		this->_blockFormattingBounds->width = (int)0;
		HX_STACK_LINE(657)
		this->_blockFormattingBounds->height = (int)0;
		HX_STACK_LINE(659)
		this->doGetBlockFormattingBounds(hx::ObjectPtr<OBJ_>(this),this->_blockFormattingBounds,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,getBlockFormattingBounds,(void))

Void BlockBoxRenderer_obj::applyShrinkToFitIfNeeded( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BlockBoxRenderer::applyShrinkToFitIfNeeded","cocktail/core/renderer/BlockBoxRenderer.hx",577);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(577)
		if (((bool(((bool((this->coreStyle->hasAutoWidth == true)) || bool((layoutState != ::cocktail::core::layout::LayoutStateValue_obj::NORMAL_dyn()))))) && bool((this->isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight() == false))))){
			HX_STACK_LINE(585)
			this->doLayoutChildren(::cocktail::core::layout::LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH_dyn());
			HX_STACK_LINE(588)
			this->getBlockFormattingBounds();
			HX_STACK_LINE(589)
			Float preferedMinimumWidth = this->_blockFormattingBounds->width;		HX_STACK_VAR(preferedMinimumWidth,"preferedMinimumWidth");
			HX_STACK_LINE(594)
			if (((this->coreStyle->hasAutoWidth == false))){
				HX_STACK_LINE(595)
				if (((this->bounds->width > preferedMinimumWidth))){
					HX_STACK_LINE(597)
					preferedMinimumWidth = this->bounds->width;
				}
			}
			HX_STACK_LINE(604)
			this->doLayoutChildren(::cocktail::core::layout::LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_WIDTH_dyn());
			HX_STACK_LINE(607)
			this->getBlockFormattingBounds();
			HX_STACK_LINE(608)
			Float preferedWidth = this->_blockFormattingBounds->width;		HX_STACK_VAR(preferedWidth,"preferedWidth");
			HX_STACK_LINE(612)
			if (((this->coreStyle->hasAutoWidth == false))){
				HX_STACK_LINE(613)
				if (((this->bounds->width > preferedWidth))){
					HX_STACK_LINE(615)
					preferedWidth = this->bounds->width;
				}
			}
			HX_STACK_LINE(621)
			Float availableWidth = this->containingBlock->coreStyle->usedValues->width;		HX_STACK_VAR(availableWidth,"availableWidth");
			HX_STACK_LINE(624)
			Float shrinkToFitWidth = ::Math_obj::min(::Math_obj::max(preferedMinimumWidth,availableWidth),preferedWidth);		HX_STACK_VAR(shrinkToFitWidth,"shrinkToFitWidth");
			HX_STACK_LINE(627)
			if (((this->coreStyle->hasMaxWidth == true))){
				HX_STACK_LINE(628)
				if (((shrinkToFitWidth > this->coreStyle->usedValues->maxWidth))){
					HX_STACK_LINE(630)
					shrinkToFitWidth = this->coreStyle->usedValues->maxWidth;
				}
			}
			HX_STACK_LINE(635)
			if (((shrinkToFitWidth < this->coreStyle->usedValues->minWidth))){
				HX_STACK_LINE(636)
				shrinkToFitWidth = this->coreStyle->usedValues->minWidth;
			}
			HX_STACK_LINE(640)
			this->coreStyle->usedValues->width = shrinkToFitWidth;
			HX_STACK_LINE(641)
			this->bounds->width = ((((shrinkToFitWidth + this->coreStyle->usedValues->paddingLeft) + this->coreStyle->usedValues->paddingRight) + this->coreStyle->usedValues->borderLeftWidth) + this->coreStyle->usedValues->borderRightWidth);
			HX_STACK_LINE(644)
			this->doLayoutChildren(::cocktail::core::layout::LayoutStateValue_obj::NORMAL_dyn());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,applyShrinkToFitIfNeeded,(void))

Void BlockBoxRenderer_obj::updateFloatedAndClearElements( ){
{
		HX_STACK_PUSH("BlockBoxRenderer::updateFloatedAndClearElements","cocktail/core/renderer/BlockBoxRenderer.hx",531);
		HX_STACK_THIS(this);
		HX_STACK_LINE(531)
		if (((this->establishesNewBlockFormattingContext() == true))){
			HX_STACK_LINE(535)
			this->floatsManager->init();
			HX_STACK_LINE(537)
			this->_offsetFromBlockFormattingRoot->x = (int)0;
			HX_STACK_LINE(538)
			this->_offsetFromBlockFormattingRoot->y = (int)0;
		}
		else{
			HX_STACK_LINE(544)
			::cocktail::core::renderer::BlockBoxRenderer blockFormattingContextRoot = this->getNearestBlockFormattingContextRoot();		HX_STACK_VAR(blockFormattingContextRoot,"blockFormattingContextRoot");
			HX_STACK_LINE(547)
			this->_offsetFromBlockFormattingRoot = this->getBlockBoxesOffset(hx::ObjectPtr<OBJ_>(this),blockFormattingContextRoot);
			HX_STACK_LINE(550)
			hx::AddEq(this->_offsetFromBlockFormattingRoot->x,(this->coreStyle->usedValues->paddingLeft + this->coreStyle->usedValues->borderLeftWidth));
			HX_STACK_LINE(551)
			hx::AddEq(this->_offsetFromBlockFormattingRoot->y,(this->coreStyle->usedValues->paddingTop + this->coreStyle->usedValues->borderTopWidth));
			HX_STACK_LINE(553)
			this->floatsManager->set_floats(blockFormattingContextRoot->floatsManager->floats);
			HX_STACK_LINE(554)
			this->floatsManager->childrenWithClearance = blockFormattingContextRoot->floatsManager->childrenWithClearance;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,updateFloatedAndClearElements,(void))

Void BlockBoxRenderer_obj::doLayoutChildren( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BlockBoxRenderer::doLayoutChildren","cocktail/core/renderer/BlockBoxRenderer.hx",505);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(505)
		if (((this->childrenInline() == false))){
			HX_STACK_LINE(510)
			this->layoutBlockChildrenAndFloats(layoutState);
		}
		else{
			HX_STACK_LINE(515)
			this->layoutInlineChildrenAndFloats(layoutState);
			HX_STACK_LINE(519)
			this->updateInlineChildrenBounds(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,doLayoutChildren,(void))

Void BlockBoxRenderer_obj::layoutChildren( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("BlockBoxRenderer::layoutChildren","cocktail/core/renderer/BlockBoxRenderer.hx",473);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
		HX_STACK_LINE(475)
		this->updateFloatedAndClearElements();
		HX_STACK_LINE(481)
		this->doLayoutChildren(layoutState);
		HX_STACK_LINE(485)
		if (((this->establishesNewBlockFormattingContext() == true))){
			HX_STACK_LINE(486)
			if (((this->establishesNewBlockFormattingContextOnlyBecauseOfOverflow() == false))){
				HX_STACK_LINE(490)
				this->applyShrinkToFitIfNeeded(layoutState);
			}
		}
		HX_STACK_LINE(497)
		this->applyContentHeightIfNeeded();
	}
return null();
}


Void BlockBoxRenderer_obj::renderFloatedChildren( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BlockBoxRenderer::renderFloatedChildren","cocktail/core/renderer/BlockBoxRenderer.hx",443);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(444)
		::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(445)
		while(((child != null()))){
			HX_STACK_LINE(447)
			if (((child->layerRenderer == referenceLayer))){
				HX_STACK_LINE(448)
				if (((child->coreStyle->isFloat == true))){
					HX_STACK_LINE(450)
					child->render(graphicContext,clipRect,scrollOffset);
				}
				else{
					HX_STACK_LINE(454)
					this->renderFloatedChildren(child,referenceLayer,graphicContext,clipRect,scrollOffset);
				}
			}
			HX_STACK_LINE(459)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BlockBoxRenderer_obj,renderFloatedChildren,(void))

Void BlockBoxRenderer_obj::renderBlockContainerChildren( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BlockBoxRenderer::renderBlockContainerChildren","cocktail/core/renderer/BlockBoxRenderer.hx",414);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(415)
		::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(416)
		while(((child != null()))){
			HX_STACK_LINE(418)
			if (((child->layerRenderer == referenceLayer))){
				HX_STACK_LINE(419)
				if (((child->coreStyle->isInlineLevel == false))){
					HX_STACK_LINE(421)
					if (((bool((child->isReplaced == false)) && bool((child->isText == false))))){
						HX_STACK_LINE(423)
						if (((child->coreStyle->isFloat == false))){
							HX_STACK_LINE(426)
							child->render(graphicContext,clipRect,scrollOffset);
							HX_STACK_LINE(427)
							this->renderBlockContainerChildren(child,referenceLayer,graphicContext,clipRect,scrollOffset);
						}
					}
				}
			}
			HX_STACK_LINE(434)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BlockBoxRenderer_obj,renderBlockContainerChildren,(void))

Void BlockBoxRenderer_obj::renderBlockReplacedChildren( ::cocktail::core::renderer::ElementRenderer rootRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BlockBoxRenderer::renderBlockReplacedChildren","cocktail/core/renderer/BlockBoxRenderer.hx",385);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootRenderer,"rootRenderer");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(386)
		::cocktail::core::renderer::ElementRenderer child = rootRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(387)
		while(((child != null()))){
			HX_STACK_LINE(389)
			if (((child->layerRenderer == referenceLayer))){
				HX_STACK_LINE(390)
				if (((child->coreStyle->isFloat == false))){
					HX_STACK_LINE(392)
					if (((bool((child->isReplaced == false)) && bool((child->coreStyle->isBlock == true))))){
						HX_STACK_LINE(394)
						this->renderBlockReplacedChildren(child,referenceLayer,graphicContext,clipRect,scrollOffset);
					}
					else{
						HX_STACK_LINE(397)
						if (((child->coreStyle->isBlock == true))){
							HX_STACK_LINE(398)
							child->render(graphicContext,clipRect,scrollOffset);
						}
					}
				}
			}
			HX_STACK_LINE(405)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BlockBoxRenderer_obj,renderBlockReplacedChildren,(void))

Void BlockBoxRenderer_obj::renderLineBoxes( ::cocktail::core::renderer::ElementRenderer rootRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BlockBoxRenderer::renderLineBoxes","cocktail/core/renderer/BlockBoxRenderer.hx",344);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootRenderer,"rootRenderer");
		HX_STACK_ARG(referenceLayer,"referenceLayer");
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(346)
		bool canHaveLineBoxes = false;		HX_STACK_VAR(canHaveLineBoxes,"canHaveLineBoxes");
		HX_STACK_LINE(347)
		if (((rootRenderer->isBlockContainer == true))){
			HX_STACK_LINE(348)
			if (((rootRenderer->hasLineBoxes == true))){
				HX_STACK_LINE(350)
				canHaveLineBoxes = true;
			}
		}
		HX_STACK_LINE(355)
		if (((canHaveLineBoxes == true))){
			HX_STACK_LINE(356)
			this->renderInlineChildren(rootRenderer,referenceLayer,graphicContext,clipRect,scrollOffset);
		}
		else{
			HX_STACK_LINE(361)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->firstChild;		HX_STACK_VAR(child,"child");
			HX_STACK_LINE(362)
			while(((child != null()))){
				HX_STACK_LINE(364)
				if (((child->layerRenderer == referenceLayer))){
					HX_STACK_LINE(365)
					if (((child->isReplaced == false))){
						HX_STACK_LINE(367)
						if (((child->coreStyle->isFloat == false))){
							HX_STACK_LINE(369)
							this->renderLineBoxes(child,referenceLayer,graphicContext,clipRect,scrollOffset);
						}
					}
				}
				HX_STACK_LINE(375)
				child = child->nextSibling;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BlockBoxRenderer_obj,renderLineBoxes,(void))

Void BlockBoxRenderer_obj::renderChildren( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("BlockBoxRenderer::renderChildren","cocktail/core/renderer/BlockBoxRenderer.hx",307);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(308)
		this->super::renderChildren(graphicContext,clipRect,scrollOffset);
		HX_STACK_LINE(313)
		if (((bool((bool((this->createOwnLayer() == true)) || bool((this->coreStyle->isInlineBlock == true)))) || bool((this->coreStyle->isFloat == true))))){
			HX_STACK_LINE(317)
			if (((this->lineBoxes->length == (int)0))){
				HX_STACK_LINE(320)
				this->renderBlockContainerChildren(hx::ObjectPtr<OBJ_>(this),this->layerRenderer,graphicContext,clipRect,scrollOffset);
				HX_STACK_LINE(324)
				this->renderBlockReplacedChildren(hx::ObjectPtr<OBJ_>(this),this->layerRenderer,graphicContext,clipRect,scrollOffset);
			}
			HX_STACK_LINE(328)
			this->renderFloatedChildren(hx::ObjectPtr<OBJ_>(this),this->layerRenderer,graphicContext,clipRect,scrollOffset);
			HX_STACK_LINE(331)
			this->renderLineBoxes(hx::ObjectPtr<OBJ_>(this),this->layerRenderer,graphicContext,clipRect,scrollOffset);
		}
	}
return null();
}


::cocktail::core::renderer::AnonymousBlockBoxRenderer BlockBoxRenderer_obj::createAnonymousBlock( ::cocktail::core::renderer::ElementRenderer child){
	HX_STACK_PUSH("BlockBoxRenderer::createAnonymousBlock","cocktail/core/renderer/BlockBoxRenderer.hx",282);
	HX_STACK_THIS(this);
	HX_STACK_ARG(child,"child");
	HX_STACK_LINE(283)
	::cocktail::core::renderer::AnonymousBlockBoxRenderer anonymousBlock = ::cocktail::core::renderer::AnonymousBlockBoxRenderer_obj::__new(this->domNode->ownerDocument);		HX_STACK_VAR(anonymousBlock,"anonymousBlock");
	HX_STACK_LINE(284)
	anonymousBlock->appendChild(child);
	HX_STACK_LINE(286)
	anonymousBlock->coreStyle = anonymousBlock->domNode->coreStyle;
	HX_STACK_LINE(290)
	::cocktail::core::css::InitialStyleDeclaration initialStyleDeclaration = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(initialStyleDeclaration,"initialStyleDeclaration");
	HX_STACK_LINE(291)
	anonymousBlock->coreStyle->specifiedValues = initialStyleDeclaration;
	HX_STACK_LINE(292)
	anonymousBlock->coreStyle->computedValues = initialStyleDeclaration->initialComputedStyleDeclaration;
	HX_STACK_LINE(293)
	anonymousBlock->coreStyle->applyHiddenBordersWidth();
	HX_STACK_LINE(294)
	anonymousBlock->coreStyle->updateCoreStyleAttribute(::cocktail::Lib_obj::get_document()->cascadeManager,true);
	HX_STACK_LINE(296)
	return anonymousBlock;
}


HX_DEFINE_DYNAMIC_FUNC1(BlockBoxRenderer_obj,createAnonymousBlock,return )

Void BlockBoxRenderer_obj::makeChildrenNonInline( ){
{
		HX_STACK_PUSH("BlockBoxRenderer::makeChildrenNonInline","cocktail/core/renderer/BlockBoxRenderer.hx",225);
		HX_STACK_THIS(this);
		HX_STACK_LINE(228)
		Array< ::cocktail::core::renderer::ElementRenderer > newChildNodes = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();		HX_STACK_VAR(newChildNodes,"newChildNodes");
		HX_STACK_LINE(233)
		::cocktail::core::renderer::AnonymousBlockBoxRenderer lastCreatedAnonymousBlock = null();		HX_STACK_VAR(lastCreatedAnonymousBlock,"lastCreatedAnonymousBlock");
		HX_STACK_LINE(237)
		::cocktail::core::renderer::ElementRenderer child = this->lastChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(238)
		while(((child != null()))){
			HX_STACK_LINE(240)
			::cocktail::core::renderer::ElementRenderer previousSibling = child->previousSibling;		HX_STACK_VAR(previousSibling,"previousSibling");
			HX_STACK_LINE(243)
			if (((child->isInlineLevel() == true))){
				HX_STACK_LINE(244)
				if (((lastCreatedAnonymousBlock != null()))){
					HX_STACK_LINE(247)
					lastCreatedAnonymousBlock->insertBefore(child,lastCreatedAnonymousBlock->firstChild);
				}
				else{
					HX_STACK_LINE(252)
					lastCreatedAnonymousBlock = this->createAnonymousBlock(child);
					HX_STACK_LINE(253)
					newChildNodes->push(lastCreatedAnonymousBlock);
				}
			}
			else{
				HX_STACK_LINE(258)
				lastCreatedAnonymousBlock = null();
				HX_STACK_LINE(259)
				newChildNodes->push(child);
			}
			HX_STACK_LINE(262)
			child = previousSibling;
		}
		HX_STACK_LINE(267)
		newChildNodes->reverse();
		HX_STACK_LINE(271)
		int length = newChildNodes->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(272)
		{
			HX_STACK_LINE(272)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(272)
			while(((_g < length))){
				HX_STACK_LINE(272)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(274)
				this->appendChild(newChildNodes->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BlockBoxRenderer_obj,makeChildrenNonInline,(void))

Void BlockBoxRenderer_obj::updateAnonymousBlock( ){
{
		HX_STACK_PUSH("BlockBoxRenderer::updateAnonymousBlock","cocktail/core/renderer/BlockBoxRenderer.hx",156);
		HX_STACK_THIS(this);
		HX_STACK_LINE(159)
		bool shouldMakeChildrenNonInline = false;		HX_STACK_VAR(shouldMakeChildrenNonInline,"shouldMakeChildrenNonInline");
		HX_STACK_LINE(164)
		if (((this->get_firstNormalFlowChild() != null()))){
			HX_STACK_LINE(168)
			bool childrenInline = this->childrenInline();		HX_STACK_VAR(childrenInline,"childrenInline");
			HX_STACK_LINE(172)
			::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
			HX_STACK_LINE(173)
			while(((child != null()))){
				HX_STACK_LINE(177)
				if (((child->isAbsolutelyPositioned() == false))){
					HX_STACK_LINE(178)
					if (((child->isFloat() == false))){
						HX_STACK_LINE(180)
						if (((child->isInlineLevel() != childrenInline))){
							HX_STACK_LINE(187)
							shouldMakeChildrenNonInline = true;
							HX_STACK_LINE(188)
							break;
						}
					}
				}
				HX_STACK_LINE(193)
				child = child->nextSibling;
			}
		}
		HX_STACK_LINE(198)
		if (((shouldMakeChildrenNonInline == true))){
			HX_STACK_LINE(199)
			this->makeChildrenNonInline();
		}
		HX_STACK_LINE(204)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(205)
		while(((child != null()))){
			HX_STACK_LINE(207)
			child->updateAnonymousBlock();
			HX_STACK_LINE(208)
			child = child->nextSibling;
		}
	}
return null();
}



BlockBoxRenderer_obj::BlockBoxRenderer_obj()
{
}

void BlockBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlockBoxRenderer);
	HX_MARK_MEMBER_NAME(_offsetFromBlockFormattingRoot,"_offsetFromBlockFormattingRoot");
	HX_MARK_MEMBER_NAME(_floatFound,"_floatFound");
	HX_MARK_MEMBER_NAME(_floatedElementsBounds,"_floatedElementsBounds");
	HX_MARK_MEMBER_NAME(_childBlockFormattingBounds,"_childBlockFormattingBounds");
	HX_MARK_MEMBER_NAME(_blockFormattingBounds,"_blockFormattingBounds");
	HX_MARK_MEMBER_NAME(_inlineBoxGlobalBounds,"_inlineBoxGlobalBounds");
	HX_MARK_MEMBER_NAME(_lineBoxPosition,"_lineBoxPosition");
	HX_MARK_MEMBER_NAME(_childPosition,"_childPosition");
	HX_MARK_MEMBER_NAME(floatsManager,"floatsManager");
	HX_MARK_MEMBER_NAME(lineBoxes,"lineBoxes");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BlockBoxRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_offsetFromBlockFormattingRoot,"_offsetFromBlockFormattingRoot");
	HX_VISIT_MEMBER_NAME(_floatFound,"_floatFound");
	HX_VISIT_MEMBER_NAME(_floatedElementsBounds,"_floatedElementsBounds");
	HX_VISIT_MEMBER_NAME(_childBlockFormattingBounds,"_childBlockFormattingBounds");
	HX_VISIT_MEMBER_NAME(_blockFormattingBounds,"_blockFormattingBounds");
	HX_VISIT_MEMBER_NAME(_inlineBoxGlobalBounds,"_inlineBoxGlobalBounds");
	HX_VISIT_MEMBER_NAME(_lineBoxPosition,"_lineBoxPosition");
	HX_VISIT_MEMBER_NAME(_childPosition,"_childPosition");
	HX_VISIT_MEMBER_NAME(floatsManager,"floatsManager");
	HX_VISIT_MEMBER_NAME(lineBoxes,"lineBoxes");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BlockBoxRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"lineBoxes") ) { return lineBoxes; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_floatFound") ) { return _floatFound; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layoutLineBox") ) { return layoutLineBox_dyn(); }
		if (HX_FIELD_EQ(inName,"createLineBox") ) { return createLineBox_dyn(); }
		if (HX_FIELD_EQ(inName,"floatsManager") ) { return floatsManager; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"childrenInline") ) { return childrenInline_dyn(); }
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"layoutChildren") ) { return layoutChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"renderChildren") ) { return renderChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"_childPosition") ) { return _childPosition; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"renderLineBoxes") ) { return renderLineBoxes_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"doLayoutChildren") ) { return doLayoutChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"_lineBoxPosition") ) { return _lineBoxPosition; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getBlockBoxesOffset") ) { return getBlockBoxesOffset_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"registerClearElement") ) { return registerClearElement_dyn(); }
		if (HX_FIELD_EQ(inName,"createAnonymousBlock") ) { return createAnonymousBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAnonymousBlock") ) { return updateAnonymousBlock_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"hasZeroHeightChildren") ) { return hasZeroHeightChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"renderFloatedChildren") ) { return renderFloatedChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"makeChildrenNonInline") ) { return makeChildrenNonInline_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"registerFloatedElement") ) { return registerFloatedElement_dyn(); }
		if (HX_FIELD_EQ(inName,"_floatedElementsBounds") ) { return _floatedElementsBounds; }
		if (HX_FIELD_EQ(inName,"_blockFormattingBounds") ) { return _blockFormattingBounds; }
		if (HX_FIELD_EQ(inName,"_inlineBoxGlobalBounds") ) { return _inlineBoxGlobalBounds; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getFloatedElementsBounds") ) { return getFloatedElementsBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"getBlockFormattingBounds") ) { return getBlockFormattingBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"applyShrinkToFitIfNeeded") ) { return applyShrinkToFitIfNeeded_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"updateInlineChildrenBounds") ) { return updateInlineChildrenBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"applyContentHeightIfNeeded") ) { return applyContentHeightIfNeeded_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetFloatedElementsBounds") ) { return doGetFloatedElementsBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetBlockFormattingBounds") ) { return doGetBlockFormattingBounds_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"renderBlockReplacedChildren") ) { return renderBlockReplacedChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"_childBlockFormattingBounds") ) { return _childBlockFormattingBounds; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"layoutBlockChildrenAndFloats") ) { return layoutBlockChildrenAndFloats_dyn(); }
		if (HX_FIELD_EQ(inName,"renderBlockContainerChildren") ) { return renderBlockContainerChildren_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"getBackgroundAndBordersBounds") ) { return getBackgroundAndBordersBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"layoutInlineChildrenAndFloats") ) { return layoutInlineChildrenAndFloats_dyn(); }
		if (HX_FIELD_EQ(inName,"updateFloatedAndClearElements") ) { return updateFloatedAndClearElements_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"_offsetFromBlockFormattingRoot") ) { return _offsetFromBlockFormattingRoot; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"doLayoutInlineChildrenAndFloats") ) { return doLayoutInlineChildrenAndFloats_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"getNearestBlockFormattingContextRoot") ) { return getNearestBlockFormattingContextRoot_dyn(); }
		if (HX_FIELD_EQ(inName,"establishesNewBlockFormattingContext") ) { return establishesNewBlockFormattingContext_dyn(); }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"collapseTopMarginWithFirstChildTopMargin") ) { return collapseTopMarginWithFirstChildTopMargin_dyn(); }
		break;
	case 45:
		if (HX_FIELD_EQ(inName,"collapseBottomMarginWithLastChildBottomMargin") ) { return collapseBottomMarginWithLastChildBottomMargin_dyn(); }
		break;
	case 54:
		if (HX_FIELD_EQ(inName,"isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight") ) { return isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight_dyn(); }
		break;
	case 55:
		if (HX_FIELD_EQ(inName,"isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom") ) { return isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom_dyn(); }
		break;
	case 57:
		if (HX_FIELD_EQ(inName,"establishesNewBlockFormattingContextOnlyBecauseOfOverflow") ) { return establishesNewBlockFormattingContextOnlyBecauseOfOverflow_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BlockBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"lineBoxes") ) { lineBoxes=inValue.Cast< Array< ::cocktail::core::linebox::LineBox > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_floatFound") ) { _floatFound=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"floatsManager") ) { floatsManager=inValue.Cast< ::cocktail::core::layout::floats::FloatsManager >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_childPosition") ) { _childPosition=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_lineBoxPosition") ) { _lineBoxPosition=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_floatedElementsBounds") ) { _floatedElementsBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_blockFormattingBounds") ) { _blockFormattingBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_inlineBoxGlobalBounds") ) { _inlineBoxGlobalBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_childBlockFormattingBounds") ) { _childBlockFormattingBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"_offsetFromBlockFormattingRoot") ) { _offsetFromBlockFormattingRoot=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BlockBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_offsetFromBlockFormattingRoot"));
	outFields->push(HX_CSTRING("_floatFound"));
	outFields->push(HX_CSTRING("_floatedElementsBounds"));
	outFields->push(HX_CSTRING("_childBlockFormattingBounds"));
	outFields->push(HX_CSTRING("_blockFormattingBounds"));
	outFields->push(HX_CSTRING("_inlineBoxGlobalBounds"));
	outFields->push(HX_CSTRING("_lineBoxPosition"));
	outFields->push(HX_CSTRING("_childPosition"));
	outFields->push(HX_CSTRING("floatsManager"));
	outFields->push(HX_CSTRING("lineBoxes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getNearestBlockFormattingContextRoot"),
	HX_CSTRING("getBlockBoxesOffset"),
	HX_CSTRING("establishesNewBlockFormattingContextOnlyBecauseOfOverflow"),
	HX_CSTRING("getBackgroundAndBordersBounds"),
	HX_CSTRING("childrenInline"),
	HX_CSTRING("establishesNewBlockFormattingContext"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("hasZeroHeightChildren"),
	HX_CSTRING("collapseBottomMarginWithLastChildBottomMargin"),
	HX_CSTRING("collapseTopMarginWithFirstChildTopMargin"),
	HX_CSTRING("updateInlineChildrenBounds"),
	HX_CSTRING("doLayoutInlineChildrenAndFloats"),
	HX_CSTRING("layoutLineBox"),
	HX_CSTRING("createLineBox"),
	HX_CSTRING("layoutInlineChildrenAndFloats"),
	HX_CSTRING("registerFloatedElement"),
	HX_CSTRING("registerClearElement"),
	HX_CSTRING("layoutBlockChildrenAndFloats"),
	HX_CSTRING("isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight"),
	HX_CSTRING("isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom"),
	HX_CSTRING("applyContentHeightIfNeeded"),
	HX_CSTRING("doGetFloatedElementsBounds"),
	HX_CSTRING("getFloatedElementsBounds"),
	HX_CSTRING("doGetBlockFormattingBounds"),
	HX_CSTRING("getBlockFormattingBounds"),
	HX_CSTRING("applyShrinkToFitIfNeeded"),
	HX_CSTRING("updateFloatedAndClearElements"),
	HX_CSTRING("doLayoutChildren"),
	HX_CSTRING("layoutChildren"),
	HX_CSTRING("renderFloatedChildren"),
	HX_CSTRING("renderBlockContainerChildren"),
	HX_CSTRING("renderBlockReplacedChildren"),
	HX_CSTRING("renderLineBoxes"),
	HX_CSTRING("renderChildren"),
	HX_CSTRING("createAnonymousBlock"),
	HX_CSTRING("makeChildrenNonInline"),
	HX_CSTRING("updateAnonymousBlock"),
	HX_CSTRING("_offsetFromBlockFormattingRoot"),
	HX_CSTRING("_floatFound"),
	HX_CSTRING("_floatedElementsBounds"),
	HX_CSTRING("_childBlockFormattingBounds"),
	HX_CSTRING("_blockFormattingBounds"),
	HX_CSTRING("_inlineBoxGlobalBounds"),
	HX_CSTRING("_lineBoxPosition"),
	HX_CSTRING("_childPosition"),
	HX_CSTRING("floatsManager"),
	HX_CSTRING("lineBoxes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BlockBoxRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BlockBoxRenderer_obj::__mClass,"__mClass");
};

Class BlockBoxRenderer_obj::__mClass;

void BlockBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.BlockBoxRenderer"), hx::TCanCast< BlockBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BlockBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
