#ifndef INCLUDED_core_unit_GradientCornerValue
#define INCLUDED_core_unit_GradientCornerValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,GradientCornerValue)
namespace core{
namespace unit{


class GradientCornerValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientCornerValue_obj OBJ_;

	public:
		GradientCornerValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.GradientCornerValue"); }
		::String __ToString() const { return HX_CSTRING("GradientCornerValue.") + tag; }

		static ::core::unit::GradientCornerValue bottomLeft;
		static inline ::core::unit::GradientCornerValue bottomLeft_dyn() { return bottomLeft; }
		static ::core::unit::GradientCornerValue bottomRight;
		static inline ::core::unit::GradientCornerValue bottomRight_dyn() { return bottomRight; }
		static ::core::unit::GradientCornerValue topLeft;
		static inline ::core::unit::GradientCornerValue topLeft_dyn() { return topLeft; }
		static ::core::unit::GradientCornerValue topRight;
		static inline ::core::unit::GradientCornerValue topRight_dyn() { return topRight; }
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_GradientCornerValue */ 
