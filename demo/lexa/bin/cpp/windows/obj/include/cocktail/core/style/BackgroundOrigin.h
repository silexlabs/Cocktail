#ifndef INCLUDED_cocktail_core_style_BackgroundOrigin
#define INCLUDED_cocktail_core_style_BackgroundOrigin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundOrigin)
namespace cocktail{
namespace core{
namespace style{


class BackgroundOrigin_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundOrigin_obj OBJ_;

	public:
		BackgroundOrigin_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundOrigin"); }
		::String __ToString() const { return HX_CSTRING("BackgroundOrigin.") + tag; }

		static ::cocktail::core::style::BackgroundOrigin borderBox;
		static inline ::cocktail::core::style::BackgroundOrigin borderBox_dyn() { return borderBox; }
		static ::cocktail::core::style::BackgroundOrigin contentBox;
		static inline ::cocktail::core::style::BackgroundOrigin contentBox_dyn() { return contentBox; }
		static ::cocktail::core::style::BackgroundOrigin paddingBox;
		static inline ::cocktail::core::style::BackgroundOrigin paddingBox_dyn() { return paddingBox; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundOrigin */ 
