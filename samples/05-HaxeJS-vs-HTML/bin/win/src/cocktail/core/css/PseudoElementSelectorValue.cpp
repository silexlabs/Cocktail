#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_PseudoElementSelectorValue
#include <cocktail/core/css/PseudoElementSelectorValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::PseudoElementSelectorValue PseudoElementSelectorValue_obj::AFTER;

::cocktail::core::css::PseudoElementSelectorValue PseudoElementSelectorValue_obj::BEFORE;

::cocktail::core::css::PseudoElementSelectorValue PseudoElementSelectorValue_obj::FIRST_LETTER;

::cocktail::core::css::PseudoElementSelectorValue PseudoElementSelectorValue_obj::FIRST_LINE;

::cocktail::core::css::PseudoElementSelectorValue PseudoElementSelectorValue_obj::NONE;

HX_DEFINE_CREATE_ENUM(PseudoElementSelectorValue_obj)

int PseudoElementSelectorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("AFTER")) return 4;
	if (inName==HX_CSTRING("BEFORE")) return 3;
	if (inName==HX_CSTRING("FIRST_LETTER")) return 2;
	if (inName==HX_CSTRING("FIRST_LINE")) return 1;
	if (inName==HX_CSTRING("NONE")) return 0;
	return super::__FindIndex(inName);
}

int PseudoElementSelectorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("AFTER")) return 0;
	if (inName==HX_CSTRING("BEFORE")) return 0;
	if (inName==HX_CSTRING("FIRST_LETTER")) return 0;
	if (inName==HX_CSTRING("FIRST_LINE")) return 0;
	if (inName==HX_CSTRING("NONE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic PseudoElementSelectorValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("AFTER")) return AFTER;
	if (inName==HX_CSTRING("BEFORE")) return BEFORE;
	if (inName==HX_CSTRING("FIRST_LETTER")) return FIRST_LETTER;
	if (inName==HX_CSTRING("FIRST_LINE")) return FIRST_LINE;
	if (inName==HX_CSTRING("NONE")) return NONE;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NONE"),
	HX_CSTRING("FIRST_LINE"),
	HX_CSTRING("FIRST_LETTER"),
	HX_CSTRING("BEFORE"),
	HX_CSTRING("AFTER"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PseudoElementSelectorValue_obj::AFTER,"AFTER");
	HX_MARK_MEMBER_NAME(PseudoElementSelectorValue_obj::BEFORE,"BEFORE");
	HX_MARK_MEMBER_NAME(PseudoElementSelectorValue_obj::FIRST_LETTER,"FIRST_LETTER");
	HX_MARK_MEMBER_NAME(PseudoElementSelectorValue_obj::FIRST_LINE,"FIRST_LINE");
	HX_MARK_MEMBER_NAME(PseudoElementSelectorValue_obj::NONE,"NONE");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PseudoElementSelectorValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PseudoElementSelectorValue_obj::AFTER,"AFTER");
	HX_VISIT_MEMBER_NAME(PseudoElementSelectorValue_obj::BEFORE,"BEFORE");
	HX_VISIT_MEMBER_NAME(PseudoElementSelectorValue_obj::FIRST_LETTER,"FIRST_LETTER");
	HX_VISIT_MEMBER_NAME(PseudoElementSelectorValue_obj::FIRST_LINE,"FIRST_LINE");
	HX_VISIT_MEMBER_NAME(PseudoElementSelectorValue_obj::NONE,"NONE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class PseudoElementSelectorValue_obj::__mClass;

Dynamic __Create_PseudoElementSelectorValue_obj() { return new PseudoElementSelectorValue_obj; }

void PseudoElementSelectorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.PseudoElementSelectorValue"), hx::TCanCast< PseudoElementSelectorValue_obj >,sStaticFields,sMemberFields,
	&__Create_PseudoElementSelectorValue_obj, &__Create,
	&super::__SGetClass(), &CreatePseudoElementSelectorValue_obj, sMarkStatics, sVisitStatic);
}

void PseudoElementSelectorValue_obj::__boot()
{
Static(AFTER) = hx::CreateEnum< PseudoElementSelectorValue_obj >(HX_CSTRING("AFTER"),4);
Static(BEFORE) = hx::CreateEnum< PseudoElementSelectorValue_obj >(HX_CSTRING("BEFORE"),3);
Static(FIRST_LETTER) = hx::CreateEnum< PseudoElementSelectorValue_obj >(HX_CSTRING("FIRST_LETTER"),2);
Static(FIRST_LINE) = hx::CreateEnum< PseudoElementSelectorValue_obj >(HX_CSTRING("FIRST_LINE"),1);
Static(NONE) = hx::CreateEnum< PseudoElementSelectorValue_obj >(HX_CSTRING("NONE"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
