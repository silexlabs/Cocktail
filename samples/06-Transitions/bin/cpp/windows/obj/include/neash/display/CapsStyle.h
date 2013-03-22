#ifndef INCLUDED_neash_display_CapsStyle
#define INCLUDED_neash_display_CapsStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,CapsStyle)
namespace neash{
namespace display{


class CapsStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CapsStyle_obj OBJ_;

	public:
		CapsStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.CapsStyle"); }
		::String __ToString() const { return HX_CSTRING("CapsStyle.") + tag; }

		static ::neash::display::CapsStyle NONE;
		static inline ::neash::display::CapsStyle NONE_dyn() { return NONE; }
		static ::neash::display::CapsStyle ROUND;
		static inline ::neash::display::CapsStyle ROUND_dyn() { return ROUND; }
		static ::neash::display::CapsStyle SQUARE;
		static inline ::neash::display::CapsStyle SQUARE_dyn() { return SQUARE; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_CapsStyle */ 
