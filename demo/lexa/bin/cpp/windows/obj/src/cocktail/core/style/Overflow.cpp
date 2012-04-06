#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_Overflow
#include <cocktail/core/style/Overflow.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::Overflow Overflow_obj::cssAuto;

::cocktail::core::style::Overflow Overflow_obj::hidden;

::cocktail::core::style::Overflow Overflow_obj::scroll;

::cocktail::core::style::Overflow Overflow_obj::visible;

HX_DEFINE_CREATE_ENUM(Overflow_obj)

int Overflow_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 3;
	if (inName==HX_CSTRING("hidden")) return 1;
	if (inName==HX_CSTRING("scroll")) return 2;
	if (inName==HX_CSTRING("visible")) return 0;
	return super::__FindIndex(inName);
}

int Overflow_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 0;
	if (inName==HX_CSTRING("hidden")) return 0;
	if (inName==HX_CSTRING("scroll")) return 0;
	if (inName==HX_CSTRING("visible")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Overflow_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("cssAuto")) return cssAuto;
	if (inName==HX_CSTRING("hidden")) return hidden;
	if (inName==HX_CSTRING("scroll")) return scroll;
	if (inName==HX_CSTRING("visible")) return visible;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("visible"),
	HX_CSTRING("hidden"),
	HX_CSTRING("scroll"),
	HX_CSTRING("cssAuto"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Overflow_obj::cssAuto,"cssAuto");
	HX_MARK_MEMBER_NAME(Overflow_obj::hidden,"hidden");
	HX_MARK_MEMBER_NAME(Overflow_obj::scroll,"scroll");
	HX_MARK_MEMBER_NAME(Overflow_obj::visible,"visible");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Overflow_obj::__mClass;

Dynamic __Create_Overflow_obj() { return new Overflow_obj; }

void Overflow_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.Overflow"), hx::TCanCast< Overflow_obj >,sStaticFields,sMemberFields,
	&__Create_Overflow_obj, &__Create,
	&super::__SGetClass(), &CreateOverflow_obj, sMarkStatics);
}

void Overflow_obj::__boot()
{
Static(cssAuto) = hx::CreateEnum< Overflow_obj >(HX_CSTRING("cssAuto"),3);
Static(hidden) = hx::CreateEnum< Overflow_obj >(HX_CSTRING("hidden"),1);
Static(scroll) = hx::CreateEnum< Overflow_obj >(HX_CSTRING("scroll"),2);
Static(visible) = hx::CreateEnum< Overflow_obj >(HX_CSTRING("visible"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
