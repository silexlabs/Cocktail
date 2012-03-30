#include <hxcpp.h>

#ifndef INCLUDED_core_style_ConstrainedDimension
#include <core/style/ConstrainedDimension.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::ConstrainedDimension  ConstrainedDimension_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< ConstrainedDimension_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::ConstrainedDimension ConstrainedDimension_obj::none;

::core::style::ConstrainedDimension  ConstrainedDimension_obj::percent(int value)
	{ return hx::CreateEnum< ConstrainedDimension_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(ConstrainedDimension_obj)

int ConstrainedDimension_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("none")) return 2;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ConstrainedDimension_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ConstrainedDimension_obj,percent,return)

int ConstrainedDimension_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic ConstrainedDimension_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("percent")) return percent_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percent"),
	HX_CSTRING("none"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConstrainedDimension_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class ConstrainedDimension_obj::__mClass;

Dynamic __Create_ConstrainedDimension_obj() { return new ConstrainedDimension_obj; }

void ConstrainedDimension_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.ConstrainedDimension"), hx::TCanCast< ConstrainedDimension_obj >,sStaticFields,sMemberFields,
	&__Create_ConstrainedDimension_obj, &__Create,
	&super::__SGetClass(), &CreateConstrainedDimension_obj, sMarkStatics);
}

void ConstrainedDimension_obj::__boot()
{
Static(none) = hx::CreateEnum< ConstrainedDimension_obj >(HX_CSTRING("none"),2);
}


} // end namespace core
} // end namespace style
