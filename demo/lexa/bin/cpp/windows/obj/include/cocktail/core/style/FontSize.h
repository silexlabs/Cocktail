#ifndef INCLUDED_cocktail_core_style_FontSize
#define INCLUDED_cocktail_core_style_FontSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,FontSize)
HX_DECLARE_CLASS3(cocktail,core,unit,FontSizeAbsoluteSize)
HX_DECLARE_CLASS3(cocktail,core,unit,FontSizeRelativeSize)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class FontSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontSize_obj OBJ_;

	public:
		FontSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.FontSize"); }
		::String __ToString() const { return HX_CSTRING("FontSize.") + tag; }

		static ::cocktail::core::style::FontSize absoluteSize(::cocktail::core::unit::FontSizeAbsoluteSize value);
		static Dynamic absoluteSize_dyn();
		static ::cocktail::core::style::FontSize length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::FontSize percentage(int value);
		static Dynamic percentage_dyn();
		static ::cocktail::core::style::FontSize relativeSize(::cocktail::core::unit::FontSizeRelativeSize value);
		static Dynamic relativeSize_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_FontSize */ 
