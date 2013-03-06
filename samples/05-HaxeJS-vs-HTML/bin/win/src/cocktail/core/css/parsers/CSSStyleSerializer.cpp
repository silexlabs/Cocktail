#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#include <cocktail/core/css/CSSAngleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorKeyword
#include <cocktail/core/css/CSSColorKeyword.h>
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
#ifndef INCLUDED_cocktail_core_css_CSSTranslationValue
#include <cocktail/core/css/CSSTranslationValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSStyleSerializer
#include <cocktail/core/css/parsers/CSSStyleSerializer.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

Void CSSStyleSerializer_obj::__construct()
{
HX_STACK_PUSH("CSSStyleSerializer::new","cocktail/core/css/parsers/CSSStyleSerializer.hx",26);
{
}
;
	return null();
}

CSSStyleSerializer_obj::~CSSStyleSerializer_obj() { }

Dynamic CSSStyleSerializer_obj::__CreateEmpty() { return  new CSSStyleSerializer_obj; }
hx::ObjectPtr< CSSStyleSerializer_obj > CSSStyleSerializer_obj::__new()
{  hx::ObjectPtr< CSSStyleSerializer_obj > result = new CSSStyleSerializer_obj();
	result->__construct();
	return result;}

Dynamic CSSStyleSerializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSStyleSerializer_obj > result = new CSSStyleSerializer_obj();
	result->__construct();
	return result;}

