#include <hxcpp.h>

#ifndef INCLUDED_core_style_PositionOffset
#include <core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::PositionOffset PositionOffset_obj::cssAuto;

::core::style::PositionOffset  PositionOffset_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< PositionOffset_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::PositionOffset  PositionOffset_obj::percent(int value)
	{ return hx::CreateEnum< PositionOffset_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(PositionOffset_obj)

int PositionOffset_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PositionOffset_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PositionOffset_obj,percent,return)

int PositionOffset_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic PositionOffset_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(PositionOffset_obj::cssAuto,"cssAuto");
};

static ::String sMemberFields[] = { ::String(null()) };
Class PositionOffset_obj::__mClass;

Dynamic __Create_PositionOffset_obj() { return new PositionOffset_obj; }

void PositionOffset_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.PositionOffset"), hx::TCanCast< PositionOffset_obj >,sStaticFields,sMemberFields,
	&__Create_PositionOffset_obj, &__Create,
	&super::__SGetClass(), &CreatePositionOffset_obj, sMarkStatics);
}

void PositionOffset_obj::__boot()
{
Static(cssAuto) = hx::CreateEnum< PositionOffset_obj >(HX_CSTRING("cssAuto"),2);
}


} // end namespace core
} // end namespace style
