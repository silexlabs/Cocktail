#ifndef INCLUDED_cocktail_core_unit_GradientSideValue
#define INCLUDED_cocktail_core_unit_GradientSideValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,GradientSideValue)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.GradientSideValue"); }
		::String __ToString() const { return HX_CSTRING("GradientSideValue.") + tag; }

		static ::cocktail::core::unit::GradientSideValue bottom;
		static inline ::cocktail::core::unit::GradientSideValue bottom_dyn() { return bottom; }
		static ::cocktail::core::unit::GradientSideValue left;
		static inline ::cocktail::core::unit::GradientSideValue left_dyn() { return left; }
		static ::cocktail::core::unit::GradientSideValue right;
		static inline ::cocktail::core::unit::GradientSideValue right_dyn() { return right; }
		static ::cocktail::core::unit::GradientSideValue top;
		static inline ::cocktail::core::unit::GradientSideValue top_dyn() { return top; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_GradientSideValue */ 
