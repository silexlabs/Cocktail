#ifndef INCLUDED_cocktail_core_style_BackgroundSizeDimension
#define INCLUDED_cocktail_core_style_BackgroundSizeDimension

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSizeDimension)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class BackgroundSizeDimension_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundSizeDimension_obj OBJ_;

	public:
		BackgroundSizeDimension_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundSizeDimension"); }
		::String __ToString() const { return HX_CSTRING("BackgroundSizeDimension.") + tag; }

		static ::cocktail::core::style::BackgroundSizeDimension cssAuto;
		static inline ::cocktail::core::style::BackgroundSizeDimension cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::style::BackgroundSizeDimension length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::BackgroundSizeDimension percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundSizeDimension */ 
