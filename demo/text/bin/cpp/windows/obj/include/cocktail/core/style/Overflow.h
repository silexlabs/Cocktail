#ifndef INCLUDED_cocktail_core_style_Overflow
#define INCLUDED_cocktail_core_style_Overflow

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Overflow)
namespace cocktail{
namespace core{
namespace style{


class Overflow_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Overflow_obj OBJ_;

	public:
		Overflow_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Overflow"); }
		::String __ToString() const { return HX_CSTRING("Overflow.") + tag; }

		static ::cocktail::core::style::Overflow cssAuto;
		static inline ::cocktail::core::style::Overflow cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::style::Overflow hidden;
		static inline ::cocktail::core::style::Overflow hidden_dyn() { return hidden; }
		static ::cocktail::core::style::Overflow scroll;
		static inline ::cocktail::core::style::Overflow scroll_dyn() { return scroll; }
		static ::cocktail::core::style::Overflow visible;
		static inline ::cocktail::core::style::Overflow visible_dyn() { return visible; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Overflow */ 
