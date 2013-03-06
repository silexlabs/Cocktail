#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void KeyboardEvent_obj::__construct()
{
HX_STACK_PUSH("KeyboardEvent::new","cocktail/core/event/KeyboardEvent.hx",138);
{
	HX_STACK_LINE(138)
	super::__construct();
}
;
	return null();
}

KeyboardEvent_obj::~KeyboardEvent_obj() { }

Dynamic KeyboardEvent_obj::__CreateEmpty() { return  new KeyboardEvent_obj; }
hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__new()
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct();
	return result;}

Dynamic KeyboardEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct();
	return result;}

Void KeyboardEvent_obj::initKeyboardEvent( ::String eventTypeArg,bool canBubbleArg,bool cancelableArg,Dynamic viewArg,::String charArg,::String keyArg,int locationArg,::String modifiersListArg,bool repeatArg,::String localeArg){
{
		HX_STACK_PUSH("KeyboardEvent::initKeyboardEvent","cocktail/core/event/KeyboardEvent.hx",166);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventTypeArg,"eventTypeArg");
		HX_STACK_ARG(canBubbleArg,"canBubbleArg");
		HX_STACK_ARG(cancelableArg,"cancelableArg");
		HX_STACK_ARG(viewArg,"viewArg");
		HX_STACK_ARG(charArg,"charArg");
		HX_STACK_ARG(keyArg,"keyArg");
		HX_STACK_ARG(locationArg,"locationArg");
		HX_STACK_ARG(modifiersListArg,"modifiersListArg");
		HX_STACK_ARG(repeatArg,"repeatArg");
		HX_STACK_ARG(localeArg,"localeArg");
		HX_STACK_LINE(168)
		if (((this->dispatched == true))){
			HX_STACK_LINE(169)
			return null();
		}
		HX_STACK_LINE(173)
		this->initUIEvent(eventTypeArg,canBubbleArg,cancelableArg,viewArg,(int)0);
		HX_STACK_LINE(174)
		this->keyChar = charArg;
		HX_STACK_LINE(175)
		this->key = keyArg;
		HX_STACK_LINE(176)
		this->repeat = repeatArg;
		HX_STACK_LINE(177)
		this->location = locationArg;
		HX_STACK_LINE(178)
		this->locale = localeArg;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC10(KeyboardEvent_obj,initKeyboardEvent,(void))

int KeyboardEvent_obj::DOM_KEY_LOCATION_STANDARD;

int KeyboardEvent_obj::DOM_KEY_LOCATION_LEFT;

int KeyboardEvent_obj::DOM_KEY_LOCATION_RIGHT;

int KeyboardEvent_obj::DOM_KEY_LOCATION_NUMPAD;

int KeyboardEvent_obj::DOM_KEY_LOCATION_MOBILE;

int KeyboardEvent_obj::DOM_KEY_LOCATION_JOYSTICK;


KeyboardEvent_obj::KeyboardEvent_obj()
{
}

void KeyboardEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(KeyboardEvent);
	HX_MARK_MEMBER_NAME(repeat,"repeat");
	HX_MARK_MEMBER_NAME(metaKey,"metaKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(locale,"locale");
	HX_MARK_MEMBER_NAME(location,"location");
	HX_MARK_MEMBER_NAME(key,"key");
	HX_MARK_MEMBER_NAME(keyChar,"keyChar");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void KeyboardEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(repeat,"repeat");
	HX_VISIT_MEMBER_NAME(metaKey,"metaKey");
	HX_VISIT_MEMBER_NAME(altKey,"altKey");
	HX_VISIT_MEMBER_NAME(shiftKey,"shiftKey");
	HX_VISIT_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_VISIT_MEMBER_NAME(locale,"locale");
	HX_VISIT_MEMBER_NAME(location,"location");
	HX_VISIT_MEMBER_NAME(key,"key");
	HX_VISIT_MEMBER_NAME(keyChar,"keyChar");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic KeyboardEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"key") ) { return key; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"repeat") ) { return repeat; }
		if (HX_FIELD_EQ(inName,"altKey") ) { return altKey; }
		if (HX_FIELD_EQ(inName,"locale") ) { return locale; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"metaKey") ) { return metaKey; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ctrlKey; }
		if (HX_FIELD_EQ(inName,"keyChar") ) { return keyChar; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		if (HX_FIELD_EQ(inName,"location") ) { return location; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initKeyboardEvent") ) { return initKeyboardEvent_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_LEFT") ) { return DOM_KEY_LOCATION_LEFT; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_RIGHT") ) { return DOM_KEY_LOCATION_RIGHT; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_NUMPAD") ) { return DOM_KEY_LOCATION_NUMPAD; }
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_MOBILE") ) { return DOM_KEY_LOCATION_MOBILE; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_STANDARD") ) { return DOM_KEY_LOCATION_STANDARD; }
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_JOYSTICK") ) { return DOM_KEY_LOCATION_JOYSTICK; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic KeyboardEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"key") ) { key=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"repeat") ) { repeat=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"locale") ) { locale=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"metaKey") ) { metaKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keyChar") ) { keyChar=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"location") ) { location=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_LEFT") ) { DOM_KEY_LOCATION_LEFT=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_RIGHT") ) { DOM_KEY_LOCATION_RIGHT=inValue.Cast< int >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_NUMPAD") ) { DOM_KEY_LOCATION_NUMPAD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_MOBILE") ) { DOM_KEY_LOCATION_MOBILE=inValue.Cast< int >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_STANDARD") ) { DOM_KEY_LOCATION_STANDARD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOM_KEY_LOCATION_JOYSTICK") ) { DOM_KEY_LOCATION_JOYSTICK=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void KeyboardEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("repeat"));
	outFields->push(HX_CSTRING("metaKey"));
	outFields->push(HX_CSTRING("altKey"));
	outFields->push(HX_CSTRING("shiftKey"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("locale"));
	outFields->push(HX_CSTRING("location"));
	outFields->push(HX_CSTRING("key"));
	outFields->push(HX_CSTRING("keyChar"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DOM_KEY_LOCATION_STANDARD"),
	HX_CSTRING("DOM_KEY_LOCATION_LEFT"),
	HX_CSTRING("DOM_KEY_LOCATION_RIGHT"),
	HX_CSTRING("DOM_KEY_LOCATION_NUMPAD"),
	HX_CSTRING("DOM_KEY_LOCATION_MOBILE"),
	HX_CSTRING("DOM_KEY_LOCATION_JOYSTICK"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initKeyboardEvent"),
	HX_CSTRING("repeat"),
	HX_CSTRING("metaKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("locale"),
	HX_CSTRING("location"),
	HX_CSTRING("key"),
	HX_CSTRING("keyChar"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_STANDARD,"DOM_KEY_LOCATION_STANDARD");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_LEFT,"DOM_KEY_LOCATION_LEFT");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_RIGHT,"DOM_KEY_LOCATION_RIGHT");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_NUMPAD,"DOM_KEY_LOCATION_NUMPAD");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_MOBILE,"DOM_KEY_LOCATION_MOBILE");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_JOYSTICK,"DOM_KEY_LOCATION_JOYSTICK");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_STANDARD,"DOM_KEY_LOCATION_STANDARD");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_LEFT,"DOM_KEY_LOCATION_LEFT");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_RIGHT,"DOM_KEY_LOCATION_RIGHT");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_NUMPAD,"DOM_KEY_LOCATION_NUMPAD");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_MOBILE,"DOM_KEY_LOCATION_MOBILE");
	HX_VISIT_MEMBER_NAME(KeyboardEvent_obj::DOM_KEY_LOCATION_JOYSTICK,"DOM_KEY_LOCATION_JOYSTICK");
};

Class KeyboardEvent_obj::__mClass;

void KeyboardEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.KeyboardEvent"), hx::TCanCast< KeyboardEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void KeyboardEvent_obj::__boot()
{
	DOM_KEY_LOCATION_STANDARD= (int)0;
	DOM_KEY_LOCATION_LEFT= (int)1;
	DOM_KEY_LOCATION_RIGHT= (int)2;
	DOM_KEY_LOCATION_NUMPAD= (int)3;
	DOM_KEY_LOCATION_MOBILE= (int)4;
	DOM_KEY_LOCATION_JOYSTICK= (int)5;
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
