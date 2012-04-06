#ifndef INCLUDED_cocktail_core_unit_UnitManager
#define INCLUDED_cocktail_core_unit_UnitManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundClip)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundImage)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundOrigin)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundPositionX)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundPositionY)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundRepeatValue)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSize)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSizeDimension)
HX_DECLARE_CLASS3(cocktail,core,style,CSSFloat)
HX_DECLARE_CLASS3(cocktail,core,style,Clear)
HX_DECLARE_CLASS3(cocktail,core,style,ConstrainedDimension)
HX_DECLARE_CLASS3(cocktail,core,style,Cursor)
HX_DECLARE_CLASS3(cocktail,core,style,Dimension)
HX_DECLARE_CLASS3(cocktail,core,style,Display)
HX_DECLARE_CLASS3(cocktail,core,style,FontSize)
HX_DECLARE_CLASS3(cocktail,core,style,FontStyle)
HX_DECLARE_CLASS3(cocktail,core,style,FontVariant)
HX_DECLARE_CLASS3(cocktail,core,style,FontWeight)
HX_DECLARE_CLASS3(cocktail,core,style,LetterSpacing)
HX_DECLARE_CLASS3(cocktail,core,style,LineHeight)
HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS3(cocktail,core,style,Overflow)
HX_DECLARE_CLASS3(cocktail,core,style,Padding)
HX_DECLARE_CLASS3(cocktail,core,style,Position)
HX_DECLARE_CLASS3(cocktail,core,style,PositionOffset)
HX_DECLARE_CLASS3(cocktail,core,style,TextAlign)
HX_DECLARE_CLASS3(cocktail,core,style,TextIndent)
HX_DECLARE_CLASS3(cocktail,core,style,TextTransform)
HX_DECLARE_CLASS3(cocktail,core,style,Transform)
HX_DECLARE_CLASS3(cocktail,core,style,TransformFunction)
HX_DECLARE_CLASS3(cocktail,core,style,Translation)
HX_DECLARE_CLASS3(cocktail,core,style,VerticalAlign)
HX_DECLARE_CLASS3(cocktail,core,style,Visibility)
HX_DECLARE_CLASS3(cocktail,core,style,WhiteSpace)
HX_DECLARE_CLASS3(cocktail,core,style,WordSpacing)
HX_DECLARE_CLASS3(cocktail,core,unit,Angle)
HX_DECLARE_CLASS3(cocktail,core,unit,CSSColor)
HX_DECLARE_CLASS3(cocktail,core,unit,ColorKeyword)
HX_DECLARE_CLASS3(cocktail,core,unit,FontSizeAbsoluteSize)
HX_DECLARE_CLASS3(cocktail,core,unit,FontSizeRelativeSize)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientAngle)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientCornerValue)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientSideValue)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientStopValue)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientValue)
HX_DECLARE_CLASS3(cocktail,core,unit,ImageValue)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
HX_DECLARE_CLASS3(cocktail,core,unit,UnitManager)
namespace cocktail{
namespace core{
namespace unit{


class UnitManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef UnitManager_obj OBJ_;
		UnitManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< UnitManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UnitManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("UnitManager"); }

		static Dynamic boxStyleEnum( ::Enum enumType,::String string);
		static Dynamic boxStyleEnum_dyn();

		static ::cocktail::core::style::ConstrainedDimension constrainedDimensionEnum( ::String string);
		static Dynamic constrainedDimensionEnum_dyn();

		static ::cocktail::core::style::Display displayEnum( ::String string);
		static Dynamic displayEnum_dyn();

		static ::cocktail::core::style::Overflow overflowEnum( ::String string);
		static Dynamic overflowEnum_dyn();

		static ::cocktail::core::style::VerticalAlign verticalAlignEnum( ::String string);
		static Dynamic verticalAlignEnum_dyn();

		static ::cocktail::core::style::Clear clearEnum( ::String string);
		static Dynamic clearEnum_dyn();

		static ::cocktail::core::style::Position positionEnum( ::String string);
		static Dynamic positionEnum_dyn();

		static ::cocktail::core::style::WhiteSpace whiteSpaceEnum( ::String string);
		static Dynamic whiteSpaceEnum_dyn();

		static ::cocktail::core::style::TextAlign textAlignEnum( ::String string);
		static Dynamic textAlignEnum_dyn();

