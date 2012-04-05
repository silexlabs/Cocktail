#ifndef INCLUDED_core_style_positioner_FixedPositioner
#define INCLUDED_core_style_positioner_FixedPositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/positioner/BoxPositioner.h>
HX_DECLARE_CLASS3(core,style,positioner,BoxPositioner)
HX_DECLARE_CLASS3(core,style,positioner,FixedPositioner)
namespace core{
namespace style{
namespace positioner{


class FixedPositioner_obj : public ::core::style::positioner::BoxPositioner_obj{
	public:
		typedef ::core::style::positioner::BoxPositioner_obj super;
		typedef FixedPositioner_obj OBJ_;
		FixedPositioner_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FixedPositioner_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FixedPositioner_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FixedPositioner"); }

};

} // end namespace core
} // end namespace style
} // end namespace positioner

#endif /* INCLUDED_core_style_positioner_FixedPositioner */ 
