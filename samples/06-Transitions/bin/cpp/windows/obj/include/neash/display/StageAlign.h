#ifndef INCLUDED_neash_display_StageAlign
#define INCLUDED_neash_display_StageAlign

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,StageAlign)
namespace neash{
namespace display{


class StageAlign_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageAlign_obj OBJ_;

	public:
		StageAlign_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.StageAlign"); }
		::String __ToString() const { return HX_CSTRING("StageAlign.") + tag; }

		static ::neash::display::StageAlign BOTTOM;
		static inline ::neash::display::StageAlign BOTTOM_dyn() { return BOTTOM; }
		static ::neash::display::StageAlign BOTTOM_LEFT;
		static inline ::neash::display::StageAlign BOTTOM_LEFT_dyn() { return BOTTOM_LEFT; }
		static ::neash::display::StageAlign BOTTOM_RIGHT;
		static inline ::neash::display::StageAlign BOTTOM_RIGHT_dyn() { return BOTTOM_RIGHT; }
		static ::neash::display::StageAlign LEFT;
		static inline ::neash::display::StageAlign LEFT_dyn() { return LEFT; }
		static ::neash::display::StageAlign RIGHT;
		static inline ::neash::display::StageAlign RIGHT_dyn() { return RIGHT; }
		static ::neash::display::StageAlign TOP;
		static inline ::neash::display::StageAlign TOP_dyn() { return TOP; }
		static ::neash::display::StageAlign TOP_LEFT;
		static inline ::neash::display::StageAlign TOP_LEFT_dyn() { return TOP_LEFT; }
		static ::neash::display::StageAlign TOP_RIGHT;
		static inline ::neash::display::StageAlign TOP_RIGHT_dyn() { return TOP_RIGHT; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_StageAlign */ 