		static ::cocktail::core::style::FontWeight fontWeightEnum( ::String string);
		static Dynamic fontWeightEnum_dyn();

		static ::cocktail::core::style::FontStyle fontStyleEnum( ::String string);
		static Dynamic fontStyleEnum_dyn();

		static ::cocktail::core::style::FontVariant fontVariantEnum( ::String string);
		static Dynamic fontVariantEnum_dyn();

		static ::cocktail::core::style::TextTransform textTransformEnum( ::String string);
		static Dynamic textTransformEnum_dyn();

		static ::cocktail::core::style::Visibility visibilityEnum( ::String string);
		static Dynamic visibilityEnum_dyn();

		static ::cocktail::core::style::Cursor cursorEnum( ::String string);
		static Dynamic cursorEnum_dyn();

		static ::cocktail::core::style::WordSpacing wordSpacingEnum( ::String string);
		static Dynamic wordSpacingEnum_dyn();

		static Array< ::cocktail::core::style::BackgroundImage > backgroundImageEnum( ::String string);
		static Dynamic backgroundImageEnum_dyn();

		static Dynamic backgroundRepeatEnum( ::String string);
		static Dynamic backgroundRepeatEnum_dyn();

		static Array< ::cocktail::core::style::BackgroundOrigin > backgroundOriginEnum( ::String string);
		static Dynamic backgroundOriginEnum_dyn();

		static Array< ::cocktail::core::style::BackgroundSize > backgroundSizeEnum( ::String string);
		static Dynamic backgroundSizeEnum_dyn();

		static Dynamic backgroundPositionEnum( ::String string);
		static Dynamic backgroundPositionEnum_dyn();

		static Array< ::cocktail::core::style::BackgroundClip > backgroundClipEnum( ::String string);
		static Dynamic backgroundClipEnum_dyn();

		static Array< ::String > fontFamilyEnum( ::String string);
		static Dynamic fontFamilyEnum_dyn();

		static ::cocktail::core::style::LetterSpacing letterSpacingEnum( ::String string);
		static Dynamic letterSpacingEnum_dyn();

		static ::cocktail::core::style::LineHeight lineHeightEnum( ::String string);
		static Dynamic lineHeightEnum_dyn();

		static ::cocktail::core::style::TextIndent textIndentEnum( ::String string);
		static Dynamic textIndentEnum_dyn();

		static ::cocktail::core::style::CSSFloat cssFloatEnum( ::String string);
		static Dynamic cssFloatEnum_dyn();

		static ::cocktail::core::unit::CSSColor colorEnum( ::String string);
		static Dynamic colorEnum_dyn();

		static Dynamic string2RGBA( ::String string);
		static Dynamic string2RGBA_dyn();

		static Dynamic string2RGB( ::String string);
		static Dynamic string2RGB_dyn();

		static ::String trim( ::String string);
		static Dynamic trim_dyn();

		static Dynamic string2VUnit( ::String string);
		static Dynamic string2VUnit_dyn();

		static ::cocktail::core::unit::Length string2Length( Dynamic parsed);
		static Dynamic string2Length_dyn();

		static ::String string2URLData( ::String string);
		static Dynamic string2URLData_dyn();

		static Array< ::String > string2VList( ::String string,Dynamic sep);
		static Dynamic string2VList_dyn();

		static Array< ::String > string2Array( ::String string);
		static Dynamic string2Array_dyn();

		static int getPixelFromLength( ::cocktail::core::unit::Length length,double emReference,double exReference);
		static Dynamic getPixelFromLength_dyn();

		static double getFontSizeFromAbsoluteSizeValue( ::cocktail::core::unit::FontSizeAbsoluteSize absoluteSize);
		static Dynamic getFontSizeFromAbsoluteSizeValue_dyn();

		static double getFontSizeFromRelativeSizeValue( ::cocktail::core::unit::FontSizeRelativeSize relativeSize,double parentFontSize);
		static Dynamic getFontSizeFromRelativeSizeValue_dyn();

		static double getPixelFromPercent( int percent,int reference);
		static Dynamic getPixelFromPercent_dyn();

		static double getPercentFromPixel( int pixel,int reference);
		static Dynamic getPercentFromPixel_dyn();

		static Dynamic getColorDataFromCSSColor( ::cocktail::core::unit::CSSColor value);
		static Dynamic getColorDataFromCSSColor_dyn();

