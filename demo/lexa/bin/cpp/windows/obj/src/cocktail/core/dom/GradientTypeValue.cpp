#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_GradientTypeValue
#include <cocktail/core/dom/GradientTypeValue.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

::cocktail::core::dom::GradientTypeValue GradientTypeValue_obj::linear;

::cocktail::core::dom::GradientTypeValue GradientTypeValue_obj::radial;

HX_DEFINE_CREATE_ENUM(GradientTypeValue_obj)

int GradientTypeValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("linear")) return 0;
	if (inName==HX_CSTRING("radial")) return 1;
	return super::__FindIndex(inName);
}

int GradientTypeValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("linear")) return 0;
	if (inName==HX_CSTRING("radial")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GradientTypeValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("linear")) return linear;
	if (inName==HX_CSTRING("radial")) return radial;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("linear"),
	HX_CSTRING("radial"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GradientTypeValue_obj::linear,"linear");
	HX_MARK_MEMBER_NAME(GradientTypeValue_obj::radial,"radial");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientTypeValue_obj::__mClass;

Dynamic __Create_GradientTypeValue_obj() { return new GradientTypeValue_obj; }

void GradientTypeValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.GradientTypeValue"), hx::TCanCast< GradientTypeValue_obj >,sStaticFields,sMemberFields,
	&__Create_GradientTypeValue_obj, &__Create,
	&super::__SGetClass(), &CreateGradientTypeValue_obj, sMarkStatics);
}

void GradientTypeValue_obj::__boot()
{
Static(linear) = hx::CreateEnum< GradientTypeValue_obj >(HX_CSTRING("linear"),0);
Static(radial) = hx::CreateEnum< GradientTypeValue_obj >(HX_CSTRING("radial"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace dom
