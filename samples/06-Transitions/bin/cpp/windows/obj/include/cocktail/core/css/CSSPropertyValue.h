#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#define INCLUDED_cocktail_core_css_CSSPropertyValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSAngleValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSColorValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSFrequencyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSLengthValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSResolutionValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTimeValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTransformFunctionValue)
namespace cocktail{
namespace core{
namespace css{


class CSSPropertyValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSPropertyValue_obj OBJ_;

	public:
		CSSPropertyValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSPropertyValue"); }
		::String __ToString() const { return HX_CSTRING("CSSPropertyValue.") + tag; }

		static ::cocktail::core::css::CSSPropertyValue ABSOLUTE_LENGTH(Float value);
		static Dynamic ABSOLUTE_LENGTH_dyn();
		static ::cocktail::core::css::CSSPropertyValue ANGLE(::cocktail::core::css::CSSAngleValue value);
		static Dynamic ANGLE_dyn();
		static ::cocktail::core::css::CSSPropertyValue COLOR(::cocktail::core::css::CSSColorValue value);
		static Dynamic COLOR_dyn();
		static ::cocktail::core::css::CSSPropertyValue CSS_LIST(Array< ::cocktail::core::css::CSSPropertyValue > value);
		static Dynamic CSS_LIST_dyn();
		static ::cocktail::core::css::CSSPropertyValue CUBIC_BEZIER(Float x1,Float y1,Float x2,Float y2);
		static Dynamic CUBIC_BEZIER_dyn();
		static ::cocktail::core::css::CSSPropertyValue FONT_SIZE_LINE_HEIGHT_GROUP(::cocktail::core::css::CSSPropertyValue fontSize,::cocktail::core::css::CSSPropertyValue lineHeight);
		static Dynamic FONT_SIZE_LINE_HEIGHT_GROUP_dyn();
		static ::cocktail::core::css::CSSPropertyValue FREQUENCY(::cocktail::core::css::CSSFrequencyValue value);
		static Dynamic FREQUENCY_dyn();
		static ::cocktail::core::css::CSSPropertyValue GROUP(Array< ::cocktail::core::css::CSSPropertyValue > value);
		static Dynamic GROUP_dyn();
		static ::cocktail::core::css::CSSPropertyValue IDENTIFIER(::String value);
		static Dynamic IDENTIFIER_dyn();
		static ::cocktail::core::css::CSSPropertyValue INHERIT;
		static inline ::cocktail::core::css::CSSPropertyValue INHERIT_dyn() { return INHERIT; }
		static ::cocktail::core::css::CSSPropertyValue INITIAL;
		static inline ::cocktail::core::css::CSSPropertyValue INITIAL_dyn() { return INITIAL; }
		static ::cocktail::core::css::CSSPropertyValue INTEGER(int value);
		static Dynamic INTEGER_dyn();
		static ::cocktail::core::css::CSSPropertyValue KEYWORD(::cocktail::core::css::CSSKeywordValue value);
		static Dynamic KEYWORD_dyn();
		static ::cocktail::core::css::CSSPropertyValue LENGTH(::cocktail::core::css::CSSLengthValue value);
		static Dynamic LENGTH_dyn();
		static ::cocktail::core::css::CSSPropertyValue NUMBER(Float value);
		static Dynamic NUMBER_dyn();
		static ::cocktail::core::css::CSSPropertyValue PERCENTAGE(Float value);
		static Dynamic PERCENTAGE_dyn();
		static ::cocktail::core::css::CSSPropertyValue RESOLUTION(::cocktail::core::css::CSSResolutionValue value);
		static Dynamic RESOLUTION_dyn();
		static ::cocktail::core::css::CSSPropertyValue STEPS(int intervalNumbers,::cocktail::core::css::CSSKeywordValue intervalChange);
		static Dynamic STEPS_dyn();
		static ::cocktail::core::css::CSSPropertyValue STRING(::String value);
		static Dynamic STRING_dyn();
		static ::cocktail::core::css::CSSPropertyValue TIME(::cocktail::core::css::CSSTimeValue value);
		static Dynamic TIME_dyn();
		static ::cocktail::core::css::CSSPropertyValue TRANSFORM_FUNCTION(::cocktail::core::css::CSSTransformFunctionValue value);
		static Dynamic TRANSFORM_FUNCTION_dyn();
		static ::cocktail::core::css::CSSPropertyValue URL(::String value);
		static Dynamic URL_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSPropertyValue */ 
