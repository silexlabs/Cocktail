#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_NamedNodeMap
#include <cocktail/core/dom/NamedNodeMap.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void Element_obj::__construct(::String tagName)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",79)
	this->_tagName = tagName;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",80)
	this->_attributes = ::cocktail::core::dom::NamedNodeMap_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",81)
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

::String Element_obj::getAttribute( ::String name){
	HX_SOURCE_PUSH("Element_obj::getAttribute")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",97)
	::cocktail::core::dom::Attr attribute = this->getAttributeNode(name);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",98)
	if (((attribute != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",99)
		return attribute->get_value();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",103)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getAttribute,return )

Void Element_obj::setAttribute( ::String name,::String value){
{
		HX_SOURCE_PUSH("Element_obj::setAttribute")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",128)
		::cocktail::core::dom::Attr attribute = this->_attributes->getNamedItem(name);
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",129)
		if (((attribute == null()))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",131)
			attribute = ::cocktail::core::dom::Attr_obj::__new(name);
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",132)
			this->_attributes->setNamedItem(attribute);
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",133)
			attribute->set_ownerElement(hx::ObjectPtr<OBJ_>(this));
		}
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",136)
		attribute->set_value(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Element_obj,setAttribute,(void))

::cocktail::core::dom::Attr Element_obj::getAttributeNode( ::String name){
	HX_SOURCE_PUSH("Element_obj::getAttributeNode")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",149)
	::cocktail::core::dom::Node attribute = this->_attributes->getNamedItem(name);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",151)
	if (((attribute != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",152)
		return attribute;
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",156)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getAttributeNode,return )

::cocktail::core::dom::Attr Element_obj::setAttributeNode( ::cocktail::core::dom::Attr newAttr){
	HX_SOURCE_PUSH("Element_obj::setAttributeNode")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",171)
	newAttr->set_ownerElement(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",172)
	return this->_attributes->setNamedItem(newAttr);
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,setAttributeNode,return )

Void Element_obj::removeAttribute( ::String name){
{
		HX_SOURCE_PUSH("Element_obj::removeAttribute")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",187)
		::cocktail::core::dom::Attr removedAttribute = this->_attributes->removeNamedItem(name);
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",189)
		if (((removedAttribute != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",190)
			removedAttribute->set_ownerElement(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,removeAttribute,(void))

Void Element_obj::setIdAttribute( ::String name,bool isId){
{
		HX_SOURCE_PUSH("Element_obj::setIdAttribute")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",212)
		::cocktail::core::dom::Attr idAttribute = this->_attributes->getNamedItem(name);
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",213)
		if (((idAttribute == null()))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",215)
			idAttribute = ::cocktail::core::dom::Attr_obj::__new(name);
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",216)
			this->_attributes->setNamedItem(idAttribute);
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",217)
			idAttribute->set_ownerElement(hx::ObjectPtr<OBJ_>(this));
		}
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",220)
		idAttribute->set_isId(isId);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Element_obj,setIdAttribute,(void))

Void Element_obj::setIdAttributeNode( ::cocktail::core::dom::Attr idAttr,bool isId){
{
		HX_SOURCE_PUSH("Element_obj::setIdAttributeNode")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",239)
		idAttr->set_isId(isId);
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",240)
		this->_attributes->setNamedItem(idAttr);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Element_obj,setIdAttributeNode,(void))

bool Element_obj::hasAttribute( ::String name){
	HX_SOURCE_PUSH("Element_obj::hasAttribute")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",252)
	return (this->_attributes->getNamedItem(name) != null());
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,hasAttribute,return )

Array< ::cocktail::core::dom::Node > Element_obj::getElementsByTagName( ::String tagName){
	HX_SOURCE_PUSH("Element_obj::getElementsByTagName")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",265)
	Array< ::cocktail::core::dom::Node > elements = Array_obj< ::cocktail::core::dom::Node >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",266)
	this->doGetElementsByTagName(hx::ObjectPtr<OBJ_>(this),tagName,elements);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",267)
	return elements;
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getElementsByTagName,return )

Void Element_obj::doGetElementsByTagName( ::cocktail::core::dom::Node node,::String tagName,Array< ::cocktail::core::dom::Node > elements){
{
		HX_SOURCE_PUSH("Element_obj::doGetElementsByTagName")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",279)
		if (((node->hasChildNodes() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",282)
			int _g1 = (int)0;
			int _g = node->get_childNodes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",282)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",282)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",284)
				::cocktail::core::dom::Node childNode = node->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",287)
				if (((childNode->get_nodeName() == tagName))){
					HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",288)
					elements->push(childNode);
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",292)
					if (((bool((tagName == HX_CSTRING("*"))) && bool((childNode->get_nodeType() == (int)1))))){
						HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",293)
						elements->push(childNode);
					}
				}
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",297)
				this->doGetElementsByTagName(childNode,tagName,elements);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Element_obj,doGetElementsByTagName,(void))

bool Element_obj::hasAttributes( ){
	HX_SOURCE_PUSH("Element_obj::hasAttributes")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",307)
	return (this->_attributes->get_length() > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,hasAttributes,return )

::String Element_obj::get_nodeName( ){
	HX_SOURCE_PUSH("Element_obj::get_nodeName")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",318)
	return this->_tagName;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_nodeName,return )

int Element_obj::get_nodeType( ){
	HX_SOURCE_PUSH("Element_obj::get_nodeType")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",323)
	return (int)1;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_nodeType,return )

::cocktail::core::dom::NamedNodeMap Element_obj::get_attributes( ){
	HX_SOURCE_PUSH("Element_obj::get_attributes")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",328)
	return this->_attributes;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_attributes,return )

::cocktail::core::dom::Element Element_obj::get_firstElementChild( ){
	HX_SOURCE_PUSH("Element_obj::get_firstElementChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",338)
	if (((this->hasChildNodes() == false))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",339)
		return null();
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",343)
	if (((this->get_firstChild()->get_nodeType() == (int)1))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",344)
		return this->get_firstChild();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",349)
		int _g1 = (int)0;
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",349)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",349)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",351)
			if (((this->_childNodes->__get(i)->get_nodeType() == (int)1))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",352)
				return this->_childNodes->__get(i);
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",358)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_firstElementChild,return )

::cocktail::core::dom::Element Element_obj::get_lastElementChild( ){
	HX_SOURCE_PUSH("Element_obj::get_lastElementChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",363)
	if (((this->hasChildNodes() == false))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",364)
		return null();
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",368)
	if (((this->get_lastChild()->get_nodeType() == (int)1))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",369)
		return this->get_lastChild();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",374)
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",374)
		while(((_g < (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",374)
			int i = (_g)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",376)
			if (((this->_childNodes->__get(i)->get_nodeType() == (int)1))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",377)
				return this->_childNodes->__get(i);
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",383)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_lastElementChild,return )

::cocktail::core::dom::Element Element_obj::get_nextElementSibling( ){
	HX_SOURCE_PUSH("Element_obj::get_nextElementSibling")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",388)
	if (((this->get_nextSibling() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",389)
		return null();
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",393)
	::cocktail::core::dom::Node nextElementSibling = this->get_nextSibling();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",395)
	while(((nextElementSibling->get_nodeType() != (int)1))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",397)
		nextElementSibling = nextElementSibling->get_nextSibling();
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",399)
		if (((nextElementSibling == null()))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",400)
			return null();
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",405)
	return nextElementSibling;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_nextElementSibling,return )

::cocktail::core::dom::Element Element_obj::get_previousElementSibling( ){
	HX_SOURCE_PUSH("Element_obj::get_previousElementSibling")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",410)
	if (((this->get_previousSibling() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",411)
		return null();
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",415)
	::cocktail::core::dom::Node previousElementSibling = this->get_previousSibling();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",417)
	while(((previousElementSibling->get_nodeType() != (int)1))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",419)
		previousElementSibling = previousElementSibling->get_previousSibling();
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",421)
		if (((previousElementSibling == null()))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",422)
			return null();
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",427)
	return previousElementSibling;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_previousElementSibling,return )

int Element_obj::get_childElementCount( ){
	HX_SOURCE_PUSH("Element_obj::get_childElementCount")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",432)
	int childElementCount = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",434)
	{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",434)
		int _g1 = (int)0;
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",434)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",434)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",436)
			if (((this->_childNodes->__get(i)->get_nodeType() == (int)1))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",437)
				(childElementCount)++;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",442)
	return childElementCount;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_childElementCount,return )

::String Element_obj::get_tagName( ){
	HX_SOURCE_PUSH("Element_obj::get_tagName")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Element.hx",450)
	return this->_tagName;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_tagName,return )

::String Element_obj::MATCH_ALL_TAG_NAME;


Element_obj::Element_obj()
{
}

void Element_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Element);
	HX_MARK_MEMBER_NAME(_tagName,"_tagName");
	HX_MARK_MEMBER_NAME(tagName,"tagName");
	HX_MARK_MEMBER_NAME(firstElementChild,"firstElementChild");
	HX_MARK_MEMBER_NAME(lastElementChild,"lastElementChild");
	HX_MARK_MEMBER_NAME(previousElementSibling,"previousElementSibling");
	HX_MARK_MEMBER_NAME(nextElementSibling,"nextElementSibling");
	HX_MARK_MEMBER_NAME(childElementCount,"childElementCount");
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
		if (HX_FIELD_EQ(inName,"getAttribute") ) { return getAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAttribute") ) { return hasAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasAttributes") ) { return hasAttributes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setIdAttribute") ) { return setIdAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"get_attributes") ) { return get_attributes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeAttribute") ) { return removeAttribute_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lastElementChild") ) { return get_lastElementChild(); }
		if (HX_FIELD_EQ(inName,"getAttributeNode") ) { return getAttributeNode_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttributeNode") ) { return setAttributeNode_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"firstElementChild") ) { return get_firstElementChild(); }
		if (HX_FIELD_EQ(inName,"childElementCount") ) { return get_childElementCount(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"MATCH_ALL_TAG_NAME") ) { return MATCH_ALL_TAG_NAME; }
		if (HX_FIELD_EQ(inName,"nextElementSibling") ) { return get_nextElementSibling(); }
		if (HX_FIELD_EQ(inName,"setIdAttributeNode") ) { return setIdAttributeNode_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getElementsByTagName") ) { return getElementsByTagName_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lastElementChild") ) { return get_lastElementChild_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_firstElementChild") ) { return get_firstElementChild_dyn(); }
		if (HX_FIELD_EQ(inName,"get_childElementCount") ) { return get_childElementCount_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"previousElementSibling") ) { return get_previousElementSibling(); }
		if (HX_FIELD_EQ(inName,"doGetElementsByTagName") ) { return doGetElementsByTagName_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nextElementSibling") ) { return get_nextElementSibling_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"get_previousElementSibling") ) { return get_previousElementSibling_dyn(); }
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
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lastElementChild") ) { lastElementChild=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"firstElementChild") ) { firstElementChild=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
		if (HX_FIELD_EQ(inName,"childElementCount") ) { childElementCount=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"MATCH_ALL_TAG_NAME") ) { MATCH_ALL_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextElementSibling") ) { nextElementSibling=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"previousElementSibling") ) { previousElementSibling=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Element_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_tagName"));
	outFields->push(HX_CSTRING("tagName"));
	outFields->push(HX_CSTRING("firstElementChild"));
	outFields->push(HX_CSTRING("lastElementChild"));
	outFields->push(HX_CSTRING("previousElementSibling"));
	outFields->push(HX_CSTRING("nextElementSibling"));
	outFields->push(HX_CSTRING("childElementCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MATCH_ALL_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_tagName"),
	HX_CSTRING("tagName"),
	HX_CSTRING("firstElementChild"),
	HX_CSTRING("lastElementChild"),
	HX_CSTRING("previousElementSibling"),
	HX_CSTRING("nextElementSibling"),
	HX_CSTRING("childElementCount"),
	HX_CSTRING("getAttribute"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("getAttributeNode"),
	HX_CSTRING("setAttributeNode"),
	HX_CSTRING("removeAttribute"),
	HX_CSTRING("setIdAttribute"),
	HX_CSTRING("setIdAttributeNode"),
	HX_CSTRING("hasAttribute"),
	HX_CSTRING("getElementsByTagName"),
	HX_CSTRING("doGetElementsByTagName"),
	HX_CSTRING("hasAttributes"),
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_attributes"),
	HX_CSTRING("get_firstElementChild"),
	HX_CSTRING("get_lastElementChild"),
	HX_CSTRING("get_nextElementSibling"),
	HX_CSTRING("get_previousElementSibling"),
	HX_CSTRING("get_childElementCount"),
	HX_CSTRING("get_tagName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Element_obj::MATCH_ALL_TAG_NAME,"MATCH_ALL_TAG_NAME");
};

Class Element_obj::__mClass;

void Element_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Element"), hx::TCanCast< Element_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Element_obj::__boot()
{
	hx::Static(MATCH_ALL_TAG_NAME) = HX_CSTRING("*");
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
