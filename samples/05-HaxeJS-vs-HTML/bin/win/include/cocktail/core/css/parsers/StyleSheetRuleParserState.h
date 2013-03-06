#ifndef INCLUDED_cocktail_core_css_parsers_StyleSheetRuleParserState
#define INCLUDED_cocktail_core_css_parsers_StyleSheetRuleParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,StyleSheetRuleParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class StyleSheetRuleParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StyleSheetRuleParserState_obj OBJ_;

	public:
		StyleSheetRuleParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.StyleSheetRuleParserState"); }
		::String __ToString() const { return HX_CSTRING("StyleSheetRuleParserState.") + tag; }

		static ::cocktail::core::css::parsers::StyleSheetRuleParserState BEGIN_AT_RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRuleParserState BEGIN_AT_RULE_dyn() { return BEGIN_AT_RULE; }
		static ::cocktail::core::css::parsers::StyleSheetRuleParserState BEGIN_RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRuleParserState BEGIN_RULE_dyn() { return BEGIN_RULE; }
		static ::cocktail::core::css::parsers::StyleSheetRuleParserState END_MEDIA_RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRuleParserState END_MEDIA_RULE_dyn() { return END_MEDIA_RULE; }
		static ::cocktail::core::css::parsers::StyleSheetRuleParserState END_STYLE_RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRuleParserState END_STYLE_RULE_dyn() { return END_STYLE_RULE; }
		static ::cocktail::core::css::parsers::StyleSheetRuleParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::StyleSheetRuleParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::StyleSheetRuleParserState RULE;
		static inline ::cocktail::core::css::parsers::StyleSheetRuleParserState RULE_dyn() { return RULE; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_StyleSheetRuleParserState */ 
