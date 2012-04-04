#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_TextAlign
#include <cocktail/core/style/TextAlign.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::TextAlign TextAlign_obj::center;

::cocktail::core::style::TextAlign TextAlign_obj::justify;

::cocktail::core::style::TextAlign TextAlign_obj::left;

::cocktail::core::style::TextAlign TextAlign_obj::right;

HX_DEFINE_CREATE_ENUM(TextAlign_obj)

int TextAlign_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("center")) return 2;
	if (inName==HX_CSTRING("justify")) return 3;
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("right")) return 1;
	return super::__FindIndex(inName);
}

int TextAlign_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("center")) return 0;
	if (inName==HX_CSTRING("justify")) return 0;
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("right")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TextAlign_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("center")) return center;
	if (inName==HX_CSTRING("justify")) return justify;
	if (inName==HX_CSTRING("left")) return left;
	if (inName==HX_CSTRING("right")) return right;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("left"),
	HX_CSTRING("right"),
	HX_CSTRING("center"),
	HX_CSTRING("justify"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextAlign_obj::center,"center");
	HX_MARK_MEMBER_NAME(TextAlign_obj::justify,"justify");
	HX_MARK_MEMBER_NAME(TextAlign_obj::left,"left");
	HX_MARK_MEMBER_NAME(TextAlign_obj::right,"right");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextAlign_obj::__mClass;

Dynamic __Create_TextAlign_obj() { return new TextAlign_obj; }

void TextAlign_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.TextAlign"), hx::TCanCast< TextAlign_obj >,sStaticFields,sMemberFields,
	&__Create_TextAlign_obj, &__Create,
	&super::__SGetClass(), &CreateTextAlign_obj, sMarkStatics);
}

void TextAlign_obj::__boot()
{
Static(center) = hx::CreateEnum< TextAlign_obj >(HX_CSTRING("center"),2);
Static(justify) = hx::CreateEnum< TextAlign_obj >(HX_CSTRING("justify"),3);
Static(left) = hx::CreateEnum< TextAlign_obj >(HX_CSTRING("left"),0);
Static(right) = hx::CreateEnum< TextAlign_obj >(HX_CSTRING("right"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
