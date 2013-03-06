#ifndef INCLUDED_cocktail_core_css_parsers_StyleSheetRulesParserState
#define INCLUDED_cocktail_core_css_parsers_StyleSheetRulesParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,StyleSheetRulesParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class StyleSheetRulesParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StyleSheetRulesParserState_obj OBJ_;

	public:
		StyleSheetRulesParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.StyleSheetRulesParserState"); }
		::String __ToString() const { return HX_CSTRING("StyleSheetRulesParserState.") + tag; }

		static ::cocktail::core::css::parsers::StyleSheetRulesParserState BEGIN;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState BEGIN_dyn() { return BEGIN; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState BEGIN_COMMENT;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState BEGIN_COMMENT_dyn() { return BEGIN_COMMENT; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState BEGIN_RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState BEGIN_RULE_dyn() { return BEGIN_RULE; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState COMMENT;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState COMMENT_dyn() { return COMMENT; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState END_COMMENT;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState END_COMMENT_dyn() { return END_COMMENT; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState END_RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState END_RULE_dyn() { return END_RULE; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::StyleSheetRulesParserState RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRulesParserState RULE_dyn() { return RULE; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_StyleSheetRulesParserState */ 
