#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CombinatorValue
#include <cocktail/core/css/CombinatorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorComponentValue
#include <cocktail/core/css/SelectorComponentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::SelectorComponentValue  SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue value)
	{ return hx::CreateEnum< SelectorComponentValue_obj >(HX_CSTRING("COMBINATOR"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::SelectorComponentValue  SelectorComponentValue_obj::SIMPLE_SELECTOR_SEQUENCE(::cocktail::core::css::SimpleSelectorSequenceVO value)
	{ return hx::CreateEnum< SelectorComponentValue_obj >(HX_CSTRING("SIMPLE_SELECTOR_SEQUENCE"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(SelectorComponentValue_obj)

int SelectorComponentValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("COMBINATOR")) return 1;
	if (inName==HX_CSTRING("SIMPLE_SELECTOR_SEQUENCE")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorComponentValue_obj,COMBINATOR,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SelectorComponentValue_obj,SIMPLE_SELECTOR_SEQUENCE,return)

int SelectorComponentValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("COMBINATOR")) return 1;
	if (inName==HX_CSTRING("SIMPLE_SELECTOR_SEQUENCE")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic SelectorComponentValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("COMBINATOR")) return COMBINATOR_dyn();
	if (inName==HX_CSTRING("SIMPLE_SELECTOR_SEQUENCE")) return SIMPLE_SELECTOR_SEQUENCE_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("SIMPLE_SELECTOR_SEQUENCE"),
	HX_CSTRING("COMBINATOR"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SelectorComponentValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class SelectorComponentValue_obj::__mClass;

Dynamic __Create_SelectorComponentValue_obj() { return new SelectorComponentValue_obj; }

void SelectorComponentValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SelectorComponentValue"), hx::TCanCast< SelectorComponentValue_obj >,sStaticFields,sMemberFields,
	&__Create_SelectorComponentValue_obj, &__Create,
	&super::__SGetClass(), &CreateSelectorComponentValue_obj, sMarkStatics, sVisitStatic);
}

void SelectorComponentValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
