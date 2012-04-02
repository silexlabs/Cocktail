#ifndef INCLUDED_nme_display_SpreadMethod
#define INCLUDED_nme_display_SpreadMethod

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,SpreadMethod)
namespace nme{
namespace display{


class SpreadMethod_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SpreadMethod_obj OBJ_;

	public:
		SpreadMethod_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.SpreadMethod"); }
		::String __ToString() const { return HX_CSTRING("SpreadMethod.") + tag; }

		static ::nme::display::SpreadMethod PAD;
		static inline ::nme::display::SpreadMethod PAD_dyn() { return PAD; }
		static ::nme::display::SpreadMethod REFLECT;
		static inline ::nme::display::SpreadMethod REFLECT_dyn() { return REFLECT; }
		static ::nme::display::SpreadMethod REPEAT;
		static inline ::nme::display::SpreadMethod REPEAT_dyn() { return REPEAT; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_SpreadMethod */ 
