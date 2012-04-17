#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_Angle
#include <cocktail/core/unit/Angle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientAngle
#include <cocktail/core/unit/GradientAngle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientCornerValue
#include <cocktail/core/unit/GradientCornerValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientSideValue
#include <cocktail/core/unit/GradientSideValue.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::GradientAngle  GradientAngle_obj::angle(::cocktail::core::unit::Angle value)
	{ return hx::CreateEnum< GradientAngle_obj >(HX_CSTRING("angle"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::GradientAngle  GradientAngle_obj::corner(::cocktail::core::unit::GradientCornerValue value)
	{ return hx::CreateEnum< GradientAngle_obj >(HX_CSTRING("corner"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::GradientAngle  GradientAngle_obj::side(::cocktail::core::unit::GradientSideValue value)
	{ return hx::CreateEnum< GradientAngle_obj >(HX_CSTRING("side"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(GradientAngle_obj)

int GradientAngle_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("angle")) return 0;
	if (inName==HX_CSTRING("corner")) return 2;
	if (inName==HX_CSTRING("side")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(GradientAngle_obj,angle,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(GradientAngle_obj,corner,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(GradientAngle_obj,side,return)

int GradientAngle_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("angle")) return 1;
	if (inName==HX_CSTRING("corner")) return 1;
	if (inName==HX_CSTRING("side")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic GradientAngle_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("angle")) return angle_dyn();
	if (inName==HX_CSTRING("corner")) return corner_dyn();
	if (inName==HX_CSTRING("side")) return side_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("angle"),
	HX_CSTRING("side"),
	HX_CSTRING("corner"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientAngle_obj::__mClass;

Dynamic __Create_GradientAngle_obj() { return new GradientAngle_obj; }

void GradientAngle_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.GradientAngle"), hx::TCanCast< GradientAngle_obj >,sStaticFields,sMemberFields,
	&__Create_GradientAngle_obj, &__Create,
	&super::__SGetClass(), &CreateGradientAngle_obj, sMarkStatics);
}

void GradientAngle_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit
