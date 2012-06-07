#include <hxcpp.h>

#ifndef INCLUDED_core_style_WordSpacing
#include <core/style/WordSpacing.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::WordSpacing  WordSpacing_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< WordSpacing_obj >(HX_CSTRING("length"),1,hx::DynamicArray(0,1).Add(value)); }

::core::style::WordSpacing WordSpacing_obj::normal;

HX_DEFINE_CREATE_ENUM(WordSpacing_obj)

int WordSpacing_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(WordSpacing_obj,length,return)

int WordSpacing_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic WordSpacing_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(WordSpacing_obj::normal,"normal");
};

static ::String sMemberFields[] = { ::String(null()) };
Class WordSpacing_obj::__mClass;

Dynamic __Create_WordSpacing_obj() { return new WordSpacing_obj; }

void WordSpacing_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.WordSpacing"), hx::TCanCast< WordSpacing_obj >,sStaticFields,sMemberFields,
	&__Create_WordSpacing_obj, &__Create,
	&super::__SGetClass(), &CreateWordSpacing_obj, sMarkStatics);
}

void WordSpacing_obj::__boot()
{
Static(normal) = hx::CreateEnum< WordSpacing_obj >(HX_CSTRING("normal"),0);
}


} // end namespace core
} // end namespace style
