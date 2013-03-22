#ifndef INCLUDED_neash_display_SpreadMethod
#define INCLUDED_neash_display_SpreadMethod

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,SpreadMethod)
namespace neash{
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
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.SpreadMethod"); }
		::String __ToString() const { return HX_CSTRING("SpreadMethod.") + tag; }

		static ::neash::display::SpreadMethod PAD;
		static inline ::neash::display::SpreadMethod PAD_dyn() { return PAD; }
		static ::neash::display::SpreadMethod REFLECT;
		static inline ::neash::display::SpreadMethod REFLECT_dyn() { return REFLECT; }
		static ::neash::display::SpreadMethod REPEAT;
		static inline ::neash::display::SpreadMethod REPEAT_dyn() { return REPEAT; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_SpreadMethod */ 
