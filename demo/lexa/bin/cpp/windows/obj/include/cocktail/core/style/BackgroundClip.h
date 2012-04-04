#ifndef INCLUDED_cocktail_core_style_BackgroundClip
#define INCLUDED_cocktail_core_style_BackgroundClip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundClip)
namespace cocktail{
namespace core{
namespace style{


class BackgroundClip_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundClip_obj OBJ_;

	public:
		BackgroundClip_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundClip"); }
		::String __ToString() const { return HX_CSTRING("BackgroundClip.") + tag; }

		static ::cocktail::core::style::BackgroundClip borderBox;
		static inline ::cocktail::core::style::BackgroundClip borderBox_dyn() { return borderBox; }
		static ::cocktail::core::style::BackgroundClip contentBox;
		static inline ::cocktail::core::style::BackgroundClip contentBox_dyn() { return contentBox; }
		static ::cocktail::core::style::BackgroundClip paddingBox;
		static inline ::cocktail::core::style::BackgroundClip paddingBox_dyn() { return paddingBox; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundClip */ 
