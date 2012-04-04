#ifndef INCLUDED_cocktail_core_style_BackgroundPositionY
#define INCLUDED_cocktail_core_style_BackgroundPositionY

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundPositionY)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class BackgroundPositionY_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundPositionY_obj OBJ_;

	public:
		BackgroundPositionY_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundPositionY"); }
		::String __ToString() const { return HX_CSTRING("BackgroundPositionY.") + tag; }

		static ::cocktail::core::style::BackgroundPositionY bottom;
		static inline ::cocktail::core::style::BackgroundPositionY bottom_dyn() { return bottom; }
		static ::cocktail::core::style::BackgroundPositionY center;
		static inline ::cocktail::core::style::BackgroundPositionY center_dyn() { return center; }
		static ::cocktail::core::style::BackgroundPositionY length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::BackgroundPositionY percent(int value);
		static Dynamic percent_dyn();
		static ::cocktail::core::style::BackgroundPositionY top;
		static inline ::cocktail::core::style::BackgroundPositionY top_dyn() { return top; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundPositionY */ 
