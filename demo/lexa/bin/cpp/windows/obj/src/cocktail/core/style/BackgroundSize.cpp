#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#include <cocktail/core/style/BackgroundSize.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::BackgroundSize BackgroundSize_obj::contain;

::cocktail::core::style::BackgroundSize BackgroundSize_obj::cover;

::cocktail::core::style::BackgroundSize  BackgroundSize_obj::dimensions(Dynamic value)
	{ return hx::CreateEnum< BackgroundSize_obj >(HX_CSTRING("dimensions"),2,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(BackgroundSize_obj)

int BackgroundSize_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("contain")) return 0;
	if (inName==HX_CSTRING("cover")) return 1;
	if (inName==HX_CSTRING("dimensions")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundSize_obj,dimensions,return)

int BackgroundSize_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("contain")) return 0;
	if (inName==HX_CSTRING("cover")) return 0;
	if (inName==HX_CSTRING("dimensions")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundSize_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("contain")) return contain;
	if (inName==HX_CSTRING("cover")) return cover;
	if (inName==HX_CSTRING("dimensions")) return dimensions_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("contain"),
	HX_CSTRING("cover"),
	HX_CSTRING("dimensions"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundSize_obj::contain,"contain");
	HX_MARK_MEMBER_NAME(BackgroundSize_obj::cover,"cover");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundSize_obj::__mClass;

Dynamic __Create_BackgroundSize_obj() { return new BackgroundSize_obj; }

void BackgroundSize_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.BackgroundSize"), hx::TCanCast< BackgroundSize_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundSize_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundSize_obj, sMarkStatics);
}

void BackgroundSize_obj::__boot()
{
Static(contain) = hx::CreateEnum< BackgroundSize_obj >(HX_CSTRING("contain"),0);
Static(cover) = hx::CreateEnum< BackgroundSize_obj >(HX_CSTRING("cover"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
