#include <hxcpp.h>

#ifndef INCLUDED_core_style_Translation
#include <core/style/Translation.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::Translation  Translation_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< Translation_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::Translation  Translation_obj::percent(int value)
	{ return hx::CreateEnum< Translation_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(Translation_obj)

int Translation_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Translation_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Translation_obj,percent,return)

int Translation_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Translation_obj::__Field(const ::String &inName)
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
Class Translation_obj::__mClass;

Dynamic __Create_Translation_obj() { return new Translation_obj; }

void Translation_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.Translation"), hx::TCanCast< Translation_obj >,sStaticFields,sMemberFields,
	&__Create_Translation_obj, &__Create,
	&super::__SGetClass(), &CreateTranslation_obj, sMarkStatics);
}

void Translation_obj::__boot()
{
}


} // end namespace core
} // end namespace style
