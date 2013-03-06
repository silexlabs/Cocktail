#ifndef INCLUDED_cocktail_core_css_PseudoClassSelectorValue
#define INCLUDED_cocktail_core_css_PseudoClassSelectorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,LinkPseudoClassValue)
HX_DECLARE_CLASS3(cocktail,core,css,PseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceVO)
HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,UIElementStatesValue)
HX_DECLARE_CLASS3(cocktail,core,css,UserActionPseudoClassValue)
namespace cocktail{
namespace core{
namespace css{


class PseudoClassSelectorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PseudoClassSelectorValue_obj OBJ_;

	public:
		PseudoClassSelectorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.PseudoClassSelectorValue"); }
		::String __ToString() const { return HX_CSTRING("PseudoClassSelectorValue.") + tag; }

		static ::cocktail::core::css::PseudoClassSelectorValue LANG(Array< ::String > value);
		static Dynamic LANG_dyn();
		static ::cocktail::core::css::PseudoClassSelectorValue LINK(::cocktail::core::css::LinkPseudoClassValue value);
		static Dynamic LINK_dyn();
		static ::cocktail::core::css::PseudoClassSelectorValue NOT(::cocktail::core::css::SimpleSelectorSequenceVO value);
		static Dynamic NOT_dyn();
		static ::cocktail::core::css::PseudoClassSelectorValue STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue value);
		static Dynamic STRUCTURAL_dyn();
		static ::cocktail::core::css::PseudoClassSelectorValue TARGET;
		static inline ::cocktail::core::css::PseudoClassSelectorValue TARGET_dyn() { return TARGET; }
		static ::cocktail::core::css::PseudoClassSelectorValue UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue value);
		static Dynamic UI_ELEMENT_STATES_dyn();
		static ::cocktail::core::css::PseudoClassSelectorValue USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue value);
		static Dynamic USER_ACTION_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_PseudoClassSelectorValue */ 