		static double getRadFromAngle( ::cocktail::core::unit::Angle value);
		static Dynamic getRadFromAngle_dyn();

		static double getDegreeFromAngle( ::cocktail::core::unit::Angle value);
		static Dynamic getDegreeFromAngle_dyn();

		static Dynamic getColorDataFromColorKeyword( ::cocktail::core::unit::ColorKeyword value);
		static Dynamic getColorDataFromColorKeyword_dyn();

		static double getLargerFontSize( double parentFontSize);
		static Dynamic getLargerFontSize_dyn();

		static double getSmallerFontSize( double parentFontSize);
		static Dynamic getSmallerFontSize_dyn();

		static ::String getCSSDisplay( ::cocktail::core::style::Display value);
		static Dynamic getCSSDisplay_dyn();

		static ::String getCSSFloatAsString( ::cocktail::core::style::CSSFloat value);
		static Dynamic getCSSFloatAsString_dyn();

		static ::String getCSSClear( ::cocktail::core::style::Clear value);
		static Dynamic getCSSClear_dyn();

		static ::String getCSSPosition( ::cocktail::core::style::Position value);
		static Dynamic getCSSPosition_dyn();

		static ::String getCSSOverflow( ::cocktail::core::style::Overflow value);
		static Dynamic getCSSOverflow_dyn();

		static ::String getCSSOpacity( double value);
		static Dynamic getCSSOpacity_dyn();

		static ::String getCSSVisibility( ::cocktail::core::style::Visibility value);
		static Dynamic getCSSVisibility_dyn();

		static ::String getCSSTransform( ::cocktail::core::style::Transform value);
		static Dynamic getCSSTransform_dyn();

		static ::String getCSSTransformFunction( ::cocktail::core::style::TransformFunction transformFunction);
		static Dynamic getCSSTransformFunction_dyn();

		static ::String getCSSTranslation( ::cocktail::core::style::Translation translation);
		static Dynamic getCSSTranslation_dyn();

		static ::String getCSSTransformOrigin( Dynamic value);
		static Dynamic getCSSTransformOrigin_dyn();

		static ::String getCSSMargin( ::cocktail::core::style::Margin value);
		static Dynamic getCSSMargin_dyn();

		static ::String getCSSPadding( ::cocktail::core::style::Padding value);
		static Dynamic getCSSPadding_dyn();

		static ::String getCSSDimension( ::cocktail::core::style::Dimension value);
		static Dynamic getCSSDimension_dyn();

		static ::String getCSSPositionOffset( ::cocktail::core::style::PositionOffset value);
		static Dynamic getCSSPositionOffset_dyn();

		static ::String getCSSConstrainedDimension( ::cocktail::core::style::ConstrainedDimension value);
		static Dynamic getCSSConstrainedDimension_dyn();

		static ::String getCSSVerticalAlign( ::cocktail::core::style::VerticalAlign value);
		static Dynamic getCSSVerticalAlign_dyn();

		static ::String getCSSLineHeight( ::cocktail::core::style::LineHeight value);
		static Dynamic getCSSLineHeight_dyn();

		static ::String getCSSFontSize( ::cocktail::core::style::FontSize value);
		static Dynamic getCSSFontSize_dyn();

		static ::String getCSSFontWeight( ::cocktail::core::style::FontWeight value);
		static Dynamic getCSSFontWeight_dyn();

		static ::String getCSSFontStyle( ::cocktail::core::style::FontStyle value);
		static Dynamic getCSSFontStyle_dyn();

		static ::String getCSSFontVariant( ::cocktail::core::style::FontVariant value);
		static Dynamic getCSSFontVariant_dyn();

		static ::String getCSSFontFamily( Array< ::String > value);
		static Dynamic getCSSFontFamily_dyn();

		static ::String getCSSTextAlign( ::cocktail::core::style::TextAlign value);
		static Dynamic getCSSTextAlign_dyn();

		static ::String getCSSWhiteSpace( ::cocktail::core::style::WhiteSpace value);
		static Dynamic getCSSWhiteSpace_dyn();

		static ::String getCSSTextTransform( ::cocktail::core::style::TextTransform value);
		static Dynamic getCSSTextTransform_dyn();

		static ::String getCSSTextIndent( ::cocktail::core::style::TextIndent value);
		static Dynamic getCSSTextIndent_dyn();

