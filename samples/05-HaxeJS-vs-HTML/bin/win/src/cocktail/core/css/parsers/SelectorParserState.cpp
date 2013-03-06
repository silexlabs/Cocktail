#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_parsers_SelectorParserState
#include <cocktail/core/css/parsers/SelectorParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::BEGIN_ATTRIBUTE_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::BEGIN_COMBINATOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::BEGIN_PSEUDO_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::COMBINATOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::END_CLASS_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::END_ID_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::END_SIMPLE_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::END_TYPE_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::END_UNIVERSAL_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::IGNORE_SPACES;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::INVALID_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::PSEUDO_ELEMENT_SELECTOR;

::cocktail::core::css::parsers::SelectorParserState SelectorParserState_obj::SIMPLE_SELECTOR;

HX_DEFINE_CREATE_ENUM(SelectorParserState_obj)

int SelectorParserState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_ATTRIBUTE_SELECTOR")) return 12;
	if (inName==HX_CSTRING("BEGIN_COMBINATOR")) return 7;
	if (inName==HX_CSTRING("BEGIN_PSEUDO_SELECTOR")) return 9;
	if (inName==HX_CSTRING("BEGIN_SIMPLE_SELECTOR")) return 1;
	if (inName==HX_CSTRING("COMBINATOR")) return 8;
	if (inName==HX_CSTRING("END_CLASS_SELECTOR")) return 5;
	if (inName==HX_CSTRING("END_ID_SELECTOR")) return 6;
	if (inName==HX_CSTRING("END_SIMPLE_SELECTOR")) return 2;
	if (inName==HX_CSTRING("END_TYPE_SELECTOR")) return 4;
	if (inName==HX_CSTRING("END_UNIVERSAL_SELECTOR")) return 10;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("INVALID_SELECTOR")) return 13;
	if (inName==HX_CSTRING("PSEUDO_ELEMENT_SELECTOR")) return 11;
	if (inName==HX_CSTRING("SIMPLE_SELECTOR")) return 3;
	return super::__FindIndex(inName);
}

