#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassArgumentValue
#include <cocktail/core/css/StructuralPseudoClassArgumentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue
#include <cocktail/core/css/StructuralPseudoClassSelectorValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::EMPTY;

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::FIRST_CHILD;

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::FIRST_OF_TYPE;

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::LAST_CHILD;

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::LAST_OF_TYPE;

::cocktail::core::css::StructuralPseudoClassSelectorValue  StructuralPseudoClassSelectorValue_obj::NTH_CHILD(::cocktail::core::css::StructuralPseudoClassArgumentValue value)
	{ return hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("NTH_CHILD"),8,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::StructuralPseudoClassSelectorValue  StructuralPseudoClassSelectorValue_obj::NTH_LAST_CHILD(::cocktail::core::css::StructuralPseudoClassArgumentValue value)
	{ return hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("NTH_LAST_CHILD"),9,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::StructuralPseudoClassSelectorValue  StructuralPseudoClassSelectorValue_obj::NTH_LAST_OF_TYPE(::cocktail::core::css::StructuralPseudoClassArgumentValue value)
	{ return hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("NTH_LAST_OF_TYPE"),11,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::StructuralPseudoClassSelectorValue  StructuralPseudoClassSelectorValue_obj::NTH_OF_TYPE(::cocktail::core::css::StructuralPseudoClassArgumentValue value)
	{ return hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("NTH_OF_TYPE"),10,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::ONLY_CHILD;

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::ONLY_OF_TYPE;

::cocktail::core::css::StructuralPseudoClassSelectorValue StructuralPseudoClassSelectorValue_obj::ROOT;

HX_DEFINE_CREATE_ENUM(StructuralPseudoClassSelectorValue_obj)

int StructuralPseudoClassSelectorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("EMPTY")) return 7;
	if (inName==HX_CSTRING("FIRST_CHILD")) return 1;
	if (inName==HX_CSTRING("FIRST_OF_TYPE")) return 3;
	if (inName==HX_CSTRING("LAST_CHILD")) return 2;
	if (inName==HX_CSTRING("LAST_OF_TYPE")) return 4;
	if (inName==HX_CSTRING("NTH_CHILD")) return 8;
	if (inName==HX_CSTRING("NTH_LAST_CHILD")) return 9;
	if (inName==HX_CSTRING("NTH_LAST_OF_TYPE")) return 11;
	if (inName==HX_CSTRING("NTH_OF_TYPE")) return 10;
	if (inName==HX_CSTRING("ONLY_CHILD")) return 5;
	if (inName==HX_CSTRING("ONLY_OF_TYPE")) return 6;
	if (inName==HX_CSTRING("ROOT")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StructuralPseudoClassSelectorValue_obj,NTH_CHILD,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StructuralPseudoClassSelectorValue_obj,NTH_LAST_CHILD,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StructuralPseudoClassSelectorValue_obj,NTH_LAST_OF_TYPE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StructuralPseudoClassSelectorValue_obj,NTH_OF_TYPE,return)

int StructuralPseudoClassSelectorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("EMPTY")) return 0;
	if (inName==HX_CSTRING("FIRST_CHILD")) return 0;
	if (inName==HX_CSTRING("FIRST_OF_TYPE")) return 0;
	if (inName==HX_CSTRING("LAST_CHILD")) return 0;
	if (inName==HX_CSTRING("LAST_OF_TYPE")) return 0;
	if (inName==HX_CSTRING("NTH_CHILD")) return 1;
	if (inName==HX_CSTRING("NTH_LAST_CHILD")) return 1;
	if (inName==HX_CSTRING("NTH_LAST_OF_TYPE")) return 1;
	if (inName==HX_CSTRING("NTH_OF_TYPE")) return 1;
	if (inName==HX_CSTRING("ONLY_CHILD")) return 0;
	if (inName==HX_CSTRING("ONLY_OF_TYPE")) return 0;
	if (inName==HX_CSTRING("ROOT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StructuralPseudoClassSelectorValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("EMPTY")) return EMPTY;
	if (inName==HX_CSTRING("FIRST_CHILD")) return FIRST_CHILD;
	if (inName==HX_CSTRING("FIRST_OF_TYPE")) return FIRST_OF_TYPE;
	if (inName==HX_CSTRING("LAST_CHILD")) return LAST_CHILD;
	if (inName==HX_CSTRING("LAST_OF_TYPE")) return LAST_OF_TYPE;
	if (inName==HX_CSTRING("NTH_CHILD")) return NTH_CHILD_dyn();
	if (inName==HX_CSTRING("NTH_LAST_CHILD")) return NTH_LAST_CHILD_dyn();
	if (inName==HX_CSTRING("NTH_LAST_OF_TYPE")) return NTH_LAST_OF_TYPE_dyn();
	if (inName==HX_CSTRING("NTH_OF_TYPE")) return NTH_OF_TYPE_dyn();
	if (inName==HX_CSTRING("ONLY_CHILD")) return ONLY_CHILD;
	if (inName==HX_CSTRING("ONLY_OF_TYPE")) return ONLY_OF_TYPE;
	if (inName==HX_CSTRING("ROOT")) return ROOT;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ROOT"),
	HX_CSTRING("FIRST_CHILD"),
	HX_CSTRING("LAST_CHILD"),
	HX_CSTRING("FIRST_OF_TYPE"),
	HX_CSTRING("LAST_OF_TYPE"),
	HX_CSTRING("ONLY_CHILD"),
	HX_CSTRING("ONLY_OF_TYPE"),
	HX_CSTRING("EMPTY"),
	HX_CSTRING("NTH_CHILD"),
	HX_CSTRING("NTH_LAST_CHILD"),
	HX_CSTRING("NTH_OF_TYPE"),
	HX_CSTRING("NTH_LAST_OF_TYPE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::EMPTY,"EMPTY");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::FIRST_CHILD,"FIRST_CHILD");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::FIRST_OF_TYPE,"FIRST_OF_TYPE");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::LAST_CHILD,"LAST_CHILD");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::LAST_OF_TYPE,"LAST_OF_TYPE");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::ONLY_CHILD,"ONLY_CHILD");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::ONLY_OF_TYPE,"ONLY_OF_TYPE");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::ROOT,"ROOT");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::EMPTY,"EMPTY");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::FIRST_CHILD,"FIRST_CHILD");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::FIRST_OF_TYPE,"FIRST_OF_TYPE");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::LAST_CHILD,"LAST_CHILD");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::LAST_OF_TYPE,"LAST_OF_TYPE");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::ONLY_CHILD,"ONLY_CHILD");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::ONLY_OF_TYPE,"ONLY_OF_TYPE");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassSelectorValue_obj::ROOT,"ROOT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StructuralPseudoClassSelectorValue_obj::__mClass;

Dynamic __Create_StructuralPseudoClassSelectorValue_obj() { return new StructuralPseudoClassSelectorValue_obj; }

void StructuralPseudoClassSelectorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.StructuralPseudoClassSelectorValue"), hx::TCanCast< StructuralPseudoClassSelectorValue_obj >,sStaticFields,sMemberFields,
	&__Create_StructuralPseudoClassSelectorValue_obj, &__Create,
	&super::__SGetClass(), &CreateStructuralPseudoClassSelectorValue_obj, sMarkStatics, sVisitStatic);
}

void StructuralPseudoClassSelectorValue_obj::__boot()
{
Static(EMPTY) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("EMPTY"),7);
Static(FIRST_CHILD) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("FIRST_CHILD"),1);
Static(FIRST_OF_TYPE) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("FIRST_OF_TYPE"),3);
Static(LAST_CHILD) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("LAST_CHILD"),2);
Static(LAST_OF_TYPE) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("LAST_OF_TYPE"),4);
Static(ONLY_CHILD) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("ONLY_CHILD"),5);
Static(ONLY_OF_TYPE) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("ONLY_OF_TYPE"),6);
Static(ROOT) = hx::CreateEnum< StructuralPseudoClassSelectorValue_obj >(HX_CSTRING("ROOT"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
