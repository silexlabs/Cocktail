#ifndef INCLUDED_core_unit_GradientValue
#define INCLUDED_core_unit_GradientValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,GradientValue)
namespace core{
namespace unit{


class GradientValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientValue_obj OBJ_;

	public:
		GradientValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.GradientValue"); }
		::String __ToString() const { return HX_CSTRING("GradientValue.") + tag; }

		static ::core::unit::GradientValue linear(Dynamic value);
		static Dynamic linear_dyn();
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_GradientValue */ 
