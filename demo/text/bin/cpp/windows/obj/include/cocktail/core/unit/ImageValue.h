#ifndef INCLUDED_cocktail_core_unit_ImageValue
#define INCLUDED_cocktail_core_unit_ImageValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,GradientValue)
HX_DECLARE_CLASS3(cocktail,core,unit,ImageValue)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.ImageValue"); }
		::String __ToString() const { return HX_CSTRING("ImageValue.") + tag; }

		static ::cocktail::core::unit::ImageValue gradient(::cocktail::core::unit::GradientValue value);
		static Dynamic gradient_dyn();
		static ::cocktail::core::unit::ImageValue imageList(Dynamic value);
		static Dynamic imageList_dyn();
		static ::cocktail::core::unit::ImageValue url(::String value);
		static Dynamic url_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_ImageValue */ 
