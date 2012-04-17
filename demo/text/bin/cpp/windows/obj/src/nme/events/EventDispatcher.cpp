#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_nme_events_ErrorEvent
#include <nme/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_EventPhase
#include <nme/events/EventPhase.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IOErrorEvent
#include <nme/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_Listener
#include <nme/events/Listener.h>
#endif
#ifndef INCLUDED_nme_events_TextEvent
#include <nme/events/TextEvent.h>
#endif
#ifndef INCLUDED_nme_utils_WeakRef
#include <nme/utils/WeakRef.h>
#endif
namespace nme{
namespace events{

Void EventDispatcher_obj::__construct(::nme::events::IEventDispatcher target)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",19)
	this->nmeTarget = (  (((target == null()))) ? ::nme::events::IEventDispatcher(hx::ObjectPtr<OBJ_>(this)) : ::nme::events::IEventDispatcher(target) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",20)
	this->nmeEventMap = null();
}
;
	return null();
}

EventDispatcher_obj::~EventDispatcher_obj() { }

Dynamic EventDispatcher_obj::__CreateEmpty() { return  new EventDispatcher_obj; }
hx::ObjectPtr< EventDispatcher_obj > EventDispatcher_obj::__new(::nme::events::IEventDispatcher target)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(target);
	return result;}

Dynamic EventDispatcher_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventDispatcher_obj > result = new EventDispatcher_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *EventDispatcher_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::nme::events::IEventDispatcher_obj)) return operator ::nme::events::IEventDispatcher_obj *();
	return super::__ToInterface(inType);
}

