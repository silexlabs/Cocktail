#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_FontSize
#include <cocktail/core/style/FontSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize
#include <cocktail/core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeRelativeSize
#include <cocktail/core/unit/FontSizeRelativeSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::FontSize  FontSize_obj::absoluteSize(::cocktail::core::unit::FontSizeAbsoluteSize value)
	{ return hx::CreateEnum< FontSize_obj >(HX_CSTRING("absoluteSize"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::FontSize  FontSize_obj::length(::cocktail::core::unit::Length value)
	{ return hx::CreateEnum< FontSize_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::FontSize  FontSize_obj::percentage(int value)
	{ return hx::CreateEnum< FontSize_obj >(HX_CSTRING("percentage"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::FontSize  FontSize_obj::relativeSize(::cocktail::core::unit::FontSizeRelativeSize value)
	{ return hx::CreateEnum< FontSize_obj >(HX_CSTRING("relativeSize"),3,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(FontSize_obj)

int FontSize_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("absoluteSize")) return 2;
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percentage")) return 1;
	if (inName==HX_CSTRING("relativeSize")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontSize_obj,absoluteSize,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontSize_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontSize_obj,percentage,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontSize_obj,relativeSize,return)

int FontSize_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("absoluteSize")) return 1;
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percentage")) return 1;
	if (inName==HX_CSTRING("relativeSize")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic FontSize_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("absoluteSize")) return absoluteSize_dyn();
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("percentage")) return percentage_dyn();
	if (inName==HX_CSTRING("relativeSize")) return relativeSize_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percentage"),
	HX_CSTRING("absoluteSize"),
	HX_CSTRING("relativeSize"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontSize_obj::__mClass;

Dynamic __Create_FontSize_obj() { return new FontSize_obj; }

void FontSize_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.FontSize"), hx::TCanCast< FontSize_obj >,sStaticFields,sMemberFields,
	&__Create_FontSize_obj, &__Create,
	&super::__SGetClass(), &CreateFontSize_obj, sMarkStatics);
}

void FontSize_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
