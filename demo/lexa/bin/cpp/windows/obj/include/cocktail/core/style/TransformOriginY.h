#ifndef INCLUDED_cocktail_core_style_TransformOriginY
#define INCLUDED_cocktail_core_style_TransformOriginY

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,TransformOriginY)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class TransformOriginY_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TransformOriginY_obj OBJ_;

	public:
		TransformOriginY_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.TransformOriginY"); }
		::String __ToString() const { return HX_CSTRING("TransformOriginY.") + tag; }

		static ::cocktail::core::style::TransformOriginY bottom;
		static inline ::cocktail::core::style::TransformOriginY bottom_dyn() { return bottom; }
		static ::cocktail::core::style::TransformOriginY center;
		static inline ::cocktail::core::style::TransformOriginY center_dyn() { return center; }
		static ::cocktail::core::style::TransformOriginY length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::TransformOriginY percent(int value);
		static Dynamic percent_dyn();
		static ::cocktail::core::style::TransformOriginY top;
		static inline ::cocktail::core::style::TransformOriginY top_dyn() { return top; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_TransformOriginY */ 
