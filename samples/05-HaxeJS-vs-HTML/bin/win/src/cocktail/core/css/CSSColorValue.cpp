#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSColorKeyword
#include <cocktail/core/css/CSSColorKeyword.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSColorValue CSSColorValue_obj::CURRENT_COLOR;

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::HEX(::String value)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("HEX"),4,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::HSL(Float hue,Float saturation,Float lightness)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("HSL"),5,hx::DynamicArray(0,3).Add(hue).Add(saturation).Add(lightness)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::HSLA(Float hue,Float saturation,Float lightness,Float alpha)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("HSLA"),6,hx::DynamicArray(0,4).Add(hue).Add(saturation).Add(lightness).Add(alpha)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword value)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("KEYWORD"),7,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::RGB(int red,int green,int blue)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("RGB"),0,hx::DynamicArray(0,3).Add(red).Add(green).Add(blue)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::RGBA(int red,int green,int blue,Float alpha)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("RGBA"),2,hx::DynamicArray(0,4).Add(red).Add(green).Add(blue).Add(alpha)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::RGBA_PERCENTAGE(Float red,Float green,Float blue,Float alpha)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("RGBA_PERCENTAGE"),3,hx::DynamicArray(0,4).Add(red).Add(green).Add(blue).Add(alpha)); }

::cocktail::core::css::CSSColorValue  CSSColorValue_obj::RGB_PERCENTAGE(Float red,Float green,Float blue)
	{ return hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("RGB_PERCENTAGE"),1,hx::DynamicArray(0,3).Add(red).Add(green).Add(blue)); }

::cocktail::core::css::CSSColorValue CSSColorValue_obj::TRANSPARENT;

HX_DEFINE_CREATE_ENUM(CSSColorValue_obj)

int CSSColorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CURRENT_COLOR")) return 9;
	if (inName==HX_CSTRING("HEX")) return 4;
	if (inName==HX_CSTRING("HSL")) return 5;
	if (inName==HX_CSTRING("HSLA")) return 6;
	if (inName==HX_CSTRING("KEYWORD")) return 7;
	if (inName==HX_CSTRING("RGB")) return 0;
	if (inName==HX_CSTRING("RGBA")) return 2;
	if (inName==HX_CSTRING("RGBA_PERCENTAGE")) return 3;
	if (inName==HX_CSTRING("RGB_PERCENTAGE")) return 1;
	if (inName==HX_CSTRING("TRANSPARENT")) return 8;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSColorValue_obj,HEX,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSColorValue_obj,HSL,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSColorValue_obj,HSLA,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSColorValue_obj,KEYWORD,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSColorValue_obj,RGB,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSColorValue_obj,RGBA,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSColorValue_obj,RGBA_PERCENTAGE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSColorValue_obj,RGB_PERCENTAGE,return)

int CSSColorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CURRENT_COLOR")) return 0;
	if (inName==HX_CSTRING("HEX")) return 1;
	if (inName==HX_CSTRING("HSL")) return 3;
	if (inName==HX_CSTRING("HSLA")) return 4;
	if (inName==HX_CSTRING("KEYWORD")) return 1;
	if (inName==HX_CSTRING("RGB")) return 3;
	if (inName==HX_CSTRING("RGBA")) return 4;
	if (inName==HX_CSTRING("RGBA_PERCENTAGE")) return 4;
	if (inName==HX_CSTRING("RGB_PERCENTAGE")) return 3;
	if (inName==HX_CSTRING("TRANSPARENT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CSSColorValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CURRENT_COLOR")) return CURRENT_COLOR;
	if (inName==HX_CSTRING("HEX")) return HEX_dyn();
	if (inName==HX_CSTRING("HSL")) return HSL_dyn();
	if (inName==HX_CSTRING("HSLA")) return HSLA_dyn();
	if (inName==HX_CSTRING("KEYWORD")) return KEYWORD_dyn();
	if (inName==HX_CSTRING("RGB")) return RGB_dyn();
	if (inName==HX_CSTRING("RGBA")) return RGBA_dyn();
	if (inName==HX_CSTRING("RGBA_PERCENTAGE")) return RGBA_PERCENTAGE_dyn();
	if (inName==HX_CSTRING("RGB_PERCENTAGE")) return RGB_PERCENTAGE_dyn();
	if (inName==HX_CSTRING("TRANSPARENT")) return TRANSPARENT;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("RGB"),
	HX_CSTRING("RGB_PERCENTAGE"),
	HX_CSTRING("RGBA"),
	HX_CSTRING("RGBA_PERCENTAGE"),
	HX_CSTRING("HEX"),
	HX_CSTRING("HSL"),
	HX_CSTRING("HSLA"),
	HX_CSTRING("KEYWORD"),
	HX_CSTRING("TRANSPARENT"),
	HX_CSTRING("CURRENT_COLOR"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSColorValue_obj::CURRENT_COLOR,"CURRENT_COLOR");
	HX_MARK_MEMBER_NAME(CSSColorValue_obj::TRANSPARENT,"TRANSPARENT");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSColorValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CSSColorValue_obj::CURRENT_COLOR,"CURRENT_COLOR");
	HX_VISIT_MEMBER_NAME(CSSColorValue_obj::TRANSPARENT,"TRANSPARENT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSColorValue_obj::__mClass;

Dynamic __Create_CSSColorValue_obj() { return new CSSColorValue_obj; }

void CSSColorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSColorValue"), hx::TCanCast< CSSColorValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSColorValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSColorValue_obj, sMarkStatics, sVisitStatic);
}

void CSSColorValue_obj::__boot()
{
Static(CURRENT_COLOR) = hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("CURRENT_COLOR"),9);
Static(TRANSPARENT) = hx::CreateEnum< CSSColorValue_obj >(HX_CSTRING("TRANSPARENT"),8);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
