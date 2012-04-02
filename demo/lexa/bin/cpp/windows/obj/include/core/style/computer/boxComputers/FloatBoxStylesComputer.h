#ifndef INCLUDED_core_style_computer_boxComputers_FloatBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_FloatBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,FloatBoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,InlineBlockBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class FloatBoxStylesComputer_obj : public ::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj super;
		typedef FloatBoxStylesComputer_obj OBJ_;
		FloatBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FloatBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FloatBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FloatBoxStylesComputer"); }

		virtual int getComputedAutoWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoWidth_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_FloatBoxStylesComputer */ 
