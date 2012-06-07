#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_Margin
#include <cocktail/core/style/Margin.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::Margin Margin_obj::cssAuto;

::cocktail::core::style::Margin  Margin_obj::length(::cocktail::core::unit::Length value)
	{ return hx::CreateEnum< Margin_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::Margin  Margin_obj::percent(int value)
	{ return hx::CreateEnum< Margin_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(Margin_obj)

int Margin_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Margin_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Margin_obj,percent,return)

int Margin_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Margin_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(Margin_obj::cssAuto,"cssAuto");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Margin_obj::__mClass;

Dynamic __Create_Margin_obj() { return new Margin_obj; }

void Margin_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.Margin"), hx::TCanCast< Margin_obj >,sStaticFields,sMemberFields,
	&__Create_Margin_obj, &__Create,
	&super::__SGetClass(), &CreateMargin_obj, sMarkStatics);
}

void Margin_obj::__boot()
{
Static(cssAuto) = hx::CreateEnum< Margin_obj >(HX_CSTRING("cssAuto"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
