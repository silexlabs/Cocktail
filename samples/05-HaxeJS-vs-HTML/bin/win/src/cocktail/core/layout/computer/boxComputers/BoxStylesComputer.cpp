#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
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
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void BoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("BoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",40);
{
}
;
	return null();
}

BoxStylesComputer_obj::~BoxStylesComputer_obj() { }

Dynamic BoxStylesComputer_obj::__CreateEmpty() { return  new BoxStylesComputer_obj; }
hx::ObjectPtr< BoxStylesComputer_obj > BoxStylesComputer_obj::__new()
{  hx::ObjectPtr< BoxStylesComputer_obj > result = new BoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic BoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxStylesComputer_obj > result = new BoxStylesComputer_obj();
	result->__construct();
	return result;}

Float BoxStylesComputer_obj::constrainHeight( ::cocktail::core::css::CoreStyle style,Float usedHeight){
	HX_STACK_PUSH("BoxStylesComputer::constrainHeight","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",758);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(usedHeight,"usedHeight");
	HX_STACK_LINE(759)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(762)
	if (((style->hasMaxHeight == true))){
		HX_STACK_LINE(763)
		if (((usedHeight > usedValues->maxHeight))){
			HX_STACK_LINE(765)
			usedHeight = usedValues->maxHeight;
		}
	}
	HX_STACK_LINE(771)
	if (((usedHeight < usedValues->minHeight))){
		HX_STACK_LINE(772)
		usedHeight = usedValues->minHeight;
	}
	HX_STACK_LINE(776)
	return usedHeight;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,constrainHeight,return )

Float BoxStylesComputer_obj::constrainWidth( ::cocktail::core::css::CoreStyle style,Float usedWidth){
	HX_STACK_PUSH("BoxStylesComputer::constrainWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",730);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(usedWidth,"usedWidth");
	HX_STACK_LINE(731)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(737)
	if (((style->hasMaxWidth == true))){
		HX_STACK_LINE(738)
		if (((usedWidth > usedValues->maxWidth))){
			HX_STACK_LINE(740)
			usedWidth = usedValues->maxWidth;
		}
	}
	HX_STACK_LINE(746)
	if (((usedWidth < usedValues->minWidth))){
		HX_STACK_LINE(747)
		usedWidth = usedValues->minWidth;
	}
	HX_STACK_LINE(751)
	return usedWidth;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,constrainWidth,return )

Float BoxStylesComputer_obj::getComputedBorderWidth( ::cocktail::core::css::CSSPropertyValue borderWidthStyleValue){
	HX_STACK_PUSH("BoxStylesComputer::getComputedBorderWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",704);
	HX_STACK_THIS(this);
	HX_STACK_ARG(borderWidthStyleValue,"borderWidthStyleValue");
	HX_STACK_LINE(705)
	Float computedBorderWidthValue;		HX_STACK_VAR(computedBorderWidthValue,"computedBorderWidthValue");
	HX_STACK_LINE(710)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (borderWidthStyleValue);
		switch((_switch_1)->GetIndex()){
			case 18: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(712)
					computedBorderWidthValue = value;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(715)
				hx::Throw (HX_CSTRING("illegal value for border width"));
			}
		}
	}
	HX_STACK_LINE(719)
	return computedBorderWidthValue;
}


HX_DEFINE_DYNAMIC_FUNC1(BoxStylesComputer_obj,getComputedBorderWidth,return )

Float BoxStylesComputer_obj::getComputedPadding( ::cocktail::core::css::CSSPropertyValue paddingStyleValue,Float containingHTMLElementDimension){
	HX_STACK_PUSH("BoxStylesComputer::getComputedPadding","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",678);
	HX_STACK_THIS(this);
	HX_STACK_ARG(paddingStyleValue,"paddingStyleValue");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_LINE(679)
	Float computedPaddingValue;		HX_STACK_VAR(computedPaddingValue,"computedPaddingValue");
	HX_STACK_LINE(682)
	{
		::cocktail::core::css::CSSPropertyValue _switch_2 = (paddingStyleValue);
		switch((_switch_2)->GetIndex()){
			case 18: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(686)
					computedPaddingValue = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(690)
					computedPaddingValue = (containingHTMLElementDimension * ((value * 0.01)));
				}
			}
			;break;
			default: {
				HX_STACK_LINE(693)
				hx::Throw (HX_CSTRING("Illegal value for padding"));
			}
		}
	}
	HX_STACK_LINE(697)
	return computedPaddingValue;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedPadding,return )

