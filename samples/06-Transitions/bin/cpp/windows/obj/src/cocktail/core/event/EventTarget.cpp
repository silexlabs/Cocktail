#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventListener
#include <cocktail/core/event/EventListener.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void EventTarget_obj::__construct()
{
HX_STACK_PUSH("EventTarget::new","cocktail/core/event/EventTarget.hx",40);
{
}
;
	return null();
}

EventTarget_obj::~EventTarget_obj() { }

Dynamic EventTarget_obj::__CreateEmpty() { return  new EventTarget_obj; }
hx::ObjectPtr< EventTarget_obj > EventTarget_obj::__new()
{  hx::ObjectPtr< EventTarget_obj > result = new EventTarget_obj();
	result->__construct();
	return result;}

Dynamic EventTarget_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventTarget_obj > result = new EventTarget_obj();
	result->__construct();
	return result;}

Void EventTarget_obj::executeDefaultActionIfNeeded( bool defaultPrevented,::cocktail::core::event::Event event){
{
		HX_STACK_PUSH("EventTarget::executeDefaultActionIfNeeded","cocktail/core/event/EventTarget.hx",339);
		HX_STACK_THIS(this);
		HX_STACK_ARG(defaultPrevented,"defaultPrevented");
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventTarget_obj,executeDefaultActionIfNeeded,(void))

Array< ::cocktail::core::event::EventTarget > EventTarget_obj::getTargetAncestors( ){
	HX_STACK_PUSH("EventTarget::getTargetAncestors","cocktail/core/event/EventTarget.hx",320);
	HX_STACK_THIS(this);
	HX_STACK_LINE(322)
	if (((this->_targetAncestors == null()))){
		HX_STACK_LINE(323)
		this->_targetAncestors = Array_obj< ::cocktail::core::event::EventTarget >::__new();
	}
	else{
		HX_STACK_LINE(327)
		this->_targetAncestors = ::cocktail::core::utils::Utils_obj::clear(this->_targetAncestors);
	}
	HX_STACK_LINE(331)
	return this->_targetAncestors;
}


HX_DEFINE_DYNAMIC_FUNC0(EventTarget_obj,getTargetAncestors,return )

bool EventTarget_obj::endEventDispatching( ::cocktail::core::event::Event evt){
	HX_STACK_PUSH("EventTarget::endEventDispatching","cocktail/core/event/EventTarget.hx",309);
	HX_STACK_THIS(this);
	HX_STACK_ARG(evt,"evt");
	HX_STACK_LINE(310)
	bool defaultPrevented = evt->defaultPrevented;		HX_STACK_VAR(defaultPrevented,"defaultPrevented");
	HX_STACK_LINE(311)
	this->executeDefaultActionIfNeeded(defaultPrevented,evt);
	HX_STACK_LINE(312)
	return defaultPrevented;
}


HX_DEFINE_DYNAMIC_FUNC1(EventTarget_obj,endEventDispatching,return )

bool EventTarget_obj::shouldStopEventPropagation( ::cocktail::core::event::Event evt){
	HX_STACK_PUSH("EventTarget::shouldStopEventPropagation","cocktail/core/event/EventTarget.hx",301);
	HX_STACK_THIS(this);
	HX_STACK_ARG(evt,"evt");
	HX_STACK_LINE(301)
	return (bool((evt->propagationStopped == true)) || bool((evt->immediatePropagationStopped == true)));
}


HX_DEFINE_DYNAMIC_FUNC1(EventTarget_obj,shouldStopEventPropagation,return )

Void EventTarget_obj::doDispatchEvent( Array< ::cocktail::core::event::EventListener > eventListeners,::cocktail::core::event::Event evt){
{
		HX_STACK_PUSH("EventTarget::doDispatchEvent","cocktail/core/event/EventTarget.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventListeners,"eventListeners");
		HX_STACK_ARG(evt,"evt");
		HX_STACK_LINE(254)
		int length = eventListeners->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(255)
		{
			HX_STACK_LINE(255)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(255)
			while(((_g < length))){
				HX_STACK_LINE(255)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(257)
				::cocktail::core::event::EventListener eventListener = eventListeners->__get(i);		HX_STACK_VAR(eventListener,"eventListener");
				HX_STACK_LINE(263)
				if (((evt->eventPhase == (int)1))){
					HX_STACK_LINE(264)
					if (((eventListener->useCapture == true))){
						HX_STACK_LINE(266)
						eventListener->handleEvent(evt);
					}
				}
				else{
					HX_STACK_LINE(271)
					if (((evt->eventPhase == (int)3))){
						HX_STACK_LINE(272)
						if (((eventListener->useCapture == false))){
							HX_STACK_LINE(274)
							eventListener->handleEvent(evt);
						}
					}
					else{
						HX_STACK_LINE(280)
						if (((evt->eventPhase == (int)2))){
							HX_STACK_LINE(281)
							eventListener->handleEvent(evt);
						}
					}
				}
				HX_STACK_LINE(289)
				if (((evt->immediatePropagationStopped == true))){
					HX_STACK_LINE(290)
					return null();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventTarget_obj,doDispatchEvent,(void))

Void EventTarget_obj::removeEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture){
bool useCapture = __o_useCapture.Default(false);
	HX_STACK_PUSH("EventTarget::removeEventListener","cocktail/core/event/EventTarget.hx",217);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_ARG(listener,"listener");
	HX_STACK_ARG(useCapture,"useCapture");
{
		HX_STACK_LINE(219)
		if (((this->_registeredEventListeners == null()))){
			HX_STACK_LINE(220)
			return null();
		}
		HX_STACK_LINE(224)
		Array< ::cocktail::core::event::EventListener > registeredEventListenersForType = this->_registeredEventListeners->get(type);		HX_STACK_VAR(registeredEventListenersForType,"registeredEventListenersForType");
		HX_STACK_LINE(225)
		if (((registeredEventListenersForType != null()))){
			HX_STACK_LINE(227)
			Array< ::cocktail::core::event::EventListener > newEventListeners = Array_obj< ::cocktail::core::event::EventListener >::__new();		HX_STACK_VAR(newEventListeners,"newEventListeners");
			HX_STACK_LINE(229)
			int length = registeredEventListenersForType->length;		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(230)
			{
				HX_STACK_LINE(230)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(230)
				while(((_g < length))){
					HX_STACK_LINE(230)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(232)
					::cocktail::core::event::EventListener eventListener = registeredEventListenersForType->__get(i);		HX_STACK_VAR(eventListener,"eventListener");
					HX_STACK_LINE(234)
					if (((bool((bool((eventListener->eventType != type)) || bool((eventListener->useCapture != useCapture)))) || bool((eventListener->listener_dyn() != listener))))){
						HX_STACK_LINE(235)
						newEventListeners->push(eventListener);
					}
				}
			}
			HX_STACK_LINE(240)
			this->_registeredEventListeners->set(type,newEventListeners);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventTarget_obj,removeEventListener,(void))

Void EventTarget_obj::addEventListener( ::String type,Dynamic listener,hx::Null< bool >  __o_useCapture){
bool useCapture = __o_useCapture.Default(false);
	HX_STACK_PUSH("EventTarget::addEventListener","cocktail/core/event/EventTarget.hx",186);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_ARG(listener,"listener");
	HX_STACK_ARG(useCapture,"useCapture");
{
		HX_STACK_LINE(187)
		if (((this->_registeredEventListeners == null()))){
			HX_STACK_LINE(188)
			this->_registeredEventListeners = ::Hash_obj::__new();
		}
		HX_STACK_LINE(192)
		if (((this->_registeredEventListeners->exists(type) == false))){
			HX_STACK_LINE(193)
			this->_registeredEventListeners->set(type,Array_obj< ::cocktail::core::event::EventListener >::__new());
		}
		HX_STACK_LINE(197)
		::cocktail::core::event::EventListener eventListener = ::cocktail::core::event::EventListener_obj::__new(type,listener,useCapture);		HX_STACK_VAR(eventListener,"eventListener");
		HX_STACK_LINE(199)
		this->_registeredEventListeners->get(type)->__Field(HX_CSTRING("push"),true)(eventListener);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventTarget_obj,addEventListener,(void))

bool EventTarget_obj::dispatchEvent( ::cocktail::core::event::Event evt){
	HX_STACK_PUSH("EventTarget::dispatchEvent","cocktail/core/event/EventTarget.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(evt,"evt");
	HX_STACK_LINE(61)
	evt->currentTarget = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(66)
	if (((evt->dispatched == false))){
		HX_STACK_LINE(70)
		evt->target = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(74)
		evt->dispatched = true;
		HX_STACK_LINE(78)
		Array< ::cocktail::core::event::EventTarget > targetAncestors = this->getTargetAncestors();		HX_STACK_VAR(targetAncestors,"targetAncestors");
		HX_STACK_LINE(81)
		evt->eventPhase = (int)1;
		HX_STACK_LINE(86)
		targetAncestors->reverse();
		HX_STACK_LINE(89)
		int length = targetAncestors->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(90)
		{
			HX_STACK_LINE(90)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(90)
			while(((_g < length))){
				HX_STACK_LINE(90)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(92)
				targetAncestors->__get(i)->dispatchEvent(evt);
				HX_STACK_LINE(95)
				if (((this->shouldStopEventPropagation(evt) == true))){
					HX_STACK_LINE(96)
					return this->endEventDispatching(evt);
				}
			}
		}
		HX_STACK_LINE(104)
		evt->eventPhase = (int)2;
		HX_STACK_LINE(105)
		this->dispatchEvent(evt);
		HX_STACK_LINE(108)
		if (((this->shouldStopEventPropagation(evt) == true))){
			HX_STACK_LINE(109)
			return this->endEventDispatching(evt);
		}
		HX_STACK_LINE(114)
		if (((evt->bubbles == true))){
			HX_STACK_LINE(117)
			evt->eventPhase = (int)3;
			HX_STACK_LINE(122)
			targetAncestors->reverse();
			HX_STACK_LINE(125)
			int length1 = targetAncestors->length;		HX_STACK_VAR(length1,"length1");
			HX_STACK_LINE(126)
			{
				HX_STACK_LINE(126)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(126)
				while(((_g < length1))){
					HX_STACK_LINE(126)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(128)
					targetAncestors->__get(i)->dispatchEvent(evt);
					HX_STACK_LINE(130)
					if (((this->shouldStopEventPropagation(evt) == true))){
						HX_STACK_LINE(131)
						return this->endEventDispatching(evt);
					}
				}
			}
			HX_STACK_LINE(137)
			return this->endEventDispatching(evt);
		}
	}
	else{
		HX_STACK_LINE(143)
		if (((this->_registeredEventListeners != null()))){
			HX_STACK_LINE(146)
			Array< ::cocktail::core::event::EventListener > eventRegisteredForEventType = this->_registeredEventListeners->get(evt->type);		HX_STACK_VAR(eventRegisteredForEventType,"eventRegisteredForEventType");
			HX_STACK_LINE(148)
			if (((eventRegisteredForEventType != null()))){
				HX_STACK_LINE(149)
				this->doDispatchEvent(eventRegisteredForEventType,evt);
			}
		}
	}
	HX_STACK_LINE(157)
	return evt->defaultPrevented;
}


HX_DEFINE_DYNAMIC_FUNC1(EventTarget_obj,dispatchEvent,return )


EventTarget_obj::EventTarget_obj()
{
}

void EventTarget_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventTarget);
	HX_MARK_MEMBER_NAME(_targetAncestors,"_targetAncestors");
	HX_MARK_MEMBER_NAME(_registeredEventListeners,"_registeredEventListeners");
	HX_MARK_END_CLASS();
}

void EventTarget_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_targetAncestors,"_targetAncestors");
	HX_VISIT_MEMBER_NAME(_registeredEventListeners,"_registeredEventListeners");
}

Dynamic EventTarget_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"doDispatchEvent") ) { return doDispatchEvent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		if (HX_FIELD_EQ(inName,"_targetAncestors") ) { return _targetAncestors; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getTargetAncestors") ) { return getTargetAncestors_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endEventDispatching") ) { return endEventDispatching_dyn(); }
		if (HX_FIELD_EQ(inName,"removeEventListener") ) { return removeEventListener_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_registeredEventListeners") ) { return _registeredEventListeners; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"shouldStopEventPropagation") ) { return shouldStopEventPropagation_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"executeDefaultActionIfNeeded") ) { return executeDefaultActionIfNeeded_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventTarget_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"_targetAncestors") ) { _targetAncestors=inValue.Cast< Array< ::cocktail::core::event::EventTarget > >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_registeredEventListeners") ) { _registeredEventListeners=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventTarget_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_targetAncestors"));
	outFields->push(HX_CSTRING("_registeredEventListeners"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("executeDefaultActionIfNeeded"),
	HX_CSTRING("getTargetAncestors"),
	HX_CSTRING("endEventDispatching"),
	HX_CSTRING("shouldStopEventPropagation"),
	HX_CSTRING("doDispatchEvent"),
	HX_CSTRING("removeEventListener"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("_targetAncestors"),
	HX_CSTRING("_registeredEventListeners"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventTarget_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventTarget_obj::__mClass,"__mClass");
};

Class EventTarget_obj::__mClass;

void EventTarget_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.EventTarget"), hx::TCanCast< EventTarget_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EventTarget_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
