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
	HX_STACK_PUSH("ElementRenderer::get_scrollHeight","cocktail/core/renderer/ElementRenderer.hx",1606);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1607)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1609)
		Float scrollableHeight = this->layerRenderer->scrollableBounds->height;		HX_STACK_VAR(scrollableHeight,"scrollableHeight");
		HX_STACK_LINE(1611)
		if (((scrollableHeight > this->bounds->height))){
			HX_STACK_LINE(1612)
			return scrollableHeight;
		}
	}
	HX_STACK_LINE(1617)
	return this->bounds->height;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollHeight,return )

Float ElementRenderer_obj::get_scrollWidth( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollWidth","cocktail/core/renderer/ElementRenderer.hx",1591);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1592)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1594)
		Float scrollableWidth = this->layerRenderer->scrollableBounds->width;		HX_STACK_VAR(scrollableWidth,"scrollableWidth");
		HX_STACK_LINE(1596)
		if (((scrollableWidth > this->bounds->width))){
			HX_STACK_LINE(1597)
			return scrollableWidth;
		}
	}
	HX_STACK_LINE(1602)
	return this->bounds->width;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollWidth,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_lastNormalFlowChild( ){
	HX_STACK_PUSH("ElementRenderer::get_lastNormalFlowChild","cocktail/core/renderer/ElementRenderer.hx",1566);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1567)
	::cocktail::core::renderer::ElementRenderer lastElementRendererChild = this->lastChild;		HX_STACK_VAR(lastElementRendererChild,"lastElementRendererChild");
	HX_STACK_LINE(1569)
	if (((lastElementRendererChild != null()))){
		HX_STACK_LINE(1571)
		if (((lastElementRendererChild->isFloat() == false))){
			HX_STACK_LINE(1572)
			if (((lastElementRendererChild->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1574)
				return lastElementRendererChild;
			}
		}
		HX_STACK_LINE(1579)
		return lastElementRendererChild->get_previousNormalFlowSibling();
	}
	HX_STACK_LINE(1582)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_lastNormalFlowChild,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_firstNormalFlowChild( ){
	HX_STACK_PUSH("ElementRenderer::get_firstNormalFlowChild","cocktail/core/renderer/ElementRenderer.hx",1546);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1547)
	::cocktail::core::renderer::ElementRenderer firstElementRendererChild = this->firstChild;		HX_STACK_VAR(firstElementRendererChild,"firstElementRendererChild");
	HX_STACK_LINE(1549)
	if (((firstElementRendererChild != null()))){
		HX_STACK_LINE(1551)
		if (((firstElementRendererChild->isFloat() == false))){
			HX_STACK_LINE(1552)
			if (((firstElementRendererChild->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1554)
				return firstElementRendererChild;
			}
		}
		HX_STACK_LINE(1559)
		return firstElementRendererChild->get_nextNormalFlowSibling();
	}
	HX_STACK_LINE(1562)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_firstNormalFlowChild,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_nextNormalFlowSibling( ){
	HX_STACK_PUSH("ElementRenderer::get_nextNormalFlowSibling","cocktail/core/renderer/ElementRenderer.hx",1526);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1527)
	::cocktail::core::renderer::ElementRenderer nextElementRendererSibling = this->nextSibling;		HX_STACK_VAR(nextElementRendererSibling,"nextElementRendererSibling");
	HX_STACK_LINE(1529)
	while(((nextElementRendererSibling != null()))){
		HX_STACK_LINE(1531)
		if (((nextElementRendererSibling->isFloat() == false))){
			HX_STACK_LINE(1532)
			if (((nextElementRendererSibling->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1534)
				return nextElementRendererSibling;
			}
		}
		HX_STACK_LINE(1539)
		nextElementRendererSibling = nextElementRendererSibling->nextSibling;
	}
	HX_STACK_LINE(1542)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_nextNormalFlowSibling,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::get_previousNormalFlowSibling( ){
	HX_STACK_PUSH("ElementRenderer::get_previousNormalFlowSibling","cocktail/core/renderer/ElementRenderer.hx",1506);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1507)
	::cocktail::core::renderer::ElementRenderer previousElementRendererSibling = this->previousSibling;		HX_STACK_VAR(previousElementRendererSibling,"previousElementRendererSibling");
	HX_STACK_LINE(1509)
	while(((previousElementRendererSibling != null()))){
		HX_STACK_LINE(1511)
		if (((previousElementRendererSibling->isFloat() == false))){
			HX_STACK_LINE(1512)
			if (((previousElementRendererSibling->isAbsolutelyPositioned() == false))){
				HX_STACK_LINE(1514)
				return previousElementRendererSibling;
			}
		}
		HX_STACK_LINE(1519)
		previousElementRendererSibling = previousElementRendererSibling->previousSibling;
	}
	HX_STACK_LINE(1522)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_previousNormalFlowSibling,return )

Float ElementRenderer_obj::get_scrollTop( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollTop","cocktail/core/renderer/ElementRenderer.hx",1492);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1493)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1494)
		return this->layerRenderer->scrollTop;
	}
	HX_STACK_LINE(1498)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollTop,return )

Float ElementRenderer_obj::set_scrollTop( Float value){
	HX_STACK_PUSH("ElementRenderer::set_scrollTop","cocktail/core/renderer/ElementRenderer.hx",1479);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1480)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1481)
		this->layerRenderer->set_scrollTop(value);
	}
	HX_STACK_LINE(1485)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,set_scrollTop,return )

Float ElementRenderer_obj::get_scrollLeft( ){
	HX_STACK_PUSH("ElementRenderer::get_scrollLeft","cocktail/core/renderer/ElementRenderer.hx",1466);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1467)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1468)
		return this->layerRenderer->scrollLeft;
	}
	HX_STACK_LINE(1472)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,get_scrollLeft,return )

