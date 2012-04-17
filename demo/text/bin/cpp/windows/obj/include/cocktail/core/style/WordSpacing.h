#ifndef INCLUDED_cocktail_core_style_WordSpacing
#define INCLUDED_cocktail_core_style_WordSpacing

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,WordSpacing)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class WordSpacing_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef WordSpacing_obj OBJ_;

	public:
		WordSpacing_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.WordSpacing"); }
		::String __ToString() const { return HX_CSTRING("WordSpacing.") + tag; }

		static ::cocktail::core::style::WordSpacing length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::WordSpacing normal;
		static inline ::cocktail::core::style::WordSpacing normal_dyn() { return normal; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_WordSpacing */ 
