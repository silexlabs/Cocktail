#ifndef INCLUDED_core_style_BackgroundPositionX
#define INCLUDED_core_style_BackgroundPositionX

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundPositionX)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class BackgroundPositionX_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundPositionX_obj OBJ_;

	public:
		BackgroundPositionX_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundPositionX"); }
		::String __ToString() const { return HX_CSTRING("BackgroundPositionX.") + tag; }

		static ::core::style::BackgroundPositionX center;
		static inline ::core::style::BackgroundPositionX center_dyn() { return center; }
		static ::core::style::BackgroundPositionX left;
		static inline ::core::style::BackgroundPositionX left_dyn() { return left; }
		static ::core::style::BackgroundPositionX length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::BackgroundPositionX percent(int value);
		static Dynamic percent_dyn();
		static ::core::style::BackgroundPositionX right;
		static inline ::core::style::BackgroundPositionX right_dyn() { return right; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundPositionX */ 
