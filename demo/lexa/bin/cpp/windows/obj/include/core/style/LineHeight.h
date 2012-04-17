#ifndef INCLUDED_core_style_LineHeight
#define INCLUDED_core_style_LineHeight

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,LineHeight)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class LineHeight_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineHeight_obj OBJ_;

	public:
		LineHeight_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.LineHeight"); }
		::String __ToString() const { return HX_CSTRING("LineHeight.") + tag; }

		static ::core::style::LineHeight length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::LineHeight normal;
		static inline ::core::style::LineHeight normal_dyn() { return normal; }
		static ::core::style::LineHeight number(double value);
		static Dynamic number_dyn();
		static ::core::style::LineHeight percentage(int value);
		static Dynamic percentage_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_LineHeight */ 
