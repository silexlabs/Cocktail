#include <hxcpp.h>

#ifndef INCLUDED_nme_events_ErrorEvent
#include <nme/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_IOErrorEvent
#include <nme/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_TextEvent
#include <nme/events/TextEvent.h>
#endif
namespace nme{
namespace events{

Void IOErrorEvent_obj::__construct(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_text,Dynamic __o_id)
{
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(false);
::String text = __o_text.Default(HX_CSTRING(""));
int id = __o_id.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/IOErrorEvent.hx",12)
	super::__construct(inType,bubbles,cancelable,text,id);
}
;
	return null();
}

IOErrorEvent_obj::~IOErrorEvent_obj() { }

Dynamic IOErrorEvent_obj::__CreateEmpty() { return  new IOErrorEvent_obj; }
hx::ObjectPtr< IOErrorEvent_obj > IOErrorEvent_obj::__new(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_text,Dynamic __o_id)
{  hx::ObjectPtr< IOErrorEvent_obj > result = new IOErrorEvent_obj();
	result->__construct(inType,__o_bubbles,__o_cancelable,__o_text,__o_id);
	return result;}

Dynamic IOErrorEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IOErrorEvent_obj > result = new IOErrorEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

::nme::events::Event IOErrorEvent_obj::clone( ){
	HX_SOURCE_PUSH("IOErrorEvent_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/IOErrorEvent.hx",18)
	return ::nme::events::IOErrorEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable(),this->text,this->errorID);
}


HX_DEFINE_DYNAMIC_FUNC0(IOErrorEvent_obj,clone,return )

::String IOErrorEvent_obj::toString( ){
	HX_SOURCE_PUSH("IOErrorEvent_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/IOErrorEvent.hx",24)
	return ((((((((((HX_CSTRING("[IOErrorEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING(" text=")) + this->text) + HX_CSTRING(" errorID=")) + this->errorID) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(IOErrorEvent_obj,toString,return )

::String IOErrorEvent_obj::IO_ERROR;


IOErrorEvent_obj::IOErrorEvent_obj()
{
}

void IOErrorEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IOErrorEvent);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic IOErrorEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"IO_ERROR") ) { return IO_ERROR; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IOErrorEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"IO_ERROR") ) { IO_ERROR=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IOErrorEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("IO_ERROR"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IOErrorEvent_obj::IO_ERROR,"IO_ERROR");
};

Class IOErrorEvent_obj::__mClass;

void IOErrorEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.IOErrorEvent"), hx::TCanCast< IOErrorEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IOErrorEvent_obj::__boot()
{
	hx::Static(IO_ERROR) = HX_CSTRING("ioError");
}

} // end namespace nme
} // end namespace events
