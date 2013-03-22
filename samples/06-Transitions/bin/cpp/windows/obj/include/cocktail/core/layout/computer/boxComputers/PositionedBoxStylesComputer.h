#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_PositionedBoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_PositionedBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,PositionedBoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class PositionedBoxStylesComputer_obj : public ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PositionedBoxStylesComputer"); }

		virtual Float getComputedStaticTop( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedStaticTop_dyn();

		virtual Float getComputedStaticLeft( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedStaticLeft_dyn();

		virtual Float measureHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float measureAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float measureWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float measureAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Void measurePositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_PositionedBoxStylesComputer */ 
