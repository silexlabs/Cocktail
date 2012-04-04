#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_FontVariant
#include <cocktail/core/style/FontVariant.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::FontVariant FontVariant_obj::normal;

::cocktail::core::style::FontVariant FontVariant_obj::smallCaps;

HX_DEFINE_CREATE_ENUM(FontVariant_obj)

int FontVariant_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("normal")) return 0;
	if (inName==HX_CSTRING("smallCaps")) return 1;
	return super::__FindIndex(inName);
}

int FontVariant_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("normal")) return 0;
	if (inName==HX_CSTRING("smallCaps")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontVariant_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("normal")) return normal;
	if (inName==HX_CSTRING("smallCaps")) return smallCaps;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("smallCaps"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontVariant_obj::normal,"normal");
	HX_MARK_MEMBER_NAME(FontVariant_obj::smallCaps,"smallCaps");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontVariant_obj::__mClass;

Dynamic __Create_FontVariant_obj() { return new FontVariant_obj; }

void FontVariant_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.FontVariant"), hx::TCanCast< FontVariant_obj >,sStaticFields,sMemberFields,
	&__Create_FontVariant_obj, &__Create,
	&super::__SGetClass(), &CreateFontVariant_obj, sMarkStatics);
}

void FontVariant_obj::__boot()
{
Static(normal) = hx::CreateEnum< FontVariant_obj >(HX_CSTRING("normal"),0);
Static(smallCaps) = hx::CreateEnum< FontVariant_obj >(HX_CSTRING("smallCaps"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
