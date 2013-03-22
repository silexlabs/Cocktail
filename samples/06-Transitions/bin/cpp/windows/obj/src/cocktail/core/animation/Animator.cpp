#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_Animator
#include <cocktail/core/animation/Animator.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_PendingAnimationVO
#include <cocktail/core/animation/PendingAnimationVO.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSConstants
#include <cocktail/core/css/CSSConstants.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTimeValue
#include <cocktail/core/css/CSSTimeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace animation{

Void Animator_obj::__construct()
{
HX_STACK_PUSH("Animator::new","cocktail/core/animation/Animator.hx",52);
{
}
;
	return null();
}

Animator_obj::~Animator_obj() { }

Dynamic Animator_obj::__CreateEmpty() { return  new Animator_obj; }
hx::ObjectPtr< Animator_obj > Animator_obj::__new()
{  hx::ObjectPtr< Animator_obj > result = new Animator_obj();
	result->__construct();
	return result;}

Dynamic Animator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Animator_obj > result = new Animator_obj();
	result->__construct();
	return result;}

Void Animator_obj::onTransitionUpdate( ::cocktail::core::animation::Transition transition){
{
		HX_STACK_PUSH("Animator::onTransitionUpdate","cocktail/core/animation/Animator.hx",463);
		HX_STACK_THIS(this);
		HX_STACK_ARG(transition,"transition");
		HX_STACK_LINE(463)
		this->onTransitionUpdateCallback(transition);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animator_obj,onTransitionUpdate,(void))

Void Animator_obj::onTransitionComplete( ::cocktail::core::animation::Transition transition){
{
		HX_STACK_PUSH("Animator::onTransitionComplete","cocktail/core/animation/Animator.hx",453);
		HX_STACK_THIS(this);
		HX_STACK_ARG(transition,"transition");
		HX_STACK_LINE(453)
		this->onTransitionCompleteCallback(transition);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animator_obj,onTransitionComplete,(void))

int Animator_obj::getRepeatedIndex( int index,int length){
	HX_STACK_PUSH("Animator::getRepeatedIndex","cocktail/core/animation/Animator.hx",434);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_ARG(length,"length");
	HX_STACK_LINE(435)
	if (((index < length))){
		HX_STACK_LINE(436)
		return index;
	}
	else{
		HX_STACK_LINE(439)
		if (((length == (int)1))){
			HX_STACK_LINE(440)
			return (int)0;
		}
	}
	HX_STACK_LINE(445)
	return hx::Mod(length,index);
}


HX_DEFINE_DYNAMIC_FUNC2(Animator_obj,getRepeatedIndex,return )

Float Animator_obj::getTransitionDelayOrDurationAsFloat( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("Animator::getTransitionDelayOrDurationAsFloat","cocktail/core/animation/Animator.hx",399);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(400)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (value);
		switch((_switch_1)->GetIndex()){
			case 0: {
				int value1 = _switch_1->__Param(0);
{
					HX_STACK_LINE(402)
					return value1;
				}
			}
			;break;
			case 9: {
				::cocktail::core::css::CSSTimeValue value1 = _switch_1->__Param(0);
{
					HX_STACK_LINE(405)
					{
						::cocktail::core::css::CSSTimeValue _switch_2 = (value1);
						switch((_switch_2)->GetIndex()){
							case 1: {
								Float value2 = _switch_2->__Param(0);
{
									HX_STACK_LINE(408)
									return value2;
								}
							}
							;break;
							case 0: {
								Float value2 = _switch_2->__Param(0);
{
									HX_STACK_LINE(411)
									return (value2 * (int)1000);
								}
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
	HX_STACK_LINE(420)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(Animator_obj,getTransitionDelayOrDurationAsFloat,return )

Array< Float > Animator_obj::getAsFloatArray( ::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("Animator::getAsFloatArray","cocktail/core/animation/Animator.hx",376);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(377)
	Array< Float > floats = Array_obj< Float >::__new();		HX_STACK_VAR(floats,"floats");
	HX_STACK_LINE(379)
	{
		::cocktail::core::css::CSSPropertyValue _switch_3 = (value);
		switch((_switch_3)->GetIndex()){
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value1 = _switch_3->__Param(0);
{
					HX_STACK_LINE(382)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = value1->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(382)
					while(((_g1 < _g))){
						HX_STACK_LINE(382)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(384)
						floats->push(this->getTransitionDelayOrDurationAsFloat(value1->__get(i)));
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(387)
				floats->push(this->getTransitionDelayOrDurationAsFloat(value));
			}
		}
	}
	HX_STACK_LINE(391)
	return floats;
}


HX_DEFINE_DYNAMIC_FUNC1(Animator_obj,getAsFloatArray,return )

Array< ::cocktail::core::css::CSSPropertyValue > Animator_obj::getTransitionTimingFunctionsAsArray( ::cocktail::core::css::CSSPropertyValue transitionTimingFunction){
	HX_STACK_PUSH("Animator::getTransitionTimingFunctionsAsArray","cocktail/core/animation/Animator.hx",356);
	HX_STACK_THIS(this);
	HX_STACK_ARG(transitionTimingFunction,"transitionTimingFunction");
	HX_STACK_LINE(356)
	{
		::cocktail::core::css::CSSPropertyValue _switch_4 = (transitionTimingFunction);
		switch((_switch_4)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_4->__Param(0);
{
					HX_STACK_LINE(359)
					return Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(transitionTimingFunction);
				}
			}
			;break;
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_4->__Param(0);
{
					HX_STACK_LINE(362)
					return value;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(365)
				return null();
			}
		}
	}
	HX_STACK_LINE(356)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animator_obj,getTransitionTimingFunctionsAsArray,return )

Float Animator_obj::getEndValue( ::cocktail::core::css::CoreStyle style,int propertyIndex){
	HX_STACK_PUSH("Animator::getEndValue","cocktail/core/animation/Animator.hx",330);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(330)
	switch( (int)(propertyIndex)){
		case (int)53: {
			struct _Function_2_1{
				inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
					HX_STACK_PUSH("*::closure","cocktail/core/animation/Animator.hx",334);
					{
						HX_STACK_LINE(334)
						::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)53,style);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(334)
						return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)53)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(333)
			{
				::cocktail::core::css::CSSPropertyValue _switch_5 = ((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)53)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(style)) )) ));
				switch((_switch_5)->GetIndex()){
					case 1: {
						Float value = _switch_5->__Param(0);
{
							HX_STACK_LINE(336)
							return value;
						}
					}
					;break;
					case 18: {
						Float value = _switch_5->__Param(0);
{
							HX_STACK_LINE(339)
							return value;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(342)
						return (int)0;
					}
				}
			}
		}
		;break;
		default: {
			HX_STACK_LINE(346)
			return ::Reflect_obj::field(style->usedValues,::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(propertyIndex));
		}
	}
	HX_STACK_LINE(330)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC2(Animator_obj,getEndValue,return )

int Animator_obj::getIndexOfPropertyInTransitionProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue transitionProperty){
	HX_STACK_PUSH("Animator::getIndexOfPropertyInTransitionProperty","cocktail/core/animation/Animator.hx",261);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(transitionProperty,"transitionProperty");
	HX_STACK_LINE(261)
	{
		::cocktail::core::css::CSSPropertyValue _switch_6 = (transitionProperty);
		switch((_switch_6)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_6->__Param(0);
{
					HX_STACK_LINE(265)
					{
						::cocktail::core::css::CSSKeywordValue _switch_7 = (value);
						switch((_switch_7)->GetIndex()){
							case 18: {
								HX_STACK_LINE(270)
								return (int)-1;
							}
							;break;
							case 48: {
								HX_STACK_LINE(275)
								return (int)0;
							}
							;break;
							default: {
								HX_STACK_LINE(278)
								hx::Throw (HX_CSTRING("Illegal keyword value for transition property"));
							}
						}
					}
				}
			}
			;break;
			case 3: {
				::String value = _switch_6->__Param(0);
{
					HX_STACK_LINE(282)
					if (((value != ::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(propertyIndex)))){
						HX_STACK_LINE(286)
						return (int)-1;
					}
					else{
						HX_STACK_LINE(290)
						return (int)0;
					}
				}
			}
			;break;
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_6->__Param(0);
{
					HX_STACK_LINE(297)
					bool foundFlag = false;		HX_STACK_VAR(foundFlag,"foundFlag");
					HX_STACK_LINE(299)
					{
						HX_STACK_LINE(299)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						int _g = value->length;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(299)
						while(((_g1 < _g))){
							HX_STACK_LINE(299)
							int i = (_g1)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(301)
							{
								::cocktail::core::css::CSSPropertyValue _switch_8 = (value->__get(i));
								switch((_switch_8)->GetIndex()){
									case 3: {
										::String value1 = _switch_8->__Param(0);
{
											HX_STACK_LINE(303)
											if (((value1 == ::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(propertyIndex)))){
												HX_STACK_LINE(307)
												return i;
											}
										}
									}
									;break;
									default: {
										HX_STACK_LINE(311)
										hx::Throw (HX_CSTRING("Illegal value for transition property"));
									}
								}
							}
						}
					}
					HX_STACK_LINE(317)
					return (int)-1;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(319)
				hx::Throw (HX_CSTRING("Illegal values for transition property style"));
			}
		}
	}
	HX_STACK_LINE(261)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(Animator_obj,getIndexOfPropertyInTransitionProperty,return )

bool Animator_obj::startTransitionIfNeeded( ::cocktail::core::animation::PendingAnimationVO pendingAnimation,::cocktail::core::css::CoreStyle style){
	HX_STACK_PUSH("Animator::startTransitionIfNeeded","cocktail/core/animation/Animator.hx",178);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pendingAnimation,"pendingAnimation");
	HX_STACK_ARG(style,"style");
	HX_STACK_LINE(179)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(184)
	int indexInTransitionProperty = this->getIndexOfPropertyInTransitionProperty(pendingAnimation->propertyIndex,style->getComputedOrInitialProperty((int)57));		HX_STACK_VAR(indexInTransitionProperty,"indexInTransitionProperty");
	HX_STACK_LINE(188)
	if (((indexInTransitionProperty == (int)-1))){
		HX_STACK_LINE(189)
		return false;
	}
	HX_STACK_LINE(195)
	Float combinedDuration = 0.0;		HX_STACK_VAR(combinedDuration,"combinedDuration");
	HX_STACK_LINE(199)
	Array< Float > transitionDelays = this->getAsFloatArray(style->getComputedOrInitialProperty((int)56));		HX_STACK_VAR(transitionDelays,"transitionDelays");
	HX_STACK_LINE(200)
	Array< Float > transitionDurations = this->getAsFloatArray(style->getComputedOrInitialProperty((int)55));		HX_STACK_VAR(transitionDurations,"transitionDurations");
	HX_STACK_LINE(205)
	Float transitionDelay = transitionDelays->__get(this->getRepeatedIndex(indexInTransitionProperty,transitionDelays->length));		HX_STACK_VAR(transitionDelay,"transitionDelay");
	HX_STACK_LINE(206)
	Float transitionDuration = transitionDurations->__get(this->getRepeatedIndex(indexInTransitionProperty,transitionDurations->length));		HX_STACK_VAR(transitionDuration,"transitionDuration");
	HX_STACK_LINE(207)
	combinedDuration = (transitionDuration + transitionDelay);
	HX_STACK_LINE(211)
	if (((combinedDuration <= (int)0))){
		HX_STACK_LINE(212)
		return false;
	}
	HX_STACK_LINE(216)
	Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunctionAsArray = this->getTransitionTimingFunctionsAsArray(style->getComputedOrInitialProperty((int)58));		HX_STACK_VAR(transitionTimingFunctionAsArray,"transitionTimingFunctionAsArray");
	HX_STACK_LINE(219)
	::cocktail::core::css::CSSPropertyValue transitionTimingFunction = transitionTimingFunctionAsArray->__get(this->getRepeatedIndex(indexInTransitionProperty,transitionTimingFunctionAsArray->length));		HX_STACK_VAR(transitionTimingFunction,"transitionTimingFunction");
	HX_STACK_LINE(221)
	::cocktail::core::animation::TransitionManager transitionManager = ::cocktail::core::animation::TransitionManager_obj::getInstance();		HX_STACK_VAR(transitionManager,"transitionManager");
	HX_STACK_LINE(224)
	::cocktail::core::animation::Transition transition = transitionManager->getTransition(pendingAnimation->propertyIndex,style);		HX_STACK_VAR(transition,"transition");
	HX_STACK_LINE(228)
	if (((transition != null()))){
		HX_STACK_LINE(229)
		return false;
	}
	HX_STACK_LINE(242)
	Float endValue = this->getEndValue(style,pendingAnimation->propertyIndex);		HX_STACK_VAR(endValue,"endValue");
	HX_STACK_LINE(245)
	transitionManager->startTransition(style,pendingAnimation->propertyIndex,pendingAnimation->startValue,endValue,transitionDuration,transitionDelay,transitionTimingFunction,this->onTransitionComplete_dyn(),this->onTransitionUpdate_dyn());
	HX_STACK_LINE(249)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(Animator_obj,startTransitionIfNeeded,return )

bool Animator_obj::revertTransitionIfNeeded( ::cocktail::core::animation::Transition currentTransition,Float currentValue,::cocktail::core::css::CoreStyle style){
	HX_STACK_PUSH("Animator::revertTransitionIfNeeded","cocktail/core/animation/Animator.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_ARG(currentTransition,"currentTransition");
	HX_STACK_ARG(currentValue,"currentValue");
	HX_STACK_ARG(style,"style");
	HX_STACK_LINE(125)
	if (((currentTransition->startValue != currentValue))){
		HX_STACK_LINE(126)
		return false;
	}
	HX_STACK_LINE(132)
	int indexInTransitionProperty = this->getIndexOfPropertyInTransitionProperty(currentTransition->propertyIndex,style->getComputedOrInitialProperty((int)57));		HX_STACK_VAR(indexInTransitionProperty,"indexInTransitionProperty");
	HX_STACK_LINE(133)
	if (((indexInTransitionProperty == (int)-1))){
		HX_STACK_LINE(134)
		return false;
	}
	HX_STACK_LINE(138)
	Array< Float > transitionDelays = this->getAsFloatArray(style->getComputedOrInitialProperty((int)56));		HX_STACK_VAR(transitionDelays,"transitionDelays");
	HX_STACK_LINE(139)
	Float transitionDelay = transitionDelays->__get(this->getRepeatedIndex(indexInTransitionProperty,transitionDelays->length));		HX_STACK_VAR(transitionDelay,"transitionDelay");
	HX_STACK_LINE(140)
	if (((currentTransition->transitionDelay != transitionDelay))){
		HX_STACK_LINE(141)
		return false;
	}
	HX_STACK_LINE(145)
	Array< Float > transitionDurations = this->getAsFloatArray(style->getComputedOrInitialProperty((int)55));		HX_STACK_VAR(transitionDurations,"transitionDurations");
	HX_STACK_LINE(146)
	Float transitionDuration = transitionDurations->__get(this->getRepeatedIndex(indexInTransitionProperty,transitionDurations->length));		HX_STACK_VAR(transitionDuration,"transitionDuration");
	HX_STACK_LINE(147)
	if (((currentTransition->transitionDuration != transitionDuration))){
		HX_STACK_LINE(148)
		return false;
	}
	HX_STACK_LINE(152)
	Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunctionAsArray = this->getTransitionTimingFunctionsAsArray(style->getComputedOrInitialProperty((int)58));		HX_STACK_VAR(transitionTimingFunctionAsArray,"transitionTimingFunctionAsArray");
	HX_STACK_LINE(153)
	::cocktail::core::css::CSSPropertyValue transitionTimingFunction = transitionTimingFunctionAsArray->__get(this->getRepeatedIndex(indexInTransitionProperty,transitionTimingFunctionAsArray->length));		HX_STACK_VAR(transitionTimingFunction,"transitionTimingFunction");
	HX_STACK_LINE(154)
	if (((currentTransition->transitionTimingFunction != transitionTimingFunction))){
		HX_STACK_LINE(155)
		return false;
	}
	HX_STACK_LINE(160)
	currentTransition->revert();
	HX_STACK_LINE(161)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(Animator_obj,revertTransitionIfNeeded,return )

Void Animator_obj::registerPendingAnimation( int propertyIndex,Float startValue){
{
		HX_STACK_PUSH("Animator::registerPendingAnimation","cocktail/core/animation/Animator.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(startValue,"startValue");
		HX_STACK_LINE(103)
		::cocktail::core::animation::PendingAnimationVO pendingAnimation = ::cocktail::core::animation::PendingAnimationVO_obj::__new();		HX_STACK_VAR(pendingAnimation,"pendingAnimation");
		HX_STACK_LINE(104)
		pendingAnimation->propertyIndex = propertyIndex;
		HX_STACK_LINE(105)
		pendingAnimation->startValue = startValue;
		HX_STACK_LINE(106)
		if (((this->_pendingAnimations == null()))){
			HX_STACK_LINE(107)
			this->_pendingAnimations = Array_obj< ::cocktail::core::animation::PendingAnimationVO >::__new();
		}
		HX_STACK_LINE(110)
		this->_pendingAnimations->push(pendingAnimation);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Animator_obj,registerPendingAnimation,(void))

bool Animator_obj::startPendingAnimations( ::cocktail::core::css::CoreStyle style){
	HX_STACK_PUSH("Animator::startPendingAnimations","cocktail/core/animation/Animator.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_LINE(68)
	if (((this->_pendingAnimations == null()))){
		HX_STACK_LINE(69)
		return false;
	}
	HX_STACK_LINE(73)
	bool atLeastOneAnimationStarted = false;		HX_STACK_VAR(atLeastOneAnimationStarted,"atLeastOneAnimationStarted");
	HX_STACK_LINE(75)
	int length = this->_pendingAnimations->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(76)
	{
		HX_STACK_LINE(76)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(76)
		while(((_g < length))){
			HX_STACK_LINE(76)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(78)
			bool animationStarted = this->startTransitionIfNeeded(this->_pendingAnimations->__get(i),style);		HX_STACK_VAR(animationStarted,"animationStarted");
			HX_STACK_LINE(79)
			if (((animationStarted == true))){
				HX_STACK_LINE(80)
				atLeastOneAnimationStarted = true;
			}
		}
	}
	HX_STACK_LINE(87)
	this->_pendingAnimations = ::cocktail::core::utils::Utils_obj::clear(this->_pendingAnimations);
	HX_STACK_LINE(89)
	return atLeastOneAnimationStarted;
}


HX_DEFINE_DYNAMIC_FUNC1(Animator_obj,startPendingAnimations,return )


Animator_obj::Animator_obj()
{
}

void Animator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Animator);
	HX_MARK_MEMBER_NAME(onTransitionUpdateCallback,"onTransitionUpdateCallback");
	HX_MARK_MEMBER_NAME(onTransitionCompleteCallback,"onTransitionCompleteCallback");
	HX_MARK_MEMBER_NAME(_pendingAnimations,"_pendingAnimations");
	HX_MARK_END_CLASS();
}

void Animator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(onTransitionUpdateCallback,"onTransitionUpdateCallback");
	HX_VISIT_MEMBER_NAME(onTransitionCompleteCallback,"onTransitionCompleteCallback");
	HX_VISIT_MEMBER_NAME(_pendingAnimations,"_pendingAnimations");
}

Dynamic Animator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"getEndValue") ) { return getEndValue_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getAsFloatArray") ) { return getAsFloatArray_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getRepeatedIndex") ) { return getRepeatedIndex_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onTransitionUpdate") ) { return onTransitionUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"_pendingAnimations") ) { return _pendingAnimations; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"onTransitionComplete") ) { return onTransitionComplete_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"startPendingAnimations") ) { return startPendingAnimations_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"startTransitionIfNeeded") ) { return startTransitionIfNeeded_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"revertTransitionIfNeeded") ) { return revertTransitionIfNeeded_dyn(); }
		if (HX_FIELD_EQ(inName,"registerPendingAnimation") ) { return registerPendingAnimation_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"onTransitionUpdateCallback") ) { return onTransitionUpdateCallback; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"onTransitionCompleteCallback") ) { return onTransitionCompleteCallback; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"getTransitionDelayOrDurationAsFloat") ) { return getTransitionDelayOrDurationAsFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"getTransitionTimingFunctionsAsArray") ) { return getTransitionTimingFunctionsAsArray_dyn(); }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"getIndexOfPropertyInTransitionProperty") ) { return getIndexOfPropertyInTransitionProperty_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Animator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"_pendingAnimations") ) { _pendingAnimations=inValue.Cast< Array< ::cocktail::core::animation::PendingAnimationVO > >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"onTransitionUpdateCallback") ) { onTransitionUpdateCallback=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"onTransitionCompleteCallback") ) { onTransitionCompleteCallback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Animator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_pendingAnimations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onTransitionUpdate"),
	HX_CSTRING("onTransitionComplete"),
	HX_CSTRING("getRepeatedIndex"),
	HX_CSTRING("getTransitionDelayOrDurationAsFloat"),
	HX_CSTRING("getAsFloatArray"),
	HX_CSTRING("getTransitionTimingFunctionsAsArray"),
	HX_CSTRING("getEndValue"),
	HX_CSTRING("getIndexOfPropertyInTransitionProperty"),
	HX_CSTRING("startTransitionIfNeeded"),
	HX_CSTRING("revertTransitionIfNeeded"),
	HX_CSTRING("registerPendingAnimation"),
	HX_CSTRING("startPendingAnimations"),
	HX_CSTRING("onTransitionUpdateCallback"),
	HX_CSTRING("onTransitionCompleteCallback"),
	HX_CSTRING("_pendingAnimations"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Animator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Animator_obj::__mClass,"__mClass");
};

Class Animator_obj::__mClass;

void Animator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.animation.Animator"), hx::TCanCast< Animator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Animator_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace animation
