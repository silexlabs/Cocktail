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

Void Element_obj::__construct(::String tagName)
{
HX_STACK_PUSH("Element::new","cocktail/core/dom/Element.hx",70);
{
	HX_STACK_LINE(71)
	this->tagName = tagName;
	HX_STACK_LINE(72)
	this->initAttributes();
	HX_STACK_LINE(73)
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

int Element_obj::get_childElementCount( ){
	HX_STACK_PUSH("Element::get_childElementCount","cocktail/core/dom/Element.hx",511);
	HX_STACK_THIS(this);
	HX_STACK_LINE(512)
	int childElementCount = (int)0;		HX_STACK_VAR(childElementCount,"childElementCount");
	HX_STACK_LINE(514)
	int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(515)
	{
		HX_STACK_LINE(515)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(515)
		while(((_g < length))){
			HX_STACK_LINE(515)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(517)
			if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeType"),true)() == (int)1))){
				HX_STACK_LINE(518)
				(childElementCount)++;
			}
		}
	}
	HX_STACK_LINE(523)
	return childElementCount;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_childElementCount,return )

Dynamic Element_obj::get_previousElementSibling( ){
	HX_STACK_PUSH("Element::get_previousElementSibling","cocktail/core/dom/Element.hx",489);
	HX_STACK_THIS(this);
	HX_STACK_LINE(490)
	if (((this->get_previousSibling() == null()))){
		HX_STACK_LINE(491)
		return null();
	}
	HX_STACK_LINE(495)
	Dynamic previousElementSibling = this->get_previousSibling();		HX_STACK_VAR(previousElementSibling,"previousElementSibling");
	HX_STACK_LINE(497)
	while(((previousElementSibling->__Field(HX_CSTRING("get_nodeType"),true)() != (int)1))){
		HX_STACK_LINE(499)
		previousElementSibling = previousElementSibling->__Field(HX_CSTRING("get_previousSibling"),true)();
		HX_STACK_LINE(501)
		if (((previousElementSibling == null()))){
			HX_STACK_LINE(502)
			return null();
		}
	}
	HX_STACK_LINE(507)
	return previousElementSibling;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_previousElementSibling,return )

Dynamic Element_obj::get_nextElementSibling( ){
	HX_STACK_PUSH("Element::get_nextElementSibling","cocktail/core/dom/Element.hx",467);
	HX_STACK_THIS(this);
	HX_STACK_LINE(468)
	if (((this->get_nextSibling() == null()))){
		HX_STACK_LINE(469)
		return null();
	}
	HX_STACK_LINE(473)
	Dynamic nextElementSibling = this->get_nextSibling();		HX_STACK_VAR(nextElementSibling,"nextElementSibling");
	HX_STACK_LINE(475)
	while(((nextElementSibling->__Field(HX_CSTRING("get_nodeType"),true)() != (int)1))){
		HX_STACK_LINE(477)
		nextElementSibling = nextElementSibling->__Field(HX_CSTRING("get_nextSibling"),true)();
		HX_STACK_LINE(479)
		if (((nextElementSibling == null()))){
			HX_STACK_LINE(480)
			return null();
		}
	}
	HX_STACK_LINE(485)
	return nextElementSibling;
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_nextElementSibling,return )

Dynamic Element_obj::get_lastElementChild( ){
	HX_STACK_PUSH("Element::get_lastElementChild","cocktail/core/dom/Element.hx",441);
	HX_STACK_THIS(this);
	HX_STACK_LINE(442)
	if (((this->hasChildNodes() == false))){
		HX_STACK_LINE(443)
		return null();
	}
	HX_STACK_LINE(447)
	if (((this->get_lastChild()->__Field(HX_CSTRING("get_nodeType"),true)() == (int)1))){
		HX_STACK_LINE(448)
		return this->get_lastChild();
	}
	else{
		HX_STACK_LINE(453)
		int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(454)
		{
			HX_STACK_LINE(454)
			int _g = length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(454)
			while(((_g < (int)0))){
				HX_STACK_LINE(454)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(456)
				if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeType"),true)() == (int)1))){
					HX_STACK_LINE(457)
					return this->childNodes->__GetItem(i);
				}
			}
		}
	}
	HX_STACK_LINE(463)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_lastElementChild,return )

