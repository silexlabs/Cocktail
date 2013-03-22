#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#include <cocktail/core/css/CSSAngleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTransformFunctionValue
#include <cocktail/core/css/CSSTransformFunctionValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTranslationValue
#include <cocktail/core/css/CSSTranslationValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::MATRIX(Float a,Float b,Float c,Float d,Float e,Float f)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("MATRIX"),0,hx::DynamicArray(0,6).Add(a).Add(b).Add(c).Add(d).Add(e).Add(f)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::ROTATE(::cocktail::core::css::CSSAngleValue angle)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("ROTATE"),7,hx::DynamicArray(0,1).Add(angle)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::SCALE(Float sx,Float sy)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("SCALE"),4,hx::DynamicArray(0,2).Add(sx).Add(sy)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::SCALE_X(Float sx)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("SCALE_X"),5,hx::DynamicArray(0,1).Add(sx)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::SCALE_Y(Float sy)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("SCALE_Y"),6,hx::DynamicArray(0,1).Add(sy)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::SKEW(::cocktail::core::css::CSSAngleValue angleX,::cocktail::core::css::CSSAngleValue angleY)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("SKEW"),10,hx::DynamicArray(0,2).Add(angleX).Add(angleY)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::SKEW_X(::cocktail::core::css::CSSAngleValue angle)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("SKEW_X"),8,hx::DynamicArray(0,1).Add(angle)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::SKEW_Y(::cocktail::core::css::CSSAngleValue angle)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("SKEW_Y"),9,hx::DynamicArray(0,1).Add(angle)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::TRANSLATE(::cocktail::core::css::CSSTranslationValue tx,::cocktail::core::css::CSSTranslationValue ty)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("TRANSLATE"),1,hx::DynamicArray(0,2).Add(tx).Add(ty)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::TRANSLATE_X(::cocktail::core::css::CSSTranslationValue tx)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("TRANSLATE_X"),2,hx::DynamicArray(0,1).Add(tx)); }

::cocktail::core::css::CSSTransformFunctionValue  CSSTransformFunctionValue_obj::TRANSLATE_Y(::cocktail::core::css::CSSTranslationValue ty)
	{ return hx::CreateEnum< CSSTransformFunctionValue_obj >(HX_CSTRING("TRANSLATE_Y"),3,hx::DynamicArray(0,1).Add(ty)); }

HX_DEFINE_CREATE_ENUM(CSSTransformFunctionValue_obj)

int CSSTransformFunctionValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("MATRIX")) return 0;
	if (inName==HX_CSTRING("ROTATE")) return 7;
	if (inName==HX_CSTRING("SCALE")) return 4;
	if (inName==HX_CSTRING("SCALE_X")) return 5;
	if (inName==HX_CSTRING("SCALE_Y")) return 6;
	if (inName==HX_CSTRING("SKEW")) return 10;
	if (inName==HX_CSTRING("SKEW_X")) return 8;
	if (inName==HX_CSTRING("SKEW_Y")) return 9;
	if (inName==HX_CSTRING("TRANSLATE")) return 1;
	if (inName==HX_CSTRING("TRANSLATE_X")) return 2;
	if (inName==HX_CSTRING("TRANSLATE_Y")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC6(CSSTransformFunctionValue_obj,MATRIX,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,ROTATE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSTransformFunctionValue_obj,SCALE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,SCALE_X,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,SCALE_Y,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSTransformFunctionValue_obj,SKEW,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,SKEW_X,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,SKEW_Y,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSTransformFunctionValue_obj,TRANSLATE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,TRANSLATE_X,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSTransformFunctionValue_obj,TRANSLATE_Y,return)

int CSSTransformFunctionValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("MATRIX")) return 6;
	if (inName==HX_CSTRING("ROTATE")) return 1;
	if (inName==HX_CSTRING("SCALE")) return 2;
	if (inName==HX_CSTRING("SCALE_X")) return 1;
	if (inName==HX_CSTRING("SCALE_Y")) return 1;
	if (inName==HX_CSTRING("SKEW")) return 2;
	if (inName==HX_CSTRING("SKEW_X")) return 1;
	if (inName==HX_CSTRING("SKEW_Y")) return 1;
	if (inName==HX_CSTRING("TRANSLATE")) return 2;
	if (inName==HX_CSTRING("TRANSLATE_X")) return 1;
	if (inName==HX_CSTRING("TRANSLATE_Y")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSTransformFunctionValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("MATRIX")) return MATRIX_dyn();
	if (inName==HX_CSTRING("ROTATE")) return ROTATE_dyn();
	if (inName==HX_CSTRING("SCALE")) return SCALE_dyn();
	if (inName==HX_CSTRING("SCALE_X")) return SCALE_X_dyn();
	if (inName==HX_CSTRING("SCALE_Y")) return SCALE_Y_dyn();
	if (inName==HX_CSTRING("SKEW")) return SKEW_dyn();
	if (inName==HX_CSTRING("SKEW_X")) return SKEW_X_dyn();
	if (inName==HX_CSTRING("SKEW_Y")) return SKEW_Y_dyn();
	if (inName==HX_CSTRING("TRANSLATE")) return TRANSLATE_dyn();
	if (inName==HX_CSTRING("TRANSLATE_X")) return TRANSLATE_X_dyn();
	if (inName==HX_CSTRING("TRANSLATE_Y")) return TRANSLATE_Y_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("MATRIX"),
	HX_CSTRING("TRANSLATE"),
	HX_CSTRING("TRANSLATE_X"),
	HX_CSTRING("TRANSLATE_Y"),
	HX_CSTRING("SCALE"),
	HX_CSTRING("SCALE_X"),
	HX_CSTRING("SCALE_Y"),
	HX_CSTRING("ROTATE"),
	HX_CSTRING("SKEW_X"),
	HX_CSTRING("SKEW_Y"),
	HX_CSTRING("SKEW"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSTransformFunctionValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSTransformFunctionValue_obj::__mClass;

Dynamic __Create_CSSTransformFunctionValue_obj() { return new CSSTransformFunctionValue_obj; }

void CSSTransformFunctionValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSTransformFunctionValue"), hx::TCanCast< CSSTransformFunctionValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSTransformFunctionValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSTransformFunctionValue_obj, sMarkStatics, sVisitStatic);
}

void CSSTransformFunctionValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
