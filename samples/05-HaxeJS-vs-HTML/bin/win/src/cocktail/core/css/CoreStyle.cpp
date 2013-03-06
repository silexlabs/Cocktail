#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_Animator
#include <cocktail/core/animation/Animator.h>
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
#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSConstants
#include <cocktail/core/css/CSSConstants.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSValueConverter
#include <cocktail/core/css/CSSValueConverter.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_InitialStyleDeclaration
#include <cocktail/core/css/InitialStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_TypedPropertyVO
#include <cocktail/core/css/TypedPropertyVO.h>
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
#ifndef INCLUDED_cocktail_core_event_TransitionEvent
#include <cocktail/core/event/TransitionEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontManager
#include <cocktail/core/font/FontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
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
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CoreStyle_obj::__construct(::cocktail::core::html::HTMLElement htmlElement)
{
HX_STACK_PUSH("CoreStyle::new","cocktail/core/css/CoreStyle.hx",530);
{
	HX_STACK_LINE(531)
	this->htmlElement = htmlElement;
	HX_STACK_LINE(533)
	this->_isFirstCascade = true;
	HX_STACK_LINE(535)
	this->hasTransitionnableProperties = false;
	HX_STACK_LINE(536)
	this->isFloat = false;
	HX_STACK_LINE(537)
	this->isInlineLevel = false;
	HX_STACK_LINE(538)
	this->isInlineBlock = false;
	HX_STACK_LINE(539)
	this->isBlock = false;
	HX_STACK_LINE(540)
	this->isVisible = false;
	HX_STACK_LINE(541)
	this->isPositioned = false;
	HX_STACK_LINE(542)
	this->isRelativePositioned = false;
	HX_STACK_LINE(543)
	this->isFixedPositioned = false;
	HX_STACK_LINE(544)
	this->canAlwaysOverflow = false;
	HX_STACK_LINE(545)
	this->isTransformed = false;
	HX_STACK_LINE(546)
	this->isTransparent = false;
	HX_STACK_LINE(547)
	this->hasBackgroundImage = false;
	HX_STACK_LINE(548)
	this->isTopAligned = false;
	HX_STACK_LINE(549)
	this->isBottomAligned = false;
	HX_STACK_LINE(550)
	this->isBaselineAligned = false;
	HX_STACK_LINE(551)
	this->canHaveClearance = false;
	HX_STACK_LINE(552)
	this->hasPreWhiteSpace = false;
	HX_STACK_LINE(553)
	this->hasNoWrapWhiteSpace = false;
	HX_STACK_LINE(554)
	this->hasNormalWhiteSpace = false;
	HX_STACK_LINE(555)
	this->hasPreLineWhiteSpace = false;
	HX_STACK_LINE(556)
	this->hasPreWrapWhiteSpace = false;
	HX_STACK_LINE(557)
	this->hasAutoHeight = false;
	HX_STACK_LINE(558)
	this->hasAutoWidth = false;
	HX_STACK_LINE(559)
	this->hasMaxHeight = false;
	HX_STACK_LINE(560)
	this->hasMaxWidth = false;
	HX_STACK_LINE(561)
	this->isInline = false;
	HX_STACK_LINE(562)
	this->isLeftAligned = false;
	HX_STACK_LINE(563)
	this->hasAutoTop = false;
	HX_STACK_LINE(564)
	this->hasAutoBottom = false;
	HX_STACK_LINE(565)
	this->hasAutoLeft = false;
	HX_STACK_LINE(566)
	this->hasAutoRight = false;
	HX_STACK_LINE(567)
	this->hasAutoMarginTop = false;
	HX_STACK_LINE(568)
	this->hasAutoMarginBottom = false;
	HX_STACK_LINE(569)
	this->hasAutoMarginLeft = false;
	HX_STACK_LINE(570)
	this->hasAutoMarginRight = false;
	HX_STACK_LINE(571)
	this->isAbsolutelyPositioned = false;
	HX_STACK_LINE(572)
	this->hasBackgroundColor = false;
	HX_STACK_LINE(573)
	this->hasCSSTransform = false;
	HX_STACK_LINE(574)
	this->hasHiddenOrScrollOverflowX = false;
	HX_STACK_LINE(575)
	this->hasHiddenOrScrollOverflowY = false;
	HX_STACK_LINE(577)
	this->_initialStyleDeclaration = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();
	HX_STACK_LINE(578)
	this->_initialComputedStyleDeclaration = this->_initialStyleDeclaration->initialComputedStyleDeclaration;
	HX_STACK_LINE(580)
	this->init();
}
;
	return null();
}

CoreStyle_obj::~CoreStyle_obj() { }

Dynamic CoreStyle_obj::__CreateEmpty() { return  new CoreStyle_obj; }
hx::ObjectPtr< CoreStyle_obj > CoreStyle_obj::__new(::cocktail::core::html::HTMLElement htmlElement)
{  hx::ObjectPtr< CoreStyle_obj > result = new CoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic CoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CoreStyle_obj > result = new CoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_textDecoration( ){
	HX_STACK_PUSH("CoreStyle::get_textDecoration","cocktail/core/css/CoreStyle.hx",2859);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2859)
	return this->getComputedOrInitialProperty((int)86);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_textDecoration,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_outlineColor( ){
	HX_STACK_PUSH("CoreStyle::get_outlineColor","cocktail/core/css/CoreStyle.hx",2854);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2854)
	return this->getComputedOrInitialProperty((int)84);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_outlineColor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_outlineStyle( ){
	HX_STACK_PUSH("CoreStyle::get_outlineStyle","cocktail/core/css/CoreStyle.hx",2849);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2849)
	return this->getComputedOrInitialProperty((int)83);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_outlineStyle,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_outlineWidth( ){
	HX_STACK_PUSH("CoreStyle::get_outlineWidth","cocktail/core/css/CoreStyle.hx",2844);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2844)
	return this->getComputedOrInitialProperty((int)82);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_outlineWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderLeftStyle( ){
	HX_STACK_PUSH("CoreStyle::get_borderLeftStyle","cocktail/core/css/CoreStyle.hx",2839);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2839)
	return this->getComputedOrInitialProperty((int)75);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderLeftStyle,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderBottomStyle( ){
	HX_STACK_PUSH("CoreStyle::get_borderBottomStyle","cocktail/core/css/CoreStyle.hx",2834);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2834)
	return this->getComputedOrInitialProperty((int)74);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderBottomStyle,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderRightStyle( ){
	HX_STACK_PUSH("CoreStyle::get_borderRightStyle","cocktail/core/css/CoreStyle.hx",2829);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2829)
	return this->getComputedOrInitialProperty((int)73);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderRightStyle,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderTopStyle( ){
	HX_STACK_PUSH("CoreStyle::get_borderTopStyle","cocktail/core/css/CoreStyle.hx",2824);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2824)
	return this->getComputedOrInitialProperty((int)72);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderTopStyle,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderLeftColor( ){
	HX_STACK_PUSH("CoreStyle::get_borderLeftColor","cocktail/core/css/CoreStyle.hx",2819);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2820);
			{
				HX_STACK_LINE(2820)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)70,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2820)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)70)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2819)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)70)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)70)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderLeftColor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderBottomColor( ){
	HX_STACK_PUSH("CoreStyle::get_borderBottomColor","cocktail/core/css/CoreStyle.hx",2814);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2815);
			{
				HX_STACK_LINE(2815)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)69,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2815)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)69)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2814)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)69)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)69)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderBottomColor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderRightColor( ){
	HX_STACK_PUSH("CoreStyle::get_borderRightColor","cocktail/core/css/CoreStyle.hx",2809);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2810);
			{
				HX_STACK_LINE(2810)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)68,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2810)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)68)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2809)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)68)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)68)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderRightColor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderTopColor( ){
	HX_STACK_PUSH("CoreStyle::get_borderTopColor","cocktail/core/css/CoreStyle.hx",2804);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2805);
			{
				HX_STACK_LINE(2805)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)67,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2805)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)67)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2804)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)67)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)67)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderTopColor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderLeftWidth( ){
	HX_STACK_PUSH("CoreStyle::get_borderLeftWidth","cocktail/core/css/CoreStyle.hx",2799);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2800);
			{
				HX_STACK_LINE(2800)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)65,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2800)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)65)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2799)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)65)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)65)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderLeftWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderBottomWidth( ){
	HX_STACK_PUSH("CoreStyle::get_borderBottomWidth","cocktail/core/css/CoreStyle.hx",2794);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2795);
			{
				HX_STACK_LINE(2795)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)64,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2795)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)64)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2794)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)64)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)64)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderBottomWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderRightWidth( ){
	HX_STACK_PUSH("CoreStyle::get_borderRightWidth","cocktail/core/css/CoreStyle.hx",2789);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2790);
			{
				HX_STACK_LINE(2790)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)63,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2790)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)63)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2789)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)63)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)63)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderRightWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_borderTopWidth( ){
	HX_STACK_PUSH("CoreStyle::get_borderTopWidth","cocktail/core/css/CoreStyle.hx",2784);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2785);
			{
				HX_STACK_LINE(2785)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)62,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2785)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)62)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2784)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)62)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)62)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_borderTopWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_transitionDelay( ){
	HX_STACK_PUSH("CoreStyle::get_transitionDelay","cocktail/core/css/CoreStyle.hx",2779);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2779)
	return this->getComputedOrInitialProperty((int)56);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_transitionDelay,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_transitionTimingFunction( ){
	HX_STACK_PUSH("CoreStyle::get_transitionTimingFunction","cocktail/core/css/CoreStyle.hx",2774);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2774)
	return this->getComputedOrInitialProperty((int)58);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_transitionTimingFunction,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_transitionDuration( ){
	HX_STACK_PUSH("CoreStyle::get_transitionDuration","cocktail/core/css/CoreStyle.hx",2769);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2769)
	return this->getComputedOrInitialProperty((int)55);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_transitionDuration,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_transitionProperty( ){
	HX_STACK_PUSH("CoreStyle::get_transitionProperty","cocktail/core/css/CoreStyle.hx",2764);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2764)
	return this->getComputedOrInitialProperty((int)57);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_transitionProperty,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_cursor( ){
	HX_STACK_PUSH("CoreStyle::get_cursor","cocktail/core/css/CoreStyle.hx",2759);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2759)
	return this->getComputedOrInitialProperty((int)54);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_cursor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_transform( ){
	HX_STACK_PUSH("CoreStyle::get_transform","cocktail/core/css/CoreStyle.hx",2754);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2754)
	return this->getComputedOrInitialProperty((int)61);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_transform,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_transformOrigin( ){
	HX_STACK_PUSH("CoreStyle::get_transformOrigin","cocktail/core/css/CoreStyle.hx",2749);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2749)
	return this->getComputedOrInitialProperty((int)60);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_transformOrigin,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_overflowY( ){
	HX_STACK_PUSH("CoreStyle::get_overflowY","cocktail/core/css/CoreStyle.hx",2744);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2744)
	return this->getComputedOrInitialProperty((int)52);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_overflowY,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_overflowX( ){
	HX_STACK_PUSH("CoreStyle::get_overflowX","cocktail/core/css/CoreStyle.hx",2739);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2739)
	return this->getComputedOrInitialProperty((int)51);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_overflowX,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_visibility( ){
	HX_STACK_PUSH("CoreStyle::get_visibility","cocktail/core/css/CoreStyle.hx",2734);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2734)
	return this->getComputedOrInitialProperty((int)49);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_visibility,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_verticalAlign( ){
	HX_STACK_PUSH("CoreStyle::get_verticalAlign","cocktail/core/css/CoreStyle.hx",2729);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2729)
	return this->getComputedOrInitialProperty((int)48);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_verticalAlign,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_textIndent( ){
	HX_STACK_PUSH("CoreStyle::get_textIndent","cocktail/core/css/CoreStyle.hx",2724);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2725);
			{
				HX_STACK_LINE(2725)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)47,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2725)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)47)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2724)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)47)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)47)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_textIndent,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_textAlign( ){
	HX_STACK_PUSH("CoreStyle::get_textAlign","cocktail/core/css/CoreStyle.hx",2719);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2719)
	return this->getComputedOrInitialProperty((int)46);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_textAlign,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_whiteSpace( ){
	HX_STACK_PUSH("CoreStyle::get_whiteSpace","cocktail/core/css/CoreStyle.hx",2714);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2714)
	return this->getComputedOrInitialProperty((int)45);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_whiteSpace,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_wordSpacing( ){
	HX_STACK_PUSH("CoreStyle::get_wordSpacing","cocktail/core/css/CoreStyle.hx",2709);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2710);
			{
				HX_STACK_LINE(2710)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)44,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2710)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)44)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2709)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)44)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)44)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_wordSpacing,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_letterSpacing( ){
	HX_STACK_PUSH("CoreStyle::get_letterSpacing","cocktail/core/css/CoreStyle.hx",2704);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2705);
			{
				HX_STACK_LINE(2705)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)43,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2705)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)43)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2704)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)43)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)43)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_letterSpacing,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_textTransform( ){
	HX_STACK_PUSH("CoreStyle::get_textTransform","cocktail/core/css/CoreStyle.hx",2699);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2699)
	return this->getComputedOrInitialProperty((int)42);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_textTransform,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_lineHeight( ){
	HX_STACK_PUSH("CoreStyle::get_lineHeight","cocktail/core/css/CoreStyle.hx",2694);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2695);
			{
				HX_STACK_LINE(2695)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)41,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2695)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)41)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2694)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)41)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)41)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_lineHeight,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_color( ){
	HX_STACK_PUSH("CoreStyle::get_color","cocktail/core/css/CoreStyle.hx",2689);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2689)
	return this->getComputedOrInitialProperty((int)40);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_color,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_fontVariant( ){
	HX_STACK_PUSH("CoreStyle::get_fontVariant","cocktail/core/css/CoreStyle.hx",2684);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2684)
	return this->getComputedOrInitialProperty((int)38);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_fontVariant,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_fontFamily( ){
	HX_STACK_PUSH("CoreStyle::get_fontFamily","cocktail/core/css/CoreStyle.hx",2679);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2679)
	return this->getComputedOrInitialProperty((int)37);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_fontFamily,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_fontStyle( ){
	HX_STACK_PUSH("CoreStyle::get_fontStyle","cocktail/core/css/CoreStyle.hx",2674);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2674)
	return this->getComputedOrInitialProperty((int)36);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_fontStyle,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_fontWeight( ){
	HX_STACK_PUSH("CoreStyle::get_fontWeight","cocktail/core/css/CoreStyle.hx",2669);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2669)
	return this->getComputedOrInitialProperty((int)35);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_fontWeight,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundPosition( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundPosition","cocktail/core/css/CoreStyle.hx",2664);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2664)
	return this->getComputedOrInitialProperty((int)30);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundPosition,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundSize( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundSize","cocktail/core/css/CoreStyle.hx",2659);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2659)
	return this->getComputedOrInitialProperty((int)29);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundSize,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundRepeat( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundRepeat","cocktail/core/css/CoreStyle.hx",2654);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2654)
	return this->getComputedOrInitialProperty((int)27);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundRepeat,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundAttachment( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundAttachment","cocktail/core/css/CoreStyle.hx",2649);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2649)
	return this->getComputedOrInitialProperty((int)32);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundAttachment,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundClip( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundClip","cocktail/core/css/CoreStyle.hx",2644);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2644)
	return this->getComputedOrInitialProperty((int)31);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundClip,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundOrigin( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundOrigin","cocktail/core/css/CoreStyle.hx",2639);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2639)
	return this->getComputedOrInitialProperty((int)28);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundOrigin,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundImage( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundImage","cocktail/core/css/CoreStyle.hx",2634);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2634)
	return this->getComputedOrInitialProperty((int)26);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundImage,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_backgroundColor( ){
	HX_STACK_PUSH("CoreStyle::get_backgroundColor","cocktail/core/css/CoreStyle.hx",2629);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2629)
	return this->getComputedOrInitialProperty((int)25);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_backgroundColor,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_zIndex( ){
	HX_STACK_PUSH("CoreStyle::get_zIndex","cocktail/core/css/CoreStyle.hx",2624);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2624)
	return this->getComputedOrInitialProperty((int)4);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_zIndex,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_clear( ){
	HX_STACK_PUSH("CoreStyle::get_clear","cocktail/core/css/CoreStyle.hx",2619);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2619)
	return this->getComputedOrInitialProperty((int)3);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_clear,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_cssFloat( ){
	HX_STACK_PUSH("CoreStyle::get_cssFloat","cocktail/core/css/CoreStyle.hx",2614);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2614)
	return this->getComputedOrInitialProperty((int)2);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_cssFloat,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_position( ){
	HX_STACK_PUSH("CoreStyle::get_position","cocktail/core/css/CoreStyle.hx",2609);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2609)
	return this->getComputedOrInitialProperty((int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_position,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_display( ){
	HX_STACK_PUSH("CoreStyle::get_display","cocktail/core/css/CoreStyle.hx",2604);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2604)
	return this->getComputedOrInitialProperty((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_display,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_fontSize( ){
	HX_STACK_PUSH("CoreStyle::get_fontSize","cocktail/core/css/CoreStyle.hx",2599);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2600);
			{
				HX_STACK_LINE(2600)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)34,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2600)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)34)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2599)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_fontSize,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_right( ){
	HX_STACK_PUSH("CoreStyle::get_right","cocktail/core/css/CoreStyle.hx",2594);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2595);
			{
				HX_STACK_LINE(2595)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)23,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2595)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)23)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2594)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_right,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_bottom( ){
	HX_STACK_PUSH("CoreStyle::get_bottom","cocktail/core/css/CoreStyle.hx",2589);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2590);
			{
				HX_STACK_LINE(2590)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)24,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2590)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)24)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2589)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_bottom,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_left( ){
	HX_STACK_PUSH("CoreStyle::get_left","cocktail/core/css/CoreStyle.hx",2584);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2585);
			{
				HX_STACK_LINE(2585)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)22,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2585)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)22)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2584)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_left,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_top( ){
	HX_STACK_PUSH("CoreStyle::get_top","cocktail/core/css/CoreStyle.hx",2579);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2580);
			{
				HX_STACK_LINE(2580)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)21,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2580)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)21)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2579)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_top,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_maxWidth( ){
	HX_STACK_PUSH("CoreStyle::get_maxWidth","cocktail/core/css/CoreStyle.hx",2574);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2575);
			{
				HX_STACK_LINE(2575)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)20,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2575)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)20)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2574)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)20)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)20)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_maxWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_minWidth( ){
	HX_STACK_PUSH("CoreStyle::get_minWidth","cocktail/core/css/CoreStyle.hx",2569);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2570);
			{
				HX_STACK_LINE(2570)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)19,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2570)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)19)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2569)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)19)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)19)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_minWidth,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_maxHeight( ){
	HX_STACK_PUSH("CoreStyle::get_maxHeight","cocktail/core/css/CoreStyle.hx",2564);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2565);
			{
				HX_STACK_LINE(2565)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)18,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2565)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)18)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2564)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)18)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)18)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_maxHeight,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_minHeight( ){
	HX_STACK_PUSH("CoreStyle::get_minHeight","cocktail/core/css/CoreStyle.hx",2559);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2560);
			{
				HX_STACK_LINE(2560)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)17,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2560)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)17)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2559)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)17)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)17)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_minHeight,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_height( ){
	HX_STACK_PUSH("CoreStyle::get_height","cocktail/core/css/CoreStyle.hx",2554);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2555);
			{
				HX_STACK_LINE(2555)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)16,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2555)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)16)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2554)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_height,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_width( ){
	HX_STACK_PUSH("CoreStyle::get_width","cocktail/core/css/CoreStyle.hx",2549);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2550);
			{
				HX_STACK_LINE(2550)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)15,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2550)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)15)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2549)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_width,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_paddingBottom( ){
	HX_STACK_PUSH("CoreStyle::get_paddingBottom","cocktail/core/css/CoreStyle.hx",2544);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2545);
			{
				HX_STACK_LINE(2545)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)14,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2545)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)14)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2544)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)14)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)14)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_paddingBottom,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_paddingTop( ){
	HX_STACK_PUSH("CoreStyle::get_paddingTop","cocktail/core/css/CoreStyle.hx",2539);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2540);
			{
				HX_STACK_LINE(2540)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)13,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2540)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)13)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2539)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)13)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)13)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_paddingTop,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_paddingRight( ){
	HX_STACK_PUSH("CoreStyle::get_paddingRight","cocktail/core/css/CoreStyle.hx",2534);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2535);
			{
				HX_STACK_LINE(2535)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)12,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2535)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)12)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2534)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)12)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)12)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_paddingRight,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_paddingLeft( ){
	HX_STACK_PUSH("CoreStyle::get_paddingLeft","cocktail/core/css/CoreStyle.hx",2529);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2530);
			{
				HX_STACK_LINE(2530)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)11,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2530)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)11)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2529)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)11)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)11)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_paddingLeft,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_marginBottom( ){
	HX_STACK_PUSH("CoreStyle::get_marginBottom","cocktail/core/css/CoreStyle.hx",2524);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2525);
			{
				HX_STACK_LINE(2525)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)9,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2525)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2524)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_marginBottom,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_marginTop( ){
	HX_STACK_PUSH("CoreStyle::get_marginTop","cocktail/core/css/CoreStyle.hx",2519);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2520);
			{
				HX_STACK_LINE(2520)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)8,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2520)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2519)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_marginTop,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_marginRight( ){
	HX_STACK_PUSH("CoreStyle::get_marginRight","cocktail/core/css/CoreStyle.hx",2514);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2515);
			{
				HX_STACK_LINE(2515)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)7,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2515)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2514)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_marginRight,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_marginLeft( ){
	HX_STACK_PUSH("CoreStyle::get_marginLeft","cocktail/core/css/CoreStyle.hx",2509);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2510);
			{
				HX_STACK_LINE(2510)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)6,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2510)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2509)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_marginLeft,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::get_opacity( ){
	HX_STACK_PUSH("CoreStyle::get_opacity","cocktail/core/css/CoreStyle.hx",2504);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2505);
			{
				HX_STACK_LINE(2505)
				::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)53,__this);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(2505)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)53)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(2504)
	return (  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(this)) )) );
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,get_opacity,return )

