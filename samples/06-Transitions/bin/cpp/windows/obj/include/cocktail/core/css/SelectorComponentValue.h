#ifndef INCLUDED_cocktail_core_css_SelectorComponentValue
#define INCLUDED_cocktail_core_css_SelectorComponentValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CombinatorValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorComponentValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceVO)
namespace cocktail{
namespace core{
namespace css{


class SelectorComponentValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SelectorComponentValue_obj OBJ_;

	public:
		SelectorComponentValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.SelectorComponentValue"); }
		::String __ToString() const { return HX_CSTRING("SelectorComponentValue.") + tag; }

		static ::cocktail::core::css::SelectorComponentValue COMBINATOR(::cocktail::core::css::CombinatorValue value);
		static Dynamic COMBINATOR_dyn();
		static ::cocktail::core::css::SelectorComponentValue SIMPLE_SELECTOR_SEQUENCE(::cocktail::core::css::SimpleSelectorSequenceVO value);
		static Dynamic SIMPLE_SELECTOR_SEQUENCE_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SelectorComponentValue */ 