Float ElementRenderer_obj::set_scrollLeft( Float value){
	HX_STACK_PUSH("ElementRenderer::set_scrollLeft","cocktail/core/renderer/ElementRenderer.hx",1451);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1452)
	if (((this->_hasOwnLayer == true))){
		HX_STACK_LINE(1453)
		this->layerRenderer->set_scrollLeft(value);
	}
	HX_STACK_LINE(1457)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,set_scrollLeft,return )

Void ElementRenderer_obj::invalidateRendering( ){
{
		HX_STACK_PUSH("ElementRenderer::invalidateRendering","cocktail/core/renderer/ElementRenderer.hx",1429);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,invalidateRendering,(void))

Void ElementRenderer_obj::invalidateStyle( int styleIndex){
{
		HX_STACK_PUSH("ElementRenderer::invalidateStyle","cocktail/core/renderer/ElementRenderer.hx",1420);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,invalidateStyle,(void))

Void ElementRenderer_obj::invalidate( ){
{
		HX_STACK_PUSH("ElementRenderer::invalidate","cocktail/core/renderer/ElementRenderer.hx",1409);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,invalidate,(void))

Void ElementRenderer_obj::doGetChildrenBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds){
{
		HX_STACK_PUSH("ElementRenderer::doGetChildrenBounds","cocktail/core/renderer/ElementRenderer.hx",1379);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(1380)
		::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(1381)
		while(((child != null()))){
			HX_STACK_LINE(1383)
			{
				HX_STACK_LINE(1383)
				::cocktail::core::geom::RectangleVO addedBounds = child->bounds;		HX_STACK_VAR(addedBounds,"addedBounds");
				bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
				bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
				HX_STACK_LINE(1383)
				if (((getHorizontalBounds == true))){
					HX_STACK_LINE(1383)
					if (((addedBounds->x < bounds->x))){
						HX_STACK_LINE(1383)
						bounds->x = addedBounds->x;
					}
					HX_STACK_LINE(1383)
					if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
						HX_STACK_LINE(1383)
						bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
					}
				}
				HX_STACK_LINE(1383)
				if (((getVerticalBounds == true))){
					HX_STACK_LINE(1383)
					if (((addedBounds->y < bounds->y))){
						HX_STACK_LINE(1383)
						bounds->y = addedBounds->y;
					}
					HX_STACK_LINE(1383)
					if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
						HX_STACK_LINE(1383)
						bounds->height = ((addedBounds->y + addedBounds->height) - bounds->y);
					}
				}
			}
			HX_STACK_LINE(1384)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(1385)
				this->doGetChildrenBounds(child,bounds);
			}
			HX_STACK_LINE(1389)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,doGetChildrenBounds,(void))

Void ElementRenderer_obj::getInlineBoxesBounds( Array< ::cocktail::core::linebox::InlineBox > inLineBoxes,::cocktail::core::geom::RectangleVO bounds){
{
		HX_STACK_PUSH("ElementRenderer::getInlineBoxesBounds","cocktail/core/renderer/ElementRenderer.hx",1359);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inLineBoxes,"inLineBoxes");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(1361)
		bounds->x = (int)50000;
		HX_STACK_LINE(1362)
		bounds->y = (int)50000;
		HX_STACK_LINE(1363)
		bounds->width = (int)0;
		HX_STACK_LINE(1364)
		bounds->height = (int)0;
		HX_STACK_LINE(1366)
		int length = inLineBoxes->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(1367)
		{
			HX_STACK_LINE(1367)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1367)
			while(((_g < length))){
				HX_STACK_LINE(1367)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1369)
				{
					HX_STACK_LINE(1369)
					::cocktail::core::geom::RectangleVO addedBounds = inLineBoxes->__get(i)->bounds;		HX_STACK_VAR(addedBounds,"addedBounds");
					bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
					bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
					HX_STACK_LINE(1369)
					if (((getHorizontalBounds == true))){
						HX_STACK_LINE(1369)
						if (((addedBounds->x < bounds->x))){
							HX_STACK_LINE(1369)
							bounds->x = addedBounds->x;
						}
						HX_STACK_LINE(1369)
						if ((((addedBounds->x + addedBounds->width) > (bounds->x + bounds->width)))){
							HX_STACK_LINE(1369)
							bounds->width = ((addedBounds->x + addedBounds->width) - bounds->x);
						}
					}
					HX_STACK_LINE(1369)
					if (((getVerticalBounds == true))){
						HX_STACK_LINE(1369)
						if (((addedBounds->y < bounds->y))){
							HX_STACK_LINE(1369)
							bounds->y = addedBounds->y;
						}
						HX_STACK_LINE(1369)
						if ((((addedBounds->y + addedBounds->height) > (bounds->y + bounds->height)))){
							HX_STACK_LINE(1369)
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
	HX_STACK_PUSH("ElementRenderer::getFirstBlockContainer","cocktail/core/renderer/ElementRenderer.hx",1344);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1345)
	::cocktail::core::renderer::ElementRenderer parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1346)
	while(((parent->isBlockContainer == false))){
		HX_STACK_LINE(1347)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1351)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getFirstBlockContainer,return )

::cocktail::core::renderer::InitialBlockRenderer ElementRenderer_obj::getInitialContainingBlock( ){
	HX_STACK_PUSH("ElementRenderer::getInitialContainingBlock","cocktail/core/renderer/ElementRenderer.hx",1336);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1336)
	return this->domNode->ownerDocument->documentElement->elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getInitialContainingBlock,return )

::cocktail::core::renderer::FlowBoxRenderer ElementRenderer_obj::getFirstPositionedAncestor( ){
	HX_STACK_PUSH("ElementRenderer::getFirstPositionedAncestor","cocktail/core/renderer/ElementRenderer.hx",1313);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1314)
	::cocktail::core::renderer::ElementRenderer parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1315)
	while(((parent->isPositioned() == false))){
		HX_STACK_LINE(1322)
		if (((parent->parentNode == null()))){
			HX_STACK_LINE(1323)
			break;
		}
		HX_STACK_LINE(1326)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1329)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getFirstPositionedAncestor,return )

::cocktail::core::renderer::FlowBoxRenderer ElementRenderer_obj::getContainingBlock( ){
	HX_STACK_PUSH("ElementRenderer::getContainingBlock","cocktail/core/renderer/ElementRenderer.hx",1285);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1285)
	if (((this->isAbsolutelyPositioned() == true))){
		HX_STACK_LINE(1287)
		if (((this->coreStyle->isFixedPositioned == true))){
			HX_STACK_LINE(1291)
			return this->getInitialContainingBlock();
		}
		else{
			HX_STACK_LINE(1297)
			return this->getFirstPositionedAncestor();
		}
	}
	else{
		HX_STACK_LINE(1304)
		return this->getFirstBlockContainer();
	}
	HX_STACK_LINE(1285)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getContainingBlock,return )

::cocktail::core::renderer::ElementRenderer ElementRenderer_obj::getNextElementRendererWithOwnLayerRenderer( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::renderer::ElementRenderer referenceElementRenderer){
	HX_STACK_PUSH("ElementRenderer::getNextElementRendererWithOwnLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",1220);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
	HX_STACK_ARG(referenceElementRenderer,"referenceElementRenderer");
	HX_STACK_LINE(1224)
	bool foundSelf = false;		HX_STACK_VAR(foundSelf,"foundSelf");
	HX_STACK_LINE(1226)
	::cocktail::core::renderer::ElementRenderer child = rootElementRenderer->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(1227)
	while(((child != null()))){
		HX_STACK_LINE(1230)
		if (((child == referenceElementRenderer))){
			HX_STACK_LINE(1231)
			foundSelf = true;
		}
		else{
			HX_STACK_LINE(1235)
			if (((bool((child->createOwnLayer() == true)) && bool((child->layerRenderer != null()))))){
				HX_STACK_LINE(1236)
				if (((foundSelf == true))){
					HX_STACK_LINE(1241)
					return child;
				}
			}
			else{
				HX_STACK_LINE(1246)
				if (((child->firstChild != null()))){
					HX_STACK_LINE(1249)
					::cocktail::core::renderer::ElementRenderer nextElementRendererWithOwnLayerRenderer = this->getNextElementRendererWithOwnLayerRenderer(child,referenceElementRenderer);		HX_STACK_VAR(nextElementRendererWithOwnLayerRenderer,"nextElementRendererWithOwnLayerRenderer");
					HX_STACK_LINE(1251)
					if (((nextElementRendererWithOwnLayerRenderer != null()))){
						HX_STACK_LINE(1252)
						if (((nextElementRendererWithOwnLayerRenderer == referenceElementRenderer))){
							HX_STACK_LINE(1254)
							foundSelf = true;
						}
						else{
							HX_STACK_LINE(1258)
							return nextElementRendererWithOwnLayerRenderer;
						}
					}
				}
			}
		}
		HX_STACK_LINE(1264)
		child = child->nextSibling;
	}
	HX_STACK_LINE(1270)
	if (((foundSelf == true))){
		HX_STACK_LINE(1271)
		return referenceElementRenderer;
	}
	else{
		HX_STACK_LINE(1275)
		return null();
	}
	HX_STACK_LINE(1270)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,getNextElementRendererWithOwnLayerRenderer,return )

::cocktail::core::layer::LayerRenderer ElementRenderer_obj::getNextLayerRenderer( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::renderer::ElementRenderer referenceElementRenderer){
	HX_STACK_PUSH("ElementRenderer::getNextLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",1183);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootElementRenderer,"rootElementRenderer");
	HX_STACK_ARG(referenceElementRenderer,"referenceElementRenderer");
	HX_STACK_LINE(1186)
	::cocktail::core::renderer::ElementRenderer nextElementRendererWithOwnLayerRenderer = this->getNextElementRendererWithOwnLayerRenderer(rootElementRenderer,referenceElementRenderer);		HX_STACK_VAR(nextElementRendererWithOwnLayerRenderer,"nextElementRendererWithOwnLayerRenderer");
	HX_STACK_LINE(1189)
	if (((nextElementRendererWithOwnLayerRenderer == null()))){
		HX_STACK_LINE(1190)
		return null();
	}
	else{
		HX_STACK_LINE(1195)
		if (((nextElementRendererWithOwnLayerRenderer == referenceElementRenderer))){
			HX_STACK_LINE(1196)
			return null();
		}
		else{
			HX_STACK_LINE(1201)
			return nextElementRendererWithOwnLayerRenderer->layerRenderer;
		}
	}
	HX_STACK_LINE(1189)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,getNextLayerRenderer,return )

Void ElementRenderer_obj::doCreateLayer( ){
{
		HX_STACK_PUSH("ElementRenderer::doCreateLayer","cocktail/core/renderer/ElementRenderer.hx",1167);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1167)
		this->layerRenderer = ::cocktail::core::layer::LayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,doCreateLayer,(void))

Void ElementRenderer_obj::createLayer( ::cocktail::core::layer::LayerRenderer parentLayer){
{
		HX_STACK_PUSH("ElementRenderer::createLayer","cocktail/core/renderer/ElementRenderer.hx",1147);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentLayer,"parentLayer");
		HX_STACK_LINE(1147)
		if (((this->createOwnLayer() == true))){
			HX_STACK_LINE(1150)
			this->doCreateLayer();
			HX_STACK_LINE(1152)
			parentLayer->insertBefore(this->layerRenderer,this->getNextLayerRenderer(parentLayer->rootElementRenderer,hx::ObjectPtr<OBJ_>(this)));
			HX_STACK_LINE(1153)
			this->_hasOwnLayer = true;
		}
		else{
			HX_STACK_LINE(1156)
			this->layerRenderer = parentLayer;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,createLayer,(void))

bool ElementRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("ElementRenderer::createOwnLayer","cocktail/core/renderer/ElementRenderer.hx",1134);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1134)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,createOwnLayer,return )