Float BoxStylesComputer_obj::getComputedDimension( ::cocktail::core::css::CSSPropertyValue dimensionStyleValue,Float containingHTMLElementDimension,bool isContainingDimensionAuto){
	HX_STACK_PUSH("BoxStylesComputer::getComputedDimension","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",636);
	HX_STACK_THIS(this);
	HX_STACK_ARG(dimensionStyleValue,"dimensionStyleValue");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(isContainingDimensionAuto,"isContainingDimensionAuto");
	HX_STACK_LINE(637)
	Float computedDimensions;		HX_STACK_VAR(computedDimensions,"computedDimensions");
	HX_STACK_LINE(640)
	{
		::cocktail::core::css::CSSPropertyValue _switch_3 = (dimensionStyleValue);
		switch((_switch_3)->GetIndex()){
			case 18: {
				Float value = _switch_3->__Param(0);
{
					HX_STACK_LINE(644)
					computedDimensions = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_3->__Param(0);
{
					HX_STACK_LINE(648)
					computedDimensions = (containingHTMLElementDimension * ((value * 0.01)));
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_3->__Param(0);
{
					HX_STACK_LINE(651)
					if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
						HX_STACK_LINE(653)
						computedDimensions = (int)0;
					}
					else{
						HX_STACK_LINE(659)
						hx::Throw (HX_CSTRING("Illegal keyword value for width or height"));
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(663)
				hx::Throw (HX_CSTRING("Illegal value for width or height"));
			}
		}
	}
	HX_STACK_LINE(667)
	return computedDimensions;
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,getComputedDimension,return )

Float BoxStylesComputer_obj::getComputedPositionOffset( ::cocktail::core::css::CSSPropertyValue positionOffsetStyleValue,Float containingHTMLElementDimension){
	HX_STACK_PUSH("BoxStylesComputer::getComputedPositionOffset","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",610);
	HX_STACK_THIS(this);
	HX_STACK_ARG(positionOffsetStyleValue,"positionOffsetStyleValue");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_LINE(611)
	Float computedPositionOffset = 0.0;		HX_STACK_VAR(computedPositionOffset,"computedPositionOffset");
	HX_STACK_LINE(613)
	{
		::cocktail::core::css::CSSPropertyValue _switch_4 = (positionOffsetStyleValue);
		switch((_switch_4)->GetIndex()){
			case 18: {
				Float value = _switch_4->__Param(0);
{
					HX_STACK_LINE(615)
					computedPositionOffset = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_4->__Param(0);
{
					HX_STACK_LINE(618)
					computedPositionOffset = (containingHTMLElementDimension * ((value * 0.01)));
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(624)
	return computedPositionOffset;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedPositionOffset,return )

Float BoxStylesComputer_obj::getComputedConstrainedDimension( ::cocktail::core::css::CSSPropertyValue constrainedDimension,Float containingHTMLElementDimension,bool isContainingDimensionAuto,hx::Null< bool >  __o_isMinConstraint){
bool isMinConstraint = __o_isMinConstraint.Default(false);
	HX_STACK_PUSH("BoxStylesComputer::getComputedConstrainedDimension","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",544);
	HX_STACK_THIS(this);
	HX_STACK_ARG(constrainedDimension,"constrainedDimension");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(isContainingDimensionAuto,"isContainingDimensionAuto");
	HX_STACK_ARG(isMinConstraint,"isMinConstraint");
{
		HX_STACK_LINE(545)
		Float computedConstraintDimension = (int)0;		HX_STACK_VAR(computedConstraintDimension,"computedConstraintDimension");
		HX_STACK_LINE(548)
		{
			::cocktail::core::css::CSSPropertyValue _switch_5 = (constrainedDimension);
			switch((_switch_5)->GetIndex()){
				case 18: {
					Float value = _switch_5->__Param(0);
{
						HX_STACK_LINE(552)
						computedConstraintDimension = value;
					}
				}
				;break;
				case 2: {
					Float value = _switch_5->__Param(0);
{
						HX_STACK_LINE(556)
						if (((isContainingDimensionAuto == true))){
							HX_STACK_LINE(561)
							if (((isMinConstraint == true))){
								HX_STACK_LINE(563)
								computedConstraintDimension = (int)0;
							}
							else{
								HX_STACK_LINE(567)
								computedConstraintDimension = (int)100000;
							}
						}
						else{
							HX_STACK_LINE(572)
							computedConstraintDimension = (containingHTMLElementDimension * ((value * 0.01)));
						}
					}
				}
				;break;
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_5->__Param(0);
{
						HX_STACK_LINE(579)
						if (((value != ::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()))){
							HX_STACK_LINE(580)
							hx::Throw (HX_CSTRING("Illegal keyword value for dimension constraints style"));
						}
						HX_STACK_LINE(584)
						if (((isMinConstraint == true))){
							HX_STACK_LINE(585)
							computedConstraintDimension = 0.0;
						}
						else{
							HX_STACK_LINE(589)
							computedConstraintDimension = (int)100000;
						}
					}
				}
				;break;
				default: {
					HX_STACK_LINE(593)
					hx::Throw (HX_CSTRING("Illegal value for dimension constraints style"));
				}
			}
		}
		HX_STACK_LINE(597)
		return computedConstraintDimension;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(BoxStylesComputer_obj,getComputedConstrainedDimension,return )

Float BoxStylesComputer_obj::getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin){
	HX_STACK_PUSH("BoxStylesComputer::getComputedAutoMargin","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",497);
	HX_STACK_THIS(this);
	HX_STACK_ARG(marginStyleValue,"marginStyleValue");
	HX_STACK_ARG(opositeMargin,"opositeMargin");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(computedDimension,"computedDimension");
	HX_STACK_ARG(isDimensionAuto,"isDimensionAuto");
	HX_STACK_ARG(computedPaddingsAndBordersDimension,"computedPaddingsAndBordersDimension");
	HX_STACK_ARG(isHorizontalMargin,"isHorizontalMargin");
	HX_STACK_LINE(498)
	Float computedMargin = (int)0;		HX_STACK_VAR(computedMargin,"computedMargin");
	HX_STACK_LINE(503)
	if (((bool((isHorizontalMargin == false)) || bool((isDimensionAuto == true))))){
		HX_STACK_LINE(504)
		computedMargin = 0.0;
	}
	else{
		HX_STACK_LINE(509)
		{
			::cocktail::core::css::CSSPropertyValue _switch_6 = (opositeMargin);
			switch((_switch_6)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_6->__Param(0);
{
						HX_STACK_LINE(515)
						if (((value != ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
							HX_STACK_LINE(516)
							hx::Throw (HX_CSTRING("Illegal keyword value for margin"));
						}
						HX_STACK_LINE(520)
						computedMargin = (Float((((containingHTMLElementDimension - computedDimension) - computedPaddingsAndBordersDimension))) / Float((int)2));
					}
				}
				;break;
				default: {
					HX_STACK_LINE(524)
					Float opositeComputedMargin = this->getComputedMargin(opositeMargin,marginStyleValue,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsAndBordersDimension,isHorizontalMargin);		HX_STACK_VAR(opositeComputedMargin,"opositeComputedMargin");
					HX_STACK_LINE(525)
					computedMargin = (((containingHTMLElementDimension - computedDimension) - computedPaddingsAndBordersDimension) - opositeComputedMargin);
				}
			}
		}
	}
	HX_STACK_LINE(529)
	return computedMargin;
}


HX_DEFINE_DYNAMIC_FUNC7(BoxStylesComputer_obj,getComputedAutoMargin,return )

Float BoxStylesComputer_obj::getComputedMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin){
	HX_STACK_PUSH("BoxStylesComputer::getComputedMargin","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",451);
	HX_STACK_THIS(this);
	HX_STACK_ARG(marginStyleValue,"marginStyleValue");
	HX_STACK_ARG(opositeMargin,"opositeMargin");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(computedDimension,"computedDimension");
	HX_STACK_ARG(isDimensionAuto,"isDimensionAuto");
	HX_STACK_ARG(computedPaddingsAndBordersDimension,"computedPaddingsAndBordersDimension");
	HX_STACK_ARG(isHorizontalMargin,"isHorizontalMargin");
	HX_STACK_LINE(453)
	Float usedMargin = (int)0;		HX_STACK_VAR(usedMargin,"usedMargin");
	HX_STACK_LINE(456)
	{
		::cocktail::core::css::CSSPropertyValue _switch_7 = (marginStyleValue);
		switch((_switch_7)->GetIndex()){
			case 18: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(460)
					usedMargin = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(464)
					if (((isDimensionAuto == true))){
						HX_STACK_LINE(468)
						usedMargin = 0.0;
					}
					else{
						HX_STACK_LINE(472)
						usedMargin = (containingHTMLElementDimension * ((value * 0.01)));
					}
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(479)
					if (((value != ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
						HX_STACK_LINE(480)
						hx::Throw (HX_CSTRING("Illegal keyword value for margin style"));
					}
					HX_STACK_LINE(483)
					usedMargin = this->getComputedAutoMargin(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsAndBordersDimension,isHorizontalMargin);
				}
			}
			;break;
			default: {
				HX_STACK_LINE(485)
				hx::Throw (HX_CSTRING("Illegal value for margin style"));
			}
		}
	}
	HX_STACK_LINE(490)
	return usedMargin;
}


HX_DEFINE_DYNAMIC_FUNC7(BoxStylesComputer_obj,getComputedMargin,return )

Float BoxStylesComputer_obj::getComputedMarginBottom( ::cocktail::core::css::CoreStyle style,Float computedHeight,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedMarginBottom","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",431);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(computedHeight,"computedHeight");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",432);
			{
				HX_STACK_LINE(432)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(432)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",432);
			{
				HX_STACK_LINE(432)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(432)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(431)
	return this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->height,computedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,getComputedMarginBottom,return )

Float BoxStylesComputer_obj::getComputedMarginTop( ::cocktail::core::css::CoreStyle style,Float computedHeight,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedMarginTop","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",423);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(computedHeight,"computedHeight");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",424);
			{
				HX_STACK_LINE(424)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(424)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",424);
			{
				HX_STACK_LINE(424)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(424)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(423)
	return this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->height,computedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,getComputedMarginTop,return )

Float BoxStylesComputer_obj::getComputedMarginRight( ::cocktail::core::css::CoreStyle style,Float computedWidth,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedMarginRight","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",415);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(computedWidth,"computedWidth");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",416);
			{
				HX_STACK_LINE(416)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(416)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",416);
			{
				HX_STACK_LINE(416)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(416)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(415)
	return this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width,computedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,getComputedMarginRight,return )

Float BoxStylesComputer_obj::getComputedMarginLeft( ::cocktail::core::css::CoreStyle style,Float computedWidth,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedMarginLeft","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",407);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(computedWidth,"computedWidth");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",408);
			{
				HX_STACK_LINE(408)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(408)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",408);
			{
				HX_STACK_LINE(408)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(408)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(407)
	return this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width,computedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,getComputedMarginLeft,return )

Float BoxStylesComputer_obj::getComputedAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedAutoHeight","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",396);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(396)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedAutoHeight,return )

Float BoxStylesComputer_obj::getComputedHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedHeight","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",386);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",387);
			{
				HX_STACK_LINE(387)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)16,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(387)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)16)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(386)
	return this->getComputedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)16)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),containingBlockData->height,containingBlockData->isHeightAuto);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedHeight,return )

Float BoxStylesComputer_obj::getComputedAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedAutoWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",374);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(374)
	return ((((((containingBlockData->width - style->usedValues->paddingLeft) - style->usedValues->paddingRight) - style->usedValues->borderLeftWidth) - style->usedValues->borderRightWidth) - style->usedValues->marginLeft) - style->usedValues->marginRight);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedAutoWidth,return )

Float BoxStylesComputer_obj::getComputedWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::getComputedWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",364);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",365);
			{
				HX_STACK_LINE(365)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)15,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(365)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)15)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(364)
	return this->getComputedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)15)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),containingBlockData->width,containingBlockData->isWidthAuto);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedWidth,return )

