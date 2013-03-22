#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
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
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_invalidation_InvalidationManager
#include <cocktail/core/invalidation/InvalidationManager.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InitialBlockRenderer
#include <cocktail/core/renderer/InitialBlockRenderer.h>
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

Void ElementRenderer_obj::__construct(::cocktail::core::html::HTMLElement domNode)
{
HX_STACK_PUSH("ElementRenderer::new","cocktail/core/renderer/ElementRenderer.hx",275);
{
	HX_STACK_LINE(276)
	super::__construct();
	HX_STACK_LINE(278)
	this->domNode = domNode;
	HX_STACK_LINE(280)
	this->initCoreStyle();
	HX_STACK_LINE(281)
	this->_hasOwnLayer = false;
	HX_STACK_LINE(282)
	this->_wasAbsolutelyPositioned = false;
	HX_STACK_LINE(283)
	this->_needsLayerRendererUpdate = true;
	HX_STACK_LINE(285)
	this->bounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(287)
	this->globalBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(289)
	this->staticOrigin = ::cocktail::core::geom::PointVO_obj::__new(0.0,0.0);
	HX_STACK_LINE(291)
	this->hitTestingBounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(293)
	this->inlineBoxes = Array_obj< ::cocktail::core::linebox::InlineBox >::__new();
	HX_STACK_LINE(295)
	this->isBlockContainer = false;
	HX_STACK_LINE(296)
	this->isReplaced = false;
	HX_STACK_LINE(297)
	this->isText = false;
	HX_STACK_LINE(298)
	this->hasLineBoxes = false;
}
;
	return null();
}

ElementRenderer_obj::~ElementRenderer_obj() { }

Dynamic ElementRenderer_obj::__CreateEmpty() { return  new ElementRenderer_obj; }
hx::ObjectPtr< ElementRenderer_obj > ElementRenderer_obj::__new(::cocktail::core::html::HTMLElement domNode)
{  hx::ObjectPtr< ElementRenderer_obj > result = new ElementRenderer_obj();
	result->__construct(domNode);
	return result;}

Dynamic ElementRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ElementRenderer_obj > result = new ElementRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Float ElementRenderer_obj::get_scrollHeight( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollHeight","cocktail/core/renderer/ElementRenderer.hx",1608);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1609)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1611)
		Float scrollableHeight = this->layerRenderer->scrollableBounds->height;		HX_STACK_VAR(scrollableHeight,"scrollableHeight");
		HX_STACK_LINE(1613)
		if (((scrollableHeight > this->bounds->height))){
			HX_STACK_LINE(1614)
			return scrollableHeight;
		}
	}
	HX_STACK_LINE(1619)
	return this->bounds->height;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollHeight,return )

Float ElementRenderer_obj::get_scrollWidth( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollWidth","cocktail/core/renderer/ElementRenderer.hx",1593);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1594)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1596)
		Float scrollableWidth = this->layerRenderer->scrollableBounds->width;		HX_STACK_VAR(scrollableWidth,"scrollableWidth");
		HX_STACK_LINE(1598)
		if (((scrollableWidth > this->bounds->width))){
			HX_STACK_LINE(1599)
			return scrollableWidth;
		}
	}
	HX_STACK_LINE(1604)
	return this->bounds->width;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollWidth,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_lastNormalFlowChild( ){
	HX_STACK_PUSH("ElementRenderer::get_lastNormalFlowChild","cocktail/core/renderer/ElementRenderer.hx",1568);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1569)
	::cocktail::core::renderer::ElementRenderer lastElementRendererChild = this->lastChild;		HX_STACK_VAR(lastElementRendererChild,"lastElementRendererChild");
	HX_STACK_LINE(1571)
	if (((lastElementRendererChild != null()))){
		HX_STACK_LINE(1573)
		if (((lastElementRendererChild->isFloat() == false))){
			HX_STACK_LINE(1574)
			if (((lastElementRendererChild->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1576)
				return lastElementRendererChild;
			}
		}
		HX_STACK_LINE(1581)
		return lastElementRendererChild->get_previousNormalFlowSibling();
	}
	HX_STACK_LINE(1584)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_lastNormalFlowChild,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_firstNormalFlowChild( ){
	HX_STACK_PUSH("ElementRenderer::get_firstNormalFlowChild","cocktail/core/renderer/ElementRenderer.hx",1548);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1549)
	::cocktail::core::renderer::ElementRenderer firstElementRendererChild = this->firstChild;		HX_STACK_VAR(firstElementRendererChild,"firstElementRendererChild");
	HX_STACK_LINE(1551)
	if (((firstElementRendererChild != null()))){
		HX_STACK_LINE(1553)
		if (((firstElementRendererChild->isFloat() == false))){
			HX_STACK_LINE(1554)
			if (((firstElementRendererChild->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1556)
				return firstElementRendererChild;
			}
		}
		HX_STACK_LINE(1561)
		return firstElementRendererChild->get_nextNormalFlowSibling();
	}
	HX_STACK_LINE(1564)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_firstNormalFlowChild,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_nextNormalFlowSibling( ){
	HX_STACK_PUSH("ElementRenderer::get_nextNormalFlowSibling","cocktail/core/renderer/ElementRenderer.hx",1528);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1529)
	::cocktail::core::renderer::ElementRenderer nextElementRendererSibling = this->nextSibling;		HX_STACK_VAR(nextElementRendererSibling,"nextElementRendererSibling");
	HX_STACK_LINE(1531)
	while(((nextElementRendererSibling != null()))){
		HX_STACK_LINE(1533)
		if (((nextElementRendererSibling->isFloat() == false))){
			HX_STACK_LINE(1534)
			if (((nextElementRendererSibling->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1536)
				return nextElementRendererSibling;
			}
		}
		HX_STACK_LINE(1541)
		nextElementRendererSibling = nextElementRendererSibling->nextSibling;
	}
	HX_STACK_LINE(1544)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_nextNormalFlowSibling,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_previousNormalFlowSibling( ){
	HX_STACK_PUSH("ElementRenderer::get_previousNormalFlowSibling","cocktail/core/renderer/ElementRenderer.hx",1508);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1509)
	::cocktail::core::renderer::ElementRenderer previousElementRendererSibling = this->previousSibling;		HX_STACK_VAR(previousElementRendererSibling,"previousElementRendererSibling");
	HX_STACK_LINE(1511)
	while(((previousElementRendererSibling != null()))){
		HX_STACK_LINE(1513)
		if (((previousElementRendererSibling->isFloat() == false))){
			HX_STACK_LINE(1514)
			if (((previousElementRendererSibling->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1516)
				return previousElementRendererSibling;
			}
		}
		HX_STACK_LINE(1521)
		previousElementRendererSibling = previousElementRendererSibling->previousSibling;
	}
	HX_STACK_LINE(1524)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_previousNormalFlowSibling,return )

Float ElementRenderer_obj::get_scrollTop( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollTop","cocktail/core/renderer/ElementRenderer.hx",1494);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1495)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1496)
		return this->layerRenderer->scrollTop;
	}
	HX_STACK_LINE(1500)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollTop,return )

Float ElementRenderer_obj::set_scrollTop( Float value){
	HX_STACK_PUSH("ElementRenderer::set_scrollTop","cocktail/core/renderer/ElementRenderer.hx",1481);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1482)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1483)
		this->layerRenderer->set_scrollTop(value);
	}
	HX_STACK_LINE(1487)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,set_scrollTop,return )

Float ElementRenderer_obj::get_scrollLeft( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollLeft","cocktail/core/renderer/ElementRenderer.hx",1468);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1469)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1470)
		return this->layerRenderer->scrollLeft;
	}
	HX_STACK_LINE(1474)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollLeft,return )

Float ElementRenderer_obj::set_scrollLeft( Float value){
	HX_STACK_PUSH("ElementRenderer::set_scrollLeft","cocktail/core/renderer/ElementRenderer.hx",1453);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1454)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1455)
		this->layerRenderer->set_scrollLeft(value);
	}
	HX_STACK_LINE(1459)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,set_scrollLeft,return )

