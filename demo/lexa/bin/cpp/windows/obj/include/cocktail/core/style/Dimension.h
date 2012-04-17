#ifndef INCLUDED_cocktail_core_style_Dimension
#define INCLUDED_cocktail_core_style_Dimension

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Dimension)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Dimension"); }
		::String __ToString() const { return HX_CSTRING("Dimension.") + tag; }

		static ::cocktail::core::style::Dimension cssAuto;
		static inline ::cocktail::core::style::Dimension cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::style::Dimension length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::Dimension percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Dimension */ 
