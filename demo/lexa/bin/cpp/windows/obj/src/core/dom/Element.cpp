#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_dom_NodeType
#include <core/dom/NodeType.h>
#endif
namespace core{
namespace dom{

Void Element_obj::__construct(::String tagName)
{
{
	HX_SOURCE_POS("../../src/core/dom/Element.hx",41)
	this->_tagName = tagName;
	HX_SOURCE_POS("../../src/core/dom/Element.hx",42)
	super::__construct();
}
;
	return null();
}

Element_obj::~Element_obj() { }

Dynamic Element_obj::__CreateEmpty() { return  new Element_obj; }
hx::ObjectPtr< Element_obj > Element_obj::__new(::String tagName)
{  hx::ObjectPtr< Element_obj > result = new Element_obj();
	result->__construct(tagName);
	return result;}

Dynamic Element_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Element_obj > result = new Element_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Element_obj::get_nodeName( ){
	HX_SOURCE_PUSH("Element_obj::get_nodeName")
	HX_SOURCE_POS("../../src/core/dom/Element.hx",50)
	return this->_tagName;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_nodeName,return )

::core::dom::NodeType Element_obj::get_nodeType( ){
	HX_SOURCE_PUSH("Element_obj::get_nodeType")
	HX_SOURCE_POS("../../src/core/dom/Element.hx",55)
	return ::core::dom::NodeType_obj::ELEMENT_NODE_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_nodeType,return )

::String Element_obj::get_tagName( ){
	HX_SOURCE_PUSH("Element_obj::get_tagName")
	HX_SOURCE_POS("../../src/core/dom/Element.hx",64)
	return this->_tagName;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_tagName,return )


Element_obj::Element_obj()
{
}

void Element_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Element);
	HX_MARK_MEMBER_NAME(_tagName,"_tagName");
	HX_MARK_MEMBER_NAME(tagName,"tagName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Element_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"tagName") ) { return get_tagName(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_tagName") ) { return _tagName; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_tagName") ) { return get_tagName_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Element_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"tagName") ) { tagName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_tagName") ) { _tagName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Element_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_tagName"));
	outFields->push(HX_CSTRING("tagName"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_tagName"),
	HX_CSTRING("tagName"),
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_tagName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Element_obj::__mClass;

void Element_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.Element"), hx::TCanCast< Element_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Element_obj::__boot()
{
}

} // end namespace core
} // end namespace dom