bool CoreStyle_obj::isNone( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CoreStyle::isNone","cocktail/core/css/CoreStyle.hx",2479);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(2479)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (property);
		switch((_switch_1)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(2482)
					{
						::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
						switch((_switch_2)->GetIndex()){
							case 18: {
								HX_STACK_LINE(2485)
								return true;
							}
							;break;
							default: {
								HX_STACK_LINE(2488)
								return false;
							}
						}
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2492)
				return false;
			}
		}
	}
	HX_STACK_LINE(2479)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,isNone,return )

bool CoreStyle_obj::isAuto( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CoreStyle::isAuto","cocktail/core/css/CoreStyle.hx",2457);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(2457)
	{
		::cocktail::core::css::CSSPropertyValue _switch_3 = (property);
		switch((_switch_3)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_3->__Param(0);
{
					HX_STACK_LINE(2460)
					{
						::cocktail::core::css::CSSKeywordValue _switch_4 = (value);
						switch((_switch_4)->GetIndex()){
							case 27: {
								HX_STACK_LINE(2463)
								return true;
							}
							;break;
							default: {
								HX_STACK_LINE(2466)
								return false;
							}
						}
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2470)
				return false;
			}
		}
	}
	HX_STACK_LINE(2457)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,isAuto,return )

::cocktail::core::css::CSSColorValue CoreStyle_obj::getColor( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CoreStyle::getColor","cocktail/core/css/CoreStyle.hx",2440);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(2440)
	{
		::cocktail::core::css::CSSPropertyValue _switch_5 = (value);
		switch((_switch_5)->GetIndex()){
			case 12: {
				::cocktail::core::css::CSSColorValue value1 = _switch_5->__Param(0);
{
					HX_STACK_LINE(2443)
					return value1;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2446)
				hx::Throw (HX_CSTRING("not a color value"));
			}
		}
	}
	HX_STACK_LINE(2440)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getColor,return )

Float CoreStyle_obj::getAbsoluteLength( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CoreStyle::getAbsoluteLength","cocktail/core/css/CoreStyle.hx",2425);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(2425)
	{
		::cocktail::core::css::CSSPropertyValue _switch_6 = (value);
		switch((_switch_6)->GetIndex()){
			case 18: {
				Float value1 = _switch_6->__Param(0);
{
					HX_STACK_LINE(2428)
					return value1;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2431)
				hx::Throw (HX_CSTRING("not an absolute length value"));
			}
		}
	}
	HX_STACK_LINE(2425)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getAbsoluteLength,return )

Array< ::cocktail::core::css::CSSPropertyValue > CoreStyle_obj::getList( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CoreStyle::getList","cocktail/core/css/CoreStyle.hx",2410);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(2410)
	{
		::cocktail::core::css::CSSPropertyValue _switch_7 = (value);
		switch((_switch_7)->GetIndex()){
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value1 = _switch_7->__Param(0);
{
					HX_STACK_LINE(2413)
					return value1;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2416)
				hx::Throw (HX_CSTRING("not a list value"));
			}
		}
	}
	HX_STACK_LINE(2410)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getList,return )

Float CoreStyle_obj::getNumber( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CoreStyle::getNumber","cocktail/core/css/CoreStyle.hx",2395);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(2395)
	{
		::cocktail::core::css::CSSPropertyValue _switch_8 = (value);
		switch((_switch_8)->GetIndex()){
			case 1: {
				Float value1 = _switch_8->__Param(0);
{
					HX_STACK_LINE(2398)
					return value1;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2401)
				hx::Throw (HX_CSTRING("not a number value"));
			}
		}
	}
	HX_STACK_LINE(2395)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getNumber,return )

::cocktail::core::css::CSSKeywordValue CoreStyle_obj::getKeyword( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CoreStyle::getKeyword","cocktail/core/css/CoreStyle.hx",2380);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(2380)
	{
		::cocktail::core::css::CSSPropertyValue _switch_9 = (value);
		switch((_switch_9)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value1 = _switch_9->__Param(0);
{
					HX_STACK_LINE(2383)
					return value1;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(2386)
				hx::Throw (HX_CSTRING("not a keyword value"));
			}
		}
	}
	HX_STACK_LINE(2380)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getKeyword,return )

