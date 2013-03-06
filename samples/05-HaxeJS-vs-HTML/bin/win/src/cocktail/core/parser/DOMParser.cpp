#include <hxcpp.h>

#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_XmlType
#include <XmlType.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Comment
#include <cocktail/core/dom/Comment.h>
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
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_parser_DOMParser
#include <cocktail/core/parser/DOMParser.h>
#endif
#ifndef INCLUDED_haxe_xml_Parser
#include <haxe/xml/Parser.h>
#endif
namespace cocktail{
namespace core{
namespace parser{

Void DOMParser_obj::__construct()
{
HX_STACK_PUSH("DOMParser::new","cocktail/core/parser/DOMParser.hx",27);
{
}
;
	return null();
}

DOMParser_obj::~DOMParser_obj() { }

Dynamic DOMParser_obj::__CreateEmpty() { return  new DOMParser_obj; }
hx::ObjectPtr< DOMParser_obj > DOMParser_obj::__new()
{  hx::ObjectPtr< DOMParser_obj > result = new DOMParser_obj();
	result->__construct();
	return result;}

Dynamic DOMParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DOMParser_obj > result = new DOMParser_obj();
	result->__construct();
	return result;}

::cocktail::core::html::HTMLElement DOMParser_obj::parse( ::String html,::cocktail::core::dom::Document ownerDocument){
	HX_STACK_PUSH("DOMParser::parse","cocktail/core/parser/DOMParser.hx",43);
	HX_STACK_ARG(html,"html");
	HX_STACK_ARG(ownerDocument,"ownerDocument");
	HX_STACK_LINE(44)
	::cocktail::core::html::HTMLElement node = ::cocktail::core::parser::DOMParser_obj::doSetInnerHTML(::haxe::xml::Parser_obj::parse(html)->firstElement(),ownerDocument);		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(45)
	return node;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DOMParser_obj,parse,return )

::String DOMParser_obj::serialize( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("DOMParser::serialize","cocktail/core/parser/DOMParser.hx",53);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(55)
	::Xml xml = ::cocktail::core::parser::DOMParser_obj::doGetInnerHTML(node,::Xml_obj::createElement(node->get_nodeName()));		HX_STACK_VAR(xml,"xml");
	HX_STACK_LINE(57)
	{
		HX_STACK_LINE(57)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = node->attributes->get_length();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		while(((_g1 < _g))){
			HX_STACK_LINE(57)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(59)
			::cocktail::core::dom::Attr attribute = node->attributes->item(i);		HX_STACK_VAR(attribute,"attribute");
			HX_STACK_LINE(61)
			if (((attribute->specified == true))){
				HX_STACK_LINE(62)
				xml->set(attribute->name,attribute->get_value());
			}
		}
	}
	HX_STACK_LINE(66)
	return xml->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DOMParser_obj,serialize,return )

::cocktail::core::html::HTMLElement DOMParser_obj::doSetInnerHTML( ::Xml xml,::cocktail::core::dom::Document ownerDocument){
	HX_STACK_PUSH("DOMParser::doSetInnerHTML","cocktail/core/parser/DOMParser.hx",81);
	HX_STACK_ARG(xml,"xml");
	HX_STACK_ARG(ownerDocument,"ownerDocument");
	HX_STACK_LINE(82)
	::XmlType _switch_1 = (xml->nodeType);
	if (  ( _switch_1==::Xml_obj::PCData)){
		HX_STACK_LINE(85)
		return ownerDocument->createTextNode(xml->getNodeValue());
	}
	else if (  ( _switch_1==::Xml_obj::Comment)){
		HX_STACK_LINE(89)
		return ownerDocument->createComment(xml->getNodeValue());
	}
	else if (  ( _switch_1==::Xml_obj::Element)){
		HX_STACK_LINE(97)
		::cocktail::core::html::HTMLElement htmlElement = ownerDocument->createElement(xml->getNodeName());		HX_STACK_VAR(htmlElement,"htmlElement");
		HX_STACK_LINE(100)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml->iterator());  __it->hasNext(); ){
			::Xml child = __it->next();
			{
				HX_STACK_LINE(103)
				::XmlType _switch_2 = (child->nodeType);
				if (  ( _switch_2==::Xml_obj::PCData)){
					HX_STACK_LINE(109)
					if (((child->getNodeValue() == HX_CSTRING("")))){
						HX_STACK_LINE(111)
						continue;
					}
				}
				HX_STACK_LINE(118)
				::cocktail::core::html::HTMLElement childNode = ::cocktail::core::parser::DOMParser_obj::doSetInnerHTML(child,ownerDocument);		HX_STACK_VAR(childNode,"childNode");
				HX_STACK_LINE(119)
				htmlElement->appendChild(childNode);
			}
;
		}
		HX_STACK_LINE(124)
		Dynamic attributes = xml->attributes();		HX_STACK_VAR(attributes,"attributes");
		HX_STACK_LINE(125)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(attributes);  __it->hasNext(); ){
			::String attribute = __it->next();
			{
				HX_STACK_LINE(126)
				::String value = xml->get(attribute);		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(127)
				htmlElement->setAttribute(attribute,value);
			}
;
		}
		HX_STACK_LINE(130)
		return htmlElement;
	}
	HX_STACK_LINE(133)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DOMParser_obj,doSetInnerHTML,return )

