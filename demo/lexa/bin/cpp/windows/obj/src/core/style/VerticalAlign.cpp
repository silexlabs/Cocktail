#include <hxcpp.h>

#ifndef INCLUDED_core_style_VerticalAlign
#include <core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
namespace core{
namespace style{

::core::style::VerticalAlign VerticalAlign_obj::baseline;

::core::style::VerticalAlign VerticalAlign_obj::bottom;

::core::style::VerticalAlign VerticalAlign_obj::cssSuper;

::core::style::VerticalAlign  VerticalAlign_obj::length(::core::unit::Length value)
	{ return hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("length"),9,hx::DynamicArray(0,1).Add(value)); }

::core::style::VerticalAlign VerticalAlign_obj::middle;

::core::style::VerticalAlign  VerticalAlign_obj::percent(int value)
	{ return hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("percent"),8,hx::DynamicArray(0,1).Add(value)); }

::core::style::VerticalAlign VerticalAlign_obj::sub;

::core::style::VerticalAlign VerticalAlign_obj::textBottom;

::core::style::VerticalAlign VerticalAlign_obj::textTop;

::core::style::VerticalAlign VerticalAlign_obj::top;

HX_DEFINE_CREATE_ENUM(VerticalAlign_obj)

int VerticalAlign_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("baseline")) return 0;
	if (inName==HX_CSTRING("bottom")) return 6;
	if (inName==HX_CSTRING("cssSuper")) return 2;
	if (inName==HX_CSTRING("length")) return 9;
	if (inName==HX_CSTRING("middle")) return 5;
	if (inName==HX_CSTRING("percent")) return 8;
	if (inName==HX_CSTRING("sub")) return 1;
	if (inName==HX_CSTRING("textBottom")) return 7;
	if (inName==HX_CSTRING("textTop")) return 4;
	if (inName==HX_CSTRING("top")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(VerticalAlign_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(VerticalAlign_obj,percent,return)

int VerticalAlign_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("baseline")) return 0;
	if (inName==HX_CSTRING("bottom")) return 0;
	if (inName==HX_CSTRING("cssSuper")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("middle")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("sub")) return 0;
	if (inName==HX_CSTRING("textBottom")) return 0;
	if (inName==HX_CSTRING("textTop")) return 0;
	if (inName==HX_CSTRING("top")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic VerticalAlign_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("baseline")) return baseline;
	if (inName==HX_CSTRING("bottom")) return bottom;
	if (inName==HX_CSTRING("cssSuper")) return cssSuper;
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("middle")) return middle;
	if (inName==HX_CSTRING("percent")) return percent_dyn();
	if (inName==HX_CSTRING("sub")) return sub;
	if (inName==HX_CSTRING("textBottom")) return textBottom;
	if (inName==HX_CSTRING("textTop")) return textTop;
	if (inName==HX_CSTRING("top")) return top;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("baseline"),
	HX_CSTRING("sub"),
	HX_CSTRING("cssSuper"),
	HX_CSTRING("top"),
	HX_CSTRING("textTop"),
	HX_CSTRING("middle"),
	HX_CSTRING("bottom"),
	HX_CSTRING("textBottom"),
	HX_CSTRING("percent"),
	HX_CSTRING("length"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::baseline,"baseline");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::bottom,"bottom");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::cssSuper,"cssSuper");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::middle,"middle");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::sub,"sub");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::textBottom,"textBottom");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::textTop,"textTop");
	HX_MARK_MEMBER_NAME(VerticalAlign_obj::top,"top");
};

static ::String sMemberFields[] = { ::String(null()) };
Class VerticalAlign_obj::__mClass;

Dynamic __Create_VerticalAlign_obj() { return new VerticalAlign_obj; }

void VerticalAlign_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.VerticalAlign"), hx::TCanCast< VerticalAlign_obj >,sStaticFields,sMemberFields,
	&__Create_VerticalAlign_obj, &__Create,
	&super::__SGetClass(), &CreateVerticalAlign_obj, sMarkStatics);
}

void VerticalAlign_obj::__boot()
{
Static(baseline) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("baseline"),0);
Static(bottom) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("bottom"),6);
Static(cssSuper) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("cssSuper"),2);
Static(middle) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("middle"),5);
Static(sub) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("sub"),1);
Static(textBottom) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("textBottom"),7);
Static(textTop) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("textTop"),4);
Static(top) = hx::CreateEnum< VerticalAlign_obj >(HX_CSTRING("top"),3);
}


} // end namespace core
} // end namespace style
