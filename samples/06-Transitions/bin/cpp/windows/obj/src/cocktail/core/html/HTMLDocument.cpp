#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_DefaultCSSStyleSheet
#include <cocktail/core/css/DefaultCSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_MatchedPseudoClassesVO
#include <cocktail/core/css/MatchedPseudoClassesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleManager
#include <cocktail/core/css/StyleManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
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
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchEvent
#include <cocktail/core/event/TouchEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchList
#include <cocktail/core/event/TouchList.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_WheelEvent
#include <cocktail/core/event/WheelEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_focus_FocusManager
#include <cocktail/core/focus/FocusManager.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_hittest_HitTestManager
#include <cocktail/core/hittest/HitTestManager.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLAnchorElement
#include <cocktail/core/html/HTMLAnchorElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLAudioElement
#include <cocktail/core/html/HTMLAudioElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBRElement
#include <cocktail/core/html/HTMLBRElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLFormElement
#include <cocktail/core/html/HTMLFormElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLHtmlElement
#include <cocktail/core/html/HTMLHtmlElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#include <cocktail/core/html/HTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#include <cocktail/core/html/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLLinkElement
#include <cocktail/core/html/HTMLLinkElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLMediaElement
#include <cocktail/core/html/HTMLMediaElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLMetaElement
#include <cocktail/core/html/HTMLMetaElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLObjectElement
#include <cocktail/core/html/HTMLObjectElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLParamElement
#include <cocktail/core/html/HTMLParamElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLSourceElement
#include <cocktail/core/html/HTMLSourceElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLStyleElement
#include <cocktail/core/html/HTMLStyleElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLVideoElement
#include <cocktail/core/html/HTMLVideoElement.h>
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
#ifndef INCLUDED_cocktail_core_layout_LayoutManager
#include <cocktail/core/layout/LayoutManager.h>
#endif
#ifndef INCLUDED_cocktail_core_multitouch_MultiTouchManager
#include <cocktail/core/multitouch/MultiTouchManager.h>
#endif
#ifndef INCLUDED_cocktail_core_parser_DOMParser
#include <cocktail/core/parser/DOMParser.h>
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
namespace html{

Void HTMLDocument_obj::__construct(::cocktail::core::window::Window window)
{
HX_STACK_PUSH("HTMLDocument::new","cocktail/core/html/HTMLDocument.hx",253);
{
	HX_STACK_LINE(254)
	super::__construct();
	HX_STACK_LINE(258)
	if (((window == null()))){
		HX_STACK_LINE(259)
		window = ::cocktail::core::window::Window_obj::__new();
	}
	HX_STACK_LINE(263)
	this->window = window;
	HX_STACK_LINE(265)
	this->init();
}
;
	return null();
}

HTMLDocument_obj::~HTMLDocument_obj() { }

Dynamic HTMLDocument_obj::__CreateEmpty() { return  new HTMLDocument_obj; }
hx::ObjectPtr< HTMLDocument_obj > HTMLDocument_obj::__new(::cocktail::core::window::Window window)
{  hx::ObjectPtr< HTMLDocument_obj > result = new HTMLDocument_obj();
	result->__construct(window);
	return result;}

Dynamic HTMLDocument_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLDocument_obj > result = new HTMLDocument_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::html::HTMLElement HTMLDocument_obj::get_activeElement( ){
	HX_STACK_PUSH("HTMLDocument::get_activeElement","cocktail/core/html/HTMLDocument.hx",1074);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1074)
	return this->_focusManager->activeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,get_activeElement,return )

::cocktail::core::html::HTMLElement HTMLDocument_obj::set_activeElement( ::cocktail::core::html::HTMLElement newActiveElement){
	HX_STACK_PUSH("HTMLDocument::set_activeElement","cocktail/core/html/HTMLDocument.hx",1065);
	HX_STACK_THIS(this);
	HX_STACK_ARG(newActiveElement,"newActiveElement");
	HX_STACK_LINE(1066)
	this->_focusManager->setActiveElement(newActiveElement,this->body);
	HX_STACK_LINE(1067)
	return this->get_activeElement();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,set_activeElement,return )

::cocktail::core::html::HTMLElement HTMLDocument_obj::getFirstVerticallyScrollableHTMLElement( ::cocktail::core::html::HTMLElement htmlElement,int scrollOffset){
	HX_STACK_PUSH("HTMLDocument::getFirstVerticallyScrollableHTMLElement","cocktail/core/html/HTMLDocument.hx",1044);
	HX_STACK_THIS(this);
	HX_STACK_ARG(htmlElement,"htmlElement");
	HX_STACK_ARG(scrollOffset,"scrollOffset");
	HX_STACK_LINE(1044)
	return htmlElement;
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLDocument_obj,getFirstVerticallyScrollableHTMLElement,return )

::cocktail::core::renderer::ElementRenderer HTMLDocument_obj::getFirstElementRendererWhichCanDispatchMouseEvent( int x,int y){
	HX_STACK_PUSH("HTMLDocument::getFirstElementRendererWhichCanDispatchMouseEvent","cocktail/core/html/HTMLDocument.hx",1009);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(1010)
	::cocktail::core::renderer::ElementRenderer elementRendererAtPoint = this->_hitTestManager->getTopMostElementRendererAtPoint(this->documentElement->elementRenderer->layerRenderer->stackingContext,x,y);		HX_STACK_VAR(elementRendererAtPoint,"elementRendererAtPoint");
	HX_STACK_LINE(1014)
	if (((elementRendererAtPoint == null()))){
		HX_STACK_LINE(1015)
		return null();
	}
	HX_STACK_LINE(1019)
	while(((bool((elementRendererAtPoint->domNode->get_nodeType() != (int)1)) || bool((elementRendererAtPoint->isAnonymousBlockBox() == true))))){
		HX_STACK_LINE(1021)
		elementRendererAtPoint = elementRendererAtPoint->parentNode;
		HX_STACK_LINE(1022)
		if (((elementRendererAtPoint == null()))){
			HX_STACK_LINE(1023)
			return null();
		}
	}
	HX_STACK_LINE(1028)
	return elementRendererAtPoint;
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLDocument_obj,getFirstElementRendererWhichCanDispatchMouseEvent,return )

