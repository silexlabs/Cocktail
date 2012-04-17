#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,ConstrainedDimension)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Dimension)
HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS3(cocktail,core,style,Padding)
HX_DECLARE_CLASS3(cocktail,core,style,PositionOffset)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
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
		::String __ToString() const { return HX_CSTRING("BoxStylesComputer"); }

		virtual Void measure( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measure_dyn();

		virtual int shrinkToFit( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic shrinkToFit_dyn();

		virtual int applyContentHeight( ::cocktail::core::style::CoreStyle style,Dynamic cotainingHTMLElementData,int childrenHeight);
		Dynamic applyContentHeight_dyn();

		virtual Void measureDimensionsConstraints( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureDimensionsConstraints_dyn();

		virtual Void measurePositionOffsets( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureVerticalPaddings( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureVerticalPaddings_dyn();

		virtual Void measureHorizontalPaddings( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHorizontalPaddings_dyn();

		virtual Void measureWidthAndHorizontalMargins( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureWidthAndHorizontalMargins_dyn();

		virtual Void measureAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoWidth_dyn();

		virtual Void measureWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureWidth_dyn();

		virtual Void measureHeightAndVerticalMargins( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeightAndVerticalMargins_dyn();

		virtual Void measureAutoHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoHeight_dyn();

		virtual Void measureHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeight_dyn();

		virtual int constrainWidth( ::cocktail::core::style::CoreStyle style,int computedWidth);
		Dynamic constrainWidth_dyn();

		virtual int constrainHeight( ::cocktail::core::style::CoreStyle style,int computedHeight);
		Dynamic constrainHeight_dyn();

		virtual Void setComputedHeight( ::cocktail::core::style::CoreStyle style,int computedHeight);
		Dynamic setComputedHeight_dyn();

		virtual Void setComputedWidth( ::cocktail::core::style::CoreStyle style,int computedWidth);
		Dynamic setComputedWidth_dyn();

		virtual int getComputedWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedWidth_dyn();

		virtual int getComputedAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoWidth_dyn();

		virtual int getComputedHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedHeight_dyn();

		virtual int getComputedAutoHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoHeight_dyn();

		virtual int getComputedMarginLeft( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginLeft_dyn();

		virtual int getComputedMarginRight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginRight_dyn();

		virtual int getComputedMarginTop( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginTop_dyn();

		virtual int getComputedMarginBottom( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginBottom_dyn();

		virtual int getComputedMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedMargin_dyn();

		virtual int getComputedAutoMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual int getComputedConstrainedDimension( ::cocktail::core::style::ConstrainedDimension constrainedDimension,int containingHTMLElementDimension,bool isContainingDimensionAuto,double fontSize,double xHeight,Dynamic isMinConstraint);
		Dynamic getComputedConstrainedDimension_dyn();

		virtual int getComputedPositionOffset( ::cocktail::core::style::PositionOffset positionOffsetStyleValue,int containingHTMLElementDimension,double fontSize,double xHeight);
		Dynamic getComputedPositionOffset_dyn();

		virtual int getComputedDimension( ::cocktail::core::style::Dimension dimensionStyleValue,int containingHTMLElementDimension,bool isContainingDimensionAuto,double fontSize,double xHeight);
		Dynamic getComputedDimension_dyn();

		virtual int getComputedPadding( ::cocktail::core::style::Padding paddingStyleValue,int containingHTMLElementDimension,double fontSize,double xHeight);
		Dynamic getComputedPadding_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer */ 