Void ElementRenderer_obj::invalidateRendering( ){
{
		HX_STACK_PUSH("ElementRenderer::invalidateRendering","cocktail/core/renderer/ElementRenderer.hx",1431);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,invalidateRendering,(void))

Void ElementRenderer_obj::invalidateStyle( int styleIndex){
{
		HX_STACK_PUSH("ElementRenderer::invalidateStyle","cocktail/core/renderer/ElementRenderer.hx",1422);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,invalidateStyle,(void))

Void ElementRenderer_obj::invalidate( ){
{
		HX_STACK_PUSH("ElementRenderer::invalidate","cocktail/core/renderer/ElementRenderer.hx",1411);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,invalidate,(void))

Void ElementRenderer_obj::doGetChildrenBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds){
{
		HX_STACK_PUSH("ElementRenderer::doGetChildrenBounds","cocktail/core/renderer/ElementRenderer.hx",1381);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(1382)
		::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(1383)
		while(((child != null()))){
			HX_STACK_LINE(1385)
			{
				HX_STACK_LINE(1385)
				::cocktail::core::geom::RectangleVO addedBounds = child->bounds;		HX_STACK_VAR(addedBounds,"addedBounds");
				bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
				bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
				HX_STACK_LINE(1385)
				if (((getHorizontalBounds == true))){
					HX_STACK_LINE(1385)
					if (((addedBounds->x < bounds->x))){
						HX_STACK_LINE(1385)
						bounds->x = addedBounds->x;
					}
					HX_STACK_LINE(1385)
					if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
						HX_STACK_LINE(1385)
						bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
					}
				}
				HX_STACK_LINE(1385)
				if (((getVerticalBounds == true))){
					HX_STACK_LINE(1385)
					if (((addedBounds->y < bounds->y))){
						HX_STACK_LINE(1385)
						bounds->y = addedBounds->y;
					}
					HX_STACK_LINE(1385)
					if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
						HX_STACK_LINE(1385)
						bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
					}
				}
			}
			HX_STACK_LINE(1386)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(1387)
				this->doGetChildrenBounds(child,bounds);
			}
			HX_STACK_LINE(1391)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,doGetChildrenBounds,(void))

Void ElementRenderer_obj::getInlineBoxesBounds( Array< ::cocktail::core::linebox::InlineBox > inLineBoxes,::cocktail::core::geom::RectangleVO bounds){
{
		HX_STACK_PUSH("ElementRenderer::getInlineBoxesBounds","cocktail/core/renderer/ElementRenderer.hx",1361);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inLineBoxes,"inLineBoxes");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(1363)
		bounds->x = (int)50000;
		HX_STACK_LINE(1364)
		bounds->y = (int)50000;
		HX_STACK_LINE(1365)
		bounds->width = (int)0;
		HX_STACK_LINE(1366)
		bounds->height = (int)0;
		HX_STACK_LINE(1368)
		int length = inLineBoxes->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(1369)
		{
			HX_STACK_LINE(1369)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1369)
			while(((_g < length))){
				HX_STACK_LINE(1369)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1371)
				{
					HX_STACK_LINE(1371)
					::cocktail::core::geom::RectangleVO addedBounds = inLineBoxes->__get(i)->bounds;		HX_STACK_VAR(addedBounds,"addedBounds");
					bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
					bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
					HX_STACK_LINE(1371)
					if (((getHorizontalBounds == true))){
						HX_STACK_LINE(1371)
						if (((addedBounds->x < bounds->x))){
							HX_STACK_LINE(1371)
							bounds->x = addedBounds->x;
						}
						HX_STACK_LINE(1371)
						if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
							HX_STACK_LINE(1371)
							bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
						}
					}
					HX_STACK_LINE(1371)
					if (((getVerticalBounds == true))){
						HX_STACK_LINE(1371)
						if (((addedBounds->y < bounds->y))){
							HX_STACK_LINE(1371)
							bounds->y = addedBounds->y;
						}
						HX_STACK_LINE(1371)
						if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
							HX_STACK_LINE(1371)
							bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,getInlineBoxesBounds,(void))

::cocktail::core::renderer::FlowBoxRenderer ElementRenderer_obj::getFirstBlockContainer( ){
	HX_STACK_PUSH("ElementRenderer::getFirstBlockContainer","cocktail/core/renderer/ElementRenderer.hx",1346);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1347)
	::cocktail::core::renderer::ElementRenderer parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1348)
	while(((parent->isBlockContainer == false))){
		HX_STACK_LINE(1349)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1353)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getFirstBlockContainer,return )

::cocktail::core::renderer::InitialBlockRenderer ElementRenderer_obj::getInitialContainingBlock( ){
	HX_STACK_PUSH("ElementRenderer::getInitialContainingBlock","cocktail/core/renderer/ElementRenderer.hx",1338);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1338)
	return this->domNode->ownerDocument->documentElement->elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getInitialContainingBlock,return )

::cocktail::core::renderer::FlowBoxRenderer ElementRenderer_obj::getFirstPositionedAncestor( ){
	HX_STACK_PUSH("ElementRenderer::getFirstPositionedAncestor","cocktail/core/renderer/ElementRenderer.hx",1315);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1316)
	::cocktail::core::renderer::ElementRenderer parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1317)
	while(((parent->isPositioned() == false))){
		HX_STACK_LINE(1324)
		if (((parent->parentNode == null()))){
			HX_STACK_LINE(1325)
			break;
		}
		HX_STACK_LINE(1328)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1331)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getFirstPositionedAncestor,return )

::cocktail::core::renderer::FlowBoxRenderer ElementRenderer_obj::getContainingBlock( ){
	HX_STACK_PUSH("ElementRenderer::getContainingBlock","cocktail/core/renderer/ElementRenderer.hx",1287);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1287)
	if (((this->isAbsolutelyPositioned() == true))){
		HX_STACK_LINE(1289)
		if (((this->coreStyle->isFixedPositioned == true))){
			HX_STACK_LINE(1293)
			return this->getInitialContainingBlock();
		}
		else{
			HX_STACK_LINE(1299)
			return this->getFirstPositionedAncestor();
		}
	}
	else{
		HX_STACK_LINE(1306)
		return this->getFirstBlockContainer();
	}
	HX_STACK_LINE(1287)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getContainingBlock,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::getNextElementRendererWithOwnLayerRenderer( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::renderer::ElementRenderer referenceElementRenderer){
	HX_STACK_PUSH("ElementRenderer::getNextElementRendererWithOwnLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",1222);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
	HX_STACK_ARG(referenceElementRenderer,"referenceElementRenderer");
	HX_STACK_LINE(1226)
	bool foundSelf = false;		HX_STACK_VAR(foundSelf,"foundSelf");
	HX_STACK_LINE(1228)
	::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(1229)
	while(((child != null()))){
		HX_STACK_LINE(1232)
		if (((child == referenceElementRenderer))){
			HX_STACK_LINE(1233)
			foundSelf = true;
		}
		else{
			HX_STACK_LINE(1237)
			if (((bool((child->createOwnLayer() == true)) && bool((child->layerRenderer != null()))))){
				HX_STACK_LINE(1238)
				if (((foundSelf == true))){
					HX_STACK_LINE(1243)
					return child;
				}
			}
			else{
				HX_STACK_LINE(1248)
				if (((child->firstChild != null()))){
					HX_STACK_LINE(1251)
					::cocktail::core::renderer::ElementRenderer nextElementRendererWithOwnLayerRenderer = this->getNextElementRendererWithOwnLayerRenderer(child,referenceElementRenderer);		HX_STACK_VAR(nextElementRendererWithOwnLayerRenderer,"nextElementRendererWithOwnLayerRenderer");
					HX_STACK_LINE(1253)
					if (((nextElementRendererWithOwnLayerRenderer != null()))){
						HX_STACK_LINE(1254)
						if (((nextElementRendererWithOwnLayerRenderer == referenceElementRenderer))){
							HX_STACK_LINE(1256)
							foundSelf = true;
						}
						else{
							HX_STACK_LINE(1260)
							return nextElementRendererWithOwnLayerRenderer;
						}
					}
				}
			}
		}
		HX_STACK_LINE(1266)
		child = child->nextSibling;
	}
	HX_STACK_LINE(1272)
	if (((foundSelf == true))){
		HX_STACK_LINE(1273)
		return referenceElementRenderer;
	}
	else{
		HX_STACK_LINE(1277)
		return null();
	}
	HX_STACK_LINE(1272)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,getNextElementRendererWithOwnLayerRenderer,return )

::cocktail::core::layer::LayerRenderer ElementRenderer_obj::getNextLayerRenderer( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::renderer::ElementRenderer referenceElementRenderer){
	HX_STACK_PUSH("ElementRenderer::getNextLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",1185);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
	HX_STACK_ARG(referenceElementRenderer,"referenceElementRenderer");
	HX_STACK_LINE(1188)
	::cocktail::core::renderer::ElementRenderer nextElementRendererWithOwnLayerRenderer = this->getNextElementRendererWithOwnLayerRenderer(rootElementRenderer,referenceElementRenderer);		HX_STACK_VAR(nextElementRendererWithOwnLayerRenderer,"nextElementRendererWithOwnLayerRenderer");
	HX_STACK_LINE(1191)
	if (((nextElementRendererWithOwnLayerRenderer == null()))){
		HX_STACK_LINE(1192)
		return null();
	}
	else{
		HX_STACK_LINE(1197)
		if (((nextElementRendererWithOwnLayerRenderer == referenceElementRenderer))){
			HX_STACK_LINE(1198)
			return null();
		}
		else{
			HX_STACK_LINE(1203)
			return nextElementRendererWithOwnLayerRenderer->layerRenderer;
		}
	}
	HX_STACK_LINE(1191)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,getNextLayerRenderer,return )

