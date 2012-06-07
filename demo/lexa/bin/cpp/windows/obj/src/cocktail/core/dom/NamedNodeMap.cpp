#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_NamedNodeMap
#include <cocktail/core/dom/NamedNodeMap.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

Void NamedNodeMap_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",35)
	this->_nodes = Array_obj< ::cocktail::core::dom::Node >::__new();
}
;
	return null();
}

NamedNodeMap_obj::~NamedNodeMap_obj() { }

Dynamic NamedNodeMap_obj::__CreateEmpty() { return  new NamedNodeMap_obj; }
hx::ObjectPtr< NamedNodeMap_obj > NamedNodeMap_obj::__new()
{  hx::ObjectPtr< NamedNodeMap_obj > result = new NamedNodeMap_obj();
	result->__construct();
	return result;}

Dynamic NamedNodeMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NamedNodeMap_obj > result = new NamedNodeMap_obj();
	result->__construct();
	return result;}

::cocktail::core::dom::Node NamedNodeMap_obj::getNamedItem( ::String name){
	HX_SOURCE_PUSH("NamedNodeMap_obj::getNamedItem")
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",52)
	{
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",52)
		int _g1 = (int)0;
		int _g = this->_nodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",52)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",52)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",54)
			if (((this->_nodes->__get(i)->get_nodeName() == name))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",55)
				return this->_nodes->__get(i);
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",60)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,getNamedItem,return )

::cocktail::core::dom::Node NamedNodeMap_obj::setNamedItem( ::cocktail::core::dom::Node arg){
	HX_SOURCE_PUSH("NamedNodeMap_obj::setNamedItem")
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",80)
	::cocktail::core::dom::Node replacedNode = this->getNamedItem(arg->get_nodeName());
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",82)
	if (((replacedNode != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",84)
		int _g1 = (int)0;
		int _g = this->get_length();
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",84)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",84)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",86)
			if (((this->_nodes->__get(i)->isSameNode(replacedNode) == true))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",88)
				this->_nodes[i] = arg;
				HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",89)
				return replacedNode;
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",94)
		this->_nodes->push(arg);
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",98)
	return replacedNode;
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,setNamedItem,return )

::cocktail::core::dom::Node NamedNodeMap_obj::removeNamedItem( ::String name){
	HX_SOURCE_PUSH("NamedNodeMap_obj::removeNamedItem")
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",116)
	::cocktail::core::dom::Node removedNode = this->getNamedItem(name);
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",118)
	if (((removedNode == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",119)
		return null();
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",123)
	Array< ::cocktail::core::dom::Node > newNodes = Array_obj< ::cocktail::core::dom::Node >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",125)
	{
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",125)
		int _g1 = (int)0;
		int _g = this->get_length();
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",125)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",125)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",127)
			if (((this->_nodes->__get(i)->isSameNode(removedNode) == false))){
				HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",128)
				newNodes->push(this->_nodes->__get(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",133)
	this->_nodes = newNodes;
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",135)
	return removedNode;
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,removeNamedItem,return )

::cocktail::core::dom::Node NamedNodeMap_obj::item( int index){
	HX_SOURCE_PUSH("NamedNodeMap_obj::item")
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",148)
	if (((index > (this->get_length() - (int)1)))){
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",150)
		return null();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",154)
		return this->_nodes->__get(index);
	}
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,item,return )

int NamedNodeMap_obj::get_length( ){
	HX_SOURCE_PUSH("NamedNodeMap_obj::get_length")
	HX_SOURCE_POS("../../src/cocktail/core/dom/NamedNodeMap.hx",164)
	return this->_nodes->length;
}


HX_DEFINE_DYNAMIC_FUNC0(NamedNodeMap_obj,get_length,return )


NamedNodeMap_obj::NamedNodeMap_obj()
{
}

void NamedNodeMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NamedNodeMap);
	HX_MARK_MEMBER_NAME(_nodes,"_nodes");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

Dynamic NamedNodeMap_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"item") ) { return item_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_nodes") ) { return _nodes; }
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getNamedItem") ) { return getNamedItem_dyn(); }
		if (HX_FIELD_EQ(inName,"setNamedItem") ) { return setNamedItem_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeNamedItem") ) { return removeNamedItem_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NamedNodeMap_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_nodes") ) { _nodes=inValue.Cast< Array< ::cocktail::core::dom::Node > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NamedNodeMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nodes"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_nodes"),
	HX_CSTRING("length"),
	HX_CSTRING("getNamedItem"),
	HX_CSTRING("setNamedItem"),
	HX_CSTRING("removeNamedItem"),
	HX_CSTRING("item"),
	HX_CSTRING("get_length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class NamedNodeMap_obj::__mClass;

void NamedNodeMap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.NamedNodeMap"), hx::TCanCast< NamedNodeMap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NamedNodeMap_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
