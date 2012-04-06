#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_Transform
#include <cocktail/core/style/Transform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformFunction
#include <cocktail/core/style/TransformFunction.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::Transform Transform_obj::none;

::cocktail::core::style::Transform  Transform_obj::transformFunctions(Array< ::cocktail::core::style::TransformFunction > transformFunctions)
	{ return hx::CreateEnum< Transform_obj >(HX_CSTRING("transformFunctions"),1,hx::DynamicArray(0,1).Add(transformFunctions)); }

HX_DEFINE_CREATE_ENUM(Transform_obj)

int Transform_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("transformFunctions")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,transformFunctions,return)

int Transform_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("transformFunctions")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Transform_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("transformFunctions")) return transformFunctions_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("none"),
	HX_CSTRING("transformFunctions"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Transform_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Transform_obj::__mClass;

Dynamic __Create_Transform_obj() { return new Transform_obj; }

void Transform_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.Transform"), hx::TCanCast< Transform_obj >,sStaticFields,sMemberFields,
	&__Create_Transform_obj, &__Create,
	&super::__SGetClass(), &CreateTransform_obj, sMarkStatics);
}

void Transform_obj::__boot()
{
Static(none) = hx::CreateEnum< Transform_obj >(HX_CSTRING("none"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
