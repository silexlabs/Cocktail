#ifndef INCLUDED_core_style_Position
#define INCLUDED_core_style_Position

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Position)
namespace core{
namespace style{


class Position_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Position_obj OBJ_;

	public:
		Position_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Position"); }
		::String __ToString() const { return HX_CSTRING("Position.") + tag; }

		static ::core::style::Position absolute;
		static inline ::core::style::Position absolute_dyn() { return absolute; }
		static ::core::style::Position cssStatic;
		static inline ::core::style::Position cssStatic_dyn() { return cssStatic; }
		static ::core::style::Position fixed;
		static inline ::core::style::Position fixed_dyn() { return fixed; }
		static ::core::style::Position relative;
		static inline ::core::style::Position relative_dyn() { return relative; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Position */ 
