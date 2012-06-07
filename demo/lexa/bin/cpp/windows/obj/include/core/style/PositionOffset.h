#ifndef INCLUDED_core_style_PositionOffset
#define INCLUDED_core_style_PositionOffset

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,PositionOffset)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class PositionOffset_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PositionOffset_obj OBJ_;

	public:
		PositionOffset_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.PositionOffset"); }
		::String __ToString() const { return HX_CSTRING("PositionOffset.") + tag; }

		static ::core::style::PositionOffset cssAuto;
		static inline ::core::style::PositionOffset cssAuto_dyn() { return cssAuto; }
		static ::core::style::PositionOffset length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::PositionOffset percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_PositionOffset */ 
