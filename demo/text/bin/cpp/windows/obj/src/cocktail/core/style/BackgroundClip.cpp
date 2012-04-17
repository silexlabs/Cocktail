#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_BackgroundClip
#include <cocktail/core/style/BackgroundClip.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::BackgroundClip BackgroundClip_obj::borderBox;

::cocktail::core::style::BackgroundClip BackgroundClip_obj::contentBox;

::cocktail::core::style::BackgroundClip BackgroundClip_obj::paddingBox;

HX_DEFINE_CREATE_ENUM(BackgroundClip_obj)

int BackgroundClip_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("borderBox")) return 0;
	if (inName==HX_CSTRING("contentBox")) return 2;
	if (inName==HX_CSTRING("paddingBox")) return 1;
	return super::__FindIndex(inName);
}

int BackgroundClip_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("borderBox")) return 0;
	if (inName==HX_CSTRING("contentBox")) return 0;
	if (inName==HX_CSTRING("paddingBox")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundClip_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(BackgroundClip_obj::borderBox,"borderBox");
	HX_MARK_MEMBER_NAME(BackgroundClip_obj::contentBox,"contentBox");
	HX_MARK_MEMBER_NAME(BackgroundClip_obj::paddingBox,"paddingBox");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundClip_obj::__mClass;

Dynamic __Create_BackgroundClip_obj() { return new BackgroundClip_obj; }

void BackgroundClip_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.BackgroundClip"), hx::TCanCast< BackgroundClip_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundClip_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundClip_obj, sMarkStatics);
}

void BackgroundClip_obj::__boot()
{
Static(borderBox) = hx::CreateEnum< BackgroundClip_obj >(HX_CSTRING("borderBox"),0);
Static(contentBox) = hx::CreateEnum< BackgroundClip_obj >(HX_CSTRING("contentBox"),2);
Static(paddingBox) = hx::CreateEnum< BackgroundClip_obj >(HX_CSTRING("paddingBox"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