bool ElementRenderer_obj::isVisible( ){
	HX_STACK_PUSH("ElementRenderer::isVisible","cocktail/core/renderer/ElementRenderer.hx",1123);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1123)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isVisible,return )

bool ElementRenderer_obj::hasCSSTransform( ){
	HX_STACK_PUSH("ElementRenderer::hasCSSTransform","cocktail/core/renderer/ElementRenderer.hx",1118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1118)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,hasCSSTransform,return )

bool ElementRenderer_obj::isTransformed( ){
	HX_STACK_PUSH("ElementRenderer::isTransformed","cocktail/core/renderer/ElementRenderer.hx",1113);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1113)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isTransformed,return )

bool ElementRenderer_obj::isAnonymousBlockBox( ){
	HX_STACK_PUSH("ElementRenderer::isAnonymousBlockBox","cocktail/core/renderer/ElementRenderer.hx",1108);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1108)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isAnonymousBlockBox,return )

bool ElementRenderer_obj::childrenInline( ){
	HX_STACK_PUSH("ElementRenderer::childrenInline","cocktail/core/renderer/ElementRenderer.hx",1103);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1103)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,childrenInline,return )

bool ElementRenderer_obj::isTransparent( ){
	HX_STACK_PUSH("ElementRenderer::isTransparent","cocktail/core/renderer/ElementRenderer.hx",1098);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1098)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isTransparent,return )

bool ElementRenderer_obj::isRelativePositioned( ){
	HX_STACK_PUSH("ElementRenderer::isRelativePositioned","cocktail/core/renderer/ElementRenderer.hx",1093);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1093)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isRelativePositioned,return )

bool ElementRenderer_obj::isInlineLevel( ){
	HX_STACK_PUSH("ElementRenderer::isInlineLevel","cocktail/core/renderer/ElementRenderer.hx",1088);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1088)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isInlineLevel,return )

bool ElementRenderer_obj::isAbsolutelyPositioned( ){
	HX_STACK_PUSH("ElementRenderer::isAbsolutelyPositioned","cocktail/core/renderer/ElementRenderer.hx",1083);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1083)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isAbsolutelyPositioned,return )

bool ElementRenderer_obj::isPositioned( ){
	HX_STACK_PUSH("ElementRenderer::isPositioned","cocktail/core/renderer/ElementRenderer.hx",1078);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1078)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isPositioned,return )

bool ElementRenderer_obj::isFloat( ){
	HX_STACK_PUSH("ElementRenderer::isFloat","cocktail/core/renderer/ElementRenderer.hx",1073);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1073)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isFloat,return )

bool ElementRenderer_obj::canHaveClearance( ){
	HX_STACK_PUSH("ElementRenderer::canHaveClearance","cocktail/core/renderer/ElementRenderer.hx",1068);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1068)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,canHaveClearance,return )

bool ElementRenderer_obj::isScrollBar( ){
	HX_STACK_PUSH("ElementRenderer::isScrollBar","cocktail/core/renderer/ElementRenderer.hx",1063);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1063)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,isScrollBar,return )

bool ElementRenderer_obj::establishesNewBlockFormattingContext( ){
	HX_STACK_PUSH("ElementRenderer::establishesNewBlockFormattingContext","cocktail/core/renderer/ElementRenderer.hx",1058);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1058)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,establishesNewBlockFormattingContext,return )

Float ElementRenderer_obj::getLeadedDescent( ){
	HX_STACK_PUSH("ElementRenderer::getLeadedDescent","cocktail/core/renderer/ElementRenderer.hx",1041);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1042)
	::cocktail::core::font::FontMetricsVO fontMetrics = this->coreStyle->fontMetrics;		HX_STACK_VAR(fontMetrics,"fontMetrics");
	HX_STACK_LINE(1044)
	Float ascent = fontMetrics->ascent;		HX_STACK_VAR(ascent,"ascent");
	HX_STACK_LINE(1045)
	Float descent = fontMetrics->descent;		HX_STACK_VAR(descent,"descent");
	HX_STACK_LINE(1047)
	Float lineHeight = this->coreStyle->usedValues->lineHeight;		HX_STACK_VAR(lineHeight,"lineHeight");
	HX_STACK_LINE(1049)
	Float leading = (lineHeight - ((ascent + descent)));		HX_STACK_VAR(leading,"leading");
	HX_STACK_LINE(1051)
	Float leadedAscent = (ascent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedAscent,"leadedAscent");
	HX_STACK_LINE(1052)
	Float leadedDescent = (descent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedDescent,"leadedDescent");
	HX_STACK_LINE(1054)
	return leadedDescent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getLeadedDescent,return )

Float ElementRenderer_obj::getLeadedAscent( ){
	HX_STACK_PUSH("ElementRenderer::getLeadedAscent","cocktail/core/renderer/ElementRenderer.hx",1018);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1019)
	::cocktail::core::font::FontMetricsVO fontMetrics = this->coreStyle->fontMetrics;		HX_STACK_VAR(fontMetrics,"fontMetrics");
	HX_STACK_LINE(1021)
	Float ascent = fontMetrics->ascent;		HX_STACK_VAR(ascent,"ascent");
	HX_STACK_LINE(1022)
	Float descent = fontMetrics->descent;		HX_STACK_VAR(descent,"descent");
	HX_STACK_LINE(1024)
	Float lineHeight = this->coreStyle->usedValues->lineHeight;		HX_STACK_VAR(lineHeight,"lineHeight");
	HX_STACK_LINE(1028)
	Float leading = (lineHeight - ((ascent + descent)));		HX_STACK_VAR(leading,"leading");
	HX_STACK_LINE(1031)
	Float leadedAscent = (ascent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedAscent,"leadedAscent");
	HX_STACK_LINE(1032)
	Float leadedDescent = (descent + (Float(leading) / Float((int)2)));		HX_STACK_VAR(leadedDescent,"leadedDescent");
	HX_STACK_LINE(1034)
	return leadedAscent;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getLeadedAscent,return )

