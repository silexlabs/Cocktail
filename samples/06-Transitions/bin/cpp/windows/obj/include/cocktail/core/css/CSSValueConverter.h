#ifndef INCLUDED_cocktail_core_css_CSSValueConverter
#define INCLUDED_cocktail_core_css_CSSValueConverter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSColorKeyword)
HX_DECLARE_CLASS3(cocktail,core,css,CSSColorValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSLengthValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSValueConverter)
HX_DECLARE_CLASS3(cocktail,core,css,ColorVO)
namespace cocktail{
namespace core{
namespace css{


class CSSValueConverter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSValueConverter_obj OBJ_;
		CSSValueConverter_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CSSValueConverter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSValueConverter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSValueConverter"); }

		static Float getPixelFromLength( ::cocktail::core::css::CSSLengthValue length,Float emReference,Float exReference);
		static Dynamic getPixelFromLength_dyn();

		static Float getBorderWidthFromBorderWidthKeyword( ::cocktail::core::css::CSSKeywordValue value);
		static Dynamic getBorderWidthFromBorderWidthKeyword_dyn();

		static Array< ::String > getFontFamilyAsStringArray( ::cocktail::core::css::CSSPropertyValue value);
		static Dynamic getFontFamilyAsStringArray_dyn();

		static Float getFontSizeFromAbsoluteSizeValue( ::cocktail::core::css::CSSKeywordValue absoluteSize);
		static Dynamic getFontSizeFromAbsoluteSizeValue_dyn();

		static Float getFontSizeFromRelativeSizeValue( ::cocktail::core::css::CSSKeywordValue relativeSize,Float parentFontSize);
		static Dynamic getFontSizeFromRelativeSizeValue_dyn();

		static Float getPixelFromPercent( Float percent,Float reference);
		static Dynamic getPixelFromPercent_dyn();

		static Float getPercentFromPixel( Float pixel,Float reference);
		static Dynamic getPercentFromPixel_dyn();

		static ::cocktail::core::css::CSSColorValue getComputedCSSColorFromCSSColor( ::cocktail::core::css::CSSColorValue colorProperty,::cocktail::core::css::CSSColorValue currentColor);
		static Dynamic getComputedCSSColorFromCSSColor_dyn();

		static Void getColorVOFromCSSColor( ::cocktail::core::css::CSSColorValue value,::cocktail::core::css::ColorVO colorVO);
		static Dynamic getColorVOFromCSSColor_dyn();

		static ::cocktail::core::css::CSSColorValue HSLAToRGBA( Float hue,Float saturation,Float lightness,Float alpha);
		static Dynamic HSLAToRGBA_dyn();

		static Float hueToRGB( Float m1,Float m2,Float h);
		static Dynamic hueToRGB_dyn();

		static Float clampNumber( Float number,Float max,Float min);
		static Dynamic clampNumber_dyn();

		static int clampInteger( int integer,int max,int min);
		static Dynamic clampInteger_dyn();

		static ::cocktail::core::css::CSSColorValue hexToRGBA( ::String hex);
		static Dynamic hexToRGBA_dyn();

		static int hexToInt( ::String _char);
		static Dynamic hexToInt_dyn();

		static ::cocktail::core::css::CSSColorValue getRGBAColorFromColorKeyword( ::cocktail::core::css::CSSColorKeyword value);
		static Dynamic getRGBAColorFromColorKeyword_dyn();

		static Float getLargerFontSize( Float parentFontSize);
		static Dynamic getLargerFontSize_dyn();

		static Float getSmallerFontSize( Float parentFontSize);
		static Dynamic getSmallerFontSize_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSValueConverter */ 