::cocktail::core::html::HTMLElement HTMLDocument_obj::set_fullscreenElement( ::cocktail::core::html::HTMLElement value){
	HX_STACK_PUSH("HTMLDocument::set_fullscreenElement","cocktail/core/html/HTMLDocument.hx",966);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(970)
	if (((value == null()))){
		HX_STACK_LINE(972)
		this->fullscreenElement = null();
		HX_STACK_LINE(973)
		return value;
	}
	HX_STACK_LINE(977)
	if (((this->fullscreenElement != null()))){
		HX_STACK_LINE(978)
		return this->fullscreenElement;
	}
	HX_STACK_LINE(982)
	this->fullscreenElement = value;
	HX_STACK_LINE(987)
	if (((this->onEnterFullscreen_dyn() != null()))){
		HX_STACK_LINE(988)
		this->onEnterFullscreen();
	}
	HX_STACK_LINE(993)
	::cocktail::core::event::Event fullscreenEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(fullscreenEvent,"fullscreenEvent");
	HX_STACK_LINE(994)
	fullscreenEvent->initEvent(HX_CSTRING("fullscreenchange"),true,false);
	HX_STACK_LINE(996)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,set_fullscreenElement,return )

bool HTMLDocument_obj::get_fullscreenEnabled( ){
	HX_STACK_PUSH("HTMLDocument::get_fullscreenEnabled","cocktail/core/html/HTMLDocument.hx",955);
	HX_STACK_THIS(this);
	HX_STACK_LINE(955)
	return this->window->platform->fullScreenEnabled();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,get_fullscreenEnabled,return )

