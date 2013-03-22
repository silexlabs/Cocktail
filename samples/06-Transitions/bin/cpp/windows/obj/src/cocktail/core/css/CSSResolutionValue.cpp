#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSResolutionValue
#include <cocktail/core/css/CSSResolutionValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSResolutionValue  CSSResolutionValue_obj::DPCM(Float value)
	{ return hx::CreateEnum< CSSResolutionValue_obj >(HX_CSTRING("DPCM"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSResolutionValue  CSSResolutionValue_obj::DPI(Float value)
	{ return hx::CreateEnum< CSSResolutionValue_obj >(HX_CSTRING("DPI"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSResolutionValue  CSSResolutionValue_obj::DPPX(Float value)
	{ return hx::CreateEnum< CSSResolutionValue_obj >(HX_CSTRING("DPPX"),2,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSResolutionValue_obj)

int CSSResolutionValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("DPCM")) return 1;
	if (inName==HX_CSTRING("DPI")) return 0;
	if (inName==HX_CSTRING("DPPX")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSResolutionValue_obj,DPCM,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSResolutionValue_obj,DPI,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSResolutionValue_obj,DPPX,return)

int CSSResolutionValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("DPCM")) return 1;
	if (inName==HX_CSTRING("DPI")) return 1;
	if (inName==HX_CSTRING("DPPX")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSResolutionValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("DPCM")) return DPCM_dyn();
	if (inName==HX_CSTRING("DPI")) return DPI_dyn();
	if (inName==HX_CSTRING("DPPX")) return DPPX_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("DPI"),
	HX_CSTRING("DPCM"),
	HX_CSTRING("DPPX"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSResolutionValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSResolutionValue_obj::__mClass;

Dynamic __Create_CSSResolutionValue_obj() { return new CSSResolutionValue_obj; }

void CSSResolutionValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSResolutionValue"), hx::TCanCast< CSSResolutionValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSResolutionValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSResolutionValue_obj, sMarkStatics, sVisitStatic);
}

void CSSResolutionValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
