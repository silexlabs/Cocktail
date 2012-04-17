#include <hxcpp.h>

#ifndef INCLUDED_core_style_BackgroundPositionX
#include <core/style/BackgroundPositionX.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::BackgroundPositionX BackgroundPositionX_obj::center;

::core::style::BackgroundPositionX BackgroundPositionX_obj::left;

::core::style::BackgroundPositionX  BackgroundPositionX_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< BackgroundPositionX_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::BackgroundPositionX  BackgroundPositionX_obj::percent(int value)
	{ return hx::CreateEnum< BackgroundPositionX_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

::core::style::BackgroundPositionX BackgroundPositionX_obj::right;

HX_DEFINE_CREATE_ENUM(BackgroundPositionX_obj)

int BackgroundPositionX_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("center")) return 3;
	if (inName==HX_CSTRING("left")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("right")) return 4;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundPositionX_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundPositionX_obj,percent,return)

int BackgroundPositionX_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("center")) return 0;
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("right")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundPositionX_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("center")) return center;
	if (inName==HX_CSTRING("left")) return left;
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("percent")) return percent_dyn();
	if (inName==HX_CSTRING("right")) return right;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percent"),
	HX_CSTRING("left"),
	HX_CSTRING("center"),
	HX_CSTRING("right"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundPositionX_obj::center,"center");
	HX_MARK_MEMBER_NAME(BackgroundPositionX_obj::left,"left");
	HX_MARK_MEMBER_NAME(BackgroundPositionX_obj::right,"right");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundPositionX_obj::__mClass;

Dynamic __Create_BackgroundPositionX_obj() { return new BackgroundPositionX_obj; }

void BackgroundPositionX_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.BackgroundPositionX"), hx::TCanCast< BackgroundPositionX_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundPositionX_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundPositionX_obj, sMarkStatics);
}

void BackgroundPositionX_obj::__boot()
{
Static(center) = hx::CreateEnum< BackgroundPositionX_obj >(HX_CSTRING("center"),3);
Static(left) = hx::CreateEnum< BackgroundPositionX_obj >(HX_CSTRING("left"),2);
Static(right) = hx::CreateEnum< BackgroundPositionX_obj >(HX_CSTRING("right"),4);
}


} // end namespace core
} // end namespace style
