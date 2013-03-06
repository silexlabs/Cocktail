#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_DOMConstants
#include <cocktail/core/dom/DOMConstants.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void DOMConstants_obj::__construct()
{
HX_STACK_PUSH("DOMConstants::new","cocktail/core/dom/DOMConstants.hx",76);
{
}
;
	return null();
}

DOMConstants_obj::~DOMConstants_obj() { }

Dynamic DOMConstants_obj::__CreateEmpty() { return  new DOMConstants_obj; }
hx::ObjectPtr< DOMConstants_obj > DOMConstants_obj::__new()
{  hx::ObjectPtr< DOMConstants_obj > result = new DOMConstants_obj();
	result->__construct();
	return result;}

Dynamic DOMConstants_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DOMConstants_obj > result = new DOMConstants_obj();
	result->__construct();
	return result;}

int DOMConstants_obj::ELEMENT_NODE;

int DOMConstants_obj::ATTRIBUTE_NODE;

int DOMConstants_obj::TEXT_NODE;

int DOMConstants_obj::CDATA_SECTION_NODE;

int DOMConstants_obj::ENTITY_REFERENCE_NODE;

int DOMConstants_obj::ENTITY_NODE;

int DOMConstants_obj::PROCESSING_INSTRUCTION_NODE;

int DOMConstants_obj::COMMENT_NODE;

int DOMConstants_obj::DOCUMENT_NODE;

int DOMConstants_obj::DOCUMENT_TYPE_NODE;

int DOMConstants_obj::DOCUMENT_FRAGMENT_NODE;

int DOMConstants_obj::NOTATION_NODE;

::String DOMConstants_obj::EVENT_INTERFACE;

::String DOMConstants_obj::UI_EVENT_INTERFACE;

::String DOMConstants_obj::MOUSE_EVENT_INTERFACE;

::String DOMConstants_obj::FOCUS_EVENT_INTERFACE;

::String DOMConstants_obj::KEYBOARD_EVENT_INTERFACE;

::String DOMConstants_obj::WHEEL_EVENT_INTERFACE;

::String DOMConstants_obj::CUSTOM_EVENT_INTERFACE;

::String DOMConstants_obj::TRANSITION_EVENT_INTERFACE;

::String DOMConstants_obj::POPSTATE_EVENT_INTERFACE;

::String DOMConstants_obj::MATCH_ALL_TAG_NAME;

::String DOMConstants_obj::TEXT_NODE_NAME;


DOMConstants_obj::DOMConstants_obj()
{
}

void DOMConstants_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DOMConstants);
	HX_MARK_END_CLASS();
}

