#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_StyleRuleParserState
#include <cocktail/core/css/parsers/StyleRuleParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::BEGIN_SELECTOR;

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::BEGIN_STYLES;

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::END_SELECTOR;

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::END_STYLES;

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::SELECTOR;

::cocktail::core::css::parsers::StyleRuleParserState StyleRuleParserState_obj::STYLES;

HX_DEFINE_CREATE_ENUM(StyleRuleParserState_obj)

int StyleRuleParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_SELECTOR")) return 1;
	if (inName==HX_CSTRING("BEGIN_STYLES")) return 4;
	if (inName==HX_CSTRING("END_SELECTOR")) return 2;
	if (inName==HX_CSTRING("END_STYLES")) return 6;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("SELECTOR")) return 3;
	if (inName==HX_CSTRING("STYLES")) return 5;
	return super::__FindIndex(inName);
}

int StyleRuleParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_SELECTOR")) return 0;
	if (inName==HX_CSTRING("BEGIN_STYLES")) return 0;
	if (inName==HX_CSTRING("END_SELECTOR")) return 0;
	if (inName==HX_CSTRING("END_STYLES")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("SELECTOR")) return 0;
	if (inName==HX_CSTRING("STYLES")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StyleRuleParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BEGIN_SELECTOR")) return BEGIN_SELECTOR;
	if (inName==HX_CSTRING("BEGIN_STYLES")) return BEGIN_STYLES;
	if (inName==HX_CSTRING("END_SELECTOR")) return END_SELECTOR;
	if (inName==HX_CSTRING("END_STYLES")) return END_STYLES;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("SELECTOR")) return SELECTOR;
	if (inName==HX_CSTRING("STYLES")) return STYLES;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("BEGIN_SELECTOR"),
	HX_CSTRING("END_SELECTOR"),
	HX_CSTRING("SELECTOR"),
	HX_CSTRING("BEGIN_STYLES"),
	HX_CSTRING("STYLES"),
	HX_CSTRING("END_STYLES"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::BEGIN_SELECTOR,"BEGIN_SELECTOR");
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::BEGIN_STYLES,"BEGIN_STYLES");
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::END_SELECTOR,"END_SELECTOR");
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::END_STYLES,"END_STYLES");
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::SELECTOR,"SELECTOR");
	HX_MARK_MEMBER_NAME(StyleRuleParserState_obj::STYLES,"STYLES");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::BEGIN_SELECTOR,"BEGIN_SELECTOR");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::BEGIN_STYLES,"BEGIN_STYLES");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::END_SELECTOR,"END_SELECTOR");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::END_STYLES,"END_STYLES");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::SELECTOR,"SELECTOR");
	HX_VISIT_MEMBER_NAME(StyleRuleParserState_obj::STYLES,"STYLES");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StyleRuleParserState_obj::__mClass;

Dynamic __Create_StyleRuleParserState_obj() { return new StyleRuleParserState_obj; }

void StyleRuleParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.StyleRuleParserState"), hx::TCanCast< StyleRuleParserState_obj >,sStaticFields,sMemberFields,
	&__Create_StyleRuleParserState_obj, &__Create,
	&super::__SGetClass(), &CreateStyleRuleParserState_obj, sMarkStatics, sVisitStatic);
}

void StyleRuleParserState_obj::__boot()
{
Static(BEGIN_SELECTOR) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("BEGIN_SELECTOR"),1);
Static(BEGIN_STYLES) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("BEGIN_STYLES"),4);
Static(END_SELECTOR) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("END_SELECTOR"),2);
Static(END_STYLES) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("END_STYLES"),6);
Static(IGNORE_SPACES) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("IGNORE_SPACES"),0);
Static(SELECTOR) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("SELECTOR"),3);
Static(STYLES) = hx::CreateEnum< StyleRuleParserState_obj >(HX_CSTRING("STYLES"),5);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
