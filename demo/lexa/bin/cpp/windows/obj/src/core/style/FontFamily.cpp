#include <hxcpp.h>

#ifndef INCLUDED_core_style_FontFamily
#include <core/style/FontFamily.h>
#endif
#ifndef INCLUDED_core_style_GenericFontFamily
#include <core/style/GenericFontFamily.h>
#endif
namespace core{
namespace style{

::core::style::FontFamily  FontFamily_obj::familyName(::String name)
	{ return hx::CreateEnum< FontFamily_obj >(HX_CSTRING("familyName"),0,hx::DynamicArray(0,1).Add(name)); }

::core::style::FontFamily  FontFamily_obj::genericFamily(::core::style::GenericFontFamily genericName)
	{ return hx::CreateEnum< FontFamily_obj >(HX_CSTRING("genericFamily"),1,hx::DynamicArray(0,1).Add(genericName)); }

HX_DEFINE_CREATE_ENUM(FontFamily_obj)

int FontFamily_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("familyName")) return 0;
	if (inName==HX_CSTRING("genericFamily")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontFamily_obj,familyName,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontFamily_obj,genericFamily,return)

int FontFamily_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("familyName")) return 1;
	if (inName==HX_CSTRING("genericFamily")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic FontFamily_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("familyName")) return familyName_dyn();
	if (inName==HX_CSTRING("genericFamily")) return genericFamily_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("familyName"),
	HX_CSTRING("genericFamily"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontFamily_obj::__mClass;

Dynamic __Create_FontFamily_obj() { return new FontFamily_obj; }

void FontFamily_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.FontFamily"), hx::TCanCast< FontFamily_obj >,sStaticFields,sMemberFields,
	&__Create_FontFamily_obj, &__Create,
	&super::__SGetClass(), &CreateFontFamily_obj, sMarkStatics);
}

void FontFamily_obj::__boot()
{
}


} // end namespace core
} // end namespace style
