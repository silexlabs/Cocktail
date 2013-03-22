#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
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
#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void EmbeddedBlockBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",36);
{
	HX_STACK_LINE(36)
	super::__construct();
}
;
	return null();
}

EmbeddedBlockBoxStylesComputer_obj::~EmbeddedBlockBoxStylesComputer_obj() { }

Dynamic EmbeddedBlockBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedBlockBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > EmbeddedBlockBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > result = new EmbeddedBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedBlockBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > result = new EmbeddedBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Float EmbeddedBlockBoxStylesComputer_obj::getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin){
	HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::getComputedAutoMargin","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",396);
	HX_STACK_THIS(this);
	HX_STACK_ARG(marginStyleValue,"marginStyleValue");
	HX_STACK_ARG(opositeMargin,"opositeMargin");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(computedDimension,"computedDimension");
	HX_STACK_ARG(isDimensionAuto,"isDimensionAuto");
	HX_STACK_ARG(computedPaddingsAndBordersDimension,"computedPaddingsAndBordersDimension");
	HX_STACK_ARG(isHorizontalMargin,"isHorizontalMargin");
	HX_STACK_LINE(397)
	Float usedMargin;		HX_STACK_VAR(usedMargin,"usedMargin");
	HX_STACK_LINE(399)
	if (((isHorizontalMargin == false))){
		HX_STACK_LINE(400)
		usedMargin = 0.0;
	}
	else{
		HX_STACK_LINE(404)
		usedMargin = this->super::getComputedAutoMargin(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,false,computedPaddingsAndBordersDimension,isHorizontalMargin);
	}
	HX_STACK_LINE(410)
	return usedMargin;
}


Float EmbeddedBlockBoxStylesComputer_obj::getComputedAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::getComputedAutoHeight","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",325);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(326)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(328)
	Float usedHeight = 0.0;		HX_STACK_VAR(usedHeight,"usedHeight");
	HX_STACK_LINE(332)
	::cocktail::core::html::EmbeddedElement embeddedHTMLElement = style->htmlElement;		HX_STACK_VAR(embeddedHTMLElement,"embeddedHTMLElement");
	HX_STACK_LINE(338)
	if (((embeddedHTMLElement->getAttributeNode(HX_CSTRING("height")) != null()))){
		HX_STACK_LINE(339)
		usedHeight = embeddedHTMLElement->get_height();
	}
	else{
		HX_STACK_LINE(343)
		if (((style->hasAutoWidth == true))){
			HX_STACK_LINE(344)
			if (((embeddedHTMLElement->get_intrinsicHeight() != null()))){
				HX_STACK_LINE(349)
				usedHeight = embeddedHTMLElement->get_intrinsicHeight();
			}
			else{
				HX_STACK_LINE(353)
				if (((bool((embeddedHTMLElement->get_intrinsicWidth() != null())) && bool((embeddedHTMLElement->get_intrinsicRatio() != null()))))){
					HX_STACK_LINE(354)
					usedHeight = (embeddedHTMLElement->get_intrinsicWidth() * embeddedHTMLElement->get_intrinsicRatio());
				}
				else{
					HX_STACK_LINE(358)
					if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
					}
				}
			}
		}
		else{
			HX_STACK_LINE(365)
			if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",370);
						{
							HX_STACK_LINE(370)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)15,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(370)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)15)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(370)
				Float usedWidth = this->getComputedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->width,containingBlockData->isWidthAuto);		HX_STACK_VAR(usedWidth,"usedWidth");
				HX_STACK_LINE(372)
				usedHeight = (usedWidth * embeddedHTMLElement->get_intrinsicRatio());
			}
			else{
				HX_STACK_LINE(375)
				if (((embeddedHTMLElement->get_intrinsicHeight() != null()))){
					HX_STACK_LINE(376)
					usedHeight = embeddedHTMLElement->get_intrinsicHeight();
				}
				else{
					HX_STACK_LINE(380)
					usedHeight = (int)150;
				}
			}
		}
	}
	HX_STACK_LINE(388)
	return usedHeight;
}


