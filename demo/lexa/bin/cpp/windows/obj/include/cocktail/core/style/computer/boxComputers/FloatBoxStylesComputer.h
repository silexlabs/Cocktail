#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,FloatBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,InlineBlockBoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class FloatBoxStylesComputer_obj : public ::cocktail::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj super;
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

		virtual int getComputedAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoWidth_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer */ 
