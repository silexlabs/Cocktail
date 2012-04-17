#ifndef INCLUDED_cocktail_core_style_LineHeight
#define INCLUDED_cocktail_core_style_LineHeight

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,LineHeight)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class LineHeight_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineHeight_obj OBJ_;

	public:
		LineHeight_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.LineHeight"); }
		::String __ToString() const { return HX_CSTRING("LineHeight.") + tag; }

		static ::cocktail::core::style::LineHeight length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::LineHeight normal;
		static inline ::cocktail::core::style::LineHeight normal_dyn() { return normal; }
		static ::cocktail::core::style::LineHeight number(double value);
		static Dynamic number_dyn();
		static ::cocktail::core::style::LineHeight percentage(int value);
		static Dynamic percentage_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_LineHeight */ 
