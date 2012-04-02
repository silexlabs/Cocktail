#ifndef INCLUDED_core_style_BackgroundPositionY
#define INCLUDED_core_style_BackgroundPositionY

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundPositionY)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class BackgroundPositionY_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundPositionY_obj OBJ_;

	public:
		BackgroundPositionY_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundPositionY"); }
		::String __ToString() const { return HX_CSTRING("BackgroundPositionY.") + tag; }

		static ::core::style::BackgroundPositionY bottom;
		static inline ::core::style::BackgroundPositionY bottom_dyn() { return bottom; }
		static ::core::style::BackgroundPositionY center;
		static inline ::core::style::BackgroundPositionY center_dyn() { return center; }
		static ::core::style::BackgroundPositionY length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::BackgroundPositionY percent(int value);
		static Dynamic percent_dyn();
		static ::core::style::BackgroundPositionY top;
		static inline ::core::style::BackgroundPositionY top_dyn() { return top; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundPositionY */ 