		static ::String getCSSLetterSpacing( ::cocktail::core::style::LetterSpacing value);
		static Dynamic getCSSLetterSpacing_dyn();

		static ::String getCSSWordSpacing( ::cocktail::core::style::WordSpacing value);
		static Dynamic getCSSWordSpacing_dyn();

		static ::String getCSSBackgroundColor( ::cocktail::core::unit::CSSColor value);
		static Dynamic getCSSBackgroundColor_dyn();

		static ::String getCSSBackgroundOrigin( Array< ::cocktail::core::style::BackgroundOrigin > value);
		static Dynamic getCSSBackgroundOrigin_dyn();

		static ::String getCSSBackgroundClip( Array< ::cocktail::core::style::BackgroundClip > value);
		static Dynamic getCSSBackgroundClip_dyn();

		static ::String getCSSBackgroundImage( Array< ::cocktail::core::style::BackgroundImage > value);
		static Dynamic getCSSBackgroundImage_dyn();

		static ::String getCSSBackgroundSize( Array< ::cocktail::core::style::BackgroundSize > value);
		static Dynamic getCSSBackgroundSize_dyn();

		static ::String getCSSBackgroundSizeDimensions( Dynamic value);
		static Dynamic getCSSBackgroundSizeDimensions_dyn();

		static ::String getCSSBackgroundSizeDimension( ::cocktail::core::style::BackgroundSizeDimension value);
		static Dynamic getCSSBackgroundSizeDimension_dyn();

		static ::String getCSSBackgroundPosition( Dynamic value);
		static Dynamic getCSSBackgroundPosition_dyn();

		static ::String getCSSBackgroundPositionX( ::cocktail::core::style::BackgroundPositionX value);
		static Dynamic getCSSBackgroundPositionX_dyn();

		static ::String getCSSBackgroundPositionY( ::cocktail::core::style::BackgroundPositionY value);
		static Dynamic getCSSBackgroundPositionY_dyn();

		static ::String getCSSBackgroundRepeat( Dynamic value);
		static Dynamic getCSSBackgroundRepeat_dyn();

		static ::String getCSSBackgroundRepeatValue( ::cocktail::core::style::BackgroundRepeatValue value);
		static Dynamic getCSSBackgroundRepeatValue_dyn();

		static ::String getCSSCursor( ::cocktail::core::style::Cursor value);
		static Dynamic getCSSCursor_dyn();

		static ::String getCSSImageValue( ::cocktail::core::unit::ImageValue value);
		static Dynamic getCSSImageValue_dyn();

		static ::String getCSSImageList( Dynamic value);
		static Dynamic getCSSImageList_dyn();

		static ::String getCSSGradientValue( ::cocktail::core::unit::GradientValue value);
		static Dynamic getCSSGradientValue_dyn();

		static ::String getCSSLinearGradientValue( Dynamic value);
		static Dynamic getCSSLinearGradientValue_dyn();

		static ::String getCSSColorStopsValue( Dynamic value);
		static Dynamic getCSSColorStopsValue_dyn();

		static ::String getCSSColorStopValue( ::cocktail::core::unit::GradientStopValue value);
		static Dynamic getCSSColorStopValue_dyn();

		static ::String getCSSGradientAngle( ::cocktail::core::unit::GradientAngle value);
		static Dynamic getCSSGradientAngle_dyn();

		static ::String getCSSSideValue( ::cocktail::core::unit::GradientSideValue value);
		static Dynamic getCSSSideValue_dyn();

		static ::String getCSSCornerValue( ::cocktail::core::unit::GradientCornerValue value);
		static Dynamic getCSSCornerValue_dyn();

		static ::String getCSSColor( ::cocktail::core::unit::CSSColor value);
		static Dynamic getCSSColor_dyn();

		static ::String getCSSLength( ::cocktail::core::unit::Length lengthValue);
		static Dynamic getCSSLength_dyn();

		static ::String getCSSPercentValue( int value);
		static Dynamic getCSSPercentValue_dyn();

		static ::String getCSSAngle( ::cocktail::core::unit::Angle value);
		static Dynamic getCSSAngle_dyn();

		static ::String getColorFromKeyword( ::cocktail::core::unit::ColorKeyword value);
		static Dynamic getColorFromKeyword_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_UnitManager */ 
