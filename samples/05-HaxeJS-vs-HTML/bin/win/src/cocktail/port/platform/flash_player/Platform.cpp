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
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
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
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_display_StageDisplayState
#include <native/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_native_display_StageQuality
#include <native/display/StageQuality.h>
#endif
#ifndef INCLUDED_native_display_StageScaleMode
#include <native/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_net_URLRequest
#include <native/net/URLRequest.h>
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
HX_STACK_PUSH("Platform::new","cocktail/port/platform/flash_player/Platform.hx",104);
{
	HX_STACK_LINE(105)
	this->initDisplayList();
	HX_STACK_LINE(107)
	super::__construct();
	HX_STACK_LINE(111)
	::nme::Lib_obj::get_current()->get_stage()->set_scaleMode(::native::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_STACK_LINE(115)
	if (((::cocktail::core::config::Config_obj::getInstance()->useLowStageQuality == true))){
		HX_STACK_LINE(116)
		::nme::Lib_obj::get_current()->get_stage()->set_quality(::native::display::StageQuality_obj::LOW_dyn());
	}
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

Void Platform_obj::hitTestChildrenInSameStackingContext( ::cocktail::core::layer::LayerRenderer rootLayer){
{
		HX_STACK_PUSH("Platform::hitTestChildrenInSameStackingContext","cocktail/port/platform/flash_player/Platform.hx",462);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayer,"rootLayer");
		HX_STACK_LINE(463)
		::cocktail::core::layer::LayerRenderer child = rootLayer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(464)
		while(((child != null()))){
			HX_STACK_LINE(466)
			if (((child->hasOwnStackingContext == false))){
				HX_STACK_LINE(468)
				this->hitTestLayer(child);
				HX_STACK_LINE(469)
				this->hitTestChildrenInSameStackingContext(child);
			}
			else{
				HX_STACK_LINE(472)
				{
					::cocktail::core::css::CSSPropertyValue _switch_1 = (child->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
					switch((_switch_1)->GetIndex()){
						case 0: {
							int value = _switch_1->__Param(0);
{
								HX_STACK_LINE(475)
								if (((value == (int)0))){
									HX_STACK_LINE(477)
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
			HX_STACK_LINE(484)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,hitTestChildrenInSameStackingContext,(void))

Void Platform_obj::doUpdateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext){
{
		HX_STACK_PUSH("Platform::doUpdateHitTestingBounds","cocktail/port/platform/flash_player/Platform.hx",417);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stackingContext,"stackingContext");
		HX_STACK_LINE(418)
		this->hitTestLayer(stackingContext->layerRenderer);
		HX_STACK_LINE(420)
		::cocktail::core::stacking::StackingContext child = stackingContext->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(422)
		bool hasHitTestedAutoAndZeroLayers = false;		HX_STACK_VAR(hasHitTestedAutoAndZeroLayers,"hasHitTestedAutoAndZeroLayers");
		HX_STACK_LINE(424)
		while(((child != null()))){
			HX_STACK_LINE(426)
			{
				::cocktail::core::css::CSSPropertyValue _switch_2 = (child->layerRenderer->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
				switch((_switch_2)->GetIndex()){
					case 0: {
						int value = _switch_2->__Param(0);
{
							HX_STACK_LINE(428)
							if (((value == (int)0))){
							}
							else{
								HX_STACK_LINE(436)
								if (((bool((value > (int)0)) && bool((hasHitTestedAutoAndZeroLayers == false))))){
									HX_STACK_LINE(438)
									this->hitTestChildrenInSameStackingContext(stackingContext->layerRenderer);
									HX_STACK_LINE(439)
									hasHitTestedAutoAndZeroLayers = true;
								}
								HX_STACK_LINE(442)
								this->doUpdateHitTestingBounds(child);
							}
						}
					}
					;break;
					default: {
					}
				}
			}
			HX_STACK_LINE(448)
			child = child->nextSibling;
		}
		HX_STACK_LINE(451)
		if (((hasHitTestedAutoAndZeroLayers == false))){
			HX_STACK_LINE(452)
			this->hitTestChildrenInSameStackingContext(stackingContext->layerRenderer);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,doUpdateHitTestingBounds,(void))

Void Platform_obj::hitTestLayer( ::cocktail::core::layer::LayerRenderer layerRenderer){
{
		HX_STACK_PUSH("Platform::hitTestLayer","cocktail/port/platform/flash_player/Platform.hx",393);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layerRenderer,"layerRenderer");
		HX_STACK_LINE(393)
		if (((layerRenderer->rootElementRenderer->domNode->tagName == HX_CSTRING("OBJECT")))){
			HX_STACK_LINE(396)
			this->_foundObjectTag = true;
			HX_STACK_LINE(397)
			this->_objectTagsBounds->push(layerRenderer->bounds);
			HX_STACK_LINE(398)
			this->resetHitTestingSprite();
		}
		else{
			HX_STACK_LINE(401)
			if (((this->_foundObjectTag == true))){
				HX_STACK_LINE(403)
				this->fillHitTestingSprite(layerRenderer->bounds);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,hitTestLayer,(void))

Void Platform_obj::fillHitTestingSprite( ::cocktail::core::geom::RectangleVO rect){
{
		HX_STACK_PUSH("Platform::fillHitTestingSprite","cocktail/port/platform/flash_player/Platform.hx",381);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_LINE(382)
		this->hitTestingSprite->get_graphics()->beginFill((int)0,0.0);
		HX_STACK_LINE(383)
		this->hitTestingSprite->get_graphics()->drawRect(rect->x,rect->y,rect->width,rect->height);
		HX_STACK_LINE(384)
		this->hitTestingSprite->get_graphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Platform_obj,fillHitTestingSprite,(void))

Void Platform_obj::resetHitTestingSprite( ){
{
		HX_STACK_PUSH("Platform::resetHitTestingSprite","cocktail/port/platform/flash_player/Platform.hx",361);
		HX_STACK_THIS(this);
		HX_STACK_LINE(362)
		this->hitTestingSprite->get_graphics()->clear();
		HX_STACK_LINE(363)
		this->hitTestingSprite->get_graphics()->beginFill((int)0,0.0);
		HX_STACK_LINE(364)
		this->hitTestingSprite->get_graphics()->drawRect((int)0,(int)0,this->get_innerWidth(),this->get_innerHeight());
		HX_STACK_LINE(367)
		{
			HX_STACK_LINE(367)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->_objectTagsBounds->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(367)
			while(((_g1 < _g))){
				HX_STACK_LINE(367)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(369)
				this->hitTestingSprite->get_graphics()->drawRect(this->_objectTagsBounds->__get(i)->x,this->_objectTagsBounds->__get(i)->y,this->_objectTagsBounds->__get(i)->width,this->_objectTagsBounds->__get(i)->height);
			}
		}
		HX_STACK_LINE(373)
		this->hitTestingSprite->get_graphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Platform_obj,resetHitTestingSprite,(void))

int Platform_obj::get_innerWidth( ){
	HX_STACK_PUSH("Platform::get_innerWidth","cocktail/port/platform/flash_player/Platform.hx",345);
	HX_STACK_THIS(this);
	HX_STACK_LINE(345)
	return ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();
}


int Platform_obj::get_innerHeight( ){
	HX_STACK_PUSH("Platform::get_innerHeight","cocktail/port/platform/flash_player/Platform.hx",337);
	HX_STACK_THIS(this);
	HX_STACK_LINE(337)
	return ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();
}


Void Platform_obj::updateHitTestingSprite( ){
{
		HX_STACK_PUSH("Platform::updateHitTestingSprite","cocktail/port/platform/flash_player/Platform.hx",322);
		HX_STACK_THIS(this);
		HX_STACK_LINE(323)
		this->hitTestingSprite->get_graphics()->clear();
		HX_STACK_LINE(324)
		this->hitTestingSprite->get_graphics()->beginFill((int)0,(int)0);
		HX_STACK_LINE(325)
		this->hitTestingSprite->get_graphics()->drawRect((int)0,(int)0,this->get_innerWidth(),this->get_innerHeight());
		HX_STACK_LINE(326)
		this->hitTestingSprite->get_graphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Platform_obj,updateHitTestingSprite,(void))

Void Platform_obj::onNativeResize( Dynamic event){
{
		HX_STACK_PUSH("Platform::onNativeResize","cocktail/port/platform/flash_player/Platform.hx",306);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(307)
		this->updateHitTestingSprite();
		HX_STACK_LINE(308)
		this->super::onNativeResize(event);
	}
return null();
}


::cocktail::core::event::Event Platform_obj::getEvent( Dynamic event){
	HX_STACK_PUSH("Platform::getEvent","cocktail/port/platform/flash_player/Platform.hx",290);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(291)
	::cocktail::core::event::Event fullScreenChangeEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(fullScreenChangeEvent,"fullScreenChangeEvent");
	HX_STACK_LINE(292)
	fullScreenChangeEvent->initEvent(HX_CSTRING("fullscreenchange"),false,false);
	HX_STACK_LINE(294)
	return fullScreenChangeEvent;
}


::cocktail::core::event::UIEvent Platform_obj::getUIEvent( Dynamic event){
	HX_STACK_PUSH("Platform::getUIEvent","cocktail/port/platform/flash_player/Platform.hx",276);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(277)
	::cocktail::core::event::UIEvent resizeEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(resizeEvent,"resizeEvent");
	HX_STACK_LINE(278)
	resizeEvent->initUIEvent(HX_CSTRING("resize"),false,false,null(),0.0);
	HX_STACK_LINE(280)
	return resizeEvent;
}


Void Platform_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("Platform::removeNativeListeners","cocktail/port/platform/flash_player/Platform.hx",260);
		HX_STACK_THIS(this);
		HX_STACK_LINE(260)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::Event_obj::RESIZE,this->onNativeResize_dyn(),null());
	}
return null();
}


Void Platform_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("Platform::setNativeListeners","cocktail/port/platform/flash_player/Platform.hx",247);
		HX_STACK_THIS(this);
		HX_STACK_LINE(247)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::RESIZE,this->onNativeResize_dyn(),null(),null(),null());
	}
return null();
}


Void Platform_obj::updateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext){
{
		HX_STACK_PUSH("Platform::updateHitTestingBounds","cocktail/port/platform/flash_player/Platform.hx",225);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stackingContext,"stackingContext");
		HX_STACK_LINE(227)
		if (((::cocktail::core::config::Config_obj::getInstance()->useAdvancedHitTesting == false))){
			HX_STACK_LINE(228)
			return null();
		}
		HX_STACK_LINE(232)
		this->_objectTagsBounds = Array_obj< ::cocktail::core::geom::RectangleVO >::__new();
		HX_STACK_LINE(233)
		this->_foundObjectTag = false;
		HX_STACK_LINE(235)
		this->updateHitTestingSprite();
		HX_STACK_LINE(236)
		this->doUpdateHitTestingBounds(stackingContext);
	}
return null();
}


::native::display::DisplayObjectContainer Platform_obj::getInitialNativeLayer( ){
	HX_STACK_PUSH("Platform::getInitialNativeLayer","cocktail/port/platform/flash_player/Platform.hx",199);
	HX_STACK_THIS(this);
	HX_STACK_LINE(199)
	return this->_nativeLayersRootSprite;
}


bool Platform_obj::fullscreen( ){
	HX_STACK_PUSH("Platform::fullscreen","cocktail/port/platform/flash_player/Platform.hx",191);
	HX_STACK_THIS(this);
	HX_STACK_LINE(191)
	return (::nme::Lib_obj::get_current()->get_stage()->get_displayState() == ::native::display::StageDisplayState_obj::FULL_SCREEN_dyn());
}


bool Platform_obj::fullScreenEnabled( ){
	HX_STACK_PUSH("Platform::fullScreenEnabled","cocktail/port/platform/flash_player/Platform.hx",183);
	HX_STACK_THIS(this);
	HX_STACK_LINE(183)
	return ::Reflect_obj::hasField(::nme::Lib_obj::get_current()->get_stage(),HX_CSTRING("allowsFullScreen"));
}


Void Platform_obj::exitFullscreen( ){
{
		HX_STACK_PUSH("Platform::exitFullscreen","cocktail/port/platform/flash_player/Platform.hx",173);
		HX_STACK_THIS(this);
		HX_STACK_LINE(173)
		::nme::Lib_obj::get_current()->get_stage()->set_displayState(::native::display::StageDisplayState_obj::NORMAL_dyn());
	}
return null();
}


Void Platform_obj::enterFullscreen( ){
{
		HX_STACK_PUSH("Platform::enterFullscreen","cocktail/port/platform/flash_player/Platform.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_LINE(165)
		::nme::Lib_obj::get_current()->get_stage()->set_displayState(::native::display::StageDisplayState_obj::FULL_SCREEN_dyn());
	}
return null();
}


Void Platform_obj::open( ::String url,::String name){
{
		HX_STACK_PUSH("Platform::open","cocktail/port/platform/flash_player/Platform.hx",157);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(157)
		::nme::Lib_obj::getURL(::native::net::URLRequest_obj::__new(url),name);
	}
return null();
}


Void Platform_obj::initDisplayList( ){
{
		HX_STACK_PUSH("Platform::initDisplayList","cocktail/port/platform/flash_player/Platform.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_LINE(127)
		this->_rootSprite = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(129)
		this->_nativeLayersRootSprite = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(132)
		this->hitTestingSprite = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(133)
		this->updateHitTestingSprite();
		HX_STACK_LINE(135)
		if (((::cocktail::core::config::Config_obj::getInstance()->useAdvancedHitTesting == true))){
			HX_STACK_LINE(137)
			this->_rootSprite->addChild(this->_nativeLayersRootSprite);
			HX_STACK_LINE(138)
			this->_rootSprite->addChild(this->hitTestingSprite);
		}
		else{
			HX_STACK_LINE(142)
			this->_rootSprite->addChild(this->hitTestingSprite);
			HX_STACK_LINE(143)
			this->_rootSprite->addChild(this->_nativeLayersRootSprite);
		}
		HX_STACK_LINE(146)
		::nme::Lib_obj::get_current()->addChild(this->_rootSprite);
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
	HX_MARK_MEMBER_NAME(_foundObjectTag,"_foundObjectTag");
	HX_MARK_MEMBER_NAME(_objectTagsBounds,"_objectTagsBounds");
	HX_MARK_MEMBER_NAME(hitTestingSprite,"hitTestingSprite");
	HX_MARK_MEMBER_NAME(_nativeLayersRootSprite,"_nativeLayersRootSprite");
	HX_MARK_MEMBER_NAME(_rootSprite,"_rootSprite");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Platform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_foundObjectTag,"_foundObjectTag");
	HX_VISIT_MEMBER_NAME(_objectTagsBounds,"_objectTagsBounds");
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
		if (HX_FIELD_EQ(inName,"get_innerHeight") ) { return get_innerHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"enterFullscreen") ) { return enterFullscreen_dyn(); }
		if (HX_FIELD_EQ(inName,"initDisplayList") ) { return initDisplayList_dyn(); }
		if (HX_FIELD_EQ(inName,"_foundObjectTag") ) { return _foundObjectTag; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hitTestingSprite") ) { return hitTestingSprite; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"fullScreenEnabled") ) { return fullScreenEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"_objectTagsBounds") ) { return _objectTagsBounds; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
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
		if (HX_FIELD_EQ(inName,"_rootSprite") ) { _rootSprite=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_foundObjectTag") ) { _foundObjectTag=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hitTestingSprite") ) { hitTestingSprite=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_objectTagsBounds") ) { _objectTagsBounds=inValue.Cast< Array< ::cocktail::core::geom::RectangleVO > >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_nativeLayersRootSprite") ) { _nativeLayersRootSprite=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"ALLOW_FULLSCREEN_ATTRIBUTE") ) { ALLOW_FULLSCREEN_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Platform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_foundObjectTag"));
	outFields->push(HX_CSTRING("_objectTagsBounds"));
	outFields->push(HX_CSTRING("hitTestingSprite"));
	outFields->push(HX_CSTRING("_nativeLayersRootSprite"));
	outFields->push(HX_CSTRING("_rootSprite"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ALLOW_FULLSCREEN_ATTRIBUTE"),
	String(null()) };

static ::String sMemberFields[] = {
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
	HX_CSTRING("_foundObjectTag"),
	HX_CSTRING("_objectTagsBounds"),
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