Float EmbeddedBlockBoxStylesComputer_obj::getComputedAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::getComputedAutoWidth","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",238);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(239)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(241)
	Float usedWidth = 0.0;		HX_STACK_VAR(usedWidth,"usedWidth");
	HX_STACK_LINE(243)
	::cocktail::core::html::EmbeddedElement embeddedHTMLElement = style->htmlElement;		HX_STACK_VAR(embeddedHTMLElement,"embeddedHTMLElement");
	HX_STACK_LINE(249)
	if (((embeddedHTMLElement->getAttributeNode(HX_CSTRING("width")) != null()))){
		HX_STACK_LINE(250)
		usedWidth = embeddedHTMLElement->get_width();
	}
	else{
		HX_STACK_LINE(254)
		if (((style->hasAutoHeight == true))){
			HX_STACK_LINE(255)
			if (((embeddedHTMLElement->get_intrinsicWidth() != null()))){
				HX_STACK_LINE(261)
				usedWidth = embeddedHTMLElement->get_intrinsicWidth();
			}
			else{
				HX_STACK_LINE(265)
				if (((bool((embeddedHTMLElement->get_intrinsicHeight() != null())) && bool((embeddedHTMLElement->get_intrinsicRatio() != null()))))){
					HX_STACK_LINE(266)
					usedWidth = (embeddedHTMLElement->get_intrinsicHeight() * embeddedHTMLElement->get_intrinsicRatio());
				}
				else{
					HX_STACK_LINE(269)
					if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
						HX_STACK_LINE(270)
						if (((containingBlockData->isWidthAuto == false))){
							HX_STACK_LINE(279)
							usedWidth = ((((((containingBlockData->width - usedValues->marginLeft) - usedValues->marginRight) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth);
						}
						else{
							HX_STACK_LINE(283)
							usedWidth = 0.0;
						}
					}
				}
			}
		}
		else{
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",294);
					{
						HX_STACK_LINE(294)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)16,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(294)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)16)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(294)
			Float usedHeight = this->getComputedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),containingBlockData->height,containingBlockData->isHeightAuto);		HX_STACK_VAR(usedHeight,"usedHeight");
			HX_STACK_LINE(297)
			if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
				HX_STACK_LINE(298)
				usedWidth = (Float(usedHeight) / Float(embeddedHTMLElement->get_intrinsicRatio()));
			}
			else{
				HX_STACK_LINE(302)
				if (((embeddedHTMLElement->get_intrinsicWidth() != null()))){
					HX_STACK_LINE(303)
					usedWidth = embeddedHTMLElement->get_intrinsicWidth();
				}
				else{
					HX_STACK_LINE(307)
					usedWidth = (int)300;
				}
			}
		}
	}
	HX_STACK_LINE(316)
	return usedWidth;
}


