#include <hxcpp.h>

#ifndef INCLUDED_core_unit_GradientCornerValue
#include <core/unit/GradientCornerValue.h>
#endif
namespace core{
namespace unit{

::core::unit::GradientCornerValue GradientCornerValue_obj::bottomLeft;

::core::unit::GradientCornerValue GradientCornerValue_obj::bottomRight;

::core::unit::GradientCornerValue GradientCornerValue_obj::topLeft;

::core::unit::GradientCornerValue GradientCornerValue_obj::topRight;

HX_DEFINE_CREATE_ENUM(GradientCornerValue_obj)

int GradientCornerValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bottomLeft")) return 2;
	if (inName==HX_CSTRING("bottomRight")) return 1;
	if (inName==HX_CSTRING("topLeft")) return 3;
	if (inName==HX_CSTRING("topRight")) return 0;
	return super::__FindIndex(inName);
}

int GradientCornerValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bottomLeft")) return 0;
	if (inName==HX_CSTRING("bottomRight")) return 0;
	if (inName==HX_CSTRING("topLeft")) return 0;
	if (inName==HX_CSTRING("topRight")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GradientCornerValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("bottomLeft")) return bottomLeft;
	if (inName==HX_CSTRING("bottomRight")) return bottomRight;
	if (inName==HX_CSTRING("topLeft")) return topLeft;
	if (inName==HX_CSTRING("topRight")) return topRight;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("topRight"),
	HX_CSTRING("bottomRight"),
	HX_CSTRING("bottomLeft"),
	HX_CSTRING("topLeft"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GradientCornerValue_obj::bottomLeft,"bottomLeft");
	HX_MARK_MEMBER_NAME(GradientCornerValue_obj::bottomRight,"bottomRight");
	HX_MARK_MEMBER_NAME(GradientCornerValue_obj::topLeft,"topLeft");
	HX_MARK_MEMBER_NAME(GradientCornerValue_obj::topRight,"topRight");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientCornerValue_obj::__mClass;

Dynamic __Create_GradientCornerValue_obj() { return new GradientCornerValue_obj; }

void GradientCornerValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.unit.GradientCornerValue"), hx::TCanCast< GradientCornerValue_obj >,sStaticFields,sMemberFields,
	&__Create_GradientCornerValue_obj, &__Create,
	&super::__SGetClass(), &CreateGradientCornerValue_obj, sMarkStatics);
}

void GradientCornerValue_obj::__boot()
{
Static(bottomLeft) = hx::CreateEnum< GradientCornerValue_obj >(HX_CSTRING("bottomLeft"),2);
Static(bottomRight) = hx::CreateEnum< GradientCornerValue_obj >(HX_CSTRING("bottomRight"),1);
Static(topLeft) = hx::CreateEnum< GradientCornerValue_obj >(HX_CSTRING("topLeft"),3);
Static(topRight) = hx::CreateEnum< GradientCornerValue_obj >(HX_CSTRING("topRight"),0);
}


} // end namespace core
} // end namespace unit
