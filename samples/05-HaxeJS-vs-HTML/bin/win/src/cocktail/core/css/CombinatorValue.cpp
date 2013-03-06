#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CombinatorValue
#include <cocktail/core/css/CombinatorValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::CombinatorValue CombinatorValue_obj::ADJACENT_SIBLING;

::cocktail::core::css::CombinatorValue CombinatorValue_obj::CHILD;

::cocktail::core::css::CombinatorValue CombinatorValue_obj::DESCENDANT;

::cocktail::core::css::CombinatorValue CombinatorValue_obj::GENERAL_SIBLING;

HX_DEFINE_CREATE_ENUM(CombinatorValue_obj)

int CombinatorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ADJACENT_SIBLING")) return 2;
	if (inName==HX_CSTRING("CHILD")) return 1;
	if (inName==HX_CSTRING("DESCENDANT")) return 0;
	if (inName==HX_CSTRING("GENERAL_SIBLING")) return 3;
	return super::__FindIndex(inName);
}

int CombinatorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ADJACENT_SIBLING")) return 0;
	if (inName==HX_CSTRING("CHILD")) return 0;
	if (inName==HX_CSTRING("DESCENDANT")) return 0;
	if (inName==HX_CSTRING("GENERAL_SIBLING")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CombinatorValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ADJACENT_SIBLING")) return ADJACENT_SIBLING;
	if (inName==HX_CSTRING("CHILD")) return CHILD;
	if (inName==HX_CSTRING("DESCENDANT")) return DESCENDANT;
	if (inName==HX_CSTRING("GENERAL_SIBLING")) return GENERAL_SIBLING;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("DESCENDANT"),
	HX_CSTRING("CHILD"),
	HX_CSTRING("ADJACENT_SIBLING"),
	HX_CSTRING("GENERAL_SIBLING"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CombinatorValue_obj::ADJACENT_SIBLING,"ADJACENT_SIBLING");
	HX_MARK_MEMBER_NAME(CombinatorValue_obj::CHILD,"CHILD");
	HX_MARK_MEMBER_NAME(CombinatorValue_obj::DESCENDANT,"DESCENDANT");
	HX_MARK_MEMBER_NAME(CombinatorValue_obj::GENERAL_SIBLING,"GENERAL_SIBLING");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CombinatorValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CombinatorValue_obj::ADJACENT_SIBLING,"ADJACENT_SIBLING");
	HX_VISIT_MEMBER_NAME(CombinatorValue_obj::CHILD,"CHILD");
	HX_VISIT_MEMBER_NAME(CombinatorValue_obj::DESCENDANT,"DESCENDANT");
	HX_VISIT_MEMBER_NAME(CombinatorValue_obj::GENERAL_SIBLING,"GENERAL_SIBLING");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CombinatorValue_obj::__mClass;

Dynamic __Create_CombinatorValue_obj() { return new CombinatorValue_obj; }

void CombinatorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CombinatorValue"), hx::TCanCast< CombinatorValue_obj >,sStaticFields,sMemberFields,
	&__Create_CombinatorValue_obj, &__Create,
	&super::__SGetClass(), &CreateCombinatorValue_obj, sMarkStatics, sVisitStatic);
}

void CombinatorValue_obj::__boot()
{
Static(ADJACENT_SIBLING) = hx::CreateEnum< CombinatorValue_obj >(HX_CSTRING("ADJACENT_SIBLING"),2);
Static(CHILD) = hx::CreateEnum< CombinatorValue_obj >(HX_CSTRING("CHILD"),1);
Static(DESCENDANT) = hx::CreateEnum< CombinatorValue_obj >(HX_CSTRING("DESCENDANT"),0);
Static(GENERAL_SIBLING) = hx::CreateEnum< CombinatorValue_obj >(HX_CSTRING("GENERAL_SIBLING"),3);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
