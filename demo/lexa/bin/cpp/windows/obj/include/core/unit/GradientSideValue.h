#ifndef INCLUDED_core_unit_GradientSideValue
#define INCLUDED_core_unit_GradientSideValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,GradientSideValue)
namespace core{
namespace unit{


class GradientSideValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientSideValue_obj OBJ_;

	public:
		GradientSideValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.GradientSideValue"); }
		::String __ToString() const { return HX_CSTRING("GradientSideValue.") + tag; }

		static ::core::unit::GradientSideValue bottom;
		static inline ::core::unit::GradientSideValue bottom_dyn() { return bottom; }
		static ::core::unit::GradientSideValue left;
		static inline ::core::unit::GradientSideValue left_dyn() { return left; }
		static ::core::unit::GradientSideValue right;
		static inline ::core::unit::GradientSideValue right_dyn() { return right; }
		static ::core::unit::GradientSideValue top;
		static inline ::core::unit::GradientSideValue top_dyn() { return top; }
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_GradientSideValue */ 