bool CoreStyle_obj::hasNoneOrHiddenBorderStyle( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::hasNoneOrHiddenBorderStyle","cocktail/core/css/CoreStyle.hx",2334);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(2335)
	::cocktail::core::css::CSSPropertyValue borderStyle = null();		HX_STACK_VAR(borderStyle,"borderStyle");
	HX_STACK_LINE(2336)
	if (((propertyIndex == (int)62))){
		HX_STACK_LINE(2337)
		borderStyle = this->getComputedOrInitialProperty((int)72);
	}
	else{
		HX_STACK_LINE(2340)
		if (((propertyIndex == (int)63))){
			HX_STACK_LINE(2341)
			borderStyle = this->getComputedOrInitialProperty((int)73);
		}
		else{
			HX_STACK_LINE(2344)
			if (((propertyIndex == (int)64))){
				HX_STACK_LINE(2345)
				borderStyle = this->getComputedOrInitialProperty((int)74);
			}
			else{
				HX_STACK_LINE(2348)
				if (((propertyIndex == (int)65))){
					HX_STACK_LINE(2349)
					borderStyle = this->getComputedOrInitialProperty((int)75);
				}
				else{
					HX_STACK_LINE(2353)
					hx::Throw (HX_CSTRING("not a border width style"));
				}
			}
		}
	}
	HX_STACK_LINE(2357)
	{
		::cocktail::core::css::CSSPropertyValue _switch_10 = (borderStyle);
		switch((_switch_10)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_10->__Param(0);
{
					HX_STACK_LINE(2359)
					{
						::cocktail::core::css::CSSKeywordValue _switch_11 = (value);
						switch((_switch_11)->GetIndex()){
							case 18: case 37: {
								HX_STACK_LINE(2362)
								return true;
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
	HX_STACK_LINE(2371)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,hasNoneOrHiddenBorderStyle,return )

bool CoreStyle_obj::isInherited( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::isInherited","cocktail/core/css/CoreStyle.hx",2314);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(2314)
	switch( (int)(propertyIndex)){
		case (int)40: case (int)54: case (int)37: case (int)34: case (int)36: case (int)38: case (int)35: case (int)43: case (int)41: case (int)46: case (int)47: case (int)42: case (int)49: case (int)45: case (int)44: {
			HX_STACK_LINE(2317)
			return true;
		}
		;break;
		default: {
			HX_STACK_LINE(2324)
			return false;
		}
	}
	HX_STACK_LINE(2314)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,isInherited,return )

Float CoreStyle_obj::getAnimatablePropertyValue( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::getAnimatablePropertyValue","cocktail/core/css/CoreStyle.hx",2279);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(2279)
	switch( (int)(propertyIndex)){
		case (int)53: {
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2283);
					{
						HX_STACK_LINE(2283)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)53,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(2283)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)53)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(2282)
			{
				::cocktail::core::css::CSSPropertyValue _switch_12 = ((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
				switch((_switch_12)->GetIndex()){
					case 1: {
						Float value = _switch_12->__Param(0);
{
							HX_STACK_LINE(2285)
							return value;
						}
					}
					;break;
					case 18: {
						Float value = _switch_12->__Param(0);
{
							HX_STACK_LINE(2288)
							return value;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(2291)
						return (int)0;
					}
				}
			}
		}
		;break;
		default: {
			HX_STACK_LINE(2297)
			return ::Reflect_obj::field(this->usedValues,this->getIDLName(propertyIndex));
		}
	}
	HX_STACK_LINE(2279)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getAnimatablePropertyValue,return )

bool CoreStyle_obj::isAnimatable( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::isAnimatable","cocktail/core/css/CoreStyle.hx",2262);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(2262)
	switch( (int)(propertyIndex)){
		case (int)15: case (int)16: case (int)21: case (int)24: case (int)22: case (int)23: case (int)53: {
			HX_STACK_LINE(2265)
			return true;
		}
		;break;
		default: {
			HX_STACK_LINE(2269)
			return false;
		}
	}
	HX_STACK_LINE(2262)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,isAnimatable,return )

::String CoreStyle_obj::getIDLName( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::getIDLName","cocktail/core/css/CoreStyle.hx",2235);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(2235)
	switch( (int)(propertyIndex)){
		case (int)17: {
			HX_STACK_LINE(2238)
			return HX_CSTRING("height");
		}
		;break;
		case (int)18: {
			HX_STACK_LINE(2241)
			return HX_CSTRING("maxHeight");
		}
		;break;
		case (int)19: {
			HX_STACK_LINE(2244)
			return HX_CSTRING("minWidth");
		}
		;break;
		case (int)20: {
			HX_STACK_LINE(2247)
			return HX_CSTRING("maxWidth");
		}
		;break;
		default: {
			HX_STACK_LINE(2250)
			return ::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(propertyIndex);
		}
	}
	HX_STACK_LINE(2235)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getIDLName,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::getComputedOrInitialProperty( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::getComputedOrInitialProperty","cocktail/core/css/CoreStyle.hx",2214);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	struct _Function_1_1{
		inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CoreStyle_obj *__this,int &propertyIndex){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2215);
			{
				HX_STACK_LINE(2215)
				::cocktail::core::css::CSSStyleDeclaration _this = __this->computedValues;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(2215)
				if (((_this->_indexedProperties == null()))){
					HX_STACK_LINE(2215)
					_this->resetIndexedProperties();
					HX_STACK_LINE(2215)
					_this->resetPropertiesPositions();
				}
				HX_STACK_LINE(2215)
				return _this->_indexedProperties->__get(propertyIndex);
			}
			return null();
		}
	};
	HX_STACK_LINE(2215)
	::cocktail::core::css::TypedPropertyVO typedProperty = _Function_1_1::Block(this,propertyIndex);		HX_STACK_VAR(typedProperty,"typedProperty");
	HX_STACK_LINE(2217)
	if (((typedProperty == null()))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CoreStyle_obj *__this,int &propertyIndex){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",2219);
				{
					HX_STACK_LINE(2219)
					::cocktail::core::css::CSSStyleDeclaration _this = __this->_initialComputedStyleDeclaration;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(2219)
					if (((_this->_indexedProperties == null()))){
						HX_STACK_LINE(2219)
						_this->resetIndexedProperties();
						HX_STACK_LINE(2219)
						_this->resetPropertiesPositions();
					}
					HX_STACK_LINE(2219)
					return _this->_indexedProperties->__get(propertyIndex);
				}
				return null();
			}
		};
		HX_STACK_LINE(2218)
		return (_Function_2_1::Block(this,propertyIndex))->typedValue;
	}
	else{
		HX_STACK_LINE(2222)
		return typedProperty->typedValue;
	}
	HX_STACK_LINE(2217)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getComputedOrInitialProperty,return )

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::getTransitionablePropertyValue( int properyIndex){
	HX_STACK_PUSH("CoreStyle::getTransitionablePropertyValue","cocktail/core/css/CoreStyle.hx",2174);
	HX_STACK_THIS(this);
	HX_STACK_ARG(properyIndex,"properyIndex");
	HX_STACK_LINE(2174)
	if (((this->hasTransitionnableProperties == false))){
		HX_STACK_LINE(2177)
		return this->getComputedOrInitialProperty(properyIndex);
	}
	else{
		HX_STACK_LINE(2181)
		if (((this->_transitionManager->hasTransitionsInProgress == false))){
			HX_STACK_LINE(2182)
			return this->getComputedOrInitialProperty(properyIndex);
		}
		else{
			HX_STACK_LINE(2188)
			::cocktail::core::animation::Transition transition = this->_transitionManager->getTransition(properyIndex,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(transition,"transition");
			HX_STACK_LINE(2191)
			if (((transition != null()))){
				HX_STACK_LINE(2192)
				return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue());
			}
			else{
				HX_STACK_LINE(2197)
				return this->getComputedOrInitialProperty(properyIndex);
			}
		}
	}
	HX_STACK_LINE(2174)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getTransitionablePropertyValue,return )

Void CoreStyle_obj::onTransitionUpdate( ::cocktail::core::animation::Transition transition){
{
		HX_STACK_PUSH("CoreStyle::onTransitionUpdate","cocktail/core/css/CoreStyle.hx",2163);
		HX_STACK_THIS(this);
		HX_STACK_ARG(transition,"transition");
		HX_STACK_LINE(2163)
		this->htmlElement->invalidateStyle(transition->propertyIndex);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,onTransitionUpdate,(void))

Void CoreStyle_obj::onTransitionComplete( ::cocktail::core::animation::Transition transition){
{
		HX_STACK_PUSH("CoreStyle::onTransitionComplete","cocktail/core/css/CoreStyle.hx",2118);
		HX_STACK_THIS(this);
		HX_STACK_ARG(transition,"transition");
		HX_STACK_LINE(2119)
		this->htmlElement->invalidateStyle(transition->propertyIndex);
		HX_STACK_LINE(2122)
		::cocktail::core::html::HTMLDocument htmlDocument = this->htmlElement->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(2123)
		htmlDocument->invalidationManager->invalidatePendingAnimations();
		HX_STACK_LINE(2125)
		::cocktail::core::event::TransitionEvent transitionEvent = ::cocktail::core::event::TransitionEvent_obj::__new();		HX_STACK_VAR(transitionEvent,"transitionEvent");
		HX_STACK_LINE(2126)
		transitionEvent->initTransitionEvent(HX_CSTRING("transitionend"),true,true,::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(transition->propertyIndex),transition->transitionDuration,HX_CSTRING(""));
		HX_STACK_LINE(2129)
		if (((this->_pendingTransitionEndEvents == null()))){
			HX_STACK_LINE(2130)
			this->_pendingTransitionEndEvents = Array_obj< ::cocktail::core::event::TransitionEvent >::__new();
		}
		HX_STACK_LINE(2134)
		this->_pendingTransitionEndEvents->push(transitionEvent);
		HX_STACK_LINE(2138)
		if (((this->_pendingComputedValues != null()))){
			HX_STACK_LINE(2139)
			if (((this->_pendingComputedValues->__get(transition->propertyIndex) != null()))){
				HX_STACK_LINE(2144)
				this->_animator->registerPendingAnimation(transition->propertyIndex,this->getAnimatablePropertyValue(transition->propertyIndex));
				HX_STACK_LINE(2146)
				htmlDocument->invalidationManager->invalidatePendingAnimations();
				HX_STACK_LINE(2149)
				::cocktail::core::css::TypedPropertyVO pendingComputedProperty = this->_pendingComputedValues->__get(transition->propertyIndex);		HX_STACK_VAR(pendingComputedProperty,"pendingComputedProperty");
				HX_STACK_LINE(2150)
				this->computedValues->setTypedProperty(pendingComputedProperty->index,pendingComputedProperty->typedValue,pendingComputedProperty->important);
				HX_STACK_LINE(2152)
				this->_pendingComputedValues[transition->propertyIndex] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,onTransitionComplete,(void))

Void CoreStyle_obj::endPendingAnimation( ){
{
		HX_STACK_PUSH("CoreStyle::endPendingAnimation","cocktail/core/css/CoreStyle.hx",2087);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2089)
		if (((this->_pendingTransitionEndEvents == null()))){
			HX_STACK_LINE(2090)
			return null();
		}
		HX_STACK_LINE(2094)
		int length = this->_pendingTransitionEndEvents->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(2095)
		if (((length == (int)0))){
			HX_STACK_LINE(2096)
			return null();
		}
		HX_STACK_LINE(2100)
		{
			HX_STACK_LINE(2100)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(2100)
			while(((_g < length))){
				HX_STACK_LINE(2100)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(2102)
				this->htmlElement->dispatchEvent(this->_pendingTransitionEndEvents->__get(i));
			}
		}
		HX_STACK_LINE(2105)
		this->_pendingTransitionEndEvents = ::cocktail::core::utils::Utils_obj::clear(this->_pendingTransitionEndEvents);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,endPendingAnimation,(void))

bool CoreStyle_obj::startPendingAnimations( ){
	HX_STACK_PUSH("CoreStyle::startPendingAnimations","cocktail/core/css/CoreStyle.hx",2069);
	HX_STACK_THIS(this);
	HX_STACK_LINE(2073)
	if (((this->_animator == null()))){
		HX_STACK_LINE(2074)
		return false;
	}
	HX_STACK_LINE(2078)
	return this->_animator->startPendingAnimations(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,startPendingAnimations,return )

Void CoreStyle_obj::applyNoneOutlineWidth( ){
{
		HX_STACK_PUSH("CoreStyle::applyNoneOutlineWidth","cocktail/core/css/CoreStyle.hx",2045);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2045)
		{
			::cocktail::core::css::CSSPropertyValue _switch_13 = (this->getComputedOrInitialProperty((int)83));
			switch((_switch_13)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_13->__Param(0);
{
						HX_STACK_LINE(2048)
						{
							::cocktail::core::css::CSSKeywordValue _switch_14 = (value);
							switch((_switch_14)->GetIndex()){
								case 18: {
									HX_STACK_LINE(2051)
									this->computedValues->setTypedProperty((int)82,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0),false);
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
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,applyNoneOutlineWidth,(void))

Void CoreStyle_obj::applyHiddenBordersWidth( ){
{
		HX_STACK_PUSH("CoreStyle::applyHiddenBordersWidth","cocktail/core/css/CoreStyle.hx",2018);
		HX_STACK_THIS(this);
		HX_STACK_LINE(2019)
		if (((this->hasNoneOrHiddenBorderStyle((int)62) == true))){
			HX_STACK_LINE(2020)
			this->computedValues->setTypedProperty((int)62,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0),false);
		}
		HX_STACK_LINE(2024)
		if (((this->hasNoneOrHiddenBorderStyle((int)63) == true))){
			HX_STACK_LINE(2025)
			this->computedValues->setTypedProperty((int)63,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0),false);
		}
		HX_STACK_LINE(2029)
		if (((this->hasNoneOrHiddenBorderStyle((int)64) == true))){
			HX_STACK_LINE(2030)
			this->computedValues->setTypedProperty((int)64,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0),false);
		}
		HX_STACK_LINE(2034)
		if (((this->hasNoneOrHiddenBorderStyle((int)65) == true))){
			HX_STACK_LINE(2035)
			this->computedValues->setTypedProperty((int)65,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0),false);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,applyHiddenBordersWidth,(void))

Void CoreStyle_obj::applyPositionFloatAndDisplayRelationship( ){
{
		HX_STACK_PUSH("CoreStyle::applyPositionFloatAndDisplayRelationship","cocktail/core/css/CoreStyle.hx",1965);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1965)
		{
			::cocktail::core::css::CSSKeywordValue _switch_15 = (this->getKeyword(this->getComputedOrInitialProperty((int)1)));
			switch((_switch_15)->GetIndex()){
				case 34: case 35: {
					HX_STACK_LINE(1969)
					{
						::cocktail::core::css::CSSKeywordValue _switch_16 = (this->getKeyword(this->getComputedOrInitialProperty((int)0)));
						switch((_switch_16)->GetIndex()){
							case 30: case 29: {
								HX_STACK_LINE(1973)
								this->computedValues->setTypedProperty((int)0,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BLOCK_dyn()),false);
							}
							;break;
							default: {
							}
						}
					}
					HX_STACK_LINE(1979)
					{
						::cocktail::core::css::CSSKeywordValue _switch_17 = (this->getKeyword(this->getComputedOrInitialProperty((int)2)));
						switch((_switch_17)->GetIndex()){
							case 11: case 12: {
								HX_STACK_LINE(1983)
								this->computedValues->setTypedProperty((int)2,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()),false);
							}
							;break;
							default: {
							}
						}
					}
				}
				;break;
				default: {
					HX_STACK_LINE(1989)
					{
						::cocktail::core::css::CSSKeywordValue _switch_18 = (this->getKeyword(this->getComputedOrInitialProperty((int)2)));
						switch((_switch_18)->GetIndex()){
							case 11: case 12: {
								HX_STACK_LINE(1994)
								{
									::cocktail::core::css::CSSKeywordValue _switch_19 = (this->getKeyword(this->getComputedOrInitialProperty((int)0)));
									switch((_switch_19)->GetIndex()){
										case 30: case 29: {
											HX_STACK_LINE(1998)
											this->computedValues->setTypedProperty((int)0,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BLOCK_dyn()),false);
										}
										;break;
										default: {
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
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,applyPositionFloatAndDisplayRelationship,(void))

::cocktail::core::css::CSSPropertyValue CoreStyle_obj::getComputedProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue property,Float parentFontSize,Float parentXHeight,Float fontSize,Float xHeight,::cocktail::core::css::CSSColorValue parentColor){
	HX_STACK_PUSH("CoreStyle::getComputedProperty","cocktail/core/css/CoreStyle.hx",1563);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(property,"property");
	HX_STACK_ARG(parentFontSize,"parentFontSize");
	HX_STACK_ARG(parentXHeight,"parentXHeight");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_ARG(xHeight,"xHeight");
	HX_STACK_ARG(parentColor,"parentColor");
	HX_STACK_LINE(1564)
	switch( (int)(propertyIndex)){
		case (int)19: case (int)17: case (int)18: case (int)20: case (int)22: case (int)23: case (int)21: case (int)24: case (int)11: case (int)12: case (int)13: case (int)14: case (int)8: case (int)6: case (int)9: case (int)7: case (int)15: case (int)16: {
			HX_STACK_LINE(1566)
			{
				::cocktail::core::css::CSSPropertyValue _switch_20 = (property);
				switch((_switch_20)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_20->__Param(0);
{
							HX_STACK_LINE(1573)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					case 0: {
						int value = _switch_20->__Param(0);
{
							HX_STACK_LINE(1576)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(value);
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)62: case (int)63: case (int)64: case (int)65: case (int)82: {
			HX_STACK_LINE(1582)
			{
				::cocktail::core::css::CSSPropertyValue _switch_21 = (property);
				switch((_switch_21)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_21->__Param(0);
{
							HX_STACK_LINE(1587)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					case 0: {
						int value = _switch_21->__Param(0);
{
							HX_STACK_LINE(1590)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(value);
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_21->__Param(0);
{
							HX_STACK_LINE(1593)
							{
								::cocktail::core::css::CSSKeywordValue _switch_22 = (value);
								switch((_switch_22)->GetIndex()){
									case 73: case 61: case 74: {
										HX_STACK_LINE(1596)
										return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getBorderWidthFromBorderWidthKeyword(value));
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
		;break;
		case (int)57: {
			HX_STACK_LINE(1610)
			{
				::cocktail::core::css::CSSPropertyValue _switch_23 = (property);
				switch((_switch_23)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_23->__Param(0);
{
							HX_STACK_LINE(1613)
							{
								::cocktail::core::css::CSSKeywordValue _switch_24 = (value);
								switch((_switch_24)->GetIndex()){
									case 11: {
										HX_STACK_LINE(1616)
										return ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("left"));
									}
									;break;
									case 12: {
										HX_STACK_LINE(1619)
										return ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("right"));
									}
									;break;
									case 22: {
										HX_STACK_LINE(1622)
										return ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("top"));
									}
									;break;
									case 25: {
										HX_STACK_LINE(1625)
										return ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("bottom"));
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_23->__Param(0);
{
							HX_STACK_LINE(1632)
							int length = value->length;		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(1633)
							{
								HX_STACK_LINE(1633)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1633)
								while(((_g < length))){
									HX_STACK_LINE(1633)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1635)
									{
										::cocktail::core::css::CSSPropertyValue _switch_25 = (value->__get(i));
										switch((_switch_25)->GetIndex()){
											case 4: {
												::cocktail::core::css::CSSKeywordValue keyword = _switch_25->__Param(0);
{
													HX_STACK_LINE(1637)
													{
														::cocktail::core::css::CSSKeywordValue _switch_26 = (keyword);
														switch((_switch_26)->GetIndex()){
															case 11: {
																HX_STACK_LINE(1640)
																value[i] = ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("left"));
															}
															;break;
															case 12: {
																HX_STACK_LINE(1643)
																value[i] = ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("right"));
															}
															;break;
															case 22: {
																HX_STACK_LINE(1646)
																return ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("top"));
															}
															;break;
															case 25: {
																HX_STACK_LINE(1649)
																return ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(HX_CSTRING("bottom"));
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
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)53: {
			HX_STACK_LINE(1662)
			{
				::cocktail::core::css::CSSPropertyValue _switch_27 = (property);
				switch((_switch_27)->GetIndex()){
					case 1: {
						Float value = _switch_27->__Param(0);
{
							HX_STACK_LINE(1666)
							if (((value > (int)1))){
								HX_STACK_LINE(1667)
								return ::cocktail::core::css::CSSPropertyValue_obj::NUMBER((int)1);
							}
							HX_STACK_LINE(1670)
							if (((value < (int)0))){
								HX_STACK_LINE(1671)
								return ::cocktail::core::css::CSSPropertyValue_obj::NUMBER((int)0);
							}
						}
					}
					;break;
					case 0: {
						int value = _switch_27->__Param(0);
{
							HX_STACK_LINE(1676)
							if (((value < (int)0))){
								HX_STACK_LINE(1677)
								return ::cocktail::core::css::CSSPropertyValue_obj::NUMBER((int)0);
							}
							HX_STACK_LINE(1680)
							if (((value > (int)1))){
								HX_STACK_LINE(1681)
								return ::cocktail::core::css::CSSPropertyValue_obj::NUMBER((int)1);
							}
							HX_STACK_LINE(1684)
							return ::cocktail::core::css::CSSPropertyValue_obj::NUMBER(value);
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)34: {
			HX_STACK_LINE(1689)
			{
				::cocktail::core::css::CSSPropertyValue _switch_28 = (property);
				switch((_switch_28)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_28->__Param(0);
{
							HX_STACK_LINE(1692)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,parentFontSize,parentXHeight));
						}
					}
					;break;
					case 2: {
						Float value = _switch_28->__Param(0);
{
							HX_STACK_LINE(1695)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((parentFontSize * ((value * 0.01))));
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_28->__Param(0);
{
							HX_STACK_LINE(1698)
							{
								::cocktail::core::css::CSSKeywordValue _switch_29 = (value);
								switch((_switch_29)->GetIndex()){
									case 58: case 59: case 60: case 61: case 62: case 63: case 64: {
										HX_STACK_LINE(1701)
										return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getFontSizeFromAbsoluteSizeValue(value));
									}
									;break;
									case 65: case 66: {
										HX_STACK_LINE(1704)
										return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getFontSizeFromRelativeSizeValue(value,parentFontSize));
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
		;break;
		case (int)61: {
			HX_STACK_LINE(1713)
			{
				::cocktail::core::css::CSSPropertyValue _switch_30 = (property);
				switch((_switch_30)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_30->__Param(0);
{
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)35: {
			HX_STACK_LINE(1723)
			{
				::cocktail::core::css::CSSPropertyValue _switch_31 = (property);
				switch((_switch_31)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_31->__Param(0);
{
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)48: {
			HX_STACK_LINE(1733)
			{
				::cocktail::core::css::CSSPropertyValue _switch_32 = (property);
				switch((_switch_32)->GetIndex()){
					case 0: {
						int value = _switch_32->__Param(0);
{
							HX_STACK_LINE(1736)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0);
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_32->__Param(0);
{
							HX_STACK_LINE(1739)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)54: {
			HX_STACK_LINE(1745)
			{
				::cocktail::core::css::CSSPropertyValue _switch_33 = (property);
				switch((_switch_33)->GetIndex()){
					case 5: {
						::String value = _switch_33->__Param(0);
{
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)41: {
			HX_STACK_LINE(1755)
			{
				::cocktail::core::css::CSSPropertyValue _switch_34 = (property);
				switch((_switch_34)->GetIndex()){
					case 1: {
						Float value = _switch_34->__Param(0);
{
							HX_STACK_LINE(1758)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((value * fontSize));
						}
					}
					;break;
					case 0: {
						int value = _switch_34->__Param(0);
{
							HX_STACK_LINE(1761)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((value * fontSize));
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_34->__Param(0);
{
							HX_STACK_LINE(1764)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					case 2: {
						Float value = _switch_34->__Param(0);
{
							HX_STACK_LINE(1767)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((fontSize * ((value * 0.01))));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)47: {
			HX_STACK_LINE(1773)
			{
				::cocktail::core::css::CSSPropertyValue _switch_35 = (property);
				switch((_switch_35)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_35->__Param(0);
{
							HX_STACK_LINE(1776)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					case 0: {
						int value = _switch_35->__Param(0);
{
							HX_STACK_LINE(1779)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(value);
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)43: {
			HX_STACK_LINE(1785)
			{
				::cocktail::core::css::CSSPropertyValue _switch_36 = (property);
				switch((_switch_36)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_36->__Param(0);
{
							HX_STACK_LINE(1788)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)44: {
			HX_STACK_LINE(1794)
			{
				::cocktail::core::css::CSSPropertyValue _switch_37 = (property);
				switch((_switch_37)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_37->__Param(0);
{
							HX_STACK_LINE(1797)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_37->__Param(0);
{
							HX_STACK_LINE(1800)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0);
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)40: {
			HX_STACK_LINE(1806)
			{
				::cocktail::core::css::CSSPropertyValue _switch_38 = (property);
				switch((_switch_38)->GetIndex()){
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_38->__Param(0);
{
							HX_STACK_LINE(1809)
							return ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSValueConverter_obj::getComputedCSSColorFromCSSColor(value,parentColor));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)25: case (int)67: case (int)68: case (int)69: case (int)70: {
			HX_STACK_LINE(1815)
			{
				::cocktail::core::css::CSSPropertyValue _switch_39 = (property);
				switch((_switch_39)->GetIndex()){
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_39->__Param(0);
{
							HX_STACK_LINE(1820)
							return ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSValueConverter_obj::getComputedCSSColorFromCSSColor(value,this->getColor(this->getComputedOrInitialProperty((int)40))));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)26: {
			HX_STACK_LINE(1827)
			{
				::cocktail::core::css::CSSPropertyValue _switch_40 = (property);
				switch((_switch_40)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_40->__Param(0);
{
						}
					}
					;break;
					case 5: {
						::String value = _switch_40->__Param(0);
{
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)30: {
			HX_STACK_LINE(1837)
			{
				::cocktail::core::css::CSSPropertyValue _switch_41 = (property);
				switch((_switch_41)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_41->__Param(0);
{
							HX_STACK_LINE(1840)
							{
								::cocktail::core::css::CSSKeywordValue _switch_42 = (value);
								switch((_switch_42)->GetIndex()){
									case 11: case 12: {
										HX_STACK_LINE(1843)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(value)).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CENTER_dyn())));
									}
									;break;
									case 22: case 25: {
										HX_STACK_LINE(1846)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CENTER_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(value)));
									}
									;break;
									default: {
										HX_STACK_LINE(1849)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(value)).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CENTER_dyn())));
									}
								}
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_41->__Param(0);
{
							HX_STACK_LINE(1854)
							return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight))).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CENTER_dyn())));
						}
					}
					;break;
					case 2: {
						Float value = _switch_41->__Param(0);
{
							HX_STACK_LINE(1857)
							return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE(value)).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CENTER_dyn())));
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_41->__Param(0);
{
							HX_STACK_LINE(1861)
							::cocktail::core::css::CSSPropertyValue backgroundPositionX = null();		HX_STACK_VAR(backgroundPositionX,"backgroundPositionX");
							HX_STACK_LINE(1862)
							::cocktail::core::css::CSSPropertyValue backgroundPostionY = null();		HX_STACK_VAR(backgroundPostionY,"backgroundPostionY");
							HX_STACK_LINE(1863)
							{
								::cocktail::core::css::CSSPropertyValue _switch_43 = (value->__get((int)0));
								switch((_switch_43)->GetIndex()){
									case 7: {
										::cocktail::core::css::CSSLengthValue value1 = _switch_43->__Param(0);
{
											HX_STACK_LINE(1865)
											backgroundPositionX = ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value1,fontSize,xHeight));
										}
									}
									;break;
									default: {
										HX_STACK_LINE(1868)
										backgroundPositionX = value->__get((int)0);
									}
								}
							}
							HX_STACK_LINE(1872)
							{
								::cocktail::core::css::CSSPropertyValue _switch_44 = (value->__get((int)1));
								switch((_switch_44)->GetIndex()){
									case 7: {
										::cocktail::core::css::CSSLengthValue value1 = _switch_44->__Param(0);
{
											HX_STACK_LINE(1874)
											backgroundPostionY = ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value1,fontSize,xHeight));
										}
									}
									;break;
									default: {
										HX_STACK_LINE(1877)
										backgroundPostionY = value->__get((int)1);
									}
								}
							}
							HX_STACK_LINE(1881)
							return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(backgroundPositionX).Add(backgroundPostionY));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)27: {
			HX_STACK_LINE(1886)
			{
				::cocktail::core::css::CSSPropertyValue _switch_45 = (property);
				switch((_switch_45)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_45->__Param(0);
{
							HX_STACK_LINE(1889)
							{
								::cocktail::core::css::CSSKeywordValue _switch_46 = (value);
								switch((_switch_46)->GetIndex()){
									case 67: {
										HX_STACK_LINE(1892)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn())));
									}
									;break;
									case 72: {
										HX_STACK_LINE(1895)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NO_REPEAT_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NO_REPEAT_dyn())));
									}
									;break;
									case 71: {
										HX_STACK_LINE(1898)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ROUND_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ROUND_dyn())));
									}
									;break;
									case 70: {
										HX_STACK_LINE(1901)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SPACE_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SPACE_dyn())));
									}
									;break;
									case 68: {
										HX_STACK_LINE(1904)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NO_REPEAT_dyn())));
									}
									;break;
									case 69: {
										HX_STACK_LINE(1907)
										return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NO_REPEAT_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn())));
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
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_45->__Param(0);
{
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)29: {
			HX_STACK_LINE(1919)
			{
				::cocktail::core::css::CSSPropertyValue _switch_47 = (property);
				switch((_switch_47)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_47->__Param(0);
{
							HX_STACK_LINE(1922)
							return ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value,fontSize,xHeight));
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_47->__Param(0);
{
							HX_STACK_LINE(1927)
							::cocktail::core::css::CSSPropertyValue backgroundSizeX = null();		HX_STACK_VAR(backgroundSizeX,"backgroundSizeX");
							HX_STACK_LINE(1928)
							::cocktail::core::css::CSSPropertyValue backgroundSizeY = null();		HX_STACK_VAR(backgroundSizeY,"backgroundSizeY");
							HX_STACK_LINE(1930)
							{
								::cocktail::core::css::CSSPropertyValue _switch_48 = (value->__get((int)0));
								switch((_switch_48)->GetIndex()){
									case 7: {
										::cocktail::core::css::CSSLengthValue value1 = _switch_48->__Param(0);
{
											HX_STACK_LINE(1932)
											backgroundSizeX = ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value1,fontSize,xHeight));
										}
									}
									;break;
									default: {
										HX_STACK_LINE(1935)
										backgroundSizeX = value->__get((int)0);
									}
								}
							}
							HX_STACK_LINE(1939)
							{
								::cocktail::core::css::CSSPropertyValue _switch_49 = (value->__get((int)1));
								switch((_switch_49)->GetIndex()){
									case 7: {
										::cocktail::core::css::CSSLengthValue value1 = _switch_49->__Param(0);
{
											HX_STACK_LINE(1941)
											backgroundSizeY = ::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::css::CSSValueConverter_obj::getPixelFromLength(value1,fontSize,xHeight));
										}
									}
									;break;
									default: {
										HX_STACK_LINE(1944)
										backgroundSizeY = value->__get((int)1);
									}
								}
							}
							HX_STACK_LINE(1948)
							return ::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(backgroundSizeX).Add(backgroundSizeY));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
	}
	HX_STACK_LINE(1954)
	return property;
}


HX_DEFINE_DYNAMIC_FUNC7(CoreStyle_obj,getComputedProperty,return )

bool CoreStyle_obj::setProperty( int propertyIndex,::cocktail::core::css::TypedPropertyVO cascadedProperty,::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration initialStyleDeclaration,::cocktail::core::css::CSSColorValue parentColor,Float parentFontSize,Float parentXHeight,Float fontSize,Float xHeight,bool programmaticChange,bool isInherited,bool isInitial){
	HX_STACK_PUSH("CoreStyle::setProperty","cocktail/core/css/CoreStyle.hx",1379);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(cascadedProperty,"cascadedProperty");
	HX_STACK_ARG(parentStyleDeclaration,"parentStyleDeclaration");
	HX_STACK_ARG(initialStyleDeclaration,"initialStyleDeclaration");
	HX_STACK_ARG(parentColor,"parentColor");
	HX_STACK_ARG(parentFontSize,"parentFontSize");
	HX_STACK_ARG(parentXHeight,"parentXHeight");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_ARG(xHeight,"xHeight");
	HX_STACK_ARG(programmaticChange,"programmaticChange");
	HX_STACK_ARG(isInherited,"isInherited");
	HX_STACK_ARG(isInitial,"isInitial");
	HX_STACK_LINE(1380)
	::cocktail::core::css::CSSPropertyValue property = cascadedProperty->typedValue;		HX_STACK_VAR(property,"property");
	struct _Function_1_1{
		inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CoreStyle_obj *__this,int &propertyIndex){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1383);
			{
				HX_STACK_LINE(1383)
				::cocktail::core::css::CSSStyleDeclaration _this = __this->specifiedValues;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(1383)
				if (((_this->_indexedProperties == null()))){
					HX_STACK_LINE(1383)
					_this->resetIndexedProperties();
					HX_STACK_LINE(1383)
					_this->resetPropertiesPositions();
				}
				HX_STACK_LINE(1383)
				return _this->_indexedProperties->__get(propertyIndex);
			}
			return null();
		}
	};
	HX_STACK_LINE(1383)
	::cocktail::core::css::TypedPropertyVO specifiedProperty = _Function_1_1::Block(this,propertyIndex);		HX_STACK_VAR(specifiedProperty,"specifiedProperty");
	HX_STACK_LINE(1387)
	if (((specifiedProperty != null()))){
		HX_STACK_LINE(1388)
		if (((property == specifiedProperty->typedValue))){
			HX_STACK_LINE(1390)
			return false;
		}
	}
	HX_STACK_LINE(1395)
	if (((specifiedProperty != null()))){
		HX_STACK_LINE(1396)
		this->specifiedValues->setTypedProperty(propertyIndex,property,cascadedProperty->important);
	}
	else{
		HX_STACK_LINE(1401)
		this->specifiedValues->setTypedPropertyInitial(propertyIndex,property,cascadedProperty->important);
	}
	HX_STACK_LINE(1408)
	::cocktail::core::css::CSSPropertyValue computedProperty = null();		HX_STACK_VAR(computedProperty,"computedProperty");
	HX_STACK_LINE(1412)
	if (((isInitial == false))){
		HX_STACK_LINE(1413)
		{
			::cocktail::core::css::CSSPropertyValue _switch_50 = (property);
			switch((_switch_50)->GetIndex()){
				case 16: {
					struct _Function_3_1{
						inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &parentStyleDeclaration,int &propertyIndex){
							HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1419);
							{
								HX_STACK_LINE(1419)
								if (((parentStyleDeclaration->_indexedProperties == null()))){
									HX_STACK_LINE(1419)
									parentStyleDeclaration->resetIndexedProperties();
									HX_STACK_LINE(1419)
									parentStyleDeclaration->resetPropertiesPositions();
								}
								HX_STACK_LINE(1419)
								return parentStyleDeclaration->_indexedProperties->__get(propertyIndex);
							}
							return null();
						}
					};
					HX_STACK_LINE(1419)
					computedProperty = (_Function_3_1::Block(parentStyleDeclaration,propertyIndex))->typedValue;
					HX_STACK_LINE(1422)
					isInherited = true;
				}
				;break;
				case 17: {
					struct _Function_3_1{
						inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &initialStyleDeclaration,int &propertyIndex){
							HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1430);
							{
								HX_STACK_LINE(1430)
								if (((initialStyleDeclaration->_indexedProperties == null()))){
									HX_STACK_LINE(1430)
									initialStyleDeclaration->resetIndexedProperties();
									HX_STACK_LINE(1430)
									initialStyleDeclaration->resetPropertiesPositions();
								}
								HX_STACK_LINE(1430)
								return initialStyleDeclaration->_indexedProperties->__get(propertyIndex);
							}
							return null();
						}
					};
					HX_STACK_LINE(1429)
					computedProperty = (_Function_3_1::Block(initialStyleDeclaration,propertyIndex))->typedValue;
				}
				;break;
				default: {
					HX_STACK_LINE(1432)
					computedProperty = this->getComputedProperty(propertyIndex,property,parentFontSize,parentXHeight,fontSize,xHeight,parentColor);
				}
			}
		}
	}
	else{
		HX_STACK_LINE(1439)
		computedProperty = this->getComputedProperty(propertyIndex,property,parentFontSize,parentXHeight,fontSize,xHeight,parentColor);
	}
	HX_STACK_LINE(1447)
	bool registerPengingComputedProperty = false;		HX_STACK_VAR(registerPengingComputedProperty,"registerPengingComputedProperty");
	HX_STACK_LINE(1450)
	if (((this->hasTransitionnableProperties == true))){
		HX_STACK_LINE(1451)
		if (((bool((programmaticChange == true)) && bool((isInherited == false))))){
			HX_STACK_LINE(1454)
			if ((this->isAnimatable(propertyIndex))){
				HX_STACK_LINE(1458)
				if (((this->_animator == null()))){
					HX_STACK_LINE(1459)
					this->initAnimator();
				}
				HX_STACK_LINE(1463)
				::cocktail::core::animation::Transition transition = this->_transitionManager->getTransition(propertyIndex,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(1465)
				if (((transition != null()))){
					HX_STACK_LINE(1467)
					registerPengingComputedProperty = true;
					HX_STACK_LINE(1476)
					{
						::cocktail::core::css::CSSPropertyValue _switch_51 = (computedProperty);
						switch((_switch_51)->GetIndex()){
							case 18: {
								Float value = _switch_51->__Param(0);
{
									HX_STACK_LINE(1480)
									bool didRevert = this->_animator->revertTransitionIfNeeded(transition,value,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(didRevert,"didRevert");
									HX_STACK_LINE(1484)
									if (((didRevert == true))){
										HX_STACK_LINE(1485)
										registerPengingComputedProperty = false;
									}
								}
							}
							;break;
							default: {
							}
						}
					}
				}
				else{
					HX_STACK_LINE(1495)
					this->_animator->registerPendingAnimation(propertyIndex,this->getAnimatablePropertyValue(propertyIndex));
					HX_STACK_LINE(1496)
					::cocktail::core::html::HTMLDocument htmlDocument = this->htmlElement->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
					HX_STACK_LINE(1497)
					htmlDocument->invalidationManager->invalidatePendingAnimations();
				}
			}
		}
	}
	HX_STACK_LINE(1503)
	if (((specifiedProperty != null()))){
		HX_STACK_LINE(1504)
		if (((registerPengingComputedProperty == false))){
			HX_STACK_LINE(1506)
			this->computedValues->setTypedProperty(propertyIndex,computedProperty,cascadedProperty->important);
		}
		else{
			HX_STACK_LINE(1513)
			if (((this->_pendingComputedValues == null()))){
				HX_STACK_LINE(1514)
				this->initPendingComputedValues();
			}
			HX_STACK_LINE(1517)
			::cocktail::core::css::TypedPropertyVO typedComputedProperty = ::cocktail::core::css::TypedPropertyVO_obj::__new();		HX_STACK_VAR(typedComputedProperty,"typedComputedProperty");
			HX_STACK_LINE(1518)
			typedComputedProperty->important = cascadedProperty->important;
			HX_STACK_LINE(1519)
			typedComputedProperty->index = propertyIndex;
			HX_STACK_LINE(1520)
			typedComputedProperty->typedValue = computedProperty;
			HX_STACK_LINE(1522)
			this->_pendingComputedValues[propertyIndex] = typedComputedProperty;
		}
	}
	else{
		HX_STACK_LINE(1526)
		if (((registerPengingComputedProperty == false))){
			HX_STACK_LINE(1528)
			this->computedValues->setTypedPropertyInitial(propertyIndex,computedProperty,cascadedProperty->important);
		}
	}
	HX_STACK_LINE(1534)
	this->htmlElement->invalidateStyle(propertyIndex);
	HX_STACK_LINE(1536)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC12(CoreStyle_obj,setProperty,return )

bool CoreStyle_obj::setInitialProperty( int propertyIndex){
	HX_STACK_PUSH("CoreStyle::setInitialProperty","cocktail/core/css/CoreStyle.hx",1337);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	struct _Function_1_1{
		inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CoreStyle_obj *__this,int &propertyIndex){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1341);
			{
				HX_STACK_LINE(1341)
				::cocktail::core::css::CSSStyleDeclaration _this = __this->specifiedValues;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(1341)
				if (((_this->_indexedProperties == null()))){
					HX_STACK_LINE(1341)
					_this->resetIndexedProperties();
					HX_STACK_LINE(1341)
					_this->resetPropertiesPositions();
				}
				HX_STACK_LINE(1341)
				return _this->_indexedProperties->__get(propertyIndex);
			}
			return null();
		}
	};
	HX_STACK_LINE(1341)
	if (((_Function_1_1::Block(this,propertyIndex) != null()))){
		HX_STACK_LINE(1345)
		this->specifiedValues->removeProperty(propertyIndex);
		HX_STACK_LINE(1346)
		this->computedValues->removeProperty(propertyIndex);
		HX_STACK_LINE(1347)
		this->htmlElement->invalidateStyle(propertyIndex);
		HX_STACK_LINE(1349)
		return true;
	}
	else{
		struct _Function_2_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CoreStyle_obj *__this,int &propertyIndex){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1357);
				{
					HX_STACK_LINE(1357)
					::cocktail::core::css::CSSStyleDeclaration _this = __this->computedValues;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1357)
					if (((_this->_indexedProperties == null()))){
						HX_STACK_LINE(1357)
						_this->resetIndexedProperties();
						HX_STACK_LINE(1357)
						_this->resetPropertiesPositions();
					}
					HX_STACK_LINE(1357)
					return _this->_indexedProperties->__get(propertyIndex);
				}
				return null();
			}
		};
		HX_STACK_LINE(1357)
		if (((_Function_2_1::Block(this,propertyIndex) != null()))){
			HX_STACK_LINE(1358)
			this->computedValues->removeProperty(propertyIndex);
		}
	}
	HX_STACK_LINE(1363)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,setInitialProperty,return )

bool CoreStyle_obj::cascadeProperty( int propertyIndex,::cocktail::core::css::CSSStyleDeclaration initialStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration styleSheetDeclaration,::cocktail::core::css::CSSStyleDeclaration inlineStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration,::cocktail::core::css::CSSColorValue parentColor,Float parentFontSize,Float parentXHeight,Float fontSize,Float xHeight,bool programmaticChange,bool hasInlineStyle,bool hasStyleSheetStyle){
	HX_STACK_PUSH("CoreStyle::cascadeProperty","cocktail/core/css/CoreStyle.hx",1286);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(initialStyleDeclaration,"initialStyleDeclaration");
	HX_STACK_ARG(styleSheetDeclaration,"styleSheetDeclaration");
	HX_STACK_ARG(inlineStyleDeclaration,"inlineStyleDeclaration");
	HX_STACK_ARG(parentStyleDeclaration,"parentStyleDeclaration");
	HX_STACK_ARG(parentColor,"parentColor");
	HX_STACK_ARG(parentFontSize,"parentFontSize");
	HX_STACK_ARG(parentXHeight,"parentXHeight");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_ARG(xHeight,"xHeight");
	HX_STACK_ARG(programmaticChange,"programmaticChange");
	HX_STACK_ARG(hasInlineStyle,"hasInlineStyle");
	HX_STACK_ARG(hasStyleSheetStyle,"hasStyleSheetStyle");
	HX_STACK_LINE(1289)
	if (((hasInlineStyle == true))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &inlineStyleDeclaration,int &propertyIndex){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1291);
				{
					HX_STACK_LINE(1291)
					if (((inlineStyleDeclaration->_indexedProperties == null()))){
						HX_STACK_LINE(1291)
						inlineStyleDeclaration->resetIndexedProperties();
						HX_STACK_LINE(1291)
						inlineStyleDeclaration->resetPropertiesPositions();
					}
					HX_STACK_LINE(1291)
					return inlineStyleDeclaration->_indexedProperties->__get(propertyIndex);
				}
				return null();
			}
		};
		HX_STACK_LINE(1291)
		::cocktail::core::css::TypedPropertyVO typedProperty = _Function_2_1::Block(inlineStyleDeclaration,propertyIndex);		HX_STACK_VAR(typedProperty,"typedProperty");
		HX_STACK_LINE(1292)
		if (((typedProperty != null()))){
			HX_STACK_LINE(1293)
			return this->setProperty(propertyIndex,typedProperty,parentStyleDeclaration,initialStyleDeclaration,parentColor,parentFontSize,parentXHeight,fontSize,xHeight,programmaticChange,false,false);
		}
	}
	HX_STACK_LINE(1299)
	if (((hasStyleSheetStyle == true))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &styleSheetDeclaration,int &propertyIndex){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1301);
				{
					HX_STACK_LINE(1301)
					if (((styleSheetDeclaration->_indexedProperties == null()))){
						HX_STACK_LINE(1301)
						styleSheetDeclaration->resetIndexedProperties();
						HX_STACK_LINE(1301)
						styleSheetDeclaration->resetPropertiesPositions();
					}
					HX_STACK_LINE(1301)
					return styleSheetDeclaration->_indexedProperties->__get(propertyIndex);
				}
				return null();
			}
		};
		HX_STACK_LINE(1301)
		::cocktail::core::css::TypedPropertyVO typedProperty = _Function_2_1::Block(styleSheetDeclaration,propertyIndex);		HX_STACK_VAR(typedProperty,"typedProperty");
		HX_STACK_LINE(1302)
		if (((typedProperty != null()))){
			HX_STACK_LINE(1303)
			return this->setProperty(propertyIndex,typedProperty,parentStyleDeclaration,initialStyleDeclaration,parentColor,parentFontSize,parentXHeight,fontSize,xHeight,programmaticChange,false,false);
		}
	}
	struct _Function_1_1{
		inline static bool Block( int &propertyIndex){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1310);
			{
				HX_STACK_LINE(1310)
				switch( (int)(propertyIndex)){
					case (int)40: case (int)54: case (int)37: case (int)34: case (int)36: case (int)38: case (int)35: case (int)43: case (int)41: case (int)46: case (int)47: case (int)42: case (int)49: case (int)45: case (int)44: {
						HX_STACK_LINE(1310)
						return true;
					}
					;break;
					default: {
						HX_STACK_LINE(1310)
						return false;
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(1310)
	if (((_Function_1_1::Block(propertyIndex) == true))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &parentStyleDeclaration,int &propertyIndex){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1312);
				{
					HX_STACK_LINE(1312)
					if (((parentStyleDeclaration->_indexedProperties == null()))){
						HX_STACK_LINE(1312)
						parentStyleDeclaration->resetIndexedProperties();
						HX_STACK_LINE(1312)
						parentStyleDeclaration->resetPropertiesPositions();
					}
					HX_STACK_LINE(1312)
					return parentStyleDeclaration->_indexedProperties->__get(propertyIndex);
				}
				return null();
			}
		};
		HX_STACK_LINE(1311)
		if (((_Function_2_1::Block(parentStyleDeclaration,propertyIndex) != null()))){
			struct _Function_3_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &parentStyleDeclaration,int &propertyIndex){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1314);
					{
						HX_STACK_LINE(1314)
						if (((parentStyleDeclaration->_indexedProperties == null()))){
							HX_STACK_LINE(1314)
							parentStyleDeclaration->resetIndexedProperties();
							HX_STACK_LINE(1314)
							parentStyleDeclaration->resetPropertiesPositions();
						}
						HX_STACK_LINE(1314)
						return parentStyleDeclaration->_indexedProperties->__get(propertyIndex);
					}
					return null();
				}
			};
			HX_STACK_LINE(1313)
			return this->setProperty(propertyIndex,_Function_3_1::Block(parentStyleDeclaration,propertyIndex),parentStyleDeclaration,initialStyleDeclaration,parentColor,parentFontSize,parentXHeight,fontSize,xHeight,programmaticChange,true,false);
		}
		else{
			HX_STACK_LINE(1319)
			return this->setInitialProperty(propertyIndex);
		}
	}
	HX_STACK_LINE(1325)
	return this->setInitialProperty(propertyIndex);
}


HX_DEFINE_DYNAMIC_FUNC13(CoreStyle_obj,cascadeProperty,return )

Void CoreStyle_obj::updateCoreStyleAttribute( ::cocktail::core::css::CascadeManager cascadeManager,bool isFirstCascade){
{
		HX_STACK_PUSH("CoreStyle::updateCoreStyleAttribute","cocktail/core/css/CoreStyle.hx",999);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cascadeManager,"cascadeManager");
		HX_STACK_ARG(isFirstCascade,"isFirstCascade");
		HX_STACK_LINE(1000)
		if (((bool((cascadeManager->hasFloat == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1001)
			this->isFloat = (this->isNone(this->getComputedOrInitialProperty((int)2)) == false);
		}
		HX_STACK_LINE(1005)
		if (((bool((bool((bool((cascadeManager->hasDisplay == true)) || bool((cascadeManager->hasPosition == true)))) || bool((cascadeManager->hasFloat == true)))) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1008)
			this->isInlineLevel = false;
			HX_STACK_LINE(1009)
			this->isInlineBlock = false;
			HX_STACK_LINE(1010)
			this->isBlock = false;
			HX_STACK_LINE(1011)
			this->isInline = false;
			HX_STACK_LINE(1013)
			{
				::cocktail::core::css::CSSKeywordValue _switch_52 = (this->getKeyword(this->getComputedOrInitialProperty((int)0)));
				switch((_switch_52)->GetIndex()){
					case 30: {
						HX_STACK_LINE(1016)
						this->isInlineLevel = true;
						HX_STACK_LINE(1017)
						this->isInline = true;
					}
					;break;
					case 29: {
						HX_STACK_LINE(1020)
						this->isInlineLevel = true;
						HX_STACK_LINE(1021)
						this->isInlineBlock = true;
					}
					;break;
					case 28: {
						HX_STACK_LINE(1023)
						this->isBlock = true;
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(1030)
		if (((bool((cascadeManager->hasVisible == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1031)
			this->isVisible = (this->getKeyword(this->getComputedOrInitialProperty((int)49)) != ::cocktail::core::css::CSSKeywordValue_obj::HIDDEN_dyn());
		}
		HX_STACK_LINE(1035)
		if (((bool((cascadeManager->hasPosition == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1037)
			this->isPositioned = false;
			HX_STACK_LINE(1038)
			this->isRelativePositioned = false;
			HX_STACK_LINE(1039)
			this->isFixedPositioned = false;
			HX_STACK_LINE(1040)
			this->isAbsolutelyPositioned = false;
			HX_STACK_LINE(1042)
			{
				::cocktail::core::css::CSSKeywordValue _switch_53 = (this->getKeyword(this->getComputedOrInitialProperty((int)1)));
				switch((_switch_53)->GetIndex()){
					case 32: {
					}
					;break;
					case 34: {
						HX_STACK_LINE(1047)
						this->isPositioned = true;
						HX_STACK_LINE(1048)
						this->isAbsolutelyPositioned = true;
					}
					;break;
					case 35: {
						HX_STACK_LINE(1051)
						this->isPositioned = true;
						HX_STACK_LINE(1052)
						this->isFixedPositioned = true;
						HX_STACK_LINE(1053)
						this->isAbsolutelyPositioned = true;
					}
					;break;
					case 33: {
						HX_STACK_LINE(1056)
						this->isPositioned = true;
						HX_STACK_LINE(1057)
						this->isRelativePositioned = true;
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(1063)
		if (((bool((bool(cascadeManager->hasOverflowX) || bool(cascadeManager->hasOverflowY))) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1065)
			this->canAlwaysOverflow = true;
			HX_STACK_LINE(1066)
			this->hasHiddenOrScrollOverflowX = false;
			HX_STACK_LINE(1068)
			{
				::cocktail::core::css::CSSKeywordValue _switch_54 = (this->getKeyword(this->getComputedOrInitialProperty((int)51)));
				switch((_switch_54)->GetIndex()){
					case 36: {
					}
					;break;
					case 37: case 38: {
						HX_STACK_LINE(1073)
						this->hasHiddenOrScrollOverflowX = true;
						HX_STACK_LINE(1074)
						this->canAlwaysOverflow = false;
					}
					;break;
					default: {
						HX_STACK_LINE(1076)
						this->canAlwaysOverflow = false;
					}
				}
			}
			HX_STACK_LINE(1080)
			{
				::cocktail::core::css::CSSKeywordValue _switch_55 = (this->getKeyword(this->getComputedOrInitialProperty((int)52)));
				switch((_switch_55)->GetIndex()){
					case 36: {
					}
					;break;
					case 37: case 38: {
						HX_STACK_LINE(1085)
						this->hasHiddenOrScrollOverflowY = true;
						HX_STACK_LINE(1086)
						this->canAlwaysOverflow = false;
					}
					;break;
					default: {
						HX_STACK_LINE(1088)
						this->canAlwaysOverflow = false;
					}
				}
			}
		}
		HX_STACK_LINE(1093)
		if (((bool((bool(cascadeManager->hasTransform) || bool(cascadeManager->hasPosition))) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1095)
			this->isTransformed = false;
			HX_STACK_LINE(1096)
			this->hasCSSTransform = false;
			HX_STACK_LINE(1098)
			if (((this->isRelativePositioned == true))){
				HX_STACK_LINE(1099)
				this->isTransformed = true;
			}
			else{
				HX_STACK_LINE(1102)
				if (((this->isNone(this->getComputedOrInitialProperty((int)61)) == false))){
					HX_STACK_LINE(1104)
					this->isTransformed = true;
					HX_STACK_LINE(1105)
					this->hasCSSTransform = true;
				}
			}
		}
		HX_STACK_LINE(1109)
		if (((bool((cascadeManager->hasOpacity == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1111)
			this->isTransparent = false;
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1112);
					{
						HX_STACK_LINE(1112)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)53,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1112)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)53)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1112)
			{
				::cocktail::core::css::CSSPropertyValue _switch_56 = ((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
				switch((_switch_56)->GetIndex()){
					case 1: {
						Float value = _switch_56->__Param(0);
{
							HX_STACK_LINE(1114)
							this->isTransparent = (value != 1.0);
						}
					}
					;break;
					case 18: {
						Float value = _switch_56->__Param(0);
{
							HX_STACK_LINE(1117)
							this->isTransparent = (value != 1.0);
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(1124)
		if (((bool((cascadeManager->hasMarginTop == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1126);
					{
						HX_STACK_LINE(1126)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)8,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1126)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)8)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1125)
			this->hasAutoMarginTop = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1129)
		if (((bool((cascadeManager->hasMarginBottom == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1131);
					{
						HX_STACK_LINE(1131)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)9,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1131)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)9)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1130)
			this->hasAutoMarginBottom = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1134)
		if (((bool((cascadeManager->hasMarginLeft == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1136);
					{
						HX_STACK_LINE(1136)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)6,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1136)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)6)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1135)
			this->hasAutoMarginLeft = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1139)
		if (((bool((cascadeManager->hasMarginRight == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1141);
					{
						HX_STACK_LINE(1141)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)7,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1141)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)7)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1140)
			this->hasAutoMarginRight = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1146)
		if (((bool((cascadeManager->hasBackgroundImage == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1148)
			this->hasBackgroundImage = false;
			HX_STACK_LINE(1149)
			if (((this->isNone(this->getComputedOrInitialProperty((int)26)) == false))){
				HX_STACK_LINE(1151)
				this->hasBackgroundImage = true;
				HX_STACK_LINE(1153)
				{
					::cocktail::core::css::CSSPropertyValue _switch_57 = (this->getComputedOrInitialProperty((int)26));
					switch((_switch_57)->GetIndex()){
						case 5: {
							::String value = _switch_57->__Param(0);
{
								HX_STACK_LINE(1155)
								::cocktail::core::resource::ResourceManager_obj::getImageResource(value);
							}
						}
						;break;
						default: {
						}
					}
				}
			}
		}
		HX_STACK_LINE(1163)
		if (((bool((cascadeManager->hasVerticalAlign == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1165)
			this->isTopAligned = false;
			HX_STACK_LINE(1166)
			this->isBottomAligned = false;
			HX_STACK_LINE(1167)
			this->isBaselineAligned = false;
			HX_STACK_LINE(1169)
			{
				::cocktail::core::css::CSSPropertyValue _switch_58 = (this->getComputedOrInitialProperty((int)48));
				switch((_switch_58)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_58->__Param(0);
{
							HX_STACK_LINE(1171)
							{
								::cocktail::core::css::CSSKeywordValue _switch_59 = (value);
								switch((_switch_59)->GetIndex()){
									case 22: {
										HX_STACK_LINE(1174)
										this->isTopAligned = true;
									}
									;break;
									case 25: {
										HX_STACK_LINE(1177)
										this->isBottomAligned = true;
									}
									;break;
									case 19: {
										HX_STACK_LINE(1180)
										this->isBaselineAligned = true;
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
		HX_STACK_LINE(1190)
		if (((bool((cascadeManager->hasClear == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1191)
			this->canHaveClearance = (this->isNone(this->getComputedOrInitialProperty((int)3)) == false);
		}
		HX_STACK_LINE(1195)
		if (((bool((cascadeManager->hasWhiteSpace == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1197)
			this->hasPreLineWhiteSpace = false;
			HX_STACK_LINE(1198)
			this->hasPreWhiteSpace = false;
			HX_STACK_LINE(1199)
			this->hasNoWrapWhiteSpace = false;
			HX_STACK_LINE(1200)
			this->hasNormalWhiteSpace = false;
			HX_STACK_LINE(1201)
			this->hasPreWrapWhiteSpace = false;
			HX_STACK_LINE(1203)
			{
				::cocktail::core::css::CSSKeywordValue _switch_60 = (this->getKeyword(this->getComputedOrInitialProperty((int)45)));
				switch((_switch_60)->GetIndex()){
					case 7: {
						HX_STACK_LINE(1205)
						this->hasPreWhiteSpace = true;
					}
					;break;
					case 10: {
						HX_STACK_LINE(1208)
						this->hasPreLineWhiteSpace = true;
					}
					;break;
					case 9: {
						HX_STACK_LINE(1211)
						this->hasPreWrapWhiteSpace = true;
					}
					;break;
					case 8: {
						HX_STACK_LINE(1214)
						this->hasNoWrapWhiteSpace = true;
					}
					;break;
					case 0: {
						HX_STACK_LINE(1217)
						this->hasNormalWhiteSpace = true;
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(1224)
		if (((bool((cascadeManager->hasWidth == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1226);
					{
						HX_STACK_LINE(1226)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)15,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1226)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)15)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1225)
			this->hasAutoWidth = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1229)
		if (((bool((cascadeManager->hasHeight == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1231);
					{
						HX_STACK_LINE(1231)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)16,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1231)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)16)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1230)
			this->hasAutoHeight = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1234)
		if (((bool((cascadeManager->hasMaxHeight == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1236);
					{
						HX_STACK_LINE(1236)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)18,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1236)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)18)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1235)
			this->hasMaxHeight = (this->isNone((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)18)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)18)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) )) == false);
		}
		HX_STACK_LINE(1239)
		if (((bool((cascadeManager->hasMaxWidth == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1241);
					{
						HX_STACK_LINE(1241)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)20,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1241)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)20)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1240)
			this->hasMaxWidth = (this->isNone((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)20)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)20)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) )) == false);
		}
		HX_STACK_LINE(1244)
		if (((bool((cascadeManager->hasTextAlign == true)) || bool((isFirstCascade == true))))){
			HX_STACK_LINE(1246)
			this->isLeftAligned = false;
			HX_STACK_LINE(1247)
			{
				::cocktail::core::css::CSSKeywordValue _switch_61 = (this->getKeyword(this->getComputedOrInitialProperty((int)46)));
				switch((_switch_61)->GetIndex()){
					case 11: {
						HX_STACK_LINE(1249)
						this->isLeftAligned = true;
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(1256)
		if (((bool((cascadeManager->hasTop == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1258);
					{
						HX_STACK_LINE(1258)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)21,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1258)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)21)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1257)
			this->hasAutoTop = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1261)
		if (((bool((cascadeManager->hasBottom == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1263);
					{
						HX_STACK_LINE(1263)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)24,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1263)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)24)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1262)
			this->hasAutoBottom = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1266)
		if (((bool((cascadeManager->hasLeft == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1268);
					{
						HX_STACK_LINE(1268)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)22,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1268)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)22)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1267)
			this->hasAutoLeft = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
		HX_STACK_LINE(1271)
		if (((bool((cascadeManager->hasRight == true)) || bool((isFirstCascade == true))))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",1273);
					{
						HX_STACK_LINE(1273)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)23,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(1273)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)23)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(1272)
			this->hasAutoRight = this->isAuto((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(CoreStyle_obj,updateCoreStyleAttribute,(void))

Void CoreStyle_obj::cascade( ::cocktail::core::css::CascadeManager cascadeManager,::cocktail::core::css::InitialStyleDeclaration initialStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration styleSheetDeclaration,::cocktail::core::css::CSSStyleDeclaration inlineStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration,Float parentFontSize,Float parentXHeight,bool programmaticChange){
{
		HX_STACK_PUSH("CoreStyle::cascade","cocktail/core/css/CoreStyle.hx",655);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cascadeManager,"cascadeManager");
		HX_STACK_ARG(initialStyleDeclaration,"initialStyleDeclaration");
		HX_STACK_ARG(styleSheetDeclaration,"styleSheetDeclaration");
		HX_STACK_ARG(inlineStyleDeclaration,"inlineStyleDeclaration");
		HX_STACK_ARG(parentStyleDeclaration,"parentStyleDeclaration");
		HX_STACK_ARG(parentFontSize,"parentFontSize");
		HX_STACK_ARG(parentXHeight,"parentXHeight");
		HX_STACK_ARG(programmaticChange,"programmaticChange");
		HX_STACK_LINE(658)
		if (((cascadeManager->hasPropertiesToCascade == false))){
			HX_STACK_LINE(659)
			return null();
		}
		HX_STACK_LINE(665)
		this->_changedProperties = ::cocktail::core::utils::Utils_obj::clear(this->_changedProperties);
		HX_STACK_LINE(668)
		bool hasInlineStyle = (inlineStyleDeclaration->length > (int)0);		HX_STACK_VAR(hasInlineStyle,"hasInlineStyle");
		HX_STACK_LINE(669)
		bool hasStyleSheetStyle = (styleSheetDeclaration->length > (int)0);		HX_STACK_VAR(hasStyleSheetStyle,"hasStyleSheetStyle");
		struct _Function_1_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &parentStyleDeclaration){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",673);
				{
					HX_STACK_LINE(673)
					if (((parentStyleDeclaration->_indexedProperties == null()))){
						HX_STACK_LINE(673)
						parentStyleDeclaration->resetIndexedProperties();
						HX_STACK_LINE(673)
						parentStyleDeclaration->resetPropertiesPositions();
					}
					HX_STACK_LINE(673)
					return parentStyleDeclaration->_indexedProperties->__get((int)40);
				}
				return null();
			}
		};
		HX_STACK_LINE(673)
		::cocktail::core::css::CSSColorValue parentColor = this->getColor((_Function_1_1::Block(parentStyleDeclaration))->typedValue);		HX_STACK_VAR(parentColor,"parentColor");
		HX_STACK_LINE(678)
		if (((bool((cascadeManager->hasTransitionProperty == true)) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(680)
			this->cascadeProperty((int)57,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);
			HX_STACK_LINE(685)
			this->hasTransitionnableProperties = (this->isNone(this->getComputedOrInitialProperty((int)57)) == false);
			HX_STACK_LINE(688)
			cascadeManager->removePropertyToCascade((int)57);
		}
		HX_STACK_LINE(694)
		if (((bool((cascadeManager->hasLeftBorderStyle == true)) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(696)
			bool leftBorderStyleDidChange = this->cascadeProperty((int)75,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(leftBorderStyleDidChange,"leftBorderStyleDidChange");
			HX_STACK_LINE(697)
			if (((leftBorderStyleDidChange == true))){
				HX_STACK_LINE(699)
				this->_changedProperties->push((int)65);
				HX_STACK_LINE(700)
				cascadeManager->addPropertyToCascade((int)65);
			}
			HX_STACK_LINE(703)
			cascadeManager->removePropertyToCascade((int)75);
		}
		HX_STACK_LINE(707)
		if (((bool((cascadeManager->hasRightBorderStyle == true)) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(709)
			bool rightBorderStyleDidChange = this->cascadeProperty((int)73,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(rightBorderStyleDidChange,"rightBorderStyleDidChange");
			HX_STACK_LINE(710)
			if (((rightBorderStyleDidChange == true))){
				HX_STACK_LINE(712)
				this->_changedProperties->push((int)63);
				HX_STACK_LINE(713)
				cascadeManager->addPropertyToCascade((int)63);
			}
			HX_STACK_LINE(716)
			cascadeManager->removePropertyToCascade((int)73);
		}
		HX_STACK_LINE(720)
		if (((bool((cascadeManager->hasTopBorderStyle == true)) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(722)
			bool topBorderStyleDidChange = this->cascadeProperty((int)72,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(topBorderStyleDidChange,"topBorderStyleDidChange");
			HX_STACK_LINE(723)
			if (((topBorderStyleDidChange == true))){
				HX_STACK_LINE(725)
				this->_changedProperties->push((int)62);
				HX_STACK_LINE(726)
				cascadeManager->addPropertyToCascade((int)62);
			}
			HX_STACK_LINE(729)
			cascadeManager->removePropertyToCascade((int)72);
		}
		HX_STACK_LINE(733)
		if (((bool((cascadeManager->hasBottomBorderStyle == true)) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(735)
			bool bottomBorderStyleDidChange = this->cascadeProperty((int)74,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(bottomBorderStyleDidChange,"bottomBorderStyleDidChange");
			HX_STACK_LINE(736)
			if (((bottomBorderStyleDidChange == true))){
				HX_STACK_LINE(738)
				this->_changedProperties->push((int)64);
				HX_STACK_LINE(739)
				cascadeManager->addPropertyToCascade((int)64);
			}
			HX_STACK_LINE(742)
			cascadeManager->removePropertyToCascade((int)74);
		}
		HX_STACK_LINE(747)
		if (((bool((cascadeManager->hasOutlineStyle == true)) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(749)
			bool outlineStyleDidChange = this->cascadeProperty((int)83,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(outlineStyleDidChange,"outlineStyleDidChange");
			HX_STACK_LINE(750)
			if (((outlineStyleDidChange == true))){
				HX_STACK_LINE(752)
				this->_changedProperties->push((int)82);
				HX_STACK_LINE(753)
				cascadeManager->addPropertyToCascade((int)82);
			}
			HX_STACK_LINE(756)
			cascadeManager->removePropertyToCascade((int)83);
		}
		HX_STACK_LINE(759)
		if (((bool((bool((cascadeManager->hasFontSize == true)) || bool((cascadeManager->hasFontFamily == true)))) || bool((cascadeManager->cascadeAll == true))))){
			HX_STACK_LINE(768)
			bool fontSizeDidChange = this->cascadeProperty((int)34,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(fontSizeDidChange,"fontSizeDidChange");
			HX_STACK_LINE(769)
			bool fontFamilyDidChange = this->cascadeProperty((int)37,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(fontFamilyDidChange,"fontFamilyDidChange");
			HX_STACK_LINE(773)
			if (((bool((fontSizeDidChange == true)) || bool((fontFamilyDidChange == true))))){
				HX_STACK_LINE(775)
				Array< int > lengthCSSProperties = initialStyleDeclaration->lengthCSSProperties;		HX_STACK_VAR(lengthCSSProperties,"lengthCSSProperties");
				HX_STACK_LINE(776)
				int length = lengthCSSProperties->length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(777)
				{
					HX_STACK_LINE(777)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(777)
					while(((_g < length))){
						HX_STACK_LINE(777)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(779)
						cascadeManager->addPropertyToCascade(lengthCSSProperties->__get(i));
					}
				}
				HX_STACK_LINE(783)
				if (((this->computedValues->get_fontFamily() != null()))){
					struct _Function_4_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
							HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",785);
							{
								HX_STACK_LINE(785)
								::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)34,__this);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(785)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)34)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(784)
					this->fontMetrics = this->_fontManager->getFontMetrics(this->computedValues->get_fontFamily(),this->getAbsoluteLength((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(this)) )) )));
				}
				else{
					struct _Function_4_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
							HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",789);
							{
								HX_STACK_LINE(789)
								::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)34,__this);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(789)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)34)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(788)
					this->fontMetrics = this->_fontManager->getFontMetrics(initialStyleDeclaration->initialComputedStyleDeclaration->get_fontFamily(),this->getAbsoluteLength((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(this)) )) )));
				}
			}
			HX_STACK_LINE(794)
			cascadeManager->removePropertyToCascade((int)34);
			HX_STACK_LINE(795)
			cascadeManager->removePropertyToCascade((int)37);
		}
		HX_STACK_LINE(802)
		if (((cascadeManager->hasColor == true))){
			HX_STACK_LINE(804)
			bool colorDidChange = this->cascadeProperty((int)40,initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,(int)0,(int)0,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(colorDidChange,"colorDidChange");
			HX_STACK_LINE(808)
			if (((colorDidChange == true))){
				HX_STACK_LINE(812)
				this->_changedProperties->push((int)40);
				HX_STACK_LINE(814)
				Array< int > colorCSSProperties = initialStyleDeclaration->colorCSSProperties;		HX_STACK_VAR(colorCSSProperties,"colorCSSProperties");
				HX_STACK_LINE(815)
				int length = colorCSSProperties->length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(816)
				{
					HX_STACK_LINE(816)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(816)
					while(((_g < length))){
						HX_STACK_LINE(816)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(818)
						cascadeManager->addPropertyToCascade(colorCSSProperties->__get(i));
					}
				}
			}
			HX_STACK_LINE(823)
			cascadeManager->removePropertyToCascade((int)40);
		}
		HX_STACK_LINE(826)
		Float fontSize = this->fontMetrics->fontSize;		HX_STACK_VAR(fontSize,"fontSize");
		HX_STACK_LINE(827)
		Float xHeight = this->fontMetrics->xHeight;		HX_STACK_VAR(xHeight,"xHeight");
		HX_STACK_LINE(830)
		Array< int > propertiesToCascade = null();		HX_STACK_VAR(propertiesToCascade,"propertiesToCascade");
		HX_STACK_LINE(834)
		if (((cascadeManager->cascadeAll == true))){
			HX_STACK_LINE(835)
			propertiesToCascade = initialStyleDeclaration->supportedCSSProperties;
		}
		else{
			HX_STACK_LINE(841)
			propertiesToCascade = Array_obj< int >::__new();
			HX_STACK_LINE(843)
			Array< bool > flaggedProperties = cascadeManager->propertiesToCascade;		HX_STACK_VAR(flaggedProperties,"flaggedProperties");
			HX_STACK_LINE(844)
			int flaggedPropertiesLength = flaggedProperties->length;		HX_STACK_VAR(flaggedPropertiesLength,"flaggedPropertiesLength");
			HX_STACK_LINE(845)
			{
				HX_STACK_LINE(845)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(845)
				while(((_g < flaggedPropertiesLength))){
					HX_STACK_LINE(845)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(847)
					if (((flaggedProperties->__get(i) == true))){
						HX_STACK_LINE(848)
						propertiesToCascade->push(i);
					}
				}
			}
		}
		HX_STACK_LINE(854)
		int length = propertiesToCascade->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(855)
		{
			HX_STACK_LINE(855)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(855)
			while(((_g < length))){
				HX_STACK_LINE(855)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(860)
				bool didChangeSpecifiedValue = this->cascadeProperty(propertiesToCascade->__get(i),initialStyleDeclaration,styleSheetDeclaration,inlineStyleDeclaration,parentStyleDeclaration,parentColor,parentFontSize,parentXHeight,fontSize,xHeight,programmaticChange,hasInlineStyle,hasStyleSheetStyle);		HX_STACK_VAR(didChangeSpecifiedValue,"didChangeSpecifiedValue");
				HX_STACK_LINE(862)
				if (((didChangeSpecifiedValue == true))){
					HX_STACK_LINE(863)
					this->_changedProperties->push(propertiesToCascade->__get(i));
				}
			}
		}
		HX_STACK_LINE(870)
		cascadeManager->reset();
		HX_STACK_LINE(876)
		int length1 = this->_changedProperties->length;		HX_STACK_VAR(length1,"length1");
		HX_STACK_LINE(877)
		{
			HX_STACK_LINE(877)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(877)
			while(((_g < length1))){
				HX_STACK_LINE(877)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(879)
				cascadeManager->addPropertyToCascade(this->_changedProperties->__get(i));
			}
		}
		HX_STACK_LINE(884)
		this->applyPositionFloatAndDisplayRelationship();
		HX_STACK_LINE(888)
		this->applyHiddenBordersWidth();
		HX_STACK_LINE(891)
		this->applyNoneOutlineWidth();
		HX_STACK_LINE(896)
		if (((cascadeManager->hasBackgroundColor == true))){
			HX_STACK_LINE(898)
			::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(this->getColor(this->getComputedOrInitialProperty((int)25)),this->usedValues->backgroundColor);
			HX_STACK_LINE(902)
			this->hasBackgroundColor = (this->usedValues->backgroundColor->alpha != 0.0);
		}
		HX_STACK_LINE(905)
		if (((cascadeManager->hasColor == true))){
			HX_STACK_LINE(906)
			::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(this->getColor(this->getComputedOrInitialProperty((int)40)),this->usedValues->color);
		}
		HX_STACK_LINE(911)
		if (((cascadeManager->hasLeftBorderColor == true))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",913);
					{
						HX_STACK_LINE(913)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)70,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(913)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)70)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(912)
			::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(this->getColor((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)70)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)70)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) )),this->usedValues->borderLeftColor);
		}
		HX_STACK_LINE(916)
		if (((cascadeManager->hasTopBorderColor == true))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",918);
					{
						HX_STACK_LINE(918)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)67,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(918)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)67)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(917)
			::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(this->getColor((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)67)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)67)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) )),this->usedValues->borderTopColor);
		}
		HX_STACK_LINE(921)
		if (((cascadeManager->hasRightBorderColor == true))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",923);
					{
						HX_STACK_LINE(923)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)68,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(923)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)68)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(922)
			::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(this->getColor((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)68)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)68)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) )),this->usedValues->borderRightColor);
		}
		HX_STACK_LINE(926)
		if (((cascadeManager->hasBottomBorderColor == true))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",928);
					{
						HX_STACK_LINE(928)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)69,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(928)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)69)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(927)
			::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(this->getColor((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)69)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)69)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) )),this->usedValues->borderBottomColor);
		}
		HX_STACK_LINE(932)
		if (((cascadeManager->hasOutlineColor == true))){
			HX_STACK_LINE(933)
			{
				::cocktail::core::css::CSSPropertyValue _switch_62 = (this->getComputedOrInitialProperty((int)84));
				switch((_switch_62)->GetIndex()){
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_62->__Param(0);
{
							HX_STACK_LINE(936)
							::cocktail::core::css::CSSValueConverter_obj::getColorVOFromCSSColor(value,this->usedValues->outlineColor);
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		struct _Function_1_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",950);
				{
					HX_STACK_LINE(950)
					::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)41,__this);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(950)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)41)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(950)
		{
			::cocktail::core::css::CSSPropertyValue _switch_63 = ((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)41)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)41)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(this)) )) ));
			switch((_switch_63)->GetIndex()){
				case 18: {
					Float value = _switch_63->__Param(0);
{
						HX_STACK_LINE(952)
						this->usedValues->lineHeight = value;
					}
				}
				;break;
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_63->__Param(0);
{
						HX_STACK_LINE(955)
						this->usedValues->lineHeight = (fontSize * 1.2);
					}
				}
				;break;
				case 1: {
					Float value = _switch_63->__Param(0);
{
						HX_STACK_LINE(958)
						this->usedValues->lineHeight = (fontSize * value);
					}
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(966)
		if (((cascadeManager->hasLetterSpacing == true))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle_obj *__this){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CoreStyle.hx",968);
					{
						HX_STACK_LINE(968)
						::cocktail::core::animation::Transition transition = __this->_transitionManager->getTransition((int)43,__this);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(968)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(__this->getComputedOrInitialProperty((int)43)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(967)
			{
				::cocktail::core::css::CSSPropertyValue _switch_64 = ((  (((this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)43)) : ::cocktail::core::css::CSSPropertyValue((  (((this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(this->getComputedOrInitialProperty((int)43)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(this)) )) ));
				switch((_switch_64)->GetIndex()){
					case 18: {
						Float value = _switch_64->__Param(0);
{
							HX_STACK_LINE(970)
							this->usedValues->letterSpacing = value;
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_64->__Param(0);
{
							HX_STACK_LINE(973)
							this->usedValues->letterSpacing = 0.0;
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		HX_STACK_LINE(981)
		this->updateCoreStyleAttribute(cascadeManager,this->_isFirstCascade);
		HX_STACK_LINE(985)
		if (((this->_isFirstCascade == true))){
			HX_STACK_LINE(986)
			this->_isFirstCascade = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(CoreStyle_obj,cascade,(void))

Void CoreStyle_obj::initAnimator( ){
{
		HX_STACK_PUSH("CoreStyle::initAnimator","cocktail/core/css/CoreStyle.hx",622);
		HX_STACK_THIS(this);
		HX_STACK_LINE(623)
		this->_animator = ::cocktail::core::animation::Animator_obj::__new();
		HX_STACK_LINE(624)
		this->_animator->onTransitionCompleteCallback = this->onTransitionComplete_dyn();
		HX_STACK_LINE(625)
		this->_animator->onTransitionUpdateCallback = this->onTransitionUpdate_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,initAnimator,(void))

Void CoreStyle_obj::initPendingComputedValues( ){
{
		HX_STACK_PUSH("CoreStyle::initPendingComputedValues","cocktail/core/css/CoreStyle.hx",608);
		HX_STACK_THIS(this);
		HX_STACK_LINE(609)
		this->_pendingComputedValues = Array_obj< ::cocktail::core::css::TypedPropertyVO >::__new();
		HX_STACK_LINE(610)
		{
			HX_STACK_LINE(610)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(610)
			while(((_g < (int)87))){
				HX_STACK_LINE(610)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(612)
				this->_pendingComputedValues[i] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,initPendingComputedValues,(void))

Void CoreStyle_obj::init( ){
{
		HX_STACK_PUSH("CoreStyle::init","cocktail/core/css/CoreStyle.hx",587);
		HX_STACK_THIS(this);
		HX_STACK_LINE(588)
		this->computedValues = ::cocktail::core::css::CSSStyleDeclaration_obj::__new(null(),null());
		HX_STACK_LINE(589)
		this->specifiedValues = ::cocktail::core::css::CSSStyleDeclaration_obj::__new(null(),null());
		HX_STACK_LINE(591)
		this->_changedProperties = Array_obj< int >::__new();
		HX_STACK_LINE(593)
		this->_fontManager = ::cocktail::core::font::FontManager_obj::getInstance();
		HX_STACK_LINE(595)
		this->fontMetrics = this->_fontManager->getFontMetrics(::cocktail::core::config::Config_obj::getInstance()->defaultFont,::cocktail::core::config::Config_obj::getInstance()->mediumFontSize);
		HX_STACK_LINE(597)
		this->_transitionManager = ::cocktail::core::animation::TransitionManager_obj::getInstance();
		HX_STACK_LINE(599)
		this->usedValues = ::cocktail::core::css::UsedValuesVO_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,init,(void))


CoreStyle_obj::CoreStyle_obj()
{
}

void CoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CoreStyle);
	HX_MARK_MEMBER_NAME(hasTransitionnableProperties,"hasTransitionnableProperties");
	HX_MARK_MEMBER_NAME(hasAutoMarginBottom,"hasAutoMarginBottom");
	HX_MARK_MEMBER_NAME(hasAutoMarginTop,"hasAutoMarginTop");
	HX_MARK_MEMBER_NAME(hasAutoMarginRight,"hasAutoMarginRight");
	HX_MARK_MEMBER_NAME(hasAutoMarginLeft,"hasAutoMarginLeft");
	HX_MARK_MEMBER_NAME(hasAutoRight,"hasAutoRight");
	HX_MARK_MEMBER_NAME(hasAutoLeft,"hasAutoLeft");
	HX_MARK_MEMBER_NAME(hasAutoBottom,"hasAutoBottom");
	HX_MARK_MEMBER_NAME(hasAutoTop,"hasAutoTop");
	HX_MARK_MEMBER_NAME(isLeftAligned,"isLeftAligned");
	HX_MARK_MEMBER_NAME(hasMaxHeight,"hasMaxHeight");
	HX_MARK_MEMBER_NAME(hasMaxWidth,"hasMaxWidth");
	HX_MARK_MEMBER_NAME(hasAutoHeight,"hasAutoHeight");
	HX_MARK_MEMBER_NAME(hasAutoWidth,"hasAutoWidth");
	HX_MARK_MEMBER_NAME(hasNormalWhiteSpace,"hasNormalWhiteSpace");
	HX_MARK_MEMBER_NAME(hasPreWrapWhiteSpace,"hasPreWrapWhiteSpace");
	HX_MARK_MEMBER_NAME(hasPreLineWhiteSpace,"hasPreLineWhiteSpace");
	HX_MARK_MEMBER_NAME(hasNoWrapWhiteSpace,"hasNoWrapWhiteSpace");
	HX_MARK_MEMBER_NAME(hasPreWhiteSpace,"hasPreWhiteSpace");
	HX_MARK_MEMBER_NAME(canHaveClearance,"canHaveClearance");
	HX_MARK_MEMBER_NAME(isBaselineAligned,"isBaselineAligned");
	HX_MARK_MEMBER_NAME(isBottomAligned,"isBottomAligned");
	HX_MARK_MEMBER_NAME(isTopAligned,"isTopAligned");
	HX_MARK_MEMBER_NAME(hasBackgroundColor,"hasBackgroundColor");
	HX_MARK_MEMBER_NAME(hasBackgroundImage,"hasBackgroundImage");
	HX_MARK_MEMBER_NAME(isTransparent,"isTransparent");
	HX_MARK_MEMBER_NAME(hasCSSTransform,"hasCSSTransform");
	HX_MARK_MEMBER_NAME(isTransformed,"isTransformed");
	HX_MARK_MEMBER_NAME(hasHiddenOrScrollOverflowY,"hasHiddenOrScrollOverflowY");
	HX_MARK_MEMBER_NAME(hasHiddenOrScrollOverflowX,"hasHiddenOrScrollOverflowX");
	HX_MARK_MEMBER_NAME(canAlwaysOverflow,"canAlwaysOverflow");
	HX_MARK_MEMBER_NAME(isAbsolutelyPositioned,"isAbsolutelyPositioned");
	HX_MARK_MEMBER_NAME(isFixedPositioned,"isFixedPositioned");
	HX_MARK_MEMBER_NAME(isRelativePositioned,"isRelativePositioned");
	HX_MARK_MEMBER_NAME(isPositioned,"isPositioned");
	HX_MARK_MEMBER_NAME(isVisible,"isVisible");
	HX_MARK_MEMBER_NAME(isBlock,"isBlock");
	HX_MARK_MEMBER_NAME(isInline,"isInline");
	HX_MARK_MEMBER_NAME(isInlineBlock,"isInlineBlock");
	HX_MARK_MEMBER_NAME(isInlineLevel,"isInlineLevel");
	HX_MARK_MEMBER_NAME(isFloat,"isFloat");
	HX_MARK_MEMBER_NAME(_initialComputedStyleDeclaration,"_initialComputedStyleDeclaration");
	HX_MARK_MEMBER_NAME(_initialStyleDeclaration,"_initialStyleDeclaration");
	HX_MARK_MEMBER_NAME(htmlElement,"htmlElement");
	HX_MARK_MEMBER_NAME(_isFirstCascade,"_isFirstCascade");
	HX_MARK_MEMBER_NAME(_changedProperties,"_changedProperties");
	HX_MARK_MEMBER_NAME(_fontManager,"_fontManager");
	HX_MARK_MEMBER_NAME(fontMetrics,"fontMetrics");
	HX_MARK_MEMBER_NAME(_pendingComputedValues,"_pendingComputedValues");
	HX_MARK_MEMBER_NAME(_pendingTransitionEndEvents,"_pendingTransitionEndEvents");
	HX_MARK_MEMBER_NAME(_transitionManager,"_transitionManager");
	HX_MARK_MEMBER_NAME(_animator,"_animator");
	HX_MARK_MEMBER_NAME(usedValues,"usedValues");
	HX_MARK_MEMBER_NAME(computedValues,"computedValues");
	HX_MARK_MEMBER_NAME(specifiedValues,"specifiedValues");
	HX_MARK_MEMBER_NAME(transitionTimingFunction,"transitionTimingFunction");
	HX_MARK_MEMBER_NAME(transitionDelay,"transitionDelay");
	HX_MARK_MEMBER_NAME(transitionDuration,"transitionDuration");
	HX_MARK_MEMBER_NAME(transitionProperty,"transitionProperty");
	HX_MARK_MEMBER_NAME(outlineStyle,"outlineStyle");
	HX_MARK_MEMBER_NAME(outlineColor,"outlineColor");
	HX_MARK_MEMBER_NAME(outlineWidth,"outlineWidth");
	HX_MARK_MEMBER_NAME(cursor,"cursor");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_MARK_MEMBER_NAME(overflowY,"overflowY");
	HX_MARK_MEMBER_NAME(overflowX,"overflowX");
	HX_MARK_MEMBER_NAME(visibility,"visibility");
	HX_MARK_MEMBER_NAME(opacity,"opacity");
	HX_MARK_MEMBER_NAME(textDecoration,"textDecoration");
	HX_MARK_MEMBER_NAME(verticalAlign,"verticalAlign");
	HX_MARK_MEMBER_NAME(textIndent,"textIndent");
	HX_MARK_MEMBER_NAME(textAlign,"textAlign");
	HX_MARK_MEMBER_NAME(whiteSpace,"whiteSpace");
	HX_MARK_MEMBER_NAME(wordSpacing,"wordSpacing");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(textTransform,"textTransform");
	HX_MARK_MEMBER_NAME(lineHeight,"lineHeight");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(fontVariant,"fontVariant");
	HX_MARK_MEMBER_NAME(fontFamily,"fontFamily");
	HX_MARK_MEMBER_NAME(fontStyle,"fontStyle");
	HX_MARK_MEMBER_NAME(fontWeight,"fontWeight");
	HX_MARK_MEMBER_NAME(fontSize,"fontSize");
	HX_MARK_MEMBER_NAME(borderLeftStyle,"borderLeftStyle");
	HX_MARK_MEMBER_NAME(borderBottomStyle,"borderBottomStyle");
	HX_MARK_MEMBER_NAME(borderRightStyle,"borderRightStyle");
	HX_MARK_MEMBER_NAME(borderTopStyle,"borderTopStyle");
	HX_MARK_MEMBER_NAME(borderLeftColor,"borderLeftColor");
	HX_MARK_MEMBER_NAME(borderBottomColor,"borderBottomColor");
	HX_MARK_MEMBER_NAME(borderRightColor,"borderRightColor");
	HX_MARK_MEMBER_NAME(borderTopColor,"borderTopColor");
	HX_MARK_MEMBER_NAME(borderLeftWidth,"borderLeftWidth");
	HX_MARK_MEMBER_NAME(borderBottomWidth,"borderBottomWidth");
	HX_MARK_MEMBER_NAME(borderRightWidth,"borderRightWidth");
	HX_MARK_MEMBER_NAME(borderTopWidth,"borderTopWidth");
	HX_MARK_MEMBER_NAME(backgroundAttachment,"backgroundAttachment");
	HX_MARK_MEMBER_NAME(backgroundClip,"backgroundClip");
	HX_MARK_MEMBER_NAME(backgroundPosition,"backgroundPosition");
	HX_MARK_MEMBER_NAME(backgroundSize,"backgroundSize");
	HX_MARK_MEMBER_NAME(backgroundOrigin,"backgroundOrigin");
	HX_MARK_MEMBER_NAME(backgroundRepeat,"backgroundRepeat");
	HX_MARK_MEMBER_NAME(backgroundImage,"backgroundImage");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(minWidth,"minWidth");
	HX_MARK_MEMBER_NAME(maxHeight,"maxHeight");
	HX_MARK_MEMBER_NAME(minHeight,"minHeight");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_MARK_MEMBER_NAME(paddingTop,"paddingTop");
	HX_MARK_MEMBER_NAME(paddingRight,"paddingRight");
	HX_MARK_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_MARK_MEMBER_NAME(marginBottom,"marginBottom");
	HX_MARK_MEMBER_NAME(marginTop,"marginTop");
	HX_MARK_MEMBER_NAME(marginRight,"marginRight");
	HX_MARK_MEMBER_NAME(marginLeft,"marginLeft");
	HX_MARK_MEMBER_NAME(zIndex,"zIndex");
	HX_MARK_MEMBER_NAME(clear,"clear");
	HX_MARK_MEMBER_NAME(cssFloat,"cssFloat");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_END_CLASS();
}

void CoreStyle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hasTransitionnableProperties,"hasTransitionnableProperties");
	HX_VISIT_MEMBER_NAME(hasAutoMarginBottom,"hasAutoMarginBottom");
	HX_VISIT_MEMBER_NAME(hasAutoMarginTop,"hasAutoMarginTop");
	HX_VISIT_MEMBER_NAME(hasAutoMarginRight,"hasAutoMarginRight");
	HX_VISIT_MEMBER_NAME(hasAutoMarginLeft,"hasAutoMarginLeft");
	HX_VISIT_MEMBER_NAME(hasAutoRight,"hasAutoRight");
	HX_VISIT_MEMBER_NAME(hasAutoLeft,"hasAutoLeft");
	HX_VISIT_MEMBER_NAME(hasAutoBottom,"hasAutoBottom");
	HX_VISIT_MEMBER_NAME(hasAutoTop,"hasAutoTop");
	HX_VISIT_MEMBER_NAME(isLeftAligned,"isLeftAligned");
	HX_VISIT_MEMBER_NAME(hasMaxHeight,"hasMaxHeight");
	HX_VISIT_MEMBER_NAME(hasMaxWidth,"hasMaxWidth");
	HX_VISIT_MEMBER_NAME(hasAutoHeight,"hasAutoHeight");
	HX_VISIT_MEMBER_NAME(hasAutoWidth,"hasAutoWidth");
	HX_VISIT_MEMBER_NAME(hasNormalWhiteSpace,"hasNormalWhiteSpace");
	HX_VISIT_MEMBER_NAME(hasPreWrapWhiteSpace,"hasPreWrapWhiteSpace");
	HX_VISIT_MEMBER_NAME(hasPreLineWhiteSpace,"hasPreLineWhiteSpace");
	HX_VISIT_MEMBER_NAME(hasNoWrapWhiteSpace,"hasNoWrapWhiteSpace");
	HX_VISIT_MEMBER_NAME(hasPreWhiteSpace,"hasPreWhiteSpace");
	HX_VISIT_MEMBER_NAME(canHaveClearance,"canHaveClearance");
	HX_VISIT_MEMBER_NAME(isBaselineAligned,"isBaselineAligned");
	HX_VISIT_MEMBER_NAME(isBottomAligned,"isBottomAligned");
	HX_VISIT_MEMBER_NAME(isTopAligned,"isTopAligned");
	HX_VISIT_MEMBER_NAME(hasBackgroundColor,"hasBackgroundColor");
	HX_VISIT_MEMBER_NAME(hasBackgroundImage,"hasBackgroundImage");
	HX_VISIT_MEMBER_NAME(isTransparent,"isTransparent");
	HX_VISIT_MEMBER_NAME(hasCSSTransform,"hasCSSTransform");
	HX_VISIT_MEMBER_NAME(isTransformed,"isTransformed");
	HX_VISIT_MEMBER_NAME(hasHiddenOrScrollOverflowY,"hasHiddenOrScrollOverflowY");
	HX_VISIT_MEMBER_NAME(hasHiddenOrScrollOverflowX,"hasHiddenOrScrollOverflowX");
	HX_VISIT_MEMBER_NAME(canAlwaysOverflow,"canAlwaysOverflow");
	HX_VISIT_MEMBER_NAME(isAbsolutelyPositioned,"isAbsolutelyPositioned");
	HX_VISIT_MEMBER_NAME(isFixedPositioned,"isFixedPositioned");
	HX_VISIT_MEMBER_NAME(isRelativePositioned,"isRelativePositioned");
	HX_VISIT_MEMBER_NAME(isPositioned,"isPositioned");
	HX_VISIT_MEMBER_NAME(isVisible,"isVisible");
	HX_VISIT_MEMBER_NAME(isBlock,"isBlock");
	HX_VISIT_MEMBER_NAME(isInline,"isInline");
	HX_VISIT_MEMBER_NAME(isInlineBlock,"isInlineBlock");
	HX_VISIT_MEMBER_NAME(isInlineLevel,"isInlineLevel");
	HX_VISIT_MEMBER_NAME(isFloat,"isFloat");
	HX_VISIT_MEMBER_NAME(_initialComputedStyleDeclaration,"_initialComputedStyleDeclaration");
	HX_VISIT_MEMBER_NAME(_initialStyleDeclaration,"_initialStyleDeclaration");
	HX_VISIT_MEMBER_NAME(htmlElement,"htmlElement");
	HX_VISIT_MEMBER_NAME(_isFirstCascade,"_isFirstCascade");
	HX_VISIT_MEMBER_NAME(_changedProperties,"_changedProperties");
	HX_VISIT_MEMBER_NAME(_fontManager,"_fontManager");
	HX_VISIT_MEMBER_NAME(fontMetrics,"fontMetrics");
	HX_VISIT_MEMBER_NAME(_pendingComputedValues,"_pendingComputedValues");
	HX_VISIT_MEMBER_NAME(_pendingTransitionEndEvents,"_pendingTransitionEndEvents");
	HX_VISIT_MEMBER_NAME(_transitionManager,"_transitionManager");
	HX_VISIT_MEMBER_NAME(_animator,"_animator");
	HX_VISIT_MEMBER_NAME(usedValues,"usedValues");
	HX_VISIT_MEMBER_NAME(computedValues,"computedValues");
	HX_VISIT_MEMBER_NAME(specifiedValues,"specifiedValues");
	HX_VISIT_MEMBER_NAME(transitionTimingFunction,"transitionTimingFunction");
	HX_VISIT_MEMBER_NAME(transitionDelay,"transitionDelay");
	HX_VISIT_MEMBER_NAME(transitionDuration,"transitionDuration");
	HX_VISIT_MEMBER_NAME(transitionProperty,"transitionProperty");
	HX_VISIT_MEMBER_NAME(outlineStyle,"outlineStyle");
	HX_VISIT_MEMBER_NAME(outlineColor,"outlineColor");
	HX_VISIT_MEMBER_NAME(outlineWidth,"outlineWidth");
	HX_VISIT_MEMBER_NAME(cursor,"cursor");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_VISIT_MEMBER_NAME(overflowY,"overflowY");
	HX_VISIT_MEMBER_NAME(overflowX,"overflowX");
	HX_VISIT_MEMBER_NAME(visibility,"visibility");
	HX_VISIT_MEMBER_NAME(opacity,"opacity");
	HX_VISIT_MEMBER_NAME(textDecoration,"textDecoration");
	HX_VISIT_MEMBER_NAME(verticalAlign,"verticalAlign");
	HX_VISIT_MEMBER_NAME(textIndent,"textIndent");
	HX_VISIT_MEMBER_NAME(textAlign,"textAlign");
	HX_VISIT_MEMBER_NAME(whiteSpace,"whiteSpace");
	HX_VISIT_MEMBER_NAME(wordSpacing,"wordSpacing");
	HX_VISIT_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_VISIT_MEMBER_NAME(textTransform,"textTransform");
	HX_VISIT_MEMBER_NAME(lineHeight,"lineHeight");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(fontVariant,"fontVariant");
	HX_VISIT_MEMBER_NAME(fontFamily,"fontFamily");
	HX_VISIT_MEMBER_NAME(fontStyle,"fontStyle");
	HX_VISIT_MEMBER_NAME(fontWeight,"fontWeight");
	HX_VISIT_MEMBER_NAME(fontSize,"fontSize");
	HX_VISIT_MEMBER_NAME(borderLeftStyle,"borderLeftStyle");
	HX_VISIT_MEMBER_NAME(borderBottomStyle,"borderBottomStyle");
	HX_VISIT_MEMBER_NAME(borderRightStyle,"borderRightStyle");
	HX_VISIT_MEMBER_NAME(borderTopStyle,"borderTopStyle");
	HX_VISIT_MEMBER_NAME(borderLeftColor,"borderLeftColor");
	HX_VISIT_MEMBER_NAME(borderBottomColor,"borderBottomColor");
	HX_VISIT_MEMBER_NAME(borderRightColor,"borderRightColor");
	HX_VISIT_MEMBER_NAME(borderTopColor,"borderTopColor");
	HX_VISIT_MEMBER_NAME(borderLeftWidth,"borderLeftWidth");
	HX_VISIT_MEMBER_NAME(borderBottomWidth,"borderBottomWidth");
	HX_VISIT_MEMBER_NAME(borderRightWidth,"borderRightWidth");
	HX_VISIT_MEMBER_NAME(borderTopWidth,"borderTopWidth");
	HX_VISIT_MEMBER_NAME(backgroundAttachment,"backgroundAttachment");
	HX_VISIT_MEMBER_NAME(backgroundClip,"backgroundClip");
	HX_VISIT_MEMBER_NAME(backgroundPosition,"backgroundPosition");
	HX_VISIT_MEMBER_NAME(backgroundSize,"backgroundSize");
	HX_VISIT_MEMBER_NAME(backgroundOrigin,"backgroundOrigin");
	HX_VISIT_MEMBER_NAME(backgroundRepeat,"backgroundRepeat");
	HX_VISIT_MEMBER_NAME(backgroundImage,"backgroundImage");
	HX_VISIT_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_VISIT_MEMBER_NAME(right,"right");
	HX_VISIT_MEMBER_NAME(bottom,"bottom");
	HX_VISIT_MEMBER_NAME(left,"left");
	HX_VISIT_MEMBER_NAME(top,"top");
	HX_VISIT_MEMBER_NAME(maxWidth,"maxWidth");
	HX_VISIT_MEMBER_NAME(minWidth,"minWidth");
	HX_VISIT_MEMBER_NAME(maxHeight,"maxHeight");
	HX_VISIT_MEMBER_NAME(minHeight,"minHeight");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_VISIT_MEMBER_NAME(paddingTop,"paddingTop");
	HX_VISIT_MEMBER_NAME(paddingRight,"paddingRight");
	HX_VISIT_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_VISIT_MEMBER_NAME(marginBottom,"marginBottom");
	HX_VISIT_MEMBER_NAME(marginTop,"marginTop");
	HX_VISIT_MEMBER_NAME(marginRight,"marginRight");
	HX_VISIT_MEMBER_NAME(marginLeft,"marginLeft");
	HX_VISIT_MEMBER_NAME(zIndex,"zIndex");
	HX_VISIT_MEMBER_NAME(clear,"clear");
	HX_VISIT_MEMBER_NAME(cssFloat,"cssFloat");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(display,"display");
}

Dynamic CoreStyle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return inCallProp ? get_top() : top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"left") ) { return inCallProp ? get_left() : left; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? get_right() : right; }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		if (HX_FIELD_EQ(inName,"clear") ) { return inCallProp ? get_clear() : clear; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isNone") ) { return isNone_dyn(); }
		if (HX_FIELD_EQ(inName,"isAuto") ) { return isAuto_dyn(); }
		if (HX_FIELD_EQ(inName,"cursor") ) { return inCallProp ? get_cursor() : cursor; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return inCallProp ? get_bottom() : bottom; }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"zIndex") ) { return inCallProp ? get_zIndex() : zIndex; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"getList") ) { return getList_dyn(); }
		if (HX_FIELD_EQ(inName,"cascade") ) { return cascade_dyn(); }
		if (HX_FIELD_EQ(inName,"isBlock") ) { return isBlock; }
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat; }
		if (HX_FIELD_EQ(inName,"opacity") ) { return inCallProp ? get_opacity() : opacity; }
		if (HX_FIELD_EQ(inName,"display") ) { return inCallProp ? get_display() : display; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"getColor") ) { return getColor_dyn(); }
		if (HX_FIELD_EQ(inName,"isInline") ) { return isInline; }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return inCallProp ? get_fontSize() : fontSize; }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return inCallProp ? get_maxWidth() : maxWidth; }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return inCallProp ? get_minWidth() : minWidth; }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return inCallProp ? get_cssFloat() : cssFloat; }
		if (HX_FIELD_EQ(inName,"position") ) { return inCallProp ? get_position() : position; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clear") ) { return get_clear_dyn(); }
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"getNumber") ) { return getNumber_dyn(); }
		if (HX_FIELD_EQ(inName,"isVisible") ) { return isVisible; }
		if (HX_FIELD_EQ(inName,"_animator") ) { return _animator; }
		if (HX_FIELD_EQ(inName,"transform") ) { return inCallProp ? get_transform() : transform; }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return inCallProp ? get_overflowY() : overflowY; }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return inCallProp ? get_overflowX() : overflowX; }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return inCallProp ? get_textAlign() : textAlign; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return inCallProp ? get_fontStyle() : fontStyle; }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return inCallProp ? get_maxHeight() : maxHeight; }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return inCallProp ? get_minHeight() : minHeight; }
		if (HX_FIELD_EQ(inName,"marginTop") ) { return inCallProp ? get_marginTop() : marginTop; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_cursor") ) { return get_cursor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zIndex") ) { return get_zIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"getKeyword") ) { return getKeyword_dyn(); }
		if (HX_FIELD_EQ(inName,"getIDLName") ) { return getIDLName_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoTop") ) { return hasAutoTop; }
		if (HX_FIELD_EQ(inName,"usedValues") ) { return usedValues; }
		if (HX_FIELD_EQ(inName,"visibility") ) { return inCallProp ? get_visibility() : visibility; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return inCallProp ? get_textIndent() : textIndent; }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return inCallProp ? get_whiteSpace() : whiteSpace; }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return inCallProp ? get_lineHeight() : lineHeight; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return inCallProp ? get_fontFamily() : fontFamily; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return inCallProp ? get_fontWeight() : fontWeight; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return inCallProp ? get_paddingTop() : paddingTop; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return inCallProp ? get_marginLeft() : marginLeft; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_display") ) { return get_display_dyn(); }
		if (HX_FIELD_EQ(inName,"get_opacity") ) { return get_opacity_dyn(); }
		if (HX_FIELD_EQ(inName,"isInherited") ) { return isInherited_dyn(); }
		if (HX_FIELD_EQ(inName,"setProperty") ) { return setProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoLeft") ) { return hasAutoLeft; }
		if (HX_FIELD_EQ(inName,"hasMaxWidth") ) { return hasMaxWidth; }
		if (HX_FIELD_EQ(inName,"htmlElement") ) { return htmlElement; }
		if (HX_FIELD_EQ(inName,"fontMetrics") ) { return fontMetrics; }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return inCallProp ? get_wordSpacing() : wordSpacing; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return inCallProp ? get_fontVariant() : fontVariant; }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return inCallProp ? get_paddingLeft() : paddingLeft; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return inCallProp ? get_marginRight() : marginRight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_cssFloat") ) { return get_cssFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_position") ) { return get_position_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontSize") ) { return get_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxWidth") ) { return get_maxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_minWidth") ) { return get_minWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"isAnimatable") ) { return isAnimatable_dyn(); }
		if (HX_FIELD_EQ(inName,"initAnimator") ) { return initAnimator_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoRight") ) { return hasAutoRight; }
		if (HX_FIELD_EQ(inName,"hasMaxHeight") ) { return hasMaxHeight; }
		if (HX_FIELD_EQ(inName,"hasAutoWidth") ) { return hasAutoWidth; }
		if (HX_FIELD_EQ(inName,"isTopAligned") ) { return isTopAligned; }
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned; }
		if (HX_FIELD_EQ(inName,"_fontManager") ) { return _fontManager; }
		if (HX_FIELD_EQ(inName,"outlineStyle") ) { return inCallProp ? get_outlineStyle() : outlineStyle; }
		if (HX_FIELD_EQ(inName,"outlineColor") ) { return inCallProp ? get_outlineColor() : outlineColor; }
		if (HX_FIELD_EQ(inName,"outlineWidth") ) { return inCallProp ? get_outlineWidth() : outlineWidth; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return inCallProp ? get_paddingRight() : paddingRight; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return inCallProp ? get_marginBottom() : marginBottom; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_transform") ) { return get_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflowY") ) { return get_overflowY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflowX") ) { return get_overflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textAlign") ) { return get_textAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontStyle") ) { return get_fontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxHeight") ) { return get_maxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_minHeight") ) { return get_minHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginTop") ) { return get_marginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoBottom") ) { return hasAutoBottom; }
		if (HX_FIELD_EQ(inName,"isLeftAligned") ) { return isLeftAligned; }
		if (HX_FIELD_EQ(inName,"hasAutoHeight") ) { return hasAutoHeight; }
		if (HX_FIELD_EQ(inName,"isTransparent") ) { return isTransparent; }
		if (HX_FIELD_EQ(inName,"isTransformed") ) { return isTransformed; }
		if (HX_FIELD_EQ(inName,"isInlineBlock") ) { return isInlineBlock; }
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { return isInlineLevel; }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return inCallProp ? get_verticalAlign() : verticalAlign; }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return inCallProp ? get_letterSpacing() : letterSpacing; }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return inCallProp ? get_textTransform() : textTransform; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return inCallProp ? get_paddingBottom() : paddingBottom; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_visibility") ) { return get_visibility_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textIndent") ) { return get_textIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_whiteSpace") ) { return get_whiteSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lineHeight") ) { return get_lineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontFamily") ) { return get_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontWeight") ) { return get_fontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingTop") ) { return get_paddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginLeft") ) { return get_marginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"computedValues") ) { return computedValues; }
		if (HX_FIELD_EQ(inName,"textDecoration") ) { return inCallProp ? get_textDecoration() : textDecoration; }
		if (HX_FIELD_EQ(inName,"borderTopStyle") ) { return inCallProp ? get_borderTopStyle() : borderTopStyle; }
		if (HX_FIELD_EQ(inName,"borderTopColor") ) { return inCallProp ? get_borderTopColor() : borderTopColor; }
		if (HX_FIELD_EQ(inName,"borderTopWidth") ) { return inCallProp ? get_borderTopWidth() : borderTopWidth; }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return inCallProp ? get_backgroundClip() : backgroundClip; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return inCallProp ? get_backgroundSize() : backgroundSize; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_wordSpacing") ) { return get_wordSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontVariant") ) { return get_fontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingLeft") ) { return get_paddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginRight") ) { return get_marginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"cascadeProperty") ) { return cascadeProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"isBottomAligned") ) { return isBottomAligned; }
		if (HX_FIELD_EQ(inName,"hasCSSTransform") ) { return hasCSSTransform; }
		if (HX_FIELD_EQ(inName,"_isFirstCascade") ) { return _isFirstCascade; }
		if (HX_FIELD_EQ(inName,"specifiedValues") ) { return specifiedValues; }
		if (HX_FIELD_EQ(inName,"transitionDelay") ) { return inCallProp ? get_transitionDelay() : transitionDelay; }
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { return inCallProp ? get_transformOrigin() : transformOrigin; }
		if (HX_FIELD_EQ(inName,"borderLeftStyle") ) { return inCallProp ? get_borderLeftStyle() : borderLeftStyle; }
		if (HX_FIELD_EQ(inName,"borderLeftColor") ) { return inCallProp ? get_borderLeftColor() : borderLeftColor; }
		if (HX_FIELD_EQ(inName,"borderLeftWidth") ) { return inCallProp ? get_borderLeftWidth() : borderLeftWidth; }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return inCallProp ? get_backgroundImage() : backgroundImage; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return inCallProp ? get_backgroundColor() : backgroundColor; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_outlineColor") ) { return get_outlineColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outlineStyle") ) { return get_outlineStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outlineWidth") ) { return get_outlineWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingRight") ) { return get_paddingRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginBottom") ) { return get_marginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoMarginTop") ) { return hasAutoMarginTop; }
		if (HX_FIELD_EQ(inName,"hasPreWhiteSpace") ) { return hasPreWhiteSpace; }
		if (HX_FIELD_EQ(inName,"canHaveClearance") ) { return canHaveClearance; }
		if (HX_FIELD_EQ(inName,"borderRightStyle") ) { return inCallProp ? get_borderRightStyle() : borderRightStyle; }
		if (HX_FIELD_EQ(inName,"borderRightColor") ) { return inCallProp ? get_borderRightColor() : borderRightColor; }
		if (HX_FIELD_EQ(inName,"borderRightWidth") ) { return inCallProp ? get_borderRightWidth() : borderRightWidth; }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return inCallProp ? get_backgroundOrigin() : backgroundOrigin; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return inCallProp ? get_backgroundRepeat() : backgroundRepeat; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_verticalAlign") ) { return get_verticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"get_letterSpacing") ) { return get_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textTransform") ) { return get_textTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingBottom") ) { return get_paddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"getAbsoluteLength") ) { return getAbsoluteLength_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoMarginLeft") ) { return hasAutoMarginLeft; }
		if (HX_FIELD_EQ(inName,"isBaselineAligned") ) { return isBaselineAligned; }
		if (HX_FIELD_EQ(inName,"canAlwaysOverflow") ) { return canAlwaysOverflow; }
		if (HX_FIELD_EQ(inName,"isFixedPositioned") ) { return isFixedPositioned; }
		if (HX_FIELD_EQ(inName,"borderBottomStyle") ) { return inCallProp ? get_borderBottomStyle() : borderBottomStyle; }
		if (HX_FIELD_EQ(inName,"borderBottomColor") ) { return inCallProp ? get_borderBottomColor() : borderBottomColor; }
		if (HX_FIELD_EQ(inName,"borderBottomWidth") ) { return inCallProp ? get_borderBottomWidth() : borderBottomWidth; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_textDecoration") ) { return get_textDecoration_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTopStyle") ) { return get_borderTopStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTopColor") ) { return get_borderTopColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTopWidth") ) { return get_borderTopWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundSize") ) { return get_backgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundClip") ) { return get_backgroundClip_dyn(); }
		if (HX_FIELD_EQ(inName,"onTransitionUpdate") ) { return onTransitionUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"setInitialProperty") ) { return setInitialProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoMarginRight") ) { return hasAutoMarginRight; }
		if (HX_FIELD_EQ(inName,"hasBackgroundColor") ) { return hasBackgroundColor; }
		if (HX_FIELD_EQ(inName,"hasBackgroundImage") ) { return hasBackgroundImage; }
		if (HX_FIELD_EQ(inName,"_changedProperties") ) { return _changedProperties; }
		if (HX_FIELD_EQ(inName,"_transitionManager") ) { return _transitionManager; }
		if (HX_FIELD_EQ(inName,"transitionDuration") ) { return inCallProp ? get_transitionDuration() : transitionDuration; }
		if (HX_FIELD_EQ(inName,"transitionProperty") ) { return inCallProp ? get_transitionProperty() : transitionProperty; }
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return inCallProp ? get_backgroundPosition() : backgroundPosition; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_borderLeftStyle") ) { return get_borderLeftStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderLeftColor") ) { return get_borderLeftColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderLeftWidth") ) { return get_borderLeftWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transitionDelay") ) { return get_transitionDelay_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transformOrigin") ) { return get_transformOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundImage") ) { return get_backgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundColor") ) { return get_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"endPendingAnimation") ) { return endPendingAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedProperty") ) { return getComputedProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAutoMarginBottom") ) { return hasAutoMarginBottom; }
		if (HX_FIELD_EQ(inName,"hasNormalWhiteSpace") ) { return hasNormalWhiteSpace; }
		if (HX_FIELD_EQ(inName,"hasNoWrapWhiteSpace") ) { return hasNoWrapWhiteSpace; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_borderRightStyle") ) { return get_borderRightStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderRightColor") ) { return get_borderRightColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderRightWidth") ) { return get_borderRightWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundRepeat") ) { return get_backgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundOrigin") ) { return get_backgroundOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"onTransitionComplete") ) { return onTransitionComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"hasPreWrapWhiteSpace") ) { return hasPreWrapWhiteSpace; }
		if (HX_FIELD_EQ(inName,"hasPreLineWhiteSpace") ) { return hasPreLineWhiteSpace; }
		if (HX_FIELD_EQ(inName,"isRelativePositioned") ) { return isRelativePositioned; }
		if (HX_FIELD_EQ(inName,"backgroundAttachment") ) { return inCallProp ? get_backgroundAttachment() : backgroundAttachment; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_borderBottomStyle") ) { return get_borderBottomStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderBottomColor") ) { return get_borderBottomColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderBottomWidth") ) { return get_borderBottomWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"applyNoneOutlineWidth") ) { return applyNoneOutlineWidth_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"get_transitionDuration") ) { return get_transitionDuration_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transitionProperty") ) { return get_transitionProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundPosition") ) { return get_backgroundPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"startPendingAnimations") ) { return startPendingAnimations_dyn(); }
		if (HX_FIELD_EQ(inName,"isAbsolutelyPositioned") ) { return isAbsolutelyPositioned; }
		if (HX_FIELD_EQ(inName,"_pendingComputedValues") ) { return _pendingComputedValues; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"applyHiddenBordersWidth") ) { return applyHiddenBordersWidth_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"get_backgroundAttachment") ) { return get_backgroundAttachment_dyn(); }
		if (HX_FIELD_EQ(inName,"updateCoreStyleAttribute") ) { return updateCoreStyleAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"_initialStyleDeclaration") ) { return _initialStyleDeclaration; }
		if (HX_FIELD_EQ(inName,"transitionTimingFunction") ) { return inCallProp ? get_transitionTimingFunction() : transitionTimingFunction; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"initPendingComputedValues") ) { return initPendingComputedValues_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"hasNoneOrHiddenBorderStyle") ) { return hasNoneOrHiddenBorderStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnimatablePropertyValue") ) { return getAnimatablePropertyValue_dyn(); }
		if (HX_FIELD_EQ(inName,"hasHiddenOrScrollOverflowY") ) { return hasHiddenOrScrollOverflowY; }
		if (HX_FIELD_EQ(inName,"hasHiddenOrScrollOverflowX") ) { return hasHiddenOrScrollOverflowX; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_pendingTransitionEndEvents") ) { return _pendingTransitionEndEvents; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"get_transitionTimingFunction") ) { return get_transitionTimingFunction_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedOrInitialProperty") ) { return getComputedOrInitialProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"hasTransitionnableProperties") ) { return hasTransitionnableProperties; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"getTransitionablePropertyValue") ) { return getTransitionablePropertyValue_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"_initialComputedStyleDeclaration") ) { return _initialComputedStyleDeclaration; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"applyPositionFloatAndDisplayRelationship") ) { return applyPositionFloatAndDisplayRelationship_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { top=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { left=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { right=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clear") ) { clear=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"cursor") ) { cursor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { bottom=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zIndex") ) { zIndex=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isBlock") ) { isBlock=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isFloat") ) { isFloat=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opacity") ) { opacity=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"display") ) { display=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isInline") ) { isInline=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontSize") ) { fontSize=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { maxWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minWidth") ) { minWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { cssFloat=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isVisible") ) { isVisible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_animator") ) { _animator=inValue.Cast< ::cocktail::core::animation::Animator >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"overflowY") ) { overflowY=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"overflowX") ) { overflowX=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textAlign") ) { textAlign=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { fontStyle=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { maxHeight=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minHeight") ) { minHeight=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginTop") ) { marginTop=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hasAutoTop") ) { hasAutoTop=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"usedValues") ) { usedValues=inValue.Cast< ::cocktail::core::css::UsedValuesVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visibility") ) { visibility=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { textIndent=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { whiteSpace=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { lineHeight=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { fontFamily=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { fontWeight=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { paddingTop=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { marginLeft=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasAutoLeft") ) { hasAutoLeft=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasMaxWidth") ) { hasMaxWidth=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"htmlElement") ) { htmlElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontMetrics") ) { fontMetrics=inValue.Cast< ::cocktail::core::font::FontMetricsVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { wordSpacing=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { fontVariant=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { paddingLeft=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { marginRight=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hasAutoRight") ) { hasAutoRight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasMaxHeight") ) { hasMaxHeight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasAutoWidth") ) { hasAutoWidth=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isTopAligned") ) { isTopAligned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isPositioned") ) { isPositioned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fontManager") ) { _fontManager=inValue.Cast< ::cocktail::core::font::FontManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineStyle") ) { outlineStyle=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineColor") ) { outlineColor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineWidth") ) { outlineWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { paddingRight=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { marginBottom=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasAutoBottom") ) { hasAutoBottom=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isLeftAligned") ) { isLeftAligned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasAutoHeight") ) { hasAutoHeight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isTransparent") ) { isTransparent=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isTransformed") ) { isTransformed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isInlineBlock") ) { isInlineBlock=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isInlineLevel") ) { isInlineLevel=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { verticalAlign=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { letterSpacing=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textTransform") ) { textTransform=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { paddingBottom=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"computedValues") ) { computedValues=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textDecoration") ) { textDecoration=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopStyle") ) { borderTopStyle=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopColor") ) { borderTopColor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopWidth") ) { borderTopWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { backgroundClip=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { backgroundSize=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isBottomAligned") ) { isBottomAligned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasCSSTransform") ) { hasCSSTransform=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isFirstCascade") ) { _isFirstCascade=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"specifiedValues") ) { specifiedValues=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionDelay") ) { transitionDelay=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { transformOrigin=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftStyle") ) { borderLeftStyle=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftColor") ) { borderLeftColor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftWidth") ) { borderLeftWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { backgroundImage=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { backgroundColor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hasAutoMarginTop") ) { hasAutoMarginTop=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasPreWhiteSpace") ) { hasPreWhiteSpace=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"canHaveClearance") ) { canHaveClearance=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRightStyle") ) { borderRightStyle=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRightColor") ) { borderRightColor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRightWidth") ) { borderRightWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { backgroundOrigin=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { backgroundRepeat=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"hasAutoMarginLeft") ) { hasAutoMarginLeft=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isBaselineAligned") ) { isBaselineAligned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"canAlwaysOverflow") ) { canAlwaysOverflow=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isFixedPositioned") ) { isFixedPositioned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottomStyle") ) { borderBottomStyle=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottomColor") ) { borderBottomColor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottomWidth") ) { borderBottomWidth=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"hasAutoMarginRight") ) { hasAutoMarginRight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBackgroundColor") ) { hasBackgroundColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBackgroundImage") ) { hasBackgroundImage=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_changedProperties") ) { _changedProperties=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_transitionManager") ) { _transitionManager=inValue.Cast< ::cocktail::core::animation::TransitionManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionDuration") ) { transitionDuration=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionProperty") ) { transitionProperty=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { backgroundPosition=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"hasAutoMarginBottom") ) { hasAutoMarginBottom=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasNormalWhiteSpace") ) { hasNormalWhiteSpace=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasNoWrapWhiteSpace") ) { hasNoWrapWhiteSpace=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"hasPreWrapWhiteSpace") ) { hasPreWrapWhiteSpace=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasPreLineWhiteSpace") ) { hasPreLineWhiteSpace=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isRelativePositioned") ) { isRelativePositioned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundAttachment") ) { backgroundAttachment=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"isAbsolutelyPositioned") ) { isAbsolutelyPositioned=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pendingComputedValues") ) { _pendingComputedValues=inValue.Cast< Array< ::cocktail::core::css::TypedPropertyVO > >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_initialStyleDeclaration") ) { _initialStyleDeclaration=inValue.Cast< ::cocktail::core::css::InitialStyleDeclaration >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionTimingFunction") ) { transitionTimingFunction=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"hasHiddenOrScrollOverflowY") ) { hasHiddenOrScrollOverflowY=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasHiddenOrScrollOverflowX") ) { hasHiddenOrScrollOverflowX=inValue.Cast< bool >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_pendingTransitionEndEvents") ) { _pendingTransitionEndEvents=inValue.Cast< Array< ::cocktail::core::event::TransitionEvent > >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"hasTransitionnableProperties") ) { hasTransitionnableProperties=inValue.Cast< bool >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"_initialComputedStyleDeclaration") ) { _initialComputedStyleDeclaration=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CoreStyle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hasTransitionnableProperties"));
	outFields->push(HX_CSTRING("hasAutoMarginBottom"));
	outFields->push(HX_CSTRING("hasAutoMarginTop"));
	outFields->push(HX_CSTRING("hasAutoMarginRight"));
	outFields->push(HX_CSTRING("hasAutoMarginLeft"));
	outFields->push(HX_CSTRING("hasAutoRight"));
	outFields->push(HX_CSTRING("hasAutoLeft"));
	outFields->push(HX_CSTRING("hasAutoBottom"));
	outFields->push(HX_CSTRING("hasAutoTop"));
	outFields->push(HX_CSTRING("isLeftAligned"));
	outFields->push(HX_CSTRING("hasMaxHeight"));
	outFields->push(HX_CSTRING("hasMaxWidth"));
	outFields->push(HX_CSTRING("hasAutoHeight"));
	outFields->push(HX_CSTRING("hasAutoWidth"));
	outFields->push(HX_CSTRING("hasNormalWhiteSpace"));
	outFields->push(HX_CSTRING("hasPreWrapWhiteSpace"));
	outFields->push(HX_CSTRING("hasPreLineWhiteSpace"));
	outFields->push(HX_CSTRING("hasNoWrapWhiteSpace"));
	outFields->push(HX_CSTRING("hasPreWhiteSpace"));
	outFields->push(HX_CSTRING("canHaveClearance"));
	outFields->push(HX_CSTRING("isBaselineAligned"));
	outFields->push(HX_CSTRING("isBottomAligned"));
	outFields->push(HX_CSTRING("isTopAligned"));
	outFields->push(HX_CSTRING("hasBackgroundColor"));
	outFields->push(HX_CSTRING("hasBackgroundImage"));
	outFields->push(HX_CSTRING("isTransparent"));
	outFields->push(HX_CSTRING("hasCSSTransform"));
	outFields->push(HX_CSTRING("isTransformed"));
	outFields->push(HX_CSTRING("hasHiddenOrScrollOverflowY"));
	outFields->push(HX_CSTRING("hasHiddenOrScrollOverflowX"));
	outFields->push(HX_CSTRING("canAlwaysOverflow"));
	outFields->push(HX_CSTRING("isAbsolutelyPositioned"));
	outFields->push(HX_CSTRING("isFixedPositioned"));
	outFields->push(HX_CSTRING("isRelativePositioned"));
	outFields->push(HX_CSTRING("isPositioned"));
	outFields->push(HX_CSTRING("isVisible"));
	outFields->push(HX_CSTRING("isBlock"));
	outFields->push(HX_CSTRING("isInline"));
	outFields->push(HX_CSTRING("isInlineBlock"));
	outFields->push(HX_CSTRING("isInlineLevel"));
	outFields->push(HX_CSTRING("isFloat"));
	outFields->push(HX_CSTRING("_initialComputedStyleDeclaration"));
	outFields->push(HX_CSTRING("_initialStyleDeclaration"));
	outFields->push(HX_CSTRING("htmlElement"));
	outFields->push(HX_CSTRING("_isFirstCascade"));
	outFields->push(HX_CSTRING("_changedProperties"));
	outFields->push(HX_CSTRING("_fontManager"));
	outFields->push(HX_CSTRING("fontMetrics"));
	outFields->push(HX_CSTRING("_pendingComputedValues"));
	outFields->push(HX_CSTRING("_pendingTransitionEndEvents"));
	outFields->push(HX_CSTRING("_transitionManager"));
	outFields->push(HX_CSTRING("_animator"));
	outFields->push(HX_CSTRING("usedValues"));
	outFields->push(HX_CSTRING("computedValues"));
	outFields->push(HX_CSTRING("specifiedValues"));
	outFields->push(HX_CSTRING("transitionTimingFunction"));
	outFields->push(HX_CSTRING("transitionDelay"));
	outFields->push(HX_CSTRING("transitionDuration"));
	outFields->push(HX_CSTRING("transitionProperty"));
	outFields->push(HX_CSTRING("outlineStyle"));
	outFields->push(HX_CSTRING("outlineColor"));
	outFields->push(HX_CSTRING("outlineWidth"));
	outFields->push(HX_CSTRING("cursor"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("transformOrigin"));
	outFields->push(HX_CSTRING("overflowY"));
	outFields->push(HX_CSTRING("overflowX"));
	outFields->push(HX_CSTRING("visibility"));
	outFields->push(HX_CSTRING("opacity"));
	outFields->push(HX_CSTRING("textDecoration"));
	outFields->push(HX_CSTRING("verticalAlign"));
	outFields->push(HX_CSTRING("textIndent"));
	outFields->push(HX_CSTRING("textAlign"));
	outFields->push(HX_CSTRING("whiteSpace"));
	outFields->push(HX_CSTRING("wordSpacing"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("textTransform"));
	outFields->push(HX_CSTRING("lineHeight"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("fontVariant"));
	outFields->push(HX_CSTRING("fontFamily"));
	outFields->push(HX_CSTRING("fontStyle"));
	outFields->push(HX_CSTRING("fontWeight"));
	outFields->push(HX_CSTRING("fontSize"));
	outFields->push(HX_CSTRING("borderLeftStyle"));
	outFields->push(HX_CSTRING("borderBottomStyle"));
	outFields->push(HX_CSTRING("borderRightStyle"));
	outFields->push(HX_CSTRING("borderTopStyle"));
	outFields->push(HX_CSTRING("borderLeftColor"));
	outFields->push(HX_CSTRING("borderBottomColor"));
	outFields->push(HX_CSTRING("borderRightColor"));
	outFields->push(HX_CSTRING("borderTopColor"));
	outFields->push(HX_CSTRING("borderLeftWidth"));
	outFields->push(HX_CSTRING("borderBottomWidth"));
	outFields->push(HX_CSTRING("borderRightWidth"));
	outFields->push(HX_CSTRING("borderTopWidth"));
	outFields->push(HX_CSTRING("backgroundAttachment"));
	outFields->push(HX_CSTRING("backgroundClip"));
	outFields->push(HX_CSTRING("backgroundPosition"));
	outFields->push(HX_CSTRING("backgroundSize"));
	outFields->push(HX_CSTRING("backgroundOrigin"));
	outFields->push(HX_CSTRING("backgroundRepeat"));
	outFields->push(HX_CSTRING("backgroundImage"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("minWidth"));
	outFields->push(HX_CSTRING("maxHeight"));
	outFields->push(HX_CSTRING("minHeight"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("paddingBottom"));
	outFields->push(HX_CSTRING("paddingTop"));
	outFields->push(HX_CSTRING("paddingRight"));
	outFields->push(HX_CSTRING("paddingLeft"));
	outFields->push(HX_CSTRING("marginBottom"));
	outFields->push(HX_CSTRING("marginTop"));
	outFields->push(HX_CSTRING("marginRight"));
	outFields->push(HX_CSTRING("marginLeft"));
	outFields->push(HX_CSTRING("zIndex"));
	outFields->push(HX_CSTRING("clear"));
	outFields->push(HX_CSTRING("cssFloat"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("display"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_textDecoration"),
	HX_CSTRING("get_outlineColor"),
	HX_CSTRING("get_outlineStyle"),
	HX_CSTRING("get_outlineWidth"),
	HX_CSTRING("get_borderLeftStyle"),
	HX_CSTRING("get_borderBottomStyle"),
	HX_CSTRING("get_borderRightStyle"),
	HX_CSTRING("get_borderTopStyle"),
	HX_CSTRING("get_borderLeftColor"),
	HX_CSTRING("get_borderBottomColor"),
	HX_CSTRING("get_borderRightColor"),
	HX_CSTRING("get_borderTopColor"),
	HX_CSTRING("get_borderLeftWidth"),
	HX_CSTRING("get_borderBottomWidth"),
	HX_CSTRING("get_borderRightWidth"),
	HX_CSTRING("get_borderTopWidth"),
	HX_CSTRING("get_transitionDelay"),
	HX_CSTRING("get_transitionTimingFunction"),
	HX_CSTRING("get_transitionDuration"),
	HX_CSTRING("get_transitionProperty"),
	HX_CSTRING("get_cursor"),
	HX_CSTRING("get_transform"),
	HX_CSTRING("get_transformOrigin"),
	HX_CSTRING("get_overflowY"),
	HX_CSTRING("get_overflowX"),
	HX_CSTRING("get_visibility"),
	HX_CSTRING("get_verticalAlign"),
	HX_CSTRING("get_textIndent"),
	HX_CSTRING("get_textAlign"),
	HX_CSTRING("get_whiteSpace"),
	HX_CSTRING("get_wordSpacing"),
	HX_CSTRING("get_letterSpacing"),
	HX_CSTRING("get_textTransform"),
	HX_CSTRING("get_lineHeight"),
	HX_CSTRING("get_color"),
	HX_CSTRING("get_fontVariant"),
	HX_CSTRING("get_fontFamily"),
	HX_CSTRING("get_fontStyle"),
	HX_CSTRING("get_fontWeight"),
	HX_CSTRING("get_backgroundPosition"),
	HX_CSTRING("get_backgroundSize"),
	HX_CSTRING("get_backgroundRepeat"),
	HX_CSTRING("get_backgroundAttachment"),
	HX_CSTRING("get_backgroundClip"),
	HX_CSTRING("get_backgroundOrigin"),
	HX_CSTRING("get_backgroundImage"),
	HX_CSTRING("get_backgroundColor"),
	HX_CSTRING("get_zIndex"),
	HX_CSTRING("get_clear"),
	HX_CSTRING("get_cssFloat"),
	HX_CSTRING("get_position"),
	HX_CSTRING("get_display"),
	HX_CSTRING("get_fontSize"),
	HX_CSTRING("get_right"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("get_left"),
	HX_CSTRING("get_top"),
	HX_CSTRING("get_maxWidth"),
	HX_CSTRING("get_minWidth"),
	HX_CSTRING("get_maxHeight"),
	HX_CSTRING("get_minHeight"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_paddingBottom"),
	HX_CSTRING("get_paddingTop"),
	HX_CSTRING("get_paddingRight"),
	HX_CSTRING("get_paddingLeft"),
	HX_CSTRING("get_marginBottom"),
	HX_CSTRING("get_marginTop"),
	HX_CSTRING("get_marginRight"),
	HX_CSTRING("get_marginLeft"),
	HX_CSTRING("get_opacity"),
	HX_CSTRING("isNone"),
	HX_CSTRING("isAuto"),
	HX_CSTRING("getColor"),
	HX_CSTRING("getAbsoluteLength"),
	HX_CSTRING("getList"),
	HX_CSTRING("getNumber"),
	HX_CSTRING("getKeyword"),
	HX_CSTRING("hasNoneOrHiddenBorderStyle"),
	HX_CSTRING("isInherited"),
	HX_CSTRING("getAnimatablePropertyValue"),
	HX_CSTRING("isAnimatable"),
	HX_CSTRING("getIDLName"),
	HX_CSTRING("getComputedOrInitialProperty"),
	HX_CSTRING("getTransitionablePropertyValue"),
	HX_CSTRING("onTransitionUpdate"),
	HX_CSTRING("onTransitionComplete"),
	HX_CSTRING("endPendingAnimation"),
	HX_CSTRING("startPendingAnimations"),
	HX_CSTRING("applyNoneOutlineWidth"),
	HX_CSTRING("applyHiddenBordersWidth"),
	HX_CSTRING("applyPositionFloatAndDisplayRelationship"),
	HX_CSTRING("getComputedProperty"),
	HX_CSTRING("setProperty"),
	HX_CSTRING("setInitialProperty"),
	HX_CSTRING("cascadeProperty"),
	HX_CSTRING("updateCoreStyleAttribute"),
	HX_CSTRING("cascade"),
	HX_CSTRING("initAnimator"),
	HX_CSTRING("initPendingComputedValues"),
	HX_CSTRING("init"),
	HX_CSTRING("hasTransitionnableProperties"),
	HX_CSTRING("hasAutoMarginBottom"),
	HX_CSTRING("hasAutoMarginTop"),
	HX_CSTRING("hasAutoMarginRight"),
	HX_CSTRING("hasAutoMarginLeft"),
	HX_CSTRING("hasAutoRight"),
	HX_CSTRING("hasAutoLeft"),
	HX_CSTRING("hasAutoBottom"),
	HX_CSTRING("hasAutoTop"),
	HX_CSTRING("isLeftAligned"),
	HX_CSTRING("hasMaxHeight"),
	HX_CSTRING("hasMaxWidth"),
	HX_CSTRING("hasAutoHeight"),
	HX_CSTRING("hasAutoWidth"),
	HX_CSTRING("hasNormalWhiteSpace"),
	HX_CSTRING("hasPreWrapWhiteSpace"),
	HX_CSTRING("hasPreLineWhiteSpace"),
	HX_CSTRING("hasNoWrapWhiteSpace"),
	HX_CSTRING("hasPreWhiteSpace"),
	HX_CSTRING("canHaveClearance"),
	HX_CSTRING("isBaselineAligned"),
	HX_CSTRING("isBottomAligned"),
	HX_CSTRING("isTopAligned"),
	HX_CSTRING("hasBackgroundColor"),
	HX_CSTRING("hasBackgroundImage"),
	HX_CSTRING("isTransparent"),
	HX_CSTRING("hasCSSTransform"),
	HX_CSTRING("isTransformed"),
	HX_CSTRING("hasHiddenOrScrollOverflowY"),
	HX_CSTRING("hasHiddenOrScrollOverflowX"),
	HX_CSTRING("canAlwaysOverflow"),
	HX_CSTRING("isAbsolutelyPositioned"),
	HX_CSTRING("isFixedPositioned"),
	HX_CSTRING("isRelativePositioned"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("isVisible"),
	HX_CSTRING("isBlock"),
	HX_CSTRING("isInline"),
	HX_CSTRING("isInlineBlock"),
	HX_CSTRING("isInlineLevel"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("_initialComputedStyleDeclaration"),
	HX_CSTRING("_initialStyleDeclaration"),
	HX_CSTRING("htmlElement"),
	HX_CSTRING("_isFirstCascade"),
	HX_CSTRING("_changedProperties"),
	HX_CSTRING("_fontManager"),
	HX_CSTRING("fontMetrics"),
	HX_CSTRING("_pendingComputedValues"),
	HX_CSTRING("_pendingTransitionEndEvents"),
	HX_CSTRING("_transitionManager"),
	HX_CSTRING("_animator"),
	HX_CSTRING("usedValues"),
	HX_CSTRING("computedValues"),
	HX_CSTRING("specifiedValues"),
	HX_CSTRING("transitionTimingFunction"),
	HX_CSTRING("transitionDelay"),
	HX_CSTRING("transitionDuration"),
	HX_CSTRING("transitionProperty"),
	HX_CSTRING("outlineStyle"),
	HX_CSTRING("outlineColor"),
	HX_CSTRING("outlineWidth"),
	HX_CSTRING("cursor"),
	HX_CSTRING("transform"),
	HX_CSTRING("transformOrigin"),
	HX_CSTRING("overflowY"),
	HX_CSTRING("overflowX"),
	HX_CSTRING("visibility"),
	HX_CSTRING("opacity"),
	HX_CSTRING("textDecoration"),
	HX_CSTRING("verticalAlign"),
	HX_CSTRING("textIndent"),
	HX_CSTRING("textAlign"),
	HX_CSTRING("whiteSpace"),
	HX_CSTRING("wordSpacing"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("textTransform"),
	HX_CSTRING("lineHeight"),
	HX_CSTRING("color"),
	HX_CSTRING("fontVariant"),
	HX_CSTRING("fontFamily"),
	HX_CSTRING("fontStyle"),
	HX_CSTRING("fontWeight"),
	HX_CSTRING("fontSize"),
	HX_CSTRING("borderLeftStyle"),
	HX_CSTRING("borderBottomStyle"),
	HX_CSTRING("borderRightStyle"),
	HX_CSTRING("borderTopStyle"),
	HX_CSTRING("borderLeftColor"),
	HX_CSTRING("borderBottomColor"),
	HX_CSTRING("borderRightColor"),
	HX_CSTRING("borderTopColor"),
	HX_CSTRING("borderLeftWidth"),
	HX_CSTRING("borderBottomWidth"),
	HX_CSTRING("borderRightWidth"),
	HX_CSTRING("borderTopWidth"),
	HX_CSTRING("backgroundAttachment"),
	HX_CSTRING("backgroundClip"),
	HX_CSTRING("backgroundPosition"),
	HX_CSTRING("backgroundSize"),
	HX_CSTRING("backgroundOrigin"),
	HX_CSTRING("backgroundRepeat"),
	HX_CSTRING("backgroundImage"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("right"),
	HX_CSTRING("bottom"),
	HX_CSTRING("left"),
	HX_CSTRING("top"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("minWidth"),
	HX_CSTRING("maxHeight"),
	HX_CSTRING("minHeight"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("paddingBottom"),
	HX_CSTRING("paddingTop"),
	HX_CSTRING("paddingRight"),
	HX_CSTRING("paddingLeft"),
	HX_CSTRING("marginBottom"),
	HX_CSTRING("marginTop"),
	HX_CSTRING("marginRight"),
	HX_CSTRING("marginLeft"),
	HX_CSTRING("zIndex"),
	HX_CSTRING("clear"),
	HX_CSTRING("cssFloat"),
	HX_CSTRING("position"),
	HX_CSTRING("display"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CoreStyle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CoreStyle_obj::__mClass,"__mClass");
};

Class CoreStyle_obj::__mClass;

void CoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CoreStyle"), hx::TCanCast< CoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
