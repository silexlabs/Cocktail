#ifndef INCLUDED_neash_display_GradientType
#define INCLUDED_neash_display_GradientType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,GradientType)
namespace neash{
namespace display{


class GradientType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientType_obj OBJ_;

	public:
		GradientType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.GradientType"); }
		::String __ToString() const { return HX_CSTRING("GradientType.") + tag; }

		static ::neash::display::GradientType LINEAR;
		static inline ::neash::display::GradientType LINEAR_dyn() { return LINEAR; }
		static ::neash::display::GradientType RADIAL;
		static inline ::neash::display::GradientType RADIAL_dyn() { return RADIAL; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_GradientType */ 
