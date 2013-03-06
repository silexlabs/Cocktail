#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void NativeTextInputBase_obj::__construct()
{
HX_STACK_PUSH("NativeTextInputBase::new","cocktail/port/base/NativeTextInputBase.hx",63);
{
}
;
	return null();
}

NativeTextInputBase_obj::~NativeTextInputBase_obj() { }

Dynamic NativeTextInputBase_obj::__CreateEmpty() { return  new NativeTextInputBase_obj; }
hx::ObjectPtr< NativeTextInputBase_obj > NativeTextInputBase_obj::__new()
{  hx::ObjectPtr< NativeTextInputBase_obj > result = new NativeTextInputBase_obj();
	result->__construct();
	return result;}

Dynamic NativeTextInputBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeTextInputBase_obj > result = new NativeTextInputBase_obj();
	result->__construct();
	return result;}

Float NativeTextInputBase_obj::get_letterSpacing( ){
	HX_STACK_PUSH("NativeTextInputBase::get_letterSpacing","cocktail/port/base/NativeTextInputBase.hx",195);
	HX_STACK_THIS(this);
	HX_STACK_LINE(195)
	return this->letterSpacing;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_letterSpacing,return )

Float NativeTextInputBase_obj::set_letterSpacing( Float value){
	HX_STACK_PUSH("NativeTextInputBase::set_letterSpacing","cocktail/port/base/NativeTextInputBase.hx",190);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(190)
	return this->letterSpacing = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_letterSpacing,return )

int NativeTextInputBase_obj::set_maxLength( int value){
	HX_STACK_PUSH("NativeTextInputBase::set_maxLength","cocktail/port/base/NativeTextInputBase.hx",185);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(185)
	return this->maxLength = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_maxLength,return )

::String NativeTextInputBase_obj::set_value( ::String textValue){
	HX_STACK_PUSH("NativeTextInputBase::set_value","cocktail/port/base/NativeTextInputBase.hx",180);
	HX_STACK_THIS(this);
	HX_STACK_ARG(textValue,"textValue");
	HX_STACK_LINE(180)
	return this->value = textValue;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_value,return )

::String NativeTextInputBase_obj::get_value( ){
	HX_STACK_PUSH("NativeTextInputBase::get_value","cocktail/port/base/NativeTextInputBase.hx",175);
	HX_STACK_THIS(this);
	HX_STACK_LINE(175)
	return this->value;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_value,return )

Float NativeTextInputBase_obj::get_fontSize( ){
	HX_STACK_PUSH("NativeTextInputBase::get_fontSize","cocktail/port/base/NativeTextInputBase.hx",170);
	HX_STACK_THIS(this);
	HX_STACK_LINE(170)
	return this->fontSize;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_fontSize,return )

Float NativeTextInputBase_obj::set_fontSize( Float value){
	HX_STACK_PUSH("NativeTextInputBase::set_fontSize","cocktail/port/base/NativeTextInputBase.hx",165);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(165)
	return this->fontSize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_fontSize,return )

::String NativeTextInputBase_obj::get_fontFamily( ){
	HX_STACK_PUSH("NativeTextInputBase::get_fontFamily","cocktail/port/base/NativeTextInputBase.hx",160);
	HX_STACK_THIS(this);
	HX_STACK_LINE(160)
	return this->fontFamily;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_fontFamily,return )

::String NativeTextInputBase_obj::set_fontFamily( ::String value){
	HX_STACK_PUSH("NativeTextInputBase::set_fontFamily","cocktail/port/base/NativeTextInputBase.hx",155);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(155)
	return this->fontFamily = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_fontFamily,return )

int NativeTextInputBase_obj::get_color( ){
	HX_STACK_PUSH("NativeTextInputBase::get_color","cocktail/port/base/NativeTextInputBase.hx",150);
	HX_STACK_THIS(this);
	HX_STACK_LINE(150)
	return this->color;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_color,return )

int NativeTextInputBase_obj::set_color( int value){
	HX_STACK_PUSH("NativeTextInputBase::set_color","cocktail/port/base/NativeTextInputBase.hx",145);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(145)
	return this->color = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_color,return )

bool NativeTextInputBase_obj::set_bold( bool value){
	HX_STACK_PUSH("NativeTextInputBase::set_bold","cocktail/port/base/NativeTextInputBase.hx",140);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(140)
	return this->set_italic(value);
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_bold,return )

bool NativeTextInputBase_obj::get_bold( ){
	HX_STACK_PUSH("NativeTextInputBase::get_bold","cocktail/port/base/NativeTextInputBase.hx",135);
	HX_STACK_THIS(this);
	HX_STACK_LINE(135)
	return this->get_italic();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_bold,return )

bool NativeTextInputBase_obj::get_italic( ){
	HX_STACK_PUSH("NativeTextInputBase::get_italic","cocktail/port/base/NativeTextInputBase.hx",130);
	HX_STACK_THIS(this);
	HX_STACK_LINE(130)
	return this->italic;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_italic,return )

