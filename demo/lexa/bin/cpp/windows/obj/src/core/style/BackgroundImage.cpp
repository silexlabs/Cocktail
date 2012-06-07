#include <hxcpp.h>

#ifndef INCLUDED_core_style_BackgroundImage
#include <core/style/BackgroundImage.h>
#endif
#ifndef INCLUDED_core_unit_ImageValue
#include <core/unit/ImageValue.h>
#endif
namespace core{
namespace style{

::core::style::BackgroundImage  BackgroundImage_obj::image(::core::unit::ImageValue value)
	{ return hx::CreateEnum< BackgroundImage_obj >(HX_CSTRING("image"),1,hx::DynamicArray(0,1).Add(value)); }

::core::style::BackgroundImage BackgroundImage_obj::none;

HX_DEFINE_CREATE_ENUM(BackgroundImage_obj)

int BackgroundImage_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("image")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundImage_obj,image,return)

int BackgroundImage_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("image")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundImage_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("image")) return image_dyn();
	if (inName==HX_CSTRING("none")) return none;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("none"),
	HX_CSTRING("image"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundImage_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundImage_obj::__mClass;

Dynamic __Create_BackgroundImage_obj() { return new BackgroundImage_obj; }

void BackgroundImage_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.BackgroundImage"), hx::TCanCast< BackgroundImage_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundImage_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundImage_obj, sMarkStatics);
}

void BackgroundImage_obj::__boot()
{
Static(none) = hx::CreateEnum< BackgroundImage_obj >(HX_CSTRING("none"),0);
}


} // end namespace core
} // end namespace style
