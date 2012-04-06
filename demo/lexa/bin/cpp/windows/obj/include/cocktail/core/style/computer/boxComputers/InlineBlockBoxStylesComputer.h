#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,InlineBlockBoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class InlineBlockBoxStylesComputer_obj : public ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj super;
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

		virtual int getComputedAutoMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual int shrinkToFit( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic shrinkToFit_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer */ 
