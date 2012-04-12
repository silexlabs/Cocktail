#ifndef INCLUDED_cocktail_core_style_positioner_AbsolutePositioner
#define INCLUDED_cocktail_core_style_positioner_AbsolutePositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/positioner/BoxPositioner.h>
HX_DECLARE_CLASS4(cocktail,core,style,positioner,AbsolutePositioner)
HX_DECLARE_CLASS4(cocktail,core,style,positioner,BoxPositioner)
namespace cocktail{
namespace core{
namespace style{
namespace positioner{


class AbsolutePositioner_obj : public ::cocktail::core::style::positioner::BoxPositioner_obj{
	public:
		typedef ::cocktail::core::style::positioner::BoxPositioner_obj super;
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

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace positioner

#endif /* INCLUDED_cocktail_core_style_positioner_AbsolutePositioner */ 
