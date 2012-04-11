#include <hxcpp.h>

#ifndef INCLUDED_hxtml_Value
#include <hxtml/Value.h>
#endif
namespace hxtml{

::hxtml::Value  Value_obj::VFloat(double v)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VFloat"),4,hx::DynamicArray(0,1).Add(v)); }

::hxtml::Value  Value_obj::VGroup(Array< ::hxtml::Value > l)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VGroup"),8,hx::DynamicArray(0,1).Add(l)); }

::hxtml::Value  Value_obj::VHex(::String v)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VHex"),6,hx::DynamicArray(0,1).Add(v)); }

::hxtml::Value  Value_obj::VIdent(::String i)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VIdent"),0,hx::DynamicArray(0,1).Add(i)); }

::hxtml::Value  Value_obj::VInt(int v)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VInt"),5,hx::DynamicArray(0,1).Add(v)); }

::hxtml::Value  Value_obj::VLabel(::String v,::hxtml::Value val)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VLabel"),10,hx::DynamicArray(0,2).Add(v).Add(val)); }

::hxtml::Value  Value_obj::VList(Array< ::hxtml::Value > l)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VList"),7,hx::DynamicArray(0,1).Add(l)); }

::hxtml::Value  Value_obj::VRGBA(::String v)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VRGBA"),3,hx::DynamicArray(0,1).Add(v)); }

::hxtml::Value Value_obj::VSlash;

::hxtml::Value  Value_obj::VString(::String s)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VString"),1,hx::DynamicArray(0,1).Add(s)); }

::hxtml::Value  Value_obj::VUnit(double v,::String unit)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VUnit"),2,hx::DynamicArray(0,2).Add(v).Add(unit)); }

::hxtml::Value  Value_obj::VUrl(::String v)
	{ return hx::CreateEnum< Value_obj >(HX_CSTRING("VUrl"),9,hx::DynamicArray(0,1).Add(v)); }

HX_DEFINE_CREATE_ENUM(Value_obj)

int Value_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("VFloat")) return 4;
	if (inName==HX_CSTRING("VGroup")) return 8;
	if (inName==HX_CSTRING("VHex")) return 6;
	if (inName==HX_CSTRING("VIdent")) return 0;
	if (inName==HX_CSTRING("VInt")) return 5;
	if (inName==HX_CSTRING("VLabel")) return 10;
	if (inName==HX_CSTRING("VList")) return 7;
	if (inName==HX_CSTRING("VRGBA")) return 3;
	if (inName==HX_CSTRING("VSlash")) return 11;
	if (inName==HX_CSTRING("VString")) return 1;
	if (inName==HX_CSTRING("VUnit")) return 2;
	if (inName==HX_CSTRING("VUrl")) return 9;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VFloat,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VGroup,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VHex,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VIdent,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VInt,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_obj,VLabel,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VList,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VRGBA,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VString,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Value_obj,VUnit,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Value_obj,VUrl,return)

int Value_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("VFloat")) return 1;
	if (inName==HX_CSTRING("VGroup")) return 1;
	if (inName==HX_CSTRING("VHex")) return 1;
	if (inName==HX_CSTRING("VIdent")) return 1;
	if (inName==HX_CSTRING("VInt")) return 1;
	if (inName==HX_CSTRING("VLabel")) return 2;
	if (inName==HX_CSTRING("VList")) return 1;
	if (inName==HX_CSTRING("VRGBA")) return 1;
	if (inName==HX_CSTRING("VSlash")) return 0;
	if (inName==HX_CSTRING("VString")) return 1;
	if (inName==HX_CSTRING("VUnit")) return 2;
	if (inName==HX_CSTRING("VUrl")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Value_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("VFloat")) return VFloat_dyn();
	if (inName==HX_CSTRING("VGroup")) return VGroup_dyn();
	if (inName==HX_CSTRING("VHex")) return VHex_dyn();
	if (inName==HX_CSTRING("VIdent")) return VIdent_dyn();
	if (inName==HX_CSTRING("VInt")) return VInt_dyn();
	if (inName==HX_CSTRING("VLabel")) return VLabel_dyn();
	if (inName==HX_CSTRING("VList")) return VList_dyn();
	if (inName==HX_CSTRING("VRGBA")) return VRGBA_dyn();
	if (inName==HX_CSTRING("VSlash")) return VSlash;
	if (inName==HX_CSTRING("VString")) return VString_dyn();
	if (inName==HX_CSTRING("VUnit")) return VUnit_dyn();
	if (inName==HX_CSTRING("VUrl")) return VUrl_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("VIdent"),
	HX_CSTRING("VString"),
	HX_CSTRING("VUnit"),
	HX_CSTRING("VRGBA"),
	HX_CSTRING("VFloat"),
	HX_CSTRING("VInt"),
	HX_CSTRING("VHex"),
	HX_CSTRING("VList"),
	HX_CSTRING("VGroup"),
	HX_CSTRING("VUrl"),
	HX_CSTRING("VLabel"),
	HX_CSTRING("VSlash"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Value_obj::VSlash,"VSlash");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Value_obj::__mClass;

Dynamic __Create_Value_obj() { return new Value_obj; }

void Value_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxtml.Value"), hx::TCanCast< Value_obj >,sStaticFields,sMemberFields,
	&__Create_Value_obj, &__Create,
	&super::__SGetClass(), &CreateValue_obj, sMarkStatics);
}

void Value_obj::__boot()
{
Static(VSlash) = hx::CreateEnum< Value_obj >(HX_CSTRING("VSlash"),11);
}


} // end namespace hxtml