Dynamic Element_obj::get_firstElementChild( ){
	HX_STACK_PUSH("Element::get_firstElementChild","cocktail/core/dom/Element.hx",415);
	HX_STACK_THIS(this);
	HX_STACK_LINE(416)
	if (((this->hasChildNodes() == false))){
		HX_STACK_LINE(417)
		return null();
	}
	HX_STACK_LINE(421)
	if (((this->get_firstChild()->__Field(HX_CSTRING("get_nodeType"),true)() == (int)1))){
		HX_STACK_LINE(422)
		return this->get_firstChild();
	}
	else{
		HX_STACK_LINE(427)
		int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(428)
		{
			HX_STACK_LINE(428)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(428)
			while(((_g < length))){
				HX_STACK_LINE(428)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(430)
				if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeType"),true)() == (int)1))){
					HX_STACK_LINE(431)
					return this->childNodes->__GetItem(i);
				}
			}
		}
	}
	HX_STACK_LINE(437)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,get_firstElementChild,return )

int Element_obj::get_nodeType( ){
	HX_STACK_PUSH("Element::get_nodeType","cocktail/core/dom/Element.hx",406);
	HX_STACK_THIS(this);
	HX_STACK_LINE(406)
	return (int)1;
}


::String Element_obj::get_nodeName( ){
	HX_STACK_PUSH("Element::get_nodeName","cocktail/core/dom/Element.hx",401);
	HX_STACK_THIS(this);
	HX_STACK_LINE(401)
	return this->tagName;
}


bool Element_obj::hasAttributes( ){
	HX_STACK_PUSH("Element::hasAttributes","cocktail/core/dom/Element.hx",392);
	HX_STACK_THIS(this);
	HX_STACK_LINE(392)
	return (this->attributes->get_length() > (int)0);
}