Void ElementRenderer_obj::unregisterWithContainingBlock( ){
{
		HX_STACK_PUSH("ElementRenderer::unregisterWithContainingBlock","cocktail/core/renderer/ElementRenderer.hx",1002);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1002)
		if (((this->_wasAbsolutelyPositioned == true))){
			HX_STACK_LINE(1005)
			this->containingBlock->removeAbsolutelyPositionedChild(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(1006)
			this->_wasAbsolutelyPositioned = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,unregisterWithContainingBlock,(void))

Void ElementRenderer_obj::registerWithContaininingBlock( ){
{
		HX_STACK_PUSH("ElementRenderer::registerWithContaininingBlock","cocktail/core/renderer/ElementRenderer.hx",986);
		HX_STACK_THIS(this);
		HX_STACK_LINE(986)
		if (((this->isAbsolutelyPositioned() == true))){
			HX_STACK_LINE(989)
			this->containingBlock->addAbsolutelyPositionedChildren(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(992)
			this->_wasAbsolutelyPositioned = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,registerWithContaininingBlock,(void))

Void ElementRenderer_obj::detachLayer( ){
{
		HX_STACK_PUSH("ElementRenderer::detachLayer","cocktail/core/renderer/ElementRenderer.hx",966);
		HX_STACK_THIS(this);
		HX_STACK_LINE(970)
		if (((this->_hasOwnLayer == true))){
			HX_STACK_LINE(972)
			this->parentNode->__Field(HX_CSTRING("layerRenderer"),true)->__Field(HX_CSTRING("removeChild"),true)(this->layerRenderer);
			HX_STACK_LINE(973)
			this->_hasOwnLayer = false;
			HX_STACK_LINE(974)
			this->layerRenderer->dispose();
		}
		HX_STACK_LINE(977)
		this->layerRenderer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,detachLayer,(void))

Void ElementRenderer_obj::attachLayer( ){
{
		HX_STACK_PUSH("ElementRenderer::attachLayer","cocktail/core/renderer/ElementRenderer.hx",954);
		HX_STACK_THIS(this);
		HX_STACK_LINE(954)
		if (((this->parentNode != null()))){
			HX_STACK_LINE(957)
			this->createLayer(this->parentNode->__Field(HX_CSTRING("layerRenderer"),true));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,attachLayer,(void))

Void ElementRenderer_obj::removedFromRenderingTree( ){
{
		HX_STACK_PUSH("ElementRenderer::removedFromRenderingTree","cocktail/core/renderer/ElementRenderer.hx",936);
		HX_STACK_THIS(this);
		HX_STACK_LINE(938)
		this->detach();
		HX_STACK_LINE(941)
		this->unregisterWithContainingBlock();
		HX_STACK_LINE(942)
		this->containingBlock = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,removedFromRenderingTree,(void))

Void ElementRenderer_obj::addedToRenderingTree( ){
{
		HX_STACK_PUSH("ElementRenderer::addedToRenderingTree","cocktail/core/renderer/ElementRenderer.hx",920);
		HX_STACK_THIS(this);
		HX_STACK_LINE(922)
		this->containingBlock = this->getContainingBlock();
		HX_STACK_LINE(923)
		this->registerWithContaininingBlock();
		HX_STACK_LINE(927)
		this->invalidateLayerRenderer();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,addedToRenderingTree,(void))

Void ElementRenderer_obj::updateInlineBoxes( ){
{
		HX_STACK_PUSH("ElementRenderer::updateInlineBoxes","cocktail/core/renderer/ElementRenderer.hx",905);
		HX_STACK_THIS(this);
		HX_STACK_LINE(906)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(907)
		while(((child != null()))){
			HX_STACK_LINE(909)
			child->updateInlineBoxes();
			HX_STACK_LINE(910)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateInlineBoxes,(void))

Void ElementRenderer_obj::updateAnonymousBlock( ){
{
		HX_STACK_PUSH("ElementRenderer::updateAnonymousBlock","cocktail/core/renderer/ElementRenderer.hx",890);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateAnonymousBlock,(void))

Void ElementRenderer_obj::detach( ){
{
		HX_STACK_PUSH("ElementRenderer::detach","cocktail/core/renderer/ElementRenderer.hx",863);
		HX_STACK_THIS(this);
		HX_STACK_LINE(865)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(866)
		while(((child != null()))){
			HX_STACK_LINE(868)
			child->detach();
			HX_STACK_LINE(869)
			child = child->nextSibling;
		}
		HX_STACK_LINE(872)
		if (((this->layerRenderer != null()))){
			HX_STACK_LINE(873)
			this->detachLayer();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,detach,(void))

Void ElementRenderer_obj::attach( ){
{
		HX_STACK_PUSH("ElementRenderer::attach","cocktail/core/renderer/ElementRenderer.hx",845);
		HX_STACK_THIS(this);
		HX_STACK_LINE(846)
		this->attachLayer();
		HX_STACK_LINE(850)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(851)
		while(((child != null()))){
			HX_STACK_LINE(853)
			child->attach();
			HX_STACK_LINE(854)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,attach,(void))

Void ElementRenderer_obj::updateLayerRenderer( ){
{
		HX_STACK_PUSH("ElementRenderer::updateLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",790);
		HX_STACK_THIS(this);
		HX_STACK_LINE(791)
		if (((this->_needsLayerRendererUpdate == true))){
			HX_STACK_LINE(794)
			this->_needsLayerRendererUpdate = false;
			HX_STACK_LINE(799)
			if (((this->layerRenderer == null()))){
				HX_STACK_LINE(801)
				this->attach();
				HX_STACK_LINE(805)
				return null();
			}
			else{
				HX_STACK_LINE(811)
				if (((this->_hasOwnLayer != this->createOwnLayer()))){
					HX_STACK_LINE(813)
					this->detach();
					HX_STACK_LINE(814)
					this->attach();
					HX_STACK_LINE(815)
					return null();
				}
				else{
					HX_STACK_LINE(821)
					if (((this->createOwnLayer() == true))){
						HX_STACK_LINE(823)
						this->parentNode->__Field(HX_CSTRING("layerRenderer"),true)->__Field(HX_CSTRING("insertBefore"),true)(this->layerRenderer,this->getNextLayerRenderer(this->parentNode->__Field(HX_CSTRING("layerRenderer"),true)->__Field(HX_CSTRING("rootElementRenderer"),true),hx::ObjectPtr<OBJ_>(this)));
					}
				}
			}
		}
		HX_STACK_LINE(832)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(833)
		while(((child != null()))){
			HX_STACK_LINE(835)
			child->updateLayerRenderer();
			HX_STACK_LINE(836)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateLayerRenderer,(void))

Void ElementRenderer_obj::getAdjoiningBottomMargins( Array< Float > adjoiningMargins){
{
		HX_STACK_PUSH("ElementRenderer::getAdjoiningBottomMargins","cocktail/core/renderer/ElementRenderer.hx",765);
		HX_STACK_THIS(this);
		HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,getAdjoiningBottomMargins,(void))

Void ElementRenderer_obj::getAdjoiningTopMargins( Array< Float > adjoiningMargins){
{
		HX_STACK_PUSH("ElementRenderer::getAdjoiningTopMargins","cocktail/core/renderer/ElementRenderer.hx",757);
		HX_STACK_THIS(this);
		HX_STACK_ARG(adjoiningMargins,"adjoiningMargins");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ElementRenderer_obj,getAdjoiningTopMargins,(void))

Float ElementRenderer_obj::getCollapsedBottomMargin( ){
	HX_STACK_PUSH("ElementRenderer::getCollapsedBottomMargin","cocktail/core/renderer/ElementRenderer.hx",748);
	HX_STACK_THIS(this);
	HX_STACK_LINE(748)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getCollapsedBottomMargin,return )

Float ElementRenderer_obj::getCollapsedTopMargin( ){
	HX_STACK_PUSH("ElementRenderer::getCollapsedTopMargin","cocktail/core/renderer/ElementRenderer.hx",739);
	HX_STACK_THIS(this);
	HX_STACK_LINE(739)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,getCollapsedTopMargin,return )

Void ElementRenderer_obj::setAbsolutelyPositionedGlobalOrigins( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float addedX,Float addedY,Float addedPositionedX,Float addedPositionedY){
{
		HX_STACK_PUSH("ElementRenderer::setAbsolutelyPositionedGlobalOrigins","cocktail/core/renderer/ElementRenderer.hx",675);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(addedX,"addedX");
		HX_STACK_ARG(addedY,"addedY");
		HX_STACK_ARG(addedPositionedX,"addedPositionedX");
		HX_STACK_ARG(addedPositionedY,"addedPositionedY");
		HX_STACK_LINE(676)
		::cocktail::core::css::CoreStyle elementRendererCoreStyle = elementRenderer->coreStyle;		HX_STACK_VAR(elementRendererCoreStyle,"elementRendererCoreStyle");
		HX_STACK_LINE(679)
		if ((elementRendererCoreStyle->isFixedPositioned)){
			HX_STACK_LINE(682)
			if (((bool((elementRendererCoreStyle->hasAutoLeft == true)) && bool((elementRendererCoreStyle->hasAutoRight == true))))){
				HX_STACK_LINE(683)
				elementRenderer->globalBounds->x = (addedX + elementRenderer->staticOrigin->x);
			}
			else{
				HX_STACK_LINE(689)
				elementRenderer->globalBounds->x = elementRenderer->bounds->x;
			}
			HX_STACK_LINE(693)
			if (((bool((elementRendererCoreStyle->hasAutoTop == true)) && bool((elementRendererCoreStyle->hasAutoBottom == true))))){
				HX_STACK_LINE(694)
				elementRenderer->globalBounds->y = (addedY + elementRenderer->staticOrigin->y);
			}
			else{
				HX_STACK_LINE(698)
				elementRenderer->globalBounds->y = elementRenderer->bounds->y;
			}
		}
		else{
			HX_STACK_LINE(706)
			if (((bool((elementRendererCoreStyle->hasAutoLeft == true)) && bool((elementRendererCoreStyle->hasAutoRight == true))))){
				HX_STACK_LINE(707)
				elementRenderer->globalBounds->x = (addedX + elementRenderer->staticOrigin->x);
			}
			else{
				HX_STACK_LINE(713)
				elementRenderer->globalBounds->x = (addedPositionedX + elementRenderer->bounds->x);
			}
			HX_STACK_LINE(718)
			if (((bool((elementRendererCoreStyle->hasAutoTop == true)) && bool((elementRendererCoreStyle->hasAutoBottom == true))))){
				HX_STACK_LINE(719)
				elementRenderer->globalBounds->y = (addedY + elementRenderer->staticOrigin->y);
			}
			else{
				HX_STACK_LINE(723)
				elementRenderer->globalBounds->y = (addedPositionedY + elementRenderer->bounds->y);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(ElementRenderer_obj,setAbsolutelyPositionedGlobalOrigins,(void))

Void ElementRenderer_obj::setGlobalOrigins( Float addedX,Float addedY,Float addedPositionedX,Float addedPositionedY){
{
		HX_STACK_PUSH("ElementRenderer::setGlobalOrigins","cocktail/core/renderer/ElementRenderer.hx",604);
		HX_STACK_THIS(this);
		HX_STACK_ARG(addedX,"addedX");
		HX_STACK_ARG(addedY,"addedY");
		HX_STACK_ARG(addedPositionedX,"addedPositionedX");
		HX_STACK_ARG(addedPositionedY,"addedPositionedY");
		HX_STACK_LINE(606)
		if (((this->isPositioned() == true))){
			HX_STACK_LINE(608)
			addedPositionedX = this->globalBounds->x;
			HX_STACK_LINE(609)
			addedPositionedY = this->globalBounds->y;
		}
		HX_STACK_LINE(612)
		if (((this->isBlockContainer == true))){
			HX_STACK_LINE(614)
			addedX = ((this->globalBounds->x + this->coreStyle->usedValues->paddingLeft) + this->coreStyle->usedValues->borderLeftWidth);
			HX_STACK_LINE(615)
			addedY = ((this->globalBounds->y + this->coreStyle->usedValues->paddingTop) + this->coreStyle->usedValues->borderTopWidth);
		}
		HX_STACK_LINE(619)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(620)
		while(((child != null()))){
			HX_STACK_LINE(623)
			if ((child->isAbsolutelyPositioned())){
				HX_STACK_LINE(624)
				this->setAbsolutelyPositionedGlobalOrigins(child,addedX,addedY,addedPositionedX,addedPositionedY);
			}
			else{
				HX_STACK_LINE(630)
				child->globalBounds->x = addedX;
				HX_STACK_LINE(631)
				child->globalBounds->y = addedY;
				HX_STACK_LINE(637)
				if (((bool((child->isInlineLevel() == false)) || bool((child->isReplaced == true))))){
					HX_STACK_LINE(639)
					hx::AddEq(child->globalBounds->x,child->bounds->x);
					HX_STACK_LINE(640)
					hx::AddEq(child->globalBounds->y,child->bounds->y);
				}
				else{
					HX_STACK_LINE(645)
					if (((child->isBlockContainer == true))){
						HX_STACK_LINE(647)
						hx::AddEq(child->globalBounds->x,child->bounds->x);
						HX_STACK_LINE(648)
						hx::AddEq(child->globalBounds->y,child->bounds->y);
					}
				}
			}
			HX_STACK_LINE(653)
			child->globalBounds->width = child->bounds->width;
			HX_STACK_LINE(654)
			child->globalBounds->height = child->bounds->height;
			HX_STACK_LINE(657)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(658)
				child->setGlobalOrigins(addedX,addedY,addedPositionedX,addedPositionedY);
			}
			HX_STACK_LINE(662)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ElementRenderer_obj,setGlobalOrigins,(void))

Void ElementRenderer_obj::layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("ElementRenderer::layout","cocktail/core/renderer/ElementRenderer.hx",590);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_ARG(layoutState,"layoutState");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ElementRenderer_obj,layout,(void))

Void ElementRenderer_obj::invalidateLayerRenderer( ){
{
		HX_STACK_PUSH("ElementRenderer::invalidateLayerRenderer","cocktail/core/renderer/ElementRenderer.hx",567);
		HX_STACK_THIS(this);
		HX_STACK_LINE(568)
		this->_needsLayerRendererUpdate = true;
		HX_STACK_LINE(570)
		switch( (int)(this->domNode->get_nodeType())){
			case (int)1: case (int)3: {
				HX_STACK_LINE(573)
				::cocktail::core::html::HTMLDocument htmlDocument = this->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
				HX_STACK_LINE(574)
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
		HX_STACK_PUSH("ElementRenderer::updateTextDecorations","cocktail/core/renderer/ElementRenderer.hx",486);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inheritUnderline,"inheritUnderline");
		HX_STACK_ARG(inheritOverline,"inheritOverline");
		HX_STACK_ARG(inheritLineThrough,"inheritLineThrough");
		HX_STACK_ARG(inheritBlink,"inheritBlink");
		HX_STACK_LINE(489)
		{
			::cocktail::core::css::CSSPropertyValue _switch_1 = (this->coreStyle->getComputedOrInitialProperty((int)86));
			switch((_switch_1)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
						HX_STACK_LINE(491)
						{
							::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
							switch((_switch_2)->GetIndex()){
								case 84: {
									HX_STACK_LINE(494)
									inheritUnderline = true;
								}
								;break;
								case 85: {
									HX_STACK_LINE(497)
									inheritOverline = true;
								}
								;break;
								case 86: {
									HX_STACK_LINE(500)
									inheritLineThrough = true;
								}
								;break;
								case 87: {
									HX_STACK_LINE(503)
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
						HX_STACK_LINE(510)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						int _g = value->length;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(510)
						while(((_g1 < _g))){
							HX_STACK_LINE(510)
							int i = (_g1)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(512)
							{
								::cocktail::core::css::CSSPropertyValue _switch_3 = (value->__get(i));
								switch((_switch_3)->GetIndex()){
									case 4: {
										::cocktail::core::css::CSSKeywordValue value1 = _switch_3->__Param(0);
{
											HX_STACK_LINE(514)
											{
												::cocktail::core::css::CSSKeywordValue _switch_4 = (value1);
												switch((_switch_4)->GetIndex()){
													case 84: {
														HX_STACK_LINE(517)
														inheritUnderline = true;
													}
													;break;
													case 85: {
														HX_STACK_LINE(520)
														inheritOverline = true;
													}
													;break;
													case 86: {
														HX_STACK_LINE(523)
														inheritLineThrough = true;
													}
													;break;
													case 87: {
														HX_STACK_LINE(526)
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
		HX_STACK_LINE(540)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(541)
		while(((child != null()))){
			HX_STACK_LINE(544)
			if (((bool((bool((child->coreStyle->isFloat == true)) || bool((child->coreStyle->isAbsolutelyPositioned == true)))) || bool((child->coreStyle->isInlineBlock == true))))){
				HX_STACK_LINE(545)
				child->updateTextDecorations(false,false,false,false);
			}
			else{
				HX_STACK_LINE(549)
				child->updateTextDecorations(inheritUnderline,inheritOverline,inheritLineThrough,inheritBlink);
			}
			HX_STACK_LINE(552)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(ElementRenderer_obj,updateTextDecorations,(void))

Void ElementRenderer_obj::updateText( ){
{
		HX_STACK_PUSH("ElementRenderer::updateText","cocktail/core/renderer/ElementRenderer.hx",459);
		HX_STACK_THIS(this);
		HX_STACK_LINE(460)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(461)
		while(((child != null()))){
			HX_STACK_LINE(463)
			child->updateText();
			HX_STACK_LINE(464)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ElementRenderer_obj,updateText,(void))

Void ElementRenderer_obj::render( ::cocktail::core::graphics::GraphicsContext parentGraphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("ElementRenderer::render","cocktail/core/renderer/ElementRenderer.hx",450);
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
		HX_STACK_LINE(401)
		if (((bool((this->coreStyle->isInline == true)) || bool((this->isText == true))))){
			HX_STACK_LINE(403)
			hx::AddEq(this->hitTestingBounds->x,this->bounds->x);
			HX_STACK_LINE(404)
			hx::AddEq(this->hitTestingBounds->y,this->bounds->y);
		}
		HX_STACK_LINE(409)
		::cocktail::core::geom::PointVO scrollOffset = this->layerRenderer->scrollOffset;		HX_STACK_VAR(scrollOffset,"scrollOffset");
		HX_STACK_LINE(410)
		hx::SubEq(this->hitTestingBounds->x,scrollOffset->x);
		HX_STACK_LINE(411)
		hx::SubEq(this->hitTestingBounds->y,scrollOffset->y);
		HX_STACK_LINE(415)
		::cocktail::core::geom::Matrix matrix = this->layerRenderer->matrix;		HX_STACK_VAR(matrix,"matrix");
		HX_STACK_LINE(416)
		hx::AddEq(this->hitTestingBounds->x,matrix->e);
		HX_STACK_LINE(417)
		hx::AddEq(this->hitTestingBounds->y,matrix->f);
		HX_STACK_LINE(422)
		if (((this->_hasOwnLayer == true))){
			HX_STACK_LINE(424)
			hx::AddEq(this->hitTestingBounds->x,this->layerRenderer->scrollLeft);
			HX_STACK_LINE(425)
			hx::AddEq(this->hitTestingBounds->y,this->layerRenderer->scrollTop);
		}
		HX_STACK_LINE(430)
		{
			HX_STACK_LINE(430)
			::cocktail::core::geom::RectangleVO bounds1 = this->layerRenderer->clipRect;		HX_STACK_VAR(bounds1,"bounds1");
			::cocktail::core::geom::RectangleVO bounds2 = this->hitTestingBounds;		HX_STACK_VAR(bounds2,"bounds2");
			::cocktail::core::geom::RectangleVO resultBounds = this->hitTestingBounds;		HX_STACK_VAR(resultBounds,"resultBounds");
			HX_STACK_LINE(430)
			if (((bool((bool((bool(((bounds1->x + bounds1->width) < bounds2->x)) || bool(((bounds2->x + bounds2->width) < bounds1->x)))) || bool(((bounds1->y + bounds1->height) < bounds2->y)))) || bool(((bounds2->y + bounds2->height) < bounds1->y))))){
				HX_STACK_LINE(430)
				resultBounds->x = (int)0;
				HX_STACK_LINE(430)
				resultBounds->y = (int)0;
				HX_STACK_LINE(430)
				resultBounds->height = (int)0;
				HX_STACK_LINE(430)
				resultBounds->width = (int)0;
			}
			else{
				HX_STACK_LINE(430)
				Float left = (int)0;		HX_STACK_VAR(left,"left");
				HX_STACK_LINE(430)
				Float right = (int)0;		HX_STACK_VAR(right,"right");
				HX_STACK_LINE(430)
				Float top = (int)0;		HX_STACK_VAR(top,"top");
				HX_STACK_LINE(430)
				Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
				HX_STACK_LINE(430)
				if (((bounds1->x < bounds2->x))){
					HX_STACK_LINE(430)
					left = bounds2->x;
				}
				else{
					HX_STACK_LINE(430)
					left = bounds1->x;
				}
				HX_STACK_LINE(430)
				if ((((bounds1->x + bounds1->width) < (bounds2->x + bounds2->width)))){
					HX_STACK_LINE(430)
					right = (bounds1->x + bounds1->width);
				}
				else{
					HX_STACK_LINE(430)
					right = (bounds2->x + bounds2->width);
				}
				HX_STACK_LINE(430)
				if (((bounds1->y < bounds2->y))){
					HX_STACK_LINE(430)
					top = bounds2->y;
				}
				else{
					HX_STACK_LINE(430)
					top = bounds1->y;
				}
				HX_STACK_LINE(430)
				if ((((bounds1->y + bounds1->height) < (bounds2->y + bounds2->height)))){
					HX_STACK_LINE(430)
					bottom = (bounds1->y + bounds1->height);
				}
				else{
					HX_STACK_LINE(430)
					bottom = (bounds2->y + bounds2->height);
				}
				HX_STACK_LINE(430)
				resultBounds->x = left;
				HX_STACK_LINE(430)
				resultBounds->y = top;
				HX_STACK_LINE(430)
				resultBounds->width = (right - left);
				HX_STACK_LINE(430)
				resultBounds->height = (bottom - top);
			}
		}
		HX_STACK_LINE(433)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(434)
		while(((child != null()))){
			HX_STACK_LINE(436)
			child->updateHitTestingBounds();
			HX_STACK_LINE(437)
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
