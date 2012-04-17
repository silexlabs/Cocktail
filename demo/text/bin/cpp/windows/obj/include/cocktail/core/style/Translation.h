#ifndef INCLUDED_cocktail_core_style_Translation
#define INCLUDED_cocktail_core_style_Translation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Translation)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class Translation_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Translation_obj OBJ_;

	public:
		Translation_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Translation"); }
		::String __ToString() const { return HX_CSTRING("Translation.") + tag; }

		static ::cocktail::core::style::Translation length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::Translation percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Translation */ 
