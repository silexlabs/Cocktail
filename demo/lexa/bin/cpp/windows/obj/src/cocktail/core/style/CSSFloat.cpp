#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_CSSFloat
#include <cocktail/core/style/CSSFloat.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::CSSFloat CSSFloat_obj::left;

::cocktail::core::style::CSSFloat CSSFloat_obj::none;

::cocktail::core::style::CSSFloat CSSFloat_obj::right;

HX_DEFINE_CREATE_ENUM(CSSFloat_obj)

int CSSFloat_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("none")) return 2;
	if (inName==HX_CSTRING("right")) return 1;
	return super::__FindIndex(inName);
}

int CSSFloat_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("right")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CSSFloat_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("left")) return left;
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("right")) return right;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("left"),
	HX_CSTRING("right"),
	HX_CSTRING("none"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSFloat_obj::left,"left");
	HX_MARK_MEMBER_NAME(CSSFloat_obj::none,"none");
	HX_MARK_MEMBER_NAME(CSSFloat_obj::right,"right");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSFloat_obj::__mClass;

Dynamic __Create_CSSFloat_obj() { return new CSSFloat_obj; }

void CSSFloat_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.CSSFloat"), hx::TCanCast< CSSFloat_obj >,sStaticFields,sMemberFields,
	&__Create_CSSFloat_obj, &__Create,
	&super::__SGetClass(), &CreateCSSFloat_obj, sMarkStatics);
}

void CSSFloat_obj::__boot()
{
Static(left) = hx::CreateEnum< CSSFloat_obj >(HX_CSTRING("left"),0);
Static(none) = hx::CreateEnum< CSSFloat_obj >(HX_CSTRING("none"),2);
Static(right) = hx::CreateEnum< CSSFloat_obj >(HX_CSTRING("right"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
