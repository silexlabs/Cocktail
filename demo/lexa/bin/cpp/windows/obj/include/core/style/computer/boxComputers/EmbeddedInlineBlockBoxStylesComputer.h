#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedInlineBlockBoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedInlineBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class EmbeddedInlineBlockBoxStylesComputer_obj : public ::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::EmbeddedInlineBoxStylesComputer_obj super;
		typedef EmbeddedInlineBlockBoxStylesComputer_obj OBJ_;
		EmbeddedInlineBlockBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EmbeddedInlineBlockBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedInlineBlockBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedInlineBlockBoxStylesComputer"); }

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer */ 
