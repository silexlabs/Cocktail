#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void Attr_obj::__construct(::String name)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",66)
	this->_name = name;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",67)
	this->_specified = false;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",68)
	super::__construct();
}
;
	return null();
}

Attr_obj::~Attr_obj() { }

Dynamic Attr_obj::__CreateEmpty() { return  new Attr_obj; }
hx::ObjectPtr< Attr_obj > Attr_obj::__new(::String name)
{  hx::ObjectPtr< Attr_obj > result = new Attr_obj();
	result->__construct(name);
	return result;}

Dynamic Attr_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Attr_obj > result = new Attr_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Attr_obj::get_nodeName( ){
	HX_SOURCE_PUSH("Attr_obj::get_nodeName")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",76)
	return this->_name;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_nodeName,return )

int Attr_obj::get_nodeType( ){
	HX_SOURCE_PUSH("Attr_obj::get_nodeType")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",81)
	return (int)2;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_nodeType,return )

::String Attr_obj::get_nodeValue( ){
	HX_SOURCE_PUSH("Attr_obj::get_nodeValue")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",86)
	return this->get_value();
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_nodeValue,return )

::String Attr_obj::set_nodeValue( ::String value){
	HX_SOURCE_PUSH("Attr_obj::set_nodeValue")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",91)
	return this->set_value(value);
}


HX_DEFINE_DYNAMIC_FUNC1(Attr_obj,set_nodeValue,return )

::cocktail::core::dom::Element Attr_obj::get_ownerElement( ){
	HX_SOURCE_PUSH("Attr_obj::get_ownerElement")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",100)
	return this->_ownerElement;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_ownerElement,return )

::cocktail::core::dom::Element Attr_obj::set_ownerElement( ::cocktail::core::dom::Element value){
	HX_SOURCE_PUSH("Attr_obj::set_ownerElement")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",105)
	return this->_ownerElement = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Attr_obj,set_ownerElement,return )

bool Attr_obj::get_isId( ){
	HX_SOURCE_PUSH("Attr_obj::get_isId")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",110)
	return this->_isId;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_isId,return )

bool Attr_obj::set_isId( bool value){
	HX_SOURCE_PUSH("Attr_obj::set_isId")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",115)
	return this->_isId = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Attr_obj,set_isId,return )

::String Attr_obj::get_name( ){
	HX_SOURCE_PUSH("Attr_obj::get_name")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",120)
	return this->_name;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_name,return )

::String Attr_obj::get_value( ){
	HX_SOURCE_PUSH("Attr_obj::get_value")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",127)
	if (((this->_value == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",128)
		return HX_CSTRING("");
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",131)
	return this->_value;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_value,return )

::String Attr_obj::set_value( ::String value){
	HX_SOURCE_PUSH("Attr_obj::set_value")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",136)
	this->_specified = true;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",137)
	return this->_value = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Attr_obj,set_value,return )

bool Attr_obj::get_specified( ){
	HX_SOURCE_PUSH("Attr_obj::get_specified")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Attr.hx",141)
	return this->_specified;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_specified,return )


Attr_obj::Attr_obj()
{
}

void Attr_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Attr);
	HX_MARK_MEMBER_NAME(_name,"_name");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(_value,"_value");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(_specified,"_specified");
	HX_MARK_MEMBER_NAME(specified,"specified");
	HX_MARK_MEMBER_NAME(_isId,"_isId");
	HX_MARK_MEMBER_NAME(isId,"isId");
	HX_MARK_MEMBER_NAME(_ownerElement,"_ownerElement");
	HX_MARK_MEMBER_NAME(ownerElement,"ownerElement");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Attr_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		if (HX_FIELD_EQ(inName,"isId") ) { return get_isId(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_name") ) { return _name; }
		if (HX_FIELD_EQ(inName,"value") ) { return get_value(); }
		if (HX_FIELD_EQ(inName,"_isId") ) { return _isId; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { return _value; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_isId") ) { return get_isId_dyn(); }
		if (HX_FIELD_EQ(inName,"set_isId") ) { return set_isId_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"specified") ) { return get_specified(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_specified") ) { return _specified; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ownerElement") ) { return get_ownerElement(); }
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_ownerElement") ) { return _ownerElement; }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_specified") ) { return get_specified_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_ownerElement") ) { return get_ownerElement_dyn(); }
		if (HX_FIELD_EQ(inName,"set_ownerElement") ) { return set_ownerElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Attr_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isId") ) { return set_isId(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_name") ) { _name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"value") ) { return set_value(inValue); }
		if (HX_FIELD_EQ(inName,"_isId") ) { _isId=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { _value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"specified") ) { specified=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_specified") ) { _specified=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ownerElement") ) { return set_ownerElement(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_ownerElement") ) { _ownerElement=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Attr_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_name"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("_value"));
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("_specified"));
	outFields->push(HX_CSTRING("specified"));
	outFields->push(HX_CSTRING("_isId"));
	outFields->push(HX_CSTRING("isId"));
	outFields->push(HX_CSTRING("_ownerElement"));
	outFields->push(HX_CSTRING("ownerElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_name"),
	HX_CSTRING("name"),
	HX_CSTRING("_value"),
	HX_CSTRING("value"),
	HX_CSTRING("_specified"),
	HX_CSTRING("specified"),
	HX_CSTRING("_isId"),
	HX_CSTRING("isId"),
	HX_CSTRING("_ownerElement"),
	HX_CSTRING("ownerElement"),
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("set_nodeValue"),
	HX_CSTRING("get_ownerElement"),
	HX_CSTRING("set_ownerElement"),
	HX_CSTRING("get_isId"),
	HX_CSTRING("set_isId"),
	HX_CSTRING("get_name"),
	HX_CSTRING("get_value"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_specified"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Attr_obj::__mClass;

void Attr_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Attr"), hx::TCanCast< Attr_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Attr_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
