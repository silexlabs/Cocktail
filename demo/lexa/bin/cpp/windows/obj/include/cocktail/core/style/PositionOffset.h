#ifndef INCLUDED_cocktail_core_style_PositionOffset
#define INCLUDED_cocktail_core_style_PositionOffset

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,PositionOffset)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.PositionOffset"); }
		::String __ToString() const { return HX_CSTRING("PositionOffset.") + tag; }

		static ::cocktail::core::style::PositionOffset cssAuto;
		static inline ::cocktail::core::style::PositionOffset cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::style::PositionOffset length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::PositionOffset percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_PositionOffset */ 
