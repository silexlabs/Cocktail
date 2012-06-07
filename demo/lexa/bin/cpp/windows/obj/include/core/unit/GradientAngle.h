#ifndef INCLUDED_core_unit_GradientAngle
#define INCLUDED_core_unit_GradientAngle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,Angle)
HX_DECLARE_CLASS2(core,unit,GradientAngle)
HX_DECLARE_CLASS2(core,unit,GradientCornerValue)
HX_DECLARE_CLASS2(core,unit,GradientSideValue)
namespace core{
namespace unit{


class GradientAngle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientAngle_obj OBJ_;

	public:
		GradientAngle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.GradientAngle"); }
		::String __ToString() const { return HX_CSTRING("GradientAngle.") + tag; }

		static ::core::unit::GradientAngle angle(::core::unit::Angle value);
		static Dynamic angle_dyn();
		static ::core::unit::GradientAngle corner(::core::unit::GradientCornerValue value);
		static Dynamic corner_dyn();
		static ::core::unit::GradientAngle side(::core::unit::GradientSideValue value);
		static Dynamic side_dyn();
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_GradientAngle */ 
