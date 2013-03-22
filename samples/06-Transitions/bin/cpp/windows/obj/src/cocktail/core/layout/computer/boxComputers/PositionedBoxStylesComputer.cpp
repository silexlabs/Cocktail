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
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_PositionedBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void PositionedBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("PositionedBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",32);
{
	HX_STACK_LINE(32)
	super::__construct();
}
;
	return null();
}

PositionedBoxStylesComputer_obj::~PositionedBoxStylesComputer_obj() { }

Dynamic PositionedBoxStylesComputer_obj::__CreateEmpty() { return  new PositionedBoxStylesComputer_obj; }
hx::ObjectPtr< PositionedBoxStylesComputer_obj > PositionedBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< PositionedBoxStylesComputer_obj > result = new PositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic PositionedBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PositionedBoxStylesComputer_obj > result = new PositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Float PositionedBoxStylesComputer_obj::getComputedStaticTop( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("PositionedBoxStylesComputer::getComputedStaticTop","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",401);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(401)
	return style->usedValues->marginTop;
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,getComputedStaticTop,return )

Float PositionedBoxStylesComputer_obj::getComputedStaticLeft( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("PositionedBoxStylesComputer::getComputedStaticLeft","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",392);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(392)
	return style->usedValues->marginLeft;
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,getComputedStaticLeft,return )

