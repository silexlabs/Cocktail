#ifndef INCLUDED_nme_display_GradientType
#define INCLUDED_nme_display_GradientType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,GradientType)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.GradientType"); }
		::String __ToString() const { return HX_CSTRING("GradientType.") + tag; }

		static ::nme::display::GradientType LINEAR;
		static inline ::nme::display::GradientType LINEAR_dyn() { return LINEAR; }
		static ::nme::display::GradientType RADIAL;
		static inline ::nme::display::GradientType RADIAL_dyn() { return RADIAL; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_GradientType */ 
