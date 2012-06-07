#include <hxcpp.h>

#ifndef INCLUDED_cocktailCore_focus_FocusManager
#include <cocktailCore/focus/FocusManager.h>
#endif
#ifndef INCLUDED_cocktailCore_focus_abstract_AbstractFocusManagerImpl
#include <cocktailCore/focus/abstract/AbstractFocusManagerImpl.h>
#endif
#ifndef INCLUDED_cocktailCore_focus_as3_FocusManagerImpl
#include <cocktailCore/focus/as3/FocusManagerImpl.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_HTMLBodyElement
#include <core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace cocktailCore{
namespace focus{

Void FocusManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",71)
	this->_focusManagerImpl = ::cocktailCore::focus::as3::FocusManagerImpl_obj::__new();
}
;
	return null();
}

FocusManager_obj::~FocusManager_obj() { }

Dynamic FocusManager_obj::__CreateEmpty() { return  new FocusManager_obj; }
hx::ObjectPtr< FocusManager_obj > FocusManager_obj::__new()
{  hx::ObjectPtr< FocusManager_obj > result = new FocusManager_obj();
	result->__construct();
	return result;}

Dynamic FocusManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FocusManager_obj > result = new FocusManager_obj();
	result->__construct();
	return result;}

Void FocusManager_obj::invalidate( ){
{
		HX_SOURCE_PUSH("FocusManager_obj::invalidate")
		HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",97)
		this->_focusManagerImpl->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FocusManager_obj,invalidate,(void))

::port::flash_player::HTMLElement FocusManager_obj::setActiveElement( ::port::flash_player::HTMLElement value){
	HX_SOURCE_PUSH("FocusManager_obj::setActiveElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",107)
	return this->_focusManagerImpl->setActiveElement(value);
}


HX_DEFINE_DYNAMIC_FUNC1(FocusManager_obj,setActiveElement,return )

::port::flash_player::HTMLElement FocusManager_obj::getActiveElement( ){
	HX_SOURCE_PUSH("FocusManager_obj::getActiveElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",112)
	return this->_focusManagerImpl->getActiveElement();
}


HX_DEFINE_DYNAMIC_FUNC0(FocusManager_obj,getActiveElement,return )

::core::html::HTMLBodyElement FocusManager_obj::setBodyElement( ::core::html::HTMLBodyElement value){
	HX_SOURCE_PUSH("FocusManager_obj::setBodyElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",117)
	return this->_focusManagerImpl->setBodyElement(value);
}


HX_DEFINE_DYNAMIC_FUNC1(FocusManager_obj,setBodyElement,return )

::core::html::HTMLBodyElement FocusManager_obj::getBodyElement( ){
	HX_SOURCE_PUSH("FocusManager_obj::getBodyElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",122)
	return this->_focusManagerImpl->getBodyElement();
}


HX_DEFINE_DYNAMIC_FUNC0(FocusManager_obj,getBodyElement,return )

::cocktailCore::focus::FocusManager FocusManager_obj::_instance;

::cocktailCore::focus::FocusManager FocusManager_obj::getInstance( ){
	HX_SOURCE_PUSH("FocusManager_obj::getInstance")
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",80)
	if (((::cocktailCore::focus::FocusManager_obj::_instance == null()))){
		HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",81)
		::cocktailCore::focus::FocusManager_obj::_instance = ::cocktailCore::focus::FocusManager_obj::__new();
	}
	HX_SOURCE_POS("../../src/cocktailCore/focus/FocusManager.hx",84)
	return ::cocktailCore::focus::FocusManager_obj::_instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FocusManager_obj,getInstance,return )


FocusManager_obj::FocusManager_obj()
{
}

void FocusManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FocusManager);
	HX_MARK_MEMBER_NAME(bodyElement,"bodyElement");
	HX_MARK_MEMBER_NAME(activeElement,"activeElement");
	HX_MARK_MEMBER_NAME(_focusManagerImpl,"_focusManagerImpl");
	HX_MARK_END_CLASS();
}

Dynamic FocusManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { return _instance; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"bodyElement") ) { return getBodyElement(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return getActiveElement(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setBodyElement") ) { return setBodyElement_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyElement") ) { return getBodyElement_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setActiveElement") ) { return setActiveElement_dyn(); }
		if (HX_FIELD_EQ(inName,"getActiveElement") ) { return getActiveElement_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_focusManagerImpl") ) { return _focusManagerImpl; }
	}
	return super::__Field(inName);
}

Dynamic FocusManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { _instance=inValue.Cast< ::cocktailCore::focus::FocusManager >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bodyElement") ) { return setBodyElement(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return setActiveElement(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_focusManagerImpl") ) { _focusManagerImpl=inValue.Cast< ::cocktailCore::focus::as3::FocusManagerImpl >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FocusManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bodyElement"));
	outFields->push(HX_CSTRING("activeElement"));
	outFields->push(HX_CSTRING("_focusManagerImpl"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bodyElement"),
	HX_CSTRING("activeElement"),
	HX_CSTRING("_focusManagerImpl"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("setActiveElement"),
	HX_CSTRING("getActiveElement"),
	HX_CSTRING("setBodyElement"),
	HX_CSTRING("getBodyElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FocusManager_obj::_instance,"_instance");
};

Class FocusManager_obj::__mClass;

void FocusManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktailCore.focus.FocusManager"), hx::TCanCast< FocusManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FocusManager_obj::__boot()
{
	hx::Static(_instance);
}

} // end namespace cocktailCore
} // end namespace focus
