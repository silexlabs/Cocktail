#ifndef INCLUDED_cocktail_core_style_TransformOriginX
#define INCLUDED_cocktail_core_style_TransformOriginX

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,TransformOriginX)
HX_DECLARE_CLASS3(cocktail,core,unit,Length)
namespace cocktail{
namespace core{
namespace style{


class TransformOriginX_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TransformOriginX_obj OBJ_;

	public:
		TransformOriginX_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.TransformOriginX"); }
		::String __ToString() const { return HX_CSTRING("TransformOriginX.") + tag; }

		static ::cocktail::core::style::TransformOriginX center;
		static inline ::cocktail::core::style::TransformOriginX center_dyn() { return center; }
		static ::cocktail::core::style::TransformOriginX left;
		static inline ::cocktail::core::style::TransformOriginX left_dyn() { return left; }
		static ::cocktail::core::style::TransformOriginX length(::cocktail::core::unit::Length value);
		static Dynamic length_dyn();
		static ::cocktail::core::style::TransformOriginX percent(int value);
		static Dynamic percent_dyn();
		static ::cocktail::core::style::TransformOriginX right;
		static inline ::cocktail::core::style::TransformOriginX right_dyn() { return right; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_TransformOriginX */ 
