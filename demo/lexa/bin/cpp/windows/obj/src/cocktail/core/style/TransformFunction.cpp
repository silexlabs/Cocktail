#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_TransformFunction
#include <cocktail/core/style/TransformFunction.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Translation
#include <cocktail/core/style/Translation.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Angle
#include <cocktail/core/unit/Angle.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::TransformFunction  TransformFunction_obj::matrix(Dynamic data)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("matrix"),0,hx::DynamicArray(0,1).Add(data)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::rotate(::cocktail::core::unit::Angle angle)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("rotate"),7,hx::DynamicArray(0,1).Add(angle)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::scale(double sx,double sy)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("scale"),4,hx::DynamicArray(0,2).Add(sx).Add(sy)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::scaleX(double sx)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("scaleX"),5,hx::DynamicArray(0,1).Add(sx)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::scaleY(double sy)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("scaleY"),6,hx::DynamicArray(0,1).Add(sy)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::skew(::cocktail::core::unit::Angle angleX,::cocktail::core::unit::Angle angleY)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("skew"),10,hx::DynamicArray(0,2).Add(angleX).Add(angleY)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::skewX(::cocktail::core::unit::Angle angle)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("skewX"),8,hx::DynamicArray(0,1).Add(angle)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::skewY(::cocktail::core::unit::Angle angle)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("skewY"),9,hx::DynamicArray(0,1).Add(angle)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::translate(::cocktail::core::style::Translation tx,::cocktail::core::style::Translation ty)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("translate"),1,hx::DynamicArray(0,2).Add(tx).Add(ty)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::translateX(::cocktail::core::style::Translation tx)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("translateX"),2,hx::DynamicArray(0,1).Add(tx)); }

::cocktail::core::style::TransformFunction  TransformFunction_obj::translateY(::cocktail::core::style::Translation ty)
	{ return hx::CreateEnum< TransformFunction_obj >(HX_CSTRING("translateY"),3,hx::DynamicArray(0,1).Add(ty)); }

HX_DEFINE_CREATE_ENUM(TransformFunction_obj)

int TransformFunction_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("matrix")) return 0;
	if (inName==HX_CSTRING("rotate")) return 7;
	if (inName==HX_CSTRING("scale")) return 4;
	if (inName==HX_CSTRING("scaleX")) return 5;
	if (inName==HX_CSTRING("scaleY")) return 6;
	if (inName==HX_CSTRING("skew")) return 10;
	if (inName==HX_CSTRING("skewX")) return 8;
	if (inName==HX_CSTRING("skewY")) return 9;
	if (inName==HX_CSTRING("translate")) return 1;
	if (inName==HX_CSTRING("translateX")) return 2;
	if (inName==HX_CSTRING("translateY")) return 3;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,matrix,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,rotate,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(TransformFunction_obj,scale,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,scaleX,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,scaleY,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(TransformFunction_obj,skew,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,skewX,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,skewY,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(TransformFunction_obj,translate,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,translateX,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TransformFunction_obj,translateY,return)

int TransformFunction_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("matrix")) return 1;
	if (inName==HX_CSTRING("rotate")) return 1;
	if (inName==HX_CSTRING("scale")) return 2;
	if (inName==HX_CSTRING("scaleX")) return 1;
	if (inName==HX_CSTRING("scaleY")) return 1;
	if (inName==HX_CSTRING("skew")) return 2;
	if (inName==HX_CSTRING("skewX")) return 1;
	if (inName==HX_CSTRING("skewY")) return 1;
	if (inName==HX_CSTRING("translate")) return 2;
	if (inName==HX_CSTRING("translateX")) return 1;
	if (inName==HX_CSTRING("translateY")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic TransformFunction_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("matrix")) return matrix_dyn();
	if (inName==HX_CSTRING("rotate")) return rotate_dyn();
	if (inName==HX_CSTRING("scale")) return scale_dyn();
	if (inName==HX_CSTRING("scaleX")) return scaleX_dyn();
	if (inName==HX_CSTRING("scaleY")) return scaleY_dyn();
	if (inName==HX_CSTRING("skew")) return skew_dyn();
	if (inName==HX_CSTRING("skewX")) return skewX_dyn();
	if (inName==HX_CSTRING("skewY")) return skewY_dyn();
	if (inName==HX_CSTRING("translate")) return translate_dyn();
	if (inName==HX_CSTRING("translateX")) return translateX_dyn();
	if (inName==HX_CSTRING("translateY")) return translateY_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("matrix"),
	HX_CSTRING("translate"),
	HX_CSTRING("translateX"),
	HX_CSTRING("translateY"),
	HX_CSTRING("scale"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("rotate"),
	HX_CSTRING("skewX"),
	HX_CSTRING("skewY"),
	HX_CSTRING("skew"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class TransformFunction_obj::__mClass;

Dynamic __Create_TransformFunction_obj() { return new TransformFunction_obj; }

void TransformFunction_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.TransformFunction"), hx::TCanCast< TransformFunction_obj >,sStaticFields,sMemberFields,
	&__Create_TransformFunction_obj, &__Create,
	&super::__SGetClass(), &CreateTransformFunction_obj, sMarkStatics);
}

void TransformFunction_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
