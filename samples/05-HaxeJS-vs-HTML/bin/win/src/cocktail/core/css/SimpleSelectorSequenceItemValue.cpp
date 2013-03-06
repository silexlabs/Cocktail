#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_AttributeSelectorValue
#include <cocktail/core/css/AttributeSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoClassSelectorValue
#include <cocktail/core/css/PseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue
#include <cocktail/core/css/SimpleSelectorSequenceItemValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::SimpleSelectorSequenceItemValue  SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue value)
	{ return hx::CreateEnum< SimpleSelectorSequenceItemValue_obj >(HX_CSTRING("ATTRIBUTE"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::SimpleSelectorSequenceItemValue  SimpleSelectorSequenceItemValue_obj::CSS_CLASS(::String value)
	{ return hx::CreateEnum< SimpleSelectorSequenceItemValue_obj >(HX_CSTRING("CSS_CLASS"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::SimpleSelectorSequenceItemValue  SimpleSelectorSequenceItemValue_obj::ID(::String value)
	{ return hx::CreateEnum< SimpleSelectorSequenceItemValue_obj >(HX_CSTRING("ID"),3,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::SimpleSelectorSequenceItemValue  SimpleSelectorSequenceItemValue_obj::PSEUDO_CLASS(::cocktail::core::css::PseudoClassSelectorValue value)
	{ return hx::CreateEnum< SimpleSelectorSequenceItemValue_obj >(HX_CSTRING("PSEUDO_CLASS"),1,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(SimpleSelectorSequenceItemValue_obj)

int SimpleSelectorSequenceItemValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return 0;
	if (inName==HX_CSTRING("CSS_CLASS")) return 2;
	if (inName==HX_CSTRING("ID")) return 3;
	if (inName==HX_CSTRING("PSEUDO_CLASS")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleSelectorSequenceItemValue_obj,ATTRIBUTE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleSelectorSequenceItemValue_obj,CSS_CLASS,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleSelectorSequenceItemValue_obj,ID,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleSelectorSequenceItemValue_obj,PSEUDO_CLASS,return)

int SimpleSelectorSequenceItemValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return 1;
	if (inName==HX_CSTRING("CSS_CLASS")) return 1;
	if (inName==HX_CSTRING("ID")) return 1;
	if (inName==HX_CSTRING("PSEUDO_CLASS")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic SimpleSelectorSequenceItemValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return ATTRIBUTE_dyn();
	if (inName==HX_CSTRING("CSS_CLASS")) return CSS_CLASS_dyn();
	if (inName==HX_CSTRING("ID")) return ID_dyn();
	if (inName==HX_CSTRING("PSEUDO_CLASS")) return PSEUDO_CLASS_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ATTRIBUTE"),
	HX_CSTRING("PSEUDO_CLASS"),
	HX_CSTRING("CSS_CLASS"),
	HX_CSTRING("ID"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleSelectorSequenceItemValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class SimpleSelectorSequenceItemValue_obj::__mClass;

Dynamic __Create_SimpleSelectorSequenceItemValue_obj() { return new SimpleSelectorSequenceItemValue_obj; }

void SimpleSelectorSequenceItemValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SimpleSelectorSequenceItemValue"), hx::TCanCast< SimpleSelectorSequenceItemValue_obj >,sStaticFields,sMemberFields,
	&__Create_SimpleSelectorSequenceItemValue_obj, &__Create,
	&super::__SGetClass(), &CreateSimpleSelectorSequenceItemValue_obj, sMarkStatics, sVisitStatic);
}

void SimpleSelectorSequenceItemValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
