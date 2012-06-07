#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_Position
#include <cocktail/core/style/Position.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::Position Position_obj::absolute;

::cocktail::core::style::Position Position_obj::cssStatic;

::cocktail::core::style::Position Position_obj::fixed;

::cocktail::core::style::Position Position_obj::relative;

HX_DEFINE_CREATE_ENUM(Position_obj)

int Position_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("absolute")) return 2;
	if (inName==HX_CSTRING("cssStatic")) return 0;
	if (inName==HX_CSTRING("fixed")) return 3;
	if (inName==HX_CSTRING("relative")) return 1;
	return super::__FindIndex(inName);
}

int Position_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("absolute")) return 0;
	if (inName==HX_CSTRING("cssStatic")) return 0;
	if (inName==HX_CSTRING("fixed")) return 0;
	if (inName==HX_CSTRING("relative")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Position_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("absolute")) return absolute;
	if (inName==HX_CSTRING("cssStatic")) return cssStatic;
	if (inName==HX_CSTRING("fixed")) return fixed;
	if (inName==HX_CSTRING("relative")) return relative;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("cssStatic"),
	HX_CSTRING("relative"),
	HX_CSTRING("absolute"),
	HX_CSTRING("fixed"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Position_obj::absolute,"absolute");
	HX_MARK_MEMBER_NAME(Position_obj::cssStatic,"cssStatic");
	HX_MARK_MEMBER_NAME(Position_obj::fixed,"fixed");
	HX_MARK_MEMBER_NAME(Position_obj::relative,"relative");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Position_obj::__mClass;

Dynamic __Create_Position_obj() { return new Position_obj; }

void Position_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.Position"), hx::TCanCast< Position_obj >,sStaticFields,sMemberFields,
	&__Create_Position_obj, &__Create,
	&super::__SGetClass(), &CreatePosition_obj, sMarkStatics);
}

void Position_obj::__boot()
{
Static(absolute) = hx::CreateEnum< Position_obj >(HX_CSTRING("absolute"),2);
Static(cssStatic) = hx::CreateEnum< Position_obj >(HX_CSTRING("cssStatic"),0);
Static(fixed) = hx::CreateEnum< Position_obj >(HX_CSTRING("fixed"),3);
Static(relative) = hx::CreateEnum< Position_obj >(HX_CSTRING("relative"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
