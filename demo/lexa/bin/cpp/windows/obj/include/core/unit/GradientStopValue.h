#ifndef INCLUDED_core_unit_GradientStopValue
#define INCLUDED_core_unit_GradientStopValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,GradientStopValue)
HX_DECLARE_CLASS2(core,unit,Length)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.GradientStopValue"); }
		::String __ToString() const { return HX_CSTRING("GradientStopValue.") + tag; }

		static ::core::unit::GradientStopValue length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::unit::GradientStopValue percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_GradientStopValue */ 
