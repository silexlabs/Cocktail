#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_StyleSheetRuleParserState
#include <cocktail/core/css/parsers/StyleSheetRuleParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::StyleSheetRuleParserState StyleSheetRuleParserState_obj::BEGIN_AT_RULE;

::cocktail::core::css::parsers::StyleSheetRuleParserState StyleSheetRuleParserState_obj::BEGIN_RULE;

::cocktail::core::css::parsers::StyleSheetRuleParserState StyleSheetRuleParserState_obj::END_MEDIA_RULE;

::cocktail::core::css::parsers::StyleSheetRuleParserState StyleSheetRuleParserState_obj::END_STYLE_RULE;

::cocktail::core::css::parsers::StyleSheetRuleParserState StyleSheetRuleParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::StyleSheetRuleParserState StyleSheetRuleParserState_obj::RULE;

HX_DEFINE_CREATE_ENUM(StyleSheetRuleParserState_obj)

int StyleSheetRuleParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_AT_RULE")) return 2;
	if (inName==HX_CSTRING("BEGIN_RULE")) return 1;
	if (inName==HX_CSTRING("END_MEDIA_RULE")) return 3;
	if (inName==HX_CSTRING("END_STYLE_RULE")) return 5;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("RULE")) return 4;
	return super::__FindIndex(inName);
}

int StyleSheetRuleParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_AT_RULE")) return 0;
	if (inName==HX_CSTRING("BEGIN_RULE")) return 0;
	if (inName==HX_CSTRING("END_MEDIA_RULE")) return 0;
	if (inName==HX_CSTRING("END_STYLE_RULE")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("RULE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StyleSheetRuleParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BEGIN_AT_RULE")) return BEGIN_AT_RULE;
	if (inName==HX_CSTRING("BEGIN_RULE")) return BEGIN_RULE;
	if (inName==HX_CSTRING("END_MEDIA_RULE")) return END_MEDIA_RULE;
	if (inName==HX_CSTRING("END_STYLE_RULE")) return END_STYLE_RULE;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("RULE")) return RULE;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("BEGIN_RULE"),
	HX_CSTRING("BEGIN_AT_RULE"),
	HX_CSTRING("END_MEDIA_RULE"),
	HX_CSTRING("RULE"),
	HX_CSTRING("END_STYLE_RULE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleSheetRuleParserState_obj::BEGIN_AT_RULE,"BEGIN_AT_RULE");
	HX_MARK_MEMBER_NAME(StyleSheetRuleParserState_obj::BEGIN_RULE,"BEGIN_RULE");
	HX_MARK_MEMBER_NAME(StyleSheetRuleParserState_obj::END_MEDIA_RULE,"END_MEDIA_RULE");
	HX_MARK_MEMBER_NAME(StyleSheetRuleParserState_obj::END_STYLE_RULE,"END_STYLE_RULE");
	HX_MARK_MEMBER_NAME(StyleSheetRuleParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(StyleSheetRuleParserState_obj::RULE,"RULE");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::BEGIN_AT_RULE,"BEGIN_AT_RULE");
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::BEGIN_RULE,"BEGIN_RULE");
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::END_MEDIA_RULE,"END_MEDIA_RULE");
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::END_STYLE_RULE,"END_STYLE_RULE");
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(StyleSheetRuleParserState_obj::RULE,"RULE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StyleSheetRuleParserState_obj::__mClass;

Dynamic __Create_StyleSheetRuleParserState_obj() { return new StyleSheetRuleParserState_obj; }

void StyleSheetRuleParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.StyleSheetRuleParserState"), hx::TCanCast< StyleSheetRuleParserState_obj >,sStaticFields,sMemberFields,
	&__Create_StyleSheetRuleParserState_obj, &__Create,
	&super::__SGetClass(), &CreateStyleSheetRuleParserState_obj, sMarkStatics, sVisitStatic);
}

void StyleSheetRuleParserState_obj::__boot()
{
Static(BEGIN_AT_RULE) = hx::CreateEnum< StyleSheetRuleParserState_obj >(HX_CSTRING("BEGIN_AT_RULE"),2);
Static(BEGIN_RULE) = hx::CreateEnum< StyleSheetRuleParserState_obj >(HX_CSTRING("BEGIN_RULE"),1);
Static(END_MEDIA_RULE) = hx::CreateEnum< StyleSheetRuleParserState_obj >(HX_CSTRING("END_MEDIA_RULE"),3);
Static(END_STYLE_RULE) = hx::CreateEnum< StyleSheetRuleParserState_obj >(HX_CSTRING("END_STYLE_RULE"),5);
Static(IGNORE_SPACES) = hx::CreateEnum< StyleSheetRuleParserState_obj >(HX_CSTRING("IGNORE_SPACES"),0);
Static(RULE) = hx::CreateEnum< StyleSheetRuleParserState_obj >(HX_CSTRING("RULE"),4);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
