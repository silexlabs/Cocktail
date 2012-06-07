#ifndef INCLUDED_core_unit_Angle
#define INCLUDED_core_unit_Angle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,Angle)
namespace core{
namespace unit{


class Angle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Angle_obj OBJ_;

	public:
		Angle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.Angle"); }
		::String __ToString() const { return HX_CSTRING("Angle.") + tag; }

		static ::core::unit::Angle deg(double value);
		static Dynamic deg_dyn();
		static ::core::unit::Angle grad(double value);
		static Dynamic grad_dyn();
		static ::core::unit::Angle rad(double value);
		static Dynamic rad_dyn();
		static ::core::unit::Angle turn(double value);
		static Dynamic turn_dyn();
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_Angle */ 
