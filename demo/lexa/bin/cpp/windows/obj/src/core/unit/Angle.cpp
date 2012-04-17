#include <hxcpp.h>

#ifndef INCLUDED_core_unit_Angle
#include <core/unit/Angle.h>
#endif
namespace core{
namespace unit{

::core::unit::Angle  Angle_obj::deg(double value)
	{ return hx::CreateEnum< Angle_obj >(HX_CSTRING("deg"),0,hx::DynamicArray(0,1).Add(value)); }

::core::unit::Angle  Angle_obj::grad(double value)
	{ return hx::CreateEnum< Angle_obj >(HX_CSTRING("grad"),1,hx::DynamicArray(0,1).Add(value)); }

::core::unit::Angle  Angle_obj::rad(double value)
	{ return hx::CreateEnum< Angle_obj >(HX_CSTRING("rad"),2,hx::DynamicArray(0,1).Add(value)); }

::core::unit::Angle  Angle_obj::turn(double value)
	{ return hx::CreateEnum< Angle_obj >(HX_CSTRING("turn"),3,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(Angle_obj)

int Angle_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("deg")) return 0;
	if (inName==HX_CSTRING("grad")) return 1;
	if (inName==HX_CSTRING("rad")) return 2;
	if (inName==HX_CSTRING("turn")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Angle_obj,deg,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Angle_obj,grad,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Angle_obj,rad,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Angle_obj,turn,return)

int Angle_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("deg")) return 1;
	if (inName==HX_CSTRING("grad")) return 1;
	if (inName==HX_CSTRING("rad")) return 1;
	if (inName==HX_CSTRING("turn")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Angle_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("deg")) return deg_dyn();
	if (inName==HX_CSTRING("grad")) return grad_dyn();
	if (inName==HX_CSTRING("rad")) return rad_dyn();
	if (inName==HX_CSTRING("turn")) return turn_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("deg"),
	HX_CSTRING("grad"),
	HX_CSTRING("rad"),
	HX_CSTRING("turn"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class Angle_obj::__mClass;

Dynamic __Create_Angle_obj() { return new Angle_obj; }

void Angle_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.unit.Angle"), hx::TCanCast< Angle_obj >,sStaticFields,sMemberFields,
	&__Create_Angle_obj, &__Create,
	&super::__SGetClass(), &CreateAngle_obj, sMarkStatics);
}

void Angle_obj::__boot()
{
}


} // end namespace core
} // end namespace unit
