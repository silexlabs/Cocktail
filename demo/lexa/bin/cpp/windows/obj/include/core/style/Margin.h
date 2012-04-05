#ifndef INCLUDED_core_style_Margin
#define INCLUDED_core_style_Margin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Margin)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class Margin_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Margin_obj OBJ_;

	public:
		Margin_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Margin"); }
		::String __ToString() const { return HX_CSTRING("Margin.") + tag; }

		static ::core::style::Margin cssAuto;
		static inline ::core::style::Margin cssAuto_dyn() { return cssAuto; }
		static ::core::style::Margin length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::Margin percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Margin */ 
