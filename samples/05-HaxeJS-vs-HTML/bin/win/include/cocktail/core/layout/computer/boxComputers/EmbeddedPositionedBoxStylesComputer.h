#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedPositionedBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedPositionedBoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class EmbeddedPositionedBoxStylesComputer_obj : public ::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj super;
		typedef EmbeddedPositionedBoxStylesComputer_obj OBJ_;
		EmbeddedPositionedBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedPositionedBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedPositionedBoxStylesComputer"); }

		virtual Float getComputedStaticTop( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedStaticTop_dyn();

		virtual Float getComputedStaticLeft( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic getComputedStaticLeft_dyn();

		virtual Void measureVerticalPositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureVerticalPositionOffsets_dyn();

		virtual Void measureHorizontalPositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);
		Dynamic measureHorizontalPositionOffsets_dyn();

		virtual Void measurePositionOffsets( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedPositionedBoxStylesComputer */ 
