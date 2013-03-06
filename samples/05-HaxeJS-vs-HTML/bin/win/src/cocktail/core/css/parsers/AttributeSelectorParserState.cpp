#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_AttributeSelectorParserState
#include <cocktail/core/css/parsers/AttributeSelectorParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::ATTRIBUTE;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::BEGIN_OPERATOR;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::END_OPERATOR;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::END_SELECTOR;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::IDENTIFIER_VALUE;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::INVALID_SELECTOR;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::OPERATOR;

::cocktail::core::css::parsers::AttributeSelectorParserState AttributeSelectorParserState_obj::STRING_VALUE;

HX_DEFINE_CREATE_ENUM(AttributeSelectorParserState_obj)

int AttributeSelectorParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return 2;
	if (inName==HX_CSTRING("BEGIN_OPERATOR")) return 3;
	if (inName==HX_CSTRING("END_OPERATOR")) return 1;
	if (inName==HX_CSTRING("END_SELECTOR")) return 7;
	if (inName==HX_CSTRING("IDENTIFIER_VALUE")) return 5;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("INVALID_SELECTOR")) return 8;
	if (inName==HX_CSTRING("OPERATOR")) return 4;
	if (inName==HX_CSTRING("STRING_VALUE")) return 6;
	return super::__FindIndex(inName);
}

int AttributeSelectorParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return 0;
	if (inName==HX_CSTRING("BEGIN_OPERATOR")) return 0;
	if (inName==HX_CSTRING("END_OPERATOR")) return 0;
	if (inName==HX_CSTRING("END_SELECTOR")) return 0;
	if (inName==HX_CSTRING("IDENTIFIER_VALUE")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("INVALID_SELECTOR")) return 0;
	if (inName==HX_CSTRING("OPERATOR")) return 0;
	if (inName==HX_CSTRING("STRING_VALUE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic AttributeSelectorParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return ATTRIBUTE;
	if (inName==HX_CSTRING("BEGIN_OPERATOR")) return BEGIN_OPERATOR;
	if (inName==HX_CSTRING("END_OPERATOR")) return END_OPERATOR;
	if (inName==HX_CSTRING("END_SELECTOR")) return END_SELECTOR;
	if (inName==HX_CSTRING("IDENTIFIER_VALUE")) return IDENTIFIER_VALUE;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("INVALID_SELECTOR")) return INVALID_SELECTOR;
	if (inName==HX_CSTRING("OPERATOR")) return OPERATOR;
	if (inName==HX_CSTRING("STRING_VALUE")) return STRING_VALUE;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("END_OPERATOR"),
	HX_CSTRING("ATTRIBUTE"),
	HX_CSTRING("BEGIN_OPERATOR"),
	HX_CSTRING("OPERATOR"),
	HX_CSTRING("IDENTIFIER_VALUE"),
	HX_CSTRING("STRING_VALUE"),
	HX_CSTRING("END_SELECTOR"),
	HX_CSTRING("INVALID_SELECTOR"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::ATTRIBUTE,"ATTRIBUTE");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::BEGIN_OPERATOR,"BEGIN_OPERATOR");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::END_OPERATOR,"END_OPERATOR");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::END_SELECTOR,"END_SELECTOR");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::IDENTIFIER_VALUE,"IDENTIFIER_VALUE");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::INVALID_SELECTOR,"INVALID_SELECTOR");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::OPERATOR,"OPERATOR");
	HX_MARK_MEMBER_NAME(AttributeSelectorParserState_obj::STRING_VALUE,"STRING_VALUE");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::ATTRIBUTE,"ATTRIBUTE");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::BEGIN_OPERATOR,"BEGIN_OPERATOR");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::END_OPERATOR,"END_OPERATOR");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::END_SELECTOR,"END_SELECTOR");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::IDENTIFIER_VALUE,"IDENTIFIER_VALUE");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::INVALID_SELECTOR,"INVALID_SELECTOR");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::OPERATOR,"OPERATOR");
	HX_VISIT_MEMBER_NAME(AttributeSelectorParserState_obj::STRING_VALUE,"STRING_VALUE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class AttributeSelectorParserState_obj::__mClass;

Dynamic __Create_AttributeSelectorParserState_obj() { return new AttributeSelectorParserState_obj; }

void AttributeSelectorParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.AttributeSelectorParserState"), hx::TCanCast< AttributeSelectorParserState_obj >,sStaticFields,sMemberFields,
	&__Create_AttributeSelectorParserState_obj, &__Create,
	&super::__SGetClass(), &CreateAttributeSelectorParserState_obj, sMarkStatics, sVisitStatic);
}

void AttributeSelectorParserState_obj::__boot()
{
Static(ATTRIBUTE) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("ATTRIBUTE"),2);
Static(BEGIN_OPERATOR) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("BEGIN_OPERATOR"),3);
Static(END_OPERATOR) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("END_OPERATOR"),1);
Static(END_SELECTOR) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("END_SELECTOR"),7);
Static(IDENTIFIER_VALUE) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("IDENTIFIER_VALUE"),5);
Static(IGNORE_SPACES) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("IGNORE_SPACES"),0);
Static(INVALID_SELECTOR) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("INVALID_SELECTOR"),8);
Static(OPERATOR) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("OPERATOR"),4);
Static(STRING_VALUE) = hx::CreateEnum< AttributeSelectorParserState_obj >(HX_CSTRING("STRING_VALUE"),6);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
