#ifndef INCLUDED_neash_display_StageQuality
#define INCLUDED_neash_display_StageQuality

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,StageQuality)
namespace neash{
namespace display{


class StageQuality_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageQuality_obj OBJ_;

	public:
		StageQuality_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.StageQuality"); }
		::String __ToString() const { return HX_CSTRING("StageQuality.") + tag; }

		static ::neash::display::StageQuality BEST;
		static inline ::neash::display::StageQuality BEST_dyn() { return BEST; }
		static ::neash::display::StageQuality HIGH;
		static inline ::neash::display::StageQuality HIGH_dyn() { return HIGH; }
		static ::neash::display::StageQuality LOW;
		static inline ::neash::display::StageQuality LOW_dyn() { return LOW; }
		static ::neash::display::StageQuality MEDIUM;
		static inline ::neash::display::StageQuality MEDIUM_dyn() { return MEDIUM; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageQuality */ 