::Xml DOMParser_obj::doGetInnerHTML( ::cocktail::core::html::HTMLElement node,::Xml xml){
	HX_STACK_PUSH("DOMParser::doGetInnerHTML","cocktail/core/parser/DOMParser.hx",146);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(xml,"xml");
	HX_STACK_LINE(147)
	int length = node->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(148)
	{
		HX_STACK_LINE(148)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(148)
		while(((_g < length))){
			HX_STACK_LINE(148)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(150)
			::cocktail::core::html::HTMLElement child = node->childNodes->__GetItem(i);		HX_STACK_VAR(child,"child");
			HX_STACK_LINE(152)
			switch( (int)(child->get_nodeType())){
				case (int)1: {
					HX_STACK_LINE(158)
					::Xml childXml = ::Xml_obj::createElement(child->get_nodeName());		HX_STACK_VAR(childXml,"childXml");
					HX_STACK_LINE(161)
					::cocktail::core::dom::NamedNodeMap childAttributes = child->attributes;		HX_STACK_VAR(childAttributes,"childAttributes");
					HX_STACK_LINE(162)
					int childAttributesLength = childAttributes->get_length();		HX_STACK_VAR(childAttributesLength,"childAttributesLength");
					HX_STACK_LINE(163)
					{
						HX_STACK_LINE(163)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(163)
						while(((_g1 < childAttributesLength))){
							HX_STACK_LINE(163)
							int j = (_g1)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(165)
							::cocktail::core::dom::Attr attribute = childAttributes->item(j);		HX_STACK_VAR(attribute,"attribute");
							HX_STACK_LINE(167)
							if (((attribute->specified == true))){
								HX_STACK_LINE(168)
								childXml->set(attribute->name,attribute->get_value());
							}
						}
					}
					HX_STACK_LINE(176)
					if (((child->style->length > (int)0))){
						HX_STACK_LINE(177)
						childXml->set(HX_CSTRING("style"),child->style->get_cssText());
					}
					HX_STACK_LINE(182)
					xml->addChild(::cocktail::core::parser::DOMParser_obj::doGetInnerHTML(child,childXml));
					HX_STACK_LINE(188)
					if (((bool((childXml->firstChild() == null())) && bool((child->isVoidElement() == false))))){
						HX_STACK_LINE(189)
						childXml->addChild(::Xml_obj::createPCData(HX_CSTRING("")));
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(195)
					::Xml text = ::Xml_obj::createPCData(child->get_nodeValue());		HX_STACK_VAR(text,"text");
					HX_STACK_LINE(196)
					xml->addChild(text);
				}
				;break;
				case (int)8: {
					HX_STACK_LINE(200)
					::Xml comment = ::Xml_obj::createComment(child->get_nodeValue());		HX_STACK_VAR(comment,"comment");
					HX_STACK_LINE(201)
					xml->addChild(comment);
				}
				;break;
			}
		}
	}
	HX_STACK_LINE(205)
	return xml;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DOMParser_obj,doGetInnerHTML,return )


DOMParser_obj::DOMParser_obj()
{
}

void DOMParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DOMParser);
	HX_MARK_END_CLASS();
}

void DOMParser_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic DOMParser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"serialize") ) { return serialize_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"doSetInnerHTML") ) { return doSetInnerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetInnerHTML") ) { return doGetInnerHTML_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DOMParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DOMParser_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("parse"),
	HX_CSTRING("serialize"),
	HX_CSTRING("doSetInnerHTML"),
	HX_CSTRING("doGetInnerHTML"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DOMParser_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DOMParser_obj::__mClass,"__mClass");
};

Class DOMParser_obj::__mClass;

void DOMParser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.parser.DOMParser"), hx::TCanCast< DOMParser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DOMParser_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace parser
