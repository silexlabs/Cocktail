#ifndef INCLUDED_core_unit_CSSColor
#define INCLUDED_core_unit_CSSColor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,CSSColor)
HX_DECLARE_CLASS2(core,unit,ColorKeyword)
namespace core{
namespace unit{


class CSSColor_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSColor_obj OBJ_;

	public:
		CSSColor_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.CSSColor"); }
		::String __ToString() const { return HX_CSTRING("CSSColor.") + tag; }

		static ::core::unit::CSSColor hex(::String value);
		static Dynamic hex_dyn();
		static ::core::unit::CSSColor keyword(::core::unit::ColorKeyword value);
		static Dynamic keyword_dyn();
		static ::core::unit::CSSColor rgb(int red,int green,int blue);
		static Dynamic rgb_dyn();
		static ::core::unit::CSSColor rgba(int red,int green,int blue,double alpha);
		static Dynamic rgba_dyn();
		static ::core::unit::CSSColor transparent;
		static inline ::core::unit::CSSColor transparent_dyn() { return transparent; }
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_CSSColor */ 
