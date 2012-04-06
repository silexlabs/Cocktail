#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_BackgroundOrigin
#include <cocktail/core/style/BackgroundOrigin.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::BackgroundOrigin BackgroundOrigin_obj::borderBox;

::cocktail::core::style::BackgroundOrigin BackgroundOrigin_obj::contentBox;

::cocktail::core::style::BackgroundOrigin BackgroundOrigin_obj::paddingBox;

HX_DEFINE_CREATE_ENUM(BackgroundOrigin_obj)

int BackgroundOrigin_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("borderBox")) return 0;
	if (inName==HX_CSTRING("contentBox")) return 2;
	if (inName==HX_CSTRING("paddingBox")) return 1;
	return super::__FindIndex(inName);
}

int BackgroundOrigin_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("borderBox")) return 0;
	if (inName==HX_CSTRING("contentBox")) return 0;
	if (inName==HX_CSTRING("paddingBox")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundOrigin_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("borderBox")) return borderBox;
	if (inName==HX_CSTRING("contentBox")) return contentBox;
	if (inName==HX_CSTRING("paddingBox")) return paddingBox;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("borderBox"),
	HX_CSTRING("paddingBox"),
	HX_CSTRING("contentBox"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundOrigin_obj::borderBox,"borderBox");
	HX_MARK_MEMBER_NAME(BackgroundOrigin_obj::contentBox,"contentBox");
	HX_MARK_MEMBER_NAME(BackgroundOrigin_obj::paddingBox,"paddingBox");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundOrigin_obj::__mClass;

Dynamic __Create_BackgroundOrigin_obj() { return new BackgroundOrigin_obj; }

void BackgroundOrigin_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.BackgroundOrigin"), hx::TCanCast< BackgroundOrigin_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundOrigin_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundOrigin_obj, sMarkStatics);
}

void BackgroundOrigin_obj::__boot()
{
Static(borderBox) = hx::CreateEnum< BackgroundOrigin_obj >(HX_CSTRING("borderBox"),0);
Static(contentBox) = hx::CreateEnum< BackgroundOrigin_obj >(HX_CSTRING("contentBox"),2);
Static(paddingBox) = hx::CreateEnum< BackgroundOrigin_obj >(HX_CSTRING("paddingBox"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
