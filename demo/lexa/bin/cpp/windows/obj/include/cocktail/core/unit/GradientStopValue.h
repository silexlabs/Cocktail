#ifndef INCLUDED_cocktail_core_unit_GradientStopValue
#define INCLUDED_cocktail_core_unit_GradientStopValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,GradientStopValue)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace unit{


class GradientStopValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientStopValue_obj OBJ_;

	public:
		GradientStopValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.GradientStopValue"); }
		::String __ToString() const { return HX_CSTRING("GradientStopValue.") + tag; }

		static ::cocktail::core::unit::GradientStopValue length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::unit::GradientStopValue percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_GradientStopValue */ 
