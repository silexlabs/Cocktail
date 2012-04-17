#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_dom_Text
#include <cocktail/core/dom/Text.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void Document_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",39)
	super::__construct();
}
;
	return null();
}

Document_obj::~Document_obj() { }

Dynamic Document_obj::__CreateEmpty() { return  new Document_obj; }
hx::ObjectPtr< Document_obj > Document_obj::__new()
{  hx::ObjectPtr< Document_obj > result = new Document_obj();
	result->__construct();
	return result;}

Dynamic Document_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Document_obj > result = new Document_obj();
	result->__construct();
	return result;}

::cocktail::core::html::HTMLElement Document_obj::createElement( ::String tagName){
	HX_SOURCE_PUSH("Document_obj::createElement")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",66)
	::cocktail::core::html::HTMLElement element = ::cocktail::core::html::HTMLElement_obj::__new(tagName);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",67)
	element->set_ownerDocument(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",68)
	return element;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createElement,return )

::cocktail::port::flash_player::Text Document_obj::createTextNode( ::String data){
	HX_SOURCE_PUSH("Document_obj::createTextNode")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",78)
	::cocktail::port::flash_player::Text text = ::cocktail::port::flash_player::Text_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",79)
	text->set_nodeValue(data);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",80)
	return text;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createTextNode,return )

::cocktail::core::dom::Attr Document_obj::createAttribute( ::String name){
	HX_SOURCE_PUSH("Document_obj::createAttribute")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",100)
	::cocktail::core::dom::Attr attribute = ::cocktail::core::dom::Attr_obj::__new(name);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",101)
	return attribute;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createAttribute,return )

::cocktail::core::dom::Element Document_obj::getElementById( ::String elementId){
	HX_SOURCE_PUSH("Document_obj::getElementById")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",114)
	return this->doGetElementById(this->_documentElement,elementId);
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,getElementById,return )

::cocktail::core::dom::Element Document_obj::doGetElementById( ::cocktail::core::dom::Node node,::String elementId){
	HX_SOURCE_PUSH("Document_obj::doGetElementById")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",130)
	if (((bool((node->hasChildNodes() == true)) && bool((node->get_nodeType() == (int)1))))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",132)
		int _g1 = (int)0;
		int _g = node->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",132)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",132)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",134)
			::cocktail::core::dom::Element matchingElement = this->doGetElementById(node->get_childNodes()->__get(i),elementId);
			HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",136)
			if (((matchingElement != null()))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",137)
				return matchingElement;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",145)
	if (((node->hasAttributes() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",147)
		::cocktail::core::dom::NamedNodeMap attributes = node->get_attributes();
		HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",148)
		::cocktail::core::dom::Element element = node;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",152)
		{
			HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",152)
			int _g1 = (int)0;
			int _g = attributes->get_length();
			HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",152)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",152)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",155)
				::cocktail::core::dom::Attr attribute = element->getAttributeNode(attributes->item(i)->get_nodeName());
				HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",158)
				if (((bool((attribute->get_isId() == true)) && bool((attribute->get_specified() == true))))){
					HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",159)
					if (((attribute->get_value() == elementId))){
						HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",162)
						return element;
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",170)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Document_obj,doGetElementById,return )

Array< ::cocktail::core::dom::Node > Document_obj::getElementsByTagName( ::String tagName){
	HX_SOURCE_PUSH("Document_obj::getElementsByTagName")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",185)
	return this->_documentElement->getElementsByTagName(tagName);
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,getElementsByTagName,return )

int Document_obj::get_nodeType( ){
	HX_SOURCE_PUSH("Document_obj::get_nodeType")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",196)
	return (int)9;
}


HX_DEFINE_DYNAMIC_FUNC0(Document_obj,get_nodeType,return )

::cocktail::core::dom::Element Document_obj::get_documentElement( ){
	HX_SOURCE_PUSH("Document_obj::get_documentElement")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Document.hx",205)
	return this->_documentElement;
}


HX_DEFINE_DYNAMIC_FUNC0(Document_obj,get_documentElement,return )


Document_obj::Document_obj()
{
}

void Document_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Document);
	HX_MARK_MEMBER_NAME(_documentElement,"_documentElement");
	HX_MARK_MEMBER_NAME(documentElement,"documentElement");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Document_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createTextNode") ) { return createTextNode_dyn(); }
		if (HX_FIELD_EQ(inName,"getElementById") ) { return getElementById_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"documentElement") ) { return get_documentElement(); }
		if (HX_FIELD_EQ(inName,"createAttribute") ) { return createAttribute_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_documentElement") ) { return _documentElement; }
		if (HX_FIELD_EQ(inName,"doGetElementById") ) { return doGetElementById_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_documentElement") ) { return get_documentElement_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getElementsByTagName") ) { return getElementsByTagName_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Document_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"documentElement") ) { documentElement=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_documentElement") ) { _documentElement=inValue.Cast< ::cocktail::core::dom::Element >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Document_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_documentElement"));
	outFields->push(HX_CSTRING("documentElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_documentElement"),
	HX_CSTRING("documentElement"),
	HX_CSTRING("createElement"),
	HX_CSTRING("createTextNode"),
	HX_CSTRING("createAttribute"),
	HX_CSTRING("getElementById"),
	HX_CSTRING("doGetElementById"),
	HX_CSTRING("getElementsByTagName"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_documentElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Document_obj::__mClass;

void Document_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Document"), hx::TCanCast< Document_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Document_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