Float BoxStylesComputer_obj::measureHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::measureHeight","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",337);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(341)
	Float computedHeight = this->constrainHeight(style,this->getComputedHeight(style,containingBlockData));		HX_STACK_VAR(computedHeight,"computedHeight");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",344);
			{
				HX_STACK_LINE(344)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(344)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",344);
			{
				HX_STACK_LINE(344)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(344)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(344)
	style->usedValues->marginTop = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->height,computedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
	struct _Function_1_3{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",346);
			{
				HX_STACK_LINE(346)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(346)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",346);
			{
				HX_STACK_LINE(346)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(346)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(346)
	style->usedValues->marginBottom = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->height,computedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
	HX_STACK_LINE(348)
	return computedHeight;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureHeight,return )

Float BoxStylesComputer_obj::measureAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::measureAutoHeight","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",317);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(319)
	Float computedHeight = this->getComputedAutoHeight(style,containingBlockData);		HX_STACK_VAR(computedHeight,"computedHeight");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",322);
			{
				HX_STACK_LINE(322)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(322)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",322);
			{
				HX_STACK_LINE(322)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(322)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(322)
	style->usedValues->marginTop = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->height,computedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
	struct _Function_1_3{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",324);
			{
				HX_STACK_LINE(324)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)9,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(324)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) );
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",324);
			{
				HX_STACK_LINE(324)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)8,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(324)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(324)
	style->usedValues->marginBottom = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)9)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)8)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->height,computedHeight,style->hasAutoHeight,(((style->usedValues->paddingTop + style->usedValues->paddingBottom) + style->usedValues->borderTopWidth) + style->usedValues->borderBottomWidth),false);
	HX_STACK_LINE(326)
	return computedHeight;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureAutoHeight,return )

