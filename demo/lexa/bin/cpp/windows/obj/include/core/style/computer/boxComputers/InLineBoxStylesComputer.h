#ifndef INCLUDED_core_style_computer_boxComputers_InLineBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_InLineBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,Margin)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,InLineBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class InLineBoxStylesComputer_obj : public ::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::BoxStylesComputer_obj super;
		typedef InLineBoxStylesComputer_obj OBJ_;
		InLineBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InLineBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InLineBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InLineBoxStylesComputer"); }

		virtual Void measureVerticalPaddings( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureVerticalPaddings_dyn();

		virtual Void measureAutoHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoHeight_dyn();

		virtual Void measureHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeight_dyn();

		virtual int getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual int getComputedWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedWidth_dyn();

		virtual int getComputedHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedHeight_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_InLineBoxStylesComputer */ 
