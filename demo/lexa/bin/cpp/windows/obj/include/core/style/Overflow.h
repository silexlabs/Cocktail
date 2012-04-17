#ifndef INCLUDED_core_style_Overflow
#define INCLUDED_core_style_Overflow

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Overflow)
namespace core{
namespace style{


class Overflow_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Overflow_obj OBJ_;

	public:
		Overflow_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Overflow"); }
		::String __ToString() const { return HX_CSTRING("Overflow.") + tag; }

		static ::core::style::Overflow cssAuto;
		static inline ::core::style::Overflow cssAuto_dyn() { return cssAuto; }
		static ::core::style::Overflow hidden;
		static inline ::core::style::Overflow hidden_dyn() { return hidden; }
		static ::core::style::Overflow scroll;
		static inline ::core::style::Overflow scroll_dyn() { return scroll; }
		static ::core::style::Overflow visible;
		static inline ::core::style::Overflow visible_dyn() { return visible; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Overflow */ 
