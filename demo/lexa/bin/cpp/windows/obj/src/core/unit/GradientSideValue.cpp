#include <hxcpp.h>

#ifndef INCLUDED_core_unit_GradientSideValue
#include <core/unit/GradientSideValue.h>
#endif
namespace core{
namespace unit{

::core::unit::GradientSideValue GradientSideValue_obj::bottom;

::core::unit::GradientSideValue GradientSideValue_obj::left;

::core::unit::GradientSideValue GradientSideValue_obj::right;

::core::unit::GradientSideValue GradientSideValue_obj::top;

HX_DEFINE_CREATE_ENUM(GradientSideValue_obj)

int GradientSideValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bottom")) return 2;
	if (inName==HX_CSTRING("left")) return 1;
	if (inName==HX_CSTRING("right")) return 3;
	if (inName==HX_CSTRING("top")) return 0;
	return super::__FindIndex(inName);
}

int GradientSideValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bottom")) return 0;
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("right")) return 0;
	if (inName==HX_CSTRING("top")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GradientSideValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("bottom")) return bottom;
	if (inName==HX_CSTRING("left")) return left;
	if (inName==HX_CSTRING("right")) return right;
	if (inName==HX_CSTRING("top")) return top;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("top"),
	HX_CSTRING("left"),
	HX_CSTRING("bottom"),
	HX_CSTRING("right"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GradientSideValue_obj::bottom,"bottom");
	HX_MARK_MEMBER_NAME(GradientSideValue_obj::left,"left");
	HX_MARK_MEMBER_NAME(GradientSideValue_obj::right,"right");
	HX_MARK_MEMBER_NAME(GradientSideValue_obj::top,"top");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientSideValue_obj::__mClass;

Dynamic __Create_GradientSideValue_obj() { return new GradientSideValue_obj; }

void GradientSideValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.unit.GradientSideValue"), hx::TCanCast< GradientSideValue_obj >,sStaticFields,sMemberFields,
	&__Create_GradientSideValue_obj, &__Create,
	&super::__SGetClass(), &CreateGradientSideValue_obj, sMarkStatics);
}

void GradientSideValue_obj::__boot()
{
Static(bottom) = hx::CreateEnum< GradientSideValue_obj >(HX_CSTRING("bottom"),2);
Static(left) = hx::CreateEnum< GradientSideValue_obj >(HX_CSTRING("left"),1);
Static(right) = hx::CreateEnum< GradientSideValue_obj >(HX_CSTRING("right"),3);
Static(top) = hx::CreateEnum< GradientSideValue_obj >(HX_CSTRING("top"),0);
}


} // end namespace core
} // end namespace unit
