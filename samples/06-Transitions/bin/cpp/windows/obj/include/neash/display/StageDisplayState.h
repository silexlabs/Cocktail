#ifndef INCLUDED_neash_display_StageDisplayState
#define INCLUDED_neash_display_StageDisplayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,StageDisplayState)
namespace neash{
namespace display{


class StageDisplayState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageDisplayState_obj OBJ_;

	public:
		StageDisplayState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.StageDisplayState"); }
		::String __ToString() const { return HX_CSTRING("StageDisplayState.") + tag; }

		static ::neash::display::StageDisplayState FULL_SCREEN;
		static inline ::neash::display::StageDisplayState FULL_SCREEN_dyn() { return FULL_SCREEN; }
		static ::neash::display::StageDisplayState FULL_SCREEN_INTERACTIVE;
		static inline ::neash::display::StageDisplayState FULL_SCREEN_INTERACTIVE_dyn() { return FULL_SCREEN_INTERACTIVE; }
		static ::neash::display::StageDisplayState NORMAL;
		static inline ::neash::display::StageDisplayState NORMAL_dyn() { return NORMAL; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageDisplayState */ 
