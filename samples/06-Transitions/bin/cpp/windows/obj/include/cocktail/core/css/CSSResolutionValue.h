#ifndef INCLUDED_cocktail_core_css_CSSResolutionValue
#define INCLUDED_cocktail_core_css_CSSResolutionValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSResolutionValue)
namespace cocktail{
namespace core{
namespace css{


class CSSResolutionValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSResolutionValue_obj OBJ_;

	public:
		CSSResolutionValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSResolutionValue"); }
		::String __ToString() const { return HX_CSTRING("CSSResolutionValue.") + tag; }

		static ::cocktail::core::css::CSSResolutionValue DPCM(Float value);
		static Dynamic DPCM_dyn();
		static ::cocktail::core::css::CSSResolutionValue DPI(Float value);
		static Dynamic DPI_dyn();
		static ::cocktail::core::css::CSSResolutionValue DPPX(Float value);
		static Dynamic DPPX_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSResolutionValue */ 
