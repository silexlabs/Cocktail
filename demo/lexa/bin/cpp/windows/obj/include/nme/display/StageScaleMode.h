#ifndef INCLUDED_nme_display_StageScaleMode
#define INCLUDED_nme_display_StageScaleMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,StageScaleMode)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.StageScaleMode"); }
		::String __ToString() const { return HX_CSTRING("StageScaleMode.") + tag; }

		static ::nme::display::StageScaleMode EXACT_FIT;
		static inline ::nme::display::StageScaleMode EXACT_FIT_dyn() { return EXACT_FIT; }
		static ::nme::display::StageScaleMode NO_BORDER;
		static inline ::nme::display::StageScaleMode NO_BORDER_dyn() { return NO_BORDER; }
		static ::nme::display::StageScaleMode NO_SCALE;
		static inline ::nme::display::StageScaleMode NO_SCALE_dyn() { return NO_SCALE; }
		static ::nme::display::StageScaleMode SHOW_ALL;
		static inline ::nme::display::StageScaleMode SHOW_ALL_dyn() { return SHOW_ALL; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_StageScaleMode */ 
