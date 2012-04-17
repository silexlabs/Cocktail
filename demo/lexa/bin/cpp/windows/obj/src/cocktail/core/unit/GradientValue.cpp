#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_GradientValue
#include <cocktail/core/unit/GradientValue.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::GradientValue  GradientValue_obj::linear(Dynamic value)
	{ return hx::CreateEnum< GradientValue_obj >(HX_CSTRING("linear"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(GradientValue_obj)

int GradientValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("linear")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(GradientValue_obj,linear,return)

int GradientValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("linear")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic GradientValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("linear")) return linear_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("linear"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientValue_obj::__mClass;

Dynamic __Create_GradientValue_obj() { return new GradientValue_obj; }

void GradientValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.GradientValue"), hx::TCanCast< GradientValue_obj >,sStaticFields,sMemberFields,
	&__Create_GradientValue_obj, &__Create,
	&super::__SGetClass(), &CreateGradientValue_obj, sMarkStatics);
}

void GradientValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit
