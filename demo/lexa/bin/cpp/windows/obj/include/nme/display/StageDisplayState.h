#ifndef INCLUDED_nme_display_StageDisplayState
#define INCLUDED_nme_display_StageDisplayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,StageDisplayState)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.StageDisplayState"); }
		::String __ToString() const { return HX_CSTRING("StageDisplayState.") + tag; }

		static ::nme::display::StageDisplayState FULL_SCREEN;
		static inline ::nme::display::StageDisplayState FULL_SCREEN_dyn() { return FULL_SCREEN; }
		static ::nme::display::StageDisplayState FULL_SCREEN_INTERACTIVE;
		static inline ::nme::display::StageDisplayState FULL_SCREEN_INTERACTIVE_dyn() { return FULL_SCREEN_INTERACTIVE; }
		static ::nme::display::StageDisplayState NORMAL;
		static inline ::nme::display::StageDisplayState NORMAL_dyn() { return NORMAL; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_StageDisplayState */ 
