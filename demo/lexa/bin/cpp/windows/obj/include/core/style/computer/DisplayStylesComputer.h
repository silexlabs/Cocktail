#ifndef INCLUDED_core_style_computer_DisplayStylesComputer
#define INCLUDED_core_style_computer_DisplayStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,CSSFloat)
HX_DECLARE_CLASS2(core,style,Clear)
HX_DECLARE_CLASS2(core,style,Display)
HX_DECLARE_CLASS2(core,style,Position)
HX_DECLARE_CLASS3(core,style,computer,DisplayStylesComputer)
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

		static Void compute( ::core::style::AbstractStyle style);
		static Dynamic compute_dyn();

		static ::core::style::Position getComputedPosition( ::core::style::AbstractStyle style);
		static Dynamic getComputedPosition_dyn();

		static ::core::style::CSSFloat getComputedFloat( ::core::style::AbstractStyle style,::core::style::Position computedPosition);
		static Dynamic getComputedFloat_dyn();

		static ::core::style::Display getComputedDisplay( ::core::style::AbstractStyle style,::core::style::CSSFloat computedFloat);
		static Dynamic getComputedDisplay_dyn();

		static ::core::style::Clear getComputedClear( ::core::style::AbstractStyle style,::core::style::Position computedPosition,::core::style::Display computedDisplay);
		static Dynamic getComputedClear_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_core_style_computer_DisplayStylesComputer */ 
