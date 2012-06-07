#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_FontSizeRelativeSize
#include <cocktail/core/unit/FontSizeRelativeSize.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::FontSizeRelativeSize FontSizeRelativeSize_obj::larger;

::cocktail::core::unit::FontSizeRelativeSize FontSizeRelativeSize_obj::smaller;

HX_DEFINE_CREATE_ENUM(FontSizeRelativeSize_obj)

int FontSizeRelativeSize_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("larger")) return 0;
	if (inName==HX_CSTRING("smaller")) return 1;
	return super::__FindIndex(inName);
}

int FontSizeRelativeSize_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("larger")) return 0;
	if (inName==HX_CSTRING("smaller")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontSizeRelativeSize_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("larger")) return larger;
	if (inName==HX_CSTRING("smaller")) return smaller;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("larger"),
	HX_CSTRING("smaller"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontSizeRelativeSize_obj::larger,"larger");
	HX_MARK_MEMBER_NAME(FontSizeRelativeSize_obj::smaller,"smaller");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontSizeRelativeSize_obj::__mClass;

Dynamic __Create_FontSizeRelativeSize_obj() { return new FontSizeRelativeSize_obj; }

void FontSizeRelativeSize_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.FontSizeRelativeSize"), hx::TCanCast< FontSizeRelativeSize_obj >,sStaticFields,sMemberFields,
	&__Create_FontSizeRelativeSize_obj, &__Create,
	&super::__SGetClass(), &CreateFontSizeRelativeSize_obj, sMarkStatics);
}

void FontSizeRelativeSize_obj::__boot()
{
Static(larger) = hx::CreateEnum< FontSizeRelativeSize_obj >(HX_CSTRING("larger"),0);
Static(smaller) = hx::CreateEnum< FontSizeRelativeSize_obj >(HX_CSTRING("smaller"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit
