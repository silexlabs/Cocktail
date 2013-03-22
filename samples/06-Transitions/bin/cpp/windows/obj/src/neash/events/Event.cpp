#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
#endif
namespace neash{
namespace events{

Void Event_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{
HX_STACK_PUSH("Event::new","neash/events/Event.hx",51);
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(52)
	this->_type = type;
	HX_STACK_LINE(53)
	this->_bubbles = bubbles;
	HX_STACK_LINE(54)
	this->_cancelable = cancelable;
	HX_STACK_LINE(55)
	this->nmeIsCancelled = false;
	HX_STACK_LINE(56)
	this->nmeIsCancelledNow = false;
	HX_STACK_LINE(57)
	this->_target = null();
	HX_STACK_LINE(58)
	this->_currentTarget = null();
	HX_STACK_LINE(59)
	this->_eventPhase = ::neash::events::EventPhase_obj::AT_TARGET;
}
;
	return null();
}

Event_obj::~Event_obj() { }

Dynamic Event_obj::__CreateEmpty() { return  new Event_obj; }
hx::ObjectPtr< Event_obj > Event_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic Event_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Event_obj > result = new Event_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Event_obj::nmeGetType( ){
	HX_STACK_PUSH("Event::nmeGetType","neash/events/Event.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_LINE(120)
	return this->_type;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetType,return )

Dynamic Event_obj::nmeSetTarget( Dynamic v){
	HX_STACK_PUSH("Event::nmeSetTarget","neash/events/Event.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(119)
	this->_target = v;
	HX_STACK_LINE(119)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Event_obj,nmeSetTarget,return )

Dynamic Event_obj::nmeGetTarget( ){
	HX_STACK_PUSH("Event::nmeGetTarget","neash/events/Event.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(118)
	return this->_target;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetTarget,return )

int Event_obj::nmeGetEventPhase( ){
	HX_STACK_PUSH("Event::nmeGetEventPhase","neash/events/Event.hx",117);
	HX_STACK_THIS(this);
	HX_STACK_LINE(117)
	return this->_eventPhase;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetEventPhase,return )

Dynamic Event_obj::nmeSetCurrentTarget( Dynamic v){
	HX_STACK_PUSH("Event::nmeSetCurrentTarget","neash/events/Event.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(116)
	this->_currentTarget = v;
	HX_STACK_LINE(116)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Event_obj,nmeSetCurrentTarget,return )

Dynamic Event_obj::nmeGetCurrentTarget( ){
	HX_STACK_PUSH("Event::nmeGetCurrentTarget","neash/events/Event.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(115)
	return this->_currentTarget;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetCurrentTarget,return )

bool Event_obj::nmeGetCancelable( ){
	HX_STACK_PUSH("Event::nmeGetCancelable","neash/events/Event.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_LINE(114)
	return this->_cancelable;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetCancelable,return )

bool Event_obj::nmeGetBubbles( ){
	HX_STACK_PUSH("Event::nmeGetBubbles","neash/events/Event.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_LINE(113)
	return this->_bubbles;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetBubbles,return )

::String Event_obj::toString( ){
	HX_STACK_PUSH("Event::toString","neash/events/Event.hx",103);
	HX_STACK_THIS(this);
	HX_STACK_LINE(103)
	return ((((((HX_CSTRING("[Event type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + ::Std_obj::string(this->nmeGetBubbles())) + HX_CSTRING(" cancelable=")) + ::Std_obj::string(this->nmeGetCancelable())) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,toString,return )

Void Event_obj::stopPropagation( ){
{
		HX_STACK_PUSH("Event::stopPropagation","neash/events/Event.hx",96);
		HX_STACK_THIS(this);
		HX_STACK_LINE(96)
		if ((this->nmeGetCancelable())){
			HX_STACK_LINE(98)
			this->nmeIsCancelled = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,stopPropagation,(void))

Void Event_obj::stopImmediatePropagation( ){
{
		HX_STACK_PUSH("Event::stopImmediatePropagation","neash/events/Event.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_LINE(89)
		if ((this->nmeGetCancelable())){
			HX_STACK_LINE(91)
			this->nmeIsCancelledNow = this->nmeIsCancelled = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,stopImmediatePropagation,(void))

Void Event_obj::nmeSetPhase( int inPhase){
{
		HX_STACK_PUSH("Event::nmeSetPhase","neash/events/Event.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inPhase,"inPhase");
		HX_STACK_LINE(82)
		this->_eventPhase = inPhase;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Event_obj,nmeSetPhase,(void))

bool Event_obj::nmeGetIsCancelledNow( ){
	HX_STACK_PUSH("Event::nmeGetIsCancelledNow","neash/events/Event.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_LINE(76)
	return this->nmeIsCancelledNow;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetIsCancelledNow,return )

bool Event_obj::nmeGetIsCancelled( ){
	HX_STACK_PUSH("Event::nmeGetIsCancelled","neash/events/Event.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_LINE(70)
	return this->nmeIsCancelled;
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,nmeGetIsCancelled,return )

::neash::events::Event Event_obj::clone( ){
	HX_STACK_PUSH("Event::clone","neash/events/Event.hx",64);
	HX_STACK_THIS(this);
	HX_STACK_LINE(64)
	return ::neash::events::Event_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable());
}


HX_DEFINE_DYNAMIC_FUNC0(Event_obj,clone,return )

::String Event_obj::ACTIVATE;

::String Event_obj::ADDED;

::String Event_obj::ADDED_TO_STAGE;

::String Event_obj::CANCEL;

::String Event_obj::CHANGE;

::String Event_obj::CLOSE;

::String Event_obj::COMPLETE;

::String Event_obj::CONNECT;

::String Event_obj::DEACTIVATE;

::String Event_obj::ENTER_FRAME;

::String Event_obj::ID3;

::String Event_obj::INIT;

::String Event_obj::MOUSE_LEAVE;

::String Event_obj::OPEN;

::String Event_obj::REMOVED;

::String Event_obj::REMOVED_FROM_STAGE;

::String Event_obj::RENDER;

::String Event_obj::RESIZE;

::String Event_obj::SCROLL;

::String Event_obj::SELECT;

::String Event_obj::SOUND_COMPLETE;

::String Event_obj::TAB_CHILDREN_CHANGE;

::String Event_obj::TAB_ENABLED_CHANGE;

::String Event_obj::TAB_INDEX_CHANGE;

::String Event_obj::UNLOAD;


Event_obj::Event_obj()
{
}

void Event_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Event);
	HX_MARK_MEMBER_NAME(nmeIsCancelledNow,"nmeIsCancelledNow");
	HX_MARK_MEMBER_NAME(nmeIsCancelled,"nmeIsCancelled");
	HX_MARK_MEMBER_NAME(_type,"_type");
	HX_MARK_MEMBER_NAME(_target,"_target");
	HX_MARK_MEMBER_NAME(_eventPhase,"_eventPhase");
	HX_MARK_MEMBER_NAME(_currentTarget,"_currentTarget");
	HX_MARK_MEMBER_NAME(_cancelable,"_cancelable");
	HX_MARK_MEMBER_NAME(_bubbles,"_bubbles");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(eventPhase,"eventPhase");
	HX_MARK_MEMBER_NAME(currentTarget,"currentTarget");
	HX_MARK_MEMBER_NAME(cancelable,"cancelable");
	HX_MARK_MEMBER_NAME(bubbles,"bubbles");
	HX_MARK_END_CLASS();
}

void Event_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeIsCancelledNow,"nmeIsCancelledNow");
	HX_VISIT_MEMBER_NAME(nmeIsCancelled,"nmeIsCancelled");
	HX_VISIT_MEMBER_NAME(_type,"_type");
	HX_VISIT_MEMBER_NAME(_target,"_target");
	HX_VISIT_MEMBER_NAME(_eventPhase,"_eventPhase");
	HX_VISIT_MEMBER_NAME(_currentTarget,"_currentTarget");
	HX_VISIT_MEMBER_NAME(_cancelable,"_cancelable");
	HX_VISIT_MEMBER_NAME(_bubbles,"_bubbles");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(eventPhase,"eventPhase");
	HX_VISIT_MEMBER_NAME(currentTarget,"currentTarget");
	HX_VISIT_MEMBER_NAME(cancelable,"cancelable");
	HX_VISIT_MEMBER_NAME(bubbles,"bubbles");
}

Dynamic Event_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ID3") ) { return ID3; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"INIT") ) { return INIT; }
		if (HX_FIELD_EQ(inName,"OPEN") ) { return OPEN; }
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? nmeGetType() : type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ADDED") ) { return ADDED; }
		if (HX_FIELD_EQ(inName,"CLOSE") ) { return CLOSE; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"_type") ) { return _type; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"CANCEL") ) { return CANCEL; }
		if (HX_FIELD_EQ(inName,"CHANGE") ) { return CHANGE; }
		if (HX_FIELD_EQ(inName,"RENDER") ) { return RENDER; }
		if (HX_FIELD_EQ(inName,"RESIZE") ) { return RESIZE; }
		if (HX_FIELD_EQ(inName,"SCROLL") ) { return SCROLL; }
		if (HX_FIELD_EQ(inName,"SELECT") ) { return SELECT; }
		if (HX_FIELD_EQ(inName,"UNLOAD") ) { return UNLOAD; }
		if (HX_FIELD_EQ(inName,"target") ) { return inCallProp ? nmeGetTarget() : target; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"CONNECT") ) { return CONNECT; }
		if (HX_FIELD_EQ(inName,"REMOVED") ) { return REMOVED; }
		if (HX_FIELD_EQ(inName,"_target") ) { return _target; }
		if (HX_FIELD_EQ(inName,"bubbles") ) { return inCallProp ? nmeGetBubbles() : bubbles; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ACTIVATE") ) { return ACTIVATE; }
		if (HX_FIELD_EQ(inName,"COMPLETE") ) { return COMPLETE; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"_bubbles") ) { return _bubbles; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"DEACTIVATE") ) { return DEACTIVATE; }
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		if (HX_FIELD_EQ(inName,"eventPhase") ) { return inCallProp ? nmeGetEventPhase() : eventPhase; }
		if (HX_FIELD_EQ(inName,"cancelable") ) { return inCallProp ? nmeGetCancelable() : cancelable; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ENTER_FRAME") ) { return ENTER_FRAME; }
		if (HX_FIELD_EQ(inName,"MOUSE_LEAVE") ) { return MOUSE_LEAVE; }
		if (HX_FIELD_EQ(inName,"nmeSetPhase") ) { return nmeSetPhase_dyn(); }
		if (HX_FIELD_EQ(inName,"_eventPhase") ) { return _eventPhase; }
		if (HX_FIELD_EQ(inName,"_cancelable") ) { return _cancelable; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeSetTarget") ) { return nmeSetTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTarget") ) { return nmeGetTarget_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeGetBubbles") ) { return nmeGetBubbles_dyn(); }
		if (HX_FIELD_EQ(inName,"currentTarget") ) { return inCallProp ? nmeGetCurrentTarget() : currentTarget; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ADDED_TO_STAGE") ) { return ADDED_TO_STAGE; }
		if (HX_FIELD_EQ(inName,"SOUND_COMPLETE") ) { return SOUND_COMPLETE; }
		if (HX_FIELD_EQ(inName,"nmeIsCancelled") ) { return nmeIsCancelled; }
		if (HX_FIELD_EQ(inName,"_currentTarget") ) { return _currentTarget; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stopPropagation") ) { return stopPropagation_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"TAB_INDEX_CHANGE") ) { return TAB_INDEX_CHANGE; }
		if (HX_FIELD_EQ(inName,"nmeGetEventPhase") ) { return nmeGetEventPhase_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetCancelable") ) { return nmeGetCancelable_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetIsCancelled") ) { return nmeGetIsCancelled_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeIsCancelledNow") ) { return nmeIsCancelledNow; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"REMOVED_FROM_STAGE") ) { return REMOVED_FROM_STAGE; }
		if (HX_FIELD_EQ(inName,"TAB_ENABLED_CHANGE") ) { return TAB_ENABLED_CHANGE; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"TAB_CHILDREN_CHANGE") ) { return TAB_CHILDREN_CHANGE; }
		if (HX_FIELD_EQ(inName,"nmeSetCurrentTarget") ) { return nmeSetCurrentTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetCurrentTarget") ) { return nmeGetCurrentTarget_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeGetIsCancelledNow") ) { return nmeGetIsCancelledNow_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"stopImmediatePropagation") ) { return stopImmediatePropagation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Event_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ID3") ) { ID3=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"INIT") ) { INIT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OPEN") ) { OPEN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ADDED") ) { ADDED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CLOSE") ) { CLOSE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_type") ) { _type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"CANCEL") ) { CANCEL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CHANGE") ) { CHANGE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RENDER") ) { RENDER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RESIZE") ) { RESIZE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SCROLL") ) { SCROLL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SELECT") ) { SELECT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"UNLOAD") ) { UNLOAD=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { if (inCallProp) return nmeSetTarget(inValue);target=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"CONNECT") ) { CONNECT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"REMOVED") ) { REMOVED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_target") ) { _target=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bubbles") ) { bubbles=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ACTIVATE") ) { ACTIVATE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"COMPLETE") ) { COMPLETE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bubbles") ) { _bubbles=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"DEACTIVATE") ) { DEACTIVATE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"eventPhase") ) { eventPhase=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cancelable") ) { cancelable=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ENTER_FRAME") ) { ENTER_FRAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_LEAVE") ) { MOUSE_LEAVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_eventPhase") ) { _eventPhase=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cancelable") ) { _cancelable=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentTarget") ) { if (inCallProp) return nmeSetCurrentTarget(inValue);currentTarget=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ADDED_TO_STAGE") ) { ADDED_TO_STAGE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SOUND_COMPLETE") ) { SOUND_COMPLETE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeIsCancelled") ) { nmeIsCancelled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_currentTarget") ) { _currentTarget=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"TAB_INDEX_CHANGE") ) { TAB_INDEX_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeIsCancelledNow") ) { nmeIsCancelledNow=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"REMOVED_FROM_STAGE") ) { REMOVED_FROM_STAGE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TAB_ENABLED_CHANGE") ) { TAB_ENABLED_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"TAB_CHILDREN_CHANGE") ) { TAB_CHILDREN_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Event_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeIsCancelledNow"));
	outFields->push(HX_CSTRING("nmeIsCancelled"));
	outFields->push(HX_CSTRING("_type"));
	outFields->push(HX_CSTRING("_target"));
	outFields->push(HX_CSTRING("_eventPhase"));
	outFields->push(HX_CSTRING("_currentTarget"));
	outFields->push(HX_CSTRING("_cancelable"));
	outFields->push(HX_CSTRING("_bubbles"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("eventPhase"));
	outFields->push(HX_CSTRING("currentTarget"));
	outFields->push(HX_CSTRING("cancelable"));
	outFields->push(HX_CSTRING("bubbles"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ACTIVATE"),
	HX_CSTRING("ADDED"),
	HX_CSTRING("ADDED_TO_STAGE"),
	HX_CSTRING("CANCEL"),
	HX_CSTRING("CHANGE"),
	HX_CSTRING("CLOSE"),
	HX_CSTRING("COMPLETE"),
	HX_CSTRING("CONNECT"),
	HX_CSTRING("DEACTIVATE"),
	HX_CSTRING("ENTER_FRAME"),
	HX_CSTRING("ID3"),
	HX_CSTRING("INIT"),
	HX_CSTRING("MOUSE_LEAVE"),
	HX_CSTRING("OPEN"),
	HX_CSTRING("REMOVED"),
	HX_CSTRING("REMOVED_FROM_STAGE"),
	HX_CSTRING("RENDER"),
	HX_CSTRING("RESIZE"),
	HX_CSTRING("SCROLL"),
	HX_CSTRING("SELECT"),
	HX_CSTRING("SOUND_COMPLETE"),
	HX_CSTRING("TAB_CHILDREN_CHANGE"),
	HX_CSTRING("TAB_ENABLED_CHANGE"),
	HX_CSTRING("TAB_INDEX_CHANGE"),
	HX_CSTRING("UNLOAD"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("nmeSetTarget"),
	HX_CSTRING("nmeGetTarget"),
	HX_CSTRING("nmeGetEventPhase"),
	HX_CSTRING("nmeSetCurrentTarget"),
	HX_CSTRING("nmeGetCurrentTarget"),
	HX_CSTRING("nmeGetCancelable"),
	HX_CSTRING("nmeGetBubbles"),
	HX_CSTRING("toString"),
	HX_CSTRING("stopPropagation"),
	HX_CSTRING("stopImmediatePropagation"),
	HX_CSTRING("nmeSetPhase"),
	HX_CSTRING("nmeGetIsCancelledNow"),
	HX_CSTRING("nmeGetIsCancelled"),
	HX_CSTRING("clone"),
	HX_CSTRING("nmeIsCancelledNow"),
	HX_CSTRING("nmeIsCancelled"),
	HX_CSTRING("_type"),
	HX_CSTRING("_target"),
	HX_CSTRING("_eventPhase"),
	HX_CSTRING("_currentTarget"),
	HX_CSTRING("_cancelable"),
	HX_CSTRING("_bubbles"),
	HX_CSTRING("type"),
	HX_CSTRING("target"),
	HX_CSTRING("eventPhase"),
	HX_CSTRING("currentTarget"),
	HX_CSTRING("cancelable"),
	HX_CSTRING("bubbles"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Event_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Event_obj::ACTIVATE,"ACTIVATE");
	HX_MARK_MEMBER_NAME(Event_obj::ADDED,"ADDED");
	HX_MARK_MEMBER_NAME(Event_obj::ADDED_TO_STAGE,"ADDED_TO_STAGE");
	HX_MARK_MEMBER_NAME(Event_obj::CANCEL,"CANCEL");
	HX_MARK_MEMBER_NAME(Event_obj::CHANGE,"CHANGE");
	HX_MARK_MEMBER_NAME(Event_obj::CLOSE,"CLOSE");
	HX_MARK_MEMBER_NAME(Event_obj::COMPLETE,"COMPLETE");
	HX_MARK_MEMBER_NAME(Event_obj::CONNECT,"CONNECT");
	HX_MARK_MEMBER_NAME(Event_obj::DEACTIVATE,"DEACTIVATE");
	HX_MARK_MEMBER_NAME(Event_obj::ENTER_FRAME,"ENTER_FRAME");
	HX_MARK_MEMBER_NAME(Event_obj::ID3,"ID3");
	HX_MARK_MEMBER_NAME(Event_obj::INIT,"INIT");
	HX_MARK_MEMBER_NAME(Event_obj::MOUSE_LEAVE,"MOUSE_LEAVE");
	HX_MARK_MEMBER_NAME(Event_obj::OPEN,"OPEN");
	HX_MARK_MEMBER_NAME(Event_obj::REMOVED,"REMOVED");
	HX_MARK_MEMBER_NAME(Event_obj::REMOVED_FROM_STAGE,"REMOVED_FROM_STAGE");
	HX_MARK_MEMBER_NAME(Event_obj::RENDER,"RENDER");
	HX_MARK_MEMBER_NAME(Event_obj::RESIZE,"RESIZE");
	HX_MARK_MEMBER_NAME(Event_obj::SCROLL,"SCROLL");
	HX_MARK_MEMBER_NAME(Event_obj::SELECT,"SELECT");
	HX_MARK_MEMBER_NAME(Event_obj::SOUND_COMPLETE,"SOUND_COMPLETE");
	HX_MARK_MEMBER_NAME(Event_obj::TAB_CHILDREN_CHANGE,"TAB_CHILDREN_CHANGE");
	HX_MARK_MEMBER_NAME(Event_obj::TAB_ENABLED_CHANGE,"TAB_ENABLED_CHANGE");
	HX_MARK_MEMBER_NAME(Event_obj::TAB_INDEX_CHANGE,"TAB_INDEX_CHANGE");
	HX_MARK_MEMBER_NAME(Event_obj::UNLOAD,"UNLOAD");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Event_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Event_obj::ACTIVATE,"ACTIVATE");
	HX_VISIT_MEMBER_NAME(Event_obj::ADDED,"ADDED");
	HX_VISIT_MEMBER_NAME(Event_obj::ADDED_TO_STAGE,"ADDED_TO_STAGE");
	HX_VISIT_MEMBER_NAME(Event_obj::CANCEL,"CANCEL");
	HX_VISIT_MEMBER_NAME(Event_obj::CHANGE,"CHANGE");
	HX_VISIT_MEMBER_NAME(Event_obj::CLOSE,"CLOSE");
	HX_VISIT_MEMBER_NAME(Event_obj::COMPLETE,"COMPLETE");
	HX_VISIT_MEMBER_NAME(Event_obj::CONNECT,"CONNECT");
	HX_VISIT_MEMBER_NAME(Event_obj::DEACTIVATE,"DEACTIVATE");
	HX_VISIT_MEMBER_NAME(Event_obj::ENTER_FRAME,"ENTER_FRAME");
	HX_VISIT_MEMBER_NAME(Event_obj::ID3,"ID3");
	HX_VISIT_MEMBER_NAME(Event_obj::INIT,"INIT");
	HX_VISIT_MEMBER_NAME(Event_obj::MOUSE_LEAVE,"MOUSE_LEAVE");
	HX_VISIT_MEMBER_NAME(Event_obj::OPEN,"OPEN");
	HX_VISIT_MEMBER_NAME(Event_obj::REMOVED,"REMOVED");
	HX_VISIT_MEMBER_NAME(Event_obj::REMOVED_FROM_STAGE,"REMOVED_FROM_STAGE");
	HX_VISIT_MEMBER_NAME(Event_obj::RENDER,"RENDER");
	HX_VISIT_MEMBER_NAME(Event_obj::RESIZE,"RESIZE");
	HX_VISIT_MEMBER_NAME(Event_obj::SCROLL,"SCROLL");
	HX_VISIT_MEMBER_NAME(Event_obj::SELECT,"SELECT");
	HX_VISIT_MEMBER_NAME(Event_obj::SOUND_COMPLETE,"SOUND_COMPLETE");
	HX_VISIT_MEMBER_NAME(Event_obj::TAB_CHILDREN_CHANGE,"TAB_CHILDREN_CHANGE");
	HX_VISIT_MEMBER_NAME(Event_obj::TAB_ENABLED_CHANGE,"TAB_ENABLED_CHANGE");
	HX_VISIT_MEMBER_NAME(Event_obj::TAB_INDEX_CHANGE,"TAB_INDEX_CHANGE");
	HX_VISIT_MEMBER_NAME(Event_obj::UNLOAD,"UNLOAD");
};

Class Event_obj::__mClass;

void Event_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.events.Event"), hx::TCanCast< Event_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Event_obj::__boot()
{
	ACTIVATE= HX_CSTRING("activate");
	ADDED= HX_CSTRING("added");
	ADDED_TO_STAGE= HX_CSTRING("addedToStage");
	CANCEL= HX_CSTRING("cancel");
	CHANGE= HX_CSTRING("change");
	CLOSE= HX_CSTRING("close");
	COMPLETE= HX_CSTRING("complete");
	CONNECT= HX_CSTRING("connect");
	DEACTIVATE= HX_CSTRING("deactivate");
	ENTER_FRAME= HX_CSTRING("enterFrame");
	ID3= HX_CSTRING("id3");
	INIT= HX_CSTRING("init");
	MOUSE_LEAVE= HX_CSTRING("mouseLeave");
	OPEN= HX_CSTRING("open");
	REMOVED= HX_CSTRING("removed");
	REMOVED_FROM_STAGE= HX_CSTRING("removedFromStage");
	RENDER= HX_CSTRING("render");
	RESIZE= HX_CSTRING("resize");
	SCROLL= HX_CSTRING("scroll");
	SELECT= HX_CSTRING("select");
	SOUND_COMPLETE= HX_CSTRING("soundComplete");
	TAB_CHILDREN_CHANGE= HX_CSTRING("tabChildrenChange");
	TAB_ENABLED_CHANGE= HX_CSTRING("tabEnabledChange");
	TAB_INDEX_CHANGE= HX_CSTRING("tabIndexChange");
	UNLOAD= HX_CSTRING("unload");
}

} // end namespace neash
} // end namespace events
