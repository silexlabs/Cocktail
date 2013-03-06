#ifndef INCLUDED_cocktail_core_css_parsers_StyleRuleParserState
#define INCLUDED_cocktail_core_css_parsers_StyleRuleParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,StyleRuleParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class StyleRuleParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StyleRuleParserState_obj OBJ_;

	public:
		StyleRuleParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.StyleRuleParserState"); }
		::String __ToString() const { return HX_CSTRING("StyleRuleParserState.") + tag; }

		static ::cocktail::core::css::parsers::StyleRuleParserState BEGIN_SELECTOR;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState BEGIN_SELECTOR_dyn() { return BEGIN_SELECTOR; }
		static ::cocktail::core::css::parsers::StyleRuleParserState BEGIN_STYLES;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState BEGIN_STYLES_dyn() { return BEGIN_STYLES; }
		static ::cocktail::core::css::parsers::StyleRuleParserState END_SELECTOR;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState END_SELECTOR_dyn() { return END_SELECTOR; }
		static ::cocktail::core::css::parsers::StyleRuleParserState END_STYLES;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState END_STYLES_dyn() { return END_STYLES; }
		static ::cocktail::core::css::parsers::StyleRuleParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::StyleRuleParserState SELECTOR;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState SELECTOR_dyn() { return SELECTOR; }
		static ::cocktail::core::css::parsers::StyleRuleParserState STYLES;
		static inline ::cocktail::core::css::parsers::StyleRuleParserState STYLES_dyn() { return STYLES; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_StyleRuleParserState */ 