Void ElementRenderer_obj::doCreateLayer( ){
{
		HX_STACK_PUSH("ElementRenderer::doCreateLayer","cocktail/core/renderer/ElementRenderer.hx",1169);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1169)
		this->layerRenderer = ::cocktail::core::layer::LayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,doCreateLayer,(void))

Void ElementRenderer_obj::createLayer( ::cocktail::core::layer::LayerRenderer parentLayer){
{
		HX_STACK_PUSH("ElementRenderer::createLayer","cocktail/core/renderer/ElementRenderer.hx",1149);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentLayer,"parentLayer");
		HX_STACK_LINE(1149)
		if (((this->createOwnLayer() == true))){
			HX_STACK_LINE(1152)
			this->doCreateLayer();
			HX_STACK_LINE(1154)
			parentLayer->insertBefore(this->layerRenderer,this->getNextLayerRenderer(parentLayer->rootElementRenderer,hx::ObjectPtr<OBJ_>(this)));
			HX_STACK_LINE(1155)
			this->_hasOwnLayer = true;
		}
		else{
			HX_STACK_LINE(1158)
			this->layerRenderer = parentLayer;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,createLayer,(void))

bool ElementRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("ElementRenderer::createOwnLayer","cocktail/core/renderer/ElementRenderer.hx",1136);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1136)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,createOwnLayer,return )

bool ElementRenderer_obj::isVisible( ){
	HX_STACK_PUSH("ElementRenderer::isVisible","cocktail/core/renderer/ElementRenderer.hx",1125);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1125)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isVisible,return )

bool ElementRenderer_obj::hasCSSTransform( ){
	HX_STACK_PUSH("ElementRenderer::hasCSSTransform","cocktail/core/renderer/ElementRenderer.hx",1120);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1120)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,hasCSSTransform,return )

bool ElementRenderer_obj::isTransformed( ){
	HX_STACK_PUSH("ElementRenderer::isTransformed","cocktail/core/renderer/ElementRenderer.hx",1115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1115)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isTransformed,return )

bool ElementRenderer_obj::isAnonymousBlockBox( ){
	HX_STACK_PUSH("ElementRenderer::isAnonymousBlockBox","cocktail/core/renderer/ElementRenderer.hx",1110);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1110)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isAnonymousBlockBox,return )

bool ElementRenderer_obj::childrenInline( ){
	HX_STACK_PUSH("ElementRenderer::childrenInline","cocktail/core/renderer/ElementRenderer.hx",1105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1105)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,childrenInline,return )

bool ElementRenderer_obj::isTransparent( ){
	HX_STACK_PUSH("ElementRenderer::isTransparent","cocktail/core/renderer/ElementRenderer.hx",1100);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1100)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isTransparent,return )

bool ElementRenderer_obj::isRelativePositioned( ){
	HX_STACK_PUSH("ElementRenderer::isRelativePositioned","cocktail/core/renderer/ElementRenderer.hx",1095);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1095)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isRelativePositioned,return )

bool ElementRenderer_obj::isInlineLevel( ){
	HX_STACK_PUSH("ElementRenderer::isInlineLevel","cocktail/core/renderer/ElementRenderer.hx",1090);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1090)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isInlineLevel,return )

bool ElementRenderer_obj::isAbsolutelyPositioned( ){
	HX_STACK_PUSH("ElementRenderer::isAbsolutelyPositioned","cocktail/core/renderer/ElementRenderer.hx",1085);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1085)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isAbsolutelyPositioned,return )

bool ElementRenderer_obj::isPositioned( ){
	HX_STACK_PUSH("ElementRenderer::isPositioned","cocktail/core/renderer/ElementRenderer.hx",1080);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1080)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isPositioned,return )

bool ElementRenderer_obj::isFloat( ){
	HX_STACK_PUSH("ElementRenderer::isFloat","cocktail/core/renderer/ElementRenderer.hx",1075);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1075)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isFloat,return )

bool ElementRenderer_obj::canHaveClearance( ){
	HX_STACK_PUSH("ElementRenderer::canHaveClearance","cocktail/core/renderer/ElementRenderer.hx",1070);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1070)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,canHaveClearance,return )

bool ElementRenderer_obj::isScrollBar( ){
	HX_STACK_PUSH("ElementRenderer::isScrollBar","cocktail/core/renderer/ElementRenderer.hx",1065);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1065)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isScrollBar,return )

bool ElementRenderer_obj::establishesNewBlockFormattingContext( ){
	HX_STACK_PUSH("ElementRenderer::establishesNewBlockFormattingContext","cocktail/core/renderer/ElementRenderer.hx",1060);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1060)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,establishesNewBlockFormattingContext,return )

Float ElementRenderer_obj::getLeadedDescent( ){
	HX_STACK_PUSH("ElementRenderer::getLeadedDescent","cocktail/core/renderer/ElementRenderer.hx",1043);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1044)
	::cocktail::core::font::FontMetricsVO fontMetrics = this->coreStyle->fontMetrics;		HX_STACK_VAR(fontMetrics,"fontMetrics");
	HX_STACK_LINE(1046)
	Float ascent = fontMetrics->ascent;		HX_STACK_VAR(ascent,"ascent");
	HX_STACK_LINE(1047)
	Float descent = fontMetrics->descent;		HX_STACK_VAR(descent,"descent");
	HX_STACK_LINE(1049)
	Float lineHeight = this->coreStyle->usedValues->lineHeight;		HX_STACK_VAR(lineHeight,"lineHeight");
	HX_STACK_LINE(1051)
	Float leading = (lineHeight - ((ascent + descent)));		HX_STACK_VAR(leading,"leading");
	HX_STACK_LINE(1053)
	Float leadedAscent = (ascent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedAscent,"leadedAscent");
	HX_STACK_LINE(1054)
	Float leadedDescent = (descent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedDescent,"leadedDescent");
	HX_STACK_LINE(1056)
	return leadedDescent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getLeadedDescent,return )

Float ElementRenderer_obj::getLeadedAscent( ){
	HX_STACK_PUSH("ElementRenderer::getLeadedAscent","cocktail/core/renderer/ElementRenderer.hx",1020);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1021)
	::cocktail::core::font::FontMetricsVO fontMetrics = this->coreStyle->fontMetrics;		HX_STACK_VAR(fontMetrics,"fontMetrics");
	HX_STACK_LINE(1023)
	Float ascent = fontMetrics->ascent;		HX_STACK_VAR(ascent,"ascent");
	HX_STACK_LINE(1024)
	Float descent = fontMetrics->descent;		HX_STACK_VAR(descent,"descent");
	HX_STACK_LINE(1026)
	Float lineHeight = this->coreStyle->usedValues->lineHeight;		HX_STACK_VAR(lineHeight,"lineHeight");
	HX_STACK_LINE(1030)
	Float leading = (lineHeight - ((ascent + descent)));		HX_STACK_VAR(leading,"leading");
	HX_STACK_LINE(1033)
	Float leadedAscent = (ascent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedAscent,"leadedAscent");
	HX_STACK_LINE(1034)
	Float leadedDescent = (descent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedDescent,"leadedDescent");
	HX_STACK_LINE(1036)
	return leadedAscent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getLeadedAscent,return )

Void ElementRenderer_obj::unregisterWithContainingBlock( ){
{
		HX_STACK_PUSH("ElementRenderer::unregisterWithContainingBlock","cocktail/core/renderer/ElementRenderer.hx",1004);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1004)
		if (((this->_wasAbsolutelyPositioned == true))){
			HX_STACK_LINE(1007)
			this->containingBlock->removeAbsolutelyPositionedChild(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(1008)
			this->_wasAbsolutelyPositioned = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,unregisterWithContainingBlock,(void))

Void ElementRenderer_obj::registerWithContaininingBlock( ){
{
		HX_STACK_PUSH("ElementRenderer::registerWithContaininingBlock","cocktail/core/renderer/ElementRenderer.hx",988);
		HX_STACK_THIS(this);
		HX_STACK_LINE(988)
		if (((this->isAbsolutelyPositioned() == true))){
			HX_STACK_LINE(991)
			this->containingBlock->addAbsolutelyPositionedChildren(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(994)
			this->_wasAbsolutelyPositioned = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,registerWithContaininingBlock,(void))

Void ElementRenderer_obj::detachLayer( ){
{
		HX_STACK_PUSH("ElementRenderer::detachLayer","cocktail/core/renderer/ElementRenderer.hx",968);
		HX_STACK_THIS(this);
		HX_STACK_LINE(972)
		if (((this->_hasOwnLayer == true))){
			HX_STACK_LINE(974)
			this->parentNode->__Field(HX_CSTRING("layerRenderer"),true)->__Field(HX_CSTRING("removeChild"),true)(this->layerRenderer);
			HX_STACK_LINE(975)
			this->_hasOwnLayer = false;
			HX_STACK_LINE(976)
			this->layerRenderer->dispose();
		}
		HX_STACK_LINE(979)
		this->layerRenderer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,detachLayer,(void))

Void ElementRenderer_obj::attachLayer( ){
{
		HX_STACK_PUSH("ElementRenderer::attachLayer","cocktail/core/renderer/ElementRenderer.hx",956);
		HX_STACK_THIS(this);
		HX_STACK_LINE(956)
		if (((this->parentNode != null()))){
			HX_STACK_LINE(959)
			this->createLayer(this->parentNode->__Field(HX_CSTRING("layerRenderer"),true));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,attachLayer,(void))

Void ElementRenderer_obj::removedFromRenderingTree( ){
{
		HX_STACK_PUSH("ElementRenderer::removedFromRenderingTree","cocktail/core/renderer/ElementRenderer.hx",938);
		HX_STACK_THIS(this);
		HX_STACK_LINE(940)
		this->detach();
		HX_STACK_LINE(943)
		this->unregisterWithContainingBlock();
		HX_STACK_LINE(944)
		this->containingBlock = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,removedFromRenderingTree,(void))

Void ElementRenderer_obj::addedToRenderingTree( ){
{
		HX_STACK_PUSH("ElementRenderer::addedToRenderingTree","cocktail/core/renderer/ElementRenderer.hx",922);
		HX_STACK_THIS(this);
		HX_STACK_LINE(924)
		this->containingBlock = this->getContainingBlock();
		HX_STACK_LINE(925)
		this->registerWithContaininingBlock();
		HX_STACK_LINE(929)
		this->invalidateLayerRenderer();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,addedToRenderingTree,(void))

Void ElementRenderer_obj::updateInlineBoxes( ){
{
		HX_STACK_PUSH("ElementRenderer::updateInlineBoxes","cocktail/core/renderer/ElementRenderer.hx",907);
		HX_STACK_THIS(this);
		HX_STACK_LINE(908)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(909)
		while(((child != null()))){
			HX_STACK_LINE(911)
			child->updateInlineBoxes();
			HX_STACK_LINE(912)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateInlineBoxes,(void))

Void ElementRenderer_obj::updateAnonymousBlock( ){
{
		HX_STACK_PUSH("ElementRenderer::updateAnonymousBlock","cocktail/core/renderer/ElementRenderer.hx",892);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateAnonymousBlock,(void))

Void ElementRenderer_obj::detach( ){
{
		HX_STACK_PUSH("ElementRenderer::detach","cocktail/core/renderer/ElementRenderer.hx",865);
		HX_STACK_THIS(this);
		HX_STACK_LINE(867)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(868)
		while(((child != null()))){
			HX_STACK_LINE(870)
			child->detach();
			HX_STACK_LINE(871)
			child = child->nextSibling;
		}
		HX_STACK_LINE(874)
		if (((this->layerRenderer != null()))){
			HX_STACK_LINE(875)
			this->detachLayer();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,detach,(void))

Void ElementRenderer_obj::attach( ){
{
		HX_STACK_PUSH("ElementRenderer::attach","cocktail/core/renderer/ElementRenderer.hx",847);
		HX_STACK_THIS(this);
		HX_STACK_LINE(848)
		this->attachLayer();
		HX_STACK_LINE(852)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(853)
		while(((child != null()))){
			HX_STACK_LINE(855)
			child->attach();
			HX_STACK_LINE(856)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,attach,(void))

Void ElementRenderer_obj::updateLayerRenderer( ){
{
		HX_STACK_PUSH("ElementRenderer::updateLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",792);
		HX_STACK_THIS(this);
		HX_STACK_LINE(793)
		if (((this->_needsLayerRendererUpdate == true))){
			HX_STACK_LINE(796)
			this->_needsLayerRendererUpdate = false;
			HX_STACK_LINE(801)
			if (((this->layerRenderer == null()))){
				HX_STACK_LINE(803)
				this->attach();
				HX_STACK_LINE(807)
				return null();
			}
			else{
				HX_STACK_LINE(813)
				if (((this->_hasOwnLayer != this->createOwnLayer()))){
					HX_STACK_LINE(815)
					this->detach();
					HX_STACK_LINE(816)
					this->attach();
					HX_STACK_LINE(817)
					return null();
				}
				else{
					HX_STACK_LINE(823)
					if (((this->createOwnLayer() == true))){
						HX_STACK_LINE(825)
						this->parentNode->__Field(HX_CSTRING("layerRenderer"),true)->__Field(HX_CSTRING("insertBefore"),true)(this->layerRenderer,this->getNextLayerRenderer(this->parentNode->__Field(HX_CSTRING("layerRenderer"),true)->__Field(HX_CSTRING("rootElementRenderer"),true),hx::ObjectPtr<OBJ_>(this)));
					}
				}
			}
		}
		HX_STACK_LINE(834)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(835)
		while(((child != null()))){
			HX_STACK_LINE(837)
			child->updateLayerRenderer();
			HX_STACK_LINE(838)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateLayerRenderer,(void))

Void ElementRenderer_obj::getAdjoiningBottomMargins( Array< Float > adjoiningMargins){
{
		HX_STACK_PUSH("ElementRenderer::getAdjoiningBottomMargins","cocktail/core/renderer/ElementRenderer.hx",767);
		HX_STACK_THIS(this);
		HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,getAdjoiningBottomMargins,(void))

Void ElementRenderer_obj::getAdjoiningTopMargins( Array< Float > adjoiningMargins){
{
		HX_STACK_PUSH("ElementRenderer::getAdjoiningTopMargins","cocktail/core/renderer/ElementRenderer.hx",759);
		HX_STACK_THIS(this);
		HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,getAdjoiningTopMargins,(void))

Float ElementRenderer_obj::getCollapsedBottomMargin( ){
	HX_STACK_PUSH("ElementRenderer::getCollapsedBottomMargin","cocktail/core/renderer/ElementRenderer.hx",750);
	HX_STACK_THIS(this);
	HX_STACK_LINE(750)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getCollapsedBottomMargin,return )

Float ElementRenderer_obj::getCollapsedTopMargin( ){
	HX_STACK_PUSH("ElementRenderer::getCollapsedTopMargin","cocktail/core/renderer/ElementRenderer.hx",741);
	HX_STACK_THIS(this);
	HX_STACK_LINE(741)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getCollapsedTopMargin,return )

Void ElementRenderer_obj::setAbsolutelyPositionedGlobalOrigins( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float addedX,Float addedY,Float addedPositionedX,Float addedPositionedY){
{
		HX_STACK_PUSH("ElementRenderer::setAbsolutelyPositionedGlobalOrigins","cocktail/core/renderer/ElementRenderer.hx",677);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(addedX,"addedX");
		HX_STACK_ARG(addedY,"addedY");
		HX_STACK_ARG(addedPositionedX,"addedPositionedX");
		HX_STACK_ARG(addedPositionedY,"addedPositionedY");
		HX_STACK_LINE(678)
		::cocktail::core::css::CoreStyle elementRendererCoreStyle = elementRenderer->coreStyle;		HX_STACK_VAR(elementRendererCoreStyle,"elementRendererCoreStyle");
		HX_STACK_LINE(681)
		if ((elementRendererCoreStyle->isFixedPositioned)){
			HX_STACK_LINE(684)
			if (((bool((elementRendererCoreStyle->hasAutoLeft == true)) && bool((elementRendererCoreStyle->hasAutoRight == true))))){
				HX_STACK_LINE(685)
				elementRenderer->globalBounds->x = (addedX + elementRenderer->staticOrigin->x);
			}
			else{
				HX_STACK_LINE(691)
				elementRenderer->globalBounds->x = elementRenderer->bounds->x;
			}
			HX_STACK_LINE(695)
			if (((bool((elementRendererCoreStyle->hasAutoTop == true)) && bool((elementRendererCoreStyle->hasAutoBottom == true))))){
				HX_STACK_LINE(696)
				elementRenderer->globalBounds->y = (addedY + elementRenderer->staticOrigin->y);
			}
			else{
				HX_STACK_LINE(700)
				elementRenderer->globalBounds->y = elementRenderer->bounds->y;
			}
		}
		else{
			HX_STACK_LINE(708)
			if (((bool((elementRendererCoreStyle->hasAutoLeft == true)) && bool((elementRendererCoreStyle->hasAutoRight == true))))){
				HX_STACK_LINE(709)
				elementRenderer->globalBounds->x = (addedX + elementRenderer->staticOrigin->x);
			}
			else{
				HX_STACK_LINE(715)
				elementRenderer->globalBounds->x = (addedPositionedX + elementRenderer->bounds->x);
			}
			HX_STACK_LINE(720)
			if (((bool((elementRendererCoreStyle->hasAutoTop == true)) && bool((elementRendererCoreStyle->hasAutoBottom == true))))){
				HX_STACK_LINE(721)
				elementRenderer->globalBounds->y = (addedY + elementRenderer->staticOrigin->y);
			}
			else{
				HX_STACK_LINE(725)
				elementRenderer->globalBounds->y = (addedPositionedY + elementRenderer->bounds->y);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(ElementRenderer_obj,setAbsolutelyPositionedGlobalOrigins,(void))

Void ElementRenderer_obj::setGlobalOrigins( Float addedX,Float addedY,Float addedPositionedX,Float addedPositionedY){
{
		HX_STACK_PUSH("ElementRenderer::setGlobalOrigins","cocktail/core/renderer/ElementRenderer.hx",606);
		HX_STACK_THIS(this);
		HX_STACK_ARG(addedX,"addedX");
		HX_STACK_ARG(addedY,"addedY");
		HX_STACK_ARG(addedPositionedX,"addedPositionedX");
		HX_STACK_ARG(addedPositionedY,"addedPositionedY");
		HX_STACK_LINE(608)
		if (((this->isPositioned() == true))){
			HX_STACK_LINE(610)
			addedPositionedX = this->globalBounds->x;
			HX_STACK_LINE(611)
			addedPositionedY = this->globalBounds->y;
		}
		HX_STACK_LINE(614)
		if (((this->isBlockContainer == true))){
			HX_STACK_LINE(616)
			addedX = ((this->globalBounds->x + this->coreStyle->usedValues->paddingLeft) + this->coreStyle->usedValues->borderLeftWidth);
			HX_STACK_LINE(617)
			addedY = ((this->globalBounds->y + this->coreStyle->usedValues->paddingTop) + this->coreStyle->usedValues->borderTopWidth);
		}
		HX_STACK_LINE(621)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(622)
		while(((child != null()))){
			HX_STACK_LINE(625)
			if ((child->isAbsolutelyPositioned())){
				HX_STACK_LINE(626)
				this->setAbsolutelyPositionedGlobalOrigins(child,addedX,addedY,addedPositionedX,addedPositionedY);
			}
			else{
				HX_STACK_LINE(632)
				child->globalBounds->x = addedX;
				HX_STACK_LINE(633)
				child->globalBounds->y = addedY;
				HX_STACK_LINE(639)
				if (((bool((child->isInlineLevel() == false)) || bool((child->isReplaced == true))))){
					HX_STACK_LINE(641)
					hx::AddEq(child->globalBounds->x,child->bounds->x);
					HX_STACK_LINE(642)
					hx::AddEq(child->globalBounds->y,child->bounds->y);
				}
				else{
					HX_STACK_LINE(647)
					if (((child->isBlockContainer == true))){
						HX_STACK_LINE(649)
						hx::AddEq(child->globalBounds->x,child->bounds->x);
						HX_STACK_LINE(650)
						hx::AddEq(child->globalBounds->y,child->bounds->y);
					}
				}
			}
			HX_STACK_LINE(655)
			child->globalBounds->width = child->bounds->width;
			HX_STACK_LINE(656)
			child->globalBounds->height = child->bounds->height;
			HX_STACK_LINE(659)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(660)
				child->setGlobalOrigins(addedX,addedY,addedPositionedX,addedPositionedY);
			}
			HX_STACK_LINE(664)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ElementRenderer_obj,setGlobalOrigins,(void))

Void ElementRenderer_obj::layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("ElementRenderer::layout","cocktail/core/renderer/ElementRenderer.hx",592);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_ARG(layoutState,"layoutState");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,layout,(void))

Void ElementRenderer_obj::invalidateLayerRenderer( ){
{
		HX_STACK_PUSH("ElementRenderer::invalidateLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",569);
		HX_STACK_THIS(this);
		HX_STACK_LINE(570)
		this->_needsLayerRendererUpdate = true;
		HX_STACK_LINE(572)
		switch( (int)(this->domNode->get_nodeType())){
			case (int)1: case (int)3: {
				HX_STACK_LINE(575)
				::cocktail::core::html::HTMLDocument htmlDocument = this->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
				HX_STACK_LINE(576)
				htmlDocument->invalidationManager->invalidateLayerTree();
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,invalidateLayerRenderer,(void))

Void ElementRenderer_obj::updateTextDecorations( bool inheritUnderline,bool inheritOverline,bool inheritLineThrough,bool inheritBlink){
{
		HX_STACK_PUSH("ElementRenderer::updateTextDecorations","cocktail/core/renderer/ElementRenderer.hx",488);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inheritUnderline,"inheritUnderline");
		HX_STACK_ARG(inheritOverline,"inheritOverline");
		HX_STACK_ARG(inheritLineThrough,"inheritLineThrough");
		HX_STACK_ARG(inheritBlink,"inheritBlink");
		HX_STACK_LINE(491)
		{
			::cocktail::core::css::CSSPropertyValue _switch_1 = (this->coreStyle->getComputedOrInitialProperty((int)86));
			switch((_switch_1)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
						HX_STACK_LINE(493)
						{
							::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
							switch((_switch_2)->GetIndex()){
								case 84: {
									HX_STACK_LINE(496)
									inheritUnderline = true;
								}
								;break;
								case 85: {
									HX_STACK_LINE(499)
									inheritOverline = true;
								}
								;break;
								case 86: {
									HX_STACK_LINE(502)
									inheritLineThrough = true;
								}
								;break;
								case 87: {
									HX_STACK_LINE(505)
									inheritBlink = true;
								}
								;break;
								default: {
								}
							}
						}
					}
				}
				;break;
				case 13: {
					Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_1->__Param(0);
{
						HX_STACK_LINE(512)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						int _g = value->length;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(512)
						while(((_g1 < _g))){
							HX_STACK_LINE(512)
							int i = (_g1)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(514)
							{
								::cocktail::core::css::CSSPropertyValue _switch_3 = (value->__get(i));
								switch((_switch_3)->GetIndex()){
									case 4: {
										::cocktail::core::css::CSSKeywordValue value1 = _switch_3->__Param(0);
{
											HX_STACK_LINE(516)
											{
												::cocktail::core::css::CSSKeywordValue _switch_4 = (value1);
												switch((_switch_4)->GetIndex()){
													case 84: {
														HX_STACK_LINE(519)
														inheritUnderline = true;
													}
													;break;
													case 85: {
														HX_STACK_LINE(522)
														inheritOverline = true;
													}
													;break;
													case 86: {
														HX_STACK_LINE(525)
														inheritLineThrough = true;
													}
													;break;
													case 87: {
														HX_STACK_LINE(528)
														inheritBlink = true;
													}
													;break;
													default: {
													}
												}
											}
										}
									}
									;break;
									default: {
									}
								}
							}
						}
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(542)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(543)
		while(((child != null()))){
			HX_STACK_LINE(546)
			if (((bool((bool((child->coreStyle->isFloat == true)) || bool((child->coreStyle->isAbsolutelyPositioned == true)))) || bool((child->coreStyle->isInlineBlock == true))))){
				HX_STACK_LINE(547)
				child->updateTextDecorations(false,false,false,false);
			}
			else{
				HX_STACK_LINE(551)
				child->updateTextDecorations(inheritUnderline,inheritOverline,inheritLineThrough,inheritBlink);
			}
			HX_STACK_LINE(554)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ElementRenderer_obj,updateTextDecorations,(void))

Void ElementRenderer_obj::updateText( ){
{
		HX_STACK_PUSH("ElementRenderer::updateText","cocktail/core/renderer/ElementRenderer.hx",461);
		HX_STACK_THIS(this);
		HX_STACK_LINE(462)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(463)
		while(((child != null()))){
			HX_STACK_LINE(465)
			child->updateText();
			HX_STACK_LINE(466)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateText,(void))

Void ElementRenderer_obj::render( ::cocktail::core::graphics::GraphicsContext parentGraphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("ElementRenderer::render","cocktail/core/renderer/ElementRenderer.hx",452);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentGraphicContext,"parentGraphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ElementRenderer_obj,render,(void))

Void ElementRenderer_obj::updateHitTestingBounds( ){
{
		HX_STACK_PUSH("ElementRenderer::updateHitTestingBounds","cocktail/core/renderer/ElementRenderer.hx",390);
		HX_STACK_THIS(this);
		HX_STACK_LINE(394)
		this->hitTestingBounds->x = this->globalBounds->x;
		HX_STACK_LINE(395)
		this->hitTestingBounds->y = this->globalBounds->y;
		HX_STACK_LINE(396)
		this->hitTestingBounds->width = this->globalBounds->width;
		HX_STACK_LINE(397)
		this->hitTestingBounds->height = this->globalBounds->height;
		HX_STACK_LINE(403)
		if (((bool(((bool((this->coreStyle->isInline == true)) || bool((this->isText == true))))) && bool((this->isReplaced == false))))){
			HX_STACK_LINE(405)
			hx::AddEq(this->hitTestingBounds->x,this->bounds->x);
			HX_STACK_LINE(406)
			hx::AddEq(this->hitTestingBounds->y,this->bounds->y);
		}
		HX_STACK_LINE(411)
		::cocktail::core::geom::PointVO scrollOffset = this->layerRenderer->scrollOffset;		HX_STACK_VAR(scrollOffset,"scrollOffset");
		HX_STACK_LINE(412)
		hx::SubEq(this->hitTestingBounds->x,scrollOffset->x);
		HX_STACK_LINE(413)
		hx::SubEq(this->hitTestingBounds->y,scrollOffset->y);
		HX_STACK_LINE(417)
		::cocktail::core::geom::Matrix matrix = this->layerRenderer->matrix;		HX_STACK_VAR(matrix,"matrix");
		HX_STACK_LINE(418)
		hx::AddEq(this->hitTestingBounds->x,matrix->e);
		HX_STACK_LINE(419)
		hx::AddEq(this->hitTestingBounds->y,matrix->f);
		HX_STACK_LINE(424)
		if (((this->_hasOwnLayer == true))){
			HX_STACK_LINE(426)
			hx::AddEq(this->hitTestingBounds->x,this->layerRenderer->scrollLeft);
			HX_STACK_LINE(427)
			hx::AddEq(this->hitTestingBounds->y,this->layerRenderer->scrollTop);
		}
		HX_STACK_LINE(432)
		{
			HX_STACK_LINE(432)
			::cocktail::core::geom::RectangleVO bounds1 = this->layerRenderer->clipRect;		HX_STACK_VAR(bounds1,"bounds1");
			::cocktail::core::geom::RectangleVO bounds2 = this->hitTestingBounds;		HX_STACK_VAR(bounds2,"bounds2");
			::cocktail::core::geom::RectangleVO resultBounds = this->hitTestingBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
			HX_STACK_LINE(432)
			if (((bool((bool((bool(((bounds1->x + bounds1->width) < bounds2->x)) || bool(((bounds2->x + bounds2->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < bounds2->y)))) || bool(((bounds2->y + bounds2->height) < bounds1->y))))){
				HX_STACK_LINE(432)
				resultBounds->x = (int)0;
				HX_STACK_LINE(432)
				resultBounds->y = (int)0;
				HX_STACK_LINE(432)
				resultBounds->height = (int)0;
				HX_STACK_LINE(432)
				resultBounds->width = (int)0;
			}
			else{
				HX_STACK_LINE(432)
				Float left = (int)0;		HX_STACK_VAR(left,"left");
				HX_STACK_LINE(432)
				Float right = (int)0;		HX_STACK_VAR(right,"right");
				HX_STACK_LINE(432)
				Float top = (int)0;		HX_STACK_VAR(top,"top");
				HX_STACK_LINE(432)
				Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
				HX_STACK_LINE(432)
				if (((bounds1->x < bounds2->x))){
					HX_STACK_LINE(432)
					left = bounds2->x;
				}
				else{
					HX_STACK_LINE(432)
					left = bounds1->x;
				}
				HX_STACK_LINE(432)
				if ((((bounds1->x + bounds1->width) < (bounds2->x + bounds2->width)))){
					HX_STACK_LINE(432)
					right = (bounds1->x + bounds1->width);
				}
				else{
					HX_STACK_LINE(432)
					right = (bounds2->x + bounds2->width);
				}
				HX_STACK_LINE(432)
				if (((bounds1->y < bounds2->y))){
					HX_STACK_LINE(432)
					top = bounds2->y;
				}
				else{
					HX_STACK_LINE(432)
					top = bounds1->y;
				}
				HX_STACK_LINE(432)
				if ((((bounds1->y + bounds1->height) < (bounds2->y + bounds2->height)))){
					HX_STACK_LINE(432)
					bottom = (bounds1->y + bounds1->height);
				}
				else{
					HX_STACK_LINE(432)
					bottom = (bounds2->y + bounds2->height);
				}
				HX_STACK_LINE(432)
				resultBounds->x = left;
				HX_STACK_LINE(432)
				resultBounds->y = top;
				HX_STACK_LINE(432)
				resultBounds->width = (right - left);
				HX_STACK_LINE(432)
				resultBounds->height = (bottom - top);
			}
		}
		HX_STACK_LINE(435)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(436)
		while(((child != null()))){
			HX_STACK_LINE(438)
			child->updateHitTestingBounds();
			HX_STACK_LINE(439)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateHitTestingBounds,(void))

Void ElementRenderer_obj::insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild){
{
		HX_STACK_PUSH("ElementRenderer::insertBefore","cocktail/core/renderer/ElementRenderer.hx",366);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
		HX_STACK_ARG(_tmp_refChild,"_tmp_refChild");
		HX_STACK_LINE(367)
		::cocktail::core::renderer::ElementRenderer newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
		::cocktail::core::renderer::ElementRenderer refChild = _tmp_refChild;		HX_STACK_VAR(refChild,"refChild");
		HX_STACK_LINE(367)
		this->super::insertBefore(newChild,refChild);
		HX_STACK_LINE(372)
		if (((refChild == null()))){
			HX_STACK_LINE(373)
			return null();
		}
		HX_STACK_LINE(377)
		newChild->addedToRenderingTree();
		HX_STACK_LINE(378)
		this->invalidate();
	}
return null();
}


Void ElementRenderer_obj::removeChild( Dynamic _tmp_oldChild){
{
		HX_STACK_PUSH("ElementRenderer::removeChild","cocktail/core/renderer/ElementRenderer.hx",354);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_oldChild,"_tmp_oldChild");
		HX_STACK_LINE(355)
		::cocktail::core::renderer::ElementRenderer oldChild = _tmp_oldChild;		HX_STACK_VAR(oldChild,"oldChild");
		HX_STACK_LINE(355)
		oldChild->removedFromRenderingTree();
		HX_STACK_LINE(357)
		this->super::removeChild(oldChild);
		HX_STACK_LINE(358)
		this->invalidate();
	}
return null();
}


Void ElementRenderer_obj::appendChild( Dynamic _tmp_newChild){
{
		HX_STACK_PUSH("ElementRenderer::appendChild","cocktail/core/renderer/ElementRenderer.hx",342);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
		HX_STACK_LINE(343)
		::cocktail::core::renderer::ElementRenderer newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
		HX_STACK_LINE(343)
		this->super::appendChild(newChild);
		HX_STACK_LINE(345)
		newChild->addedToRenderingTree();
		HX_STACK_LINE(346)
		this->invalidate();
	}
return null();
}


Void ElementRenderer_obj::initCoreStyle( ){
{
		HX_STACK_PUSH("ElementRenderer::initCoreStyle","cocktail/core/renderer/ElementRenderer.hx",329);
		HX_STACK_THIS(this);
		HX_STACK_LINE(329)
		this->coreStyle = this->domNode->coreStyle;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,initCoreStyle,(void))

Void ElementRenderer_obj::dispose( ){
{
		HX_STACK_PUSH("ElementRenderer::dispose","cocktail/core/renderer/ElementRenderer.hx",305);
		HX_STACK_THIS(this);
		HX_STACK_LINE(306)
		this->domNode = null();
		HX_STACK_LINE(307)
		this->coreStyle = null();
		HX_STACK_LINE(309)
		this->bounds = null();
		HX_STACK_LINE(310)
		this->globalBounds = null();
		HX_STACK_LINE(311)
		this->staticOrigin = null();
		HX_STACK_LINE(312)
		this->hitTestingBounds = null();
		HX_STACK_LINE(313)
		this->layerRenderer = null();
		HX_STACK_LINE(315)
		int length = this->inlineBoxes->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(316)
		{
			HX_STACK_LINE(316)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(316)
			while(((_g < length))){
				HX_STACK_LINE(316)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(318)
				this->inlineBoxes->__get(i)->dispose();
			}
		}
		HX_STACK_LINE(321)
		this->inlineBoxes = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,dispose,(void))


ElementRenderer_obj::ElementRenderer_obj()
{
}

void ElementRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ElementRenderer);
	HX_MARK_MEMBER_NAME(hasLineBoxes,"hasLineBoxes");
	HX_MARK_MEMBER_NAME(isText,"isText");
	HX_MARK_MEMBER_NAME(isBlockContainer,"isBlockContainer");
	HX_MARK_MEMBER_NAME(isReplaced,"isReplaced");
	HX_MARK_MEMBER_NAME(lastNormalFlowChild,"lastNormalFlowChild");
	HX_MARK_MEMBER_NAME(firstNormalFlowChild,"firstNormalFlowChild");
	HX_MARK_MEMBER_NAME(nextNormalFlowSibling,"nextNormalFlowSibling");
	HX_MARK_MEMBER_NAME(previousNormalFlowSibling,"previousNormalFlowSibling");
	HX_MARK_MEMBER_NAME(containingBlock,"containingBlock");
	HX_MARK_MEMBER_NAME(scrollHeight,"scrollHeight");
	HX_MARK_MEMBER_NAME(scrollWidth,"scrollWidth");
	HX_MARK_MEMBER_NAME(scrollTop,"scrollTop");
	HX_MARK_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_MARK_MEMBER_NAME(_wasAbsolutelyPositioned,"_wasAbsolutelyPositioned");
	HX_MARK_MEMBER_NAME(_needsLayerRendererUpdate,"_needsLayerRendererUpdate");
	HX_MARK_MEMBER_NAME(_hasOwnLayer,"_hasOwnLayer");
	HX_MARK_MEMBER_NAME(inlineBoxes,"inlineBoxes");
	HX_MARK_MEMBER_NAME(layerRenderer,"layerRenderer");
	HX_MARK_MEMBER_NAME(coreStyle,"coreStyle");
	HX_MARK_MEMBER_NAME(domNode,"domNode");
	HX_MARK_MEMBER_NAME(staticOrigin,"staticOrigin");
	HX_MARK_MEMBER_NAME(hitTestingBounds,"hitTestingBounds");
	HX_MARK_MEMBER_NAME(globalBounds,"globalBounds");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ElementRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hasLineBoxes,"hasLineBoxes");
	HX_VISIT_MEMBER_NAME(isText,"isText");
	HX_VISIT_MEMBER_NAME(isBlockContainer,"isBlockContainer");
	HX_VISIT_MEMBER_NAME(isReplaced,"isReplaced");
	HX_VISIT_MEMBER_NAME(lastNormalFlowChild,"lastNormalFlowChild");
	HX_VISIT_MEMBER_NAME(firstNormalFlowChild,"firstNormalFlowChild");
	HX_VISIT_MEMBER_NAME(nextNormalFlowSibling,"nextNormalFlowSibling");
	HX_VISIT_MEMBER_NAME(previousNormalFlowSibling,"previousNormalFlowSibling");
	HX_VISIT_MEMBER_NAME(containingBlock,"containingBlock");
	HX_VISIT_MEMBER_NAME(scrollHeight,"scrollHeight");
	HX_VISIT_MEMBER_NAME(scrollWidth,"scrollWidth");
	HX_VISIT_MEMBER_NAME(scrollTop,"scrollTop");
	HX_VISIT_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_VISIT_MEMBER_NAME(_wasAbsolutelyPositioned,"_wasAbsolutelyPositioned");
	HX_VISIT_MEMBER_NAME(_needsLayerRendererUpdate,"_needsLayerRendererUpdate");
	HX_VISIT_MEMBER_NAME(_hasOwnLayer,"_hasOwnLayer");
	HX_VISIT_MEMBER_NAME(inlineBoxes,"inlineBoxes");
	HX_VISIT_MEMBER_NAME(layerRenderer,"layerRenderer");
	HX_VISIT_MEMBER_NAME(coreStyle,"coreStyle");
	HX_VISIT_MEMBER_NAME(domNode,"domNode");
	HX_VISIT_MEMBER_NAME(staticOrigin,"staticOrigin");
	HX_VISIT_MEMBER_NAME(hitTestingBounds,"hitTestingBounds");
	HX_VISIT_MEMBER_NAME(globalBounds,"globalBounds");
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ElementRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"isText") ) { return isText; }
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"domNode") ) { return domNode; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isVisible") ) { return isVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"scrollTop") ) { return inCallProp ? get_scrollTop() : scrollTop; }
		if (HX_FIELD_EQ(inName,"coreStyle") ) { return coreStyle; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"updateText") ) { return updateText_dyn(); }
		if (HX_FIELD_EQ(inName,"isReplaced") ) { return isReplaced; }
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { return inCallProp ? get_scrollLeft() : scrollLeft; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createLayer") ) { return createLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"isScrollBar") ) { return isScrollBar_dyn(); }
		if (HX_FIELD_EQ(inName,"detachLayer") ) { return detachLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"attachLayer") ) { return attachLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"scrollWidth") ) { return inCallProp ? get_scrollWidth() : scrollWidth; }
		if (HX_FIELD_EQ(inName,"inlineBoxes") ) { return inlineBoxes; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		if (HX_FIELD_EQ(inName,"hasLineBoxes") ) { return hasLineBoxes; }
		if (HX_FIELD_EQ(inName,"scrollHeight") ) { return inCallProp ? get_scrollHeight() : scrollHeight; }
		if (HX_FIELD_EQ(inName,"_hasOwnLayer") ) { return _hasOwnLayer; }
		if (HX_FIELD_EQ(inName,"staticOrigin") ) { return staticOrigin; }
		if (HX_FIELD_EQ(inName,"globalBounds") ) { return globalBounds; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_scrollTop") ) { return get_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollTop") ) { return set_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"doCreateLayer") ) { return doCreateLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"isTransformed") ) { return isTransformed_dyn(); }
		if (HX_FIELD_EQ(inName,"isTransparent") ) { return isTransparent_dyn(); }
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel_dyn(); }
		if (HX_FIELD_EQ(inName,"initCoreStyle") ) { return initCoreStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { return layerRenderer; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_scrollLeft") ) { return get_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollLeft") ) { return set_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"childrenInline") ) { return childrenInline_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_scrollWidth") ) { return get_scrollWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateStyle") ) { return invalidateStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"hasCSSTransform") ) { return hasCSSTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getLeadedAscent") ) { return getLeadedAscent_dyn(); }
		if (HX_FIELD_EQ(inName,"containingBlock") ) { return containingBlock; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_scrollHeight") ) { return get_scrollHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"canHaveClearance") ) { return canHaveClearance_dyn(); }
		if (HX_FIELD_EQ(inName,"getLeadedDescent") ) { return getLeadedDescent_dyn(); }
		if (HX_FIELD_EQ(inName,"setGlobalOrigins") ) { return setGlobalOrigins_dyn(); }
		if (HX_FIELD_EQ(inName,"isBlockContainer") ) { return isBlockContainer; }
		if (HX_FIELD_EQ(inName,"hitTestingBounds") ) { return hitTestingBounds; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateInlineBoxes") ) { return updateInlineBoxes_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getContainingBlock") ) { return getContainingBlock_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"invalidateRendering") ) { return invalidateRendering_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetChildrenBounds") ) { return doGetChildrenBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"isAnonymousBlockBox") ) { return isAnonymousBlockBox_dyn(); }
		if (HX_FIELD_EQ(inName,"updateLayerRenderer") ) { return updateLayerRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"lastNormalFlowChild") ) { return inCallProp ? get_lastNormalFlowChild() : lastNormalFlowChild; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getInlineBoxesBounds") ) { return getInlineBoxesBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"getNextLayerRenderer") ) { return getNextLayerRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"isRelativePositioned") ) { return isRelativePositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"addedToRenderingTree") ) { return addedToRenderingTree_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAnonymousBlock") ) { return updateAnonymousBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"firstNormalFlowChild") ) { return inCallProp ? get_firstNormalFlowChild() : firstNormalFlowChild; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getCollapsedTopMargin") ) { return getCollapsedTopMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"updateTextDecorations") ) { return updateTextDecorations_dyn(); }
		if (HX_FIELD_EQ(inName,"nextNormalFlowSibling") ) { return inCallProp ? get_nextNormalFlowSibling() : nextNormalFlowSibling; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getFirstBlockContainer") ) { return getFirstBlockContainer_dyn(); }
		if (HX_FIELD_EQ(inName,"isAbsolutelyPositioned") ) { return isAbsolutelyPositioned_dyn(); }
		if (HX_FIELD_EQ(inName,"getAdjoiningTopMargins") ) { return getAdjoiningTopMargins_dyn(); }
		if (HX_FIELD_EQ(inName,"updateHitTestingBounds") ) { return updateHitTestingBounds_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"get_lastNormalFlowChild") ) { return get_lastNormalFlowChild_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateLayerRenderer") ) { return invalidateLayerRenderer_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"get_firstNormalFlowChild") ) { return get_firstNormalFlowChild_dyn(); }
		if (HX_FIELD_EQ(inName,"removedFromRenderingTree") ) { return removedFromRenderingTree_dyn(); }
		if (HX_FIELD_EQ(inName,"getCollapsedBottomMargin") ) { return getCollapsedBottomMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"_wasAbsolutelyPositioned") ) { return _wasAbsolutelyPositioned; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"get_nextNormalFlowSibling") ) { return get_nextNormalFlowSibling_dyn(); }
		if (HX_FIELD_EQ(inName,"getInitialContainingBlock") ) { return getInitialContainingBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"getAdjoiningBottomMargins") ) { return getAdjoiningBottomMargins_dyn(); }
		if (HX_FIELD_EQ(inName,"previousNormalFlowSibling") ) { return inCallProp ? get_previousNormalFlowSibling() : previousNormalFlowSibling; }
		if (HX_FIELD_EQ(inName,"_needsLayerRendererUpdate") ) { return _needsLayerRendererUpdate; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getFirstPositionedAncestor") ) { return getFirstPositionedAncestor_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"get_previousNormalFlowSibling") ) { return get_previousNormalFlowSibling_dyn(); }
		if (HX_FIELD_EQ(inName,"unregisterWithContainingBlock") ) { return unregisterWithContainingBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"registerWithContaininingBlock") ) { return registerWithContaininingBlock_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"establishesNewBlockFormattingContext") ) { return establishesNewBlockFormattingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"setAbsolutelyPositionedGlobalOrigins") ) { return setAbsolutelyPositionedGlobalOrigins_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"getNextElementRendererWithOwnLayerRenderer") ) { return getNextElementRendererWithOwnLayerRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ElementRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"isText") ) { isText=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"domNode") ) { domNode=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"scrollTop") ) { if (inCallProp) return set_scrollTop(inValue);scrollTop=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coreStyle") ) { coreStyle=inValue.Cast< ::cocktail::core::css::CoreStyle >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isReplaced") ) { isReplaced=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { if (inCallProp) return set_scrollLeft(inValue);scrollLeft=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"scrollWidth") ) { scrollWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"inlineBoxes") ) { inlineBoxes=inValue.Cast< Array< ::cocktail::core::linebox::InlineBox > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hasLineBoxes") ) { hasLineBoxes=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollHeight") ) { scrollHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hasOwnLayer") ) { _hasOwnLayer=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"staticOrigin") ) { staticOrigin=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"globalBounds") ) { globalBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { layerRenderer=inValue.Cast< ::cocktail::core::layer::LayerRenderer >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"containingBlock") ) { containingBlock=inValue.Cast< ::cocktail::core::renderer::FlowBoxRenderer >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"isBlockContainer") ) { isBlockContainer=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hitTestingBounds") ) { hitTestingBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"lastNormalFlowChild") ) { lastNormalFlowChild=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"firstNormalFlowChild") ) { firstNormalFlowChild=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nextNormalFlowSibling") ) { nextNormalFlowSibling=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_wasAbsolutelyPositioned") ) { _wasAbsolutelyPositioned=inValue.Cast< bool >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"previousNormalFlowSibling") ) { previousNormalFlowSibling=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_needsLayerRendererUpdate") ) { _needsLayerRendererUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ElementRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hasLineBoxes"));
	outFields->push(HX_CSTRING("isText"));
	outFields->push(HX_CSTRING("isBlockContainer"));
	outFields->push(HX_CSTRING("isReplaced"));
	outFields->push(HX_CSTRING("lastNormalFlowChild"));
	outFields->push(HX_CSTRING("firstNormalFlowChild"));
	outFields->push(HX_CSTRING("nextNormalFlowSibling"));
	outFields->push(HX_CSTRING("previousNormalFlowSibling"));
	outFields->push(HX_CSTRING("containingBlock"));
	outFields->push(HX_CSTRING("scrollHeight"));
	outFields->push(HX_CSTRING("scrollWidth"));
	outFields->push(HX_CSTRING("scrollTop"));
	outFields->push(HX_CSTRING("scrollLeft"));
	outFields->push(HX_CSTRING("_wasAbsolutelyPositioned"));
	outFields->push(HX_CSTRING("_needsLayerRendererUpdate"));
	outFields->push(HX_CSTRING("_hasOwnLayer"));
	outFields->push(HX_CSTRING("inlineBoxes"));
	outFields->push(HX_CSTRING("layerRenderer"));
	outFields->push(HX_CSTRING("coreStyle"));
	outFields->push(HX_CSTRING("domNode"));
	outFields->push(HX_CSTRING("staticOrigin"));
	outFields->push(HX_CSTRING("hitTestingBounds"));
	outFields->push(HX_CSTRING("globalBounds"));
	outFields->push(HX_CSTRING("bounds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_scrollHeight"),
	HX_CSTRING("get_scrollWidth"),
	HX_CSTRING("get_lastNormalFlowChild"),
	HX_CSTRING("get_firstNormalFlowChild"),
	HX_CSTRING("get_nextNormalFlowSibling"),
	HX_CSTRING("get_previousNormalFlowSibling"),
	HX_CSTRING("get_scrollTop"),
	HX_CSTRING("set_scrollTop"),
	HX_CSTRING("get_scrollLeft"),
	HX_CSTRING("set_scrollLeft"),
	HX_CSTRING("invalidateRendering"),
	HX_CSTRING("invalidateStyle"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("doGetChildrenBounds"),
	HX_CSTRING("getInlineBoxesBounds"),
	HX_CSTRING("getFirstBlockContainer"),
	HX_CSTRING("getInitialContainingBlock"),
	HX_CSTRING("getFirstPositionedAncestor"),
	HX_CSTRING("getContainingBlock"),
	HX_CSTRING("getNextElementRendererWithOwnLayerRenderer"),
	HX_CSTRING("getNextLayerRenderer"),
	HX_CSTRING("doCreateLayer"),
	HX_CSTRING("createLayer"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("isVisible"),
	HX_CSTRING("hasCSSTransform"),
	HX_CSTRING("isTransformed"),
	HX_CSTRING("isAnonymousBlockBox"),
	HX_CSTRING("childrenInline"),
	HX_CSTRING("isTransparent"),
	HX_CSTRING("isRelativePositioned"),
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("isAbsolutelyPositioned"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("canHaveClearance"),
	HX_CSTRING("isScrollBar"),
	HX_CSTRING("establishesNewBlockFormattingContext"),
	HX_CSTRING("getLeadedDescent"),
	HX_CSTRING("getLeadedAscent"),
	HX_CSTRING("unregisterWithContainingBlock"),
	HX_CSTRING("registerWithContaininingBlock"),
	HX_CSTRING("detachLayer"),
	HX_CSTRING("attachLayer"),
	HX_CSTRING("removedFromRenderingTree"),
	HX_CSTRING("addedToRenderingTree"),
	HX_CSTRING("updateInlineBoxes"),
	HX_CSTRING("updateAnonymousBlock"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("updateLayerRenderer"),
	HX_CSTRING("getAdjoiningBottomMargins"),
	HX_CSTRING("getAdjoiningTopMargins"),
	HX_CSTRING("getCollapsedBottomMargin"),
	HX_CSTRING("getCollapsedTopMargin"),
	HX_CSTRING("setAbsolutelyPositionedGlobalOrigins"),
	HX_CSTRING("setGlobalOrigins"),
	HX_CSTRING("layout"),
	HX_CSTRING("invalidateLayerRenderer"),
	HX_CSTRING("updateTextDecorations"),
	HX_CSTRING("updateText"),
	HX_CSTRING("render"),
	HX_CSTRING("updateHitTestingBounds"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("initCoreStyle"),
	HX_CSTRING("dispose"),
	HX_CSTRING("hasLineBoxes"),
	HX_CSTRING("isText"),
	HX_CSTRING("isBlockContainer"),
	HX_CSTRING("isReplaced"),
	HX_CSTRING("lastNormalFlowChild"),
	HX_CSTRING("firstNormalFlowChild"),
	HX_CSTRING("nextNormalFlowSibling"),
	HX_CSTRING("previousNormalFlowSibling"),
	HX_CSTRING("containingBlock"),
	HX_CSTRING("scrollHeight"),
	HX_CSTRING("scrollWidth"),
	HX_CSTRING("scrollTop"),
	HX_CSTRING("scrollLeft"),
	HX_CSTRING("_wasAbsolutelyPositioned"),
	HX_CSTRING("_needsLayerRendererUpdate"),
	HX_CSTRING("_hasOwnLayer"),
	HX_CSTRING("inlineBoxes"),
	HX_CSTRING("layerRenderer"),
	HX_CSTRING("coreStyle"),
	HX_CSTRING("domNode"),
	HX_CSTRING("staticOrigin"),
	HX_CSTRING("hitTestingBounds"),
	HX_CSTRING("globalBounds"),
	HX_CSTRING("bounds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ElementRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ElementRenderer_obj::__mClass,"__mClass");
};

Class ElementRenderer_obj::__mClass;

void ElementRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.ElementRenderer"), hx::TCanCast< ElementRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ElementRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
