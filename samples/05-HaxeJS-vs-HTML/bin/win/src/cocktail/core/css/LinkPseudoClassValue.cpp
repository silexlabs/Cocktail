#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_LinkPseudoClassValue
#include <cocktail/core/css/LinkPseudoClassValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::LinkPseudoClassValue LinkPseudoClassValue_obj::LINK;

::cocktail::core::css::LinkPseudoClassValue LinkPseudoClassValue_obj::VISITED;

HX_DEFINE_CREATE_ENUM(LinkPseudoClassValue_obj)

int LinkPseudoClassValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("LINK")) return 0;
	if (inName==HX_CSTRING("VISITED")) return 1;
	return super::__FindIndex(inName);
}

int LinkPseudoClassValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("LINK")) return 0;
	if (inName==HX_CSTRING("VISITED")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic LinkPseudoClassValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("LINK")) return LINK;
	if (inName==HX_CSTRING("VISITED")) return VISITED;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("LINK"),
	HX_CSTRING("VISITED"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LinkPseudoClassValue_obj::LINK,"LINK");
	HX_MARK_MEMBER_NAME(LinkPseudoClassValue_obj::VISITED,"VISITED");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LinkPseudoClassValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(LinkPseudoClassValue_obj::LINK,"LINK");
	HX_VISIT_MEMBER_NAME(LinkPseudoClassValue_obj::VISITED,"VISITED");
};

static ::String sMemberFields[] = { ::String(null()) };
Class LinkPseudoClassValue_obj::__mClass;

Dynamic __Create_LinkPseudoClassValue_obj() { return new LinkPseudoClassValue_obj; }

void LinkPseudoClassValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.LinkPseudoClassValue"), hx::TCanCast< LinkPseudoClassValue_obj >,sStaticFields,sMemberFields,
	&__Create_LinkPseudoClassValue_obj, &__Create,
	&super::__SGetClass(), &CreateLinkPseudoClassValue_obj, sMarkStatics, sVisitStatic);
}

void LinkPseudoClassValue_obj::__boot()
{
Static(LINK) = hx::CreateEnum< LinkPseudoClassValue_obj >(HX_CSTRING("LINK"),0);
Static(VISITED) = hx::CreateEnum< LinkPseudoClassValue_obj >(HX_CSTRING("VISITED"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
