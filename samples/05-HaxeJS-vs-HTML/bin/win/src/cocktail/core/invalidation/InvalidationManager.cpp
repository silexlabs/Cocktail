#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
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
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
namespace cocktail{
namespace core{
namespace invalidation{

Void InvalidationManager_obj::__construct(::cocktail::core::html::HTMLDocument htmlDocument)
{
HX_STACK_PUSH("InvalidationManager::new","cocktail/core/invalidation/InvalidationManager.hx",183);
{
	HX_STACK_LINE(184)
	this->_htmlDocument = htmlDocument;
	HX_STACK_LINE(186)
	this->_invalidationScheduled = false;
	HX_STACK_LINE(187)
	this->_documentNeedsLayout = true;
	HX_STACK_LINE(188)
	this->_documentNeedsRendering = true;
	HX_STACK_LINE(189)
	this->_documentNeedsCascading = true;
	HX_STACK_LINE(190)
	this->_graphicsContextTreeNeedsUpdate = true;
	HX_STACK_LINE(191)
	this->_forceGraphicsContextUpdate = false;
	HX_STACK_LINE(192)
	this->_renderingTreeNeedsUpdate = true;
	HX_STACK_LINE(193)
	this->_layerTreeNeedsUpdate = true;
	HX_STACK_LINE(194)
	this->_nativeLayerTreeNeedsUpdate = true;
	HX_STACK_LINE(195)
	this->_stackingContextsNeedUpdate = true;
	HX_STACK_LINE(196)
	this->_pendingAnimationsNeedUpdate = true;
	HX_STACK_LINE(197)
	this->_forceLayout = false;
	HX_STACK_LINE(198)
	this->_viewportResized = false;
	HX_STACK_LINE(199)
	this->_bitmapSizeNeedsUpdate = true;
	HX_STACK_LINE(200)
	this->_scrollOffsetNeedsUpdate = false;
	HX_STACK_LINE(202)
	this->_initialMatrix = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(203)
	this->_dirtyRect = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(205)
	this->_firstDirtyRect = true;
	HX_STACK_LINE(209)
	this->_repaintWholeViewport = true;
}
;
	return null();
}

InvalidationManager_obj::~InvalidationManager_obj() { }

Dynamic InvalidationManager_obj::__CreateEmpty() { return  new InvalidationManager_obj; }
hx::ObjectPtr< InvalidationManager_obj > InvalidationManager_obj::__new(::cocktail::core::html::HTMLDocument htmlDocument)
{  hx::ObjectPtr< InvalidationManager_obj > result = new InvalidationManager_obj();
	result->__construct(htmlDocument);
	return result;}

Dynamic InvalidationManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InvalidationManager_obj > result = new InvalidationManager_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InvalidationManager_obj::startLayout( bool forceLayout){
{
		HX_STACK_PUSH("InvalidationManager::startLayout","cocktail/core/invalidation/InvalidationManager.hx",707);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_LINE(710)
		this->_htmlDocument->documentElement->elementRenderer->layout(forceLayout,::cocktail::core::layout::LayoutStateValue_obj::NORMAL_dyn());
		HX_STACK_LINE(714)
		this->_htmlDocument->documentElement->elementRenderer->setGlobalOrigins((int)0,(int)0,(int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidationManager_obj,startLayout,(void))

Void InvalidationManager_obj::startCascade( bool programmaticChange){
{
		HX_STACK_PUSH("InvalidationManager::startCascade","cocktail/core/invalidation/InvalidationManager.hx",696);
		HX_STACK_THIS(this);
		HX_STACK_ARG(programmaticChange,"programmaticChange");
		HX_STACK_LINE(697)
		this->_htmlDocument->cascadeManager->reset();
		HX_STACK_LINE(698)
		this->_htmlDocument->documentElement->cascade(this->_htmlDocument->cascadeManager,programmaticChange);
		HX_STACK_LINE(699)
		this->_documentNeedsCascading = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidationManager_obj,startCascade,(void))

Void InvalidationManager_obj::onUpdateSchedule( Float timeStamp){
{
		HX_STACK_PUSH("InvalidationManager::onUpdateSchedule","cocktail/core/invalidation/InvalidationManager.hx",682);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timeStamp,"timeStamp");
		HX_STACK_LINE(683)
		this->_invalidationScheduled = false;
		HX_STACK_LINE(684)
		this->updateDocument();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidationManager_obj,onUpdateSchedule,(void))

Void InvalidationManager_obj::updateDocument( ){
{
		HX_STACK_PUSH("InvalidationManager::updateDocument","cocktail/core/invalidation/InvalidationManager.hx",448);
		HX_STACK_THIS(this);
		HX_STACK_LINE(450)
		if (((this->_documentNeedsCascading == true))){
			HX_STACK_LINE(451)
			this->startCascade(true);
		}
		HX_STACK_LINE(457)
		if (((this->_renderingTreeNeedsUpdate == true))){
			HX_STACK_LINE(459)
			this->_htmlDocument->documentElement->updateElementRenderer();
			HX_STACK_LINE(460)
			this->_htmlDocument->documentElement->elementRenderer->updateAnonymousBlock();
			HX_STACK_LINE(461)
			this->_htmlDocument->documentElement->elementRenderer->updateInlineBoxes();
			HX_STACK_LINE(462)
			this->_renderingTreeNeedsUpdate = false;
		}
		HX_STACK_LINE(467)
		if (((this->_layerTreeNeedsUpdate == true))){
			HX_STACK_LINE(469)
			this->_htmlDocument->documentElement->elementRenderer->updateLayerRenderer();
			HX_STACK_LINE(470)
			this->_layerTreeNeedsUpdate = false;
		}
		HX_STACK_LINE(474)
		if (((this->_stackingContextsNeedUpdate == true))){
			HX_STACK_LINE(476)
			this->_htmlDocument->documentElement->elementRenderer->layerRenderer->updateStackingContext();
			HX_STACK_LINE(477)
			this->_stackingContextsNeedUpdate = false;
		}
		HX_STACK_LINE(482)
		if (((this->_documentNeedsLayout == true))){
			HX_STACK_LINE(485)
			this->_htmlDocument->documentElement->elementRenderer->updateText();
			HX_STACK_LINE(487)
			this->startLayout(this->_forceLayout);
			HX_STACK_LINE(489)
			this->_forceLayout = false;
			HX_STACK_LINE(490)
			this->_documentNeedsLayout = false;
		}
		HX_STACK_LINE(494)
		if (((this->_pendingAnimationsNeedUpdate == true))){
			HX_STACK_LINE(497)
			bool atLeastOneAnimationStarted = this->_htmlDocument->documentElement->startPendingAnimation();		HX_STACK_VAR(atLeastOneAnimationStarted,"atLeastOneAnimationStarted");
			HX_STACK_LINE(503)
			if (((atLeastOneAnimationStarted == true))){
				HX_STACK_LINE(504)
				this->startLayout(false);
			}
		}
		HX_STACK_LINE(511)
		if (((this->_graphicsContextTreeNeedsUpdate == true))){
			HX_STACK_LINE(513)
			this->_htmlDocument->documentElement->elementRenderer->layerRenderer->updateGraphicsContext(this->_forceGraphicsContextUpdate);
			HX_STACK_LINE(514)
			this->_graphicsContextTreeNeedsUpdate = false;
			HX_STACK_LINE(515)
			this->_forceGraphicsContextUpdate = false;
		}
		HX_STACK_LINE(519)
		if (((this->_nativeLayerTreeNeedsUpdate == true))){
			HX_STACK_LINE(521)
			this->_htmlDocument->documentElement->elementRenderer->layerRenderer->graphicsContext->updateNativeLayer();
			HX_STACK_LINE(522)
			this->_nativeLayerTreeNeedsUpdate = false;
		}
		HX_STACK_LINE(529)
		if (((this->_bitmapSizeNeedsUpdate == true))){
			HX_STACK_LINE(531)
			this->_htmlDocument->documentElement->elementRenderer->layerRenderer->graphicsContext->updateGraphicsSize(this->_htmlDocument->window->get_innerWidth(),this->_htmlDocument->window->get_innerHeight());
			HX_STACK_LINE(532)
			this->_bitmapSizeNeedsUpdate = false;
		}
		HX_STACK_LINE(536)
		if (((this->_documentNeedsRendering == true))){
			HX_STACK_LINE(538)
			::cocktail::core::layer::LayerRenderer initialLayerRenderer = this->_htmlDocument->documentElement->elementRenderer->layerRenderer;		HX_STACK_VAR(initialLayerRenderer,"initialLayerRenderer");
			HX_STACK_LINE(541)
			initialLayerRenderer->updateLayerMatrix(this->_initialMatrix);
			HX_STACK_LINE(544)
			initialLayerRenderer->updateBounds();
			HX_STACK_LINE(547)
			initialLayerRenderer->updateClippedBounds();
			HX_STACK_LINE(550)
			initialLayerRenderer->updateScrollableBounds();
			HX_STACK_LINE(553)
			initialLayerRenderer->resetScrollOffset();
			HX_STACK_LINE(554)
			initialLayerRenderer->updateScrollOffset();
			HX_STACK_LINE(557)
			initialLayerRenderer->resetClipRect((int)0,(int)0,this->_htmlDocument->window->get_innerWidth(),this->_htmlDocument->window->get_innerHeight());
			HX_STACK_LINE(558)
			initialLayerRenderer->updateClipRect();
			HX_STACK_LINE(561)
			this->_htmlDocument->documentElement->elementRenderer->updateHitTestingBounds();
			HX_STACK_LINE(564)
			this->_htmlDocument->window->platform->updateHitTestingBounds(this->_htmlDocument->documentElement->elementRenderer->layerRenderer->stackingContext);
			HX_STACK_LINE(568)
			initialLayerRenderer->updateLayerAlpha(1.0);
			HX_STACK_LINE(573)
			this->_htmlDocument->documentElement->elementRenderer->updateTextDecorations(false,false,false,false);
			HX_STACK_LINE(577)
			if (((this->_repaintWholeViewport == true))){
				HX_STACK_LINE(579)
				this->_dirtyRect->x = (int)0;
				HX_STACK_LINE(580)
				this->_dirtyRect->y = (int)0;
				HX_STACK_LINE(581)
				this->_dirtyRect->width = this->_htmlDocument->window->get_innerWidth();
				HX_STACK_LINE(582)
				this->_dirtyRect->height = this->_htmlDocument->window->get_innerHeight();
			}
			HX_STACK_LINE(587)
			initialLayerRenderer->clear(this->_dirtyRect->x,this->_dirtyRect->y,this->_dirtyRect->width,this->_dirtyRect->height);
			HX_STACK_LINE(591)
			initialLayerRenderer->stackingContext->render(this->_dirtyRect);
			HX_STACK_LINE(593)
			this->_documentNeedsRendering = false;
			HX_STACK_LINE(594)
			this->_repaintWholeViewport = false;
			HX_STACK_LINE(597)
			this->_firstDirtyRect = true;
			HX_STACK_LINE(598)
			this->_dirtyRect->x = (int)0;
			HX_STACK_LINE(599)
			this->_dirtyRect->y = (int)0;
			HX_STACK_LINE(600)
			this->_dirtyRect->width = (int)0;
			HX_STACK_LINE(601)
			this->_dirtyRect->height = (int)0;
			HX_STACK_LINE(602)
			this->_scrollOffsetNeedsUpdate = false;
		}
		else{
			HX_STACK_LINE(607)
			if (((this->_scrollOffsetNeedsUpdate == true))){
				HX_STACK_LINE(613)
				::cocktail::core::layer::LayerRenderer initialLayerRenderer = this->_htmlDocument->documentElement->elementRenderer->layerRenderer;		HX_STACK_VAR(initialLayerRenderer,"initialLayerRenderer");
				HX_STACK_LINE(615)
				initialLayerRenderer->resetScrollOffset();
				HX_STACK_LINE(616)
				initialLayerRenderer->updateScrollOffset();
				HX_STACK_LINE(618)
				initialLayerRenderer->resetClipRect((int)0,(int)0,this->_htmlDocument->window->get_innerWidth(),this->_htmlDocument->window->get_innerHeight());
				HX_STACK_LINE(619)
				initialLayerRenderer->updateClipRect();
				HX_STACK_LINE(622)
				this->_htmlDocument->documentElement->elementRenderer->updateHitTestingBounds();
				HX_STACK_LINE(625)
				this->_htmlDocument->window->platform->updateHitTestingBounds(this->_htmlDocument->documentElement->elementRenderer->layerRenderer->stackingContext);
				HX_STACK_LINE(627)
				this->_dirtyRect->x = (int)0;
				HX_STACK_LINE(628)
				this->_dirtyRect->y = (int)0;
				HX_STACK_LINE(629)
				this->_dirtyRect->width = (int)0;
				HX_STACK_LINE(630)
				this->_dirtyRect->height = (int)0;
				HX_STACK_LINE(634)
				initialLayerRenderer->updateScrollRegion(this->_dirtyRect);
				HX_STACK_LINE(637)
				initialLayerRenderer->clear(this->_dirtyRect->x,this->_dirtyRect->y,this->_dirtyRect->width,this->_dirtyRect->height);
				HX_STACK_LINE(638)
				initialLayerRenderer->stackingContext->render(this->_dirtyRect);
				HX_STACK_LINE(640)
				this->_documentNeedsRendering = false;
				HX_STACK_LINE(641)
				this->_repaintWholeViewport = false;
				HX_STACK_LINE(644)
				this->_firstDirtyRect = true;
				HX_STACK_LINE(645)
				this->_dirtyRect->x = (int)0;
				HX_STACK_LINE(646)
				this->_dirtyRect->y = (int)0;
				HX_STACK_LINE(647)
				this->_dirtyRect->width = (int)0;
				HX_STACK_LINE(648)
				this->_dirtyRect->height = (int)0;
				HX_STACK_LINE(649)
				this->_scrollOffsetNeedsUpdate = false;
			}
		}
		HX_STACK_LINE(654)
		if (((this->_pendingAnimationsNeedUpdate == true))){
			HX_STACK_LINE(662)
			this->_htmlDocument->documentElement->endPendingAnimation();
			HX_STACK_LINE(663)
			this->_pendingAnimationsNeedUpdate = false;
		}
		HX_STACK_LINE(668)
		if (((this->_viewportResized == true))){
			HX_STACK_LINE(670)
			this->_viewportResized = false;
			HX_STACK_LINE(671)
			::cocktail::core::event::UIEvent resizeEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(resizeEvent,"resizeEvent");
			HX_STACK_LINE(672)
			resizeEvent->initUIEvent(HX_CSTRING("resize"),false,false,null(),(int)0);
			HX_STACK_LINE(673)
			this->_htmlDocument->window->dispatchEvent(resizeEvent);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,updateDocument,(void))

Void InvalidationManager_obj::doInvalidate( ){
{
		HX_STACK_PUSH("InvalidationManager::doInvalidate","cocktail/core/invalidation/InvalidationManager.hx",437);
		HX_STACK_THIS(this);
		HX_STACK_LINE(438)
		this->_invalidationScheduled = true;
		HX_STACK_LINE(439)
		this->_htmlDocument->timer->delay(this->onUpdateSchedule_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,doInvalidate,(void))

Void InvalidationManager_obj::invalidate( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidate","cocktail/core/invalidation/InvalidationManager.hx",425);
		HX_STACK_THIS(this);
		HX_STACK_LINE(425)
		if (((this->_invalidationScheduled == false))){
			HX_STACK_LINE(427)
			this->doInvalidate();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidate,(void))

Void InvalidationManager_obj::invalidateCascade( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateCascade","cocktail/core/invalidation/InvalidationManager.hx",412);
		HX_STACK_THIS(this);
		HX_STACK_LINE(413)
		this->_documentNeedsCascading = true;
		HX_STACK_LINE(414)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateCascade,(void))

Void InvalidationManager_obj::invalidateGraphicsContextTree( bool force){
{
		HX_STACK_PUSH("InvalidationManager::invalidateGraphicsContextTree","cocktail/core/invalidation/InvalidationManager.hx",399);
		HX_STACK_THIS(this);
		HX_STACK_ARG(force,"force");
		HX_STACK_LINE(400)
		this->_graphicsContextTreeNeedsUpdate = true;
		HX_STACK_LINE(401)
		if (((force == true))){
			HX_STACK_LINE(402)
			this->_forceGraphicsContextUpdate = true;
		}
		HX_STACK_LINE(405)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidationManager_obj,invalidateGraphicsContextTree,(void))

Void InvalidationManager_obj::invalidatePendingAnimations( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidatePendingAnimations","cocktail/core/invalidation/InvalidationManager.hx",389);
		HX_STACK_THIS(this);
		HX_STACK_LINE(390)
		this->_pendingAnimationsNeedUpdate = true;
		HX_STACK_LINE(391)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidatePendingAnimations,(void))

Void InvalidationManager_obj::invalidateNativeLayerTree( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateNativeLayerTree","cocktail/core/invalidation/InvalidationManager.hx",380);
		HX_STACK_THIS(this);
		HX_STACK_LINE(381)
		this->_nativeLayerTreeNeedsUpdate = true;
		HX_STACK_LINE(382)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateNativeLayerTree,(void))

Void InvalidationManager_obj::invalidateStackingContexts( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateStackingContexts","cocktail/core/invalidation/InvalidationManager.hx",371);
		HX_STACK_THIS(this);
		HX_STACK_LINE(372)
		this->_stackingContextsNeedUpdate = true;
		HX_STACK_LINE(373)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateStackingContexts,(void))

Void InvalidationManager_obj::invalidateLayerTree( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateLayerTree","cocktail/core/invalidation/InvalidationManager.hx",362);
		HX_STACK_THIS(this);
		HX_STACK_LINE(363)
		this->_layerTreeNeedsUpdate = true;
		HX_STACK_LINE(364)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateLayerTree,(void))

Void InvalidationManager_obj::invalidateRenderingTree( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateRenderingTree","cocktail/core/invalidation/InvalidationManager.hx",353);
		HX_STACK_THIS(this);
		HX_STACK_LINE(354)
		this->_renderingTreeNeedsUpdate = true;
		HX_STACK_LINE(355)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateRenderingTree,(void))

Void InvalidationManager_obj::invalidateScrollOffset( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateScrollOffset","cocktail/core/invalidation/InvalidationManager.hx",344);
		HX_STACK_THIS(this);
		HX_STACK_LINE(345)
		this->_scrollOffsetNeedsUpdate = true;
		HX_STACK_LINE(346)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateScrollOffset,(void))

Void InvalidationManager_obj::invalidateRendering( ::cocktail::core::geom::RectangleVO dirtyRect){
{
		HX_STACK_PUSH("InvalidationManager::invalidateRendering","cocktail/core/invalidation/InvalidationManager.hx",292);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dirtyRect,"dirtyRect");
		HX_STACK_LINE(293)
		this->_documentNeedsRendering = true;
		HX_STACK_LINE(294)
		this->invalidate();
		HX_STACK_LINE(298)
		if (((this->_repaintWholeViewport == true))){
			HX_STACK_LINE(299)
			return null();
		}
		HX_STACK_LINE(303)
		if (((dirtyRect == null()))){
			HX_STACK_LINE(304)
			this->_repaintWholeViewport = true;
		}
		else{
			HX_STACK_LINE(311)
			if (((this->_firstDirtyRect == true))){
				HX_STACK_LINE(316)
				this->_dirtyRect->x = dirtyRect->x;
				HX_STACK_LINE(317)
				this->_dirtyRect->y = dirtyRect->y;
				HX_STACK_LINE(318)
				this->_dirtyRect->width = dirtyRect->width;
				HX_STACK_LINE(319)
				this->_dirtyRect->height = dirtyRect->height;
				HX_STACK_LINE(321)
				this->_firstDirtyRect = false;
			}
			else{
				HX_STACK_LINE(325)
				::cocktail::core::geom::RectangleVO bounds = this->_dirtyRect;		HX_STACK_VAR(bounds,"bounds");
				bool getHorizontalBounds = true;		HX_STACK_VAR(getHorizontalBounds,"getHorizontalBounds");
				bool getVerticalBounds = true;		HX_STACK_VAR(getVerticalBounds,"getVerticalBounds");
				HX_STACK_LINE(325)
				if (((getHorizontalBounds == true))){
					HX_STACK_LINE(325)
					if (((dirtyRect->x < bounds->x))){
						HX_STACK_LINE(325)
						bounds->x = dirtyRect->x;
					}
					HX_STACK_LINE(325)
					if ((((dirtyRect->x + dirtyRect->width) > (bounds->x + bounds->width)))){
						HX_STACK_LINE(325)
						bounds->width = ((dirtyRect->x + dirtyRect->width) - bounds->x);
					}
				}
				HX_STACK_LINE(325)
				if (((getVerticalBounds == true))){
					HX_STACK_LINE(325)
					if (((dirtyRect->y < bounds->y))){
						HX_STACK_LINE(325)
						bounds->y = dirtyRect->y;
					}
					HX_STACK_LINE(325)
					if ((((dirtyRect->y + dirtyRect->height) > (bounds->y + bounds->height)))){
						HX_STACK_LINE(325)
						bounds->height = ((dirtyRect->y + dirtyRect->height) - bounds->y);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidationManager_obj,invalidateRendering,(void))

Void InvalidationManager_obj::invalidateLayout( bool force){
{
		HX_STACK_PUSH("InvalidationManager::invalidateLayout","cocktail/core/invalidation/InvalidationManager.hx",271);
		HX_STACK_THIS(this);
		HX_STACK_ARG(force,"force");
		HX_STACK_LINE(272)
		if (((this->_forceLayout == true))){
			HX_STACK_LINE(273)
			this->_forceLayout = force;
		}
		HX_STACK_LINE(277)
		this->_documentNeedsLayout = true;
		HX_STACK_LINE(278)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidationManager_obj,invalidateLayout,(void))

Void InvalidationManager_obj::invalidateBitmapSizes( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateBitmapSizes","cocktail/core/invalidation/InvalidationManager.hx",260);
		HX_STACK_THIS(this);
		HX_STACK_LINE(261)
		this->_bitmapSizeNeedsUpdate = true;
		HX_STACK_LINE(262)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateBitmapSizes,(void))

Void InvalidationManager_obj::invalidateViewportSize( ){
{
		HX_STACK_PUSH("InvalidationManager::invalidateViewportSize","cocktail/core/invalidation/InvalidationManager.hx",248);
		HX_STACK_THIS(this);
		HX_STACK_LINE(249)
		this->invalidateLayout(true);
		HX_STACK_LINE(250)
		this->invalidateRendering(null());
		HX_STACK_LINE(251)
		this->_viewportResized = true;
		HX_STACK_LINE(252)
		this->_bitmapSizeNeedsUpdate = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,invalidateViewportSize,(void))

Void InvalidationManager_obj::updateDocumentImmediately( ){
{
		HX_STACK_PUSH("InvalidationManager::updateDocumentImmediately","cocktail/core/invalidation/InvalidationManager.hx",220);
		HX_STACK_THIS(this);
		HX_STACK_LINE(220)
		if (((::cocktail::core::config::Config_obj::getInstance()->enableSynchronousUpdate == true))){
			HX_STACK_LINE(223)
			if (((this->_documentNeedsRendering == false))){
				HX_STACK_LINE(231)
				this->updateDocument();
			}
			else{
				HX_STACK_LINE(236)
				this->_documentNeedsRendering = false;
				HX_STACK_LINE(237)
				this->updateDocument();
				HX_STACK_LINE(238)
				this->_documentNeedsRendering = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidationManager_obj,updateDocumentImmediately,(void))


InvalidationManager_obj::InvalidationManager_obj()
{
}

void InvalidationManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InvalidationManager);
	HX_MARK_MEMBER_NAME(_firstDirtyRect,"_firstDirtyRect");
	HX_MARK_MEMBER_NAME(_repaintWholeViewport,"_repaintWholeViewport");
	HX_MARK_MEMBER_NAME(_dirtyRect,"_dirtyRect");
	HX_MARK_MEMBER_NAME(_initialMatrix,"_initialMatrix");
	HX_MARK_MEMBER_NAME(_htmlDocument,"_htmlDocument");
	HX_MARK_MEMBER_NAME(_bitmapSizeNeedsUpdate,"_bitmapSizeNeedsUpdate");
	HX_MARK_MEMBER_NAME(_viewportResized,"_viewportResized");
	HX_MARK_MEMBER_NAME(_forceGraphicsContextUpdate,"_forceGraphicsContextUpdate");
	HX_MARK_MEMBER_NAME(_graphicsContextTreeNeedsUpdate,"_graphicsContextTreeNeedsUpdate");
	HX_MARK_MEMBER_NAME(_pendingAnimationsNeedUpdate,"_pendingAnimationsNeedUpdate");
	HX_MARK_MEMBER_NAME(_nativeLayerTreeNeedsUpdate,"_nativeLayerTreeNeedsUpdate");
	HX_MARK_MEMBER_NAME(_stackingContextsNeedUpdate,"_stackingContextsNeedUpdate");
	HX_MARK_MEMBER_NAME(_layerTreeNeedsUpdate,"_layerTreeNeedsUpdate");
	HX_MARK_MEMBER_NAME(_renderingTreeNeedsUpdate,"_renderingTreeNeedsUpdate");
	HX_MARK_MEMBER_NAME(_documentNeedsCascading,"_documentNeedsCascading");
	HX_MARK_MEMBER_NAME(_scrollOffsetNeedsUpdate,"_scrollOffsetNeedsUpdate");
	HX_MARK_MEMBER_NAME(_documentNeedsRendering,"_documentNeedsRendering");
	HX_MARK_MEMBER_NAME(_forceLayout,"_forceLayout");
	HX_MARK_MEMBER_NAME(_documentNeedsLayout,"_documentNeedsLayout");
	HX_MARK_MEMBER_NAME(_invalidationScheduled,"_invalidationScheduled");
	HX_MARK_END_CLASS();
}

void InvalidationManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_firstDirtyRect,"_firstDirtyRect");
	HX_VISIT_MEMBER_NAME(_repaintWholeViewport,"_repaintWholeViewport");
	HX_VISIT_MEMBER_NAME(_dirtyRect,"_dirtyRect");
	HX_VISIT_MEMBER_NAME(_initialMatrix,"_initialMatrix");
	HX_VISIT_MEMBER_NAME(_htmlDocument,"_htmlDocument");
	HX_VISIT_MEMBER_NAME(_bitmapSizeNeedsUpdate,"_bitmapSizeNeedsUpdate");
	HX_VISIT_MEMBER_NAME(_viewportResized,"_viewportResized");
	HX_VISIT_MEMBER_NAME(_forceGraphicsContextUpdate,"_forceGraphicsContextUpdate");
	HX_VISIT_MEMBER_NAME(_graphicsContextTreeNeedsUpdate,"_graphicsContextTreeNeedsUpdate");
	HX_VISIT_MEMBER_NAME(_pendingAnimationsNeedUpdate,"_pendingAnimationsNeedUpdate");
	HX_VISIT_MEMBER_NAME(_nativeLayerTreeNeedsUpdate,"_nativeLayerTreeNeedsUpdate");
	HX_VISIT_MEMBER_NAME(_stackingContextsNeedUpdate,"_stackingContextsNeedUpdate");
	HX_VISIT_MEMBER_NAME(_layerTreeNeedsUpdate,"_layerTreeNeedsUpdate");
	HX_VISIT_MEMBER_NAME(_renderingTreeNeedsUpdate,"_renderingTreeNeedsUpdate");
	HX_VISIT_MEMBER_NAME(_documentNeedsCascading,"_documentNeedsCascading");
	HX_VISIT_MEMBER_NAME(_scrollOffsetNeedsUpdate,"_scrollOffsetNeedsUpdate");
	HX_VISIT_MEMBER_NAME(_documentNeedsRendering,"_documentNeedsRendering");
	HX_VISIT_MEMBER_NAME(_forceLayout,"_forceLayout");
	HX_VISIT_MEMBER_NAME(_documentNeedsLayout,"_documentNeedsLayout");
	HX_VISIT_MEMBER_NAME(_invalidationScheduled,"_invalidationScheduled");
}

Dynamic InvalidationManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"_dirtyRect") ) { return _dirtyRect; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"startLayout") ) { return startLayout_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startCascade") ) { return startCascade_dyn(); }
		if (HX_FIELD_EQ(inName,"doInvalidate") ) { return doInvalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"_forceLayout") ) { return _forceLayout; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_htmlDocument") ) { return _htmlDocument; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateDocument") ) { return updateDocument_dyn(); }
		if (HX_FIELD_EQ(inName,"_initialMatrix") ) { return _initialMatrix; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_firstDirtyRect") ) { return _firstDirtyRect; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onUpdateSchedule") ) { return onUpdateSchedule_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateLayout") ) { return invalidateLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"_viewportResized") ) { return _viewportResized; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"invalidateCascade") ) { return invalidateCascade_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"invalidateLayerTree") ) { return invalidateLayerTree_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateRendering") ) { return invalidateRendering_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_documentNeedsLayout") ) { return _documentNeedsLayout; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"invalidateBitmapSizes") ) { return invalidateBitmapSizes_dyn(); }
		if (HX_FIELD_EQ(inName,"_repaintWholeViewport") ) { return _repaintWholeViewport; }
		if (HX_FIELD_EQ(inName,"_layerTreeNeedsUpdate") ) { return _layerTreeNeedsUpdate; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"invalidateScrollOffset") ) { return invalidateScrollOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateViewportSize") ) { return invalidateViewportSize_dyn(); }
		if (HX_FIELD_EQ(inName,"_bitmapSizeNeedsUpdate") ) { return _bitmapSizeNeedsUpdate; }
		if (HX_FIELD_EQ(inName,"_invalidationScheduled") ) { return _invalidationScheduled; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"invalidateRenderingTree") ) { return invalidateRenderingTree_dyn(); }
		if (HX_FIELD_EQ(inName,"_documentNeedsCascading") ) { return _documentNeedsCascading; }
		if (HX_FIELD_EQ(inName,"_documentNeedsRendering") ) { return _documentNeedsRendering; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_scrollOffsetNeedsUpdate") ) { return _scrollOffsetNeedsUpdate; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"invalidateNativeLayerTree") ) { return invalidateNativeLayerTree_dyn(); }
		if (HX_FIELD_EQ(inName,"updateDocumentImmediately") ) { return updateDocumentImmediately_dyn(); }
		if (HX_FIELD_EQ(inName,"_renderingTreeNeedsUpdate") ) { return _renderingTreeNeedsUpdate; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"invalidateStackingContexts") ) { return invalidateStackingContexts_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"invalidatePendingAnimations") ) { return invalidatePendingAnimations_dyn(); }
		if (HX_FIELD_EQ(inName,"_forceGraphicsContextUpdate") ) { return _forceGraphicsContextUpdate; }
		if (HX_FIELD_EQ(inName,"_nativeLayerTreeNeedsUpdate") ) { return _nativeLayerTreeNeedsUpdate; }
		if (HX_FIELD_EQ(inName,"_stackingContextsNeedUpdate") ) { return _stackingContextsNeedUpdate; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_pendingAnimationsNeedUpdate") ) { return _pendingAnimationsNeedUpdate; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"invalidateGraphicsContextTree") ) { return invalidateGraphicsContextTree_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"_graphicsContextTreeNeedsUpdate") ) { return _graphicsContextTreeNeedsUpdate; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InvalidationManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_dirtyRect") ) { _dirtyRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_forceLayout") ) { _forceLayout=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_htmlDocument") ) { _htmlDocument=inValue.Cast< ::cocktail::core::html::HTMLDocument >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_initialMatrix") ) { _initialMatrix=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_firstDirtyRect") ) { _firstDirtyRect=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_viewportResized") ) { _viewportResized=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_documentNeedsLayout") ) { _documentNeedsLayout=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_repaintWholeViewport") ) { _repaintWholeViewport=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_layerTreeNeedsUpdate") ) { _layerTreeNeedsUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_bitmapSizeNeedsUpdate") ) { _bitmapSizeNeedsUpdate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_invalidationScheduled") ) { _invalidationScheduled=inValue.Cast< bool >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_documentNeedsCascading") ) { _documentNeedsCascading=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_documentNeedsRendering") ) { _documentNeedsRendering=inValue.Cast< bool >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_scrollOffsetNeedsUpdate") ) { _scrollOffsetNeedsUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_renderingTreeNeedsUpdate") ) { _renderingTreeNeedsUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_forceGraphicsContextUpdate") ) { _forceGraphicsContextUpdate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nativeLayerTreeNeedsUpdate") ) { _nativeLayerTreeNeedsUpdate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stackingContextsNeedUpdate") ) { _stackingContextsNeedUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_pendingAnimationsNeedUpdate") ) { _pendingAnimationsNeedUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"_graphicsContextTreeNeedsUpdate") ) { _graphicsContextTreeNeedsUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InvalidationManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_firstDirtyRect"));
	outFields->push(HX_CSTRING("_repaintWholeViewport"));
	outFields->push(HX_CSTRING("_dirtyRect"));
	outFields->push(HX_CSTRING("_initialMatrix"));
	outFields->push(HX_CSTRING("_htmlDocument"));
	outFields->push(HX_CSTRING("_bitmapSizeNeedsUpdate"));
	outFields->push(HX_CSTRING("_viewportResized"));
	outFields->push(HX_CSTRING("_forceGraphicsContextUpdate"));
	outFields->push(HX_CSTRING("_graphicsContextTreeNeedsUpdate"));
	outFields->push(HX_CSTRING("_pendingAnimationsNeedUpdate"));
	outFields->push(HX_CSTRING("_nativeLayerTreeNeedsUpdate"));
	outFields->push(HX_CSTRING("_stackingContextsNeedUpdate"));
	outFields->push(HX_CSTRING("_layerTreeNeedsUpdate"));
	outFields->push(HX_CSTRING("_renderingTreeNeedsUpdate"));
	outFields->push(HX_CSTRING("_documentNeedsCascading"));
	outFields->push(HX_CSTRING("_scrollOffsetNeedsUpdate"));
	outFields->push(HX_CSTRING("_documentNeedsRendering"));
	outFields->push(HX_CSTRING("_forceLayout"));
	outFields->push(HX_CSTRING("_documentNeedsLayout"));
	outFields->push(HX_CSTRING("_invalidationScheduled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("startLayout"),
	HX_CSTRING("startCascade"),
	HX_CSTRING("onUpdateSchedule"),
	HX_CSTRING("updateDocument"),
	HX_CSTRING("doInvalidate"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("invalidateCascade"),
	HX_CSTRING("invalidateGraphicsContextTree"),
	HX_CSTRING("invalidatePendingAnimations"),
	HX_CSTRING("invalidateNativeLayerTree"),
	HX_CSTRING("invalidateStackingContexts"),
	HX_CSTRING("invalidateLayerTree"),
	HX_CSTRING("invalidateRenderingTree"),
	HX_CSTRING("invalidateScrollOffset"),
	HX_CSTRING("invalidateRendering"),
	HX_CSTRING("invalidateLayout"),
	HX_CSTRING("invalidateBitmapSizes"),
	HX_CSTRING("invalidateViewportSize"),
	HX_CSTRING("updateDocumentImmediately"),
	HX_CSTRING("_firstDirtyRect"),
	HX_CSTRING("_repaintWholeViewport"),
	HX_CSTRING("_dirtyRect"),
	HX_CSTRING("_initialMatrix"),
	HX_CSTRING("_htmlDocument"),
	HX_CSTRING("_bitmapSizeNeedsUpdate"),
	HX_CSTRING("_viewportResized"),
	HX_CSTRING("_forceGraphicsContextUpdate"),
	HX_CSTRING("_graphicsContextTreeNeedsUpdate"),
	HX_CSTRING("_pendingAnimationsNeedUpdate"),
	HX_CSTRING("_nativeLayerTreeNeedsUpdate"),
	HX_CSTRING("_stackingContextsNeedUpdate"),
	HX_CSTRING("_layerTreeNeedsUpdate"),
	HX_CSTRING("_renderingTreeNeedsUpdate"),
	HX_CSTRING("_documentNeedsCascading"),
	HX_CSTRING("_scrollOffsetNeedsUpdate"),
	HX_CSTRING("_documentNeedsRendering"),
	HX_CSTRING("_forceLayout"),
	HX_CSTRING("_documentNeedsLayout"),
	HX_CSTRING("_invalidationScheduled"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InvalidationManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InvalidationManager_obj::__mClass,"__mClass");
};

Class InvalidationManager_obj::__mClass;

void InvalidationManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.invalidation.InvalidationManager"), hx::TCanCast< InvalidationManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InvalidationManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace invalidation
