#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_LinkPseudoClassValue
#include <cocktail/core/css/LinkPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoClassSelectorValue
#include <cocktail/core/css/PseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue
#include <cocktail/core/css/StructuralPseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UIElementStatesValue
#include <cocktail/core/css/UIElementStatesValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UserActionPseudoClassValue
#include <cocktail/core/css/UserActionPseudoClassValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::PseudoClassSelectorValue  PseudoClassSelectorValue_obj::LANG(Array< ::String > value)
	{ return hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("LANG"),3,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::PseudoClassSelectorValue  PseudoClassSelectorValue_obj::LINK(::cocktail::core::css::LinkPseudoClassValue value)
	{ return hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("LINK"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::PseudoClassSelectorValue  PseudoClassSelectorValue_obj::NOT(::cocktail::core::css::SimpleSelectorSequenceVO value)
	{ return hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("NOT"),6,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::PseudoClassSelectorValue  PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue value)
	{ return hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("STRUCTURAL"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::PseudoClassSelectorValue PseudoClassSelectorValue_obj::TARGET;

::cocktail::core::css::PseudoClassSelectorValue  PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue value)
	{ return hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("UI_ELEMENT_STATES"),5,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::PseudoClassSelectorValue  PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue value)
	{ return hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("USER_ACTION"),4,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(PseudoClassSelectorValue_obj)

int PseudoClassSelectorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("LANG")) return 3;
	if (inName==HX_CSTRING("LINK")) return 1;
	if (inName==HX_CSTRING("NOT")) return 6;
	if (inName==HX_CSTRING("STRUCTURAL")) return 0;
	if (inName==HX_CSTRING("TARGET")) return 2;
	if (inName==HX_CSTRING("UI_ELEMENT_STATES")) return 5;
	if (inName==HX_CSTRING("USER_ACTION")) return 4;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PseudoClassSelectorValue_obj,LANG,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PseudoClassSelectorValue_obj,LINK,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PseudoClassSelectorValue_obj,NOT,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PseudoClassSelectorValue_obj,STRUCTURAL,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PseudoClassSelectorValue_obj,UI_ELEMENT_STATES,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(PseudoClassSelectorValue_obj,USER_ACTION,return)

int PseudoClassSelectorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("LANG")) return 1;
	if (inName==HX_CSTRING("LINK")) return 1;
	if (inName==HX_CSTRING("NOT")) return 1;
	if (inName==HX_CSTRING("STRUCTURAL")) return 1;
	if (inName==HX_CSTRING("TARGET")) return 0;
	if (inName==HX_CSTRING("UI_ELEMENT_STATES")) return 1;
	if (inName==HX_CSTRING("USER_ACTION")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic PseudoClassSelectorValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("LANG")) return LANG_dyn();
	if (inName==HX_CSTRING("LINK")) return LINK_dyn();
	if (inName==HX_CSTRING("NOT")) return NOT_dyn();
	if (inName==HX_CSTRING("STRUCTURAL")) return STRUCTURAL_dyn();
	if (inName==HX_CSTRING("TARGET")) return TARGET;
	if (inName==HX_CSTRING("UI_ELEMENT_STATES")) return UI_ELEMENT_STATES_dyn();
	if (inName==HX_CSTRING("USER_ACTION")) return USER_ACTION_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("STRUCTURAL"),
	HX_CSTRING("LINK"),
	HX_CSTRING("TARGET"),
	HX_CSTRING("LANG"),
	HX_CSTRING("USER_ACTION"),
	HX_CSTRING("UI_ELEMENT_STATES"),
	HX_CSTRING("NOT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PseudoClassSelectorValue_obj::TARGET,"TARGET");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PseudoClassSelectorValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PseudoClassSelectorValue_obj::TARGET,"TARGET");
};

static ::String sMemberFields[] = { ::String(null()) };
Class PseudoClassSelectorValue_obj::__mClass;

Dynamic __Create_PseudoClassSelectorValue_obj() { return new PseudoClassSelectorValue_obj; }

void PseudoClassSelectorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.PseudoClassSelectorValue"), hx::TCanCast< PseudoClassSelectorValue_obj >,sStaticFields,sMemberFields,
	&__Create_PseudoClassSelectorValue_obj, &__Create,
	&super::__SGetClass(), &CreatePseudoClassSelectorValue_obj, sMarkStatics, sVisitStatic);
}

void PseudoClassSelectorValue_obj::__boot()
{
Static(TARGET) = hx::CreateEnum< PseudoClassSelectorValue_obj >(HX_CSTRING("TARGET"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
