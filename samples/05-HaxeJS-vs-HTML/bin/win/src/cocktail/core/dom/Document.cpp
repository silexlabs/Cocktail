#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_event_CustomEvent
#include <cocktail/core/event/CustomEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_FocusEvent
#include <cocktail/core/event/FocusEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_PopStateEvent
#include <cocktail/core/event/PopStateEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TransitionEvent
#include <cocktail/core/event/TransitionEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_WheelEvent
#include <cocktail/core/event/WheelEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void Document_obj::__construct()
{
HX_STACK_PUSH("Document::new","cocktail/core/dom/Document.hx",49);
{
	HX_STACK_LINE(49)
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

int Document_obj::get_nodeType( ){
	HX_STACK_PUSH("Document::get_nodeType","cocktail/core/dom/Document.hx",290);
	HX_STACK_THIS(this);
	HX_STACK_LINE(290)
	return (int)9;
}


Array< ::cocktail::core::html::HTMLElement > Document_obj::getElementsByClassName( ::String className){
	HX_STACK_PUSH("Document::getElementsByClassName","cocktail/core/dom/Document.hx",281);
	HX_STACK_THIS(this);
	HX_STACK_ARG(className,"className");
	HX_STACK_LINE(281)
	return this->documentElement->getElementsByClassName(className);
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,getElementsByClassName,return )

Array< ::cocktail::core::html::HTMLElement > Document_obj::getElementsByTagName( ::String tagName){
	HX_STACK_PUSH("Document::getElementsByTagName","cocktail/core/dom/Document.hx",264);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tagName,"tagName");
	HX_STACK_LINE(264)
	return this->documentElement->getElementsByTagName(tagName);
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,getElementsByTagName,return )

::cocktail::core::html::HTMLElement Document_obj::doGetElementById( ::cocktail::core::html::HTMLElement node,::String elementId){
	HX_STACK_PUSH("Document::doGetElementById","cocktail/core/dom/Document.hx",202);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(elementId,"elementId");
	HX_STACK_LINE(204)
	if (((bool((node->hasChildNodes() == true)) && bool((node->get_nodeType() == (int)1))))){
		HX_STACK_LINE(206)
		int length = node->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(207)
		{
			HX_STACK_LINE(207)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(207)
			while(((_g < length))){
				HX_STACK_LINE(207)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(209)
				::cocktail::core::html::HTMLElement matchingElement = this->doGetElementById(node->childNodes->__GetItem(i),elementId);		HX_STACK_VAR(matchingElement,"matchingElement");
				HX_STACK_LINE(211)
				if (((matchingElement != null()))){
					HX_STACK_LINE(212)
					return matchingElement;
				}
			}
		}
	}
	HX_STACK_LINE(220)
	if (((node->hasAttributes() == true))){
		HX_STACK_LINE(222)
		::cocktail::core::dom::NamedNodeMap attributes = node->attributes;		HX_STACK_VAR(attributes,"attributes");
		HX_STACK_LINE(223)
		::cocktail::core::html::HTMLElement element = node;		HX_STACK_VAR(element,"element");
		HX_STACK_LINE(227)
		int attributesLength = attributes->get_length();		HX_STACK_VAR(attributesLength,"attributesLength");
		HX_STACK_LINE(228)
		{
			HX_STACK_LINE(228)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(228)
			while(((_g < attributesLength))){
				HX_STACK_LINE(228)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(230)
				::cocktail::core::dom::Attr attribute = element->getAttributeNode(attributes->item(i)->get_nodeName());		HX_STACK_VAR(attribute,"attribute");
				HX_STACK_LINE(233)
				if (((bool((attribute->isId == true)) && bool((attribute->specified == true))))){
					HX_STACK_LINE(234)
					if (((attribute->get_value() == elementId))){
						HX_STACK_LINE(237)
						return element;
					}
				}
			}
		}
	}
	HX_STACK_LINE(245)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Document_obj,doGetElementById,return )

::cocktail::core::html::HTMLElement Document_obj::getElementById( ::String elementId){
	HX_STACK_PUSH("Document::getElementById","cocktail/core/dom/Document.hx",188);
	HX_STACK_THIS(this);
	HX_STACK_ARG(elementId,"elementId");
	HX_STACK_LINE(188)
	return this->doGetElementById(this->documentElement,elementId);
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,getElementById,return )

::cocktail::core::event::Event Document_obj::createEvent( ::String eventInterface){
	HX_STACK_PUSH("Document::createEvent","cocktail/core/dom/Document.hx",137);
	HX_STACK_THIS(this);
	HX_STACK_ARG(eventInterface,"eventInterface");
	HX_STACK_LINE(138)
	::String _switch_1 = (eventInterface);
	if (  ( _switch_1==HX_CSTRING("Event"))){
		HX_STACK_LINE(140)
		return ::cocktail::core::event::Event_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("UIEvent"))){
		HX_STACK_LINE(143)
		return ::cocktail::core::event::UIEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("CustomEvent"))){
		HX_STACK_LINE(146)
		return ::cocktail::core::event::CustomEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("MouseEvent"))){
		HX_STACK_LINE(149)
		return ::cocktail::core::event::MouseEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("KeyboardEvent"))){
		HX_STACK_LINE(152)
		return ::cocktail::core::event::KeyboardEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("FocusEvent"))){
		HX_STACK_LINE(155)
		return ::cocktail::core::event::FocusEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("WheelEvent"))){
		HX_STACK_LINE(158)
		return ::cocktail::core::event::WheelEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("TransitionEvent"))){
		HX_STACK_LINE(161)
		return ::cocktail::core::event::TransitionEvent_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("PopStateEvent"))){
		HX_STACK_LINE(164)
		return ::cocktail::core::event::PopStateEvent_obj::__new();
	}
	else  {
		HX_STACK_LINE(167)
		hx::Throw ((int)9);
	}
