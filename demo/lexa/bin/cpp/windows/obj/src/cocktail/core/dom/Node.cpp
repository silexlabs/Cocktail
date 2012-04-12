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
namespace cocktail{
namespace core{
namespace dom{

Void Node_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",169)
	this->_childNodes = Array_obj< ::cocktail::core::dom::Node >::__new();
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

::cocktail::core::dom::Node Node_obj::removeChild( ::cocktail::core::dom::Node oldChild){
	HX_SOURCE_PUSH("Node_obj::removeChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",186)
	oldChild->set_parentNode(null());
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",188)
	Array< ::cocktail::core::dom::Node > newChildNodes = Array_obj< ::cocktail::core::dom::Node >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",189)
	{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",189)
		int _g1 = (int)0;
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",189)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",189)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",191)
			if (((this->_childNodes->__get(i) != oldChild))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",192)
				newChildNodes->push(this->_childNodes->__get(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",196)
	this->_childNodes = newChildNodes;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",198)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeChild,return )

::cocktail::core::dom::Node Node_obj::appendChild( ::cocktail::core::dom::Node newChild){
	HX_SOURCE_PUSH("Node_obj::appendChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",213)
	this->removeFromParentIfNecessary(newChild);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",215)
	newChild->set_parentNode(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",216)
	this->_childNodes->push(newChild);
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",218)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,appendChild,return )

::cocktail::core::dom::Node Node_obj::insertBefore( ::cocktail::core::dom::Node newChild,::cocktail::core::dom::Node refChild){
	HX_SOURCE_PUSH("Node_obj::insertBefore")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",235)
	if (((refChild == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",236)
		this->appendChild(newChild);
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",241)
		this->removeFromParentIfNecessary(newChild);
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",243)
		Array< ::cocktail::core::dom::Node > newChildNodes = Array_obj< ::cocktail::core::dom::Node >::__new();
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",245)
		{
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",245)
			int _g1 = (int)0;
			int _g = this->_childNodes->length;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",245)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",245)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",247)
				if (((this->_childNodes->__get(i) == refChild))){
					HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",248)
					newChildNodes->push(newChild);
				}
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",251)
				newChildNodes->push(this->_childNodes->__get(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",254)
		this->_childNodes = newChildNodes;
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",257)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,insertBefore,return )

::cocktail::core::dom::Node Node_obj::replaceChild( ::cocktail::core::dom::Node newChild,::cocktail::core::dom::Node oldChild){
	HX_SOURCE_PUSH("Node_obj::replaceChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",273)
	Array< ::cocktail::core::dom::Node > newChildNodes = Array_obj< ::cocktail::core::dom::Node >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",275)
	{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",275)
		int _g1 = (int)0;
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",275)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",275)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",277)
			if (((this->_childNodes->__get(i) == oldChild))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",278)
				newChildNodes->push(newChild);
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",282)
				newChildNodes->push(this->_childNodes->__get(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",287)
	this->_childNodes = newChildNodes;
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",289)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC2(Node_obj,replaceChild,return )

bool Node_obj::isSameNode( ::cocktail::core::dom::Node other){
	HX_SOURCE_PUSH("Node_obj::isSameNode")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",306)
	return (other == hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,isSameNode,return )

bool Node_obj::hasChildNodes( ){
	HX_SOURCE_PUSH("Node_obj::hasChildNodes")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",314)
	return (this->_childNodes->length > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,hasChildNodes,return )

bool Node_obj::hasAttributes( ){
	HX_SOURCE_PUSH("Node_obj::hasAttributes")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",323)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,hasAttributes,return )

Void Node_obj::removeFromParentIfNecessary( ::cocktail::core::dom::Node newChild){
{
		HX_SOURCE_PUSH("Node_obj::removeFromParentIfNecessary")
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",336)
		if (((newChild->get_parentNode() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",339)
			::cocktail::core::dom::Node parentNode = newChild->get_parentNode();
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",340)
			parentNode->removeChild(newChild);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,removeFromParentIfNecessary,(void))

::cocktail::core::dom::Node Node_obj::get_firstChild( ){
	HX_SOURCE_PUSH("Node_obj::get_firstChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",349)
	if (((this->hasChildNodes() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",351)
		return this->_childNodes->__get((int)0);
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",355)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_firstChild,return )

::cocktail::core::dom::Node Node_obj::get_lastChild( ){
	HX_SOURCE_PUSH("Node_obj::get_lastChild")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",361)
	if (((this->hasChildNodes() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",363)
		return this->_childNodes->__get((this->_childNodes->length - (int)1));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",367)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_lastChild,return )

::cocktail::core::dom::Node Node_obj::get_nextSibling( ){
	HX_SOURCE_PUSH("Node_obj::get_nextSibling")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",376)
	if (((this->_parentNode == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",377)
		return null();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",381)
		if (((this->_parentNode->get_lastChild() != hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",385)
			int _g1 = (int)0;
			int _g = this->_parentNode->get_childNodes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",385)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",385)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",387)
				if (((this->isSameNode(this->_parentNode->get_childNodes()->__get(i)) == true))){
					HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",388)
					return this->_parentNode->get_childNodes()->__get((i + (int)1));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",396)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nextSibling,return )

::cocktail::core::dom::Node Node_obj::get_previousSibling( ){
	HX_SOURCE_PUSH("Node_obj::get_previousSibling")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",404)
	if (((this->_parentNode == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",405)
		return null();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",408)
		if (((this->_parentNode->get_firstChild() != hx::ObjectPtr<OBJ_>(this)))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",410)
			int _g1 = (int)0;
			int _g = this->_parentNode->get_childNodes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",410)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",410)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",412)
				if (((this->isSameNode(this->_parentNode->get_childNodes()->__get(i)) == true))){
					HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",413)
					return this->_parentNode->get_childNodes()->__get((i - (int)1));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",419)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_previousSibling,return )

int Node_obj::get_nodeType( ){
	HX_SOURCE_PUSH("Node_obj::get_nodeType")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",423)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeType,return )

::cocktail::core::dom::Node Node_obj::get_parentNode( ){
	HX_SOURCE_PUSH("Node_obj::get_parentNode")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",428)
	return this->_parentNode;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_parentNode,return )

::cocktail::core::dom::Node Node_obj::set_parentNode( ::cocktail::core::dom::Node value){
	HX_SOURCE_PUSH("Node_obj::set_parentNode")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",433)
	return this->_parentNode = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_parentNode,return )

Array< ::cocktail::core::dom::Node > Node_obj::get_childNodes( ){
	HX_SOURCE_PUSH("Node_obj::get_childNodes")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",438)
	return this->_childNodes;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_childNodes,return )

::String Node_obj::get_nodeValue( ){
	HX_SOURCE_PUSH("Node_obj::get_nodeValue")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",443)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeValue,return )

::String Node_obj::set_nodeValue( ::String value){
	HX_SOURCE_PUSH("Node_obj::set_nodeValue")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",448)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_nodeValue,return )

::String Node_obj::get_nodeName( ){
	HX_SOURCE_PUSH("Node_obj::get_nodeName")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",453)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_nodeName,return )

::cocktail::core::dom::NamedNodeMap Node_obj::get_attributes( ){
	HX_SOURCE_PUSH("Node_obj::get_attributes")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",458)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_attributes,return )

::cocktail::core::dom::Document Node_obj::get_ownerDocument( ){
	HX_SOURCE_PUSH("Node_obj::get_ownerDocument")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",463)
	return this->_ownerDocument;
}


HX_DEFINE_DYNAMIC_FUNC0(Node_obj,get_ownerDocument,return )

::cocktail::core::dom::Document Node_obj::set_ownerDocument( ::cocktail::core::dom::Document value){
	HX_SOURCE_PUSH("Node_obj::set_ownerDocument")
	HX_SOURCE_POS("../../src/cocktail/core/dom/Node.hx",468)
	return this->_ownerDocument = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Node_obj,set_ownerDocument,return )

int Node_obj::ELEMENT_NODE;

int Node_obj::ATTRIBUTE_NODE;

int Node_obj::TEXT_NODE;

int Node_obj::CDATA_SECTION_NODE;

int Node_obj::ENTITY_REFERENCE_NODE;

int Node_obj::ENTITY_NODE;

int Node_obj::PROCESSING_INSTRUCTION_NODE;

int Node_obj::COMMENT_NODE;

int Node_obj::DOCUMENT_NODE;

int Node_obj::DOCUMENT_TYPE_NODE;

int Node_obj::DOCUMENT_FRAGMENT_NODE;

int Node_obj::NOTATION_NODE;


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
	HX_MARK_MEMBER_NAME(_attributes,"_attributes");
	HX_MARK_MEMBER_NAME(attributes,"attributes");
	HX_MARK_MEMBER_NAME(_ownerDocument,"_ownerDocument");
	HX_MARK_MEMBER_NAME(ownerDocument,"ownerDocument");
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
		if (HX_FIELD_EQ(inName,"TEXT_NODE") ) { return TEXT_NODE; }
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return get_nodeValue(); }
		if (HX_FIELD_EQ(inName,"lastChild") ) { return get_lastChild(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parentNode") ) { return get_parentNode(); }
		if (HX_FIELD_EQ(inName,"childNodes") ) { return get_childNodes(); }
		if (HX_FIELD_EQ(inName,"firstChild") ) { return get_firstChild(); }
		if (HX_FIELD_EQ(inName,"attributes") ) { return get_attributes(); }
		if (HX_FIELD_EQ(inName,"isSameNode") ) { return isSameNode_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ENTITY_NODE") ) { return ENTITY_NODE; }
		if (HX_FIELD_EQ(inName,"_parentNode") ) { return _parentNode; }
		if (HX_FIELD_EQ(inName,"_childNodes") ) { return _childNodes; }
		if (HX_FIELD_EQ(inName,"nextSibling") ) { return get_nextSibling(); }
		if (HX_FIELD_EQ(inName,"_attributes") ) { return _attributes; }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ELEMENT_NODE") ) { return ELEMENT_NODE; }
		if (HX_FIELD_EQ(inName,"COMMENT_NODE") ) { return COMMENT_NODE; }
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		if (HX_FIELD_EQ(inName,"replaceChild") ) { return replaceChild_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DOCUMENT_NODE") ) { return DOCUMENT_NODE; }
		if (HX_FIELD_EQ(inName,"NOTATION_NODE") ) { return NOTATION_NODE; }
		if (HX_FIELD_EQ(inName,"ownerDocument") ) { return get_ownerDocument(); }
		if (HX_FIELD_EQ(inName,"hasChildNodes") ) { return hasChildNodes_dyn(); }
		if (HX_FIELD_EQ(inName,"hasAttributes") ) { return hasAttributes_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lastChild") ) { return get_lastChild_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ATTRIBUTE_NODE") ) { return ATTRIBUTE_NODE; }
		if (HX_FIELD_EQ(inName,"_ownerDocument") ) { return _ownerDocument; }
		if (HX_FIELD_EQ(inName,"get_firstChild") ) { return get_firstChild_dyn(); }
		if (HX_FIELD_EQ(inName,"get_parentNode") ) { return get_parentNode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_parentNode") ) { return set_parentNode_dyn(); }
		if (HX_FIELD_EQ(inName,"get_childNodes") ) { return get_childNodes_dyn(); }
		if (HX_FIELD_EQ(inName,"get_attributes") ) { return get_attributes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { return get_previousSibling(); }
		if (HX_FIELD_EQ(inName,"get_nextSibling") ) { return get_nextSibling_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_ownerDocument") ) { return get_ownerDocument_dyn(); }
		if (HX_FIELD_EQ(inName,"set_ownerDocument") ) { return set_ownerDocument_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"CDATA_SECTION_NODE") ) { return CDATA_SECTION_NODE; }
		if (HX_FIELD_EQ(inName,"DOCUMENT_TYPE_NODE") ) { return DOCUMENT_TYPE_NODE; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_previousSibling") ) { return get_previousSibling_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"ENTITY_REFERENCE_NODE") ) { return ENTITY_REFERENCE_NODE; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"DOCUMENT_FRAGMENT_NODE") ) { return DOCUMENT_FRAGMENT_NODE; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"PROCESSING_INSTRUCTION_NODE") ) { return PROCESSING_INSTRUCTION_NODE; }
		if (HX_FIELD_EQ(inName,"removeFromParentIfNecessary") ) { return removeFromParentIfNecessary_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Node_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeName") ) { nodeName=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TEXT_NODE") ) { TEXT_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeValue") ) { return set_nodeValue(inValue); }
		if (HX_FIELD_EQ(inName,"lastChild") ) { lastChild=inValue.Cast< ::cocktail::core::dom::Node >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parentNode") ) { return set_parentNode(inValue); }
		if (HX_FIELD_EQ(inName,"childNodes") ) { childNodes=inValue.Cast< Array< ::cocktail::core::dom::Node > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstChild") ) { firstChild=inValue.Cast< ::cocktail::core::dom::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"attributes") ) { attributes=inValue.Cast< ::cocktail::core::dom::NamedNodeMap >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ENTITY_NODE") ) { ENTITY_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_parentNode") ) { _parentNode=inValue.Cast< ::cocktail::core::dom::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_childNodes") ) { _childNodes=inValue.Cast< Array< ::cocktail::core::dom::Node > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextSibling") ) { nextSibling=inValue.Cast< ::cocktail::core::dom::Node >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_attributes") ) { _attributes=inValue.Cast< ::cocktail::core::dom::NamedNodeMap >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ELEMENT_NODE") ) { ELEMENT_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"COMMENT_NODE") ) { COMMENT_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DOCUMENT_NODE") ) { DOCUMENT_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NOTATION_NODE") ) { NOTATION_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ownerDocument") ) { return set_ownerDocument(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ATTRIBUTE_NODE") ) { ATTRIBUTE_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_ownerDocument") ) { _ownerDocument=inValue.Cast< ::cocktail::core::dom::Document >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"previousSibling") ) { previousSibling=inValue.Cast< ::cocktail::core::dom::Node >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"CDATA_SECTION_NODE") ) { CDATA_SECTION_NODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOCUMENT_TYPE_NODE") ) { DOCUMENT_TYPE_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"ENTITY_REFERENCE_NODE") ) { ENTITY_REFERENCE_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"DOCUMENT_FRAGMENT_NODE") ) { DOCUMENT_FRAGMENT_NODE=inValue.Cast< int >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"PROCESSING_INSTRUCTION_NODE") ) { PROCESSING_INSTRUCTION_NODE=inValue.Cast< int >(); return inValue; }
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
	outFields->push(HX_CSTRING("_attributes"));
	outFields->push(HX_CSTRING("attributes"));
	outFields->push(HX_CSTRING("_ownerDocument"));
	outFields->push(HX_CSTRING("ownerDocument"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ELEMENT_NODE"),
	HX_CSTRING("ATTRIBUTE_NODE"),
	HX_CSTRING("TEXT_NODE"),
	HX_CSTRING("CDATA_SECTION_NODE"),
	HX_CSTRING("ENTITY_REFERENCE_NODE"),
	HX_CSTRING("ENTITY_NODE"),
	HX_CSTRING("PROCESSING_INSTRUCTION_NODE"),
	HX_CSTRING("COMMENT_NODE"),
	HX_CSTRING("DOCUMENT_NODE"),
	HX_CSTRING("DOCUMENT_TYPE_NODE"),
	HX_CSTRING("DOCUMENT_FRAGMENT_NODE"),
	HX_CSTRING("NOTATION_NODE"),
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
	HX_CSTRING("_attributes"),
	HX_CSTRING("attributes"),
	HX_CSTRING("_ownerDocument"),
	HX_CSTRING("ownerDocument"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("replaceChild"),
	HX_CSTRING("isSameNode"),
	HX_CSTRING("hasChildNodes"),
	HX_CSTRING("hasAttributes"),
	HX_CSTRING("removeFromParentIfNecessary"),
	HX_CSTRING("get_firstChild"),
	HX_CSTRING("get_lastChild"),
	HX_CSTRING("get_nextSibling"),
	HX_CSTRING("get_previousSibling"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_parentNode"),
	HX_CSTRING("set_parentNode"),
	HX_CSTRING("get_childNodes"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("set_nodeValue"),
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("get_attributes"),
	HX_CSTRING("get_ownerDocument"),
	HX_CSTRING("set_ownerDocument"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Node_obj::ELEMENT_NODE,"ELEMENT_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::ATTRIBUTE_NODE,"ATTRIBUTE_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::TEXT_NODE,"TEXT_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::CDATA_SECTION_NODE,"CDATA_SECTION_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::ENTITY_REFERENCE_NODE,"ENTITY_REFERENCE_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::ENTITY_NODE,"ENTITY_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::PROCESSING_INSTRUCTION_NODE,"PROCESSING_INSTRUCTION_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::COMMENT_NODE,"COMMENT_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::DOCUMENT_NODE,"DOCUMENT_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::DOCUMENT_TYPE_NODE,"DOCUMENT_TYPE_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::DOCUMENT_FRAGMENT_NODE,"DOCUMENT_FRAGMENT_NODE");
	HX_MARK_MEMBER_NAME(Node_obj::NOTATION_NODE,"NOTATION_NODE");
};

Class Node_obj::__mClass;

void Node_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Node"), hx::TCanCast< Node_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Node_obj::__boot()
{
	hx::Static(ELEMENT_NODE) = (int)1;
	hx::Static(ATTRIBUTE_NODE) = (int)2;
	hx::Static(TEXT_NODE) = (int)3;
	hx::Static(CDATA_SECTION_NODE) = (int)4;
	hx::Static(ENTITY_REFERENCE_NODE) = (int)5;
	hx::Static(ENTITY_NODE) = (int)6;
	hx::Static(PROCESSING_INSTRUCTION_NODE) = (int)7;
	hx::Static(COMMENT_NODE) = (int)8;
	hx::Static(DOCUMENT_NODE) = (int)9;
	hx::Static(DOCUMENT_TYPE_NODE) = (int)10;
	hx::Static(DOCUMENT_FRAGMENT_NODE) = (int)11;
	hx::Static(NOTATION_NODE) = (int)11;
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
