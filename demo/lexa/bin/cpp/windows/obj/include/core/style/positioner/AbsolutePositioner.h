#ifndef INCLUDED_core_style_positioner_AbsolutePositioner
#define INCLUDED_core_style_positioner_AbsolutePositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/positioner/BoxPositioner.h>
HX_DECLARE_CLASS3(core,style,positioner,AbsolutePositioner)
HX_DECLARE_CLASS3(core,style,positioner,BoxPositioner)
namespace core{
namespace style{
namespace positioner{


class AbsolutePositioner_obj : public ::core::style::positioner::BoxPositioner_obj{
	public:
		typedef ::core::style::positioner::BoxPositioner_obj super;
		typedef AbsolutePositioner_obj OBJ_;
		AbsolutePositioner_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbsolutePositioner_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbsolutePositioner_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbsolutePositioner"); }

};

} // end namespace core
} // end namespace style
} // end namespace positioner

#endif /* INCLUDED_core_style_positioner_AbsolutePositioner */ 
