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
#ifndef INCLUDED_cocktail_core_keyboard_AbstractKeyboard
#include <cocktail/core/keyboard/AbstractKeyboard.h>
#endif
namespace cocktail{
namespace core{
namespace keyboard{

Void AbstractKeyboard_obj::__construct(::cocktail::core::html::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",61)
	this->_htmlElement = htmlElement;
}
;
	return null();
}

AbstractKeyboard_obj::~AbstractKeyboard_obj() { }

Dynamic AbstractKeyboard_obj::__CreateEmpty() { return  new AbstractKeyboard_obj; }
hx::ObjectPtr< AbstractKeyboard_obj > AbstractKeyboard_obj::__new(::cocktail::core::html::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractKeyboard_obj > result = new AbstractKeyboard_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractKeyboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractKeyboard_obj > result = new AbstractKeyboard_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractKeyboard_obj::onNativeKeyDown( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractKeyboard_obj::onNativeKeyDown")
		HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",75)
		if (((this->getOnKeyDown() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",77)
			this->getOnKeyDown()(this->getKeyData(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,onNativeKeyDown,(void))

Void AbstractKeyboard_obj::onNativeKeyUp( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractKeyboard_obj::onNativeKeyUp")
		HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",88)
		if (((this->getOnKeyUp() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",90)
			this->getOnKeyUp()(this->getKeyData(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,onNativeKeyUp,(void))

Dynamic AbstractKeyboard_obj::setOnKeyDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::setOnKeyDown")
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",101)
	this->updateListeners(this->_keyDownEvent,this->onNativeKeyDown_dyn(),value);
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",102)
	return this->_onKeyDown = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,setOnKeyDown,return )

Dynamic AbstractKeyboard_obj::getOnKeyDown( ){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getOnKeyDown")
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",106)
	return this->_onKeyDown_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractKeyboard_obj,getOnKeyDown,return )

Dynamic AbstractKeyboard_obj::setOnKeyUp( Dynamic value){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::setOnKeyUp")
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",112)
	this->updateListeners(this->_keyUpEvent,this->onNativeKeyUp_dyn(),value);
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",113)
	return this->_onKeyUp = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,setOnKeyUp,return )

Dynamic AbstractKeyboard_obj::getOnKeyUp( ){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getOnKeyUp")
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",117)
	return this->_onKeyUp_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractKeyboard_obj,getOnKeyUp,return )

Void AbstractKeyboard_obj::updateListeners( ::String keyboardEvent,Dynamic nativeCallback,Dynamic htmlElementCallback){
{
		HX_SOURCE_PUSH("AbstractKeyboard_obj::updateListeners")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractKeyboard_obj,updateListeners,(void))

::cocktail::core::event::KeyboardEvent AbstractKeyboard_obj::getKeyData( Dynamic event){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getKeyData")
	HX_SOURCE_POS("../../src/cocktail/core/keyboard/AbstractKeyboard.hx",144)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,getKeyData,return )


AbstractKeyboard_obj::AbstractKeyboard_obj()
{
}

void AbstractKeyboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractKeyboard);
	HX_MARK_MEMBER_NAME(_onKeyDown,"_onKeyDown");
	HX_MARK_MEMBER_NAME(onKeyDown,"onKeyDown");
	HX_MARK_MEMBER_NAME(_onKeyUp,"_onKeyUp");
	HX_MARK_MEMBER_NAME(onKeyUp,"onKeyUp");
	HX_MARK_MEMBER_NAME(_htmlElement,"_htmlElement");
	HX_MARK_MEMBER_NAME(_keyDownEvent,"_keyDownEvent");
	HX_MARK_MEMBER_NAME(_keyUpEvent,"_keyUpEvent");
	HX_MARK_END_CLASS();
}

Dynamic AbstractKeyboard_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return getOnKeyUp(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onKeyUp") ) { return _onKeyUp; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return getOnKeyDown(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { return _onKeyDown; }
		if (HX_FIELD_EQ(inName,"setOnKeyUp") ) { return setOnKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnKeyUp") ) { return getOnKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"getKeyData") ) { return getKeyData_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_keyUpEvent") ) { return _keyUpEvent; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { return _htmlElement; }
		if (HX_FIELD_EQ(inName,"setOnKeyDown") ) { return setOnKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnKeyDown") ) { return getOnKeyDown_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_keyDownEvent") ) { return _keyDownEvent; }
		if (HX_FIELD_EQ(inName,"onNativeKeyUp") ) { return onNativeKeyUp_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onNativeKeyDown") ) { return onNativeKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"updateListeners") ) { return updateListeners_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractKeyboard_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return setOnKeyUp(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onKeyUp") ) { _onKeyUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return setOnKeyDown(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { _onKeyDown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_keyUpEvent") ) { _keyUpEvent=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { _htmlElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_keyDownEvent") ) { _keyDownEvent=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractKeyboard_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_htmlElement"));
	outFields->push(HX_CSTRING("_keyDownEvent"));
	outFields->push(HX_CSTRING("_keyUpEvent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_onKeyDown"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("_onKeyUp"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("_htmlElement"),
	HX_CSTRING("_keyDownEvent"),
	HX_CSTRING("_keyUpEvent"),
	HX_CSTRING("onNativeKeyDown"),
	HX_CSTRING("onNativeKeyUp"),
	HX_CSTRING("setOnKeyDown"),
	HX_CSTRING("getOnKeyDown"),
	HX_CSTRING("setOnKeyUp"),
	HX_CSTRING("getOnKeyUp"),
	HX_CSTRING("updateListeners"),
	HX_CSTRING("getKeyData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractKeyboard_obj::__mClass;

void AbstractKeyboard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.keyboard.AbstractKeyboard"), hx::TCanCast< AbstractKeyboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractKeyboard_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace keyboard