Float BoxStylesComputer_obj::measureHeightAndVerticalMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::measureHeightAndVerticalMargins","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",290);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(290)
	if (((style->hasAutoHeight == true))){
		HX_STACK_LINE(296)
		return this->measureAutoHeight(style,containingBlockData);
	}
	else{
		HX_STACK_LINE(300)
		return this->measureHeight(style,containingBlockData);
	}
	HX_STACK_LINE(290)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureHeightAndVerticalMargins,return )

Float BoxStylesComputer_obj::measureWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::measureWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",267);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(271)
	Float computedWidth = this->constrainWidth(style,this->getComputedWidth(style,containingBlockData));		HX_STACK_VAR(computedWidth,"computedWidth");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",274);
			{
				HX_STACK_LINE(274)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(274)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",274);
			{
				HX_STACK_LINE(274)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(274)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(274)
	style->usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width,computedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	struct _Function_1_3{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",276);
			{
				HX_STACK_LINE(276)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(276)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",276);
			{
				HX_STACK_LINE(276)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(276)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(276)
	style->usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->width,computedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	HX_STACK_LINE(278)
	return computedWidth;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureWidth,return )

Float BoxStylesComputer_obj::measureAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::measureAutoWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",227);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(230)
	Float usedWidth = 0.0;		HX_STACK_VAR(usedWidth,"usedWidth");
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",233);
			{
				HX_STACK_LINE(233)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(233)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",233);
			{
				HX_STACK_LINE(233)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(233)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(233)
	style->usedValues->marginLeft = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	struct _Function_1_3{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",235);
			{
				HX_STACK_LINE(235)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)7,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(235)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) );
			}
			return null();
		}
	};
	struct _Function_1_4{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",235);
			{
				HX_STACK_LINE(235)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)6,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(235)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(235)
	style->usedValues->marginRight = this->getComputedMargin((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)7)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),(  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)6)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->width,usedWidth,style->hasAutoWidth,(((style->usedValues->paddingRight + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth) + style->usedValues->borderRightWidth),true);
	HX_STACK_LINE(238)
	Float computedWidth = this->getComputedAutoWidth(style,containingBlockData);		HX_STACK_VAR(computedWidth,"computedWidth");
	HX_STACK_LINE(241)
	Float constrainedWidth = this->constrainWidth(style,computedWidth);		HX_STACK_VAR(constrainedWidth,"constrainedWidth");
	HX_STACK_LINE(244)
	if (((constrainedWidth != computedWidth))){
		HX_STACK_LINE(245)
		if (((bool(style->hasAutoMarginLeft) && bool(style->hasAutoMarginRight)))){
			HX_STACK_LINE(250)
			Float marginWidth = (Float(((((((containingBlockData->width - style->usedValues->paddingLeft) - style->usedValues->paddingRight) - style->usedValues->borderLeftWidth) - style->usedValues->borderRightWidth) - constrainedWidth))) / Float((int)2));		HX_STACK_VAR(marginWidth,"marginWidth");
			HX_STACK_LINE(252)
			style->usedValues->marginLeft = marginWidth;
			HX_STACK_LINE(253)
			style->usedValues->marginRight = marginWidth;
		}
	}
	HX_STACK_LINE(257)
	return computedWidth;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureAutoWidth,return )