;
;
	HX_STACK_LINE(171)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createEvent,return )

::cocktail::core::dom::Attr Document_obj::createAttribute( ::String name){
	HX_STACK_PUSH("Document::createAttribute","cocktail/core/dom/Document.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(123)
	::cocktail::core::dom::Attr attribute = ::cocktail::core::dom::Attr_obj::__new(name);		HX_STACK_VAR(attribute,"attribute");
	HX_STACK_LINE(124)
	return attribute;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createAttribute,return )

::cocktail::core::dom::Comment Document_obj::createComment( ::String data){
	HX_STACK_PUSH("Document::createComment","cocktail/core/dom/Document.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(101)
	::cocktail::core::dom::Comment comment = ::cocktail::core::dom::Comment_obj::__new();		HX_STACK_VAR(comment,"comment");
	HX_STACK_LINE(102)
	comment->set_nodeValue(data);
	HX_STACK_LINE(103)
	return comment;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createComment,return )

::cocktail::core::dom::Text Document_obj::createTextNode( ::String data){
	HX_STACK_PUSH("Document::createTextNode","cocktail/core/dom/Document.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(87)
	::cocktail::core::dom::Text text = ::cocktail::core::dom::Text_obj::__new();		HX_STACK_VAR(text,"text");
	HX_STACK_LINE(88)
	text->set_nodeValue(data);
	HX_STACK_LINE(89)
	text->set_ownerDocument(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(91)
	return text;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createTextNode,return )

::cocktail::core::html::HTMLElement Document_obj::createElement( ::String tagName){
	HX_STACK_PUSH("Document::createElement","cocktail/core/dom/Document.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tagName,"tagName");
	HX_STACK_LINE(76)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createElement,return )


Document_obj::Document_obj()
{
}

void Document_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Document);
	HX_MARK_MEMBER_NAME(documentElement,"documentElement");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Document_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(documentElement,"documentElement");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Document_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"createEvent") ) { return createEvent_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createComment") ) { return createComment_dyn(); }
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getElementById") ) { return getElementById_dyn(); }
		if (HX_FIELD_EQ(inName,"createTextNode") ) { return createTextNode_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"createAttribute") ) { return createAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"documentElement") ) { return documentElement; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"doGetElementById") ) { return doGetElementById_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getElementsByTagName") ) { return getElementsByTagName_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getElementsByClassName") ) { return getElementsByClassName_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Document_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"documentElement") ) { documentElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Document_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("documentElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("getElementsByClassName"),
	HX_CSTRING("getElementsByTagName"),
	HX_CSTRING("doGetElementById"),
	HX_CSTRING("getElementById"),
	HX_CSTRING("createEvent"),
	HX_CSTRING("createAttribute"),
	HX_CSTRING("createComment"),
	HX_CSTRING("createTextNode"),
	HX_CSTRING("createElement"),
	HX_CSTRING("documentElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Document_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Document_obj::__mClass,"__mClass");
};

Class Document_obj::__mClass;

void Document_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Document"), hx::TCanCast< Document_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Document_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
