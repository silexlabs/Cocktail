#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_GradientValue
#include <cocktail/core/unit/GradientValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_ImageValue
#include <cocktail/core/unit/ImageValue.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::ImageValue  ImageValue_obj::gradient(::cocktail::core::unit::GradientValue value)
	{ return hx::CreateEnum< ImageValue_obj >(HX_CSTRING("gradient"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::ImageValue  ImageValue_obj::imageList(Dynamic value)
	{ return hx::CreateEnum< ImageValue_obj >(HX_CSTRING("imageList"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::ImageValue  ImageValue_obj::url(::String value)
	{ return hx::CreateEnum< ImageValue_obj >(HX_CSTRING("url"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(ImageValue_obj)

int ImageValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("gradient")) return 2;
	if (inName==HX_CSTRING("imageList")) return 1;
	if (inName==HX_CSTRING("url")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ImageValue_obj,gradient,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ImageValue_obj,imageList,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ImageValue_obj,url,return)

int ImageValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("gradient")) return 1;
	if (inName==HX_CSTRING("imageList")) return 1;
	if (inName==HX_CSTRING("url")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic ImageValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("gradient")) return gradient_dyn();
	if (inName==HX_CSTRING("imageList")) return imageList_dyn();
	if (inName==HX_CSTRING("url")) return url_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("imageList"),
	HX_CSTRING("gradient"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class ImageValue_obj::__mClass;

Dynamic __Create_ImageValue_obj() { return new ImageValue_obj; }

void ImageValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.ImageValue"), hx::TCanCast< ImageValue_obj >,sStaticFields,sMemberFields,
	&__Create_ImageValue_obj, &__Create,
	&super::__SGetClass(), &CreateImageValue_obj, sMarkStatics);
}

void ImageValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit
