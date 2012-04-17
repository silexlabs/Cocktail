#ifndef INCLUDED_cocktail_core_style_Padding
#define INCLUDED_cocktail_core_style_Padding

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Padding)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Padding"); }
		::String __ToString() const { return HX_CSTRING("Padding.") + tag; }

		static ::cocktail::core::style::Padding length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::Padding percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Padding */ 
