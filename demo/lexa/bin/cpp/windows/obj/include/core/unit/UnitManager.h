#ifndef INCLUDED_core_unit_UnitManager
#define INCLUDED_core_unit_UnitManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,Angle)
HX_DECLARE_CLASS2(core,unit,CSSColor)
HX_DECLARE_CLASS2(core,unit,ColorKeyword)
HX_DECLARE_CLASS2(core,unit,FontSizeAbsoluteSize)
HX_DECLARE_CLASS2(core,unit,FontSizeRelativeSize)
HX_DECLARE_CLASS2(core,unit,Length)
HX_DECLARE_CLASS2(core,unit,UnitManager)
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

		static int getPixelFromLength( ::core::unit::Length length,double emReference,double exReference);
		static Dynamic getPixelFromLength_dyn();

		static double getFontSizeFromAbsoluteSizeValue( ::core::unit::FontSizeAbsoluteSize absoluteSize);
		static Dynamic getFontSizeFromAbsoluteSizeValue_dyn();

		static double getFontSizeFromRelativeSizeValue( ::core::unit::FontSizeRelativeSize relativeSize,double parentFontSize);
		static Dynamic getFontSizeFromRelativeSizeValue_dyn();

		static double getPixelFromPercent( int percent,int reference);
		static Dynamic getPixelFromPercent_dyn();

		static double getPercentFromPixel( int pixel,int reference);
		static Dynamic getPercentFromPixel_dyn();

		static Dynamic getColorDataFromCSSColor( ::core::unit::CSSColor value);
		static Dynamic getColorDataFromCSSColor_dyn();

		static double getRadFromAngle( ::core::unit::Angle value);
		static Dynamic getRadFromAngle_dyn();

		static double getDegreeFromAngle( ::core::unit::Angle value);
		static Dynamic getDegreeFromAngle_dyn();

		static Dynamic getColorDataFromColorKeyword( ::core::unit::ColorKeyword value);
		static Dynamic getColorDataFromColorKeyword_dyn();

		static double getLargerFontSize( double parentFontSize);
		static Dynamic getLargerFontSize_dyn();

		static double getSmallerFontSize( double parentFontSize);
		static Dynamic getSmallerFontSize_dyn();

};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_UnitManager */ 
