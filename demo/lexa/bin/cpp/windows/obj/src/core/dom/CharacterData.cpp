#include <hxcpp.h>

#ifndef INCLUDED_core_dom_CharacterData
#include <core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_dom_NodeType
#include <core/dom/NodeType.h>
#endif
namespace core{
namespace dom{

Void CharacterData_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/dom/CharacterData.hx",35)
	super::__construct();
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

::core::dom::NodeType CharacterData_obj::get_nodeType( ){
	HX_SOURCE_PUSH("CharacterData_obj::get_nodeType")
	HX_SOURCE_POS("../../src/core/dom/CharacterData.hx",44)
	return ::core::dom::NodeType_obj::TEXT_NODE_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(CharacterData_obj,get_nodeType,return )

::String CharacterData_obj::get_data( ){
	HX_SOURCE_PUSH("CharacterData_obj::get_data")
	HX_SOURCE_POS("../../src/core/dom/CharacterData.hx",53)
	return this->_data;
}


HX_DEFINE_DYNAMIC_FUNC0(CharacterData_obj,get_data,return )

::String CharacterData_obj::set_data( ::String value){
	HX_SOURCE_PUSH("CharacterData_obj::set_data")
	HX_SOURCE_POS("../../src/core/dom/CharacterData.hx",58)
	return this->_data = value;
}


HX_DEFINE_DYNAMIC_FUNC1(CharacterData_obj,set_data,return )


CharacterData_obj::CharacterData_obj()
{
}

void CharacterData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharacterData);
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(data,"data");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic CharacterData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return get_data(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_data") ) { return get_data_dyn(); }
		if (HX_FIELD_EQ(inName,"set_data") ) { return set_data_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic CharacterData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return set_data(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void CharacterData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_data"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_data"),
	HX_CSTRING("data"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_data"),
	HX_CSTRING("set_data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class CharacterData_obj::__mClass;

void CharacterData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.CharacterData"), hx::TCanCast< CharacterData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CharacterData_obj::__boot()
{
}

} // end namespace core
} // end namespace dom
