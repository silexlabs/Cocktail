#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_UserActionPseudoClassValue
#include <cocktail/core/css/UserActionPseudoClassValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::UserActionPseudoClassValue UserActionPseudoClassValue_obj::ACTIVE;

::cocktail::core::css::UserActionPseudoClassValue UserActionPseudoClassValue_obj::FOCUS;

::cocktail::core::css::UserActionPseudoClassValue UserActionPseudoClassValue_obj::HOVER;

HX_DEFINE_CREATE_ENUM(UserActionPseudoClassValue_obj)

int UserActionPseudoClassValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ACTIVE")) return 0;
	if (inName==HX_CSTRING("FOCUS")) return 2;
	if (inName==HX_CSTRING("HOVER")) return 1;
	return super::__FindIndex(inName);
}

int UserActionPseudoClassValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ACTIVE")) return 0;
	if (inName==HX_CSTRING("FOCUS")) return 0;
	if (inName==HX_CSTRING("HOVER")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic UserActionPseudoClassValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ACTIVE")) return ACTIVE;
	if (inName==HX_CSTRING("FOCUS")) return FOCUS;
	if (inName==HX_CSTRING("HOVER")) return HOVER;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ACTIVE"),
	HX_CSTRING("HOVER"),
	HX_CSTRING("FOCUS"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UserActionPseudoClassValue_obj::ACTIVE,"ACTIVE");
	HX_MARK_MEMBER_NAME(UserActionPseudoClassValue_obj::FOCUS,"FOCUS");
	HX_MARK_MEMBER_NAME(UserActionPseudoClassValue_obj::HOVER,"HOVER");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UserActionPseudoClassValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(UserActionPseudoClassValue_obj::ACTIVE,"ACTIVE");
	HX_VISIT_MEMBER_NAME(UserActionPseudoClassValue_obj::FOCUS,"FOCUS");
	HX_VISIT_MEMBER_NAME(UserActionPseudoClassValue_obj::HOVER,"HOVER");
};

static ::String sMemberFields[] = { ::String(null()) };
Class UserActionPseudoClassValue_obj::__mClass;

Dynamic __Create_UserActionPseudoClassValue_obj() { return new UserActionPseudoClassValue_obj; }

void UserActionPseudoClassValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.UserActionPseudoClassValue"), hx::TCanCast< UserActionPseudoClassValue_obj >,sStaticFields,sMemberFields,
	&__Create_UserActionPseudoClassValue_obj, &__Create,
	&super::__SGetClass(), &CreateUserActionPseudoClassValue_obj, sMarkStatics, sVisitStatic);
}

void UserActionPseudoClassValue_obj::__boot()
{
Static(ACTIVE) = hx::CreateEnum< UserActionPseudoClassValue_obj >(HX_CSTRING("ACTIVE"),0);
Static(FOCUS) = hx::CreateEnum< UserActionPseudoClassValue_obj >(HX_CSTRING("FOCUS"),2);
Static(HOVER) = hx::CreateEnum< UserActionPseudoClassValue_obj >(HX_CSTRING("HOVER"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
