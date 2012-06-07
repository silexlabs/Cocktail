#ifndef INCLUDED_core_style_Padding
#define INCLUDED_core_style_Padding

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Padding)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class Padding_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Padding_obj OBJ_;

	public:
		Padding_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Padding"); }
		::String __ToString() const { return HX_CSTRING("Padding.") + tag; }

		static ::core::style::Padding length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::Padding percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Padding */ 
