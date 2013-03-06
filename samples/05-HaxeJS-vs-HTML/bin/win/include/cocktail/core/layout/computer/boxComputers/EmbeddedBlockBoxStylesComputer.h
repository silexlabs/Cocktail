#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class EmbeddedBlockBoxStylesComputer_obj : public ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj super;
		typedef EmbeddedBlockBoxStylesComputer_obj OBJ_;
		EmbeddedBlockBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedBlockBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedBlockBoxStylesComputer"); }

		virtual Float getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin);

		virtual Float getComputedAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float getComputedAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Float measureAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

		virtual Void constrainDimensions( ::cocktail::core::css::CoreStyle style,Float usedWidth,Float usedHeight);
		Dynamic constrainDimensions_dyn();

		virtual Void measureDimensionsAndMargins( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData);

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer */ 
