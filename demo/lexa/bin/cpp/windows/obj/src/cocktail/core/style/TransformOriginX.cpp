#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_TransformOriginX
#include <cocktail/core/style/TransformOriginX.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::TransformOriginX TransformOriginX_obj::center;

::cocktail::core::style::TransformOriginX TransformOriginX_obj::left;

::cocktail::core::style::TransformOriginX  TransformOriginX_obj::length(::cocktail::core::unit::Length value)
	{ return hx::CreateEnum< TransformOriginX_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::TransformOriginX  TransformOriginX_obj::percent(int value)
	{ return hx::CreateEnum< TransformOriginX_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::TransformOriginX TransformOriginX_obj::right;

HX_DEFINE_CREATE_ENUM(TransformOriginX_obj)

int TransformOriginX_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("center")) return 3;
	if (inName==HX_CSTRING("left")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("right")) return 4;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformOriginX_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformOriginX_obj,percent,return)

int TransformOriginX_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("center")) return 0;
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("right")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TransformOriginX_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(TransformOriginX_obj::center,"center");
	HX_MARK_MEMBER_NAME(TransformOriginX_obj::left,"left");
	HX_MARK_MEMBER_NAME(TransformOriginX_obj::right,"right");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TransformOriginX_obj::__mClass;

Dynamic __Create_TransformOriginX_obj() { return new TransformOriginX_obj; }

void TransformOriginX_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.TransformOriginX"), hx::TCanCast< TransformOriginX_obj >,sStaticFields,sMemberFields,
	&__Create_TransformOriginX_obj, &__Create,
	&super::__SGetClass(), &CreateTransformOriginX_obj, sMarkStatics);
}

void TransformOriginX_obj::__boot()
{
Static(center) = hx::CreateEnum< TransformOriginX_obj >(HX_CSTRING("center"),3);
Static(left) = hx::CreateEnum< TransformOriginX_obj >(HX_CSTRING("left"),2);
Static(right) = hx::CreateEnum< TransformOriginX_obj >(HX_CSTRING("right"),4);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
