#include <hxcpp.h>

#ifndef INCLUDED_core_style_Padding
#include <core/style/Padding.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::Padding  Padding_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< Padding_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::Padding  Padding_obj::percent(int value)
	{ return hx::CreateEnum< Padding_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(Padding_obj)

int Padding_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Padding_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Padding_obj,percent,return)

int Padding_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Padding_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("percent")) return percent_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percent"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class Padding_obj::__mClass;

Dynamic __Create_Padding_obj() { return new Padding_obj; }

void Padding_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.Padding"), hx::TCanCast< Padding_obj >,sStaticFields,sMemberFields,
	&__Create_Padding_obj, &__Create,
	&super::__SGetClass(), &CreatePadding_obj, sMarkStatics);
}

void Padding_obj::__boot()
{
}


} // end namespace core
} // end namespace style
