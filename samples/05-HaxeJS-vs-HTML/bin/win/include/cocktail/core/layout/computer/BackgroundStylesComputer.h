#ifndef INCLUDED_cocktail_core_layout_computer_BackgroundStylesComputer
#define INCLUDED_cocktail_core_layout_computer_BackgroundStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,geom,DimensionVO)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS4(cocktail,core,layout,computer,BackgroundStylesComputer)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace layout{
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BackgroundStylesComputer"); }

		static Dynamic computeIndividualBackground( ::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO backgroundBox,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,::cocktail::core::css::CSSPropertyValue backgroundPosition,::cocktail::core::css::CSSPropertyValue backgroundSize,::cocktail::core::css::CSSPropertyValue backgroundOrigin,::cocktail::core::css::CSSPropertyValue backgroundClip,::cocktail::core::css::CSSPropertyValue backgroundRepeat,::cocktail::core::css::CSSPropertyValue backgroundImage);
		static Dynamic computeIndividualBackground_dyn();

		static ::cocktail::core::geom::PointVO getComputedBackgroundPosition( ::cocktail::core::css::CSSPropertyValue backgroundPosition,::cocktail::core::geom::RectangleVO backgroundPositioningArea,::cocktail::core::geom::DimensionVO computedBackgroundSize);
		static Dynamic getComputedBackgroundPosition_dyn();

		static Float doGetComputedBackgroundPosition( ::cocktail::core::css::CSSPropertyValue backgroundPosition,Float backgroundPositioningAreaDimension,Float imageDimension);
		static Dynamic doGetComputedBackgroundPosition_dyn();

		static ::cocktail::core::geom::DimensionVO getComputedBackgroundSize( ::cocktail::core::css::CSSPropertyValue backgroundSize,::cocktail::core::geom::RectangleVO backgroundPositioningArea,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio);
		static Dynamic getComputedBackgroundSize_dyn();

		static Float getBackgroundSizeStyleDimensionVO( ::cocktail::core::css::CSSPropertyValue backgroundSizeValue,::cocktail::core::css::CSSPropertyValue opositeBackgroundSizeValue,Float backgroundPositioningAreaDimension,Float opositeBackgroundAreaDimension,Dynamic intrinsicDimension,Dynamic opositeIntrinsicDimension,Dynamic intrinsicRatio);
		static Dynamic getBackgroundSizeStyleDimensionVO_dyn();

		static ::cocktail::core::geom::RectangleVO getBackgroundPositioningArea( ::cocktail::core::css::CoreStyle style,::cocktail::core::css::CSSPropertyValue backgroundOrigin,::cocktail::core::geom::RectangleVO backgroundBox);
		static Dynamic getBackgroundPositioningArea_dyn();

		static ::cocktail::core::geom::RectangleVO getBackgroundPaintingArea( ::cocktail::core::css::CoreStyle style,::cocktail::core::css::CSSPropertyValue backgroundClip,::cocktail::core::geom::RectangleVO backgroundBox);
		static Dynamic getBackgroundPaintingArea_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer

#endif /* INCLUDED_cocktail_core_layout_computer_BackgroundStylesComputer */ 
