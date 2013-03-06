#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassArgumentValue
#include <cocktail/core/css/StructuralPseudoClassArgumentValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::StructuralPseudoClassArgumentValue StructuralPseudoClassArgumentValue_obj::EVEN;

::cocktail::core::css::StructuralPseudoClassArgumentValue StructuralPseudoClassArgumentValue_obj::ODD;

HX_DEFINE_CREATE_ENUM(StructuralPseudoClassArgumentValue_obj)

int StructuralPseudoClassArgumentValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("EVEN")) return 1;
	if (inName==HX_CSTRING("ODD")) return 0;
	return super::__FindIndex(inName);
}

int StructuralPseudoClassArgumentValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("EVEN")) return 0;
	if (inName==HX_CSTRING("ODD")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StructuralPseudoClassArgumentValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("EVEN")) return EVEN;
	if (inName==HX_CSTRING("ODD")) return ODD;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ODD"),
	HX_CSTRING("EVEN"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StructuralPseudoClassArgumentValue_obj::EVEN,"EVEN");
	HX_MARK_MEMBER_NAME(StructuralPseudoClassArgumentValue_obj::ODD,"ODD");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassArgumentValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassArgumentValue_obj::EVEN,"EVEN");
	HX_VISIT_MEMBER_NAME(StructuralPseudoClassArgumentValue_obj::ODD,"ODD");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StructuralPseudoClassArgumentValue_obj::__mClass;

Dynamic __Create_StructuralPseudoClassArgumentValue_obj() { return new StructuralPseudoClassArgumentValue_obj; }

void StructuralPseudoClassArgumentValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.StructuralPseudoClassArgumentValue"), hx::TCanCast< StructuralPseudoClassArgumentValue_obj >,sStaticFields,sMemberFields,
	&__Create_StructuralPseudoClassArgumentValue_obj, &__Create,
	&super::__SGetClass(), &CreateStructuralPseudoClassArgumentValue_obj, sMarkStatics, sVisitStatic);
}

void StructuralPseudoClassArgumentValue_obj::__boot()
{
Static(EVEN) = hx::CreateEnum< StructuralPseudoClassArgumentValue_obj >(HX_CSTRING("EVEN"),1);
Static(ODD) = hx::CreateEnum< StructuralPseudoClassArgumentValue_obj >(HX_CSTRING("ODD"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
