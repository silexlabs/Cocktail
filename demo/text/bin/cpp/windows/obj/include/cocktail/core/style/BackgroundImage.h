#ifndef INCLUDED_cocktail_core_style_BackgroundImage
#define INCLUDED_cocktail_core_style_BackgroundImage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundImage)
HX_DECLARE_CLASS3(cocktail,core,unit,ImageValue)
namespace cocktail{
namespace core{
namespace style{


class BackgroundImage_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundImage_obj OBJ_;

	public:
		BackgroundImage_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundImage"); }
		::String __ToString() const { return HX_CSTRING("BackgroundImage.") + tag; }

		static ::cocktail::core::style::BackgroundImage image(::cocktail::core::unit::ImageValue value);
		static Dynamic image_dyn();
		static ::cocktail::core::style::BackgroundImage none;
		static inline ::cocktail::core::style::BackgroundImage none_dyn() { return none; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundImage */ 
