#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void KeyboardEvent_obj::__construct(::String type,::cocktail::core::html::HTMLElement target,double detail,int keyChar,int key,bool ctrlKey,bool shiftKey,bool altKey)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",65)
	super::__construct(type,target,detail);
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",67)
	this->_keyChar = keyChar;
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",68)
	this->_key = key;
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",69)
	this->_ctrlKey = ctrlKey;
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",70)
	this->_shiftKey = shiftKey;
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",71)
	this->_altKey = altKey;
}
;
	return null();
}

KeyboardEvent_obj::~KeyboardEvent_obj() { }

Dynamic KeyboardEvent_obj::__CreateEmpty() { return  new KeyboardEvent_obj; }
hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__new(::String type,::cocktail::core::html::HTMLElement target,double detail,int keyChar,int key,bool ctrlKey,bool shiftKey,bool altKey)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(type,target,detail,keyChar,key,ctrlKey,shiftKey,altKey);
	return result;}

Dynamic KeyboardEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

bool KeyboardEvent_obj::get_altKey( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::get_altKey")
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",79)
	return this->_altKey;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,get_altKey,return )

bool KeyboardEvent_obj::get_shiftKey( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::get_shiftKey")
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",84)
	return this->_shiftKey;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,get_shiftKey,return )

bool KeyboardEvent_obj::get_ctrlKey( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::get_ctrlKey")
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",89)
	return this->_ctrlKey;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,get_ctrlKey,return )

int KeyboardEvent_obj::get_keyChar( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::get_keyChar")
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",94)
	return this->_keyChar;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,get_keyChar,return )

int KeyboardEvent_obj::get_key( ){
	HX_SOURCE_PUSH("KeyboardEvent_obj::get_key")
	HX_SOURCE_POS("../../src/cocktail/core/event/KeyboardEvent.hx",99)
	return this->_key;
}


HX_DEFINE_DYNAMIC_FUNC0(KeyboardEvent_obj,get_key,return )

::String KeyboardEvent_obj::KEY_DOWN;

::String KeyboardEvent_obj::KEY_UP;


KeyboardEvent_obj::KeyboardEvent_obj()
{
}

void KeyboardEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(KeyboardEvent);
	HX_MARK_MEMBER_NAME(_keyChar,"_keyChar");
	HX_MARK_MEMBER_NAME(keyChar,"keyChar");
	HX_MARK_MEMBER_NAME(_key,"_key");
	HX_MARK_MEMBER_NAME(key,"key");
	HX_MARK_MEMBER_NAME(_ctrlKey,"_ctrlKey");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(_shiftKey,"_shiftKey");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	HX_MARK_MEMBER_NAME(_altKey,"_altKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic KeyboardEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"key") ) { return get_key(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_key") ) { return _key; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { return KEY_UP; }
		if (HX_FIELD_EQ(inName,"altKey") ) { return get_altKey(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"keyChar") ) { return get_keyChar(); }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return get_ctrlKey(); }
		if (HX_FIELD_EQ(inName,"_altKey") ) { return _altKey; }
		if (HX_FIELD_EQ(inName,"get_key") ) { return get_key_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { return KEY_DOWN; }
		if (HX_FIELD_EQ(inName,"_keyChar") ) { return _keyChar; }
		if (HX_FIELD_EQ(inName,"_ctrlKey") ) { return _ctrlKey; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return get_shiftKey(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_shiftKey") ) { return _shiftKey; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_altKey") ) { return get_altKey_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_ctrlKey") ) { return get_ctrlKey_dyn(); }
		if (HX_FIELD_EQ(inName,"get_keyChar") ) { return get_keyChar_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_shiftKey") ) { return get_shiftKey_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic KeyboardEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"key") ) { key=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_key") ) { _key=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { KEY_UP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"keyChar") ) { keyChar=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_altKey") ) { _altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { KEY_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_keyChar") ) { _keyChar=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_ctrlKey") ) { _ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_shiftKey") ) { _shiftKey=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyboardEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_keyChar"));
	outFields->push(HX_CSTRING("keyChar"));
	outFields->push(HX_CSTRING("_key"));
	outFields->push(HX_CSTRING("key"));
	outFields->push(HX_CSTRING("_ctrlKey"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("_shiftKey"));
	outFields->push(HX_CSTRING("shiftKey"));
	outFields->push(HX_CSTRING("_altKey"));
	outFields->push(HX_CSTRING("altKey"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("KEY_DOWN"),
	HX_CSTRING("KEY_UP"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_keyChar"),
	HX_CSTRING("keyChar"),
	HX_CSTRING("_key"),
	HX_CSTRING("key"),
	HX_CSTRING("_ctrlKey"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("_shiftKey"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("_altKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("get_altKey"),
	HX_CSTRING("get_shiftKey"),
	HX_CSTRING("get_ctrlKey"),
	HX_CSTRING("get_keyChar"),
	HX_CSTRING("get_key"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_DOWN,"KEY_DOWN");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_UP,"KEY_UP");
};

Class KeyboardEvent_obj::__mClass;

void KeyboardEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.KeyboardEvent"), hx::TCanCast< KeyboardEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyboardEvent_obj::__boot()
{
	hx::Static(KEY_DOWN) = HX_CSTRING("keydown");
	hx::Static(KEY_UP) = HX_CSTRING("keyup");
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
