#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_DOMException
#include <cocktail/core/dom/DOMException.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void DOMException_obj::__construct()
{
{
}
;
	return null();
}

DOMException_obj::~DOMException_obj() { }

Dynamic DOMException_obj::__CreateEmpty() { return  new DOMException_obj; }
hx::ObjectPtr< DOMException_obj > DOMException_obj::__new()
{  hx::ObjectPtr< DOMException_obj > result = new DOMException_obj();
	result->__construct();
	return result;}

Dynamic DOMException_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DOMException_obj > result = new DOMException_obj();
	result->__construct();
	return result;}

int DOMException_obj::INDEX_SIZE_ERR;

int DOMException_obj::DOMSTRING_SIZE_ERR;

int DOMException_obj::HIERARCHY_REQUEST_ERR;

int DOMException_obj::WRONG_DOCUMENT_ERR;

int DOMException_obj::INVALID_CHARACTER_ERR;

int DOMException_obj::NO_DATA_ALLOWED_ERR;

int DOMException_obj::NO_MODIFICATION_ALLOWED_ERR;

int DOMException_obj::NOT_FOUND_ERR;

int DOMException_obj::NOT_SUPPORTED_ERR;

int DOMException_obj::INUSE_ATTRIBUTE_ERR;

int DOMException_obj::INVALID_STATE_ERR;

int DOMException_obj::SYNTAX_ERR;

int DOMException_obj::INVALID_MODIFICATION_ERR;

int DOMException_obj::NAMESPACE_ERR;

int DOMException_obj::INVALID_ACCESS_ERR;

int DOMException_obj::VALIDATION_ERR;

int DOMException_obj::TYPE_MISMATCH_ERR;


DOMException_obj::DOMException_obj()
{
}

void DOMException_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DOMException);
	HX_MARK_END_CLASS();
}

Dynamic DOMException_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"SYNTAX_ERR") ) { return SYNTAX_ERR; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"NOT_FOUND_ERR") ) { return NOT_FOUND_ERR; }
		if (HX_FIELD_EQ(inName,"NAMESPACE_ERR") ) { return NAMESPACE_ERR; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"INDEX_SIZE_ERR") ) { return INDEX_SIZE_ERR; }
		if (HX_FIELD_EQ(inName,"VALIDATION_ERR") ) { return VALIDATION_ERR; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"NOT_SUPPORTED_ERR") ) { return NOT_SUPPORTED_ERR; }
		if (HX_FIELD_EQ(inName,"INVALID_STATE_ERR") ) { return INVALID_STATE_ERR; }
		if (HX_FIELD_EQ(inName,"TYPE_MISMATCH_ERR") ) { return TYPE_MISMATCH_ERR; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"DOMSTRING_SIZE_ERR") ) { return DOMSTRING_SIZE_ERR; }
		if (HX_FIELD_EQ(inName,"WRONG_DOCUMENT_ERR") ) { return WRONG_DOCUMENT_ERR; }
		if (HX_FIELD_EQ(inName,"INVALID_ACCESS_ERR") ) { return INVALID_ACCESS_ERR; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"NO_DATA_ALLOWED_ERR") ) { return NO_DATA_ALLOWED_ERR; }
		if (HX_FIELD_EQ(inName,"INUSE_ATTRIBUTE_ERR") ) { return INUSE_ATTRIBUTE_ERR; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"HIERARCHY_REQUEST_ERR") ) { return HIERARCHY_REQUEST_ERR; }
		if (HX_FIELD_EQ(inName,"INVALID_CHARACTER_ERR") ) { return INVALID_CHARACTER_ERR; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"INVALID_MODIFICATION_ERR") ) { return INVALID_MODIFICATION_ERR; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"NO_MODIFICATION_ALLOWED_ERR") ) { return NO_MODIFICATION_ALLOWED_ERR; }
	}
	return super::__Field(inName);
}

