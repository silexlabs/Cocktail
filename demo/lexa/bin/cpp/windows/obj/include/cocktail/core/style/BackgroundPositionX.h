#ifndef INCLUDED_cocktail_core_style_BackgroundPositionX
#define INCLUDED_cocktail_core_style_BackgroundPositionX

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundPositionX)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class BackgroundPositionX_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundPositionX_obj OBJ_;

	public:
		BackgroundPositionX_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundPositionX"); }
		::String __ToString() const { return HX_CSTRING("BackgroundPositionX.") + tag; }

		static ::cocktail::core::style::BackgroundPositionX center;
		static inline ::cocktail::core::style::BackgroundPositionX center_dyn() { return center; }
		static ::cocktail::core::style::BackgroundPositionX left;
		static inline ::cocktail::core::style::BackgroundPositionX left_dyn() { return left; }
		static ::cocktail::core::style::BackgroundPositionX length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::BackgroundPositionX percent(int value);
		static Dynamic percent_dyn();
		static ::cocktail::core::style::BackgroundPositionX right;
		static inline ::cocktail::core::style::BackgroundPositionX right_dyn() { return right; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundPositionX */ 
