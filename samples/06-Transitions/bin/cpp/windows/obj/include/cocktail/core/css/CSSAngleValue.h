#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#define INCLUDED_cocktail_core_css_CSSAngleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSAngleValue)
namespace cocktail{
namespace core{
namespace css{


class CSSAngleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSAngleValue_obj OBJ_;

	public:
		CSSAngleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSAngleValue"); }
		::String __ToString() const { return HX_CSTRING("CSSAngleValue.") + tag; }

		static ::cocktail::core::css::CSSAngleValue DEG(Float value);
		static Dynamic DEG_dyn();
		static ::cocktail::core::css::CSSAngleValue GRAD(Float value);
		static Dynamic GRAD_dyn();
		static ::cocktail::core::css::CSSAngleValue RAD(Float value);
		static Dynamic RAD_dyn();
		static ::cocktail::core::css::CSSAngleValue TURN(Float value);
		static Dynamic TURN_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSAngleValue */ 