Void EventDispatcher_obj::addEventListener( ::String type,Dynamic listener,Dynamic __o_useCapture,Dynamic __o_priority,Dynamic __o_useWeakReference){
bool useCapture = __o_useCapture.Default(false);
int priority = __o_priority.Default(0);
bool useWeakReference = __o_useWeakReference.Default(false);
	HX_SOURCE_PUSH("EventDispatcher_obj::addEventListener");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",26)
		if (((this->nmeEventMap == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",27)
			this->nmeEventMap = ::Hash_obj::__new();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",28)
		Array< ::nme::utils::WeakRef > list = this->nmeEventMap->get(type);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",29)
		if (((list == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",31)
			list = Array_obj< ::nme::utils::WeakRef >::__new();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",32)
			this->nmeEventMap->set(type,list);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",35)
		::nme::events::Listener l = ::nme::events::Listener_obj::__new(listener,useCapture,priority);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",36)
		list->push(::nme::utils::WeakRef_obj::__new(l,useWeakReference));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(EventDispatcher_obj,addEventListener,(void))

Void EventDispatcher_obj::DispatchCompleteEvent( ){
{
		HX_SOURCE_PUSH("EventDispatcher_obj::DispatchCompleteEvent")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",46)
		::nme::events::Event evt = ::nme::events::Event_obj::__new(::nme::events::Event_obj::COMPLETE,null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",47)
		this->dispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,DispatchCompleteEvent,(void))

bool EventDispatcher_obj::dispatchEvent( ::nme::events::Event event){
	HX_SOURCE_PUSH("EventDispatcher_obj::dispatchEvent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",53)
	if (((this->nmeEventMap == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",54)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",55)
	if (((event->nmeGetTarget() == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",56)
		event->nmeSetTarget(this->nmeTarget);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",58)
	if (((event->nmeGetCurrentTarget() == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",59)
		event->nmeSetCurrentTarget(this->nmeTarget);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",61)
	Array< ::nme::utils::WeakRef > list = this->nmeEventMap->get(event->nmeGetType());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",62)
	bool capture = (event->nmeGetEventPhase() == ::nme::events::EventPhase_obj::CAPTURING_PHASE);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",64)
	if (((list != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",66)
		int idx = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",67)
		while(((idx < list->length))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",69)
			::nme::utils::WeakRef list_item = list->__get(idx);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",70)
			::nme::events::Listener listener = (  (((list_item != null()))) ? ::nme::events::Listener(list_item->get()) : ::nme::events::Listener(null()) );
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",72)
			if (((listener == null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",73)
				list->splice(idx,(int)1);
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",79)
				if (((listener->mUseCapture == capture))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",81)
					listener->dispatchEvent(event);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",82)
					if ((event->nmeGetIsCancelledNow())){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",83)
						return true;
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",85)
				(idx)++;
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",89)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",92)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,dispatchEvent,return )

Void EventDispatcher_obj::DispatchIOErrorEvent( ){
{
		HX_SOURCE_PUSH("EventDispatcher_obj::DispatchIOErrorEvent")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",102)
		::nme::events::IOErrorEvent evt = ::nme::events::IOErrorEvent_obj::__new(::nme::events::IOErrorEvent_obj::IO_ERROR,null(),null(),null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",103)
		this->dispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,DispatchIOErrorEvent,(void))

bool EventDispatcher_obj::hasEventListener( ::String type){
	HX_SOURCE_PUSH("EventDispatcher_obj::hasEventListener")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",109)
	if (((this->nmeEventMap == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",110)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",111)
	Array< ::nme::utils::WeakRef > h = this->nmeEventMap->get(type);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",112)
	return (  (((h == null()))) ? bool(false) : bool((h->length > (int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,hasEventListener,return )

Void EventDispatcher_obj::removeEventListener( ::String type,Dynamic listener,Dynamic __o_capture){
bool capture = __o_capture.Default(false);
	HX_SOURCE_PUSH("EventDispatcher_obj::removeEventListener");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",118)
		if (((this->nmeEventMap == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",119)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",121)
		if ((!(this->nmeEventMap->exists(type)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",121)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",123)
		Array< ::nme::utils::WeakRef > list = this->nmeEventMap->get(type);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",124)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",124)
			int _g1 = (int)0;
			int _g = list->length;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",124)
			while(((_g1 < _g))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",124)
				int i = (_g1)++;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",126)
				if (((list->__get(i) != null()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",128)
					::nme::events::Listener li = list->__get(i)->get();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",129)
					if ((li->Is(listener,capture))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",132)
						list[i] = null();
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",133)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventDispatcher_obj,removeEventListener,(void))

::String EventDispatcher_obj::toString( ){
	HX_SOURCE_PUSH("EventDispatcher_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",141)
	return ((HX_CSTRING("[object ") + ::Type_obj::getClassName(::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this)))) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(EventDispatcher_obj,toString,return )

bool EventDispatcher_obj::willTrigger( ::String type){
	HX_SOURCE_PUSH("EventDispatcher_obj::willTrigger")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",148)
	if (((this->nmeEventMap == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",149)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/EventDispatcher.hx",150)
	return this->nmeEventMap->exists(type);
}


HX_DEFINE_DYNAMIC_FUNC1(EventDispatcher_obj,willTrigger,return )


EventDispatcher_obj::EventDispatcher_obj()
{
}

void EventDispatcher_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventDispatcher);
	HX_MARK_MEMBER_NAME(nmeEventMap,"nmeEventMap");
	HX_MARK_MEMBER_NAME(nmeTarget,"nmeTarget");
	HX_MARK_END_CLASS();
}

Dynamic EventDispatcher_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeTarget") ) { return nmeTarget; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeEventMap") ) { return nmeEventMap; }
		if (HX_FIELD_EQ(inName,"willTrigger") ) { return willTrigger_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addEventListener") ) { return addEventListener_dyn(); }
		if (HX_FIELD_EQ(inName,"hasEventListener") ) { return hasEventListener_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"removeEventListener") ) { return removeEventListener_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"DispatchIOErrorEvent") ) { return DispatchIOErrorEvent_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"DispatchCompleteEvent") ) { return DispatchCompleteEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EventDispatcher_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"nmeTarget") ) { nmeTarget=inValue.Cast< ::nme::events::IEventDispatcher >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeEventMap") ) { nmeEventMap=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EventDispatcher_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeEventMap"));
	outFields->push(HX_CSTRING("nmeTarget"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeEventMap"),
	HX_CSTRING("nmeTarget"),
	HX_CSTRING("addEventListener"),
	HX_CSTRING("DispatchCompleteEvent"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("DispatchIOErrorEvent"),
	HX_CSTRING("hasEventListener"),
	HX_CSTRING("removeEventListener"),
	HX_CSTRING("toString"),
	HX_CSTRING("willTrigger"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EventDispatcher_obj::__mClass;

void EventDispatcher_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.EventDispatcher"), hx::TCanCast< EventDispatcher_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EventDispatcher_obj::__boot()
{
}

} // end namespace nme
} // end namespace events
