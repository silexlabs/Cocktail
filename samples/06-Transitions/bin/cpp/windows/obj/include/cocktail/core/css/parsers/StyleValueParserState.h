#ifndef INCLUDED_cocktail_core_css_parsers_StyleValueParserState
#define INCLUDED_cocktail_core_css_parsers_StyleValueParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,StyleValueParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class StyleValueParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StyleValueParserState_obj OBJ_;

	public:
		StyleValueParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.StyleValueParserState"); }
		::String __ToString() const { return HX_CSTRING("StyleValueParserState.") + tag; }

		static ::cocktail::core::css::parsers::StyleValueParserState BEGIN_VALUE;
		static inline ::cocktail::core::css::parsers::StyleValueParserState BEGIN_VALUE_dyn() { return BEGIN_VALUE; }
		static ::cocktail::core::css::parsers::StyleValueParserState COMPONENT_OR_END;
		static inline ::cocktail::core::css::parsers::StyleValueParserState COMPONENT_OR_END_dyn() { return COMPONENT_OR_END; }
		static ::cocktail::core::css::parsers::StyleValueParserState END;
		static inline ::cocktail::core::css::parsers::StyleValueParserState END_dyn() { return END; }
		static ::cocktail::core::css::parsers::StyleValueParserState HEX;
		static inline ::cocktail::core::css::parsers::StyleValueParserState HEX_dyn() { return HEX; }
		static ::cocktail::core::css::parsers::StyleValueParserState IDENT_FUNCTION;
		static inline ::cocktail::core::css::parsers::StyleValueParserState IDENT_FUNCTION_dyn() { return IDENT_FUNCTION; }
		static ::cocktail::core::css::parsers::StyleValueParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::StyleValueParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::StyleValueParserState IMPORTANT;
		static inline ::cocktail::core::css::parsers::StyleValueParserState IMPORTANT_dyn() { return IMPORTANT; }
		static ::cocktail::core::css::parsers::StyleValueParserState INVALID_STYLE_VALUE;
		static inline ::cocktail::core::css::parsers::StyleValueParserState INVALID_STYLE_VALUE_dyn() { return INVALID_STYLE_VALUE; }
		static ::cocktail::core::css::parsers::StyleValueParserState NUMBER_INTEGER_DIMENSION_PERCENTAGE;
		static inline ::cocktail::core::css::parsers::StyleValueParserState NUMBER_INTEGER_DIMENSION_PERCENTAGE_dyn() { return NUMBER_INTEGER_DIMENSION_PERCENTAGE; }
		static ::cocktail::core::css::parsers::StyleValueParserState STRING;
		static inline ::cocktail::core::css::parsers::StyleValueParserState STRING_dyn() { return STRING; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_StyleValueParserState */ 
