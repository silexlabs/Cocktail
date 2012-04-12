#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_TransformOriginY
#include <cocktail/core/style/TransformOriginY.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::TransformOriginY TransformOriginY_obj::bottom;

::cocktail::core::style::TransformOriginY TransformOriginY_obj::center;

::cocktail::core::style::TransformOriginY  TransformOriginY_obj::length(::cocktail::core::unit::Length value)
	{ return hx::CreateEnum< TransformOriginY_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::TransformOriginY  TransformOriginY_obj::percent(int value)
	{ return hx::CreateEnum< TransformOriginY_obj >(HX_CSTRING("percent"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::TransformOriginY TransformOriginY_obj::top;

HX_DEFINE_CREATE_ENUM(TransformOriginY_obj)

int TransformOriginY_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bottom")) return 4;
	if (inName==HX_CSTRING("center")) return 3;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("top")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformOriginY_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformOriginY_obj,percent,return)

int TransformOriginY_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bottom")) return 0;
	if (inName==HX_CSTRING("center")) return 0;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percent")) return 1;
	if (inName==HX_CSTRING("top")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TransformOriginY_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(TransformOriginY_obj::bottom,"bottom");
	HX_MARK_MEMBER_NAME(TransformOriginY_obj::center,"center");
	HX_MARK_MEMBER_NAME(TransformOriginY_obj::top,"top");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TransformOriginY_obj::__mClass;

Dynamic __Create_TransformOriginY_obj() { return new TransformOriginY_obj; }

void TransformOriginY_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.TransformOriginY"), hx::TCanCast< TransformOriginY_obj >,sStaticFields,sMemberFields,
	&__Create_TransformOriginY_obj, &__Create,
	&super::__SGetClass(), &CreateTransformOriginY_obj, sMarkStatics);
}

void TransformOriginY_obj::__boot()
{
Static(bottom) = hx::CreateEnum< TransformOriginY_obj >(HX_CSTRING("bottom"),4);
Static(center) = hx::CreateEnum< TransformOriginY_obj >(HX_CSTRING("center"),3);
Static(top) = hx::CreateEnum< TransformOriginY_obj >(HX_CSTRING("top"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
