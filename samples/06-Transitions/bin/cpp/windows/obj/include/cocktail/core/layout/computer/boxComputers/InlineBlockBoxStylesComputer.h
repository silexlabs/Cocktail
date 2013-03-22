#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_InlineBlockBoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_InlineBlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,InlineBlockBoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class InlineBlockBoxStylesComputer_obj : public ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineBlockBoxStylesComputer"); }

		virtual Float getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin);

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_InlineBlockBoxStylesComputer */ 
