#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_KeyboardEvent
#include <nme/events/KeyboardEvent.h>
#endif
namespace nme{
namespace events{

Void KeyboardEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_charCodeValue,Dynamic __o_keyCodeValue,Dynamic __o_keyLocationValue,Dynamic __o_ctrlKeyValue,Dynamic __o_altKeyValue,Dynamic __o_shiftKeyValue,Dynamic __o_controlKeyValue,Dynamic __o_commandKeyValue)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
int charCodeValue = __o_charCodeValue.Default(0);
int keyCodeValue = __o_keyCodeValue.Default(0);
int keyLocationValue = __o_keyLocationValue.Default(0);
bool ctrlKeyValue = __o_ctrlKeyValue.Default(false);
bool altKeyValue = __o_altKeyValue.Default(false);
bool shiftKeyValue = __o_shiftKeyValue.Default(false);
bool controlKeyValue = __o_controlKeyValue.Default(false);
bool commandKeyValue = __o_commandKeyValue.Default(false);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",23)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",25)
	this->keyCode = keyCodeValue;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",26)
	this->keyLocation = (  (((keyLocationValue == null()))) ? int((int)0) : int(keyLocationValue) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",27)
	this->charCode = (  (((charCodeValue == null()))) ? int((int)0) : int(charCodeValue) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",29)
	this->shiftKey = shiftKeyValue;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",30)
	this->altKey = altKeyValue;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",31)
	this->controlKey = controlKeyValue;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",32)
	this->commandKey = commandKeyValue;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",33)
	this->ctrlKey = (bool((bool(ctrlKeyValue) || bool(this->controlKey))) || bool(this->commandKey));
}
;
	return null();
}

KeyboardEvent_obj::~KeyboardEvent_obj() { }

Dynamic KeyboardEvent_obj::__CreateEmpty() { return  new KeyboardEvent_obj; }
hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_charCodeValue,Dynamic __o_keyCodeValue,Dynamic __o_keyLocationValue,Dynamic __o_ctrlKeyValue,Dynamic __o_altKeyValue,Dynamic __o_shiftKeyValue,Dynamic __o_controlKeyValue,Dynamic __o_commandKeyValue)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_charCodeValue,__o_keyCodeValue,__o_keyLocationValue,__o_ctrlKeyValue,__o_altKeyValue,__o_shiftKeyValue,__o_controlKeyValue,__o_commandKeyValue);
	return result;}

Dynamic KeyboardEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10]);
	return result;}

::nme::events::Event KeyboardEvent_obj::clone( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",38)
	return ::nme::events::KeyboardEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable(),this->charCode,this->keyCode,this->keyLocation,this->ctrlKey,this->altKey,this->shiftKey,this->controlKey,this->commandKey);
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,clone,return )

::String KeyboardEvent_obj::toString( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/KeyboardEvent.hx",44)
	return ((((((((((((((((((HX_CSTRING("[KeyboardEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING(" charCode=")) + this->charCode) + HX_CSTRING(" keyCode=")) + this->keyCode) + HX_CSTRING(" keyLocation=")) + this->keyLocation) + HX_CSTRING(" ctrlKey=")) + this->ctrlKey) + HX_CSTRING(" altKey=")) + this->altKey) + HX_CSTRING(" shiftKey=")) + this->shiftKey) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,toString,return )

::String KeyboardEvent_obj::KEY_DOWN;

::String KeyboardEvent_obj::KEY_UP;


KeyboardEvent_obj::KeyboardEvent_obj()
{
}

void KeyboardEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(KeyboardEvent);
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	HX_MARK_MEMBER_NAME(charCode,"charCode");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(controlKey,"controlKey");
	HX_MARK_MEMBER_NAME(commandKey,"commandKey");
	HX_MARK_MEMBER_NAME(keyCode,"keyCode");
	HX_MARK_MEMBER_NAME(keyLocation,"keyLocation");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic KeyboardEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { return KEY_UP; }
		if (HX_FIELD_EQ(inName,"altKey") ) { return altKey; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ctrlKey; }
		if (HX_FIELD_EQ(inName,"keyCode") ) { return keyCode; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { return KEY_DOWN; }
		if (HX_FIELD_EQ(inName,"charCode") ) { return charCode; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controlKey") ) { return controlKey; }
		if (HX_FIELD_EQ(inName,"commandKey") ) { return commandKey; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"keyLocation") ) { return keyLocation; }
	}
	return super::__Field(inName);
}

Dynamic KeyboardEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { KEY_UP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keyCode") ) { keyCode=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { KEY_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"charCode") ) { charCode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controlKey") ) { controlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"commandKey") ) { commandKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"keyLocation") ) { keyLocation=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyboardEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("altKey"));
	outFields->push(HX_CSTRING("charCode"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("controlKey"));
	outFields->push(HX_CSTRING("commandKey"));
	outFields->push(HX_CSTRING("keyCode"));
	outFields->push(HX_CSTRING("keyLocation"));
	outFields->push(HX_CSTRING("shiftKey"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("KEY_DOWN"),
	HX_CSTRING("KEY_UP"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("altKey"),
	HX_CSTRING("charCode"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("controlKey"),
	HX_CSTRING("commandKey"),
	HX_CSTRING("keyCode"),
	HX_CSTRING("keyLocation"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_DOWN,"KEY_DOWN");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_UP,"KEY_UP");
};

Class KeyboardEvent_obj::__mClass;

void KeyboardEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.KeyboardEvent"), hx::TCanCast< KeyboardEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyboardEvent_obj::__boot()
{
	hx::Static(KEY_DOWN) = HX_CSTRING("keyDown");
	hx::Static(KEY_UP) = HX_CSTRING("keyUp");
}

} // end namespace nme
} // end namespace events
