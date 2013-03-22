#ifndef INCLUDED_neash_display_TriangleCulling
#define INCLUDED_neash_display_TriangleCulling

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,TriangleCulling)
namespace neash{
namespace display{


class TriangleCulling_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TriangleCulling_obj OBJ_;

	public:
		TriangleCulling_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.TriangleCulling"); }
		::String __ToString() const { return HX_CSTRING("TriangleCulling.") + tag; }

		static ::neash::display::TriangleCulling NEGATIVE;
		static inline ::neash::display::TriangleCulling NEGATIVE_dyn() { return NEGATIVE; }
		static ::neash::display::TriangleCulling NONE;
		static inline ::neash::display::TriangleCulling NONE_dyn() { return NONE; }
		static ::neash::display::TriangleCulling POSITIVE;
		static inline ::neash::display::TriangleCulling POSITIVE_dyn() { return POSITIVE; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_TriangleCulling */ 
