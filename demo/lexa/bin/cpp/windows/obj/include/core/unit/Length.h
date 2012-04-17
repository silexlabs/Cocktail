#ifndef INCLUDED_core_unit_Length
#define INCLUDED_core_unit_Length

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace unit{


class Length_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Length_obj OBJ_;

	public:
		Length_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.Length"); }
		::String __ToString() const { return HX_CSTRING("Length.") + tag; }

		static ::core::unit::Length _in(double value);
		static Dynamic _in_dyn();
		static ::core::unit::Length cm(double value);
		static Dynamic cm_dyn();
		static ::core::unit::Length em(double value);
		static Dynamic em_dyn();
		static ::core::unit::Length ex(double value);
		static Dynamic ex_dyn();
		static ::core::unit::Length mm(double value);
		static Dynamic mm_dyn();
		static ::core::unit::Length pc(double value);
		static Dynamic pc_dyn();
		static ::core::unit::Length pt(double value);
		static Dynamic pt_dyn();
		static ::core::unit::Length px(double value);
		static Dynamic px_dyn();
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_Length */ 
