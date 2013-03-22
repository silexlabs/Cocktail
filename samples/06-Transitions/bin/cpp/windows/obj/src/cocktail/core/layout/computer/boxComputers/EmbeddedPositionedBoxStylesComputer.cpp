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
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void EmbeddedPositionedBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("EmbeddedPositionedBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",30);
{
	HX_STACK_LINE(30)
	super::__construct();
}
;
	return null();
}

EmbeddedPositionedBoxStylesComputer_obj::~EmbeddedPositionedBoxStylesComputer_obj() { }

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedPositionedBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > EmbeddedPositionedBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > result = new EmbeddedPositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > result = new EmbeddedPositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Float EmbeddedPositionedBoxStylesComputer_obj::getComputedStaticTop( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("EmbeddedPositionedBoxStylesComputer::getComputedStaticTop","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",216);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(216)
	return style->usedValues->marginTop;
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,getComputedStaticTop,return )

Float EmbeddedPositionedBoxStylesComputer_obj::getComputedStaticLeft( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("EmbeddedPositionedBoxStylesComputer::getComputedStaticLeft","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",207);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(207)
	return style->usedValues->marginLeft;
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,getComputedStaticLeft,return )

Void EmbeddedPositionedBoxStylesComputer_obj::measureVerticalPositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("EmbeddedPositionedBoxStylesComputer::measureVerticalPositionOffsets","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",132);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_LINE(133)
		::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(135)
		if (((bool((style->hasAutoTop == true)) || bool((style->hasAutoBottom == true))))){
			HX_STACK_LINE(137)
			if (((style->hasAutoMarginTop == true))){
				HX_STACK_LINE(138)
				usedValues->marginTop = (int)0;
			}
			HX_STACK_LINE(141)
			if (((style->hasAutoMarginBottom == true))){
				HX_STACK_LINE(142)
				usedValues->marginBottom = (int)0;
			}
			HX_STACK_LINE(146)
			if (((bool((style->hasAutoTop == true)) && bool((style->hasAutoBottom == true))))){
				HX_STACK_LINE(148)
				usedValues->top = this->getComputedStaticTop(style,containingBlockData);
				HX_STACK_LINE(149)
				usedValues->bottom = ((((((((containingBlockData->height - usedValues->height) - usedValues->marginTop) - usedValues->marginBottom) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top);
			}
			else{
				HX_STACK_LINE(152)
				if (((style->hasAutoTop == true))){
					struct _Function_4_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",154);
							{
								HX_STACK_LINE(154)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(154)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(154)
					usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->height);
					HX_STACK_LINE(155)
					usedValues->top = ((((((((containingBlockData->height - usedValues->height) - usedValues->marginTop) - usedValues->marginBottom) - usedValues->bottom) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth);
				}
				else{
					HX_STACK_LINE(157)
					if (((style->hasAutoBottom == true))){
						struct _Function_5_1{
							inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
								HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",159);
								{
									HX_STACK_LINE(159)
									::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
									HX_STACK_LINE(159)
									return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
								}
								return null();
							}
						};
						HX_STACK_LINE(159)
						usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),containingBlockData->height);
						HX_STACK_LINE(160)
						usedValues->bottom = ((((((((containingBlockData->height - usedValues->height) - usedValues->marginTop) - usedValues->marginBottom) - usedValues->top) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth);
					}
					else{
						struct _Function_5_1{
							inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
								HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",164);
								{
									HX_STACK_LINE(164)
									::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
									HX_STACK_LINE(164)
									return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
								}
								return null();
							}
						};
						HX_STACK_LINE(164)
						usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),containingBlockData->height);
						struct _Function_5_2{
							inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
								HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",165);
								{
									HX_STACK_LINE(165)
									::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
									HX_STACK_LINE(165)
									return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
								}
								return null();
							}
						};
						HX_STACK_LINE(165)
						usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_2::Block(style)) )) ),containingBlockData->height);
					}
				}
			}
		}
		else{
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",171);
					{
						HX_STACK_LINE(171)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(171)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(171)
			usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),containingBlockData->height);
			struct _Function_2_2{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",172);
					{
						HX_STACK_LINE(172)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(172)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(172)
			usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->height);
			HX_STACK_LINE(174)
			if (((bool((style->hasAutoMarginTop == true)) && bool((style->hasAutoMarginBottom == true))))){
				HX_STACK_LINE(176)
				Float margin = (Float((((((((containingBlockData->height - usedValues->top) - usedValues->bottom) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth))) / Float((int)2));		HX_STACK_VAR(margin,"margin");
				HX_STACK_LINE(178)
				Float usedMargin = (Float(((((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom))) / Float((int)2));		HX_STACK_VAR(usedMargin,"usedMargin");
				HX_STACK_LINE(180)
				if (((usedMargin >= (int)0))){
					HX_STACK_LINE(182)
					usedValues->marginTop = usedMargin;
					HX_STACK_LINE(183)
					usedValues->marginBottom = usedMargin;
				}
				else{
					HX_STACK_LINE(187)
					usedValues->marginTop = (int)0;
					HX_STACK_LINE(188)
					usedValues->marginBottom = (((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom);
				}
			}
			else{
				HX_STACK_LINE(191)
				if (((style->hasAutoMarginTop == true))){
					HX_STACK_LINE(192)
					usedValues->marginTop = ((((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom) - usedValues->marginBottom);
				}
				else{
					HX_STACK_LINE(195)
					if (((style->hasAutoMarginBottom == true))){
						HX_STACK_LINE(196)
						usedValues->marginBottom = ((((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom) - usedValues->marginTop);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,measureVerticalPositionOffsets,(void))

Void EmbeddedPositionedBoxStylesComputer_obj::measureHorizontalPositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("EmbeddedPositionedBoxStylesComputer::measureHorizontalPositionOffsets","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_LINE(52)
		::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(55)
		if (((bool((style->hasAutoLeft == true)) || bool((style->hasAutoRight == true))))){
			HX_STACK_LINE(58)
			if (((style->hasAutoMarginLeft == true))){
				HX_STACK_LINE(59)
				usedValues->marginLeft = (int)0;
			}
			HX_STACK_LINE(62)
			if (((style->hasAutoMarginRight == true))){
				HX_STACK_LINE(63)
				usedValues->marginRight = (int)0;
			}
			HX_STACK_LINE(68)
			if (((bool((style->hasAutoLeft == true)) && bool((style->hasAutoRight == true))))){
				HX_STACK_LINE(70)
				usedValues->left = this->getComputedStaticLeft(style,containingBlockData);
				HX_STACK_LINE(71)
				usedValues->right = ((((((((containingBlockData->width - usedValues->width) - usedValues->marginLeft) - usedValues->marginRight) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left);
			}
			else{
				HX_STACK_LINE(74)
				if (((style->hasAutoLeft == true))){
					struct _Function_4_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",76);
							{
								HX_STACK_LINE(76)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)23,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(76)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(76)
					usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->width);
					HX_STACK_LINE(77)
					usedValues->left = ((((((((containingBlockData->width - usedValues->width) - usedValues->marginLeft) - usedValues->marginRight) - usedValues->right) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth);
				}
				else{
					HX_STACK_LINE(80)
					if (((style->hasAutoRight == true))){
						struct _Function_5_1{
							inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
								HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",82);
								{
									HX_STACK_LINE(82)
									::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
									HX_STACK_LINE(82)
									return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
								}
								return null();
							}
						};
						HX_STACK_LINE(82)
						usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),containingBlockData->width);
						HX_STACK_LINE(83)
						usedValues->right = ((((((((containingBlockData->width - usedValues->width) - usedValues->marginLeft) - usedValues->marginRight) - usedValues->left) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth);
					}
				}
			}
		}
		else{
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",90);
					{
						HX_STACK_LINE(90)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(90)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(90)
			usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),containingBlockData->width);
			struct _Function_2_2{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",91);
					{
						HX_STACK_LINE(91)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)23,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(91)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(91)
			usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->width);
			HX_STACK_LINE(94)
			if (((bool((style->hasAutoMarginLeft == true)) && bool((style->hasAutoMarginRight == true))))){
				HX_STACK_LINE(96)
				Float margin = (Float((((((((containingBlockData->width - usedValues->left) - usedValues->right) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth))) / Float((int)2));		HX_STACK_VAR(margin,"margin");
				HX_STACK_LINE(100)
				Float usedMargin = (Float(((((((((containingBlockData->width - usedValues->width) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right))) / Float((int)2));		HX_STACK_VAR(usedMargin,"usedMargin");
				HX_STACK_LINE(102)
				if (((usedMargin >= (int)0))){
					HX_STACK_LINE(104)
					usedValues->marginLeft = usedMargin;
					HX_STACK_LINE(105)
					usedValues->marginRight = usedMargin;
				}
				else{
					HX_STACK_LINE(110)
					usedValues->marginLeft = (int)0;
					HX_STACK_LINE(111)
					usedValues->marginRight = (((((((containingBlockData->width - usedValues->width) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right);
				}
				HX_STACK_LINE(114)
				usedValues->marginLeft = (int)0;
			}
			else{
				HX_STACK_LINE(116)
				if (((style->hasAutoMarginLeft == true))){
					HX_STACK_LINE(117)
					usedValues->marginLeft = ((((((((containingBlockData->width - usedValues->width) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right) - usedValues->marginRight);
				}
				else{
					HX_STACK_LINE(120)
					if (((style->hasAutoMarginRight == true))){
						HX_STACK_LINE(121)
						usedValues->marginRight = ((((((((containingBlockData->width - usedValues->width) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right) - usedValues->marginLeft);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,measureHorizontalPositionOffsets,(void))

Void EmbeddedPositionedBoxStylesComputer_obj::measurePositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("EmbeddedPositionedBoxStylesComputer::measurePositionOffsets","cocktail/core/layout/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_LINE(42)
		this->measureHorizontalPositionOffsets(style,containingBlockData);
		HX_STACK_LINE(44)
		this->measureVerticalPositionOffsets(style,containingBlockData);
	}
return null();
}



EmbeddedPositionedBoxStylesComputer_obj::EmbeddedPositionedBoxStylesComputer_obj()
{
}

void EmbeddedPositionedBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedPositionedBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EmbeddedPositionedBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedStaticTop") ) { return getComputedStaticTop_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedStaticLeft") ) { return getComputedStaticLeft_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"measurePositionOffsets") ) { return measurePositionOffsets_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"measureVerticalPositionOffsets") ) { return measureVerticalPositionOffsets_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"measureHorizontalPositionOffsets") ) { return measureHorizontalPositionOffsets_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EmbeddedPositionedBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedStaticTop"),
	HX_CSTRING("getComputedStaticLeft"),
	HX_CSTRING("measureVerticalPositionOffsets"),
	HX_CSTRING("measureHorizontalPositionOffsets"),
	HX_CSTRING("measurePositionOffsets"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmbeddedPositionedBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedPositionedBoxStylesComputer_obj::__mClass,"__mClass");
};

Class EmbeddedPositionedBoxStylesComputer_obj::__mClass;

void EmbeddedPositionedBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"), hx::TCanCast< EmbeddedPositionedBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedPositionedBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