::String CSSStyleSerializer_obj::serialize( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CSSStyleSerializer::serialize","cocktail/core/css/parsers/CSSStyleSerializer.hx",38);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(38)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (property);
		switch((_switch_1)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(41)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeKeyword(value);
				}
			}
			;break;
			case 3: {
				::String value = _switch_1->__Param(0);
{
					HX_STACK_LINE(44)
					return value;
				}
			}
			;break;
			case 6: {
				::String value = _switch_1->__Param(0);
{
					HX_STACK_LINE(47)
					return ((HX_CSTRING("\"") + value) + HX_CSTRING("\""));
				}
			}
			;break;
			case 5: {
				::String value = _switch_1->__Param(0);
{
					HX_STACK_LINE(51)
					return ((HX_CSTRING("url(") + value) + HX_CSTRING(")"));
				}
			}
			;break;
			case 16: {
				HX_STACK_LINE(54)
				return HX_CSTRING("inherit");
			}
			;break;
			case 17: {
				HX_STACK_LINE(57)
				return HX_CSTRING("initial");
			}
			;break;
			case 9: {
				::cocktail::core::css::CSSTimeValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(60)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeTime(value);
				}
			}
			;break;
			case 2: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(63)
					return (value + HX_CSTRING("%"));
				}
			}
			;break;
			case 8: {
				::cocktail::core::css::CSSAngleValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(66)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeAngle(value);
				}
			}
			;break;
			case 0: {
				int value = _switch_1->__Param(0);
{
					HX_STACK_LINE(69)
					return ::Std_obj::string(value);
				}
			}
			;break;
			case 1: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(72)
					return ::Std_obj::string(value);
				}
			}
			;break;
			case 18: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(75)
					return ::Std_obj::string(value);
				}
			}
			;break;
			case 19: {
				::cocktail::core::css::CSSKeywordValue intervalChange = _switch_1->__Param(1);
				int intervalNumber = _switch_1->__Param(0);
{
					HX_STACK_LINE(78)
					return ((((HX_CSTRING("steps(") + ::Std_obj::string(intervalNumber)) + HX_CSTRING(",")) + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeKeyword(intervalChange)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 20: {
				Float y2 = _switch_1->__Param(3);
				Float x2 = _switch_1->__Param(2);
				Float y1 = _switch_1->__Param(1);
				Float x1 = _switch_1->__Param(0);
{
					HX_STACK_LINE(81)
					return ((((((((HX_CSTRING("cubic-bezier(") + ::Std_obj::string(x1)) + HX_CSTRING(",")) + ::Std_obj::string(y1)) + HX_CSTRING(",")) + ::Std_obj::string(x2)) + HX_CSTRING(",")) + ::Std_obj::string(y2)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 10: {
				::cocktail::core::css::CSSFrequencyValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(84)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeFrequency(value);
				}
			}
			;break;
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(87)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeLength(value);
				}
			}
			;break;
			case 11: {
				::cocktail::core::css::CSSResolutionValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(90)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeResolution(value);
				}
			}
			;break;
			case 12: {
				::cocktail::core::css::CSSColorValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(93)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeColor(value);
				}
			}
			;break;
			case 21: {
				::cocktail::core::css::CSSTransformFunctionValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(96)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeTransformFunction(value);
				}
			}
			;break;
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_1->__Param(0);
{
					HX_STACK_LINE(99)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeGroup(value);
				}
			}
			;break;
			case 14: {
				::cocktail::core::css::CSSPropertyValue lineHeight = _switch_1->__Param(1);
				::cocktail::core::css::CSSPropertyValue fontSize = _switch_1->__Param(0);
{
					HX_STACK_LINE(102)
					return ((::cocktail::core::css::parsers::CSSStyleSerializer_obj::serialize(fontSize) + HX_CSTRING("/")) + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serialize(lineHeight));
				}
			}
			;break;
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_1->__Param(0);
{
					HX_STACK_LINE(105)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeList(value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(38)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serialize,return )

::String CSSStyleSerializer_obj::serializeList( Array< ::cocktail::core::css::CSSPropertyValue > list){
	HX_STACK_PUSH("CSSStyleSerializer::serializeList","cocktail/core/css/parsers/CSSStyleSerializer.hx",116);
	HX_STACK_ARG(list,"list");
	HX_STACK_LINE(117)
	::String serializedList = HX_CSTRING("");		HX_STACK_VAR(serializedList,"serializedList");
	HX_STACK_LINE(119)
	{
		HX_STACK_LINE(119)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = list->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(119)
		while(((_g1 < _g))){
			HX_STACK_LINE(119)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(121)
			hx::AddEq(serializedList,::cocktail::core::css::parsers::CSSStyleSerializer_obj::serialize(list->__get(i)));
			HX_STACK_LINE(123)
			if (((i < list->length))){
				HX_STACK_LINE(124)
				hx::AddEq(serializedList,HX_CSTRING(","));
			}
		}
	}
	HX_STACK_LINE(129)
	return serializedList;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeList,return )

::String CSSStyleSerializer_obj::serializeGroup( Array< ::cocktail::core::css::CSSPropertyValue > group){
	HX_STACK_PUSH("CSSStyleSerializer::serializeGroup","cocktail/core/css/parsers/CSSStyleSerializer.hx",133);
	HX_STACK_ARG(group,"group");
	HX_STACK_LINE(134)
	::String serializedGroup = HX_CSTRING("");		HX_STACK_VAR(serializedGroup,"serializedGroup");
	HX_STACK_LINE(136)
	{
		HX_STACK_LINE(136)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = group->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(136)
		while(((_g1 < _g))){
			HX_STACK_LINE(136)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(138)
			hx::AddEq(serializedGroup,::cocktail::core::css::parsers::CSSStyleSerializer_obj::serialize(group->__get(i)));
			HX_STACK_LINE(140)
			if (((i < group->length))){
				HX_STACK_LINE(141)
				hx::AddEq(serializedGroup,HX_CSTRING(" "));
			}
		}
	}
	HX_STACK_LINE(146)
	return serializedGroup;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeGroup,return )

::String CSSStyleSerializer_obj::serializeTransformFunction( ::cocktail::core::css::CSSTransformFunctionValue transformFunction){
	HX_STACK_PUSH("CSSStyleSerializer::serializeTransformFunction","cocktail/core/css/parsers/CSSStyleSerializer.hx",150);
	HX_STACK_ARG(transformFunction,"transformFunction");
	HX_STACK_LINE(150)
	{
		::cocktail::core::css::CSSTransformFunctionValue _switch_2 = (transformFunction);
		switch((_switch_2)->GetIndex()){
			case 0: {
				Float f = _switch_2->__Param(5);
				Float e = _switch_2->__Param(4);
				Float d = _switch_2->__Param(3);
				Float c = _switch_2->__Param(2);
				Float b = _switch_2->__Param(1);
				Float a = _switch_2->__Param(0);
{
					HX_STACK_LINE(153)
					return ((((((((((((HX_CSTRING("matrix(") + ::Std_obj::string(a)) + HX_CSTRING(",")) + ::Std_obj::string(b)) + HX_CSTRING(",")) + ::Std_obj::string(c)) + HX_CSTRING(",")) + ::Std_obj::string(d)) + HX_CSTRING(",")) + ::Std_obj::string(e)) + HX_CSTRING(",")) + ::Std_obj::string(f)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 1: {
				::cocktail::core::css::CSSTranslationValue ty = _switch_2->__Param(1);
				::cocktail::core::css::CSSTranslationValue tx = _switch_2->__Param(0);
{
					HX_STACK_LINE(156)
					return ((((HX_CSTRING("translate(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeTranslation(tx)) + HX_CSTRING(",")) + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeTranslation(ty)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 2: {
				::cocktail::core::css::CSSTranslationValue tx = _switch_2->__Param(0);
{
					HX_STACK_LINE(159)
					return ((HX_CSTRING("translateX(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeTranslation(tx)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 3: {
				::cocktail::core::css::CSSTranslationValue ty = _switch_2->__Param(0);
{
					HX_STACK_LINE(162)
					return ((HX_CSTRING("translateY(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeTranslation(ty)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 10: {
				::cocktail::core::css::CSSAngleValue angleY = _switch_2->__Param(1);
				::cocktail::core::css::CSSAngleValue angleX = _switch_2->__Param(0);
{
					HX_STACK_LINE(165)
					return ((((HX_CSTRING("skew(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeAngle(angleX)) + HX_CSTRING(",")) + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeAngle(angleY)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 8: {
				::cocktail::core::css::CSSAngleValue angleX = _switch_2->__Param(0);
{
					HX_STACK_LINE(168)
					return ((HX_CSTRING("skewX(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeAngle(angleX)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 9: {
				::cocktail::core::css::CSSAngleValue angleY = _switch_2->__Param(0);
{
					HX_STACK_LINE(171)
					return ((HX_CSTRING("skewY(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeAngle(angleY)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 7: {
				::cocktail::core::css::CSSAngleValue angle = _switch_2->__Param(0);
{
					HX_STACK_LINE(174)
					return ((HX_CSTRING("rotate(") + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeAngle(angle)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 4: {
				Float sy = _switch_2->__Param(1);
				Float sx = _switch_2->__Param(0);
{
					HX_STACK_LINE(177)
					return ((((HX_CSTRING("scale(") + ::Std_obj::string(sx)) + HX_CSTRING(",")) + ::Std_obj::string(sy)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 5: {
				Float sx = _switch_2->__Param(0);
{
					HX_STACK_LINE(180)
					return ((HX_CSTRING("scaleX(") + ::Std_obj::string(sx)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 6: {
				Float sy = _switch_2->__Param(0);
{
					HX_STACK_LINE(183)
					return ((HX_CSTRING("scaleY(") + ::Std_obj::string(sy)) + HX_CSTRING(")"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(150)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeTransformFunction,return )

::String CSSStyleSerializer_obj::serializeTranslation( ::cocktail::core::css::CSSTranslationValue translation){
	HX_STACK_PUSH("CSSStyleSerializer::serializeTranslation","cocktail/core/css/parsers/CSSStyleSerializer.hx",189);
	HX_STACK_ARG(translation,"translation");
	HX_STACK_LINE(189)
	{
		::cocktail::core::css::CSSTranslationValue _switch_3 = (translation);
		switch((_switch_3)->GetIndex()){
			case 1: {
				::cocktail::core::css::CSSLengthValue value = _switch_3->__Param(0);
{
					HX_STACK_LINE(192)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeLength(value);
				}
			}
			;break;
			case 2: {
				Float value = _switch_3->__Param(0);
{
					HX_STACK_LINE(195)
					return (value + HX_CSTRING("%"));
				}
			}
			;break;
			case 0: {
				Float value = _switch_3->__Param(0);
{
					HX_STACK_LINE(198)
					return ::Std_obj::string(value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(189)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeTranslation,return )

::String CSSStyleSerializer_obj::serializeColor( ::cocktail::core::css::CSSColorValue color){
	HX_STACK_PUSH("CSSStyleSerializer::serializeColor","cocktail/core/css/parsers/CSSStyleSerializer.hx",204);
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(204)
	{
		::cocktail::core::css::CSSColorValue _switch_4 = (color);
		switch((_switch_4)->GetIndex()){
			case 7: {
				::cocktail::core::css::CSSColorKeyword value = _switch_4->__Param(0);
{
					HX_STACK_LINE(207)
					return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serializeColorKeyword(value);
				}
			}
			;break;
			case 0: {
				int blue = _switch_4->__Param(2);
				int green = _switch_4->__Param(1);
				int red = _switch_4->__Param(0);
{
					HX_STACK_LINE(210)
					return ((((((HX_CSTRING("rgb(") + ::Std_obj::string(red)) + HX_CSTRING(",")) + ::Std_obj::string(green)) + HX_CSTRING(",")) + ::Std_obj::string(blue)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 1: {
				Float blue = _switch_4->__Param(2);
				Float green = _switch_4->__Param(1);
				Float red = _switch_4->__Param(0);
{
					HX_STACK_LINE(213)
					return ((((((HX_CSTRING("rgb(") + ::Std_obj::string(red)) + HX_CSTRING("%,")) + ::Std_obj::string(green)) + HX_CSTRING("%,")) + ::Std_obj::string(blue)) + HX_CSTRING("%)"));
				}
			}
			;break;
			case 2: {
				Float alpha = _switch_4->__Param(3);
				int blue = _switch_4->__Param(2);
				int green = _switch_4->__Param(1);
				int red = _switch_4->__Param(0);
{
					HX_STACK_LINE(216)
					return ((((((((HX_CSTRING("rgba(") + ::Std_obj::string(red)) + HX_CSTRING(",")) + ::Std_obj::string(green)) + HX_CSTRING(",")) + ::Std_obj::string(blue)) + HX_CSTRING(",")) + ::Std_obj::string(alpha)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 3: {
				Float alpha = _switch_4->__Param(3);
				Float blue = _switch_4->__Param(2);
				Float green = _switch_4->__Param(1);
				Float red = _switch_4->__Param(0);
{
					HX_STACK_LINE(219)
					return ((((((((HX_CSTRING("rgba(") + ::Std_obj::string(red)) + HX_CSTRING("%,")) + ::Std_obj::string(green)) + HX_CSTRING("%,")) + ::Std_obj::string(blue)) + HX_CSTRING("%,")) + ::Std_obj::string(alpha)) + HX_CSTRING("%)"));
				}
			}
			;break;
			case 8: {
				HX_STACK_LINE(222)
				return HX_CSTRING("transparent");
			}
			;break;
			case 5: {
				Float lightness = _switch_4->__Param(2);
				Float saturation = _switch_4->__Param(1);
				Float hue = _switch_4->__Param(0);
{
					HX_STACK_LINE(225)
					return ((((((HX_CSTRING("hsl(") + ::Std_obj::string(hue)) + HX_CSTRING(",")) + ::Std_obj::string(saturation)) + HX_CSTRING(",")) + ::Std_obj::string(lightness)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 6: {
				Float alpha = _switch_4->__Param(3);
				Float lightness = _switch_4->__Param(2);
				Float saturation = _switch_4->__Param(1);
				Float hue = _switch_4->__Param(0);
{
					HX_STACK_LINE(228)
					return ((((((((HX_CSTRING("hsl(") + ::Std_obj::string(hue)) + HX_CSTRING(",")) + ::Std_obj::string(saturation)) + HX_CSTRING(",")) + ::Std_obj::string(lightness)) + HX_CSTRING(",")) + ::Std_obj::string(alpha)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 4: {
				::String value = _switch_4->__Param(0);
{
					HX_STACK_LINE(231)
					return (HX_CSTRING("#") + value);
				}
			}
			;break;
			case 9: {
				HX_STACK_LINE(234)
				return HX_CSTRING("currentColor");
			}
			;break;
		}
	}
	HX_STACK_LINE(204)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeColor,return )

::String CSSStyleSerializer_obj::serializeColorKeyword( ::cocktail::core::css::CSSColorKeyword keyword){
	HX_STACK_PUSH("CSSStyleSerializer::serializeColorKeyword","cocktail/core/css/parsers/CSSStyleSerializer.hx",241);
	HX_STACK_ARG(keyword,"keyword");
	HX_STACK_LINE(241)
	{
		::cocktail::core::css::CSSColorKeyword _switch_5 = (keyword);
		switch((_switch_5)->GetIndex()){
			case 0: {
				HX_STACK_LINE(244)
				return HX_CSTRING("aliceblue");
			}
			;break;
			case 1: {
				HX_STACK_LINE(247)
				return HX_CSTRING("antiquewhite");
			}
			;break;
			case 2: {
				HX_STACK_LINE(250)
				return HX_CSTRING("aqua");
			}
			;break;
			case 3: {
				HX_STACK_LINE(253)
				return HX_CSTRING("aquamarine");
			}
			;break;
			case 4: {
				HX_STACK_LINE(256)
				return HX_CSTRING("azure");
			}
			;break;
			case 5: {
				HX_STACK_LINE(259)
				return HX_CSTRING("beige");
			}
			;break;
			case 6: {
				HX_STACK_LINE(262)
				return HX_CSTRING("bisque");
			}
			;break;
			case 9: {
				HX_STACK_LINE(265)
				return HX_CSTRING("blue");
			}
			;break;
			case 7: {
				HX_STACK_LINE(268)
				return HX_CSTRING("black");
			}
			;break;
			case 8: {
				HX_STACK_LINE(271)
				return HX_CSTRING("blanchedalmond");
			}
			;break;
			case 10: {
				HX_STACK_LINE(274)
				return HX_CSTRING("blueviolet");
			}
			;break;
			case 11: {
				HX_STACK_LINE(277)
				return HX_CSTRING("brown");
			}
			;break;
			case 12: {
				HX_STACK_LINE(280)
				return HX_CSTRING("burlywood");
			}
			;break;
			case 13: {
				HX_STACK_LINE(283)
				return HX_CSTRING("cadetblue");
			}
			;break;
			case 14: {
				HX_STACK_LINE(286)
				return HX_CSTRING("chartreuse");
			}
			;break;
			case 15: {
				HX_STACK_LINE(289)
				return HX_CSTRING("chocolate");
			}
			;break;
			case 16: {
				HX_STACK_LINE(292)
				return HX_CSTRING("coral");
			}
			;break;
			case 17: {
				HX_STACK_LINE(295)
				return HX_CSTRING("cornflowerblue");
			}
			;break;
			case 18: {
				HX_STACK_LINE(298)
				return HX_CSTRING("cornsilk");
			}
			;break;
			case 19: {
				HX_STACK_LINE(301)
				return HX_CSTRING("crimson");
			}
			;break;
			case 20: {
				HX_STACK_LINE(304)
				return HX_CSTRING("cyan");
			}
			;break;
			case 21: {
				HX_STACK_LINE(307)
				return HX_CSTRING("darkblue");
			}
			;break;
			case 22: {
				HX_STACK_LINE(310)
				return HX_CSTRING("darkcyan");
			}
			;break;
			case 23: {
				HX_STACK_LINE(313)
				return HX_CSTRING("darkgoldenrod");
			}
			;break;
			case 24: {
				HX_STACK_LINE(316)
				return HX_CSTRING("darkgray");
			}
			;break;
			case 25: {
				HX_STACK_LINE(319)
				return HX_CSTRING("darkgreen");
			}
			;break;
			case 26: {
				HX_STACK_LINE(322)
				return HX_CSTRING("darkgrey");
			}
			;break;
			case 27: {
				HX_STACK_LINE(325)
				return HX_CSTRING("darkkhaki");
			}
			;break;
			case 28: {
				HX_STACK_LINE(328)
				return HX_CSTRING("darkmagenta");
			}
			;break;
			case 29: {
				HX_STACK_LINE(331)
				return HX_CSTRING("darkolivegreen");
			}
			;break;
			case 30: {
				HX_STACK_LINE(334)
				return HX_CSTRING("darkorange");
			}
			;break;
			case 31: {
				HX_STACK_LINE(337)
				return HX_CSTRING("darkorchid");
			}
			;break;
			case 32: {
				HX_STACK_LINE(340)
				return HX_CSTRING("darkred");
			}
			;break;
			case 33: {
				HX_STACK_LINE(343)
				return HX_CSTRING("darksalmon");
			}
			;break;
			case 34: {
				HX_STACK_LINE(346)
				return HX_CSTRING("darkseagreen");
			}
			;break;
			case 35: {
				HX_STACK_LINE(349)
				return HX_CSTRING("darkslateblue");
			}
			;break;
			case 36: {
				HX_STACK_LINE(352)
				return HX_CSTRING("darkslategray");
			}
			;break;
			case 37: {
				HX_STACK_LINE(355)
				return HX_CSTRING("darkslategrey");
			}
			;break;
			case 38: {
				HX_STACK_LINE(358)
				return HX_CSTRING("darkturquoise");
			}
			;break;
			case 39: {
				HX_STACK_LINE(361)
				return HX_CSTRING("darkviolet");
			}
			;break;
			case 40: {
				HX_STACK_LINE(364)
				return HX_CSTRING("deeppink");
			}
			;break;
			case 41: {
				HX_STACK_LINE(367)
				return HX_CSTRING("deepskyblue");
			}
			;break;
			case 42: {
				HX_STACK_LINE(370)
				return HX_CSTRING("dimgray");
			}
			;break;
			case 43: {
				HX_STACK_LINE(373)
				return HX_CSTRING("dimgrey");
			}
			;break;
			case 44: {
				HX_STACK_LINE(376)
				return HX_CSTRING("dodgerblue");
			}
			;break;
			case 45: {
				HX_STACK_LINE(379)
				return HX_CSTRING("firebrick");
			}
			;break;
			case 46: {
				HX_STACK_LINE(382)
				return HX_CSTRING("floralwhite");
			}
			;break;
			case 47: {
				HX_STACK_LINE(385)
				return HX_CSTRING("forestgreen");
			}
			;break;
			case 48: {
				HX_STACK_LINE(388)
				return HX_CSTRING("fuchsia");
			}
			;break;
			case 49: {
				HX_STACK_LINE(391)
				return HX_CSTRING("gainsboro");
			}
			;break;
			case 50: {
				HX_STACK_LINE(394)
				return HX_CSTRING("ghostwhite");
			}
			;break;
			case 51: {
				HX_STACK_LINE(397)
				return HX_CSTRING("gold");
			}
			;break;
			case 52: {
				HX_STACK_LINE(400)
				return HX_CSTRING("goldenrod");
			}
			;break;
			case 53: {
				HX_STACK_LINE(403)
				return HX_CSTRING("gray");
			}
			;break;
			case 56: {
				HX_STACK_LINE(406)
				return HX_CSTRING("grey");
			}
			;break;
			case 55: {
				HX_STACK_LINE(409)
				return HX_CSTRING("greenyellow");
			}
			;break;
			case 57: {
				HX_STACK_LINE(412)
				return HX_CSTRING("honeydew");
			}
			;break;
			case 58: {
				HX_STACK_LINE(415)
				return HX_CSTRING("hotpink");
			}
			;break;
			case 60: {
				HX_STACK_LINE(418)
				return HX_CSTRING("indigo");
			}
			;break;
			case 61: {
				HX_STACK_LINE(421)
				return HX_CSTRING("ivory");
			}
			;break;
			case 59: {
				HX_STACK_LINE(424)
				return HX_CSTRING("indianred");
			}
			;break;
			case 62: {
				HX_STACK_LINE(427)
				return HX_CSTRING("khaki");
			}
			;break;
			case 63: {
				HX_STACK_LINE(430)
				return HX_CSTRING("lavender");
			}
			;break;
			case 64: {
				HX_STACK_LINE(433)
				return HX_CSTRING("lavenderblush");
			}
			;break;
			case 65: {
				HX_STACK_LINE(436)
				return HX_CSTRING("lawngreen");
			}
			;break;
			case 66: {
				HX_STACK_LINE(439)
				return HX_CSTRING("lemonchiffon");
			}
			;break;
			case 67: {
				HX_STACK_LINE(442)
				return HX_CSTRING("lightblue");
			}
			;break;
			case 68: {
				HX_STACK_LINE(445)
				return HX_CSTRING("lightcoral");
			}
			;break;
			case 69: {
				HX_STACK_LINE(448)
				return HX_CSTRING("lightcyan");
			}
			;break;
			case 70: {
				HX_STACK_LINE(451)
				return HX_CSTRING("lightgoldenrodyellow");
			}
			;break;
			case 71: {
				HX_STACK_LINE(454)
				return HX_CSTRING("lightgray");
			}
			;break;
			case 72: {
				HX_STACK_LINE(457)
				return HX_CSTRING("lightgreen");
			}
			;break;
			case 73: {
				HX_STACK_LINE(460)
				return HX_CSTRING("lightgrey");
			}
			;break;
			case 74: {
				HX_STACK_LINE(463)
				return HX_CSTRING("lightpink");
			}
			;break;
			case 75: {
				HX_STACK_LINE(466)
				return HX_CSTRING("lightsalmon");
			}
			;break;
			case 76: {
				HX_STACK_LINE(469)
				return HX_CSTRING("lightseagreen");
			}
			;break;
			case 77: {
				HX_STACK_LINE(472)
				return HX_CSTRING("lightskyblue");
			}
			;break;
			case 78: {
				HX_STACK_LINE(475)
				return HX_CSTRING("lightslategray");
			}
			;break;
			case 79: {
				HX_STACK_LINE(478)
				return HX_CSTRING("lightslategrey");
			}
			;break;
			case 80: {
				HX_STACK_LINE(481)
				return HX_CSTRING("lightsteelblue");
			}
			;break;
			case 81: {
				HX_STACK_LINE(484)
				return HX_CSTRING("lightyellow");
			}
			;break;
			case 82: {
				HX_STACK_LINE(487)
				return HX_CSTRING("lime");
			}
			;break;
			case 83: {
				HX_STACK_LINE(490)
				return HX_CSTRING("limegreen");
			}
			;break;
			case 84: {
				HX_STACK_LINE(493)
				return HX_CSTRING("linen");
			}
			;break;
			case 85: {
				HX_STACK_LINE(496)
				return HX_CSTRING("magenta");
			}
			;break;
			case 86: {
				HX_STACK_LINE(499)
				return HX_CSTRING("marron");
			}
			;break;
			case 87: {
				HX_STACK_LINE(502)
				return HX_CSTRING("mediumaquamarine");
			}
			;break;
			case 88: {
				HX_STACK_LINE(505)
				return HX_CSTRING("mediumblue");
			}
			;break;
			case 89: {
				HX_STACK_LINE(508)
				return HX_CSTRING("mediumorchid");
			}
			;break;
			case 90: {
				HX_STACK_LINE(511)
				return HX_CSTRING("mediumpurple");
			}
			;break;
			case 91: {
				HX_STACK_LINE(514)
				return HX_CSTRING("mediumseagreen");
			}
			;break;
			case 92: {
				HX_STACK_LINE(517)
				return HX_CSTRING("mediumslateblue");
			}
			;break;
			case 93: {
				HX_STACK_LINE(520)
				return HX_CSTRING("mediumspringgreen");
			}
			;break;
			case 94: {
				HX_STACK_LINE(523)
				return HX_CSTRING("mediumturquoise");
			}
			;break;
			case 95: {
				HX_STACK_LINE(526)
				return HX_CSTRING("mediumvioletred");
			}
			;break;
			case 96: {
				HX_STACK_LINE(529)
				return HX_CSTRING("midnightblue");
			}
			;break;
			case 97: {
				HX_STACK_LINE(532)
				return HX_CSTRING("mintcream");
			}
			;break;
			case 98: {
				HX_STACK_LINE(535)
				return HX_CSTRING("mistyrose");
			}
			;break;
			case 99: {
				HX_STACK_LINE(538)
				return HX_CSTRING("moccasin");
			}
			;break;
			case 100: {
				HX_STACK_LINE(541)
				return HX_CSTRING("navajowhite");
			}
			;break;
			case 102: {
				HX_STACK_LINE(544)
				return HX_CSTRING("oldlace");
			}
			;break;
			case 104: {
				HX_STACK_LINE(547)
				return HX_CSTRING("olivedrab");
			}
			;break;
			case 106: {
				HX_STACK_LINE(550)
				return HX_CSTRING("orangered");
			}
			;break;
			case 107: {
				HX_STACK_LINE(553)
				return HX_CSTRING("orchid");
			}
			;break;
			case 108: {
				HX_STACK_LINE(556)
				return HX_CSTRING("palegoldenrod");
			}
			;break;
			case 109: {
				HX_STACK_LINE(559)
				return HX_CSTRING("palegreen");
			}
			;break;
			case 110: {
				HX_STACK_LINE(562)
				return HX_CSTRING("paleturquoise");
			}
			;break;
			case 111: {
				HX_STACK_LINE(565)
				return HX_CSTRING("palevioletred");
			}
			;break;
			case 112: {
				HX_STACK_LINE(568)
				return HX_CSTRING("papayawhip");
			}
			;break;
			case 113: {
				HX_STACK_LINE(571)
				return HX_CSTRING("peachpuff");
			}
			;break;
			case 114: {
				HX_STACK_LINE(574)
				return HX_CSTRING("peru");
			}
			;break;
			case 115: {
				HX_STACK_LINE(577)
				return HX_CSTRING("pink");
			}
			;break;
			case 116: {
				HX_STACK_LINE(580)
				return HX_CSTRING("plum");
			}
			;break;
			case 117: {
				HX_STACK_LINE(583)
				return HX_CSTRING("powderblue");
			}
			;break;
			case 120: {
				HX_STACK_LINE(586)
				return HX_CSTRING("rosybrown");
			}
			;break;
			case 121: {
				HX_STACK_LINE(589)
				return HX_CSTRING("royalblue");
			}
			;break;
			case 122: {
				HX_STACK_LINE(592)
				return HX_CSTRING("saddlebrown");
			}
			;break;
			case 123: {
				HX_STACK_LINE(595)
				return HX_CSTRING("salmon");
			}
			;break;
			case 124: {
				HX_STACK_LINE(598)
				return HX_CSTRING("sandybrown");
			}
			;break;
			case 125: {
				HX_STACK_LINE(601)
				return HX_CSTRING("seagreen");
			}
			;break;
			case 126: {
				HX_STACK_LINE(604)
				return HX_CSTRING("seashell");
			}
			;break;
			case 127: {
				HX_STACK_LINE(607)
				return HX_CSTRING("sienna");
			}
			;break;
			case 128: {
				HX_STACK_LINE(610)
				return HX_CSTRING("silver");
			}
			;break;
			case 129: {
				HX_STACK_LINE(613)
				return HX_CSTRING("skyblue");
			}
			;break;
			case 130: {
				HX_STACK_LINE(616)
				return HX_CSTRING("slateblue");
			}
			;break;
			case 131: {
				HX_STACK_LINE(619)
				return HX_CSTRING("slategray");
			}
			;break;
			case 132: {
				HX_STACK_LINE(622)
				return HX_CSTRING("slategrey");
			}
			;break;
			case 133: {
				HX_STACK_LINE(625)
				return HX_CSTRING("snow");
			}
			;break;
			case 134: {
				HX_STACK_LINE(628)
				return HX_CSTRING("springgreen");
			}
			;break;
			case 135: {
				HX_STACK_LINE(631)
				return HX_CSTRING("steelblue");
			}
			;break;
			case 136: {
				HX_STACK_LINE(634)
				return HX_CSTRING("tan");
			}
			;break;
			case 138: {
				HX_STACK_LINE(637)
				return HX_CSTRING("thisle");
			}
			;break;
			case 139: {
				HX_STACK_LINE(640)
				return HX_CSTRING("tomato");
			}
			;break;
			case 140: {
				HX_STACK_LINE(643)
				return HX_CSTRING("turquoise");
			}
			;break;
			case 141: {
				HX_STACK_LINE(646)
				return HX_CSTRING("violet");
			}
			;break;
			case 142: {
				HX_STACK_LINE(649)
				return HX_CSTRING("wheat");
			}
			;break;
			case 143: {
				HX_STACK_LINE(652)
				return HX_CSTRING("white");
			}
			;break;
			case 144: {
				HX_STACK_LINE(655)
				return HX_CSTRING("whitesmoke");
			}
			;break;
			case 146: {
				HX_STACK_LINE(658)
				return HX_CSTRING("yellowgreen");
			}
			;break;
			case 119: {
				HX_STACK_LINE(661)
				return HX_CSTRING("red");
			}
			;break;
			case 118: {
				HX_STACK_LINE(664)
				return HX_CSTRING("purple");
			}
			;break;
			case 54: {
				HX_STACK_LINE(667)
				return HX_CSTRING("green");
			}
			;break;
			case 103: {
				HX_STACK_LINE(670)
				return HX_CSTRING("olive");
			}
			;break;
			case 145: {
				HX_STACK_LINE(673)
				return HX_CSTRING("yellow");
			}
			;break;
			case 101: {
				HX_STACK_LINE(676)
				return HX_CSTRING("navy");
			}
			;break;
			case 105: {
				HX_STACK_LINE(679)
				return HX_CSTRING("orange");
			}
			;break;
			case 137: {
				HX_STACK_LINE(682)
				return HX_CSTRING("teal");
			}
			;break;
		}
	}
	HX_STACK_LINE(241)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeColorKeyword,return )

::String CSSStyleSerializer_obj::serializeResolution( ::cocktail::core::css::CSSResolutionValue resolution){
	HX_STACK_PUSH("CSSStyleSerializer::serializeResolution","cocktail/core/css/parsers/CSSStyleSerializer.hx",688);
	HX_STACK_ARG(resolution,"resolution");
	HX_STACK_LINE(688)
	{
		::cocktail::core::css::CSSResolutionValue _switch_6 = (resolution);
		switch((_switch_6)->GetIndex()){
			case 1: {
				Float value = _switch_6->__Param(0);
{
					HX_STACK_LINE(691)
					return (value + HX_CSTRING("dcpm"));
				}
			}
			;break;
			case 0: {
				Float value = _switch_6->__Param(0);
{
					HX_STACK_LINE(694)
					return (value + HX_CSTRING("dpi"));
				}
			}
			;break;
			case 2: {
				Float value = _switch_6->__Param(0);
{
					HX_STACK_LINE(697)
					return (value + HX_CSTRING("dppx"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(688)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeResolution,return )

::String CSSStyleSerializer_obj::serializeLength( ::cocktail::core::css::CSSLengthValue length){
	HX_STACK_PUSH("CSSStyleSerializer::serializeLength","cocktail/core/css/parsers/CSSStyleSerializer.hx",703);
	HX_STACK_ARG(length,"length");
	HX_STACK_LINE(703)
	{
		::cocktail::core::css::CSSLengthValue _switch_7 = (length);
		switch((_switch_7)->GetIndex()){
			case 0: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(706)
					return (value + HX_CSTRING("px"));
				}
			}
			;break;
			case 6: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(709)
					return (value + HX_CSTRING("em"));
				}
			}
			;break;
			case 5: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(712)
					return (value + HX_CSTRING("in"));
				}
			}
			;break;
			case 4: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(715)
					return (value + HX_CSTRING("pc"));
				}
			}
			;break;
			case 7: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(718)
					return (value + HX_CSTRING("ex"));
				}
			}
			;break;
			case 3: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(721)
					return (value + HX_CSTRING("pt"));
				}
			}
			;break;
			case 2: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(724)
					return (value + HX_CSTRING("mm"));
				}
			}
			;break;
			case 1: {
				Float value = _switch_7->__Param(0);
{
					HX_STACK_LINE(727)
					return (value + HX_CSTRING("cm"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(703)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeLength,return )

::String CSSStyleSerializer_obj::serializeFrequency( ::cocktail::core::css::CSSFrequencyValue frequency){
	HX_STACK_PUSH("CSSStyleSerializer::serializeFrequency","cocktail/core/css/parsers/CSSStyleSerializer.hx",733);
	HX_STACK_ARG(frequency,"frequency");
	HX_STACK_LINE(733)
	{
		::cocktail::core::css::CSSFrequencyValue _switch_8 = (frequency);
		switch((_switch_8)->GetIndex()){
			case 0: {
				Float value = _switch_8->__Param(0);
{
					HX_STACK_LINE(736)
					return (value + HX_CSTRING("hz"));
				}
			}
			;break;
			case 1: {
				Float value = _switch_8->__Param(0);
{
					HX_STACK_LINE(739)
					return (value + HX_CSTRING("khz"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(733)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeFrequency,return )

::String CSSStyleSerializer_obj::serializeAngle( ::cocktail::core::css::CSSAngleValue angle){
	HX_STACK_PUSH("CSSStyleSerializer::serializeAngle","cocktail/core/css/parsers/CSSStyleSerializer.hx",745);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_LINE(745)
	{
		::cocktail::core::css::CSSAngleValue _switch_9 = (angle);
		switch((_switch_9)->GetIndex()){
			case 0: {
				Float value = _switch_9->__Param(0);
{
					HX_STACK_LINE(748)
					return (value + HX_CSTRING("deg"));
				}
			}
			;break;
			case 2: {
				Float value = _switch_9->__Param(0);
{
					HX_STACK_LINE(751)
					return (value + HX_CSTRING("rad"));
				}
			}
			;break;
			case 3: {
				Float value = _switch_9->__Param(0);
{
					HX_STACK_LINE(754)
					return (value + HX_CSTRING("turn"));
				}
			}
			;break;
			case 1: {
				Float value = _switch_9->__Param(0);
{
					HX_STACK_LINE(757)
					return (value + HX_CSTRING("grad"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(745)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeAngle,return )

::String CSSStyleSerializer_obj::serializeTime( ::cocktail::core::css::CSSTimeValue time){
	HX_STACK_PUSH("CSSStyleSerializer::serializeTime","cocktail/core/css/parsers/CSSStyleSerializer.hx",763);
	HX_STACK_ARG(time,"time");
	HX_STACK_LINE(763)
	{
		::cocktail::core::css::CSSTimeValue _switch_10 = (time);
		switch((_switch_10)->GetIndex()){
			case 0: {
				Float value = _switch_10->__Param(0);
{
					HX_STACK_LINE(766)
					return (value + HX_CSTRING("s"));
				}
			}
			;break;
			case 1: {
				Float value = _switch_10->__Param(0);
{
					HX_STACK_LINE(769)
					return (value + HX_CSTRING("ms"));
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(763)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeTime,return )

::String CSSStyleSerializer_obj::serializeKeyword( ::cocktail::core::css::CSSKeywordValue keyword){
	HX_STACK_PUSH("CSSStyleSerializer::serializeKeyword","cocktail/core/css/parsers/CSSStyleSerializer.hx",775);
	HX_STACK_ARG(keyword,"keyword");
	HX_STACK_LINE(775)
	{
		::cocktail::core::css::CSSKeywordValue _switch_11 = (keyword);
		switch((_switch_11)->GetIndex()){
			case 0: {
				HX_STACK_LINE(778)
				return HX_CSTRING("normal");
			}
			;break;
			case 1: {
				HX_STACK_LINE(781)
				return HX_CSTRING("bold");
			}
			;break;
			case 2: {
				HX_STACK_LINE(784)
				return HX_CSTRING("bolder");
			}
			;break;
			case 3: {
				HX_STACK_LINE(787)
				return HX_CSTRING("lighter");
			}
			;break;
			case 5: {
				HX_STACK_LINE(790)
				return HX_CSTRING("oblique");
			}
			;break;
			case 4: {
				HX_STACK_LINE(793)
				return HX_CSTRING("italic");
			}
			;break;
			case 6: {
				HX_STACK_LINE(796)
				return HX_CSTRING("small-caps");
			}
			;break;
			case 7: {
				HX_STACK_LINE(799)
				return HX_CSTRING("pre");
			}
			;break;
			case 8: {
				HX_STACK_LINE(802)
				return HX_CSTRING("no-wrap");
			}
			;break;
			case 9: {
				HX_STACK_LINE(805)
				return HX_CSTRING("pre-wrap");
			}
			;break;
			case 10: {
				HX_STACK_LINE(808)
				return HX_CSTRING("pre-line");
			}
			;break;
			case 11: {
				HX_STACK_LINE(811)
				return HX_CSTRING("left");
			}
			;break;
			case 12: {
				HX_STACK_LINE(814)
				return HX_CSTRING("right");
			}
			;break;
			case 13: {
				HX_STACK_LINE(817)
				return HX_CSTRING("center");
			}
			;break;
			case 14: {
				HX_STACK_LINE(820)
				return HX_CSTRING("justify");
			}
			;break;
			case 15: {
				HX_STACK_LINE(823)
				return HX_CSTRING("capitalize");
			}
			;break;
			case 16: {
				HX_STACK_LINE(826)
				return HX_CSTRING("uppercase");
			}
			;break;
			case 17: {
				HX_STACK_LINE(829)
				return HX_CSTRING("lowercase");
			}
			;break;
			case 18: {
				HX_STACK_LINE(832)
				return HX_CSTRING("none");
			}
			;break;
			case 19: {
				HX_STACK_LINE(835)
				return HX_CSTRING("baseline");
			}
			;break;
			case 20: {
				HX_STACK_LINE(838)
				return HX_CSTRING("sub");
			}
			;break;
			case 21: {
				HX_STACK_LINE(841)
				return HX_CSTRING("super");
			}
			;break;
			case 22: {
				HX_STACK_LINE(844)
				return HX_CSTRING("top");
			}
			;break;
			case 23: {
				HX_STACK_LINE(847)
				return HX_CSTRING("text-top");
			}
			;break;
			case 24: {
				HX_STACK_LINE(850)
				return HX_CSTRING("middle");
			}
			;break;
			case 25: {
				HX_STACK_LINE(853)
				return HX_CSTRING("bottom");
			}
			;break;
			case 26: {
				HX_STACK_LINE(856)
				return HX_CSTRING("text-bottom");
			}
			;break;
			case 27: {
				HX_STACK_LINE(859)
				return HX_CSTRING("auto");
			}
			;break;
			case 28: {
				HX_STACK_LINE(862)
				return HX_CSTRING("block");
			}
			;break;
			case 29: {
				HX_STACK_LINE(865)
				return HX_CSTRING("inline-block");
			}
			;break;
			case 30: {
				HX_STACK_LINE(868)
				return HX_CSTRING("inline");
			}
			;break;
			case 31: {
				HX_STACK_LINE(871)
				return HX_CSTRING("both");
			}
			;break;
			case 32: {
				HX_STACK_LINE(874)
				return HX_CSTRING("static");
			}
			;break;
			case 33: {
				HX_STACK_LINE(877)
				return HX_CSTRING("relative");
			}
			;break;
			case 34: {
				HX_STACK_LINE(880)
				return HX_CSTRING("absolute");
			}
			;break;
			case 35: {
				HX_STACK_LINE(883)
				return HX_CSTRING("fixed");
			}
			;break;
			case 36: {
				HX_STACK_LINE(886)
				return HX_CSTRING("visible");
			}
			;break;
			case 37: {
				HX_STACK_LINE(889)
				return HX_CSTRING("hidden");
			}
			;break;
			case 38: {
				HX_STACK_LINE(892)
				return HX_CSTRING("scroll");
			}
			;break;
			case 39: {
				HX_STACK_LINE(895)
				return HX_CSTRING("border-box");
			}
			;break;
			case 40: {
				HX_STACK_LINE(898)
				return HX_CSTRING("padding-box");
			}
			;break;
			case 41: {
				HX_STACK_LINE(901)
				return HX_CSTRING("content-box");
			}
			;break;
			case 42: {
				HX_STACK_LINE(904)
				return HX_CSTRING("contain");
			}
			;break;
			case 43: {
				HX_STACK_LINE(907)
				return HX_CSTRING("cover");
			}
			;break;
			case 44: {
				HX_STACK_LINE(910)
				return HX_CSTRING("crosshair");
			}
			;break;
			case 45: {
				HX_STACK_LINE(913)
				return HX_CSTRING("default");
			}
			;break;
			case 46: {
				HX_STACK_LINE(916)
				return HX_CSTRING("pointer");
			}
			;break;
			case 47: {
				HX_STACK_LINE(919)
				return HX_CSTRING("text");
			}
			;break;
			case 48: {
				HX_STACK_LINE(922)
				return HX_CSTRING("all");
			}
			;break;
			case 49: {
				HX_STACK_LINE(925)
				return HX_CSTRING("ease");
			}
			;break;
			case 50: {
				HX_STACK_LINE(928)
				return HX_CSTRING("linear");
			}
			;break;
			case 51: {
				HX_STACK_LINE(931)
				return HX_CSTRING("ease-in");
			}
			;break;
			case 52: {
				HX_STACK_LINE(934)
				return HX_CSTRING("ease-out");
			}
			;break;
			case 53: {
				HX_STACK_LINE(937)
				return HX_CSTRING("ease-in-out");
			}
			;break;
			case 54: {
				HX_STACK_LINE(940)
				return HX_CSTRING("step-start");
			}
			;break;
			case 55: {
				HX_STACK_LINE(943)
				return HX_CSTRING("step-end");
			}
			;break;
			case 56: {
				HX_STACK_LINE(946)
				return HX_CSTRING("start");
			}
			;break;
			case 57: {
				HX_STACK_LINE(949)
				return HX_CSTRING("end");
			}
			;break;
			case 58: {
				HX_STACK_LINE(952)
				return HX_CSTRING("xx-small");
			}
			;break;
			case 59: {
				HX_STACK_LINE(955)
				return HX_CSTRING("x-small");
			}
			;break;
			case 60: {
				HX_STACK_LINE(958)
				return HX_CSTRING("small");
			}
			;break;
			case 64: {
				HX_STACK_LINE(961)
				return HX_CSTRING("xx-large");
			}
			;break;
			case 63: {
				HX_STACK_LINE(964)
				return HX_CSTRING("x-large");
			}
			;break;
			case 62: {
				HX_STACK_LINE(967)
				return HX_CSTRING("large");
			}
			;break;
			case 61: {
				HX_STACK_LINE(970)
				return HX_CSTRING("medium");
			}
			;break;
			case 65: {
				HX_STACK_LINE(973)
				return HX_CSTRING("larger");
			}
			;break;
			case 66: {
				HX_STACK_LINE(976)
				return HX_CSTRING("smaller");
			}
			;break;
			case 70: {
				HX_STACK_LINE(979)
				return HX_CSTRING("space");
			}
			;break;
			case 71: {
				HX_STACK_LINE(982)
				return HX_CSTRING("round");
			}
			;break;
			case 69: {
				HX_STACK_LINE(985)
				return HX_CSTRING("repeat-y");
			}
			;break;
			case 68: {
				HX_STACK_LINE(988)
				return HX_CSTRING("repeat-x");
			}
			;break;
			case 72: {
				HX_STACK_LINE(991)
				return HX_CSTRING("no-repeat");
			}
			;break;
			case 67: {
				HX_STACK_LINE(994)
				return HX_CSTRING("repeat");
			}
			;break;
			case 73: {
				HX_STACK_LINE(997)
				return HX_CSTRING("thin");
			}
			;break;
			case 74: {
				HX_STACK_LINE(1000)
				return HX_CSTRING("thick");
			}
			;break;
			case 75: {
				HX_STACK_LINE(1003)
				return HX_CSTRING("dotted");
			}
			;break;
			case 76: {
				HX_STACK_LINE(1006)
				return HX_CSTRING("dashed");
			}
			;break;
			case 77: {
				HX_STACK_LINE(1009)
				return HX_CSTRING("solid");
			}
			;break;
			case 78: {
				HX_STACK_LINE(1012)
				return HX_CSTRING("double");
			}
			;break;
			case 79: {
				HX_STACK_LINE(1015)
				return HX_CSTRING("groove");
			}
			;break;
			case 80: {
				HX_STACK_LINE(1018)
				return HX_CSTRING("ridge");
			}
			;break;
			case 81: {
				HX_STACK_LINE(1021)
				return HX_CSTRING("inset");
			}
			;break;
			case 82: {
				HX_STACK_LINE(1024)
				return HX_CSTRING("outset");
			}
			;break;
			case 83: {
				HX_STACK_LINE(1027)
				return HX_CSTRING("invert");
			}
			;break;
			case 84: {
				HX_STACK_LINE(1030)
				return HX_CSTRING("underline");
			}
			;break;
			case 85: {
				HX_STACK_LINE(1033)
				return HX_CSTRING("overline");
			}
			;break;
			case 86: {
				HX_STACK_LINE(1036)
				return HX_CSTRING("line-through");
			}
			;break;
			case 87: {
				HX_STACK_LINE(1039)
				return HX_CSTRING("blink");
			}
			;break;
		}
	}
	HX_STACK_LINE(775)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSerializer_obj,serializeKeyword,return )


CSSStyleSerializer_obj::CSSStyleSerializer_obj()
{
}

void CSSStyleSerializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSStyleSerializer);
	HX_MARK_END_CLASS();
}

void CSSStyleSerializer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic CSSStyleSerializer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"serialize") ) { return serialize_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"serializeList") ) { return serializeList_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeTime") ) { return serializeTime_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"serializeGroup") ) { return serializeGroup_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeColor") ) { return serializeColor_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeAngle") ) { return serializeAngle_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"serializeLength") ) { return serializeLength_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"serializeKeyword") ) { return serializeKeyword_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"serializeFrequency") ) { return serializeFrequency_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"serializeResolution") ) { return serializeResolution_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"serializeTranslation") ) { return serializeTranslation_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"serializeColorKeyword") ) { return serializeColorKeyword_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"serializeTransformFunction") ) { return serializeTransformFunction_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSStyleSerializer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSStyleSerializer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("serialize"),
	HX_CSTRING("serializeList"),
	HX_CSTRING("serializeGroup"),
	HX_CSTRING("serializeTransformFunction"),
	HX_CSTRING("serializeTranslation"),
	HX_CSTRING("serializeColor"),
	HX_CSTRING("serializeColorKeyword"),
	HX_CSTRING("serializeResolution"),
	HX_CSTRING("serializeLength"),
	HX_CSTRING("serializeFrequency"),
	HX_CSTRING("serializeAngle"),
	HX_CSTRING("serializeTime"),
	HX_CSTRING("serializeKeyword"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSStyleSerializer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSStyleSerializer_obj::__mClass,"__mClass");
};

Class CSSStyleSerializer_obj::__mClass;

void CSSStyleSerializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.CSSStyleSerializer"), hx::TCanCast< CSSStyleSerializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSStyleSerializer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
