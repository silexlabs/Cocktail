#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BlockBoxStylesComputer
#define INCLUDED_cocktail_core_layout_computer_boxComputers_BlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,layout,computer,boxComputers,BoxStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{


class BlockBoxStylesComputer_obj : public ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::layout::computer::boxComputers::BoxStylesComputer_obj super;
		typedef BlockBoxStylesComputer_obj OBJ_;
		BlockBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BlockBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlockBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlockBoxStylesComputer"); }

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_layout_computer_boxComputers_BlockBoxStylesComputer */ 
