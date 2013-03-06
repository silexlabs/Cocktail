#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_StyleSheetRulesParserState
#include <cocktail/core/css/parsers/StyleSheetRulesParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::BEGIN;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::BEGIN_COMMENT;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::BEGIN_RULE;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::COMMENT;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::END_COMMENT;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::END_RULE;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::StyleSheetRulesParserState StyleSheetRulesParserState_obj::RULE;

HX_DEFINE_CREATE_ENUM(StyleSheetRulesParserState_obj)

int StyleSheetRulesParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BEGIN")) return 1;
	if (inName==HX_CSTRING("BEGIN_COMMENT")) return 6;
	if (inName==HX_CSTRING("BEGIN_RULE")) return 2;
	if (inName==HX_CSTRING("COMMENT")) return 5;
	if (inName==HX_CSTRING("END_COMMENT")) return 7;
	if (inName==HX_CSTRING("END_RULE")) return 4;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("RULE")) return 3;
	return super::__FindIndex(inName);
}

int StyleSheetRulesParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BEGIN")) return 0;
	if (inName==HX_CSTRING("BEGIN_COMMENT")) return 0;
	if (inName==HX_CSTRING("BEGIN_RULE")) return 0;
	if (inName==HX_CSTRING("COMMENT")) return 0;
	if (inName==HX_CSTRING("END_COMMENT")) return 0;
	if (inName==HX_CSTRING("END_RULE")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("RULE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StyleSheetRulesParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BEGIN")) return BEGIN;
	if (inName==HX_CSTRING("BEGIN_COMMENT")) return BEGIN_COMMENT;
	if (inName==HX_CSTRING("BEGIN_RULE")) return BEGIN_RULE;
	if (inName==HX_CSTRING("COMMENT")) return COMMENT;
	if (inName==HX_CSTRING("END_COMMENT")) return END_COMMENT;
	if (inName==HX_CSTRING("END_RULE")) return END_RULE;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("RULE")) return RULE;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("BEGIN"),
	HX_CSTRING("BEGIN_RULE"),
	HX_CSTRING("RULE"),
	HX_CSTRING("END_RULE"),
	HX_CSTRING("COMMENT"),
	HX_CSTRING("BEGIN_COMMENT"),
	HX_CSTRING("END_COMMENT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::BEGIN,"BEGIN");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::BEGIN_COMMENT,"BEGIN_COMMENT");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::BEGIN_RULE,"BEGIN_RULE");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::COMMENT,"COMMENT");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::END_COMMENT,"END_COMMENT");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::END_RULE,"END_RULE");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(StyleSheetRulesParserState_obj::RULE,"RULE");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::BEGIN,"BEGIN");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::BEGIN_COMMENT,"BEGIN_COMMENT");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::BEGIN_RULE,"BEGIN_RULE");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::COMMENT,"COMMENT");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::END_COMMENT,"END_COMMENT");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::END_RULE,"END_RULE");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(StyleSheetRulesParserState_obj::RULE,"RULE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StyleSheetRulesParserState_obj::__mClass;

Dynamic __Create_StyleSheetRulesParserState_obj() { return new StyleSheetRulesParserState_obj; }

void StyleSheetRulesParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.StyleSheetRulesParserState"), hx::TCanCast< StyleSheetRulesParserState_obj >,sStaticFields,sMemberFields,
	&__Create_StyleSheetRulesParserState_obj, &__Create,
	&super::__SGetClass(), &CreateStyleSheetRulesParserState_obj, sMarkStatics, sVisitStatic);
}

void StyleSheetRulesParserState_obj::__boot()
{
Static(BEGIN) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("BEGIN"),1);
Static(BEGIN_COMMENT) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("BEGIN_COMMENT"),6);
Static(BEGIN_RULE) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("BEGIN_RULE"),2);
Static(COMMENT) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("COMMENT"),5);
Static(END_COMMENT) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("END_COMMENT"),7);
Static(END_RULE) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("END_RULE"),4);
Static(IGNORE_SPACES) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("IGNORE_SPACES"),0);
Static(RULE) = hx::CreateEnum< StyleSheetRulesParserState_obj >(HX_CSTRING("RULE"),3);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
