#ifndef INCLUDED_core_style_computer_boxComputers_BlockBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_BlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BlockBoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class BlockBoxStylesComputer_obj : public ::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::BoxStylesComputer_obj super;
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
		::String __ToString() const { return HX_CSTRING("BlockBoxStylesComputer"); }

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_BlockBoxStylesComputer */ 
