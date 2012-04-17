#ifndef INCLUDED_nme_display_CapsStyle
#define INCLUDED_nme_display_CapsStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,CapsStyle)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.CapsStyle"); }
		::String __ToString() const { return HX_CSTRING("CapsStyle.") + tag; }

		static ::nme::display::CapsStyle NONE;
		static inline ::nme::display::CapsStyle NONE_dyn() { return NONE; }
		static ::nme::display::CapsStyle ROUND;
		static inline ::nme::display::CapsStyle ROUND_dyn() { return ROUND; }
		static ::nme::display::CapsStyle SQUARE;
		static inline ::nme::display::CapsStyle SQUARE_dyn() { return SQUARE; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_CapsStyle */ 
