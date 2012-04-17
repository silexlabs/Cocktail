#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_TextIndent
#include <cocktail/core/style/TextIndent.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::TextIndent  TextIndent_obj::length(::cocktail::core::unit::Length value)
	{ return hx::CreateEnum< TextIndent_obj >(HX_CSTRING("length"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::style::TextIndent  TextIndent_obj::percentage(int value)
	{ return hx::CreateEnum< TextIndent_obj >(HX_CSTRING("percentage"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(TextIndent_obj)

int TextIndent_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("length")) return 0;
	if (inName==HX_CSTRING("percentage")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextIndent_obj,length,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextIndent_obj,percentage,return)

int TextIndent_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("length")) return 1;
	if (inName==HX_CSTRING("percentage")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic TextIndent_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("length")) return length_dyn();
	if (inName==HX_CSTRING("percentage")) return percentage_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("length"),
	HX_CSTRING("percentage"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextIndent_obj::__mClass;

Dynamic __Create_TextIndent_obj() { return new TextIndent_obj; }

void TextIndent_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.TextIndent"), hx::TCanCast< TextIndent_obj >,sStaticFields,sMemberFields,
	&__Create_TextIndent_obj, &__Create,
	&super::__SGetClass(), &CreateTextIndent_obj, sMarkStatics);
}

void TextIndent_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
