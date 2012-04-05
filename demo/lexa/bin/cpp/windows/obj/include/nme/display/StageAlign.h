#ifndef INCLUDED_nme_display_StageAlign
#define INCLUDED_nme_display_StageAlign

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,StageAlign)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.StageAlign"); }
		::String __ToString() const { return HX_CSTRING("StageAlign.") + tag; }

		static ::nme::display::StageAlign BOTTOM;
		static inline ::nme::display::StageAlign BOTTOM_dyn() { return BOTTOM; }
		static ::nme::display::StageAlign BOTTOM_LEFT;
		static inline ::nme::display::StageAlign BOTTOM_LEFT_dyn() { return BOTTOM_LEFT; }
		static ::nme::display::StageAlign BOTTOM_RIGHT;
		static inline ::nme::display::StageAlign BOTTOM_RIGHT_dyn() { return BOTTOM_RIGHT; }
		static ::nme::display::StageAlign LEFT;
		static inline ::nme::display::StageAlign LEFT_dyn() { return LEFT; }
		static ::nme::display::StageAlign RIGHT;
		static inline ::nme::display::StageAlign RIGHT_dyn() { return RIGHT; }
		static ::nme::display::StageAlign TOP;
		static inline ::nme::display::StageAlign TOP_dyn() { return TOP; }
		static ::nme::display::StageAlign TOP_LEFT;
		static inline ::nme::display::StageAlign TOP_LEFT_dyn() { return TOP_LEFT; }
		static ::nme::display::StageAlign TOP_RIGHT;
		static inline ::nme::display::StageAlign TOP_RIGHT_dyn() { return TOP_RIGHT; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_StageAlign */ 
