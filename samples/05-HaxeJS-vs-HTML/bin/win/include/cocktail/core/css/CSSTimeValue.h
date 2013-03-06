#ifndef INCLUDED_cocktail_core_css_CSSTimeValue
#define INCLUDED_cocktail_core_css_CSSTimeValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSTimeValue)
namespace cocktail{
namespace core{
namespace css{


class CSSTimeValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSTimeValue_obj OBJ_;

	public:
		CSSTimeValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSTimeValue"); }
		::String __ToString() const { return HX_CSTRING("CSSTimeValue.") + tag; }

		static ::cocktail::core::css::CSSTimeValue MILLISECONDS(Float value);
		static Dynamic MILLISECONDS_dyn();
		static ::cocktail::core::css::CSSTimeValue SECONDS(Float value);
		static Dynamic SECONDS_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSTimeValue */ 
