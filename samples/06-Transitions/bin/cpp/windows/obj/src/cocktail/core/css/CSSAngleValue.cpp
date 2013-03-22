#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#include <cocktail/core/css/CSSAngleValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSAngleValue  CSSAngleValue_obj::DEG(Float value)
	{ return hx::CreateEnum< CSSAngleValue_obj >(HX_CSTRING("DEG"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSAngleValue  CSSAngleValue_obj::GRAD(Float value)
	{ return hx::CreateEnum< CSSAngleValue_obj >(HX_CSTRING("GRAD"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSAngleValue  CSSAngleValue_obj::RAD(Float value)
	{ return hx::CreateEnum< CSSAngleValue_obj >(HX_CSTRING("RAD"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSAngleValue  CSSAngleValue_obj::TURN(Float value)
	{ return hx::CreateEnum< CSSAngleValue_obj >(HX_CSTRING("TURN"),3,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSAngleValue_obj)

int CSSAngleValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("DEG")) return 0;
	if (inName==HX_CSTRING("GRAD")) return 1;
	if (inName==HX_CSTRING("RAD")) return 2;
	if (inName==HX_CSTRING("TURN")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSAngleValue_obj,DEG,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSAngleValue_obj,GRAD,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSAngleValue_obj,RAD,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSAngleValue_obj,TURN,return)

int CSSAngleValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("DEG")) return 1;
	if (inName==HX_CSTRING("GRAD")) return 1;
	if (inName==HX_CSTRING("RAD")) return 1;
	if (inName==HX_CSTRING("TURN")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSAngleValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("DEG")) return DEG_dyn();
	if (inName==HX_CSTRING("GRAD")) return GRAD_dyn();
	if (inName==HX_CSTRING("RAD")) return RAD_dyn();
	if (inName==HX_CSTRING("TURN")) return TURN_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("DEG"),
	HX_CSTRING("GRAD"),
	HX_CSTRING("RAD"),
	HX_CSTRING("TURN"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSAngleValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSAngleValue_obj::__mClass;

Dynamic __Create_CSSAngleValue_obj() { return new CSSAngleValue_obj; }

void CSSAngleValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSAngleValue"), hx::TCanCast< CSSAngleValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSAngleValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSAngleValue_obj, sMarkStatics, sVisitStatic);
}

void CSSAngleValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
