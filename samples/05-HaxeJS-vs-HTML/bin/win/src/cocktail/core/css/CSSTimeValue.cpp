#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSTimeValue
#include <cocktail/core/css/CSSTimeValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSTimeValue  CSSTimeValue_obj::MILLISECONDS(Float value)
	{ return hx::CreateEnum< CSSTimeValue_obj >(HX_CSTRING("MILLISECONDS"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSTimeValue  CSSTimeValue_obj::SECONDS(Float value)
	{ return hx::CreateEnum< CSSTimeValue_obj >(HX_CSTRING("SECONDS"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSTimeValue_obj)

int CSSTimeValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("MILLISECONDS")) return 1;
	if (inName==HX_CSTRING("SECONDS")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTimeValue_obj,MILLISECONDS,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTimeValue_obj,SECONDS,return)

int CSSTimeValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("MILLISECONDS")) return 1;
	if (inName==HX_CSTRING("SECONDS")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSTimeValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("MILLISECONDS")) return MILLISECONDS_dyn();
	if (inName==HX_CSTRING("SECONDS")) return SECONDS_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("SECONDS"),
	HX_CSTRING("MILLISECONDS"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSTimeValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSTimeValue_obj::__mClass;

Dynamic __Create_CSSTimeValue_obj() { return new CSSTimeValue_obj; }

void CSSTimeValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSTimeValue"), hx::TCanCast< CSSTimeValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSTimeValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSTimeValue_obj, sMarkStatics, sVisitStatic);
}

void CSSTimeValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
