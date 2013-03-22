#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
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
#ifndef INCLUDED_cocktail_core_event_CustomEvent
#include <cocktail/core/event/CustomEvent.h>
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
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#include <cocktail/core/html/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_stacking_StackingContext
#include <cocktail/core/stacking/StackingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_display_StageDisplayState
#include <neash/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_neash_display_StageQuality
#include <neash/display/StageQuality.h>
#endif
#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_net_URLRequest
#include <neash/net/URLRequest.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void Platform_obj::__construct()
{
HX_STACK_PUSH("Platform::new","cocktail/port/platform/flash_player/Platform.hx",110);
{
	HX_STACK_LINE(111)
	this->initDisplayList();
	HX_STACK_LINE(113)
	super::__construct();
	HX_STACK_LINE(117)
	::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetScaleMode(::neash::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_STACK_LINE(121)
	if (((::cocktail::core::config::Config_obj::getInstance()->useLowStageQuality == true))){
		HX_STACK_LINE(122)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetQuality(::neash::display::StageQuality_obj::LOW_dyn());
	}
	HX_STACK_LINE(128)
	::cocktail::core::config::Config_obj::getInstance()->addEventListener(HX_CSTRING("configchanged"),this->onConfigChanged_dyn(),null());
}
;
	return null();
}

Platform_obj::~Platform_obj() { }

Dynamic Platform_obj::__CreateEmpty() { return  new Platform_obj; }
hx::ObjectPtr< Platform_obj > Platform_obj::__new()
{  hx::ObjectPtr< Platform_obj > result = new Platform_obj();
	result->__construct();
	return result;}

Dynamic Platform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Platform_obj > result = new Platform_obj();
	result->__construct();
	return result;}

Void Platform_obj::onConfigChanged( ::cocktail::core::event::CustomEvent event){
{
		HX_STACK_PUSH("Platform::onConfigChanged","cocktail/port/platform/flash_player/Platform.hx",536);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(536)
		Dynamic _switch_1 = (event->detail);
		if (  ( _switch_1==HX_CSTRING("stageWidth")) ||  ( _switch_1==HX_CSTRING("stageHeight"))){
			HX_STACK_LINE(541)
			this->onNativeResize(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,onConfigChanged,(void))

Void Platform_obj::hitTestChildrenInSameStackingContext( ::cocktail::core::layer::LayerRenderer rootLayer){
{
		HX_STACK_PUSH("Platform::hitTestChildrenInSameStackingContext","cocktail/port/platform/flash_player/Platform.hx",501);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayer,"rootLayer");
		HX_STACK_LINE(502)
		::cocktail::core::layer::LayerRenderer child = rootLayer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(503)
		while(((child != null()))){
			HX_STACK_LINE(505)
			if (((child->hasOwnStackingContext == false))){
				HX_STACK_LINE(507)
				this->hitTestLayer(child);
				HX_STACK_LINE(508)
				this->hitTestChildrenInSameStackingContext(child);
			}
			else{
				HX_STACK_LINE(511)
				{
					::cocktail::core::css::CSSPropertyValue _switch_2 = (child->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
					switch((_switch_2)->GetIndex()){
						case 0: {
							int value = _switch_2->__Param(0);
{
								HX_STACK_LINE(514)
								if (((value == (int)0))){
									HX_STACK_LINE(516)
									this->doUpdateHitTestingBounds(child->stackingContext);
								}
							}
						}
						;break;
						default: {
						}
					}
				}
			}
			HX_STACK_LINE(523)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,hitTestChildrenInSameStackingContext,(void))

Void Platform_obj::doUpdateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext){
{
		HX_STACK_PUSH("Platform::doUpdateHitTestingBounds","cocktail/port/platform/flash_player/Platform.hx",457);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stackingContext,"stackingContext");
		HX_STACK_LINE(458)
		this->hitTestLayer(stackingContext->layerRenderer);
		HX_STACK_LINE(460)
		::cocktail::core::stacking::StackingContext child = stackingContext->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(462)
		bool hasHitTestedAutoAndZeroLayers = false;		HX_STACK_VAR(hasHitTestedAutoAndZeroLayers,"hasHitTestedAutoAndZeroLayers");
		HX_STACK_LINE(464)
		while(((child != null()))){
			HX_STACK_LINE(466)
			{
				::cocktail::core::css::CSSPropertyValue _switch_3 = (child->layerRenderer->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
				switch((_switch_3)->GetIndex()){
					case 0: {
						int value = _switch_3->__Param(0);
{
							HX_STACK_LINE(468)
							if (((value == (int)0))){
							}
							else{
								HX_STACK_LINE(476)
								if (((bool((value > (int)0)) && bool((hasHitTestedAutoAndZeroLayers == false))))){
									HX_STACK_LINE(478)
									this->hitTestChildrenInSameStackingContext(stackingContext->layerRenderer);
									HX_STACK_LINE(479)
									hasHitTestedAutoAndZeroLayers = true;
								}
								HX_STACK_LINE(482)
								this->doUpdateHitTestingBounds(child);
							}
						}
					}
					;break;
					default: {
					}
				}
			}
			HX_STACK_LINE(488)
			child = child->nextSibling;
		}
		HX_STACK_LINE(491)
		if (((hasHitTestedAutoAndZeroLayers == false))){
			HX_STACK_LINE(492)
			this->hitTestChildrenInSameStackingContext(stackingContext->layerRenderer);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,doUpdateHitTestingBounds,(void))

Void Platform_obj::hitTestLayer( ::cocktail::core::layer::LayerRenderer layerRenderer){
{
		HX_STACK_PUSH("Platform::hitTestLayer","cocktail/port/platform/flash_player/Platform.hx",414);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layerRenderer,"layerRenderer");
		HX_STACK_LINE(415)
		if (((layerRenderer->rootElementRenderer->domNode->tagName == HX_CSTRING("OBJECT")))){
			HX_STACK_LINE(417)
			this->_foundHollowedTag = true;
			HX_STACK_LINE(418)
			this->_hollowedTagsBounds->push(layerRenderer->bounds);
			HX_STACK_LINE(419)
			this->resetHitTestingSprite();
			HX_STACK_LINE(420)
			return null();
		}
		HX_STACK_LINE(427)
		if (((layerRenderer->rootElementRenderer->domNode->tagName == HX_CSTRING("INPUT")))){
			HX_STACK_LINE(429)
			::cocktail::core::html::HTMLInputElement inputElement = layerRenderer->rootElementRenderer->domNode;		HX_STACK_VAR(inputElement,"inputElement");
			HX_STACK_LINE(430)
			if (((bool((inputElement->get_type() == HX_CSTRING("text"))) || bool((inputElement->get_type() == HX_CSTRING("password")))))){
				HX_STACK_LINE(432)
				::cocktail::core::html::HTMLDocument htmlDocument = inputElement->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
				HX_STACK_LINE(433)
				if (((htmlDocument->get_activeElement() == inputElement))){
					HX_STACK_LINE(435)
					this->_foundHollowedTag = true;
					HX_STACK_LINE(436)
					this->_hollowedTagsBounds->push(layerRenderer->bounds);
					HX_STACK_LINE(437)
					this->resetHitTestingSprite();
					HX_STACK_LINE(438)
					return null();
				}
			}
		}
		HX_STACK_LINE(443)
		if (((this->_foundHollowedTag == true))){
			HX_STACK_LINE(444)
			this->fillHitTestingSprite(layerRenderer->bounds);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,hitTestLayer,(void))

Void Platform_obj::fillHitTestingSprite( ::cocktail::core::geom::RectangleVO rect){
{
		HX_STACK_PUSH("Platform::fillHitTestingSprite","cocktail/port/platform/flash_player/Platform.hx",402);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_LINE(403)
		this->hitTestingSprite->nmeGetGraphics()->beginFill((int)0,0.0);
		HX_STACK_LINE(404)
		this->hitTestingSprite->nmeGetGraphics()->drawRect(rect->x,rect->y,rect->width,rect->height);
		HX_STACK_LINE(405)
		this->hitTestingSprite->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,fillHitTestingSprite,(void))

Void Platform_obj::resetHitTestingSprite( ){
{
		HX_STACK_PUSH("Platform::resetHitTestingSprite","cocktail/port/platform/flash_player/Platform.hx",383);
		HX_STACK_THIS(this);
		HX_STACK_LINE(384)
		this->hitTestingSprite->nmeGetGraphics()->clear();
		HX_STACK_LINE(385)
		this->hitTestingSprite->nmeGetGraphics()->beginFill((int)0,0.0);
		HX_STACK_LINE(386)
		this->hitTestingSprite->nmeGetGraphics()->drawRect((int)0,(int)0,this->get_innerWidth(),this->get_innerHeight());
		HX_STACK_LINE(388)
		{
			HX_STACK_LINE(388)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->_hollowedTagsBounds->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(388)
			while(((_g1 < _g))){
				HX_STACK_LINE(388)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(390)
				this->hitTestingSprite->nmeGetGraphics()->drawRect(this->_hollowedTagsBounds->__get(i)->x,this->_hollowedTagsBounds->__get(i)->y,this->_hollowedTagsBounds->__get(i)->width,this->_hollowedTagsBounds->__get(i)->height);
			}
		}
		HX_STACK_LINE(394)
		this->hitTestingSprite->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Platform_obj,resetHitTestingSprite,(void))

int Platform_obj::get_innerWidth( ){
	HX_STACK_PUSH("Platform::get_innerWidth","cocktail/port/platform/flash_player/Platform.hx",361);
	HX_STACK_THIS(this);
	HX_STACK_LINE(362)
	int configStageWidth = ::cocktail::core::config::Config_obj::getInstance()->stageWidth;		HX_STACK_VAR(configStageWidth,"configStageWidth");
	HX_STACK_LINE(363)
	if (((configStageWidth != (int)-1))){
		HX_STACK_LINE(364)
		return configStageWidth;
	}
	HX_STACK_LINE(368)
	return ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeGetStageWidth();
}


int Platform_obj::get_innerHeight( ){
	HX_STACK_PUSH("Platform::get_innerHeight","cocktail/port/platform/flash_player/Platform.hx",348);
	HX_STACK_THIS(this);
	HX_STACK_LINE(349)
	int configStageHeight = ::cocktail::core::config::Config_obj::getInstance()->stageHeight;		HX_STACK_VAR(configStageHeight,"configStageHeight");
	HX_STACK_LINE(350)
	if (((configStageHeight != (int)-1))){
		HX_STACK_LINE(351)
		return configStageHeight;
	}
	HX_STACK_LINE(354)
	return ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeGetStageHeight();
}


Void Platform_obj::updateHitTestingSprite( ){
{
		HX_STACK_PUSH("Platform::updateHitTestingSprite","cocktail/port/platform/flash_player/Platform.hx",333);
		HX_STACK_THIS(this);
		HX_STACK_LINE(334)
		this->hitTestingSprite->nmeGetGraphics()->clear();
		HX_STACK_LINE(335)
		this->hitTestingSprite->nmeGetGraphics()->beginFill((int)0,(int)0);
		HX_STACK_LINE(336)
		this->hitTestingSprite->nmeGetGraphics()->drawRect((int)0,(int)0,this->get_innerWidth(),this->get_innerHeight());
		HX_STACK_LINE(337)
		this->hitTestingSprite->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Platform_obj,updateHitTestingSprite,(void))

Void Platform_obj::onNativeResize( Dynamic event){
{
		HX_STACK_PUSH("Platform::onNativeResize","cocktail/port/platform/flash_player/Platform.hx",317);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(318)
		this->updateHitTestingSprite();
		HX_STACK_LINE(319)
		this->super::onNativeResize(event);
	}
return null();
}


::cocktail::core::event::Event Platform_obj::getEvent( Dynamic event){
	HX_STACK_PUSH("Platform::getEvent","cocktail/port/platform/flash_player/Platform.hx",301);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(302)
	::cocktail::core::event::Event fullScreenChangeEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(fullScreenChangeEvent,"fullScreenChangeEvent");
	HX_STACK_LINE(303)
	fullScreenChangeEvent->initEvent(HX_CSTRING("fullscreenchange"),false,false);
	HX_STACK_LINE(305)
	return fullScreenChangeEvent;
}


::cocktail::core::event::UIEvent Platform_obj::getUIEvent( Dynamic event){
	HX_STACK_PUSH("Platform::getUIEvent","cocktail/port/platform/flash_player/Platform.hx",287);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(288)
	::cocktail::core::event::UIEvent resizeEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(resizeEvent,"resizeEvent");
	HX_STACK_LINE(289)
	resizeEvent->initUIEvent(HX_CSTRING("resize"),false,false,null(),0.0);
	HX_STACK_LINE(291)
	return resizeEvent;
}


Void Platform_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("Platform::removeNativeListeners","cocktail/port/platform/flash_player/Platform.hx",271);
		HX_STACK_THIS(this);
		HX_STACK_LINE(271)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::neash::events::Event_obj::RESIZE,this->onNativeResize_dyn(),null());
	}
return null();
}


Void Platform_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("Platform::setNativeListeners","cocktail/port/platform/flash_player/Platform.hx",258);
		HX_STACK_THIS(this);
		HX_STACK_LINE(258)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::neash::events::Event_obj::RESIZE,this->onNativeResize_dyn(),null(),null(),null());
	}
return null();
}


Void Platform_obj::updateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext){
{
		HX_STACK_PUSH("Platform::updateHitTestingBounds","cocktail/port/platform/flash_player/Platform.hx",236);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stackingContext,"stackingContext");
		HX_STACK_LINE(238)
		if (((::cocktail::core::config::Config_obj::getInstance()->useAdvancedHitTesting == false))){
			HX_STACK_LINE(239)
			return null();
		}
		HX_STACK_LINE(243)
		this->_hollowedTagsBounds = Array_obj< ::cocktail::core::geom::RectangleVO >::__new();
		HX_STACK_LINE(244)
		this->_foundHollowedTag = false;
		HX_STACK_LINE(246)
		this->updateHitTestingSprite();
		HX_STACK_LINE(247)
		this->doUpdateHitTestingBounds(stackingContext);
	}
return null();
}


::neash::display::DisplayObjectContainer Platform_obj::getInitialNativeLayer( ){
	HX_STACK_PUSH("Platform::getInitialNativeLayer","cocktail/port/platform/flash_player/Platform.hx",209);
	HX_STACK_THIS(this);
	HX_STACK_LINE(209)
	return this->_nativeLayersRootSprite;
}


bool Platform_obj::fullscreen( ){
	HX_STACK_PUSH("Platform::fullscreen","cocktail/port/platform/flash_player/Platform.hx",201);
	HX_STACK_THIS(this);
	HX_STACK_LINE(201)
	return (::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeGetDisplayState() == ::neash::display::StageDisplayState_obj::FULL_SCREEN_dyn());
}


bool Platform_obj::fullScreenEnabled( ){
	HX_STACK_PUSH("Platform::fullScreenEnabled","cocktail/port/platform/flash_player/Platform.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_LINE(193)
	return ::Reflect_obj::hasField(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage(),HX_CSTRING("allowsFullScreen"));
}


Void Platform_obj::exitFullscreen( ){
{
		HX_STACK_PUSH("Platform::exitFullscreen","cocktail/port/platform/flash_player/Platform.hx",183);
		HX_STACK_THIS(this);
		HX_STACK_LINE(183)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetDisplayState(::neash::display::StageDisplayState_obj::NORMAL_dyn());
	}
return null();
}


Void Platform_obj::enterFullscreen( ){
{
		HX_STACK_PUSH("Platform::enterFullscreen","cocktail/port/platform/flash_player/Platform.hx",175);
		HX_STACK_THIS(this);
		HX_STACK_LINE(175)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetDisplayState(::neash::display::StageDisplayState_obj::FULL_SCREEN_dyn());
	}
return null();
}


Void Platform_obj::open( ::String url,::String name){
{
		HX_STACK_PUSH("Platform::open","cocktail/port/platform/flash_player/Platform.hx",167);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(167)
		::nme::Lib_obj::getURL(::neash::net::URLRequest_obj::__new(url),name);
	}
return null();
}


Void Platform_obj::initDisplayList( ){
{
		HX_STACK_PUSH("Platform::initDisplayList","cocktail/port/platform/flash_player/Platform.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_LINE(137)
		this->_rootSprite = ::neash::display::Sprite_obj::__new();
		HX_STACK_LINE(139)
		this->_nativeLayersRootSprite = ::neash::display::Sprite_obj::__new();
		HX_STACK_LINE(142)
		this->hitTestingSprite = ::neash::display::Sprite_obj::__new();
		HX_STACK_LINE(143)
		this->updateHitTestingSprite();
		HX_STACK_LINE(145)
		if (((::cocktail::core::config::Config_obj::getInstance()->useAdvancedHitTesting == true))){
			HX_STACK_LINE(147)
			this->_rootSprite->addChild(this->_nativeLayersRootSprite);
			HX_STACK_LINE(148)
			this->_rootSprite->addChild(this->hitTestingSprite);
		}
		else{
			HX_STACK_LINE(152)
			this->_rootSprite->addChild(this->hitTestingSprite);
			HX_STACK_LINE(153)
			this->_rootSprite->addChild(this->_nativeLayersRootSprite);
		}
		HX_STACK_LINE(156)
		::nme::Lib_obj::nmeGetCurrent()->addChild(this->_rootSprite);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Platform_obj,initDisplayList,(void))

::String Platform_obj::ALLOW_FULLSCREEN_ATTRIBUTE;


Platform_obj::Platform_obj()
{
}

void Platform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Platform);
	HX_MARK_MEMBER_NAME(_foundHollowedTag,"_foundHollowedTag");
	HX_MARK_MEMBER_NAME(_hollowedTagsBounds,"_hollowedTagsBounds");
	HX_MARK_MEMBER_NAME(hitTestingSprite,"hitTestingSprite");
	HX_MARK_MEMBER_NAME(_nativeLayersRootSprite,"_nativeLayersRootSprite");
	HX_MARK_MEMBER_NAME(_rootSprite,"_rootSprite");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Platform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_foundHollowedTag,"_foundHollowedTag");
	HX_VISIT_MEMBER_NAME(_hollowedTagsBounds,"_hollowedTagsBounds");
	HX_VISIT_MEMBER_NAME(hitTestingSprite,"hitTestingSprite");
	HX_VISIT_MEMBER_NAME(_nativeLayersRootSprite,"_nativeLayersRootSprite");
	HX_VISIT_MEMBER_NAME(_rootSprite,"_rootSprite");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Platform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getEvent") ) { return getEvent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getUIEvent") ) { return getUIEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return fullscreen_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_rootSprite") ) { return _rootSprite; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hitTestLayer") ) { return hitTestLayer_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_innerWidth") ) { return get_innerWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeResize") ) { return onNativeResize_dyn(); }
		if (HX_FIELD_EQ(inName,"exitFullscreen") ) { return exitFullscreen_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onConfigChanged") ) { return onConfigChanged_dyn(); }
		if (HX_FIELD_EQ(inName,"get_innerHeight") ) { return get_innerHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"enterFullscreen") ) { return enterFullscreen_dyn(); }
		if (HX_FIELD_EQ(inName,"initDisplayList") ) { return initDisplayList_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hitTestingSprite") ) { return hitTestingSprite; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"fullScreenEnabled") ) { return fullScreenEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"_foundHollowedTag") ) { return _foundHollowedTag; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_hollowedTagsBounds") ) { return _hollowedTagsBounds; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"fillHitTestingSprite") ) { return fillHitTestingSprite_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"resetHitTestingSprite") ) { return resetHitTestingSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
		if (HX_FIELD_EQ(inName,"getInitialNativeLayer") ) { return getInitialNativeLayer_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateHitTestingSprite") ) { return updateHitTestingSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"updateHitTestingBounds") ) { return updateHitTestingBounds_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_nativeLayersRootSprite") ) { return _nativeLayersRootSprite; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"doUpdateHitTestingBounds") ) { return doUpdateHitTestingBounds_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"ALLOW_FULLSCREEN_ATTRIBUTE") ) { return ALLOW_FULLSCREEN_ATTRIBUTE; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"hitTestChildrenInSameStackingContext") ) { return hitTestChildrenInSameStackingContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Platform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"_rootSprite") ) { _rootSprite=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hitTestingSprite") ) { hitTestingSprite=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_foundHollowedTag") ) { _foundHollowedTag=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_hollowedTagsBounds") ) { _hollowedTagsBounds=inValue.Cast< Array< ::cocktail::core::geom::RectangleVO > >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_nativeLayersRootSprite") ) { _nativeLayersRootSprite=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"ALLOW_FULLSCREEN_ATTRIBUTE") ) { ALLOW_FULLSCREEN_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Platform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_foundHollowedTag"));
	outFields->push(HX_CSTRING("_hollowedTagsBounds"));
	outFields->push(HX_CSTRING("hitTestingSprite"));
	outFields->push(HX_CSTRING("_nativeLayersRootSprite"));
	outFields->push(HX_CSTRING("_rootSprite"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ALLOW_FULLSCREEN_ATTRIBUTE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onConfigChanged"),
	HX_CSTRING("hitTestChildrenInSameStackingContext"),
	HX_CSTRING("doUpdateHitTestingBounds"),
	HX_CSTRING("hitTestLayer"),
	HX_CSTRING("fillHitTestingSprite"),
	HX_CSTRING("resetHitTestingSprite"),
	HX_CSTRING("get_innerWidth"),
	HX_CSTRING("get_innerHeight"),
	HX_CSTRING("updateHitTestingSprite"),
	HX_CSTRING("onNativeResize"),
	HX_CSTRING("getEvent"),
	HX_CSTRING("getUIEvent"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	HX_CSTRING("updateHitTestingBounds"),
	HX_CSTRING("getInitialNativeLayer"),
	HX_CSTRING("fullscreen"),
	HX_CSTRING("fullScreenEnabled"),
	HX_CSTRING("exitFullscreen"),
	HX_CSTRING("enterFullscreen"),
	HX_CSTRING("open"),
	HX_CSTRING("initDisplayList"),
	HX_CSTRING("_foundHollowedTag"),
	HX_CSTRING("_hollowedTagsBounds"),
	HX_CSTRING("hitTestingSprite"),
	HX_CSTRING("_nativeLayersRootSprite"),
	HX_CSTRING("_rootSprite"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Platform_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Platform_obj::ALLOW_FULLSCREEN_ATTRIBUTE,"ALLOW_FULLSCREEN_ATTRIBUTE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Platform_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Platform_obj::ALLOW_FULLSCREEN_ATTRIBUTE,"ALLOW_FULLSCREEN_ATTRIBUTE");
};

Class Platform_obj::__mClass;

void Platform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.Platform"), hx::TCanCast< Platform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Platform_obj::__boot()
{
	ALLOW_FULLSCREEN_ATTRIBUTE= HX_CSTRING("allowsFullScreen");
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
