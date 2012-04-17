#ifndef INCLUDED_cocktail_core_unit_GradientAngle
#define INCLUDED_cocktail_core_unit_GradientAngle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,Angle)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientAngle)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientCornerValue)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientSideValue)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.GradientAngle"); }
		::String __ToString() const { return HX_CSTRING("GradientAngle.") + tag; }

		static ::cocktail::core::unit::GradientAngle angle(::cocktail::core::unit::Angle value);
		static Dynamic angle_dyn();
		static ::cocktail::core::unit::GradientAngle corner(::cocktail::core::unit::GradientCornerValue value);
		static Dynamic corner_dyn();
		static ::cocktail::core::unit::GradientAngle side(::cocktail::core::unit::GradientSideValue value);
		static Dynamic side_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_GradientAngle */ 