Float PositionedBoxStylesComputer_obj::measureHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("PositionedBoxStylesComputer::measureHeight","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",283);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(284)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(287)
	Float usedHeight = this->getComputedHeight(style,containingBlockData);		HX_STACK_VAR(usedHeight,"usedHeight");
	HX_STACK_LINE(290)
	if (((bool((style->hasAutoTop == false)) && bool((style->hasAutoBottom == false))))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",293);
				{
					HX_STACK_LINE(293)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(293)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(293)
		usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),containingBlockData->height);
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",294);
				{
					HX_STACK_LINE(294)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(294)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(294)
		usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->height);
		HX_STACK_LINE(297)
		if (((bool((style->hasAutoMarginTop == true)) && bool((style->hasAutoMarginBottom == true))))){
			HX_STACK_LINE(301)
			Float usedMargin = (Float(((((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom))) / Float((int)2));		HX_STACK_VAR(usedMargin,"usedMargin");
			HX_STACK_LINE(303)
			if (((usedMargin >= (int)0))){
				HX_STACK_LINE(305)
				usedValues->marginTop = usedMargin;
				HX_STACK_LINE(306)
				usedValues->marginBottom = usedMargin;
			}
			else{
				HX_STACK_LINE(311)
				usedValues->marginBottom = (int)0;
				HX_STACK_LINE(312)
				usedValues->marginTop = (((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->bottom) - usedValues->top);
			}
		}
		else{
			HX_STACK_LINE(317)
			if (((style->hasAutoMarginTop == true))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",321);
						{
							HX_STACK_LINE(321)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(321)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
						}
						return null();
					}
				};
				struct _Function_4_2{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",321);
						{
							HX_STACK_LINE(321)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(321)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(321)
				usedValues->marginBottom = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
				HX_STACK_LINE(322)
				usedValues->marginTop = ((((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom) - usedValues->marginBottom);
			}
			else{
				HX_STACK_LINE(325)
				if (((style->hasAutoMarginBottom == true))){
					struct _Function_5_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",327);
							{
								HX_STACK_LINE(327)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(327)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
							}
							return null();
						}
					};
					struct _Function_5_2{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",327);
							{
								HX_STACK_LINE(327)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(327)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(327)
					usedValues->marginTop = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
					HX_STACK_LINE(328)
					usedValues->marginBottom = ((((((((containingBlockData->height - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top) - usedValues->bottom) - usedValues->marginTop);
				}
				else{
					struct _Function_5_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",333);
							{
								HX_STACK_LINE(333)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(333)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
							}
							return null();
						}
					};
					struct _Function_5_2{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",333);
							{
								HX_STACK_LINE(333)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(333)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(333)
					usedValues->marginTop = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
					struct _Function_5_3{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",334);
							{
								HX_STACK_LINE(334)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(334)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
							}
							return null();
						}
					};
					struct _Function_5_4{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",334);
							{
								HX_STACK_LINE(334)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(334)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(334)
					usedValues->marginBottom = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_4::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
				}
			}
		}
	}
	else{
		HX_STACK_LINE(341)
		if (((style->hasAutoMarginTop == true))){
			HX_STACK_LINE(342)
			usedValues->marginTop = (int)0;
		}
		else{
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",347);
					{
						HX_STACK_LINE(347)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(347)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
					}
					return null();
				}
			};
			struct _Function_3_2{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",347);
					{
						HX_STACK_LINE(347)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(347)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(346)
			usedValues->marginTop = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
		}
		HX_STACK_LINE(350)
		if (((style->hasAutoMarginBottom == true))){
			HX_STACK_LINE(351)
			usedValues->marginBottom = (int)0;
		}
		else{
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",356);
					{
						HX_STACK_LINE(356)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(356)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
					}
					return null();
				}
			};
			struct _Function_3_2{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",356);
					{
						HX_STACK_LINE(356)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(356)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(355)
			usedValues->marginBottom = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
		}
		HX_STACK_LINE(360)
		if (((bool((style->hasAutoTop == true)) && bool((style->hasAutoBottom == true))))){
			HX_STACK_LINE(362)
			usedValues->top = this->getComputedStaticTop(style,containingBlockData);
			HX_STACK_LINE(363)
			usedValues->bottom = ((((((((containingBlockData->height - usedValues->marginTop) - usedValues->marginBottom) - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top);
		}
		else{
			HX_STACK_LINE(366)
			if (((style->hasAutoBottom == true))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",368);
						{
							HX_STACK_LINE(368)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(368)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(368)
				usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->height);
				HX_STACK_LINE(369)
				usedValues->bottom = ((((((((containingBlockData->height - usedValues->marginTop) - usedValues->marginBottom) - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top);
			}
			else{
				HX_STACK_LINE(372)
				if (((style->hasAutoTop == true))){
					struct _Function_5_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",374);
							{
								HX_STACK_LINE(374)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(374)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(374)
					usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),containingBlockData->height);
					HX_STACK_LINE(375)
					usedValues->top = ((((((((containingBlockData->height - usedValues->marginTop) - usedValues->marginBottom) - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->bottom);
				}
			}
		}
	}
	HX_STACK_LINE(379)
	return usedHeight;
}


Float PositionedBoxStylesComputer_obj::measureAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("PositionedBoxStylesComputer::measureAutoHeight","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(227)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(229)
	Float usedHeight = 0.0;		HX_STACK_VAR(usedHeight,"usedHeight");
	HX_STACK_LINE(232)
	if (((style->hasAutoMarginTop == true))){
		HX_STACK_LINE(233)
		usedValues->marginTop = (int)0;
	}
	else{
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",238);
				{
					HX_STACK_LINE(238)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(238)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",238);
				{
					HX_STACK_LINE(238)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(238)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(237)
		usedValues->marginTop = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
	}
	HX_STACK_LINE(241)
	if (((style->hasAutoMarginBottom == true))){
		HX_STACK_LINE(242)
		usedValues->marginBottom = (int)0;
	}
	else{
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",247);
				{
					HX_STACK_LINE(247)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(247)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",247);
				{
					HX_STACK_LINE(247)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(247)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(246)
		usedValues->marginBottom = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->height,usedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
	}
	HX_STACK_LINE(251)
	if (((bool((style->hasAutoTop == false)) && bool((style->hasAutoBottom == false))))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",254);
				{
					HX_STACK_LINE(254)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(254)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(254)
		usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),containingBlockData->height);
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",255);
				{
					HX_STACK_LINE(255)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(255)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(255)
		usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->height);
		HX_STACK_LINE(259)
		usedHeight = ((((((((containingBlockData->height - usedValues->marginTop) - usedValues->top) - usedValues->bottom) - usedValues->marginBottom) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth);
	}
	else{
		HX_STACK_LINE(262)
		if (((style->hasAutoBottom == true))){
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",264);
					{
						HX_STACK_LINE(264)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(264)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(264)
			usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),containingBlockData->height);
			HX_STACK_LINE(265)
			usedValues->bottom = ((((((((containingBlockData->height - usedValues->marginTop) - usedValues->marginBottom) - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->top);
		}
		else{
			HX_STACK_LINE(268)
			if (((style->hasAutoTop == true))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",270);
						{
							HX_STACK_LINE(270)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(270)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(270)
				usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->height);
				HX_STACK_LINE(271)
				usedValues->top = ((((((((containingBlockData->height - usedValues->marginTop) - usedValues->marginBottom) - usedValues->height) - usedValues->paddingTop) - usedValues->paddingBottom) - usedValues->borderTopWidth) - usedValues->borderBottomWidth) - usedValues->bottom);
			}
		}
	}
	HX_STACK_LINE(276)
	return usedHeight;
}


Float PositionedBoxStylesComputer_obj::measureWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("PositionedBoxStylesComputer::measureWidth","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(120)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(123)
	Float usedWidth = this->getComputedWidth(style,containingBlockData);		HX_STACK_VAR(usedWidth,"usedWidth");
	HX_STACK_LINE(126)
	if (((bool((style->hasAutoLeft == false)) && bool((style->hasAutoRight == false))))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",129);
				{
					HX_STACK_LINE(129)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(129)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(129)
		usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),containingBlockData->width);
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",130);
				{
					HX_STACK_LINE(130)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)23,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(130)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(130)
		usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->width);
		HX_STACK_LINE(133)
		if (((bool((style->hasAutoMarginLeft == true)) && bool((style->hasAutoMarginRight == true))))){
			HX_STACK_LINE(137)
			Float usedMargin = (Float(((((((((containingBlockData->width - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right))) / Float((int)2));		HX_STACK_VAR(usedMargin,"usedMargin");
			HX_STACK_LINE(139)
			if (((usedMargin >= (int)0))){
				HX_STACK_LINE(141)
				usedValues->marginLeft = usedMargin;
				HX_STACK_LINE(142)
				usedValues->marginRight = usedMargin;
			}
			else{
				HX_STACK_LINE(147)
				usedValues->marginLeft = (int)0;
				HX_STACK_LINE(148)
				usedValues->marginRight = (((((((containingBlockData->width - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right);
			}
		}
		else{
			HX_STACK_LINE(153)
			if (((style->hasAutoMarginLeft == true))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",157);
						{
							HX_STACK_LINE(157)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(157)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
						}
						return null();
					}
				};
				struct _Function_4_2{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",157);
						{
							HX_STACK_LINE(157)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(157)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(157)
				usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
				HX_STACK_LINE(158)
				usedValues->marginLeft = ((((((((containingBlockData->width - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right) - usedValues->marginRight);
			}
			else{
				HX_STACK_LINE(161)
				if (((style->hasAutoMarginRight == true))){
					struct _Function_5_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",163);
							{
								HX_STACK_LINE(163)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(163)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
							}
							return null();
						}
					};
					struct _Function_5_2{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",163);
							{
								HX_STACK_LINE(163)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(163)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(163)
					usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
					HX_STACK_LINE(164)
					usedValues->marginRight = ((((((((containingBlockData->width - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left) - usedValues->right) - usedValues->marginLeft);
				}
				else{
					struct _Function_5_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",169);
							{
								HX_STACK_LINE(169)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(169)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
							}
							return null();
						}
					};
					struct _Function_5_2{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",169);
							{
								HX_STACK_LINE(169)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(169)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(169)
					usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
					struct _Function_5_3{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",170);
							{
								HX_STACK_LINE(170)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(170)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
							}
							return null();
						}
					};
					struct _Function_5_4{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",170);
							{
								HX_STACK_LINE(170)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(170)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(170)
					usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_4::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
				}
			}
		}
	}
	else{
		HX_STACK_LINE(177)
		if (((style->hasAutoMarginLeft == true))){
			HX_STACK_LINE(178)
			usedValues->marginLeft = (int)0;
		}
		else{
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",183);
					{
						HX_STACK_LINE(183)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(183)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
					}
					return null();
				}
			};
			struct _Function_3_2{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",183);
					{
						HX_STACK_LINE(183)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(183)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(182)
			usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
		}
		HX_STACK_LINE(186)
		if (((style->hasAutoMarginRight == true))){
			HX_STACK_LINE(187)
			usedValues->marginRight = (int)0;
		}
		else{
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",192);
					{
						HX_STACK_LINE(192)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(192)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
					}
					return null();
				}
			};
			struct _Function_3_2{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",192);
					{
						HX_STACK_LINE(192)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(192)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(191)
			usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
		}
		HX_STACK_LINE(196)
		if (((bool((style->hasAutoLeft == true)) && bool((style->hasAutoRight == true))))){
			HX_STACK_LINE(198)
			usedValues->left = this->getComputedStaticLeft(style,containingBlockData);
			HX_STACK_LINE(199)
			usedValues->right = ((((((((containingBlockData->width - usedValues->marginLeft) - usedValues->marginRight) - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left);
		}
		else{
			HX_STACK_LINE(202)
			if (((style->hasAutoLeft == true))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",204);
						{
							HX_STACK_LINE(204)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)23,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(204)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(204)
				usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->width);
				HX_STACK_LINE(205)
				usedValues->left = ((((((((containingBlockData->width - usedValues->marginLeft) - usedValues->marginRight) - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->right);
			}
			else{
				HX_STACK_LINE(208)
				if (((style->hasAutoRight == true))){
					struct _Function_5_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
							HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",210);
							{
								HX_STACK_LINE(210)
								::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(210)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(210)
					usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_5_1::Block(style)) )) ),containingBlockData->width);
					HX_STACK_LINE(211)
					usedValues->right = ((((((((containingBlockData->width - usedValues->marginLeft) - usedValues->marginRight) - usedWidth) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth) - usedValues->left);
				}
			}
		}
	}
	HX_STACK_LINE(215)
	return usedWidth;
}


Float PositionedBoxStylesComputer_obj::measureAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("PositionedBoxStylesComputer::measureAutoWidth","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",59);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(60)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(62)
	Float usedWidth = 0.0;		HX_STACK_VAR(usedWidth,"usedWidth");
	HX_STACK_LINE(65)
	if (((style->hasAutoMarginLeft == true))){
		HX_STACK_LINE(66)
		usedValues->marginLeft = (int)0;
	}
	else{
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",71);
				{
					HX_STACK_LINE(71)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(71)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",71);
				{
					HX_STACK_LINE(71)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(71)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(70)
		usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	}
	HX_STACK_LINE(74)
	if (((style->hasAutoMarginRight == true))){
		HX_STACK_LINE(75)
		usedValues->marginRight = (int)0;
	}
	else{
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",80);
				{
					HX_STACK_LINE(80)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(80)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",80);
				{
					HX_STACK_LINE(80)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(80)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(79)
		usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	}
	HX_STACK_LINE(84)
	if (((bool((style->hasAutoLeft == false)) && bool((style->hasAutoRight == false))))){
		struct _Function_2_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",87);
				{
					HX_STACK_LINE(87)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(87)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(87)
		usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ),containingBlockData->width);
		struct _Function_2_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",88);
				{
					HX_STACK_LINE(88)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)23,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(88)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(88)
		usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_2::Block(style)) )) ),containingBlockData->width);
		HX_STACK_LINE(92)
		usedWidth = ((((((((containingBlockData->width - usedValues->marginLeft) - usedValues->left) - usedValues->right) - usedValues->marginRight) - usedValues->paddingLeft) - usedValues->paddingRight) - usedValues->borderLeftWidth) - usedValues->borderRightWidth);
	}
	else{
		HX_STACK_LINE(99)
		if (((style->hasAutoLeft == true))){
			struct _Function_3_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",101);
					{
						HX_STACK_LINE(101)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)23,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(101)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(100)
			usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_3_1::Block(style)) )) ),containingBlockData->width);
		}
		else{
			HX_STACK_LINE(104)
			if (((style->hasAutoRight == true))){
				struct _Function_4_1{
					inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
						HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",106);
						{
							HX_STACK_LINE(106)
							::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
							HX_STACK_LINE(106)
							return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
						}
						return null();
					}
				};
				HX_STACK_LINE(105)
				usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_4_1::Block(style)) )) ),containingBlockData->width);
			}
		}
		HX_STACK_LINE(109)
		usedWidth = (int)0;
	}
	HX_STACK_LINE(112)
	return usedWidth;
}


Void PositionedBoxStylesComputer_obj::measurePositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("PositionedBoxStylesComputer::measurePositionOffsets","cocktail/core/layout/computer/boxComputers/PositionedBoxStylesComputer.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
	}
return null();
}



PositionedBoxStylesComputer_obj::PositionedBoxStylesComputer_obj()
{
}

void PositionedBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PositionedBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PositionedBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic PositionedBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"measureWidth") ) { return measureWidth_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"measureHeight") ) { return measureHeight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"measureAutoWidth") ) { return measureAutoWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"measureAutoHeight") ) { return measureAutoHeight_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedStaticTop") ) { return getComputedStaticTop_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedStaticLeft") ) { return getComputedStaticLeft_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"measurePositionOffsets") ) { return measurePositionOffsets_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PositionedBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PositionedBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedStaticTop"),
	HX_CSTRING("getComputedStaticLeft"),
	HX_CSTRING("measureHeight"),
	HX_CSTRING("measureAutoHeight"),
	HX_CSTRING("measureWidth"),
	HX_CSTRING("measureAutoWidth"),
	HX_CSTRING("measurePositionOffsets"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PositionedBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PositionedBoxStylesComputer_obj::__mClass,"__mClass");
};

Class PositionedBoxStylesComputer_obj::__mClass;

void PositionedBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.PositionedBoxStylesComputer"), hx::TCanCast< PositionedBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PositionedBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
