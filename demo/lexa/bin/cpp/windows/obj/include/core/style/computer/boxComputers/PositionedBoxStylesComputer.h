#ifndef INCLUDED_core_style_computer_boxComputers_PositionedBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_PositionedBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,PositionedBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class PositionedBoxStylesComputer_obj : public ::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::BoxStylesComputer_obj super;
		typedef PositionedBoxStylesComputer_obj OBJ_;
		PositionedBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PositionedBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PositionedBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PositionedBoxStylesComputer"); }

		virtual int shrinkToFit( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic shrinkToFit_dyn();

		virtual int applyContentHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,int childrenHeight);
		Dynamic applyContentHeight_dyn();

		virtual Void measurePositionOffsets( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureAutoWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoWidth_dyn();

		virtual Void measureWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureWidth_dyn();

		virtual Void measureAutoHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoHeight_dyn();

		virtual Void measureHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeight_dyn();

		virtual int getComputedStaticLeft( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticLeft_dyn();

		virtual int getComputedStaticTop( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticTop_dyn();

		virtual int doShrinkToFit( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic doShrinkToFit_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_PositionedBoxStylesComputer */ 
