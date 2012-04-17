#ifndef INCLUDED_cocktail_core_style_ConstrainedDimension
#define INCLUDED_cocktail_core_style_ConstrainedDimension

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,ConstrainedDimension)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class ConstrainedDimension_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ConstrainedDimension_obj OBJ_;

	public:
		ConstrainedDimension_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.ConstrainedDimension"); }
		::String __ToString() const { return HX_CSTRING("ConstrainedDimension.") + tag; }

		static ::cocktail::core::style::ConstrainedDimension length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::ConstrainedDimension none;
		static inline ::cocktail::core::style::ConstrainedDimension none_dyn() { return none; }
		static ::cocktail::core::style::ConstrainedDimension percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_ConstrainedDimension */ 
