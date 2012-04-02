#include <hxcpp.h>

#ifndef INCLUDED_core_style_GenericFontFamily
#include <core/style/GenericFontFamily.h>
#endif
namespace core{
namespace style{

::core::style::GenericFontFamily GenericFontFamily_obj::monospace;

::core::style::GenericFontFamily GenericFontFamily_obj::sansSerif;

::core::style::GenericFontFamily GenericFontFamily_obj::serif;

HX_DEFINE_CREATE_ENUM(GenericFontFamily_obj)

int GenericFontFamily_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("monospace")) return 2;
	if (inName==HX_CSTRING("sansSerif")) return 1;
	if (inName==HX_CSTRING("serif")) return 0;
	return super::__FindIndex(inName);
}

int GenericFontFamily_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("monospace")) return 0;
	if (inName==HX_CSTRING("sansSerif")) return 0;
	if (inName==HX_CSTRING("serif")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GenericFontFamily_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("monospace")) return monospace;
	if (inName==HX_CSTRING("sansSerif")) return sansSerif;
	if (inName==HX_CSTRING("serif")) return serif;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("serif"),
	HX_CSTRING("sansSerif"),
	HX_CSTRING("monospace"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GenericFontFamily_obj::monospace,"monospace");
	HX_MARK_MEMBER_NAME(GenericFontFamily_obj::sansSerif,"sansSerif");
	HX_MARK_MEMBER_NAME(GenericFontFamily_obj::serif,"serif");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GenericFontFamily_obj::__mClass;

Dynamic __Create_GenericFontFamily_obj() { return new GenericFontFamily_obj; }

void GenericFontFamily_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.GenericFontFamily"), hx::TCanCast< GenericFontFamily_obj >,sStaticFields,sMemberFields,
	&__Create_GenericFontFamily_obj, &__Create,
	&super::__SGetClass(), &CreateGenericFontFamily_obj, sMarkStatics);
}

void GenericFontFamily_obj::__boot()
{
Static(monospace) = hx::CreateEnum< GenericFontFamily_obj >(HX_CSTRING("monospace"),2);
Static(sansSerif) = hx::CreateEnum< GenericFontFamily_obj >(HX_CSTRING("sansSerif"),1);
Static(serif) = hx::CreateEnum< GenericFontFamily_obj >(HX_CSTRING("serif"),0);
}


} // end namespace core
} // end namespace style
