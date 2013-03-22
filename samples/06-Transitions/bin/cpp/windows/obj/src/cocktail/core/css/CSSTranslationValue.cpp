#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTranslationValue
#include <cocktail/core/css/CSSTranslationValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSTranslationValue  CSSTranslationValue_obj::ABSOLUTE_LENGTH(Float value)
	{ return hx::CreateEnum< CSSTranslationValue_obj >(HX_CSTRING("ABSOLUTE_LENGTH"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSTranslationValue  CSSTranslationValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue value)
	{ return hx::CreateEnum< CSSTranslationValue_obj >(HX_CSTRING("LENGTH"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSTranslationValue  CSSTranslationValue_obj::PERCENTAGE(Float value)
	{ return hx::CreateEnum< CSSTranslationValue_obj >(HX_CSTRING("PERCENTAGE"),2,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSTranslationValue_obj)

int CSSTranslationValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ABSOLUTE_LENGTH")) return 0;
	if (inName==HX_CSTRING("LENGTH")) return 1;
	if (inName==HX_CSTRING("PERCENTAGE")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTranslationValue_obj,ABSOLUTE_LENGTH,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTranslationValue_obj,LENGTH,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTranslationValue_obj,PERCENTAGE,return)

int CSSTranslationValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ABSOLUTE_LENGTH")) return 1;
	if (inName==HX_CSTRING("LENGTH")) return 1;
	if (inName==HX_CSTRING("PERCENTAGE")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSTranslationValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ABSOLUTE_LENGTH")) return ABSOLUTE_LENGTH_dyn();
	if (inName==HX_CSTRING("LENGTH")) return LENGTH_dyn();
	if (inName==HX_CSTRING("PERCENTAGE")) return PERCENTAGE_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ABSOLUTE_LENGTH"),
	HX_CSTRING("LENGTH"),
	HX_CSTRING("PERCENTAGE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSTranslationValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSTranslationValue_obj::__mClass;

Dynamic __Create_CSSTranslationValue_obj() { return new CSSTranslationValue_obj; }

void CSSTranslationValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSTranslationValue"), hx::TCanCast< CSSTranslationValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSTranslationValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSTranslationValue_obj, sMarkStatics, sVisitStatic);
}

void CSSTranslationValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