Void HTMLDocument_obj::exitFullscreen( ){
{
		HX_STACK_PUSH("HTMLDocument::exitFullscreen","cocktail/core/html/HTMLDocument.hx",928);
		HX_STACK_THIS(this);
		HX_STACK_LINE(931)
		if (((this->fullscreenElement == null()))){
			HX_STACK_LINE(932)
			return null();
		}
		HX_STACK_LINE(936)
		this->set_fullscreenElement(null());
		HX_STACK_LINE(941)
		if (((this->onExitFullscreen_dyn() != null()))){
			HX_STACK_LINE(942)
			this->onExitFullscreen();
		}
		HX_STACK_LINE(947)
		::cocktail::core::event::Event fullscreenEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(fullscreenEvent,"fullscreenEvent");
		HX_STACK_LINE(948)
		fullscreenEvent->initEvent(HX_CSTRING("fullscreenchange"),true,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,exitFullscreen,(void))

Void HTMLDocument_obj::setMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor){
{
		HX_STACK_PUSH("HTMLDocument::setMouseCursor","cocktail/core/html/HTMLDocument.hx",909);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cursor,"cursor");
		HX_STACK_LINE(909)
		if (((this->onSetMouseCursor_dyn() != null()))){
			HX_STACK_LINE(911)
			this->onSetMouseCursor(cursor);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,setMouseCursor,(void))

Void HTMLDocument_obj::dispatchClickEvent( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_STACK_PUSH("HTMLDocument::dispatchClickEvent","cocktail/core/html/HTMLDocument.hx",886);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mouseEvent,"mouseEvent");
		HX_STACK_LINE(887)
		::cocktail::core::renderer::ElementRenderer elementRendererAtPoint = this->getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent->screenX,mouseEvent->screenY);		HX_STACK_VAR(elementRendererAtPoint,"elementRendererAtPoint");
		HX_STACK_LINE(889)
		::cocktail::core::html::HTMLElement htmlElement = elementRendererAtPoint->domNode;		HX_STACK_VAR(htmlElement,"htmlElement");
		HX_STACK_LINE(892)
		::cocktail::core::event::MouseEvent clickEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(clickEvent,"clickEvent");
		HX_STACK_LINE(893)
		clickEvent->initMouseEvent(HX_CSTRING("click"),true,true,null(),0.0,mouseEvent->screenX,mouseEvent->screenY,mouseEvent->clientX,mouseEvent->clientY,mouseEvent->ctrlKey,mouseEvent->altKey,mouseEvent->shiftKey,mouseEvent->metaKey,mouseEvent->button,null());
		HX_STACK_LINE(897)
		htmlElement->triggerActivationBehaviour(clickEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,dispatchClickEvent,(void))

Void HTMLDocument_obj::onPlatformTouchEvent( ::cocktail::core::event::TouchEvent touchEvent){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformTouchEvent","cocktail/core/html/HTMLDocument.hx",803);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touchEvent,"touchEvent");
		HX_STACK_LINE(806)
		Dynamic touch = touchEvent->touches->item((int)0);		HX_STACK_VAR(touch,"touch");
		HX_STACK_LINE(807)
		::cocktail::core::renderer::ElementRenderer elementAtTouchPoint = this->getFirstElementRendererWhichCanDispatchMouseEvent(touch->__Field(HX_CSTRING("screenX"),true),touch->__Field(HX_CSTRING("screenY"),true));		HX_STACK_VAR(elementAtTouchPoint,"elementAtTouchPoint");
		HX_STACK_LINE(811)
		this->_multiTouchManager->setUpTouchEvent(touchEvent,elementAtTouchPoint->domNode);
		HX_STACK_LINE(814)
		elementAtTouchPoint->domNode->dispatchEvent(touchEvent);
		HX_STACK_LINE(818)
		if (((this->_shouldDispatchClickOnNextMouseUp == true))){
			HX_STACK_LINE(819)
			::String _switch_1 = (touchEvent->type);
			if (  ( _switch_1==HX_CSTRING("touchstart"))){
				HX_STACK_LINE(822)
				if (((touchEvent->defaultPrevented == true))){
					HX_STACK_LINE(825)
					this->_shouldDispatchClickOnNextMouseUp = false;
				}
				else{
					HX_STACK_LINE(829)
					if (((touchEvent->touches->get_length() > (int)1))){
					}
					else{
						HX_STACK_LINE(837)
						this->_lastTouchStartPosition->x = touchEvent->touches->item((int)0)->__Field(HX_CSTRING("screenX"),true);
						HX_STACK_LINE(838)
						this->_lastTouchStartPosition->y = touchEvent->touches->item((int)0)->__Field(HX_CSTRING("screenY"),true);
					}
				}
			}
			else if (  ( _switch_1==HX_CSTRING("touchmove"))){
				HX_STACK_LINE(841)
				if (((touchEvent->defaultPrevented == true))){
					HX_STACK_LINE(844)
					this->_shouldDispatchClickOnNextMouseUp = false;
				}
				else{
					HX_STACK_LINE(852)
					Float yOffset = (touchEvent->touches->item((int)0)->__Field(HX_CSTRING("screenY"),true) - this->_lastTouchStartPosition->y);		HX_STACK_VAR(yOffset,"yOffset");
					HX_STACK_LINE(853)
					if (((::Math_obj::abs(yOffset) > ::cocktail::core::config::Config_obj::getInstance()->touchMovePreventClickDistance))){
						HX_STACK_LINE(854)
						this->_shouldDispatchClickOnNextMouseUp = false;
					}
					else{
						HX_STACK_LINE(859)
						Float xOffset = (touchEvent->touches->item((int)0)->__Field(HX_CSTRING("screenX"),true) - this->_lastTouchStartPosition->x);		HX_STACK_VAR(xOffset,"xOffset");
						HX_STACK_LINE(860)
						if (((::Math_obj::abs(xOffset) > ::cocktail::core::config::Config_obj::getInstance()->touchMovePreventClickDistance))){
							HX_STACK_LINE(861)
							this->_shouldDispatchClickOnNextMouseUp = false;
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformTouchEvent,(void))

Void HTMLDocument_obj::onPlatformKeyUpEvent( ::cocktail::core::event::KeyboardEvent keyboardEvent){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformKeyUpEvent","cocktail/core/html/HTMLDocument.hx",792);
		HX_STACK_THIS(this);
		HX_STACK_ARG(keyboardEvent,"keyboardEvent");
		HX_STACK_LINE(792)
		this->get_activeElement()->dispatchEvent(keyboardEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformKeyUpEvent,(void))

Void HTMLDocument_obj::onPlatformKeyDownEvent( ::cocktail::core::event::KeyboardEvent keyboardEvent){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformKeyDownEvent","cocktail/core/html/HTMLDocument.hx",765);
		HX_STACK_THIS(this);
		HX_STACK_ARG(keyboardEvent,"keyboardEvent");
		HX_STACK_LINE(766)
		this->get_activeElement()->dispatchEvent(keyboardEvent);
		HX_STACK_LINE(769)
		switch( (int)(::Std_obj::parseInt(keyboardEvent->keyChar))){
			case (int)9: {
				HX_STACK_LINE(771)
				if (((keyboardEvent->defaultPrevented == false))){
					HX_STACK_LINE(774)
					this->set_activeElement(this->_focusManager->getNextFocusedElement((keyboardEvent->shiftKey == true),this->body,this->get_activeElement()));
				}
			}
			;break;
			case (int)13: case (int)32: {
				HX_STACK_LINE(778)
				if (((keyboardEvent->defaultPrevented == false))){
					HX_STACK_LINE(781)
					this->get_activeElement()->triggerActivationBehaviour(null());
				}
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformKeyDownEvent,(void))

Void HTMLDocument_obj::onPlatformMouseMoveEvent( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformMouseMoveEvent","cocktail/core/html/HTMLDocument.hx",694);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mouseEvent,"mouseEvent");
		HX_STACK_LINE(697)
		if (((this->documentElement->elementRenderer == null()))){
			HX_STACK_LINE(698)
			return null();
		}
		HX_STACK_LINE(702)
		::cocktail::core::renderer::ElementRenderer elementRendererAtPoint = this->getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent->screenX,mouseEvent->screenY);		HX_STACK_VAR(elementRendererAtPoint,"elementRendererAtPoint");
		HX_STACK_LINE(704)
		if (((elementRendererAtPoint == null()))){
			HX_STACK_LINE(705)
			return null();
		}
		HX_STACK_LINE(709)
		if (((this->_hoveredElementRenderer != elementRendererAtPoint))){
			HX_STACK_LINE(711)
			::cocktail::core::renderer::ElementRenderer oldHoveredElementRenderer = this->_hoveredElementRenderer;		HX_STACK_VAR(oldHoveredElementRenderer,"oldHoveredElementRenderer");
			HX_STACK_LINE(713)
			if (((this->_hoveredElementRenderer != null()))){
				HX_STACK_LINE(716)
				::cocktail::core::event::MouseEvent mouseOutEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(mouseOutEvent,"mouseOutEvent");
				HX_STACK_LINE(717)
				mouseOutEvent->initMouseEvent(HX_CSTRING("mouseout"),true,true,null(),0.0,mouseEvent->screenX,mouseEvent->screenY,mouseEvent->clientX,mouseEvent->clientY,mouseEvent->ctrlKey,mouseEvent->altKey,mouseEvent->shiftKey,mouseEvent->metaKey,mouseEvent->button,elementRendererAtPoint->domNode);
				HX_STACK_LINE(720)
				this->_hoveredElementRenderer->domNode->dispatchEvent(mouseOutEvent);
				HX_STACK_LINE(722)
				oldHoveredElementRenderer->domNode->invalidateStyleDeclaration(false);
			}
			HX_STACK_LINE(725)
			this->_hoveredElementRenderer = elementRendererAtPoint;
			HX_STACK_LINE(728)
			::cocktail::core::html::HTMLElement relatedTarget = null();		HX_STACK_VAR(relatedTarget,"relatedTarget");
			HX_STACK_LINE(729)
			if (((this->_hoveredElementRenderer != null()))){
				HX_STACK_LINE(730)
				relatedTarget = this->_hoveredElementRenderer->domNode;
			}
			HX_STACK_LINE(735)
			::cocktail::core::event::MouseEvent mouseOverEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(mouseOverEvent,"mouseOverEvent");
			HX_STACK_LINE(736)
			mouseOverEvent->initMouseEvent(HX_CSTRING("mouseover"),true,true,null(),0.0,mouseEvent->screenX,mouseEvent->screenY,mouseEvent->clientX,mouseEvent->clientY,mouseEvent->ctrlKey,mouseEvent->shiftKey,mouseEvent->altKey,mouseEvent->metaKey,mouseEvent->button,relatedTarget);
			HX_STACK_LINE(739)
			elementRendererAtPoint->domNode->dispatchEvent(mouseOverEvent);
			HX_STACK_LINE(743)
			elementRendererAtPoint->domNode->invalidateStyleDeclaration(false);
			HX_STACK_LINE(748)
			this->_shouldDispatchClickOnNextMouseUp = false;
			HX_STACK_LINE(752)
			this->setMouseCursor(elementRendererAtPoint->domNode->coreStyle->getComputedOrInitialProperty((int)54));
		}
		HX_STACK_LINE(755)
		elementRendererAtPoint->domNode->dispatchEvent(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformMouseMoveEvent,(void))

Void HTMLDocument_obj::onPlatformMouseWheelEvent( ::cocktail::core::event::WheelEvent wheelEvent){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformMouseWheelEvent","cocktail/core/html/HTMLDocument.hx",661);
		HX_STACK_THIS(this);
		HX_STACK_ARG(wheelEvent,"wheelEvent");
		HX_STACK_LINE(662)
		::cocktail::core::renderer::ElementRenderer elementRendererAtPoint = this->getFirstElementRendererWhichCanDispatchMouseEvent(wheelEvent->screenX,wheelEvent->screenY);		HX_STACK_VAR(elementRendererAtPoint,"elementRendererAtPoint");
		HX_STACK_LINE(663)
		elementRendererAtPoint->domNode->dispatchEvent(wheelEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformMouseWheelEvent,(void))

Void HTMLDocument_obj::onPlatformMouseLeaveEvent( ::cocktail::core::event::Event event){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformMouseLeaveEvent","cocktail/core/html/HTMLDocument.hx",637);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(637)
		if (((this->_hoveredElementRenderer != null()))){
			HX_STACK_LINE(640)
			::cocktail::core::renderer::ElementRenderer oldHoveredElementRenderer = this->_hoveredElementRenderer;		HX_STACK_VAR(oldHoveredElementRenderer,"oldHoveredElementRenderer");
			HX_STACK_LINE(642)
			::cocktail::core::event::MouseEvent mouseOutEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(mouseOutEvent,"mouseOutEvent");
			HX_STACK_LINE(643)
			mouseOutEvent->initMouseEvent(HX_CSTRING("mouseout"),true,true,null(),(int)0,(int)0,(int)0,(int)0,(int)0,false,false,false,false,(int)0,null());
			HX_STACK_LINE(646)
			this->_hoveredElementRenderer->domNode->dispatchEvent(mouseOutEvent);
			HX_STACK_LINE(647)
			oldHoveredElementRenderer->domNode->invalidateStyleDeclaration(false);
			HX_STACK_LINE(648)
			this->_hoveredElementRenderer = null();
			HX_STACK_LINE(651)
			this->setMouseCursor(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformMouseLeaveEvent,(void))

Void HTMLDocument_obj::onPlatformMouseEvent( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_STACK_PUSH("HTMLDocument::onPlatformMouseEvent","cocktail/core/html/HTMLDocument.hx",580);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mouseEvent,"mouseEvent");
		HX_STACK_LINE(583)
		::String eventType = mouseEvent->type;		HX_STACK_VAR(eventType,"eventType");
		HX_STACK_LINE(585)
		::cocktail::core::renderer::ElementRenderer elementRendererAtPoint = this->getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent->screenX,mouseEvent->screenY);		HX_STACK_VAR(elementRendererAtPoint,"elementRendererAtPoint");
		HX_STACK_LINE(587)
		if (((elementRendererAtPoint == null()))){
			HX_STACK_LINE(588)
			return null();
		}
		HX_STACK_LINE(592)
		elementRendererAtPoint->domNode->dispatchEvent(mouseEvent);
		HX_STACK_LINE(594)
		::String _switch_2 = (eventType);
		if (  ( _switch_2==HX_CSTRING("mousedown"))){
			HX_STACK_LINE(598)
			this->_shouldDispatchClickOnNextMouseUp = true;
			HX_STACK_LINE(601)
			this->_mousedDownedElementRenderer = elementRendererAtPoint;
			HX_STACK_LINE(603)
			elementRendererAtPoint->domNode->invalidateStyleDeclaration(false);
		}
		else if (  ( _switch_2==HX_CSTRING("mouseup"))){
			HX_STACK_LINE(609)
			if (((this->_shouldDispatchClickOnNextMouseUp == true))){
				HX_STACK_LINE(610)
				this->dispatchClickEvent(mouseEvent);
			}
			HX_STACK_LINE(617)
			if (((this->_mousedDownedElementRenderer != null()))){
				HX_STACK_LINE(619)
				this->_mousedDownedElementRenderer->domNode->invalidateStyleDeclaration(false);
				HX_STACK_LINE(620)
				this->_mousedDownedElementRenderer = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onPlatformMouseEvent,(void))

::String HTMLDocument_obj::get_innerHTML( ){
	HX_STACK_PUSH("HTMLDocument::get_innerHTML","cocktail/core/html/HTMLDocument.hx",563);
	HX_STACK_THIS(this);
	HX_STACK_LINE(563)
	return ::cocktail::core::parser::DOMParser_obj::serialize(this->documentElement);
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,get_innerHTML,return )

::String HTMLDocument_obj::set_innerHTML( ::String value){
	HX_STACK_PUSH("HTMLDocument::set_innerHTML","cocktail/core/html/HTMLDocument.hx",549);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(551)
	::cocktail::core::html::HTMLElement node = ::cocktail::core::parser::DOMParser_obj::parse(value,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(552)
	this->documentElement = node;
	HX_STACK_LINE(553)
	this->initBody(this->documentElement->getElementsByTagName(HX_CSTRING("BODY"))->__get((int)0));
	HX_STACK_LINE(555)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,set_innerHTML,return )

::cocktail::core::css::MatchedPseudoClassesVO HTMLDocument_obj::getMatchedPseudoClassesVO( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("HTMLDocument::getMatchedPseudoClassesVO","cocktail/core/html/HTMLDocument.hx",442);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(443)
	bool hover = false;		HX_STACK_VAR(hover,"hover");
	HX_STACK_LINE(444)
	bool focus = false;		HX_STACK_VAR(focus,"focus");
	HX_STACK_LINE(445)
	bool active = false;		HX_STACK_VAR(active,"active");
	HX_STACK_LINE(446)
	bool link = false;		HX_STACK_VAR(link,"link");
	HX_STACK_LINE(447)
	bool enabled = false;		HX_STACK_VAR(enabled,"enabled");
	HX_STACK_LINE(448)
	bool disabled = false;		HX_STACK_VAR(disabled,"disabled");
	HX_STACK_LINE(449)
	bool checked = false;		HX_STACK_VAR(checked,"checked");
	HX_STACK_LINE(451)
	if (((this->_hoveredElementRenderer != null()))){
		HX_STACK_LINE(452)
		hover = (this->_hoveredElementRenderer->domNode == node);
	}
	HX_STACK_LINE(457)
	if (((this->get_activeElement() != null()))){
		HX_STACK_LINE(458)
		focus = (this->get_activeElement() == node);
	}
	HX_STACK_LINE(463)
	if (((this->_mousedDownedElementRenderer != null()))){
		HX_STACK_LINE(464)
		active = (this->_mousedDownedElementRenderer->domNode == node);
	}
	HX_STACK_LINE(470)
	if (((bool((node->tagName == HX_CSTRING("A"))) && bool((node->getAttribute(HX_CSTRING("href")) != null()))))){
		HX_STACK_LINE(471)
		link = true;
	}
	HX_STACK_LINE(478)
	if (((node->tagName == HX_CSTRING("INPUT")))){
		HX_STACK_LINE(480)
		::cocktail::core::html::HTMLInputElement inputNode = node;		HX_STACK_VAR(inputNode,"inputNode");
		HX_STACK_LINE(484)
		if ((inputNode->set_disabled(false))){
			HX_STACK_LINE(486)
			enabled = true;
			HX_STACK_LINE(487)
			disabled = false;
		}
		else{
			HX_STACK_LINE(491)
			disabled = true;
			HX_STACK_LINE(492)
			enabled = false;
		}
		HX_STACK_LINE(496)
		if (((bool((inputNode->get_type() == HX_CSTRING("checkbox"))) || bool((inputNode->get_type() == HX_CSTRING("radio")))))){
			HX_STACK_LINE(497)
			if (((inputNode->get_checked() == true))){
				HX_STACK_LINE(499)
				checked = true;
			}
		}
	}
	HX_STACK_LINE(507)
	this->_matchedPseudoClasses->hasClasses = (node->get_className() != HX_CSTRING(""));
	HX_STACK_LINE(510)
	if (((this->_matchedPseudoClasses->hasClasses == true))){
		HX_STACK_LINE(511)
		this->_matchedPseudoClasses->nodeClassList = node->classList;
	}
	HX_STACK_LINE(517)
	this->_matchedPseudoClasses->hasId = (node->get_id() != HX_CSTRING(""));
	HX_STACK_LINE(520)
	if (((this->_matchedPseudoClasses->hasId == true))){
		HX_STACK_LINE(521)
		this->_matchedPseudoClasses->nodeId = node->get_id();
	}
	HX_STACK_LINE(526)
	this->_matchedPseudoClasses->nodeType = node->tagName;
	HX_STACK_LINE(528)
	this->_matchedPseudoClasses->hover = hover;
	HX_STACK_LINE(529)
	this->_matchedPseudoClasses->focus = focus;
	HX_STACK_LINE(530)
	this->_matchedPseudoClasses->active = active;
	HX_STACK_LINE(531)
	this->_matchedPseudoClasses->link = link;
	HX_STACK_LINE(532)
	this->_matchedPseudoClasses->enabled = enabled;
	HX_STACK_LINE(533)
	this->_matchedPseudoClasses->disabled = disabled;
	HX_STACK_LINE(534)
	this->_matchedPseudoClasses->checked = checked;
	HX_STACK_LINE(536)
	return this->_matchedPseudoClasses;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,getMatchedPseudoClassesVO,return )

::cocktail::core::css::CSSStyleDeclaration HTMLDocument_obj::getStyleDeclaration( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("HTMLDocument::getStyleDeclaration","cocktail/core/html/HTMLDocument.hx",429);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(429)
	return this->_styleManager->getStyleDeclaration(node,this->getMatchedPseudoClassesVO(node));
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,getStyleDeclaration,return )

Void HTMLDocument_obj::removeStyleSheet( ::cocktail::core::css::CSSStyleSheet stylesheet){
{
		HX_STACK_PUSH("HTMLDocument::removeStyleSheet","cocktail/core/html/HTMLDocument.hx",417);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stylesheet,"stylesheet");
		HX_STACK_LINE(418)
		this->_styleManager->removeStyleSheet(stylesheet);
		HX_STACK_LINE(419)
		this->documentElement->invalidateStyleDeclaration(true);
		HX_STACK_LINE(420)
		this->documentElement->cascade(this->cascadeManager,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,removeStyleSheet,(void))

Void HTMLDocument_obj::addStyleSheet( ::cocktail::core::css::CSSStyleSheet stylesheet){
{
		HX_STACK_PUSH("HTMLDocument::addStyleSheet","cocktail/core/html/HTMLDocument.hx",406);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stylesheet,"stylesheet");
		HX_STACK_LINE(407)
		this->_styleManager->addStyleSheet(stylesheet);
		HX_STACK_LINE(408)
		this->documentElement->invalidateStyleDeclaration(true);
		HX_STACK_LINE(409)
		this->documentElement->cascade(this->cascadeManager,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,addStyleSheet,(void))

::cocktail::core::html::HTMLElement HTMLDocument_obj::createElement( ::String tagName){
	HX_STACK_PUSH("HTMLDocument::createElement","cocktail/core/html/HTMLDocument.hx",334);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tagName,"tagName");
	HX_STACK_LINE(335)
	::cocktail::core::html::HTMLElement element;		HX_STACK_VAR(element,"element");
	HX_STACK_LINE(338)
	tagName = tagName.toUpperCase();
	HX_STACK_LINE(340)
	::String _switch_3 = (tagName);
	if (  ( _switch_3==HX_CSTRING("IMG"))){
		HX_STACK_LINE(342)
		element = ::cocktail::core::html::HTMLImageElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("INPUT"))){
		HX_STACK_LINE(345)
		element = ::cocktail::core::html::HTMLInputElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("A"))){
		HX_STACK_LINE(348)
		element = ::cocktail::core::html::HTMLAnchorElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("HTML"))){
		HX_STACK_LINE(351)
		element = ::cocktail::core::html::HTMLHtmlElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("BODY"))){
		HX_STACK_LINE(354)
		element = ::cocktail::core::html::HTMLBodyElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("VIDEO"))){
		HX_STACK_LINE(357)
		element = ::cocktail::core::html::HTMLVideoElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("AUDIO"))){
		HX_STACK_LINE(360)
		element = ::cocktail::core::html::HTMLAudioElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("SOURCE"))){
		HX_STACK_LINE(363)
		element = ::cocktail::core::html::HTMLSourceElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("OBJECT"))){
		HX_STACK_LINE(366)
		element = ::cocktail::core::html::HTMLObjectElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("PARAM"))){
		HX_STACK_LINE(369)
		element = ::cocktail::core::html::HTMLParamElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("LINK"))){
		HX_STACK_LINE(372)
		element = ::cocktail::core::html::HTMLLinkElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("STYLE"))){
		HX_STACK_LINE(375)
		element = ::cocktail::core::html::HTMLStyleElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("BR"))){
		HX_STACK_LINE(378)
		element = ::cocktail::core::html::HTMLBRElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("META"))){
		HX_STACK_LINE(381)
		element = ::cocktail::core::html::HTMLMetaElement_obj::__new();
	}
	else if (  ( _switch_3==HX_CSTRING("FORM"))){
		HX_STACK_LINE(384)
		element = ::cocktail::core::html::HTMLFormElement_obj::__new();
	}
	else  {
		HX_STACK_LINE(387)
		element = ::cocktail::core::html::HTMLElement_obj::__new(tagName);
	}
;
;
	HX_STACK_LINE(391)
	element->set_ownerDocument(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(393)
	return element;
}


Void HTMLDocument_obj::initStyleManager( ){
{
		HX_STACK_PUSH("HTMLDocument::initStyleManager","cocktail/core/html/HTMLDocument.hx",319);
		HX_STACK_THIS(this);
		HX_STACK_LINE(320)
		this->_styleManager = ::cocktail::core::css::StyleManager_obj::__new();
		HX_STACK_LINE(321)
		this->_styleManager->addStyleSheet(::cocktail::core::css::DefaultCSSStyleSheet_obj::__new());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,initStyleManager,(void))

Void HTMLDocument_obj::initBody( ::cocktail::core::html::HTMLBodyElement htmlBodyElement){
{
		HX_STACK_PUSH("HTMLDocument::initBody","cocktail/core/html/HTMLDocument.hx",305);
		HX_STACK_THIS(this);
		HX_STACK_ARG(htmlBodyElement,"htmlBodyElement");
		HX_STACK_LINE(305)
		if (((htmlBodyElement != null()))){
			HX_STACK_LINE(308)
			this->body = htmlBodyElement;
			HX_STACK_LINE(309)
			this->documentElement->appendChild(this->body);
			HX_STACK_LINE(310)
			this->set_activeElement(this->body);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,initBody,(void))

Void HTMLDocument_obj::init( ){
{
		HX_STACK_PUSH("HTMLDocument::init","cocktail/core/html/HTMLDocument.hx",272);
		HX_STACK_THIS(this);
		HX_STACK_LINE(273)
		this->timer = ::cocktail::core::timer::Timer_obj::__new();
		HX_STACK_LINE(274)
		this->initStyleManager();
		HX_STACK_LINE(275)
		this->invalidationManager = ::cocktail::core::invalidation::InvalidationManager_obj::__new(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(277)
		this->cascadeManager = ::cocktail::core::css::CascadeManager_obj::__new();
		HX_STACK_LINE(279)
		this->_matchedPseudoClasses = ::cocktail::core::css::MatchedPseudoClassesVO_obj::__new(false,false,false,false,false,false,false,false,false,null(),null(),null());
		HX_STACK_LINE(282)
		this->_focusManager = ::cocktail::core::focus::FocusManager_obj::__new();
		HX_STACK_LINE(284)
		this->_hitTestManager = ::cocktail::core::hittest::HitTestManager_obj::__new();
		HX_STACK_LINE(286)
		this->_multiTouchManager = ::cocktail::core::multitouch::MultiTouchManager_obj::__new();
		HX_STACK_LINE(288)
		this->documentElement = this->createElement(HX_CSTRING("HTML"));
		HX_STACK_LINE(290)
		this->initBody(this->createElement(HX_CSTRING("BODY")));
		HX_STACK_LINE(292)
		this->_shouldDispatchClickOnNextMouseUp = false;
		HX_STACK_LINE(293)
		this->_lastTouchStartPosition = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
		HX_STACK_LINE(295)
		this->layoutManager = ::cocktail::core::layout::LayoutManager_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,init,(void))

int HTMLDocument_obj::TAB_KEY_CODE;

int HTMLDocument_obj::ENTER_KEY_CODE;

int HTMLDocument_obj::SPACE_KEY_CODE;

int HTMLDocument_obj::MOUSE_WHEEL_DELTA_MULTIPLIER;


HTMLDocument_obj::HTMLDocument_obj()
{
}

void HTMLDocument_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLDocument);
	HX_MARK_MEMBER_NAME(innerHTML,"innerHTML");
	HX_MARK_MEMBER_NAME(cascadeManager,"cascadeManager");
	HX_MARK_MEMBER_NAME(_matchedPseudoClasses,"_matchedPseudoClasses");
	HX_MARK_MEMBER_NAME(invalidationManager,"invalidationManager");
	HX_MARK_MEMBER_NAME(layoutManager,"layoutManager");
	HX_MARK_MEMBER_NAME(_styleManager,"_styleManager");
	HX_MARK_MEMBER_NAME(window,"window");
	HX_MARK_MEMBER_NAME(_hitTestManager,"_hitTestManager");
	HX_MARK_MEMBER_NAME(_multiTouchManager,"_multiTouchManager");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(_lastTouchStartPosition,"_lastTouchStartPosition");
	HX_MARK_MEMBER_NAME(_shouldDispatchClickOnNextMouseUp,"_shouldDispatchClickOnNextMouseUp");
	HX_MARK_MEMBER_NAME(onSetMouseCursor,"onSetMouseCursor");
	HX_MARK_MEMBER_NAME(onExitFullscreen,"onExitFullscreen");
	HX_MARK_MEMBER_NAME(onEnterFullscreen,"onEnterFullscreen");
	HX_MARK_MEMBER_NAME(fullscreenElement,"fullscreenElement");
	HX_MARK_MEMBER_NAME(fullscreenEnabled,"fullscreenEnabled");
	HX_MARK_MEMBER_NAME(_mousedDownedElementRenderer,"_mousedDownedElementRenderer");
	HX_MARK_MEMBER_NAME(_hoveredElementRenderer,"_hoveredElementRenderer");
	HX_MARK_MEMBER_NAME(_focusManager,"_focusManager");
	HX_MARK_MEMBER_NAME(activeElement,"activeElement");
	HX_MARK_MEMBER_NAME(body,"body");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLDocument_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(innerHTML,"innerHTML");
	HX_VISIT_MEMBER_NAME(cascadeManager,"cascadeManager");
	HX_VISIT_MEMBER_NAME(_matchedPseudoClasses,"_matchedPseudoClasses");
	HX_VISIT_MEMBER_NAME(invalidationManager,"invalidationManager");
	HX_VISIT_MEMBER_NAME(layoutManager,"layoutManager");
	HX_VISIT_MEMBER_NAME(_styleManager,"_styleManager");
	HX_VISIT_MEMBER_NAME(window,"window");
	HX_VISIT_MEMBER_NAME(_hitTestManager,"_hitTestManager");
	HX_VISIT_MEMBER_NAME(_multiTouchManager,"_multiTouchManager");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(_lastTouchStartPosition,"_lastTouchStartPosition");
	HX_VISIT_MEMBER_NAME(_shouldDispatchClickOnNextMouseUp,"_shouldDispatchClickOnNextMouseUp");
	HX_VISIT_MEMBER_NAME(onSetMouseCursor,"onSetMouseCursor");
	HX_VISIT_MEMBER_NAME(onExitFullscreen,"onExitFullscreen");
	HX_VISIT_MEMBER_NAME(onEnterFullscreen,"onEnterFullscreen");
	HX_VISIT_MEMBER_NAME(fullscreenElement,"fullscreenElement");
	HX_VISIT_MEMBER_NAME(fullscreenEnabled,"fullscreenEnabled");
	HX_VISIT_MEMBER_NAME(_mousedDownedElementRenderer,"_mousedDownedElementRenderer");
	HX_VISIT_MEMBER_NAME(_hoveredElementRenderer,"_hoveredElementRenderer");
	HX_VISIT_MEMBER_NAME(_focusManager,"_focusManager");
	HX_VISIT_MEMBER_NAME(activeElement,"activeElement");
	HX_VISIT_MEMBER_NAME(body,"body");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLDocument_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"body") ) { return body; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { return window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"initBody") ) { return initBody_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"innerHTML") ) { return inCallProp ? get_innerHTML() : innerHTML; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TAB_KEY_CODE") ) { return TAB_KEY_CODE; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_innerHTML") ) { return get_innerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"set_innerHTML") ) { return set_innerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"addStyleSheet") ) { return addStyleSheet_dyn(); }
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		if (HX_FIELD_EQ(inName,"layoutManager") ) { return layoutManager; }
		if (HX_FIELD_EQ(inName,"_styleManager") ) { return _styleManager; }
		if (HX_FIELD_EQ(inName,"_focusManager") ) { return _focusManager; }
		if (HX_FIELD_EQ(inName,"activeElement") ) { return inCallProp ? get_activeElement() : activeElement; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ENTER_KEY_CODE") ) { return ENTER_KEY_CODE; }
		if (HX_FIELD_EQ(inName,"SPACE_KEY_CODE") ) { return SPACE_KEY_CODE; }
		if (HX_FIELD_EQ(inName,"exitFullscreen") ) { return exitFullscreen_dyn(); }
		if (HX_FIELD_EQ(inName,"setMouseCursor") ) { return setMouseCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"cascadeManager") ) { return cascadeManager; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_hitTestManager") ) { return _hitTestManager; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeStyleSheet") ) { return removeStyleSheet_dyn(); }
		if (HX_FIELD_EQ(inName,"initStyleManager") ) { return initStyleManager_dyn(); }
		if (HX_FIELD_EQ(inName,"onSetMouseCursor") ) { return onSetMouseCursor; }
		if (HX_FIELD_EQ(inName,"onExitFullscreen") ) { return onExitFullscreen; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_activeElement") ) { return get_activeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"set_activeElement") ) { return set_activeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"onEnterFullscreen") ) { return onEnterFullscreen; }
		if (HX_FIELD_EQ(inName,"fullscreenElement") ) { return fullscreenElement; }
		if (HX_FIELD_EQ(inName,"fullscreenEnabled") ) { return inCallProp ? get_fullscreenEnabled() : fullscreenEnabled; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"dispatchClickEvent") ) { return dispatchClickEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"_multiTouchManager") ) { return _multiTouchManager; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getStyleDeclaration") ) { return getStyleDeclaration_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidationManager") ) { return invalidationManager; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"onPlatformTouchEvent") ) { return onPlatformTouchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"onPlatformKeyUpEvent") ) { return onPlatformKeyUpEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"onPlatformMouseEvent") ) { return onPlatformMouseEvent_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"set_fullscreenElement") ) { return set_fullscreenElement_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fullscreenEnabled") ) { return get_fullscreenEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"_matchedPseudoClasses") ) { return _matchedPseudoClasses; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"onPlatformKeyDownEvent") ) { return onPlatformKeyDownEvent_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_lastTouchStartPosition") ) { return _lastTouchStartPosition; }
		if (HX_FIELD_EQ(inName,"_hoveredElementRenderer") ) { return _hoveredElementRenderer; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"onPlatformMouseMoveEvent") ) { return onPlatformMouseMoveEvent_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"onPlatformMouseWheelEvent") ) { return onPlatformMouseWheelEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"onPlatformMouseLeaveEvent") ) { return onPlatformMouseLeaveEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"getMatchedPseudoClassesVO") ) { return getMatchedPseudoClassesVO_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"MOUSE_WHEEL_DELTA_MULTIPLIER") ) { return MOUSE_WHEEL_DELTA_MULTIPLIER; }
		if (HX_FIELD_EQ(inName,"_mousedDownedElementRenderer") ) { return _mousedDownedElementRenderer; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"_shouldDispatchClickOnNextMouseUp") ) { return _shouldDispatchClickOnNextMouseUp; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"getFirstVerticallyScrollableHTMLElement") ) { return getFirstVerticallyScrollableHTMLElement_dyn(); }
		break;
	case 49:
		if (HX_FIELD_EQ(inName,"getFirstElementRendererWhichCanDispatchMouseEvent") ) { return getFirstElementRendererWhichCanDispatchMouseEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLDocument_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { body=inValue.Cast< ::cocktail::core::html::HTMLBodyElement >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::cocktail::core::timer::Timer >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { window=inValue.Cast< ::cocktail::core::window::Window >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"innerHTML") ) { if (inCallProp) return set_innerHTML(inValue);innerHTML=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TAB_KEY_CODE") ) { TAB_KEY_CODE=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layoutManager") ) { layoutManager=inValue.Cast< ::cocktail::core::layout::LayoutManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_styleManager") ) { _styleManager=inValue.Cast< ::cocktail::core::css::StyleManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_focusManager") ) { _focusManager=inValue.Cast< ::cocktail::core::focus::FocusManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"activeElement") ) { if (inCallProp) return set_activeElement(inValue);activeElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ENTER_KEY_CODE") ) { ENTER_KEY_CODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SPACE_KEY_CODE") ) { SPACE_KEY_CODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cascadeManager") ) { cascadeManager=inValue.Cast< ::cocktail::core::css::CascadeManager >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_hitTestManager") ) { _hitTestManager=inValue.Cast< ::cocktail::core::hittest::HitTestManager >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onSetMouseCursor") ) { onSetMouseCursor=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onExitFullscreen") ) { onExitFullscreen=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onEnterFullscreen") ) { onEnterFullscreen=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fullscreenElement") ) { if (inCallProp) return set_fullscreenElement(inValue);fullscreenElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fullscreenEnabled") ) { fullscreenEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_multiTouchManager") ) { _multiTouchManager=inValue.Cast< ::cocktail::core::multitouch::MultiTouchManager >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"invalidationManager") ) { invalidationManager=inValue.Cast< ::cocktail::core::invalidation::InvalidationManager >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_matchedPseudoClasses") ) { _matchedPseudoClasses=inValue.Cast< ::cocktail::core::css::MatchedPseudoClassesVO >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_lastTouchStartPosition") ) { _lastTouchStartPosition=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hoveredElementRenderer") ) { _hoveredElementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"MOUSE_WHEEL_DELTA_MULTIPLIER") ) { MOUSE_WHEEL_DELTA_MULTIPLIER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mousedDownedElementRenderer") ) { _mousedDownedElementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"_shouldDispatchClickOnNextMouseUp") ) { _shouldDispatchClickOnNextMouseUp=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLDocument_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("innerHTML"));
	outFields->push(HX_CSTRING("cascadeManager"));
	outFields->push(HX_CSTRING("_matchedPseudoClasses"));
	outFields->push(HX_CSTRING("invalidationManager"));
	outFields->push(HX_CSTRING("layoutManager"));
	outFields->push(HX_CSTRING("_styleManager"));
	outFields->push(HX_CSTRING("window"));
	outFields->push(HX_CSTRING("_hitTestManager"));
	outFields->push(HX_CSTRING("_multiTouchManager"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("_lastTouchStartPosition"));
	outFields->push(HX_CSTRING("_shouldDispatchClickOnNextMouseUp"));
	outFields->push(HX_CSTRING("fullscreenElement"));
	outFields->push(HX_CSTRING("fullscreenEnabled"));
	outFields->push(HX_CSTRING("_mousedDownedElementRenderer"));
	outFields->push(HX_CSTRING("_hoveredElementRenderer"));
	outFields->push(HX_CSTRING("_focusManager"));
	outFields->push(HX_CSTRING("activeElement"));
	outFields->push(HX_CSTRING("body"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TAB_KEY_CODE"),
	HX_CSTRING("ENTER_KEY_CODE"),
	HX_CSTRING("SPACE_KEY_CODE"),
	HX_CSTRING("MOUSE_WHEEL_DELTA_MULTIPLIER"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_activeElement"),
	HX_CSTRING("set_activeElement"),
	HX_CSTRING("getFirstVerticallyScrollableHTMLElement"),
	HX_CSTRING("getFirstElementRendererWhichCanDispatchMouseEvent"),
	HX_CSTRING("set_fullscreenElement"),
	HX_CSTRING("get_fullscreenEnabled"),
	HX_CSTRING("exitFullscreen"),
	HX_CSTRING("setMouseCursor"),
	HX_CSTRING("dispatchClickEvent"),
	HX_CSTRING("onPlatformTouchEvent"),
	HX_CSTRING("onPlatformKeyUpEvent"),
	HX_CSTRING("onPlatformKeyDownEvent"),
	HX_CSTRING("onPlatformMouseMoveEvent"),
	HX_CSTRING("onPlatformMouseWheelEvent"),
	HX_CSTRING("onPlatformMouseLeaveEvent"),
	HX_CSTRING("onPlatformMouseEvent"),
	HX_CSTRING("get_innerHTML"),
	HX_CSTRING("set_innerHTML"),
	HX_CSTRING("getMatchedPseudoClassesVO"),
	HX_CSTRING("getStyleDeclaration"),
	HX_CSTRING("removeStyleSheet"),
	HX_CSTRING("addStyleSheet"),
	HX_CSTRING("createElement"),
	HX_CSTRING("initStyleManager"),
	HX_CSTRING("initBody"),
	HX_CSTRING("init"),
	HX_CSTRING("innerHTML"),
	HX_CSTRING("cascadeManager"),
	HX_CSTRING("_matchedPseudoClasses"),
	HX_CSTRING("invalidationManager"),
	HX_CSTRING("layoutManager"),
	HX_CSTRING("_styleManager"),
	HX_CSTRING("window"),
	HX_CSTRING("_hitTestManager"),
	HX_CSTRING("_multiTouchManager"),
	HX_CSTRING("timer"),
	HX_CSTRING("_lastTouchStartPosition"),
	HX_CSTRING("_shouldDispatchClickOnNextMouseUp"),
	HX_CSTRING("onSetMouseCursor"),
	HX_CSTRING("onExitFullscreen"),
	HX_CSTRING("onEnterFullscreen"),
	HX_CSTRING("fullscreenElement"),
	HX_CSTRING("fullscreenEnabled"),
	HX_CSTRING("_mousedDownedElementRenderer"),
	HX_CSTRING("_hoveredElementRenderer"),
	HX_CSTRING("_focusManager"),
	HX_CSTRING("activeElement"),
	HX_CSTRING("body"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::TAB_KEY_CODE,"TAB_KEY_CODE");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::ENTER_KEY_CODE,"ENTER_KEY_CODE");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::SPACE_KEY_CODE,"SPACE_KEY_CODE");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::MOUSE_WHEEL_DELTA_MULTIPLIER,"MOUSE_WHEEL_DELTA_MULTIPLIER");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLDocument_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTMLDocument_obj::TAB_KEY_CODE,"TAB_KEY_CODE");
	HX_VISIT_MEMBER_NAME(HTMLDocument_obj::ENTER_KEY_CODE,"ENTER_KEY_CODE");
	HX_VISIT_MEMBER_NAME(HTMLDocument_obj::SPACE_KEY_CODE,"SPACE_KEY_CODE");
	HX_VISIT_MEMBER_NAME(HTMLDocument_obj::MOUSE_WHEEL_DELTA_MULTIPLIER,"MOUSE_WHEEL_DELTA_MULTIPLIER");
};

Class HTMLDocument_obj::__mClass;

void HTMLDocument_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLDocument"), hx::TCanCast< HTMLDocument_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLDocument_obj::__boot()
{
	TAB_KEY_CODE= (int)9;
	ENTER_KEY_CODE= (int)13;
	SPACE_KEY_CODE= (int)32;
	MOUSE_WHEEL_DELTA_MULTIPLIER= (int)10;
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
