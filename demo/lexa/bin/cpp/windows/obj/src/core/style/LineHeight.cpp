#include <hxcpp.h>

#ifndef INCLUDED_core_style_LineHeight
#include <core/style/LineHeight.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::LineHeight  LineHeight_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< LineHeight_obj >(HX_CSTRING("length"),2,hx::DynamicArray(0,1).Add(value)); }

::core::style::LineHeight LineHeight_obj::normal;

::core::style::LineHeight  LineHeight_obj::number(double value)
	{ return hx::CreateEnum< LineHeight_obj >(HX_CSTRING("number"),1,hx::DynamicArray(0,1).Add(value)); }

::core::style::LineHeight  LineHeight_obj::percentage(int value)
	{ return hx::CreateEnum< LineHeight_obj >(HX_CSTRING("percentage"),3,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(LineHeight_obj)

int LineHeight_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 2;
	if (inName==HX_CSTRING("normal")) return 0;
	if (inName==HX_CSTRING("number")) return 1;
	if (inName==HX_CSTRING("percentage")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(LineHeight_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(LineHeight_obj,number,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(LineHeight_obj,percentage,return)

int LineHeight_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("normal")) return 0;
	if (inName==HX_CSTRING("number")) return 1;
	if (inName==HX_CSTRING("percentage")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic LineHeight_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("normal")) return normal;
	if (inName==HX_CSTRING("number")) return number_dyn();
	if (inName==HX_CSTRING("percentage")) return percentage_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("number"),
	HX_CSTRING("length"),
	HX_CSTRING("percentage"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LineHeight_obj::normal,"normal");
};

static ::String sMemberFields[] = { ::String(null()) };
Class LineHeight_obj::__mClass;

Dynamic __Create_LineHeight_obj() { return new LineHeight_obj; }

void LineHeight_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.LineHeight"), hx::TCanCast< LineHeight_obj >,sStaticFields,sMemberFields,
	&__Create_LineHeight_obj, &__Create,
	&super::__SGetClass(), &CreateLineHeight_obj, sMarkStatics);
}

void LineHeight_obj::__boot()
{
Static(normal) = hx::CreateEnum< LineHeight_obj >(HX_CSTRING("normal"),0);
}


} // end namespace core
} // end namespace style
