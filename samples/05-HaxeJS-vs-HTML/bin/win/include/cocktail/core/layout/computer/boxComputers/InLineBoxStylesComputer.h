#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_InLineBoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_InLineBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,InLineBoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class InLineBoxStylesComputer_obj : public ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InLineBoxStylesComputer"); }

		virtual Float getComputedHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float getComputedWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin);

		virtual Float measureHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float measureAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_InLineBoxStylesComputer */ 
