#ifndef INCLUDED_cocktail_core_style_LetterSpacing
#define INCLUDED_cocktail_core_style_LetterSpacing

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,LetterSpacing)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class LetterSpacing_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LetterSpacing_obj OBJ_;

	public:
		LetterSpacing_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.LetterSpacing"); }
		::String __ToString() const { return HX_CSTRING("LetterSpacing.") + tag; }

		static ::cocktail::core::style::LetterSpacing length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::LetterSpacing normal;
		static inline ::cocktail::core::style::LetterSpacing normal_dyn() { return normal; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_LetterSpacing */ 
