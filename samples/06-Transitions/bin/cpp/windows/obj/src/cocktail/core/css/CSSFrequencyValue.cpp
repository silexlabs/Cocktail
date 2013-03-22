#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSFrequencyValue
#include <cocktail/core/css/CSSFrequencyValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSFrequencyValue  CSSFrequencyValue_obj::HERTZ(Float value)
	{ return hx::CreateEnum< CSSFrequencyValue_obj >(HX_CSTRING("HERTZ"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSFrequencyValue  CSSFrequencyValue_obj::KILO_HERTZ(Float value)
	{ return hx::CreateEnum< CSSFrequencyValue_obj >(HX_CSTRING("KILO_HERTZ"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSFrequencyValue_obj)

int CSSFrequencyValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("HERTZ")) return 0;
	if (inName==HX_CSTRING("KILO_HERTZ")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSFrequencyValue_obj,HERTZ,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSFrequencyValue_obj,KILO_HERTZ,return)

int CSSFrequencyValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("HERTZ")) return 1;
	if (inName==HX_CSTRING("KILO_HERTZ")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSFrequencyValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("HERTZ")) return HERTZ_dyn();
	if (inName==HX_CSTRING("KILO_HERTZ")) return KILO_HERTZ_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("HERTZ"),
	HX_CSTRING("KILO_HERTZ"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSFrequencyValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSFrequencyValue_obj::__mClass;

Dynamic __Create_CSSFrequencyValue_obj() { return new CSSFrequencyValue_obj; }

void CSSFrequencyValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSFrequencyValue"), hx::TCanCast< CSSFrequencyValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSFrequencyValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSFrequencyValue_obj, sMarkStatics, sVisitStatic);
}

void CSSFrequencyValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
