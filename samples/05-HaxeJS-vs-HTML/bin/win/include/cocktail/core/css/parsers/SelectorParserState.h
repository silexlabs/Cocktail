#ifndef INCLUDED_cocktail_core_css_parsers_SelectorParserState
#define INCLUDED_cocktail_core_css_parsers_SelectorParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,SelectorParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class SelectorParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SelectorParserState_obj OBJ_;

	public:
		SelectorParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.SelectorParserState"); }
		::String __ToString() const { return HX_CSTRING("SelectorParserState.") + tag; }

		static ::cocktail::core::css::parsers::SelectorParserState BEGIN_ATTRIBUTE_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState BEGIN_ATTRIBUTE_SELECTOR_dyn() { return BEGIN_ATTRIBUTE_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState BEGIN_COMBINATOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState BEGIN_COMBINATOR_dyn() { return BEGIN_COMBINATOR; }
		static ::cocktail::core::css::parsers::SelectorParserState BEGIN_PSEUDO_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState BEGIN_PSEUDO_SELECTOR_dyn() { return BEGIN_PSEUDO_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState BEGIN_SIMPLE_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState BEGIN_SIMPLE_SELECTOR_dyn() { return BEGIN_SIMPLE_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState COMBINATOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState COMBINATOR_dyn() { return COMBINATOR; }
		static ::cocktail::core::css::parsers::SelectorParserState END_CLASS_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState END_CLASS_SELECTOR_dyn() { return END_CLASS_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState END_ID_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState END_ID_SELECTOR_dyn() { return END_ID_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState END_SIMPLE_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState END_SIMPLE_SELECTOR_dyn() { return END_SIMPLE_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState END_TYPE_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState END_TYPE_SELECTOR_dyn() { return END_TYPE_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState END_UNIVERSAL_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState END_UNIVERSAL_SELECTOR_dyn() { return END_UNIVERSAL_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::SelectorParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::SelectorParserState INVALID_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState INVALID_SELECTOR_dyn() { return INVALID_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState PSEUDO_ELEMENT_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState PSEUDO_ELEMENT_SELECTOR_dyn() { return PSEUDO_ELEMENT_SELECTOR; }
		static ::cocktail::core::css::parsers::SelectorParserState SIMPLE_SELECTOR;
		static inline ::cocktail::core::css::parsers::SelectorParserState SIMPLE_SELECTOR_dyn() { return SIMPLE_SELECTOR; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_SelectorParserState */ 
