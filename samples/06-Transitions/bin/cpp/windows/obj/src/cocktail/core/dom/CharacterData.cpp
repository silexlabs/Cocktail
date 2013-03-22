#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void CharacterData_obj::__construct()
{
HX_STACK_PUSH("CharacterData::new","cocktail/core/dom/CharacterData.hx",40);
{
	HX_STACK_LINE(40)
	super::__construct(HX_CSTRING(""));
}
;
	return null();
}

CharacterData_obj::~CharacterData_obj() { }

Dynamic CharacterData_obj::__CreateEmpty() { return  new CharacterData_obj; }
hx::ObjectPtr< CharacterData_obj > CharacterData_obj::__new()
{  hx::ObjectPtr< CharacterData_obj > result = new CharacterData_obj();
	result->__construct();
	return result;}

Dynamic CharacterData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CharacterData_obj > result = new CharacterData_obj();
	result->__construct();
	return result;}

::String CharacterData_obj::set_nodeValue( ::String value){
	HX_STACK_PUSH("CharacterData::set_nodeValue","cocktail/core/dom/CharacterData.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(147)
	return this->data = value;
}


::String CharacterData_obj::get_nodeValue( ){
	HX_STACK_PUSH("CharacterData::get_nodeValue","cocktail/core/dom/CharacterData.hx",142);
	HX_STACK_THIS(this);
	HX_STACK_LINE(142)
	return this->data;
}


Void CharacterData_obj::endPendingAnimation( ){
{
		HX_STACK_PUSH("CharacterData::endPendingAnimation","cocktail/core/dom/CharacterData.hx",133);
		HX_STACK_THIS(this);
	}
return null();
}


bool CharacterData_obj::startPendingAnimation( ){
	HX_STACK_PUSH("CharacterData::startPendingAnimation","cocktail/core/dom/CharacterData.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_LINE(124)
	return false;
}


Void CharacterData_obj::init( ){
{
		HX_STACK_PUSH("CharacterData::init","cocktail/core/dom/CharacterData.hx",115);
		HX_STACK_THIS(this);
	}
return null();
}


Void CharacterData_obj::getStyleDeclaration( ){
{
		HX_STACK_PUSH("CharacterData::getStyleDeclaration","cocktail/core/dom/CharacterData.hx",106);
		HX_STACK_THIS(this);
	}
return null();
}


bool CharacterData_obj::hasAttributes( ){
	HX_STACK_PUSH("CharacterData::hasAttributes","cocktail/core/dom/CharacterData.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_LINE(94)
	return false;
}


bool CharacterData_obj::hasChildNodes( ){
	HX_STACK_PUSH("CharacterData::hasChildNodes","cocktail/core/dom/CharacterData.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_LINE(86)
	return false;
}


Void CharacterData_obj::invalidateCascade( ){
{
		HX_STACK_PUSH("CharacterData::invalidateCascade","cocktail/core/dom/CharacterData.hx",78);
		HX_STACK_THIS(this);
	}
return null();
}


Void CharacterData_obj::cascade( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange){
{
		HX_STACK_PUSH("CharacterData::cascade","cocktail/core/dom/CharacterData.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cascadeManager,"cascadeManager");
		HX_STACK_ARG(programmaticChange,"programmaticChange");
	}
return null();
}


Void CharacterData_obj::initAttributes( ){
{
		HX_STACK_PUSH("CharacterData::initAttributes","cocktail/core/dom/CharacterData.hx",56);
		HX_STACK_THIS(this);
	}
return null();
}


Void CharacterData_obj::initChildNodes( ){
{
		HX_STACK_PUSH("CharacterData::initChildNodes","cocktail/core/dom/CharacterData.hx",48);
		HX_STACK_THIS(this);
	}
return null();
}



CharacterData_obj::CharacterData_obj()
{
}

void CharacterData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharacterData);
	HX_MARK_MEMBER_NAME(data,"data");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CharacterData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CharacterData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cascade") ) { return cascade_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAttributes") ) { return hasAttributes_dyn(); }
		if (HX_FIELD_EQ(inName,"hasChildNodes") ) { return hasChildNodes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initAttributes") ) { return initAttributes_dyn(); }
		if (HX_FIELD_EQ(inName,"initChildNodes") ) { return initChildNodes_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"invalidateCascade") ) { return invalidateCascade_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endPendingAnimation") ) { return endPendingAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"getStyleDeclaration") ) { return getStyleDeclaration_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"startPendingAnimation") ) { return startPendingAnimation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CharacterData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CharacterData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_nodeValue"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("endPendingAnimation"),
	HX_CSTRING("startPendingAnimation"),
	HX_CSTRING("init"),
	HX_CSTRING("getStyleDeclaration"),
	HX_CSTRING("hasAttributes"),
	HX_CSTRING("hasChildNodes"),
	HX_CSTRING("invalidateCascade"),
	HX_CSTRING("cascade"),
	HX_CSTRING("initAttributes"),
	HX_CSTRING("initChildNodes"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CharacterData_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CharacterData_obj::__mClass,"__mClass");
};

Class CharacterData_obj::__mClass;

void CharacterData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.CharacterData"), hx::TCanCast< CharacterData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CharacterData_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
