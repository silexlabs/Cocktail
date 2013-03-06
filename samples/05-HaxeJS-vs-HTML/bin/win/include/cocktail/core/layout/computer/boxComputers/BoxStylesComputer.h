#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class BoxStylesComputer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BoxStylesComputer_obj OBJ_;
		BoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoxStylesComputer"); }

		virtual Float constrainHeight( ::cocktail::core::css::CoreStyle style,Float usedHeight);
		Dynamic constrainHeight_dyn();

		virtual Float constrainWidth( ::cocktail::core::css::CoreStyle style,Float usedWidth);
		Dynamic constrainWidth_dyn();

		virtual Float getComputedBorderWidth( ::cocktail::core::css::CSSPropertyValue borderWidthStyleValue);
		Dynamic getComputedBorderWidth_dyn();

		virtual Float getComputedPadding( ::cocktail::core::css::CSSPropertyValue paddingStyleValue,Float containingHTMLElementDimension);
		Dynamic getComputedPadding_dyn();

		virtual Float getComputedDimension( ::cocktail::core::css::CSSPropertyValue dimensionStyleValue,Float containingHTMLElementDimension,bool isContainingDimensionAuto);
		Dynamic getComputedDimension_dyn();

		virtual Float getComputedPositionOffset( ::cocktail::core::css::CSSPropertyValue positionOffsetStyleValue,Float containingHTMLElementDimension);
		Dynamic getComputedPositionOffset_dyn();

		virtual Float getComputedConstrainedDimension( ::cocktail::core::css::CSSPropertyValue constrainedDimension,Float containingHTMLElementDimension,bool isContainingDimensionAuto,hx::Null< bool >  isMinConstraint);
		Dynamic getComputedConstrainedDimension_dyn();

		virtual Float getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual Float getComputedMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin);
		Dynamic getComputedMargin_dyn();

		virtual Float getComputedMarginBottom( ::cocktail::core::css::CoreStyle style,Float computedHeight,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedMarginBottom_dyn();

		virtual Float getComputedMarginTop( ::cocktail::core::css::CoreStyle style,Float computedHeight,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedMarginTop_dyn();

		virtual Float getComputedMarginRight( ::cocktail::core::css::CoreStyle style,Float computedWidth,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedMarginRight_dyn();

		virtual Float getComputedMarginLeft( ::cocktail::core::css::CoreStyle style,Float computedWidth,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedMarginLeft_dyn();

		virtual Float getComputedAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedAutoHeight_dyn();

		virtual Float getComputedHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedHeight_dyn();

		virtual Float getComputedAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedAutoWidth_dyn();

		virtual Float getComputedWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedWidth_dyn();

		virtual Float measureHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureHeight_dyn();

		virtual Float measureAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureAutoHeight_dyn();

		virtual Float measureHeightAndVerticalMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureHeightAndVerticalMargins_dyn();

		virtual Float measureWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureWidth_dyn();

		virtual Float measureAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureAutoWidth_dyn();

		virtual Float measureWidthAndHorizontalMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureWidthAndHorizontalMargins_dyn();

		virtual Void measureOutline( ::cocktail::core::css::CoreStyle style);
		Dynamic measureOutline_dyn();

		virtual Void measureBordersWidth( ::cocktail::core::css::CoreStyle style);
		Dynamic measureBordersWidth_dyn();

		virtual Void measurePaddings( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measurePaddings_dyn();

		virtual Void measureDimensionsAndMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureDimensionsAndMargins_dyn();

		virtual Void measurePositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureDimensionsConstraints( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureDimensionsConstraints_dyn();

		virtual Void measure( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measure_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer */ 
