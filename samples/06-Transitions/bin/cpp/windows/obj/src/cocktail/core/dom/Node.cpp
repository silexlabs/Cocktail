#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
namespace cocktail{
namespace core{
namespace dom{

Void Node_obj::__construct()
{
HX_STACK_PUSH("Node::new","cocktail/core/dom/Node.hx",107);
{
	HX_STACK_LINE(108)
	super::__construct();
	HX_STACK_LINE(109)
	this->initChildNodes();
}
;
	return null();
}

Node_obj::~Node_obj() { }

Dynamic Node_obj::__CreateEmpty() { return  new Node_obj; }
hx::ObjectPtr< Node_obj > Node_obj::__new()
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct();
	return result;}

Dynamic Node_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct();
	return result;}

::String Node_obj::get_nodeName( ){
	HX_STACK_PUSH("Node::get_nodeName","cocktail/core/dom/Node.hx",466);
	HX_STACK_THIS(this);
	HX_STACK_LINE(466)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeName,return )

::cocktail::core::dom::Document Node_obj::set_ownerDocument( ::cocktail::core::dom::Document value){
	HX_STACK_PUSH("Node::set_ownerDocument","cocktail/core/dom/Node.hx",461);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(461)
	return this->ownerDocument = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_ownerDocument,return )

::String Node_obj::set_nodeValue( ::String value){
	HX_STACK_PUSH("Node::set_nodeValue","cocktail/core/dom/Node.hx",450);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(451)
	if (((value != null()))){
		HX_STACK_LINE(452)
		hx::Throw ((int)7);
	}
	HX_STACK_LINE(457)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_nodeValue,return )

::String Node_obj::get_nodeValue( ){
	HX_STACK_PUSH("Node::get_nodeValue","cocktail/core/dom/Node.hx",445);
	HX_STACK_THIS(this);
	HX_STACK_LINE(445)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeValue,return )

int Node_obj::get_nodeType( ){
	HX_STACK_PUSH("Node::get_nodeType","cocktail/core/dom/Node.hx",440);
	HX_STACK_THIS(this);
	HX_STACK_LINE(440)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeType,return )

Dynamic Node_obj::get_previousSibling( ){
	HX_STACK_PUSH("Node::get_previousSibling","cocktail/core/dom/Node.hx",419);
	HX_STACK_THIS(this);
	HX_STACK_LINE(420)
	if (((this->parentNode == null()))){
		HX_STACK_LINE(421)
		return null();
	}
	else{
		HX_STACK_LINE(424)
		if (((this->parentNode->__Field(HX_CSTRING("get_firstChild"),true)() != hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(426)
			int length = this->parentNode->__Field(HX_CSTRING("childNodes"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(427)
			{
				HX_STACK_LINE(427)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(427)
				while(((_g < length))){
					HX_STACK_LINE(427)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(429)
					if (((this->parentNode->__Field(HX_CSTRING("childNodes"),true)->__GetItem(i) == hx::ObjectPtr<OBJ_>(this)))){
						HX_STACK_LINE(430)
						return this->parentNode->__Field(HX_CSTRING("childNodes"),true)->__GetItem((i - (int)1));
					}
				}
			}
		}
	}
	HX_STACK_LINE(436)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_previousSibling,return )

Dynamic Node_obj::get_nextSibling( ){
	HX_STACK_PUSH("Node::get_nextSibling","cocktail/core/dom/Node.hx",379);
	HX_STACK_THIS(this);
	HX_STACK_LINE(382)
	if (((this->parentNode == null()))){
		HX_STACK_LINE(383)
		return null();
	}
	else{
		HX_STACK_LINE(387)
		if (((this->parentNode->__Field(HX_CSTRING("get_lastChild"),true)() != hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(391)
			Dynamic parentChildNodes = this->parentNode->__Field(HX_CSTRING("childNodes"),true);		HX_STACK_VAR(parentChildNodes,"parentChildNodes");
			HX_STACK_LINE(392)
			int length = parentChildNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(393)
			{
				HX_STACK_LINE(393)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(393)
				while(((_g < length))){
					HX_STACK_LINE(393)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(402)
					if (((parentChildNodes->__GetItem(i) == hx::ObjectPtr<OBJ_>(this)))){
						HX_STACK_LINE(404)
						return parentChildNodes->__GetItem((i + (int)1));
					}
				}
			}
		}
	}
	HX_STACK_LINE(412)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nextSibling,return )

Dynamic Node_obj::get_lastChild( ){
	HX_STACK_PUSH("Node::get_lastChild","cocktail/core/dom/Node.hx",367);
	HX_STACK_THIS(this);
	HX_STACK_LINE(367)
	if (((this->hasChildNodes() == true))){
		HX_STACK_LINE(369)
		return this->childNodes->__GetItem((this->childNodes->__Field(HX_CSTRING("length"),true) - (int)1));
	}
	else{
		HX_STACK_LINE(373)
		return null();
	}
	HX_STACK_LINE(367)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_lastChild,return )

Dynamic Node_obj::get_firstChild( ){
	HX_STACK_PUSH("Node::get_firstChild","cocktail/core/dom/Node.hx",355);
	HX_STACK_THIS(this);
	HX_STACK_LINE(355)
	if (((this->hasChildNodes() == true))){
		HX_STACK_LINE(357)
		return this->childNodes->__GetItem((int)0);
	}
	else{
		HX_STACK_LINE(361)
		return null();
	}
	HX_STACK_LINE(355)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_firstChild,return )

Void Node_obj::removeFromParentIfNecessary( Dynamic newChild){
{
		HX_STACK_PUSH("Node::removeFromParentIfNecessary","cocktail/core/dom/Node.hx",342);
		HX_STACK_THIS(this);
		HX_STACK_ARG(newChild,"newChild");
		HX_STACK_LINE(342)
		if (((newChild->__Field(HX_CSTRING("parentNode"),true) != null()))){
			HX_STACK_LINE(345)
			Dynamic parentNode = newChild->__Field(HX_CSTRING("parentNode"),true);		HX_STACK_VAR(parentNode,"parentNode");
			HX_STACK_LINE(346)
			parentNode->__Field(HX_CSTRING("removeChild"),true)(newChild);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeFromParentIfNecessary,(void))

Dynamic Node_obj::doCloneNode( ){
	HX_STACK_PUSH("Node::doCloneNode","cocktail/core/dom/Node.hx",333);
	HX_STACK_THIS(this);
	HX_STACK_LINE(333)
	return ::cocktail::core::dom::Node_obj::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,doCloneNode,return )

Array< ::cocktail::core::event::EventTarget > Node_obj::getTargetAncestors( ){
	HX_STACK_PUSH("Node::getTargetAncestors","cocktail/core/dom/Node.hx",310);
	HX_STACK_THIS(this);
	HX_STACK_LINE(311)
	Dynamic parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(312)
	Array< ::cocktail::core::event::EventTarget > targetAncestors = this->super::getTargetAncestors();		HX_STACK_VAR(targetAncestors,"targetAncestors");
	HX_STACK_LINE(314)
	while(((parent != null()))){
		HX_STACK_LINE(316)
		targetAncestors->push(parent);
		HX_STACK_LINE(317)
		parent = parent->__Field(HX_CSTRING("parentNode"),true);
	}
	HX_STACK_LINE(320)
	return targetAncestors;
}


bool Node_obj::hasAttributes( ){
	HX_STACK_PUSH("Node::hasAttributes","cocktail/core/dom/Node.hx",297);
	HX_STACK_THIS(this);
	HX_STACK_LINE(297)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,hasAttributes,return )

Dynamic Node_obj::cloneNode( bool deep){
	HX_STACK_PUSH("Node::cloneNode","cocktail/core/dom/Node.hx",279);
	HX_STACK_THIS(this);
	HX_STACK_ARG(deep,"deep");
	HX_STACK_LINE(280)
	::cocktail::core::dom::Node clonedNode = this->doCloneNode();		HX_STACK_VAR(clonedNode,"clonedNode");
	HX_STACK_LINE(281)
	if (((deep == true))){
		HX_STACK_LINE(283)
		int childLength = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(childLength,"childLength");
		HX_STACK_LINE(284)
		{
			HX_STACK_LINE(284)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(284)
			while(((_g < childLength))){
				HX_STACK_LINE(284)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(286)
				clonedNode->appendChild(this->childNodes->__GetItem(i)->__Field(HX_CSTRING("cloneNode"),true)(deep));
			}
		}
	}
	HX_STACK_LINE(289)
	return clonedNode;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,cloneNode,return )

bool Node_obj::hasChildNodes( ){
	HX_STACK_PUSH("Node::hasChildNodes","cocktail/core/dom/Node.hx",249);
	HX_STACK_THIS(this);
	HX_STACK_LINE(249)
	return (this->childNodes->__Field(HX_CSTRING("length"),true) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,hasChildNodes,return )

Dynamic Node_obj::replaceChild( Dynamic newChild,Dynamic oldChild){
	HX_STACK_PUSH("Node::replaceChild","cocktail/core/dom/Node.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_ARG(newChild,"newChild");
	HX_STACK_ARG(oldChild,"oldChild");
	HX_STACK_LINE(232)
	int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(233)
	{
		HX_STACK_LINE(233)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(233)
		while(((_g < length))){
			HX_STACK_LINE(233)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(235)
			if (((this->childNodes->__GetItem(i) == oldChild))){
				HX_STACK_LINE(237)
				this->removeChild(oldChild);
				HX_STACK_LINE(238)
				this->appendChild(newChild);
			}
		}
	}
	HX_STACK_LINE(242)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,replaceChild,return )

bool Node_obj::isSameNode( Dynamic other){
	HX_STACK_PUSH("Node::isSameNode","cocktail/core/dom/Node.hx",215);
	HX_STACK_THIS(this);
	HX_STACK_ARG(other,"other");
	HX_STACK_LINE(215)
	return (other == hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,isSameNode,return )

Dynamic Node_obj::insertBefore( Dynamic newChild,Dynamic refChild){
	HX_STACK_PUSH("Node::insertBefore","cocktail/core/dom/Node.hx",172);
	HX_STACK_THIS(this);
	HX_STACK_ARG(newChild,"newChild");
	HX_STACK_ARG(refChild,"refChild");
	HX_STACK_LINE(173)
	if (((refChild == null()))){
		HX_STACK_LINE(174)
		this->appendChild(newChild);
	}
	else{
		HX_STACK_LINE(179)
		int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(180)
		{
			HX_STACK_LINE(180)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(180)
			while(((_g < length))){
				HX_STACK_LINE(180)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(182)
				if (((this->childNodes->__GetItem(i) == refChild))){
					HX_STACK_LINE(184)
					this->childNodes->__Field(HX_CSTRING("insert"),true)(i,newChild);
					HX_STACK_LINE(187)
					this->removeFromParentIfNecessary(newChild);
					HX_STACK_LINE(188)
					newChild->__FieldRef(HX_CSTRING("parentNode")) = hx::ObjectPtr<OBJ_>(this);
					HX_STACK_LINE(189)
					return newChild;
				}
			}
		}
		HX_STACK_LINE(195)
		hx::Throw ((int)8);
	}
	HX_STACK_LINE(198)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,insertBefore,return )

Dynamic Node_obj::appendChild( Dynamic newChild){
	HX_STACK_PUSH("Node::appendChild","cocktail/core/dom/Node.hx",150);
	HX_STACK_THIS(this);
	HX_STACK_ARG(newChild,"newChild");
	HX_STACK_LINE(151)
	this->removeFromParentIfNecessary(newChild);
	HX_STACK_LINE(153)
	newChild->__FieldRef(HX_CSTRING("parentNode")) = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(154)
	this->childNodes->__Field(HX_CSTRING("push"),true)(newChild);
	HX_STACK_LINE(156)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,appendChild,return )

Dynamic Node_obj::removeChild( Dynamic oldChild){
	HX_STACK_PUSH("Node::removeChild","cocktail/core/dom/Node.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_ARG(oldChild,"oldChild");
	HX_STACK_LINE(134)
	oldChild->__FieldRef(HX_CSTRING("parentNode")) = null();
	HX_STACK_LINE(135)
	this->childNodes->__Field(HX_CSTRING("remove"),true)(oldChild);
	HX_STACK_LINE(136)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeChild,return )

Void Node_obj::initChildNodes( ){
{
		HX_STACK_PUSH("Node::initChildNodes","cocktail/core/dom/Node.hx",117);
		HX_STACK_THIS(this);
		HX_STACK_LINE(117)
		this->childNodes = Dynamic( Array_obj<Dynamic>::__new() );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,initChildNodes,(void))


Node_obj::Node_obj()
{
}

void Node_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Node);
	HX_MARK_MEMBER_NAME(ownerDocument,"ownerDocument");
	HX_MARK_MEMBER_NAME(attributes,"attributes");
	HX_MARK_MEMBER_NAME(nodeName,"nodeName");
	HX_MARK_MEMBER_NAME(nodeValue,"nodeValue");
	HX_MARK_MEMBER_NAME(nodeType,"nodeType");
	HX_MARK_MEMBER_NAME(previousSibling,"previousSibling");
	HX_MARK_MEMBER_NAME(nextSibling,"nextSibling");
	HX_MARK_MEMBER_NAME(lastChild,"lastChild");
	HX_MARK_MEMBER_NAME(firstChild,"firstChild");
	HX_MARK_MEMBER_NAME(childNodes,"childNodes");
	HX_MARK_MEMBER_NAME(parentNode,"parentNode");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Node_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ownerDocument,"ownerDocument");
	HX_VISIT_MEMBER_NAME(attributes,"attributes");
	HX_VISIT_MEMBER_NAME(nodeName,"nodeName");
	HX_VISIT_MEMBER_NAME(nodeValue,"nodeValue");
	HX_VISIT_MEMBER_NAME(nodeType,"nodeType");
	HX_VISIT_MEMBER_NAME(previousSibling,"previousSibling");
	HX_VISIT_MEMBER_NAME(nextSibling,"nextSibling");
	HX_VISIT_MEMBER_NAME(lastChild,"lastChild");
	HX_VISIT_MEMBER_NAME(firstChild,"firstChild");
	HX_VISIT_MEMBER_NAME(childNodes,"childNodes");
	HX_VISIT_MEMBER_NAME(parentNode,"parentNode");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Node_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nodeName") ) { return inCallProp ? get_nodeName() : nodeName; }
		if (HX_FIELD_EQ(inName,"nodeType") ) { return inCallProp ? get_nodeType() : nodeType; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"cloneNode") ) { return cloneNode_dyn(); }
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return inCallProp ? get_nodeValue() : nodeValue; }
		if (HX_FIELD_EQ(inName,"lastChild") ) { return inCallProp ? get_lastChild() : lastChild; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isSameNode") ) { return isSameNode_dyn(); }
		if (HX_FIELD_EQ(inName,"attributes") ) { return attributes; }
		if (HX_FIELD_EQ(inName,"firstChild") ) { return inCallProp ? get_firstChild() : firstChild; }
		if (HX_FIELD_EQ(inName,"childNodes") ) { return childNodes; }
		if (HX_FIELD_EQ(inName,"parentNode") ) { return parentNode; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"doCloneNode") ) { return doCloneNode_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nextSibling") ) { return inCallProp ? get_nextSibling() : nextSibling; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		if (HX_FIELD_EQ(inName,"replaceChild") ) { return replaceChild_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lastChild") ) { return get_lastChild_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAttributes") ) { return hasAttributes_dyn(); }
		if (HX_FIELD_EQ(inName,"hasChildNodes") ) { return hasChildNodes_dyn(); }
		if (HX_FIELD_EQ(inName,"ownerDocument") ) { return ownerDocument; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_firstChild") ) { return get_firstChild_dyn(); }
		if (HX_FIELD_EQ(inName,"initChildNodes") ) { return initChildNodes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_nextSibling") ) { return get_nextSibling_dyn(); }
		if (HX_FIELD_EQ(inName,"previousSibling") ) { return inCallProp ? get_previousSibling() : previousSibling; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"set_ownerDocument") ) { return set_ownerDocument_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getTargetAncestors") ) { return getTargetAncestors_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_previousSibling") ) { return get_previousSibling_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"removeFromParentIfNecessary") ) { return removeFromParentIfNecessary_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Node_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nodeName") ) { nodeName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nodeValue") ) { if (inCallProp) return set_nodeValue(inValue);nodeValue=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lastChild") ) { lastChild=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"attributes") ) { attributes=inValue.Cast< ::cocktail::core::dom::NamedNodeMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstChild") ) { firstChild=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"childNodes") ) { childNodes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parentNode") ) { parentNode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nextSibling") ) { nextSibling=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ownerDocument") ) { if (inCallProp) return set_ownerDocument(inValue);ownerDocument=inValue.Cast< ::cocktail::core::dom::Document >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { previousSibling=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Node_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ownerDocument"));
	outFields->push(HX_CSTRING("attributes"));
	outFields->push(HX_CSTRING("nodeName"));
	outFields->push(HX_CSTRING("nodeValue"));
	outFields->push(HX_CSTRING("nodeType"));
	outFields->push(HX_CSTRING("previousSibling"));
	outFields->push(HX_CSTRING("nextSibling"));
	outFields->push(HX_CSTRING("lastChild"));
	outFields->push(HX_CSTRING("firstChild"));
	outFields->push(HX_CSTRING("childNodes"));
	outFields->push(HX_CSTRING("parentNode"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("set_ownerDocument"),
	HX_CSTRING("set_nodeValue"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_previousSibling"),
	HX_CSTRING("get_nextSibling"),
	HX_CSTRING("get_lastChild"),
	HX_CSTRING("get_firstChild"),
	HX_CSTRING("removeFromParentIfNecessary"),
	HX_CSTRING("doCloneNode"),
	HX_CSTRING("getTargetAncestors"),
	HX_CSTRING("hasAttributes"),
	HX_CSTRING("cloneNode"),
	HX_CSTRING("hasChildNodes"),
	HX_CSTRING("replaceChild"),
	HX_CSTRING("isSameNode"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("initChildNodes"),
	HX_CSTRING("ownerDocument"),
	HX_CSTRING("attributes"),
	HX_CSTRING("nodeName"),
	HX_CSTRING("nodeValue"),
	HX_CSTRING("nodeType"),
	HX_CSTRING("previousSibling"),
	HX_CSTRING("nextSibling"),
	HX_CSTRING("lastChild"),
	HX_CSTRING("firstChild"),
	HX_CSTRING("childNodes"),
	HX_CSTRING("parentNode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Node_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Node_obj::__mClass,"__mClass");
};

Class Node_obj::__mClass;

void Node_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Node"), hx::TCanCast< Node_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Node_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
