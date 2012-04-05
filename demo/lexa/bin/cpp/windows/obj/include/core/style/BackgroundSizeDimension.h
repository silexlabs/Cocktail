#ifndef INCLUDED_core_style_BackgroundSizeDimension
#define INCLUDED_core_style_BackgroundSizeDimension

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundSizeDimension)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class BackgroundSizeDimension_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundSizeDimension_obj OBJ_;

	public:
		BackgroundSizeDimension_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundSizeDimension"); }
		::String __ToString() const { return HX_CSTRING("BackgroundSizeDimension.") + tag; }

		static ::core::style::BackgroundSizeDimension cssAuto;
		static inline ::core::style::BackgroundSizeDimension cssAuto_dyn() { return cssAuto; }
		static ::core::style::BackgroundSizeDimension length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::BackgroundSizeDimension percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundSizeDimension */ 
