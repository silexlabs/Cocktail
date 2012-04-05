#include <hxcpp.h>

#ifndef INCLUDED_core_style_Dimension
#include <core/style/Dimension.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::Dimension Dimension_obj::cssAuto;

::core::style::Dimension  Dimension_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< Dimension_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::Dimension  Dimension_obj::percent(int value)
	{ return hx::CreateEnum< Dimension_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(Dimension_obj)

int Dimension_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Dimension_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Dimension_obj,percent,return)

int Dimension_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Dimension_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("cssAuto")) return cssAuto;
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("percent")) return percent_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percent"),
	HX_CSTRING("cssAuto"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Dimension_obj::cssAuto,"cssAuto");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Dimension_obj::__mClass;

Dynamic __Create_Dimension_obj() { return new Dimension_obj; }

void Dimension_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.Dimension"), hx::TCanCast< Dimension_obj >,sStaticFields,sMemberFields,
	&__Create_Dimension_obj, &__Create,
	&super::__SGetClass(), &CreateDimension_obj, sMarkStatics);
}

void Dimension_obj::__boot()
{
Static(cssAuto) = hx::CreateEnum< Dimension_obj >(HX_CSTRING("cssAuto"),2);
}


} // end namespace core
} // end namespace style
