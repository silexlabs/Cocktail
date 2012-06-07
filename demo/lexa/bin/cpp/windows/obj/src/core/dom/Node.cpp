#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_dom_NodeType
#include <core/dom/NodeType.h>
#endif
namespace core{
namespace dom{

Void Node_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/dom/Node.hx",98)
	this->_childNodes = Array_obj< ::core::dom::Node >::__new();
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

::core::dom::Node Node_obj::removeChild( ::core::dom::Node oldChild){
	HX_SOURCE_PUSH("Node_obj::removeChild")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",115)
	oldChild->set_parentNode(null());
	HX_SOURCE_POS("../../src/core/dom/Node.hx",117)
	Array< ::core::dom::Node > newChildNodes = Array_obj< ::core::dom::Node >::__new();
	HX_SOURCE_POS("../../src/core/dom/Node.hx",118)
	{
		HX_SOURCE_POS("../../src/core/dom/Node.hx",118)
		int _g1 = (int)0;
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/core/dom/Node.hx",118)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/dom/Node.hx",118)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/dom/Node.hx",120)
			if (((this->_childNodes->__get(i) != oldChild))){
				HX_SOURCE_POS("../../src/core/dom/Node.hx",121)
				newChildNodes->push(this->_childNodes->__get(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/core/dom/Node.hx",125)
	this->_childNodes = newChildNodes;
	HX_SOURCE_POS("../../src/core/dom/Node.hx",127)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeChild,return )

::core::dom::Node Node_obj::appendChild( ::core::dom::Node newChild){
	HX_SOURCE_PUSH("Node_obj::appendChild")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",142)
	if (((newChild->get_parentNode() != null()))){
		HX_SOURCE_POS("../../src/core/dom/Node.hx",144)
		::core::dom::Node parentNode = newChild->get_parentNode();
		HX_SOURCE_POS("../../src/core/dom/Node.hx",145)
		parentNode->removeChild(newChild);
	}
	HX_SOURCE_POS("../../src/core/dom/Node.hx",147)
	newChild->set_parentNode(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/core/dom/Node.hx",148)
	this->_childNodes->push(newChild);
	HX_SOURCE_POS("../../src/core/dom/Node.hx",150)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,appendChild,return )

::core::dom::Node Node_obj::get_firstChild( ){
	HX_SOURCE_PUSH("Node_obj::get_firstChild")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",158)
	if (((this->get_hasChildNodes() == true))){
		HX_SOURCE_POS("../../src/core/dom/Node.hx",160)
		return this->_childNodes->__get((int)0);
	}
	else{
		HX_SOURCE_POS("../../src/core/dom/Node.hx",164)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_firstChild,return )

::core::dom::Node Node_obj::get_lastChild( ){
	HX_SOURCE_PUSH("Node_obj::get_lastChild")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",170)
	if (((this->get_hasChildNodes() == true))){
		HX_SOURCE_POS("../../src/core/dom/Node.hx",172)
		return this->_childNodes->__get((this->_childNodes->length - (int)1));
	}
	else{
		HX_SOURCE_POS("../../src/core/dom/Node.hx",176)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_lastChild,return )

::core::dom::Node Node_obj::get_nextSibling( ){
	HX_SOURCE_PUSH("Node_obj::get_nextSibling")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",185)
	if (((this->_parentNode == null()))){
		HX_SOURCE_POS("../../src/core/dom/Node.hx",186)
		return null();
	}
	else{
		HX_SOURCE_POS("../../src/core/dom/Node.hx",190)
		if (((this->_parentNode->get_lastChild() != hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("../../src/core/dom/Node.hx",194)
			int _g1 = (int)0;
			int _g = this->_parentNode->get_childNodes()->length;
			HX_SOURCE_POS("../../src/core/dom/Node.hx",194)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/dom/Node.hx",194)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/dom/Node.hx",196)
				if (((this->_parentNode->get_childNodes()->__get(i) == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("../../src/core/dom/Node.hx",197)
					return this->_parentNode->get_childNodes()->__get((i + (int)1));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/core/dom/Node.hx",205)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nextSibling,return )

::core::dom::Node Node_obj::get_previousSibling( ){
	HX_SOURCE_PUSH("Node_obj::get_previousSibling")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",213)
	if (((this->_parentNode == null()))){
		HX_SOURCE_POS("../../src/core/dom/Node.hx",214)
		return null();
	}
	else{
		HX_SOURCE_POS("../../src/core/dom/Node.hx",217)
		if (((this->_parentNode->get_firstChild() != hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("../../src/core/dom/Node.hx",219)
			int _g1 = (int)0;
			int _g = this->_parentNode->get_childNodes()->length;
			HX_SOURCE_POS("../../src/core/dom/Node.hx",219)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/dom/Node.hx",219)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/dom/Node.hx",221)
				if (((this->_parentNode->get_childNodes()->__get(i) == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("../../src/core/dom/Node.hx",222)
					return this->_parentNode->get_childNodes()->__get((i - (int)1));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/core/dom/Node.hx",228)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_previousSibling,return )

bool Node_obj::get_hasChildNodes( ){
	HX_SOURCE_PUSH("Node_obj::get_hasChildNodes")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",232)
	return (this->_childNodes->length > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_hasChildNodes,return )

::core::dom::NodeType Node_obj::get_nodeType( ){
	HX_SOURCE_PUSH("Node_obj::get_nodeType")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",237)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeType,return )

::core::dom::Node Node_obj::get_parentNode( ){
	HX_SOURCE_PUSH("Node_obj::get_parentNode")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",242)
	return this->_parentNode;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_parentNode,return )

::core::dom::Node Node_obj::set_parentNode( ::core::dom::Node value){
	HX_SOURCE_PUSH("Node_obj::set_parentNode")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",247)
	return this->_parentNode = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_parentNode,return )

Array< ::core::dom::Node > Node_obj::get_childNodes( ){
	HX_SOURCE_PUSH("Node_obj::get_childNodes")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",252)
	return this->_childNodes;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_childNodes,return )

::String Node_obj::get_nodeValue( ){
	HX_SOURCE_PUSH("Node_obj::get_nodeValue")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",257)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeValue,return )

::String Node_obj::set_nodeValue( ::String value){
	HX_SOURCE_PUSH("Node_obj::set_nodeValue")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",262)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_nodeValue,return )

::String Node_obj::get_nodeName( ){
	HX_SOURCE_PUSH("Node_obj::get_nodeName")
	HX_SOURCE_POS("../../src/core/dom/Node.hx",267)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeName,return )


Node_obj::Node_obj()
{
}

void Node_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Node);
	HX_MARK_MEMBER_NAME(nodeType,"nodeType");
	HX_MARK_MEMBER_NAME(nodeValue,"nodeValue");
	HX_MARK_MEMBER_NAME(nodeName,"nodeName");
	HX_MARK_MEMBER_NAME(_parentNode,"_parentNode");
	HX_MARK_MEMBER_NAME(parentNode,"parentNode");
	HX_MARK_MEMBER_NAME(_childNodes,"_childNodes");
	HX_MARK_MEMBER_NAME(childNodes,"childNodes");
	HX_MARK_MEMBER_NAME(firstChild,"firstChild");
	HX_MARK_MEMBER_NAME(lastChild,"lastChild");
	HX_MARK_MEMBER_NAME(nextSibling,"nextSibling");
	HX_MARK_MEMBER_NAME(previousSibling,"previousSibling");
	HX_MARK_MEMBER_NAME(hasChildNodes,"hasChildNodes");
	HX_MARK_END_CLASS();
}

Dynamic Node_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { return get_nodeType(); }
		if (HX_FIELD_EQ(inName,"nodeName") ) { return get_nodeName(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return get_nodeValue(); }
		if (HX_FIELD_EQ(inName,"lastChild") ) { return get_lastChild(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parentNode") ) { return get_parentNode(); }
		if (HX_FIELD_EQ(inName,"childNodes") ) { return get_childNodes(); }
		if (HX_FIELD_EQ(inName,"firstChild") ) { return get_firstChild(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_parentNode") ) { return _parentNode; }
		if (HX_FIELD_EQ(inName,"_childNodes") ) { return _childNodes; }
		if (HX_FIELD_EQ(inName,"nextSibling") ) { return get_nextSibling(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasChildNodes") ) { return get_hasChildNodes(); }
		if (HX_FIELD_EQ(inName,"get_lastChild") ) { return get_lastChild_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_firstChild") ) { return get_firstChild_dyn(); }
		if (HX_FIELD_EQ(inName,"get_parentNode") ) { return get_parentNode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_parentNode") ) { return set_parentNode_dyn(); }
		if (HX_FIELD_EQ(inName,"get_childNodes") ) { return get_childNodes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { return get_previousSibling(); }
		if (HX_FIELD_EQ(inName,"get_nextSibling") ) { return get_nextSibling_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_hasChildNodes") ) { return get_hasChildNodes_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_previousSibling") ) { return get_previousSibling_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Node_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< ::core::dom::NodeType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeName") ) { nodeName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return set_nodeValue(inValue); }
		if (HX_FIELD_EQ(inName,"lastChild") ) { lastChild=inValue.Cast< ::core::dom::Node >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parentNode") ) { return set_parentNode(inValue); }
		if (HX_FIELD_EQ(inName,"childNodes") ) { childNodes=inValue.Cast< Array< ::core::dom::Node > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstChild") ) { firstChild=inValue.Cast< ::core::dom::Node >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_parentNode") ) { _parentNode=inValue.Cast< ::core::dom::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_childNodes") ) { _childNodes=inValue.Cast< Array< ::core::dom::Node > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextSibling") ) { nextSibling=inValue.Cast< ::core::dom::Node >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasChildNodes") ) { hasChildNodes=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { previousSibling=inValue.Cast< ::core::dom::Node >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Node_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nodeType"));
	outFields->push(HX_CSTRING("nodeValue"));
	outFields->push(HX_CSTRING("nodeName"));
	outFields->push(HX_CSTRING("_parentNode"));
	outFields->push(HX_CSTRING("parentNode"));
	outFields->push(HX_CSTRING("_childNodes"));
	outFields->push(HX_CSTRING("childNodes"));
	outFields->push(HX_CSTRING("firstChild"));
	outFields->push(HX_CSTRING("lastChild"));
	outFields->push(HX_CSTRING("nextSibling"));
	outFields->push(HX_CSTRING("previousSibling"));
	outFields->push(HX_CSTRING("hasChildNodes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nodeType"),
	HX_CSTRING("nodeValue"),
	HX_CSTRING("nodeName"),
	HX_CSTRING("_parentNode"),
	HX_CSTRING("parentNode"),
	HX_CSTRING("_childNodes"),
	HX_CSTRING("childNodes"),
	HX_CSTRING("firstChild"),
	HX_CSTRING("lastChild"),
	HX_CSTRING("nextSibling"),
	HX_CSTRING("previousSibling"),
	HX_CSTRING("hasChildNodes"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("get_firstChild"),
	HX_CSTRING("get_lastChild"),
	HX_CSTRING("get_nextSibling"),
	HX_CSTRING("get_previousSibling"),
	HX_CSTRING("get_hasChildNodes"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_parentNode"),
	HX_CSTRING("set_parentNode"),
	HX_CSTRING("get_childNodes"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("set_nodeValue"),
	HX_CSTRING("get_nodeName"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Node_obj::__mClass;

void Node_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.Node"), hx::TCanCast< Node_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Node_obj::__boot()
{
}

} // end namespace core
} // end namespace dom
