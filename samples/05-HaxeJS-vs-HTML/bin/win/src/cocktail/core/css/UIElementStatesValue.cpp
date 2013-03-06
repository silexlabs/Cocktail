#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_UIElementStatesValue
#include <cocktail/core/css/UIElementStatesValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::UIElementStatesValue UIElementStatesValue_obj::CHECKED;

::cocktail::core::css::UIElementStatesValue UIElementStatesValue_obj::DISABLED;

::cocktail::core::css::UIElementStatesValue UIElementStatesValue_obj::ENABLED;

HX_DEFINE_CREATE_ENUM(UIElementStatesValue_obj)

int UIElementStatesValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CHECKED")) return 2;
	if (inName==HX_CSTRING("DISABLED")) return 1;
	if (inName==HX_CSTRING("ENABLED")) return 0;
	return super::__FindIndex(inName);
}

int UIElementStatesValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CHECKED")) return 0;
	if (inName==HX_CSTRING("DISABLED")) return 0;
	if (inName==HX_CSTRING("ENABLED")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic UIElementStatesValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CHECKED")) return CHECKED;
	if (inName==HX_CSTRING("DISABLED")) return DISABLED;
	if (inName==HX_CSTRING("ENABLED")) return ENABLED;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ENABLED"),
	HX_CSTRING("DISABLED"),
	HX_CSTRING("CHECKED"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UIElementStatesValue_obj::CHECKED,"CHECKED");
	HX_MARK_MEMBER_NAME(UIElementStatesValue_obj::DISABLED,"DISABLED");
	HX_MARK_MEMBER_NAME(UIElementStatesValue_obj::ENABLED,"ENABLED");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UIElementStatesValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(UIElementStatesValue_obj::CHECKED,"CHECKED");
	HX_VISIT_MEMBER_NAME(UIElementStatesValue_obj::DISABLED,"DISABLED");
	HX_VISIT_MEMBER_NAME(UIElementStatesValue_obj::ENABLED,"ENABLED");
};

static ::String sMemberFields[] = { ::String(null()) };
Class UIElementStatesValue_obj::__mClass;

Dynamic __Create_UIElementStatesValue_obj() { return new UIElementStatesValue_obj; }

void UIElementStatesValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.UIElementStatesValue"), hx::TCanCast< UIElementStatesValue_obj >,sStaticFields,sMemberFields,
	&__Create_UIElementStatesValue_obj, &__Create,
	&super::__SGetClass(), &CreateUIElementStatesValue_obj, sMarkStatics, sVisitStatic);
}

void UIElementStatesValue_obj::__boot()
{
Static(CHECKED) = hx::CreateEnum< UIElementStatesValue_obj >(HX_CSTRING("CHECKED"),2);
Static(DISABLED) = hx::CreateEnum< UIElementStatesValue_obj >(HX_CSTRING("DISABLED"),1);
Static(ENABLED) = hx::CreateEnum< UIElementStatesValue_obj >(HX_CSTRING("ENABLED"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
