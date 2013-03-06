#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#define INCLUDED_cocktail_core_css_CSSLengthValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSLengthValue)
namespace cocktail{
namespace core{
namespace css{


class CSSLengthValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSLengthValue_obj OBJ_;

	public:
		CSSLengthValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSLengthValue"); }
		::String __ToString() const { return HX_CSTRING("CSSLengthValue.") + tag; }

		static ::cocktail::core::css::CSSLengthValue CM(Float value);
		static Dynamic CM_dyn();
		static ::cocktail::core::css::CSSLengthValue EM(Float value);
		static Dynamic EM_dyn();
		static ::cocktail::core::css::CSSLengthValue EX(Float value);
		static Dynamic EX_dyn();
		static ::cocktail::core::css::CSSLengthValue IN(Float value);
		static Dynamic IN_dyn();
		static ::cocktail::core::css::CSSLengthValue MM(Float value);
		static Dynamic MM_dyn();
		static ::cocktail::core::css::CSSLengthValue PC(Float value);
		static Dynamic PC_dyn();
		static ::cocktail::core::css::CSSLengthValue PT(Float value);
		static Dynamic PT_dyn();
		static ::cocktail::core::css::CSSLengthValue PX(Float value);
		static Dynamic PX_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSLengthValue */ 
