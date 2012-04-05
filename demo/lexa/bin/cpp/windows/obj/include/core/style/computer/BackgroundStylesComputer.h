#ifndef INCLUDED_core_style_computer_BackgroundStylesComputer
#define INCLUDED_core_style_computer_BackgroundStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,BackgroundClip)
HX_DECLARE_CLASS2(core,style,BackgroundImage)
HX_DECLARE_CLASS2(core,style,BackgroundOrigin)
HX_DECLARE_CLASS2(core,style,BackgroundPositionX)
HX_DECLARE_CLASS2(core,style,BackgroundPositionY)
HX_DECLARE_CLASS2(core,style,BackgroundSize)
HX_DECLARE_CLASS2(core,style,BackgroundSizeDimension)
HX_DECLARE_CLASS3(core,style,computer,BackgroundStylesComputer)
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

		static Void compute( ::core::style::AbstractStyle style);
		static Dynamic compute_dyn();

		static Dynamic computeIndividualBackground( ::core::style::AbstractStyle style,Dynamic backgroundBox,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,Dynamic backgroundPosition,::core::style::BackgroundSize backgroundSize,::core::style::BackgroundOrigin backgroundOrigin,::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::core::style::BackgroundImage backgroundImage);
		static Dynamic computeIndividualBackground_dyn();

		static Dynamic getComputedBackgroundColor( ::core::style::AbstractStyle style);
		static Dynamic getComputedBackgroundColor_dyn();

		static Dynamic getComputedBackgroundPosition( Dynamic backgroundPosition,Dynamic backgroundPositioningArea,Dynamic computedBackgroundSize,double emReference,double exReference);
		static Dynamic getComputedBackgroundPosition_dyn();

		static int getComputedBackgroundXPosition( ::core::style::BackgroundPositionX backgroundPosition,int backgroundPositioningAreaDimension,int imageDimension,double emReference,double exReference);
		static Dynamic getComputedBackgroundXPosition_dyn();

		static int getComputedBackgroundYPosition( ::core::style::BackgroundPositionY backgroundPosition,int backgroundPositioningAreaDimension,int imageDimension,double emReference,double exReference);
		static Dynamic getComputedBackgroundYPosition_dyn();

		static Dynamic getComputedBackgroundSize( ::core::style::BackgroundSize backgroundSize,Dynamic backgroundPositioningArea,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,double emReference,double exReference);
		static Dynamic getComputedBackgroundSize_dyn();

		static int getBackgroundSizeStyleDimensionData( ::core::style::BackgroundSizeDimension value,::core::style::BackgroundSizeDimension opositeBackgroundSizeValue,int backgroundPositioningAreaDimension,int opositeBackgroundAreaDimension,Dynamic intrinsicDimension,Dynamic opositeIntrinsicDimension,Dynamic intrinsicRatio,double emReference,double exReference);
		static Dynamic getBackgroundSizeStyleDimensionData_dyn();

		static Dynamic getBackgroundPositioningArea( ::core::style::AbstractStyle style,::core::style::BackgroundOrigin backgroundOrigin,Dynamic backgroundBox);
		static Dynamic getBackgroundPositioningArea_dyn();

		static Dynamic getBackgroundPaintingArea( ::core::style::AbstractStyle style,::core::style::BackgroundClip backgroundClip,Dynamic backgroundBox);
		static Dynamic getBackgroundPaintingArea_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_core_style_computer_BackgroundStylesComputer */ 
