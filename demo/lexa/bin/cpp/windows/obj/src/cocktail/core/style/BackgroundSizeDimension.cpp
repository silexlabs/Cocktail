#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_BackgroundSizeDimension
#include <cocktail/core/style/BackgroundSizeDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::BackgroundSizeDimension BackgroundSizeDimension_obj::cssAuto;

::cocktail::core::style::BackgroundSizeDimension  BackgroundSizeDimension_obj::length(::cocktail::core::unit::Length value)
	{ return hx::CreateEnum< BackgroundSizeDimension_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::BackgroundSizeDimension  BackgroundSizeDimension_obj::percent(int value)
	{ return hx::CreateEnum< BackgroundSizeDimension_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(BackgroundSizeDimension_obj)

int BackgroundSizeDimension_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundSizeDimension_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundSizeDimension_obj,percent,return)

int BackgroundSizeDimension_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundSizeDimension_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(BackgroundSizeDimension_obj::cssAuto,"cssAuto");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundSizeDimension_obj::__mClass;

Dynamic __Create_BackgroundSizeDimension_obj() { return new BackgroundSizeDimension_obj; }

void BackgroundSizeDimension_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.BackgroundSizeDimension"), hx::TCanCast< BackgroundSizeDimension_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundSizeDimension_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundSizeDimension_obj, sMarkStatics);
}

void BackgroundSizeDimension_obj::__boot()
{
Static(cssAuto) = hx::CreateEnum< BackgroundSizeDimension_obj >(HX_CSTRING("cssAuto"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
