#ifndef INCLUDED_cocktail_core_unit_GradientCornerValue
#define INCLUDED_cocktail_core_unit_GradientCornerValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,GradientCornerValue)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.GradientCornerValue"); }
		::String __ToString() const { return HX_CSTRING("GradientCornerValue.") + tag; }

		static ::cocktail::core::unit::GradientCornerValue bottomLeft;
		static inline ::cocktail::core::unit::GradientCornerValue bottomLeft_dyn() { return bottomLeft; }
		static ::cocktail::core::unit::GradientCornerValue bottomRight;
		static inline ::cocktail::core::unit::GradientCornerValue bottomRight_dyn() { return bottomRight; }
		static ::cocktail::core::unit::GradientCornerValue topLeft;
		static inline ::cocktail::core::unit::GradientCornerValue topLeft_dyn() { return topLeft; }
		static ::cocktail::core::unit::GradientCornerValue topRight;
		static inline ::cocktail::core::unit::GradientCornerValue topRight_dyn() { return topRight; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_GradientCornerValue */ 
