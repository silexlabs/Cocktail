#include <hxcpp.h>

#ifndef INCLUDED_core_style_BackgroundPositionY
#include <core/style/BackgroundPositionY.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::BackgroundPositionY BackgroundPositionY_obj::bottom;

::core::style::BackgroundPositionY BackgroundPositionY_obj::center;

::core::style::BackgroundPositionY  BackgroundPositionY_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< BackgroundPositionY_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::core::style::BackgroundPositionY  BackgroundPositionY_obj::percent(int value)
	{ return hx::CreateEnum< BackgroundPositionY_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

::core::style::BackgroundPositionY BackgroundPositionY_obj::top;

HX_DEFINE_CREATE_ENUM(BackgroundPositionY_obj)

int BackgroundPositionY_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bottom")) return 4;
	if (inName==HX_CSTRING("center")) return 3;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("top")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundPositionY_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundPositionY_obj,percent,return)

int BackgroundPositionY_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bottom")) return 0;
	if (inName==HX_CSTRING("center")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("top")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundPositionY_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("bottom")) return bottom;
	if (inName==HX_CSTRING("center")) return center;
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("percent")) return percent_dyn();
	if (inName==HX_CSTRING("top")) return top;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percent"),
	HX_CSTRING("top"),
	HX_CSTRING("center"),
	HX_CSTRING("bottom"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundPositionY_obj::bottom,"bottom");
	HX_MARK_MEMBER_NAME(BackgroundPositionY_obj::center,"center");
	HX_MARK_MEMBER_NAME(BackgroundPositionY_obj::top,"top");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundPositionY_obj::__mClass;

Dynamic __Create_BackgroundPositionY_obj() { return new BackgroundPositionY_obj; }

void BackgroundPositionY_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.BackgroundPositionY"), hx::TCanCast< BackgroundPositionY_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundPositionY_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundPositionY_obj, sMarkStatics);
}

void BackgroundPositionY_obj::__boot()
{
Static(bottom) = hx::CreateEnum< BackgroundPositionY_obj >(HX_CSTRING("bottom"),4);
Static(center) = hx::CreateEnum< BackgroundPositionY_obj >(HX_CSTRING("center"),3);
Static(top) = hx::CreateEnum< BackgroundPositionY_obj >(HX_CSTRING("top"),2);
}


} // end namespace core
} // end namespace style
