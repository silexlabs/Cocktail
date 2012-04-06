#ifndef INCLUDED_cocktail_core_style_computer_BackgroundStylesComputer
#define INCLUDED_cocktail_core_style_computer_BackgroundStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundClip)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundImage)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundOrigin)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundPositionX)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundPositionY)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSize)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSizeDimension)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS4(cocktail,core,style,computer,BackgroundStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{


class BackgroundStylesComputer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BackgroundStylesComputer_obj OBJ_;
		BackgroundStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BackgroundStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BackgroundStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BackgroundStylesComputer"); }

		static Void compute( ::cocktail::core::style::CoreStyle style);
		static Dynamic compute_dyn();

		static Dynamic computeIndividualBackground( ::cocktail::core::style::CoreStyle style,Dynamic backgroundBox,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage);
		static Dynamic computeIndividualBackground_dyn();

		static Dynamic getComputedBackgroundColor( ::cocktail::core::style::CoreStyle style);
		static Dynamic getComputedBackgroundColor_dyn();

		static Dynamic getComputedBackgroundPosition( Dynamic backgroundPosition,Dynamic backgroundPositioningArea,Dynamic computedBackgroundSize,double emReference,double exReference);
		static Dynamic getComputedBackgroundPosition_dyn();

		static int getComputedBackgroundXPosition( ::cocktail::core::style::BackgroundPositionX backgroundPosition,int backgroundPositioningAreaDimension,int imageDimension,double emReference,double exReference);
		static Dynamic getComputedBackgroundXPosition_dyn();

		static int getComputedBackgroundYPosition( ::cocktail::core::style::BackgroundPositionY backgroundPosition,int backgroundPositioningAreaDimension,int imageDimension,double emReference,double exReference);
		static Dynamic getComputedBackgroundYPosition_dyn();

		static Dynamic getComputedBackgroundSize( ::cocktail::core::style::BackgroundSize backgroundSize,Dynamic backgroundPositioningArea,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,double emReference,double exReference);
		static Dynamic getComputedBackgroundSize_dyn();

		static int getBackgroundSizeStyleDimensionData( ::cocktail::core::style::BackgroundSizeDimension value,::cocktail::core::style::BackgroundSizeDimension opositeBackgroundSizeValue,int backgroundPositioningAreaDimension,int opositeBackgroundAreaDimension,Dynamic intrinsicDimension,Dynamic opositeIntrinsicDimension,Dynamic intrinsicRatio,double emReference,double exReference);
		static Dynamic getBackgroundSizeStyleDimensionData_dyn();

		static Dynamic getBackgroundPositioningArea( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::BackgroundOrigin backgroundOrigin,Dynamic backgroundBox);
		static Dynamic getBackgroundPositioningArea_dyn();

		static Dynamic getBackgroundPaintingArea( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundBox);
		static Dynamic getBackgroundPaintingArea_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_cocktail_core_style_computer_BackgroundStylesComputer */ 
