#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
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

Void Attr_obj::__construct(::String name)
{
HX_STACK_PUSH("Attr::new","cocktail/core/dom/Attr.hx",64);
{
	HX_STACK_LINE(65)
	this->name = name;
	HX_STACK_LINE(66)
	this->specified = false;
	HX_STACK_LINE(67)
	super::__construct();
}
;
	return null();
}

Attr_obj::~Attr_obj() { }

Dynamic Attr_obj::__CreateEmpty() { return  new Attr_obj; }
hx::ObjectPtr< Attr_obj > Attr_obj::__new(::String name)
{  hx::ObjectPtr< Attr_obj > result = new Attr_obj();
	result->__construct(name);
	return result;}

Dynamic Attr_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Attr_obj > result = new Attr_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Attr_obj::set_value( ::String value){
	HX_STACK_PUSH("Attr::set_value","cocktail/core/dom/Attr.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(134)
	this->specified = true;
	HX_STACK_LINE(135)
	return this->value = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Attr_obj,set_value,return )

::String Attr_obj::get_value( ){
	HX_STACK_PUSH("Attr::get_value","cocktail/core/dom/Attr.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_LINE(125)
	if (((this->value == null()))){
		HX_STACK_LINE(126)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(129)
	return this->value;
}


HX_DEFINE_DYNAMIC_FUNC0(Attr_obj,get_value,return )

::String Attr_obj::set_nodeValue( ::String value){
	HX_STACK_PUSH("Attr::set_nodeValue","cocktail/core/dom/Attr.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(115)
	return this->set_value(value);
}


::String Attr_obj::get_nodeValue( ){
	HX_STACK_PUSH("Attr::get_nodeValue","cocktail/core/dom/Attr.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_LINE(110)
	return this->get_value();
}


int Attr_obj::get_nodeType( ){
	HX_STACK_PUSH("Attr::get_nodeType","cocktail/core/dom/Attr.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(105)
	return (int)2;
}


::String Attr_obj::get_nodeName( ){
	HX_STACK_PUSH("Attr::get_nodeName","cocktail/core/dom/Attr.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_LINE(100)
	return this->name;
}


Dynamic Attr_obj::doCloneNode( ){
	HX_STACK_PUSH("Attr::doCloneNode","cocktail/core/dom/Attr.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_LINE(87)
	::cocktail::core::dom::Attr clonedAttr = ::cocktail::core::dom::Attr_obj::__new(this->name);		HX_STACK_VAR(clonedAttr,"clonedAttr");
	HX_STACK_LINE(88)
	clonedAttr->specified = this->specified;
	HX_STACK_LINE(89)
	clonedAttr->isId = this->isId;
	HX_STACK_LINE(90)
	clonedAttr->set_value(this->get_value());
	HX_STACK_LINE(92)
	return clonedAttr;
}


Void Attr_obj::initChildNodes( ){
{
		HX_STACK_PUSH("Attr::initChildNodes","cocktail/core/dom/Attr.hx",74);
		HX_STACK_THIS(this);
	}
return null();
}



Attr_obj::Attr_obj()
{
}

void Attr_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Attr);
	HX_MARK_MEMBER_NAME(ownerElement,"ownerElement");
	HX_MARK_MEMBER_NAME(isId,"isId");
	HX_MARK_MEMBER_NAME(specified,"specified");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(name,"name");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Attr_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ownerElement,"ownerElement");
	HX_VISIT_MEMBER_NAME(isId,"isId");
	HX_VISIT_MEMBER_NAME(specified,"specified");
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(name,"name");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Attr_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"isId") ) { return isId; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"specified") ) { return specified; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"doCloneNode") ) { return doCloneNode_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_nodeType") ) { return get_nodeType_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeName") ) { return get_nodeName_dyn(); }
		if (HX_FIELD_EQ(inName,"ownerElement") ) { return ownerElement; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_nodeValue") ) { return set_nodeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nodeValue") ) { return get_nodeValue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initChildNodes") ) { return initChildNodes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Attr_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"isId") ) { isId=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"specified") ) { specified=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ownerElement") ) { ownerElement=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Attr_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ownerElement"));
	outFields->push(HX_CSTRING("isId"));
	outFields->push(HX_CSTRING("specified"));
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("set_nodeValue"),
	HX_CSTRING("get_nodeValue"),
	HX_CSTRING("get_nodeType"),
	HX_CSTRING("get_nodeName"),
	HX_CSTRING("doCloneNode"),
	HX_CSTRING("initChildNodes"),
	HX_CSTRING("ownerElement"),
	HX_CSTRING("isId"),
	HX_CSTRING("specified"),
	HX_CSTRING("value"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Attr_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Attr_obj::__mClass,"__mClass");
};

Class Attr_obj::__mClass;

void Attr_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.Attr"), hx::TCanCast< Attr_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Attr_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace dom
