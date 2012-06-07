#ifndef INCLUDED_cocktail_core_style_VerticalAlign
#define INCLUDED_cocktail_core_style_VerticalAlign

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,VerticalAlign)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class VerticalAlign_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef VerticalAlign_obj OBJ_;

	public:
		VerticalAlign_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.VerticalAlign"); }
		::String __ToString() const { return HX_CSTRING("VerticalAlign.") + tag; }

		static ::cocktail::core::style::VerticalAlign baseline;
		static inline ::cocktail::core::style::VerticalAlign baseline_dyn() { return baseline; }
		static ::cocktail::core::style::VerticalAlign bottom;
		static inline ::cocktail::core::style::VerticalAlign bottom_dyn() { return bottom; }
		static ::cocktail::core::style::VerticalAlign cssSuper;
		static inline ::cocktail::core::style::VerticalAlign cssSuper_dyn() { return cssSuper; }
		static ::cocktail::core::style::VerticalAlign length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::VerticalAlign middle;
		static inline ::cocktail::core::style::VerticalAlign middle_dyn() { return middle; }
		static ::cocktail::core::style::VerticalAlign percent(int value);
		static Dynamic percent_dyn();
		static ::cocktail::core::style::VerticalAlign sub;
		static inline ::cocktail::core::style::VerticalAlign sub_dyn() { return sub; }
		static ::cocktail::core::style::VerticalAlign textBottom;
		static inline ::cocktail::core::style::VerticalAlign textBottom_dyn() { return textBottom; }
		static ::cocktail::core::style::VerticalAlign textTop;
		static inline ::cocktail::core::style::VerticalAlign textTop_dyn() { return textTop; }
		static ::cocktail::core::style::VerticalAlign top;
		static inline ::cocktail::core::style::VerticalAlign top_dyn() { return top; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_VerticalAlign */ 