Dynamic DOMException_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"SYNTAX_ERR") ) { SYNTAX_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"NOT_FOUND_ERR") ) { NOT_FOUND_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NAMESPACE_ERR") ) { NAMESPACE_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"INDEX_SIZE_ERR") ) { INDEX_SIZE_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"VALIDATION_ERR") ) { VALIDATION_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"NOT_SUPPORTED_ERR") ) { NOT_SUPPORTED_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"INVALID_STATE_ERR") ) { INVALID_STATE_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TYPE_MISMATCH_ERR") ) { TYPE_MISMATCH_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"DOMSTRING_SIZE_ERR") ) { DOMSTRING_SIZE_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WRONG_DOCUMENT_ERR") ) { WRONG_DOCUMENT_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"INVALID_ACCESS_ERR") ) { INVALID_ACCESS_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"NO_DATA_ALLOWED_ERR") ) { NO_DATA_ALLOWED_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"INUSE_ATTRIBUTE_ERR") ) { INUSE_ATTRIBUTE_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"HIERARCHY_REQUEST_ERR") ) { HIERARCHY_REQUEST_ERR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"INVALID_CHARACTER_ERR") ) { INVALID_CHARACTER_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"INVALID_MODIFICATION_ERR") ) { INVALID_MODIFICATION_ERR=inValue.Cast< int >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"NO_MODIFICATION_ALLOWED_ERR") ) { NO_MODIFICATION_ALLOWED_ERR=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void DOMException_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INDEX_SIZE_ERR"),
	HX_CSTRING("DOMSTRING_SIZE_ERR"),
	HX_CSTRING("HIERARCHY_REQUEST_ERR"),
	HX_CSTRING("WRONG_DOCUMENT_ERR"),
	HX_CSTRING("INVALID_CHARACTER_ERR"),
	HX_CSTRING("NO_DATA_ALLOWED_ERR"),
	HX_CSTRING("NO_MODIFICATION_ALLOWED_ERR"),
	HX_CSTRING("NOT_FOUND_ERR"),
	HX_CSTRING("NOT_SUPPORTED_ERR"),
	HX_CSTRING("INUSE_ATTRIBUTE_ERR"),
	HX_CSTRING("INVALID_STATE_ERR"),
	HX_CSTRING("SYNTAX_ERR"),
	HX_CSTRING("INVALID_MODIFICATION_ERR"),
	HX_CSTRING("NAMESPACE_ERR"),
	HX_CSTRING("INVALID_ACCESS_ERR"),
	HX_CSTRING("VALIDATION_ERR"),
	HX_CSTRING("TYPE_MISMATCH_ERR"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DOMException_obj::INDEX_SIZE_ERR,"INDEX_SIZE_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::DOMSTRING_SIZE_ERR,"DOMSTRING_SIZE_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::HIERARCHY_REQUEST_ERR,"HIERARCHY_REQUEST_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::WRONG_DOCUMENT_ERR,"WRONG_DOCUMENT_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::INVALID_CHARACTER_ERR,"INVALID_CHARACTER_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::NO_DATA_ALLOWED_ERR,"NO_DATA_ALLOWED_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::NO_MODIFICATION_ALLOWED_ERR,"NO_MODIFICATION_ALLOWED_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::NOT_FOUND_ERR,"NOT_FOUND_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::NOT_SUPPORTED_ERR,"NOT_SUPPORTED_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::INUSE_ATTRIBUTE_ERR,"INUSE_ATTRIBUTE_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::INVALID_STATE_ERR,"INVALID_STATE_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::SYNTAX_ERR,"SYNTAX_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::INVALID_MODIFICATION_ERR,"INVALID_MODIFICATION_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::NAMESPACE_ERR,"NAMESPACE_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::INVALID_ACCESS_ERR,"INVALID_ACCESS_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::VALIDATION_ERR,"VALIDATION_ERR");
	HX_MARK_MEMBER_NAME(DOMException_obj::TYPE_MISMATCH_ERR,"TYPE_MISMATCH_ERR");
};

Class DOMException_obj::__mClass;

void DOMException_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.DOMException"), hx::TCanCast< DOMException_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DOMException_obj::__boot()
{
	hx::Static(INDEX_SIZE_ERR) = (int)1;
	hx::Static(DOMSTRING_SIZE_ERR) = (int)2;
	hx::Static(HIERARCHY_REQUEST_ERR) = (int)3;
	hx::Static(WRONG_DOCUMENT_ERR) = (int)4;
	hx::Static(INVALID_CHARACTER_ERR) = (int)5;
	hx::Static(NO_DATA_ALLOWED_ERR) = (int)6;
	hx::Static(NO_MODIFICATION_ALLOWED_ERR) = (int)7;
	hx::Static(NOT_FOUND_ERR) = (int)8;
	hx::Static(NOT_SUPPORTED_ERR) = (int)9;
	hx::Static(INUSE_ATTRIBUTE_ERR) = (int)10;
	hx::Static(INVALID_STATE_ERR) = (int)11;
	hx::Static(SYNTAX_ERR) = (int)12;
	hx::Static(INVALID_MODIFICATION_ERR) = (int)13;
	hx::Static(NAMESPACE_ERR) = (int)14;
	hx::Static(INVALID_ACCESS_ERR) = (int)15;
	hx::Static(VALIDATION_ERR) = (int)16;
	hx::Static(TYPE_MISMATCH_ERR) = (int)19;
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