Void Element_obj::doGetElementsByClassName( ::cocktail::core::html::HTMLElement node,::String className,Array< ::cocktail::core::html::HTMLElement > elements){
{
		HX_STACK_PUSH("Element::doGetElementsByClassName","cocktail/core/dom/Element.hx",355);
		HX_STACK_THIS(this);
		HX_STACK_ARG(node,"node");
		HX_STACK_ARG(className,"className");
		HX_STACK_ARG(elements,"elements");
		HX_STACK_LINE(355)
		if (((node->hasChildNodes() == true))){
			HX_STACK_LINE(358)
			int length = node->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(359)
				while(((_g < length))){
					HX_STACK_LINE(359)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(361)
					::cocktail::core::html::HTMLElement childNode = node->childNodes->__GetItem(i);		HX_STACK_VAR(childNode,"childNode");
					HX_STACK_LINE(362)
					switch( (int)(childNode->get_nodeType())){
						case (int)1: {
							HX_STACK_LINE(365)
							Array< ::String > classList = childNode->classList;		HX_STACK_VAR(classList,"classList");
							HX_STACK_LINE(366)
							if (((classList != null()))){
								HX_STACK_LINE(368)
								bool foundFlag = false;		HX_STACK_VAR(foundFlag,"foundFlag");
								HX_STACK_LINE(369)
								int classListLength = classList->length;		HX_STACK_VAR(classListLength,"classListLength");
								HX_STACK_LINE(370)
								{
									HX_STACK_LINE(370)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(370)
									while(((_g1 < classListLength))){
										HX_STACK_LINE(370)
										int j = (_g1)++;		HX_STACK_VAR(j,"j");
										HX_STACK_LINE(372)
										if (((bool((classList->__get(j) == className)) && bool((foundFlag == false))))){
											HX_STACK_LINE(374)
											elements->push(childNode);
											HX_STACK_LINE(375)
											foundFlag = true;
										}
									}
								}
							}
						}
						;break;
					}
					HX_STACK_LINE(381)
					this->doGetElementsByClassName(childNode,className,elements);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Element_obj,doGetElementsByClassName,(void))

Void Element_obj::doGetElementsByTagName( ::cocktail::core::html::HTMLElement node,::String tagName,Array< ::cocktail::core::html::HTMLElement > elements){
{
		HX_STACK_PUSH("Element::doGetElementsByTagName","cocktail/core/dom/Element.hx",326);
		HX_STACK_THIS(this);
		HX_STACK_ARG(node,"node");
		HX_STACK_ARG(tagName,"tagName");
		HX_STACK_ARG(elements,"elements");
		HX_STACK_LINE(326)
		if (((node->hasChildNodes() == true))){
			HX_STACK_LINE(329)
			int length = node->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(330)
			{
				HX_STACK_LINE(330)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(330)
				while(((_g < length))){
					HX_STACK_LINE(330)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(332)
					::cocktail::core::html::HTMLElement childNode = node->childNodes->__GetItem(i);		HX_STACK_VAR(childNode,"childNode");
					HX_STACK_LINE(335)
					if (((childNode->get_nodeName() == tagName))){
						HX_STACK_LINE(336)
						elements->push(childNode);
					}
					else{
						HX_STACK_LINE(340)
						if (((bool((tagName == HX_CSTRING("*"))) && bool((childNode->get_nodeType() == (int)1))))){
							HX_STACK_LINE(341)
							elements->push(childNode);
						}
					}
					HX_STACK_LINE(345)
					this->doGetElementsByTagName(childNode,tagName,elements);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Element_obj,doGetElementsByTagName,(void))

Dynamic Element_obj::doCloneNode( ){
	HX_STACK_PUSH("Element::doCloneNode","cocktail/core/dom/Element.hx",304);
	HX_STACK_THIS(this);
	HX_STACK_LINE(305)
	::cocktail::core::dom::Element clonedElement = ::cocktail::core::dom::Element_obj::__new(this->tagName);		HX_STACK_VAR(clonedElement,"clonedElement");
	HX_STACK_LINE(307)
	int length = this->attributes->get_length();		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(308)
	{
		HX_STACK_LINE(308)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(308)
		while(((_g < length))){
			HX_STACK_LINE(308)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(310)
			::cocktail::core::dom::Attr clonedAttr = this->attributes->item(i)->cloneNode(false);		HX_STACK_VAR(clonedAttr,"clonedAttr");
			HX_STACK_LINE(311)
			clonedElement->setAttributeNode(clonedAttr);
		}
	}
	HX_STACK_LINE(314)
	return clonedElement;
}


Array< ::cocktail::core::html::HTMLElement > Element_obj::getElementsByClassName( ::String className){
	HX_STACK_PUSH("Element::getElementsByClassName","cocktail/core/dom/Element.hx",289);
	HX_STACK_THIS(this);
	HX_STACK_ARG(className,"className");
	HX_STACK_LINE(290)
	Array< ::cocktail::core::html::HTMLElement > elements = Array_obj< ::cocktail::core::html::HTMLElement >::__new();		HX_STACK_VAR(elements,"elements");
	HX_STACK_LINE(291)
	this->doGetElementsByClassName(hx::ObjectPtr<OBJ_>(this),className,elements);
	HX_STACK_LINE(292)
	return elements;
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getElementsByClassName,return )

Array< ::cocktail::core::html::HTMLElement > Element_obj::getElementsByTagName( ::String tagName){
	HX_STACK_PUSH("Element::getElementsByTagName","cocktail/core/dom/Element.hx",272);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tagName,"tagName");
	HX_STACK_LINE(273)
	Array< ::cocktail::core::html::HTMLElement > elements = Array_obj< ::cocktail::core::html::HTMLElement >::__new();		HX_STACK_VAR(elements,"elements");
	HX_STACK_LINE(274)
	this->doGetElementsByTagName(hx::ObjectPtr<OBJ_>(this),tagName,elements);
	HX_STACK_LINE(275)
	return elements;
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getElementsByTagName,return )

bool Element_obj::hasAttribute( ::String name){
	HX_STACK_PUSH("Element::hasAttribute","cocktail/core/dom/Element.hx",258);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(258)
	return (this->attributes->getNamedItem(name) != null());
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,hasAttribute,return )

Void Element_obj::setIdAttributeNode( ::cocktail::core::dom::Attr idAttr,bool isId){
{
		HX_STACK_PUSH("Element::setIdAttributeNode","cocktail/core/dom/Element.hx",244);
		HX_STACK_THIS(this);
		HX_STACK_ARG(idAttr,"idAttr");
		HX_STACK_ARG(isId,"isId");
		HX_STACK_LINE(245)
		idAttr->isId = isId;
		HX_STACK_LINE(246)
		this->attributes->setNamedItem(idAttr);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Element_obj,setIdAttributeNode,(void))

Void Element_obj::setIdAttribute( ::String name,bool isId){
{
		HX_STACK_PUSH("Element::setIdAttribute","cocktail/core/dom/Element.hx",217);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(isId,"isId");
		HX_STACK_LINE(218)
		::cocktail::core::dom::Attr idAttribute = this->attributes->getNamedItem(name);		HX_STACK_VAR(idAttribute,"idAttribute");
		HX_STACK_LINE(219)
		if (((idAttribute == null()))){
			HX_STACK_LINE(221)
			idAttribute = ::cocktail::core::dom::Attr_obj::__new(name);
			HX_STACK_LINE(222)
			this->attributes->setNamedItem(idAttribute);
			HX_STACK_LINE(223)
			idAttribute->ownerElement = hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(226)
		idAttribute->isId = isId;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Element_obj,setIdAttribute,(void))

Void Element_obj::removeAttribute( ::String name){
{
		HX_STACK_PUSH("Element::removeAttribute","cocktail/core/dom/Element.hx",192);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_LINE(193)
		::cocktail::core::dom::Attr removedAttribute = this->attributes->removeNamedItem(name);		HX_STACK_VAR(removedAttribute,"removedAttribute");
		HX_STACK_LINE(195)
		if (((removedAttribute != null()))){
			HX_STACK_LINE(196)
			removedAttribute->ownerElement = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,removeAttribute,(void))

::cocktail::core::dom::Attr Element_obj::setAttributeNode( ::cocktail::core::dom::Attr newAttr){
	HX_STACK_PUSH("Element::setAttributeNode","cocktail/core/dom/Element.hx",176);
	HX_STACK_THIS(this);
	HX_STACK_ARG(newAttr,"newAttr");
	HX_STACK_LINE(177)
	newAttr->ownerElement = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(178)
	return this->attributes->setNamedItem(newAttr);
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,setAttributeNode,return )

::cocktail::core::dom::Attr Element_obj::getAttributeNode( ::String name){
	HX_STACK_PUSH("Element::getAttributeNode","cocktail/core/dom/Element.hx",154);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(155)
	::cocktail::core::dom::Attr attribute = this->attributes->getNamedItem(name);		HX_STACK_VAR(attribute,"attribute");
	HX_STACK_LINE(157)
	if (((attribute != null()))){
		HX_STACK_LINE(158)
		return attribute;
	}
	HX_STACK_LINE(162)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getAttributeNode,return )

Void Element_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("Element::setAttribute","cocktail/core/dom/Element.hx",133);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(134)
		::cocktail::core::dom::Attr attribute = this->attributes->getNamedItem(name);		HX_STACK_VAR(attribute,"attribute");
		HX_STACK_LINE(135)
		if (((attribute == null()))){
			HX_STACK_LINE(137)
			attribute = ::cocktail::core::dom::Attr_obj::__new(name);
			HX_STACK_LINE(138)
			this->attributes->setNamedItem(attribute);
			HX_STACK_LINE(139)
			attribute->ownerElement = hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(142)
		attribute->set_value(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Element_obj,setAttribute,(void))

::String Element_obj::getAttribute( ::String name){
	HX_STACK_PUSH("Element::getAttribute","cocktail/core/dom/Element.hx",102);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(103)
	::cocktail::core::dom::Attr attribute = this->getAttributeNode(name);		HX_STACK_VAR(attribute,"attribute");
	HX_STACK_LINE(104)
	if (((attribute != null()))){
		HX_STACK_LINE(105)
		return attribute->get_value();
	}
	else{
		HX_STACK_LINE(109)
		return null();
	}
	HX_STACK_LINE(104)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Element_obj,getAttribute,return )

Void Element_obj::initAttributes( ){
{
		HX_STACK_PUSH("Element::initAttributes","cocktail/core/dom/Element.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_LINE(82)
		this->attributes = ::cocktail::core::dom::NamedNodeMap_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Element_obj,initAttributes,(void))


Element_obj::Element_obj()
{
}

void Element_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Element);
	HX_MARK_MEMBER_NAME(childElementCount,"childElementCount");
	HX_MARK_MEMBER_NAME(nextElementSibling,"nextElementSibling");
	HX_MARK_MEMBER_NAME(previousElementSibling,"previousElementSibling");
	HX_MARK_MEMBER_NAME(lastElementChild,"lastElementChild");
	HX_MARK_MEMBER_NAME(firstElementChild,"firstElementChild");
	HX_MARK_MEMBER_NAME(tagName,"tagName");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Element_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(childElementCount,"childElementCount");
	HX_VISIT_MEMBER_NAME(nextElementSibling,"nextElementSibling");
	HX_VISIT_MEMBER_NAME(previousElementSibling,"previousElementSibling");
	HX_VISIT_MEMBER_NAME(lastElementChild,"lastElementChild");
	HX_VISIT_MEMBER_NAME(firstElementChild,"firstElementChild");
	HX_VISIT_MEMBER_NAME(tagName,"tagName");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Element_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"tagName") ) { return tagName; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"doCloneNode") ) { return doCloneNode_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAttribute") ) { return hasAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"getAttribute") ) { return getAttribute_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasAttributes") ) { return hasAttributes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setIdAttribute") ) { return setIdAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"initAttributes") ) { return initAttributes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeAttribute") ) { return removeAttribute_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setAttributeNode") ) { return setAttributeNode_dyn(); }
		if (HX_FIELD_EQ(inName,"getAttributeNode") ) { return getAttributeNode_dyn(); }
		if (HX_FIELD_EQ(inName,"lastElementChild") ) { return inCallProp ? get_lastElementChild() : lastElementChild; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"childElementCount") ) { return inCallProp ? get_childElementCount() : childElementCount; }
		if (HX_FIELD_EQ(inName,"firstElementChild") ) { return inCallProp ? get_firstElementChild() : firstElementChild; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setIdAttributeNode") ) { return setIdAttributeNode_dyn(); }
		if (HX_FIELD_EQ(inName,"nextElementSibling") ) { return inCallProp ? get_nextElementSibling() : nextElementSibling; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_lastElementChild") ) { return get_lastElementChild_dyn(); }
		if (HX_FIELD_EQ(inName,"getElementsByTagName") ) { return getElementsByTagName_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_childElementCount") ) { return get_childElementCount_dyn(); }
		if (HX_FIELD_EQ(inName,"get_firstElementChild") ) { return get_firstElementChild_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"get_nextElementSibling") ) { return get_nextElementSibling_dyn(); }
		if (HX_FIELD_EQ(inName,"doGetElementsByTagName") ) { return doGetElementsByTagName_dyn(); }
		if (HX_FIELD_EQ(inName,"getElementsByClassName") ) { return getElementsByClassName_dyn(); }
		if (HX_FIELD_EQ(inName,"previousElementSibling") ) { return inCallProp ? get_previousElementSibling() : previousElementSibling; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"doGetElementsByClassName") ) { return doGetElementsByClassName_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"get_previousElementSibling") ) { return get_previousElementSibling_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Element_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"tagName") ) { tagName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lastElementChild") ) { lastElementChild=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"childElementCount") ) { childElementCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstElementChild") ) { firstElementChild=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nextElementSibling") ) { nextElementSibling=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"previousElementSibling") ) { previousElementSibling=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Element_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("childElementCount"));
	outFields->push(HX_CSTRING("nextElementSibling"));
	outFields->push(HX_CSTRING("previousElementSibling"));
	outFields->push(HX_CSTRING("lastElementChild"));
	outFields->push(HX_CSTRING("firstElementChild"));
	outFields->push(HX_CSTRING("tagName"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_childElementCount"),
	HX_CSTRING("get_previousElementSibling"),
	HX_CSTRING("get_nextElementSibling"),
	HX_CSTRING("get_lastElementChild"),
	HX_CSTRING("get_firstElementChild"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("hasAttributes"),
	HX_CSTRING("doGetElementsByClassName"),
	HX_CSTRING("doGetElementsByTagName"),
	HX_CSTRING("doCloneNode"),
	HX_CSTRING("getElementsByClassName"),
	HX_CSTRING("getElementsByTagName"),
	HX_CSTRING("hasAttribute"),
	HX_CSTRING("setIdAttributeNode"),
	HX_CSTRING("setIdAttribute"),
	HX_CSTRING("removeAttribute"),
	HX_CSTRING("setAttributeNode"),
	HX_CSTRING("getAttributeNode"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("getAttribute"),
	HX_CSTRING("initAttributes"),
	HX_CSTRING("childElementCount"),
	HX_CSTRING("nextElementSibling"),
	HX_CSTRING("previousElementSibling"),
	HX_CSTRING("lastElementChild"),
	HX_CSTRING("firstElementChild"),
	HX_CSTRING("tagName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Element_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Element_obj::__mClass,"__mClass");
};

Class Element_obj::__mClass;

void Element_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Element"), hx::TCanCast< Element_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Element_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
