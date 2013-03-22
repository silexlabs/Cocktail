#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void EmbeddedElement_obj::__construct(::String tagName)
{
HX_STACK_PUSH("EmbeddedElement::new","cocktail/core/html/EmbeddedElement.hx",71);
{
	HX_STACK_LINE(71)
	super::__construct(tagName);
}
;
	return null();
}

EmbeddedElement_obj::~EmbeddedElement_obj() { }

Dynamic EmbeddedElement_obj::__CreateEmpty() { return  new EmbeddedElement_obj; }
hx::ObjectPtr< EmbeddedElement_obj > EmbeddedElement_obj::__new(::String tagName)
{  hx::ObjectPtr< EmbeddedElement_obj > result = new EmbeddedElement_obj();
	result->__construct(tagName);
	return result;}

Dynamic EmbeddedElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedElement_obj > result = new EmbeddedElement_obj();
	result->__construct(inArgs[0]);
	return result;}

int EmbeddedElement_obj::get_height( ){
	HX_STACK_PUSH("EmbeddedElement::get_height","cocktail/core/html/EmbeddedElement.hx",121);
	HX_STACK_THIS(this);
	HX_STACK_LINE(121)
	return this->getAttributeAsPositiveSignedInteger(HX_CSTRING("height"),(int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_height,return )

int EmbeddedElement_obj::set_height( int value){
	HX_STACK_PUSH("EmbeddedElement::set_height","cocktail/core/html/EmbeddedElement.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(116)
	this->setAttribute(HX_CSTRING("height"),::Std_obj::string(value));
	HX_STACK_LINE(117)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(EmbeddedElement_obj,set_height,return )

int EmbeddedElement_obj::get_width( ){
	HX_STACK_PUSH("EmbeddedElement::get_width","cocktail/core/html/EmbeddedElement.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_LINE(110)
	return this->getAttributeAsPositiveSignedInteger(HX_CSTRING("width"),(int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_width,return )

int EmbeddedElement_obj::set_width( int value){
	HX_STACK_PUSH("EmbeddedElement::set_width","cocktail/core/html/EmbeddedElement.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(105)
	this->setAttribute(HX_CSTRING("width"),::Std_obj::string(value));
	HX_STACK_LINE(106)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(EmbeddedElement_obj,set_width,return )

Dynamic EmbeddedElement_obj::get_intrinsicRatio( ){
	HX_STACK_PUSH("EmbeddedElement::get_intrinsicRatio","cocktail/core/html/EmbeddedElement.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_LINE(95)
	return this->intrinsicRatio;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_intrinsicRatio,return )

Dynamic EmbeddedElement_obj::get_intrinsicWidth( ){
	HX_STACK_PUSH("EmbeddedElement::get_intrinsicWidth","cocktail/core/html/EmbeddedElement.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_LINE(90)
	return this->intrinsicWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_intrinsicWidth,return )

Dynamic EmbeddedElement_obj::get_intrinsicHeight( ){
	HX_STACK_PUSH("EmbeddedElement::get_intrinsicHeight","cocktail/core/html/EmbeddedElement.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_LINE(85)
	return this->intrinsicHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_intrinsicHeight,return )

Void EmbeddedElement_obj::init( ){
{
		HX_STACK_PUSH("EmbeddedElement::init","cocktail/core/html/EmbeddedElement.hx",76);
		HX_STACK_THIS(this);
		HX_STACK_LINE(76)
		this->super::init();
	}
return null();
}



EmbeddedElement_obj::EmbeddedElement_obj()
{
}

void EmbeddedElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedElement);
	HX_MARK_MEMBER_NAME(intrinsicRatio,"intrinsicRatio");
	HX_MARK_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_MARK_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EmbeddedElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(intrinsicRatio,"intrinsicRatio");
	HX_VISIT_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_VISIT_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { return inCallProp ? get_intrinsicRatio() : intrinsicRatio; }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { return inCallProp ? get_intrinsicWidth() : intrinsicWidth; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { return inCallProp ? get_intrinsicHeight() : intrinsicHeight; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicRatio") ) { return get_intrinsicRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return set_width(inValue);width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return set_height(inValue);height=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { intrinsicRatio=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { intrinsicWidth=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { intrinsicHeight=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EmbeddedElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("intrinsicRatio"));
	outFields->push(HX_CSTRING("intrinsicWidth"));
	outFields->push(HX_CSTRING("intrinsicHeight"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_intrinsicRatio"),
	HX_CSTRING("get_intrinsicWidth"),
	HX_CSTRING("get_intrinsicHeight"),
	HX_CSTRING("init"),
	HX_CSTRING("intrinsicRatio"),
	HX_CSTRING("intrinsicWidth"),
	HX_CSTRING("intrinsicHeight"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmbeddedElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedElement_obj::__mClass,"__mClass");
};

Class EmbeddedElement_obj::__mClass;

void EmbeddedElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.EmbeddedElement"), hx::TCanCast< EmbeddedElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
