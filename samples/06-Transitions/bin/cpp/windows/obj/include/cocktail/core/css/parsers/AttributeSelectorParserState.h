#ifndef INCLUDED_cocktail_core_css_parsers_AttributeSelectorParserState
#define INCLUDED_cocktail_core_css_parsers_AttributeSelectorParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,AttributeSelectorParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class AttributeSelectorParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AttributeSelectorParserState_obj OBJ_;

	public:
		AttributeSelectorParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.AttributeSelectorParserState"); }
		::String __ToString() const { return HX_CSTRING("AttributeSelectorParserState.") + tag; }

		static ::cocktail::core::css::parsers::AttributeSelectorParserState ATTRIBUTE;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState ATTRIBUTE_dyn() { return ATTRIBUTE; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState BEGIN_OPERATOR;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState BEGIN_OPERATOR_dyn() { return BEGIN_OPERATOR; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState END_OPERATOR;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState END_OPERATOR_dyn() { return END_OPERATOR; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState END_SELECTOR;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState END_SELECTOR_dyn() { return END_SELECTOR; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState IDENTIFIER_VALUE;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState IDENTIFIER_VALUE_dyn() { return IDENTIFIER_VALUE; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState INVALID_SELECTOR;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState INVALID_SELECTOR_dyn() { return INVALID_SELECTOR; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState OPERATOR;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState OPERATOR_dyn() { return OPERATOR; }
		static ::cocktail::core::css::parsers::AttributeSelectorParserState STRING_VALUE;
		static inline ::cocktail::core::css::parsers::AttributeSelectorParserState STRING_VALUE_dyn() { return STRING_VALUE; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_AttributeSelectorParserState */ 
