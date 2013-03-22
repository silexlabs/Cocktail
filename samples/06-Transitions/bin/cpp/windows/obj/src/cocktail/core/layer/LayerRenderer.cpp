#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
#endif
#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
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
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
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
#ifndef INCLUDED_cocktail_core_layout_computer_VisualEffectStylesComputer
#include <cocktail/core/layout/computer/VisualEffectStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_stacking_StackingContext
#include <cocktail/core/stacking/StackingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
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
namespace cocktail{
namespace core{
namespace layer{

Void LayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("LayerRenderer::new","cocktail/core/layer/LayerRenderer.hx",172);
{
	HX_STACK_LINE(173)
	super::__construct(rootElementRenderer);
	HX_STACK_LINE(175)
	this->hasOwnGraphicsContext = false;
	HX_STACK_LINE(176)
	this->hasOwnStackingContext = false;
	HX_STACK_LINE(178)
	this->_needsGraphicsContextUpdate = true;
	HX_STACK_LINE(179)
	this->_needsStackingContextUpdate = true;
	HX_STACK_LINE(180)
	this->_canUpdateScrollRegion = false;
	HX_STACK_LINE(182)
	this->matrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(183)
	this->_currentMatrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(184)
	this->_relativeOffset = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(185)
	this->_layerDirtyRect = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(186)
	this->alpha = 1.0;
}
;
	return null();
}

LayerRenderer_obj::~LayerRenderer_obj() { }

Dynamic LayerRenderer_obj::__CreateEmpty() { return  new LayerRenderer_obj; }
hx::ObjectPtr< LayerRenderer_obj > LayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< LayerRenderer_obj > result = new LayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic LayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LayerRenderer_obj > result = new LayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void LayerRenderer_obj::dispatchScrollEvent( Float timestamp){
{
		HX_STACK_PUSH("LayerRenderer::dispatchScrollEvent","cocktail/core/layer/LayerRenderer.hx",1495);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timestamp,"timestamp");
		HX_STACK_LINE(1496)
		::cocktail::core::event::UIEvent scrollEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(scrollEvent,"scrollEvent");
		HX_STACK_LINE(1498)
		scrollEvent->initEvent(HX_CSTRING("scroll"),false,false);
		HX_STACK_LINE(1501)
		if (((this->rootElementRenderer != null()))){
			HX_STACK_LINE(1502)
			if (((this->rootElementRenderer->domNode != null()))){
				HX_STACK_LINE(1504)
				this->rootElementRenderer->domNode->dispatchEvent(scrollEvent);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,dispatchScrollEvent,(void))

bool LayerRenderer_obj::establishesNewStackingContext( ){
	HX_STACK_PUSH("LayerRenderer::establishesNewStackingContext","cocktail/core/layer/LayerRenderer.hx",1462);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1465)
	if (((this->rootElementRenderer->isPositioned() == false))){
		HX_STACK_LINE(1466)
		return false;
	}
	HX_STACK_LINE(1472)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (this->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
		switch((_switch_1)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(1474)
					if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
						HX_STACK_LINE(1476)
						return false;
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1483)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,establishesNewStackingContext,return )

::cocktail::core::geom::PointVO LayerRenderer_obj::getRelativeOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer){
	HX_STACK_PUSH("LayerRenderer::getRelativeOffset","cocktail/core/layer/LayerRenderer.hx",1412);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementRenderer,"elementRenderer");
	HX_STACK_LINE(1413)
	this->_relativeOffset->x = (int)0;
	HX_STACK_LINE(1414)
	this->_relativeOffset->y = (int)0;
	HX_STACK_LINE(1418)
	if (((elementRenderer->isRelativePositioned() == true))){
		HX_STACK_LINE(1422)
		if (((elementRenderer->coreStyle->hasAutoLeft == false))){
			HX_STACK_LINE(1423)
			hx::AddEq(this->_relativeOffset->x,elementRenderer->coreStyle->usedValues->left);
		}
		else{
			HX_STACK_LINE(1427)
			if (((elementRenderer->coreStyle->hasAutoRight == false))){
				HX_STACK_LINE(1428)
				hx::SubEq(this->_relativeOffset->x,elementRenderer->coreStyle->usedValues->right);
			}
		}
		HX_STACK_LINE(1437)
		if (((elementRenderer->coreStyle->hasAutoTop == false))){
			HX_STACK_LINE(1438)
			hx::AddEq(this->_relativeOffset->y,elementRenderer->coreStyle->usedValues->top);
		}
		else{
			HX_STACK_LINE(1441)
			if (((elementRenderer->coreStyle->hasAutoBottom == false))){
				HX_STACK_LINE(1442)
				hx::SubEq(this->_relativeOffset->y,elementRenderer->coreStyle->usedValues->bottom);
			}
		}
	}
	HX_STACK_LINE(1447)
	return this->_relativeOffset;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getRelativeOffset,return )

Void LayerRenderer_obj::getConcatenatedMatrix( ::cocktail::core::geom::Matrix matrix,::cocktail::core::geom::PointVO relativeOffset){
{
		HX_STACK_PUSH("LayerRenderer::getConcatenatedMatrix","cocktail/core/layer/LayerRenderer.hx",1394);
		HX_STACK_THIS(this);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(relativeOffset,"relativeOffset");
		HX_STACK_LINE(1395)
		::cocktail::core::geom::RectangleVO globalBounds = this->rootElementRenderer->globalBounds;		HX_STACK_VAR(globalBounds,"globalBounds");
		HX_STACK_LINE(1398)
		this->_currentMatrix->translate((globalBounds->x + relativeOffset->x),(globalBounds->y + relativeOffset->y));
		HX_STACK_LINE(1400)
		this->_currentMatrix->concatenate(matrix);
		HX_STACK_LINE(1403)
		this->_currentMatrix->translate((((globalBounds->x + relativeOffset->x)) * (int)-1),(((globalBounds->y + relativeOffset->y)) * (int)-1));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(LayerRenderer_obj,getConcatenatedMatrix,(void))

::cocktail::core::geom::Matrix LayerRenderer_obj::getTransformationMatrix( ){
	HX_STACK_PUSH("LayerRenderer::getTransformationMatrix","cocktail/core/layer/LayerRenderer.hx",1370);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1371)
	::cocktail::core::geom::PointVO relativeOffset = this->getRelativeOffset(this->rootElementRenderer);		HX_STACK_VAR(relativeOffset,"relativeOffset");
	HX_STACK_LINE(1373)
	this->_currentMatrix->identity();
	HX_STACK_LINE(1376)
	if (((this->rootElementRenderer->hasCSSTransform() == true))){
		HX_STACK_LINE(1377)
		this->getConcatenatedMatrix(this->rootElementRenderer->coreStyle->usedValues->transform,relativeOffset);
	}
	HX_STACK_LINE(1382)
	this->_currentMatrix->translate(relativeOffset->x,relativeOffset->y);
	HX_STACK_LINE(1384)
	return this->_currentMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,getTransformationMatrix,return )

Void LayerRenderer_obj::doClear( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("LayerRenderer::doClear","cocktail/core/layer/LayerRenderer.hx",1361);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(1361)
		this->graphicsContext->graphics->clear(x,y,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(LayerRenderer_obj,doClear,(void))

Void LayerRenderer_obj::updateScrollRegion( ::cocktail::core::geom::RectangleVO dirtyRect){
{
		HX_STACK_PUSH("LayerRenderer::updateScrollRegion","cocktail/core/layer/LayerRenderer.hx",1224);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dirtyRect,"dirtyRect");
		HX_STACK_LINE(1227)
		if (((this->_canUpdateScrollRegion == true))){
			HX_STACK_LINE(1231)
			Float leftScrollOffset = (this->scrollOffset->x - this->_previousScrollOffsetX);		HX_STACK_VAR(leftScrollOffset,"leftScrollOffset");
			HX_STACK_LINE(1232)
			Float topScrollOffset = (this->scrollOffset->y - this->_previousScrollOffsetY);		HX_STACK_VAR(topScrollOffset,"topScrollOffset");
			HX_STACK_LINE(1236)
			::cocktail::core::geom::RectangleVO copyRect = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(copyRect,"copyRect");
			HX_STACK_LINE(1237)
			copyRect->x = this->clipRect->x;
			HX_STACK_LINE(1238)
			copyRect->y = this->clipRect->y;
			HX_STACK_LINE(1239)
			copyRect->width = this->clipRect->width;
			HX_STACK_LINE(1240)
			copyRect->height = this->clipRect->height;
			HX_STACK_LINE(1243)
			::cocktail::core::geom::PointVO copyDestination = ::cocktail::core::geom::PointVO_obj::__new(this->clipRect->x,this->clipRect->y);		HX_STACK_VAR(copyDestination,"copyDestination");
			HX_STACK_LINE(1248)
			if (((topScrollOffset != (int)0))){
				HX_STACK_LINE(1252)
				hx::SubEq(copyRect->height,::Math_obj::abs(topScrollOffset));
				HX_STACK_LINE(1257)
				if (((topScrollOffset > (int)0))){
					HX_STACK_LINE(1258)
					hx::AddEq(copyRect->y,topScrollOffset);
				}
				else{
					HX_STACK_LINE(1262)
					hx::SubEq(copyDestination->y,topScrollOffset);
				}
				HX_STACK_LINE(1268)
				::cocktail::core::geom::RectangleVO scrollTopRect = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(scrollTopRect,"scrollTopRect");
				HX_STACK_LINE(1269)
				scrollTopRect->width = this->clipRect->width;
				HX_STACK_LINE(1270)
				scrollTopRect->height = ::Math_obj::abs(topScrollOffset);
				HX_STACK_LINE(1271)
				scrollTopRect->x = this->clipRect->x;
				HX_STACK_LINE(1274)
				if (((topScrollOffset > (int)0))){
					HX_STACK_LINE(1275)
					scrollTopRect->y = ((this->clipRect->y + this->clipRect->height) - topScrollOffset);
				}
				else{
					HX_STACK_LINE(1279)
					scrollTopRect->y = this->clipRect->y;
				}
				HX_STACK_LINE(1285)
				if (((bool((dirtyRect->width == (int)0)) && bool((dirtyRect->height == (int)0))))){
					HX_STACK_LINE(1288)
					dirtyRect->x = scrollTopRect->x;
					HX_STACK_LINE(1289)
					dirtyRect->y = scrollTopRect->y;
					HX_STACK_LINE(1290)
					dirtyRect->width = scrollTopRect->width;
					HX_STACK_LINE(1291)
					dirtyRect->height = scrollTopRect->height;
				}
				else{
					HX_STACK_LINE(1294)
					if (((bool((bool((bool(((dirtyRect->x + dirtyRect->width) < scrollTopRect->x)) || bool(((scrollTopRect->x + scrollTopRect->width) < dirtyRect->x)))) || bool(((dirtyRect->y + dirtyRect->height) < scrollTopRect->y)))) || bool(((scrollTopRect->y + scrollTopRect->height) < dirtyRect->y))))){
						HX_STACK_LINE(1295)
						dirtyRect->x = (int)0;
						HX_STACK_LINE(1295)
						dirtyRect->y = (int)0;
						HX_STACK_LINE(1295)
						dirtyRect->height = (int)0;
						HX_STACK_LINE(1295)
						dirtyRect->width = (int)0;
					}
					else{
						HX_STACK_LINE(1295)
						Float left = (int)0;		HX_STACK_VAR(left,"left");
						HX_STACK_LINE(1295)
						Float right = (int)0;		HX_STACK_VAR(right,"right");
						HX_STACK_LINE(1295)
						Float top = (int)0;		HX_STACK_VAR(top,"top");
						HX_STACK_LINE(1295)
						Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
						HX_STACK_LINE(1295)
						if (((dirtyRect->x < scrollTopRect->x))){
							HX_STACK_LINE(1295)
							left = scrollTopRect->x;
						}
						else{
							HX_STACK_LINE(1295)
							left = dirtyRect->x;
						}
						HX_STACK_LINE(1295)
						if ((((dirtyRect->x + dirtyRect->width) < (scrollTopRect->x + scrollTopRect->width)))){
							HX_STACK_LINE(1295)
							right = (dirtyRect->x + dirtyRect->width);
						}
						else{
							HX_STACK_LINE(1295)
							right = (scrollTopRect->x + scrollTopRect->width);
						}
						HX_STACK_LINE(1295)
						if (((dirtyRect->y < scrollTopRect->y))){
							HX_STACK_LINE(1295)
							top = scrollTopRect->y;
						}
						else{
							HX_STACK_LINE(1295)
							top = dirtyRect->y;
						}
						HX_STACK_LINE(1295)
						if ((((dirtyRect->y + dirtyRect->height) < (scrollTopRect->y + scrollTopRect->height)))){
							HX_STACK_LINE(1295)
							bottom = (dirtyRect->y + dirtyRect->height);
						}
						else{
							HX_STACK_LINE(1295)
							bottom = (scrollTopRect->y + scrollTopRect->height);
						}
						HX_STACK_LINE(1295)
						dirtyRect->x = left;
						HX_STACK_LINE(1295)
						dirtyRect->y = top;
						HX_STACK_LINE(1295)
						dirtyRect->width = (right - left);
						HX_STACK_LINE(1295)
						dirtyRect->height = (bottom - top);
					}
				}
			}
			HX_STACK_LINE(1300)
			if (((leftScrollOffset != (int)0))){
				HX_STACK_LINE(1302)
				hx::SubEq(copyRect->width,::Math_obj::abs(leftScrollOffset));
				HX_STACK_LINE(1304)
				if (((leftScrollOffset > (int)0))){
					HX_STACK_LINE(1305)
					hx::AddEq(copyRect->x,leftScrollOffset);
				}
				else{
					HX_STACK_LINE(1309)
					hx::SubEq(copyDestination->x,leftScrollOffset);
				}
				HX_STACK_LINE(1313)
				::cocktail::core::geom::RectangleVO scrollLeftRect = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(scrollLeftRect,"scrollLeftRect");
				HX_STACK_LINE(1314)
				scrollLeftRect->width = ::Math_obj::abs(leftScrollOffset);
				HX_STACK_LINE(1315)
				scrollLeftRect->height = this->clipRect->height;
				HX_STACK_LINE(1316)
				scrollLeftRect->y = this->clipRect->y;
				HX_STACK_LINE(1318)
				if (((leftScrollOffset > (int)0))){
					HX_STACK_LINE(1319)
					scrollLeftRect->x = ((this->clipRect->x + this->clipRect->width) - leftScrollOffset);
				}
				else{
					HX_STACK_LINE(1323)
					scrollLeftRect->x = this->clipRect->x;
				}
				HX_STACK_LINE(1327)
				if (((bool((dirtyRect->width == (int)0)) && bool((dirtyRect->height == (int)0))))){
					HX_STACK_LINE(1329)
					dirtyRect->x = scrollLeftRect->x;
					HX_STACK_LINE(1330)
					dirtyRect->y = scrollLeftRect->y;
					HX_STACK_LINE(1331)
					dirtyRect->width = scrollLeftRect->width;
					HX_STACK_LINE(1332)
					dirtyRect->height = scrollLeftRect->height;
				}
				else{
					HX_STACK_LINE(1335)
					if (((bool((bool((bool(((dirtyRect->x + dirtyRect->width) < scrollLeftRect->x)) || bool(((scrollLeftRect->x + scrollLeftRect->width) < dirtyRect->x)))) || bool(((dirtyRect->y + dirtyRect->height) < scrollLeftRect->y)))) || bool(((scrollLeftRect->y + scrollLeftRect->height) < dirtyRect->y))))){
						HX_STACK_LINE(1336)
						dirtyRect->x = (int)0;
						HX_STACK_LINE(1336)
						dirtyRect->y = (int)0;
						HX_STACK_LINE(1336)
						dirtyRect->height = (int)0;
						HX_STACK_LINE(1336)
						dirtyRect->width = (int)0;
					}
					else{
						HX_STACK_LINE(1336)
						Float left = (int)0;		HX_STACK_VAR(left,"left");
						HX_STACK_LINE(1336)
						Float right = (int)0;		HX_STACK_VAR(right,"right");
						HX_STACK_LINE(1336)
						Float top = (int)0;		HX_STACK_VAR(top,"top");
						HX_STACK_LINE(1336)
						Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
						HX_STACK_LINE(1336)
						if (((dirtyRect->x < scrollLeftRect->x))){
							HX_STACK_LINE(1336)
							left = scrollLeftRect->x;
						}
						else{
							HX_STACK_LINE(1336)
							left = dirtyRect->x;
						}
						HX_STACK_LINE(1336)
						if ((((dirtyRect->x + dirtyRect->width) < (scrollLeftRect->x + scrollLeftRect->width)))){
							HX_STACK_LINE(1336)
							right = (dirtyRect->x + dirtyRect->width);
						}
						else{
							HX_STACK_LINE(1336)
							right = (scrollLeftRect->x + scrollLeftRect->width);
						}
						HX_STACK_LINE(1336)
						if (((dirtyRect->y < scrollLeftRect->y))){
							HX_STACK_LINE(1336)
							top = scrollLeftRect->y;
						}
						else{
							HX_STACK_LINE(1336)
							top = dirtyRect->y;
						}
						HX_STACK_LINE(1336)
						if ((((dirtyRect->y + dirtyRect->height) < (scrollLeftRect->y + scrollLeftRect->height)))){
							HX_STACK_LINE(1336)
							bottom = (dirtyRect->y + dirtyRect->height);
						}
						else{
							HX_STACK_LINE(1336)
							bottom = (scrollLeftRect->y + scrollLeftRect->height);
						}
						HX_STACK_LINE(1336)
						dirtyRect->x = left;
						HX_STACK_LINE(1336)
						dirtyRect->y = top;
						HX_STACK_LINE(1336)
						dirtyRect->width = (right - left);
						HX_STACK_LINE(1336)
						dirtyRect->height = (bottom - top);
					}
				}
			}
			HX_STACK_LINE(1341)
			this->graphicsContext->graphics->copyRect(copyRect,copyDestination->x,copyDestination->y);
			HX_STACK_LINE(1342)
			this->_canUpdateScrollRegion = false;
		}
		HX_STACK_LINE(1345)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(1346)
		while(((child != null()))){
			HX_STACK_LINE(1348)
			child->updateScrollRegion(dirtyRect);
			HX_STACK_LINE(1349)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,updateScrollRegion,(void))

Void LayerRenderer_obj::render( ::cocktail::core::geom::RectangleVO dirtyRect){
{
		HX_STACK_PUSH("LayerRenderer::render","cocktail/core/layer/LayerRenderer.hx",1171);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dirtyRect,"dirtyRect");
		HX_STACK_LINE(1173)
		if (((this->alpha == (int)0))){
			HX_STACK_LINE(1174)
			return null();
		}
		HX_STACK_LINE(1180)
		{
			HX_STACK_LINE(1180)
			::cocktail::core::geom::RectangleVO bounds2 = this->clipRect;		HX_STACK_VAR(bounds2,"bounds2");
			::cocktail::core::geom::RectangleVO resultBounds = this->_layerDirtyRect;		HX_STACK_VAR(resultBounds,"resultBounds");
			HX_STACK_LINE(1180)
			if (((bool((bool((bool(((dirtyRect->x + dirtyRect->width) < bounds2->x)) || bool(((bounds2->x + bounds2->width) < dirtyRect->x)))) || bool(((dirtyRect->y + dirtyRect->height) < bounds2->y)))) || bool(((bounds2->y + bounds2->height) < dirtyRect->y))))){
				HX_STACK_LINE(1180)
				resultBounds->x = (int)0;
				HX_STACK_LINE(1180)
				resultBounds->y = (int)0;
				HX_STACK_LINE(1180)
				resultBounds->height = (int)0;
				HX_STACK_LINE(1180)
				resultBounds->width = (int)0;
			}
			else{
				HX_STACK_LINE(1180)
				Float left = (int)0;		HX_STACK_VAR(left,"left");
				HX_STACK_LINE(1180)
				Float right = (int)0;		HX_STACK_VAR(right,"right");
				HX_STACK_LINE(1180)
				Float top = (int)0;		HX_STACK_VAR(top,"top");
				HX_STACK_LINE(1180)
				Float bottom = (int)0;		HX_STACK_VAR(bottom,"bottom");
				HX_STACK_LINE(1180)
				if (((dirtyRect->x < bounds2->x))){
					HX_STACK_LINE(1180)
					left = bounds2->x;
				}
				else{
					HX_STACK_LINE(1180)
					left = dirtyRect->x;
				}
				HX_STACK_LINE(1180)
				if ((((dirtyRect->x + dirtyRect->width) < (bounds2->x + bounds2->width)))){
					HX_STACK_LINE(1180)
					right = (dirtyRect->x + dirtyRect->width);
				}
				else{
					HX_STACK_LINE(1180)
					right = (bounds2->x + bounds2->width);
				}
				HX_STACK_LINE(1180)
				if (((dirtyRect->y < bounds2->y))){
					HX_STACK_LINE(1180)
					top = bounds2->y;
				}
				else{
					HX_STACK_LINE(1180)
					top = dirtyRect->y;
				}
				HX_STACK_LINE(1180)
				if ((((dirtyRect->y + dirtyRect->height) < (bounds2->y + bounds2->height)))){
					HX_STACK_LINE(1180)
					bottom = (dirtyRect->y + dirtyRect->height);
				}
				else{
					HX_STACK_LINE(1180)
					bottom = (bounds2->y + bounds2->height);
				}
				HX_STACK_LINE(1180)
				resultBounds->x = left;
				HX_STACK_LINE(1180)
				resultBounds->y = top;
				HX_STACK_LINE(1180)
				resultBounds->width = (right - left);
				HX_STACK_LINE(1180)
				resultBounds->height = (bottom - top);
			}
		}
		HX_STACK_LINE(1184)
		if (((bool((this->_layerDirtyRect->width == (int)0)) || bool((this->_layerDirtyRect->height == (int)0))))){
			HX_STACK_LINE(1185)
			return null();
		}
		HX_STACK_LINE(1191)
		if (((this->alpha != 1.0))){
			HX_STACK_LINE(1192)
			this->graphicsContext->graphics->beginTransparency(this->alpha);
		}
		HX_STACK_LINE(1198)
		this->graphicsContext->graphics->beginTransformations(this->matrix);
		HX_STACK_LINE(1202)
		this->rootElementRenderer->render(this->graphicsContext,this->_layerDirtyRect,this->scrollOffset);
		HX_STACK_LINE(1205)
		this->graphicsContext->graphics->endTransformations();
		HX_STACK_LINE(1208)
		if (((this->alpha != 1.0))){
			HX_STACK_LINE(1209)
			this->graphicsContext->graphics->endTransparency();
		}
		HX_STACK_LINE(1213)
		this->_canUpdateScrollRegion = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,render,(void))

Void LayerRenderer_obj::clear( Float x,Float y,Float width,Float height){
{
		HX_STACK_PUSH("LayerRenderer::clear","cocktail/core/layer/LayerRenderer.hx",1148);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(1149)
		if (((this->hasOwnGraphicsContext == true))){
			HX_STACK_LINE(1150)
			this->doClear(x,y,width,height);
		}
		HX_STACK_LINE(1154)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(1155)
		while(((child != null()))){
			HX_STACK_LINE(1157)
			child->clear(x,y,width,height);
			HX_STACK_LINE(1158)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(LayerRenderer_obj,clear,(void))

Void LayerRenderer_obj::scrollChanged( ){
{
		HX_STACK_PUSH("LayerRenderer::scrollChanged","cocktail/core/layer/LayerRenderer.hx",1127);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1128)
		::cocktail::core::html::HTMLDocument htmlDocument = this->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(1129)
		htmlDocument->invalidationManager->invalidateRendering(this->clipRect);
		HX_STACK_LINE(1130)
		this->_canUpdateScrollRegion = true;
		HX_STACK_LINE(1134)
		htmlDocument->timer->delay(this->dispatchScrollEvent_dyn(),null());
	}
return null();
}


Void LayerRenderer_obj::updateBounds( ){
{
		HX_STACK_PUSH("LayerRenderer::updateBounds","cocktail/core/layer/LayerRenderer.hx",1112);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1113)
		this->super::updateBounds();
		HX_STACK_LINE(1114)
		hx::AddEq(this->bounds->x,this->matrix->e);
		HX_STACK_LINE(1115)
		hx::AddEq(this->bounds->y,this->matrix->f);
	}
return null();
}


bool LayerRenderer_obj::needsBitmap( ){
	HX_STACK_PUSH("LayerRenderer::needsBitmap","cocktail/core/layer/LayerRenderer.hx",1095);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1095)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,needsBitmap,return )

bool LayerRenderer_obj::isCompositingLayer( ){
	HX_STACK_PUSH("LayerRenderer::isCompositingLayer","cocktail/core/layer/LayerRenderer.hx",1086);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1086)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,isCompositingLayer,return )

bool LayerRenderer_obj::hasZeroOrAutoCompositingLayerSibling( ::cocktail::core::layer::LayerRenderer rootLayer,::cocktail::core::layer::LayerRenderer referenceLayer){
	HX_STACK_PUSH("LayerRenderer::hasZeroOrAutoCompositingLayerSibling","cocktail/core/layer/LayerRenderer.hx",1019);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootLayer,"rootLayer");
	HX_STACK_ARG(referenceLayer,"referenceLayer");
	HX_STACK_LINE(1020)
	::cocktail::core::layer::LayerRenderer child = rootLayer->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(1021)
	while(((child != null()))){
		HX_STACK_LINE(1024)
		if (((child->hasOwnStackingContext == false))){
			HX_STACK_LINE(1030)
			if (((child == referenceLayer))){
				HX_STACK_LINE(1031)
				return false;
			}
			HX_STACK_LINE(1035)
			if (((bool((child->isCompositingLayer() == true)) || bool((child->hasOwnGraphicsContext == true))))){
				HX_STACK_LINE(1036)
				return true;
			}
			HX_STACK_LINE(1041)
			bool ret = this->hasZeroOrAutoCompositingLayerSibling(child,referenceLayer);		HX_STACK_VAR(ret,"ret");
			HX_STACK_LINE(1042)
			if (((ret == true))){
				HX_STACK_LINE(1043)
				return true;
			}
		}
		else{
			HX_STACK_LINE(1049)
			{
				::cocktail::core::css::CSSPropertyValue _switch_2 = (child->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
				switch((_switch_2)->GetIndex()){
					case 0: {
						int value = _switch_2->__Param(0);
{
							HX_STACK_LINE(1052)
							if (((value == (int)0))){
								HX_STACK_LINE(1055)
								if (((child == referenceLayer))){
									HX_STACK_LINE(1056)
									return false;
								}
								HX_STACK_LINE(1060)
								if (((bool((child->isCompositingLayer() == true)) || bool((child->hasOwnGraphicsContext == true))))){
									HX_STACK_LINE(1061)
									return true;
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
		HX_STACK_LINE(1069)
		child = child->nextSibling;
	}
	HX_STACK_LINE(1072)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(LayerRenderer_obj,hasZeroOrAutoCompositingLayerSibling,return )

bool LayerRenderer_obj::hasCompositingLayerSibling( ){
	HX_STACK_PUSH("LayerRenderer::hasCompositingLayerSibling","cocktail/core/layer/LayerRenderer.hx",950);
	HX_STACK_THIS(this);
	HX_STACK_LINE(951)
	::cocktail::core::stacking::StackingContext parentStackingContext = this->parentNode->__Field(HX_CSTRING("stackingContext"),true);		HX_STACK_VAR(parentStackingContext,"parentStackingContext");
	HX_STACK_LINE(957)
	if (((parentStackingContext == null()))){
		HX_STACK_LINE(958)
		return false;
	}
	HX_STACK_LINE(964)
	bool hasCheckedAutoAndZeroLayers = false;		HX_STACK_VAR(hasCheckedAutoAndZeroLayers,"hasCheckedAutoAndZeroLayers");
	HX_STACK_LINE(966)
	::cocktail::core::stacking::StackingContext child = parentStackingContext->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(967)
	while(((child != null()))){
		HX_STACK_LINE(971)
		if (((hasCheckedAutoAndZeroLayers == false))){
			HX_STACK_LINE(972)
			if (((child->layerRenderer->getZIndex(child->layerRenderer) >= (int)0))){
				HX_STACK_LINE(977)
				bool ret = this->hasZeroOrAutoCompositingLayerSibling(parentStackingContext->layerRenderer,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(ret,"ret");
				HX_STACK_LINE(978)
				if (((ret == true))){
					HX_STACK_LINE(979)
					return true;
				}
				HX_STACK_LINE(983)
				hasCheckedAutoAndZeroLayers = true;
			}
		}
		HX_STACK_LINE(989)
		if (((child->layerRenderer == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(990)
			return false;
		}
		else{
			HX_STACK_LINE(993)
			if (((bool((child->layerRenderer->isCompositingLayer() == true)) || bool((child->layerRenderer->hasOwnGraphicsContext == true))))){
				HX_STACK_LINE(994)
				return true;
			}
		}
		HX_STACK_LINE(998)
		child = child->nextSibling;
	}
	HX_STACK_LINE(1004)
	if (((hasCheckedAutoAndZeroLayers == false))){
		HX_STACK_LINE(1005)
		return this->hasZeroOrAutoCompositingLayerSibling(parentStackingContext->layerRenderer,hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(1009)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,hasCompositingLayerSibling,return )

bool LayerRenderer_obj::hasCompositingLayerDescendant( ::cocktail::core::layer::LayerRenderer rootLayerRenderer){
	HX_STACK_PUSH("LayerRenderer::hasCompositingLayerDescendant","cocktail/core/layer/LayerRenderer.hx",915);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootLayerRenderer,"rootLayerRenderer");
	HX_STACK_LINE(916)
	::cocktail::core::layer::LayerRenderer child = rootLayerRenderer->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(917)
	while(((child != null()))){
		HX_STACK_LINE(919)
		if (((bool((child->isCompositingLayer() == true)) || bool((child->hasOwnGraphicsContext == true))))){
			HX_STACK_LINE(920)
			return true;
		}
		else{
			HX_STACK_LINE(923)
			if (((child->firstChild != null()))){
				HX_STACK_LINE(925)
				bool hasCompositingLayer = this->hasCompositingLayerDescendant(child);		HX_STACK_VAR(hasCompositingLayer,"hasCompositingLayer");
				HX_STACK_LINE(926)
				if (((hasCompositingLayer == true))){
					HX_STACK_LINE(927)
					return true;
				}
			}
		}
		HX_STACK_LINE(932)
		child = child->nextSibling;
	}
	HX_STACK_LINE(935)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,hasCompositingLayerDescendant,return )

int LayerRenderer_obj::getZIndex( ::cocktail::core::layer::LayerRenderer layerRenderer){
	HX_STACK_PUSH("LayerRenderer::getZIndex","cocktail/core/layer/LayerRenderer.hx",892);
	HX_STACK_THIS(this);
	HX_STACK_ARG(layerRenderer,"layerRenderer");
	HX_STACK_LINE(893)
	int zIndex = (int)0;		HX_STACK_VAR(zIndex,"zIndex");
	HX_STACK_LINE(895)
	{
		::cocktail::core::css::CSSPropertyValue _switch_3 = (layerRenderer->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
		switch((_switch_3)->GetIndex()){
			case 0: {
				int value = _switch_3->__Param(0);
{
					HX_STACK_LINE(897)
					zIndex = value;
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(903)
	return zIndex;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getZIndex,return )

Void LayerRenderer_obj::createStackingContext( ::cocktail::core::stacking::StackingContext parentStackingContext){
{
		HX_STACK_PUSH("LayerRenderer::createStackingContext","cocktail/core/layer/LayerRenderer.hx",846);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentStackingContext,"parentStackingContext");
		HX_STACK_LINE(846)
		if (((this->establishesNewStackingContext() == true))){
			HX_STACK_LINE(850)
			this->stackingContext = ::cocktail::core::stacking::StackingContext_obj::__new(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(851)
			this->hasOwnStackingContext = true;
			HX_STACK_LINE(854)
			int zIndex = this->getZIndex(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(zIndex,"zIndex");
			HX_STACK_LINE(859)
			::cocktail::core::stacking::StackingContext child = parentStackingContext->firstChild;		HX_STACK_VAR(child,"child");
			HX_STACK_LINE(860)
			while(((child != null()))){
				HX_STACK_LINE(862)
				int childZIndex = this->getZIndex(child->layerRenderer);		HX_STACK_VAR(childZIndex,"childZIndex");
				HX_STACK_LINE(863)
				if (((childZIndex > zIndex))){
					HX_STACK_LINE(866)
					parentStackingContext->insertBefore(this->stackingContext,child);
					HX_STACK_LINE(867)
					return null();
				}
				HX_STACK_LINE(870)
				child = child->nextSibling;
			}
			HX_STACK_LINE(876)
			parentStackingContext->appendChild(this->stackingContext);
		}
		else{
			HX_STACK_LINE(880)
			this->stackingContext = parentStackingContext;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,createStackingContext,(void))

bool LayerRenderer_obj::establishesNewGraphicsContext( ){
	HX_STACK_PUSH("LayerRenderer::establishesNewGraphicsContext","cocktail/core/layer/LayerRenderer.hx",823);
	HX_STACK_THIS(this);
	HX_STACK_LINE(825)
	if (((::cocktail::core::config::Config_obj::getInstance()->enableCompositing == true))){
		HX_STACK_LINE(826)
		if (((this->hasCompositingLayerDescendant(hx::ObjectPtr<OBJ_>(this)) == true))){
			HX_STACK_LINE(828)
			return true;
		}
		else{
			HX_STACK_LINE(831)
			if (((this->hasCompositingLayerSibling() == true))){
				HX_STACK_LINE(832)
				return true;
			}
		}
	}
	HX_STACK_LINE(837)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,establishesNewGraphicsContext,return )

::cocktail::core::layer::LayerRenderer LayerRenderer_obj::getNextSiblingWithGraphicsContext( ::cocktail::core::layer::LayerRenderer rootLayer,::cocktail::core::layer::LayerRenderer referenceLayer,bool hasFoundSelf){
	HX_STACK_PUSH("LayerRenderer::getNextSiblingWithGraphicsContext","cocktail/core/layer/LayerRenderer.hx",741);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootLayer,"rootLayer");
	HX_STACK_ARG(referenceLayer,"referenceLayer");
	HX_STACK_ARG(hasFoundSelf,"hasFoundSelf");
	HX_STACK_LINE(742)
	::cocktail::core::layer::LayerRenderer nextSiblingWithGraphicsContext = null();		HX_STACK_VAR(nextSiblingWithGraphicsContext,"nextSiblingWithGraphicsContext");
	HX_STACK_LINE(744)
	::cocktail::core::layer::LayerRenderer child = rootLayer->firstChild;		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(745)
	while(((child != null()))){
		HX_STACK_LINE(748)
		if (((child->hasOwnStackingContext == false))){
			HX_STACK_LINE(753)
			if (((child == referenceLayer))){
				HX_STACK_LINE(754)
				hasFoundSelf = true;
			}
			else{
				HX_STACK_LINE(759)
				if (((hasFoundSelf == true))){
					HX_STACK_LINE(760)
					if (((child->hasOwnGraphicsContext == true))){
						HX_STACK_LINE(762)
						return child;
					}
				}
			}
			HX_STACK_LINE(768)
			::cocktail::core::layer::LayerRenderer childNextSiblingWithGraphicsContext = this->getNextSiblingWithGraphicsContext(child,referenceLayer,hasFoundSelf);		HX_STACK_VAR(childNextSiblingWithGraphicsContext,"childNextSiblingWithGraphicsContext");
			HX_STACK_LINE(769)
			if (((childNextSiblingWithGraphicsContext != null()))){
				HX_STACK_LINE(770)
				if (((childNextSiblingWithGraphicsContext == referenceLayer))){
					HX_STACK_LINE(772)
					hasFoundSelf = true;
				}
				else{
					HX_STACK_LINE(776)
					return childNextSiblingWithGraphicsContext;
				}
			}
		}
		else{
			HX_STACK_LINE(783)
			{
				::cocktail::core::css::CSSPropertyValue _switch_4 = (child->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
				switch((_switch_4)->GetIndex()){
					case 0: {
						int value = _switch_4->__Param(0);
{
							HX_STACK_LINE(786)
							if (((value == (int)0))){
								HX_STACK_LINE(788)
								if (((child == referenceLayer))){
									HX_STACK_LINE(790)
									hasFoundSelf = true;
								}
								else{
									HX_STACK_LINE(793)
									if (((hasFoundSelf == true))){
										HX_STACK_LINE(794)
										if (((child->hasOwnGraphicsContext == true))){
											HX_STACK_LINE(796)
											return child;
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
		}
		HX_STACK_LINE(805)
		child = child->nextSibling;
	}
	HX_STACK_LINE(808)
	if (((hasFoundSelf == true))){
		HX_STACK_LINE(809)
		return referenceLayer;
	}
	else{
		HX_STACK_LINE(813)
		return null();
	}
	HX_STACK_LINE(808)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(LayerRenderer_obj,getNextSiblingWithGraphicsContext,return )

Void LayerRenderer_obj::createGraphicsContext( ::cocktail::core::graphics::GraphicsContext parentGraphicsContext){
{
		HX_STACK_PUSH("LayerRenderer::createGraphicsContext","cocktail/core/layer/LayerRenderer.hx",617);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentGraphicsContext,"parentGraphicsContext");
		HX_STACK_LINE(617)
		if (((this->establishesNewGraphicsContext() == true))){
			HX_STACK_LINE(620)
			this->graphicsContext = ::cocktail::core::graphics::GraphicsContext_obj::__new(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(621)
			this->hasOwnGraphicsContext = true;
			HX_STACK_LINE(625)
			::cocktail::core::stacking::StackingContext parentStackingContext = this->parentNode->__Field(HX_CSTRING("stackingContext"),true);		HX_STACK_VAR(parentStackingContext,"parentStackingContext");
			HX_STACK_LINE(627)
			bool foundSelf = false;		HX_STACK_VAR(foundSelf,"foundSelf");
			HX_STACK_LINE(629)
			::cocktail::core::stacking::StackingContext child = parentStackingContext->firstChild;		HX_STACK_VAR(child,"child");
			HX_STACK_LINE(631)
			bool hasCheckedAutoAndZeroLayers = false;		HX_STACK_VAR(hasCheckedAutoAndZeroLayers,"hasCheckedAutoAndZeroLayers");
			HX_STACK_LINE(636)
			while(((child != null()))){
				HX_STACK_LINE(640)
				if (((hasCheckedAutoAndZeroLayers == false))){
					HX_STACK_LINE(641)
					if (((child->layerRenderer->getZIndex(child->layerRenderer) >= (int)0))){
						HX_STACK_LINE(644)
						::cocktail::core::layer::LayerRenderer nextSiblingWithGraphicsContext = this->getNextSiblingWithGraphicsContext(parentStackingContext->layerRenderer,hx::ObjectPtr<OBJ_>(this),foundSelf);		HX_STACK_VAR(nextSiblingWithGraphicsContext,"nextSiblingWithGraphicsContext");
						HX_STACK_LINE(648)
						if (((nextSiblingWithGraphicsContext != null()))){
							HX_STACK_LINE(649)
							if (((nextSiblingWithGraphicsContext == hx::ObjectPtr<OBJ_>(this)))){
								HX_STACK_LINE(655)
								foundSelf = true;
							}
							else{
								HX_STACK_LINE(660)
								nextSiblingWithGraphicsContext->graphicsContext->parentNode->__Field(HX_CSTRING("insertBefore"),true)(this->graphicsContext,nextSiblingWithGraphicsContext->graphicsContext);
								HX_STACK_LINE(661)
								return null();
							}
						}
						HX_STACK_LINE(665)
						hasCheckedAutoAndZeroLayers = true;
					}
				}
				HX_STACK_LINE(669)
				if (((bool((foundSelf == true)) && bool((child->layerRenderer != hx::ObjectPtr<OBJ_>(this)))))){
					HX_STACK_LINE(670)
					if (((child->layerRenderer->graphicsContext != null()))){
						HX_STACK_LINE(672)
						if (((child->layerRenderer->hasOwnGraphicsContext == true))){
							HX_STACK_LINE(675)
							child->layerRenderer->graphicsContext->parentNode->__Field(HX_CSTRING("insertBefore"),true)(this->graphicsContext,child->layerRenderer->graphicsContext);
							HX_STACK_LINE(676)
							return null();
						}
					}
				}
				HX_STACK_LINE(685)
				if (((this->hasOwnStackingContext == true))){
					HX_STACK_LINE(686)
					if (((child->layerRenderer == hx::ObjectPtr<OBJ_>(this)))){
						HX_STACK_LINE(688)
						foundSelf = true;
					}
				}
				HX_STACK_LINE(693)
				child = child->nextSibling;
			}
			HX_STACK_LINE(698)
			if (((hasCheckedAutoAndZeroLayers == false))){
				HX_STACK_LINE(700)
				::cocktail::core::layer::LayerRenderer nextSiblingWithGraphicsContext = this->getNextSiblingWithGraphicsContext(parentStackingContext->layerRenderer,hx::ObjectPtr<OBJ_>(this),foundSelf);		HX_STACK_VAR(nextSiblingWithGraphicsContext,"nextSiblingWithGraphicsContext");
				HX_STACK_LINE(702)
				if (((nextSiblingWithGraphicsContext != null()))){
					HX_STACK_LINE(703)
					if (((nextSiblingWithGraphicsContext == hx::ObjectPtr<OBJ_>(this)))){
						HX_STACK_LINE(705)
						foundSelf = true;
					}
					else{
						HX_STACK_LINE(710)
						nextSiblingWithGraphicsContext->graphicsContext->parentNode->__Field(HX_CSTRING("insertBefore"),true)(this->graphicsContext,nextSiblingWithGraphicsContext->graphicsContext);
						HX_STACK_LINE(711)
						return null();
					}
				}
			}
			HX_STACK_LINE(719)
			parentGraphicsContext->appendChild(this->graphicsContext);
		}
		else{
			HX_STACK_LINE(722)
			this->graphicsContext = parentGraphicsContext;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,createGraphicsContext,(void))

Void LayerRenderer_obj::doDetachStackingContext( ){
{
		HX_STACK_PUSH("LayerRenderer::doDetachStackingContext","cocktail/core/layer/LayerRenderer.hx",600);
		HX_STACK_THIS(this);
		HX_STACK_LINE(603)
		if (((this->hasOwnStackingContext == true))){
			HX_STACK_LINE(605)
			this->parentNode->__Field(HX_CSTRING("stackingContext"),true)->__Field(HX_CSTRING("removeChild"),true)(this->stackingContext);
			HX_STACK_LINE(606)
			this->hasOwnStackingContext = false;
		}
		HX_STACK_LINE(609)
		this->stackingContext = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,doDetachStackingContext,(void))

Void LayerRenderer_obj::doAttachStackingContext( ){
{
		HX_STACK_PUSH("LayerRenderer::doAttachStackingContext","cocktail/core/layer/LayerRenderer.hx",589);
		HX_STACK_THIS(this);
		HX_STACK_LINE(589)
		if (((this->parentNode != null()))){
			HX_STACK_LINE(591)
			this->createStackingContext(this->parentNode->__Field(HX_CSTRING("stackingContext"),true));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,doAttachStackingContext,(void))

Void LayerRenderer_obj::doDetachGraphicsContext( ){
{
		HX_STACK_PUSH("LayerRenderer::doDetachGraphicsContext","cocktail/core/layer/LayerRenderer.hx",571);
		HX_STACK_THIS(this);
		HX_STACK_LINE(574)
		if (((this->hasOwnGraphicsContext == true))){
			HX_STACK_LINE(576)
			this->graphicsContext->parentNode->__Field(HX_CSTRING("removeChild"),true)(this->graphicsContext);
			HX_STACK_LINE(577)
			this->graphicsContext->dispose();
			HX_STACK_LINE(578)
			this->hasOwnGraphicsContext = false;
		}
		HX_STACK_LINE(581)
		this->graphicsContext = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,doDetachGraphicsContext,(void))

Void LayerRenderer_obj::doAttachGraphicsContext( ){
{
		HX_STACK_PUSH("LayerRenderer::doAttachGraphicsContext","cocktail/core/layer/LayerRenderer.hx",560);
		HX_STACK_THIS(this);
		HX_STACK_LINE(560)
		if (((this->parentNode != null()))){
			HX_STACK_LINE(562)
			this->createGraphicsContext(this->parentNode->__Field(HX_CSTRING("graphicsContext"),true));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,doAttachGraphicsContext,(void))

Void LayerRenderer_obj::detachStackingContext( ){
{
		HX_STACK_PUSH("LayerRenderer::detachStackingContext","cocktail/core/layer/LayerRenderer.hx",540);
		HX_STACK_THIS(this);
		HX_STACK_LINE(541)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(542)
		while(((child != null()))){
			HX_STACK_LINE(544)
			child->detachStackingContext();
			HX_STACK_LINE(545)
			child = child->nextSibling;
		}
		HX_STACK_LINE(548)
		this->doDetachStackingContext();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,detachStackingContext,(void))

Void LayerRenderer_obj::attachStackingContext( ){
{
		HX_STACK_PUSH("LayerRenderer::attachStackingContext","cocktail/core/layer/LayerRenderer.hx",522);
		HX_STACK_THIS(this);
		HX_STACK_LINE(523)
		this->doAttachStackingContext();
		HX_STACK_LINE(525)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(526)
		while(((child != null()))){
			HX_STACK_LINE(528)
			child->attachStackingContext();
			HX_STACK_LINE(529)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,attachStackingContext,(void))

Void LayerRenderer_obj::detachGraphicsContext( ){
{
		HX_STACK_PUSH("LayerRenderer::detachGraphicsContext","cocktail/core/layer/LayerRenderer.hx",504);
		HX_STACK_THIS(this);
		HX_STACK_LINE(505)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(506)
		while(((child != null()))){
			HX_STACK_LINE(508)
			child->detachGraphicsContext();
			HX_STACK_LINE(509)
			child = child->nextSibling;
		}
		HX_STACK_LINE(512)
		this->doDetachGraphicsContext();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,detachGraphicsContext,(void))

Void LayerRenderer_obj::attachGraphicsContext( ){
{
		HX_STACK_PUSH("LayerRenderer::attachGraphicsContext","cocktail/core/layer/LayerRenderer.hx",486);
		HX_STACK_THIS(this);
		HX_STACK_LINE(487)
		this->doAttachGraphicsContext();
		HX_STACK_LINE(490)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(491)
		while(((child != null()))){
			HX_STACK_LINE(493)
			child->attachGraphicsContext();
			HX_STACK_LINE(494)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,attachGraphicsContext,(void))

Void LayerRenderer_obj::removedFromLayerTree( ){
{
		HX_STACK_PUSH("LayerRenderer::removedFromLayerTree","cocktail/core/layer/LayerRenderer.hx",469);
		HX_STACK_THIS(this);
		HX_STACK_LINE(472)
		this->invalidateGraphicsContext(this->isCompositingLayer());
		HX_STACK_LINE(473)
		this->invalidateStackingContext();
		HX_STACK_LINE(474)
		this->invalidateRendering();
		HX_STACK_LINE(476)
		this->detachGraphicsContext();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,removedFromLayerTree,(void))

Void LayerRenderer_obj::addedToLayerTree( ){
{
		HX_STACK_PUSH("LayerRenderer::addedToLayerTree","cocktail/core/layer/LayerRenderer.hx",451);
		HX_STACK_THIS(this);
		HX_STACK_LINE(452)
		this->invalidateStackingContext();
		HX_STACK_LINE(453)
		this->invalidateRendering();
		HX_STACK_LINE(460)
		this->invalidateGraphicsContext(this->isCompositingLayer());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,addedToLayerTree,(void))

Void LayerRenderer_obj::removeChild( Dynamic _tmp_oldChild){
{
		HX_STACK_PUSH("LayerRenderer::removeChild","cocktail/core/layer/LayerRenderer.hx",436);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_oldChild,"_tmp_oldChild");
		HX_STACK_LINE(437)
		::cocktail::core::layer::LayerRenderer oldChild = _tmp_oldChild;		HX_STACK_VAR(oldChild,"oldChild");
		HX_STACK_LINE(437)
		oldChild->removedFromLayerTree();
		HX_STACK_LINE(438)
		this->super::removeChild(oldChild);
	}
return null();
}


Void LayerRenderer_obj::insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild){
{
		HX_STACK_PUSH("LayerRenderer::insertBefore","cocktail/core/layer/LayerRenderer.hx",419);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
		HX_STACK_ARG(_tmp_refChild,"_tmp_refChild");
		HX_STACK_LINE(420)
		::cocktail::core::layer::LayerRenderer newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
		::cocktail::core::layer::LayerRenderer refChild = _tmp_refChild;		HX_STACK_VAR(refChild,"refChild");
		HX_STACK_LINE(420)
		this->super::insertBefore(newChild,refChild);
		HX_STACK_LINE(424)
		if (((refChild == null()))){
			HX_STACK_LINE(425)
			return null();
		}
		HX_STACK_LINE(429)
		newChild->addedToLayerTree();
	}
return null();
}


Void LayerRenderer_obj::appendChild( Dynamic _tmp_newChild){
{
		HX_STACK_PUSH("LayerRenderer::appendChild","cocktail/core/layer/LayerRenderer.hx",410);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
		HX_STACK_LINE(411)
		::cocktail::core::layer::LayerRenderer newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
		HX_STACK_LINE(411)
		this->super::appendChild(newChild);
		HX_STACK_LINE(412)
		newChild->addedToLayerTree();
	}
return null();
}


Void LayerRenderer_obj::invalidateStackingContext( ){
{
		HX_STACK_PUSH("LayerRenderer::invalidateStackingContext","cocktail/core/layer/LayerRenderer.hx",393);
		HX_STACK_THIS(this);
		HX_STACK_LINE(394)
		::cocktail::core::html::HTMLDocument htmlDocument = this->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(395)
		htmlDocument->invalidationManager->invalidateStackingContexts();
		HX_STACK_LINE(397)
		this->_needsStackingContextUpdate = true;
		HX_STACK_LINE(399)
		this->detachStackingContext();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,invalidateStackingContext,(void))

Void LayerRenderer_obj::invalidateRendering( ){
{
		HX_STACK_PUSH("LayerRenderer::invalidateRendering","cocktail/core/layer/LayerRenderer.hx",383);
		HX_STACK_THIS(this);
		HX_STACK_LINE(384)
		::cocktail::core::html::HTMLDocument htmlDocument = this->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(385)
		htmlDocument->invalidationManager->invalidateRendering(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,invalidateRendering,(void))

Void LayerRenderer_obj::invalidateGraphicsContext( bool force){
{
		HX_STACK_PUSH("LayerRenderer::invalidateGraphicsContext","cocktail/core/layer/LayerRenderer.hx",373);
		HX_STACK_THIS(this);
		HX_STACK_ARG(force,"force");
		HX_STACK_LINE(374)
		this->_needsGraphicsContextUpdate = true;
		HX_STACK_LINE(375)
		::cocktail::core::html::HTMLDocument htmlDocument = this->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(376)
		htmlDocument->invalidationManager->invalidateGraphicsContextTree(force);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,invalidateGraphicsContext,(void))

Void LayerRenderer_obj::updateStackingContext( ){
{
		HX_STACK_PUSH("LayerRenderer::updateStackingContext","cocktail/core/layer/LayerRenderer.hx",327);
		HX_STACK_THIS(this);
		HX_STACK_LINE(329)
		if (((this->_needsStackingContextUpdate == true))){
			HX_STACK_LINE(331)
			this->_needsStackingContextUpdate = false;
			HX_STACK_LINE(334)
			if (((this->stackingContext == null()))){
				HX_STACK_LINE(336)
				this->attachStackingContext();
				HX_STACK_LINE(339)
				return null();
			}
			else{
				HX_STACK_LINE(343)
				if (((this->establishesNewStackingContext() != this->hasOwnStackingContext))){
					HX_STACK_LINE(345)
					this->detachStackingContext();
					HX_STACK_LINE(346)
					this->attachStackingContext();
					HX_STACK_LINE(347)
					return null();
				}
			}
		}
		HX_STACK_LINE(352)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(353)
		while(((child != null()))){
			HX_STACK_LINE(355)
			child->updateStackingContext();
			HX_STACK_LINE(356)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,updateStackingContext,(void))

Void LayerRenderer_obj::updateLayerAlpha( Float parentAlpha){
{
		HX_STACK_PUSH("LayerRenderer::updateLayerAlpha","cocktail/core/layer/LayerRenderer.hx",288);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentAlpha,"parentAlpha");
		HX_STACK_LINE(290)
		Float layerAlpha = 1.0;		HX_STACK_VAR(layerAlpha,"layerAlpha");
		HX_STACK_LINE(293)
		if (((this->rootElementRenderer->coreStyle->isTransparent == true))){
			HX_STACK_LINE(295)
			::cocktail::core::css::CoreStyle coreStyle = this->rootElementRenderer->coreStyle;		HX_STACK_VAR(coreStyle,"coreStyle");
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &coreStyle){
					HX_STACK_PUSH("*::closure","cocktail/core/layer/LayerRenderer.hx",297);
					{
						HX_STACK_LINE(297)
						::cocktail::core::animation::Transition transition = coreStyle->_transitionManager->getTransition((int)53,coreStyle);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(297)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(coreStyle->getComputedOrInitialProperty((int)53)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(297)
			{
				::cocktail::core::css::CSSPropertyValue _switch_5 = ((  (((coreStyle->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(coreStyle->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue((  (((coreStyle->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(coreStyle->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(coreStyle)) )) ));
				switch((_switch_5)->GetIndex()){
					case 1: {
						Float value = _switch_5->__Param(0);
{
							HX_STACK_LINE(299)
							layerAlpha = value;
						}
					}
					;break;
					case 18: {
						Float value = _switch_5->__Param(0);
{
							HX_STACK_LINE(302)
							layerAlpha = value;
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(310)
		this->alpha = (layerAlpha * parentAlpha);
		HX_STACK_LINE(313)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(314)
		while(((child != null()))){
			HX_STACK_LINE(316)
			child->updateLayerAlpha(this->alpha);
			HX_STACK_LINE(317)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,updateLayerAlpha,(void))

Void LayerRenderer_obj::updateLayerMatrix( ::cocktail::core::geom::Matrix parentMatrix){
{
		HX_STACK_PUSH("LayerRenderer::updateLayerMatrix","cocktail/core/layer/LayerRenderer.hx",246);
		HX_STACK_THIS(this);
		HX_STACK_ARG(parentMatrix,"parentMatrix");
		HX_STACK_LINE(248)
		this->matrix->identity();
		HX_STACK_LINE(250)
		if (((this->rootElementRenderer->coreStyle->isTransformed == true))){
			HX_STACK_LINE(255)
			if (((this->rootElementRenderer->coreStyle->hasCSSTransform == true))){
				HX_STACK_LINE(256)
				::cocktail::core::layout::computer::VisualEffectStylesComputer_obj::compute(this->rootElementRenderer->coreStyle);
			}
			HX_STACK_LINE(260)
			this->matrix = this->getTransformationMatrix();
		}
		HX_STACK_LINE(263)
		this->matrix->concatenate(parentMatrix);
		HX_STACK_LINE(266)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(267)
		while(((child != null()))){
			HX_STACK_LINE(269)
			child->updateLayerMatrix(this->matrix);
			HX_STACK_LINE(270)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,updateLayerMatrix,(void))

Void LayerRenderer_obj::updateGraphicsContext( bool force){
{
		HX_STACK_PUSH("LayerRenderer::updateGraphicsContext","cocktail/core/layer/LayerRenderer.hx",210);
		HX_STACK_THIS(this);
		HX_STACK_ARG(force,"force");
		HX_STACK_LINE(211)
		if (((bool((this->_needsGraphicsContextUpdate == true)) || bool((force == true))))){
			HX_STACK_LINE(213)
			this->_needsGraphicsContextUpdate = false;
			HX_STACK_LINE(215)
			if (((this->graphicsContext == null()))){
				HX_STACK_LINE(217)
				this->attachGraphicsContext();
				HX_STACK_LINE(218)
				return null();
			}
			else{
				HX_STACK_LINE(220)
				if (((this->hasOwnGraphicsContext != this->establishesNewGraphicsContext()))){
					HX_STACK_LINE(222)
					this->detachGraphicsContext();
					HX_STACK_LINE(223)
					this->attachGraphicsContext();
					HX_STACK_LINE(224)
					return null();
				}
			}
		}
		HX_STACK_LINE(228)
		::cocktail::core::layer::LayerRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(229)
		while(((child != null()))){
			HX_STACK_LINE(231)
			child->updateGraphicsContext(force);
			HX_STACK_LINE(232)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,updateGraphicsContext,(void))

Void LayerRenderer_obj::dispose( ){
{
		HX_STACK_PUSH("LayerRenderer::dispose","cocktail/core/layer/LayerRenderer.hx",193);
		HX_STACK_THIS(this);
		HX_STACK_LINE(194)
		this->rootElementRenderer = null();
		HX_STACK_LINE(195)
		this->graphicsContext = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,dispose,(void))


LayerRenderer_obj::LayerRenderer_obj()
{
}

void LayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LayerRenderer);
	HX_MARK_MEMBER_NAME(_canUpdateScrollRegion,"_canUpdateScrollRegion");
	HX_MARK_MEMBER_NAME(_currentMatrix,"_currentMatrix");
	HX_MARK_MEMBER_NAME(_layerDirtyRect,"_layerDirtyRect");
	HX_MARK_MEMBER_NAME(_relativeOffset,"_relativeOffset");
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(_needsStackingContextUpdate,"_needsStackingContextUpdate");
	HX_MARK_MEMBER_NAME(_needsGraphicsContextUpdate,"_needsGraphicsContextUpdate");
	HX_MARK_MEMBER_NAME(hasOwnStackingContext,"hasOwnStackingContext");
	HX_MARK_MEMBER_NAME(hasOwnGraphicsContext,"hasOwnGraphicsContext");
	HX_MARK_MEMBER_NAME(graphicsContext,"graphicsContext");
	HX_MARK_MEMBER_NAME(stackingContext,"stackingContext");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_canUpdateScrollRegion,"_canUpdateScrollRegion");
	HX_VISIT_MEMBER_NAME(_currentMatrix,"_currentMatrix");
	HX_VISIT_MEMBER_NAME(_layerDirtyRect,"_layerDirtyRect");
	HX_VISIT_MEMBER_NAME(_relativeOffset,"_relativeOffset");
	HX_VISIT_MEMBER_NAME(matrix,"matrix");
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(_needsStackingContextUpdate,"_needsStackingContextUpdate");
	HX_VISIT_MEMBER_NAME(_needsGraphicsContextUpdate,"_needsGraphicsContextUpdate");
	HX_VISIT_MEMBER_NAME(hasOwnStackingContext,"hasOwnStackingContext");
	HX_VISIT_MEMBER_NAME(hasOwnGraphicsContext,"hasOwnGraphicsContext");
	HX_VISIT_MEMBER_NAME(graphicsContext,"graphicsContext");
	HX_VISIT_MEMBER_NAME(stackingContext,"stackingContext");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic LayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"alpha") ) { return alpha; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"matrix") ) { return matrix; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"doClear") ) { return doClear_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getZIndex") ) { return getZIndex_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"needsBitmap") ) { return needsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"updateBounds") ) { return updateBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"scrollChanged") ) { return scrollChanged_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_currentMatrix") ) { return _currentMatrix; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_layerDirtyRect") ) { return _layerDirtyRect; }
		if (HX_FIELD_EQ(inName,"_relativeOffset") ) { return _relativeOffset; }
		if (HX_FIELD_EQ(inName,"graphicsContext") ) { return graphicsContext; }
		if (HX_FIELD_EQ(inName,"stackingContext") ) { return stackingContext; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addedToLayerTree") ) { return addedToLayerTree_dyn(); }
		if (HX_FIELD_EQ(inName,"updateLayerAlpha") ) { return updateLayerAlpha_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getRelativeOffset") ) { return getRelativeOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"updateLayerMatrix") ) { return updateLayerMatrix_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"updateScrollRegion") ) { return updateScrollRegion_dyn(); }
		if (HX_FIELD_EQ(inName,"isCompositingLayer") ) { return isCompositingLayer_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"dispatchScrollEvent") ) { return dispatchScrollEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateRendering") ) { return invalidateRendering_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"removedFromLayerTree") ) { return removedFromLayerTree_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getConcatenatedMatrix") ) { return getConcatenatedMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"createStackingContext") ) { return createStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"createGraphicsContext") ) { return createGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"detachStackingContext") ) { return detachStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"attachStackingContext") ) { return attachStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"detachGraphicsContext") ) { return detachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"attachGraphicsContext") ) { return attachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"updateStackingContext") ) { return updateStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"updateGraphicsContext") ) { return updateGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"hasOwnStackingContext") ) { return hasOwnStackingContext; }
		if (HX_FIELD_EQ(inName,"hasOwnGraphicsContext") ) { return hasOwnGraphicsContext; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_canUpdateScrollRegion") ) { return _canUpdateScrollRegion; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getTransformationMatrix") ) { return getTransformationMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"doDetachStackingContext") ) { return doDetachStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"doAttachStackingContext") ) { return doAttachStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"doDetachGraphicsContext") ) { return doDetachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"doAttachGraphicsContext") ) { return doAttachGraphicsContext_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"invalidateStackingContext") ) { return invalidateStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateGraphicsContext") ) { return invalidateGraphicsContext_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"hasCompositingLayerSibling") ) { return hasCompositingLayerSibling_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_needsStackingContextUpdate") ) { return _needsStackingContextUpdate; }
		if (HX_FIELD_EQ(inName,"_needsGraphicsContextUpdate") ) { return _needsGraphicsContextUpdate; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"establishesNewStackingContext") ) { return establishesNewStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"hasCompositingLayerDescendant") ) { return hasCompositingLayerDescendant_dyn(); }
		if (HX_FIELD_EQ(inName,"establishesNewGraphicsContext") ) { return establishesNewGraphicsContext_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"getNextSiblingWithGraphicsContext") ) { return getNextSiblingWithGraphicsContext_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"hasZeroOrAutoCompositingLayerSibling") ) { return hasZeroOrAutoCompositingLayerSibling_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { alpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { matrix=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_currentMatrix") ) { _currentMatrix=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_layerDirtyRect") ) { _layerDirtyRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_relativeOffset") ) { _relativeOffset=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"graphicsContext") ) { graphicsContext=inValue.Cast< ::cocktail::core::graphics::GraphicsContext >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stackingContext") ) { stackingContext=inValue.Cast< ::cocktail::core::stacking::StackingContext >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"hasOwnStackingContext") ) { hasOwnStackingContext=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasOwnGraphicsContext") ) { hasOwnGraphicsContext=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_canUpdateScrollRegion") ) { _canUpdateScrollRegion=inValue.Cast< bool >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_needsStackingContextUpdate") ) { _needsStackingContextUpdate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_needsGraphicsContextUpdate") ) { _needsGraphicsContextUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_canUpdateScrollRegion"));
	outFields->push(HX_CSTRING("_currentMatrix"));
	outFields->push(HX_CSTRING("_layerDirtyRect"));
	outFields->push(HX_CSTRING("_relativeOffset"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("_needsStackingContextUpdate"));
	outFields->push(HX_CSTRING("_needsGraphicsContextUpdate"));
	outFields->push(HX_CSTRING("hasOwnStackingContext"));
	outFields->push(HX_CSTRING("hasOwnGraphicsContext"));
	outFields->push(HX_CSTRING("graphicsContext"));
	outFields->push(HX_CSTRING("stackingContext"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispatchScrollEvent"),
	HX_CSTRING("establishesNewStackingContext"),
	HX_CSTRING("getRelativeOffset"),
	HX_CSTRING("getConcatenatedMatrix"),
	HX_CSTRING("getTransformationMatrix"),
	HX_CSTRING("doClear"),
	HX_CSTRING("updateScrollRegion"),
	HX_CSTRING("render"),
	HX_CSTRING("clear"),
	HX_CSTRING("scrollChanged"),
	HX_CSTRING("updateBounds"),
	HX_CSTRING("needsBitmap"),
	HX_CSTRING("isCompositingLayer"),
	HX_CSTRING("hasZeroOrAutoCompositingLayerSibling"),
	HX_CSTRING("hasCompositingLayerSibling"),
	HX_CSTRING("hasCompositingLayerDescendant"),
	HX_CSTRING("getZIndex"),
	HX_CSTRING("createStackingContext"),
	HX_CSTRING("establishesNewGraphicsContext"),
	HX_CSTRING("getNextSiblingWithGraphicsContext"),
	HX_CSTRING("createGraphicsContext"),
	HX_CSTRING("doDetachStackingContext"),
	HX_CSTRING("doAttachStackingContext"),
	HX_CSTRING("doDetachGraphicsContext"),
	HX_CSTRING("doAttachGraphicsContext"),
	HX_CSTRING("detachStackingContext"),
	HX_CSTRING("attachStackingContext"),
	HX_CSTRING("detachGraphicsContext"),
	HX_CSTRING("attachGraphicsContext"),
	HX_CSTRING("removedFromLayerTree"),
	HX_CSTRING("addedToLayerTree"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("invalidateStackingContext"),
	HX_CSTRING("invalidateRendering"),
	HX_CSTRING("invalidateGraphicsContext"),
	HX_CSTRING("updateStackingContext"),
	HX_CSTRING("updateLayerAlpha"),
	HX_CSTRING("updateLayerMatrix"),
	HX_CSTRING("updateGraphicsContext"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_canUpdateScrollRegion"),
	HX_CSTRING("_currentMatrix"),
	HX_CSTRING("_layerDirtyRect"),
	HX_CSTRING("_relativeOffset"),
	HX_CSTRING("matrix"),
	HX_CSTRING("alpha"),
	HX_CSTRING("_needsStackingContextUpdate"),
	HX_CSTRING("_needsGraphicsContextUpdate"),
	HX_CSTRING("hasOwnStackingContext"),
	HX_CSTRING("hasOwnGraphicsContext"),
	HX_CSTRING("graphicsContext"),
	HX_CSTRING("stackingContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LayerRenderer_obj::__mClass,"__mClass");
};

Class LayerRenderer_obj::__mClass;

void LayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.LayerRenderer"), hx::TCanCast< LayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
