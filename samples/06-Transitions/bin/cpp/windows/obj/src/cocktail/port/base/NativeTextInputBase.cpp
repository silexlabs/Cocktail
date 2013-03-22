#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#include <cocktail/port/base/NativeInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void NativeTextInputBase_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("NativeTextInputBase::new","cocktail/port/base/NativeTextInputBase.hx",50);
{
	HX_STACK_LINE(50)
	super::__construct(node);
}
;
	return null();
}

NativeTextInputBase_obj::~NativeTextInputBase_obj() { }

Dynamic NativeTextInputBase_obj::__CreateEmpty() { return  new NativeTextInputBase_obj; }
hx::ObjectPtr< NativeTextInputBase_obj > NativeTextInputBase_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< NativeTextInputBase_obj > result = new NativeTextInputBase_obj();
	result->__construct(node);
	return result;}

Dynamic NativeTextInputBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeTextInputBase_obj > result = new NativeTextInputBase_obj();
	result->__construct(inArgs[0]);
	return result;}

int NativeTextInputBase_obj::get_intrinsicHeight( ){
	HX_STACK_PUSH("NativeTextInputBase::get_intrinsicHeight","cocktail/port/base/NativeTextInputBase.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_LINE(124)
	return (int)30;
}


int NativeTextInputBase_obj::get_intrinsicWidth( ){
	HX_STACK_PUSH("NativeTextInputBase::get_intrinsicWidth","cocktail/port/base/NativeTextInputBase.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_LINE(119)
	return (int)150;
}


Float NativeTextInputBase_obj::get_letterSpacing( ){
	HX_STACK_PUSH("NativeTextInputBase::get_letterSpacing","cocktail/port/base/NativeTextInputBase.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_LINE(114)
	return this->letterSpacing;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_letterSpacing,return )

Float NativeTextInputBase_obj::set_letterSpacing( Float value){
	HX_STACK_PUSH("NativeTextInputBase::set_letterSpacing","cocktail/port/base/NativeTextInputBase.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(109)
	return this->letterSpacing = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_letterSpacing,return )

Float NativeTextInputBase_obj::get_fontSize( ){
	HX_STACK_PUSH("NativeTextInputBase::get_fontSize","cocktail/port/base/NativeTextInputBase.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_LINE(104)
	return this->fontSize;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_fontSize,return )

Float NativeTextInputBase_obj::set_fontSize( Float value){
	HX_STACK_PUSH("NativeTextInputBase::set_fontSize","cocktail/port/base/NativeTextInputBase.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(99)
	return this->fontSize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_fontSize,return )

::String NativeTextInputBase_obj::get_fontFamily( ){
	HX_STACK_PUSH("NativeTextInputBase::get_fontFamily","cocktail/port/base/NativeTextInputBase.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_LINE(94)
	return this->fontFamily;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_fontFamily,return )

::String NativeTextInputBase_obj::set_fontFamily( ::String value){
	HX_STACK_PUSH("NativeTextInputBase::set_fontFamily","cocktail/port/base/NativeTextInputBase.hx",89);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(89)
	return this->fontFamily = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_fontFamily,return )

int NativeTextInputBase_obj::get_color( ){
	HX_STACK_PUSH("NativeTextInputBase::get_color","cocktail/port/base/NativeTextInputBase.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_LINE(84)
	return this->color;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_color,return )

int NativeTextInputBase_obj::set_color( int value){
	HX_STACK_PUSH("NativeTextInputBase::set_color","cocktail/port/base/NativeTextInputBase.hx",79);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(79)
	return this->color = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_color,return )

bool NativeTextInputBase_obj::set_bold( bool value){
	HX_STACK_PUSH("NativeTextInputBase::set_bold","cocktail/port/base/NativeTextInputBase.hx",74);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(74)
	return this->set_italic(value);
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_bold,return )

bool NativeTextInputBase_obj::get_bold( ){
	HX_STACK_PUSH("NativeTextInputBase::get_bold","cocktail/port/base/NativeTextInputBase.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_LINE(69)
	return this->get_italic();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_bold,return )

bool NativeTextInputBase_obj::get_italic( ){
	HX_STACK_PUSH("NativeTextInputBase::get_italic","cocktail/port/base/NativeTextInputBase.hx",64);
	HX_STACK_THIS(this);
	HX_STACK_LINE(64)
	return this->italic;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_italic,return )

bool NativeTextInputBase_obj::set_italic( bool value){
	HX_STACK_PUSH("NativeTextInputBase::set_italic","cocktail/port/base/NativeTextInputBase.hx",59);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(59)
	return this->italic = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_italic,return )

int NativeTextInputBase_obj::INPUT_TEXT_INTRINSIC_WIDTH;

Float NativeTextInputBase_obj::INPUT_TEXT_INTRINSIC_HEIGHT;


NativeTextInputBase_obj::NativeTextInputBase_obj()
{
}

void NativeTextInputBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeTextInputBase);
	HX_MARK_MEMBER_NAME(fontSize,"fontSize");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(fontFamily,"fontFamily");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(bold,"bold");
	HX_MARK_MEMBER_NAME(italic,"italic");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeTextInputBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fontSize,"fontSize");
	HX_VISIT_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_VISIT_MEMBER_NAME(fontFamily,"fontFamily");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(bold,"bold");
	HX_VISIT_MEMBER_NAME(italic,"italic");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeTextInputBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { return inCallProp ? get_italic() : bold; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { return inCallProp ? get_italic() : italic; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_bold") ) { return set_bold_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bold") ) { return get_bold_dyn(); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return inCallProp ? get_fontSize() : fontSize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_italic") ) { return get_italic_dyn(); }
		if (HX_FIELD_EQ(inName,"set_italic") ) { return set_italic_dyn(); }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return inCallProp ? get_fontFamily() : fontFamily; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_fontSize") ) { return get_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontSize") ) { return set_fontSize_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return inCallProp ? get_letterSpacing() : letterSpacing; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_fontFamily") ) { return get_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontFamily") ) { return set_fontFamily_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_letterSpacing") ) { return get_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_letterSpacing") ) { return set_letterSpacing_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"INPUT_TEXT_INTRINSIC_WIDTH") ) { return INPUT_TEXT_INTRINSIC_WIDTH; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"INPUT_TEXT_INTRINSIC_HEIGHT") ) { return INPUT_TEXT_INTRINSIC_HEIGHT; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeTextInputBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { if (inCallProp) return set_italic(inValue);bold=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { if (inCallProp) return set_color(inValue);color=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { if (inCallProp) return set_italic(inValue);italic=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fontSize") ) { if (inCallProp) return set_fontSize(inValue);fontSize=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fontFamily") ) { if (inCallProp) return set_fontFamily(inValue);fontFamily=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { if (inCallProp) return set_letterSpacing(inValue);letterSpacing=inValue.Cast< Float >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"INPUT_TEXT_INTRINSIC_WIDTH") ) { INPUT_TEXT_INTRINSIC_WIDTH=inValue.Cast< int >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"INPUT_TEXT_INTRINSIC_HEIGHT") ) { INPUT_TEXT_INTRINSIC_HEIGHT=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeTextInputBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fontSize"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("fontFamily"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("bold"));
	outFields->push(HX_CSTRING("italic"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INPUT_TEXT_INTRINSIC_WIDTH"),
	HX_CSTRING("INPUT_TEXT_INTRINSIC_HEIGHT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_intrinsicHeight"),
	HX_CSTRING("get_intrinsicWidth"),
	HX_CSTRING("get_letterSpacing"),
	HX_CSTRING("set_letterSpacing"),
	HX_CSTRING("get_fontSize"),
	HX_CSTRING("set_fontSize"),
	HX_CSTRING("get_fontFamily"),
	HX_CSTRING("set_fontFamily"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_color"),
	HX_CSTRING("set_bold"),
	HX_CSTRING("get_bold"),
	HX_CSTRING("get_italic"),
	HX_CSTRING("set_italic"),
	HX_CSTRING("fontSize"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("fontFamily"),
	HX_CSTRING("color"),
	HX_CSTRING("bold"),
	HX_CSTRING("italic"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeTextInputBase_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NativeTextInputBase_obj::INPUT_TEXT_INTRINSIC_WIDTH,"INPUT_TEXT_INTRINSIC_WIDTH");
	HX_MARK_MEMBER_NAME(NativeTextInputBase_obj::INPUT_TEXT_INTRINSIC_HEIGHT,"INPUT_TEXT_INTRINSIC_HEIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeTextInputBase_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NativeTextInputBase_obj::INPUT_TEXT_INTRINSIC_WIDTH,"INPUT_TEXT_INTRINSIC_WIDTH");
	HX_VISIT_MEMBER_NAME(NativeTextInputBase_obj::INPUT_TEXT_INTRINSIC_HEIGHT,"INPUT_TEXT_INTRINSIC_HEIGHT");
};

Class NativeTextInputBase_obj::__mClass;

void NativeTextInputBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.NativeTextInputBase"), hx::TCanCast< NativeTextInputBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeTextInputBase_obj::__boot()
{
	INPUT_TEXT_INTRINSIC_WIDTH= (int)150;
	INPUT_TEXT_INTRINSIC_HEIGHT= (int)30;
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