void DOMConstants_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic DOMConstants_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"TEXT_NODE") ) { return TEXT_NODE; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ENTITY_NODE") ) { return ENTITY_NODE; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ELEMENT_NODE") ) { return ELEMENT_NODE; }
		if (HX_FIELD_EQ(inName,"COMMENT_NODE") ) { return COMMENT_NODE; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DOCUMENT_NODE") ) { return DOCUMENT_NODE; }
		if (HX_FIELD_EQ(inName,"NOTATION_NODE") ) { return NOTATION_NODE; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ATTRIBUTE_NODE") ) { return ATTRIBUTE_NODE; }
		if (HX_FIELD_EQ(inName,"TEXT_NODE_NAME") ) { return TEXT_NODE_NAME; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"EVENT_INTERFACE") ) { return EVENT_INTERFACE; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"CDATA_SECTION_NODE") ) { return CDATA_SECTION_NODE; }
		if (HX_FIELD_EQ(inName,"DOCUMENT_TYPE_NODE") ) { return DOCUMENT_TYPE_NODE; }
		if (HX_FIELD_EQ(inName,"UI_EVENT_INTERFACE") ) { return UI_EVENT_INTERFACE; }
		if (HX_FIELD_EQ(inName,"MATCH_ALL_TAG_NAME") ) { return MATCH_ALL_TAG_NAME; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"ENTITY_REFERENCE_NODE") ) { return ENTITY_REFERENCE_NODE; }
		if (HX_FIELD_EQ(inName,"MOUSE_EVENT_INTERFACE") ) { return MOUSE_EVENT_INTERFACE; }
		if (HX_FIELD_EQ(inName,"FOCUS_EVENT_INTERFACE") ) { return FOCUS_EVENT_INTERFACE; }
		if (HX_FIELD_EQ(inName,"WHEEL_EVENT_INTERFACE") ) { return WHEEL_EVENT_INTERFACE; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"DOCUMENT_FRAGMENT_NODE") ) { return DOCUMENT_FRAGMENT_NODE; }
		if (HX_FIELD_EQ(inName,"CUSTOM_EVENT_INTERFACE") ) { return CUSTOM_EVENT_INTERFACE; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"KEYBOARD_EVENT_INTERFACE") ) { return KEYBOARD_EVENT_INTERFACE; }
		if (HX_FIELD_EQ(inName,"POPSTATE_EVENT_INTERFACE") ) { return POPSTATE_EVENT_INTERFACE; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"TRANSITION_EVENT_INTERFACE") ) { return TRANSITION_EVENT_INTERFACE; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"PROCESSING_INSTRUCTION_NODE") ) { return PROCESSING_INSTRUCTION_NODE; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DOMConstants_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"TEXT_NODE") ) { TEXT_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ENTITY_NODE") ) { ENTITY_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ELEMENT_NODE") ) { ELEMENT_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"COMMENT_NODE") ) { COMMENT_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DOCUMENT_NODE") ) { DOCUMENT_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NOTATION_NODE") ) { NOTATION_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ATTRIBUTE_NODE") ) { ATTRIBUTE_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TEXT_NODE_NAME") ) { TEXT_NODE_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"EVENT_INTERFACE") ) { EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"CDATA_SECTION_NODE") ) { CDATA_SECTION_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOCUMENT_TYPE_NODE") ) { DOCUMENT_TYPE_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"UI_EVENT_INTERFACE") ) { UI_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MATCH_ALL_TAG_NAME") ) { MATCH_ALL_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"ENTITY_REFERENCE_NODE") ) { ENTITY_REFERENCE_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_EVENT_INTERFACE") ) { MOUSE_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FOCUS_EVENT_INTERFACE") ) { FOCUS_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WHEEL_EVENT_INTERFACE") ) { WHEEL_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"DOCUMENT_FRAGMENT_NODE") ) { DOCUMENT_FRAGMENT_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CUSTOM_EVENT_INTERFACE") ) { CUSTOM_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"KEYBOARD_EVENT_INTERFACE") ) { KEYBOARD_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POPSTATE_EVENT_INTERFACE") ) { POPSTATE_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"TRANSITION_EVENT_INTERFACE") ) { TRANSITION_EVENT_INTERFACE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"PROCESSING_INSTRUCTION_NODE") ) { PROCESSING_INSTRUCTION_NODE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DOMConstants_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ELEMENT_NODE"),
	HX_CSTRING("ATTRIBUTE_NODE"),
	HX_CSTRING("TEXT_NODE"),
	HX_CSTRING("CDATA_SECTION_NODE"),
	HX_CSTRING("ENTITY_REFERENCE_NODE"),
	HX_CSTRING("ENTITY_NODE"),
	HX_CSTRING("PROCESSING_INSTRUCTION_NODE"),
	HX_CSTRING("COMMENT_NODE"),
	HX_CSTRING("DOCUMENT_NODE"),
	HX_CSTRING("DOCUMENT_TYPE_NODE"),
	HX_CSTRING("DOCUMENT_FRAGMENT_NODE"),
	HX_CSTRING("NOTATION_NODE"),
	HX_CSTRING("EVENT_INTERFACE"),
	HX_CSTRING("UI_EVENT_INTERFACE"),
	HX_CSTRING("MOUSE_EVENT_INTERFACE"),
	HX_CSTRING("FOCUS_EVENT_INTERFACE"),
	HX_CSTRING("KEYBOARD_EVENT_INTERFACE"),
	HX_CSTRING("WHEEL_EVENT_INTERFACE"),
	HX_CSTRING("CUSTOM_EVENT_INTERFACE"),
	HX_CSTRING("TRANSITION_EVENT_INTERFACE"),
	HX_CSTRING("POPSTATE_EVENT_INTERFACE"),
	HX_CSTRING("MATCH_ALL_TAG_NAME"),
	HX_CSTRING("TEXT_NODE_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DOMConstants_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::ELEMENT_NODE,"ELEMENT_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::ATTRIBUTE_NODE,"ATTRIBUTE_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::TEXT_NODE,"TEXT_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::CDATA_SECTION_NODE,"CDATA_SECTION_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::ENTITY_REFERENCE_NODE,"ENTITY_REFERENCE_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::ENTITY_NODE,"ENTITY_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::PROCESSING_INSTRUCTION_NODE,"PROCESSING_INSTRUCTION_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::COMMENT_NODE,"COMMENT_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::DOCUMENT_NODE,"DOCUMENT_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::DOCUMENT_TYPE_NODE,"DOCUMENT_TYPE_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::DOCUMENT_FRAGMENT_NODE,"DOCUMENT_FRAGMENT_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::NOTATION_NODE,"NOTATION_NODE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::EVENT_INTERFACE,"EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::UI_EVENT_INTERFACE,"UI_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::MOUSE_EVENT_INTERFACE,"MOUSE_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::FOCUS_EVENT_INTERFACE,"FOCUS_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::KEYBOARD_EVENT_INTERFACE,"KEYBOARD_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::WHEEL_EVENT_INTERFACE,"WHEEL_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::CUSTOM_EVENT_INTERFACE,"CUSTOM_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::TRANSITION_EVENT_INTERFACE,"TRANSITION_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::POPSTATE_EVENT_INTERFACE,"POPSTATE_EVENT_INTERFACE");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::MATCH_ALL_TAG_NAME,"MATCH_ALL_TAG_NAME");
	HX_MARK_MEMBER_NAME(DOMConstants_obj::TEXT_NODE_NAME,"TEXT_NODE_NAME");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::ELEMENT_NODE,"ELEMENT_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::ATTRIBUTE_NODE,"ATTRIBUTE_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::TEXT_NODE,"TEXT_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::CDATA_SECTION_NODE,"CDATA_SECTION_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::ENTITY_REFERENCE_NODE,"ENTITY_REFERENCE_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::ENTITY_NODE,"ENTITY_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::PROCESSING_INSTRUCTION_NODE,"PROCESSING_INSTRUCTION_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::COMMENT_NODE,"COMMENT_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::DOCUMENT_NODE,"DOCUMENT_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::DOCUMENT_TYPE_NODE,"DOCUMENT_TYPE_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::DOCUMENT_FRAGMENT_NODE,"DOCUMENT_FRAGMENT_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::NOTATION_NODE,"NOTATION_NODE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::EVENT_INTERFACE,"EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::UI_EVENT_INTERFACE,"UI_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::MOUSE_EVENT_INTERFACE,"MOUSE_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::FOCUS_EVENT_INTERFACE,"FOCUS_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::KEYBOARD_EVENT_INTERFACE,"KEYBOARD_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::WHEEL_EVENT_INTERFACE,"WHEEL_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::CUSTOM_EVENT_INTERFACE,"CUSTOM_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::TRANSITION_EVENT_INTERFACE,"TRANSITION_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::POPSTATE_EVENT_INTERFACE,"POPSTATE_EVENT_INTERFACE");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::MATCH_ALL_TAG_NAME,"MATCH_ALL_TAG_NAME");
	HX_VISIT_MEMBER_NAME(DOMConstants_obj::TEXT_NODE_NAME,"TEXT_NODE_NAME");
};

