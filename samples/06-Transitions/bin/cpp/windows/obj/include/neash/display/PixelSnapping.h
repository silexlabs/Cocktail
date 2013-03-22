#ifndef INCLUDED_neash_display_PixelSnapping
#define INCLUDED_neash_display_PixelSnapping

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,PixelSnapping)
namespace neash{
namespace display{


class PixelSnapping_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PixelSnapping_obj OBJ_;

	public:
		PixelSnapping_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.PixelSnapping"); }
		::String __ToString() const { return HX_CSTRING("PixelSnapping.") + tag; }

		static ::neash::display::PixelSnapping ALWAYS;
		static inline ::neash::display::PixelSnapping ALWAYS_dyn() { return ALWAYS; }
		static ::neash::display::PixelSnapping AUTO;
		static inline ::neash::display::PixelSnapping AUTO_dyn() { return AUTO; }
		static ::neash::display::PixelSnapping NEVER;
		static inline ::neash::display::PixelSnapping NEVER_dyn() { return NEVER; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_PixelSnapping */ 
