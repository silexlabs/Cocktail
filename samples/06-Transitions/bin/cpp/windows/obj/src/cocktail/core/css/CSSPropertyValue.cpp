#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#include <cocktail/core/css/CSSAngleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSFrequencyValue
#include <cocktail/core/css/CSSFrequencyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSResolutionValue
#include <cocktail/core/css/CSSResolutionValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTimeValue
#include <cocktail/core/css/CSSTimeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTransformFunctionValue
#include <cocktail/core/css/CSSTransformFunctionValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::ABSOLUTE_LENGTH(Float value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("ABSOLUTE_LENGTH"),18,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::ANGLE(::cocktail::core::css::CSSAngleValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("ANGLE"),8,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("COLOR"),12,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::CSS_LIST(Array< ::cocktail::core::css::CSSPropertyValue > value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("CSS_LIST"),15,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::CUBIC_BEZIER(Float x1,Float y1,Float x2,Float y2)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("CUBIC_BEZIER"),20,hx::DynamicArray(0,4).Add(x1).Add(y1).Add(x2).Add(y2)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::FONT_SIZE_LINE_HEIGHT_GROUP(::cocktail::core::css::CSSPropertyValue fontSize,::cocktail::core::css::CSSPropertyValue lineHeight)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("FONT_SIZE_LINE_HEIGHT_GROUP"),14,hx::DynamicArray(0,2).Add(fontSize).Add(lineHeight)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::FREQUENCY(::cocktail::core::css::CSSFrequencyValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("FREQUENCY"),10,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::GROUP(Array< ::cocktail::core::css::CSSPropertyValue > value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("GROUP"),13,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::IDENTIFIER(::String value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("IDENTIFIER"),3,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue CSSPropertyValue_obj::INHERIT;

::cocktail::core::css::CSSPropertyValue CSSPropertyValue_obj::INITIAL;

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::INTEGER(int value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("INTEGER"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("KEYWORD"),4,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("LENGTH"),7,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::NUMBER(Float value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("NUMBER"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::PERCENTAGE(Float value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("PERCENTAGE"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::RESOLUTION(::cocktail::core::css::CSSResolutionValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("RESOLUTION"),11,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::STEPS(int intervalNumbers,::cocktail::core::css::CSSKeywordValue intervalChange)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("STEPS"),19,hx::DynamicArray(0,2).Add(intervalNumbers).Add(intervalChange)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::STRING(::String value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("STRING"),6,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("TIME"),9,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::TRANSFORM_FUNCTION(::cocktail::core::css::CSSTransformFunctionValue value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("TRANSFORM_FUNCTION"),21,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::CSSPropertyValue  CSSPropertyValue_obj::URL(::String value)
	{ return hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("URL"),5,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(CSSPropertyValue_obj)

int CSSPropertyValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ABSOLUTE_LENGTH")) return 18;
	if (inName==HX_CSTRING("ANGLE")) return 8;
	if (inName==HX_CSTRING("COLOR")) return 12;
	if (inName==HX_CSTRING("CSS_LIST")) return 15;
	if (inName==HX_CSTRING("CUBIC_BEZIER")) return 20;
	if (inName==HX_CSTRING("FONT_SIZE_LINE_HEIGHT_GROUP")) return 14;
	if (inName==HX_CSTRING("FREQUENCY")) return 10;
	if (inName==HX_CSTRING("GROUP")) return 13;
	if (inName==HX_CSTRING("IDENTIFIER")) return 3;
	if (inName==HX_CSTRING("INHERIT")) return 16;
	if (inName==HX_CSTRING("INITIAL")) return 17;
	if (inName==HX_CSTRING("INTEGER")) return 0;
	if (inName==HX_CSTRING("KEYWORD")) return 4;
	if (inName==HX_CSTRING("LENGTH")) return 7;
	if (inName==HX_CSTRING("NUMBER")) return 1;
	if (inName==HX_CSTRING("PERCENTAGE")) return 2;
	if (inName==HX_CSTRING("RESOLUTION")) return 11;
	if (inName==HX_CSTRING("STEPS")) return 19;
	if (inName==HX_CSTRING("STRING")) return 6;
	if (inName==HX_CSTRING("TIME")) return 9;
	if (inName==HX_CSTRING("TRANSFORM_FUNCTION")) return 21;
	if (inName==HX_CSTRING("URL")) return 5;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,ABSOLUTE_LENGTH,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,ANGLE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,COLOR,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,CSS_LIST,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSPropertyValue_obj,CUBIC_BEZIER,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSPropertyValue_obj,FONT_SIZE_LINE_HEIGHT_GROUP,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,FREQUENCY,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,GROUP,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,IDENTIFIER,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,INTEGER,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,KEYWORD,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,LENGTH,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,NUMBER,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,PERCENTAGE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,RESOLUTION,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSPropertyValue_obj,STEPS,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,STRING,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,TIME,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,TRANSFORM_FUNCTION,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSPropertyValue_obj,URL,return)

int CSSPropertyValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ABSOLUTE_LENGTH")) return 1;
	if (inName==HX_CSTRING("ANGLE")) return 1;
	if (inName==HX_CSTRING("COLOR")) return 1;
	if (inName==HX_CSTRING("CSS_LIST")) return 1;
	if (inName==HX_CSTRING("CUBIC_BEZIER")) return 4;
	if (inName==HX_CSTRING("FONT_SIZE_LINE_HEIGHT_GROUP")) return 2;
	if (inName==HX_CSTRING("FREQUENCY")) return 1;
	if (inName==HX_CSTRING("GROUP")) return 1;
	if (inName==HX_CSTRING("IDENTIFIER")) return 1;
	if (inName==HX_CSTRING("INHERIT")) return 0;
	if (inName==HX_CSTRING("INITIAL")) return 0;
	if (inName==HX_CSTRING("INTEGER")) return 1;
	if (inName==HX_CSTRING("KEYWORD")) return 1;
	if (inName==HX_CSTRING("LENGTH")) return 1;
	if (inName==HX_CSTRING("NUMBER")) return 1;
	if (inName==HX_CSTRING("PERCENTAGE")) return 1;
	if (inName==HX_CSTRING("RESOLUTION")) return 1;
	if (inName==HX_CSTRING("STEPS")) return 2;
	if (inName==HX_CSTRING("STRING")) return 1;
	if (inName==HX_CSTRING("TIME")) return 1;
	if (inName==HX_CSTRING("TRANSFORM_FUNCTION")) return 1;
	if (inName==HX_CSTRING("URL")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic CSSPropertyValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ABSOLUTE_LENGTH")) return ABSOLUTE_LENGTH_dyn();
	if (inName==HX_CSTRING("ANGLE")) return ANGLE_dyn();
	if (inName==HX_CSTRING("COLOR")) return COLOR_dyn();
	if (inName==HX_CSTRING("CSS_LIST")) return CSS_LIST_dyn();
	if (inName==HX_CSTRING("CUBIC_BEZIER")) return CUBIC_BEZIER_dyn();
	if (inName==HX_CSTRING("FONT_SIZE_LINE_HEIGHT_GROUP")) return FONT_SIZE_LINE_HEIGHT_GROUP_dyn();
	if (inName==HX_CSTRING("FREQUENCY")) return FREQUENCY_dyn();
	if (inName==HX_CSTRING("GROUP")) return GROUP_dyn();
	if (inName==HX_CSTRING("IDENTIFIER")) return IDENTIFIER_dyn();
	if (inName==HX_CSTRING("INHERIT")) return INHERIT;
	if (inName==HX_CSTRING("INITIAL")) return INITIAL;
	if (inName==HX_CSTRING("INTEGER")) return INTEGER_dyn();
	if (inName==HX_CSTRING("KEYWORD")) return KEYWORD_dyn();
	if (inName==HX_CSTRING("LENGTH")) return LENGTH_dyn();
	if (inName==HX_CSTRING("NUMBER")) return NUMBER_dyn();
	if (inName==HX_CSTRING("PERCENTAGE")) return PERCENTAGE_dyn();
	if (inName==HX_CSTRING("RESOLUTION")) return RESOLUTION_dyn();
	if (inName==HX_CSTRING("STEPS")) return STEPS_dyn();
	if (inName==HX_CSTRING("STRING")) return STRING_dyn();
	if (inName==HX_CSTRING("TIME")) return TIME_dyn();
	if (inName==HX_CSTRING("TRANSFORM_FUNCTION")) return TRANSFORM_FUNCTION_dyn();
	if (inName==HX_CSTRING("URL")) return URL_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("INTEGER"),
	HX_CSTRING("NUMBER"),
	HX_CSTRING("PERCENTAGE"),
	HX_CSTRING("IDENTIFIER"),
	HX_CSTRING("KEYWORD"),
	HX_CSTRING("URL"),
	HX_CSTRING("STRING"),
	HX_CSTRING("LENGTH"),
	HX_CSTRING("ANGLE"),
	HX_CSTRING("TIME"),
	HX_CSTRING("FREQUENCY"),
	HX_CSTRING("RESOLUTION"),
	HX_CSTRING("COLOR"),
	HX_CSTRING("GROUP"),
	HX_CSTRING("FONT_SIZE_LINE_HEIGHT_GROUP"),
	HX_CSTRING("CSS_LIST"),
	HX_CSTRING("INHERIT"),
	HX_CSTRING("INITIAL"),
	HX_CSTRING("ABSOLUTE_LENGTH"),
	HX_CSTRING("STEPS"),
	HX_CSTRING("CUBIC_BEZIER"),
	HX_CSTRING("TRANSFORM_FUNCTION"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSPropertyValue_obj::INHERIT,"INHERIT");
	HX_MARK_MEMBER_NAME(CSSPropertyValue_obj::INITIAL,"INITIAL");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSPropertyValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CSSPropertyValue_obj::INHERIT,"INHERIT");
	HX_VISIT_MEMBER_NAME(CSSPropertyValue_obj::INITIAL,"INITIAL");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CSSPropertyValue_obj::__mClass;

Dynamic __Create_CSSPropertyValue_obj() { return new CSSPropertyValue_obj; }

void CSSPropertyValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSPropertyValue"), hx::TCanCast< CSSPropertyValue_obj >,sStaticFields,sMemberFields,
	&__Create_CSSPropertyValue_obj, &__Create,
	&super::__SGetClass(), &CreateCSSPropertyValue_obj, sMarkStatics, sVisitStatic);
}

void CSSPropertyValue_obj::__boot()
{
Static(INHERIT) = hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("INHERIT"),16);
Static(INITIAL) = hx::CreateEnum< CSSPropertyValue_obj >(HX_CSTRING("INITIAL"),17);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
