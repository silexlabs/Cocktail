#ifndef INCLUDED_cocktail_core_css_CSSFrequencyValue
#define INCLUDED_cocktail_core_css_CSSFrequencyValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSFrequencyValue)
namespace cocktail{
namespace core{
namespace css{


class CSSFrequencyValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSFrequencyValue_obj OBJ_;

	public:
		CSSFrequencyValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSFrequencyValue"); }
		::String __ToString() const { return HX_CSTRING("CSSFrequencyValue.") + tag; }

		static ::cocktail::core::css::CSSFrequencyValue HERTZ(Float value);
		static Dynamic HERTZ_dyn();
		static ::cocktail::core::css::CSSFrequencyValue KILO_HERTZ(Float value);
		static Dynamic KILO_HERTZ_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSFrequencyValue */ 
