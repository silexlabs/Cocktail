#ifndef INCLUDED_core_style_Dimension
#define INCLUDED_core_style_Dimension

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Dimension)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class Dimension_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Dimension_obj OBJ_;

	public:
		Dimension_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Dimension"); }
		::String __ToString() const { return HX_CSTRING("Dimension.") + tag; }

		static ::core::style::Dimension cssAuto;
		static inline ::core::style::Dimension cssAuto_dyn() { return cssAuto; }
		static ::core::style::Dimension length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::Dimension percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Dimension */ 
