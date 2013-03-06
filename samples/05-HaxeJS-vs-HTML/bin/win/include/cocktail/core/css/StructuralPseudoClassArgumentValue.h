#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassArgumentValue
#define INCLUDED_cocktail_core_css_StructuralPseudoClassArgumentValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassArgumentValue)
namespace cocktail{
namespace core{
namespace css{


class StructuralPseudoClassArgumentValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StructuralPseudoClassArgumentValue_obj OBJ_;

	public:
		StructuralPseudoClassArgumentValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.StructuralPseudoClassArgumentValue"); }
		::String __ToString() const { return HX_CSTRING("StructuralPseudoClassArgumentValue.") + tag; }

		static ::cocktail::core::css::StructuralPseudoClassArgumentValue EVEN;
		static inline ::cocktail::core::css::StructuralPseudoClassArgumentValue EVEN_dyn() { return EVEN; }
		static ::cocktail::core::css::StructuralPseudoClassArgumentValue ODD;
		static inline ::cocktail::core::css::StructuralPseudoClassArgumentValue ODD_dyn() { return ODD; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_StructuralPseudoClassArgumentValue */ 
