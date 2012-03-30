#ifndef INCLUDED_core_style_computer_boxComputers_InlineBlockBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_InlineBlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,Margin)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,InlineBlockBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class InlineBlockBoxStylesComputer_obj : public ::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::BoxStylesComputer_obj super;
		typedef InlineBlockBoxStylesComputer_obj OBJ_;
		InlineBlockBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InlineBlockBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InlineBlockBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineBlockBoxStylesComputer"); }

		virtual int getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual int shrinkToFit( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic shrinkToFit_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_InlineBlockBoxStylesComputer */ 
