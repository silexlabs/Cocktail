#ifndef INCLUDED_core_style_ConstrainedDimension
#define INCLUDED_core_style_ConstrainedDimension

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,ConstrainedDimension)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class ConstrainedDimension_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ConstrainedDimension_obj OBJ_;

	public:
		ConstrainedDimension_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.ConstrainedDimension"); }
		::String __ToString() const { return HX_CSTRING("ConstrainedDimension.") + tag; }

		static ::core::style::ConstrainedDimension length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::ConstrainedDimension none;
		static inline ::core::style::ConstrainedDimension none_dyn() { return none; }
		static ::core::style::ConstrainedDimension percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_ConstrainedDimension */ 
