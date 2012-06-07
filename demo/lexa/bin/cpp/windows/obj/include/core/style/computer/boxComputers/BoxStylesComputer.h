#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_BoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,ConstrainedDimension)
HX_DECLARE_CLASS2(core,style,Dimension)
HX_DECLARE_CLASS2(core,style,Margin)
HX_DECLARE_CLASS2(core,style,Padding)
HX_DECLARE_CLASS2(core,style,PositionOffset)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
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

		virtual Void measure( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measure_dyn();

		virtual int shrinkToFit( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic shrinkToFit_dyn();

		virtual int applyContentHeight( ::core::style::AbstractStyle style,Dynamic cotainingHTMLElementData,int childrenHeight);
		Dynamic applyContentHeight_dyn();

		virtual Void measureDimensionsConstraints( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureDimensionsConstraints_dyn();

		virtual Void measurePositionOffsets( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureVerticalPaddings( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureVerticalPaddings_dyn();

		virtual Void measureHorizontalPaddings( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHorizontalPaddings_dyn();

		virtual Void measureWidthAndHorizontalMargins( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureWidthAndHorizontalMargins_dyn();

		virtual Void measureAutoWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoWidth_dyn();

		virtual Void measureWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureWidth_dyn();

		virtual Void measureHeightAndVerticalMargins( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeightAndVerticalMargins_dyn();

		virtual Void measureAutoHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoHeight_dyn();

		virtual Void measureHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeight_dyn();

		virtual int constrainWidth( ::core::style::AbstractStyle style,int computedWidth);
		Dynamic constrainWidth_dyn();

		virtual int constrainHeight( ::core::style::AbstractStyle style,int computedHeight);
		Dynamic constrainHeight_dyn();

		virtual Void setComputedHeight( ::core::style::AbstractStyle style,int computedHeight);
		Dynamic setComputedHeight_dyn();

		virtual Void setComputedWidth( ::core::style::AbstractStyle style,int computedWidth);
		Dynamic setComputedWidth_dyn();

		virtual int getComputedWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedWidth_dyn();

		virtual int getComputedAutoWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoWidth_dyn();

		virtual int getComputedHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedHeight_dyn();

		virtual int getComputedAutoHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoHeight_dyn();

		virtual int getComputedMarginLeft( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginLeft_dyn();

		virtual int getComputedMarginRight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginRight_dyn();

		virtual int getComputedMarginTop( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginTop_dyn();

		virtual int getComputedMarginBottom( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedMarginBottom_dyn();

		virtual int getComputedMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedMargin_dyn();

		virtual int getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual int getComputedConstrainedDimension( ::core::style::ConstrainedDimension constrainedDimension,int containingHTMLElementDimension,bool isContainingDimensionAuto,double fontSize,double xHeight,Dynamic isMinConstraint);
		Dynamic getComputedConstrainedDimension_dyn();

		virtual int getComputedPositionOffset( ::core::style::PositionOffset positionOffsetStyleValue,int containingHTMLElementDimension,double fontSize,double xHeight);
		Dynamic getComputedPositionOffset_dyn();

		virtual int getComputedDimension( ::core::style::Dimension dimensionStyleValue,int containingHTMLElementDimension,bool isContainingDimensionAuto,double fontSize,double xHeight);
		Dynamic getComputedDimension_dyn();

		virtual int getComputedPadding( ::core::style::Padding paddingStyleValue,int containingHTMLElementDimension,double fontSize,double xHeight);
		Dynamic getComputedPadding_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_BoxStylesComputer */ 
