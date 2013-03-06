#ifndef INCLUDED_cocktail_core_layout_LayoutManager
#define INCLUDED_cocktail_core_layout_LayoutManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,layout,LayoutManager)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedFloatBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedInlineBlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedInlineBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,EmbeddedPositionedBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,FloatBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,InLineBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,InlineBlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,PositionedBoxStylesComputer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layout{


class LayoutManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LayoutManager_obj OBJ_;
		LayoutManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< LayoutManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LayoutManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LayoutManager"); }

		virtual ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer getBoxStylesComputer( ::cocktail::core::renderer::ElementRenderer elementRenderer);
		Dynamic getBoxStylesComputer_dyn();

		::cocktail::core::layout::computer::boxComputers::PositionedBoxStylesComputer positionedBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::InLineBoxStylesComputer inlineBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::InlineBlockBoxStylesComputer inlineBlockBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::FloatBoxStylesComputer floatBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::EmbeddedPositionedBoxStylesComputer embeddedPositionedBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBoxStylesComputer embeddedInlineBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::EmbeddedInlineBlockBoxStylesComputer embeddedInlineBlockBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::EmbeddedFloatBoxStylesComputer embeddedFloatBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::EmbeddedBlockBoxStylesComputer embeddedBlockBoxStylesComputer; /* REM */ 
		::cocktail::core::layout::computer::boxComputers::BlockBoxStylesComputer blockBoxStyleComputer; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout

#endif /* INCLUDED_cocktail_core_layout_LayoutManager */ 
