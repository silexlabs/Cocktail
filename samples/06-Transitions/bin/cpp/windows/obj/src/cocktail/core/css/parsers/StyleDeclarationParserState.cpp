#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_StyleDeclarationParserState
#include <cocktail/core/css/parsers/StyleDeclarationParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::BEGIN;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::BEGIN_COMMENT;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::COMMENT;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::END_COMMENT;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::INVALID_STYLE;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::STYLE_NAME;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::STYLE_SEPARATOR;

::cocktail::core::css::parsers::StyleDeclarationParserState StyleDeclarationParserState_obj::STYLE_VALUE;

HX_DEFINE_CREATE_ENUM(StyleDeclarationParserState_obj)

int StyleDeclarationParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BEGIN")) return 5;
	if (inName==HX_CSTRING("BEGIN_COMMENT")) return 7;
	if (inName==HX_CSTRING("COMMENT")) return 6;
	if (inName==HX_CSTRING("END_COMMENT")) return 8;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 2;
	if (inName==HX_CSTRING("INVALID_STYLE")) return 3;
	if (inName==HX_CSTRING("STYLE_NAME")) return 0;
	if (inName==HX_CSTRING("STYLE_SEPARATOR")) return 4;
	if (inName==HX_CSTRING("STYLE_VALUE")) return 1;
	return super::__FindIndex(inName);
}

int StyleDeclarationParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BEGIN")) return 0;
	if (inName==HX_CSTRING("BEGIN_COMMENT")) return 0;
	if (inName==HX_CSTRING("COMMENT")) return 0;
	if (inName==HX_CSTRING("END_COMMENT")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("INVALID_STYLE")) return 0;
	if (inName==HX_CSTRING("STYLE_NAME")) return 0;
	if (inName==HX_CSTRING("STYLE_SEPARATOR")) return 0;
	if (inName==HX_CSTRING("STYLE_VALUE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StyleDeclarationParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BEGIN")) return BEGIN;
	if (inName==HX_CSTRING("BEGIN_COMMENT")) return BEGIN_COMMENT;
	if (inName==HX_CSTRING("COMMENT")) return COMMENT;
	if (inName==HX_CSTRING("END_COMMENT")) return END_COMMENT;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("INVALID_STYLE")) return INVALID_STYLE;
	if (inName==HX_CSTRING("STYLE_NAME")) return STYLE_NAME;
	if (inName==HX_CSTRING("STYLE_SEPARATOR")) return STYLE_SEPARATOR;
	if (inName==HX_CSTRING("STYLE_VALUE")) return STYLE_VALUE;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("STYLE_NAME"),
	HX_CSTRING("STYLE_VALUE"),
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("INVALID_STYLE"),
	HX_CSTRING("STYLE_SEPARATOR"),
	HX_CSTRING("BEGIN"),
	HX_CSTRING("COMMENT"),
	HX_CSTRING("BEGIN_COMMENT"),
	HX_CSTRING("END_COMMENT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::BEGIN,"BEGIN");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::BEGIN_COMMENT,"BEGIN_COMMENT");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::COMMENT,"COMMENT");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::END_COMMENT,"END_COMMENT");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::INVALID_STYLE,"INVALID_STYLE");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::STYLE_NAME,"STYLE_NAME");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::STYLE_SEPARATOR,"STYLE_SEPARATOR");
	HX_MARK_MEMBER_NAME(StyleDeclarationParserState_obj::STYLE_VALUE,"STYLE_VALUE");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::BEGIN,"BEGIN");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::BEGIN_COMMENT,"BEGIN_COMMENT");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::COMMENT,"COMMENT");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::END_COMMENT,"END_COMMENT");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::INVALID_STYLE,"INVALID_STYLE");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::STYLE_NAME,"STYLE_NAME");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::STYLE_SEPARATOR,"STYLE_SEPARATOR");
	HX_VISIT_MEMBER_NAME(StyleDeclarationParserState_obj::STYLE_VALUE,"STYLE_VALUE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StyleDeclarationParserState_obj::__mClass;

Dynamic __Create_StyleDeclarationParserState_obj() { return new StyleDeclarationParserState_obj; }

void StyleDeclarationParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.StyleDeclarationParserState"), hx::TCanCast< StyleDeclarationParserState_obj >,sStaticFields,sMemberFields,
	&__Create_StyleDeclarationParserState_obj, &__Create,
	&super::__SGetClass(), &CreateStyleDeclarationParserState_obj, sMarkStatics, sVisitStatic);
}

void StyleDeclarationParserState_obj::__boot()
{
Static(BEGIN) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("BEGIN"),5);
Static(BEGIN_COMMENT) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("BEGIN_COMMENT"),7);
Static(COMMENT) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("COMMENT"),6);
Static(END_COMMENT) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("END_COMMENT"),8);
Static(IGNORE_SPACES) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("IGNORE_SPACES"),2);
Static(INVALID_STYLE) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("INVALID_STYLE"),3);
Static(STYLE_NAME) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("STYLE_NAME"),0);
Static(STYLE_SEPARATOR) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("STYLE_SEPARATOR"),4);
Static(STYLE_VALUE) = hx::CreateEnum< StyleDeclarationParserState_obj >(HX_CSTRING("STYLE_VALUE"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