bool NativeTextInputBase_obj::set_italic( bool value){
	HX_STACK_PUSH("NativeTextInputBase::set_italic","cocktail/port/base/NativeTextInputBase.hx",125);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(125)
	return this->italic = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_italic,return )

::cocktail::core::geom::RectangleVO NativeTextInputBase_obj::set_clipRect( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeTextInputBase::set_clipRect","cocktail/port/base/NativeTextInputBase.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(120)
	return this->clipRect = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_clipRect,return )

::cocktail::core::geom::RectangleVO NativeTextInputBase_obj::get_clipRect( ){
	HX_STACK_PUSH("NativeTextInputBase::get_clipRect","cocktail/port/base/NativeTextInputBase.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(115)
	return this->clipRect;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_clipRect,return )

::cocktail::core::geom::RectangleVO NativeTextInputBase_obj::set_viewport( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeTextInputBase::set_viewport","cocktail/port/base/NativeTextInputBase.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(110)
	return this->viewport = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,set_viewport,return )

::cocktail::core::geom::RectangleVO NativeTextInputBase_obj::get_viewport( ){
	HX_STACK_PUSH("NativeTextInputBase::get_viewport","cocktail/port/base/NativeTextInputBase.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(105)
	return this->viewport;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,get_viewport,return )

Void NativeTextInputBase_obj::focus( ){
{
		HX_STACK_PUSH("NativeTextInputBase::focus","cocktail/port/base/NativeTextInputBase.hx",96);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInputBase_obj,focus,(void))

Void NativeTextInputBase_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeTextInputBase::detach","cocktail/port/base/NativeTextInputBase.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,detach,(void))

Void NativeTextInputBase_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeTextInputBase::attach","cocktail/port/base/NativeTextInputBase.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeTextInputBase_obj,attach,(void))


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
	HX_MARK_MEMBER_NAME(clipRect,"clipRect");
	HX_MARK_MEMBER_NAME(viewport,"viewport");
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(value,"value");
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
	HX_VISIT_MEMBER_NAME(clipRect,"clipRect");
	HX_VISIT_MEMBER_NAME(viewport,"viewport");
	HX_VISIT_MEMBER_NAME(maxLength,"maxLength");
	HX_VISIT_MEMBER_NAME(value,"value");
}

Dynamic NativeTextInputBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bold") ) { return inCallProp ? get_italic() : bold; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"focus") ) { return focus_dyn(); }
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		if (HX_FIELD_EQ(inName,"italic") ) { return inCallProp ? get_italic() : italic; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_bold") ) { return set_bold_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bold") ) { return get_bold_dyn(); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return inCallProp ? get_fontSize() : fontSize; }
		if (HX_FIELD_EQ(inName,"clipRect") ) { return inCallProp ? get_clipRect() : clipRect; }
		if (HX_FIELD_EQ(inName,"viewport") ) { return inCallProp ? get_viewport() : viewport; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return maxLength; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_italic") ) { return get_italic_dyn(); }
		if (HX_FIELD_EQ(inName,"set_italic") ) { return set_italic_dyn(); }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return inCallProp ? get_fontFamily() : fontFamily; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_fontSize") ) { return get_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontSize") ) { return set_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_clipRect") ) { return set_clipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clipRect") ) { return get_clipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"set_viewport") ) { return set_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"get_viewport") ) { return get_viewport_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return inCallProp ? get_letterSpacing() : letterSpacing; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_fontFamily") ) { return get_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontFamily") ) { return set_fontFamily_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_letterSpacing") ) { return get_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_letterSpacing") ) { return set_letterSpacing_dyn(); }
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
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"italic") ) { if (inCallProp) return set_italic(inValue);italic=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fontSize") ) { if (inCallProp) return set_fontSize(inValue);fontSize=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clipRect") ) { if (inCallProp) return set_clipRect(inValue);clipRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"viewport") ) { if (inCallProp) return set_viewport(inValue);viewport=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxLength") ) { if (inCallProp) return set_maxLength(inValue);maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fontFamily") ) { if (inCallProp) return set_fontFamily(inValue);fontFamily=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { if (inCallProp) return set_letterSpacing(inValue);letterSpacing=inValue.Cast< Float >(); return inValue; }
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
	outFields->push(HX_CSTRING("clipRect"));
	outFields->push(HX_CSTRING("viewport"));
	outFields->push(HX_CSTRING("maxLength"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_letterSpacing"),
	HX_CSTRING("set_letterSpacing"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
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
	HX_CSTRING("set_clipRect"),
	HX_CSTRING("get_clipRect"),
	HX_CSTRING("set_viewport"),
	HX_CSTRING("get_viewport"),
	HX_CSTRING("focus"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("fontSize"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("fontFamily"),
	HX_CSTRING("color"),
	HX_CSTRING("bold"),
	HX_CSTRING("italic"),
	HX_CSTRING("clipRect"),
	HX_CSTRING("viewport"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeTextInputBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeTextInputBase_obj::__mClass,"__mClass");
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
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