Float BoxStylesComputer_obj::measureWidthAndHorizontalMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("BoxStylesComputer::measureWidthAndHorizontalMargins","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(206)
	if (((style->hasAutoWidth == true))){
		HX_STACK_LINE(208)
		return this->measureAutoWidth(style,containingBlockData);
	}
	else{
		HX_STACK_LINE(212)
		return this->measureWidth(style,containingBlockData);
	}
	HX_STACK_LINE(206)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureWidthAndHorizontalMargins,return )

Void BoxStylesComputer_obj::measureOutline( ::cocktail::core::css::CoreStyle style){
{
		HX_STACK_PUSH("BoxStylesComputer::measureOutline","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",193);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_LINE(193)
		style->usedValues->outlineWidth = this->getComputedBorderWidth(style->getComputedOrInitialProperty((int)82));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BoxStylesComputer_obj,measureOutline,(void))

Void BoxStylesComputer_obj::measureBordersWidth( ::cocktail::core::css::CoreStyle style){
{
		HX_STACK_PUSH("BoxStylesComputer::measureBordersWidth","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",178);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",179);
				{
					HX_STACK_LINE(179)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)65,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(179)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)65)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(179)
		style->usedValues->borderLeftWidth = this->getComputedBorderWidth((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)65)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)65)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ));
		struct _Function_1_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",181);
				{
					HX_STACK_LINE(181)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)62,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(181)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)62)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(181)
		style->usedValues->borderTopWidth = this->getComputedBorderWidth((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)62)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)62)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ));
		struct _Function_1_3{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",183);
				{
					HX_STACK_LINE(183)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)63,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(183)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)63)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(183)
		style->usedValues->borderRightWidth = this->getComputedBorderWidth((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)63)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)63)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ));
		struct _Function_1_4{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",185);
				{
					HX_STACK_LINE(185)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)64,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(185)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)64)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(185)
		style->usedValues->borderBottomWidth = this->getComputedBorderWidth((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)64)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)64)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BoxStylesComputer_obj,measureBordersWidth,(void))

Void BoxStylesComputer_obj::measurePaddings( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("BoxStylesComputer::measurePaddings","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",160);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",161);
				{
					HX_STACK_LINE(161)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)11,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(161)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)11)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(161)
		style->usedValues->paddingLeft = this->getComputedPadding((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)11)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)11)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),containingBlockData->width);
		struct _Function_1_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",163);
				{
					HX_STACK_LINE(163)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)12,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(163)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)12)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(163)
		style->usedValues->paddingRight = this->getComputedPadding((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)12)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)12)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width);
		struct _Function_1_3{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",165);
				{
					HX_STACK_LINE(165)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)13,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(165)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)13)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(165)
		style->usedValues->paddingTop = this->getComputedPadding((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)13)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)13)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),containingBlockData->width);
		struct _Function_1_4{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",167);
				{
					HX_STACK_LINE(167)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)14,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(167)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)14)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(167)
		style->usedValues->paddingBottom = this->getComputedPadding((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)14)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)14)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->width);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measurePaddings,(void))

Void BoxStylesComputer_obj::measureDimensionsAndMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("BoxStylesComputer::measureDimensionsAndMargins","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",144);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_LINE(146)
		style->usedValues->width = this->constrainWidth(style,this->measureWidthAndHorizontalMargins(style,containingBlockData));
		HX_STACK_LINE(148)
		style->usedValues->height = this->constrainHeight(style,this->measureHeightAndVerticalMargins(style,containingBlockData));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureDimensionsAndMargins,(void))

