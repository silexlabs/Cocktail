#include <hxcpp.h>

#ifndef INCLUDED_core_style_LetterSpacing
#include <core/style/LetterSpacing.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::LetterSpacing  LetterSpacing_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< LetterSpacing_obj >(HX_CSTRING("length"),1,hx::DynamicArray(0,1).Add(value)); }

::core::style::LetterSpacing LetterSpacing_obj::normal;

HX_DEFINE_CREATE_ENUM(LetterSpacing_obj)

int LetterSpacing_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(LetterSpacing_obj,length,return)

int LetterSpacing_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic LetterSpacing_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("normal")) return normal;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("length"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LetterSpacing_obj::normal,"normal");
};

static ::String sMemberFields[] = { ::String(null()) };
Class LetterSpacing_obj::__mClass;

Dynamic __Create_LetterSpacing_obj() { return new LetterSpacing_obj; }

void LetterSpacing_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.LetterSpacing"), hx::TCanCast< LetterSpacing_obj >,sStaticFields,sMemberFields,
	&__Create_LetterSpacing_obj, &__Create,
	&super::__SGetClass(), &CreateLetterSpacing_obj, sMarkStatics);
}

void LetterSpacing_obj::__boot()
{
Static(normal) = hx::CreateEnum< LetterSpacing_obj >(HX_CSTRING("normal"),0);
}


} // end namespace core
} // end namespace style
