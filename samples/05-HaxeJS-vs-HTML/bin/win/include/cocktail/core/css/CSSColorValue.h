#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#define INCLUDED_cocktail_core_css_CSSColorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSColorKeyword)
HX_DECLARE_CLASS3(cocktail,core,css,CSSColorValue)
namespace cocktail{
namespace core{
namespace css{


class CSSColorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSColorValue_obj OBJ_;

	public:
		CSSColorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSColorValue"); }
		::String __ToString() const { return HX_CSTRING("CSSColorValue.") + tag; }

		static ::cocktail::core::css::CSSColorValue CURRENT_COLOR;
		static inline ::cocktail::core::css::CSSColorValue CURRENT_COLOR_dyn() { return CURRENT_COLOR; }
		static ::cocktail::core::css::CSSColorValue HEX(::String value);
		static Dynamic HEX_dyn();
		static ::cocktail::core::css::CSSColorValue HSL(Float hue,Float saturation,Float lightness);
		static Dynamic HSL_dyn();
		static ::cocktail::core::css::CSSColorValue HSLA(Float hue,Float saturation,Float lightness,Float alpha);
		static Dynamic HSLA_dyn();
		static ::cocktail::core::css::CSSColorValue KEYWORD(::cocktail::core::css::CSSColorKeyword value);
		static Dynamic KEYWORD_dyn();
		static ::cocktail::core::css::CSSColorValue RGB(int red,int green,int blue);
		static Dynamic RGB_dyn();
		static ::cocktail::core::css::CSSColorValue RGBA(int red,int green,int blue,Float alpha);
		static Dynamic RGBA_dyn();
		static ::cocktail::core::css::CSSColorValue RGBA_PERCENTAGE(Float red,Float green,Float blue,Float alpha);
		static Dynamic RGBA_PERCENTAGE_dyn();
		static ::cocktail::core::css::CSSColorValue RGB_PERCENTAGE(Float red,Float green,Float blue);
		static Dynamic RGB_PERCENTAGE_dyn();
		static ::cocktail::core::css::CSSColorValue TRANSPARENT;
		static inline ::cocktail::core::css::CSSColorValue TRANSPARENT_dyn() { return TRANSPARENT; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSColorValue */ 