Class DOMConstants_obj::__mClass;

void DOMConstants_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.DOMConstants"), hx::TCanCast< DOMConstants_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DOMConstants_obj::__boot()
{
	ELEMENT_NODE= (int)1;
	ATTRIBUTE_NODE= (int)2;
	TEXT_NODE= (int)3;
	CDATA_SECTION_NODE= (int)4;
	ENTITY_REFERENCE_NODE= (int)5;
	ENTITY_NODE= (int)6;
	PROCESSING_INSTRUCTION_NODE= (int)7;
	COMMENT_NODE= (int)8;
	DOCUMENT_NODE= (int)9;
	DOCUMENT_TYPE_NODE= (int)10;
	DOCUMENT_FRAGMENT_NODE= (int)11;
	NOTATION_NODE= (int)11;
	EVENT_INTERFACE= HX_CSTRING("Event");
	UI_EVENT_INTERFACE= HX_CSTRING("UIEvent");
	MOUSE_EVENT_INTERFACE= HX_CSTRING("MouseEvent");
	FOCUS_EVENT_INTERFACE= HX_CSTRING("FocusEvent");
	KEYBOARD_EVENT_INTERFACE= HX_CSTRING("KeyboardEvent");
	WHEEL_EVENT_INTERFACE= HX_CSTRING("WheelEvent");
	CUSTOM_EVENT_INTERFACE= HX_CSTRING("CustomEvent");
	TRANSITION_EVENT_INTERFACE= HX_CSTRING("TransitionEvent");
	POPSTATE_EVENT_INTERFACE= HX_CSTRING("PopStateEvent");
	MATCH_ALL_TAG_NAME= HX_CSTRING("*");
	TEXT_NODE_NAME= HX_CSTRING("#text");
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
