#ifndef INCLUDED_cocktail_core_style_Margin
#define INCLUDED_cocktail_core_style_Margin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Margin"); }
		::String __ToString() const { return HX_CSTRING("Margin.") + tag; }

		static ::cocktail::core::style::Margin cssAuto;
		static inline ::cocktail::core::style::Margin cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::style::Margin length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::Margin percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Margin */ 
