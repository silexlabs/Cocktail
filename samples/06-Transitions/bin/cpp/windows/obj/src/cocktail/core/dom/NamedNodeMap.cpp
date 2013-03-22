#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
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

Void NamedNodeMap_obj::__construct()
{
HX_STACK_PUSH("NamedNodeMap::new","cocktail/core/dom/NamedNodeMap.hx",41);
{
	HX_STACK_LINE(41)
	this->_nodes = Array_obj< ::cocktail::core::dom::Attr >::__new();
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

int NamedNodeMap_obj::get_length( ){
	HX_STACK_PUSH("NamedNodeMap::get_length","cocktail/core/dom/NamedNodeMap.hx",161);
	HX_STACK_THIS(this);
	HX_STACK_LINE(161)
	return this->_nodes->length;
}


HX_DEFINE_DYNAMIC_FUNC0(NamedNodeMap_obj,get_length,return )

::cocktail::core::dom::Attr NamedNodeMap_obj::item( int index){
	HX_STACK_PUSH("NamedNodeMap::item","cocktail/core/dom/NamedNodeMap.hx",145);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(145)
	if (((index > (this->get_length() - (int)1)))){
		HX_STACK_LINE(147)
		return null();
	}
	else{
		HX_STACK_LINE(151)
		return this->_nodes->__get(index);
	}
	HX_STACK_LINE(145)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,item,return )

::cocktail::core::dom::Attr NamedNodeMap_obj::removeNamedItem( ::String name){
	HX_STACK_PUSH("NamedNodeMap::removeNamedItem","cocktail/core/dom/NamedNodeMap.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(123)
	::cocktail::core::dom::Attr removedNode = this->getNamedItem(name);		HX_STACK_VAR(removedNode,"removedNode");
	HX_STACK_LINE(125)
	if (((removedNode == null()))){
		HX_STACK_LINE(126)
		return null();
	}
	HX_STACK_LINE(130)
	this->_nodes->remove(removedNode);
	HX_STACK_LINE(132)
	return removedNode;
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,removeNamedItem,return )

::cocktail::core::dom::Attr NamedNodeMap_obj::setNamedItem( ::cocktail::core::dom::Attr arg){
	HX_STACK_PUSH("NamedNodeMap::setNamedItem","cocktail/core/dom/NamedNodeMap.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(arg,"arg");
	HX_STACK_LINE(87)
	::cocktail::core::dom::Attr replacedNode = this->getNamedItem(arg->get_nodeName());		HX_STACK_VAR(replacedNode,"replacedNode");
	HX_STACK_LINE(89)
	if (((replacedNode != null()))){
		HX_STACK_LINE(91)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->get_length();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(91)
		while(((_g1 < _g))){
			HX_STACK_LINE(91)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(93)
			if (((this->_nodes->__get(i) == replacedNode))){
				HX_STACK_LINE(95)
				this->_nodes[i] = arg;
				HX_STACK_LINE(96)
				return replacedNode;
			}
		}
	}
	else{
		HX_STACK_LINE(101)
		this->_nodes->push(arg);
	}
	HX_STACK_LINE(105)
	return replacedNode;
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,setNamedItem,return )

::cocktail::core::dom::Attr NamedNodeMap_obj::getNamedItem( ::String name){
	HX_STACK_PUSH("NamedNodeMap::getNamedItem","cocktail/core/dom/NamedNodeMap.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(58)
	int length = this->_nodes->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(59)
	{
		HX_STACK_LINE(59)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(59)
		while(((_g < length))){
			HX_STACK_LINE(59)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(61)
			if (((this->_nodes->__get(i)->name == name))){
				HX_STACK_LINE(62)
				return this->_nodes->__get(i);
			}
		}
	}
	HX_STACK_LINE(67)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NamedNodeMap_obj,getNamedItem,return )


NamedNodeMap_obj::NamedNodeMap_obj()
{
}

void NamedNodeMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NamedNodeMap);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(_nodes,"_nodes");
	HX_MARK_END_CLASS();
}

void NamedNodeMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(_nodes,"_nodes");
}

Dynamic NamedNodeMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"item") ) { return item_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"_nodes") ) { return _nodes; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setNamedItem") ) { return setNamedItem_dyn(); }
		if (HX_FIELD_EQ(inName,"getNamedItem") ) { return getNamedItem_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeNamedItem") ) { return removeNamedItem_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NamedNodeMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nodes") ) { _nodes=inValue.Cast< Array< ::cocktail::core::dom::Attr > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NamedNodeMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("_nodes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_length"),
	HX_CSTRING("item"),
	HX_CSTRING("removeNamedItem"),
	HX_CSTRING("setNamedItem"),
	HX_CSTRING("getNamedItem"),
	HX_CSTRING("length"),
	HX_CSTRING("_nodes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NamedNodeMap_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NamedNodeMap_obj::__mClass,"__mClass");
};

Class NamedNodeMap_obj::__mClass;

void NamedNodeMap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.NamedNodeMap"), hx::TCanCast< NamedNodeMap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NamedNodeMap_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
