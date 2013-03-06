#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue
#define INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,AttributeSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,PseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceItemValue)
namespace cocktail{
namespace core{
namespace css{


class SimpleSelectorSequenceItemValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SimpleSelectorSequenceItemValue_obj OBJ_;

	public:
		SimpleSelectorSequenceItemValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.SimpleSelectorSequenceItemValue"); }
		::String __ToString() const { return HX_CSTRING("SimpleSelectorSequenceItemValue.") + tag; }

		static ::cocktail::core::css::SimpleSelectorSequenceItemValue ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue value);
		static Dynamic ATTRIBUTE_dyn();
		static ::cocktail::core::css::SimpleSelectorSequenceItemValue CSS_CLASS(::String value);
		static Dynamic CSS_CLASS_dyn();
		static ::cocktail::core::css::SimpleSelectorSequenceItemValue ID(::String value);
		static Dynamic ID_dyn();
		static ::cocktail::core::css::SimpleSelectorSequenceItemValue PSEUDO_CLASS(::cocktail::core::css::PseudoClassSelectorValue value);
		static Dynamic PSEUDO_CLASS_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue */ 
