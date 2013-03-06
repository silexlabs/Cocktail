#ifndef INCLUDED_cocktail_core_css_PseudoElementSelectorValue
#define INCLUDED_cocktail_core_css_PseudoElementSelectorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,PseudoElementSelectorValue)
namespace cocktail{
namespace core{
namespace css{


class PseudoElementSelectorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PseudoElementSelectorValue_obj OBJ_;

	public:
		PseudoElementSelectorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.PseudoElementSelectorValue"); }
		::String __ToString() const { return HX_CSTRING("PseudoElementSelectorValue.") + tag; }

		static ::cocktail::core::css::PseudoElementSelectorValue AFTER;
		static inline ::cocktail::core::css::PseudoElementSelectorValue AFTER_dyn() { return AFTER; }
		static ::cocktail::core::css::PseudoElementSelectorValue BEFORE;
		static inline ::cocktail::core::css::PseudoElementSelectorValue BEFORE_dyn() { return BEFORE; }
		static ::cocktail::core::css::PseudoElementSelectorValue FIRST_LETTER;
		static inline ::cocktail::core::css::PseudoElementSelectorValue FIRST_LETTER_dyn() { return FIRST_LETTER; }
		static ::cocktail::core::css::PseudoElementSelectorValue FIRST_LINE;
		static inline ::cocktail::core::css::PseudoElementSelectorValue FIRST_LINE_dyn() { return FIRST_LINE; }
		static ::cocktail::core::css::PseudoElementSelectorValue NONE;
		static inline ::cocktail::core::css::PseudoElementSelectorValue NONE_dyn() { return NONE; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_PseudoElementSelectorValue */ 
