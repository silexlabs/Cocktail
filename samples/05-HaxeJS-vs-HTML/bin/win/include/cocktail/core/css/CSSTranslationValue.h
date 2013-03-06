#ifndef INCLUDED_cocktail_core_css_CSSTranslationValue
#define INCLUDED_cocktail_core_css_CSSTranslationValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSLengthValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTranslationValue)
namespace cocktail{
namespace core{
namespace css{


class CSSTranslationValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSTranslationValue_obj OBJ_;

	public:
		CSSTranslationValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSTranslationValue"); }
		::String __ToString() const { return HX_CSTRING("CSSTranslationValue.") + tag; }

		static ::cocktail::core::css::CSSTranslationValue ABSOLUTE_LENGTH(Float value);
		static Dynamic ABSOLUTE_LENGTH_dyn();
		static ::cocktail::core::css::CSSTranslationValue LENGTH(::cocktail::core::css::CSSLengthValue value);
		static Dynamic LENGTH_dyn();
		static ::cocktail::core::css::CSSTranslationValue PERCENTAGE(Float value);
		static Dynamic PERCENTAGE_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSTranslationValue */ 
