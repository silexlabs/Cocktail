#ifndef INCLUDED_neash_display_StageScaleMode
#define INCLUDED_neash_display_StageScaleMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,StageScaleMode)
namespace neash{
namespace display{


class StageScaleMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageScaleMode_obj OBJ_;

	public:
		StageScaleMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.StageScaleMode"); }
		::String __ToString() const { return HX_CSTRING("StageScaleMode.") + tag; }

		static ::neash::display::StageScaleMode EXACT_FIT;
		static inline ::neash::display::StageScaleMode EXACT_FIT_dyn() { return EXACT_FIT; }
		static ::neash::display::StageScaleMode NO_BORDER;
		static inline ::neash::display::StageScaleMode NO_BORDER_dyn() { return NO_BORDER; }
		static ::neash::display::StageScaleMode NO_SCALE;
		static inline ::neash::display::StageScaleMode NO_SCALE_dyn() { return NO_SCALE; }
		static ::neash::display::StageScaleMode SHOW_ALL;
		static inline ::neash::display::StageScaleMode SHOW_ALL_dyn() { return SHOW_ALL; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageScaleMode */ 
