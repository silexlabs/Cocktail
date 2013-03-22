#ifndef INCLUDED_neash_display_JointStyle
#define INCLUDED_neash_display_JointStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,JointStyle)
namespace neash{
namespace display{


class JointStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef JointStyle_obj OBJ_;

	public:
		JointStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.JointStyle"); }
		::String __ToString() const { return HX_CSTRING("JointStyle.") + tag; }

		static ::neash::display::JointStyle BEVEL;
		static inline ::neash::display::JointStyle BEVEL_dyn() { return BEVEL; }
		static ::neash::display::JointStyle MITER;
		static inline ::neash::display::JointStyle MITER_dyn() { return MITER; }
		static ::neash::display::JointStyle ROUND;
		static inline ::neash::display::JointStyle ROUND_dyn() { return ROUND; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_JointStyle */ 
