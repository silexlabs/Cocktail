#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::CM(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("CM"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::EM(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("EM"),6,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::EX(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("EX"),7,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::IN(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("IN"),5,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::MM(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("MM"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::PC(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("PC"),4,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::PT(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("PT"),3,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSLengthValue  CSSLengthValue_obj::PX(Float value)
	{ return hx::CreateEnum< CSSLengthValue_obj >(HX_CSTRING("PX"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSLengthValue_obj)

int CSSLengthValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CM")) return 1;
	if (inName==HX_CSTRING("EM")) return 6;
	if (inName==HX_CSTRING("EX")) return 7;
	if (inName==HX_CSTRING("IN")) return 5;
	if (inName==HX_CSTRING("MM")) return 2;
	if (inName==HX_CSTRING("PC")) return 4;
	if (inName==HX_CSTRING("PT")) return 3;
	if (inName==HX_CSTRING("PX")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,CM,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,EM,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,EX,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,IN,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,MM,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,PC,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,PT,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSLengthValue_obj,PX,return)

int CSSLengthValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CM")) return 1;
	if (inName==HX_CSTRING("EM")) return 1;
	if (inName==HX_CSTRING("EX")) return 1;
	if (inName==HX_CSTRING("IN")) return 1;
	if (inName==HX_CSTRING("MM")) return 1;
	if (inName==HX_CSTRING("PC")) return 1;
	if (inName==HX_CSTRING("PT")) return 1;
	if (inName==HX_CSTRING("PX")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSLengthValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CM")) return CM_dyn();
	if (inName==HX_CSTRING("EM")) return EM_dyn();
	if (inName==HX_CSTRING("EX")) return EX_dyn();
	if (inName==HX_CSTRING("IN")) return IN_dyn();
	if (inName==HX_CSTRING("MM")) return MM_dyn();
	if (inName==HX_CSTRING("PC")) return PC_dyn();
	if (inName==HX_CSTRING("PT")) return PT_dyn();
	if (inName==HX_CSTRING("PX")) return PX_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("PX"),
	HX_CSTRING("CM"),
	HX_CSTRING("MM"),
	HX_CSTRING("PT"),
	HX_CSTRING("PC"),
	HX_CSTRING("IN"),
	HX_CSTRING("EM"),
	HX_CSTRING("EX"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSLengthValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSLengthValue_obj::__mClass;

Dynamic __Create_CSSLengthValue_obj() { return new CSSLengthValue_obj; }

void CSSLengthValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSLengthValue"), hx::TCanCast< CSSLengthValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSLengthValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSLengthValue_obj, sMarkStatics, sVisitStatic);
}

void CSSLengthValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