Float EmbeddedBlockBoxStylesComputer_obj::measureAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::measureAutoWidth","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(219)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(222)
	Float usedWidth = this->getComputedAutoWidth(style,containingBlockData);		HX_STACK_VAR(usedWidth,"usedWidth");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",225);
			{
				HX_STACK_LINE(225)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(225)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",225);
			{
				HX_STACK_LINE(225)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(225)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(225)
	usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	struct _Function_1_3{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",227);
			{
				HX_STACK_LINE(227)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(227)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",227);
			{
				HX_STACK_LINE(227)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(227)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(227)
	usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	HX_STACK_LINE(229)
	return usedWidth;
}


Void EmbeddedBlockBoxStylesComputer_obj::constrainDimensions( ::cocktail::core::css::CoreStyle style,Float usedWidth,Float usedHeight){
{
		HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::constrainDimensions","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(usedWidth,"usedWidth");
		HX_STACK_ARG(usedHeight,"usedHeight");
		HX_STACK_LINE(75)
		::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(77)
		Float maxHeight = usedValues->maxHeight;		HX_STACK_VAR(maxHeight,"maxHeight");
		HX_STACK_LINE(78)
		Float minHeight = usedValues->minHeight;		HX_STACK_VAR(minHeight,"minHeight");
		HX_STACK_LINE(79)
		Float maxWidth = usedValues->maxWidth;		HX_STACK_VAR(maxWidth,"maxWidth");
		HX_STACK_LINE(80)
		Float minWidth = usedValues->minWidth;		HX_STACK_VAR(minWidth,"minWidth");
		HX_STACK_LINE(83)
		bool widthSuperiorToMaxWidth = false;		HX_STACK_VAR(widthSuperiorToMaxWidth,"widthSuperiorToMaxWidth");
		HX_STACK_LINE(84)
		if (((style->hasMaxWidth == true))){
			HX_STACK_LINE(85)
			widthSuperiorToMaxWidth = (usedWidth > maxWidth);
		}
		HX_STACK_LINE(89)
		bool heightSuperiorToMaxHeight = false;		HX_STACK_VAR(heightSuperiorToMaxHeight,"heightSuperiorToMaxHeight");
		HX_STACK_LINE(90)
		if (((style->hasMaxHeight == true))){
			HX_STACK_LINE(91)
			heightSuperiorToMaxHeight = (usedHeight > maxHeight);
		}
		HX_STACK_LINE(95)
		bool widthInferiorToMinWidth = (usedWidth < minWidth);		HX_STACK_VAR(widthInferiorToMinWidth,"widthInferiorToMinWidth");
		HX_STACK_LINE(96)
		bool heightInferiorToMinHeight = (usedHeight < minHeight);		HX_STACK_VAR(heightInferiorToMinHeight,"heightInferiorToMinHeight");
		HX_STACK_LINE(101)
		if (((widthSuperiorToMaxWidth == true))){
			HX_STACK_LINE(102)
			if (((heightSuperiorToMaxHeight == true))){
				HX_STACK_LINE(104)
				if ((((Float(maxWidth) / Float(usedWidth)) <= (Float(maxHeight) / Float(usedHeight))))){
					HX_STACK_LINE(107)
					if (((minHeight > (maxWidth * ((Float(usedHeight) / Float(usedWidth))))))){
						HX_STACK_LINE(108)
						usedHeight = minHeight;
					}
					else{
						HX_STACK_LINE(112)
						usedHeight = (maxWidth * ((Float(usedHeight) / Float(usedWidth))));
					}
					HX_STACK_LINE(115)
					usedWidth = maxWidth;
				}
			}
			else{
				HX_STACK_LINE(118)
				if (((heightInferiorToMinHeight == true))){
					HX_STACK_LINE(120)
					usedWidth = maxWidth;
					HX_STACK_LINE(121)
					usedHeight = minHeight;
				}
				else{
					HX_STACK_LINE(125)
					if ((((maxWidth * ((Float(usedHeight) / Float(usedWidth)))) > minHeight))){
						HX_STACK_LINE(126)
						usedHeight = (maxWidth * ((Float(usedHeight) / Float(usedWidth))));
					}
					else{
						HX_STACK_LINE(130)
						usedHeight = minHeight;
					}
					HX_STACK_LINE(133)
					usedWidth = maxWidth;
				}
			}
		}
		else{
			HX_STACK_LINE(136)
			if (((widthInferiorToMinWidth == true))){
				HX_STACK_LINE(137)
				if (((heightInferiorToMinHeight == true))){
					HX_STACK_LINE(139)
					if ((((Float(minWidth) / Float(usedWidth)) <= (Float(minHeight) / Float(usedHeight))))){
						HX_STACK_LINE(142)
						if (((maxWidth < (minHeight * ((Float(usedWidth) / Float(usedHeight))))))){
							HX_STACK_LINE(143)
							usedWidth = maxWidth;
						}
						else{
							HX_STACK_LINE(147)
							usedWidth = (minHeight * ((Float(usedWidth) / Float(usedHeight))));
						}
						HX_STACK_LINE(150)
						usedHeight = minHeight;
					}
					else{
						HX_STACK_LINE(154)
						if (((maxHeight < (minWidth * ((Float(usedHeight) / Float(usedWidth))))))){
							HX_STACK_LINE(155)
							usedHeight = maxHeight;
						}
						else{
							HX_STACK_LINE(159)
							usedHeight = (minWidth * ((Float(usedHeight) / Float(usedWidth))));
						}
						HX_STACK_LINE(162)
						usedWidth = minWidth;
					}
				}
				else{
					HX_STACK_LINE(165)
					if (((heightSuperiorToMaxHeight == true))){
						HX_STACK_LINE(167)
						usedWidth = minWidth;
						HX_STACK_LINE(168)
						usedHeight = maxHeight;
					}
					else{
						HX_STACK_LINE(172)
						if ((((minWidth * ((Float(usedHeight) / Float(usedWidth)))) < maxHeight))){
							HX_STACK_LINE(173)
							usedHeight = (minWidth * ((Float(usedHeight) / Float(usedWidth))));
						}
						else{
							HX_STACK_LINE(177)
							usedHeight = maxHeight;
						}
						HX_STACK_LINE(180)
						usedWidth = minWidth;
					}
				}
			}
			else{
				HX_STACK_LINE(183)
				if (((heightSuperiorToMaxHeight == true))){
					HX_STACK_LINE(185)
					if ((((maxHeight * ((Float(usedWidth) / Float(usedHeight)))) > minWidth))){
						HX_STACK_LINE(186)
						usedWidth = (maxHeight * ((Float(usedWidth) / Float(usedHeight))));
					}
					else{
						HX_STACK_LINE(190)
						usedWidth = minWidth;
					}
					HX_STACK_LINE(193)
					usedHeight = maxHeight;
				}
				else{
					HX_STACK_LINE(195)
					if (((heightInferiorToMinHeight == true))){
						HX_STACK_LINE(197)
						if ((((minHeight * ((Float(usedWidth) / Float(usedHeight)))) < minHeight))){
							HX_STACK_LINE(198)
							usedWidth = (minHeight * ((Float(usedWidth) / Float(usedHeight))));
						}
						else{
							HX_STACK_LINE(202)
							usedWidth = minHeight;
						}
						HX_STACK_LINE(205)
						usedHeight = minHeight;
					}
				}
			}
		}
		HX_STACK_LINE(208)
		usedValues->width = usedWidth;
		HX_STACK_LINE(209)
		usedValues->height = usedHeight;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EmbeddedBlockBoxStylesComputer_obj,constrainDimensions,(void))

Void EmbeddedBlockBoxStylesComputer_obj::measureDimensionsAndMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("EmbeddedBlockBoxStylesComputer::measureDimensionsAndMargins","cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_LINE(46)
		::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(48)
		Float usedWidth = this->measureWidthAndHorizontalMargins(style,containingBlockData);		HX_STACK_VAR(usedWidth,"usedWidth");
		HX_STACK_LINE(49)
		Float usedHeight = this->measureHeightAndVerticalMargins(style,containingBlockData);		HX_STACK_VAR(usedHeight,"usedHeight");
		HX_STACK_LINE(51)
		if (((bool((style->hasAutoWidth == true)) && bool((style->hasAutoHeight == true))))){
			HX_STACK_LINE(52)
			this->constrainDimensions(style,usedWidth,usedHeight);
		}
		else{
			HX_STACK_LINE(59)
			usedValues->width = this->constrainWidth(style,usedWidth);
			HX_STACK_LINE(60)
			usedValues->height = this->constrainHeight(style,usedHeight);
		}
	}
return null();
}



EmbeddedBlockBoxStylesComputer_obj::EmbeddedBlockBoxStylesComputer_obj()
{
}

void EmbeddedBlockBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedBlockBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EmbeddedBlockBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedBlockBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"measureAutoWidth") ) { return measureAutoWidth_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"constrainDimensions") ) { return constrainDimensions_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedAutoWidth") ) { return getComputedAutoWidth_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedAutoHeight") ) { return getComputedAutoHeight_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"measureDimensionsAndMargins") ) { return measureDimensionsAndMargins_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedBlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EmbeddedBlockBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedAutoMargin"),
	HX_CSTRING("getComputedAutoHeight"),
	HX_CSTRING("getComputedAutoWidth"),
	HX_CSTRING("measureAutoWidth"),
	HX_CSTRING("constrainDimensions"),
	HX_CSTRING("measureDimensionsAndMargins"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmbeddedBlockBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedBlockBoxStylesComputer_obj::__mClass,"__mClass");
};

Class EmbeddedBlockBoxStylesComputer_obj::__mClass;

void EmbeddedBlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.EmbeddedBlockBoxStylesComputer"), hx::TCanCast< EmbeddedBlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedBlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
