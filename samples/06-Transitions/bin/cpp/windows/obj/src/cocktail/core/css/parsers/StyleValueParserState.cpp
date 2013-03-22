#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_StyleValueParserState
#include <cocktail/core/css/parsers/StyleValueParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::BEGIN_VALUE;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::COMPONENT_OR_END;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::END;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::HEX;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::IDENT_FUNCTION;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::IMPORTANT;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::INVALID_STYLE_VALUE;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::NUMBER_INTEGER_DIMENSION_PERCENTAGE;

::cocktail::core::css::parsers::StyleValueParserState StyleValueParserState_obj::STRING;

HX_DEFINE_CREATE_ENUM(StyleValueParserState_obj)

int StyleValueParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_VALUE")) return 1;
	if (inName==HX_CSTRING("COMPONENT_OR_END")) return 4;
	if (inName==HX_CSTRING("END")) return 7;
	if (inName==HX_CSTRING("HEX")) return 8;
	if (inName==HX_CSTRING("IDENT_FUNCTION")) return 2;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("IMPORTANT")) return 6;
	if (inName==HX_CSTRING("INVALID_STYLE_VALUE")) return 5;
	if (inName==HX_CSTRING("NUMBER_INTEGER_DIMENSION_PERCENTAGE")) return 3;
	if (inName==HX_CSTRING("STRING")) return 9;
	return super::__FindIndex(inName);
}

int StyleValueParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_VALUE")) return 0;
	if (inName==HX_CSTRING("COMPONENT_OR_END")) return 0;
	if (inName==HX_CSTRING("END")) return 0;
	if (inName==HX_CSTRING("HEX")) return 0;
	if (inName==HX_CSTRING("IDENT_FUNCTION")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("IMPORTANT")) return 0;
	if (inName==HX_CSTRING("INVALID_STYLE_VALUE")) return 0;
	if (inName==HX_CSTRING("NUMBER_INTEGER_DIMENSION_PERCENTAGE")) return 0;
	if (inName==HX_CSTRING("STRING")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StyleValueParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BEGIN_VALUE")) return BEGIN_VALUE;
	if (inName==HX_CSTRING("COMPONENT_OR_END")) return COMPONENT_OR_END;
	if (inName==HX_CSTRING("END")) return END;
	if (inName==HX_CSTRING("HEX")) return HEX;
	if (inName==HX_CSTRING("IDENT_FUNCTION")) return IDENT_FUNCTION;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("IMPORTANT")) return IMPORTANT;
	if (inName==HX_CSTRING("INVALID_STYLE_VALUE")) return INVALID_STYLE_VALUE;
	if (inName==HX_CSTRING("NUMBER_INTEGER_DIMENSION_PERCENTAGE")) return NUMBER_INTEGER_DIMENSION_PERCENTAGE;
	if (inName==HX_CSTRING("STRING")) return STRING;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("BEGIN_VALUE"),
	HX_CSTRING("IDENT_FUNCTION"),
	HX_CSTRING("NUMBER_INTEGER_DIMENSION_PERCENTAGE"),
	HX_CSTRING("COMPONENT_OR_END"),
	HX_CSTRING("INVALID_STYLE_VALUE"),
	HX_CSTRING("IMPORTANT"),
	HX_CSTRING("END"),
	HX_CSTRING("HEX"),
	HX_CSTRING("STRING"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::BEGIN_VALUE,"BEGIN_VALUE");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::COMPONENT_OR_END,"COMPONENT_OR_END");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::END,"END");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::HEX,"HEX");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::IDENT_FUNCTION,"IDENT_FUNCTION");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::IMPORTANT,"IMPORTANT");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::INVALID_STYLE_VALUE,"INVALID_STYLE_VALUE");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::NUMBER_INTEGER_DIMENSION_PERCENTAGE,"NUMBER_INTEGER_DIMENSION_PERCENTAGE");
	HX_MARK_MEMBER_NAME(StyleValueParserState_obj::STRING,"STRING");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::BEGIN_VALUE,"BEGIN_VALUE");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::COMPONENT_OR_END,"COMPONENT_OR_END");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::END,"END");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::HEX,"HEX");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::IDENT_FUNCTION,"IDENT_FUNCTION");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::IMPORTANT,"IMPORTANT");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::INVALID_STYLE_VALUE,"INVALID_STYLE_VALUE");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::NUMBER_INTEGER_DIMENSION_PERCENTAGE,"NUMBER_INTEGER_DIMENSION_PERCENTAGE");
	HX_VISIT_MEMBER_NAME(StyleValueParserState_obj::STRING,"STRING");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StyleValueParserState_obj::__mClass;

Dynamic __Create_StyleValueParserState_obj() { return new StyleValueParserState_obj; }

void StyleValueParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.StyleValueParserState"), hx::TCanCast< StyleValueParserState_obj >,sStaticFields,sMemberFields,
	&__Create_StyleValueParserState_obj, &__Create,
	&super::__SGetClass(), &CreateStyleValueParserState_obj, sMarkStatics, sVisitStatic);
}

void StyleValueParserState_obj::__boot()
{
Static(BEGIN_VALUE) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("BEGIN_VALUE"),1);
Static(COMPONENT_OR_END) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("COMPONENT_OR_END"),4);
Static(END) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("END"),7);
Static(HEX) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("HEX"),8);
Static(IDENT_FUNCTION) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("IDENT_FUNCTION"),2);
Static(IGNORE_SPACES) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("IGNORE_SPACES"),0);
Static(IMPORTANT) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("IMPORTANT"),6);
Static(INVALID_STYLE_VALUE) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("INVALID_STYLE_VALUE"),5);
Static(NUMBER_INTEGER_DIMENSION_PERCENTAGE) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("NUMBER_INTEGER_DIMENSION_PERCENTAGE"),3);
Static(STRING) = hx::CreateEnum< StyleValueParserState_obj >(HX_CSTRING("STRING"),9);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
