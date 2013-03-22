#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue
#define INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassArgumentValue)
HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassSelectorValue)
namespace cocktail{
namespace core{
namespace css{


class StructuralPseudoClassSelectorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StructuralPseudoClassSelectorValue_obj OBJ_;

	public:
		StructuralPseudoClassSelectorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.StructuralPseudoClassSelectorValue"); }
		::String __ToString() const { return HX_CSTRING("StructuralPseudoClassSelectorValue.") + tag; }

		static ::cocktail::core::css::StructuralPseudoClassSelectorValue EMPTY;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue EMPTY_dyn() { return EMPTY; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue FIRST_CHILD;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue FIRST_CHILD_dyn() { return FIRST_CHILD; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue FIRST_OF_TYPE;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue FIRST_OF_TYPE_dyn() { return FIRST_OF_TYPE; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue LAST_CHILD;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue LAST_CHILD_dyn() { return LAST_CHILD; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue LAST_OF_TYPE;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue LAST_OF_TYPE_dyn() { return LAST_OF_TYPE; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue NTH_CHILD(::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		static Dynamic NTH_CHILD_dyn();
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue NTH_LAST_CHILD(::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		static Dynamic NTH_LAST_CHILD_dyn();
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue NTH_LAST_OF_TYPE(::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		static Dynamic NTH_LAST_OF_TYPE_dyn();
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue NTH_OF_TYPE(::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		static Dynamic NTH_OF_TYPE_dyn();
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue ONLY_CHILD;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue ONLY_CHILD_dyn() { return ONLY_CHILD; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue ONLY_OF_TYPE;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue ONLY_OF_TYPE_dyn() { return ONLY_OF_TYPE; }
		static ::cocktail::core::css::StructuralPseudoClassSelectorValue ROOT;
		static inline ::cocktail::core::css::StructuralPseudoClassSelectorValue ROOT_dyn() { return ROOT; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue */ 
