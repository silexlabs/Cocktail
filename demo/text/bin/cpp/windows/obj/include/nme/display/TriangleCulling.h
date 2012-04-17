#ifndef INCLUDED_nme_display_TriangleCulling
#define INCLUDED_nme_display_TriangleCulling

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,TriangleCulling)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.TriangleCulling"); }
		::String __ToString() const { return HX_CSTRING("TriangleCulling.") + tag; }

		static ::nme::display::TriangleCulling NEGATIVE;
		static inline ::nme::display::TriangleCulling NEGATIVE_dyn() { return NEGATIVE; }
		static ::nme::display::TriangleCulling NONE;
		static inline ::nme::display::TriangleCulling NONE_dyn() { return NONE; }
		static ::nme::display::TriangleCulling POSITIVE;
		static inline ::nme::display::TriangleCulling POSITIVE_dyn() { return POSITIVE; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_TriangleCulling */ 