int SelectorParserState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BEGIN_ATTRIBUTE_SELECTOR")) return 0;
	if (inName==HX_CSTRING("BEGIN_COMBINATOR")) return 0;
	if (inName==HX_CSTRING("BEGIN_PSEUDO_SELECTOR")) return 0;
	if (inName==HX_CSTRING("BEGIN_SIMPLE_SELECTOR")) return 0;
	if (inName==HX_CSTRING("COMBINATOR")) return 0;
	if (inName==HX_CSTRING("END_CLASS_SELECTOR")) return 0;
	if (inName==HX_CSTRING("END_ID_SELECTOR")) return 0;
	if (inName==HX_CSTRING("END_SIMPLE_SELECTOR")) return 0;
	if (inName==HX_CSTRING("END_TYPE_SELECTOR")) return 0;
	if (inName==HX_CSTRING("END_UNIVERSAL_SELECTOR")) return 0;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return 0;
	if (inName==HX_CSTRING("INVALID_SELECTOR")) return 0;
	if (inName==HX_CSTRING("PSEUDO_ELEMENT_SELECTOR")) return 0;
	if (inName==HX_CSTRING("SIMPLE_SELECTOR")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic SelectorParserState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BEGIN_ATTRIBUTE_SELECTOR")) return BEGIN_ATTRIBUTE_SELECTOR;
	if (inName==HX_CSTRING("BEGIN_COMBINATOR")) return BEGIN_COMBINATOR;
	if (inName==HX_CSTRING("BEGIN_PSEUDO_SELECTOR")) return BEGIN_PSEUDO_SELECTOR;
	if (inName==HX_CSTRING("BEGIN_SIMPLE_SELECTOR")) return BEGIN_SIMPLE_SELECTOR;
	if (inName==HX_CSTRING("COMBINATOR")) return COMBINATOR;
	if (inName==HX_CSTRING("END_CLASS_SELECTOR")) return END_CLASS_SELECTOR;
	if (inName==HX_CSTRING("END_ID_SELECTOR")) return END_ID_SELECTOR;
	if (inName==HX_CSTRING("END_SIMPLE_SELECTOR")) return END_SIMPLE_SELECTOR;
	if (inName==HX_CSTRING("END_TYPE_SELECTOR")) return END_TYPE_SELECTOR;
	if (inName==HX_CSTRING("END_UNIVERSAL_SELECTOR")) return END_UNIVERSAL_SELECTOR;
	if (inName==HX_CSTRING("IGNORE_SPACES")) return IGNORE_SPACES;
	if (inName==HX_CSTRING("INVALID_SELECTOR")) return INVALID_SELECTOR;
	if (inName==HX_CSTRING("PSEUDO_ELEMENT_SELECTOR")) return PSEUDO_ELEMENT_SELECTOR;
	if (inName==HX_CSTRING("SIMPLE_SELECTOR")) return SIMPLE_SELECTOR;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("IGNORE_SPACES"),
	HX_CSTRING("BEGIN_SIMPLE_SELECTOR"),
	HX_CSTRING("END_SIMPLE_SELECTOR"),
	HX_CSTRING("SIMPLE_SELECTOR"),
	HX_CSTRING("END_TYPE_SELECTOR"),
	HX_CSTRING("END_CLASS_SELECTOR"),
	HX_CSTRING("END_ID_SELECTOR"),
	HX_CSTRING("BEGIN_COMBINATOR"),
	HX_CSTRING("COMBINATOR"),
	HX_CSTRING("BEGIN_PSEUDO_SELECTOR"),
	HX_CSTRING("END_UNIVERSAL_SELECTOR"),
	HX_CSTRING("PSEUDO_ELEMENT_SELECTOR"),
	HX_CSTRING("BEGIN_ATTRIBUTE_SELECTOR"),
	HX_CSTRING("INVALID_SELECTOR"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::BEGIN_ATTRIBUTE_SELECTOR,"BEGIN_ATTRIBUTE_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::BEGIN_COMBINATOR,"BEGIN_COMBINATOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::BEGIN_PSEUDO_SELECTOR,"BEGIN_PSEUDO_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR,"BEGIN_SIMPLE_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::COMBINATOR,"COMBINATOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::END_CLASS_SELECTOR,"END_CLASS_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::END_ID_SELECTOR,"END_ID_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::END_SIMPLE_SELECTOR,"END_SIMPLE_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::END_TYPE_SELECTOR,"END_TYPE_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::END_UNIVERSAL_SELECTOR,"END_UNIVERSAL_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::INVALID_SELECTOR,"INVALID_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::PSEUDO_ELEMENT_SELECTOR,"PSEUDO_ELEMENT_SELECTOR");
	HX_MARK_MEMBER_NAME(SelectorParserState_obj::SIMPLE_SELECTOR,"SIMPLE_SELECTOR");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::BEGIN_ATTRIBUTE_SELECTOR,"BEGIN_ATTRIBUTE_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::BEGIN_COMBINATOR,"BEGIN_COMBINATOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::BEGIN_PSEUDO_SELECTOR,"BEGIN_PSEUDO_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR,"BEGIN_SIMPLE_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::COMBINATOR,"COMBINATOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::END_CLASS_SELECTOR,"END_CLASS_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::END_ID_SELECTOR,"END_ID_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::END_SIMPLE_SELECTOR,"END_SIMPLE_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::END_TYPE_SELECTOR,"END_TYPE_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::END_UNIVERSAL_SELECTOR,"END_UNIVERSAL_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::IGNORE_SPACES,"IGNORE_SPACES");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::INVALID_SELECTOR,"INVALID_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::PSEUDO_ELEMENT_SELECTOR,"PSEUDO_ELEMENT_SELECTOR");
	HX_VISIT_MEMBER_NAME(SelectorParserState_obj::SIMPLE_SELECTOR,"SIMPLE_SELECTOR");
};

static ::String sMemberFields[] = { ::String(null()) };
Class SelectorParserState_obj::__mClass;

Dynamic __Create_SelectorParserState_obj() { return new SelectorParserState_obj; }

void SelectorParserState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.SelectorParserState"), hx::TCanCast< SelectorParserState_obj >,sStaticFields,sMemberFields,
	&__Create_SelectorParserState_obj, &__Create,
	&super::__SGetClass(), &CreateSelectorParserState_obj, sMarkStatics, sVisitStatic);
}

void SelectorParserState_obj::__boot()
{
Static(BEGIN_ATTRIBUTE_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("BEGIN_ATTRIBUTE_SELECTOR"),12);
Static(BEGIN_COMBINATOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("BEGIN_COMBINATOR"),7);
Static(BEGIN_PSEUDO_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("BEGIN_PSEUDO_SELECTOR"),9);
Static(BEGIN_SIMPLE_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("BEGIN_SIMPLE_SELECTOR"),1);
Static(COMBINATOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("COMBINATOR"),8);
Static(END_CLASS_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("END_CLASS_SELECTOR"),5);
Static(END_ID_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("END_ID_SELECTOR"),6);
Static(END_SIMPLE_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("END_SIMPLE_SELECTOR"),2);
Static(END_TYPE_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("END_TYPE_SELECTOR"),4);
Static(END_UNIVERSAL_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("END_UNIVERSAL_SELECTOR"),10);
Static(IGNORE_SPACES) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("IGNORE_SPACES"),0);
Static(INVALID_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("INVALID_SELECTOR"),13);
Static(PSEUDO_ELEMENT_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("PSEUDO_ELEMENT_SELECTOR"),11);
Static(SIMPLE_SELECTOR) = hx::CreateEnum< SelectorParserState_obj >(HX_CSTRING("SIMPLE_SELECTOR"),3);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
