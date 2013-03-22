#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
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
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
#endif
namespace cocktail{
namespace core{
namespace animation{

Void TransitionManager_obj::__construct()
{
HX_STACK_PUSH("TransitionManager::new","cocktail/core/animation/TransitionManager.hx",90);
{
	HX_STACK_LINE(91)
	this->initTransitions();
	HX_STACK_LINE(92)
	this->_currentTransitionsNumber = (int)0;
	HX_STACK_LINE(93)
	this->hasTransitionsInProgress = false;
	HX_STACK_LINE(94)
	this->_lastTick = (int)0;
}
;
	return null();
}

TransitionManager_obj::~TransitionManager_obj() { }

Dynamic TransitionManager_obj::__CreateEmpty() { return  new TransitionManager_obj; }
hx::ObjectPtr< TransitionManager_obj > TransitionManager_obj::__new()
{  hx::ObjectPtr< TransitionManager_obj > result = new TransitionManager_obj();
	result->__construct();
	return result;}

Dynamic TransitionManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransitionManager_obj > result = new TransitionManager_obj();
	result->__construct();
	return result;}

Void TransitionManager_obj::onTransitionTick( Float timeStamp){
{
		HX_STACK_PUSH("TransitionManager::onTransitionTick","cocktail/core/animation/TransitionManager.hx",238);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timeStamp,"timeStamp");
		HX_STACK_LINE(241)
		Float interval = (timeStamp - this->_lastTick);		HX_STACK_VAR(interval,"interval");
		HX_STACK_LINE(245)
		this->_lastTick = timeStamp;
		HX_STACK_LINE(247)
		int transitionsLength = this->_transitions->length;		HX_STACK_VAR(transitionsLength,"transitionsLength");
		HX_STACK_LINE(249)
		{
			HX_STACK_LINE(249)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(249)
			while(((_g < transitionsLength))){
				HX_STACK_LINE(249)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(254)
				Array< ::cocktail::core::animation::Transition > completedTransitions = Array_obj< ::cocktail::core::animation::Transition >::__new();		HX_STACK_VAR(completedTransitions,"completedTransitions");
				HX_STACK_LINE(256)
				Array< ::cocktail::core::animation::Transition > transitionsForProperty = this->_transitions->__get(i);		HX_STACK_VAR(transitionsForProperty,"transitionsForProperty");
				HX_STACK_LINE(257)
				int length = transitionsForProperty->length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(258)
				{
					HX_STACK_LINE(258)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(258)
					while(((_g1 < length))){
						HX_STACK_LINE(258)
						int j = (_g1)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(260)
						::cocktail::core::animation::Transition transition = transitionsForProperty->__get(j);		HX_STACK_VAR(transition,"transition");
						HX_STACK_LINE(265)
						transition->updateTime(interval);
						HX_STACK_LINE(268)
						if (((transition->get_complete() == true))){
							HX_STACK_LINE(271)
							transition->onComplete(transition);
							HX_STACK_LINE(274)
							completedTransitions->push(transition);
						}
						else{
							HX_STACK_LINE(277)
							transition->onUpdate(transition);
						}
					}
				}
				HX_STACK_LINE(284)
				int completedTransitionsLength = completedTransitions->length;		HX_STACK_VAR(completedTransitionsLength,"completedTransitionsLength");
				HX_STACK_LINE(285)
				{
					HX_STACK_LINE(285)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(285)
					while(((_g1 < completedTransitionsLength))){
						HX_STACK_LINE(285)
						int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(287)
						this->stopTransition(completedTransitions->__get(i1));
					}
				}
			}
		}
		HX_STACK_LINE(293)
		if (((this->_currentTransitionsNumber > (int)0))){
			HX_STACK_LINE(294)
			::cocktail::Lib_obj::get_document()->timer->delay(this->onTransitionTick_dyn(),null());
		}
		else{
			HX_STACK_LINE(298)
			this->hasTransitionsInProgress = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TransitionManager_obj,onTransitionTick,(void))

Void TransitionManager_obj::startTransitionUpdate( ){
{
		HX_STACK_PUSH("TransitionManager::startTransitionUpdate","cocktail/core/animation/TransitionManager.hx",221);
		HX_STACK_THIS(this);
		HX_STACK_LINE(225)
		this->_lastTick = ::Date_obj::now()->getTime();
		HX_STACK_LINE(229)
		::cocktail::Lib_obj::get_document()->timer->delay(this->onTransitionTick_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransitionManager_obj,startTransitionUpdate,(void))

Array< ::cocktail::core::animation::Transition > TransitionManager_obj::getTransitionsForProperty( int propertyIndex){
	HX_STACK_PUSH("TransitionManager::getTransitionsForProperty","cocktail/core/animation/TransitionManager.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(213)
	return this->_transitions->__get(propertyIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(TransitionManager_obj,getTransitionsForProperty,return )

Void TransitionManager_obj::stopTransition( ::cocktail::core::animation::Transition transition){
{
		HX_STACK_PUSH("TransitionManager::stopTransition","cocktail/core/animation/TransitionManager.hx",191);
		HX_STACK_THIS(this);
		HX_STACK_ARG(transition,"transition");
		HX_STACK_LINE(193)
		Array< ::cocktail::core::animation::Transition > propertyTransitions = this->_transitions->__get(transition->propertyIndex);		HX_STACK_VAR(propertyTransitions,"propertyTransitions");
		HX_STACK_LINE(194)
		propertyTransitions->remove(transition);
		HX_STACK_LINE(196)
		transition->dispose();
		HX_STACK_LINE(201)
		(this->_currentTransitionsNumber)--;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TransitionManager_obj,stopTransition,(void))

Void TransitionManager_obj::startTransition( ::cocktail::core::css::CoreStyle target,int propertyIndex,Float startValue,Float endValue,Float transitionDuration,Float transitionDelay,::cocktail::core::css::CSSPropertyValue transitionTimingFunction,Dynamic onComplete,Dynamic onUpdate){
{
		HX_STACK_PUSH("TransitionManager::startTransition","cocktail/core/animation/TransitionManager.hx",163);
		HX_STACK_THIS(this);
		HX_STACK_ARG(target,"target");
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(startValue,"startValue");
		HX_STACK_ARG(endValue,"endValue");
		HX_STACK_ARG(transitionDuration,"transitionDuration");
		HX_STACK_ARG(transitionDelay,"transitionDelay");
		HX_STACK_ARG(transitionTimingFunction,"transitionTimingFunction");
		HX_STACK_ARG(onComplete,"onComplete");
		HX_STACK_ARG(onUpdate,"onUpdate");
		HX_STACK_LINE(165)
		::cocktail::core::animation::Transition transition = ::cocktail::core::animation::Transition_obj::__new(propertyIndex,target,transitionDuration,transitionDelay,transitionTimingFunction,startValue,endValue,onComplete,onUpdate);		HX_STACK_VAR(transition,"transition");
		HX_STACK_LINE(169)
		Array< ::cocktail::core::animation::Transition > transitionsForProperty = this->_transitions->__get(propertyIndex);		HX_STACK_VAR(transitionsForProperty,"transitionsForProperty");
		HX_STACK_LINE(171)
		transitionsForProperty->push(transition);
		HX_STACK_LINE(176)
		if (((this->_currentTransitionsNumber == (int)0))){
			HX_STACK_LINE(178)
			this->startTransitionUpdate();
			HX_STACK_LINE(179)
			this->hasTransitionsInProgress = true;
		}
		HX_STACK_LINE(183)
		(this->_currentTransitionsNumber)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(TransitionManager_obj,startTransition,(void))

::cocktail::core::animation::Transition TransitionManager_obj::getTransition( int propertyIndex,::cocktail::core::css::CoreStyle style){
	HX_STACK_PUSH("TransitionManager::getTransition","cocktail/core/animation/TransitionManager.hx",135);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(style,"style");
	HX_STACK_LINE(137)
	Array< ::cocktail::core::animation::Transition > transitionsForProperty = this->_transitions->__get(propertyIndex);		HX_STACK_VAR(transitionsForProperty,"transitionsForProperty");
	HX_STACK_LINE(138)
	if (((transitionsForProperty->length == (int)0))){
		HX_STACK_LINE(139)
		return null();
	}
	HX_STACK_LINE(144)
	int length = transitionsForProperty->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(145)
	{
		HX_STACK_LINE(145)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(145)
		while(((_g < length))){
			HX_STACK_LINE(145)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(147)
			if (((transitionsForProperty->__get(i)->target == style))){
				HX_STACK_LINE(148)
				return transitionsForProperty->__get(i);
			}
		}
	}
	HX_STACK_LINE(154)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TransitionManager_obj,getTransition,return )

Void TransitionManager_obj::initTransitions( ){
{
		HX_STACK_PUSH("TransitionManager::initTransitions","cocktail/core/animation/TransitionManager.hx",114);
		HX_STACK_THIS(this);
		HX_STACK_LINE(115)
		this->_transitions = Array_obj< Array< ::cocktail::core::animation::Transition > >::__new();
		HX_STACK_LINE(118)
		{
			HX_STACK_LINE(118)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(118)
			while(((_g < (int)87))){
				HX_STACK_LINE(118)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(120)
				this->_transitions[i] = Array_obj< ::cocktail::core::animation::Transition >::__new();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransitionManager_obj,initTransitions,(void))

::cocktail::core::animation::TransitionManager TransitionManager_obj::_instance;

::cocktail::core::animation::TransitionManager TransitionManager_obj::getInstance( ){
	HX_STACK_PUSH("TransitionManager::getInstance","cocktail/core/animation/TransitionManager.hx",101);
	HX_STACK_LINE(102)
	if (((::cocktail::core::animation::TransitionManager_obj::_instance == null()))){
		HX_STACK_LINE(103)
		::cocktail::core::animation::TransitionManager_obj::_instance = ::cocktail::core::animation::TransitionManager_obj::__new();
	}
	HX_STACK_LINE(107)
	return ::cocktail::core::animation::TransitionManager_obj::_instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(TransitionManager_obj,getInstance,return )


TransitionManager_obj::TransitionManager_obj()
{
}

void TransitionManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransitionManager);
	HX_MARK_MEMBER_NAME(_lastTick,"_lastTick");
	HX_MARK_MEMBER_NAME(hasTransitionsInProgress,"hasTransitionsInProgress");
	HX_MARK_MEMBER_NAME(_currentTransitionsNumber,"_currentTransitionsNumber");
	HX_MARK_MEMBER_NAME(_transitions,"_transitions");
	HX_MARK_END_CLASS();
}

void TransitionManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_lastTick,"_lastTick");
	HX_VISIT_MEMBER_NAME(hasTransitionsInProgress,"hasTransitionsInProgress");
	HX_VISIT_MEMBER_NAME(_currentTransitionsNumber,"_currentTransitionsNumber");
	HX_VISIT_MEMBER_NAME(_transitions,"_transitions");
}

Dynamic TransitionManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { return _instance; }
		if (HX_FIELD_EQ(inName,"_lastTick") ) { return _lastTick; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_transitions") ) { return _transitions; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getTransition") ) { return getTransition_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"stopTransition") ) { return stopTransition_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"startTransition") ) { return startTransition_dyn(); }
		if (HX_FIELD_EQ(inName,"initTransitions") ) { return initTransitions_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onTransitionTick") ) { return onTransitionTick_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"startTransitionUpdate") ) { return startTransitionUpdate_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"hasTransitionsInProgress") ) { return hasTransitionsInProgress; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getTransitionsForProperty") ) { return getTransitionsForProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"_currentTransitionsNumber") ) { return _currentTransitionsNumber; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TransitionManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { _instance=inValue.Cast< ::cocktail::core::animation::TransitionManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastTick") ) { _lastTick=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_transitions") ) { _transitions=inValue.Cast< Array< Array< ::cocktail::core::animation::Transition > > >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"hasTransitionsInProgress") ) { hasTransitionsInProgress=inValue.Cast< bool >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_currentTransitionsNumber") ) { _currentTransitionsNumber=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransitionManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_lastTick"));
	outFields->push(HX_CSTRING("hasTransitionsInProgress"));
	outFields->push(HX_CSTRING("_currentTransitionsNumber"));
	outFields->push(HX_CSTRING("_transitions"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onTransitionTick"),
	HX_CSTRING("startTransitionUpdate"),
	HX_CSTRING("getTransitionsForProperty"),
	HX_CSTRING("stopTransition"),
	HX_CSTRING("startTransition"),
	HX_CSTRING("getTransition"),
	HX_CSTRING("initTransitions"),
	HX_CSTRING("_lastTick"),
	HX_CSTRING("hasTransitionsInProgress"),
	HX_CSTRING("_currentTransitionsNumber"),
	HX_CSTRING("_transitions"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TransitionManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TransitionManager_obj::_instance,"_instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TransitionManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TransitionManager_obj::_instance,"_instance");
};

Class TransitionManager_obj::__mClass;

void TransitionManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.animation.TransitionManager"), hx::TCanCast< TransitionManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TransitionManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace animation
