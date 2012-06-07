#ifndef INCLUDED_core_unit_ImageValue
#define INCLUDED_core_unit_ImageValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,GradientValue)
HX_DECLARE_CLASS2(core,unit,ImageValue)
namespace core{
namespace unit{


class ImageValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ImageValue_obj OBJ_;

	public:
		ImageValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.ImageValue"); }
		::String __ToString() const { return HX_CSTRING("ImageValue.") + tag; }

		static ::core::unit::ImageValue gradient(::core::unit::GradientValue value);
		static Dynamic gradient_dyn();
		static ::core::unit::ImageValue imageList(Dynamic value);
		static Dynamic imageList_dyn();
		static ::core::unit::ImageValue url(::String value);
		static Dynamic url_dyn();
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_ImageValue */ 
