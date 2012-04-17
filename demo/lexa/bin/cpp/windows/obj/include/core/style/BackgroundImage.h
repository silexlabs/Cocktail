#ifndef INCLUDED_core_style_BackgroundImage
#define INCLUDED_core_style_BackgroundImage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,BackgroundImage)
HX_DECLARE_CLASS2(core,unit,ImageValue)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.style.BackgroundImage"); }
		::String __ToString() const { return HX_CSTRING("BackgroundImage.") + tag; }

		static ::core::style::BackgroundImage image(::core::unit::ImageValue value);
		static Dynamic image_dyn();
		static ::core::style::BackgroundImage none;
		static inline ::core::style::BackgroundImage none_dyn() { return none; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_BackgroundImage */ 
