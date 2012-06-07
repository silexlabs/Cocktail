#ifndef INCLUDED_cocktail_core_style_computer_DisplayStylesComputer
#define INCLUDED_cocktail_core_style_computer_DisplayStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,CSSFloat)
HX_DECLARE_CLASS3(cocktail,core,style,Clear)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Display)
HX_DECLARE_CLASS3(cocktail,core,style,Position)
HX_DECLARE_CLASS4(cocktail,core,style,computer,DisplayStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{


class DisplayStylesComputer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DisplayStylesComputer_obj OBJ_;
		DisplayStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DisplayStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisplayStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("DisplayStylesComputer"); }

		static Void compute( ::cocktail::core::style::CoreStyle style);
		static Dynamic compute_dyn();

		static ::cocktail::core::style::Position getComputedPosition( ::cocktail::core::style::CoreStyle style);
		static Dynamic getComputedPosition_dyn();

		static ::cocktail::core::style::CSSFloat getComputedFloat( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::Position computedPosition);
		static Dynamic getComputedFloat_dyn();

		static ::cocktail::core::style::Display getComputedDisplay( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::CSSFloat computedFloat);
		static Dynamic getComputedDisplay_dyn();

		static ::cocktail::core::style::Clear getComputedClear( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::Position computedPosition,::cocktail::core::style::Display computedDisplay);
		static Dynamic getComputedClear_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_cocktail_core_style_computer_DisplayStylesComputer */ 
