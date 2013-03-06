#ifndef INCLUDED_cocktail_core_css_parsers_StyleDeclarationParserState
#define INCLUDED_cocktail_core_css_parsers_StyleDeclarationParserState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(cocktail,core,css,parsers,StyleDeclarationParserState)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class StyleDeclarationParserState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StyleDeclarationParserState_obj OBJ_;

	public:
		StyleDeclarationParserState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.parsers.StyleDeclarationParserState"); }
		::String __ToString() const { return HX_CSTRING("StyleDeclarationParserState.") + tag; }

		static ::cocktail::core::css::parsers::StyleDeclarationParserState BEGIN;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState BEGIN_dyn() { return BEGIN; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState BEGIN_COMMENT;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState BEGIN_COMMENT_dyn() { return BEGIN_COMMENT; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState COMMENT;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState COMMENT_dyn() { return COMMENT; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState END_COMMENT;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState END_COMMENT_dyn() { return END_COMMENT; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState IGNORE_SPACES;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState IGNORE_SPACES_dyn() { return IGNORE_SPACES; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState INVALID_STYLE;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState INVALID_STYLE_dyn() { return INVALID_STYLE; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState STYLE_NAME;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState STYLE_NAME_dyn() { return STYLE_NAME; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState STYLE_SEPARATOR;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState STYLE_SEPARATOR_dyn() { return STYLE_SEPARATOR; }
		static ::cocktail::core::css::parsers::StyleDeclarationParserState STYLE_VALUE;
		static inline ::cocktail::core::css::parsers::StyleDeclarationParserState STYLE_VALUE_dyn() { return STYLE_VALUE; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_StyleDeclarationParserState */ 