Void BoxStylesComputer_obj::measurePositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("BoxStylesComputer::measurePositionOffsets","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",125);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",127);
				{
					HX_STACK_LINE(127)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)22,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(127)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(127)
		style->usedValues->left = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)22)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),containingBlockData->width);
		struct _Function_1_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",130);
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
		style->usedValues->right = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)23)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->width);
		struct _Function_1_3{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",133);
				{
					HX_STACK_LINE(133)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)21,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(133)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(133)
		style->usedValues->top = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)21)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),containingBlockData->height);
		struct _Function_1_4{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",136);
				{
					HX_STACK_LINE(136)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)24,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(136)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(136)
		style->usedValues->bottom = this->getComputedPositionOffset((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)24)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measurePositionOffsets,(void))

Void BoxStylesComputer_obj::measureDimensionsConstraints( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("BoxStylesComputer::measureDimensionsConstraints","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",105);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",107);
				{
					HX_STACK_LINE(107)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)18,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(107)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)18)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(107)
		style->usedValues->maxHeight = this->getComputedConstrainedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)18)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)18)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ),containingBlockData->height,containingBlockData->isHeightAuto,null());
		struct _Function_1_2{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",110);
				{
					HX_STACK_LINE(110)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)17,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(110)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)17)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(110)
		style->usedValues->minHeight = this->getComputedConstrainedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)17)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)17)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_2::Block(style)) )) ),containingBlockData->height,containingBlockData->isHeightAuto,true);
		struct _Function_1_3{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",113);
				{
					HX_STACK_LINE(113)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)20,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(113)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)20)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(113)
		style->usedValues->maxWidth = this->getComputedConstrainedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)20)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)20)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_3::Block(style)) )) ),containingBlockData->width,containingBlockData->isWidthAuto,null());
		struct _Function_1_4{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
				HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",116);
				{
					HX_STACK_LINE(116)
					::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)19,style);		HX_STACK_VAR(transition,"transition");
					HX_STACK_LINE(116)
					return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)19)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(116)
		style->usedValues->minWidth = this->getComputedConstrainedDimension((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)19)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)19)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_4::Block(style)) )) ),containingBlockData->width,containingBlockData->isWidthAuto,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureDimensionsConstraints,(void))

Void BoxStylesComputer_obj::measure( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
{
		HX_STACK_PUSH("BoxStylesComputer::measure","cocktail/core/layout/computer/boxComputers/BoxStylesComputer.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(containingBlockData,"containingBlockData");
		HX_STACK_LINE(62)
		this->measurePaddings(style,containingBlockData);
		HX_STACK_LINE(64)
		this->measureBordersWidth(style);
		HX_STACK_LINE(66)
		this->measureOutline(style);
		HX_STACK_LINE(72)
		this->measureDimensionsConstraints(style,containingBlockData);
		HX_STACK_LINE(76)
		this->measureDimensionsAndMargins(style,containingBlockData);
		HX_STACK_LINE(81)
		if (((style->isPositioned == true))){
			HX_STACK_LINE(82)
			this->measurePositionOffsets(style,containingBlockData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measure,(void))


BoxStylesComputer_obj::BoxStylesComputer_obj()
{
}

void BoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoxStylesComputer);
	HX_MARK_END_CLASS();
}

void BoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"measure") ) { return measure_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"measureWidth") ) { return measureWidth_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"measureHeight") ) { return measureHeight_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"constrainWidth") ) { return constrainWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"measureOutline") ) { return measureOutline_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"constrainHeight") ) { return constrainHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"measurePaddings") ) { return measurePaddings_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getComputedWidth") ) { return getComputedWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"measureAutoWidth") ) { return measureAutoWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getComputedMargin") ) { return getComputedMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedHeight") ) { return getComputedHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"measureAutoHeight") ) { return measureAutoHeight_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getComputedPadding") ) { return getComputedPadding_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"measureBordersWidth") ) { return measureBordersWidth_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedDimension") ) { return getComputedDimension_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginTop") ) { return getComputedMarginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedAutoWidth") ) { return getComputedAutoWidth_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginLeft") ) { return getComputedMarginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedAutoHeight") ) { return getComputedAutoHeight_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getComputedBorderWidth") ) { return getComputedBorderWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginRight") ) { return getComputedMarginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"measurePositionOffsets") ) { return measurePositionOffsets_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getComputedMarginBottom") ) { return getComputedMarginBottom_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getComputedPositionOffset") ) { return getComputedPositionOffset_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"measureDimensionsAndMargins") ) { return measureDimensionsAndMargins_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"measureDimensionsConstraints") ) { return measureDimensionsConstraints_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"getComputedConstrainedDimension") ) { return getComputedConstrainedDimension_dyn(); }
		if (HX_FIELD_EQ(inName,"measureHeightAndVerticalMargins") ) { return measureHeightAndVerticalMargins_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"measureWidthAndHorizontalMargins") ) { return measureWidthAndHorizontalMargins_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("constrainHeight"),
	HX_CSTRING("constrainWidth"),
	HX_CSTRING("getComputedBorderWidth"),
	HX_CSTRING("getComputedPadding"),
	HX_CSTRING("getComputedDimension"),
	HX_CSTRING("getComputedPositionOffset"),
	HX_CSTRING("getComputedConstrainedDimension"),
	HX_CSTRING("getComputedAutoMargin"),
	HX_CSTRING("getComputedMargin"),
	HX_CSTRING("getComputedMarginBottom"),
	HX_CSTRING("getComputedMarginTop"),
	HX_CSTRING("getComputedMarginRight"),
	HX_CSTRING("getComputedMarginLeft"),
	HX_CSTRING("getComputedAutoHeight"),
	HX_CSTRING("getComputedHeight"),
	HX_CSTRING("getComputedAutoWidth"),
	HX_CSTRING("getComputedWidth"),
	HX_CSTRING("measureHeight"),
	HX_CSTRING("measureAutoHeight"),
	HX_CSTRING("measureHeightAndVerticalMargins"),
	HX_CSTRING("measureWidth"),
	HX_CSTRING("measureAutoWidth"),
	HX_CSTRING("measureWidthAndHorizontalMargins"),
	HX_CSTRING("measureOutline"),
	HX_CSTRING("measureBordersWidth"),
	HX_CSTRING("measurePaddings"),
	HX_CSTRING("measureDimensionsAndMargins"),
	HX_CSTRING("measurePositionOffsets"),
	HX_CSTRING("measureDimensionsConstraints"),
	HX_CSTRING("measure"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoxStylesComputer_obj::__mClass,"__mClass");
};

Class BoxStylesComputer_obj::__mClass;

void BoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.BoxStylesComputer"), hx::TCanCast< BoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
