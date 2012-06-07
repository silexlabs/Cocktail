#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_ColorKeyword
#include <cocktail/core/unit/ColorKeyword.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::CSSColor  CSSColor_obj::hex(::String value)
	{ return hx::CreateEnum< CSSColor_obj >(HX_CSTRING("hex"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::CSSColor  CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword value)
	{ return hx::CreateEnum< CSSColor_obj >(HX_CSTRING("keyword"),3,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::CSSColor  CSSColor_obj::rgb(int red,int green,int blue)
	{ return hx::CreateEnum< CSSColor_obj >(HX_CSTRING("rgb"),0,hx::DynamicArray(0,3).Add(red).Add(green).Add(blue)); }

::cocktail::core::unit::CSSColor  CSSColor_obj::rgba(int red,int green,int blue,double alpha)
	{ return hx::CreateEnum< CSSColor_obj >(HX_CSTRING("rgba"),1,hx::DynamicArray(0,4).Add(red).Add(green).Add(blue).Add(alpha)); }

::cocktail::core::unit::CSSColor CSSColor_obj::transparent;

HX_DEFINE_CREATE_ENUM(CSSColor_obj)

int CSSColor_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("hex")) return 2;
	if (inName==HX_CSTRING("keyword")) return 3;
	if (inName==HX_CSTRING("rgb")) return 0;
	if (inName==HX_CSTRING("rgba")) return 1;
	if (inName==HX_CSTRING("transparent")) return 4;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSColor_obj,hex,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSColor_obj,keyword,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSColor_obj,rgb,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSColor_obj,rgba,return)

int CSSColor_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("hex")) return 1;
	if (inName==HX_CSTRING("keyword")) return 1;
	if (inName==HX_CSTRING("rgb")) return 3;
	if (inName==HX_CSTRING("rgba")) return 4;
	if (inName==HX_CSTRING("transparent")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CSSColor_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("hex")) return hex_dyn();
	if (inName==HX_CSTRING("keyword")) return keyword_dyn();
	if (inName==HX_CSTRING("rgb")) return rgb_dyn();
	if (inName==HX_CSTRING("rgba")) return rgba_dyn();
	if (inName==HX_CSTRING("transparent")) return transparent;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("rgb"),
	HX_CSTRING("rgba"),
	HX_CSTRING("hex"),
	HX_CSTRING("keyword"),
	HX_CSTRING("transparent"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSColor_obj::transparent,"transparent");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSColor_obj::__mClass;

Dynamic __Create_CSSColor_obj() { return new CSSColor_obj; }

void CSSColor_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.CSSColor"), hx::TCanCast< CSSColor_obj >,sStaticFields,sMemberFields,
	&__Create_CSSColor_obj, &__Create,
	&super::__SGetClass(), &CreateCSSColor_obj, sMarkStatics);
}

void CSSColor_obj::__boot()
{
Static(transparent) = hx::CreateEnum< CSSColor_obj >(HX_CSTRING("transparent"),4);
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit
